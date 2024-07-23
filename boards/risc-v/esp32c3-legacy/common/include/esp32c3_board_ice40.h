/****************************************************************************
 * boards/risc-v/esp32c3-legacy/common/include/esp32c3_board_ice40.h
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

#ifndef __BOARDS_RISCV_ESP32C3_LEGACY_COMMON_INCLUDE_ESP32C3_BOARD_ICE40_H
#define __BOARDS_RISCV_ESP32C3_LEGACY_COMMON_INCLUDE_ESP32C3_BOARD_ICE40_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

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
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: esp32c3_ice40_setup
 *
 * Description:
 *  Initialize ICE40 FPGA GPIOs, SPI and register the ICE40 driver.
 *
 * Returned Value:
 *  Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

#ifdef CONFIG_SPI_ICE40
int esp32c3_ice40_setup(void);
#endif

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_RISCV_ESP32C3_COMMON_INCLUDE_ESP32C3_BOARD_BMP180_H */
