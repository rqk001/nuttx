/************************************************************************************************************
 * arch/arm/src/sama5/hardware/_sama5d4x_pinmap.h
 *
 *   Copyright (C) 2014 Gregory Nutt. All rights reserved.
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

#ifndef __ARCH_ARM_SRC_SAMA5_HARDWARE__SAMA5D4X_PINMAP_H
#define __ARCH_ARM_SRC_SAMA5_HARDWARE__SAMA5D4X_PINMAP_H

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
 * file.  For example, if we wanted the PCK0 on PB26, then the following definition should appear in the
 * board.h header file for that board:
 *
 *   #define PIO_PMC_PCK0 PIO_PMC_PCK0_1
 *
 * The PCK logic will then automatically configure PB26 as the PCK0 pin.
 */

/* WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!!
 * Additional effort is required to select specific PIO options such as frequency, open-drain/push-pull,
 * and pull-up/down!  Just the basics are defined for most pins in this file at the present time.
 */

/* Analog-to-Digital Converter - ADC */

#define PIO_ADC_AD0       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN27)
#define PIO_ADC_AD1       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN28)
#define PIO_ADC_AD2       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN29)
#define PIO_ADC_AD3       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN30)
#define PIO_ADC_AD4       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN31)
#define PIO_ADC_TRG       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN31)

/* Advanced Interrupt Controller - AIC */

#define PIO_AIC_FIQ       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN9)
#define PIO_AIC_IRQ       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN25)

/* Capacitive Touch Module - CATB */

#define PIO_CATB_DIS      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN29)
#define PIO_CATB_SENSE0   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN18)
#define PIO_CATB_SENSE1   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN19)
#define PIO_CATB_SENSE2   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN20)
#define PIO_CATB_SENSE3   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN21)
#define PIO_CATB_SENSE4   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN22)
#define PIO_CATB_SENSE5   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN23)
#define PIO_CATB_SENSE6   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN24)
#define PIO_CATB_SENSE7   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN25)
#define PIO_CATB_SENSE8   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN26)
#define PIO_CATB_SENSE9   (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN27)

/* Debug Unit - DBGU */

#define PIO_DBGU_DRXD     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN24)
#define PIO_DBGU_DTXD     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN25)

/* External Bus Interface - EBI */

#define PIO_EBI_A0        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN0)
#define PIO_EBI_A1        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN1)
#define PIO_EBI_A2        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN2)
#define PIO_EBI_A3        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN3)
#define PIO_EBI_A4        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN4)
#define PIO_EBI_A5        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN5)
#define PIO_EBI_A6        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN6)
#define PIO_EBI_A7        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN7)
#define PIO_EBI_A8        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN8)
#define PIO_EBI_A9        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN9)
#define PIO_EBI_A10       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN10)
#define PIO_EBI_A11       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN11)
#define PIO_EBI_A12       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN12)
#define PIO_EBI_A13       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN13)
#define PIO_EBI_A14       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN14)
#define PIO_EBI_A15       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN15)
#define PIO_EBI_A16       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN16)
#define PIO_EBI_A17       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN17)
#define PIO_EBI_A18_1     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN18)
#define PIO_EBI_A18_2     (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN26)
#define PIO_EBI_A19_1     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN19)
#define PIO_EBI_A19_2     (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN28)
#define PIO_EBI_A20       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN20)
#define PIO_EBI_A21       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN17)
#define PIO_EBI_A22       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN18)
#define PIO_EBI_A23       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN21)
#define PIO_EBI_A24       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN22)
#define PIO_EBI_A25       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN23)
#define PIO_EBI_D0        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN5)
#define PIO_EBI_D1        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN6)
#define PIO_EBI_D2        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN7)
#define PIO_EBI_D3        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN8)
#define PIO_EBI_D4        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN9)
#define PIO_EBI_D5        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN10)
#define PIO_EBI_D6        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN11)
#define PIO_EBI_D7        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN12)
#define PIO_EBI_D8        (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN18)
#define PIO_EBI_D9        (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN19)
#define PIO_EBI_D10       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN20)
#define PIO_EBI_D11       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN21)
#define PIO_EBI_D12       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN22)
#define PIO_EBI_D13       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN23)
#define PIO_EBI_D14       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN24)
#define PIO_EBI_D15       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN25)
#define PIO_EBI_NWAIT     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN28)

/* RMII Ethernet 10/100 - EMAC0 */

#define PIO_EMAC0_COL     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN5)
#define PIO_EMAC0_CRS     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN4)
#define PIO_EMAC0_MDC     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN16)
#define PIO_EMAC0_MDIO    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN17)
#define PIO_EMAC0_RX0     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN8)
#define PIO_EMAC0_RX1     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN9)
#define PIO_EMAC0_RX2     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN10)
#define PIO_EMAC0_RX3     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN11)
#define PIO_EMAC0_RXCK    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN1)
#define PIO_EMAC0_RXDV    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN6)
#define PIO_EMAC0_RXER    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN7)
#define PIO_EMAC0_TX0     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN12)
#define PIO_EMAC0_TX1     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN13)
#define PIO_EMAC0_TX2     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN14)
#define PIO_EMAC0_TX3     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN15)
#define PIO_EMAC0_TXCK    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN0)
#define PIO_EMAC0_TXEN    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN2)
#define PIO_EMAC0_TXER    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN3)

/* RMII Ethernet 10/100 - EMAC1 */

#define PIO_EMAC1_COL     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN9)
#define PIO_EMAC1_CRS     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN6)
#define PIO_EMAC1_MDC     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN22)
#define PIO_EMAC1_MDIO    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN23)
#define PIO_EMAC1_RX0     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN12)
#define PIO_EMAC1_RX1     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN13)
#define PIO_EMAC1_RX2     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN18)
#define PIO_EMAC1_RX3     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN19)
#define PIO_EMAC1_RXCK    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN3)
#define PIO_EMAC1_RXDV    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN10)
#define PIO_EMAC1_RXER    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN11)
#define PIO_EMAC1_TX0     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN14)
#define PIO_EMAC1_TX1     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN15)
#define PIO_EMAC1_TX2     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN20)
#define PIO_EMAC1_TX3     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN21)
#define PIO_EMAC1_TXCK    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN2)
#define PIO_EMAC1_TXEN    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN4)
#define PIO_EMAC1_TXER    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN5)

/* Static Memory Controller - HSMC */

#define PIO_HSMC_NANDALE  (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN17)
#define PIO_HSMC_NANDCLE  (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN18)
#define PIO_HSMC_NANDOE   (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN13)
#define PIO_HSMC_NANDRDY  (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN16)
#define PIO_HSMC_NANDWE   (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN14)
#define PIO_HSMC_NBS0     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN0)
#define PIO_HSMC_NBS1     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN27)
#define PIO_HSMC_NCS0     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN24)
#define PIO_HSMC_NCS1     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN25)
#define PIO_HSMC_NCS2     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN26)
#define PIO_HSMC_NCS3     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN15)
#define PIO_HSMC_NRD      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN13)
#define PIO_HSMC_NWE      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN14)
#define PIO_HSMC_NWR1     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN27)

/* Image Sensor Interface - ISI */

#define PIO_ISI_D0        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN19)
#define PIO_ISI_D1        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN20)
#define PIO_ISI_D2        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN21)
#define PIO_ISI_D3        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN22)
#define PIO_ISI_D4        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN23)
#define PIO_ISI_D5        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN24)
#define PIO_ISI_D6        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN25)
#define PIO_ISI_D7        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN26)
#define PIO_ISI_D8        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN0)
#define PIO_ISI_D9        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN1)
#define PIO_ISI_D10       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN2)
#define PIO_ISI_D11       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN3)
#define PIO_ISI_HSYNC     (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN4)
#define PIO_ISI_PCK       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN1)
#define PIO_ISI_VSYNC     (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN3)

/* JTAG/SWI */

#define PIO_JTAG_SWCLK    (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN8)
#define PIO_JTAG_TCK      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN8)
#define PIO_JTAG_TDO      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN25)
#define PIO_JTAG_TMS      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN0)

/* LCD Controller - LCDC */

#define PIO_LCD_DAT0      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN0)
#define PIO_LCD_DAT1      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN1)
#define PIO_LCD_DAT2      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN2)
#define PIO_LCD_DAT3      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN3)
#define PIO_LCD_DAT4      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN4)
#define PIO_LCD_DAT5      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN5)
#define PIO_LCD_DAT6      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN6)
#define PIO_LCD_DAT7      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN7)
#define PIO_LCD_DAT8      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN8)
#define PIO_LCD_DAT9      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN9)
#define PIO_LCD_DAT10     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN10)
#define PIO_LCD_DAT11     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN11)
#define PIO_LCD_DAT12     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN12)
#define PIO_LCD_DAT13     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN13)
#define PIO_LCD_DAT14     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN14)
#define PIO_LCD_DAT15     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN15)
#define PIO_LCD_DAT16     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN16)
#define PIO_LCD_DAT17     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN17)
#define PIO_LCD_DAT18     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN18)
#define PIO_LCD_DAT19     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN19)
#define PIO_LCD_DAT20     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN20)
#define PIO_LCD_DAT21     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN21)
#define PIO_LCD_DAT22     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN22)
#define PIO_LCD_DAT23     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN23)
#define PIO_LCD_DEN       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN29)
#define PIO_LCD_DISP      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN25)
#define PIO_LCD_HSYNC     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN27)
#define PIO_LCD_PCK       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN28)
#define PIO_LCD_PWM       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN24)
#define PIO_LCD_VSYNC     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN26)

/* High Speed Multimedia Card Interface - HSMCI0-1 */

#define PIO_MCI0_CDA      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN5)
#define PIO_MCI0_CDB      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN0)
#define PIO_MCI0_CK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN4)
#define PIO_MCI0_DA0      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN6)
#define PIO_MCI0_DA1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN7)
#define PIO_MCI0_DA2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN8)
#define PIO_MCI0_DA3      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN9)
#define PIO_MCI0_DA4      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN10)
#define PIO_MCI0_DA5      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN11)
#define PIO_MCI0_DA6      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN12)
#define PIO_MCI0_DA7      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN13)
#define PIO_MCI0_DB0      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN1)
#define PIO_MCI0_DB1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN2)
#define PIO_MCI0_DB2      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN3)
#define PIO_MCI0_DB3      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN4)

#define PIO_MCI1_CDA      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN19)
#define PIO_MCI1_CK       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN18)
#define PIO_MCI1_DA0      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN20)
#define PIO_MCI1_DA1      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN21)
#define PIO_MCI1_DA2      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN22)
#define PIO_MCI1_DA3      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN23)

/* Clocks, Oscillators and PLLs */

#define PIO_PMC_PCK0_1    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN26)
#define PIO_PMC_PCK0_2    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN8)
#define PIO_PMC_PCK0_3    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN24)
#define PIO_PMC_PCK1_1    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN31)
#define PIO_PMC_PCK1_2    (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN24)
#define PIO_PMC_PCK1_3    (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN4)
#define PIO_PMC_PCK2_1    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN10)
#define PIO_PMC_PCK2_2    (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN5)

/* Pulse Width Modulation Controller- PWMC */

#define PIO_PWM0_FI       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN29)
#define PIO_PWM0_H_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN26)
#define PIO_PWM0_H_2      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN14)
#define PIO_PWM0_H_3      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN26)
#define PIO_PWM0_H_4      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN30)
#define PIO_PWM0_L_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN27)
#define PIO_PWM0_L_2      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN15)
#define PIO_PWM0_L_3      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN27)
#define PIO_PWM0_L_4      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN27)

#define PIO_PWM1_FI       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN7)
#define PIO_PWM1_H_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN28)
#define PIO_PWM1_H_2      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN11)
#define PIO_PWM1_H_3      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN28)
#define PIO_PWM1_H_4      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN31)
#define PIO_PWM1_L_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN29)
#define PIO_PWM1_L_2      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN10)
#define PIO_PWM1_L_3      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN29)
#define PIO_PWM1_L_4      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN28)

#define PIO_PWM2_H_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN0)
#define PIO_PWM2_H_2      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN12)
#define PIO_PWM2_L_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN1)
#define PIO_PWM2_L_2      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN13)

#define PIO_PWM3_H_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN2)
#define PIO_PWM3_H_2      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN14)
#define PIO_PWM3_L_1      (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN3)
#define PIO_PWM3_L_2      (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN8)

/* Reset Control -- RSTC */

#define PIO_RSTC_NTRST    (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN16)

/* Softe Modem - SMD */

#define PIO_SMD_DIBN      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN30)
#define PIO_SMD_DIBP      (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN29)

/* Serial Peripheral Interface - SPIx [1..0] */

#define PIO_SPI0_MISO     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN0)
#define PIO_SPI0_MOSI     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN1)
#define PIO_SPI0_NPCS0    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN3)
#define PIO_SPI0_NPCS1_1  (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN4)
#define PIO_SPI0_NPCS1_2  (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN27)
#define PIO_SPI0_NPCS2_1  (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN31)
#define PIO_SPI0_NPCS2_2  (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN28)
#define PIO_SPI0_NPCS3    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN29)
#define PIO_SPI0_SPCK     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN2)

#define PIO_SPI1_MISO     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN18)
#define PIO_SPI1_MOSI     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN19)
#define PIO_SPI1_NPCS0    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN21)
#define PIO_SPI1_NPCS1_1  (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN22)
#define PIO_SPI1_NPCS1_2  (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN26)
#define PIO_SPI1_NPCS2_1  (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN23)
#define PIO_SPI1_NPCS2_2  (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN27)
#define PIO_SPI1_NPCS3_1  (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN27)
#define PIO_SPI1_NPCS3_2  (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN28)
#define PIO_SPI1_SPCK     (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN20)

#define PIO_SPI2_MISO     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN11)
#define PIO_SPI2_MOSI     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN13)
#define PIO_SPI2_NPCS0    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN17)
#define PIO_SPI2_NPCS1    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN14)
#define PIO_SPI2_NPCS2    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN15)
#define PIO_SPI2_NPCS3    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN28)
#define PIO_SPI2_SPCK     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN15)

/* Synchronous Serial Controller - SSCx [1..0] */

#define PIO_SSC0_RD       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN29)
#define PIO_SSC0_RF       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN30)
#define PIO_SSC0_RK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN26)
#define PIO_SSC0_TD_1     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN25)
#define PIO_SSC0_TD_2     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN28)
#define PIO_SSC0_TF       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN31)
#define PIO_SSC0_TK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN27)

#define PIO_SSC1_RD       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN23)
#define PIO_SSC1_RF       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN22)
#define PIO_SSC1_RK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN24)
#define PIO_SSC1_TD_1     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN21)
#define PIO_SSC1_TD_2     (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN24)
#define PIO_SSC1_TF       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN20)
#define PIO_SSC1_TK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN19)

/* Timer/Counter - TCx [5..0] */

#define PIO_TC0_CLK       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN17)
#define PIO_TC0_IOA       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN15)
#define PIO_TC0_IOB       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN16)

#define PIO_TC1_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN14)
#define PIO_TC1_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN12)
#define PIO_TC1_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN13)

#define PIO_TC2_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN11)
#define PIO_TC2_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN9)
#define PIO_TC2_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN10)

#define PIO_TC3_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN8)
#define PIO_TC3_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN6)
#define PIO_TC3_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN7)

#define PIO_TC4_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN23)
#define PIO_TC4_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN21)
#define PIO_TC4_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN22)

#define PIO_TC5_CLK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN20)
#define PIO_TC5_IOA       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN18)
#define PIO_TC5_IOB       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN19)

/* What about TC6-8? */

/* Two-Wire Interface -TWIx [3..0] */

#define PIO_TWI0_CK       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN31)
#define PIO_TWI0_D        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOA | PIO_PIN30)

#define PIO_TWI1_CK       (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN30)
#define PIO_TWI1_D        (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN29)

#define PIO_TWI2_CK       (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN30)
#define PIO_TWI2_D        (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN29)

#define PIO_TWI3_CK       (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN26)
#define PIO_TWI3_D        (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN25)

/* Universal Asynchronous Receiver Transmitter - UARTx [1..0] */

#define PIO_UART0_RXD     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN29)
#define PIO_UART0_TXD     (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN30)

#define PIO_UART1_RXD     (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN25)
#define PIO_UART1_TXD     (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOC | PIO_PIN26)

/* Universal Synchronous Asynchronous Receiver Transmitter- USART0-4 */

#define PIO_USART0_CTS    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN10)
#define PIO_USART0_RTS    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN11)
#define PIO_USART0_RXD    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN12)
#define PIO_USART0_SCK    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN28)
#define PIO_USART0_TXD    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN13)

#define PIO_USART1_CTS    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN14)
#define PIO_USART1_RTS    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN15)
#define PIO_USART1_RXD    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN16)
#define PIO_USART1_SCK    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN29)
#define PIO_USART1_TXD    (PIO_PERIPHA | PIO_CFG_DEFAULT | PIO_PORT_PIOD | PIO_PIN17)

#define PIO_USART2_CTS    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN3)
#define PIO_USART2_RTS    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN11)
#define PIO_USART2_RXD    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN4)
#define PIO_USART2_SCK    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN1)
#define PIO_USART2_TXD    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOB | PIO_PIN5)

#define PIO_USART3_CTS    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN5)
#define PIO_USART3_RTS    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN24)
#define PIO_USART3_RXD    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN16)
#define PIO_USART3_SCK    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN15)
#define PIO_USART3_TXD    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN17)

#define PIO_USART4_CTS    (PIO_PERIPHC | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN0)
#define PIO_USART4_RTS    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN28)
#define PIO_USART4_RXD    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN26)
#define PIO_USART4_SCK    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN25)
#define PIO_USART4_TXD    (PIO_PERIPHB | PIO_CFG_DEFAULT | PIO_PORT_PIOE | PIO_PIN27)

#endif /* __ARCH_ARM_SRC_SAMA5_HARDWARE__SAMA5D4X_PINMAP_H */
