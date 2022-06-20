/****************************************************************************
 * boards/arm/rp2040/raspberrypi-pico/src/rp2040_bringup.c
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

#include <nuttx/config.h>

#include <debug.h>
#include <stddef.h>

#include <nuttx/fs/fs.h>

#include <arch/board/board.h>

#include "rp2040_pico.h"

#ifdef CONFIG_LCD_BACKPACK
#include "rp2040_lcd_backpack.h"
#endif

#ifdef CONFIG_LCD
#include <nuttx/board.h>
#endif

#ifdef CONFIG_LCD_DEV
#include <nuttx/lcd/lcd_dev.h>
#endif

#ifdef CONFIG_VIDEO_FB
#include <nuttx/video/fb.h>
#endif

#ifdef CONFIG_SENSORS_INA219
#include <nuttx/sensors/ina219.h>
#include "rp2040_ina219.h"
#endif

#ifdef CONFIG_SENSORS_BMP180
#include <nuttx/sensors/bmp180.h>
#include "rp2040_bmp180.h"
#endif

#ifdef CONFIG_RP2040_PWM
#include "rp2040_pwmdev.h"
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: rp2040_bringup
 ****************************************************************************/

int rp2040_bringup(void)
{
  int ret = 0;

#ifdef CONFIG_RP2040_I2C_DRIVER
  #ifdef CONFIG_RP2040_I2C0
  ret = board_i2cdev_initialize(0);
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize I2C0.\n");
    }
  #endif

  #ifdef CONFIG_RP2040_I2C1
  ret = board_i2cdev_initialize(1);
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize I2C1.\n");
    }
  #endif
#endif

#ifdef CONFIG_RP2040_SPI_DRIVER
  #ifdef CONFIG_RP2040_SPI0
  ret = board_spidev_initialize(0);
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize SPI0.\n");
    }
  #endif

  #ifdef CONFIG_RP2040_SPI1
  ret = board_spidev_initialize(1);
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize SPI1.\n");
    }
  #endif
#endif

#ifdef CONFIG_RP2040_PWM
#ifdef CONFIG_RP2040_PWM0
#if defined(CONFIG_PWM_NCHANNELS) && CONFIG_PWM_NCHANNELS == 2
  ret = rp2040_pwmdev_initialize( 0, 
                                  CONFIG_RP2040_PWM0A_GPIO, 
                                  CONFIG_RP2040_PWM0B_GPIO );
#else
  ret = rp2040_pwmdev_initialize( 0, 
                                  CONFIG_RP2040_PWM0A_GPIO );
#endif
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize PWM0.\n");
    }
#endif

#ifdef CONFIG_RP2040_PWM1
#if defined(CONFIG_PWM_NCHANNELS) && CONFIG_PWM_NCHANNELS == 2
  ret = rp2040_pwmdev_initialize( 1, 
                                  CONFIG_RP2040_PWM1A_GPIO, 
                                  CONFIG_RP2040_PWM1B_GPIO );
#else
  ret = rp2040_pwmdev_initialize( 1, 
                                  CONFIG_RP2040_PWM1A_GPIO );
#endif
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize PWM1.\n");
    }
#endif

#ifdef CONFIG_RP2040_PWM2
#if defined(CONFIG_PWM_NCHANNELS) && CONFIG_PWM_NCHANNELS == 2
  ret = rp2040_pwmdev_initialize( 2, 
                                  CONFIG_RP2040_PWM2A_GPIO, 
                                  CONFIG_RP2040_PWM2B_GPIO );
#else
  ret = rp2040_pwmdev_initialize( 2, 
                                  CONFIG_RP2040_PWM2A_GPIO );
#endif
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize PWM2.\n");
    }
#endif

#ifdef CONFIG_RP2040_PWM3
#if defined(CONFIG_PWM_NCHANNELS) && CONFIG_PWM_NCHANNELS == 2
  ret = rp2040_pwmdev_initialize( 3, 
                                  CONFIG_RP2040_PWM3A_GPIO, 
                                  CONFIG_RP2040_PWM3B_GPIO );
#else
  ret = rp2040_pwmdev_initialize( 3, 
                                  CONFIG_RP2040_PWM3A_GPIO );
#endif
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize PWM3.\n");
    }
#endif

#ifdef CONFIG_RP2040_PWM4
#if defined(CONFIG_PWM_NCHANNELS) && CONFIG_PWM_NCHANNELS == 2
  ret = rp2040_pwmdev_initialize( 4, 
                                  CONFIG_RP2040_PWM4A_GPIO, 
                                  CONFIG_RP2040_PWM4B_GPIO );
#else
  ret = rp2040_pwmdev_initialize( 4, 
                                  CONFIG_RP2040_PWM4A_GPIO );
#endif
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize PWM4.\n");
    }
#endif

#ifdef CONFIG_RP2040_PWM5
#if defined(CONFIG_PWM_NCHANNELS) && CONFIG_PWM_NCHANNELS == 2
  ret = rp2040_pwmdev_initialize( 5, 
                                  CONFIG_RP2040_PWM5A_GPIO, 
                                  CONFIG_RP2040_PWM5B_GPIO );
#else
  ret = rp2040_pwmdev_initialize( 5, 
                                  CONFIG_RP2040_PWM5A_GPIO );
#endif
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize PWM5.\n");
    }
#endif

#ifdef CONFIG_RP2040_PWM6
#if defined(CONFIG_PWM_NCHANNELS) && CONFIG_PWM_NCHANNELS == 2
  ret = rp2040_pwmdev_initialize( 6, 
                                  CONFIG_RP2040_PWM6A_GPIO, 
                                  CONFIG_RP2040_PWM6B_GPIO );
#else
  ret = rp2040_pwmdev_initialize( 6, 
                                  CONFIG_RP2040_PWM6A_GPIO );
#endif
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize PWM6.\n");
    }
#endif

#ifdef CONFIG_RP2040_PWM7
#if defined(CONFIG_PWM_NCHANNELS) && CONFIG_PWM_NCHANNELS == 2
  ret = rp2040_pwmdev_initialize( 7, 
                                  CONFIG_RP2040_PWM7A_GPIO, 
                                  CONFIG_RP2040_PWM7B_GPIO );
#else
  ret = rp2040_pwmdev_initialize( 7, 
                                  CONFIG_RP2040_PWM7A_GPIO );
#endif
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize PWM7.\n");
    }
#endif
#endif

#ifdef CONFIG_RP2040_SPISD
  /* Mount the SPI-based MMC/SD block driver */

  ret = board_spisd_initialize(0, CONFIG_RP2040_SPISD_SPI_CH);
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize SPI device to MMC/SD: %d\n",
           ret);
    }
#endif

#ifdef CONFIG_FS_PROCFS
  /* Mount the procfs file system */

  ret = nx_mount(NULL, "/proc", "procfs", 0, NULL);
  if (ret < 0)
    {
      serr("ERROR: Failed to mount procfs at %s: %d\n", "/proc", ret);
    }
#endif

#ifdef CONFIG_SENSORS_BMP180
  /* Try to register BMP180 device in I2C0 */

  ret = board_bmp180_initialize(0);
  if (ret < 0)
    {
      syslog(LOG_ERR, "Failed to initialize BMP180 driver: %d\n", ret);
    }
#endif

#ifdef CONFIG_SENSORS_INA219
  /* Configure and initialize the INA219 sensor in I2C0 */

  ret = board_ina219_initialize(0);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: rp2040_ina219_initialize() failed: %d\n", ret);
    }
#endif

#ifdef CONFIG_VIDEO_FB
  ret = fb_register(0, 0);
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize Frame Buffer Driver.\n");
    }
#elif defined(CONFIG_LCD)
  ret = board_lcd_initialize();
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: Failed to initialize LCD.\n");
    }
#endif

#ifdef CONFIG_LCD_DEV
  ret = lcddev_register(0);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: lcddev_register() failed: %d\n", ret);
    }
#endif

#ifdef CONFIG_LCD_BACKPACK
  /* slcd:0, i2c:0, rows=2, cols=16 */

  ret = board_lcd_backpack_init(0, 0, 2, 16);
  if (ret < 0)
    {
      syslog(LOG_ERR, "Failed to initialize PCF8574 LCD, error %d\n", ret);
      return ret;
    }
#endif

#ifdef CONFIG_RP2040_I2S
  ret = board_i2sdev_initialize(0);
  if (ret < 0)
    {
      _err("ERROR: Failed to initialize I2S.\n");
    }
#endif

#ifdef CONFIG_DEV_GPIO
  ret = rp2040_dev_gpio_init();
  if (ret < 0)
    {
      syslog(LOG_ERR, "Failed to initialize GPIO Driver: %d\n", ret);
      return ret;
    }
#endif

  return ret;
}
