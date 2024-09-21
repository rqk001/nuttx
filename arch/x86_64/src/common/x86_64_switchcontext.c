/****************************************************************************
 * arch/x86_64/src/common/x86_64_switchcontext.c
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

#include <sched.h>
#include <assert.h>
#include <debug.h>
#include <nuttx/addrenv.h>
#include <nuttx/arch.h>
#include <nuttx/sched.h>

#include <stdio.h>

#include "sched/sched.h"
#include "clock/clock.h"
#include "x86_64_internal.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_switch_context
 *
 * Description:
 *   A task is currently in the ready-to-run list but has been prepped
 *   to execute. Restore its context, and start execution.
 *
 * Input Parameters:
 *   tcb: Refers to the head task of the ready-to-run list
 *     which will be executed.
 *   rtcb: Refers to the running task which will be blocked.
 *
 ****************************************************************************/

void up_switch_context(struct tcb_s *tcb, struct tcb_s *rtcb)
{
  int cpu;

  /* Update scheduler parameters */

  nxsched_suspend_scheduler(rtcb);

  /* Are we in an interrupt handler? */

  if (up_current_regs())
    {
      /* Yes, then we have to do things differently.
       * Just copy the g_current_regs into the OLD rtcb.
       */

      x86_64_savestate(rtcb->xcp.regs);

      x86_64_restore_auxstate(tcb);

      /* Update scheduler parameters */

      nxsched_resume_scheduler(tcb);

      /* Then switch contexts.  Any necessary address environment
       * changes will be made when the interrupt returns.
       */

      x86_64_restorestate(tcb->xcp.regs);
    }

  /* We are not in an interrupt handler.  Copy the user C context
   * into the TCB of the task that was previously active.  if
   * up_saveusercontext returns a non-zero value, then this is really the
   * previously running task restarting!
   */

  else if (!up_saveusercontext(rtcb->xcp.regs))
    {
      x86_64_restore_auxstate(tcb);

#ifdef CONFIG_ARCH_ADDRENV
      /* Make sure that the address environment for the previously
       * running task is closed down gracefully (data caches dump,
       * MMU flushed) and set up the address environment for the new
       * thread at the head of the ready-to-run list.
       */

      addrenv_switch(tcb);
#endif
      /* Update scheduler parameters */

      nxsched_resume_scheduler(tcb);

      /* Restore the cpu lock */

      restore_critical_section(tcb, this_cpu());

      /* Record the new "running" task.  g_running_tasks[] is only used by
       * assertion logic for reporting crashes.
       */

      cpu = this_cpu();
      g_running_tasks[cpu] = current_task(cpu);

      /* Then switch contexts */

      x86_64_fullcontextrestore(tcb->xcp.regs);
    }
}
