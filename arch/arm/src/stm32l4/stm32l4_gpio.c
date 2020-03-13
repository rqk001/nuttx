/****************************************************************************
 * arch/arm/src/stm32l4/stm32l4_gpio.c
 *
 *   Copyright (C) 2009, 2011-2012 Gregory Nutt. All rights reserved.
 *   Copyright (C) 2011 Uros Platise. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *           Uros Platise <uros.platise@isotel.eu>
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

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <debug.h>

#include <arch/irq.h>
#include <arch/stm32l4/chip.h>

#include "up_arch.h"

#include "chip.h"
#include "stm32l4_gpio.h"

#include "hardware/stm32l4_syscfg.h"

/****************************************************************************
 * Public Data
 ****************************************************************************/
/* Base addresses for each GPIO block */

const uint32_t g_gpiobase[STM32L4_NPORTS] =
{
#if STM32L4_NPORTS > 0
  STM32L4_GPIOA_BASE,
#endif
#if STM32L4_NPORTS > 1
  STM32L4_GPIOB_BASE,
#endif
#if STM32L4_NPORTS > 2
  STM32L4_GPIOC_BASE,
#endif
#if STM32L4_NPORTS > 3
  STM32L4_GPIOD_BASE,
#endif
#if STM32L4_NPORTS > 4
  STM32L4_GPIOE_BASE,
#endif
#if STM32L4_NPORTS > 5
  STM32L4_GPIOF_BASE,
#endif
#if STM32L4_NPORTS > 6
  STM32L4_GPIOG_BASE,
#endif
#if STM32L4_NPORTS > 7
  STM32L4_GPIOH_BASE,
#endif
#if STM32L4_NPORTS > 8
  STM32L4_GPIOI_BASE,
#endif
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function:  stm32l4_gpioinit
 *
 * Description:
 *   Based on configuration within the .config file, it does:
 *    - Remaps positions of alternative functions.
 *
 *   Typically called from stm32l4_start().
 *
 * Assumptions:
 *   This function is called early in the initialization sequence so that
 *   no mutual exclusion is necessary.
 *
 ****************************************************************************/

void stm32l4_gpioinit(void)
{
}

/****************************************************************************
 * Name: stm32l4_configgpio
 *
 * Description:
 *   Configure a GPIO pin based on bit-encoded description of the pin.
 *   Once it is configured as Alternative (GPIO_ALT|GPIO_CNF_AFPP|...)
 *   function, it must be unconfigured with stm32l4_unconfiggpio() with
 *   the same cfgset first before it can be set to non-alternative function.
 *
 * Returned Value:
 *   OK on success
 *   A negated errno value on invalid port, or when pin is locked as ALT
 *   function.
 *
 * To-Do: Auto Power Enable
 ****************************************************************************/

int stm32l4_configgpio(uint32_t cfgset)
{
  uintptr_t base;
  uint32_t regval;
  uint32_t setting;
  unsigned int regoffset;
  unsigned int port;
  unsigned int pin;
  unsigned int pos;
  unsigned int pinmode;
  irqstate_t flags;

  /* Verify that this hardware supports the select GPIO port */

  port = (cfgset & GPIO_PORT_MASK) >> GPIO_PORT_SHIFT;
  if (port >= STM32L4_NPORTS)
    {
      return -EINVAL;
    }

  /* Get the port base address */

  base = g_gpiobase[port];

  /* Get the pin number and select the port configuration register for that
   * pin
   */

  pin = (cfgset & GPIO_PIN_MASK) >> GPIO_PIN_SHIFT;

  /* Set up the mode register (and remember whether the pin mode) */

  switch (cfgset & GPIO_MODE_MASK)
    {
      default:
      case GPIO_INPUT:      /* Input mode */
        pinmode = GPIO_MODER_INPUT;
        break;

      case GPIO_OUTPUT:     /* General purpose output mode */
        stm32l4_gpiowrite(cfgset, (cfgset & GPIO_OUTPUT_SET) != 0); /* Set the initial output value */
        pinmode = GPIO_MODER_OUTPUT;
        break;

      case GPIO_ALT:        /* Alternate function mode */
        pinmode = GPIO_MODER_ALT;
        break;

      case GPIO_ANALOG:     /* Analog mode */
        pinmode = GPIO_MODER_ANALOG;
        break;
    }

  /* Interrupts must be disabled from here on out so that we have mutually
   * exclusive access to all of the GPIO configuration registers.
   */

  flags = enter_critical_section();

  /* Now apply the configuration to the mode register */

  regval  = getreg32(base + STM32L4_GPIO_MODER_OFFSET);
  regval &= ~GPIO_MODER_MASK(pin);
  regval |= ((uint32_t)pinmode << GPIO_MODER_SHIFT(pin));
  putreg32(regval, base + STM32L4_GPIO_MODER_OFFSET);

  /* Set up the pull-up/pull-down configuration (all but analog pins) */

  setting = GPIO_PUPDR_NONE;
  if (pinmode != GPIO_MODER_ANALOG)
    {
      switch (cfgset & GPIO_PUPD_MASK)
        {
          default:
          case GPIO_FLOAT:      /* No pull-up, pull-down */
            break;

          case GPIO_PULLUP:     /* Pull-up */
            setting = GPIO_PUPDR_PULLUP;
            break;

          case GPIO_PULLDOWN:   /* Pull-down */
            setting = GPIO_PUPDR_PULLDOWN;
            break;
        }
    }

  regval  = getreg32(base + STM32L4_GPIO_PUPDR_OFFSET);
  regval &= ~GPIO_PUPDR_MASK(pin);
  regval |= (setting << GPIO_PUPDR_SHIFT(pin));
  putreg32(regval, base + STM32L4_GPIO_PUPDR_OFFSET);

  /* Set the alternate function (Only alternate function pins) */

  if (pinmode == GPIO_MODER_ALT)
    {
      setting = (cfgset & GPIO_AF_MASK) >> GPIO_AF_SHIFT;
    }
  else
    {
      setting = 0;
    }

  if (pin < 8)
    {
      regoffset = STM32L4_GPIO_AFRL_OFFSET;
      pos       = pin;
    }
  else
    {
      regoffset = STM32L4_GPIO_AFRH_OFFSET;
      pos       = pin - 8;
    }

  regval  = getreg32(base + regoffset);
  regval &= ~GPIO_AFR_MASK(pos);
  regval |= (setting << GPIO_AFR_SHIFT(pos));
  putreg32(regval, base + regoffset);

  /* Set speed (Only outputs and alternate function pins) */

  if (pinmode == GPIO_MODER_OUTPUT || pinmode == GPIO_MODER_ALT)
    {
      switch (cfgset & GPIO_SPEED_MASK)
        {
          default:
          case GPIO_SPEED_2MHz:    /* 2 MHz Low speed output */
            setting = GPIO_OSPEED_2MHz;
            break;

          case GPIO_SPEED_25MHz:   /* 25 MHz Medium speed output */
            setting = GPIO_OSPEED_25MHz;
            break;

          case GPIO_SPEED_50MHz:   /* 50 MHz High speed output  */
            setting = GPIO_OSPEED_50MHz;
            break;

          case GPIO_SPEED_100MHz:   /* 100 MHz Very High speed output */
            setting = GPIO_OSPEED_100MHz;
            break;
        }
    }
  else
    {
      setting = 0;
    }

  regval  = getreg32(base + STM32L4_GPIO_OSPEED_OFFSET);
  regval &= ~GPIO_OSPEED_MASK(pin);
  regval |= (setting << GPIO_OSPEED_SHIFT(pin));
  putreg32(regval, base + STM32L4_GPIO_OSPEED_OFFSET);

  /* Set push-pull/open-drain (Only outputs and alternate function pins) */

  regval  = getreg32(base + STM32L4_GPIO_OTYPER_OFFSET);
  setting = GPIO_OTYPER_OD(pin);

  if ((pinmode == GPIO_MODER_OUTPUT || pinmode == GPIO_MODER_ALT) &&
      (cfgset & GPIO_OPENDRAIN) != 0)
    {
      regval |= setting;
    }
  else
    {
      regval &= ~setting;
    }

  putreg32(regval, base + STM32L4_GPIO_OTYPER_OFFSET);

  /* Otherwise, it is an input pin.  Should it configured as an EXTI interrupt? */

  if (pinmode != GPIO_MODER_OUTPUT && (cfgset & GPIO_EXTI) != 0)
    {
      /* The selection of the EXTI line source is performed through the EXTIx
       * bits in the SYSCFG_EXTICRx registers.
       *
       * The range of EXTI bit values in STM32L4x6 goes to 0b1000 to support the
       * ports up to PI in STM32L496xx devices. For STM32L4x3 the EXTI bit values
       * end at 0b111 (for PH0, PH1 and PH3 only) and values for non-existent
       * ports F and G are reserved.
       */

      uint32_t regaddr;
      int shift;

      /* Set the bits in the SYSCFG EXTICR register */

      regaddr = STM32L4_SYSCFG_EXTICR(pin);
      regval  = getreg32(regaddr);
      shift   = SYSCFG_EXTICR_EXTI_SHIFT(pin);
      regval &= ~(SYSCFG_EXTICR_PORT_MASK << shift);
      regval |= (((uint32_t)port) << shift);

      putreg32(regval, regaddr);
    }

  leave_critical_section(flags);
  return OK;
}

/****************************************************************************
 * Name: stm32l4_unconfiggpio
 *
 * Description:
 *   Unconfigure a GPIO pin based on bit-encoded description of the pin, set it
 *   into default HiZ state (and possibly mark it's unused) and unlock it whether
 *   it was previsouly selected as alternative function (GPIO_ALT|GPIO_CNF_AFPP|...).
 *
 *   This is a safety function and prevents hardware from schocks, as unexpected
 *   write to the Timer Channel Output GPIO to fixed '1' or '0' while it should
 *   operate in PWM mode could produce excessive on-board currents and trigger
 *   over-current/alarm function.
 *
 * Returned Value:
 *  OK on success
 *  A negated errno value on invalid port
 *
 * To-Do: Auto Power Disable
 ****************************************************************************/

int stm32l4_unconfiggpio(uint32_t cfgset)
{
  /* Reuse port and pin number and set it to default HiZ INPUT */

  cfgset &= GPIO_PORT_MASK | GPIO_PIN_MASK;
  cfgset |= GPIO_INPUT | GPIO_FLOAT;

  /* To-Do: Mark its unuse for automatic power saving options */

  return stm32l4_configgpio(cfgset);
}

/****************************************************************************
 * Name: stm32l4_gpiowrite
 *
 * Description:
 *   Write one or zero to the selected GPIO pin
 *
 ****************************************************************************/

void stm32l4_gpiowrite(uint32_t pinset, bool value)
{
  uint32_t base;
  uint32_t bit;
  unsigned int port;
  unsigned int pin;

  port = (pinset & GPIO_PORT_MASK) >> GPIO_PORT_SHIFT;
  if (port < STM32L4_NPORTS)
    {
      /* Get the port base address */

      base = g_gpiobase[port];

      /* Get the pin number  */

      pin = (pinset & GPIO_PIN_MASK) >> GPIO_PIN_SHIFT;

      /* Set or clear the output on the pin */

      if (value)
        {
          bit = GPIO_BSRR_SET(pin);
        }
      else
        {
          bit = GPIO_BSRR_RESET(pin);
        }

      putreg32(bit, base + STM32L4_GPIO_BSRR_OFFSET);

    }
}

/****************************************************************************
 * Name: stm32l4_gpioread
 *
 * Description:
 *   Read one or zero from the selected GPIO pin
 *
 ****************************************************************************/

bool stm32l4_gpioread(uint32_t pinset)
{
  uint32_t base;
  unsigned int port;
  unsigned int pin;

  port = (pinset & GPIO_PORT_MASK) >> GPIO_PORT_SHIFT;
  if (port < STM32L4_NPORTS)
    {
      /* Get the port base address */

      base = g_gpiobase[port];

      /* Get the pin number and return the input state of that pin */

      pin = (pinset & GPIO_PIN_MASK) >> GPIO_PIN_SHIFT;
      return ((getreg32(base + STM32L4_GPIO_IDR_OFFSET) & (1 << pin)) != 0);
    }
  return 0;
}
