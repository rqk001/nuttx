/****************************************************************************
 * boards/xtensa/esp32/esp32-wrover-kit/src/esp32_spiflash.c
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

#include "esp32_spiflash.h"
#include "esp32-wrover-kit.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define ARRAYSIZE(x)                (sizeof((x)) / sizeof((x)[0]))

#define ESP32_MTD_OFFSET            CONFIG_ESP32_MTD_OFFSET
#define ESP32_MTD_SIZE              CONFIG_ESP32_MTD_SIZE

/****************************************************************************
 * Private Types
 ****************************************************************************/

#ifdef CONFIG_ESP32_HAVE_OTA_PARTITION

struct ota_partition_s
{
  uint32_t    offset;          /* Partition offset from the beginning of MTD */
  uint32_t    size;            /* Partition size in bytes */
  const char *devpath;         /* Partition device path */
};

#endif

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

#ifdef CONFIG_ESP32_HAVE_OTA_PARTITION
static int init_ota_partitions(void);
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

#ifdef CONFIG_ESP32_HAVE_OTA_PARTITION
static const struct ota_partition_s g_ota_partition_table[] =
{
  {
    .offset  = CONFIG_ESP32_OTA_PRIMARY_SLOT_OFFSET,
    .size    = CONFIG_ESP32_OTA_SLOT_SIZE,
    .devpath = CONFIG_ESP32_OTA_PRIMARY_SLOT_DEVPATH
  },
  {
    .offset  = CONFIG_ESP32_OTA_SECONDARY_SLOT_OFFSET,
    .size    = CONFIG_ESP32_OTA_SLOT_SIZE,
    .devpath = CONFIG_ESP32_OTA_SECONDARY_SLOT_DEVPATH
  },
  {
    .offset  = CONFIG_ESP32_OTA_SCRATCH_OFFSET,
    .size    = CONFIG_ESP32_OTA_SCRATCH_SIZE,
    .devpath = CONFIG_ESP32_OTA_SCRATCH_DEVPATH
  }
};
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

#ifdef CONFIG_ESP32_HAVE_OTA_PARTITION
static int init_ota_partitions(void)
{
  FAR struct mtd_dev_s *mtd;
#ifdef CONFIG_BCH
  char blockdev[18];
#endif
  int ret = OK;

  for (int i = 0; i < ARRAYSIZE(g_ota_partition_table); ++i)
    {
      const struct ota_partition_s *part = &g_ota_partition_table[i];
      mtd = esp32_spiflash_alloc_mtdpart(part->offset, part->size);

      ret = ftl_initialize(i, mtd);
      if (ret < 0)
        {
          ferr("ERROR: Failed to initialize the FTL layer: %d\n", ret);
          return ret;
        }

#ifdef CONFIG_BCH
      snprintf(blockdev, 18, "/dev/mtdblock%d", i);

      ret = bchdev_register(blockdev, part->devpath, false);
      if (ret < 0)
        {
          ferr("ERROR: bchdev_register %s failed: %d\n", part->devpath, ret);
          return ret;
        }
#endif
    }

  return ret;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: esp32_spiflash_init
 *
 * Description:
 *   Initialize the SPIFLASH and register the MTD device.
 ****************************************************************************/

int esp32_spiflash_init(void)
{
  FAR struct mtd_dev_s *mtd;
  int ret = ERROR;

#ifdef CONFIG_ESP32_HAVE_OTA_PARTITION
  ret = init_ota_partitions();
  if (ret < 0)
    {
      return ret;
    }
#endif

  mtd = esp32_spiflash_alloc_mtdpart(ESP32_MTD_OFFSET, ESP32_MTD_SIZE);

#if defined (CONFIG_ESP32_SPIFLASH_SMARTFS)
  ret = smart_initialize(0, mtd, NULL);
  if (ret < 0)
    {
      finfo("smart_initialize failed, Trying to erase first...\n");
      ret = mtd->ioctl(mtd, MTDIOC_BULKERASE, 0);
      if (ret < 0)
        {
          ferr("ERROR: ioctl(BULKERASE) failed: %d\n", ret);
          return ret;
        }

      finfo("Erase successful, initializing again\n");
      ret = smart_initialize(0, mtd, NULL);
      if (ret < 0)
        {
          ferr("ERROR: smart_initialize failed: %d\n", ret);
          return ret;
        }
    }

#elif defined (CONFIG_ESP32_SPIFLASH_NXFFS)
  ret = nxffs_initialize(mtd);
  if (ret < 0)
    {
      ferr("ERROR: NXFFS init failed: %d\n", ret);
      return ret;
    }

#else
  ret = register_mtddriver("/dev/esp32flash", mtd, 0755, NULL);
  if (ret < 0)
    {
      ferr("ERROR: Register mtd failed: %d\n", ret);
      return ret;
    }
#endif

  return ret;
}

/****************************************************************************
 * Name: esp32_spiflash_encrypt_test
 *
 * Description:
 *   Test ESP32 SPI Flash driver read/write with encryption.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

#ifdef CONFIG_ESP32_SPIFLASH_ENCRYPTION_TEST

void esp32_spiflash_encrypt_test(void)
{
  int i;
  int ret;
  uint8_t *wbuf;
  uint8_t *rbuf;
  struct mtd_geometry_s geo;
  uint32_t erase_block;
  uint32_t erase_nblocks;
  uint32_t rw_block;
  uint32_t rw_nblocks;
  struct mtd_dev_s *mtd = esp32_spiflash_get_mtd();
  struct mtd_dev_s *enc_mtd = esp32_spiflash_encrypt_get_mtd();
  const uint32_t address = CONFIG_ESP32_SPIFLASH_TEST_ADDRESS;
  const uint32_t size = 4096;

  ret = MTD_IOCTL(enc_mtd, MTDIOC_GEOMETRY,
                  (unsigned long)(uintptr_t)&geo);
  if (ret < 0)
    {
      ferr("ERROR: Failed to get GEO ret = %d\n", ret);
      DEBUGASSERT(0);
    }

  wbuf = kmm_malloc(size);
  if (!wbuf)
    {
      ferr("ERROR: Failed to alloc %d heap\n", size);
      DEBUGASSERT(0);
    }

  rbuf = kmm_malloc(size);
  if (!rbuf)
    {
      ferr("ERROR: Failed to alloc %d heap\n", size);
      DEBUGASSERT(0);
    }

  for (i = 0; i < size; i++)
    {
      wbuf[i] = (uint8_t)random();
    }

  erase_block = address / geo.erasesize;
  erase_nblocks = size / geo.erasesize;

  rw_block = address / geo.blocksize;
  rw_nblocks = size / geo.blocksize;

  ret = MTD_ERASE(enc_mtd, erase_block, erase_nblocks);
  if (ret != erase_nblocks)
    {
      ferr("ERROR: Failed to erase block ret=%d\n", ret);
      DEBUGASSERT(0);
    }

  ret = MTD_BWRITE(enc_mtd, rw_block, rw_nblocks, wbuf);
  if (ret != rw_nblocks)
    {
      ferr("ERROR: Failed to encrypt write ret=%d\n", ret);
      DEBUGASSERT(0);
    }

  memset(rbuf, 0, size);
  ret = MTD_BREAD(enc_mtd, rw_block, rw_nblocks, rbuf);
  if (ret != rw_nblocks)
    {
      ferr("ERROR: Failed to decrypt read ret=%d\n", ret);
      DEBUGASSERT(0);
    }

  if (memcmp(wbuf, rbuf, size))
    {
      ferr("ASSERT: Encrypted and decrypted data is not same\n");
      DEBUGASSERT(0);
    }

  memset(rbuf, 0, size);
  ret = MTD_BREAD(mtd, rw_block, rw_nblocks, rbuf);
  if (ret != rw_nblocks)
    {
      ferr("ERROR: Failed to read ret=%d\n", ret);
      DEBUGASSERT(0);
    }

  if (!memcmp(wbuf, rbuf, size))
    {
      ferr("ASSERT: Encrypted and normal data is same\n");
      DEBUGASSERT(0);
    }

  for (i = 0; i < size; i++)
    {
      wbuf[i] = (uint8_t)random();
    }

  ret = MTD_ERASE(enc_mtd, erase_block, erase_nblocks);
  if (ret != erase_nblocks)
    {
      ferr("ERROR: Failed to erase ret=%d\n", ret);
      DEBUGASSERT(0);
    }

  ret = MTD_BWRITE(mtd, rw_block, rw_nblocks, wbuf);
  if (ret != rw_nblocks)
    {
      ferr("ERROR: Failed to write ret=%d\n", ret);
      DEBUGASSERT(0);
    }

  memset(rbuf, 0, size);
  ret = MTD_BREAD(enc_mtd, rw_block, rw_nblocks, rbuf);
  if (ret != rw_nblocks)
    {
      ferr("ERROR: Failed to decrypt read ret=%d\n", ret);
      DEBUGASSERT(0);
    }

  if (!memcmp(wbuf, rbuf, size))
    {
      ferr("ASSERT: Normal and decrypted data is same\n");
      DEBUGASSERT(0);
    }

  memset(rbuf, 0, size);
  ret = MTD_BREAD(mtd, rw_block, rw_nblocks, rbuf);
  if (ret != rw_nblocks)
    {
      ferr("ERROR: Failed to read ret=%d\n", ret);
      DEBUGASSERT(0);
    }

  if (memcmp(wbuf, rbuf, size))
    {
      ferr("ASSERT: Normal and normal data is not same\n");
      DEBUGASSERT(0);
    }

  kmm_free(wbuf);
  kmm_free(rbuf);

  finfo("INFO: ESP32 SPI Flash encryption test successfully\n");
}

#endif /* CONFIG_ESP32_SPIFLASH_ENCRYPTION_TEST */
