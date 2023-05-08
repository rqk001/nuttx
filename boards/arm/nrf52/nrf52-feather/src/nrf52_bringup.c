/****************************************************************************
 * boards/arm/nrf52/nrf52-feather/src/nrf52_bringup.c
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

#include <sys/types.h>
#include <sys/mount.h>

#include <syslog.h>

#include <nuttx/signal.h>
#include <nuttx/board.h>

#ifdef CONFIG_NRF52_WDT
#  include "nrf52_wdt_lowerhalf.h"
#endif

#ifdef CONFIG_USERLED
#  include <nuttx/leds/userled.h>
#endif

#ifdef CONFIG_SPI
#  include "nrf52_spi.h"
#endif

#ifdef CONFIG_I2C
#  include "nrf52_i2c.h"
#endif

#ifdef CONFIG_WS2812
#  include <nuttx/leds/ws2812.h>
#endif

#ifdef CONFIG_LCD_DEV
#  include <nuttx/lcd/lcd_dev.h>
#endif

#ifdef CONFIG_MMCSD_SPI
#  include <nuttx/mmcsd.h>
#endif

#include "nrf52-feather.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: nrf52_bringup
 *
 * Description:
 *   Perform architecture-specific initialization
 *
 *   CONFIG_BOARD_LATE_INITIALIZE=y :
 *     Called from board_late_initialize().
 *
 *   CONFIG_BOARD_LATE_INITIALIZE=n && CONFIG_BOARDCTL=y :
 *     Called from the NSH library
 *
 ****************************************************************************/

int nrf52_bringup(void)
{
  int ret;
  FAR struct spi_dev_s *spi;

#ifdef CONFIG_FS_PROCFS
  /* Mount the procfs file system */

  ret = mount(NULL, "/proc", "procfs", 0, NULL);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: Failed to mount procfs at /proc: %d\n", ret);
    }
#endif

#ifdef CONFIG_NRF52_WDT
  /* Start Watchdog timer */

  ret = nrf52_wdt_initialize(CONFIG_WATCHDOG_DEVPATH, 1, 1);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: nrf52_wdt_initialize failed: %d\n", ret);
    }
#endif

#ifdef CONFIG_USERLED
  /* Register the LED driver */

  ret = userled_lower_initialize(CONFIG_EXAMPLES_LEDS_DEVPATH);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: userled_lower_initialize() failed: %d\n", ret);
    }
#endif

#if defined(CONFIG_I2C) && defined(CONFIG_SYSTEM_I2CTOOL)
  nrf52_i2ctool();
#endif

#ifdef CONFIG_NRF52_SPI_MASTER
  nrf52_spidev_initialize();
#endif

#ifdef CONFIG_KB_FEATHERWING_NEOPIXEL
  spi = nrf52_spibus_initialize(KB_FW_NEOPIXEL_SPI_DEV);
  if (!spi)
    {
      syslog(LOG_ERR, "ERROR: Failed to initialize NeoPixel spi bus.\n");
    }
  else
    {
      /* It seems that for SPIM2 there is a delay required before it
       * can be used to clock data out.
       */

      nxsig_usleep(100);
      ret = ws2812_leds_register("/dev/leds0", spi, 1);
      if (ret < 0)
        {
          syslog(LOG_ERR, "ERROR: ws2812_leds_register() failed: %d\n", ret);
        }
    }
#endif

#ifdef CONFIG_KB_FEATHERWING_SDCARD
  spi = nrf52_spibus_initialize(KB_FW_SDCARD_SPI_DEV);
  if (!spi)
    {
      syslog(LOG_ERR, "ERROR: Failed to initialize SD Card spi bus.\n");
    }
  else
    {
      ret = mmcsd_spislotinitialize(0, 0, spi);
      if (ret < 0)
        {
          syslog(LOG_ERR,
                 "ERROR: mmcsd_spislotinitialize() failed: %d\n", ret);
        }
    }
#endif

#ifdef CONFIG_KB_FEATHERWING_LCD_TOUCH
  ret = fw_stmpe811_setup(0);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: fw_stmpe811_setup() failed: %d\n", ret);
    }
#endif

#ifdef CONFIG_LCD
  ret = board_lcd_initialize();
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: board_lcd_initialize() failed: %d\n", ret);
    }

#ifdef CONFIG_LCD_DEV

  ret = lcddev_register(0);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: lcddev_register() failed: %d\n", ret);
    }

#endif
#endif

#ifdef CONFIG_KB_FEATHERWING_KEYBOARD
  kb_backlightctl(true);
  ret = q10kbd_setup(KB_FW_KEYBOARD_I2C_DEV);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: q10kbd_setup() failed: %d\n", ret);
    }
#endif

  UNUSED(ret);
  return OK;
}
