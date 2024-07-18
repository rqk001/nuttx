/****************************************************************************
 * arch/arm/src/armv7-a/arm_undefinedinsn.c
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
#include <debug.h>

#include <nuttx/arch.h>

#include "arm_internal.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: arm_undefinedinsn
 ****************************************************************************/

uint32_t *arm_undefinedinsn(uint32_t *regs)
{
  /* Save the saved processor context in current_regs where it can be
   * accessed for register dumps and possibly context switching.
   */

  up_set_current_regs(regs);

  if (regs[REG_PC] >= (uint32_t)_stext && regs[REG_PC] < (uint32_t)_etext)
    {
      _alert("Undefined instruction at 0x%" PRIx32 ": 0x%" PRIx32 "\n",
             regs[REG_PC], *(uint32_t *)regs[REG_PC]);
    }
  else
    {
      _alert("Undefined instruction at 0x%" PRIx32 "\n", regs[REG_PC]);
    }

  PANIC_WITH_REGS("panic", regs);
  return regs; /* To keep the compiler happy */
}
