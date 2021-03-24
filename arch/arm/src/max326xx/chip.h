/************************************************************************************
 * arch/arm/src/max326xx/chip.h
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
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_MAX326XX_CHIP_H
#define __ARCH_ARM_SRC_MAX326XX_CHIP_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

/* Include the memory map and the chip features and IRQ definition file.  */

#include <arch/irq.h>
#include <arch/max326xx/chip.h>

/* The common ARMv7-M vector handling logic expects the following definition in this
 * file.  ARMV7M_PERIPHERAL_INTERRUPTS provides the number of supported external
 * interrupts which, for this architecture, is provided in the arch/max326xx/irq.h
 * header file.
 */

#define ARMV7M_PERIPHERAL_INTERRUPTS MAX326_IRQ_NEXTINT

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/************************************************************************************
 * Public Types
 ************************************************************************************/

/************************************************************************************
 * Public Data
 ************************************************************************************/

/************************************************************************************
 * Public Functions
 ************************************************************************************/

#endif /* __ARCH_ARM_SRC_MAX326XX_CHIP_H */
