/****************************************************************************
 * boards/arm/s32k1xx/ucans32k146/src/ucans32k146.h
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

#ifndef __BOARDS_ARM_S32K1XX_UCANS32K146_SRC_UCANS32K146_H
#define __BOARDS_ARM_S32K1XX_UCANS32K146_SRC_UCANS32K146_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>

#include <stdint.h>

#include "hardware/s32k1xx_pinmux.h"
#include "s32k1xx_periphclocks.h"
#include "s32k1xx_pin.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

/* UCANS32K146 GPIOs ********************************************************/

/* LEDs.  The UCANS32K146 has one RGB LED:
 *
 *   RedLED    PTD15  (FTM0 CH0)
 *   GreenLED  PTD16  (FTM0 CH1)
 *   BlueLED   PTD0   (FTM0 CH2)
 *
 * An output of '0' illuminates the LED.
 */

#define GPIO_LED_R     (PIN_PTD15 | GPIO_LOWDRIVE | GPIO_OUTPUT_ONE)
#define GPIO_LED_G     (PIN_PTD16 | GPIO_LOWDRIVE | GPIO_OUTPUT_ONE)
#define GPIO_LED_B     (PIN_PTD0  | GPIO_LOWDRIVE | GPIO_OUTPUT_ONE)

/* Buttons.  The UCANS32K146 supports one button:
 *
 *   SW3  PTC14
 */

#define GPIO_SW3       (PIN_PTC14 | PIN_INT_BOTH)

/* SE050 Secure Element enable pin */

#define GPIO_SE050_EN  (PIN_PTA6 | GPIO_LOWDRIVE)

/* Count of peripheral clock user configurations */

#define NUM_OF_PERIPHERAL_CLOCKS_0 12

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifndef __ASSEMBLY__

/* User peripheral configuration structure 0 */

extern const struct peripheral_clock_config_s g_peripheral_clockconfig0[];

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: s32k1xx_bringup
 *
 * Description:
 *   Perform architecture-specific initialization
 *
 *   CONFIG_BOARD_LATE_INITIALIZE=y :
 *     Called from board_late_initialize().
 *
 *   CONFIG_BOARD_LATE_INITIALIZE=y && CONFIG_BOARDCTL=y :
 *     Called from the NSH library
 *
 ****************************************************************************/

int s32k1xx_bringup(void);

/****************************************************************************
 * Name: s32k1xx_i2cdev_initialize
 *
 * Description:
 *   Initialize I2C driver and register /dev/i2cN devices.
 *
 ****************************************************************************/

int s32k1xx_i2cdev_initialize(void);

/****************************************************************************
 * Name: s32k1xx_spidev_initialize
 *
 * Description:
 *   Configure chip select pins, initialize the SPI driver and register
 *   /dev/spiN devices.
 *
 ****************************************************************************/

int s32k1xx_spidev_initialize(void);

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_ARM_S32K1XX_UCANS32K146_SRC_UCANS32K146_H */
