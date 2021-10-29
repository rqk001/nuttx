/****************************************************************************
 * arch/arm/include/phy62xx/irq.h
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

/* This file should never be included directly but, rather, only indirectly
 * through nuttx/irq.h
 */

#ifndef __ARCH_ARM_INCLUDE_PHY62XX_IRQ_H
#define __ARCH_ARM_INCLUDE_PHY62XX_IRQ_H

/****************************************************************************
 * Included Files
 ****************************************************************************/
#  include <arch/phy62xx/phy62xx_irq.h>

#ifndef __ASSEMBLY__
#  include <stdint.h>
#endif

/****************************************************************************
 * Pre-processor Prototypes
 ****************************************************************************/

/* IRQ numbers.  The IRQ number corresponds vector number and hence map
 * directly to bits in the NVIC.  This does, however, waste several words of
 * memory in the IRQ to handle mapping tables.
 */

/* Common Processor Exceptions (vectors 0-15) */

#define PHY62XX_IRQ_RESERVED       (0) /* Reserved vector (only used with CONFIG_DEBUG_FEATURES) */

                /* Vector  0: Reset stack pointer value */

                /* Vector  1: Reset (not handler as an IRQ) */

#define PHY62XX_IRQ_NMI            (2) /* Vector  2: Non-Maskable Interrupt (NMI) */
#define PHY62XX_IRQ_HARDFAULT      (3) /* Vector  3: Hard fault */

                /* Vectors 4-10: Reserved */

#define PHY62XX_IRQ_SVCALL        (11) /* Vector 11: SVC call */

                /* Vector 12-13: Reserved */

#define PHY62XX_IRQ_PENDSV        (14) /* Vector 14: Pendable system service request */
#define PHY62XX_IRQ_SYSTICK       (15) /* Vector 15: System tick */

/* External interrupts (vectors >= 16) */

#define PHY62XX_IRQ_EXTINT        (16) /* Vector number of the first external interrupt */

/****************************************************************************
 * Included Files
 ****************************************************************************/

/* Include MCU-specific external interrupt definitions */

#define NR_IRQS                 (PHY62XX_IRQ_EXTINT + PHY62XX_IRQ_NEXTINT)

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__
typedef void (*vic_vector_t)(uint32_t *regs);

/****************************************************************************
 * Inline functions
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif
#endif /* __ASSEMBLY__ */

#endif /* __ARCH_ARM_INCLUDE_STM32F0L0G0_IRQ_H */
