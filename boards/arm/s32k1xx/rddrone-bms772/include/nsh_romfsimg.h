/****************************************************************************
 * boards/arm/s32k1xx/rddrone-bms772/include/nsh_romfsimg.h
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

/* Copyright 2022 NXP */

#ifndef __BOARDS_ARM_S32K1XX_RDDRONE_BMS772_INCLUDE_NSH_ROMFSIMG_H
#define __BOARDS_ARM_S32K1XX_RDDRONE_BMS772_INCLUDE_NSH_ROMFSIMG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifdef CONFIG_DEBUG_FEATURES

/* Full init script is used, including a call to the free command to show the
 * memory usage after board initialization has finished.
 */

const unsigned char aligned_data(4) romfs_img[] =
{
  0x2d, 0x72, 0x6f, 0x6d, 0x31, 0x66, 0x73, 0x2d, 0x00, 0x00, 0x01, 0xb0,
  0x98, 0xcd, 0xf3, 0x32, 0x4e, 0x53, 0x48, 0x49, 0x6e, 0x69, 0x74, 0x56,
  0x6f, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49,
  0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0xd1, 0xff, 0xff, 0x97,
  0x2e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x20,
  0x00, 0x00, 0x00, 0x00, 0xd1, 0xd1, 0xff, 0x80, 0x2e, 0x2e, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x68, 0x2d, 0x96, 0x03, 0x69, 0x6e, 0x69, 0x74, 0x2e, 0x64, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x7a,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xce, 0x8d, 0x9c, 0xaa, 0xb8,
  0x72, 0x63, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x23, 0x20, 0x49, 0x6e, 0x69, 0x74, 0x69, 0x61,
  0x6c, 0x69, 0x7a, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20, 0x52, 0x44, 0x44,
  0x52, 0x4f, 0x4e, 0x45, 0x2d, 0x42, 0x4d, 0x53, 0x37, 0x37, 0x32, 0x20,
  0x42, 0x4d, 0x53, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74,
  0x69, 0x6f, 0x6e, 0x0a, 0x65, 0x63, 0x68, 0x6f, 0x20, 0x22, 0x41, 0x76,
  0x61, 0x69, 0x6c, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x6d, 0x65, 0x6d, 0x6f,
  0x72, 0x79, 0x20, 0x61, 0x66, 0x74, 0x65, 0x72, 0x20, 0x62, 0x6f, 0x61,
  0x72, 0x64, 0x20, 0x69, 0x6e, 0x69, 0x74, 0x69, 0x61, 0x6c, 0x69, 0x7a,
  0x61, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x22, 0x0a, 0x22, 0x66, 0x72, 0x65,
  0x65, 0x22, 0x0a, 0x65, 0x63, 0x68, 0x6f, 0x20, 0x22, 0x42, 0x72, 0x69,
  0x6e, 0x67, 0x20, 0x75, 0x70, 0x20, 0x63, 0x61, 0x6e, 0x30, 0x20, 0x69,
  0x6e, 0x74, 0x65, 0x72, 0x66, 0x61, 0x63, 0x65, 0x3a, 0x22, 0x0a, 0x22,
  0x69, 0x66, 0x75, 0x70, 0x22, 0x20, 0x22, 0x63, 0x61, 0x6e, 0x30, 0x22,
  0x0a, 0x65, 0x63, 0x68, 0x6f, 0x20, 0x22, 0x52, 0x44, 0x44, 0x52, 0x4f,
  0x4e, 0x45, 0x2d, 0x42, 0x4d, 0x53, 0x37, 0x37, 0x32, 0x3a, 0x20, 0x53,
  0x74, 0x61, 0x72, 0x74, 0x69, 0x6e, 0x67, 0x20, 0x42, 0x4d, 0x53, 0x20,
  0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x22,
  0x0a, 0x22, 0x62, 0x6d, 0x73, 0x22, 0x00, 0x00, 0x00, 0x00, 0x01, 0x90,
  0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0xd1, 0xff, 0xfe, 0x10,
  0x2e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
  0x00, 0x00, 0x00, 0x00, 0xd1, 0xd1, 0xff, 0xe0, 0x2e, 0x2e, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};
const unsigned int romfs_img_len = 1024;

#else /* !CONFIG_DEBUG_FEATURES */

/* Init script does not call the free command to show available memory */

const unsigned char aligned_data(4) romfs_img[] =
{
  0x2d, 0x72, 0x6f, 0x6d, 0x31, 0x66, 0x73, 0x2d, 0x00, 0x00, 0x01, 0xb0,
  0x4e, 0x7a, 0x78, 0x04, 0x4e, 0x53, 0x48, 0x49, 0x6e, 0x69, 0x74, 0x56,
  0x6f, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49,
  0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0xd1, 0xff, 0xff, 0x97,
  0x2e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x20,
  0x00, 0x00, 0x00, 0x00, 0xd1, 0xd1, 0xff, 0x80, 0x2e, 0x2e, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x68, 0x2d, 0x96, 0x03, 0x69, 0x6e, 0x69, 0x74, 0x2e, 0x64, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x7a,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x8d, 0x9c, 0xaa, 0xb6,
  0x72, 0x63, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x23, 0x20, 0x49, 0x6e, 0x69, 0x74, 0x69, 0x61,
  0x6c, 0x69, 0x7a, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20, 0x52, 0x44, 0x44,
  0x52, 0x4f, 0x4e, 0x45, 0x2d, 0x42, 0x4d, 0x53, 0x37, 0x37, 0x32, 0x20,
  0x42, 0x4d, 0x53, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74,
  0x69, 0x6f, 0x6e, 0x0a, 0x23, 0x65, 0x63, 0x68, 0x6f, 0x20, 0x22, 0x41,
  0x76, 0x61, 0x69, 0x6c, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x6d, 0x65, 0x6d,
  0x6f, 0x72, 0x79, 0x20, 0x61, 0x66, 0x74, 0x65, 0x72, 0x20, 0x62, 0x6f,
  0x61, 0x72, 0x64, 0x20, 0x69, 0x6e, 0x69, 0x74, 0x69, 0x61, 0x6c, 0x69,
  0x7a, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x22, 0x0a, 0x23, 0x22, 0x66,
  0x72, 0x65, 0x65, 0x22, 0x0a, 0x65, 0x63, 0x68, 0x6f, 0x20, 0x22, 0x42,
  0x72, 0x69, 0x6e, 0x67, 0x20, 0x75, 0x70, 0x20, 0x63, 0x61, 0x6e, 0x30,
  0x20, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x66, 0x61, 0x63, 0x65, 0x3a, 0x22,
  0x0a, 0x22, 0x69, 0x66, 0x75, 0x70, 0x22, 0x20, 0x22, 0x63, 0x61, 0x6e,
  0x30, 0x22, 0x0a, 0x65, 0x63, 0x68, 0x6f, 0x20, 0x22, 0x52, 0x44, 0x44,
  0x52, 0x4f, 0x4e, 0x45, 0x2d, 0x42, 0x4d, 0x53, 0x37, 0x37, 0x32, 0x3a,
  0x20, 0x53, 0x74, 0x61, 0x72, 0x74, 0x69, 0x6e, 0x67, 0x20, 0x42, 0x4d,
  0x53, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f,
  0x6e, 0x22, 0x0a, 0x22, 0x62, 0x6d, 0x73, 0x22, 0x00, 0x00, 0x01, 0x90,
  0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0xd1, 0xff, 0xfe, 0x10,
  0x2e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
  0x00, 0x00, 0x00, 0x00, 0xd1, 0xd1, 0xff, 0xe0, 0x2e, 0x2e, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};
const unsigned int romfs_img_len = 1024;

#endif /* CONFIG_DEBUG_FEATURES */
#endif /* __BOARDS_ARM_S32K1XX_RDDRONE_BMS772_INCLUDE_NSH_ROMFSIMG_H */
