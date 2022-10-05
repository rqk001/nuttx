/****************************************************************************
 * boards/arm/lpc17xx_40xx/pnev5180b/src/lpc17_40_romfs.h
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

#ifndef __BOARDS_ARM_LPC17XX_40XX_PNEV5180B_SRC_LPC17_40_ROMFS_H
#define __BOARDS_ARM_LPC17XX_40XX_PNEV5180B_SRC_LPC17_40_ROMFS_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#ifdef CONFIG_LPC17_40_ROMFS

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define ROMFS_SECTOR_SIZE 64

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: lpc17_40_romfs_initialize
 *
 * Description:
 *   Registers built-in ROMFS image as block device and mounts it.
 *
 * Returned Value:
 *   Zero (OK) on success, a negated errno value on error.
 *
 * Assumptions/Limitations:
 *   Memory addresses [romfs_data_begin .. romfs_data_end) should contain
 *   ROMFS volume data, as included in the assembly snippet in
 *   lpc17_40_romfs_initialize.c.
 *
 ****************************************************************************/

int lpc17_40_romfs_initialize(void);

#endif /* CONFIG_LPC17_40_ROMFS */

#endif /* __BOARDS_ARM_LPC17XX_40XX_PNEV5180B_SRC_LPC17_40_ROMFS_H */
