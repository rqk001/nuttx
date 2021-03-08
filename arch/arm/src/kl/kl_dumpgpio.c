/****************************************************************************
 * arch/arm/src/kl/kl_dumpgpio.c
 *
 *   Copyright (C) 2013, 2016 Gregory Nutt. All rights reserved.
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

/* Output debug info even if debug output is not selected. */

#undef  CONFIG_DEBUG_INFO
#define CONFIG_DEBUG_INFO 1

#include <sys/types.h>
#include <debug.h>

#include <nuttx/irq.h>
#include "arm_arch.h"

#include "chip.h"
#include "kl_gpio.h"

#ifdef CONFIG_DEBUG_FEATURES

/****************************************************************************
 * Private Data
 ****************************************************************************/
/* Port letters for prettier debug output */

static const char g_portchar[KL_GPIO_NPORTS] =
{
#if KL_GPIO_NPORTS > 9
#  error "Additional support required for this number of GPIOs"
#elif KL_GPIO_NPORTS > 8
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'
#elif KL_GPIO_NPORTS > 7
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
#elif KL_GPIO_NPORTS > 6
  'A', 'B', 'C', 'D', 'E', 'F', 'G'
#elif KL_GPIO_NPORTS > 5
  'A', 'B', 'C', 'D', 'E', 'F'
#elif KL_GPIO_NPORTS > 4
  'A', 'B', 'C', 'D', 'E'
#elif KL_GPIO_NPORTS > 3
  'A', 'B', 'C', 'D'
#elif KL_GPIO_NPORTS > 2
  'A', 'B', 'C'
#elif KL_GPIO_NPORTS > 1
  'A', 'B'
#elif KL_GPIO_NPORTS > 0
  'A'
#else
#  error "Bad number of GPIOs"
#endif
};

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function:  kl_dumpgpio
 *
 * Description:
 *   Dump all GPIO registers associated with the provided pin description
 *   along with a descriptive messasge.
 *
 ****************************************************************************/

void kl_dumpgpio(gpio_cfgset_t pinset, const char *msg)
{
  irqstate_t flags;
  uintptr_t base;
  int port;

  /* Decode the port and pin.  Use the port number to get the GPIO base
   * address.
   */

  port = (pinset & _PIN_PORT_MASK) >> _PIN_PORT_SHIFT;
  DEBUGASSERT((unsigned)port < KL_GPIO_NPORTS);
  base = KL_GPIO_BASE(port);

  /* The following requires exclusive access to the GPIO registers */

  flags = enter_critical_section();

  _info("GPIO%c pinset: %08x base: %08x -- %s\n",
       g_portchar[port], pinset, base, msg);
  _info("  PDOR: %08x  PDIR: %08x  PDDR: %08x\n",
       getreg32(base + KL_GPIO_PDOR_OFFSET),
       getreg32(base + KL_GPIO_PDIR_OFFSET),
       getreg32(base + KL_GPIO_PDDR_OFFSET));

  leave_critical_section(flags);
}

#endif /* CONFIG_DEBUG_FEATURES */
