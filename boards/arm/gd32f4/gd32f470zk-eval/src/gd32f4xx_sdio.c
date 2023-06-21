/****************************************************************************
 * boards/arm/gd32f4/gd32f470zk-eval/src/gd32f4xx_sdio.c
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

#include <stdbool.h>
#include <stdio.h>
#include <debug.h>
#include <errno.h>

#include <nuttx/sdio.h>
#include <nuttx/mmcsd.h>

#include "chip.h"
#include "gd32f4xx.h"
#include "gd32f470z_eval.h"

#ifdef CONFIG_MMCSD

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

/* Card detections requires card support and a card detection GPIO */

#define HAVE_NCD   1
#if !defined(GPIO_SDMMC1_NCD)
#  undef HAVE_NCD
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

static struct sdio_dev_s *g_sdio_dev;
#ifdef HAVE_NCD
static bool g_sd_inserted;
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gd32_ncd_interrupt
 *
 * Description:
 *   Card detect interrupt handler.
 *
 ****************************************************************************/

#ifdef HAVE_NCD
static int gd32_ncd_interrupt(int irq, void *context)
{
  bool present;

  present = !gd32_gpio_read(GPIO_SDMMC1_NCD);
  if (g_sdio_dev && present != g_sd_inserted)
    {
      sdio_mediachange(g_sdio_dev, present);
      g_sd_inserted = present;
    }

  return OK;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gd32_sdio_initialize
 *
 * Description:
 *   Initialize SDIO-based MMC/SD card support
 *
 ****************************************************************************/

int gd32_sdio_initialize(void)
{
  int ret;

  /* Mount the SDIO-based MMC/SD block driver
   * First, get an instance of the SDIO interface
   */

  finfo("Initializing SDIO slot %d\n", SDIO_SLOTNO);

  g_sdio_dev = sdio_initialize(SDIO_SLOTNO);
  if (!g_sdio_dev)
    {
      ferr("ERROR: Failed to initialize SDIO slot %d\n", SDIO_SLOTNO);
      return -ENODEV;
    }

  /* Now bind the SDIO interface to the MMC/SD driver */

  finfo("Bind SDIO to the MMC/SD driver, minor=%d\n", SDIO_MINOR);

  ret = mmcsd_slotinitialize(SDIO_MINOR, g_sdio_dev);
  if (ret != OK)
    {
      ferr("ERROR: Failed to bind SDIO to the MMC/SD driver: %d\n", ret);
      return ret;
    }

  finfo("Successfully bound SDIO to the MMC/SD driver\n");

#ifdef HAVE_NCD
  /* Use SD card detect pin to check if a card is g_sd_inserted */

  g_sd_inserted = !gd32_gpio_read(GPIO_SDMMC1_NCD);
  finfo("Card detect : %d\n", g_sd_inserted);

  sdio_mediachange(g_sdio_dev, g_sd_inserted);
#else
  /* Assume that the SD card is inserted.  What choice do we have? */

  sdio_mediachange(g_sdio_dev, true);
#endif

  return OK;
}

#endif /* CONFIG_MMCSD */
