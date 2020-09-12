/****************************************************************************
 * boards/arm/nrf52/nrf52-feather/src/nrf52_spi.c
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

#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/spi/spi.h>
#include <nuttx/input/stmpe811.h>

#include "arm_arch.h"
#include "chip.h"
#include "nrf52_gpio.h"
#include "nrf52_spi.h"

#include "nrf52-feather.h"
#include <arch/board/board.h>

#ifdef CONFIG_NRF52_SPI_MASTER

/****************************************************************************
 * Private Types
 ****************************************************************************/

struct nrf52_mmcsd_state_s
{
  spi_mediachange_t  callback;   /* SPI media change callback */
  FAR void           *cbarg;     /* Arg to pass to media change callback */
  bool               detected;   /* Last known card state */
};

/****************************************************************************
 * Private Data
 ****************************************************************************/

static struct nrf52_mmcsd_state_s g_mmcsd =
{
  .callback  = NULL,
  .cbarg     = NULL,
  .detected  = false,
};

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: kb_feather_carddet
 *
 * Description:
 *   This function is called when a change in the sd card is detected
 *
 * Input Parameters:
 *   pin - Interrupt GPIO pin (not used)
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void kb_feather_carddet(int pin)
{
  g_mmcsd.detected = kb_card_state();
  g_mmcsd.callback(g_mmcsd.cbarg);
}

/****************************************************************************
 * Name: nrf52_spidev_initialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins.
 *
 ****************************************************************************/

void nrf52_spidev_initialize(void)
{
#ifdef CONFIG_NRF52_FEATHER_KB_FEATHERWING
  /* Configure the SPI-based ILI9341 chip select GPIO */

  spiinfo("Configure GPIO for ILI9341 Display CS\n");
  nrf52_gpio_config(ILI9341_DISPLAY_CS);

  /* Configure the SPI-based SD Card reader chip select GPIO */

  spiinfo("Configure GPIO for MMCSD CS\n");
  nrf52_gpio_config(KB_FW_CARD_CS);

  /* Configure the SPI-based STMP chip select GPIO */

  spiinfo("Configure GPIO for STMP CS\n");
  nrf52_gpio_config(KB_FW_STMP_CS);
#endif
}

/****************************************************************************
 * Name:  nrf52_spi0/1/2select and nrf52_spi0/1/2status
 *
 * Description:
 *   The external functions, nrf52_spi0/1/2select and
 *   nrf52_spi0/1/2status must be provided by board-specific logic.
 *   They are implementations of the select and status methods of the SPI
 *   interface defined by struct spi_ops_s (see include/nuttx/spi/spi.h).
 *   All other methods (including nrf52_spibus_initialize()) are provided
 *   by common NRF52 logic.  To use this common SPI logic on your board:
 *
 *   1. Provide logic in nrf52_boardinitialize() to configure SPI chip select
 *      pins.
 *   2. Provide nrf52_spi0/1/2select() and nrf52_spi0/1/2status()
 *      functions in your board-specific logic. These functions will perform
 *      chip selection and status operations using GPIOs in the way your
 *      board is configured.
 *   3. Add a calls to nrf52_spibus_initialize() in your low level
 *      application initialization logic
 *   4. The handle returned by nrf52_spibus_initialize() may then be used to
 *      bind the SPI driver to higher level logic (e.g., calling
 *      mmcsd_spislotinitialize(), for example, will bind the SPI driver to
 *      the SPI MMC/SD driver).
 *
 ****************************************************************************/

#ifdef CONFIG_NRF52_SPI0_MASTER
void nrf52_spi0select(FAR struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  spiinfo("devid: %08lx CS: %s\n",
          (unsigned long)devid, selected ? "assert" : "de-assert");

  switch (devid)
    {
#ifdef CONFIG_LCD_ILI9341
      case SPIDEV_DISPLAY(0):
        {
          spiinfo("ILI9341 device %s\n",
                  selected ? "asserted" : "de-asserted");

          /* Set the GPIO low to select and high to de-select */

          nrf52_gpio_write(ILI9341_DISPLAY_CS, !selected);
          break;
        }
#endif

#ifdef CONFIG_KB_FEATHERWING_SDCARD
      case SPIDEV_MMCSD(0):
        {
          spiinfo("SD Card device %s\n",
                  selected ? "asserted" : "de-asserted");

          /* Set the GPIO low to select and high to de-select */

          nrf52_gpio_write(KB_FW_CARD_CS, !selected);
          break;
        }
#endif

#if 1
      case SPIDEV_TOUCHSCREEN(0):
        {
          spiinfo("Touch Screen device %s\n",
                  selected ? "asserted" : "de-asserted");

          /* Set the GPIO low to select and high to de-select */

          nrf52_gpio_write(KB_FW_STMP_CS, !selected);
          break;
        }
#endif

      default:
        {
          break;
        }
    }
}

uint8_t nrf52_spi0status(FAR struct spi_dev_s *dev, uint32_t devid)
{
  uint8_t status = 0;

  switch (devid)
    {
#ifdef CONFIG_LCD_ILI9341
      case SPIDEV_DISPLAY(0):
        {
          status |= SPI_STATUS_PRESENT;
          break;
        }
#endif

#ifdef CONFIG_KB_FEATHERWING_SDCARD
      case SPIDEV_MMCSD(0):
        {
          if (g_mmcsd.detected)
            {
              status |= SPI_STATUS_PRESENT;
            }
          break;
        }
#endif

#if 1
      case SPIDEV_TOUCHSCREEN(0):
        {
          status |= SPI_STATUS_PRESENT;
          break;
        }
#endif

      default:
        {
          break;
        }
    }

  return status;
}
#endif

#ifdef CONFIG_NRF52_SPI1_MASTER
void nrf52_spi1select(FAR struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  spiinfo("devid: %08lx CS: %s\n",
          (unsigned long)devid, selected ? "assert" : "de-assert");
}

uint8_t nrf52_spi1status(FAR struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

#ifdef CONFIG_NRF52_SPI2_MASTER
void nrf52_spi2select(FAR struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  spiinfo("devid: %08lx CS: %s\n",
          (unsigned long)devid, selected ? "assert" : "de-assert");
}

uint8_t nrf52_spi2status(FAR struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

/****************************************************************************
 * Name: nrf52_spi0/1/2/3register
 *
 * Description:
 *   If the board supports a card detect callback to inform the SPI-based
 *   MMC/SD driver when an SD card is inserted or removed, then
 *   CONFIG_SPI_CALLBACK should be defined and the following function(s)
 *   must be implemented.  These functions implements the registercallback
 *   method of the SPI interface (see include/nuttx/spi/spi.h for details)
 *
 * Input Parameters:
 *   dev -      Device-specific state data
 *   callback - The function to call on the media change
 *   arg -      A caller provided value to return with the callback
 *
 * Returned Value:
 *   0 on success; negated errno on failure.
 *
 ****************************************************************************/

#ifdef CONFIG_SPI_CALLBACK
#ifdef CONFIG_NRF52_SPI0_MASTER
int  nrf52_spi0register(FAR struct spi_dev_s *dev,
                         spi_mediachange_t callback, FAR void *arg)
{
  /* We are assuming a single SPI SD card on this bus */

  g_mmcsd.callback = callback;
  g_mmcsd.cbarg = arg;

  return OK;
}
#endif /* CONFIG_NRF52_SPI0_MASTER */

#ifdef CONFIG_NRF52_SPI1_MASTER
int  nrf52_spi1register(FAR struct spi_dev_s *dev,
                         spi_mediachange_t callback, FAR void *arg)
{
  return -ENOSYS;
}
#endif /* CONFIG_NRF52_SPI1_MASTER */

#ifdef CONFIG_NRF52_SPI2_MASTER
int  nrf52_spi2register(FAR struct spi_dev_s *dev,
                         spi_mediachange_t callback, FAR void *arg)
{
  return -ENOSYS;
}
#endif /* CONFIG_NRF52_SPI2_MASTER */
#endif /* CONFIG_SPI_CALLBACK */

#endif /* CONFIG_NRF52_SPI_MASTER */
