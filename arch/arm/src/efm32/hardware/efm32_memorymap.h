/****************************************************************************
 * arch/arm/src/efm32/hardware/efm32_memorymap.h
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

#ifndef __ARCH_ARM_SRC_EFM32_CHIP_EFM32_MEMORYMAP_H
#define __ARCH_ARM_SRC_EFM32_CHIP_EFM32_MEMORYMAP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include "chip.h"

#if defined(CONFIG_EFM32_EFM32TG)
#  include "hardware/efm32tg_memorymap.h"
#elif defined(CONFIG_EFM32_EFM32G)
#  include "hardware/efm32g_memorymap.h"
#elif defined(CONFIG_EFM32_EFM32GG)
#  include "hardware/efm32gg_memorymap.h"
#else
#  error "Unsupported EFM32 memory map"
#endif

#endif /* __ARCH_ARM_SRC_EFM32_CHIP_EFM32_MEMORYMAP_H */
