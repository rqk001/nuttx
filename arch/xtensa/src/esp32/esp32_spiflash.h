/****************************************************************************
 * arch/xtensa/src/esp32/esp32_spiflash.h
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

#ifndef __ARCH_XTENSA_SRC_ESP32_ESP32_SPIFLASH_H
#define __ARCH_XTENSA_SRC_ESP32_ESP32_SPIFLASH_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <stdint.h>
#include <nuttx/mtd/mtd.h>

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define CACHE_BLOCKSIZE (32*1024)

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef CONFIG_ESP32_SPIRAM

/****************************************************************************
 * Name: esp32_set_bank
 *
 * Description:
 *   Set Ext-SRAM-Cache mmu mapping.
 *
 * Input Parameters:
 *   virt_bank - Beginning of the virtual bank
 *   phys_bank - Beginning of the physical bank
 *   ct        - Number of banks
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

void esp32_set_bank(int virt_bank, int phys_bank, int ct);

#endif

/****************************************************************************
 * Name: esp32_spiflash_init
 *
 * Description:
 *   Initialize ESP32 SPI flash driver.
 *
 * Returned Value:
 *   OK if success or a negative value if fail.
 *
 ****************************************************************************/

int esp32_spiflash_init(void);

/****************************************************************************
 * Name: esp32_spiflash_alloc_mtdpart
 *
 * Description:
 *   Allocate an MTD partition from the ESP32 SPI Flash.
 *
 * Input Parameters:
 *   mtd_offset - MTD Partition offset from the base address in SPI Flash.
 *   mtd_size   - Size for the MTD partition.
 *   encrypted  - Flag indicating whether the newly allocated partition will
 *                have its content encrypted.
 *
 * Returned Value:
 *   ESP32 SPI Flash MTD data pointer if success or NULL if fail.
 *
 ****************************************************************************/

struct mtd_dev_s *esp32_spiflash_alloc_mtdpart(uint32_t mtd_offset,
                                               uint32_t mtd_size,
                                               bool encrypted);

/****************************************************************************
 * Name: esp32_spiflash_get_mtd
 *
 * Description:
 *   Get ESP32 SPI Flash raw MTD.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   ESP32 SPI Flash raw MTD data pointer.
 *
 ****************************************************************************/

struct mtd_dev_s *esp32_spiflash_get_mtd(void);

/****************************************************************************
 * Name: esp32_spiflash_encrypt_get_mtd
 *
 * Description:
 *   Get ESP32 SPI Flash encryption raw MTD.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   ESP32 SPI Flash encryption raw MTD data pointer.
 *
 ****************************************************************************/

struct mtd_dev_s *esp32_spiflash_encrypt_get_mtd(void);

/****************************************************************************
 * Name: esp32_flash_encryption_enabled
 *
 * Description:
 *   Check if ESP32 enables SPI Flash encryption.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   True: SPI Flash encryption is enable, False if not.
 *
 ****************************************************************************/

bool esp32_flash_encryption_enabled(void);

#ifdef CONFIG_ESP32_SPI_FLASH_MMAP

/****************************************************************************
 * Name: esp32_spiflash_mmu_init
 *
 * Description:
 *   Initialize MMU for accessing SPI flash by I-Bus.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void esp32_spiflash_mmu_init(void);

/****************************************************************************
 * Name: esp32_flash_mmap
 *
 * Description:
 *   Map SPI flash physical space to I-Bus address.
 *
 * Input Parameters:
 *   flash_addr - SPI flash physical space start address
 *   flash_size - SPI flash physical space size
 *   mapped_ptr - Mapped I-Bus address
 *
 * Returned Value:
 *   0 if success or a negative value if failed.
 *
 ****************************************************************************/

int esp32_flash_mmap(uint32_t flash_addr, uint32_t flash_size,
                     uint32_t *mapped_ptr);

/****************************************************************************
 * Name: esp32_flash_unmap
 *
 * Description:
 *   Free mapped I-Bus space.
 *
 * Input Parameters:
 *   mapped_ptr  - Mapped I-Bus space start address
 *   mapped_size - Mapped I-Bus space size
 *
 * Returned Value:
 *   0 if success or a negative value if failed.
 *
 ****************************************************************************/

int esp32_flash_unmap(uint32_t mapped_ptr, uint32_t mapped_size);
#endif

#ifdef __cplusplus
}
#endif
#undef EXTERN

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_XTENSA_SRC_ESP32_ESP32_SPIFLASH_H */
