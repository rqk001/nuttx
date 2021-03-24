/****************************************************************************
 * arch/arm/src/stm32/stm32_dfumode.h
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

#ifndef __ARCH_ARM_SRC_STM32_DFUMODE_H
#define __ARCH_ARM_SRC_STM32_DFUMODE_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/compiler.h>

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name:  stm32_dfumode
 *
 * Description:
 *   Reboot the part in DFU mode.
 *
 *   https://community.st.com/s/question/0D50X00009XkhAzSAJ/calling-stm32429ieval-bootloader
 *
 ****************************************************************************/

#if defined(CONFIG_STM32_STM32F20XX) || defined(CONFIG_STM32_STM32F4XXX)
void stm32_dfumode(void) noreturn_function;
#endif

#endif /* __ARCH_ARM_SRC_STM32_DFUMODE_H */
