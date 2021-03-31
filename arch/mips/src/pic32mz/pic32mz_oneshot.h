/****************************************************************************
 * arch/mips/src/pic32mz/pic32mz_oneshot.h
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

#ifndef __ARCH_MIPS_SRC_PIC32MZ_PIC32MZ_ONESHOT_H
#define __ARCH_MIPS_SRC_PIC32MZ_PIC32MZ_ONESHOT_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <time.h>

#include <nuttx/irq.h>

#include "pic32mz_timer.h"

#ifdef CONFIG_PIC32MZ_ONESHOT

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#if !defined(CONFIG_PIC32MZ_ONESHOT_MAXTIMERS) || \
    CONFIG_PIC32MZ_ONESHOT_MAXTIMERS < 1
#  undef CONFIG_PIC32MZ_ONESHOT_MAXTIMERS
#  define CONFIG_PIC32MZ_ONESHOT_MAXTIMERS 1
#endif

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* This describes the callback function that will be invoked when the oneshot
 * timer expires. When the oneshot fires, the client will receive:
 *
 *   arg - The opaque argument provided when the interrupt was registered
 */

typedef void (*oneshot_handler_t)(void *arg);

/* The oneshot client must allocate an instance of this structure and called
 * pic32mz_oneshot_initialize() before using the oneshot facilities.
 * The client should not access the contents of this structure directly
 * since the contents are subject to change.
 */

struct pic32mz_oneshot_s
{
  uint8_t chan;                          /* The timer/counter in use      */
#if CONFIG_PIC32MZ_ONESHOT_MAXTIMERS > 1
  uint8_t cbndx;                         /* Timer callback handler index  */
#endif
  volatile bool running;                 /* True: the timer is running    */
  FAR struct pic32mz_timer_dev_s *timer; /* PIC32MZ timer driver          */
  volatile oneshot_handler_t handler;    /* Oneshot expiration callback   */
  volatile void *arg;                    /* Callback's argument           */
  uint32_t freq;                         /* Timer's frequency             */
  uint32_t period;                       /* Timer's period                */
  uint8_t  width;                        /* Timer's width                 */
};

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
 * Name: pic32mz_oneshot_initialize
 *
 * Description:
 *   Initialize the oneshot timer wrapper
 *
 * Input Parameters:
 *   oneshot    Caller allocated instance of the oneshot state structure
 *   chan       Timer counter channel to be used.
 *   resolution The required resolution of the timer in units of
 *              microseconds. NOTE that the range is restricted to the
 *              range of uint16_t (excluding zero).
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned
 *   on failure.
 *
 ****************************************************************************/

int pic32mz_oneshot_initialize(struct pic32mz_oneshot_s *oneshot, int chan,
                               uint16_t resolution);

/****************************************************************************
 * Name: pic32mz_oneshot_max_delay
 *
 * Description:
 *   Determine the maximum delay of the one-shot timer (in microseconds)
 *
 ****************************************************************************/

int pic32mz_oneshot_max_delay(struct pic32mz_oneshot_s *oneshot,
                              uint64_t *usec);

/****************************************************************************
 * Name: pic32mz_oneshot_start
 *
 * Description:
 *   Start the oneshot timer
 *
 * Input Parameters:
 *   oneshot Caller allocated instance of the oneshot state structure.  This
 *           structure must have been previously initialized via a call to
 *           pic32mz_oneshot_initialize();
 *   handler The function to call when when the oneshot timer expires.
 *   arg     An opaque argument that will accompany the callback.
 *   ts      Provides the duration of the one shot timer.
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned
 *   on failure.
 *
 ****************************************************************************/

int pic32mz_oneshot_start(struct pic32mz_oneshot_s *oneshot,
                          oneshot_handler_t handler, void *arg,
                          const struct timespec *ts);

/****************************************************************************
 * Name: pic32mz_oneshot_cancel
 *
 * Description:
 *   Cancel the oneshot timer and return the time remaining on the timer.
 *
 *   NOTE: This function may execute at a high rate with no timer running (as
 *   when pre-emption is enabled and disabled).
 *
 * Input Parameters:
 *   oneshot Caller allocated instance of the oneshot state structure.  This
 *           structure must have been previously initialized via a call to
 *           pic32mz_oneshot_initialize();
 *   ts      The location in which to return the time remaining on the
 *           oneshot timer.  A time of zero is returned if the timer is
 *           not running.
 *
 * Returned Value:
 *   Zero (OK) is returned on success.  A call to up_timer_cancel() when
 *   the timer is not active should also return success; a negated errno
 *   value is returned on any failure.
 *
 ****************************************************************************/

int pic32mz_oneshot_cancel(struct pic32mz_oneshot_s *oneshot,
                           struct timespec *ts);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* CONFIG_PIC32MZ_ONESHOT */
#endif /* __ARCH_MIPS_SRC_PIC32MZ_PIC32MZ_ONESHOT_H */
