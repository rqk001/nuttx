/****************************************************************************
 * arch/arm/src/at32/at32_pmsleep.c
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

#include <stdbool.h>

#include "arm_internal.h"
#include "nvic.h"
#include "at32_pwr.h"
#include "at32_pm.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: at32_pmsleep
 *
 * Description:
 *   Enter SLEEP mode.
 *
 * Input Parameters:
 *   sleeponexit - true:  SLEEPONEXIT bit is set when the WFI instruction is
 *                        executed, the MCU enters Sleep mode as soon as it
 *                        exits the lowest priority ISR.
 *               - false: SLEEPONEXIT bit is cleared, the MCU enters Sleep
 *                        mode as soon as WFI or WFE instruction is executed.
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void at32_pmsleep(bool sleeponexit)
{
  uint32_t regval;

  /* Clear SLEEPDEEP bit of Cortex System Control Register */

  regval  = getreg32(NVIC_SYSCON);
  regval &= ~NVIC_SYSCON_SLEEPDEEP;
  if (sleeponexit)
    {
      regval |= NVIC_SYSCON_SLEEPONEXIT;
    }
  else
    {
      regval &= ~NVIC_SYSCON_SLEEPONEXIT;
    }

  putreg32(regval, NVIC_SYSCON);

  /* Sleep until the wakeup interrupt or event occurs */

#ifdef CONFIG_PM_WFE
  /* Mode: SLEEP + Entry with WFE */

  asm("wfe");
#else
  /* Mode: SLEEP + Entry with WFI */

  asm("wfi");
#endif
}
