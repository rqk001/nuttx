/****************************************************************************
 * drivers/audio/cs35l41_cal_fw_img.c
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

#include "cs35l41_cal_fw_img.h"

/****************************************************************************
 * Public Data
 ****************************************************************************/

const uint8_t g_cs35l41_cal_fw_img[] =
{
  0xff, 0x98, 0xb9, 0x54,  /* IMG_MAGIC_NUMBER_1 */
  0x02, 0x00, 0x00, 0x00,  /* IMG_FORMAT_REV */
  0x90, 0x03, 0x00, 0x00,  /* IMG_SIZE */
  0x00, 0x00, 0x00, 0x00,  /* SYM_TABLE_SIZE */
  0x00, 0x00, 0x00, 0x00,  /* ALG_LIST_SIZE */
  0xa4, 0x00, 0x04, 0x00,  /* FW_ID */
  0x00, 0x2a, 0x00, 0x00,  /* FW_VERSION */
  0x02, 0x00, 0x00, 0x00,  /* DATA_BLOCKS */
  0x2c, 0x10, 0x00, 0x00,  /* MAX_BLOCK_SIZE */
  0x00, 0x00, 0x00, 0x00,  /* FW_IMG_VERSION */

  0x48, 0x03, 0x00, 0x00,  /* COEFF_BLOCK_SIZE_0_0 */
  0x5c, 0x01, 0xc0, 0x02,  /* COEFF_BLOCK_ADDR_0_0 */
  0x04, 0x00, 0x01, 0x1a, 0x03, 0x00, 0x00, 0x00, 0x00, 0x04, 0xd4, 0x00,
  0x80, 0x00, 0x06, 0x89, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x44, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0xac, 0x00, 0x00, 0x08, 0x00,
  0x07, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00,
  0x03, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x20, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x03, 0x85, 0x00,
  0xaf, 0x00, 0x03, 0xae, 0x03, 0xab, 0x00, 0x03, 0x00, 0x04, 0x80, 0x00,
  0x29, 0x00, 0x04, 0x7f, 0x04, 0x28, 0x00, 0x04, 0x00, 0x03, 0x87, 0x00,
  0xb5, 0x00, 0x03, 0xb6, 0x03, 0x86, 0x00, 0x03, 0x00, 0x00, 0x29, 0x00,
  0x00, 0x00, 0x00, 0x11, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00,
  0x05, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x20, 0x17, 0x6d, 0xb7, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00,
  0x03, 0x00, 0x00, 0x20, 0x7d, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
  0x32, 0x00, 0x00, 0x04, 0x00, 0x20, 0x00, 0x08, 0x00, 0x00, 0x05, 0x00,
  0x20, 0x00, 0x23, 0x83, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x06, 0x00, 0x00, 0x65, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
  0x07, 0x00, 0x00, 0x06, 0xb5, 0xab, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e,
  0x06, 0x00, 0x00, 0x19, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00,
  0x00, 0x00, 0x29, 0x4a, 0x08, 0x9d, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
  0x06, 0x00, 0x00, 0x06, 0xe7, 0x16, 0x00, 0x00, 0x7e, 0x35, 0x12, 0x80,
  0xcf, 0x00, 0x00, 0xcf, 0x00, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0x06, 0x00, 0x00, 0x07, 0x00, 0x06, 0x00, 0x00, 0x00, 0x20, 0x31, 0x00,
  0x06, 0x00, 0x00, 0x04, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x31, 0x00,
  0x07, 0x00, 0x00, 0x05, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x32, 0x00,
  0x04, 0x00, 0x00, 0x04, 0x33, 0xd7, 0x00, 0x00, 0x70, 0x34, 0x4a, 0x88,
  0xba, 0x01, 0x3d, 0xba, 0x3d, 0xba, 0x01, 0x3d, 0x00, 0x00, 0x07, 0x01,
  0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
  0x04, 0x00, 0x00, 0x32, 0x00, 0x04, 0x00, 0x00, 0x83, 0xb5, 0xcb, 0x00,
  0xba, 0x79, 0x36, 0x3a, 0x3d, 0xba, 0x01, 0x3d, 0x01, 0x3d, 0xba, 0x01,
  0x04, 0x00, 0x00, 0x07, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x3e, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0x7d, 0x8a, 0x6c, 0x53, 0x02, 0x18, 0x6c, 0x22, 0x02, 0x02, 0x18, 0x02,
  0x08, 0x02, 0x02, 0x18, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x3e, 0x00,
  0x04, 0x00, 0x00, 0x04, 0xd2, 0xf3, 0x00, 0x00, 0x77, 0x61, 0x33, 0x84,
  0x18, 0x02, 0x02, 0x18, 0x02, 0x18, 0x02, 0x02, 0x00, 0x00, 0x08, 0x02,
  0x04, 0x00, 0x00, 0x07, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x3e, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0xa9, 0x84, 0xb9, 0xc0, 0xb6, 0xab, 0x7c, 0x92, 0x00, 0x00, 0x00, 0x01,
  0x20, 0xfe, 0x49, 0x55, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0xc0, 0x00, 0x00, 0x04, 0x92, 0xa9, 0x84, 0xb9, 0x01, 0xb6, 0xab, 0x7c,
  0x55, 0x00, 0x00, 0x00, 0x00, 0x20, 0xfe, 0x49, 0x00, 0x00, 0x20, 0x00,
  0x8c, 0x00, 0x00, 0x0d, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00,
  0xd7, 0x00, 0x00, 0x05, 0x34, 0x4a, 0x88, 0x33, 0x01, 0x3d, 0xba, 0x70,
  0xba, 0x01, 0x3d, 0xba, 0x00, 0x07, 0x01, 0x3d, 0x00, 0x00, 0x05, 0x00,
  0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x32, 0x00,
  0x05, 0x00, 0x00, 0x05, 0xb5, 0xcb, 0x00, 0x00, 0x79, 0x36, 0x3a, 0x83,
  0xba, 0x01, 0x3d, 0xba, 0x3d, 0xba, 0x01, 0x3d, 0x00, 0x00, 0x07, 0x01,
  0x05, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
  0x05, 0x00, 0x00, 0x3e, 0x00, 0x05, 0x00, 0x00, 0x8a, 0x6c, 0x53, 0x00,
  0x18, 0x6c, 0x22, 0x7d, 0x02, 0x18, 0x02, 0x02, 0x02, 0x02, 0x18, 0x02,
  0x07, 0x00, 0x00, 0x08, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00,
  0xf3, 0x00, 0x00, 0x05, 0x61, 0x33, 0x84, 0xd2, 0x02, 0x02, 0x18, 0x77,
  0x18, 0x02, 0x02, 0x18, 0x00, 0x08, 0x02, 0x02, 0x00, 0x00, 0x07, 0x00,
  0x05, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
  0x05, 0x00, 0x00, 0x3e, 0x00, 0x05, 0x00, 0x00, 0x84, 0xb9, 0xc0, 0x00,
  0xab, 0x7c, 0x92, 0xa9, 0x00, 0x00, 0x01, 0xb6, 0xfe, 0x49, 0x55, 0x00,
  0x3e, 0x00, 0x00, 0x20, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00,
  0xa9, 0x84, 0xb9, 0xc0, 0xb6, 0xab, 0x7c, 0x92, 0x00, 0x00, 0x00, 0x01,
  0x20, 0xfe, 0x49, 0x55, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
  0x0e, 0x00, 0x00, 0x05, 0x01, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00,
  0x0d, 0x00, 0x02, 0x0c, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x0f, 0x00, 0x00, 0x0d, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x00,
  0x05, 0x00, 0x00, 0x08, 0x1d, 0x49, 0x00, 0x00, 0x00, 0x23, 0x83, 0x00,
  0x2c, 0x00, 0x08, 0x32, 0x00, 0x19, 0x00, 0x7d, 0x00, 0x00, 0x10, 0x00,
  0x02, 0x00, 0x00, 0x06, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
  0x08, 0x00, 0x00, 0x00,  /* COEFF_BLOCK_SIZE_0_1 */
  0x30, 0x06, 0x40, 0x03,  /* COEFF_BLOCK_ADDR_0_1 */
  0x00, 0x00, 0x00, 0x03, 0x00, 0x7f, 0xff, 0xff,

  0xa6, 0xe2, 0x6b, 0x93,  /* IMG_MAGIC_NUMBER_2 */
  0x7d, 0x38, 0x27, 0x9a,  /* IMG_CHECKSUM */
};
