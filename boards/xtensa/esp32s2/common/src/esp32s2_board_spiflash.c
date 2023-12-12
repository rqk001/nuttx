/****************************************************************************
 * boards/xtensa/esp32s2/common/src/esp32s2_board_spiflash.c
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

#include <sys/mount.h>

#include "inttypes.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/kmalloc.h>
#include <nuttx/spi/spi.h>
#include <nuttx/mtd/mtd.h>
#include <nuttx/fs/nxffs.h>
#ifdef CONFIG_BCH
#include <nuttx/drivers/drivers.h>
#endif

#include "esp32s2_spiflash.h"
#include "esp32s2_spiflash_mtd.h"
#include "esp32s2-saola-1.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifndef CONFIG_ESP32S2_STORAGE_MTD_OFFSET
#  define CONFIG_ESP32S2_STORAGE_MTD_OFFSET 0x10000
#endif

#ifndef CONFIG_ESP32S2_STORAGE_MTD_SIZE
#  define CONFIG_ESP32S2_STORAGE_MTD_SIZE 0x100000
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: setup_smartfs
 *
 * Description:
 *   Provide a block driver wrapper around MTD partition and mount a
 *   SMART FS over it.
 *
 * Parameters:
 *   smartn - Number used to register the mtd partition: /dev/smartx, where
 *            x = smartn.
 *   mtd    - Pointer to a pre-allocated mtd partition.
 *   mnt_pt - Mount point
 *
 * Returned Value:
 *   Zero on success; a negated errno value on failure.
 *
 ****************************************************************************/

#if defined (CONFIG_ESP32S2_SPIFLASH_SMARTFS)
static int setup_smartfs(int smartn, struct mtd_dev_s *mtd,
                         const char *mnt_pt)
{
  int ret = OK;
  char path[22];

  ret = smart_initialize(smartn, mtd, NULL);
  if (ret < 0)
    {
      syslog(LOG_INFO, "smart_initialize failed, "
             "Trying to erase first...\n");
      ret = mtd->ioctl(mtd, MTDIOC_BULKERASE, 0);
      if (ret < 0)
        {
          syslog(LOG_ERR, "ERROR: ioctl(BULKERASE) failed: %d\n", ret);
          return ret;
        }

      syslog(LOG_INFO, "Erase successful, initializing it again.\n");
      ret = smart_initialize(smartn, mtd, NULL);
      if (ret < 0)
        {
          syslog(LOG_ERR, "ERROR: smart_initialize failed: %d\n", ret);
          return ret;
        }
    }

  if (mnt_pt != NULL)
    {
      snprintf(path, sizeof(path), "/dev/smart%d", smartn);

      ret = nx_mount(path, mnt_pt, "smartfs", 0, NULL);
      if (ret < 0)
        {
          syslog(LOG_ERR, "ERROR: Failed to mount the FS volume: %d\n", ret);
          if (ret == -ENODEV)
            {
              syslog(LOG_WARNING, "Smartfs seems unformatted. "
                     "Did you run 'mksmartfs /dev/smart%d'?\n", smartn);
            }

          return ret;
        }
    }

  return ret;
}

#endif

/****************************************************************************
 * Name: setup_littlefs
 *
 * Description:
 *   Register a mtd driver and mount a Little FS over it.
 *
 * Parameters:
 *   path   - Path name used to register the mtd driver.
 *   mtd    - Pointer to a pre-allocated mtd partition.
 *   mnt_pt - Mount point
 *   priv   - Privileges
 *
 * Returned Value:
 *   Zero on success; a negated errno value on failure.
 *
 ****************************************************************************/

#if defined (CONFIG_ESP32S2_SPIFLASH_LITTLEFS)
static int setup_littlefs(const char *path, struct mtd_dev_s *mtd,
                          const char *mnt_pt, int priv)
{
  int ret = OK;

  ret = register_mtddriver(path, mtd, priv, NULL);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: Failed to register MTD: %d\n", ret);
      return ERROR;
    }

  if (mnt_pt != NULL)
    {
      ret = nx_mount(path, mnt_pt, "littlefs", 0, NULL);
      if (ret < 0)
        {
          ret = nx_mount(path, mnt_pt, "littlefs", 0, "forceformat");
          if (ret < 0)
            {
              syslog(LOG_ERR, "ERROR: Failed to mount the FS volume: %d\n",
                     ret);
              return ret;
            }
        }
    }

  return OK;
}
#endif

/****************************************************************************
 * Name: setup_spiffs
 *
 * Description:
 *   Register a mtd driver and mount a SPIFFS over it.
 *
 * Parameters:
 *   path   - Path name used to register the mtd driver.
 *   mtd    - Pointer to a pre-allocated mtd partition.
 *   mnt_pt - Mount point
 *   priv   - Privileges
 *
 * Returned Value:
 *   Zero on success; a negated errno value on failure.
 *
 ****************************************************************************/

#if defined (CONFIG_ESP32S2_SPIFLASH_SPIFFS)
static int setup_spiffs(const char *path, struct mtd_dev_s *mtd,
                        const char *mnt_pt, int priv)
{
  int ret = OK;

  ret = register_mtddriver(path, mtd, priv, NULL);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: Failed to register MTD: %d\n", ret);
      return ERROR;
    }

  if (mnt_pt != NULL)
    {
      ret = nx_mount(path, mnt_pt, "spiffs", 0, NULL);
      if (ret < 0)
        {
          syslog(LOG_ERR, "ERROR: Failed to mount the FS volume: %d\n", ret);
          return ret;
        }
    }

  return ret;
}
#endif

/****************************************************************************
 * Name: setup_nxffs
 *
 * Description:
 *   Register a mtd driver and mount a SPIFFS over it.
 *
 * Parameters:
 *   mtd    - Pointer to a pre-allocated mtd partition.
 *   mnt_pt - Mount point
 *
 * Returned Value:
 *   Zero on success; a negated errno value on failure.
 *
 ****************************************************************************/

#if defined (CONFIG_ESP32S2_SPIFLASH_NXFFS)
static int setup_nxffs(struct mtd_dev_s *mtd, const char *mnt_pt)
{
  int ret = OK;

  ret = nxffs_initialize(mtd);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: NXFFS init failed: %d\n", ret);
      return ret;
    }

  if (mnt_pt != NULL)
    {
      ret = nx_mount(NULL, mnt_pt, "nxffs", 0, NULL);
      if (ret < 0)
        {
          syslog(LOG_ERR, "ERROR: Failed to mount the FS volume: %d\n", ret);
          return ret;
        }
    }

  return ret;
}
#endif

/****************************************************************************
 * Name: init_storage_partition
 *
 * Description:
 *   Initialize partition that is dedicated to general use.
 *
 * Returned Value:
 *   Zero on success; a negated errno value on failure.
 *
 ****************************************************************************/

static int init_storage_partition(void)
{
  int ret = OK;
  struct mtd_dev_s *mtd;

  mtd = esp32s2_spiflash_alloc_mtdpart(CONFIG_ESP32S2_STORAGE_MTD_OFFSET,
                                       CONFIG_ESP32S2_STORAGE_MTD_SIZE,
                                       false);
  if (!mtd)
    {
      syslog(LOG_ERR, "ERROR: Failed to alloc MTD partition of SPI Flash\n");
      return ERROR;
    }

#if defined (CONFIG_ESP32S2_SPIFLASH_SMARTFS)

  ret = setup_smartfs(0, mtd, "/data");
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: Failed to setup smartfs\n");
      return ret;
    }

#elif defined (CONFIG_ESP32S2_SPIFLASH_NXFFS)

  ret = setup_nxffs(mtd, "/data");
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: Failed to setup nxffs\n");
      return ret;
    }

#elif defined (CONFIG_ESP32S2_SPIFLASH_LITTLEFS)

  const char *path = "/dev/esp32s2flash";
  ret = setup_littlefs(path, mtd, "/data", 0755);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: Failed to setup littlefs\n");
      return ret;
    }

#elif defined (CONFIG_ESP32S2_SPIFLASH_SPIFFS)

  const char *path = "/dev/esp32s2flash";
  ret = setup_spiffs(path, mtd, "/data", 0755);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: Failed to setup spiffs\n");
      return ret;
    }

#else

  ret = register_mtddriver("/dev/esp32s2flash", mtd, 0755, NULL);
  if (ret < 0)
    {
      syslog(LOG_ERR, "ERROR: Failed to register MTD: %d\n", ret);
      return ret;
    }

#endif

  return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: board_spiflash_init
 *
 * Description:
 *   Initialize the SPIFLASH and register the MTD device.
 *
 ****************************************************************************/

int board_spiflash_init(void)
{
  int ret = OK;

  ret = esp32s2_spiflash_init();
  if (ret < 0)
    {
      return ret;
    }

  ret = init_storage_partition();
  if (ret < 0)
    {
      return ret;
    }

  return ret;
}

