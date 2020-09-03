/****************************************************************************
 * arch/arm/src/nrf52/nrf52_timerisr.c
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <time.h>
#include <debug.h>

#include <nuttx/arch.h>
#include <arch/board/board.h>
#include <nuttx/timers/arch_timer.h>

#include "nvic.h"
#include "clock/clock.h"
#include "arm_internal.h"
#include "arm_arch.h"

#if defined(CONFIG_NRF52_SYSTIMER_SYSTICK)
#include "systick.h"
#elif defined(CONFIG_NRF52_SYSTIMER_RTC)
#include "nrf52_rtc_lowerhalf.h"
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function:  up_timer_initialize
 *
 * Description:
 *   This function is called during start-up to initialize
 *   the timer interrupt.
 *
 ****************************************************************************/

void up_timer_initialize(void)
{
  struct timer_lowerhalf_s *lower;

#if defined(CONFIG_NRF52_SYSTIMER_SYSTICK)
  /* Use SysTick to drive system timer  */

  lower = systick_initialize(true, BOARD_SYSTICK_CLOCK, -1);
#elif defined(CONFIG_NRF52_SYSTIMER_RTC)
  /* Use RTC to drive system timer  */

  nrf52_rtc_initialize("/dev/systimer", CONFIG_NRF52_SYSTIMER_RTC_INSTANCE,
                       &lower);
#endif

  up_timer_set_lowerhalf(lower);
}
