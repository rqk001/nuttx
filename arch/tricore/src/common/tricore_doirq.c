/****************************************************************************
 * arch/tricore/src/common/tricore_doirq.c
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

#include <stdint.h>
#include <assert.h>

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/addrenv.h>
#include <nuttx/board.h>

#include <arch/board/board.h>

#include <sched/sched.h>

#include "tricore_internal.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

IFX_INTERRUPT_INTERNAL(tricore_doirq, 0, 255)
{
#ifdef CONFIG_SUPPRESS_INTERRUPTS
  PANIC();
#else
  Ifx_CPU_ICR icr;
  uintptr_t *regs;

  icr.U = __mfcr(CPU_ICR);
  regs = (uintptr_t *)__mfcr(CPU_PCXI);

  board_autoled_on(LED_INIRQ);

  /* Nested interrupts are not supported */

  DEBUGASSERT(CURRENT_REGS == NULL);

  /* Current regs non-zero indicates that we are processing an interrupt;
   * CURRENT_REGS is also used to manage interrupt level context switches.
   */

  CURRENT_REGS = regs;

  /* Deliver the IRQ */

  irq_dispatch(icr.B.CCPN, regs);

  /* Check for a context switch.  If a context switch occurred, then
   * CURRENT_REGS will have a different value than it did on entry.  If an
   * interrupt level context switch has occurred, then restore the floating
   * point state and the establish the correct address environment before
   * returning from the interrupt.
   */

  if (regs != CURRENT_REGS)
    {
#ifdef CONFIG_ARCH_ADDRENV
      /* Make sure that the address environment for the previously
       * running task is closed down gracefully (data caches dump,
       * MMU flushed) and set up the address environment for the new
       * thread at the head of the ready-to-run list.
       */

      addrenv_switch(NULL);
#endif

      /* Record the new "running" task when context switch occurred.
       * g_running_tasks[] is only used by assertion logic for reporting
       * crashes.
       */

      g_running_tasks[this_cpu()] = this_task();

      __mtcr(CPU_PCXI, (uintptr_t)CURRENT_REGS);
      __isync();
    }

  /* Set CURRENT_REGS to NULL to indicate that we are no longer in an
   * interrupt handler.
   */

  CURRENT_REGS = NULL;

  board_autoled_off(LED_INIRQ);
#endif
}
