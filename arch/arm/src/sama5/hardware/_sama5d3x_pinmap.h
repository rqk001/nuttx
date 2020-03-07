/************************************************************************************************************
 * arch/arm/src/sama5/hardware/_sama5d3x_pinmap.h
 *
 *   Copyright (C) 2013 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************************************/

#ifndef __ARCH_ARM_SRC_SAMA5_HARDWARE__SAMA5D3X_PINMAP_H
#define __ARCH_ARM_SRC_SAMA5_HARDWARE__SAMA5D3X_PINMAP_H

/************************************************************************************************************
 * Included Files
 ************************************************************************************************************/

#include <nuttx/config.h>

#include "chip.h"
#include "sam_pio.h"

/************************************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************************************/

/* PIO pin definitions **************************************************************************************/
/* Alternate Pin Functions.
 *
 * Alternative pin selections are provided with a numeric suffix like _1, _2, etc.  Drivers, however, will
 * use the pin selection without the numeric suffix.  Additional definitions are required in the board.h
 * file.  For example, if we wanted the LCD data bit 16 on PA16, then the following definition should appear
 * in the board.h header file for that board:
 *
 *   #define PIO_LCD_DAT16 PIO_LCD_DAT16_1
 *
 * The LCD driver will then automatically configure PA16 as the DAT16 pin.
 */

/* WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!!
 * Additional effort is required to select specific PIO options such as frequency, open-drain/push-pull,
 * and pull-up/down!  Just the basics are defined for most pins in this file at the present time.
 */

/* Touch Screen Analog-to-Digital Converter - ADC */

#define PIO_ADC_AD0       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN20) /* Type: GPIO_ANA */
#define PIO_ADC_AD1       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN21) /* Type: GPIO_ANA */
#define PIO_ADC_AD2       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN22) /* Type: GPIO_ANA */
#define PIO_ADC_AD3       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN23) /* Type: GPIO_ANA */
#define PIO_ADC_AD4       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN24) /* Type: GPIO_ANA */
#define PIO_ADC_AD5       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN25) /* Type: GPIO_ANA */
#define PIO_ADC_AD6       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN26) /* Type: GPIO_ANA */
#define PIO_ADC_AD7       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN27) /* Type: GPIO_ANA */
#define PIO_ADC_AD8       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN28) /* Type: GPIO_ANA */
#define PIO_ADC_AD9       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN29) /* Type: GPIO_ANA */
#define PIO_ADC_AD10      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN30) /* Type: GPIO_ANA */
#define PIO_ADC_AD11      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN31) /* Type: GPIO_ANA */
#define PIO_ADC_TRG       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN19) /* Type: GPIO */

/* Advanced Interrupt Controller - AIC */

#define PIO_AIC_FIQ       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN31) /* Type: GPIO */
#define PIO_AIC_IRQ       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN31) /* Type: EBI */

/* CAN controller - CANx */

#define PIO_CAN0_RX       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN14) /* Type: GPIO */
#define PIO_CAN0_TX       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN15) /* Type: GPIO */

#define PIO_CAN1_RX       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN14) /* Type: GMAC */
#define PIO_CAN1_TX       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN15) /* Type: GMAC */

/* Debug Unit - DBGU */

#define PIO_DBGU_DRXD     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN30) /* Type: GPIO */
#define PIO_DBGU_DTXD     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN31) /* Type: GPIO */

/* External Bus Interface - EBI */

#define PIO_EBI_A0        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN0)  /* Type: EBI */
#define PIO_EBI_A1        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN1)  /* Type: EBI */
#define PIO_EBI_A10       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN10) /* Type: EBI */
#define PIO_EBI_A11       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN11) /* Type: EBI */
#define PIO_EBI_A12       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN12) /* Type: EBI */
#define PIO_EBI_A13       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN13) /* Type: EBI */
#define PIO_EBI_A14       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN14) /* Type: EBI */
#define PIO_EBI_A15       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN15) /* Type: EBI */
#define PIO_EBI_A16       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN16) /* Type: EBI */
#define PIO_EBI_A17       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN17) /* Type: EBI */
#define PIO_EBI_A18       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN18) /* Type: EBI */
#define PIO_EBI_A19       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN19) /* Type: EBI */
#define PIO_EBI_A2        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN2)  /* Type: EBI */
#define PIO_EBI_A20       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN20) /* Type: EBI */
#define PIO_EBI_A21       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN21) /* Type: EBI */
#define PIO_EBI_A22       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN22) /* Type: EBI */
#define PIO_EBI_A23       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN23) /* Type: EBI */
#define PIO_EBI_A24       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN24) /* Type: EBI */
#define PIO_EBI_A25       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN25) /* Type: EBI */
#define PIO_EBI_A3        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN3)  /* Type: EBI */
#define PIO_EBI_A4        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN4)  /* Type: EBI */
#define PIO_EBI_A5        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN5)  /* Type: EBI */
#define PIO_EBI_A6        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN6)  /* Type: EBI */
#define PIO_EBI_A7        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN7)  /* Type: EBI */
#define PIO_EBI_A8        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN8)  /* Type: EBI */
#define PIO_EBI_A9        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN9)  /* Type: EBI */
#define PIO_EBI_NWAIT     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN30) /* Type: EBI */

/* RMII Ethernet 10/100 - EMAC */

#define PIO_EMAC_CRSDV    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN5)  /* Type: GPIO */
#define PIO_EMAC_MDC      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN8)  /* Type: GPIO */
#define PIO_EMAC_MDIO     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN9)  /* Type: GPIO */
#define PIO_EMAC_REFCK    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN7)  /* Type: GPIO */
#define PIO_EMAC_RX0      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN2)  /* Type: GPIO */
#define PIO_EMAC_RX1      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN3)  /* Type: GPIO */
#define PIO_EMAC_RXER     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN6)  /* Type: GPIO */
#define PIO_EMAC_TX0      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN0)  /* Type: GPIO */
#define PIO_EMAC_TX1      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN1)  /* Type: GPIO */
#define PIO_EMAC_TXEN     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN4)  /* Type: GPIO */

/* GIgabit Ethernet 10/100/1000 - GMAC */

#define PIO_GMAC_125CK    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN18) /* Type: GMAC */
#define PIO_GMAC_125CKO   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN27) /* Type: GPIO */
#define PIO_GMAC_COL      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN15) /* Type: GMAC */
#define PIO_GMAC_CRS      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN14) /* Type: GMAC */
#define PIO_GMAC_MDC      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN16) /* Type: GMAC */
#define PIO_GMAC_MDIO     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN17) /* Type: GMAC */
#define PIO_GMAC_RX0      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN4)  /* Type: GMAC */
#define PIO_GMAC_RX1      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN5)  /* Type: GMAC */
#define PIO_GMAC_RX2      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN6)  /* Type: GMAC */
#define PIO_GMAC_RX3      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN7)  /* Type: GMAC */
#define PIO_GMAC_RX4      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN23) /* Type: GMAC */
#define PIO_GMAC_RX5      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN24) /* Type: GMAC */
#define PIO_GMAC_RX6      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN25) /* Type: GMAC */
#define PIO_GMAC_RX7      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN26) /* Type: GMAC */
#define PIO_GMAC_RXCK     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN11) /* Type: GMAC */
#define PIO_GMAC_RXDV     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN12) /* Type: GMAC */
#define PIO_GMAC_RXER     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN13) /* Type: GMAC */
#define PIO_GMAC_TX0      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN0)  /* Type: GMAC */
#define PIO_GMAC_TX1      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN1)  /* Type: GMAC */
#define PIO_GMAC_TX2      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN2)  /* Type: GMAC */
#define PIO_GMAC_TX3      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN3)  /* Type: GMAC */
#define PIO_GMAC_TX4      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN19) /* Type: GMAC */
#define PIO_GMAC_TX5      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN20) /* Type: GMAC */
#define PIO_GMAC_TX6      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN21) /* Type: GMAC */
#define PIO_GMAC_TX7      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN22) /* Type: GMAC */
#define PIO_GMAC_TXCK     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN8)  /* Type: GMAC */
#define PIO_GMAC_TXEN     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN9)  /* Type: GMAC */
#define PIO_GMAC_TXER     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN10) /* Type: GMAC */

/* Static Memory Controller - HSMC */

#define PIO_HSMC_NANDALE  (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN21) /* Type: EBI */
#define PIO_HSMC_NANDCLE  (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN22) /* Type: EBI */
#define PIO_HSMC_NBS0     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN0)  /* Type: EBI */
#define PIO_HSMC_NBS1     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN29) /* Type: EBI */
#define PIO_HSMC_NCS0     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN26) /* Type: EBI */
#define PIO_HSMC_NCS1     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN27) /* Type: EBI */
#define PIO_HSMC_NCS2     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN28) /* Type: EBI */
#define PIO_HSMC_NWR1     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN29) /* Type: EBI */

/* Image Sensor Interface - ISI */

#define PIO_ISI_D0        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN16) /* Type: GPIO */
#define PIO_ISI_D1        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN17) /* Type: GPIO */
#define PIO_ISI_D2        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN18) /* Type: GPIO */
#define PIO_ISI_D3        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN19) /* Type: GPIO */
#define PIO_ISI_D4        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN20) /* Type: GPIO */
#define PIO_ISI_D5        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN21) /* Type: GPIO */
#define PIO_ISI_D6        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN22) /* Type: GPIO */
#define PIO_ISI_D7        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN23) /* Type: GPIO */
#define PIO_ISI_D8        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN29) /* Type: GPIO */
#define PIO_ISI_D9        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN28) /* Type: GPIO */
#define PIO_ISI_D10       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN27) /* Type: GPIO */
#define PIO_ISI_D11       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN26) /* Type: GPIO */
#define PIO_ISI_HSYNC     (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN31) /* Type: GPIO */
#define PIO_ISI_PCK       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN30) /* Type: GPIO */
#define PIO_ISI_VSYNC     (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN30) /* Type: GPIO */

/* LCD Controller - LCDC */

#define PIO_LCD_DAT0      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN0)  /* Type: GPIO */
#define PIO_LCD_DAT2      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN2)  /* Type: GPIO */
#define PIO_LCD_DAT1      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN1)  /* Type: GPIO */
#define PIO_LCD_DAT3      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN3)  /* Type: GPIO */
#define PIO_LCD_DAT4      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN4)  /* Type: GPIO */
#define PIO_LCD_DAT5      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN5)  /* Type: GPIO */
#define PIO_LCD_DAT6      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN6)  /* Type: GPIO */
#define PIO_LCD_DAT7      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN7)  /* Type: GPIO */
#define PIO_LCD_DAT8      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN8)  /* Type: GPIO */
#define PIO_LCD_DAT9      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN9)  /* Type: GPIO */
#define PIO_LCD_DAT10     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN10) /* Type: GPIO */
#define PIO_LCD_DAT11     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN11) /* Type: GPIO */
#define PIO_LCD_DAT12     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN12) /* Type: GPIO */
#define PIO_LCD_DAT13     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN13) /* Type: GPIO */
#define PIO_LCD_DAT14     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN14) /* Type: GPIO */
#define PIO_LCD_DAT15     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN15) /* Type: GPIO */
#define PIO_LCD_DAT16_1   (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN16) /* Type: GPIO */
#define PIO_LCD_DAT16_2   (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN14) /* Type: GPIO */
#define PIO_LCD_DAT17_1   (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN17) /* Type: GPIO */
#define PIO_LCD_DAT17_2   (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN13) /* Type: GPIO */
#define PIO_LCD_DAT18_1   (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN18) /* Type: GPIO */
#define PIO_LCD_DAT18_2   (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN12) /* Type: GPIO */
#define PIO_LCD_DAT19_1   (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN19) /* Type: GPIO */
#define PIO_LCD_DAT19_2   (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN11) /* Type: GPIO */
#define PIO_LCD_DAT20_1   (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN20) /* Type: GPIO */
#define PIO_LCD_DAT20_2   (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN10) /* Type: GPIO */
#define PIO_LCD_DAT21_1   (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN21) /* Type: GPIO */
#define PIO_LCD_DAT21_2   (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN15) /* Type: MCI_CLK */
#define PIO_LCD_DAT22_1   (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN27) /* Type: EBI */
#define PIO_LCD_DAT22_2   (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN22) /* Type: GPIO */
#define PIO_LCD_DAT23_1   (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN28) /* Type: EBI */
#define PIO_LCD_DAT23_2   (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN23) /* Type: GPIO */
#define PIO_LCD_DEN       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN29) /* Type: GPIO */
#define PIO_LCD_DISP      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN25) /* Type: GPIO */
#define PIO_LCD_HSYNC     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN27) /* Type: GPIO */
#define PIO_LCD_PCK       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN28) /* Type: GPIO_CLK2 */
#define PIO_LCD_PWM       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN24) /* Type: GPIO */
#define PIO_LCD_VSYNC     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN26) /* Type: GPIO */

/* High Speed Multimedia Card Interface - HSMCI0-2 */

#define PIO_MCI0_CDA      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN0)  /* Type: GPIO */
#define PIO_MCI0_CK       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN9)  /* Type: MCI_CLK */
#define PIO_MCI0_DA0      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN1)  /* Type: GPIO */
#define PIO_MCI0_DA1      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN2)  /* Type: GPIO */
#define PIO_MCI0_DA2      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN3)  /* Type: GPIO */
#define PIO_MCI0_DA3      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN4)  /* Type: GPIO */
#define PIO_MCI0_DA4      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN5)  /* Type: GPIO */
#define PIO_MCI0_DA5      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN6)  /* Type: GPIO */
#define PIO_MCI0_DA6      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN7)  /* Type: GPIO */
#define PIO_MCI0_DA7      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN8)  /* Type: GPIO */

#define PIO_MCI1_CDA      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN19) /* Type: GMAC */
#define PIO_MCI1_CK       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN24) /* Type: GMAC */
#define PIO_MCI1_DA0      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN20) /* Type: GMAC */
#define PIO_MCI1_DA1      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN21) /* Type: GMAC */
#define PIO_MCI1_DA2      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN22) /* Type: GMAC */
#define PIO_MCI1_DA3      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN23) /* Type: GMAC */

#define PIO_MCI2_CDA      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN10) /* Type: GPIO */
#define PIO_MCI2_CK       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN15) /* Type: MCI_CLK */
#define PIO_MCI2_DA0      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN11) /* Type: GPIO */
#define PIO_MCI2_DA1      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN12) /* Type: GPIO */
#define PIO_MCI2_DA2      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN13) /* Type: GPIO */
#define PIO_MCI2_DA3      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN14) /* Type: GPIO */

/* Clocks, Oscillators and PLLs */

#define PIO_PMC_PCK0      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN30) /* Type: GPIO_ANA */
#define PIO_PMC_PCK1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN31) /* Type: GPIO_ANA */
#define PIO_PMC_PCK2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN15) /* Type: MCI_CLK */

/* Pulse Width Modulation Controller- PWMC */

#define PIO_PWM0_FI       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN28) /* Type: GPIO */
#define PIO_PWM0_H_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN0)  /* Type: GMAC */
#define PIO_PWM0_H_2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN20) /* Type: GPIO */
#define PIO_PWM0_L_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN1)  /* Type: GMAC */
#define PIO_PWM0_L_2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN21) /* Type: GPIO */

#define PIO_PWM1_FI       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN31) /* Type: GPIO */
#define PIO_PWM1_H_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN4)  /* Type: GMAC */
#define PIO_PWM1_H_2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN22) /* Type: GPIO */
#define PIO_PWM1_L_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN5)  /* Type: GMAC */
#define PIO_PWM1_L_2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN31) /* Type: EBI */
#define PIO_PWM1_L_3      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN23) /* Type: GPIO */

#define PIO_PWM2_FI       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN29) /* Type: GPIO */
#define PIO_PWM2_H_1      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN5)  /* Type: GPIO */
#define PIO_PWM2_H_2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN8)  /* Type: GMAC */
#define PIO_PWM2_L_1      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN6)  /* Type: GPIO */
#define PIO_PWM2_L_2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN9)  /* Type: GMAC */

#define PIO_PWM3_FI       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN16) /* Type: GPIO */
#define PIO_PWM3_H_1      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN7)  /* Type: GPIO */
#define PIO_PWM3_H_2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN12) /* Type: GMAC */
#define PIO_PWM3_L_1      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN8)  /* Type: GPIO */
#define PIO_PWM3_L_2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN13) /* Type: GMAC */

/* Serial Peripheral Interface - SPIx [1..0] */

#define PIO_SPI0_MISO     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN10) /* Type: GPIO */
#define PIO_SPI0_MOSI     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN11) /* Type: GPIO */
#define PIO_SPI0_NPCS0    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN13) /* Type: GPIO */
#define PIO_SPI0_NPCS1    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN14) /* Type: GPIO */
#define PIO_SPI0_NPCS2    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN15) /* Type: GPIO */
#define PIO_SPI0_NPCS3    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN16) /* Type: GPIO */
#define PIO_SPI0_SPCK     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN12) /* Type: GPIO_CLK */

#define PIO_SPI1_MISO     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN22) /* Type: GPIO */
#define PIO_SPI1_MOSI     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN23) /* Type: GPIO */
#define PIO_SPI1_NPCS0    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN25) /* Type: GPIO */
#define PIO_SPI1_NPCS1    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN26) /* Type: GPIO */
#define PIO_SPI1_NPCS2    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN27) /* Type: GPIO */
#define PIO_SPI1_NPCS3    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN28) /* Type: GPIO */
#define PIO_SPI1_SPCK     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN24) /* Type: GPIO_CLK */

/* Synchronous Serial Controller - SSCx [1..0] */

#define PIO_SSC0_RD       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN21) /* Type: GPIO */
#define PIO_SSC0_RF       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN20) /* Type: GPIO */
#define PIO_SSC0_RK       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN19) /* Type: GPIO */
#define PIO_SSC0_TD       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN18) /* Type: GPIO */
#define PIO_SSC0_TF       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN17) /* Type: GPIO */
#define PIO_SSC0_TK       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN16) /* Type: GPIO */

#define PIO_SSC1_RD       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN11) /* Type: GMAC */
#define PIO_SSC1_RF       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN10) /* Type: GMAC */
#define PIO_SSC1_RK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN7)  /* Type: GMAC */
#define PIO_SSC1_TD       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN6)  /* Type: GMAC */
#define PIO_SSC1_TF       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN3)  /* Type: GMAC */
#define PIO_SSC1_TK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN2)  /* Type: GMAC */

/* Timer/Counter - TCx [5..0] */

#define PIO_TC0_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN7)  /* Type: GPIO */
#define PIO_TC0_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN5)  /* Type: GPIO */
#define PIO_TC0_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN6)  /* Type: GPIO */

#define PIO_TC1_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN14) /* Type: GPIO */
#define PIO_TC1_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN12) /* Type: GPIO */
#define PIO_TC1_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN13) /* Type: GPIO */

#define PIO_TC2_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN29) /* Type: EBI */
#define PIO_TC2_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN27) /* Type: EBI */
#define PIO_TC2_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN28) /* Type: EBI */

#define PIO_TC3_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN2)  /* Type: GPIO */
#define PIO_TC3_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN0)  /* Type: GPIO */
#define PIO_TC3_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN1)  /* Type: GPIO */

#define PIO_TC4_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN5)  /* Type: GPIO */
#define PIO_TC4_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN3)  /* Type: GPIO */
#define PIO_TC4_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN4)  /* Type: GPIO */

#define PIO_TC5_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN8)  /* Type: GPIO */
#define PIO_TC5_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN6)  /* Type: GPIO */
#define PIO_TC5_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN7)  /* Type: GPIO */

/* Two-Wire Interface -TWIx [2..0] */

#define PIO_TWI0_CK       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN31) /* Type: GPIO */
#define PIO_TWI0_D        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN30) /* Type: GPIO */

#define PIO_TWI1_CK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN27) /* Type: GPIO */
#define PIO_TWI1_D        (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN26) /* Type: GPIO */

#define PIO_TWI2_CK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN19) /* Type: GPIO */
#define PIO_TWI2_D        (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN18) /* Type: GPIO */

/* Universal Asynchronous Receiver Transmitter - UARTx [1..0] */

#define PIO_UART0_RXD     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN29) /* Type: GPIO */
#define PIO_UART0_TXD     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN30) /* Type: GPIO */

#define PIO_UART1_RXD     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN30) /* Type: GPIO */
#define PIO_UART1_TXD     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN31) /* Type: GPIO */

/* Universal Synchronous Asynchronous Receiver Transmitter- USART0-3 */

#define PIO_USART0_CTS    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN15) /* Type: GPIO */
#define PIO_USART0_RTS    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN16) /* Type: GPIO */
#define PIO_USART0_RXD    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN17) /* Type: GPIO */
#define PIO_USART0_SCK    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN14) /* Type: GPIO */
#define PIO_USART0_TXD    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN18) /* Type: GPIO */

#define PIO_USART1_CTS    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN26) /* Type: GMAC */
#define PIO_USART1_RTS    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN27) /* Type: GPIO */
#define PIO_USART1_RXD    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN28) /* Type: GPIO */
#define PIO_USART1_SCK    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN25) /* Type: GMAC */
#define PIO_USART1_TXD    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN29) /* Type: GPIO */

#define PIO_USART2_CTS    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN23) /* Type: EBI */
#define PIO_USART2_RTS    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN24) /* Type: EBI */
#define PIO_USART2_RXD    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN25) /* Type: EBI */
#define PIO_USART2_SCK    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN20) /* Type: EBI */
#define PIO_USART2_TXD    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN26) /* Type: EBI */

#define PIO_USART3_CTS    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN16) /* Type: EBI */
#define PIO_USART3_RTS    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN17) /* Type: EBI */
#define PIO_USART3_RXD    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN18) /* Type: EBI */
#define PIO_USART3_SCK    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN15) /* Type: EBI */
#define PIO_USART3_TXD    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN19) /* Type: EBI */

#endif /* __ARCH_ARM_SRC_SAMA5_HARDWARE__SAMA5D3X_PINMAP_H */
