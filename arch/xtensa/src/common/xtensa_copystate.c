/****************************************************************************
 * arch/xtensa/src/common/xtensa_copystate.c
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
#include <arch/irq.h>

#include "xtensa.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: xtensa_copystate
 ****************************************************************************/

/* A little faster than most memcpy's */

void xtensa_copystate(uint32_t *dest, uint32_t *src)
{
  int i;

  /* In the XTENSA model, the state is copied from the stack to the TCB,
   * but only a reference is passed to get the state from the TCB.  So the
   * following check avoids copying the TCB save area onto itself:
   */

  if (src != dest)
    {
#if XCHAL_CP_NUM > 0
      uintptr_t cpstate;
      uintptr_t cpstate_off;
      cpstate_off = offsetof(struct xcptcontext, cpstate) -
                    offsetof(struct xcptcontext, regs);
      cpstate = (uintptr_t)dest + cpstate_off;

      xtensa_coproc_savestate(cpstate);
#endif

      for (i = 0; i < XCPTCONTEXT_REGS; i++)
        {
          *dest++ = *src++;
        }
    }
}
