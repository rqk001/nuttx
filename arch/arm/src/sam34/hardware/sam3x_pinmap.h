/************************************************************************************
 * arch/arm/src/sam34/hardware/sam3x_pinmap.h
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

#ifndef __ARCH_ARM_SRC_SAM34_HARDWARE_SAM3X_PINMAP_H
#define __ARCH_ARM_SRC_SAM34_HARDWARE_SAM3X_PINMAP_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

#include "chip.h"
#include "sam_gpio.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* GPIO pin definitions *************************************************************/
/* Alternate Pin Functions.
 *
 * Alternative pin selections are provided with a numeric suffix like _1, _2, etc.
 * Drivers, however, will use the pin selection without the numeric suffix.
 * Additional definitions are required in the board.h file.  For example, if we
 * wanted the PWM0 Output high on PE15, then the following definition should appear
 * in the board.h header file for that board:
 *
 * #define GPIO_PWM0_H GPIO_PWM0_H_1
 *
 * The driver will then automatically configure RE15 as the PWM0 H pin.
 */

/* WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!!
 * Additional effort is required to select specific GPIO options such as frequency,
 * open-drain/push-pull, and pull-up/down!  Just the basics are defined for most
 * pins in this file.
 */

/* 12-bit Analog-to-Digital Conververt (ADC) */

#define GPIO_ADC0_AD0      (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN2)
#define GPIO_ADC0_AD1      (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN3)
#define GPIO_ADC0_AD2      (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN4)
#define GPIO_ADC0_AD3      (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN6)
#define GPIO_ADC0_AD4      (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN22)
#define GPIO_ADC0_AD5      (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN23)
#define GPIO_ADC0_AD6      (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN24)
#define GPIO_ADC0_AD7      (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN16)
#define GPIO_ADC0_AD8      (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN12)
#define GPIO_ADC0_AD9      (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN13)
#define GPIO_ADC0_AD10     (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN17)
#define GPIO_ADC0_AD11     (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN18)
#define GPIO_ADC0_AD12     (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN19)
#define GPIO_ADC0_AD13     (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN20)
#define GPIO_ADC0_AD14     (GPIO_INPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN21)
#define GPIO_ADC0_ADTRG    (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN11)

/* Digital-to-Analog Convert (DAC) */

#define GPIO_DAC0          (GPIO_OUTPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN15)
#define GPIO_DAC1          (GPIO_OUTPUT | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN16)
#define GPIO_DATRG         (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN10)

/* CAN */

#define GPIO_CAN0_RX       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN1)
#define GPIO_CAN0_TX       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN0)
#define GPIO_CAN1_RX       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN15)
#define GPIO_CAN1_TX       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN14)

/* Ethernet MAC */

#define GPIO_EMAC_COL      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN13)
#define GPIO_EMAC_CRS      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN10)
#define GPIO_EMAC_CRSDV    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN4)
#define GPIO_EMAC_MDC      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN8)
#define GPIO_EMAC_MDIO     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN9)
#define GPIO_EMAC_REFCK    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN0)
#define GPIO_EMAC_RX0      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN5)
#define GPIO_EMAC_RX1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN6)
#define GPIO_EMAC_RX2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN11)
#define GPIO_EMAC_RX3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN12)
#define GPIO_EMAC_RXCK     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN14)
#define GPIO_EMAC_RXDV     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN4)
#define GPIO_EMAC_RXER     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN7)
#define GPIO_EMAC_TX0      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN2)
#define GPIO_EMAC_TX1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN3)
#define GPIO_EMAC_TX2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN15)
#define GPIO_EMAC_TX3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN16)
#define GPIO_EMAC_TXCK     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN0)
#define GPIO_EMAC_TXEN     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN1)
#define GPIO_EMAC_TXER     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN17)

/* High-Speed Multimedia Card Interface (HSMCI) */

#define GPIO_HSMCIA_CD     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN20)
#define GPIO_HSMCIA_DAT0   (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN21)
#define GPIO_HSMCIA_DAT1   (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN22)
#define GPIO_HSMCIA_DAT2   (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN23)
#define GPIO_HSMCIA_DAT3   (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN24)
#define GPIO_HSMCIA_DAT4   (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN0)
#define GPIO_HSMCIA_DAT5   (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN1)
#define GPIO_HSMCIA_DAT6   (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN2)
#define GPIO_HSMCIA_DAT7   (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN3)
#define GPIO_HSMCIB_CD     (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN20)
#define GPIO_HSMCIB_DAT0   (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN22)
#define GPIO_HSMCIB_DAT1   (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN24)
#define GPIO_HSMCIB_DAT2   (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN26)
#define GPIO_HSMCIB_DAT3   (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN27)
#define GPIO_HSMCI_CK      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN19)

/* Programmable Clock Output */

#define GPIO_PCK0_1        (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN1)
#define GPIO_PCK0_2        (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN22)
#define GPIO_PCK1_1        (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN24)
#define GPIO_PCK1_2        (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN30)
#define GPIO_PCK2_1        (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN28)
#define GPIO_PCK2_2        (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN31)

/* Pulse Width Modulation (PWM) */

#define GPIO_PWM0_FI       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN5)
#define GPIO_PWM0_H_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN15)
#define GPIO_PWM0_H_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN8)
#define GPIO_PWM0_H_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN12)
#define GPIO_PWM0_H_4      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN3)
#define GPIO_PWM0_L_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN18)
#define GPIO_PWM0_L_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN21)
#define GPIO_PWM0_L_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN16)
#define GPIO_PWM0_L_4      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN2)
#define GPIO_PWM1_FI       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN3)
#define GPIO_PWM1_H_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN16)
#define GPIO_PWM1_H_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN19)
#define GPIO_PWM1_H_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN13)
#define GPIO_PWM1_H_4      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN5)
#define GPIO_PWM1_L_1      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN12)
#define GPIO_PWM1_L_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN17)
#define GPIO_PWM1_L_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN4)
#define GPIO_PWM2_FI       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN6)
#define GPIO_PWM2_H_1      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN13)
#define GPIO_PWM2_H_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN14)
#define GPIO_PWM2_H_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN7)
#define GPIO_PWM2_L_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN17)
#define GPIO_PWM2_L_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN20)
#define GPIO_PWM2_L_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN18)
#define GPIO_PWM2_L_4      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN6)
#define GPIO_PWM3_H_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOF | GPIO_PIN3)
#define GPIO_PWM3_H_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN9)
#define GPIO_PWM3_H_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN15)
#define GPIO_PWM3_H_4      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN9)
#define GPIO_PWM3_L_1      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN0)
#define GPIO_PWM3_L_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN19)
#define GPIO_PWM3_L_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN8)
#define GPIO_PWM4_H_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN20)
#define GPIO_PWM4_H_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN20)
#define GPIO_PWM4_L_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN19)
#define GPIO_PWM4_L_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN6)
#define GPIO_PWM4_L_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN21)
#define GPIO_PWM5_H_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN22)
#define GPIO_PWM5_H_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN19)
#define GPIO_PWM5_L_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN21)
#define GPIO_PWM5_L_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN7)
#define GPIO_PWM5_L_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN22)
#define GPIO_PWM6_H_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN24)
#define GPIO_PWM6_H_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN18)
#define GPIO_PWM6_L_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN23)
#define GPIO_PWM6_L_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN8)
#define GPIO_PWM6_L_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN23)
#define GPIO_PWM7_H        (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN26)
#define GPIO_PWM7_L_1      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN25)
#define GPIO_PWM7_L_2      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN9)
#define GPIO_PWM7_L_3      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN24)

/* Static Memory Controller (SMC) */

#define GPIO_SMC_A0        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN21)
#define GPIO_SMC_A1        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN22)
#define GPIO_SMC_A2        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN23)
#define GPIO_SMC_A3        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN24)
#define GPIO_SMC_A4        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN25)
#define GPIO_SMC_A5_1      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN26)
#define GPIO_SMC_A5_2      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN17)
#define GPIO_SMC_A6_1      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN27)
#define GPIO_SMC_A6_2      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN18)
#define GPIO_SMC_A7_1      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN28)
#define GPIO_SMC_A7_2      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN19)
#define GPIO_SMC_A8_1      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN29)
#define GPIO_SMC_A8_2      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN20)
#define GPIO_SMC_A9_1      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN30)
#define GPIO_SMC_A9_2      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN21)
#define GPIO_SMC_A10_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN0)
#define GPIO_SMC_A10_2     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN22)
#define GPIO_SMC_A11_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN1)
#define GPIO_SMC_A11_2     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN23)
#define GPIO_SMC_A12_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN2)
#define GPIO_SMC_A12_2     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN24)
#define GPIO_SMC_A13_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN25)
#define GPIO_SMC_A13_2     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN3)
#define GPIO_SMC_A14_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN26)
#define GPIO_SMC_A14_2     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN4)
#define GPIO_SMC_A15_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN27)
#define GPIO_SMC_A15_2     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN5)
#define GPIO_SMC_A16_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN28)
#define GPIO_SMC_A16_2     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN6)
#define GPIO_SMC_A17_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN29)
#define GPIO_SMC_A17_2     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN7)
#define GPIO_SMC_A18_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN30)
#define GPIO_SMC_A18_2     (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN25)
#define GPIO_SMC_A18_3     (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOB | GPIO_PIN10)
#define GPIO_SMC_A19_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN0)
#define GPIO_SMC_A19_2     (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN26)
#define GPIO_SMC_A19_3     (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOB | GPIO_PIN11)
#define GPIO_SMC_A20_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN1)
#define GPIO_SMC_A20_2     (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN18)
#define GPIO_SMC_A20_3     (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN27)
#define GPIO_SMC_A21_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN8)
#define GPIO_SMC_A21_2     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN2)
#define GPIO_SMC_A22_1     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN9)
#define GPIO_SMC_A22_2     (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN3)
#define GPIO_SMC_A23       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN4)
#define GPIO_SMC_D0        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN2)
#define GPIO_SMC_D1        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN3)
#define GPIO_SMC_D2        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN4)
#define GPIO_SMC_D3        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN5)
#define GPIO_SMC_D4        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN6)
#define GPIO_SMC_D5        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN7)
#define GPIO_SMC_D6        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN8)
#define GPIO_SMC_D7        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN9)
#define GPIO_SMC_D8        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN10)
#define GPIO_SMC_D9        (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN11)
#define GPIO_SMC_D10       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN12)
#define GPIO_SMC_D11       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN13)
#define GPIO_SMC_D12       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN14)
#define GPIO_SMC_D13       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN15)
#define GPIO_SMC_D14       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN16)
#define GPIO_SMC_D15       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN17)
#define GPIO_SMC_NCS0      (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN6)
#define GPIO_SMC_NCS1      (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN7)
#define GPIO_SMC_NCS2      (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOB | GPIO_PIN24)
#define GPIO_SMC_NCS3      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOB | GPIO_PIN27)
#define GPIO_SMC_NCS4      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN5)
#define GPIO_SMC_NCS5      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN6)
#define GPIO_SMC_NCS6      (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN18)
#define GPIO_SMC_NCS7      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOE | GPIO_PIN27)
#define GPIO_SMC_NRD       (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN29)
#define GPIO_SMC_NWAIT     (GPIO_PERIPHB | GPIO_CFG_PULLUP | GPIO_PORT_PIOA | GPIO_PIN4)
#define GPIO_SMC_NWE       (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN18)
#define GPIO_SMC_NWR0      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOC | GPIO_PIN18)
#define GPIO_SMC_NWR1      (GPIO_PERIPHA | GPIO_CFG_PULLUP | GPIO_PORT_PIOD | GPIO_PIN10)

/* NAND Interface */

#define GPIO_NAND_ALE_1    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN8)
#define GPIO_NAND_ALE_2    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN2)
#define GPIO_NAND_CLE_1    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN9)
#define GPIO_NAND_CLE_2    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN3)
#define GPIO_NAND_OE       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN19)
#define GPIO_NAND_RDY      (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN2)
#define GPIO_NAND_WE       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN20)

/* SDRAM Controller */

#define GPIO_SDRAM_BA0_1   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN28)
#define GPIO_SDRAM_BA0_2   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN6)
#define GPIO_SDRAM_BA1_1   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN29)
#define GPIO_SDRAM_BA1_2   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN7)
#define GPIO_SDRAM_CAS     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN16)
#define GPIO_SDRAM_NBS0    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN21)
#define GPIO_SDRAM_NBS1    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN10)
#define GPIO_SDRAM_RAS     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN15)
#define GPIO_SDRAM_SDA10   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN11)
#define GPIO_SDRAM_SDCKE   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN13)
#define GPIO_SDRAM_SDCS    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN12)
#define GPIO_SDRAM_SDWE    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN14)

/* Serial Peripheral Interface (SPI) */

#define GPIO_SPI0_MISO     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN25)
#define GPIO_SPI0_MOSI     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN26)
#define GPIO_SPI0_NPCS0    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN28)
#define GPIO_SPI0_NPCS1_1  (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN29)
#define GPIO_SPI0_NPCS1_2  (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN20)
#define GPIO_SPI0_NPCS2_1  (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN30)
#define GPIO_SPI0_NPCS2_2  (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN21)
#define GPIO_SPI0_NPCS3_1  (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN31)
#define GPIO_SPI0_NPCS3_2  (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN23)
#define GPIO_SPI0_SPCK_1   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN27)
#define GPIO_SPI0_SPCK_2   (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN17)
#define GPIO_SPI1_MISO     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN28)
#define GPIO_SPI1_MOSI     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN29)
#define GPIO_SPI1_NPCS0    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN31)
#define GPIO_SPI1_NPCS1    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOF | GPIO_PIN0)
#define GPIO_SPI1_NPCS2    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOF | GPIO_PIN1)
#define GPIO_SPI1_NPCS3    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOF | GPIO_PIN2)
#define GPIO_SPI1_SPCK_1   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN16)
#define GPIO_SPI1_SPCK_2   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN30)

/* Synchronous Serial Controller (SSC) */

#define GPIO_SSC_RD        (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN18)
#define GPIO_SSC_RF        (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN17)
#define GPIO_SSC_RK        (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN19)
#define GPIO_SSC_TD        (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN16)
#define GPIO_SSC_TF        (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN15)
#define GPIO_SSC_TK        (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN14)

/* Timer/Counters (TC) */

#define GPIO_TC0_CLK       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN26)
#define GPIO_TC0_IOA       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN25)
#define GPIO_TC0_IOB       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN27)
#define GPIO_TC1_CLK       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN4)
#define GPIO_TC1_IOA       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN2)
#define GPIO_TC1_IOB       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN3)
#define GPIO_TC2_CLK       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN7)
#define GPIO_TC2_IOA       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN5)
#define GPIO_TC2_IOB       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN6)
#define GPIO_TC3_CLK       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN22)
#define GPIO_TC3_IOA_1     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN9)
#define GPIO_TC3_IOA_2     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN0)
#define GPIO_TC3_IOB_1     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN10)
#define GPIO_TC3_IOB_2     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN1)
#define GPIO_TC4_CLK       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN23)
#define GPIO_TC4_IOA_1     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN11)
#define GPIO_TC4_IOA_2     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN2)
#define GPIO_TC4_IOB_1     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN12)
#define GPIO_TC4_IOB_2     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN3)
#define GPIO_TC5_CLK       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN16)
#define GPIO_TC5_IOA_1     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN13)
#define GPIO_TC5_IOA_2     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN4)
#define GPIO_TC5_IOB_1     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN14)
#define GPIO_TC5_IOB_2     (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN5)
#define GPIO_TC6_CLK       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN27)
#define GPIO_TC6_IOA       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN25)
#define GPIO_TC6_IOB       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN26)
#define GPIO_TC7_CLK       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN30)
#define GPIO_TC7_IOA       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN28)
#define GPIO_TC7_IOB       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOC | GPIO_PIN29)
#define GPIO_TC8_CLK       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN9)
#define GPIO_TC8_IOA       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN7)
#define GPIO_TC8_IOB       (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN8)

/* Two Wire Interface (TWI) */

#define GPIO_TWI0_CK       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN18)
#define GPIO_TWI0_D        (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN17)
#define GPIO_TWI1_CK       (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN13)
#define GPIO_TWI1_D        (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN12)

/* Universal Asynchronous Receiver Transceiver (UART) */

#define GPIO_UART0_RXD     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN8)
#define GPIO_UART0_TXD     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN9)

/* Universal Synchronous Asynchronous Receiver Transmitter (USART) */

#define GPIO_USART0_CTS    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN26)
#define GPIO_USART0_RTS    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN25)
#define GPIO_USART0_RXD    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN10)
#define GPIO_USART0_TXD    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN11)
#define GPIO_USART1_CTS    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN15)
#define GPIO_USART1_RTS    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN14)
#define GPIO_USART1_RXD    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN12)
#define GPIO_USART1_TXD    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOA | GPIO_PIN13)
#define GPIO_USART2_CTS    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN23)
#define GPIO_USART2_RTS    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN22)
#define GPIO_USART2_RXD    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN21)
#define GPIO_USART2_SCK    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN24)
#define GPIO_USART2_TXD    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN20)
#define GPIO_USART3_CTS    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOF | GPIO_PIN4)
#define GPIO_USART3_RTS    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOF | GPIO_PIN5)
#define GPIO_USART3_RXD    (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN5)
#define GPIO_USART3_SCK    (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOE | GPIO_PIN16)
#define GPIO_USART3_TXD    (GPIO_PERIPHB | GPIO_CFG_DEFAULT | GPIO_PORT_PIOD | GPIO_PIN4)

/* USB OTG High Speed */

#define GPIO_USBOTGHS_ID   (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN11)
#define GPIO_USBOTGHS_VBOF (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN10)

/* Debug */

#define GPIO_JTAG_TCK      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN28)
#define GPIO_JTAG_TDI      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN29_|
#define GPIO_JTAG_TDO      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN30)
#define GPIO_JTAG_TMS      (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN31)

#define GPIO_SWI_SSWCLK    (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN28)
#define GPIO_SWI_SWDIO     (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN31)
#define GPIO_SWI_TRACESWO  (GPIO_PERIPHA | GPIO_CFG_DEFAULT | GPIO_PORT_PIOB | GPIO_PIN30)

/************************************************************************************
 * Public Types
 ************************************************************************************/

/************************************************************************************
 * Inline Functions
 ************************************************************************************/

#ifndef __ASSEMBLY__

/************************************************************************************
 * Public Data
 ************************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/************************************************************************************
 * Public Function Prototypes
 ************************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_SAM34_HARDWARE_SAM3X_PINMAP_H */
