/****************************************************************************
 * arch/x86/src/common/x86_assert.c
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
#include <debug.h>

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/board.h>

#include <arch/board/board.h>

#include "sched/sched.h"
#include "x86_internal.h"

/****************************************************************************
 * Private Data
 ****************************************************************************/

static uint32_t s_last_regs[XCPTCONTEXT_REGS];

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_assert
 ****************************************************************************/

void up_assert(void)
{
  board_autoled_on(LED_ASSERTION);

  if (g_current_regs != NULL)
    {
      x86_registerdump((uint32_t *)g_current_regs);
    }
  else
    {
      /* Capture and dump user registers by hand */

      up_saveusercontext(s_last_regs);
      x86_registerdump(s_last_regs);
    }
}
