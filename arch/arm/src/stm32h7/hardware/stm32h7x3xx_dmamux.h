/************************************************************************************
 * arch/arm/src/stm32h7/hardware/stm32h7x3xx_dmamux.h
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
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_STM32H7_HARDWARE_STM32H7X3XX_DMAMUX_H
#define __ARCH_ARM_SRC_STM32H7_HARDWARE_STM32H7X3XX_DMAMUX_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* DMAMUX1 mapping ******************************************************************/

/* NOTE: DMAMUX1 channels 0 to 7 are connected to DMA1 channels 0 to 7.
 *       DMAMUX1 channels 8 to 15 are connected to DMA2 channels 0 to 7.
 */

#define DMAMUX1_REQ_GEN0       (1)
#define DMAMUX1_REQ_GEN1       (2)
#define DMAMUX1_REQ_GEN2       (3)
#define DMAMUX1_REQ_GEN3       (4)
#define DMAMUX1_REQ_GEN4       (5)
#define DMAMUX1_REQ_GEN5       (6)
#define DMAMUX1_REQ_GEN6       (7)
#define DMAMUX1_REQ_GEN7       (8)
#define DMAMUX1_ADC1           (9)
#define DMAMUX1_ADC2           (10)
#define DMAMUX1_TIM1_CH1       (11)
#define DMAMUX1_TIM1_CH2       (12)
#define DMAMUX1_TIM1_CH3       (13)
#define DMAMUX1_TIM1_CH4       (14)
#define DMAMUX1_TIM1_UP        (15)
#define DMAMUX1_TIM1_TRIG      (16)
#define DMAMUX1_TIM1_COM       (17)
#define DMAMUX1_TIM2_CH1       (18)
#define DMAMUX1_TIM2_CH2       (19)
#define DMAMUX1_TIM2_CH3       (20)
#define DMAMUX1_TIM2_CH4       (21)
#define DMAMUX1_TIM2_UP        (22)
#define DMAMUX1_TIM3_CH1       (23)
#define DMAMUX1_TIM3_CH2       (24)
#define DMAMUX1_TIM3_CH3       (25)
#define DMAMUX1_TIM3_CH4       (26)
#define DMAMUX1_TIM3_UP        (27)
#define DMAMUX1_TIM3_TRIG      (28)
#define DMAMUX1_TIM4_CH1       (29)
#define DMAMUX1_TIM4_CH2       (30)
#define DMAMUX1_TIM4_CH3       (31)
#define DMAMUX1_TIM4_UP        (32)
#define DMAMUX1_I2C1_RX        (33)
#define DMAMUX1_I2C1_TX        (34)
#define DMAMUX1_I2C2_RX        (35)
#define DMAMUX1_I2C2_TX        (36)
#define DMAMUX1_SPI1_RX        (37)
#define DMAMUX1_SPI1_TX        (38)
#define DMAMUX1_SPI2_RX        (39)
#define DMAMUX1_SPI2_TX        (40)
#define DMAMUX1_USART1_RX      (41)
#define DMAMUX1_USART1_TX      (42)
#define DMAMUX1_USART2_RX      (43)
#define DMAMUX1_USART2_TX      (44)
#define DMAMUX1_USART3_RX      (45)
#define DMAMUX1_USART3_TX      (46)
#define DMAMUX1_TIM8_CH1       (47)
#define DMAMUX1_TIM8_CH2       (48)
#define DMAMUX1_TIM8_CH3       (49)
#define DMAMUX1_TIM8_CH4       (50)
#define DMAMUX1_TIM8_UP        (51)
#define DMAMUX1_TIM8_TRIG      (52)
#define DMAMUX1_TIM8_COM       (53)
/* DMAMUX1 54: Reserved */
#define DMAMUX1_TIM5_CH1       (55)
#define DMAMUX1_TIM5_CH2       (56)
#define DMAMUX1_TIM5_CH3       (57)
#define DMAMUX1_TIM5_CH4       (58)
#define DMAMUX1_TIM5_UP        (59)
#define DMAMUX1_TIM5_TRIG      (60)
#define DMAMUX1_SPI3_RX        (61)
#define DMAMUX1_SPI3_TX        (62)
#define DMAMUX1_UART4_RX       (63)
#define DMAMUX1_UART4_TX       (64)
#define DMAMUX1_UART5_RX       (65)
#define DMAMUX1_UART5_TX       (66)
#define DMAMUX1_DAC1_CH1       (67)
#define DMAMUX1_DAC1_CH2       (68)
#define DMAMUX1_TIM6_UP        (69)
#define DMAMUX1_TIM7_UP        (70)
#define DMAMUX1_USART6_RX      (71)
#define DMAMUX1_USART6_TX      (72)
#define DMAMUX1_I2C3_RX        (73)
#define DMAMUX1_I2C3_TX        (74)
#define DMAMUX1_DCMI           (75)
#define DMAMUX1_CRYPT_IN       (76)
#define DMAMUX1_CRYPT_OUT      (77)
#define DMAMUX1_HASH_IN        (78)
#define DMAMUX1_UART7_RX       (79)
#define DMAMUX1_UART7_TX       (80)
#define DMAMUX1_UART8_RX       (81)
#define DMAMUX1_UART8_TX       (82)
#define DMAMUX1_SPI4_RX        (83)
#define DMAMUX1_SPI4_TX        (84)
#define DMAMUX1_SPI5_RX        (85)
#define DMAMUX1_SPI5_TX        (86)
#define DMAMUX1_SAI1A          (87)
#define DMAMUX1_SAI1B          (88)
#define DMAMUX1_SAI2A          (89)
#define DMAMUX1_SAI2B          (90)
#define DMAMUX1_SWPMI_RX       (91)
#define DMAMUX1_SWPMI_TX       (92)
#define DMAMUX1_SPDIFRX_DAT    (93)
#define DMAMUX1_SPDIFRX_CTRL   (94)
#define DMAMUX1_HR_REQ1        (95)
#define DMAMUX1_HR_REQ2        (96)
#define DMAMUX1_HR_REQ3        (97)
#define DMAMUX1_HR_REQ4        (98)
#define DMAMUX1_HR_REQ5        (99)
#define DMAMUX1_HR_REQ6        (100)
#define DMAMUX1_DFSDM1_0       (101)
#define DMAMUX1_DFSDM1_1       (102)
#define DMAMUX1_DFSDM1_2       (103)
#define DMAMUX1_DFSDM1_3       (104)
#define DMAMUX1_TIM15_CH1      (105)
#define DMAMUX1_TIM15_UP       (106)
#define DMAMUX1_TIM15_TRIG     (107)
#define DMAMUX1_TIM15_COM      (108)
#define DMAMUX1_TIM16_CH1      (109)
#define DMAMUX1_TIM16_UP       (110)
#define DMAMUX1_TIM17_CH1      (111)
#define DMAMUX1_TIM17_UP       (112)
#define DMAMUX1_SAI3A          (113)
#define DMAMUX1_SAI3B          (114)
#define DMAMUX1_ADC3           (115)
/* DMAMUX1 116-127: Reserved */

/* DMAMUX2 mapping ******************************************************************/

/* NOTE: DMAMUX2 channels 0 to 7 are connected to BDMA channels 0 to 7 */

#define DMAMUX2_REQ_GEN0       (1)
#define DMAMUX2_REQ_GEN1       (2)
#define DMAMUX2_REQ_GEN2       (3)
#define DMAMUX2_REQ_GEN3       (4)
#define DMAMUX2_REQ_GEN4       (5)
#define DMAMUX2_REQ_GEN5       (6)
#define DMAMUX2_REQ_GEN6       (7)
#define DMAMUX2_REQ_GEN7       (8)
#define DMAMUX2_LPUART1_RX     (9)
#define DMAMUX2_LPUART1_TX     (10)
#define DMAMUX2_SPI6_RX        (11)
#define DMAMUX2_SPI6_TX        (12)
#define DMAMUX2_I2C4_RX        (13)
#define DMAMUX2_I2C4_TX        (14)
#define DMAMUX2_SAI4A          (15)
#define DMAMUX2_SAI4B          (16)
#define DMAMUX2_ADC3           (17)
/* DMAMUX2 18-32: Reserved */

/* DMAMAP for MDMA */

#define MDMA_STR_DMA1S0     0
#define MDMA_STR_DMA1S1     1
#define MDMA_STR_DMA1S2     2
#define MDMA_STR_DMA1S3     3
#define MDMA_STR_DMA1S4     4
#define MDMA_STR_DMA1S5     5
#define MDMA_STR_DMA1S6     6
#define MDMA_STR_DMA1S7     7
#define MDMA_STR_DMA2S0     8
#define MDMA_STR_DMA2S1     9
#define MDMA_STR_DMA2S2     10
#define MDMA_STR_DMA2S3     11
#define MDMA_STR_DMA2S4     12
#define MDMA_STR_DMA2S5     13
#define MDMA_STR_DMA2S6     14
#define MDMA_STR_DMA2S7     15
#define MDMA_STR_LTDC       16
#define MDMA_STR_JPEG_IFT   17
#define MDMA_STR_JPEG_IFNT  18
#define MDMA_STR_JPEG_OFT   19
#define MDMA_STR_JPEG_OFNE  20
#define MDMA_STR_JPEG_OEC   21
#define MDMA_STR_QUADSPI_FT 22
#define MDMA_STR_QUADSPI_TC 23
#define MDMA_STR_DMA2D_CLUT 24
#define MDMA_STR_DMA2D_TC   25
#define MDMA_STR_DMA2D_TW   26
#define MDMA_STR_SDMMC1     29

/* DMAP for MDMA (no DMAMUX) */

#define DMAP_MDMA_DMA1S0           DMAMAP_MAP(MDMA, MDMA_STR_DMA1S0)
#define DMAP_MDMA_DMA1S1           DMAMAP_MAP(MDMA, MDMA_STR_DMA1S1)
#define DMAP_MDMA_DMA1S2           DMAMAP_MAP(MDMA, MDMA_STR_DMA1S2)
#define DMAP_MDMA_DMA1S3           DMAMAP_MAP(MDMA, MDMA_STR_DMA1S3)
#define DMAP_MDMA_DMA1S4           DMAMAP_MAP(MDMA, MDMA_STR_DMA1S4)
#define DMAP_MDMA_DMA1S5           DMAMAP_MAP(MDMA, MDMA_STR_DMA1S5)
#define DMAP_MDMA_DMA1S6           DMAMAP_MAP(MDMA, MDMA_STR_DMA1S6)
#define DMAP_MDMA_DMA1S7           DMAMAP_MAP(MDMA, MDMA_STR_DMA1S7)
#define DMAP_MDMA_DMA2S0           DMAMAP_MAP(MDMA, MDMA_STR_DMA2S0)
#define DMAP_MDMA_DMA2S1           DMAMAP_MAP(MDMA, MDMA_STR_DMA2S1)
#define DMAP_MDMA_DMA2S2           DMAMAP_MAP(MDMA, MDMA_STR_DMA2S2)
#define DMAP_MDMA_DMA2S3           DMAMAP_MAP(MDMA, MDMA_STR_DMA2S3)
#define DMAP_MDMA_DMA2S4           DMAMAP_MAP(MDMA, MDMA_STR_DMA2S4)
#define DMAP_MDMA_DMA2S5           DMAMAP_MAP(MDMA, MDMA_STR_DMA2S5)
#define DMAP_MDMA_DMA2S6           DMAMAP_MAP(MDMA, MDMA_STR_DMA2S6)
#define DMAP_MDMA_DMA2S7           DMAMAP_MAP(MDMA, MDMA_STR_DMA2S7)
#define DMAP_MDMA_LTDC             DMAMAP_MAP(MDMA, MDMA_STR_LTDC)
#define DMAP_MDMA_JPEG_IFT         DMAMAP_MAP(MDMA, MDMA_STR_JPEG_IFT)
#define DMAP_MDMA_JPEG_IFNT        DMAMAP_MAP(MDMA, MDMA_STR_JPEG_IFNT)
#define DMAP_MDMA_JPEG_OFT         DMAMAP_MAP(MDMA, MDMA_STR_JPEG_OFT)
#define DMAP_MDMA_JPEG_OFNE        DMAMAP_MAP(MDMA, MDMA_STR_JPEG_OFNE)
#define DMAP_MDMA_JPEG_OEC         DMAMAP_MAP(MDMA, MDMA_STR_JPEG_OEC)
#define DMAP_MDMA_QUADSPI_FT       DMAMAP_MAP(MDMA, MDMA_STR_QUADSPI_FT)
#define DMAP_MDMA_QUADSPI_TC       DMAMAP_MAP(MDMA, MDMA_STR_QUADSPI_TC)
#define DMAP_MDMA_DMA2D_CLUT       DMAMAP_MAP(MDMA, MDMA_STR_QUADSPI_CLUT)
#define DMAP_MDMA_DMA2D_TC         DMAMAP_MAP(MDMA, MDMA_STR_DMA2d_TC)
#define DMAP_MDMA_DMA2D_TW         DMAMAP_MAP(MDMA, MDMA_STR_DMA2D_TW)
#define DMAP_MDMA_SDMMC1           DMAMAP_MAP(MDMA, MDMA_STR_SDMMC1)

/* DMAMAP for DMA1 and DMA2 (DMAMUX1) */

#define DMAMAP_DMA12_REGGEN0_0     DMAMAP_MAP(DMA1, DMAMUX1_REQ_GEN0)
#define DMAMAP_DMA12_REGGEN0_1     DMAMAP_MAP(DMA2, DMAMUX1_REQ_GEN0)
#define DMAMAP_DMA12_REGGEN1_0     DMAMAP_MAP(DMA1, DMAMUX1_REQ_GEN1)
#define DMAMAP_DMA12_REGGEN1_1     DMAMAP_MAP(DMA2, DMAMUX1_REQ_GEN1)
#define DMAMAP_DMA12_REGGEN2_0     DMAMAP_MAP(DMA1, DMAMUX1_REQ_GEN2)
#define DMAMAP_DMA12_REGGEN2_1     DMAMAP_MAP(DMA2, DMAMUX1_REQ_GEN2)
#define DMAMAP_DMA12_REGGEN3_0     DMAMAP_MAP(DMA1, DMAMUX1_REQ_GEN3)
#define DMAMAP_DMA12_REGGEN3_1     DMAMAP_MAP(DMA2, DMAMUX1_REQ_GEN3)
#define DMAMAP_DMA12_REGGEN4_0     DMAMAP_MAP(DMA1, DMAMUX1_REQ_GEN4)
#define DMAMAP_DMA12_REGGEN4_1     DMAMAP_MAP(DMA2, DMAMUX1_REQ_GEN4)
#define DMAMAP_DMA12_REGGEN5_0     DMAMAP_MAP(DMA1, DMAMUX1_REQ_GEN5)
#define DMAMAP_DMA12_REGGEN5_1     DMAMAP_MAP(DMA2, DMAMUX1_REQ_GEN5)
#define DMAMAP_DMA12_REGGEN6_0     DMAMAP_MAP(DMA1, DMAMUX1_REQ_GEN6)
#define DMAMAP_DMA12_REGGEN6_1     DMAMAP_MAP(DMA2, DMAMUX1_REQ_GEN6)
#define DMAMAP_DMA12_REGGEN7_0     DMAMAP_MAP(DMA1, DMAMUX1_REQ_GEN7)
#define DMAMAP_DMA12_REGGEN7_1     DMAMAP_MAP(DMA2, DMAMUX1_REQ_GEN7)
#define DMAMAP_DMA12_ADC1_0        DMAMAP_MAP(DMA1, DMAMUX1_ADC1)
#define DMAMAP_DMA12_ADC1_1        DMAMAP_MAP(DMA2, DMAMUX1_ADC1)
#define DMAMAP_DMA12_ADC2_0        DMAMAP_MAP(DMA1, DMAMUX1_ADC2)
#define DMAMAP_DMA12_ADC2_1        DMAMAP_MAP(DMA2, DMAMUX1_ADC2)
#define DMAMAP_DMA12_TIM1CH1_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM1_CH1)
#define DMAMAP_DMA12_TIM1CH1_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM1_CH1)
#define DMAMAP_DMA12_TIM1CH2_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM1_CH2)
#define DMAMAP_DMA12_TIM1CH2_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM1_CH2)
#define DMAMAP_DMA12_TIM1CH3_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM1_CH3)
#define DMAMAP_DMA12_TIM1CH3_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM1_CH3)
#define DMAMAP_DMA12_TIM1CH4_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM1_CH4)
#define DMAMAP_DMA12_TIM1CH4_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM1_CH4)
#define DMAMAP_DMA12_TIM1UP_0      DMAMAP_MAP(DMA1, DMAMUX1_TIM1_UP)
#define DMAMAP_DMA12_TIM1UP_1      DMAMAP_MAP(DMA2, DMAMUX1_TIM1_UP)
#define DMAMAP_DMA12_TIM1TRIG_0    DMAMAP_MAP(DMA1, DMAMUX1_TIM1_TRIG)
#define DMAMAP_DMA12_TIM1TRIG_1    DMAMAP_MAP(DMA2, DMAMUX1_TIM1_TRIG)
#define DMAMAP_DMA12_TIM1COM_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM1_COM)
#define DMAMAP_DMA12_TIM1COM_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM1_COM)
#define DMAMAP_DMA12_TIM2CH1_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM2_CH1)
#define DMAMAP_DMA12_TIM2CH1_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM2_CH1)
#define DMAMAP_DMA12_TIM2CH2_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM2_CH2)
#define DMAMAP_DMA12_TIM2CH2_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM2_CH2)
#define DMAMAP_DMA12_TIM2CH3_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM2_CH3)
#define DMAMAP_DMA12_TIM2CH3_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM2_CH3)
#define DMAMAP_DMA12_TIM2CH4_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM2_CH4)
#define DMAMAP_DMA12_TIM2CH4_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM2_CH4)
#define DMAMAP_DMA12_TIM2UP_0      DMAMAP_MAP(DMA1, DMAMUX1_TIM2_UP)
#define DMAMAP_DMA12_TIM2UP_1      DMAMAP_MAP(DMA2, DMAMUX1_TIM2_UP)
#define DMAMAP_DMA12_TIM3CH1_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM3_CH1)
#define DMAMAP_DMA12_TIM3CH1_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM3_CH1)
#define DMAMAP_DMA12_TIM3CH2_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM3_CH2)
#define DMAMAP_DMA12_TIM3CH2_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM3_CH2)
#define DMAMAP_DMA12_TIM3CH3_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM3_CH3)
#define DMAMAP_DMA12_TIM3CH3_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM3_CH3)
#define DMAMAP_DMA12_TIM3CH4_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM3_CH4)
#define DMAMAP_DMA12_TIM3CH4_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM3_CH4)
#define DMAMAP_DMA12_TIM3UP_0      DMAMAP_MAP(DMA1, DMAMUX1_TIM3_UP)
#define DMAMAP_DMA12_TIM3UP_1      DMAMAP_MAP(DMA2, DMAMUX1_TIM3_UP)
#define DMAMAP_DMA12_TIM3TRIG_0    DMAMAP_MAP(DMA1, DMAMUX1_TIM3_TRIG)
#define DMAMAP_DMA12_TIM3TRIG_1    DMAMAP_MAP(DMA2, DMAMUX1_TIM3_TRIG)
#define DMAMAP_DMA12_TIM4CH1_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM4_CH1)
#define DMAMAP_DMA12_TIM4CH1_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM4_CH1)
#define DMAMAP_DMA12_TIM4CH2_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM4_CH2)
#define DMAMAP_DMA12_TIM4CH2_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM4_CH2)
#define DMAMAP_DMA12_TIM4CH3_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM4_CH3)
#define DMAMAP_DMA12_TIM4CH3_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM4_CH3)
#define DMAMAP_DMA12_TIM4UP_0      DMAMAP_MAP(DMA1, DMAMUX1_TIM4_UP)
#define DMAMAP_DMA12_TIM4UP_1      DMAMAP_MAP(DMA2, DMAMUX1_TIM4_UP)
#define DMAMAP_DMA12_I2C1RX_0      DMAMAP_MAP(DMA1, DMAMUX1_I2C1_RX)
#define DMAMAP_DMA12_I2C1RX_1      DMAMAP_MAP(DMA2, DMAMUX1_I2C1_RX)
#define DMAMAP_DMA12_I2C2TX_0      DMAMAP_MAP(DMA1, DMAMUX1_I2C2_TX)
#define DMAMAP_DMA12_I2C2TX_1      DMAMAP_MAP(DMA2, DMAMUX1_I2C2_TX)
#define DMAMAP_DMA12_SPI1RX_0      DMAMAP_MAP(DMA1, DMAMUX1_SPI1_RX)
#define DMAMAP_DMA12_SPI1RX_1      DMAMAP_MAP(DMA2, DMAMUX1_SPI1_RX)
#define DMAMAP_DMA12_SPI1TX_0      DMAMAP_MAP(DMA1, DMAMUX1_SPI1_TX)
#define DMAMAP_DMA12_SPI1TX_1      DMAMAP_MAP(DMA2, DMAMUX1_SPI1_TX)
#define DMAMAP_DMA12_SPI2RX_0      DMAMAP_MAP(DMA1, DMAMUX1_SPI2_RX)
#define DMAMAP_DMA12_SPI2RX_1      DMAMAP_MAP(DMA2, DMAMUX1_SPI2_RX)
#define DMAMAP_DMA12_SPI2TX_0      DMAMAP_MAP(DMA1, DMAMUX1_SPI2_TX)
#define DMAMAP_DMA12_SPI2TX_1      DMAMAP_MAP(DMA2, DMAMUX1_SPI2_TX)
#define DMAMAP_DMA12_USART1RX_0    DMAMAP_MAP(DMA1, DMAMUX1_USART1_RX)
#define DMAMAP_DMA12_USART1RX_1    DMAMAP_MAP(DMA2, DMAMUX1_USART1_RX)
#define DMAMAP_DMA12_USART1TX_0    DMAMAP_MAP(DMA1, DMAMUX1_USART1_TX)
#define DMAMAP_DMA12_USART1TX_1    DMAMAP_MAP(DMA2, DMAMUX1_USART1_TX)
#define DMAMAP_DMA12_USART2RX_0    DMAMAP_MAP(DMA1, DMAMUX1_USART2_RX)
#define DMAMAP_DMA12_USART2RX_1    DMAMAP_MAP(DMA2, DMAMUX1_USART2_RX)
#define DMAMAP_DMA12_USART2TX_0    DMAMAP_MAP(DMA1, DMAMUX1_USART2_TX)
#define DMAMAP_DMA12_USART2TX_1    DMAMAP_MAP(DMA2, DMAMUX1_USART2_TX)
#define DMAMAP_DMA12_USART3RX_0    DMAMAP_MAP(DMA1, DMAMUX1_USART3_RX)
#define DMAMAP_DMA12_USART3RX_1    DMAMAP_MAP(DMA2, DMAMUX1_USART3_RX)
#define DMAMAP_DMA12_USART3TX_0    DMAMAP_MAP(DMA1, DMAMUX1_USART3_TX)
#define DMAMAP_DMA12_USART3TX_1    DMAMAP_MAP(DMA2, DMAMUX1_USART3_TX)
#define DMAMAP_DMA12_TIM8CH1_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM8_CH1)
#define DMAMAP_DMA12_TIM8CH1_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM8_CH1)
#define DMAMAP_DMA12_TIM8CH2_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM8_CH2)
#define DMAMAP_DMA12_TIM8CH2_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM8_CH2)
#define DMAMAP_DMA12_TIM8CH3_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM8_CH3)
#define DMAMAP_DMA12_TIM8CH3_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM8_CH3)
#define DMAMAP_DMA12_TIM8CH4_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM8_CH4)
#define DMAMAP_DMA12_TIM8CH4_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM8_CH4)
#define DMAMAP_DMA12_TIM8UP_0      DMAMAP_MAP(DMA1, DMAMUX1_TIM8_UP)
#define DMAMAP_DMA12_TIM8UP_1      DMAMAP_MAP(DMA2, DMAMUX1_TIM8_UP)
#define DMAMAP_DMA12_TIM8TRIG_0    DMAMAP_MAP(DMA1, DMAMUX1_TIM8_TRIG)
#define DMAMAP_DMA12_TIM8TRIG_1    DMAMAP_MAP(DMA2, DMAMUX1_TIM8_TRIG)
#define DMAMAP_DMA12_TIM8COM_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM8_COM)
#define DMAMAP_DMA12_TIM8COM_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM8_COM)
#define DMAMAP_DMA12_TIM5CH1_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM5_CH1)
#define DMAMAP_DMA12_TIM5CH1_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM5_CH1)
#define DMAMAP_DMA12_TIM5CH2_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM5_CH2)
#define DMAMAP_DMA12_TIM5CH2_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM5_CH2)
#define DMAMAP_DMA12_TIM5CH3_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM5_CH3)
#define DMAMAP_DMA12_TIM5CH3_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM5_CH3)
#define DMAMAP_DMA12_TIM5CH4_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM5_CH4)
#define DMAMAP_DMA12_TIM5CH4_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM5_CH4)
#define DMAMAP_DMA12_TIM5UP_0      DMAMAP_MAP(DMA1, DMAMUX1_TIM5_UP)
#define DMAMAP_DMA12_TIM5UP_1      DMAMAP_MAP(DMA2, DMAMUX1_TIM5_UP)
#define DMAMAP_DMA12_TIM5TRIG_0    DMAMAP_MAP(DMA1, DMAMUX1_TIM5_TRIG)
#define DMAMAP_DMA12_TIM5TRIG_1    DMAMAP_MAP(DMA2, DMAMUX1_TIM5_TRIG)
#define DMAMAP_DMA12_SPI3RX_0      DMAMAP_MAP(DMA1, DMAMUX1_SPI3_RX)
#define DMAMAP_DMA12_SPI3RX_1      DMAMAP_MAP(DMA2, DMAMUX1_SPI3_RX)
#define DMAMAP_DMA12_SPI3TX_0      DMAMAP_MAP(DMA1, DMAMUX1_SPI3_TX)
#define DMAMAP_DMA12_SPI3TX_1      DMAMAP_MAP(DMA2, DMAMUX1_SPI3_TX)
#define DMAMAP_DMA12_UART4RX_0     DMAMAP_MAP(DMA1, DMAMUX1_UART4_RX)
#define DMAMAP_DMA12_UART4RX_1     DMAMAP_MAP(DMA2, DMAMUX1_UART4_RX)
#define DMAMAP_DMA12_UART4TX_0     DMAMAP_MAP(DMA1, DMAMUX1_UART4_TX)
#define DMAMAP_DMA12_UART4TX_1     DMAMAP_MAP(DMA2, DMAMUX1_UART4_TX)
#define DMAMAP_DMA12_UART5RX_0     DMAMAP_MAP(DMA1, DMAMUX1_UART5_RX)
#define DMAMAP_DMA12_UART5RX_1     DMAMAP_MAP(DMA2, DMAMUX1_UART5_RX)
#define DMAMAP_DMA12_UART5TX_0     DMAMAP_MAP(DMA1, DMAMUX1_UART5_TX)
#define DMAMAP_DMA12_UART5TX_1     DMAMAP_MAP(DMA2, DMAMUX1_UART5_TX)
#define DMAMAP_DMA12_DAC1CH1_0     DMAMAP_MAP(DMA1, DMAMUX1_DAC1_CH1)
#define DMAMAP_DMA12_DAC1CH1_1     DMAMAP_MAP(DMA2, DMAMUX1_DAC1_CH1)
#define DMAMAP_DMA12_DAC1CH2_0     DMAMAP_MAP(DMA1, DMAMUX1_DAC1_CH2)
#define DMAMAP_DMA12_DAC1CH2_1     DMAMAP_MAP(DMA2, DMAMUX1_DAC1_CH2)
#define DMAMAP_DMA12_TIM6UP_0      DMAMAP_MAP(DMA1, DMAMUX1_TIM6_UP)
#define DMAMAP_DMA12_TIM6UP_1      DMAMAP_MAP(DMA2, DMAMUX1_TIM6_UP)
#define DMAMAP_DMA12_TIM7UP_0      DMAMAP_MAP(DMA1, DMAMUX1_TIM7_UP)
#define DMAMAP_DMA12_TIM7UP_1      DMAMAP_MAP(DMA2, DMAMUX1_TIM7_UP)
#define DMAMAP_DMA12_USART6RX_0    DMAMAP_MAP(DMA1, DMAMUX1_USART6_RX)
#define DMAMAP_DMA12_USART6RX_1    DMAMAP_MAP(DMA2, DMAMUX1_USART6_RX)
#define DMAMAP_DMA12_USART6TX_0    DMAMAP_MAP(DMA1, DMAMUX1_USART6_TX)
#define DMAMAP_DMA12_USART6TX_1    DMAMAP_MAP(DMA2, DMAMUX1_USART6_TX)
#define DMAMAP_DMA12_I2C3RX_0      DMAMAP_MAP(DMA1, DMAMUX1_I2C3_RX)
#define DMAMAP_DMA12_I2C3RX_1      DMAMAP_MAP(DMA2, DMAMUX1_I2C3_RX)
#define DMAMAP_DMA12_I2C3TX_0      DMAMAP_MAP(DMA1, DMAMUX1_I2C3_TX)
#define DMAMAP_DMA12_I2C3TX_1      DMAMAP_MAP(DMA2, DMAMUX1_I2C3_TX)
#define DMAMAP_DMA12_DCMI_0        DMAMAP_MAP(DMA1, DMAMUX1_DCMI)
#define DMAMAP_DMA12_DCMI_1        DMAMAP_MAP(DMA2, DMAMUX1_DCMI)
#define DMAMAP_DMA12_CRYPTOIN_0    DMAMAP_MAP(DMA1, DMAMUX1_CRYPTO_IN)
#define DMAMAP_DMA12_CRYPTOIN_1    DMAMAP_MAP(DMA2, DMAMUX1_CRYPTO_IN)
#define DMAMAP_DMA12_CRYPTOOUT_0   DMAMAP_MAP(DMA1, DMAMUX1_CRYPTO_OUT)
#define DMAMAP_DMA12_CRYPTOOUT_1   DMAMAP_MAP(DMA2, DMAMUX1_CRYPTO_OUT)
#define DMAMAP_DMA12_HASHIN_0      DMAMAP_MAP(DMA1, DMAMUX1_HASH_IN)
#define DMAMAP_DMA12_HASHIN_1      DMAMAP_MAP(DMA2, DMAMUX1_HASH_IN)
#define DMAMAP_DMA12_UART7RX_0     DMAMAP_MAP(DMA1, DMAMUX1_UART7_RX)
#define DMAMAP_DMA12_UART7RX_1     DMAMAP_MAP(DMA2, DMAMUX1_UART7_RX)
#define DMAMAP_DMA12_UART7TX_0     DMAMAP_MAP(DMA1, DMAMUX1_UART7_TX)
#define DMAMAP_DMA12_UART7TX_1     DMAMAP_MAP(DMA2, DMAMUX1_UART7_TX)
#define DMAMAP_DMA12_UART8RX_0     DMAMAP_MAP(DMA1, DMAMUX1_UART8_RX)
#define DMAMAP_DMA12_UART8RX_1     DMAMAP_MAP(DMA2, DMAMUX1_UART8_RX)
#define DMAMAP_DMA12_UART8TX_0     DMAMAP_MAP(DMA1, DMAMUX1_UART8_TX)
#define DMAMAP_DMA12_UART8TX_1     DMAMAP_MAP(DMA2, DMAMUX1_UART8_TX)
#define DMAMAP_DMA12_SPI4RX_0      DMAMAP_MAP(DMA1, DMAMUX1_SPI4_RX)
#define DMAMAP_DMA12_SPI4RX_1      DMAMAP_MAP(DMA2, DMAMUX1_SPI4_RX)
#define DMAMAP_DMA12_SPI4TX_0      DMAMAP_MAP(DMA1, DMAMUX1_SPI4_TX)
#define DMAMAP_DMA12_SPI4TX_1      DMAMAP_MAP(DMA2, DMAMUX1_SPI4_TX)
#define DMAMAP_DMA12_SPI5RX_0      DMAMAP_MAP(DMA1, DMAMUX1_SPI5_RX)
#define DMAMAP_DMA12_SPI5RX_1      DMAMAP_MAP(DMA2, DMAMUX1_SPI5_RX)
#define DMAMAP_DMA12_SPI5TX_0      DMAMAP_MAP(DMA1, DMAMUX1_SPI5_TX)
#define DMAMAP_DMA12_SPI5TX_1      DMAMAP_MAP(DMA2, DMAMUX1_SPI5_TX)
#define DMAMAP_DMA12_SAI1A_0       DMAMAP_MAP(DMA1, DMAMUX1_SAI1A)
#define DMAMAP_DMA12_SAI1A_1       DMAMAP_MAP(DMA2, DMAMUX1_SAI1A)
#define DMAMAP_DMA12_SAI1B_0       DMAMAP_MAP(DMA1, DMAMUX1_SAI1B)
#define DMAMAP_DMA12_SAI1B_1       DMAMAP_MAP(DMA2, DMAMUX1_SAI1B)
#define DMAMAP_DMA12_SAI2A_0       DMAMAP_MAP(DMA1, DMAMUX1_SAI2A)
#define DMAMAP_DMA12_SAI2A_1       DMAMAP_MAP(DMA2, DMAMUX1_SAI2A)
#define DMAMAP_DMA12_SAI2B_0       DMAMAP_MAP(DMA1, DMAMUX1_SAI2B)
#define DMAMAP_DMA12_SAI2B_1       DMAMAP_MAP(DMA2, DMAMUX1_SAI2B)
#define DMAMAP_DMA12_SWPMIRX_0     DMAMAP_MAP(DMA1, DMAMUX1_SWPMI_RX)
#define DMAMAP_DMA12_SWPMIRX_1     DMAMAP_MAP(DMA2, DMAMUX1_SWPMI_RX)
#define DMAMAP_DMA12_SWPMITX_0     DMAMAP_MAP(DMA1, DMAMUX1_SWPMI_TX)
#define DMAMAP_DMA12_SWPMITX_1     DMAMAP_MAP(DMA2, DMAMUX1_SWPMI_TX)
#define DMAMAP_DMA12_SPDIFRFDAT_0  DMAMAP_MAP(DMA1, DMAMUX1_SPDIFRX_DAT)
#define DMAMAP_DMA12_SPDIFRFDAT_1  DMAMAP_MAP(DMA2, DMAMUX1_SPDIFRX_DAT)
#define DMAMAP_DMA12_SPDIFRFCTRL_0 DMAMAP_MAP(DMA1, DMAMUX1_SPDIFRX_CTRL)
#define DMAMAP_DMA12_SPDIFRFCTRL_1 DMAMAP_MAP(DMA2, DMAMUX1_SPDIFRX_CTRL)
#define DMAMAP_DMA12_HRREQ1_0      DMAMAP_MAP(DMA1, DMAMUX1_HR_REQ1)
#define DMAMAP_DMA12_HRREQ1_1      DMAMAP_MAP(DMA2, DMAMUX1_HR_REQ1)
#define DMAMAP_DMA12_HRREQ2_0      DMAMAP_MAP(DMA1, DMAMUX1_HR_REQ2)
#define DMAMAP_DMA12_HRREQ2_1      DMAMAP_MAP(DMA2, DMAMUX1_HR_REQ2)
#define DMAMAP_DMA12_HRREQ3_0      DMAMAP_MAP(DMA1, DMAMUX1_HR_REQ3)
#define DMAMAP_DMA12_HRREQ3_1      DMAMAP_MAP(DMA2, DMAMUX1_HR_REQ3)
#define DMAMAP_DMA12_HRREQ4_0      DMAMAP_MAP(DMA1, DMAMUX1_HR_REQ4)
#define DMAMAP_DMA12_HRREQ4_1      DMAMAP_MAP(DMA2, DMAMUX1_HR_REQ4)
#define DMAMAP_DMA12_HRREQ5_0      DMAMAP_MAP(DMA1, DMAMUX1_HR_REQ5)
#define DMAMAP_DMA12_HRREQ5_1      DMAMAP_MAP(DMA2, DMAMUX1_HR_REQ5)
#define DMAMAP_DMA12_HRREQ6_0      DMAMAP_MAP(DMA1, DMAMUX1_HR_REQ6)
#define DMAMAP_DMA12_HRREQ6_1      DMAMAP_MAP(DMA2, DMAMUX1_HR_REQ6)
#define DMAMAP_DMA12_DFSDM10_0     DMAMAP_MAP(DMA1, DMAMUX1_DFSDM1_0)
#define DMAMAP_DMA12_DFSDM10_1     DMAMAP_MAP(DMA2, DMAMUX1_DFSDM1_0)
#define DMAMAP_DMA12_DFSDM11_0     DMAMAP_MAP(DMA1, DMAMUX1_DFSDM1_1)
#define DMAMAP_DMA12_DFSDM11_1     DMAMAP_MAP(DMA2, DMAMUX1_DFSDM1_1)
#define DMAMAP_DMA12_DFSDM12_0     DMAMAP_MAP(DMA1, DMAMUX1_DFSDM1_2)
#define DMAMAP_DMA12_DFSDM12_1     DMAMAP_MAP(DMA2, DMAMUX1_DFSDM1_2)
#define DMAMAP_DMA12_DFSDM13_0     DMAMAP_MAP(DMA1, DMAMUX1_DFSDM1_3)
#define DMAMAP_DMA12_DFSDM13_1     DMAMAP_MAP(DMA2, DMAMUX1_DFSDM1_3)
#define DMAMAP_DMA12_TIM15CH1_0    DMAMAP_MAP(DMA1, DMAMUX1_TIM15_CH1)
#define DMAMAP_DMA12_TIM15CH1_1    DMAMAP_MAP(DMA2, DMAMUX1_TIM15_CH1)
#define DMAMAP_DMA12_TIM15UP_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM15_UP)
#define DMAMAP_DMA12_TIM15UP_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM15_UP)
#define DMAMAP_DMA12_TIM15TRIG_0   DMAMAP_MAP(DMA1, DMAMUX1_TIM15_TRIG)
#define DMAMAP_DMA12_TIM15TRIG_1   DMAMAP_MAP(DMA2, DMAMUX1_TIM15_TRIG)
#define DMAMAP_DMA12_TIM15COM_0    DMAMAP_MAP(DMA1, DMAMUX1_TIM15_COM)
#define DMAMAP_DMA12_TIM15COM_1    DMAMAP_MAP(DMA2, DMAMUX1_TIM15_COM)
#define DMAMAP_DMA12_TIM16CH1_0    DMAMAP_MAP(DMA1, DMAMUX1_TIM16_CH1)
#define DMAMAP_DMA12_TIM16CH1_1    DMAMAP_MAP(DMA2, DMAMUX1_TIM16_CH1)
#define DMAMAP_DMA12_TIM16UP_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM16_UP)
#define DMAMAP_DMA12_TIM16UP_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM16_UP)
#define DMAMAP_DMA12_TIM17CH1_0    DMAMAP_MAP(DMA1, DMAMUX1_TIM17_CH1)
#define DMAMAP_DMA12_TIM17CH1_1    DMAMAP_MAP(DMA2, DMAMUX1_TIM17_CH1)
#define DMAMAP_DMA12_TIM17UP_0     DMAMAP_MAP(DMA1, DMAMUX1_TIM17_UP)
#define DMAMAP_DMA12_TIM17UP_1     DMAMAP_MAP(DMA2, DMAMUX1_TIM17_UP)
#define DMAMAP_DMA12_SAI3A_0       DMAMAP_MAP(DMA1, DMAMUX1_SAI3A)
#define DMAMAP_DMA12_SAI3A_1       DMAMAP_MAP(DMA2, DMAMUX1_SAI3A)
#define DMAMAP_DMA12_SAI3B_0       DMAMAP_MAP(DMA1, DMAMUX1_SAI3B)
#define DMAMAP_DMA12_SAI3B_1       DMAMAP_MAP(DMA2, DMAMUX1_SAI3B)
#define DMAMAP_DMA12_ADC3_0        DMAMAP_MAP(DMA1, DMAMUX1_ADC3)
#define DMAMAP_DMA12_ADC3_1        DMAMAP_MAP(DMA2, DMAMUX1_ADC3)

/* DMAMAP for BDMA (DMAMUX2) */

#define DMAMAP_BDMA_REGGEN0        DMAMAP_MAP(BDMA, DMAMUX2_REQ_GEN0)
#define DMAMAP_BDMA_REGGEN1        DMAMAP_MAP(BDMA, DMAMUX2_REQ_GEN1)
#define DMAMAP_BDMA_REGGEN2        DMAMAP_MAP(BDMA, DMAMUX2_REQ_GEN2)
#define DMAMAP_BDMA_REGGEN3        DMAMAP_MAP(BDMA, DMAMUX2_REQ_GEN3)
#define DMAMAP_BDMA_REGGEN4        DMAMAP_MAP(BDMA, DMAMUX2_REQ_GEN4)
#define DMAMAP_BDMA_REGGEN5        DMAMAP_MAP(BDMA, DMAMUX2_REQ_GEN5)
#define DMAMAP_BDMA_REGGEN6        DMAMAP_MAP(BDMA, DMAMUX2_REQ_GEN6)
#define DMAMAP_BDMA_REGGEN7        DMAMAP_MAP(BDMA, DMAMUX2_REQ_GEN7)
#define DMAMAP_BDMA_LPUART1_RX     DMAMAP_MAP(BDMA, DMAMUX2_LPUART_RX)
#define DMAMAP_BDMA_LPUART1_TX     DMAMAP_MAP(BDMA, DMAMUX2_LPUART_TX)
#define DMAMAP_BDMA_SPI6_RX        DMAMAP_MAP(BDMA, DMAMUX2_SPI6_RX)
#define DMAMAP_BDMA_SPI6_TX        DMAMAP_MAP(BDMA, DMAMUX2_SPI6_TX)
#define DMAMAP_BDMA_I2C4_RX        DMAMAP_MAP(BDMA, DMAMUX2_I2C4_RX)
#define DMAMAP_BDMA_I2C4_TX        DMAMAP_MAP(BDMA, DMAMUX2_I2C4_TX)
#define DMAMAP_BDMA_SAI4A          DMAMAP_MAP(BDMA, DMAMUX2_SAI4A)
#define DMAMAP_BDMA_SAI4B          DMAMAP_MAP(BDMA, DMAMUX2_SAI4B)
#define DMAMAP_BDMA_ADC3           DMAMAP_MAP(BDMA, DMAMUX2_ADC3)

#endif /* __ARCH_ARM_SRC_STM32H7_HARDWARE_STM32H7X3XX_DMAMUX_H */
