/****************************************************************************
 * arch/risc-v/include/bl808/irq.h
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

#ifndef __ARCH_RISCV_INCLUDE_BL808_IRQ_H
#define __ARCH_RISCV_INCLUDE_BL808_IRQ_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Map RISC-V exception code to NuttX IRQ */

#define NR_IRQS (RISCV_IRQ_SEXT + 114)

#define BL808_IRQ_NUM_BASE (16)
#define BL808_M0_IRQ_OFFSET (64) // IRQs tied to M0 core are given a virtual IRQ number

/* D0 IRQs ******************************************************************/
#define BL808_IRQ_UART3 (RISCV_IRQ_SEXT + BL808_IRQ_NUM_BASE + 4)
#define BL808_IRQ_D0_IPC (RISCV_IRQ_SEXT + BL808_IRQ_NUM_BASE + 38)

/* M0 IRQs ******************************************************************/
#define BL808_IRQ_UART0 (RISCV_IRQ_SEXT + BL808_IRQ_NUM_BASE + BL808_M0_IRQ_OFFSET + 28)
#define BL808_IRQ_UART1 (RISCV_IRQ_SEXT + BL808_IRQ_NUM_BASE + BL808_M0_IRQ_OFFSET + 29)
#define BL808_IRQ_UART2 (RISCV_IRQ_SEXT + BL808_IRQ_NUM_BASE + BL808_M0_IRQ_OFFSET + 30)

#endif /* __ARCH_RISCV_INCLUDE_BL808_IRQ_H */
