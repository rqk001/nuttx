/****************************************************************************
 * boards/mips/pic32mx/pic32mx-starterkit/src/pic32mx_leds.c
 *
 *   Copyright (C) 2011, 2015 Gregory Nutt. All rights reserved.
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
#include <stdbool.h>
#include <debug.h>

#include <nuttx/board.h>
#include <arch/board/board.h>

#include "chip.h"
#include "mips_arch.h"
#include "mips_internal.h"

#include "pic32mx.h"
#include "pic32mx_ioport.h"
#include "pic32mx-starterkit.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* LED Configuration ********************************************************/

/* The PIC32MX Ethernet Starter kit has 3 user LEDs labelled LED1-3 on the
 * board graphics (but referred to as LED4-6 in the schematic):
 *
 * PIN User's Guide  Board Stencil  Notes
 * --- ------------- -------------- -------------------------
 * RD0 "User LED D4" "LED1 (RD0")   High illuminates (RED)
 * RD2 "User LED D5" "LED3 (RD2)"   High illuminates (YELLOW)
 * RD1 "User LED D6" "LED2 (RD1)"   High illuminates (GREEN)
 *
 * We will use the labels on the board to identify LEDs
 *
 *                           ON                  OFF
 * ------------------------- ---- ---- ---- ---- ---- ----
 *                           LED1 LED2 LED3 LED1 LED2 LED3
 * ------------------------- ---- ---- ---- ---- ---- ----
 * LED_STARTED            0  OFF  OFF  OFF  ---  ---  ---
 * LED_HEAPALLOCATE       1  ON   OFF  N/C  ---  ---  ---
 * LED_IRQSENABLED        2  OFF  ON   N/C  ---  ---  ---
 * LED_STACKCREATED       3  ON   ON   N/C  ---  ---  ---
 * LED_INIRQ              4  N/C  N/C  ON   N/C  N/C  OFF
 * LED_SIGNAL             4  N/C  N/C  ON   N/C  N/C  OFF
 * LED_ASSERTION          4  N/C  N/C  ON   N/C  N/C  OFF
 * LED_PANIC              5  ON   N/C  N/C  OFF  N/C  N/C
 */

#define GPIO_LED_1   (GPIO_OUTPUT|GPIO_VALUE_ZERO|GPIO_PORTD|GPIO_PIN0)
#define GPIO_LED_2   (GPIO_OUTPUT|GPIO_VALUE_ZERO|GPIO_PORTD|GPIO_PIN1)
#define GPIO_LED_3   (GPIO_OUTPUT|GPIO_VALUE_ZERO|GPIO_PORTD|GPIO_PIN2)

/* LED Management Definitions ***********************************************/

#ifdef CONFIG_ARCH_LEDS
#  define LED_OFF 0
#  define LED_ON  1
#  define LED_NC  2
#endif

/****************************************************************************
 * Private types
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
struct led_setting_s
{
  uint8_t led1   : 2;
  uint8_t led2   : 2;
  uint8_t led3   : 2;
  uint8_t unused : 2;
};
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* If CONFIG_ARCH_LEDS is defined then NuttX will control the LEDs.  The
 * following structures identified the LED settings for each NuttX LED state.
 */

#ifdef CONFIG_ARCH_LEDS
static const struct led_setting_s g_ledonvalues[LED_NVALUES] =
{
  {LED_OFF, LED_OFF, LED_OFF, LED_OFF},
  {LED_ON,  LED_OFF, LED_NC,  LED_OFF},
  {LED_OFF, LED_ON,  LED_NC,  LED_OFF},
  {LED_ON,  LED_ON,  LED_NC,  LED_OFF},
  {LED_NC,  LED_NC,  LED_ON,  LED_OFF},
  {LED_ON,  LED_NC,  LED_NC,  LED_OFF},
};

static const struct led_setting_s g_ledoffvalues[LED_NVALUES] =
{
  {LED_NC,  LED_NC,  LED_NC,  LED_OFF},
  {LED_NC,  LED_NC,  LED_NC,  LED_OFF},
  {LED_NC,  LED_NC,  LED_NC,  LED_OFF},
  {LED_NC,  LED_NC,  LED_NC,  LED_OFF},
  {LED_NC,  LED_NC,  LED_OFF, LED_OFF},
  {LED_OFF, LED_NC,  LED_NC,  LED_OFF},
};

/* If CONFIG_ARCH_LEDS is not defined, then the user can control the LEDs in
 * any way.  The following array simply maps the PIC32MX_STARTERKIT_LEDn
 * index values to the correct LED pin configuration.
 */

#else
static const uint16_t g_ledpincfg[PIC32MX_STARTERKIT_NLEDS] =
{
  GPIO_LED_1, GPIO_LED_2, GPIO_LED_3
};
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: pic32mx_setleds
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
static void pic32mx_setleds(FAR const struct led_setting_s *setting)
{
  if (setting->led1 != LED_NC)
    {
      pic32mx_gpiowrite(GPIO_LED_1, setting->led1 == LED_ON);
    }

  if (setting->led2 != LED_NC)
    {
      pic32mx_gpiowrite(GPIO_LED_2, setting->led2 == LED_ON);
    }

  if (setting->led3 != LED_NC)
    {
      pic32mx_gpiowrite(GPIO_LED_3, setting->led3 == LED_ON);
    }
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: board_userled_initialize
 ****************************************************************************/

#ifndef CONFIG_ARCH_LEDS
void board_userled_initialize(void)
{
  /* Configure output pins */

  pic32mx_configgpio(GPIO_LED_1);
  pic32mx_configgpio(GPIO_LED_2);
  pic32mx_configgpio(GPIO_LED_3);
}
#endif

/****************************************************************************
 * Name: board_userled
 ****************************************************************************/

#ifndef CONFIG_ARCH_LEDS
void board_userled(int led, bool ledon)
{
  if ((unsigned)led < PIC32MX_STARTERKIT_NLEDS)
    {
      pic32mx_gpiowrite(g_ledpincfg[led], ledon);
    }
}
#endif

/****************************************************************************
 * Name: board_userled_all
 ****************************************************************************/

#ifndef CONFIG_ARCH_LEDS
void board_userled_all(uint8_t ledset)
{
  board_userled(PIC32MX_STARTERKIT_LED1,
               (ledset & PIC32MX_STARTERKIT_LED1_BIT) != 0);
  board_userled(PIC32MX_STARTERKIT_LED2,
               (ledset & PIC32MX_STARTERKIT_LED2_BIT) != 0);
  board_userled(PIC32MX_STARTERKIT_LED3,
               (ledset & PIC32MX_STARTERKIT_LED3_BIT) != 0);
}
#endif

/****************************************************************************
 * Name: pic32mx_led_initialize
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void pic32mx_led_initialize(void)
{
  /* Configure output pins */

  pic32mx_configgpio(GPIO_LED_1);
  pic32mx_configgpio(GPIO_LED_2);
  pic32mx_configgpio(GPIO_LED_3);
}
#endif

/****************************************************************************
 * Name: board_autoled_on
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void board_autoled_on(int led)
{
  if ((unsigned)led < LED_NVALUES)
    {
      pic32mx_setleds(&g_ledonvalues[led]);
    }
}
#endif

/****************************************************************************
 * Name: board_autoled_off
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void board_autoled_off(int led)
{
  if ((unsigned)led < LED_NVALUES)
    {
      pic32mx_setleds(&g_ledoffvalues[led]);
    }
}
#endif
