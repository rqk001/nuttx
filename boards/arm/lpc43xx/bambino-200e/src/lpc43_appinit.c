/****************************************************************************
 * boards/arm/lpc43xx/bambino-200e/src/lpc43_appinit.c
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

#include <stdio.h>
#include <syslog.h>
#include <errno.h>

#include <nuttx/board.h>

#include "chip.h"

#ifdef CONFIG_LPC43_SPIFI
#  include <nuttx/mtd/mtd.h>
#  include "lpc43_spifi.h"

#  ifdef CONFIG_SPFI_NXFFS
#    include <nuttx/fs/fs.h>
#    include <nuttx/fs/nxffs.h>
#  endif
#endif

#ifdef CONFIG_LPC43_SDMMC
#  include <nuttx/sdio.h>
#  include <nuttx/mmcsd.h>
#  include "lpc43_sdmmc.h"
#endif

#include "bambino-200e.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

#ifndef CONFIG_SPIFI_DEVNO
#  define CONFIG_SPIFI_DEVNO 0
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: nsh_spifi_initialize
 *
 * Description:
 *   Make the SPIFI (or part of it) into a block driver that can hold a
 *   file system.
 *
 ****************************************************************************/

#ifdef CONFIG_LPC43_SPIFI
static int nsh_spifi_initialize(void)
{
  FAR struct mtd_dev_s *mtd;
  int ret;

  /* Initialize the SPIFI interface and create the MTD driver instance */

  mtd = lpc43_spifi_initialize();
  if (!mtd)
    {
      ferr("ERROR: lpc43_spifi_initialize failed\n");
      return -ENODEV;
    }

#ifndef CONFIG_SPFI_NXFFS
  /* And use the FTL layer to wrap the MTD driver as a block driver */

  ret = ftl_initialize(CONFIG_SPIFI_DEVNO, mtd);
  if (ret < 0)
    {
      ferr("ERROR: Initializing the FTL layer: %d\n", ret);
      return ret;
    }
#else
  /* Initialize to provide NXFFS on the MTD interface */

  ret = nxffs_initialize(mtd);
  if (ret < 0)
    {
      ferr("ERROR: NXFFS initialization failed: %d\n", ret);
      return ret;
    }

  /* Mount the file system at /mnt/spifi */

  ret = nx_mount(NULL, "/mnt/spifi", "nxffs", 0, NULL);
  if (ret < 0)
    {
      ferr("ERROR: Failed to mount the NXFFS volume: %d\n", ret);
      return ret;
    }
#endif

  return OK;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: board_app_initialize
 *
 * Description:
 *   Perform architecture specific initialization
 *
 * Input Parameters:
 *   arg - The boardctl() argument is passed to the board_app_initialize()
 *         implementation without modification.  The argument has no
 *         meaning to NuttX; the meaning of the argument is a contract
 *         between the board-specific initialization logic and the
 *         matching application logic.  The value could be such things as a
 *         mode enumeration value, a set of DIP switch switch settings, a
 *         pointer to configuration data read from a file or serial FLASH,
 *         or whatever you would like to do with it.  Every implementation
 *         should accept zero/NULL as a default configuration.
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure to indicate the nature of the failure.
 *
 ****************************************************************************/

int board_app_initialize(uintptr_t arg)
{
#ifdef HAVE_MMCSD
  struct sdio_dev_s *sdmmc;
#endif
  int ret = 0;

#ifdef CONFIG_LPC43_SPIFI
  /* Initialize the SPIFI block device */

  ret = nsh_spifi_initialize();
  if (ret != OK)
    {
      syslog(LOG_ERR, "ERROR: nsh_spifi_initialize() failed: %d\n", ret);
    }
#endif

#ifdef HAVE_MMCSD
  /* Get an instance of the SDIO interface */

  sdmmc = lpc43_sdmmc_initialize(0);
  if (!sdmmc)
    {
      syslog(LOG_ERR, "ERROR: Failed to initialize SD/MMC\n");
    }
  else
    {
      /* Bind the SDIO interface to the MMC/SD driver */

      ret = mmcsd_slotinitialize(MMCSD_MINOR, sdmmc);
      if (ret != OK)
        {
          syslog(LOG_ERR,
                 "ERROR: Failed to bind SDIO to the MMC/SD driver: %d\n",
                 ret);
        }
    }
#endif

#ifdef CONFIG_TIMER
  /* Registers the timers */

  lpc43_timerinitialize();
#endif

  return ret;
}
