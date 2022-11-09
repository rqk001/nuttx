/****************************************************************************
 * arch/arm/src/stm32/stm32_rtc.h
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

#ifndef __ARCH_ARM_SRC_STM32_STM32_RTC_H
#define __ARCH_ARM_SRC_STM32_STM32_RTC_H

#include <nuttx/config.h>

#include "chip.h"

/* The STM32 F1 has a simple battery-backed counter for its RTC and has a
 * separate block for the BKP registers.
 */

#if defined(CONFIG_STM32_STM32F10XX)
#  include "hardware/stm32_rtc.h"
#  include "hardware/stm32_bkp.h"

/* The other families use a more traditional Realtime Clock/Calendar (RTCC)
 * with broken-out data/time in BCD format.  The backup registers are
 * integrated into the RTCC in these families.
 */

#elif defined(CONFIG_STM32_STM32L15XX) || defined(CONFIG_STM32_STM32F20XX) || \
      defined(CONFIG_STM32_STM32F30XX) || defined(CONFIG_STM32_STM32F4XXX) || \
      defined(CONFIG_STM32_STM32G4XXX)
#  include "hardware/stm32_rtcc.h"
#endif

/* Alarm function differs from part to part */

#if defined(CONFIG_STM32_STM32F4XXX)
#  include "stm32f40xxx_alarm.h"
#elif defined(CONFIG_STM32_STM32L15XX)
#  include "stm32l15xxx_alarm.h"
#else
#  include "stm32_alarm.h"
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define STM32_RTC_PRESCALER_SECOND        32767  /* Default prescaler to get a
                                                  * second base */
#define STM32_RTC_PRESCALER_MIN           1      /* Maximum speed of 16384 Hz */

#if defined(CONFIG_STM32_STM32F10XX)
/* RTC is only a counter, store RTC data in backup domain register DR1 (if
 * CONFIG_RTC_HIRES) and DR2 (state).
 */

#if !defined(CONFIG_STM32_RTC_MAGIC)
#  define CONFIG_STM32_RTC_MAGIC          (0xface) /* only 16 bit */
#endif

#if !defined(CONFIG_STM32_RTC_MAGIC_TIME_SET)
#  define CONFIG_STM32_RTC_MAGIC_TIME_SET (0xf00d)
#endif

#define RTC_MAGIC_REG                     STM32_BKP_DR2

#else /* !CONFIG_STM32_STM32F10XX */

#if !defined(CONFIG_STM32_RTC_MAGIC)
#  define CONFIG_STM32_RTC_MAGIC          (0xfacefeed)
#endif

#if !defined(CONFIG_STM32_RTC_MAGIC_TIME_SET)
#  define CONFIG_STM32_RTC_MAGIC_TIME_SET (0xf00dface)
#endif

#if !defined(CONFIG_STM32_RTC_MAGIC_REG)
#  define CONFIG_STM32_RTC_MAGIC_REG      (0)
#endif

#if defined(CONFIG_STM32_STM32G4XXX)
#  define RTC_MAGIC_REG                   STM32_TAMP_BKR(CONFIG_STM32_RTC_MAGIC_REG)

#else
#  define RTC_MAGIC_REG                   STM32_RTC_BKR(CONFIG_STM32_RTC_MAGIC_REG)

#endif/* CONFIG_STM32_STM32G4XXX */

#endif /* CONFIG_STM32_STM32F10XX */

#define RTC_MAGIC                         CONFIG_STM32_RTC_MAGIC
#define RTC_MAGIC_TIME_SET                CONFIG_STM32_RTC_MAGIC_TIME_SET

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Public Data
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_rtc_irqinitialize
 *
 * Description:
 *   Initialize IRQs for RTC, not possible during up_rtc_initialize because
 *   up_irqinitialize is called later.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno on failure
 *
 ****************************************************************************/

int stm32_rtc_irqinitialize(void);

/****************************************************************************
 * Name: stm32_rtc_getdatetime_with_subseconds
 *
 * Description:
 *   Get the current date and time from the date/time RTC.  This interface
 *   is only supported by the date/time RTC hardware implementation.
 *   It is used to replace the system timer.  It is only used by the RTOS
 *   during initialization to set up the system time when CONFIG_RTC and
 *   CONFIG_RTC_DATETIME are selected (and CONFIG_RTC_HIRES is not).
 *
 *   NOTE: Some date/time RTC hardware is capability of sub-second accuracy.
 *   Thatsub-second accuracy is returned through 'nsec'.
 *
 * Input Parameters:
 *   tp - The location to return the high resolution time value.
 *   nsec - The location to return the subsecond time value.
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno on failure
 *
 ****************************************************************************/

#ifdef CONFIG_STM32_HAVE_RTC_SUBSECONDS
int stm32_rtc_getdatetime_with_subseconds(struct tm *tp, long *nsec);
#endif

/****************************************************************************
 * Name: stm32_rtc_setdatetime
 *
 * Description:
 *   Set the RTC to the provided time. RTC implementations which provide
 *   up_rtc_getdatetime() (CONFIG_RTC_DATETIME is selected) should provide
 *   this function.
 *
 * Input Parameters:
 *   tp - the time to use
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno on failure
 *
 ****************************************************************************/

#ifdef CONFIG_RTC_DATETIME
struct tm;
int stm32_rtc_setdatetime(const struct tm *tp);
#endif

/****************************************************************************
 * Name: stm32_rtc_lowerhalf
 *
 * Description:
 *   Instantiate the RTC lower half driver for the STM32.  General usage:
 *
 *     #include <nuttx/timers/rtc.h>
 *     #include "stm32_rtc.h"
 *
 *     struct rtc_lowerhalf_s *lower;
 *     lower = stm32_rtc_lowerhalf();
 *     rtc_initialize(0, lower);
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   On success, a non-NULL RTC lower interface is returned.  NULL is
 *   returned on any failure.
 *
 ****************************************************************************/

#ifdef CONFIG_RTC_DRIVER
struct rtc_lowerhalf_s;
struct rtc_lowerhalf_s *stm32_rtc_lowerhalf(void);
#endif

#undef EXTERN
#if defined(__cplusplus)
}
#endif
#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_STM32_STM32_RTC_H */
