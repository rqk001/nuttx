/****************************************************************************
 * boards/arm/nrf91/nrf9160-dk/include/board.h
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

#ifndef __BOARDS_ARM_NRF91_NRF9160_DK_INCLUDE_BOARD_H
#define __BOARDS_ARM_NRF91_NRF9160_DK_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <stdbool.h>

#if defined(CONFIG_ARCH_IRQBUTTONS) && defined(CONFIG_NRF91_GPIOTE)
#  include <nuttx/irq.h>
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

#define BOARD_SYSTICK_CLOCK         (64000000)

/* LED definitions **********************************************************/

/* A low output illuminates the LED.
 *
 * LED index values for use with board_userled()
 */

#define BOARD_LED1        0
#define BOARD_LED2        1
#define BOARD_LED3        2
#define BOARD_LED4        3
#define BOARD_NLEDS       4

/* LED bits for use with board_userled_all() */

#define BOARD_LED1_BIT    (1 << BOARD_LED1)
#define BOARD_LED2_BIT    (1 << BOARD_LED2)
#define BOARD_LED3_BIT    (1 << BOARD_LED3)
#define BOARD_LED4_BIT    (1 << BOARD_LED4)

/* If CONFIG_ARCH_LEDS is defined, the LED will be controlled as follows
 * for NuttX debug functionality (where NC means "No Change").
 */

#define LED_STARTED                0  /* OFF      */
#define LED_HEAPALLOCATE           0  /* OFF      */
#define LED_IRQSENABLED            0  /* OFF      */
#define LED_STACKCREATED           1  /* ON       */
#define LED_INIRQ                  2  /* NC       */
#define LED_SIGNAL                 2  /* NC       */
#define LED_ASSERTION              2  /* NC       */
#define LED_PANIC                  3  /* Flashing */

/* If CONFIG_ARCH_LEDS is not defined, then the LEDs are completely under
 * control of the application.  The following interfaces are then available
 * for application control of the LEDs:
 *
 *  uint32_t board_userled_initialize(void);
 *  void board_userled(int led, bool ledon);
 *  void board_userled_all(uint32_t ledset);
 */

/* Button definitions *******************************************************/

/* Board supports 2 buttons. */

#define BUTTON_BTN1       0
#define BUTTON_BTN2       1
#define NUM_BUTTONS       2

#define BUTTON_BTN1_BIT  (1 << BUTTON_BTN1)
#define BUTTON_BTN2_BIT  (1 << BUTTON_BTN2)

/* UART Pins ****************************************************************/

/* UART0 is connected to the virtual COM port:
 *   UART0_RX - P0-28
 *   UART0_TX - P0-29
 */

#define BOARD_UART0_RX_PIN  (GPIO_INPUT  | GPIO_PORT0 | GPIO_PIN(28))
#define BOARD_UART0_TX_PIN  (GPIO_OUTPUT | GPIO_VALUE_ONE | GPIO_PORT0 | GPIO_PIN(29))

/* UART1 is connected to the virtual COM port:
 *   UART1_RX - P0-00
 *   UART1_TX - P0-01
 */

#define BOARD_UART1_RX_PIN  (GPIO_INPUT  | GPIO_PORT0 | GPIO_PIN(0))
#define BOARD_UART1_TX_PIN  (GPIO_OUTPUT | GPIO_VALUE_ONE | GPIO_PORT0 | GPIO_PIN(1))

#endif /* __BOARDS_ARM_NRF91_NRF9160_DK_INCLUDE_BOARD_H */
