/****************************************************************************
 * arch/arm/src/ameba/ameba_vectors.c
 *
 *   Copyright (C) 2012 Michael Smith. All rights reserved.
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

#include "chip.h"
#include "arm_internal.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

extern uint32_t         __stack;
#define IDLE_STACK      ((unsigned)&__stack - 4)

#ifndef ARMV8M_PERIPHERAL_INTERRUPTS
#  error ARMV8M_PERIPHERAL_INTERRUPTS must be defined to the number of I/O interrupts to be supported
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/* Chip-specific entrypoint */

extern void ram_start(void);

/* Common exception entrypoint */

extern void exception_common(void);

/************************************************************************************
 * Public data
 ************************************************************************************/

/* The v7m vector table consists of an array of function pointers, with the first
 * slot (vector zero) used to hold the initial stack pointer.
 *
 * As all exceptions (interrupts) are routed via exception_common, we just need to
 * fill this array with pointers to it.
 *
 * Note that the [ ... ] designated initialiser is a GCC extension.
 */

unsigned _vectors[] __attribute__((section(".vectors"))) __attribute__((aligned(0x100))) =
{
  /* Initial stack */

  IDLE_STACK,

  /* Reset exception handler */

  (unsigned)&ram_start,

  /* Vectors 2 - n point directly at the generic handler */

  [2 ... (15 + ARMV8M_PERIPHERAL_INTERRUPTS)] = (unsigned)&exception_common
};

