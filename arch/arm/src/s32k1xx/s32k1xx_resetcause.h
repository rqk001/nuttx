/****************************************************************************
 * arch/arm/src/s32k1xx/s32k1xx_resetcause.h
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

#ifndef __ARCH_ARM_SRC_S32K1XX_RESETCAUSE_H
#define __ARCH_ARM_SRC_S32K1XX_RESETCAUSE_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: s32k1xx_resetcause_init
 *
 * Description: This function initializes the resetcause
 *              It will get the resetcause and store it
 *
 ****************************************************************************/

void s32k1xx_resetcause_init(void);

/****************************************************************************
 * Name: s32k1xx_resetcause_initialize_procfs
 *
 * Description:   This function registrates the reset cause as a proc fs
 *                Returns 0 if OK, error number otherwise
 *
 ****************************************************************************/

int s32k1xx_resetcause_initialize_procfs(void);

#endif /* __ARCH_ARM_SRC_S32K1XX_RESETCAUSE_H */
