/************************************************************************************
 * arch/arm/src/lpc55xx/lpc55_start.h
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
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_LPC55XX_LPC55_START_H
#define __ARCH_ARM_SRC_LPC55XX_LPC55_START_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>

#include "arm_internal.h"
#include "chip.h"

/************************************************************************************
 * Public Data
 ************************************************************************************/

#ifndef __ASSEMBLY__

/* g_idle_topstack: _sbss is the start of the BSS region as defined by the linker
 * script. _ebss lies at the end of the BSS region. The idle task stack starts at
 * the end of BSS and is of size CONFIG_IDLETHREAD_STACKSIZE.  The IDLE thread is
 * the thread that the system boots on and, eventually, becomes the IDLE, do
 * nothing task that runs only when there is nothing else to run.  The heap
 * continues from there until the end of memory.  g_idle_topstack is a read-only
 * variable the provides this computed address.
 */

extern const uintptr_t g_idle_topstack;

/************************************************************************************
 * Public Function Prototypes
 ************************************************************************************/

/************************************************************************************
 * Name: lpc55_board_initialize
 *
 * Description:
 *   All LPC55xx architectures must provide the following entry point.  This entry
 *   point is called early in the initialization -- after clocking and memory have
 *   been configured but before caches have been enabled and before any devices have
 *   been initialized.
 *
 ************************************************************************************/

void lpc55_board_initialize(void);

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_LPC55XX_LPC55_START_H */
