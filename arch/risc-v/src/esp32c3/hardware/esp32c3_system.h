/****************************************************************************
 * arch/risc-v/src/esp32c3/hardware/esp32c3_system.h
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

#ifndef __ARCH_RISCV_SRC_ESP32C3_HARDWARE_ESP32C3_SYSTEM_H
#define __ARCH_RISCV_SRC_ESP32C3_HARDWARE_ESP32C3_SYSTEM_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "esp32c3_soc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Performance Counter */

#define CSR_PCER_MACHINE    0x7e0
#define CSR_PCMR_MACHINE    0x7e1
#define CSR_PCCR_MACHINE    0x7e2

#define SYSTEM_CPU_PERI_CLK_EN_REG          (DR_REG_SYSTEM_BASE + 0x000)

/* SYSTEM_CLK_EN_DEDICATED_GPIO : R/W [7] : 1'b0 ; */

#define SYSTEM_CLK_EN_DEDICATED_GPIO    (BIT(7))
#define SYSTEM_CLK_EN_DEDICATED_GPIO_M  (BIT(7))
#define SYSTEM_CLK_EN_DEDICATED_GPIO_V  0x1
#define SYSTEM_CLK_EN_DEDICATED_GPIO_S  7

/* SYSTEM_CLK_EN_ASSIST_DEBUG : R/W [6] : 1'b0 ; */

#define SYSTEM_CLK_EN_ASSIST_DEBUG    (BIT(6))
#define SYSTEM_CLK_EN_ASSIST_DEBUG_M  (BIT(6))
#define SYSTEM_CLK_EN_ASSIST_DEBUG_V  0x1
#define SYSTEM_CLK_EN_ASSIST_DEBUG_S  6

#define SYSTEM_CPU_PERI_RST_EN_REG          (DR_REG_SYSTEM_BASE + 0x004)

/* SYSTEM_RST_EN_DEDICATED_GPIO : R/W [7] : 1'b1 ; */

#define SYSTEM_RST_EN_DEDICATED_GPIO    (BIT(7))
#define SYSTEM_RST_EN_DEDICATED_GPIO_M  (BIT(7))
#define SYSTEM_RST_EN_DEDICATED_GPIO_V  0x1
#define SYSTEM_RST_EN_DEDICATED_GPIO_S  7

/* SYSTEM_RST_EN_ASSIST_DEBUG : R/W [6] : 1'b1 ; */

#define SYSTEM_RST_EN_ASSIST_DEBUG    (BIT(6))
#define SYSTEM_RST_EN_ASSIST_DEBUG_M  (BIT(6))
#define SYSTEM_RST_EN_ASSIST_DEBUG_V  0x1
#define SYSTEM_RST_EN_ASSIST_DEBUG_S  6

#define SYSTEM_CPU_PER_CONF_REG          (DR_REG_SYSTEM_BASE + 0x008)

/* SYSTEM_CPU_WAITI_DELAY_NUM : R/W [7:4] : 4'h0 ; */

#define SYSTEM_CPU_WAITI_DELAY_NUM   0x0000000f
#define SYSTEM_CPU_WAITI_DELAY_NUM_M (SYSTEM_CPU_WAITI_DELAY_NUM_V << SYSTEM_CPU_WAITI_DELAY_NUM_S
#define SYSTEM_CPU_WAITI_DELAY_NUM_V  0xf
#define SYSTEM_CPU_WAITI_DELAY_NUM_S  4

/* SYSTEM_CPU_WAIT_MODE_FORCE_ON : R/W [3] : 1'b1 ; */

#define SYSTEM_CPU_WAIT_MODE_FORCE_ON    (BIT(3))
#define SYSTEM_CPU_WAIT_MODE_FORCE_ON_M  (BIT(3))
#define SYSTEM_CPU_WAIT_MODE_FORCE_ON_V  0x1
#define SYSTEM_CPU_WAIT_MODE_FORCE_ON_S  3

/* SYSTEM_PLL_FREQ_SEL : R/W [2] : 1'b1 ; */

#define SYSTEM_PLL_FREQ_SEL    (BIT(2))
#define SYSTEM_PLL_FREQ_SEL_M  (BIT(2))
#define SYSTEM_PLL_FREQ_SEL_V  0x1
#define SYSTEM_PLL_FREQ_SEL_S  2

/* SYSTEM_CPUPERIOD_SEL : R/W [1:0] : 2'b0 ; */

#define SYSTEM_CPUPERIOD_SEL    0x00000003
#define SYSTEM_CPUPERIOD_SEL_M  (SYSTEM_CPUPERIOD_SEL_V << SYSTEM_CPUPERIOD_SEL_S)
#define SYSTEM_CPUPERIOD_SEL_V  0x3
#define SYSTEM_CPUPERIOD_SEL_S  0

#define SYSTEM_MEM_PD_MASK_REG          (DR_REG_SYSTEM_BASE + 0x00c)

/* SYSTEM_LSLP_MEM_PD_MASK : R/W [0] : 1'b1 ; */

#define SYSTEM_LSLP_MEM_PD_MASK    (BIT(0))
#define SYSTEM_LSLP_MEM_PD_MASK_M  (BIT(0))
#define SYSTEM_LSLP_MEM_PD_MASK_V  0x1
#define SYSTEM_LSLP_MEM_PD_MASK_S  0

#define SYSTEM_PERIP_CLK_EN0_REG          (DR_REG_SYSTEM_BASE + 0x010)

/* SYSTEM_SPI4_CLK_EN : R/W [31] : 1'h1 ; */

#define SYSTEM_SPI4_CLK_EN    (BIT(31))
#define SYSTEM_SPI4_CLK_EN_M  (BIT(31))
#define SYSTEM_SPI4_CLK_EN_V  0x1
#define SYSTEM_SPI4_CLK_EN_S  31

/* SYSTEM_ADC2_ARB_CLK_EN : R/W [30] : 1'b1 ; */

#define SYSTEM_ADC2_ARB_CLK_EN    (BIT(30))
#define SYSTEM_ADC2_ARB_CLK_EN_M  (BIT(30))
#define SYSTEM_ADC2_ARB_CLK_EN_V  0x1
#define SYSTEM_ADC2_ARB_CLK_EN_S  30

/* SYSTEM_SYSTIMER_CLK_EN : R/W [29] : 1'b1 ; */

#define SYSTEM_SYSTIMER_CLK_EN    (BIT(29))
#define SYSTEM_SYSTIMER_CLK_EN_M  (BIT(29))
#define SYSTEM_SYSTIMER_CLK_EN_V  0x1
#define SYSTEM_SYSTIMER_CLK_EN_S  29

/* SYSTEM_APB_SARADC_CLK_EN : R/W [28] : 1'b1 ; */

#define SYSTEM_APB_SARADC_CLK_EN    (BIT(28))
#define SYSTEM_APB_SARADC_CLK_EN_M  (BIT(28))
#define SYSTEM_APB_SARADC_CLK_EN_V  0x1
#define SYSTEM_APB_SARADC_CLK_EN_S  28

/* SYSTEM_SPI3_DMA_CLK_EN : R/W [27] : 1'b1 ; */

#define SYSTEM_SPI3_DMA_CLK_EN    (BIT(27))
#define SYSTEM_SPI3_DMA_CLK_EN_M  (BIT(27))
#define SYSTEM_SPI3_DMA_CLK_EN_V  0x1
#define SYSTEM_SPI3_DMA_CLK_EN_S  27

/* SYSTEM_PWM3_CLK_EN : R/W [26] : 1'b0 ; */

#define SYSTEM_PWM3_CLK_EN    (BIT(26))
#define SYSTEM_PWM3_CLK_EN_M  (BIT(26))
#define SYSTEM_PWM3_CLK_EN_V  0x1
#define SYSTEM_PWM3_CLK_EN_S  26

/* SYSTEM_PWM2_CLK_EN : R/W [25] : 1'b0 ; */

#define SYSTEM_PWM2_CLK_EN    (BIT(25))
#define SYSTEM_PWM2_CLK_EN_M  (BIT(25))
#define SYSTEM_PWM2_CLK_EN_V  0x1
#define SYSTEM_PWM2_CLK_EN_S  25

/* SYSTEM_UART_MEM_CLK_EN : R/W [24] : 1'b1 ; */

#define SYSTEM_UART_MEM_CLK_EN    (BIT(24))
#define SYSTEM_UART_MEM_CLK_EN_M  (BIT(24))
#define SYSTEM_UART_MEM_CLK_EN_V  0x1
#define SYSTEM_UART_MEM_CLK_EN_S  24

/* SYSTEM_USB_DEVICE_CLK_EN : R/W [23] : 1'b1 ; */

#define SYSTEM_USB_DEVICE_CLK_EN    (BIT(23))
#define SYSTEM_USB_DEVICE_CLK_EN_M  (BIT(23))
#define SYSTEM_USB_DEVICE_CLK_EN_V  0x1
#define SYSTEM_USB_DEVICE_CLK_EN_S  23

/* SYSTEM_SPI2_DMA_CLK_EN : R/W [22] : 1'b1 ; */

#define SYSTEM_SPI2_DMA_CLK_EN    (BIT(22))
#define SYSTEM_SPI2_DMA_CLK_EN_M  (BIT(22))
#define SYSTEM_SPI2_DMA_CLK_EN_V  0x1
#define SYSTEM_SPI2_DMA_CLK_EN_S  22

/* SYSTEM_I2S1_CLK_EN : R/W [21] : 1'b0 ; */

#define SYSTEM_I2S1_CLK_EN    (BIT(21))
#define SYSTEM_I2S1_CLK_EN_M  (BIT(21))
#define SYSTEM_I2S1_CLK_EN_V  0x1
#define SYSTEM_I2S1_CLK_EN_S  21

/* SYSTEM_PWM1_CLK_EN : R/W [20] : 1'b0 ; */

#define SYSTEM_PWM1_CLK_EN    (BIT(20))
#define SYSTEM_PWM1_CLK_EN_M  (BIT(20))
#define SYSTEM_PWM1_CLK_EN_V  0x1
#define SYSTEM_PWM1_CLK_EN_S  20

/* SYSTEM_TWAI_CLK_EN : R/W [19] : 1'b0 ; */

#define SYSTEM_TWAI_CLK_EN    (BIT(19))
#define SYSTEM_TWAI_CLK_EN_M  (BIT(19))
#define SYSTEM_TWAI_CLK_EN_V  0x1
#define SYSTEM_TWAI_CLK_EN_S  19

/* SYSTEM_I2C_EXT1_CLK_EN : R/W [18] : 1'b0 ; */

#define SYSTEM_I2C_EXT1_CLK_EN    (BIT(18))
#define SYSTEM_I2C_EXT1_CLK_EN_M  (BIT(18))
#define SYSTEM_I2C_EXT1_CLK_EN_V  0x1
#define SYSTEM_I2C_EXT1_CLK_EN_S  18

/* SYSTEM_PWM0_CLK_EN : R/W [17] : 1'b0 ; */

#define SYSTEM_PWM0_CLK_EN    (BIT(17))
#define SYSTEM_PWM0_CLK_EN_M  (BIT(17))
#define SYSTEM_PWM0_CLK_EN_V  0x1
#define SYSTEM_PWM0_CLK_EN_S  17

/* SYSTEM_SPI3_CLK_EN : R/W [16] : 1'b1 ; */

#define SYSTEM_SPI3_CLK_EN    (BIT(16))
#define SYSTEM_SPI3_CLK_EN_M  (BIT(16))
#define SYSTEM_SPI3_CLK_EN_V  0x1
#define SYSTEM_SPI3_CLK_EN_S  16

/* SYSTEM_TIMERGROUP1_CLK_EN : R/W [15] : 1'b1 ; */

#define SYSTEM_TIMERGROUP1_CLK_EN    (BIT(15))
#define SYSTEM_TIMERGROUP1_CLK_EN_M  (BIT(15))
#define SYSTEM_TIMERGROUP1_CLK_EN_V  0x1
#define SYSTEM_TIMERGROUP1_CLK_EN_S  15

/* SYSTEM_EFUSE_CLK_EN : R/W [14] : 1'b1 ; */

#define SYSTEM_EFUSE_CLK_EN    (BIT(14))
#define SYSTEM_EFUSE_CLK_EN_M  (BIT(14))
#define SYSTEM_EFUSE_CLK_EN_V  0x1
#define SYSTEM_EFUSE_CLK_EN_S  14

/* SYSTEM_TIMERGROUP_CLK_EN : R/W [13] : 1'b1 ; */

#define SYSTEM_TIMERGROUP_CLK_EN    (BIT(13))
#define SYSTEM_TIMERGROUP_CLK_EN_M  (BIT(13))
#define SYSTEM_TIMERGROUP_CLK_EN_V  0x1
#define SYSTEM_TIMERGROUP_CLK_EN_S  13

/* SYSTEM_UHCI1_CLK_EN : R/W [12] : 1'b0 ; */

#define SYSTEM_UHCI1_CLK_EN    (BIT(12))
#define SYSTEM_UHCI1_CLK_EN_M  (BIT(12))
#define SYSTEM_UHCI1_CLK_EN_V  0x1
#define SYSTEM_UHCI1_CLK_EN_S  12

/* SYSTEM_LEDC_CLK_EN : R/W [11] : 1'b0 ; */

#define SYSTEM_LEDC_CLK_EN    (BIT(11))
#define SYSTEM_LEDC_CLK_EN_M  (BIT(11))
#define SYSTEM_LEDC_CLK_EN_V  0x1
#define SYSTEM_LEDC_CLK_EN_S  11

/* SYSTEM_PCNT_CLK_EN : R/W [10] : 1'b0 ; */

#define SYSTEM_PCNT_CLK_EN    (BIT(10))
#define SYSTEM_PCNT_CLK_EN_M  (BIT(10))
#define SYSTEM_PCNT_CLK_EN_V  0x1
#define SYSTEM_PCNT_CLK_EN_S  10

/* SYSTEM_RMT_CLK_EN : R/W [9] : 1'b0 ; */

#define SYSTEM_RMT_CLK_EN    (BIT(9))
#define SYSTEM_RMT_CLK_EN_M  (BIT(9))
#define SYSTEM_RMT_CLK_EN_V  0x1
#define SYSTEM_RMT_CLK_EN_S  9

/* SYSTEM_UHCI0_CLK_EN : R/W [8] : 1'b0 ; */

#define SYSTEM_UHCI0_CLK_EN    (BIT(8))
#define SYSTEM_UHCI0_CLK_EN_M  (BIT(8))
#define SYSTEM_UHCI0_CLK_EN_V  0x1
#define SYSTEM_UHCI0_CLK_EN_S  8

/* SYSTEM_I2C_EXT0_CLK_EN : R/W [7] : 1'b0 ; */

#define SYSTEM_I2C_EXT0_CLK_EN    (BIT(7))
#define SYSTEM_I2C_EXT0_CLK_EN_M  (BIT(7))
#define SYSTEM_I2C_EXT0_CLK_EN_V  0x1
#define SYSTEM_I2C_EXT0_CLK_EN_S  7

/* SYSTEM_SPI2_CLK_EN : R/W [6] : 1'b1 ; */

#define SYSTEM_SPI2_CLK_EN    (BIT(6))
#define SYSTEM_SPI2_CLK_EN_M  (BIT(6))
#define SYSTEM_SPI2_CLK_EN_V  0x1
#define SYSTEM_SPI2_CLK_EN_S  6

/* SYSTEM_UART1_CLK_EN : R/W [5] : 1'b1 ; */

#define SYSTEM_UART1_CLK_EN    (BIT(5))
#define SYSTEM_UART1_CLK_EN_M  (BIT(5))
#define SYSTEM_UART1_CLK_EN_V  0x1
#define SYSTEM_UART1_CLK_EN_S  5

/* SYSTEM_I2S0_CLK_EN : R/W [4] : 1'b0 ; */

#define SYSTEM_I2S0_CLK_EN    (BIT(4))
#define SYSTEM_I2S0_CLK_EN_M  (BIT(4))
#define SYSTEM_I2S0_CLK_EN_V  0x1
#define SYSTEM_I2S0_CLK_EN_S  4

/* SYSTEM_WDG_CLK_EN : R/W [3] : 1'b1 ; */

#define SYSTEM_WDG_CLK_EN    (BIT(3))
#define SYSTEM_WDG_CLK_EN_M  (BIT(3))
#define SYSTEM_WDG_CLK_EN_V  0x1
#define SYSTEM_WDG_CLK_EN_S  3

/* SYSTEM_UART_CLK_EN : R/W [2] : 1'b1 ; */

#define SYSTEM_UART_CLK_EN    (BIT(2))
#define SYSTEM_UART_CLK_EN_M  (BIT(2))
#define SYSTEM_UART_CLK_EN_V  0x1
#define SYSTEM_UART_CLK_EN_S  2

/* SYSTEM_SPI01_CLK_EN : R/W [1] : 1'b1 ; */

#define SYSTEM_SPI01_CLK_EN    (BIT(1))
#define SYSTEM_SPI01_CLK_EN_M  (BIT(1))
#define SYSTEM_SPI01_CLK_EN_V  0x1
#define SYSTEM_SPI01_CLK_EN_S  1

/* SYSTEM_TIMERS_CLK_EN : R/W [0] : 1'b1 ; */

#define SYSTEM_TIMERS_CLK_EN    (BIT(0))
#define SYSTEM_TIMERS_CLK_EN_M  (BIT(0))
#define SYSTEM_TIMERS_CLK_EN_V  0x1
#define SYSTEM_TIMERS_CLK_EN_S  0

#define SYSTEM_PERIP_CLK_EN1_REG          (DR_REG_SYSTEM_BASE + 0x014)

/* SYSTEM_TSENS_CLK_EN : R/W [10] : 1'b0 ; */

#define SYSTEM_TSENS_CLK_EN    (BIT(10))
#define SYSTEM_TSENS_CLK_EN_M  (BIT(10))
#define SYSTEM_TSENS_CLK_EN_V  0x1
#define SYSTEM_TSENS_CLK_EN_S  10

/* SYSTEM_UART2_CLK_EN : R/W [9] : 1'b1 ; */

#define SYSTEM_UART2_CLK_EN    (BIT(9))
#define SYSTEM_UART2_CLK_EN_M  (BIT(9))
#define SYSTEM_UART2_CLK_EN_V  0x1
#define SYSTEM_UART2_CLK_EN_S  9

/* SYSTEM_LCD_CAM_CLK_EN : R/W [8] : 1'b0 ; */

#define SYSTEM_LCD_CAM_CLK_EN    (BIT(8))
#define SYSTEM_LCD_CAM_CLK_EN_M  (BIT(8))
#define SYSTEM_LCD_CAM_CLK_EN_V  0x1
#define SYSTEM_LCD_CAM_CLK_EN_S  8

/* SYSTEM_SDIO_HOST_CLK_EN : R/W [7] : 1'b0 ; */

#define SYSTEM_SDIO_HOST_CLK_EN    (BIT(7))
#define SYSTEM_SDIO_HOST_CLK_EN_M  (BIT(7))
#define SYSTEM_SDIO_HOST_CLK_EN_V  0x1
#define SYSTEM_SDIO_HOST_CLK_EN_S  7

/* SYSTEM_DMA_CLK_EN : R/W [6] : 1'b0 ; */

#define SYSTEM_DMA_CLK_EN    (BIT(6))
#define SYSTEM_DMA_CLK_EN_M  (BIT(6))
#define SYSTEM_DMA_CLK_EN_V  0x1
#define SYSTEM_DMA_CLK_EN_S  6

/* SYSTEM_CRYPTO_HMAC_CLK_EN : R/W [5] : 1'b0 ; */

#define SYSTEM_CRYPTO_HMAC_CLK_EN    (BIT(5))
#define SYSTEM_CRYPTO_HMAC_CLK_EN_M  (BIT(5))
#define SYSTEM_CRYPTO_HMAC_CLK_EN_V  0x1
#define SYSTEM_CRYPTO_HMAC_CLK_EN_S  5

/* SYSTEM_CRYPTO_DS_CLK_EN : R/W [4] : 1'b0 ; */

#define SYSTEM_CRYPTO_DS_CLK_EN    (BIT(4))
#define SYSTEM_CRYPTO_DS_CLK_EN_M  (BIT(4))
#define SYSTEM_CRYPTO_DS_CLK_EN_V  0x1
#define SYSTEM_CRYPTO_DS_CLK_EN_S  4

/* SYSTEM_CRYPTO_RSA_CLK_EN : R/W [3] : 1'b0 ; */

#define SYSTEM_CRYPTO_RSA_CLK_EN    (BIT(3))
#define SYSTEM_CRYPTO_RSA_CLK_EN_M  (BIT(3))
#define SYSTEM_CRYPTO_RSA_CLK_EN_V  0x1
#define SYSTEM_CRYPTO_RSA_CLK_EN_S  3

/* SYSTEM_CRYPTO_SHA_CLK_EN : R/W [2] : 1'b0 ; */

#define SYSTEM_CRYPTO_SHA_CLK_EN    (BIT(2))
#define SYSTEM_CRYPTO_SHA_CLK_EN_M  (BIT(2))
#define SYSTEM_CRYPTO_SHA_CLK_EN_V  0x1
#define SYSTEM_CRYPTO_SHA_CLK_EN_S  2

/* SYSTEM_CRYPTO_AES_CLK_EN : R/W [1] : 1'b0 ; */

#define SYSTEM_CRYPTO_AES_CLK_EN    (BIT(1))
#define SYSTEM_CRYPTO_AES_CLK_EN_M  (BIT(1))
#define SYSTEM_CRYPTO_AES_CLK_EN_V  0x1
#define SYSTEM_CRYPTO_AES_CLK_EN_S  1

#define SYSTEM_PERIP_RST_EN0_REG          (DR_REG_SYSTEM_BASE + 0x018)

/* SYSTEM_SPI4_RST : R/W [31] : 1'h0 ; */

#define SYSTEM_SPI4_RST    (BIT(31))
#define SYSTEM_SPI4_RST_M  (BIT(31))
#define SYSTEM_SPI4_RST_V  0x1
#define SYSTEM_SPI4_RST_S  31

/* SYSTEM_ADC2_ARB_RST : R/W [30] : 1'b0 ; */

#define SYSTEM_ADC2_ARB_RST    (BIT(30))
#define SYSTEM_ADC2_ARB_RST_M  (BIT(30))
#define SYSTEM_ADC2_ARB_RST_V  0x1
#define SYSTEM_ADC2_ARB_RST_S  30

/* SYSTEM_SYSTIMER_RST : R/W [29] : 1'b0 ; */

#define SYSTEM_SYSTIMER_RST    (BIT(29))
#define SYSTEM_SYSTIMER_RST_M  (BIT(29))
#define SYSTEM_SYSTIMER_RST_V  0x1
#define SYSTEM_SYSTIMER_RST_S  29

/* SYSTEM_APB_SARADC_RST : R/W [28] : 1'b0 ; */

#define SYSTEM_APB_SARADC_RST    (BIT(28))
#define SYSTEM_APB_SARADC_RST_M  (BIT(28))
#define SYSTEM_APB_SARADC_RST_V  0x1
#define SYSTEM_APB_SARADC_RST_S  28

/* SYSTEM_SPI3_DMA_RST : R/W [27] : 1'b0 ; */

#define SYSTEM_SPI3_DMA_RST    (BIT(27))
#define SYSTEM_SPI3_DMA_RST_M  (BIT(27))
#define SYSTEM_SPI3_DMA_RST_V  0x1
#define SYSTEM_SPI3_DMA_RST_S  27

/* SYSTEM_PWM3_RST : R/W [26] : 1'b0 ; */

#define SYSTEM_PWM3_RST    (BIT(26))
#define SYSTEM_PWM3_RST_M  (BIT(26))
#define SYSTEM_PWM3_RST_V  0x1
#define SYSTEM_PWM3_RST_S  26

/* SYSTEM_PWM2_RST : R/W [25] : 1'b0 ; */

#define SYSTEM_PWM2_RST    (BIT(25))
#define SYSTEM_PWM2_RST_M  (BIT(25))
#define SYSTEM_PWM2_RST_V  0x1
#define SYSTEM_PWM2_RST_S  25

/* SYSTEM_UART_MEM_RST : R/W [24] : 1'b0 ; */

#define SYSTEM_UART_MEM_RST    (BIT(24))
#define SYSTEM_UART_MEM_RST_M  (BIT(24))
#define SYSTEM_UART_MEM_RST_V  0x1
#define SYSTEM_UART_MEM_RST_S  24

/* SYSTEM_USB_DEVICE_RST : R/W [23] : 1'b0 ; */

#define SYSTEM_USB_DEVICE_RST    (BIT(23))
#define SYSTEM_USB_DEVICE_RST_M  (BIT(23))
#define SYSTEM_USB_DEVICE_RST_V  0x1
#define SYSTEM_USB_DEVICE_RST_S  23

/* SYSTEM_SPI2_DMA_RST : R/W [22] : 1'b0 ; */

#define SYSTEM_SPI2_DMA_RST    (BIT(22))
#define SYSTEM_SPI2_DMA_RST_M  (BIT(22))
#define SYSTEM_SPI2_DMA_RST_V  0x1
#define SYSTEM_SPI2_DMA_RST_S  22

/* SYSTEM_I2S1_RST : R/W [21] : 1'b0 ; */

#define SYSTEM_I2S1_RST    (BIT(21))
#define SYSTEM_I2S1_RST_M  (BIT(21))
#define SYSTEM_I2S1_RST_V  0x1
#define SYSTEM_I2S1_RST_S  21

/* SYSTEM_PWM1_RST : R/W [20] : 1'b0 ; */

#define SYSTEM_PWM1_RST    (BIT(20))
#define SYSTEM_PWM1_RST_M  (BIT(20))
#define SYSTEM_PWM1_RST_V  0x1
#define SYSTEM_PWM1_RST_S  20

/* SYSTEM_TWAI_RST : R/W [19] : 1'b0 ; */

#define SYSTEM_TWAI_RST    (BIT(19))
#define SYSTEM_TWAI_RST_M  (BIT(19))
#define SYSTEM_TWAI_RST_V  0x1
#define SYSTEM_TWAI_RST_S  19

/* SYSTEM_I2C_EXT1_RST : R/W [18] : 1'b0 ; */

#define SYSTEM_I2C_EXT1_RST    (BIT(18))
#define SYSTEM_I2C_EXT1_RST_M  (BIT(18))
#define SYSTEM_I2C_EXT1_RST_V  0x1
#define SYSTEM_I2C_EXT1_RST_S  18

/* SYSTEM_PWM0_RST : R/W [17] : 1'b0 ; */

#define SYSTEM_PWM0_RST    (BIT(17))
#define SYSTEM_PWM0_RST_M  (BIT(17))
#define SYSTEM_PWM0_RST_V  0x1
#define SYSTEM_PWM0_RST_S  17

/* SYSTEM_SPI3_RST : R/W [16] : 1'b0 ; */

#define SYSTEM_SPI3_RST    (BIT(16))
#define SYSTEM_SPI3_RST_M  (BIT(16))
#define SYSTEM_SPI3_RST_V  0x1
#define SYSTEM_SPI3_RST_S  16

/* SYSTEM_TIMERGROUP1_RST : R/W [15] : 1'b0 ; */

#define SYSTEM_TIMERGROUP1_RST    (BIT(15))
#define SYSTEM_TIMERGROUP1_RST_M  (BIT(15))
#define SYSTEM_TIMERGROUP1_RST_V  0x1
#define SYSTEM_TIMERGROUP1_RST_S  15

/* SYSTEM_EFUSE_RST : R/W [14] : 1'b0 ; */

#define SYSTEM_EFUSE_RST    (BIT(14))
#define SYSTEM_EFUSE_RST_M  (BIT(14))
#define SYSTEM_EFUSE_RST_V  0x1
#define SYSTEM_EFUSE_RST_S  14

/* SYSTEM_TIMERGROUP_RST : R/W [13] : 1'b0 ; */

#define SYSTEM_TIMERGROUP_RST    (BIT(13))
#define SYSTEM_TIMERGROUP_RST_M  (BIT(13))
#define SYSTEM_TIMERGROUP_RST_V  0x1
#define SYSTEM_TIMERGROUP_RST_S  13

/* SYSTEM_UHCI1_RST : R/W [12] : 1'b0 ; */

#define SYSTEM_UHCI1_RST    (BIT(12))
#define SYSTEM_UHCI1_RST_M  (BIT(12))
#define SYSTEM_UHCI1_RST_V  0x1
#define SYSTEM_UHCI1_RST_S  12

/* SYSTEM_LEDC_RST : R/W [11] : 1'b0 ; */

#define SYSTEM_LEDC_RST    (BIT(11))
#define SYSTEM_LEDC_RST_M  (BIT(11))
#define SYSTEM_LEDC_RST_V  0x1
#define SYSTEM_LEDC_RST_S  11

/* SYSTEM_PCNT_RST : R/W [10] : 1'b0 ; */

#define SYSTEM_PCNT_RST    (BIT(10))
#define SYSTEM_PCNT_RST_M  (BIT(10))
#define SYSTEM_PCNT_RST_V  0x1
#define SYSTEM_PCNT_RST_S  10

/* SYSTEM_RMT_RST : R/W [9] : 1'b0 ; */

#define SYSTEM_RMT_RST    (BIT(9))
#define SYSTEM_RMT_RST_M  (BIT(9))
#define SYSTEM_RMT_RST_V  0x1
#define SYSTEM_RMT_RST_S  9

/* SYSTEM_UHCI0_RST : R/W [8] : 1'b0 ; */

#define SYSTEM_UHCI0_RST    (BIT(8))
#define SYSTEM_UHCI0_RST_M  (BIT(8))
#define SYSTEM_UHCI0_RST_V  0x1
#define SYSTEM_UHCI0_RST_S  8

/* SYSTEM_I2C_EXT0_RST : R/W [7] : 1'b0 ; */

#define SYSTEM_I2C_EXT0_RST    (BIT(7))
#define SYSTEM_I2C_EXT0_RST_M  (BIT(7))
#define SYSTEM_I2C_EXT0_RST_V  0x1
#define SYSTEM_I2C_EXT0_RST_S  7

/* SYSTEM_SPI2_RST : R/W [6] : 1'b0 ; */

#define SYSTEM_SPI2_RST    (BIT(6))
#define SYSTEM_SPI2_RST_M  (BIT(6))
#define SYSTEM_SPI2_RST_V  0x1
#define SYSTEM_SPI2_RST_S  6

/* SYSTEM_UART1_RST : R/W [5] : 1'b0 ; */

#define SYSTEM_UART1_RST    (BIT(5))
#define SYSTEM_UART1_RST_M  (BIT(5))
#define SYSTEM_UART1_RST_V  0x1
#define SYSTEM_UART1_RST_S  5

/* SYSTEM_I2S0_RST : R/W [4] : 1'b0 ; */

#define SYSTEM_I2S0_RST    (BIT(4))
#define SYSTEM_I2S0_RST_M  (BIT(4))
#define SYSTEM_I2S0_RST_V  0x1
#define SYSTEM_I2S0_RST_S  4

/* SYSTEM_WDG_RST : R/W [3] : 1'b0 ; */

#define SYSTEM_WDG_RST    (BIT(3))
#define SYSTEM_WDG_RST_M  (BIT(3))
#define SYSTEM_WDG_RST_V  0x1
#define SYSTEM_WDG_RST_S  3

/* SYSTEM_UART_RST : R/W [2] : 1'b0 ; */

#define SYSTEM_UART_RST    (BIT(2))
#define SYSTEM_UART_RST_M  (BIT(2))
#define SYSTEM_UART_RST_V  0x1
#define SYSTEM_UART_RST_S  2

/* SYSTEM_SPI01_RST : R/W [1] : 1'b0 ; */

#define SYSTEM_SPI01_RST    (BIT(1))
#define SYSTEM_SPI01_RST_M  (BIT(1))
#define SYSTEM_SPI01_RST_V  0x1
#define SYSTEM_SPI01_RST_S  1

/* SYSTEM_TIMERS_RST : R/W [0] : 1'b0 ; */

#define SYSTEM_TIMERS_RST    (BIT(0))
#define SYSTEM_TIMERS_RST_M  (BIT(0))
#define SYSTEM_TIMERS_RST_V  0x1
#define SYSTEM_TIMERS_RST_S  0

#define SYSTEM_PERIP_RST_EN1_REG          (DR_REG_SYSTEM_BASE + 0x01c)

/* SYSTEM_TSENS_RST : R/W [10] : 1'b0 ; */

#define SYSTEM_TSENS_RST    (BIT(10))
#define SYSTEM_TSENS_RST_M  (BIT(10))
#define SYSTEM_TSENS_RST_V  0x1
#define SYSTEM_TSENS_RST_S  10

/* SYSTEM_UART2_RST : R/W [9] : 1'b0 ; */

#define SYSTEM_UART2_RST    (BIT(9))
#define SYSTEM_UART2_RST_M  (BIT(9))
#define SYSTEM_UART2_RST_V  0x1
#define SYSTEM_UART2_RST_S  9

/* SYSTEM_LCD_CAM_RST : R/W [8] : 1'b1 ; */

#define SYSTEM_LCD_CAM_RST    (BIT(8))
#define SYSTEM_LCD_CAM_RST_M  (BIT(8))
#define SYSTEM_LCD_CAM_RST_V  0x1
#define SYSTEM_LCD_CAM_RST_S  8

/* SYSTEM_SDIO_HOST_RST : R/W [7] : 1'b1 ; */

#define SYSTEM_SDIO_HOST_RST    (BIT(7))
#define SYSTEM_SDIO_HOST_RST_M  (BIT(7))
#define SYSTEM_SDIO_HOST_RST_V  0x1
#define SYSTEM_SDIO_HOST_RST_S  7

/* SYSTEM_DMA_RST : R/W [6] : 1'b1 ; */

#define SYSTEM_DMA_RST    (BIT(6))
#define SYSTEM_DMA_RST_M  (BIT(6))
#define SYSTEM_DMA_RST_V  0x1
#define SYSTEM_DMA_RST_S  6

/* SYSTEM_CRYPTO_HMAC_RST : R/W [5] : 1'b1 ; */

#define SYSTEM_CRYPTO_HMAC_RST    (BIT(5))
#define SYSTEM_CRYPTO_HMAC_RST_M  (BIT(5))
#define SYSTEM_CRYPTO_HMAC_RST_V  0x1
#define SYSTEM_CRYPTO_HMAC_RST_S  5

/* SYSTEM_CRYPTO_DS_RST : R/W [4] : 1'b1 ; */

#define SYSTEM_CRYPTO_DS_RST    (BIT(4))
#define SYSTEM_CRYPTO_DS_RST_M  (BIT(4))
#define SYSTEM_CRYPTO_DS_RST_V  0x1
#define SYSTEM_CRYPTO_DS_RST_S  4

/* SYSTEM_CRYPTO_RSA_RST : R/W [3] : 1'b1 ; */

#define SYSTEM_CRYPTO_RSA_RST    (BIT(3))
#define SYSTEM_CRYPTO_RSA_RST_M  (BIT(3))
#define SYSTEM_CRYPTO_RSA_RST_V  0x1
#define SYSTEM_CRYPTO_RSA_RST_S  3

/* SYSTEM_CRYPTO_SHA_RST : R/W [2] : 1'b1 ; */

#define SYSTEM_CRYPTO_SHA_RST    (BIT(2))
#define SYSTEM_CRYPTO_SHA_RST_M  (BIT(2))
#define SYSTEM_CRYPTO_SHA_RST_V  0x1
#define SYSTEM_CRYPTO_SHA_RST_S  2

/* SYSTEM_CRYPTO_AES_RST : R/W [1] : 1'b1 ; */

#define SYSTEM_CRYPTO_AES_RST    (BIT(1))
#define SYSTEM_CRYPTO_AES_RST_M  (BIT(1))
#define SYSTEM_CRYPTO_AES_RST_V  0x1
#define SYSTEM_CRYPTO_AES_RST_S  1

#define SYSTEM_BT_LPCK_DIV_INT_REG          (DR_REG_SYSTEM_BASE + 0x020)

/* SYSTEM_BT_LPCK_DIV_NUM : R/W [11:0] : 12'd255 ; */

#define SYSTEM_BT_LPCK_DIV_NUM    0x00000fff
#define SYSTEM_BT_LPCK_DIV_NUM_M  (SYSTEM_BT_LPCK_DIV_NUM_V << SYSTEM_BT_LPCK_DIV_NUM_S)
#define SYSTEM_BT_LPCK_DIV_NUM_V  0xfff
#define SYSTEM_BT_LPCK_DIV_NUM_S  0

#define SYSTEM_BT_LPCK_DIV_FRAC_REG          (DR_REG_SYSTEM_BASE + 0x024)

/* SYSTEM_LPCLK_RTC_EN : R/W [28] : 1'b0 ; */

#define SYSTEM_LPCLK_RTC_EN    (BIT(28))
#define SYSTEM_LPCLK_RTC_EN_M  (BIT(28))
#define SYSTEM_LPCLK_RTC_EN_V  0x1
#define SYSTEM_LPCLK_RTC_EN_S  28

/* SYSTEM_LPCLK_SEL_XTAL32K : R/W [27] : 1'b0 ; */

#define SYSTEM_LPCLK_SEL_XTAL32K    (BIT(27))
#define SYSTEM_LPCLK_SEL_XTAL32K_M  (BIT(27))
#define SYSTEM_LPCLK_SEL_XTAL32K_V  0x1
#define SYSTEM_LPCLK_SEL_XTAL32K_S  27

/* SYSTEM_LPCLK_SEL_XTAL : R/W [26] : 1'b0 ; */

#define SYSTEM_LPCLK_SEL_XTAL    (BIT(26))
#define SYSTEM_LPCLK_SEL_XTAL_M  (BIT(26))
#define SYSTEM_LPCLK_SEL_XTAL_V  0x1
#define SYSTEM_LPCLK_SEL_XTAL_S  26

/* SYSTEM_LPCLK_SEL_8M : R/W [25] : 1'b1 ; */

#define SYSTEM_LPCLK_SEL_8M    (BIT(25))
#define SYSTEM_LPCLK_SEL_8M_M  (BIT(25))
#define SYSTEM_LPCLK_SEL_8M_V  0x1
#define SYSTEM_LPCLK_SEL_8M_S  25

/* SYSTEM_LPCLK_SEL_RTC_SLOW : R/W [24] : 1'b0 ; */

#define SYSTEM_LPCLK_SEL_RTC_SLOW    (BIT(24))
#define SYSTEM_LPCLK_SEL_RTC_SLOW_M  (BIT(24))
#define SYSTEM_LPCLK_SEL_RTC_SLOW_V  0x1
#define SYSTEM_LPCLK_SEL_RTC_SLOW_S  24

/* SYSTEM_BT_LPCK_DIV_A : R/W [23:12] : 12'd1 ; */

#define SYSTEM_BT_LPCK_DIV_A    0x00000fff
#define SYSTEM_BT_LPCK_DIV_A_M  (SYSTEM_BT_LPCK_DIV_A_V << SYSTEM_BT_LPCK_DIV_A_S)
#define SYSTEM_BT_LPCK_DIV_A_V  0xfff
#define SYSTEM_BT_LPCK_DIV_A_S  12

/* SYSTEM_BT_LPCK_DIV_B : R/W [11:0] : 12'd1 ; */

#define SYSTEM_BT_LPCK_DIV_B    0x00000fff
#define SYSTEM_BT_LPCK_DIV_B_M  (SYSTEM_BT_LPCK_DIV_B_V << SYSTEM_BT_LPCK_DIV_B_S)
#define SYSTEM_BT_LPCK_DIV_B_V  0xfff
#define SYSTEM_BT_LPCK_DIV_B_S  0

#define SYSTEM_CPU_INTR_FROM_CPU_0_REG          (DR_REG_SYSTEM_BASE + 0x028)

/* SYSTEM_CPU_INTR_FROM_CPU_0 : R/W [0] : 1'b0 ; */

#define SYSTEM_CPU_INTR_FROM_CPU_0    (BIT(0))
#define SYSTEM_CPU_INTR_FROM_CPU_0_M  (BIT(0))
#define SYSTEM_CPU_INTR_FROM_CPU_0_V  0x1
#define SYSTEM_CPU_INTR_FROM_CPU_0_S  0

#define SYSTEM_CPU_INTR_FROM_CPU_1_REG          (DR_REG_SYSTEM_BASE + 0x02c)

/* SYSTEM_CPU_INTR_FROM_CPU_1 : R/W [0] : 1'b0 ; */

#define SYSTEM_CPU_INTR_FROM_CPU_1    (BIT(0))
#define SYSTEM_CPU_INTR_FROM_CPU_1_M  (BIT(0))
#define SYSTEM_CPU_INTR_FROM_CPU_1_V  0x1
#define SYSTEM_CPU_INTR_FROM_CPU_1_S  0

#define SYSTEM_CPU_INTR_FROM_CPU_2_REG          (DR_REG_SYSTEM_BASE + 0x030)

/* SYSTEM_CPU_INTR_FROM_CPU_2 : R/W [0] : 1'b0 ; */

#define SYSTEM_CPU_INTR_FROM_CPU_2    (BIT(0))
#define SYSTEM_CPU_INTR_FROM_CPU_2_M  (BIT(0))
#define SYSTEM_CPU_INTR_FROM_CPU_2_V  0x1
#define SYSTEM_CPU_INTR_FROM_CPU_2_S  0

#define SYSTEM_CPU_INTR_FROM_CPU_3_REG          (DR_REG_SYSTEM_BASE + 0x034)

/* SYSTEM_CPU_INTR_FROM_CPU_3 : R/W [0] : 1'b0 ; */

#define SYSTEM_CPU_INTR_FROM_CPU_3    (BIT(0))
#define SYSTEM_CPU_INTR_FROM_CPU_3_M  (BIT(0))
#define SYSTEM_CPU_INTR_FROM_CPU_3_V  0x1
#define SYSTEM_CPU_INTR_FROM_CPU_3_S  0

#define SYSTEM_RSA_PD_CTRL_REG          (DR_REG_SYSTEM_BASE + 0x038)

/* SYSTEM_RSA_MEM_FORCE_PD : R/W [2] : 1'b0 ; */

#define SYSTEM_RSA_MEM_FORCE_PD    (BIT(2))
#define SYSTEM_RSA_MEM_FORCE_PD_M  (BIT(2))
#define SYSTEM_RSA_MEM_FORCE_PD_V  0x1
#define SYSTEM_RSA_MEM_FORCE_PD_S  2

/* SYSTEM_RSA_MEM_FORCE_PU : R/W [1] : 1'b0 ; */

#define SYSTEM_RSA_MEM_FORCE_PU    (BIT(1))
#define SYSTEM_RSA_MEM_FORCE_PU_M  (BIT(1))
#define SYSTEM_RSA_MEM_FORCE_PU_V  0x1
#define SYSTEM_RSA_MEM_FORCE_PU_S  1

/* SYSTEM_RSA_MEM_PD : R/W [0] : 1'b1 ; */

#define SYSTEM_RSA_MEM_PD    (BIT(0))
#define SYSTEM_RSA_MEM_PD_M  (BIT(0))
#define SYSTEM_RSA_MEM_PD_V  0x1
#define SYSTEM_RSA_MEM_PD_S  0

#define SYSTEM_EDMA_CTRL_REG          (DR_REG_SYSTEM_BASE + 0x03c)

/* SYSTEM_EDMA_RESET : R/W [1] : 1'b0 ; */

#define SYSTEM_EDMA_RESET    (BIT(1))
#define SYSTEM_EDMA_RESET_M  (BIT(1))
#define SYSTEM_EDMA_RESET_V  0x1
#define SYSTEM_EDMA_RESET_S  1

/* SYSTEM_EDMA_CLK_ON : R/W [0] : 1'b1 ; */

#define SYSTEM_EDMA_CLK_ON    (BIT(0))
#define SYSTEM_EDMA_CLK_ON_M  (BIT(0))
#define SYSTEM_EDMA_CLK_ON_V  0x1
#define SYSTEM_EDMA_CLK_ON_S  0

#define SYSTEM_CACHE_CONTROL_REG          (DR_REG_SYSTEM_BASE + 0x040)

/* SYSTEM_DCACHE_RESET : R/W [3] : 1'b0 ; */

#define SYSTEM_DCACHE_RESET    (BIT(3))
#define SYSTEM_DCACHE_RESET_M  (BIT(3))
#define SYSTEM_DCACHE_RESET_V  0x1
#define SYSTEM_DCACHE_RESET_S  3

/* SYSTEM_DCACHE_CLK_ON : R/W [2] : 1'b1 ; */

#define SYSTEM_DCACHE_CLK_ON    (BIT(2))
#define SYSTEM_DCACHE_CLK_ON_M  (BIT(2))
#define SYSTEM_DCACHE_CLK_ON_V  0x1
#define SYSTEM_DCACHE_CLK_ON_S  2

/* SYSTEM_ICACHE_RESET : R/W [1] : 1'b0 ; */

#define SYSTEM_ICACHE_RESET    (BIT(1))
#define SYSTEM_ICACHE_RESET_M  (BIT(1))
#define SYSTEM_ICACHE_RESET_V  0x1
#define SYSTEM_ICACHE_RESET_S  1

/* SYSTEM_ICACHE_CLK_ON : R/W [0] : 1'b1 ; */

#define SYSTEM_ICACHE_CLK_ON    (BIT(0))
#define SYSTEM_ICACHE_CLK_ON_M  (BIT(0))
#define SYSTEM_ICACHE_CLK_ON_V  0x1
#define SYSTEM_ICACHE_CLK_ON_S  0

#define SYSTEM_EXTERNAL_DEVICE_ENCRYPT_DECRYPT_CONTROL_REG          (DR_REG_SYSTEM_BASE + 0x044)

/* SYSTEM_ENABLE_DOWNLOAD_MANUAL_ENCRYPT : R/W [3] : 1'b0 ; */

#define SYSTEM_ENABLE_DOWNLOAD_MANUAL_ENCRYPT    (BIT(3))
#define SYSTEM_ENABLE_DOWNLOAD_MANUAL_ENCRYPT_M  (BIT(3))
#define SYSTEM_ENABLE_DOWNLOAD_MANUAL_ENCRYPT_V  0x1
#define SYSTEM_ENABLE_DOWNLOAD_MANUAL_ENCRYPT_S  3

/* SYSTEM_ENABLE_DOWNLOAD_G0CB_DECRYPT : R/W [2] : 1'b0 ; */

#define SYSTEM_ENABLE_DOWNLOAD_G0CB_DECRYPT    (BIT(2))
#define SYSTEM_ENABLE_DOWNLOAD_G0CB_DECRYPT_M  (BIT(2))
#define SYSTEM_ENABLE_DOWNLOAD_G0CB_DECRYPT_V  0x1
#define SYSTEM_ENABLE_DOWNLOAD_G0CB_DECRYPT_S  2

/* SYSTEM_ENABLE_DOWNLOAD_DB_ENCRYPT : R/W [1] : 1'b0 ; */

#define SYSTEM_ENABLE_DOWNLOAD_DB_ENCRYPT    (BIT(1))
#define SYSTEM_ENABLE_DOWNLOAD_DB_ENCRYPT_M  (BIT(1))
#define SYSTEM_ENABLE_DOWNLOAD_DB_ENCRYPT_V  0x1
#define SYSTEM_ENABLE_DOWNLOAD_DB_ENCRYPT_S  1

/* SYSTEM_ENABLE_SPI_MANUAL_ENCRYPT : R/W [0] : 1'b0 ; */

#define SYSTEM_ENABLE_SPI_MANUAL_ENCRYPT    (BIT(0))
#define SYSTEM_ENABLE_SPI_MANUAL_ENCRYPT_M  (BIT(0))
#define SYSTEM_ENABLE_SPI_MANUAL_ENCRYPT_V  0x1
#define SYSTEM_ENABLE_SPI_MANUAL_ENCRYPT_S  0

#define SYSTEM_RTC_FASTMEM_CONFIG_REG          (DR_REG_SYSTEM_BASE + 0x048)

/* SYSTEM_RTC_MEM_CRC_FINISH : RO [31] : 1'b0 ; */

#define SYSTEM_RTC_MEM_CRC_FINISH    (BIT(31))
#define SYSTEM_RTC_MEM_CRC_FINISH_M  (BIT(31))
#define SYSTEM_RTC_MEM_CRC_FINISH_V  0x1
#define SYSTEM_RTC_MEM_CRC_FINISH_S  31

/* SYSTEM_RTC_MEM_CRC_LEN : R/W [30:20] : 11'h7ff ; */

#define SYSTEM_RTC_MEM_CRC_LEN    0x000007ff
#define SYSTEM_RTC_MEM_CRC_LEN_M  (SYSTEM_RTC_MEM_CRC_LEN_V << SYSTEM_RTC_MEM_CRC_LEN_S)
#define SYSTEM_RTC_MEM_CRC_LEN_V  0x7ff
#define SYSTEM_RTC_MEM_CRC_LEN_S  20

/* SYSTEM_RTC_MEM_CRC_ADDR : R/W [19:9] : 11'h0 ; */

#define SYSTEM_RTC_MEM_CRC_ADDR    0x000007ff
#define SYSTEM_RTC_MEM_CRC_ADDR_M  (SYSTEM_RTC_MEM_CRC_ADDR_V << SYSTEM_RTC_MEM_CRC_ADDR_S)
#define SYSTEM_RTC_MEM_CRC_ADDR_V  0x7ff
#define SYSTEM_RTC_MEM_CRC_ADDR_S  9

/* SYSTEM_RTC_MEM_CRC_START : R/W [8] : 1'b0 ; */

#define SYSTEM_RTC_MEM_CRC_START    (BIT(8))
#define SYSTEM_RTC_MEM_CRC_START_M  (BIT(8))
#define SYSTEM_RTC_MEM_CRC_START_V  0x1
#define SYSTEM_RTC_MEM_CRC_START_S  8

#define SYSTEM_RTC_FASTMEM_CRC_REG          (DR_REG_SYSTEM_BASE + 0x04c)

/* SYSTEM_RTC_MEM_CRC_RES : RO [31:0] : 32'b0 ; */

#define SYSTEM_RTC_MEM_CRC_RES    0xffffffff
#define SYSTEM_RTC_MEM_CRC_RES_M  (SYSTEM_RTC_MEM_CRC_RES_V << SYSTEM_RTC_MEM_CRC_RES_S)
#define SYSTEM_RTC_MEM_CRC_RES_V  0xffffffff
#define SYSTEM_RTC_MEM_CRC_RES_S  0

#define SYSTEM_REDUNDANT_ECO_CTRL_REG          (DR_REG_SYSTEM_BASE + 0x050)

/* SYSTEM_REDUNDANT_ECO_RESULT : RO [1] : 1'b0 ; */

#define SYSTEM_REDUNDANT_ECO_RESULT  (BIT(1))
#define SYSTEM_REDUNDANT_ECO_RESULT_M  (BIT(1))
#define SYSTEM_REDUNDANT_ECO_RESULT_V  0x1
#define SYSTEM_REDUNDANT_ECO_RESULT_S  1

/* SYSTEM_REDUNDANT_ECO_DRIVE : R/W [0] : 1'b0 ; */

#define SYSTEM_REDUNDANT_ECO_DRIVE    (BIT(0))
#define SYSTEM_REDUNDANT_ECO_DRIVE_M  (BIT(0))
#define SYSTEM_REDUNDANT_ECO_DRIVE_V  0x1
#define SYSTEM_REDUNDANT_ECO_DRIVE_S  0

#define SYSTEM_CLOCK_GATE_REG          (DR_REG_SYSTEM_BASE + 0x054)

/* SYSTEM_CLK_EN : R/W [0] : 1'b1 ; */

#define SYSTEM_CLK_EN    (BIT(0))
#define SYSTEM_CLK_EN_M  (BIT(0))
#define SYSTEM_CLK_EN_V  0x1
#define SYSTEM_CLK_EN_S  0

#define SYSTEM_SYSCLK_CONF_REG          (DR_REG_SYSTEM_BASE + 0x058)

/* SYSTEM_CLK_DIV_EN : RO [19] : 1'd0 ; */

#define SYSTEM_CLK_DIV_EN    (BIT(19))
#define SYSTEM_CLK_DIV_EN_M  (BIT(19))
#define SYSTEM_CLK_DIV_EN_V  0x1
#define SYSTEM_CLK_DIV_EN_S  19

/* SYSTEM_CLK_XTAL_FREQ : RO [18:12] : 7'd0 ; */

#define SYSTEM_CLK_XTAL_FREQ    0x0000007f
#define SYSTEM_CLK_XTAL_FREQ_M  (SYSTEM_CLK_XTAL_FREQ_V << SYSTEM_CLK_XTAL_FREQ_S)
#define SYSTEM_CLK_XTAL_FREQ_V  0x7f
#define SYSTEM_CLK_XTAL_FREQ_S  12

/* SYSTEM_SOC_CLK_SEL : R/W [11:10] : 2'd0 ; */

#define SYSTEM_SOC_CLK_SEL    0x00000003
#define SYSTEM_SOC_CLK_SEL_M  (SYSTEM_SOC_CLK_SEL_V << SYSTEM_SOC_CLK_SEL_S)
#define SYSTEM_SOC_CLK_SEL_V  0x3
#define SYSTEM_SOC_CLK_SEL_S  10

/* SYSTEM_PRE_DIV_CNT : R/W [9:0] : 10'h1 ; */

#define SYSTEM_PRE_DIV_CNT    0x000003ff
#define SYSTEM_PRE_DIV_CNT_M  (SYSTEM_PRE_DIV_CNT_V << SYSTEM_PRE_DIV_CNT_S)
#define SYSTEM_PRE_DIV_CNT_V  0x3ff
#define SYSTEM_PRE_DIV_CNT_S  0

#define SYSTEM_MEM_PVT_REG          (DR_REG_SYSTEM_BASE + 0x05c)

/* SYSTEM_MEM_VT_SEL : R/W [23:22] : 2'd0 ; */

#define SYSTEM_MEM_VT_SEL    0x00000003
#define SYSTEM_MEM_VT_SEL_M  (SYSTEM_MEM_VT_SEL_V << SYSTEM_MEM_VT_SEL_S)
#define SYSTEM_MEM_VT_SEL_V  0x3
#define SYSTEM_MEM_VT_SEL_S  22

/* SYSTEM_MEM_TIMING_ERR_CNT : RO [21:6] : 16'h0 ; */

#define SYSTEM_MEM_TIMING_ERR_CNT    0x0000ffff
#define SYSTEM_MEM_TIMING_ERR_CNT_M  (SYSTEM_MEM_TIMING_ERR_CNT_V << SYSTEM_MEM_TIMING_ERR_CNT_S)
#define SYSTEM_MEM_TIMING_ERR_CNT_V  0xffff
#define SYSTEM_MEM_TIMING_ERR_CNT_S  6

/* SYSTEM_MEM_PVT_MONITOR_EN : R/W [5] : 1'b0 ; */

#define SYSTEM_MEM_PVT_MONITOR_EN    (BIT(5))
#define SYSTEM_MEM_PVT_MONITOR_EN_M  (BIT(5))
#define SYSTEM_MEM_PVT_MONITOR_EN_V  0x1
#define SYSTEM_MEM_PVT_MONITOR_EN_S  5

/* SYSTEM_MEM_ERR_CNT_CLR : WO [4] : 1'b0 ; */

#define SYSTEM_MEM_ERR_CNT_CLR    (BIT(4))
#define SYSTEM_MEM_ERR_CNT_CLR_M  (BIT(4))
#define SYSTEM_MEM_ERR_CNT_CLR_V  0x1
#define SYSTEM_MEM_ERR_CNT_CLR_S  4

/* SYSTEM_MEM_PATH_LEN : R/W [3:0] : 4'h3 ; */

#define SYSTEM_MEM_PATH_LEN    0x0000000f
#define SYSTEM_MEM_PATH_LEN_M  (SYSTEM_MEM_PATH_LEN_V << SYSTEM_MEM_PATH_LEN_S)
#define SYSTEM_MEM_PATH_LEN_V  0xf
#define SYSTEM_MEM_PATH_LEN_S  0

#define SYSTEM_COMB_PVT_LVT_CONF_REG          (DR_REG_SYSTEM_BASE + 0x060)

/* SYSTEM_COMB_PVT_MONITOR_EN_LVT : R/W [6] : 1'b0 ; */

#define SYSTEM_COMB_PVT_MONITOR_EN_LVT    (BIT(6))
#define SYSTEM_COMB_PVT_MONITOR_EN_LVT_M  (BIT(6))
#define SYSTEM_COMB_PVT_MONITOR_EN_LVT_V  0x1
#define SYSTEM_COMB_PVT_MONITOR_EN_LVT_S  6

/* SYSTEM_COMB_ERR_CNT_CLR_LVT : WO [5] : 1'b0 ; */

#define SYSTEM_COMB_ERR_CNT_CLR_LVT    (BIT(5))
#define SYSTEM_COMB_ERR_CNT_CLR_LVT_M  (BIT(5))
#define SYSTEM_COMB_ERR_CNT_CLR_LVT_V  0x1
#define SYSTEM_COMB_ERR_CNT_CLR_LVT_S  5

/* SYSTEM_COMB_PATH_LEN_LVT : R/W [4:0] : 5'h3 ; */

#define SYSTEM_COMB_PATH_LEN_LVT    0x0000001f
#define SYSTEM_COMB_PATH_LEN_LVT_M  (SYSTEM_COMB_PATH_LEN_LVT_V << SYSTEM_COMB_PATH_LEN_LVT_S)
#define SYSTEM_COMB_PATH_LEN_LVT_V  0x1f
#define SYSTEM_COMB_PATH_LEN_LVT_S  0

#define SYSTEM_COMB_PVT_NVT_CONF_REG          (DR_REG_SYSTEM_BASE + 0x064)

/* SYSTEM_COMB_PVT_MONITOR_EN_NVT : R/W [6] : 1'b0 ; */

#define SYSTEM_COMB_PVT_MONITOR_EN_NVT    (BIT(6))
#define SYSTEM_COMB_PVT_MONITOR_EN_NVT_M  (BIT(6))
#define SYSTEM_COMB_PVT_MONITOR_EN_NVT_V  0x1
#define SYSTEM_COMB_PVT_MONITOR_EN_NVT_S  6

/* SYSTEM_COMB_ERR_CNT_CLR_NVT : WO [5] : 1'b0 ; */

#define SYSTEM_COMB_ERR_CNT_CLR_NVT    (BIT(5))
#define SYSTEM_COMB_ERR_CNT_CLR_NVT_M  (BIT(5))
#define SYSTEM_COMB_ERR_CNT_CLR_NVT_V  0x1
#define SYSTEM_COMB_ERR_CNT_CLR_NVT_S  5

/* SYSTEM_COMB_PATH_LEN_NVT : R/W [4:0] : 5'h3 ; */

#define SYSTEM_COMB_PATH_LEN_NVT    0x0000001f
#define SYSTEM_COMB_PATH_LEN_NVT_M  (SYSTEM_COMB_PATH_LEN_NVT_V << SYSTEM_COMB_PATH_LEN_NVT_S)
#define SYSTEM_COMB_PATH_LEN_NVT_V  0x1f
#define SYSTEM_COMB_PATH_LEN_NVT_S  0

#define SYSTEM_COMB_PVT_HVT_CONF_REG          (DR_REG_SYSTEM_BASE + 0x068)

/* SYSTEM_COMB_PVT_MONITOR_EN_HVT : R/W [6] : 1'b0 ; */

#define SYSTEM_COMB_PVT_MONITOR_EN_HVT    (BIT(6))
#define SYSTEM_COMB_PVT_MONITOR_EN_HVT_M  (BIT(6))
#define SYSTEM_COMB_PVT_MONITOR_EN_HVT_V  0x1
#define SYSTEM_COMB_PVT_MONITOR_EN_HVT_S  6

/* SYSTEM_COMB_ERR_CNT_CLR_HVT : WO [5] : 1'b0 ; */

#define SYSTEM_COMB_ERR_CNT_CLR_HVT    (BIT(5))
#define SYSTEM_COMB_ERR_CNT_CLR_HVT_M  (BIT(5))
#define SYSTEM_COMB_ERR_CNT_CLR_HVT_V  0x1
#define SYSTEM_COMB_ERR_CNT_CLR_HVT_S  5

/* SYSTEM_COMB_PATH_LEN_HVT : R/W [4:0] : 5'h3 ; */

#define SYSTEM_COMB_PATH_LEN_HVT    0x0000001f
#define SYSTEM_COMB_PATH_LEN_HVT_M  (SYSTEM_COMB_PATH_LEN_HVT_V << SYSTEM_COMB_PATH_LEN_HVT_S)
#define SYSTEM_COMB_PATH_LEN_HVT_V  0x1f
#define SYSTEM_COMB_PATH_LEN_HVT_S  0

#define SYSTEM_COMB_PVT_ERR_LVT_SITE0_REG          (DR_REG_SYSTEM_BASE + 0x06c)

/* SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE0 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE0    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE0_M  (SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE0_V << SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE0_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE0_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE0_S  0

#define SYSTEM_COMB_PVT_ERR_NVT_SITE0_REG          (DR_REG_SYSTEM_BASE + 0x070)

/* SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE0 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE0    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE0_M  (SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE0_V << SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE0_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE0_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE0_S  0

#define SYSTEM_COMB_PVT_ERR_HVT_SITE0_REG          (DR_REG_SYSTEM_BASE + 0x074)

/* SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE0 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE0    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE0_M  (SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE0_V << SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE0_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE0_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE0_S  0

#define SYSTEM_COMB_PVT_ERR_LVT_SITE1_REG          (DR_REG_SYSTEM_BASE + 0x078)

/* SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE1 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE1    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE1_M  (SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE1_V << SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE1_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE1_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE1_S  0

#define SYSTEM_COMB_PVT_ERR_NVT_SITE1_REG          (DR_REG_SYSTEM_BASE + 0x07c)

/* SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE1 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE1    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE1_M  (SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE1_V << SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE1_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE1_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE1_S  0

#define SYSTEM_COMB_PVT_ERR_HVT_SITE1_REG          (DR_REG_SYSTEM_BASE + 0x080)

/* SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE1 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE1    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE1_M  (SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE1_V << SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE1_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE1_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE1_S  0

#define SYSTEM_COMB_PVT_ERR_LVT_SITE2_REG          (DR_REG_SYSTEM_BASE + 0x084)

/* SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE2 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE2    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE2_M  (SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE2_V << SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE2_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE2_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE2_S  0

#define SYSTEM_COMB_PVT_ERR_NVT_SITE2_REG          (DR_REG_SYSTEM_BASE + 0x088)

/* SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE2 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE2    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE2_M  (SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE2_V << SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE2_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE2_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE2_S  0

#define SYSTEM_COMB_PVT_ERR_HVT_SITE2_REG          (DR_REG_SYSTEM_BASE + 0x08c)

/* SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE2 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE2    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE2_M  (SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE2_V << SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE2_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE2_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE2_S  0

#define SYSTEM_COMB_PVT_ERR_LVT_SITE3_REG          (DR_REG_SYSTEM_BASE + 0x090)

/* SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE3 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE3    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE3_M  (SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE3_V << SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE3_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE3_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_LVT_SITE3_S  0

#define SYSTEM_COMB_PVT_ERR_NVT_SITE3_REG          (DR_REG_SYSTEM_BASE + 0x094)

/* SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE3 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE3    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE3_M  (SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE3_V << SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE3_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE3_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_NVT_SITE3_S  0

#define SYSTEM_COMB_PVT_ERR_HVT_SITE3_REG          (DR_REG_SYSTEM_BASE + 0x098)

/* SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE3 : RO [15:0] : 16'h0 ; */

#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE3    0x0000ffff
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE3_M  (SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE3_V << SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE3_S)
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE3_V  0xffff
#define SYSTEM_COMB_TIMING_ERR_CNT_HVT_SITE3_S  0

#define SYSTEM_DATE_REG          (DR_REG_SYSTEM_BASE + 0xffc)

/* SYSTEM_DATE : R/W [27:0] : 28'h2007150 ; */

#define SYSTEM_DATE    0x0fffffff
#define SYSTEM_DATE_M  (SYSTEM_DATE_V << SYSTEM_DATE_S)
#define SYSTEM_DATE_V  0xfffffff
#define SYSTEM_DATE_S  0

#endif /* __ARCH_RISCV_SRC_ESP32C3_HARDWARE_ESP32C3_SYSTEM_H */
