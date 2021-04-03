/****************************************************************************
 * arch/renesas/src/m16c/m16c_initialstate.c
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
#include <string.h>

#include <nuttx/arch.h>
#include <arch/board/board.h>

#include "up_internal.h"
#include "up_arch.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_initial_state
 *
 * Description:
 *   A new thread is being started and a new TCB has been created. This
 *   function is called to initialize the processor specific portions of the
 *   new TCB.
 *
 *   This function must setup the initial architecture registers and/or stack
 *   so that execution will begin at tcb->start on the next context switch.
 *
 ****************************************************************************/

void up_initial_state(FAR struct tcb_s *tcb)
{
  FAR struct xcptcontext *xcp  = &tcb->xcp;
  FAR uint8_t            *regs = xcp->regs;

  /* Initialize the idle thread stack */

  if (tcb->pid == 0)
    {
      tcb->stack_alloc_ptr = (void *)(g_idle_topstack -
                                      CONFIG_IDLETHREAD_STACKSIZE);
      tcb->adj_stack_ptr   = (void *)g_idle_topstack;
      tcb->adj_stack_size  = CONFIG_IDLETHREAD_STACKSIZE;
    }

  /* Initialize the initial exception register context structure */

  memset(xcp, 0, sizeof(struct xcptcontext));

  /* Offset 0: FLG (bits 12-14) PC (bits 16-19) as would be present by an
   * interrupt
   */

  *regs++ = ((M16C_DEFAULT_IPL << 4) | ((uint32_t)tcb->start >> 16));

  /* Offset 1: FLG (bits 0-7) */

#ifdef CONFIG_SUPPRESS_INTERRUPTS
  *regs++ = M16C_FLG_U;
#else
  *regs++ = M16C_FLG_U | M16C_FLG_I;
#endif

  /* Offset 2-3: 16-bit PC [0]:bits8-15 [1]:bits 0-7 */

  *regs++ = (uint32_t)tcb->start >> 8;  /* Bits 8-15 of PC */
  *regs++ = (uint32_t)tcb->start;       /* Bits 0-7 of PC */

  /* Offset 18-20: User stack pointer */

  regs    = &xcp->regs[REG_SP];
  *regs++ = (uint32_t)tcb->adj_stack_ptr >> 8;  /* Bits 8-15 of SP */
  *regs   = (uint32_t)tcb->adj_stack_ptr;       /* Bits 0-7 of SP */
}
