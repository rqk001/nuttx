/****************************************************************************
 * sched/sched/sched_setscheduler.c
 *
 *   Copyright (C) 2007, 2009, 2012, 2015-2016, 2018 Gregory Nutt. All
 *     rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
#include <assert.h>
#include <errno.h>

#include <nuttx/sched.h>
#include <nuttx/irq.h>
#include <nuttx/arch.h>

#include "sched/sched.h"
#include "clock/clock.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: nxsched_set_scheduler
 *
 * Description:
 *   nxsched_set_scheduler() sets both the scheduling policy and the priority
 *   for the task identified by pid. If pid equals zero, the scheduler of
 *   the calling task will be set.  The parameter 'param' holds the priority
 *   of the thread under the new policy.
 *
 *   nxsched_set_scheduler() is identical to the function sched_getparam(),
 *   differing only in its return value:  This function does not modify the
 *    errno variable.
 *
 *   This is a non-standard, internal OS function and is not intended for
 *   use by application logic.  Applications should use the standard
 *   sched_getparam().
 *
 * Input Parameters:
 *   pid - the task ID of the task to modify.  If pid is zero, the calling
 *      task is modified.
 *   policy - Scheduling policy requested (either SCHED_FIFO or SCHED_RR)
 *   param - A structure whose member sched_priority is the new priority.
 *      The range of valid priority numbers is from SCHED_PRIORITY_MIN
 *      through SCHED_PRIORITY_MAX.
 *
 * Returned Value:
 *   On success, nxsched_set_scheduler() returns OK (zero).  On error, a
 *   negated errno value is returned:
 *
 *   EINVAL The scheduling policy is not one of the recognized policies.
 *   ESRCH  The task whose ID is pid could not be found.
 *
 ****************************************************************************/

int nxsched_set_scheduler(pid_t pid, int policy,
                         FAR const struct sched_param *param)
{
  FAR struct tcb_s *tcb;
  irqstate_t flags;
  int ret;

  /* Check for supported scheduling policy */

  if (policy != SCHED_FIFO
#if CONFIG_RR_INTERVAL > 0
      && policy != SCHED_RR
#endif
#ifdef CONFIG_SCHED_SPORADIC
      && policy != SCHED_SPORADIC
#endif
     )
    {
      return -EINVAL;
    }

  /* Check if the task to modify the calling task */

  if (pid == 0)
    {
      pid = getpid();
    }

  /* Verify that the pid corresponds to a real task */

  tcb = nxsched_get_tcb(pid);
  if (!tcb)
    {
      return -ESRCH;
    }

  /* Prohibit any context switches while we muck with priority and scheduler
   * settings.
   */

  sched_lock();

  /* Further, disable timer interrupts while we set up scheduling policy. */

  flags = enter_critical_section();
  tcb->flags &= ~TCB_FLAG_POLICY_MASK;
  switch (policy)
    {
      default:
        DEBUGPANIC();
        break;

      case SCHED_FIFO:
        {
#ifdef CONFIG_SCHED_SPORADIC
          /* Cancel any on-going sporadic scheduling */

          if ((tcb->flags & TCB_FLAG_POLICY_MASK) == TCB_FLAG_SCHED_SPORADIC)
            {
              DEBUGVERIFY(sched_sporadic_stop(tcb));
            }
#endif

          /* Save the FIFO scheduling parameters */

          tcb->flags       |= TCB_FLAG_SCHED_FIFO;
#if CONFIG_RR_INTERVAL > 0 || defined(CONFIG_SCHED_SPORADIC)
          tcb->timeslice    = 0;
#endif
        }
        break;

#if CONFIG_RR_INTERVAL > 0
      case SCHED_RR:
        {
#ifdef CONFIG_SCHED_SPORADIC
          /* Cancel any on-going sporadic scheduling */

          if ((tcb->flags & TCB_FLAG_POLICY_MASK) == TCB_FLAG_SCHED_SPORADIC)
            {
              DEBUGVERIFY(sched_sporadic_stop(tcb));
            }
#endif

          /* Save the round robin scheduling parameters */

          tcb->flags       |= TCB_FLAG_SCHED_RR;
          tcb->timeslice    = MSEC2TICK(CONFIG_RR_INTERVAL);
        }
        break;
#endif

#ifdef CONFIG_SCHED_SPORADIC
      case SCHED_SPORADIC:
        {
          FAR struct sporadic_s *sporadic;
          sclock_t repl_ticks;
          sclock_t budget_ticks;

          if (param->sched_ss_max_repl < 1 ||
              param->sched_ss_max_repl > CONFIG_SCHED_SPORADIC_MAXREPL)
            {
              ret = -EINVAL;
              goto errout_with_irq;
            }

          /* Convert timespec values to system clock ticks */

          clock_time2ticks(&param->sched_ss_repl_period, &repl_ticks);
          clock_time2ticks(&param->sched_ss_init_budget, &budget_ticks);

          /* Avoid zero/negative times */

          if (repl_ticks < 1)
            {
              repl_ticks = 1;
            }

          if (budget_ticks < 1)
            {
              budget_ticks = 1;
            }

          /* The replenishment period must be greater than or equal to the
           * budget period.
           */

#if 1
          /* REVISIT: In the current implementation, the budget cannot
           * exceed half the duty.
           */

          if (repl_ticks < (2 * budget_ticks))
#else
          if (repl_ticks < budget_ticks)
#endif
            {
              ret = -EINVAL;
              goto errout_with_irq;
            }

          /* Initialize/reset current sporadic scheduling */

          if ((tcb->flags & TCB_FLAG_POLICY_MASK) == TCB_FLAG_SCHED_SPORADIC)
            {
              ret = sched_sporadic_reset(tcb);
            }
          else
            {
              ret = sched_sporadic_initialize(tcb);
            }

          /* Save the sporadic scheduling parameters. */

          if (ret >= 0)
            {
              tcb->flags            |= TCB_FLAG_SCHED_SPORADIC;
              tcb->timeslice         = budget_ticks;

              sporadic               = tcb->sporadic;
              DEBUGASSERT(sporadic != NULL);

              sporadic->hi_priority  = param->sched_priority;
              sporadic->low_priority = param->sched_ss_low_priority;
              sporadic->max_repl     = param->sched_ss_max_repl;
              sporadic->repl_period  = repl_ticks;
              sporadic->budget       = budget_ticks;

              /* And restart at the next replenishment interval */

              ret = sched_sporadic_start(tcb);
            }

          /* Handle errors */

          if (ret < 0)
            {
              goto errout_with_irq;
            }
        }
        break;
#endif

#if 0 /* Not supported */
      case SCHED_OTHER:
        tcb->flags    |= TCB_FLAG_SCHED_OTHER;
        break;
#endif
    }

  leave_critical_section(flags);

  /* Set the new priority */

  ret = nxsched_reprioritize(tcb, param->sched_priority);
  sched_unlock();
  return ret;

#ifdef CONFIG_SCHED_SPORADIC
errout_with_irq:
  leave_critical_section(flags);
  sched_unlock();
  return ret;
#endif
}

/****************************************************************************
 * Name: sched_setscheduler
 *
 * Description:
 *   sched_setscheduler() sets both the scheduling policy and the priority
 *   for the task identified by pid. If pid equals zero, the scheduler of
 *   the calling task will be set.  The parameter 'param' holds the priority
 *   of the thread under the new policy.
 *
 *   This function is a simply wrapper around nxsched_get_param() that
 *   sets the errno value in the event of an error.
 *
 * Input Parameters:
 *   pid - the task ID of the task to modify.  If pid is zero, the calling
 *      task is modified.
 *   policy - Scheduling policy requested (either SCHED_FIFO or SCHED_RR)
 *   param - A structure whose member sched_priority is the new priority.
 *      The range of valid priority numbers is from SCHED_PRIORITY_MIN
 *      through SCHED_PRIORITY_MAX.
 *
 * Returned Value:
 *   On success, sched_setscheduler() returns OK (zero).  On error, ERROR
 *   (-1) is returned, and errno is set appropriately:
 *
 *   EINVAL The scheduling policy is not one of the recognized policies.
 *   ESRCH  The task whose ID is pid could not be found.
 *
 ****************************************************************************/

int sched_setscheduler(pid_t pid, int policy,
                       FAR const struct sched_param *param)
{
  int ret = nxsched_set_scheduler(pid, policy, param);
  if (ret < 0)
    {
      set_errno(-ret);
      ret = ERROR;
    }

  return ret;
}
