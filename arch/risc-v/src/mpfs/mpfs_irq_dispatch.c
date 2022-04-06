/****************************************************************************
 * arch/risc-v/src/mpfs/mpfs_irq_dispatch.c
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
#include <nuttx/board.h>
#include <arch/board/board.h>

#include "riscv_internal.h"

#include "group/group.h"
#include "hardware/mpfs_memorymap.h"
#include "hardware/mpfs_plic.h"

#include "mpfs_plic.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * riscv_dispatch_irq
 ****************************************************************************/

void *riscv_dispatch_irq(uintptr_t vector, uintptr_t *regs)
{
  int irq = (vector & 0x3f);
  uintptr_t *mepc = regs;

  /* Check if fault happened  */

  if (vector < RISCV_IRQ_ECALLU ||
      vector == RISCV_IRQ_INSTRUCTIONPF ||
      vector == RISCV_IRQ_LOADPF ||
      vector == RISCV_IRQ_STOREPF ||
      vector == RISCV_IRQ_RESERVED)
    {
      riscv_exception(irq, regs);
    }

  if ((vector & RISCV_IRQ_BIT) != 0)
    {
       irq += MPFS_IRQ_ASYNC;
    }

  /* Firstly, check if the irq is machine external interrupt */

  uintptr_t claim_address = mpfs_plic_get_claimbase();

  if (irq == RISCV_IRQ_MEXT)
    {
      uint32_t ext = getreg32(claim_address);

      /* Add the value to nuttx irq which is offset to the mext */

      irq = MPFS_IRQ_EXT_START + ext;
    }

  /* NOTE: In case of ecall, we need to adjust mepc in the context */

  if (irq == RISCV_IRQ_ECALLM || irq == RISCV_IRQ_ECALLU)
    {
      *mepc += 4;
    }

  /* Acknowledge the interrupt */

  riscv_ack_irq(irq);

  /* MEXT means no interrupt */

  if (irq != RISCV_IRQ_MEXT && irq != MPFS_IRQ_INVALID)
    {
      /* Deliver the IRQ */

      regs = riscv_doirq(irq, regs);
    }

  if (irq > MPFS_IRQ_EXT_START)
    {
      /* Then write PLIC_CLAIM to clear pending in PLIC */

      putreg32(irq - MPFS_IRQ_EXT_START, claim_address);
    }

  return regs;
}
