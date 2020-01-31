/********************************************************************************************
 * arch/arm/src/samd5e5/hardware/samd5e5_pinmap.h
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
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
 ********************************************************************************************/

#ifndef __ARCH_ARM_SRC_SAMD5E5_HARDWARE_SAMD5E5_PINMAP_H
#define __ARCH_ARM_SRC_SAMD5E5_HARDWARE_SAMD5E5_PINMAP_H

/********************************************************************************************
 * Included Files
 ********************************************************************************************/

#include <nuttx/config.h>

/********************************************************************************************
 * Pre-processor Definitions
 ********************************************************************************************/
/* GPIO pin definitions *********************************************************************/
/* Alternate Pin Functions.
 *
 * Alternative pin selections are provided with a numeric suffix like _1, _2, etc.
 * Drivers, however, will use the pin selection without the numeric suffix.
 * Additional definitions are required in the board.h file.  For example, if we
 * wanted the SERCOM0 PAD0 on PA8, then the following definition should appear in
 * the board.h header file for that board:
 *
 * #define PORT_SERCOM0_PAD0 PORT_SERCOM0_PAD0_1
 *
 * The driver will then automatically configure PA8 as the SERCOM0 PAD0 pin.
 */

/* WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!!
 * Additional effort is required to select specific GPIO options such as frequency,
 * open-drain/push-pull, and pull-up/down!  Just the basics are defined for most
 * pins in this file.
 */

/* Analog comparator (AC) */

#define PORT_AC_AIN0                 (PORT_FUNCB | PORTA | PORT_PIN4)
#define PORT_AC_AIN1                 (PORT_FUNCB | PORTA | PORT_PIN5)
#define PORT_AC_AIN2                 (PORT_FUNCB | PORTA | PORT_PIN6)
#define PORT_AC_AIN3                 (PORT_FUNCB | PORTA | PORT_PIN7)
#define PORT_AC_CMP0_1               (PORT_FUNCM | PORTA | PORT_PIN12)
#define PORT_AC_CMP0_2               (PORT_FUNCM | PORTA | PORT_PIN18)
#define PORT_AC_CMP0_3               (PORT_FUNCM | PORTB | PORT_PIN24)
#define PORT_AC_CMP1_1               (PORT_FUNCM | PORTA | PORT_PIN13)
#define PORT_AC_CMP1_2               (PORT_FUNCM | PORTA | PORT_PIN19)
#define PORT_AC_CMP1_3               (PORT_FUNCM | PORTB | PORT_PIN25)

/* Analog-to-Digital Conversion (ADC) */

#define PORT_ADC0_AIN0               (PORT_FUNCB | PORTA | PORT_PIN2)
#define PORT_ADC0_AIN1               (PORT_FUNCB | PORTA | PORT_PIN3)
#define PORT_ADC0_AIN2               (PORT_FUNCB | PORTB | PORT_PIN8)
#define PORT_ADC0_AIN3               (PORT_FUNCB | PORTB | PORT_PIN9)
#define PORT_ADC0_AIN4               (PORT_FUNCB | PORTA | PORT_PIN4)
#define PORT_ADC0_AIN5               (PORT_FUNCB | PORTA | PORT_PIN5)
#define PORT_ADC0_AIN6               (PORT_FUNCB | PORTA | PORT_PIN6)
#define PORT_ADC0_AIN7               (PORT_FUNCB | PORTA | PORT_PIN7)
#define PORT_ADC0_AIN8               (PORT_FUNCB | PORTA | PORT_PIN8)
#define PORT_ADC0_AIN9               (PORT_FUNCB | PORTA | PORT_PIN9)
#define PORT_ADC0_AIN10              (PORT_FUNCB | PORTA | PORT_PIN10)
#define PORT_ADC0_AIN11              (PORT_FUNCB | PORTA | PORT_PIN11)
#define PORT_ADC0_AIN12              (PORT_FUNCB | PORTB | PORT_PIN0)
#define PORT_ADC0_AIN13              (PORT_FUNCB | PORTB | PORT_PIN1)
#define PORT_ADC0_AIN14              (PORT_FUNCB | PORTB | PORT_PIN2)
#define PORT_ADC0_AIN15              (PORT_FUNCB | PORTB | PORT_PIN3)

#define PORT_ADC1_AIN0               (PORT_FUNCB | PORTB | PORT_PIN8)
#define PORT_ADC1_AIN1               (PORT_FUNCB | PORTB | PORT_PIN9)
#define PORT_ADC1_AIN2               (PORT_FUNCB | PORTA | PORT_PIN8)
#define PORT_ADC1_AIN3               (PORT_FUNCB | PORTA | PORT_PIN9)
#define PORT_ADC1_AIN4               (PORT_FUNCB | PORTC | PORT_PIN2)
#define PORT_ADC1_AIN5               (PORT_FUNCB | PORTC | PORT_PIN3)
#define PORT_ADC1_AIN6               (PORT_FUNCB | PORTB | PORT_PIN4)
#define PORT_ADC1_AIN7               (PORT_FUNCB | PORTB | PORT_PIN5)
#define PORT_ADC1_AIN8               (PORT_FUNCB | PORTB | PORT_PIN6)
#define PORT_ADC1_AIN9               (PORT_FUNCB | PORTB | PORT_PIN7)
#define PORT_ADC1_AIN10              (PORT_FUNCB | PORTC | PORT_PIN0)
#define PORT_ADC1_AIN11              (PORT_FUNCB | PORTC | PORT_PIN1)
#define PORT_ADC1_AIN12              (PORT_FUNCB | PORTC | PORT_PIN30)
#define PORT_ADC1_AIN13              (PORT_FUNCB | PORTC | PORT_PIN31)
#define PORT_ADC1_AIN14              (PORT_FUNCB | PORTD | PORT_PIN0)
#define PORT_ADC1_AIN15              (PORT_FUNCB | PORTD | PORT_PIN1)

/* Analog Voltage Reference (ANAREF) */

#define PORT_ANAREF_VREFA            (PORT_FUNCB | PORTA | PORT_PIN3)
#define PORT_ANAREF_VREFB            (PORT_FUNCB | PORTA | PORT_PIN4)
#define PORT_ANAREF_VREFC            (PORT_FUNCB | PORTA | PORT_PIN6)

/* Controller Area Network (CAN) */

#define PORT_CAN0_RX_1               (PORT_FUNCI | PORTA | PORT_PIN23)
#define PORT_CAN0_RX_2               (PORT_FUNCI | PORTA | PORT_PIN25)
#define PORT_CAN0_TX_1               (PORT_FUNCI | PORTA | PORT_PIN22)
#define PORT_CAN0_TX_2               (PORT_FUNCI | PORTA | PORT_PIN24)

#define PORT_CAN1_RX_1               (PORT_FUNCH | PORTB | PORT_PIN13)
#define PORT_CAN1_RX_2               (PORT_FUNCH | PORTB | PORT_PIN15)
#define PORT_CAN1_TX_1               (PORT_FUNCH | PORTB | PORT_PIN12)
#define PORT_CAN1_TX_2               (PORT_FUNCH | PORTB | PORT_PIN14)

/* Configurable Custom Logic (CCL) */

#define PORT_CCL_IN0_1               (PORT_FUNCN | PORTA | PORT_PIN16)
#define PORT_CCL_IN0_2               (PORT_FUNCN | PORTA | PORT_PIN4)
#define PORT_CCL_IN0_3               (PORT_FUNCN | PORTB | PORT_PIN22)
#define PORT_CCL_IN1_1               (PORT_FUNCN | PORTA | PORT_PIN17)
#define PORT_CCL_IN1_2               (PORT_FUNCN | PORTA | PORT_PIN5)
#define PORT_CCL_IN1_3               (PORT_FUNCN | PORTB | PORT_PIN0)
#define PORT_CCL_IN2_1               (PORT_FUNCN | PORTA | PORT_PIN18)
#define PORT_CCL_IN2_2               (PORT_FUNCN | PORTA | PORT_PIN6)
#define PORT_CCL_IN2_3               (PORT_FUNCN | PORTB | PORT_PIN1)
#define PORT_CCL_IN3_1               (PORT_FUNCN | PORTA | PORT_PIN30)
#define PORT_CCL_IN3_2               (PORT_FUNCN | PORTA | PORT_PIN8)
#define PORT_CCL_IN4_1               (PORT_FUNCN | PORTA | PORT_PIN9)
#define PORT_CCL_IN4_2               (PORT_FUNCN | PORTC | PORT_PIN27)
#define PORT_CCL_IN5_1               (PORT_FUNCN | PORTA | PORT_PIN10)
#define PORT_CCL_IN5_2               (PORT_FUNCN | PORTC | PORT_PIN28)
#define PORT_CCL_IN6_1               (PORT_FUNCN | PORTA | PORT_PIN22)
#define PORT_CCL_IN6_2               (PORT_FUNCN | PORTB | PORT_PIN6)
#define PORT_CCL_IN7_1               (PORT_FUNCN | PORTA | PORT_PIN23)
#define PORT_CCL_IN7_2               (PORT_FUNCN | PORTB | PORT_PIN7)
#define PORT_CCL_IN8_1               (PORT_FUNCN | PORTA | PORT_PIN24)
#define PORT_CCL_IN8_2               (PORT_FUNCN | PORTB | PORT_PIN8)
#define PORT_CCL_IN9_1               (PORT_FUNCN | PORTB | PORT_PIN14)
#define PORT_CCL_IN9_2               (PORT_FUNCN | PORTC | PORT_PIN20)
#define PORT_CCL_IN10_1              (PORT_FUNCN | PORTB | PORT_PIN15)
#define PORT_CCL_IN10_2              (PORT_FUNCN | PORTC | PORT_PIN21)
#define PORT_CCL_IN11_1              (PORT_FUNCN | PORTB | PORT_PIN10)
#define PORT_CCL_IN11_2              (PORT_FUNCN | PORTB | PORT_PIN16)
#define PORT_CCL_OUT0_1              (PORT_FUNCN | PORTA | PORT_PIN19)
#define PORT_CCL_OUT0_2              (PORT_FUNCN | PORTA | PORT_PIN7)
#define PORT_CCL_OUT0_3              (PORT_FUNCN | PORTB | PORT_PIN2)
#define PORT_CCL_OUT0_4              (PORT_FUNCN | PORTB | PORT_PIN23)
#define PORT_CCL_OUT1_1              (PORT_FUNCN | PORTA | PORT_PIN11)
#define PORT_CCL_OUT1_2              (PORT_FUNCN | PORTA | PORT_PIN31)
#define PORT_CCL_OUT1_3              (PORT_FUNCN | PORTB | PORT_PIN11)
#define PORT_CCL_OUT2_1              (PORT_FUNCN | PORTA | PORT_PIN25)
#define PORT_CCL_OUT2_2              (PORT_FUNCN | PORTB | PORT_PIN9)
#define PORT_CCL_OUT3                (PORT_FUNCN | PORTB | PORT_PIN17)

/* Cortex-M4 JTAG/SWD */

#define PORT_CORTEX_CM4_SWCLK        (PORT_FUNCH | PORTA | PORT_PIN30)
#define PORT_CORTEX_CM4_SWDIO        (PORT_FUNCH | PORTA | PORT_PIN31)
#define PORT_CORTEX_CM4_SWO          (PORT_FUNCH | PORTB | PORT_PIN30)
#define PORT_CORTEX_CM4_TRACECLK     (PORT_FUNCH | PORTC | PORT_PIN27)
#define PORT_CORTEX_CM4_TRACEDATA0   (PORT_FUNCH | PORTC | PORT_PIN28)
#define PORT_CORTEX_CM4_TRACEDATA1   (PORT_FUNCH | PORTC | PORT_PIN26)
#define PORT_CORTEX_CM4_TRACEDATA2   (PORT_FUNCH | PORTC | PORT_PIN25)
#define PORT_CORTEX_CM4_TRACEDATA3   (PORT_FUNCH | PORTC | PORT_PIN24)
#define PORT_CORTEX_M4_SWO           (PORT_FUNCM | PORTC | PORT_PIN27)

/* Digital-to-Analog Conversion (DAC) */

#define PORT_DAC_VOUT0               (PORT_FUNCB | PORTA | PORT_PIN2)
#define PORT_DAC_VOUT1               (PORT_FUNCB | PORTA | PORT_PIN5)

/* External Interrupt Controller (EIC) */

#define PORT_EIC_EXTINT0_1           (PORT_FUNCA | PORTA | PORT_PIN0)
#define PORT_EIC_EXTINT0_2           (PORT_FUNCA | PORTA | PORT_PIN16)
#define PORT_EIC_EXTINT0_3           (PORT_FUNCA | PORTB | PORT_PIN0)
#define PORT_EIC_EXTINT0_4           (PORT_FUNCA | PORTB | PORT_PIN16)
#define PORT_EIC_EXTINT0_5           (PORT_FUNCA | PORTC | PORT_PIN0)
#define PORT_EIC_EXTINT0_6           (PORT_FUNCA | PORTC | PORT_PIN16)
#define PORT_EIC_EXTINT0_7           (PORT_FUNCA | PORTD | PORT_PIN0)
#define PORT_EIC_EXTINT1_1           (PORT_FUNCA | PORTA | PORT_PIN1)
#define PORT_EIC_EXTINT1_2           (PORT_FUNCA | PORTA | PORT_PIN17)
#define PORT_EIC_EXTINT1_3           (PORT_FUNCA | PORTB | PORT_PIN1)
#define PORT_EIC_EXTINT1_4           (PORT_FUNCA | PORTB | PORT_PIN17)
#define PORT_EIC_EXTINT1_5           (PORT_FUNCA | PORTC | PORT_PIN1)
#define PORT_EIC_EXTINT1_6           (PORT_FUNCA | PORTC | PORT_PIN17)
#define PORT_EIC_EXTINT1_7           (PORT_FUNCA | PORTD | PORT_PIN1)
#define PORT_EIC_EXTINT2_1           (PORT_FUNCA | PORTA | PORT_PIN18)
#define PORT_EIC_EXTINT2_2           (PORT_FUNCA | PORTA | PORT_PIN2)
#define PORT_EIC_EXTINT2_3           (PORT_FUNCA | PORTB | PORT_PIN18)
#define PORT_EIC_EXTINT2_4           (PORT_FUNCA | PORTB | PORT_PIN2)
#define PORT_EIC_EXTINT2_5           (PORT_FUNCA | PORTC | PORT_PIN18)
#define PORT_EIC_EXTINT2_6           (PORT_FUNCA | PORTC | PORT_PIN2)
#define PORT_EIC_EXTINT3_1           (PORT_FUNCA | PORTA | PORT_PIN19)
#define PORT_EIC_EXTINT3_2           (PORT_FUNCA | PORTA | PORT_PIN3)
#define PORT_EIC_EXTINT3_3           (PORT_FUNCA | PORTB | PORT_PIN19)
#define PORT_EIC_EXTINT3_4           (PORT_FUNCA | PORTB | PORT_PIN3)
#define PORT_EIC_EXTINT3_5           (PORT_FUNCA | PORTC | PORT_PIN19)
#define PORT_EIC_EXTINT3_6           (PORT_FUNCA | PORTC | PORT_PIN3)
#define PORT_EIC_EXTINT3_7           (PORT_FUNCA | PORTD | PORT_PIN8)
#define PORT_EIC_EXTINT4_1           (PORT_FUNCA | PORTA | PORT_PIN20)
#define PORT_EIC_EXTINT4_2           (PORT_FUNCA | PORTA | PORT_PIN4)
#define PORT_EIC_EXTINT4_3           (PORT_FUNCA | PORTB | PORT_PIN20)
#define PORT_EIC_EXTINT4_4           (PORT_FUNCA | PORTB | PORT_PIN4)
#define PORT_EIC_EXTINT4_5           (PORT_FUNCA | PORTC | PORT_PIN20)
#define PORT_EIC_EXTINT4_6           (PORT_FUNCA | PORTC | PORT_PIN4)
#define PORT_EIC_EXTINT4_7           (PORT_FUNCA | PORTD | PORT_PIN9)
#define PORT_EIC_EXTINT5_1           (PORT_FUNCA | PORTA | PORT_PIN21)
#define PORT_EIC_EXTINT5_2           (PORT_FUNCA | PORTA | PORT_PIN5)
#define PORT_EIC_EXTINT5_3           (PORT_FUNCA | PORTB | PORT_PIN21)
#define PORT_EIC_EXTINT5_4           (PORT_FUNCA | PORTB | PORT_PIN5)
#define PORT_EIC_EXTINT5_5           (PORT_FUNCA | PORTC | PORT_PIN21)
#define PORT_EIC_EXTINT5_6           (PORT_FUNCA | PORTC | PORT_PIN5)
#define PORT_EIC_EXTINT5_7           (PORT_FUNCA | PORTD | PORT_PIN10)
#define PORT_EIC_EXTINT6_1           (PORT_FUNCA | PORTA | PORT_PIN22)
#define PORT_EIC_EXTINT6_2           (PORT_FUNCA | PORTA | PORT_PIN6)
#define PORT_EIC_EXTINT6_3           (PORT_FUNCA | PORTB | PORT_PIN22)
#define PORT_EIC_EXTINT6_4           (PORT_FUNCA | PORTB | PORT_PIN6)
#define PORT_EIC_EXTINT6_5           (PORT_FUNCA | PORTC | PORT_PIN22)
#define PORT_EIC_EXTINT6_6           (PORT_FUNCA | PORTC | PORT_PIN6)
#define PORT_EIC_EXTINT6_7           (PORT_FUNCA | PORTD | PORT_PIN11)
#define PORT_EIC_EXTINT7_1           (PORT_FUNCA | PORTA | PORT_PIN23)
#define PORT_EIC_EXTINT7_2           (PORT_FUNCA | PORTA | PORT_PIN7)
#define PORT_EIC_EXTINT7_3           (PORT_FUNCA | PORTB | PORT_PIN23)
#define PORT_EIC_EXTINT7_4           (PORT_FUNCA | PORTB | PORT_PIN7)
#define PORT_EIC_EXTINT7_5           (PORT_FUNCA | PORTC | PORT_PIN23)
#define PORT_EIC_EXTINT7_6           (PORT_FUNCA | PORTD | PORT_PIN12)
#define PORT_EIC_EXTINT8_1           (PORT_FUNCA | PORTA | PORT_PIN24)
#define PORT_EIC_EXTINT8_2           (PORT_FUNCA | PORTB | PORT_PIN24)
#define PORT_EIC_EXTINT8_3           (PORT_FUNCA | PORTB | PORT_PIN8)
#define PORT_EIC_EXTINT8_4           (PORT_FUNCA | PORTC | PORT_PIN24)
#define PORT_EIC_EXTINT9_1           (PORT_FUNCA | PORTA | PORT_PIN25)
#define PORT_EIC_EXTINT9_2           (PORT_FUNCA | PORTA | PORT_PIN9)
#define PORT_EIC_EXTINT9_3           (PORT_FUNCA | PORTB | PORT_PIN25)
#define PORT_EIC_EXTINT9_4           (PORT_FUNCA | PORTB | PORT_PIN9)
#define PORT_EIC_EXTINT9_5           (PORT_FUNCA | PORTC | PORT_PIN25)
#define PORT_EIC_EXTINT9_6           (PORT_FUNCA | PORTC | PORT_PIN7)
#define PORT_EIC_EXTINT10_1          (PORT_FUNCA | PORTA | PORT_PIN10)
#define PORT_EIC_EXTINT10_2          (PORT_FUNCA | PORTB | PORT_PIN10)
#define PORT_EIC_EXTINT10_3          (PORT_FUNCA | PORTC | PORT_PIN10)
#define PORT_EIC_EXTINT10_4          (PORT_FUNCA | PORTC | PORT_PIN26)
#define PORT_EIC_EXTINT10_5          (PORT_FUNCA | PORTD | PORT_PIN20)
#define PORT_EIC_EXTINT11_1          (PORT_FUNCA | PORTA | PORT_PIN11)
#define PORT_EIC_EXTINT11_2          (PORT_FUNCA | PORTA | PORT_PIN27)
#define PORT_EIC_EXTINT11_3          (PORT_FUNCA | PORTB | PORT_PIN11)
#define PORT_EIC_EXTINT11_4          (PORT_FUNCA | PORTC | PORT_PIN11)
#define PORT_EIC_EXTINT11_5          (PORT_FUNCA | PORTC | PORT_PIN27)
#define PORT_EIC_EXTINT11_6          (PORT_FUNCA | PORTD | PORT_PIN21)
#define PORT_EIC_EXTINT12_1          (PORT_FUNCA | PORTA | PORT_PIN12)
#define PORT_EIC_EXTINT12_2          (PORT_FUNCA | PORTB | PORT_PIN12)
#define PORT_EIC_EXTINT12_3          (PORT_FUNCA | PORTB | PORT_PIN26)
#define PORT_EIC_EXTINT12_4          (PORT_FUNCA | PORTC | PORT_PIN12)
#define PORT_EIC_EXTINT12_5          (PORT_FUNCA | PORTC | PORT_PIN28)
#define PORT_EIC_EXTINT13_1          (PORT_FUNCA | PORTA | PORT_PIN13)
#define PORT_EIC_EXTINT13_2          (PORT_FUNCA | PORTB | PORT_PIN13)
#define PORT_EIC_EXTINT13_3          (PORT_FUNCA | PORTB | PORT_PIN27)
#define PORT_EIC_EXTINT13_4          (PORT_FUNCA | PORTC | PORT_PIN13)
#define PORT_EIC_EXTINT14_1          (PORT_FUNCA | PORTA | PORT_PIN14)
#define PORT_EIC_EXTINT14_2          (PORT_FUNCA | PORTA | PORT_PIN30)
#define PORT_EIC_EXTINT14_3          (PORT_FUNCA | PORTB | PORT_PIN14)
#define PORT_EIC_EXTINT14_4          (PORT_FUNCA | PORTB | PORT_PIN28)
#define PORT_EIC_EXTINT14_5          (PORT_FUNCA | PORTB | PORT_PIN30)
#define PORT_EIC_EXTINT14_6          (PORT_FUNCA | PORTC | PORT_PIN14)
#define PORT_EIC_EXTINT14_7          (PORT_FUNCA | PORTC | PORT_PIN30)
#define PORT_EIC_EXTINT15_1          (PORT_FUNCA | PORTA | PORT_PIN15)
#define PORT_EIC_EXTINT15_2          (PORT_FUNCA | PORTA | PORT_PIN31)
#define PORT_EIC_EXTINT15_3          (PORT_FUNCA | PORTB | PORT_PIN15)
#define PORT_EIC_EXTINT15_4          (PORT_FUNCA | PORTB | PORT_PIN29)
#define PORT_EIC_EXTINT15_5          (PORT_FUNCA | PORTB | PORT_PIN31)
#define PORT_EIC_EXTINT15_6          (PORT_FUNCA | PORTC | PORT_PIN15)
#define PORT_EIC_EXTINT15_7          (PORT_FUNCA | PORTC | PORT_PIN31)
#define PORT_EIC_NMI                 (PORT_FUNCA | PORTA | PORT_PIN8)

/* Generic Clock Controller (GCLK) */

#define PORT_GCLK_IO0_1              (PORT_FUNCM | PORTA | PORT_PIN14)
#define PORT_GCLK_IO0_2              (PORT_FUNCM | PORTA | PORT_PIN30)
#define PORT_GCLK_IO0_3              (PORT_FUNCM | PORTB | PORT_PIN14)
#define PORT_GCLK_IO0_4              (PORT_FUNCM | PORTB | PORT_PIN22)
#define PORT_GCLK_IO1_1              (PORT_FUNCL | PORTA | PORT_PIN27)
#define PORT_GCLK_IO1_2              (PORT_FUNCM | PORTA | PORT_PIN15)
#define PORT_GCLK_IO1_3              (PORT_FUNCM | PORTB | PORT_PIN15)
#define PORT_GCLK_IO1_4              (PORT_FUNCM | PORTB | PORT_PIN23)
#define PORT_GCLK_IO2_1              (PORT_FUNCM | PORTA | PORT_PIN16)
#define PORT_GCLK_IO2_2              (PORT_FUNCM | PORTB | PORT_PIN16)
#define PORT_GCLK_IO3_1              (PORT_FUNCM | PORTA | PORT_PIN17)
#define PORT_GCLK_IO3_2              (PORT_FUNCM | PORTB | PORT_PIN17)
#define PORT_GCLK_IO4_1              (PORT_FUNCM | PORTA | PORT_PIN10)
#define PORT_GCLK_IO4_2              (PORT_FUNCM | PORTB | PORT_PIN10)
#define PORT_GCLK_IO4_3              (PORT_FUNCM | PORTB | PORT_PIN18)
#define PORT_GCLK_IO5_1              (PORT_FUNCM | PORTA | PORT_PIN11)
#define PORT_GCLK_IO5_2              (PORT_FUNCM | PORTB | PORT_PIN11)
#define PORT_GCLK_IO5_3              (PORT_FUNCM | PORTB | PORT_PIN19)
#define PORT_GCLK_IO6_1              (PORT_FUNCM | PORTB | PORT_PIN12)
#define PORT_GCLK_IO6_2              (PORT_FUNCM | PORTB | PORT_PIN20)
#define PORT_GCLK_IO7_1              (PORT_FUNCM | PORTB | PORT_PIN13)
#define PORT_GCLK_IO7_2              (PORT_FUNCM | PORTB | PORT_PIN21)

/* Ethernet (GMAC) */

#define PORT_GMAC_GCOL               (PORT_FUNCL | PORTC | PORT_PIN21)
#define PORT_GMAC_GCRS               (PORT_FUNCL | PORTA | PORT_PIN16)
#define PORT_GMAC_GMDC_1             (PORT_FUNCL | PORTA | PORT_PIN20)
#define PORT_GMAC_GMDC_2             (PORT_FUNCL | PORTB | PORT_PIN14)
#define PORT_GMAC_GMDC_3             (PORT_FUNCL | PORTC | PORT_PIN11)
#define PORT_GMAC_GMDC_4             (PORT_FUNCL | PORTC | PORT_PIN22)
#define PORT_GMAC_GMDIO_1            (PORT_FUNCL | PORTA | PORT_PIN21)
#define PORT_GMAC_GMDIO_2            (PORT_FUNCL | PORTB | PORT_PIN15)
#define PORT_GMAC_GMDIO_3            (PORT_FUNCL | PORTC | PORT_PIN12)
#define PORT_GMAC_GMDIO_4            (PORT_FUNCL | PORTC | PORT_PIN23)
#define PORT_GMAC_GRX0               (PORT_FUNCL | PORTA | PORT_PIN13)
#define PORT_GMAC_GRX1               (PORT_FUNCL | PORTA | PORT_PIN12)
#define PORT_GMAC_GRX2               (PORT_FUNCL | PORTC | PORT_PIN15)
#define PORT_GMAC_GRX3               (PORT_FUNCL | PORTC | PORT_PIN14)
#define PORT_GMAC_GRXCK              (PORT_FUNCL | PORTC | PORT_PIN18)
#define PORT_GMAC_GRXDV              (PORT_FUNCL | PORTC | PORT_PIN20)
#define PORT_GMAC_GRXER              (PORT_FUNCL | PORTA | PORT_PIN15)
#define PORT_GMAC_GTX0               (PORT_FUNCL | PORTA | PORT_PIN18)
#define PORT_GMAC_GTX1               (PORT_FUNCL | PORTA | PORT_PIN19)
#define PORT_GMAC_GTX2               (PORT_FUNCL | PORTC | PORT_PIN16)
#define PORT_GMAC_GTX3               (PORT_FUNCL | PORTC | PORT_PIN17)
#define PORT_GMAC_GTXCK              (PORT_FUNCL | PORTA | PORT_PIN14)
#define PORT_GMAC_GTXEN              (PORT_FUNCL | PORTA | PORT_PIN17)
#define PORT_GMAC_GTXER              (PORT_FUNCL | PORTC | PORT_PIN19)

/* Inter IC Sound (I2S) */

#define PORT_I2S_FS0_1               (PORT_FUNCJ | PORTA | PORT_PIN20)
#define PORT_I2S_FS0_2               (PORT_FUNCJ | PORTA | PORT_PIN9)
#define PORT_I2S_FS1_1               (PORT_FUNCJ | PORTA | PORT_PIN23)
#define PORT_I2S_FS1_2               (PORT_FUNCJ | PORTB | PORT_PIN11)
#define PORT_I2S_MCK0_1              (PORT_FUNCJ | PORTA | PORT_PIN8)
#define PORT_I2S_MCK0_2              (PORT_FUNCJ | PORTB | PORT_PIN17)
#define PORT_I2S_MCK1_1              (PORT_FUNCJ | PORTB | PORT_PIN13)
#define PORT_I2S_MCK1_2              (PORT_FUNCJ | PORTB | PORT_PIN29)
#define PORT_I2S_SCK0_1              (PORT_FUNCJ | PORTA | PORT_PIN10)
#define PORT_I2S_SCK0_2              (PORT_FUNCJ | PORTB | PORT_PIN16)
#define PORT_I2S_SCK1_1              (PORT_FUNCJ | PORTB | PORT_PIN12)
#define PORT_I2S_SCK1_2              (PORT_FUNCJ | PORTB | PORT_PIN28)
#define PORT_I2S_SDI_1               (PORT_FUNCJ | PORTA | PORT_PIN22)
#define PORT_I2S_SDI_2               (PORT_FUNCJ | PORTB | PORT_PIN10)
#define PORT_I2S_SDO_1               (PORT_FUNCJ | PORTA | PORT_PIN11)
#define PORT_I2S_SDO_2               (PORT_FUNCJ | PORTA | PORT_PIN21)

/* Parallel Capture Controller (PCC) */

#define PORT_PCC_CLK                 (PORT_FUNCK | PORTA | PORT_PIN14)
#define PORT_PCC_DATA0               (PORT_FUNCK | PORTA | PORT_PIN16)
#define PORT_PCC_DATA1               (PORT_FUNCK | PORTA | PORT_PIN17)
#define PORT_PCC_DATA2               (PORT_FUNCK | PORTA | PORT_PIN18)
#define PORT_PCC_DATA3               (PORT_FUNCK | PORTA | PORT_PIN19)
#define PORT_PCC_DATA4               (PORT_FUNCK | PORTA | PORT_PIN20)
#define PORT_PCC_DATA5               (PORT_FUNCK | PORTA | PORT_PIN21)
#define PORT_PCC_DATA6               (PORT_FUNCK | PORTA | PORT_PIN22)
#define PORT_PCC_DATA7               (PORT_FUNCK | PORTA | PORT_PIN23)
#define PORT_PCC_DATA8               (PORT_FUNCK | PORTB | PORT_PIN14)
#define PORT_PCC_DATA9               (PORT_FUNCK | PORTB | PORT_PIN15)
#define PORT_PCC_DATA10              (PORT_FUNCK | PORTC | PORT_PIN12)
#define PORT_PCC_DATA11              (PORT_FUNCK | PORTC | PORT_PIN13)
#define PORT_PCC_DATA12              (PORT_FUNCK | PORTC | PORT_PIN14)
#define PORT_PCC_DATA13              (PORT_FUNCK | PORTC | PORT_PIN15)
#define PORT_PCC_DEN1                (PORT_FUNCK | PORTA | PORT_PIN12)
#define PORT_PCC_DEN2                (PORT_FUNCK | PORTA | PORT_PIN13)

/* Position Decoder (PDEC) */

#define PORT_PDEC_QDI0_1             (PORT_FUNCG | PORTA | PORT_PIN24)
#define PORT_PDEC_QDI0_2             (PORT_FUNCG | PORTB | PORT_PIN18)
#define PORT_PDEC_QDI0_3             (PORT_FUNCG | PORTB | PORT_PIN23)
#define PORT_PDEC_QDI0_4             (PORT_FUNCG | PORTC | PORT_PIN16)
#define PORT_PDEC_QDI1_1             (PORT_FUNCG | PORTA | PORT_PIN25)
#define PORT_PDEC_QDI1_2             (PORT_FUNCG | PORTB | PORT_PIN19)
#define PORT_PDEC_QDI1_3             (PORT_FUNCG | PORTB | PORT_PIN24)
#define PORT_PDEC_QDI1_4             (PORT_FUNCG | PORTC | PORT_PIN17)
#define PORT_PDEC_QDI2_1             (PORT_FUNCG | PORTB | PORT_PIN20)
#define PORT_PDEC_QDI2_2             (PORT_FUNCG | PORTB | PORT_PIN22)
#define PORT_PDEC_QDI2_3             (PORT_FUNCG | PORTB | PORT_PIN25)
#define PORT_PDEC_QDI2_4             (PORT_FUNCG | PORTC | PORT_PIN18)

/* Peripheral Touch Controller (PTC) */

#define PORT_PTC_X0_Y0               (PORT_FUNCB | PORTA | PORT_PIN3)
#define PORT_PTC_X1_Y1               (PORT_FUNCB | PORTB | PORT_PIN8)
#define PORT_PTC_X2_Y2               (PORT_FUNCB | PORTB | PORT_PIN9)
#define PORT_PTC_X3_Y3               (PORT_FUNCB | PORTA | PORT_PIN4)
#define PORT_PTC_X4_Y4               (PORT_FUNCB | PORTA | PORT_PIN6)
#define PORT_PTC_X5_Y5               (PORT_FUNCB | PORTA | PORT_PIN7)
#define PORT_PTC_X6_Y6               (PORT_FUNCB | PORTA | PORT_PIN8)
#define PORT_PTC_X7_Y7               (PORT_FUNCB | PORTA | PORT_PIN9)
#define PORT_PTC_X8_Y8               (PORT_FUNCB | PORTA | PORT_PIN10)
#define PORT_PTC_X9_Y9               (PORT_FUNCB | PORTA | PORT_PIN11)
#define PORT_PTC_X10_Y10             (PORT_FUNCB | PORTA | PORT_PIN16)
#define PORT_PTC_X11_Y11             (PORT_FUNCB | PORTA | PORT_PIN17)
#define PORT_PTC_X12_Y12             (PORT_FUNCB | PORTA | PORT_PIN18)
#define PORT_PTC_X13_Y13             (PORT_FUNCB | PORTA | PORT_PIN19)
#define PORT_PTC_X14_Y14             (PORT_FUNCB | PORTA | PORT_PIN20)
#define PORT_PTC_X15_Y15             (PORT_FUNCB | PORTA | PORT_PIN21)
#define PORT_PTC_X16_Y16             (PORT_FUNCB | PORTA | PORT_PIN22)
#define PORT_PTC_X17_Y17             (PORT_FUNCB | PORTA | PORT_PIN23)
#define PORT_PTC_X18_Y18             (PORT_FUNCB | PORTA | PORT_PIN27)
#define PORT_PTC_X19_Y19             (PORT_FUNCB | PORTA | PORT_PIN30)
#define PORT_PTC_X20_Y20             (PORT_FUNCB | PORTB | PORT_PIN2)
#define PORT_PTC_X21_Y21             (PORT_FUNCB | PORTB | PORT_PIN3)
#define PORT_PTC_X22_Y22             (PORT_FUNCB | PORTB | PORT_PIN4)
#define PORT_PTC_X23_Y23             (PORT_FUNCB | PORTB | PORT_PIN5)
#define PORT_PTC_X24_Y24             (PORT_FUNCB | PORTB | PORT_PIN6)
#define PORT_PTC_X25_Y25             (PORT_FUNCB | PORTB | PORT_PIN7)
#define PORT_PTC_X26_Y26             (PORT_FUNCB | PORTB | PORT_PIN12)
#define PORT_PTC_X27_Y27             (PORT_FUNCB | PORTB | PORT_PIN13)
#define PORT_PTC_X28_Y28             (PORT_FUNCB | PORTB | PORT_PIN14)
#define PORT_PTC_X29_Y29             (PORT_FUNCB | PORTB | PORT_PIN15)
#define PORT_PTC_X30_Y30             (PORT_FUNCB | PORTB | PORT_PIN0)
#define PORT_PTC_X31_Y31             (PORT_FUNCB | PORTB | PORT_PIN1)

/* Quad SPI (QSPI) */

#define PORT_QSPI_CS                 (PORT_FUNCH | PORTB | PORT_PIN11)
#define PORT_QSPI_DATA0              (PORT_FUNCH | PORTA | PORT_PIN8)
#define PORT_QSPI_DATA1              (PORT_FUNCH | PORTA | PORT_PIN9)
#define PORT_QSPI_DATA2              (PORT_FUNCH | PORTA | PORT_PIN10)
#define PORT_QSPI_DATA3              (PORT_FUNCH | PORTA | PORT_PIN11)
#define PORT_QSPI_SCK                (PORT_FUNCH | PORTB | PORT_PIN10)

/* SDHC Memory Card Controllers */

#define PORT_SDHC0_SDCD_1            (PORT_FUNCI | PORTA | PORT_PIN12)
#define PORT_SDHC0_SDCD_2            (PORT_FUNCI | PORTA | PORT_PIN6)
#define PORT_SDHC0_SDCD_3            (PORT_FUNCI | PORTB | PORT_PIN12)
#define PORT_SDHC0_SDCD_4            (PORT_FUNCI | PORTC | PORT_PIN6)
#define PORT_SDHC0_SDCK              (PORT_FUNCI | PORTB | PORT_PIN11)
#define PORT_SDHC0_SDCMD             (PORT_FUNCI | PORTA | PORT_PIN8)
#define PORT_SDHC0_SDDAT0            (PORT_FUNCI | PORTA | PORT_PIN9)
#define PORT_SDHC0_SDDAT1            (PORT_FUNCI | PORTA | PORT_PIN10)
#define PORT_SDHC0_SDDAT2            (PORT_FUNCI | PORTA | PORT_PIN11)
#define PORT_SDHC0_SDDAT3            (PORT_FUNCI | PORTB | PORT_PIN10)
#define PORT_SDHC0_SDWP_1            (PORT_FUNCI | PORTA | PORT_PIN13)
#define PORT_SDHC0_SDWP_2            (PORT_FUNCI | PORTA | PORT_PIN7)
#define PORT_SDHC0_SDWP_3            (PORT_FUNCI | PORTB | PORT_PIN13)
#define PORT_SDHC0_SDWP_4            (PORT_FUNCI | PORTC | PORT_PIN7)

#define PORT_SDHC1_SDCD_1            (PORT_FUNCI | PORTB | PORT_PIN16)
#define PORT_SDHC1_SDCD_2            (PORT_FUNCI | PORTC | PORT_PIN20)
#define PORT_SDHC1_SDCD_3            (PORT_FUNCI | PORTD | PORT_PIN20)
#define PORT_SDHC1_SDCK              (PORT_FUNCI | PORTA | PORT_PIN21)
#define PORT_SDHC1_SDCMD             (PORT_FUNCI | PORTA | PORT_PIN20)
#define PORT_SDHC1_SDDAT0            (PORT_FUNCI | PORTB | PORT_PIN18)
#define PORT_SDHC1_SDDAT1            (PORT_FUNCI | PORTB | PORT_PIN19)
#define PORT_SDHC1_SDDAT2            (PORT_FUNCI | PORTB | PORT_PIN20)
#define PORT_SDHC1_SDDAT3            (PORT_FUNCI | PORTB | PORT_PIN21)
#define PORT_SDHC1_SDWP_1            (PORT_FUNCI | PORTB | PORT_PIN17)
#define PORT_SDHC1_SDWP_2            (PORT_FUNCI | PORTC | PORT_PIN21)
#define PORT_SDHC1_SDWP_3            (PORT_FUNCI | PORTD | PORT_PIN21)

/* Serial Communication Interfaces (SERCOM) */

#define PORT_SERCOM0_PAD0_1          (PORT_FUNCC | PORTA | PORT_PIN8)
#define PORT_SERCOM0_PAD0_2          (PORT_FUNCC | PORTB | PORT_PIN24)
#define PORT_SERCOM0_PAD0_3          (PORT_FUNCD | PORTA | PORT_PIN4)
#define PORT_SERCOM0_PAD0_4          (PORT_FUNCD | PORTC | PORT_PIN17)
#define PORT_SERCOM0_PAD1_1          (PORT_FUNCC | PORTA | PORT_PIN9)
#define PORT_SERCOM0_PAD1_2          (PORT_FUNCC | PORTB | PORT_PIN25)
#define PORT_SERCOM0_PAD1_3          (PORT_FUNCD | PORTA | PORT_PIN5)
#define PORT_SERCOM0_PAD1_4          (PORT_FUNCD | PORTC | PORT_PIN16)
#define PORT_SERCOM0_PAD2_1          (PORT_FUNCC | PORTA | PORT_PIN10)
#define PORT_SERCOM0_PAD2_2          (PORT_FUNCC | PORTC | PORT_PIN24)
#define PORT_SERCOM0_PAD2_3          (PORT_FUNCD | PORTA | PORT_PIN6)
#define PORT_SERCOM0_PAD2_4          (PORT_FUNCD | PORTC | PORT_PIN18)
#define PORT_SERCOM0_PAD3_1          (PORT_FUNCC | PORTA | PORT_PIN11)
#define PORT_SERCOM0_PAD3_2          (PORT_FUNCC | PORTC | PORT_PIN25)
#define PORT_SERCOM0_PAD3_3          (PORT_FUNCD | PORTA | PORT_PIN7)
#define PORT_SERCOM0_PAD3_4          (PORT_FUNCD | PORTC | PORT_PIN19)

#define PORT_SERCOM1_PAD0_1          (PORT_FUNCC | PORTA | PORT_PIN16)
#define PORT_SERCOM1_PAD0_2          (PORT_FUNCC | PORTC | PORT_PIN22)
#define PORT_SERCOM1_PAD0_3          (PORT_FUNCC | PORTC | PORT_PIN27)
#define PORT_SERCOM1_PAD0_4          (PORT_FUNCD | PORTA | PORT_PIN0)
#define PORT_SERCOM1_PAD1_1          (PORT_FUNCC | PORTA | PORT_PIN17)
#define PORT_SERCOM1_PAD1_2          (PORT_FUNCC | PORTC | PORT_PIN23)
#define PORT_SERCOM1_PAD1_3          (PORT_FUNCC | PORTC | PORT_PIN28)
#define PORT_SERCOM1_PAD1_4          (PORT_FUNCD | PORTA | PORT_PIN1)
#define PORT_SERCOM1_PAD2_1          (PORT_FUNCC | PORTA | PORT_PIN18)
#define PORT_SERCOM1_PAD2_2          (PORT_FUNCC | PORTB | PORT_PIN22)
#define PORT_SERCOM1_PAD2_3          (PORT_FUNCC | PORTD | PORT_PIN20)
#define PORT_SERCOM1_PAD2_4          (PORT_FUNCD | PORTA | PORT_PIN30)
#define PORT_SERCOM1_PAD3_1          (PORT_FUNCC | PORTA | PORT_PIN19)
#define PORT_SERCOM1_PAD3_2          (PORT_FUNCC | PORTB | PORT_PIN23)
#define PORT_SERCOM1_PAD3_3          (PORT_FUNCC | PORTD | PORT_PIN21)
#define PORT_SERCOM1_PAD3_4          (PORT_FUNCD | PORTA | PORT_PIN31)

#define PORT_SERCOM2_PAD0_1          (PORT_FUNCC | PORTA | PORT_PIN12)
#define PORT_SERCOM2_PAD0_2          (PORT_FUNCC | PORTB | PORT_PIN26)
#define PORT_SERCOM2_PAD0_3          (PORT_FUNCD | PORTA | PORT_PIN9)
#define PORT_SERCOM2_PAD0_4          (PORT_FUNCD | PORTB | PORT_PIN25)
#define PORT_SERCOM2_PAD1_1          (PORT_FUNCC | PORTA | PORT_PIN13)
#define PORT_SERCOM2_PAD1_2          (PORT_FUNCC | PORTB | PORT_PIN27)
#define PORT_SERCOM2_PAD1_3          (PORT_FUNCD | PORTA | PORT_PIN8)
#define PORT_SERCOM2_PAD1_4          (PORT_FUNCD | PORTB | PORT_PIN24)
#define PORT_SERCOM2_PAD2_1          (PORT_FUNCC | PORTA | PORT_PIN14)
#define PORT_SERCOM2_PAD2_2          (PORT_FUNCC | PORTB | PORT_PIN28)
#define PORT_SERCOM2_PAD2_3          (PORT_FUNCD | PORTA | PORT_PIN10)
#define PORT_SERCOM2_PAD2_4          (PORT_FUNCD | PORTC | PORT_PIN24)
#define PORT_SERCOM2_PAD3_1          (PORT_FUNCC | PORTA | PORT_PIN15)
#define PORT_SERCOM2_PAD3_2          (PORT_FUNCC | PORTB | PORT_PIN29)
#define PORT_SERCOM2_PAD3_3          (PORT_FUNCD | PORTA | PORT_PIN11)
#define PORT_SERCOM2_PAD3_4          (PORT_FUNCD | PORTC | PORT_PIN25)

#define PORT_SERCOM3_PAD0_1          (PORT_FUNCC | PORTA | PORT_PIN22)
#define PORT_SERCOM3_PAD0_2          (PORT_FUNCC | PORTB | PORT_PIN20)
#define PORT_SERCOM3_PAD0_3          (PORT_FUNCD | PORTA | PORT_PIN17)
#define PORT_SERCOM3_PAD0_4          (PORT_FUNCD | PORTC | PORT_PIN23)
#define PORT_SERCOM3_PAD1_1          (PORT_FUNCC | PORTA | PORT_PIN23)
#define PORT_SERCOM3_PAD1_2          (PORT_FUNCC | PORTB | PORT_PIN21)
#define PORT_SERCOM3_PAD1_3          (PORT_FUNCD | PORTA | PORT_PIN16)
#define PORT_SERCOM3_PAD1_4          (PORT_FUNCD | PORTC | PORT_PIN22)
#define PORT_SERCOM3_PAD2_1          (PORT_FUNCC | PORTA | PORT_PIN24)
#define PORT_SERCOM3_PAD2_2          (PORT_FUNCD | PORTA | PORT_PIN18)
#define PORT_SERCOM3_PAD2_3          (PORT_FUNCD | PORTA | PORT_PIN20)
#define PORT_SERCOM3_PAD2_4          (PORT_FUNCD | PORTD | PORT_PIN20)
#define PORT_SERCOM3_PAD3_1          (PORT_FUNCC | PORTA | PORT_PIN25)
#define PORT_SERCOM3_PAD3_2          (PORT_FUNCD | PORTA | PORT_PIN19)
#define PORT_SERCOM3_PAD3_3          (PORT_FUNCD | PORTA | PORT_PIN21)
#define PORT_SERCOM3_PAD3_4          (PORT_FUNCD | PORTD | PORT_PIN21)

#define PORT_SERCOM4_PAD0_1          (PORT_FUNCC | PORTB | PORT_PIN12)
#define PORT_SERCOM4_PAD0_2          (PORT_FUNCD | PORTA | PORT_PIN13)
#define PORT_SERCOM4_PAD0_3          (PORT_FUNCD | PORTB | PORT_PIN27)
#define PORT_SERCOM4_PAD0_4          (PORT_FUNCD | PORTB | PORT_PIN8)
#define PORT_SERCOM4_PAD1_1          (PORT_FUNCC | PORTB | PORT_PIN13)
#define PORT_SERCOM4_PAD1_2          (PORT_FUNCD | PORTA | PORT_PIN12)
#define PORT_SERCOM4_PAD1_3          (PORT_FUNCD | PORTB | PORT_PIN26)
#define PORT_SERCOM4_PAD1_4          (PORT_FUNCD | PORTB | PORT_PIN9)
#define PORT_SERCOM4_PAD2_1          (PORT_FUNCC | PORTB | PORT_PIN14)
#define PORT_SERCOM4_PAD2_2          (PORT_FUNCD | PORTA | PORT_PIN14)
#define PORT_SERCOM4_PAD2_3          (PORT_FUNCD | PORTB | PORT_PIN10)
#define PORT_SERCOM4_PAD2_4          (PORT_FUNCD | PORTB | PORT_PIN28)
#define PORT_SERCOM4_PAD3_1          (PORT_FUNCC | PORTB | PORT_PIN15)
#define PORT_SERCOM4_PAD3_2          (PORT_FUNCD | PORTA | PORT_PIN15)
#define PORT_SERCOM4_PAD3_3          (PORT_FUNCD | PORTB | PORT_PIN11)
#define PORT_SERCOM4_PAD3_4          (PORT_FUNCD | PORTB | PORT_PIN29)

#define PORT_SERCOM5_PAD0_1          (PORT_FUNCC | PORTB | PORT_PIN16)
#define PORT_SERCOM5_PAD0_2          (PORT_FUNCD | PORTA | PORT_PIN23)
#define PORT_SERCOM5_PAD0_3          (PORT_FUNCD | PORTB | PORT_PIN2)
#define PORT_SERCOM5_PAD0_4          (PORT_FUNCD | PORTB | PORT_PIN31)
#define PORT_SERCOM5_PAD1_1          (PORT_FUNCC | PORTB | PORT_PIN17)
#define PORT_SERCOM5_PAD1_2          (PORT_FUNCD | PORTA | PORT_PIN22)
#define PORT_SERCOM5_PAD1_3          (PORT_FUNCD | PORTB | PORT_PIN3)
#define PORT_SERCOM5_PAD1_4          (PORT_FUNCD | PORTB | PORT_PIN30)
#define PORT_SERCOM5_PAD2_1          (PORT_FUNCC | PORTA | PORT_PIN20)
#define PORT_SERCOM5_PAD2_2          (PORT_FUNCC | PORTB | PORT_PIN18)
#define PORT_SERCOM5_PAD2_3          (PORT_FUNCD | PORTA | PORT_PIN24)
#define PORT_SERCOM5_PAD2_4          (PORT_FUNCD | PORTB | PORT_PIN0)
#define PORT_SERCOM5_PAD2_5          (PORT_FUNCD | PORTB | PORT_PIN22)
#define PORT_SERCOM5_PAD3_1          (PORT_FUNCC | PORTA | PORT_PIN21)
#define PORT_SERCOM5_PAD3_2          (PORT_FUNCC | PORTB | PORT_PIN19)
#define PORT_SERCOM5_PAD3_3          (PORT_FUNCD | PORTA | PORT_PIN25)
#define PORT_SERCOM5_PAD3_4          (PORT_FUNCD | PORTB | PORT_PIN1)
#define PORT_SERCOM5_PAD3_5          (PORT_FUNCD | PORTB | PORT_PIN23)

#define PORT_SERCOM6_PAD0_1          (PORT_FUNCC | PORTC | PORT_PIN16)
#define PORT_SERCOM6_PAD0_2          (PORT_FUNCC | PORTC | PORT_PIN4)
#define PORT_SERCOM6_PAD0_3          (PORT_FUNCD | PORTC | PORT_PIN13)
#define PORT_SERCOM6_PAD0_4          (PORT_FUNCD | PORTD | PORT_PIN9)
#define PORT_SERCOM6_PAD1_1          (PORT_FUNCC | PORTC | PORT_PIN17)
#define PORT_SERCOM6_PAD1_2          (PORT_FUNCC | PORTC | PORT_PIN5)
#define PORT_SERCOM6_PAD1_3          (PORT_FUNCD | PORTC | PORT_PIN12)
#define PORT_SERCOM6_PAD1_4          (PORT_FUNCD | PORTD | PORT_PIN8)
#define PORT_SERCOM6_PAD2_1          (PORT_FUNCC | PORTC | PORT_PIN10)
#define PORT_SERCOM6_PAD2_2          (PORT_FUNCC | PORTC | PORT_PIN18)
#define PORT_SERCOM6_PAD2_3          (PORT_FUNCC | PORTC | PORT_PIN6)
#define PORT_SERCOM6_PAD2_4          (PORT_FUNCD | PORTC | PORT_PIN14)
#define PORT_SERCOM6_PAD2_5          (PORT_FUNCD | PORTD | PORT_PIN10)
#define PORT_SERCOM6_PAD3_1          (PORT_FUNCC | PORTC | PORT_PIN11)
#define PORT_SERCOM6_PAD3_2          (PORT_FUNCC | PORTC | PORT_PIN19)
#define PORT_SERCOM6_PAD3_3          (PORT_FUNCC | PORTC | PORT_PIN7)
#define PORT_SERCOM6_PAD3_4          (PORT_FUNCD | PORTC | PORT_PIN15)
#define PORT_SERCOM6_PAD3_5          (PORT_FUNCD | PORTD | PORT_PIN11)

#define PORT_SERCOM7_PAD0_1          (PORT_FUNCC | PORTB | PORT_PIN30)
#define PORT_SERCOM7_PAD0_2          (PORT_FUNCC | PORTC | PORT_PIN12)
#define PORT_SERCOM7_PAD0_3          (PORT_FUNCC | PORTD | PORT_PIN8)
#define PORT_SERCOM7_PAD0_4          (PORT_FUNCD | PORTB | PORT_PIN21)
#define PORT_SERCOM7_PAD1_1          (PORT_FUNCC | PORTB | PORT_PIN31)
#define PORT_SERCOM7_PAD1_2          (PORT_FUNCC | PORTC | PORT_PIN13)
#define PORT_SERCOM7_PAD1_3          (PORT_FUNCC | PORTD | PORT_PIN9)
#define PORT_SERCOM7_PAD1_4          (PORT_FUNCD | PORTB | PORT_PIN20)
#define PORT_SERCOM7_PAD2_1          (PORT_FUNCC | PORTA | PORT_PIN30)
#define PORT_SERCOM7_PAD2_2          (PORT_FUNCC | PORTC | PORT_PIN14)
#define PORT_SERCOM7_PAD2_3          (PORT_FUNCC | PORTD | PORT_PIN10)
#define PORT_SERCOM7_PAD2_4          (PORT_FUNCD | PORTB | PORT_PIN18)
#define PORT_SERCOM7_PAD2_5          (PORT_FUNCD | PORTC | PORT_PIN10)
#define PORT_SERCOM7_PAD3_1          (PORT_FUNCC | PORTA | PORT_PIN31)
#define PORT_SERCOM7_PAD3_2          (PORT_FUNCC | PORTC | PORT_PIN15)
#define PORT_SERCOM7_PAD3_3          (PORT_FUNCC | PORTD | PORT_PIN11)
#define PORT_SERCOM7_PAD3_4          (PORT_FUNCD | PORTB | PORT_PIN19)
#define PORT_SERCOM7_PAD3_5          (PORT_FUNCD | PORTC | PORT_PIN11)

/* Timer/Counters (TC) */

#define PORT_TC0_WO0_1               (PORT_FUNCE | PORTA | PORT_PIN4)
#define PORT_TC0_WO0_2               (PORT_FUNCE | PORTA | PORT_PIN8)
#define PORT_TC0_WO0_3               (PORT_FUNCE | PORTB | PORT_PIN30)
#define PORT_TC0_WO1_1               (PORT_FUNCE | PORTA | PORT_PIN5)
#define PORT_TC0_WO1_2               (PORT_FUNCE | PORTA | PORT_PIN9)
#define PORT_TC0_WO1_3               (PORT_FUNCE | PORTB | PORT_PIN31)

#define PORT_TC1_WO0_1               (PORT_FUNCE | PORTA | PORT_PIN10)
#define PORT_TC1_WO0_2               (PORT_FUNCE | PORTA | PORT_PIN6)
#define PORT_TC1_WO1_1               (PORT_FUNCE | PORTA | PORT_PIN11)
#define PORT_TC1_WO1_2               (PORT_FUNCE | PORTA | PORT_PIN7)

#define PORT_TC2_WO0_1               (PORT_FUNCE | PORTA | PORT_PIN0)
#define PORT_TC2_WO0_2               (PORT_FUNCE | PORTA | PORT_PIN12)
#define PORT_TC2_WO0_3               (PORT_FUNCE | PORTA | PORT_PIN16)
#define PORT_TC2_WO1_1               (PORT_FUNCE | PORTA | PORT_PIN1)
#define PORT_TC2_WO1_2               (PORT_FUNCE | PORTA | PORT_PIN13)
#define PORT_TC2_WO1_3               (PORT_FUNCE | PORTA | PORT_PIN17)

#define PORT_TC3_WO0_1               (PORT_FUNCE | PORTA | PORT_PIN14)
#define PORT_TC3_WO0_2               (PORT_FUNCE | PORTA | PORT_PIN18)
#define PORT_TC3_WO1_1               (PORT_FUNCE | PORTA | PORT_PIN15)
#define PORT_TC3_WO1_2               (PORT_FUNCE | PORTA | PORT_PIN19)

#define PORT_TC4_WO0_1               (PORT_FUNCE | PORTA | PORT_PIN22)
#define PORT_TC4_WO0_2               (PORT_FUNCE | PORTB | PORT_PIN12)
#define PORT_TC4_WO0_3               (PORT_FUNCE | PORTB | PORT_PIN8)
#define PORT_TC4_WO1_1               (PORT_FUNCE | PORTA | PORT_PIN23)
#define PORT_TC4_WO1_2               (PORT_FUNCE | PORTB | PORT_PIN13)
#define PORT_TC4_WO1_3               (PORT_FUNCE | PORTB | PORT_PIN9)

#define PORT_TC5_WO0_1               (PORT_FUNCE | PORTA | PORT_PIN24)
#define PORT_TC5_WO0_2               (PORT_FUNCE | PORTB | PORT_PIN10)
#define PORT_TC5_WO0_3               (PORT_FUNCE | PORTB | PORT_PIN14)
#define PORT_TC5_WO1_1               (PORT_FUNCE | PORTA | PORT_PIN25)
#define PORT_TC5_WO1_2               (PORT_FUNCE | PORTB | PORT_PIN11)
#define PORT_TC5_WO1_3               (PORT_FUNCE | PORTB | PORT_PIN15)

#define PORT_TC6_WO0_1               (PORT_FUNCE | PORTA | PORT_PIN30)
#define PORT_TC6_WO0_2               (PORT_FUNCE | PORTB | PORT_PIN16)
#define PORT_TC6_WO0_3               (PORT_FUNCE | PORTB | PORT_PIN2)
#define PORT_TC6_WO1_1               (PORT_FUNCE | PORTA | PORT_PIN31)
#define PORT_TC6_WO1_2               (PORT_FUNCE | PORTB | PORT_PIN17)
#define PORT_TC6_WO1_3               (PORT_FUNCE | PORTB | PORT_PIN3)

#define PORT_TC7_WO0_1               (PORT_FUNCE | PORTA | PORT_PIN20)
#define PORT_TC7_WO0_2               (PORT_FUNCE | PORTB | PORT_PIN0)
#define PORT_TC7_WO0_3               (PORT_FUNCE | PORTB | PORT_PIN22)
#define PORT_TC7_WO1_1               (PORT_FUNCE | PORTA | PORT_PIN21)
#define PORT_TC7_WO1_2               (PORT_FUNCE | PORTB | PORT_PIN1)
#define PORT_TC7_WO1_3               (PORT_FUNCE | PORTB | PORT_PIN23)

/* Timer/Counters Control (TCC) */

#define PORT_TCC0_WO0_1              (PORT_FUNCF | PORTA | PORT_PIN8)
#define PORT_TCC0_WO0_2              (PORT_FUNCF | PORTC | PORT_PIN10)
#define PORT_TCC0_WO0_3              (PORT_FUNCF | PORTC | PORT_PIN16)
#define PORT_TCC0_WO0_4              (PORT_FUNCF | PORTC | PORT_PIN4)
#define PORT_TCC0_WO0_5              (PORT_FUNCG | PORTA | PORT_PIN20)
#define PORT_TCC0_WO0_6              (PORT_FUNCG | PORTB | PORT_PIN12)
#define PORT_TCC0_WO1_1              (PORT_FUNCF | PORTA | PORT_PIN9)
#define PORT_TCC0_WO1_2              (PORT_FUNCF | PORTC | PORT_PIN11)
#define PORT_TCC0_WO1_3              (PORT_FUNCF | PORTC | PORT_PIN17)
#define PORT_TCC0_WO1_4              (PORT_FUNCF | PORTD | PORT_PIN8)
#define PORT_TCC0_WO1_5              (PORT_FUNCG | PORTA | PORT_PIN21)
#define PORT_TCC0_WO1_6              (PORT_FUNCG | PORTB | PORT_PIN13)
#define PORT_TCC0_WO2_1              (PORT_FUNCF | PORTA | PORT_PIN10)
#define PORT_TCC0_WO2_2              (PORT_FUNCF | PORTC | PORT_PIN12)
#define PORT_TCC0_WO2_3              (PORT_FUNCF | PORTC | PORT_PIN18)
#define PORT_TCC0_WO2_4              (PORT_FUNCF | PORTD | PORT_PIN9)
#define PORT_TCC0_WO2_5              (PORT_FUNCG | PORTA | PORT_PIN22)
#define PORT_TCC0_WO2_6              (PORT_FUNCG | PORTB | PORT_PIN14)
#define PORT_TCC0_WO3_1              (PORT_FUNCF | PORTA | PORT_PIN11)
#define PORT_TCC0_WO3_2              (PORT_FUNCF | PORTC | PORT_PIN13)
#define PORT_TCC0_WO3_3              (PORT_FUNCF | PORTC | PORT_PIN19)
#define PORT_TCC0_WO3_4              (PORT_FUNCF | PORTD | PORT_PIN10)
#define PORT_TCC0_WO3_5              (PORT_FUNCG | PORTA | PORT_PIN23)
#define PORT_TCC0_WO3_6              (PORT_FUNCG | PORTB | PORT_PIN15)
#define PORT_TCC0_WO4_1              (PORT_FUNCF | PORTB | PORT_PIN10)
#define PORT_TCC0_WO4_2              (PORT_FUNCF | PORTC | PORT_PIN14)
#define PORT_TCC0_WO4_3              (PORT_FUNCF | PORTC | PORT_PIN20)
#define PORT_TCC0_WO4_4              (PORT_FUNCF | PORTD | PORT_PIN11)
#define PORT_TCC0_WO4_5              (PORT_FUNCG | PORTA | PORT_PIN16)
#define PORT_TCC0_WO4_6              (PORT_FUNCG | PORTB | PORT_PIN16)
#define PORT_TCC0_WO5_1              (PORT_FUNCF | PORTB | PORT_PIN11)
#define PORT_TCC0_WO5_2              (PORT_FUNCF | PORTC | PORT_PIN15)
#define PORT_TCC0_WO5_3              (PORT_FUNCF | PORTC | PORT_PIN21)
#define PORT_TCC0_WO5_4              (PORT_FUNCF | PORTD | PORT_PIN12)
#define PORT_TCC0_WO5_5              (PORT_FUNCG | PORTA | PORT_PIN17)
#define PORT_TCC0_WO5_6              (PORT_FUNCG | PORTB | PORT_PIN17)
#define PORT_TCC0_WO6_1              (PORT_FUNCF | PORTA | PORT_PIN12)
#define PORT_TCC0_WO6_2              (PORT_FUNCF | PORTC | PORT_PIN22)
#define PORT_TCC0_WO6_3              (PORT_FUNCG | PORTA | PORT_PIN18)
#define PORT_TCC0_WO6_4              (PORT_FUNCG | PORTB | PORT_PIN30)
#define PORT_TCC0_WO7_1              (PORT_FUNCF | PORTA | PORT_PIN13)
#define PORT_TCC0_WO7_2              (PORT_FUNCF | PORTC | PORT_PIN23)
#define PORT_TCC0_WO7_3              (PORT_FUNCG | PORTA | PORT_PIN19)
#define PORT_TCC0_WO7_4              (PORT_FUNCG | PORTB | PORT_PIN31)

#define PORT_TCC1_WO0_1              (PORT_FUNCF | PORTA | PORT_PIN16)
#define PORT_TCC1_WO0_2              (PORT_FUNCF | PORTB | PORT_PIN18)
#define PORT_TCC1_WO0_3              (PORT_FUNCF | PORTD | PORT_PIN20)
#define PORT_TCC1_WO0_4              (PORT_FUNCG | PORTB | PORT_PIN10)
#define PORT_TCC1_WO0_5              (PORT_FUNCG | PORTC | PORT_PIN14)
#define PORT_TCC1_WO1_1              (PORT_FUNCF | PORTA | PORT_PIN17)
#define PORT_TCC1_WO1_2              (PORT_FUNCF | PORTB | PORT_PIN19)
#define PORT_TCC1_WO1_3              (PORT_FUNCF | PORTD | PORT_PIN21)
#define PORT_TCC1_WO1_4              (PORT_FUNCG | PORTB | PORT_PIN11)
#define PORT_TCC1_WO1_5              (PORT_FUNCG | PORTC | PORT_PIN15)
#define PORT_TCC1_WO2_1              (PORT_FUNCF | PORTA | PORT_PIN18)
#define PORT_TCC1_WO2_2              (PORT_FUNCF | PORTB | PORT_PIN20)
#define PORT_TCC1_WO2_3              (PORT_FUNCF | PORTB | PORT_PIN26)
#define PORT_TCC1_WO2_4              (PORT_FUNCG | PORTA | PORT_PIN12)
#define PORT_TCC1_WO2_5              (PORT_FUNCG | PORTA | PORT_PIN14)
#define PORT_TCC1_WO3_1              (PORT_FUNCF | PORTA | PORT_PIN19)
#define PORT_TCC1_WO3_2              (PORT_FUNCF | PORTB | PORT_PIN21)
#define PORT_TCC1_WO3_3              (PORT_FUNCF | PORTB | PORT_PIN27)
#define PORT_TCC1_WO3_4              (PORT_FUNCG | PORTA | PORT_PIN13)
#define PORT_TCC1_WO3_5              (PORT_FUNCG | PORTA | PORT_PIN15)
#define PORT_TCC1_WO4_1              (PORT_FUNCF | PORTA | PORT_PIN20)
#define PORT_TCC1_WO4_2              (PORT_FUNCF | PORTB | PORT_PIN28)
#define PORT_TCC1_WO4_3              (PORT_FUNCG | PORTA | PORT_PIN8)
#define PORT_TCC1_WO4_4              (PORT_FUNCG | PORTC | PORT_PIN10)
#define PORT_TCC1_WO5_1              (PORT_FUNCF | PORTA | PORT_PIN21)
#define PORT_TCC1_WO5_2              (PORT_FUNCF | PORTB | PORT_PIN29)
#define PORT_TCC1_WO5_3              (PORT_FUNCG | PORTA | PORT_PIN9)
#define PORT_TCC1_WO5_4              (PORT_FUNCG | PORTC | PORT_PIN11)
#define PORT_TCC1_WO6_1              (PORT_FUNCF | PORTA | PORT_PIN22)
#define PORT_TCC1_WO6_2              (PORT_FUNCG | PORTA | PORT_PIN10)
#define PORT_TCC1_WO6_3              (PORT_FUNCG | PORTC | PORT_PIN12)
#define PORT_TCC1_WO7_1              (PORT_FUNCF | PORTA | PORT_PIN23)
#define PORT_TCC1_WO7_2              (PORT_FUNCG | PORTA | PORT_PIN11)
#define PORT_TCC1_WO7_3              (PORT_FUNCG | PORTC | PORT_PIN13)

#define PORT_TCC2_WO0_1              (PORT_FUNCF | PORTA | PORT_PIN14)
#define PORT_TCC2_WO0_2              (PORT_FUNCF | PORTA | PORT_PIN30)
#define PORT_TCC2_WO1_1              (PORT_FUNCF | PORTA | PORT_PIN15)
#define PORT_TCC2_WO1_2              (PORT_FUNCF | PORTA | PORT_PIN31)
#define PORT_TCC2_WO2_1              (PORT_FUNCF | PORTA | PORT_PIN24)
#define PORT_TCC2_WO2_2              (PORT_FUNCF | PORTB | PORT_PIN2)

#define PORT_TCC3_WO0_1              (PORT_FUNCF | PORTB | PORT_PIN12)
#define PORT_TCC3_WO0_2              (PORT_FUNCF | PORTB | PORT_PIN16)
#define PORT_TCC3_WO1_1              (PORT_FUNCF | PORTB | PORT_PIN13)
#define PORT_TCC3_WO1_2              (PORT_FUNCF | PORTB | PORT_PIN17)

#define PORT_TCC4_WO0_1              (PORT_FUNCF | PORTB | PORT_PIN14)
#define PORT_TCC4_WO0_2              (PORT_FUNCF | PORTB | PORT_PIN30)
#define PORT_TCC4_WO1_1              (PORT_FUNCF | PORTB | PORT_PIN15)
#define PORT_TCC4_WO1_2              (PORT_FUNCF | PORTB | PORT_PIN31)

/* USB */

#define PORT_USB_DM                  (PORT_FUNCH | PORTA | PORT_PIN24)
#define PORT_USB_DP                  (PORT_FUNCH | PORTA | PORT_PIN25)
#define PORT_USB_SOF_1KHZ_1          (PORT_FUNCH | PORTA | PORT_PIN23)
#define PORT_USB_SOF_1KHZ_2          (PORT_FUNCH | PORTB | PORT_PIN22)

/********************************************************************************************
 * Public Types
 ********************************************************************************************/

/********************************************************************************************
 * Public Data
 ********************************************************************************************/

/********************************************************************************************
 * Public Functions
 ********************************************************************************************/

#endif /* __ARCH_ARM_SRC_SAMD5E5_HARDWARE_SAMD5E5_PINMAP_H */
