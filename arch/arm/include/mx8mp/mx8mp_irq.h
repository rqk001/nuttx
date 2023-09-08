/****************************************************************************
 * arch/arm/include/mx8mp/mx8mp_irq.h
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

/* This file should never be included directly but, rather, only indirectly
 * through nuttx/irq.h
 */

#ifndef ARCH_ARM_INCLUDE_MX8MP_IRQ_H
#define ARCH_ARM_INCLUDE_MX8MP_IRQ_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Prototypes
 ****************************************************************************/

/* IRQ numbers.  The IRQ number corresponds vector number and hence map
 * directly to bits in the NVIC.  This does, however, waste several words of
 * memory in the IRQ to handle mapping tables.
 *
 * Processor Exceptions (vectors 0-15). These common definitions can be found
 * in the file nuttx/arch/arm/include/mx8mp/irq.h which includes this file
 *
 * External interrupts (vectors >= 16)
 */

#define MX8MP_IRQ_DAP            (MX8MP_IRQ_FIRST + 1)
#define MX8MP_IRQ_SDMA1          (MX8MP_IRQ_FIRST + 2)
#define MX8MP_IRQ_GPU3D          (MX8MP_IRQ_FIRST + 3)
#define MX8MP_IRQ_SNVS_ONOFF     (MX8MP_IRQ_FIRST + 4)
#define MX8MP_IRQ_LCDIF1         (MX8MP_IRQ_FIRST + 5)
#define MX8MP_IRQ_LCDIF2         (MX8MP_IRQ_FIRST + 6)
#define MX8MP_IRQ_VPU_G1         (MX8MP_IRQ_FIRST + 7)
#define MX8MP_IRQ_VPU_G2         (MX8MP_IRQ_FIRST + 8)
#define MX8MP_IRQ_QOS            (MX8MP_IRQ_FIRST + 9)
#define MX8MP_IRQ_WDOG3          (MX8MP_IRQ_FIRST + 10)
#define MX8MP_IRQ_HS_CP1         (MX8MP_IRQ_FIRST + 11)
#define MX8MP_IRQ_APBHDMA        (MX8MP_IRQ_FIRST + 12)
#define MX8MP_IRQ_NPU            (MX8MP_IRQ_FIRST + 13)
#define MX8MP_IRQ_RAWNAND_BCH    (MX8MP_IRQ_FIRST + 14)
#define MX8MP_IRQ_RAWNAND_GPMI   (MX8MP_IRQ_FIRST + 15)
#define MX8MP_IRQ_ISI_C0         (MX8MP_IRQ_FIRST + 16)
#define MX8MP_IRQ_MIPI_CSI1      (MX8MP_IRQ_FIRST + 17)
#define MX8MP_IRQ_MIPI_DSI       (MX8MP_IRQ_FIRST + 18)
#define MX8MP_IRQ_SNVS_SRTC_NTZ  (MX8MP_IRQ_FIRST + 19)
#define MX8MP_IRQ_SNVS_SRTC_TZ   (MX8MP_IRQ_FIRST + 20)
#define MX8MP_IRQ_CSU            (MX8MP_IRQ_FIRST + 21)
#define MX8MP_IRQ_USDHC1         (MX8MP_IRQ_FIRST + 22)
#define MX8MP_IRQ_USDHC2         (MX8MP_IRQ_FIRST + 23)
#define MX8MP_IRQ_USDHC3         (MX8MP_IRQ_FIRST + 24)
#define MX8MP_IRQ_GPU2D          (MX8MP_IRQ_FIRST + 25)
#define MX8MP_IRQ_UART1          (MX8MP_IRQ_FIRST + 26)
#define MX8MP_IRQ_UART2          (MX8MP_IRQ_FIRST + 27)
#define MX8MP_IRQ_UART3          (MX8MP_IRQ_FIRST + 28)
#define MX8MP_IRQ_UART4          (MX8MP_IRQ_FIRST + 29)
#define MX8MP_IRQ_VPU            (MX8MP_IRQ_FIRST + 30)
#define MX8MP_IRQ_ECSPI1         (MX8MP_IRQ_FIRST + 31)
#define MX8MP_IRQ_ECSPI2         (MX8MP_IRQ_FIRST + 32)
#define MX8MP_IRQ_ECSPI3         (MX8MP_IRQ_FIRST + 33)
#define MX8MP_IRQ_SDMA3          (MX8MP_IRQ_FIRST + 34)
#define MX8MP_IRQ_I2C1           (MX8MP_IRQ_FIRST + 35)
#define MX8MP_IRQ_I2C2           (MX8MP_IRQ_FIRST + 36)
#define MX8MP_IRQ_I2C3           (MX8MP_IRQ_FIRST + 37)
#define MX8MP_IRQ_I2C4           (MX8MP_IRQ_FIRST + 38)
#define MX8MP_IRQ_RDC            (MX8MP_IRQ_FIRST + 39)
#define MX8MP_IRQ_USB1           (MX8MP_IRQ_FIRST + 40)
#define MX8MP_IRQ_USB2           (MX8MP_IRQ_FIRST + 41)
#define MX8MP_IRQ_ISI_C1         (MX8MP_IRQ_FIRST + 42)
#define MX8MP_IRQ_HDMI_TX        (MX8MP_IRQ_FIRST + 43)
#define MX8MP_IRQ_MICFIL0        (MX8MP_IRQ_FIRST + 44)
#define MX8MP_IRQ_MICFIL1        (MX8MP_IRQ_FIRST + 45)
#define MX8MP_IRQ_GPT6           (MX8MP_IRQ_FIRST + 46)
#define MX8MP_IRQ_SCTR0          (MX8MP_IRQ_FIRST + 47)
#define MX8MP_IRQ_SCTR1          (MX8MP_IRQ_FIRST + 48)
#define MX8MP_IRQ_ANAMIX         (MX8MP_IRQ_FIRST + 49)
#define MX8MP_IRQ_SAI3           (MX8MP_IRQ_FIRST + 50)
#define MX8MP_IRQ_GPT5           (MX8MP_IRQ_FIRST + 51)
#define MX8MP_IRQ_GPT4           (MX8MP_IRQ_FIRST + 52)
#define MX8MP_IRQ_GPT3           (MX8MP_IRQ_FIRST + 53)
#define MX8MP_IRQ_GPT2           (MX8MP_IRQ_FIRST + 54)
#define MX8MP_IRQ_GPT1           (MX8MP_IRQ_FIRST + 55)
#define MX8MP_IRQ_GPIO1_7        (MX8MP_IRQ_FIRST + 56)
#define MX8MP_IRQ_GPIO1_6        (MX8MP_IRQ_FIRST + 57)
#define MX8MP_IRQ_GPIO1_5        (MX8MP_IRQ_FIRST + 58)
#define MX8MP_IRQ_GPIO1_4        (MX8MP_IRQ_FIRST + 59)
#define MX8MP_IRQ_GPIO1_3        (MX8MP_IRQ_FIRST + 60)
#define MX8MP_IRQ_GPIO1_2        (MX8MP_IRQ_FIRST + 61)
#define MX8MP_IRQ_GPIO1_1        (MX8MP_IRQ_FIRST + 62)
#define MX8MP_IRQ_GPIO1_0        (MX8MP_IRQ_FIRST + 63)
#define MX8MP_IRQ_GPIO1_0_15     (MX8MP_IRQ_FIRST + 64)
#define MX8MP_IRQ_GPIO1_16_31    (MX8MP_IRQ_FIRST + 65)
#define MX8MP_IRQ_GPIO2_0_15     (MX8MP_IRQ_FIRST + 66)
#define MX8MP_IRQ_GPIO2_16_31    (MX8MP_IRQ_FIRST + 67)
#define MX8MP_IRQ_GPIO3_0_15     (MX8MP_IRQ_FIRST + 68)
#define MX8MP_IRQ_GPIO3_16_31    (MX8MP_IRQ_FIRST + 69)
#define MX8MP_IRQ_GPIO4_0_15     (MX8MP_IRQ_FIRST + 70)
#define MX8MP_IRQ_GPIO4_16_31    (MX8MP_IRQ_FIRST + 71)
#define MX8MP_IRQ_GPIO5_0_15     (MX8MP_IRQ_FIRST + 72)
#define MX8MP_IRQ_GPIO5_16_31    (MX8MP_IRQ_FIRST + 73)
#define MX8MP_IRQ_ISP1           (MX8MP_IRQ_FIRST + 74)
#define MX8MP_IRQ_ISP2           (MX8MP_IRQ_FIRST + 75)
#define MX8MP_IRQ_I2C5           (MX8MP_IRQ_FIRST + 76)
#define MX8MP_IRQ_I2C6           (MX8MP_IRQ_FIRST + 77)
#define MX8MP_IRQ_WDOG1          (MX8MP_IRQ_FIRST + 78)
#define MX8MP_IRQ_WDOG2          (MX8MP_IRQ_FIRST + 79)
#define MX8MP_IRQ_MIPI_CSI2      (MX8MP_IRQ_FIRST + 80)
#define MX8MP_IRQ_PWM1           (MX8MP_IRQ_FIRST + 81)
#define MX8MP_IRQ_PWM2           (MX8MP_IRQ_FIRST + 82)
#define MX8MP_IRQ_PWM3           (MX8MP_IRQ_FIRST + 83)
#define MX8MP_IRQ_PWM4           (MX8MP_IRQ_FIRST + 84)
#define MX8MP_IRQ_CCM1           (MX8MP_IRQ_FIRST + 85)
#define MX8MP_IRQ_CCM2           (MX8MP_IRQ_FIRST + 86)
#define MX8MP_IRQ_GPC1           (MX8MP_IRQ_FIRST + 87)
#define MX8MP_IRQ_MU1_A53        (MX8MP_IRQ_FIRST + 88)
#define MX8MP_IRQ_SRC1           (MX8MP_IRQ_FIRST + 89)
#define MX8MP_IRQ_SAI5           (MX8MP_IRQ_FIRST + 90)
#define MX8MP_IRQ_CAAM           (MX8MP_IRQ_FIRST + 91)
#define MX8MP_IRQ_CPU_PERF       (MX8MP_IRQ_FIRST + 92)
#define MX8MP_IRQ_CPU_CTI        (MX8MP_IRQ_FIRST + 93)
#define MX8MP_IRQ_WDOG_ALL       (MX8MP_IRQ_FIRST + 94)
#define MX8MP_IRQ_SAI1           (MX8MP_IRQ_FIRST + 95)
#define MX8MP_IRQ_SAI2           (MX8MP_IRQ_FIRST + 96)
#define MX8MP_IRQ_MU1_M7         (MX8MP_IRQ_FIRST + 97)
#define MX8MP_IRQ_DDR            (MX8MP_IRQ_FIRST + 98)
#define MX8MP_IRQ_DDR_DFI        (MX8MP_IRQ_FIRST + 99)
#define MX8MP_IRQ_DEWARP         (MX8MP_IRQ_FIRST + 100)
#define MX8MP_IRQ_ERROR_AXI      (MX8MP_IRQ_FIRST + 101)
#define MX8MP_IRQ_ERROR_ECC      (MX8MP_IRQ_FIRST + 102)
#define MX8MP_IRQ_SDMA2          (MX8MP_IRQ_FIRST + 103)
#define MX8MP_IRQ_SJC            (MX8MP_IRQ_FIRST + 104)
#define MX8MP_IRQ_CAAM_JQ0       (MX8MP_IRQ_FIRST + 105)
#define MX8MP_IRQ_CAAM_JQ1       (MX8MP_IRQ_FIRST + 106)
#define MX8MP_IRQ_FLEXSPI        (MX8MP_IRQ_FIRST + 107)
#define MX8MP_IRQ_TSASC          (MX8MP_IRQ_FIRST + 108)
#define MX8MP_IRQ_MICFIL0        (MX8MP_IRQ_FIRST + 109)
#define MX8MP_IRQ_MIFIL1         (MX8MP_IRQ_FIRST + 110)
#define MX8MP_IRQ_SAI7           (MX8MP_IRQ_FIRST + 111)
#define MX8MP_IRQ_PERFMON1       (MX8MP_IRQ_FIRST + 112)
#define MX8MP_IRQ_PERFMON2       (MX8MP_IRQ_FIRST + 113)
#define MX8MP_IRQ_CAAM_JQ2       (MX8MP_IRQ_FIRST + 114)
#define MX8MP_IRQ_CAAM_ERROR     (MX8MP_IRQ_FIRST + 115)
#define MX8MP_IRQ_HS_CP0         (MX8MP_IRQ_FIRST + 116)
#define MX8MP_IRQ_CM7            (MX8MP_IRQ_FIRST + 117)
#define MX8MP_IRQ_ENET1_0        (MX8MP_IRQ_FIRST + 118)
#define MX8MP_IRQ_ENET1_1        (MX8MP_IRQ_FIRST + 119)
#define MX8MP_IRQ_ENET1_2        (MX8MP_IRQ_FIRST + 120)
#define MX8MP_IRQ_ENET1_3        (MX8MP_IRQ_FIRST + 121)
#define MX8MP_IRQ_ASRC           (MX8MP_IRQ_FIRST + 122)
#define MX8MP_IRQ_PCIE_0         (MX8MP_IRQ_FIRST + 123)
#define MX8MP_IRQ_PCIE_1         (MX8MP_IRQ_FIRST + 124)
#define MX8MP_IRQ_PCIE_2         (MX8MP_IRQ_FIRST + 125)
#define MX8MP_IRQ_PCIE_3         (MX8MP_IRQ_FIRST + 126)
#define MX8MP_IRQ_PCIE_4         (MX8MP_IRQ_FIRST + 127)
#define MX8MP_IRQ_AUDIO_XCVR_0   (MX8MP_IRQ_FIRST + 128)
#define MX8MP_IRQ_AUDIO_XCVR_1   (MX8MP_IRQ_FIRST + 129)
#define MX8MP_IRQ_AUD2HTX        (MX8MP_IRQ_FIRST + 130)
#define MX8MP_IRQ_EDMA1_0        (MX8MP_IRQ_FIRST + 131)
#define MX8MP_IRQ_EDMA1_1        (MX8MP_IRQ_FIRST + 132)
#define MX8MP_IRQ_EDMA1_2        (MX8MP_IRQ_FIRST + 133)
#define MX8MP_IRQ_ENET_QOS_0     (MX8MP_IRQ_FIRST + 134)
#define MX8MP_IRQ_ENET_QOS_1     (MX8MP_IRQ_FIRST + 135)
#define MX8MP_IRQ_MU2_A53        (MX8MP_IRQ_FIRST + 136)
#define MX8MP_IRQ_MU2_DSP        (MX8MP_IRQ_FIRST + 137)
#define MX8MP_IRQ_MU3_M7         (MX8MP_IRQ_FIRST + 138)
#define MX8MP_IRQ_MU3_DSP        (MX8MP_IRQ_FIRST + 139)
#define MX8MP_IRQ_PCIE_5         (MX8MP_IRQ_FIRST + 140)
#define MX8MP_IRQ_PCIE_6         (MX8MP_IRQ_FIRST + 141)
#define MX8MP_IRQ_CAN_FD1_0      (MX8MP_IRQ_FIRST + 142)
#define MX8MP_IRQ_CAN_FD1_1      (MX8MP_IRQ_FIRST + 143)
#define MX8MP_IRQ_CAN_FD2_0      (MX8MP_IRQ_FIRST + 144)
#define MX8MP_IRQ_CAN_FD2_1      (MX8MP_IRQ_FIRST + 145)
#define MX8MP_IRQ_AUDIO_XCVR     (MX8MP_IRQ_FIRST + 146)
#define MX8MP_IRQ_DDR_ECC        (MX8MP_IRQ_FIRST + 147)
#define MX8MP_IRQ_USB1           (MX8MP_IRQ_FIRST + 148)
#define MX8MP_IRQ_USB2           (MX8MP_IRQ_FIRST + 149)

#define MX8MP_IRQ_NEXTINTS   160                    /* 112 Non core IRQs */

/* 160 vectors */

#define MX8MP_IRQ_NVECTORS   (MX8MP_IRQ_FIRST + MX8MP_IRQ_NEXTINTS)

/* GPIO second level interrupt **********************************************/

#define MX8MP_IRQ_SOFT_GPIO_START   MX8MP_IRQ_NVECTORS

/* GPIO1 has dedicated interrupts for pins 0-7, however theses pin are also
 * connected to the multiplexed IRQ and both can be triggered together is
 * enabled. Here we choose to no use the dedicated IRQ.
 * REVISIT: add an option to choose the strategy:
 * - both IRQ
 * - only dedicated (and losst of GPIO1 8-15 IRQs)
 * - only multiplexed
 */

#define MX8MP_IRQ_SOFT_GPIO1_START     MX8MP_IRQ_SOFT_GPIO_START

#define MX8MP_IRQ_SOFT_GPIO1_0      (MX8MP_IRQ_SOFT_GPIO1_START + 1)
#define MX8MP_IRQ_SOFT_GPIO1_1      (MX8MP_IRQ_SOFT_GPIO1_START + 2)
#define MX8MP_IRQ_SOFT_GPIO1_2      (MX8MP_IRQ_SOFT_GPIO1_START + 3)
#define MX8MP_IRQ_SOFT_GPIO1_3      (MX8MP_IRQ_SOFT_GPIO1_START + 4)
#define MX8MP_IRQ_SOFT_GPIO1_4      (MX8MP_IRQ_SOFT_GPIO1_START + 5)
#define MX8MP_IRQ_SOFT_GPIO1_5      (MX8MP_IRQ_SOFT_GPIO1_START + 6)
#define MX8MP_IRQ_SOFT_GPIO1_6      (MX8MP_IRQ_SOFT_GPIO1_START + 7)
#define MX8MP_IRQ_SOFT_GPIO1_7      (MX8MP_IRQ_SOFT_GPIO1_START + 8)
#define MX8MP_IRQ_SOFT_GPIO1_8      (MX8MP_IRQ_SOFT_GPIO1_START + 9)
#define MX8MP_IRQ_SOFT_GPIO1_9      (MX8MP_IRQ_SOFT_GPIO1_START + 10)
#define MX8MP_IRQ_SOFT_GPIO1_10     (MX8MP_IRQ_SOFT_GPIO1_START + 11)
#define MX8MP_IRQ_SOFT_GPIO1_11     (MX8MP_IRQ_SOFT_GPIO1_START + 12)
#define MX8MP_IRQ_SOFT_GPIO1_12     (MX8MP_IRQ_SOFT_GPIO1_START + 13)
#define MX8MP_IRQ_SOFT_GPIO1_13     (MX8MP_IRQ_SOFT_GPIO1_START + 14)
#define MX8MP_IRQ_SOFT_GPIO1_14     (MX8MP_IRQ_SOFT_GPIO1_START + 15)
#define MX8MP_IRQ_SOFT_GPIO1_15     (MX8MP_IRQ_SOFT_GPIO1_START + 16)
#define MX8MP_IRQ_SOFT_GPIO1_16     (MX8MP_IRQ_SOFT_GPIO1_START + 17)
#define MX8MP_IRQ_SOFT_GPIO1_17     (MX8MP_IRQ_SOFT_GPIO1_START + 18)
#define MX8MP_IRQ_SOFT_GPIO1_18     (MX8MP_IRQ_SOFT_GPIO1_START + 19)
#define MX8MP_IRQ_SOFT_GPIO1_19     (MX8MP_IRQ_SOFT_GPIO1_START + 20)
#define MX8MP_IRQ_SOFT_GPIO1_20     (MX8MP_IRQ_SOFT_GPIO1_START + 21)
#define MX8MP_IRQ_SOFT_GPIO1_21     (MX8MP_IRQ_SOFT_GPIO1_START + 22)
#define MX8MP_IRQ_SOFT_GPIO1_22     (MX8MP_IRQ_SOFT_GPIO1_START + 23)
#define MX8MP_IRQ_SOFT_GPIO1_23     (MX8MP_IRQ_SOFT_GPIO1_START + 24)
#define MX8MP_IRQ_SOFT_GPIO1_24     (MX8MP_IRQ_SOFT_GPIO1_START + 25)
#define MX8MP_IRQ_SOFT_GPIO1_25     (MX8MP_IRQ_SOFT_GPIO1_START + 26)
#define MX8MP_IRQ_SOFT_GPIO1_26     (MX8MP_IRQ_SOFT_GPIO1_START + 27)
#define MX8MP_IRQ_SOFT_GPIO1_27     (MX8MP_IRQ_SOFT_GPIO1_START + 28)
#define MX8MP_IRQ_SOFT_GPIO1_28     (MX8MP_IRQ_SOFT_GPIO1_START + 29)
#define MX8MP_IRQ_SOFT_GPIO1_29     (MX8MP_IRQ_SOFT_GPIO1_START + 30)
#define MX8MP_IRQ_SOFT_GPIO1_30     (MX8MP_IRQ_SOFT_GPIO1_START + 31)
#define MX8MP_IRQ_SOFT_GPIO1_31     (MX8MP_IRQ_SOFT_GPIO1_START + 32)

#define MX8MP_IRQ_SOFT_GPIO2_START     MX8MP_IRQ_SOFT_GPIO1_31

#define MX8MP_IRQ_SOFT_GPIO2_0      (MX8MP_IRQ_SOFT_GPIO2_START + 1)
#define MX8MP_IRQ_SOFT_GPIO2_1      (MX8MP_IRQ_SOFT_GPIO2_START + 2)
#define MX8MP_IRQ_SOFT_GPIO2_2      (MX8MP_IRQ_SOFT_GPIO2_START + 3)
#define MX8MP_IRQ_SOFT_GPIO2_3      (MX8MP_IRQ_SOFT_GPIO2_START + 4)
#define MX8MP_IRQ_SOFT_GPIO2_4      (MX8MP_IRQ_SOFT_GPIO2_START + 5)
#define MX8MP_IRQ_SOFT_GPIO2_5      (MX8MP_IRQ_SOFT_GPIO2_START + 6)
#define MX8MP_IRQ_SOFT_GPIO2_6      (MX8MP_IRQ_SOFT_GPIO2_START + 7)
#define MX8MP_IRQ_SOFT_GPIO2_7      (MX8MP_IRQ_SOFT_GPIO2_START + 8)
#define MX8MP_IRQ_SOFT_GPIO2_8      (MX8MP_IRQ_SOFT_GPIO2_START + 9)
#define MX8MP_IRQ_SOFT_GPIO2_9      (MX8MP_IRQ_SOFT_GPIO2_START + 10)
#define MX8MP_IRQ_SOFT_GPIO2_10     (MX8MP_IRQ_SOFT_GPIO2_START + 11)
#define MX8MP_IRQ_SOFT_GPIO2_11     (MX8MP_IRQ_SOFT_GPIO2_START + 12)
#define MX8MP_IRQ_SOFT_GPIO2_12     (MX8MP_IRQ_SOFT_GPIO2_START + 13)
#define MX8MP_IRQ_SOFT_GPIO2_13     (MX8MP_IRQ_SOFT_GPIO2_START + 14)
#define MX8MP_IRQ_SOFT_GPIO2_14     (MX8MP_IRQ_SOFT_GPIO2_START + 15)
#define MX8MP_IRQ_SOFT_GPIO2_15     (MX8MP_IRQ_SOFT_GPIO2_START + 16)
#define MX8MP_IRQ_SOFT_GPIO2_16     (MX8MP_IRQ_SOFT_GPIO2_START + 17)
#define MX8MP_IRQ_SOFT_GPIO2_17     (MX8MP_IRQ_SOFT_GPIO2_START + 18)
#define MX8MP_IRQ_SOFT_GPIO2_18     (MX8MP_IRQ_SOFT_GPIO2_START + 19)
#define MX8MP_IRQ_SOFT_GPIO2_19     (MX8MP_IRQ_SOFT_GPIO2_START + 20)
#define MX8MP_IRQ_SOFT_GPIO2_20     (MX8MP_IRQ_SOFT_GPIO2_START + 21)
#define MX8MP_IRQ_SOFT_GPIO2_21     (MX8MP_IRQ_SOFT_GPIO2_START + 22)
#define MX8MP_IRQ_SOFT_GPIO2_22     (MX8MP_IRQ_SOFT_GPIO2_START + 23)
#define MX8MP_IRQ_SOFT_GPIO2_23     (MX8MP_IRQ_SOFT_GPIO2_START + 24)
#define MX8MP_IRQ_SOFT_GPIO2_24     (MX8MP_IRQ_SOFT_GPIO2_START + 25)
#define MX8MP_IRQ_SOFT_GPIO2_25     (MX8MP_IRQ_SOFT_GPIO2_START + 26)
#define MX8MP_IRQ_SOFT_GPIO2_26     (MX8MP_IRQ_SOFT_GPIO2_START + 27)
#define MX8MP_IRQ_SOFT_GPIO2_27     (MX8MP_IRQ_SOFT_GPIO2_START + 28)
#define MX8MP_IRQ_SOFT_GPIO2_28     (MX8MP_IRQ_SOFT_GPIO2_START + 29)
#define MX8MP_IRQ_SOFT_GPIO2_29     (MX8MP_IRQ_SOFT_GPIO2_START + 30)
#define MX8MP_IRQ_SOFT_GPIO2_30     (MX8MP_IRQ_SOFT_GPIO2_START + 31)
#define MX8MP_IRQ_SOFT_GPIO2_31     (MX8MP_IRQ_SOFT_GPIO2_START + 32)

#define MX8MP_IRQ_SOFT_GPIO3_START     MX8MP_IRQ_SOFT_GPIO2_31

#define MX8MP_IRQ_SOFT_GPIO3_0      (MX8MP_IRQ_SOFT_GPIO3_START + 1)
#define MX8MP_IRQ_SOFT_GPIO3_1      (MX8MP_IRQ_SOFT_GPIO3_START + 2)
#define MX8MP_IRQ_SOFT_GPIO3_2      (MX8MP_IRQ_SOFT_GPIO3_START + 3)
#define MX8MP_IRQ_SOFT_GPIO3_3      (MX8MP_IRQ_SOFT_GPIO3_START + 4)
#define MX8MP_IRQ_SOFT_GPIO3_4      (MX8MP_IRQ_SOFT_GPIO3_START + 5)
#define MX8MP_IRQ_SOFT_GPIO3_5      (MX8MP_IRQ_SOFT_GPIO3_START + 6)
#define MX8MP_IRQ_SOFT_GPIO3_6      (MX8MP_IRQ_SOFT_GPIO3_START + 7)
#define MX8MP_IRQ_SOFT_GPIO3_7      (MX8MP_IRQ_SOFT_GPIO3_START + 8)
#define MX8MP_IRQ_SOFT_GPIO3_8      (MX8MP_IRQ_SOFT_GPIO3_START + 9)
#define MX8MP_IRQ_SOFT_GPIO3_9      (MX8MP_IRQ_SOFT_GPIO3_START + 10)
#define MX8MP_IRQ_SOFT_GPIO3_10     (MX8MP_IRQ_SOFT_GPIO3_START + 11)
#define MX8MP_IRQ_SOFT_GPIO3_11     (MX8MP_IRQ_SOFT_GPIO3_START + 12)
#define MX8MP_IRQ_SOFT_GPIO3_12     (MX8MP_IRQ_SOFT_GPIO3_START + 13)
#define MX8MP_IRQ_SOFT_GPIO3_13     (MX8MP_IRQ_SOFT_GPIO3_START + 14)
#define MX8MP_IRQ_SOFT_GPIO3_14     (MX8MP_IRQ_SOFT_GPIO3_START + 15)
#define MX8MP_IRQ_SOFT_GPIO3_15     (MX8MP_IRQ_SOFT_GPIO3_START + 16)
#define MX8MP_IRQ_SOFT_GPIO3_16     (MX8MP_IRQ_SOFT_GPIO3_START + 17)
#define MX8MP_IRQ_SOFT_GPIO3_17     (MX8MP_IRQ_SOFT_GPIO3_START + 18)
#define MX8MP_IRQ_SOFT_GPIO3_18     (MX8MP_IRQ_SOFT_GPIO3_START + 19)
#define MX8MP_IRQ_SOFT_GPIO3_19     (MX8MP_IRQ_SOFT_GPIO3_START + 20)
#define MX8MP_IRQ_SOFT_GPIO3_20     (MX8MP_IRQ_SOFT_GPIO3_START + 21)
#define MX8MP_IRQ_SOFT_GPIO3_21     (MX8MP_IRQ_SOFT_GPIO3_START + 22)
#define MX8MP_IRQ_SOFT_GPIO3_22     (MX8MP_IRQ_SOFT_GPIO3_START + 23)
#define MX8MP_IRQ_SOFT_GPIO3_23     (MX8MP_IRQ_SOFT_GPIO3_START + 24)
#define MX8MP_IRQ_SOFT_GPIO3_24     (MX8MP_IRQ_SOFT_GPIO3_START + 25)
#define MX8MP_IRQ_SOFT_GPIO3_25     (MX8MP_IRQ_SOFT_GPIO3_START + 26)
#define MX8MP_IRQ_SOFT_GPIO3_26     (MX8MP_IRQ_SOFT_GPIO3_START + 27)
#define MX8MP_IRQ_SOFT_GPIO3_27     (MX8MP_IRQ_SOFT_GPIO3_START + 28)
#define MX8MP_IRQ_SOFT_GPIO3_28     (MX8MP_IRQ_SOFT_GPIO3_START + 29)
#define MX8MP_IRQ_SOFT_GPIO3_29     (MX8MP_IRQ_SOFT_GPIO3_START + 30)
#define MX8MP_IRQ_SOFT_GPIO3_30     (MX8MP_IRQ_SOFT_GPIO3_START + 31)
#define MX8MP_IRQ_SOFT_GPIO3_31     (MX8MP_IRQ_SOFT_GPIO3_START + 32)

#define MX8MP_IRQ_SOFT_GPIO4_START     MX8MP_IRQ_SOFT_GPIO3_31

#define MX8MP_IRQ_SOFT_GPIO4_0      (MX8MP_IRQ_SOFT_GPIO4_START + 1)
#define MX8MP_IRQ_SOFT_GPIO4_1      (MX8MP_IRQ_SOFT_GPIO4_START + 2)
#define MX8MP_IRQ_SOFT_GPIO4_2      (MX8MP_IRQ_SOFT_GPIO4_START + 3)
#define MX8MP_IRQ_SOFT_GPIO4_3      (MX8MP_IRQ_SOFT_GPIO4_START + 4)
#define MX8MP_IRQ_SOFT_GPIO4_4      (MX8MP_IRQ_SOFT_GPIO4_START + 5)
#define MX8MP_IRQ_SOFT_GPIO4_5      (MX8MP_IRQ_SOFT_GPIO4_START + 6)
#define MX8MP_IRQ_SOFT_GPIO4_6      (MX8MP_IRQ_SOFT_GPIO4_START + 7)
#define MX8MP_IRQ_SOFT_GPIO4_7      (MX8MP_IRQ_SOFT_GPIO4_START + 8)
#define MX8MP_IRQ_SOFT_GPIO4_8      (MX8MP_IRQ_SOFT_GPIO4_START + 9)
#define MX8MP_IRQ_SOFT_GPIO4_9      (MX8MP_IRQ_SOFT_GPIO4_START + 10)
#define MX8MP_IRQ_SOFT_GPIO4_10     (MX8MP_IRQ_SOFT_GPIO4_START + 11)
#define MX8MP_IRQ_SOFT_GPIO4_11     (MX8MP_IRQ_SOFT_GPIO4_START + 12)
#define MX8MP_IRQ_SOFT_GPIO4_12     (MX8MP_IRQ_SOFT_GPIO4_START + 13)
#define MX8MP_IRQ_SOFT_GPIO4_13     (MX8MP_IRQ_SOFT_GPIO4_START + 14)
#define MX8MP_IRQ_SOFT_GPIO4_14     (MX8MP_IRQ_SOFT_GPIO4_START + 15)
#define MX8MP_IRQ_SOFT_GPIO4_15     (MX8MP_IRQ_SOFT_GPIO4_START + 16)
#define MX8MP_IRQ_SOFT_GPIO4_16     (MX8MP_IRQ_SOFT_GPIO4_START + 17)
#define MX8MP_IRQ_SOFT_GPIO4_17     (MX8MP_IRQ_SOFT_GPIO4_START + 18)
#define MX8MP_IRQ_SOFT_GPIO4_18     (MX8MP_IRQ_SOFT_GPIO4_START + 19)
#define MX8MP_IRQ_SOFT_GPIO4_19     (MX8MP_IRQ_SOFT_GPIO4_START + 20)
#define MX8MP_IRQ_SOFT_GPIO4_20     (MX8MP_IRQ_SOFT_GPIO4_START + 21)
#define MX8MP_IRQ_SOFT_GPIO4_21     (MX8MP_IRQ_SOFT_GPIO4_START + 22)
#define MX8MP_IRQ_SOFT_GPIO4_22     (MX8MP_IRQ_SOFT_GPIO4_START + 23)
#define MX8MP_IRQ_SOFT_GPIO4_23     (MX8MP_IRQ_SOFT_GPIO4_START + 24)
#define MX8MP_IRQ_SOFT_GPIO4_24     (MX8MP_IRQ_SOFT_GPIO4_START + 25)
#define MX8MP_IRQ_SOFT_GPIO4_25     (MX8MP_IRQ_SOFT_GPIO4_START + 26)
#define MX8MP_IRQ_SOFT_GPIO4_26     (MX8MP_IRQ_SOFT_GPIO4_START + 27)
#define MX8MP_IRQ_SOFT_GPIO4_27     (MX8MP_IRQ_SOFT_GPIO4_START + 28)
#define MX8MP_IRQ_SOFT_GPIO4_28     (MX8MP_IRQ_SOFT_GPIO4_START + 29)
#define MX8MP_IRQ_SOFT_GPIO4_29     (MX8MP_IRQ_SOFT_GPIO4_START + 30)
#define MX8MP_IRQ_SOFT_GPIO4_30     (MX8MP_IRQ_SOFT_GPIO4_START + 31)
#define MX8MP_IRQ_SOFT_GPIO4_31     (MX8MP_IRQ_SOFT_GPIO4_START + 32)

#define MX8MP_IRQ_SOFT_GPIO5_START     MX8MP_IRQ_SOFT_GPIO4_31

#define MX8MP_IRQ_SOFT_GPIO5_0      (MX8MP_IRQ_SOFT_GPIO5_START + 1)
#define MX8MP_IRQ_SOFT_GPIO5_1      (MX8MP_IRQ_SOFT_GPIO5_START + 2)
#define MX8MP_IRQ_SOFT_GPIO5_2      (MX8MP_IRQ_SOFT_GPIO5_START + 3)
#define MX8MP_IRQ_SOFT_GPIO5_3      (MX8MP_IRQ_SOFT_GPIO5_START + 4)
#define MX8MP_IRQ_SOFT_GPIO5_4      (MX8MP_IRQ_SOFT_GPIO5_START + 5)
#define MX8MP_IRQ_SOFT_GPIO5_5      (MX8MP_IRQ_SOFT_GPIO5_START + 6)
#define MX8MP_IRQ_SOFT_GPIO5_6      (MX8MP_IRQ_SOFT_GPIO5_START + 7)
#define MX8MP_IRQ_SOFT_GPIO5_7      (MX8MP_IRQ_SOFT_GPIO5_START + 8)
#define MX8MP_IRQ_SOFT_GPIO5_8      (MX8MP_IRQ_SOFT_GPIO5_START + 9)
#define MX8MP_IRQ_SOFT_GPIO5_9      (MX8MP_IRQ_SOFT_GPIO5_START + 10)
#define MX8MP_IRQ_SOFT_GPIO5_10     (MX8MP_IRQ_SOFT_GPIO5_START + 11)
#define MX8MP_IRQ_SOFT_GPIO5_11     (MX8MP_IRQ_SOFT_GPIO5_START + 12)
#define MX8MP_IRQ_SOFT_GPIO5_12     (MX8MP_IRQ_SOFT_GPIO5_START + 13)
#define MX8MP_IRQ_SOFT_GPIO5_13     (MX8MP_IRQ_SOFT_GPIO5_START + 14)
#define MX8MP_IRQ_SOFT_GPIO5_14     (MX8MP_IRQ_SOFT_GPIO5_START + 15)
#define MX8MP_IRQ_SOFT_GPIO5_15     (MX8MP_IRQ_SOFT_GPIO5_START + 16)
#define MX8MP_IRQ_SOFT_GPIO5_16     (MX8MP_IRQ_SOFT_GPIO5_START + 17)
#define MX8MP_IRQ_SOFT_GPIO5_17     (MX8MP_IRQ_SOFT_GPIO5_START + 18)
#define MX8MP_IRQ_SOFT_GPIO5_18     (MX8MP_IRQ_SOFT_GPIO5_START + 19)
#define MX8MP_IRQ_SOFT_GPIO5_19     (MX8MP_IRQ_SOFT_GPIO5_START + 20)
#define MX8MP_IRQ_SOFT_GPIO5_20     (MX8MP_IRQ_SOFT_GPIO5_START + 21)
#define MX8MP_IRQ_SOFT_GPIO5_21     (MX8MP_IRQ_SOFT_GPIO5_START + 22)
#define MX8MP_IRQ_SOFT_GPIO5_22     (MX8MP_IRQ_SOFT_GPIO5_START + 23)
#define MX8MP_IRQ_SOFT_GPIO5_23     (MX8MP_IRQ_SOFT_GPIO5_START + 24)
#define MX8MP_IRQ_SOFT_GPIO5_24     (MX8MP_IRQ_SOFT_GPIO5_START + 25)
#define MX8MP_IRQ_SOFT_GPIO5_25     (MX8MP_IRQ_SOFT_GPIO5_START + 26)
#define MX8MP_IRQ_SOFT_GPIO5_26     (MX8MP_IRQ_SOFT_GPIO5_START + 27)
#define MX8MP_IRQ_SOFT_GPIO5_27     (MX8MP_IRQ_SOFT_GPIO5_START + 28)
#define MX8MP_IRQ_SOFT_GPIO5_28     (MX8MP_IRQ_SOFT_GPIO5_START + 29)
#define MX8MP_IRQ_SOFT_GPIO5_29     (MX8MP_IRQ_SOFT_GPIO5_START + 30)
#define MX8MP_IRQ_SOFT_GPIO5_30     (MX8MP_IRQ_SOFT_GPIO5_START + 31)
#define MX8MP_IRQ_SOFT_GPIO5_31     (MX8MP_IRQ_SOFT_GPIO5_START + 32)

#define MX8MP_IRQ_SOFT_GPIO_END     MX8MP_IRQ_SOFT_GPIO5_31

#define NR_IRQS                     (MX8MP_IRQ_NVECTORS + MX8MP_IRQ_SOFT_GPIO_END)

#endif /* ARCH_ARM_INCLUDE_MX8MP_IRQ_H */
