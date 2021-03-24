/************************************************************************************
 * arch/arm/src/sam34/chip.h
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

#ifndef __ARCH_ARM_SRC_SAM34_CHIP_H
#define __ARCH_ARM_SRC_SAM34_CHIP_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

/* Include the memory map and the chip definitions file.  Other chip hardware files
 * should then include this file for the proper setup.
 */

#include <arch/sam34/chip.h>
#include "hardware/sam_memorymap.h"

/* Include the chip interrupt definition file */

#include <arch/sam34/irq.h>

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* Provide the required number of peripheral interrupt vector definitions as well.
 * The definition SAM_IRQ_NEXTINT simply comes from the chip-specific IRQ header
 * file included by arch/sam34/irq.h.
 */

#define ARMV7M_PERIPHERAL_INTERRUPTS  SAM_IRQ_NEXTINT

#endif /* __ARCH_ARM_SRC_SAM34_CHIP_H */
