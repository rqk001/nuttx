/****************************************************************************
 * arch/risc-v/src/bl602/bl602_oneshot.h
 *
 * Copyright (C) 2016 Gregory Nutt. All rights reserved.
 * Author: Gregory Nutt <gnutt@nuttx.org>
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

#ifndef __ARCH_ARM_SRC_BL602_ONESHOT_H
#define __ARCH_ARM_SRC_BL602_ONESHOT_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <time.h>

#include <nuttx/irq.h>

#include "bl602_tim_lowerhalf.h"

#ifdef CONFIG_BL602_ONESHOT

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#if !defined(CONFIG_BL602_ONESHOT_MAXTIMERS) || \
  CONFIG_BL602_ONESHOT_MAXTIMERS < 1
#undef CONFIG_BL602_ONESHOT_MAXTIMERS
#define CONFIG_BL602_ONESHOT_MAXTIMERS 1
#endif

#if CONFIG_BL602_ONESHOT_MAXTIMERS > 8
#warning Additional logic required to handle more than 8 timers
#undef CONFIG_BL602_ONESHOT_MAXTIMERS
#define CONFIG_BL602_ONESHOT_MAXTIMERS 8
#endif

/****************************************************************************
 * Public Types
 ****************************************************************************/

#ifndef __ASSEMBLY__
/* This describes the callback function that will be invoked when the oneshot
 * timer expires.  The oneshot fires, the client will receive:
 *
 *   arg - The opaque argument provided when the interrupt was registered
 */

typedef void (*oneshot_handler_t)(void *arg);

/* The oneshot client must allocate an instance of this structure and called
 * bl602_oneshot_initialize() before using the oneshot facilities.  The
 * client should not access the contents of this structure directly since
 * the contents are subject to change.
 */

struct bl602_oneshot_s
{
  uint8_t chan; /* The timer/counter in use */
#if CONFIG_BL602_ONESHOT_MAXTIMERS > 1
  uint8_t cbndx; /* Timer callback handler index */
#endif
  volatile bool               running; /* True: the timer is running */
  FAR struct bl602_tim_dev_s *tch;     /* Pointer returned by
                                        * bl602_tim_init() */
  volatile oneshot_handler_t handler;  /* Oneshot expiration callback */
  volatile void *            arg;      /* The argument that will accompany
                                        * the callback */
  uint32_t frequency;
  uint32_t period;
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
 * Name: bl602_oneshot_initialize
 *
 * Description:
 *   Initialize the oneshot timer wrapper
 *
 * Input Parameters:
 *   oneshot    Caller allocated instance of the oneshot state structure
 *   chan       Timer counter channel to be used.
 *   resolution The required resolution of the timer in units of
 *              microseconds.  NOTE that the range is restricted to the
 *              range of uint16_t (excluding zero).
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned
 *   on failure.
 *
 ****************************************************************************/

int bl602_oneshot_initialize(struct bl602_oneshot_s *oneshot,
                             int                     chan,
                             uint16_t                resolution);

/****************************************************************************
 * Name: bl602_oneshot_max_delay
 *
 * Description:
 *   Determine the maximum delay of the one-shot timer (in microseconds)
 *
 ****************************************************************************/

int bl602_oneshot_max_delay(struct bl602_oneshot_s *oneshot, uint64_t *usec);

/****************************************************************************
 * Name: bl602_oneshot_start
 *
 * Description:
 *   Start the oneshot timer
 *
 * Input Parameters:
 *   oneshot Caller allocated instance of the oneshot state structure.  This
 *           structure must have been previously initialized via a call to
 *           bl602_oneshot_initialize();
 *   handler The function to call when when the oneshot timer expires.
 *   arg     An opaque argument that will accompany the callback.
 *   ts      Provides the duration of the one shot timer.
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned
 *   on failure.
 *
 ****************************************************************************/

int bl602_oneshot_start(struct bl602_oneshot_s *oneshot,
                        oneshot_handler_t       handler,
                        void *                  arg,
                        const struct timespec * ts);

/****************************************************************************
 * Name: bl602_oneshot_cancel
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
 *           bl602_oneshot_initialize();
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

int bl602_oneshot_cancel(struct bl602_oneshot_s *oneshot,
                         struct timespec *       ts);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* CONFIG_BL602_ONESHOT */
#endif /* __ARCH_ARM_SRC_BL602_ONESHOT_H */
