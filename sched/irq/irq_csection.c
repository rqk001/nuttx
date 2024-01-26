/****************************************************************************
 * sched/irq/irq_csection.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <assert.h>

#include <nuttx/init.h>
#include <nuttx/spinlock.h>
#include <nuttx/sched_note.h>
#include <arch/irq.h>

#include "sched/sched.h"
#include "irq/irq.h"

#ifdef CONFIG_IRQCOUNT
/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifdef CONFIG_SMP
#  define cpu_irqlock_set(cpu) \
  do \
    { \
      g_cpu_irqset |= (1 << cpu); \
    } \
  while (0)
#endif

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifdef CONFIG_SMP
/* This is the spinlock that enforces critical sections when interrupts are
 * disabled.
 */

volatile spinlock_t g_cpu_irqlock = SP_UNLOCKED;

/* Used to keep track of which CPU(s) hold the IRQ lock. */

volatile cpu_set_t g_cpu_irqset;

/* Handles nested calls to enter_critical section from interrupt handlers */

volatile uint8_t g_cpu_nestcount[CONFIG_SMP_NCPUS];
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: irq_waitlock
 *
 * Description:
 *   Spin to get g_cpu_irqlock, handling a known deadlock condition:
 *
 *   A deadlock may occur if enter_critical_section is called from an
 *   interrupt handler.  Suppose:
 *
 *   - CPUn is in a critical section and has the g_cpu_irqlock spinlock.
 *   - CPUm takes an interrupt and attempts to enter the critical section.
 *   - It spins waiting on g_cpu_irqlock with interrupts disabled.
 *   - CPUn calls up_cpu_pause() to pause operation on CPUm.  This will
 *     issue an inter-CPU interrupt to CPUm
 *   - But interrupts are disabled on CPUm so the up_cpu_pause() is never
 *     handled, causing the deadlock.
 *
 *   This same deadlock can occur in the normal tasking case:
 *
 *   - A task on CPUn enters a critical section and has the g_cpu_irqlock
 *     spinlock.
 *   - Another task on CPUm attempts to enter the critical section but has
 *     to wait, spinning to get g_cpu_irqlock with interrupts disabled.
 *   - The task on CPUn causes a new task to become ready-to-run and the
 *     scheduler selects CPUm.  CPUm is requested to pause via a pause
 *     interrupt.
 *   - But the task on CPUm is also attempting to enter the critical
 *     section.  Since it is spinning with interrupts disabled, CPUm cannot
 *     process the pending pause interrupt, causing the deadlock.
 *
 *   This function detects this deadlock condition while spinning with
 *   interrupts disabled.
 *
 * Input Parameters:
 *   cpu - The index of CPU that is trying to enter the critical section.
 *
 * Returned Value:
 *   True:  The g_cpu_irqlock spinlock has been taken.
 *   False: The g_cpu_irqlock spinlock has not been taken yet, but there is
 *          a pending pause interrupt request.
 *
 ****************************************************************************/

#ifdef CONFIG_SMP
static inline_function bool irq_waitlock(int cpu)
{
#ifdef CONFIG_SCHED_INSTRUMENTATION_SPINLOCKS
  FAR struct tcb_s *tcb = current_task(cpu);

  /* Notify that we are waiting for a spinlock */

  sched_note_spinlock(tcb, &g_cpu_irqlock, NOTE_SPINLOCK_LOCK);
#endif

  /* Duplicate the spin_lock() logic from spinlock.c, but adding the check
   * for the deadlock condition.
   */

  while (!spin_trylock_wo_note(&g_cpu_irqlock))
    {
      /* Is a pause request pending? */

      if (up_cpu_pausereq(cpu))
        {
          /* Yes.. some other CPU is requesting to pause this CPU!
           * Abort the wait and return false.
           */

#ifdef CONFIG_SCHED_INSTRUMENTATION_SPINLOCKS
          /* Notify that we have aborted the wait for the spinlock */

          sched_note_spinlock(tcb, &g_cpu_irqlock, NOTE_SPINLOCK_ABORT);
#endif

          return false;
        }
    }

  /* We have g_cpu_irqlock! */

#ifdef CONFIG_SCHED_INSTRUMENTATION_SPINLOCKS
  /* Notify that we have the spinlock */

  sched_note_spinlock(tcb, &g_cpu_irqlock, NOTE_SPINLOCK_LOCKED);
#endif

  return true;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: enter_critical_section
 *
 * Description:
 *   Take the CPU IRQ lock and disable interrupts on all CPUs.  A thread-
 *   specific counter is incremented to indicate that the thread has IRQs
 *   disabled and to support nested calls to enter_critical_section().
 *
 ****************************************************************************/

#ifdef CONFIG_SMP
irqstate_t enter_critical_section(void)
{
  FAR struct tcb_s *rtcb;
  irqstate_t ret;
  int cpu;

  /* Disable interrupts.
   *
   * NOTE 1: Ideally this should disable interrupts on all CPUs, but most
   * architectures only support disabling interrupts on the local CPU.
   * NOTE 2: Interrupts may already be disabled, but we call up_irq_save()
   * unconditionally because we need to return valid interrupt status in any
   * event.
   * NOTE 3: We disable local interrupts BEFORE taking the spinlock in order
   * to prevent possible waits on the spinlock from interrupt handling on
   * the local CPU.
   */

try_again:
  ret = up_irq_save();

  /* If called from an interrupt handler, then just take the spinlock.
   * If we are already in a critical section, this will lock the CPU
   * in the interrupt handler.  Sounds worse than it is.
   */

  if (up_interrupt_context())
    {
      /* We are in an interrupt handler.  How can this happen?
       *
       *   1. We were not in a critical section when the interrupt
       *      occurred.  In this case, the interrupt was entered with:
       *
       *      g_cpu_irqlock = SP_UNLOCKED.
       *      g_cpu_nestcount = 0
       *      All CPU bits in g_cpu_irqset should be zero
       *
       *   2. We were in a critical section and interrupts on this
       *      this CPU were disabled -- this is an impossible case.
       *
       *   3. We were in critical section, but up_irq_save() only
       *      disabled local interrupts on a different CPU;
       *      Interrupts could still be enabled on this CPU.
       *
       *      g_cpu_irqlock = SP_LOCKED.
       *      g_cpu_nestcount = 0
       *      The bit in g_cpu_irqset for this CPU should be zero
       *
       *   4. An extension of 3 is that we may be re-entered numerous
       *      times from the same interrupt handler.  In that case:
       *
       *      g_cpu_irqlock = SP_LOCKED.
       *      g_cpu_nestcount > 0
       *      The bit in g_cpu_irqset for this CPU should be zero
       *
       * NOTE: However, the interrupt entry conditions can change due
       * to previous processing by the interrupt handler that may
       * instantiate a new thread that has irqcount > 0 and may then
       * set the bit in g_cpu_irqset and g_cpu_irqlock = SP_LOCKED
       */

      /* Handle nested calls to enter_critical_section() from the same
       * interrupt.
       */

      cpu = this_cpu();
      if (g_cpu_nestcount[cpu] > 0)
        {
          DEBUGASSERT(spin_is_locked(&g_cpu_irqlock) &&
                      g_cpu_nestcount[cpu] < UINT8_MAX);
          g_cpu_nestcount[cpu]++;
        }

      /* This is the first call to enter_critical_section from the
       * interrupt handler.
       */

      else
        {
          int paused = false;

          /* Make sure that the g_cpu_irqset was not already set
           * by previous logic on this CPU that was executed by the
           * interrupt handler.  We know that the bit in g_cpu_irqset
           * for this CPU was zero on entry into the interrupt handler,
           * so if it is non-zero now then we know that was the case.
           */

          if ((g_cpu_irqset & (1 << cpu)) == 0)
            {
              /* Wait until we can get the spinlock (meaning that we are
               * no longer blocked by the critical section).
               */

try_again_in_irq:
              if (!irq_waitlock(cpu))
                {
                  /* We are in a deadlock condition due to a pending
                   * pause request interrupt.  Break the deadlock by
                   * handling the pause request now.
                   */

                  if (!paused)
                    {
                      up_cpu_paused_save();
                    }

                  DEBUGVERIFY(up_cpu_paused(cpu));
                  paused = true;

                  DEBUGASSERT((g_cpu_irqset & (1 << cpu)) == 0);

                  /* NOTE: Here, this CPU does not hold g_cpu_irqlock,
                   * so call irq_waitlock(cpu) to acquire g_cpu_irqlock.
                   */

                  goto try_again_in_irq;
                }

                cpu_irqlock_set(cpu);
            }

          /* In any event, the nesting count is now one */

          g_cpu_nestcount[cpu] = 1;

          if (paused)
            {
              up_cpu_paused_restore();
            }

          DEBUGASSERT(spin_is_locked(&g_cpu_irqlock) &&
                      (g_cpu_irqset & (1 << cpu)) != 0);
        }
    }
  else
    {
      /* Normal tasking environment.
       *
       * Get the TCB of the currently executing task on this CPU (avoid
       * using this_task() which can recurse.
       */

      cpu  = this_cpu();
      rtcb = current_task(cpu);
      DEBUGASSERT(rtcb != NULL);

      /* Do we already have interrupts disabled? */

      if (rtcb->irqcount > 0)
        {
          /* Yes... make sure that the spinlock is set and increment the
           * IRQ lock count.
           *
           * NOTE: If irqcount > 0 then (1) we are in a critical section,
           * and (2) this CPU should hold the lock.
           */

          DEBUGASSERT(spin_is_locked(&g_cpu_irqlock) &&
                      (g_cpu_irqset & (1 << this_cpu())) != 0 &&
                      rtcb->irqcount < INT16_MAX);
          rtcb->irqcount++;
        }
      else
        {
          /* If we get here with irqcount == 0, then we know that the
           * current task running on this CPU is not in a critical
           * section.  However other tasks on other CPUs may be in a
           * critical section.  If so, we must wait until they release
           * the spinlock.
           */

          DEBUGASSERT((g_cpu_irqset & (1 << cpu)) == 0);

          if (!irq_waitlock(cpu))
            {
              /* We are in a deadlock condition due to a pending pause
               * request interrupt.  Re-enable interrupts on this CPU
               * and try again.  Briefly re-enabling interrupts should
               * be sufficient to permit processing the pending pause
               * request.
               */

              up_irq_restore(ret);
              goto try_again;
            }

          /* Then set the lock count to 1.
           *
           * Interrupts disables must follow a stacked order.  We
           * cannot other context switches to re-order the enabling
           * disabling of interrupts.
           *
           * The scheduler accomplishes this by treating the irqcount
           * like lockcount:  Both will disable pre-emption.
           */

          cpu_irqlock_set(cpu);
          rtcb->irqcount = 1;

          /* Note that we have entered the critical section */

#if CONFIG_SCHED_CRITMONITOR_MAXTIME_CSECTION >= 0
          nxsched_critmon_csection(rtcb, true);
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_CSECTION
          sched_note_csection(rtcb, true);
#endif
        }
    }

  /* Return interrupt status */

  return ret;
}

#else

irqstate_t enter_critical_section(void)
{
  irqstate_t ret;

  /* Disable interrupts */

  ret = up_irq_save();

  /* Check if we were called from an interrupt handler */

  if (!up_interrupt_context())
    {
      FAR struct tcb_s *rtcb = this_task();
      DEBUGASSERT(rtcb != NULL);

      /* Have we just entered the critical section?  Or is this a nested
       * call to enter_critical_section.
       */

      DEBUGASSERT(rtcb->irqcount >= 0 && rtcb->irqcount < INT16_MAX);
      if (++rtcb->irqcount == 1)
        {
          /* Note that we have entered the critical section */

#if CONFIG_SCHED_CRITMONITOR_MAXTIME_CSECTION >= 0
          nxsched_critmon_csection(rtcb, true);
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_CSECTION
          sched_note_csection(rtcb, true);
#endif
        }
    }

  /* Return interrupt status */

  return ret;
}
#endif

/****************************************************************************
 * Name: leave_critical_section
 *
 * Description:
 *   Decrement the IRQ lock count and if it decrements to zero then release
 *   the spinlock.
 *
 ****************************************************************************/

#ifdef CONFIG_SMP
void leave_critical_section(irqstate_t flags)
{
  int cpu;

  /* If called from an interrupt handler, then just release the
   * spinlock.  The interrupt handling logic should already hold the
   * spinlock if enter_critical_section() has been called.  Unlocking
   * the spinlock will allow interrupt handlers on other CPUs to execute
   * again.
   */

  if (up_interrupt_context())
    {
      /* We are in an interrupt handler. Check if the last call to
       * enter_critical_section() was nested.
       */

      cpu = this_cpu();
      if (g_cpu_nestcount[cpu] > 1)
        {
          /* Yes.. then just decrement the nesting count */

          DEBUGASSERT(spin_is_locked(&g_cpu_irqlock));
          g_cpu_nestcount[cpu]--;
        }
      else
        {
          /* No, not nested. Restore the g_cpu_irqset for this CPU
           * and release the spinlock (if necessary).
           */

          DEBUGASSERT(spin_is_locked(&g_cpu_irqlock) &&
                      g_cpu_nestcount[cpu] == 1);

          FAR struct tcb_s *rtcb = current_task(cpu);
          DEBUGASSERT(rtcb != NULL);
          DEBUGASSERT((g_cpu_irqset & (1 << cpu)) != 0);

          if (rtcb->irqcount <= 0)
            {
              cpu_irqlock_clear();
            }

          g_cpu_nestcount[cpu] = 0;
        }
    }
  else
    {
      FAR struct tcb_s *rtcb;

      /* Get the TCB of the currently executing task on this CPU (avoid
       * using this_task() which can recurse.
       */

      cpu  = this_cpu();
      rtcb = current_task(cpu);
      DEBUGASSERT(rtcb != NULL && rtcb->irqcount > 0);

      /* Normal tasking context.  We need to coordinate with other
       * tasks.
       *
       * Will we still have interrupts disabled after decrementing the
       * count?
       */

      if (rtcb->irqcount > 1)
        {
          /* Yes... the spinlock should remain set */

          DEBUGASSERT(spin_is_locked(&g_cpu_irqlock));
          rtcb->irqcount--;
        }
      else
        {
          /* No.. Note that we have left the critical section */

#if CONFIG_SCHED_CRITMONITOR_MAXTIME_CSECTION >= 0
          nxsched_critmon_csection(rtcb, false);
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_CSECTION
          sched_note_csection(rtcb, false);
#endif
          /* Decrement our count on the lock.  If all CPUs have
           * released, then unlock the spinlock.
           */

          DEBUGASSERT(spin_is_locked(&g_cpu_irqlock) &&
                      (g_cpu_irqset & (1 << cpu)) != 0);

          /* Now, possibly on return from a context switch, clear our
           * count on the lock.  If all CPUs have released the lock,
           * then unlock the global IRQ spinlock.
           */

          rtcb->irqcount = 0;
          cpu_irqlock_clear();

          /* Have all CPUs released the lock? */
        }
    }

  /* Restore the previous interrupt state which may still be interrupts
   * disabled (but we don't have a mechanism to verify that now)
   */

  up_irq_restore(flags);
}

#else

void leave_critical_section(irqstate_t flags)
{
  /* Check if we were called from an interrupt handler and that the tasks
   * lists have been initialized.
   */

  if (!up_interrupt_context())
    {
      FAR struct tcb_s *rtcb = this_task();
      DEBUGASSERT(rtcb != NULL);

      /* Have we left entered the critical section?  Or are we still
       * nested.
       */

      DEBUGASSERT(rtcb->irqcount > 0);
      if (--rtcb->irqcount <= 0)
        {
          /* Note that we have left the critical section */

#if CONFIG_SCHED_CRITMONITOR_MAXTIME_CSECTION >= 0
          nxsched_critmon_csection(rtcb, false);
#endif
#ifdef CONFIG_SCHED_INSTRUMENTATION_CSECTION
          sched_note_csection(rtcb, false);
#endif
        }
    }

  /* Restore the previous interrupt state. */

  up_irq_restore(flags);
}
#endif
#endif /* CONFIG_IRQCOUNT */
