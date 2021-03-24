/****************************************************************************
 * arch/arm/src/kinetis/hardware/kinetis_port.h
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

#ifndef __ARCH_ARM_SRC_KINETIS_HARDWARE_KINETIS_PORT_H
#define __ARCH_ARM_SRC_KINETIS_HARDWARE_KINETIS_PORT_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "chip.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* General Definitions ******************************************************/

#define KINETIS_PORTA              (0)
#define KINETIS_PORTB              (1)
#define KINETIS_PORTC              (2)
#define KINETIS_PORTD              (3)
#define KINETIS_PORTE              (4)
#define KINETIS_NPORTS             (5)

/* Register Offsets *********************************************************/

#define KINETIS_PORT_PCR_OFFSET(n) ((n) << 2) /* Pin Control Register n, n=0..31 */

#define KINETIS_PORT_PCR0_OFFSET   0x0000 /* Pin Control Register 0 */
#define KINETIS_PORT_PCR1_OFFSET   0x0004 /* Pin Control Register 1 */
#define KINETIS_PORT_PCR2_OFFSET   0x0008 /* Pin Control Register 2 */
#define KINETIS_PORT_PCR3_OFFSET   0x000C /* Pin Control Register 3 */
#define KINETIS_PORT_PCR4_OFFSET   0x0010 /* Pin Control Register 4 */
#define KINETIS_PORT_PCR5_OFFSET   0x0014 /* Pin Control Register 5 */
#define KINETIS_PORT_PCR6_OFFSET   0x0018 /* Pin Control Register 6 */
#define KINETIS_PORT_PCR7_OFFSET   0x001c /* Pin Control Register 7 */
#define KINETIS_PORT_PCR8_OFFSET   0x0020 /* Pin Control Register 8 */
#define KINETIS_PORT_PCR9_OFFSET   0x0024 /* Pin Control Register 9 */
#define KINETIS_PORT_PCR10_OFFSET  0x0028 /* Pin Control Register 10 */
#define KINETIS_PORT_PCR11_OFFSET  0x002c /* Pin Control Register 11 */
#define KINETIS_PORT_PCR12_OFFSET  0x0030 /* Pin Control Register 12 */
#define KINETIS_PORT_PCR13_OFFSET  0x0034 /* Pin Control Register 13 */
#define KINETIS_PORT_PCR14_OFFSET  0x0038 /* Pin Control Register 14 */
#define KINETIS_PORT_PCR15_OFFSET  0x003c /* Pin Control Register 15 */
#define KINETIS_PORT_PCR16_OFFSET  0x0040 /* Pin Control Register 16 */
#define KINETIS_PORT_PCR17_OFFSET  0x0044 /* Pin Control Register 17 */
#define KINETIS_PORT_PCR18_OFFSET  0x0048 /* Pin Control Register 18 */
#define KINETIS_PORT_PCR19_OFFSET  0x004c /* Pin Control Register 19 */
#define KINETIS_PORT_PCR20_OFFSET  0x0050 /* Pin Control Register 20 */
#define KINETIS_PORT_PCR21_OFFSET  0x0054 /* Pin Control Register 21 */
#define KINETIS_PORT_PCR22_OFFSET  0x0058 /* Pin Control Register 22 */
#define KINETIS_PORT_PCR23_OFFSET  0x005c /* Pin Control Register 23 */
#define KINETIS_PORT_PCR24_OFFSET  0x0060 /* Pin Control Register 24 */
#define KINETIS_PORT_PCR25_OFFSET  0x0064 /* Pin Control Register 25 */
#define KINETIS_PORT_PCR26_OFFSET  0x0068 /* Pin Control Register 26 */
#define KINETIS_PORT_PCR27_OFFSET  0x006c /* Pin Control Register 27 */
#define KINETIS_PORT_PCR28_OFFSET  0x0070 /* Pin Control Register 28 */
#define KINETIS_PORT_PCR29_OFFSET  0x0074 /* Pin Control Register 29 */
#define KINETIS_PORT_PCR30_OFFSET  0x0078 /* Pin Control Register 30 */
#define KINETIS_PORT_PCR31_OFFSET  0x007c /* Pin Control Register 31 */
#define KINETIS_PORT_GPCLR_OFFSET  0x0080 /* Global Pin Control Low Register */
#define KINETIS_PORT_GPCHR_OFFSET  0x0084 /* Global Pin Control High Register */
#define KINETIS_PORT_ISFR_OFFSET   0x00a0 /* Interrupt Status Flag Register */
#define KINETIS_PORT_DFER_OFFSET   0x00c0 /* Digital Filter Enable Register */
#define KINETIS_PORT_DFCR_OFFSET   0x00c4 /* Digital Filter Clock Register */
#define KINETIS_PORT_DFWR_OFFSET   0x00c8 /* Digital Filter Width Register */

/* Register Addresses *******************************************************/

#define KINETIS_PORT_PCR(p,n)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR_OFFSET(n)
#define KINETIS_PORT_PCR0(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR0_OFFSET)
#define KINETIS_PORT_PCR1(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR1_OFFSET)
#define KINETIS_PORT_PCR2(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR2_OFFSET)
#define KINETIS_PORT_PCR3(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR3_OFFSET)
#define KINETIS_PORT_PCR4(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR4_OFFSET)
#define KINETIS_PORT_PCR5(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR5_OFFSET)
#define KINETIS_PORT_PCR6(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR6_OFFSET)
#define KINETIS_PORT_PCR7(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR7_OFFSET)
#define KINETIS_PORT_PCR8(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR8_OFFSET)
#define KINETIS_PORT_PCR9(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR9_OFFSET)
#define KINETIS_PORT_PCR10(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR10_OFFSET)
#define KINETIS_PORT_PCR11(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR11_OFFSET)
#define KINETIS_PORT_PCR12(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR12_OFFSET)
#define KINETIS_PORT_PCR13(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR13_OFFSET)
#define KINETIS_PORT_PCR14(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR14_OFFSET)
#define KINETIS_PORT_PCR15(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR15_OFFSET)
#define KINETIS_PORT_PCR16(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR16_OFFSET)
#define KINETIS_PORT_PCR17(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR17_OFFSET)
#define KINETIS_PORT_PCR18(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR18_OFFSET)
#define KINETIS_PORT_PCR19(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR19_OFFSET)
#define KINETIS_PORT_PCR20(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR20_OFFSET)
#define KINETIS_PORT_PCR21(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR21_OFFSET)
#define KINETIS_PORT_PCR22(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR22_OFFSET)
#define KINETIS_PORT_PCR23(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR23_OFFSET)
#define KINETIS_PORT_PCR24(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR24_OFFSET)
#define KINETIS_PORT_PCR25(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR25_OFFSET)
#define KINETIS_PORT_PCR26(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR26_OFFSET)
#define KINETIS_PORT_PCR27(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR27_OFFSET)
#define KINETIS_PORT_PCR28(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR28_OFFSET)
#define KINETIS_PORT_PCR29(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR29_OFFSET)
#define KINETIS_PORT_PCR30(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR30_OFFSET)
#define KINETIS_PORT_PCR31(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_PCR31_OFFSET)
#define KINETIS_PORT_GPCLR(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_GPCLR_OFFSET)
#define KINETIS_PORT_GPCHR(p)      (KINETIS_PORT_BASE(p)+KINETIS_PORT_GPCHR_OFFSET)
#define KINETIS_PORT_ISFR(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_ISFR_OFFSET)
#define KINETIS_PORT_DFER(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_DFER_OFFSET)
#define KINETIS_PORT_DFCR(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_DFCR_OFFSET)
#define KINETIS_PORT_DFWR(p)       (KINETIS_PORT_BASE(p)+KINETIS_PORT_DFWR_OFFSET)

#define KINETIS_PORTA_PCR(n)       (KINETIS_PORTA_BASE+KINETIS_PORT_PCR_OFFSET(n)
#define KINETIS_PORTA_PCR0         (KINETIS_PORTA_BASE+KINETIS_PORT_PCR0_OFFSET)
#define KINETIS_PORTA_PCR1         (KINETIS_PORTA_BASE+KINETIS_PORT_PCR1_OFFSET)
#define KINETIS_PORTA_PCR2         (KINETIS_PORTA_BASE+KINETIS_PORT_PCR2_OFFSET)
#define KINETIS_PORTA_PCR3         (KINETIS_PORTA_BASE+KINETIS_PORT_PCR3_OFFSET)
#define KINETIS_PORTA_PCR4         (KINETIS_PORTA_BASE+KINETIS_PORT_PCR4_OFFSET)
#define KINETIS_PORTA_PCR5         (KINETIS_PORTA_BASE+KINETIS_PORT_PCR5_OFFSET)
#define KINETIS_PORTA_PCR6         (KINETIS_PORTA_BASE+KINETIS_PORT_PCR6_OFFSET)
#define KINETIS_PORTA_PCR7         (KINETIS_PORTA_BASE+KINETIS_PORT_PCR7_OFFSET)
#define KINETIS_PORTA_PCR8         (KINETIS_PORTA_BASE+KINETIS_PORT_PCR8_OFFSET)
#define KINETIS_PORTA_PCR9         (KINETIS_PORTA_BASE+KINETIS_PORT_PCR9_OFFSET)
#define KINETIS_PORTA_PCR10        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR10_OFFSET)
#define KINETIS_PORTA_PCR11        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR11_OFFSET)
#define KINETIS_PORTA_PCR12        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR12_OFFSET)
#define KINETIS_PORTA_PCR13        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR13_OFFSET)
#define KINETIS_PORTA_PCR14        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR14_OFFSET)
#define KINETIS_PORTA_PCR15        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR15_OFFSET)
#define KINETIS_PORTA_PCR16        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR16_OFFSET)
#define KINETIS_PORTA_PCR17        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR17_OFFSET)
#define KINETIS_PORTA_PCR18        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR18_OFFSET)
#define KINETIS_PORTA_PCR19        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR19_OFFSET)
#define KINETIS_PORTA_PCR20        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR20_OFFSET)
#define KINETIS_PORTA_PCR21        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR21_OFFSET)
#define KINETIS_PORTA_PCR22        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR22_OFFSET)
#define KINETIS_PORTA_PCR23        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR23_OFFSET)
#define KINETIS_PORTA_PCR24        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR24_OFFSET)
#define KINETIS_PORTA_PCR25        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR25_OFFSET)
#define KINETIS_PORTA_PCR26        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR26_OFFSET)
#define KINETIS_PORTA_PCR27        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR27_OFFSET)
#define KINETIS_PORTA_PCR28        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR28_OFFSET)
#define KINETIS_PORTA_PCR29        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR29_OFFSET)
#define KINETIS_PORTA_PCR30        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR30_OFFSET)
#define KINETIS_PORTA_PCR31        (KINETIS_PORTA_BASE+KINETIS_PORT_PCR31_OFFSET)
#define KINETIS_PORTA_GPCLR        (KINETIS_PORTA_BASE+KINETIS_PORT_GPCLR_OFFSET)
#define KINETIS_PORTA_GPCHR        (KINETIS_PORTA_BASE+KINETIS_PORT_GPCHR_OFFSET)
#define KINETIS_PORTA_ISFR         (KINETIS_PORTA_BASE+KINETIS_PORT_ISFR_OFFSET)
#define KINETIS_PORTA_DFER         (KINETIS_PORTA_BASE+KINETIS_PORT_DFER_OFFSET)
#define KINETIS_PORTA_DFCR         (KINETIS_PORTA_BASE+KINETIS_PORT_DFCR_OFFSET)
#define KINETIS_PORTA_DFWR         (KINETIS_PORTA_BASE+KINETIS_PORT_DFWR_OFFSET)

#define KINETIS_PORTB_PCR(n)       (KINETIS_PORTB_BASE+KINETIS_PORT_PCR_OFFSET(n)
#define KINETIS_PORTB_PCR0         (KINETIS_PORTB_BASE+KINETIS_PORT_PCR0_OFFSET)
#define KINETIS_PORTB_PCR1         (KINETIS_PORTB_BASE+KINETIS_PORT_PCR1_OFFSET)
#define KINETIS_PORTB_PCR2         (KINETIS_PORTB_BASE+KINETIS_PORT_PCR2_OFFSET)
#define KINETIS_PORTB_PCR3         (KINETIS_PORTB_BASE+KINETIS_PORT_PCR3_OFFSET)
#define KINETIS_PORTB_PCR4         (KINETIS_PORTB_BASE+KINETIS_PORT_PCR4_OFFSET)
#define KINETIS_PORTB_PCR5         (KINETIS_PORTB_BASE+KINETIS_PORT_PCR5_OFFSET)
#define KINETIS_PORTB_PCR6         (KINETIS_PORTB_BASE+KINETIS_PORT_PCR6_OFFSET)
#define KINETIS_PORTB_PCR7         (KINETIS_PORTB_BASE+KINETIS_PORT_PCR7_OFFSET)
#define KINETIS_PORTB_PCR8         (KINETIS_PORTB_BASE+KINETIS_PORT_PCR8_OFFSET)
#define KINETIS_PORTB_PCR9         (KINETIS_PORTB_BASE+KINETIS_PORT_PCR9_OFFSET)
#define KINETIS_PORTB_PCR10        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR10_OFFSET)
#define KINETIS_PORTB_PCR11        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR11_OFFSET)
#define KINETIS_PORTB_PCR12        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR12_OFFSET)
#define KINETIS_PORTB_PCR13        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR13_OFFSET)
#define KINETIS_PORTB_PCR14        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR14_OFFSET)
#define KINETIS_PORTB_PCR15        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR15_OFFSET)
#define KINETIS_PORTB_PCR16        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR16_OFFSET)
#define KINETIS_PORTB_PCR17        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR17_OFFSET)
#define KINETIS_PORTB_PCR18        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR18_OFFSET)
#define KINETIS_PORTB_PCR19        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR19_OFFSET)
#define KINETIS_PORTB_PCR20        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR20_OFFSET)
#define KINETIS_PORTB_PCR21        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR21_OFFSET)
#define KINETIS_PORTB_PCR22        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR22_OFFSET)
#define KINETIS_PORTB_PCR23        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR23_OFFSET)
#define KINETIS_PORTB_PCR24        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR24_OFFSET)
#define KINETIS_PORTB_PCR25        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR25_OFFSET)
#define KINETIS_PORTB_PCR26        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR26_OFFSET)
#define KINETIS_PORTB_PCR27        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR27_OFFSET)
#define KINETIS_PORTB_PCR28        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR28_OFFSET)
#define KINETIS_PORTB_PCR29        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR29_OFFSET)
#define KINETIS_PORTB_PCR30        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR30_OFFSET)
#define KINETIS_PORTB_PCR31        (KINETIS_PORTB_BASE+KINETIS_PORT_PCR31_OFFSET)
#define KINETIS_PORTB_GPCLR        (KINETIS_PORTB_BASE+KINETIS_PORT_GPCLR_OFFSET)
#define KINETIS_PORTB_GPCHR        (KINETIS_PORTB_BASE+KINETIS_PORT_GPCHR_OFFSET)
#define KINETIS_PORTB_ISFR         (KINETIS_PORTB_BASE+KINETIS_PORT_ISFR_OFFSET)
#define KINETIS_PORTB_DFER         (KINETIS_PORTB_BASE+KINETIS_PORT_DFER_OFFSET)
#define KINETIS_PORTB_DFCR         (KINETIS_PORTB_BASE+KINETIS_PORT_DFCR_OFFSET)
#define KINETIS_PORTB_DFWR         (KINETIS_PORTB_BASE+KINETIS_PORT_DFWR_OFFSET)

#define KINETIS_PORTC_PCR(n)       (KINETIS_PORTC_BASE+KINETIS_PORT_PCR_OFFSET(n)
#define KINETIS_PORTC_PCR0         (KINETIS_PORTC_BASE+KINETIS_PORT_PCR0_OFFSET)
#define KINETIS_PORTC_PCR1         (KINETIS_PORTC_BASE+KINETIS_PORT_PCR1_OFFSET)
#define KINETIS_PORTC_PCR2         (KINETIS_PORTC_BASE+KINETIS_PORT_PCR2_OFFSET)
#define KINETIS_PORTC_PCR3         (KINETIS_PORTC_BASE+KINETIS_PORT_PCR3_OFFSET)
#define KINETIS_PORTC_PCR4         (KINETIS_PORTC_BASE+KINETIS_PORT_PCR4_OFFSET)
#define KINETIS_PORTC_PCR5         (KINETIS_PORTC_BASE+KINETIS_PORT_PCR5_OFFSET)
#define KINETIS_PORTC_PCR6         (KINETIS_PORTC_BASE+KINETIS_PORT_PCR6_OFFSET)
#define KINETIS_PORTC_PCR7         (KINETIS_PORTC_BASE+KINETIS_PORT_PCR7_OFFSET)
#define KINETIS_PORTC_PCR8         (KINETIS_PORTC_BASE+KINETIS_PORT_PCR8_OFFSET)
#define KINETIS_PORTC_PCR9         (KINETIS_PORTC_BASE+KINETIS_PORT_PCR9_OFFSET)
#define KINETIS_PORTC_PCR10        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR10_OFFSET)
#define KINETIS_PORTC_PCR11        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR11_OFFSET)
#define KINETIS_PORTC_PCR12        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR12_OFFSET)
#define KINETIS_PORTC_PCR13        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR13_OFFSET)
#define KINETIS_PORTC_PCR14        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR14_OFFSET)
#define KINETIS_PORTC_PCR15        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR15_OFFSET)
#define KINETIS_PORTC_PCR16        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR16_OFFSET)
#define KINETIS_PORTC_PCR17        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR17_OFFSET)
#define KINETIS_PORTC_PCR18        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR18_OFFSET)
#define KINETIS_PORTC_PCR19        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR19_OFFSET)
#define KINETIS_PORTC_PCR20        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR20_OFFSET)
#define KINETIS_PORTC_PCR21        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR21_OFFSET)
#define KINETIS_PORTC_PCR22        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR22_OFFSET)
#define KINETIS_PORTC_PCR23        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR23_OFFSET)
#define KINETIS_PORTC_PCR24        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR24_OFFSET)
#define KINETIS_PORTC_PCR25        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR25_OFFSET)
#define KINETIS_PORTC_PCR26        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR26_OFFSET)
#define KINETIS_PORTC_PCR27        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR27_OFFSET)
#define KINETIS_PORTC_PCR28        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR28_OFFSET)
#define KINETIS_PORTC_PCR29        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR29_OFFSET)
#define KINETIS_PORTC_PCR30        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR30_OFFSET)
#define KINETIS_PORTC_PCR31        (KINETIS_PORTC_BASE+KINETIS_PORT_PCR31_OFFSET)
#define KINETIS_PORTC_GPCLR        (KINETIS_PORTC_BASE+KINETIS_PORT_GPCLR_OFFSET)
#define KINETIS_PORTC_GPCHR        (KINETIS_PORTC_BASE+KINETIS_PORT_GPCHR_OFFSET)
#define KINETIS_PORTC_ISFR         (KINETIS_PORTC_BASE+KINETIS_PORT_ISFR_OFFSET)
#define KINETIS_PORTC_DFER         (KINETIS_PORTC_BASE+KINETIS_PORT_DFER_OFFSET)
#define KINETIS_PORTC_DFCR         (KINETIS_PORTC_BASE+KINETIS_PORT_DFCR_OFFSET)
#define KINETIS_PORTC_DFWR         (KINETIS_PORTC_BASE+KINETIS_PORT_DFWR_OFFSET)

#define KINETIS_PORTD_PCR(n)       (KINETIS_PORTD_BASE+KINETIS_PORT_PCR_OFFSET(n)
#define KINETIS_PORTD_PCR0         (KINETIS_PORTD_BASE+KINETIS_PORT_PCR0_OFFSET)
#define KINETIS_PORTD_PCR1         (KINETIS_PORTD_BASE+KINETIS_PORT_PCR1_OFFSET)
#define KINETIS_PORTD_PCR2         (KINETIS_PORTD_BASE+KINETIS_PORT_PCR2_OFFSET)
#define KINETIS_PORTD_PCR3         (KINETIS_PORTD_BASE+KINETIS_PORT_PCR3_OFFSET)
#define KINETIS_PORTD_PCR4         (KINETIS_PORTD_BASE+KINETIS_PORT_PCR4_OFFSET)
#define KINETIS_PORTD_PCR5         (KINETIS_PORTD_BASE+KINETIS_PORT_PCR5_OFFSET)
#define KINETIS_PORTD_PCR6         (KINETIS_PORTD_BASE+KINETIS_PORT_PCR6_OFFSET)
#define KINETIS_PORTD_PCR7         (KINETIS_PORTD_BASE+KINETIS_PORT_PCR7_OFFSET)
#define KINETIS_PORTD_PCR8         (KINETIS_PORTD_BASE+KINETIS_PORT_PCR8_OFFSET)
#define KINETIS_PORTD_PCR9         (KINETIS_PORTD_BASE+KINETIS_PORT_PCR9_OFFSET)
#define KINETIS_PORTD_PCR10        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR10_OFFSET)
#define KINETIS_PORTD_PCR11        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR11_OFFSET)
#define KINETIS_PORTD_PCR12        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR12_OFFSET)
#define KINETIS_PORTD_PCR13        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR13_OFFSET)
#define KINETIS_PORTD_PCR14        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR14_OFFSET)
#define KINETIS_PORTD_PCR15        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR15_OFFSET)
#define KINETIS_PORTD_PCR16        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR16_OFFSET)
#define KINETIS_PORTD_PCR17        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR17_OFFSET)
#define KINETIS_PORTD_PCR18        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR18_OFFSET)
#define KINETIS_PORTD_PCR19        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR19_OFFSET)
#define KINETIS_PORTD_PCR20        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR20_OFFSET)
#define KINETIS_PORTD_PCR21        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR21_OFFSET)
#define KINETIS_PORTD_PCR22        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR22_OFFSET)
#define KINETIS_PORTD_PCR23        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR23_OFFSET)
#define KINETIS_PORTD_PCR24        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR24_OFFSET)
#define KINETIS_PORTD_PCR25        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR25_OFFSET)
#define KINETIS_PORTD_PCR26        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR26_OFFSET)
#define KINETIS_PORTD_PCR27        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR27_OFFSET)
#define KINETIS_PORTD_PCR28        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR28_OFFSET)
#define KINETIS_PORTD_PCR29        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR29_OFFSET)
#define KINETIS_PORTD_PCR30        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR30_OFFSET)
#define KINETIS_PORTD_PCR31        (KINETIS_PORTD_BASE+KINETIS_PORT_PCR31_OFFSET)
#define KINETIS_PORTD_GPCLR        (KINETIS_PORTD_BASE+KINETIS_PORT_GPCLR_OFFSET)
#define KINETIS_PORTD_GPCHR        (KINETIS_PORTD_BASE+KINETIS_PORT_GPCHR_OFFSET)
#define KINETIS_PORTD_ISFR         (KINETIS_PORTD_BASE+KINETIS_PORT_ISFR_OFFSET)
#define KINETIS_PORTD_DFER         (KINETIS_PORTD_BASE+KINETIS_PORT_DFER_OFFSET)
#define KINETIS_PORTD_DFCR         (KINETIS_PORTD_BASE+KINETIS_PORT_DFCR_OFFSET)
#define KINETIS_PORTD_DFWR         (KINETIS_PORTD_BASE+KINETIS_PORT_DFWR_OFFSET)

#define KINETIS_PORTE_PCR(n)       (KINETIS_PORTE_BASE+KINETIS_PORT_PCR_OFFSET(n)
#define KINETIS_PORTE_PCR0         (KINETIS_PORTE_BASE+KINETIS_PORT_PCR0_OFFSET)
#define KINETIS_PORTE_PCR1         (KINETIS_PORTE_BASE+KINETIS_PORT_PCR1_OFFSET)
#define KINETIS_PORTE_PCR2         (KINETIS_PORTE_BASE+KINETIS_PORT_PCR2_OFFSET)
#define KINETIS_PORTE_PCR3         (KINETIS_PORTE_BASE+KINETIS_PORT_PCR3_OFFSET)
#define KINETIS_PORTE_PCR4         (KINETIS_PORTE_BASE+KINETIS_PORT_PCR4_OFFSET)
#define KINETIS_PORTE_PCR5         (KINETIS_PORTE_BASE+KINETIS_PORT_PCR5_OFFSET)
#define KINETIS_PORTE_PCR6         (KINETIS_PORTE_BASE+KINETIS_PORT_PCR6_OFFSET)
#define KINETIS_PORTE_PCR7         (KINETIS_PORTE_BASE+KINETIS_PORT_PCR7_OFFSET)
#define KINETIS_PORTE_PCR8         (KINETIS_PORTE_BASE+KINETIS_PORT_PCR8_OFFSET)
#define KINETIS_PORTE_PCR9         (KINETIS_PORTE_BASE+KINETIS_PORT_PCR9_OFFSET)
#define KINETIS_PORTE_PCR10        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR10_OFFSET)
#define KINETIS_PORTE_PCR11        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR11_OFFSET)
#define KINETIS_PORTE_PCR12        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR12_OFFSET)
#define KINETIS_PORTE_PCR13        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR13_OFFSET)
#define KINETIS_PORTE_PCR14        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR14_OFFSET)
#define KINETIS_PORTE_PCR15        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR15_OFFSET)
#define KINETIS_PORTE_PCR16        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR16_OFFSET)
#define KINETIS_PORTE_PCR17        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR17_OFFSET)
#define KINETIS_PORTE_PCR18        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR18_OFFSET)
#define KINETIS_PORTE_PCR19        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR19_OFFSET)
#define KINETIS_PORTE_PCR20        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR20_OFFSET)
#define KINETIS_PORTE_PCR21        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR21_OFFSET)
#define KINETIS_PORTE_PCR22        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR22_OFFSET)
#define KINETIS_PORTE_PCR23        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR23_OFFSET)
#define KINETIS_PORTE_PCR24        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR24_OFFSET)
#define KINETIS_PORTE_PCR25        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR25_OFFSET)
#define KINETIS_PORTE_PCR26        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR26_OFFSET)
#define KINETIS_PORTE_PCR27        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR27_OFFSET)
#define KINETIS_PORTE_PCR28        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR28_OFFSET)
#define KINETIS_PORTE_PCR29        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR29_OFFSET)
#define KINETIS_PORTE_PCR30        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR30_OFFSET)
#define KINETIS_PORTE_PCR31        (KINETIS_PORTE_BASE+KINETIS_PORT_PCR31_OFFSET)
#define KINETIS_PORTE_GPCLR        (KINETIS_PORTE_BASE+KINETIS_PORT_GPCLR_OFFSET)
#define KINETIS_PORTE_GPCHR        (KINETIS_PORTE_BASE+KINETIS_PORT_GPCHR_OFFSET)
#define KINETIS_PORTE_ISFR         (KINETIS_PORTE_BASE+KINETIS_PORT_ISFR_OFFSET)
#define KINETIS_PORTE_DFER         (KINETIS_PORTE_BASE+KINETIS_PORT_DFER_OFFSET)
#define KINETIS_PORTE_DFCR         (KINETIS_PORTE_BASE+KINETIS_PORT_DFCR_OFFSET)
#define KINETIS_PORTE_DFWR         (KINETIS_PORTE_BASE+KINETIS_PORT_DFWR_OFFSET)

/* Register Bit Definitions *************************************************/

/* Pin Control Register n, n=0..31 */

#define PORT_PCR_PS                 (1 << 0)  /* Bit 0: Pull Select */
#define PORT_PCR_PE                 (1 << 1)  /* Bit 1: Pull Enable */
#define PORT_PCR_SRE                (1 << 2)  /* Bit 2: Slew Rate Enable */
                                              /* Bit 3: Reserved */
#define PORT_PCR_PFE                (1 << 4)  /* Bit 4: Passive Filter Enable */
#define PORT_PCR_ODE                (1 << 5)  /* Bit 5: Open Drain Enable */
#define PORT_PCR_DSE                (1 << 6)  /* Bit 6: Drive Strength Enable */
                                              /* Bit 7: Reserved */
#define PORT_PCR_MUX_SHIFT          (8)       /* Bits 8-10: Pin Mux Control */
#define PORT_PCR_MUX_MASK           (7 << PORT_PCR_MUX_SHIFT)
#  define PORT_PCR_MUX_ANALOG       (0 << PORT_PCR_MUX_SHIFT)  /* Pin Disabled (Analog) */
#  define PORT_PCR_MUX_GPIO         (1 << PORT_PCR_MUX_SHIFT)  /* Alternative 1 (GPIO) */
#  define PORT_PCR_MUX_ALT1         (1 << PORT_PCR_MUX_SHIFT)  /* Alternative 1 (GPIO) */
#  define PORT_PCR_MUX_ALT2         (2 << PORT_PCR_MUX_SHIFT)  /* Alternative 2 (chip specific) */
#  define PORT_PCR_MUX_ALT3         (3 << PORT_PCR_MUX_SHIFT)  /* Alternative 3 (chip specific) */
#  define PORT_PCR_MUX_ALT4         (4 << PORT_PCR_MUX_SHIFT)  /* Alternative 4 (chip specific) */
#  define PORT_PCR_MUX_ALT5         (5 << PORT_PCR_MUX_SHIFT)  /* Alternative 5 (chip specific) */
#  define PORT_PCR_MUX_ALT6         (6 << PORT_PCR_MUX_SHIFT)  /* Alternative 6 (chip specific) */
#  define PORT_PCR_MUX_ALT7         (7 << PORT_PCR_MUX_SHIFT)  /* Alternative 7 (chip specific / JTAG / NMI) */

                                              /* Bits 11-14: Reserved */
#define PORT_PCR_LK                 (1 << 15) /* Bit 15: Lock Register */
#define PORT_PCR_IRQC_SHIFT         (16)      /* Bits 16-19: Interrupt Configuration */
#define PORT_PCR_IRQC_MASK          (15 << PORT_PCR_IRQC_SHIFT)
#  define PORT_PCR_IRQC_DISABLED    (0 << PORT_PCR_IRQC_SHIFT)  /* Interrupt/DMA Request disabled */
#  define PORT_PCR_IRQC_DMARISING   (1 << PORT_PCR_IRQC_SHIFT)  /* DMA Request on rising edge */
#  define PORT_PCR_IRQC_DMAFALLING  (2 << PORT_PCR_IRQC_SHIFT)  /* DMA Request on falling edge */
#  define PORT_PCR_IRQC_DMABOTH     (3 << PORT_PCR_IRQC_SHIFT)  /* DMA Request on either edge */
#  define PORT_PCR_IRQC_ZERO        (8 << PORT_PCR_IRQC_SHIFT)  /* Interrupt when logic zero */
#  define PORT_PCR_IRQC_RISING      (9 << PORT_PCR_IRQC_SHIFT)  /* Interrupt on rising edge */
#  define PORT_PCR_IRQC_FALLING     (10 << PORT_PCR_IRQC_SHIFT) /* Interrupt on falling edge */
#  define PORT_PCR_IRQC_BOTH        (11 << PORT_PCR_IRQC_SHIFT) /* Interrupt on either edge */
#  define PORT_PCR_IRQC_ONE         (12 << PORT_PCR_IRQC_SHIFT) /* Interrupt when logic one */

                                              /* Bits 20-23: Reserved */
#define PORT_PCR_ISF                (1 << 24) /* Bit 24: Interrupt Status Flag */
                                              /* Bits 25-31: Reserved */

/* Global Pin Control Low Register */

#define PORT_GPCLR_GPWD_SHIFT       (0)       /* Bits 0-15: Global Pin Write Data */
#define PORT_GPCLR_GPWD_MASK        (0xffff << PORT_GPCLR_GPWD_SHIFT)
#  define PORT_GPCLR_GPWD(n)        ((1 << (n)) << PORT_GPCLR_GPWD_SHIFT)
#define PORT_GPCLR_GPWE_SHIFT       (16)      /* Bits 16-31: Global Pin Write Enable */
#define PORT_GPCLR_GPWE_MASK        (0xffff << PORT_GPCLR_GPWE_SHIFT)
#  define PORT_GPCLR_GPWE(n)        ((1 << (n)) << PORT_GPCLR_GPWE_SHIFT)

/* Global Pin Control High Register */

#define PORT_GPCHR_GPWD_SHIFT       (0)       /* Bits 0-15: Global Pin Write Data */
#define PORT_GPCHR_GPWD_MASK        (0xffff << PORT_GPCHR_GPWD_SHIFT)
#  define PORT_GPCHR_GPWD(n)        ((1 << (n)) << PORT_GPCHR_GPWD_SHIFT)
#define PORT_GPCHR_GPWE_SHIFT       (16)      /* Bits 16-31: Global Pin Write Enable */
#define PORT_GPCHR_GPWE_MASK        (0xffff << PORT_GPCHR_GPWE_SHIFT)
#  define PORT_GPCHR_GPWE(n)        ((1 << (n)) << PORT_GPCHR_GPWE_SHIFT)

/* Interrupt Status Flag Register */

#define PORT_ISFR(n)                (1 << (n))

/* Digital Filter Enable Register */

#define PORT_DFER(n)                (1 << (n))

/* Digital Filter Clock Register */

#define PORT_DFCR_CS                (1 << 0)  /* Bit 0: Clock Source */

/* Digital Filter Width Register */

#define PORT_DFWR_FILT_SHIFT        (0)       /* Bits 0-4: Filter Length */
#define PORT_DFWR_FILT_MASK         (31 << PORT_DFWR_FILT_SHIFT)

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions Prototypes
 ****************************************************************************/

#endif /* __ARCH_ARM_SRC_KINETIS_HARDWARE_KINETIS_PORT_H */
