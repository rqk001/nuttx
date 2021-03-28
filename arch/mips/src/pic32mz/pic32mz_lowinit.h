/************************************************************************************
 * arch/mips/src/pic32mz/pic32mz_lowinit.h
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

#ifndef __ARCH_MIPS_SRC_PIC32MZ_PIC32MZ_LOWINIT_H
#define __ARCH_MIPS_SRC_PIC32MZ_PIC32MZ_LOWINIT_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>

#include <stdbool.h>

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/************************************************************************************
 * Public Types
 ************************************************************************************/

#ifndef __ASSEMBLY__

/************************************************************************************
 * Public Data
 ************************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/************************************************************************************
 * Public Function Prototypes
 ************************************************************************************/

/************************************************************************************
 * Name: pic32mz_lowinit
 *
 * Description:
 *   This performs basic low-level initialization of the system.
 *
 ************************************************************************************/

void pic32mz_lowinit(void);

/************************************************************************************
 * Name: pic32mz_boardinitialize
 *
 * Description:
 *   This function must be provided by the board-specific logic in the  directory
 *   boards/mips/pic32mz/<board-name>/src/pic32mz_boot.c.
 *
 ************************************************************************************/

void pic32mz_boardinitialize(void);

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_MIPS_SRC_PIC32MZ_PIC32MZ_LOWINIT_H */
