/****************************************************************************
 * arch/arm/src/imxrt/hardware/rt117x/imxrt117x_xbar.h
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

#ifndef __ARCH_ARM_SRC_IMXRT_HARDWARE_RT117X_IMXRT117X_XBAR_H
#define __ARCH_ARM_SRC_IMXRT_HARDWARE_RT117X_IMXRT117X_XBAR_H

/* XBAR Defines for IMXRT117X */

#define IMXRT_XBAR_SEL_MASKS {0xff, 0x7f, 0x7f}  /* The select masks A, B2, B3 */

/* XBARA1 Mux Inputs (I values) *********************************************/

#define IMXRT_XBARA1_IN_LOGIC_LOW                            IMXRT_XBARA1(XBAR_INPUT, 0)      /* LOGIC_LOW output assigned to XBARA1_IN0 input. */
#define IMXRT_XBARA1_IN_LOGIC_HIGH                           IMXRT_XBARA1(XBAR_INPUT, 1)      /* LOGIC_HIGH output assigned to XBARA1_IN1 input. */
#define IMXRT_XBARA1_IN_GND2                                 IMXRT_XBARA1(XBAR_INPUT, 2)      /* GND assigned to XBARA1_IN2 input. */
#define IMXRT_XBARA1_IN_GND3                                 IMXRT_XBARA1(XBAR_INPUT, 3)      /* GND assigned to XBARA1_IN3 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO04                      IMXRT_XBARA1(XBAR_INPUT, 4)      /* IOMUX_XBAR_INOUT04 output assigned to XBARA1_IN4 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO05                      IMXRT_XBARA1(XBAR_INPUT, 5)      /* IOMUX_XBAR_INOUT05 output assigned to XBARA1_IN5 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO06                      IMXRT_XBARA1(XBAR_INPUT, 6)      /* IOMUX_XBAR_INOUT06 output assigned to XBARA1_IN6 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO07                      IMXRT_XBARA1(XBAR_INPUT, 7)      /* IOMUX_XBAR_INOUT07 output assigned to XBARA1_IN7 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO08                      IMXRT_XBARA1(XBAR_INPUT, 8)      /* IOMUX_XBAR_INOUT08 output assigned to XBARA1_IN8 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO09                      IMXRT_XBARA1(XBAR_INPUT, 9)      /* IOMUX_XBAR_INOUT09 output assigned to XBARA1_IN9 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO10                      IMXRT_XBARA1(XBAR_INPUT, 10)     /* IOMUX_XBAR_INOUT10 output assigned to XBARA1_IN10 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO11                      IMXRT_XBARA1(XBAR_INPUT, 11)     /* IOMUX_XBAR_INOUT11 output assigned to XBARA1_IN11 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO12                      IMXRT_XBARA1(XBAR_INPUT, 12)     /* IOMUX_XBAR_INOUT12 output assigned to XBARA1_IN12 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO13                      IMXRT_XBARA1(XBAR_INPUT, 13)     /* IOMUX_XBAR_INOUT13 output assigned to XBARA1_IN13 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO14                      IMXRT_XBARA1(XBAR_INPUT, 14)     /* IOMUX_XBAR_INOUT14 output assigned to XBARA1_IN14 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO15                      IMXRT_XBARA1(XBAR_INPUT, 15)     /* IOMUX_XBAR_INOUT15 output assigned to XBARA1_IN15 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO16                      IMXRT_XBARA1(XBAR_INPUT, 16)     /* IOMUX_XBAR_INOUT16 output assigned to XBARA1_IN16 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO17                      IMXRT_XBARA1(XBAR_INPUT, 17)     /* IOMUX_XBAR_INOUT17 output assigned to XBARA1_IN17 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO18                      IMXRT_XBARA1(XBAR_INPUT, 18)     /* IOMUX_XBAR_INOUT18 output assigned to XBARA1_IN18 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IO19                      IMXRT_XBARA1(XBAR_INPUT, 19)     /* IOMUX_XBAR_INOUT19 output assigned to XBARA1_IN19 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN20                      IMXRT_XBARA1(XBAR_INPUT, 20)     /* IOMUX_XBAR_INOUT20 output assigned to XBARA1_IN20 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN21                      IMXRT_XBARA1(XBAR_INPUT, 21)     /* IOMUX_XBAR_INOUT21 output assigned to XBARA1_IN21 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN22                      IMXRT_XBARA1(XBAR_INPUT, 22)     /* IOMUX_XBAR_INOUT22 output assigned to XBARA1_IN22 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN23                      IMXRT_XBARA1(XBAR_INPUT, 23)     /* IOMUX_XBAR_INOUT23 output assigned to XBARA1_IN23 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN24                      IMXRT_XBARA1(XBAR_INPUT, 24)     /* IOMUX_XBAR_INOUT24 output assigned to XBARA1_IN24 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN25                      IMXRT_XBARA1(XBAR_INPUT, 25)     /* IOMUX_XBAR_INOUT25 output assigned to XBARA1_IN25 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN26                      IMXRT_XBARA1(XBAR_INPUT, 26)     /* IOMUX_XBAR_INOUT26 output assigned to XBARA1_IN26 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN27                      IMXRT_XBARA1(XBAR_INPUT, 27)     /* IOMUX_XBAR_INOUT27 output assigned to XBARA1_IN27 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN28                      IMXRT_XBARA1(XBAR_INPUT, 28)     /* IOMUX_XBAR_INOUT28 output assigned to XBARA1_IN28 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN29                      IMXRT_XBARA1(XBAR_INPUT, 29)     /* IOMUX_XBAR_INOUT29 output assigned to XBARA1_IN29 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN30                      IMXRT_XBARA1(XBAR_INPUT, 30)     /* IOMUX_XBAR_INOUT30 output assigned to XBARA1_IN30 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN31                      IMXRT_XBARA1(XBAR_INPUT, 31)     /* IOMUX_XBAR_INOUT31 output assigned to XBARA1_IN31 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN32                      IMXRT_XBARA1(XBAR_INPUT, 32)     /* IOMUX_XBAR_INOUT32 output assigned to XBARA1_IN32 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN33                      IMXRT_XBARA1(XBAR_INPUT, 33)     /* IOMUX_XBAR_INOUT33 output assigned to XBARA1_IN33 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN34                      IMXRT_XBARA1(XBAR_INPUT, 34)     /* IOMUX_XBAR_INOUT34 output assigned to XBARA1_IN34 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN35                      IMXRT_XBARA1(XBAR_INPUT, 35)     /* IOMUX_XBAR_INOUT35 output assigned to XBARA1_IN35 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN36                      IMXRT_XBARA1(XBAR_INPUT, 36)     /* IOMUX_XBAR_INOUT36 output assigned to XBARA1_IN36 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN37                      IMXRT_XBARA1(XBAR_INPUT, 37)     /* IOMUX_XBAR_INOUT37 output assigned to XBARA1_IN37 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN38                      IMXRT_XBARA1(XBAR_INPUT, 38)     /* IOMUX_XBAR_INOUT38 output assigned to XBARA1_IN38 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN39                      IMXRT_XBARA1(XBAR_INPUT, 39)     /* IOMUX_XBAR_INOUT39 output assigned to XBARA1_IN39 input. */
#define IMXRT_XBARA1_IN_IOMUX_XBAR_IN40                      IMXRT_XBARA1(XBAR_INPUT, 40)     /* IOMUX_XBAR_INOUT40 output assigned to XBARA1_IN40 input. */
#define IMXRT_XBARA1_IN_GND41                                IMXRT_XBARA1(XBAR_INPUT, 41)     /* GND assigned to XBARA1_IN41 input. */
#define IMXRT_XBARA1_IN_ACMP1_OUT                            IMXRT_XBARA1(XBAR_INPUT, 42)     /* ACMP1_OUT output assigned to XBARA1_IN42 input. */
#define IMXRT_XBARA1_IN_ACMP2_OUT                            IMXRT_XBARA1(XBAR_INPUT, 43)     /* ACMP2_OUT output assigned to XBARA1_IN43 input. */
#define IMXRT_XBARA1_IN_ACMP3_OUT                            IMXRT_XBARA1(XBAR_INPUT, 44)     /* ACMP3_OUT output assigned to XBARA1_IN44 input. */
#define IMXRT_XBARA1_IN_ACMP4_OUT                            IMXRT_XBARA1(XBAR_INPUT, 45)     /* ACMP4_OUT output assigned to XBARA1_IN45 input. */
#define IMXRT_XBARA1_IN_GND46                                IMXRT_XBARA1(XBAR_INPUT, 46)     /* GND assigned to XBARA1_IN46 input. */
#define IMXRT_XBARA1_IN_GND47                                IMXRT_XBARA1(XBAR_INPUT, 47)     /* GND assigned to XBARA1_IN47 input. */
#define IMXRT_XBARA1_IN_GND48                                IMXRT_XBARA1(XBAR_INPUT, 48)     /* GND assigned to XBARA1_IN48 input. */
#define IMXRT_XBARA1_IN_GND49                                IMXRT_XBARA1(XBAR_INPUT, 49)     /* GND assigned to XBARA1_IN49 input. */
#define IMXRT_XBARA1_IN_QTIMER1_TMR0_OUT                     IMXRT_XBARA1(XBAR_INPUT, 50)     /* QTIMER1_TMR0_OUTPUT output assigned to XBARA1_IN50 input. */
#define IMXRT_XBARA1_IN_QTIMER1_TMR1_OUT                     IMXRT_XBARA1(XBAR_INPUT, 51)     /* QTIMER1_TMR1_OUTPUT output assigned to XBARA1_IN51 input. */
#define IMXRT_XBARA1_IN_QTIMER1_TMR2_OUT                     IMXRT_XBARA1(XBAR_INPUT, 52)     /* QTIMER1_TMR2_OUTPUT output assigned to XBARA1_IN52 input. */
#define IMXRT_XBARA1_IN_QTIMER1_TMR3_OUT                     IMXRT_XBARA1(XBAR_INPUT, 53)     /* QTIMER1_TMR3_OUTPUT output assigned to XBARA1_IN53 input. */
#define IMXRT_XBARA1_IN_QTIMER2_TMR0_OUT                     IMXRT_XBARA1(XBAR_INPUT, 54)     /* QTIMER2_TMR0_OUTPUT output assigned to XBARA1_IN54 input. */
#define IMXRT_XBARA1_IN_QTIMER2_TMR1_OUT                     IMXRT_XBARA1(XBAR_INPUT, 55)     /* QTIMER2_TMR1_OUTPUT output assigned to XBARA1_IN55 input. */
#define IMXRT_XBARA1_IN_QTIMER2_TMR2_OUT                     IMXRT_XBARA1(XBAR_INPUT, 56)     /* QTIMER2_TMR2_OUTPUT output assigned to XBARA1_IN56 input. */
#define IMXRT_XBARA1_IN_QTIMER2_TMR3_OUT                     IMXRT_XBARA1(XBAR_INPUT, 57)     /* QTIMER2_TMR3_OUTPUT output assigned to XBARA1_IN57 input. */
#define IMXRT_XBARA1_IN_QTIMER3_TMR0_OUT                     IMXRT_XBARA1(XBAR_INPUT, 58)     /* QTIMER3_TMR0_OUTPUT output assigned to XBARA1_IN58 input. */
#define IMXRT_XBARA1_IN_QTIMER3_TMR1_OUT                     IMXRT_XBARA1(XBAR_INPUT, 59)     /* QTIMER3_TMR1_OUTPUT output assigned to XBARA1_IN59 input. */
#define IMXRT_XBARA1_IN_QTIMER3_TMR2_OUT                     IMXRT_XBARA1(XBAR_INPUT, 60)     /* QTIMER3_TMR2_OUTPUT output assigned to XBARA1_IN60 input. */
#define IMXRT_XBARA1_IN_QTIMER3_TMR3_OUT                     IMXRT_XBARA1(XBAR_INPUT, 61)     /* QTIMER3_TMR3_OUTPUT output assigned to XBARA1_IN61 input. */
#define IMXRT_XBARA1_IN_QTIMER4_TMR0_OUT                     IMXRT_XBARA1(XBAR_INPUT, 62)     /* QTIMER4_TMR0_OUTPUT output assigned to XBARA1_IN62 input. */
#define IMXRT_XBARA1_IN_QTIMER4_TMR1_OUT                     IMXRT_XBARA1(XBAR_INPUT, 63)     /* QTIMER4_TMR1_OUTPUT output assigned to XBARA1_IN63 input. */
#define IMXRT_XBARA1_IN_QTIMER4_TMR2_OUT                     IMXRT_XBARA1(XBAR_INPUT, 64)     /* QTIMER4_TMR2_OUTPUT output assigned to XBARA1_IN64 input. */
#define IMXRT_XBARA1_IN_QTIMER4_TMR3_OUT                     IMXRT_XBARA1(XBAR_INPUT, 65)     /* QTIMER4_TMR3_OUTPUT output assigned to XBARA1_IN65 input. */
#define IMXRT_XBARA1_IN_GND66                                IMXRT_XBARA1(XBAR_INPUT, 66)     /* GND assigned to XBARA1_IN66 input. */
#define IMXRT_XBARA1_IN_GND67                                IMXRT_XBARA1(XBAR_INPUT, 67)     /* GND assigned to XBARA1_IN67 input. */
#define IMXRT_XBARA1_IN_GND68                                IMXRT_XBARA1(XBAR_INPUT, 68)     /* GND assigned to XBARA1_IN68 input. */
#define IMXRT_XBARA1_IN_GND69                                IMXRT_XBARA1(XBAR_INPUT, 69)     /* GND assigned to XBARA1_IN69 input. */
#define IMXRT_XBARA1_IN_GND70                                IMXRT_XBARA1(XBAR_INPUT, 70)     /* GND assigned to XBARA1_IN70 input. */
#define IMXRT_XBARA1_IN_GND71                                IMXRT_XBARA1(XBAR_INPUT, 71)     /* GND assigned to XBARA1_IN71 input. */
#define IMXRT_XBARA1_IN_GND72                                IMXRT_XBARA1(XBAR_INPUT, 72)     /* GND assigned to XBARA1_IN72 input. */
#define IMXRT_XBARA1_IN_GND73                                IMXRT_XBARA1(XBAR_INPUT, 73)     /* GND assigned to XBARA1_IN73 input. */
#define IMXRT_XBARA1_IN_FLEXPWM1_PWM0_OUT_TRIG0              IMXRT_XBARA1(XBAR_INPUT, 74)     /* FLEXPWM1_PWM0_OUT_TRIG0 output assigned to XBARA1_IN74 input. */
#define IMXRT_XBARA1_IN_FLEXPWM1_PWM0_OUT_TRIG1              IMXRT_XBARA1(XBAR_INPUT, 75)     /* FLEXPWM1_PWM0_OUT_TRIG1 output assigned to XBARA1_IN75 input. */
#define IMXRT_XBARA1_IN_FLEXPWM1_PWM1_OUT_TRIG0              IMXRT_XBARA1(XBAR_INPUT, 76)     /* FLEXPWM1_PWM1_OUT_TRIG0 output assigned to XBARA1_IN76 input. */
#define IMXRT_XBARA1_IN_FLEXPWM1_PWM1_OUT_TRIG1              IMXRT_XBARA1(XBAR_INPUT, 77)     /* FLEXPWM1_PWM1_OUT_TRIG1 output assigned to XBARA1_IN77 input. */
#define IMXRT_XBARA1_IN_FLEXPWM1_PWM2_OUT_TRIG0              IMXRT_XBARA1(XBAR_INPUT, 78)     /* FLEXPWM1_PWM2_OUT_TRIG0 output assigned to XBARA1_IN78 input. */
#define IMXRT_XBARA1_IN_FLEXPWM1_PWM2_OUT_TRIG1              IMXRT_XBARA1(XBAR_INPUT, 79)     /* FLEXPWM1_PWM2_OUT_TRIG1 output assigned to XBARA1_IN79 input. */
#define IMXRT_XBARA1_IN_FLEXPWM1_PWM3_OUT_TRIG0              IMXRT_XBARA1(XBAR_INPUT, 80)     /* FLEXPWM1_PWM3_OUT_TRIG0 output assigned to XBARA1_IN80 input. */
#define IMXRT_XBARA1_IN_FLEXPWM1_PWM3_OUT_TRIG1              IMXRT_XBARA1(XBAR_INPUT, 81)     /* FLEXPWM1_PWM3_OUT_TRIG1 output assigned to XBARA1_IN81 input. */
#define IMXRT_XBARA1_IN_FLEXPWM2_PWM0_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 82)     /* FLEXPWM2_PWM0_OUT_TRIG0_1 output assigned to XBARA1_IN82 input. */
#define IMXRT_XBARA1_IN_FLEXPWM2_PWM1_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 83)     /* FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBARA1_IN83 input. */
#define IMXRT_XBARA1_IN_FLEXPWM2_PWM2_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 84)     /* FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBARA1_IN84 input. */
#define IMXRT_XBARA1_IN_FLEXPWM2_PWM3_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 85)     /* FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBARA1_IN85 input. */
#define IMXRT_XBARA1_IN_FLEXPWM3_PWM0_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 86)     /* FLEXPWM3_PWM0_OUT_TRIG0_1 output assigned to XBARA1_IN86 input. */
#define IMXRT_XBARA1_IN_FLEXPWM3_PWM1_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 87)     /* FLEXPWM3_PWM1_OUT_TRIG0_1 output assigned to XBARA1_IN87 input. */
#define IMXRT_XBARA1_IN_FLEXPWM3_PWM2_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 88)     /* FLEXPWM3_PWM2_OUT_TRIG0_1 output assigned to XBARA1_IN88 input. */
#define IMXRT_XBARA1_IN_FLEXPWM3_PWM3_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 89)     /* FLEXPWM3_PWM3_OUT_TRIG0_1 output assigned to XBARA1_IN89 input. */
#define IMXRT_XBARA1_IN_FLEXPWM4_PWM0_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 90)     /* FLEXPWM4_PWM0_OUT_TRIG0_1 output assigned to XBARA1_IN90 input. */
#define IMXRT_XBARA1_IN_FLEXPWM4_PWM1_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 91)     /* FLEXPWM4_PWM1_OUT_TRIG0_1 output assigned to XBARA1_IN91 input. */
#define IMXRT_XBARA1_IN_FLEXPWM4_PWM2_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 92)     /* FLEXPWM4_PWM2_OUT_TRIG0_1 output assigned to XBARA1_IN92 input. */
#define IMXRT_XBARA1_IN_FLEXPWM4_PWM3_OUT_TRIG01             IMXRT_XBARA1(XBAR_INPUT, 93)     /* FLEXPWM4_PWM3_OUT_TRIG0_1 output assigned to XBARA1_IN93 input. */
#define IMXRT_XBARA1_IN_GND94                                IMXRT_XBARA1(XBAR_INPUT, 94)     /* GND assigned to XBARA1_IN94 input. */
#define IMXRT_XBARA1_IN_GND95                                IMXRT_XBARA1(XBAR_INPUT, 95)     /* GND assigned to XBARA1_IN95 input. */
#define IMXRT_XBARA1_IN_GND96                                IMXRT_XBARA1(XBAR_INPUT, 96)     /* GND assigned to XBARA1_IN96 input. */
#define IMXRT_XBARA1_IN_GND97                                IMXRT_XBARA1(XBAR_INPUT, 97)     /* GND assigned to XBARA1_IN97 input. */
#define IMXRT_XBARA1_IN_GND98                                IMXRT_XBARA1(XBAR_INPUT, 98)     /* GND assigned to XBARA1_IN98 input. */
#define IMXRT_XBARA1_IN_GND99                                IMXRT_XBARA1(XBAR_INPUT, 99)     /* GND assigned to XBARA1_IN99 input. */
#define IMXRT_XBARA1_IN_GND100                               IMXRT_XBARA1(XBAR_INPUT, 100)    /* GND assigned to XBARA1_IN100 input. */
#define IMXRT_XBARA1_IN_GND101                               IMXRT_XBARA1(XBAR_INPUT, 101)    /* GND assigned to XBARA1_IN101 input. */
#define IMXRT_XBARA1_IN_PIT1_TRIGGER0                        IMXRT_XBARA1(XBAR_INPUT, 102)    /* PIT1_TRIGGER0 output assigned to XBARA1_IN102 input. */
#define IMXRT_XBARA1_IN_PIT1_TRIGGER1                        IMXRT_XBARA1(XBAR_INPUT, 103)    /* PIT1_TRIGGER1 output assigned to XBARA1_IN103 input. */
#define IMXRT_XBARA1_IN_PIT1_TRIGGER2                        IMXRT_XBARA1(XBAR_INPUT, 104)    /* PIT1_TRIGGER2 output assigned to XBARA1_IN104 input. */
#define IMXRT_XBARA1_IN_PIT1_TRIGGER3                        IMXRT_XBARA1(XBAR_INPUT, 105)    /* PIT1_TRIGGER3 output assigned to XBARA1_IN105 input. */
#define IMXRT_XBARA1_IN_QDC1_POSMATCH                        IMXRT_XBARA1(XBAR_INPUT, 106)    /* QDC1_POSMATCH output assigned to XBARA1_IN106 input. */
#define IMXRT_XBARA1_IN_QDC2_POSMATCH                        IMXRT_XBARA1(XBAR_INPUT, 107)    /* QDC1_POSMATCH output assigned to XBARA1_IN107 input. */
#define IMXRT_XBARA1_IN_QDC3_POSMATCH                        IMXRT_XBARA1(XBAR_INPUT, 108)    /* QDC1_POSMATCH output assigned to XBARA1_IN108 input. */
#define IMXRT_XBARA1_IN_QDC4_POSMATCH                        IMXRT_XBARA1(XBAR_INPUT, 109)    /* QDC1_POSMATCH output assigned to XBARA1_IN109 input. */
#define IMXRT_XBARA1_IN_GND110                               IMXRT_XBARA1(XBAR_INPUT, 110)    /* GND assigned to XBARA1_IN110 input. */
#define IMXRT_XBARA1_IN_GND111                               IMXRT_XBARA1(XBAR_INPUT, 111)    /* GND assigned to XBARA1_IN111 input. */
#define IMXRT_XBARA1_IN_EDMA_DONE0                           IMXRT_XBARA1(XBAR_INPUT, 112)    /* EDMA_DONE0 output assigned to XBARA1_IN112 input. */
#define IMXRT_XBARA1_IN_EDMA_DONE1                           IMXRT_XBARA1(XBAR_INPUT, 113)    /* EDMA_DONE1 output assigned to XBARA1_IN113 input. */
#define IMXRT_XBARA1_IN_EDMA_DONE2                           IMXRT_XBARA1(XBAR_INPUT, 114)    /* EDMA_DONE2 output assigned to XBARA1_IN114 input. */
#define IMXRT_XBARA1_IN_EDMA_DONE3                           IMXRT_XBARA1(XBAR_INPUT, 115)    /* EDMA_DONE3 output assigned to XBARA1_IN115 input. */
#define IMXRT_XBARA1_IN_EDMA_DONE4                           IMXRT_XBARA1(XBAR_INPUT, 116)    /* EDMA_DONE4 output assigned to XBARA1_IN116 input. */
#define IMXRT_XBARA1_IN_EDMA_DONE5                           IMXRT_XBARA1(XBAR_INPUT, 117)    /* EDMA_DONE5 output assigned to XBARA1_IN117 input. */
#define IMXRT_XBARA1_IN_EDMA_DONE6                           IMXRT_XBARA1(XBAR_INPUT, 118)    /* EDMA_DONE6 output assigned to XBARA1_IN118 input. */
#define IMXRT_XBARA1_IN_EDMA_DONE7                           IMXRT_XBARA1(XBAR_INPUT, 119)    /* EDMA_DONE7 output assigned to XBARA1_IN119 input. */
#define IMXRT_XBARA1_IN_EDMA_LPSR_DONE0                      IMXRT_XBARA1(XBAR_INPUT, 120)    /* EDMA_LPSR_DONE0 output assigned to XBARA1_IN120 input. */
#define IMXRT_XBARA1_IN_EDMA_LPSR_DONE1                      IMXRT_XBARA1(XBAR_INPUT, 121)    /* EDMA_LPSR_DONE1 output assigned to XBARA1_IN121 input. */
#define IMXRT_XBARA1_IN_EDMA_LPSR_DONE2                      IMXRT_XBARA1(XBAR_INPUT, 122)    /* EDMA_LPSR_DONE2 output assigned to XBARA1_IN122 input. */
#define IMXRT_XBARA1_IN_EDMA_LPSR_DONE3                      IMXRT_XBARA1(XBAR_INPUT, 123)    /* EDMA_LPSR_DONE3 output assigned to XBARA1_IN123 input. */
#define IMXRT_XBARA1_IN_EDMA_LPSR_DONE4                      IMXRT_XBARA1(XBAR_INPUT, 124)    /* EDMA_LPSR_DONE4 output assigned to XBARA1_IN124 input. */
#define IMXRT_XBARA1_IN_EDMA_LPSR_DONE5                      IMXRT_XBARA1(XBAR_INPUT, 125)    /* EDMA_LPSR_DONE5 output assigned to XBARA1_IN125 input. */
#define IMXRT_XBARA1_IN_EDMA_LPSR_DONE6                      IMXRT_XBARA1(XBAR_INPUT, 126)    /* EDMA_LPSR_DONE6 output assigned to XBARA1_IN126 input. */
#define IMXRT_XBARA1_IN_EDMA_LPSR_DONE7                      IMXRT_XBARA1(XBAR_INPUT, 127)    /* EDMA_LPSR_DONE7 output assigned to XBARA1_IN127 input. */
#define IMXRT_XBARA1_IN_AOI1_OUT0                            IMXRT_XBARA1(XBAR_INPUT, 128)    /* AOI1_OUT0 output assigned to XBARA1_IN128 input. */
#define IMXRT_XBARA1_IN_AOI1_OUT1                            IMXRT_XBARA1(XBAR_INPUT, 129)    /* AOI1_OUT1 output assigned to XBARA1_IN129 input. */
#define IMXRT_XBARA1_IN_AOI1_OUT2                            IMXRT_XBARA1(XBAR_INPUT, 130)    /* AOI1_OUT2 output assigned to XBARA1_IN130 input. */
#define IMXRT_XBARA1_IN_AOI1_OUT3                            IMXRT_XBARA1(XBAR_INPUT, 131)    /* AOI1_OUT3 output assigned to XBARA1_IN131 input. */
#define IMXRT_XBARA1_IN_AOI2_OUT0                            IMXRT_XBARA1(XBAR_INPUT, 132)    /* AOI2_OUT0 output assigned to XBARA1_IN132 input. */
#define IMXRT_XBARA1_IN_AOI2_OUT1                            IMXRT_XBARA1(XBAR_INPUT, 133)    /* AOI2_OUT1 output assigned to XBARA1_IN133 input. */
#define IMXRT_XBARA1_IN_AOI2_OUT2                            IMXRT_XBARA1(XBAR_INPUT, 134)    /* AOI2_OUT2 output assigned to XBARA1_IN134 input. */
#define IMXRT_XBARA1_IN_AOI2_OUT3                            IMXRT_XBARA1(XBAR_INPUT, 135)    /* AOI2_OUT3 output assigned to XBARA1_IN135 input. */
#define IMXRT_XBARA1_IN_ADC_ETC0_COCO0                       IMXRT_XBARA1(XBAR_INPUT, 136)    /* ADC_ETC0_COCO0 output assigned to XBARA1_IN136 input. */
#define IMXRT_XBARA1_IN_ADC_ETC0_COCO1                       IMXRT_XBARA1(XBAR_INPUT, 137)    /* ADC_ETC0_COCO1 output assigned to XBARA1_IN137 input. */
#define IMXRT_XBARA1_IN_ADC_ETC0_COCO2                       IMXRT_XBARA1(XBAR_INPUT, 138)    /* ADC_ETC0_COCO2 output assigned to XBARA1_IN138 input. */
#define IMXRT_XBARA1_IN_ADC_ETC0_COCO3                       IMXRT_XBARA1(XBAR_INPUT, 139)    /* ADC_ETC0_COCO3 output assigned to XBARA1_IN139 input. */
#define IMXRT_XBARA1_IN_ADC_ETC1_COCO0                       IMXRT_XBARA1(XBAR_INPUT, 140)    /* ADC_ETC1_COCO0 output assigned to XBARA1_IN140 input. */
#define IMXRT_XBARA1_IN_ADC_ETC1_COCO1                       IMXRT_XBARA1(XBAR_INPUT, 141)    /* ADC_ETC1_COCO1 output assigned to XBARA1_IN141 input. */
#define IMXRT_XBARA1_IN_ADC_ETC1_COCO2                       IMXRT_XBARA1(XBAR_INPUT, 142)    /* ADC_ETC1_COCO2 output assigned to XBARA1_IN142 input. */
#define IMXRT_XBARA1_IN_ADC_ETC1_COCO3                       IMXRT_XBARA1(XBAR_INPUT, 143)    /* ADC_ETC1_COCO3 output assigned to XBARA1_IN143 input. */
#define IMXRT_XBARA1_IN_GND144                               IMXRT_XBARA1(XBAR_INPUT, 144)    /* GND assigned to XBARA1_IN144 input. */
#define IMXRT_XBARA1_IN_GND145                               IMXRT_XBARA1(XBAR_INPUT, 145)    /* GND assigned to XBARA1_IN145 input. */

/* XBARA1 Mux Output (M Muxes) **********************************************/

#define IMXRT_XBARA1_OUT_DMA_CH_MUX_REQ81_SEL_OFFSET         IMXRT_XBARA1(XBAR_OUTPUT, 0)     /* XBARA1_OUT0 output assigned to DMA_CH_MUX_REQ81 */
#define IMXRT_XBARA1_OUT_DMA_CH_MUX_REQ82_SEL_OFFSET         IMXRT_XBARA1(XBAR_OUTPUT, 1)     /* XBARA1_OUT1 output assigned to DMA_CH_MUX_REQ82 */
#define IMXRT_XBARA1_OUT_DMA_CH_MUX_REQ83_SEL_OFFSET         IMXRT_XBARA1(XBAR_OUTPUT, 2)     /* XBARA1_OUT2 output assigned to DMA_CH_MUX_REQ83 */
#define IMXRT_XBARA1_OUT_DMA_CH_MUX_REQ84_SEL_OFFSET         IMXRT_XBARA1(XBAR_OUTPUT, 3)     /* XBARA1_OUT3 output assigned to DMA_CH_MUX_REQ84 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO04_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 4)     /* XBARA1_OUT4 output assigned to IOMUX_XBAR_INOUT04 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO05_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 5)     /* XBARA1_OUT5 output assigned to IOMUX_XBAR_INOUT05 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO06_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 6)     /* XBARA1_OUT6 output assigned to IOMUX_XBAR_INOUT06 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO07_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 7)     /* XBARA1_OUT7 output assigned to IOMUX_XBAR_INOUT07 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO08_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 8)     /* XBARA1_OUT8 output assigned to IOMUX_XBAR_INOUT08 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO09_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 9)     /* XBARA1_OUT9 output assigned to IOMUX_XBAR_INOUT09 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO10_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 10)    /* XBARA1_OUT10 output assigned to IOMUX_XBAR_INOUT10 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO11_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 11)    /* XBARA1_OUT11 output assigned to IOMUX_XBAR_INOUT11 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO12_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 12)    /* XBARA1_OUT12 output assigned to IOMUX_XBAR_INOUT12 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO13_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 13)    /* XBARA1_OUT13 output assigned to IOMUX_XBAR_INOUT13 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO14_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 14)    /* XBARA1_OUT14 output assigned to IOMUX_XBAR_INOUT14 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO15_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 15)    /* XBARA1_OUT15 output assigned to IOMUX_XBAR_INOUT15 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO16_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 16)    /* XBARA1_OUT16 output assigned to IOMUX_XBAR_INOUT16 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO17_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 17)    /* XBARA1_OUT17 output assigned to IOMUX_XBAR_INOUT17 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO18_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 18)    /* XBARA1_OUT18 output assigned to IOMUX_XBAR_INOUT18 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO19_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 19)    /* XBARA1_OUT19 output assigned to IOMUX_XBAR_INOUT19 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO20_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 20)    /* XBARA1_OUT20 output assigned to IOMUX_XBAR_INOUT20 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO21_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 21)    /* XBARA1_OUT21 output assigned to IOMUX_XBAR_INOUT21 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO22_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 22)    /* XBARA1_OUT22 output assigned to IOMUX_XBAR_INOUT22 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO23_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 23)    /* XBARA1_OUT23 output assigned to IOMUX_XBAR_INOUT23 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO24_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 24)    /* XBARA1_OUT24 output assigned to IOMUX_XBAR_INOUT24 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO25_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 25)    /* XBARA1_OUT25 output assigned to IOMUX_XBAR_INOUT25 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO26_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 26)    /* XBARA1_OUT26 output assigned to IOMUX_XBAR_INOUT26 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO27_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 27)    /* XBARA1_OUT27 output assigned to IOMUX_XBAR_INOUT27 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO28_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 28)    /* XBARA1_OUT28 output assigned to IOMUX_XBAR_INOUT28 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO29_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 29)    /* XBARA1_OUT29 output assigned to IOMUX_XBAR_INOUT29 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO30_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 30)    /* XBARA1_OUT30 output assigned to IOMUX_XBAR_INOUT30 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO31_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 31)    /* XBARA1_OUT31 output assigned to IOMUX_XBAR_INOUT31 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO32_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 32)    /* XBARA1_OUT32 output assigned to IOMUX_XBAR_INOUT32 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO33_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 33)    /* XBARA1_OUT33 output assigned to IOMUX_XBAR_INOUT33 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO34_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 34)    /* XBARA1_OUT34 output assigned to IOMUX_XBAR_INOUT34 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO35_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 35)    /* XBARA1_OUT35 output assigned to IOMUX_XBAR_INOUT35 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO36_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 36)    /* XBARA1_OUT36 output assigned to IOMUX_XBAR_INOUT36 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO37_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 37)    /* XBARA1_OUT37 output assigned to IOMUX_XBAR_INOUT37 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO38_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 38)    /* XBARA1_OUT38 output assigned to IOMUX_XBAR_INOUT38 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO39_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 39)    /* XBARA1_OUT39 output assigned to IOMUX_XBAR_INOUT39 */
#define IMXRT_XBARA1_OUT_IOMUX_XBAR_IO40_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 40)    /* XBARA1_OUT40 output assigned to IOMUX_XBAR_INOUT40 */
#define IMXRT_XBARA1_OUT_ACMP1_SAMPLE_SEL_OFFSET             IMXRT_XBARA1(XBAR_OUTPUT, 41)    /* XBARA1_OUT41 output assigned to ACMP1_SAMPLE */
#define IMXRT_XBARA1_OUT_ACMP2_SAMPLE_SEL_OFFSET             IMXRT_XBARA1(XBAR_OUTPUT, 42)    /* XBARA1_OUT42 output assigned to ACMP2_SAMPLE */
#define IMXRT_XBARA1_OUT_ACMP3_SAMPLE_SEL_OFFSET             IMXRT_XBARA1(XBAR_OUTPUT, 43)    /* XBARA1_OUT43 output assigned to ACMP3_SAMPLE */
#define IMXRT_XBARA1_OUT_ACMP4_SAMPLE_SEL_OFFSET             IMXRT_XBARA1(XBAR_OUTPUT, 44)    /* XBARA1_OUT44 output assigned to ACMP4_SAMPLE */
#define IMXRT_XBARA1_OUT_RESERVED45_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 45)    /* XBARA1_OUT45 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED46_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 46)    /* XBARA1_OUT46 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED47_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 47)    /* XBARA1_OUT47 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED48_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 48)    /* XBARA1_OUT48 output is reserved. */
#define IMXRT_XBARA1_OUT_FLEXPWM1_PWM0_EXTA_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 49)    /* XBARA1_OUT49 output assigned to FLEXPWM1_PWM0_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM1_PWM1_EXTA_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 50)    /* XBARA1_OUT50 output assigned to FLEXPWM1_PWM1_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM1_PWM2_EXTA_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 51)    /* XBARA1_OUT51 output assigned to FLEXPWM1_PWM2_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM1_PWM3_EXTA_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 52)    /* XBARA1_OUT52 output assigned to FLEXPWM1_PWM3_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM1_PWM0_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 53)    /* XBARA1_OUT53 output assigned to FLEXPWM1_PWM0_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM1_PWM1_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 54)    /* XBARA1_OUT54 output assigned to FLEXPWM1_PWM1_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM1_PWM2_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 55)    /* XBARA1_OUT55 output assigned to FLEXPWM1_PWM2_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM1_PWM3_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 56)    /* XBARA1_OUT56 output assigned to FLEXPWM1_PWM3_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM1_EXT_CLK_SEL_OFFSET         IMXRT_XBARA1(XBAR_OUTPUT, 57)    /* XBARA1_OUT57 output assigned to FLEXPWM1_EXT_CLK */
#define IMXRT_XBARA1_OUT_FLEXPWM1_FAULT0_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 58)    /* XBARA1_OUT58 output assigned to FLEXPWM1_FAULT0 */
#define IMXRT_XBARA1_OUT_FLEXPWM1_FAULT1_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 59)    /* XBARA1_OUT59 output assigned to FLEXPWM1_FAULT1 */
#define IMXRT_XBARA1_OUT_FLEXPWM1234_FAULT2_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 60)    /* XBARA1_OUT60 output assigned to FLEXPWM1_2_3_4_FAULT2 */
#define IMXRT_XBARA1_OUT_FLEXPWM1234_FAULT3_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 61)    /* XBARA1_OUT61 output assigned to FLEXPWM1_2_3_4_FAULT3 */
#define IMXRT_XBARA1_OUT_FLEXPWM1_EXT_FORCE_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 62)    /* XBARA1_OUT62 output assigned to FLEXPWM1_EXT_FORCE */
#define IMXRT_XBARA1_OUT_FLEXPWM2_PWM0_EXTA_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 63)    /* XBARA1_OUT63 output assigned to FLEXPWM2_PWM0_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM2_PWM1_EXTA_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 64)    /* XBARA1_OUT64 output assigned to FLEXPWM2_PWM1_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM2_PWM2_EXTA_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 65)    /* XBARA1_OUT65 output assigned to FLEXPWM2_PWM2_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM2_PWM3_EXTA_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 66)    /* XBARA1_OUT66 output assigned to FLEXPWM2_PWM3_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM2_PWM0_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 67)    /* XBARA1_OUT67 output assigned to FLEXPWM2_PWM0_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM2_PWM1_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 68)    /* XBARA1_OUT68 output assigned to FLEXPWM2_PWM1_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM2_PWM2_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 69)    /* XBARA1_OUT69 output assigned to FLEXPWM2_PWM2_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM2_PWM3_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 70)    /* XBARA1_OUT70 output assigned to FLEXPWM2_PWM3_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM2_EXT_CLK_SEL_OFFSET         IMXRT_XBARA1(XBAR_OUTPUT, 71)    /* XBARA1_OUT71 output assigned to FLEXPWM2_EXT_CLK */
#define IMXRT_XBARA1_OUT_FLEXPWM2_FAULT0_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 72)    /* XBARA1_OUT72 output assigned to FLEXPWM2_FAULT0 */
#define IMXRT_XBARA1_OUT_FLEXPWM2_FAULT1_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 73)    /* XBARA1_OUT73 output assigned to FLEXPWM2_FAULT1 */
#define IMXRT_XBARA1_OUT_FLEXPWM2_EXT_FORCE_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 74)    /* XBARA1_OUT74 output assigned to FLEXPWM2_EXT_FORCE */
#define IMXRT_XBARA1_OUT_FLEXPWM34_PWM0_EXTA_SEL_OFFSET      IMXRT_XBARA1(XBAR_OUTPUT, 75)    /* XBARA1_OUT75 output assigned to FLEXPWM3_4_PWM0_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM34_PWM1_EXTA_SEL_OFFSET      IMXRT_XBARA1(XBAR_OUTPUT, 76)    /* XBARA1_OUT76 output assigned to FLEXPWM3_4_PWM1_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM34_PWM2_EXTA_SEL_OFFSET      IMXRT_XBARA1(XBAR_OUTPUT, 77)    /* XBARA1_OUT77 output assigned to FLEXPWM3_4_PWM2_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM34_PWM3_EXTA_SEL_OFFSET      IMXRT_XBARA1(XBAR_OUTPUT, 78)    /* XBARA1_OUT78 output assigned to FLEXPWM3_4_PWM3_EXTA */
#define IMXRT_XBARA1_OUT_FLEXPWM34_EXT_CLK_SEL_OFFSET        IMXRT_XBARA1(XBAR_OUTPUT, 79)    /* XBARA1_OUT79 output assigned to FLEXPWM3_4_EXT_CLK */
#define IMXRT_XBARA1_OUT_FLEXPWM3_PWM0_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 80)    /* XBARA1_OUT80 output assigned to FLEXPWM3_PWM0_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM3_PWM1_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 81)    /* XBARA1_OUT81 output assigned to FLEXPWM3_PWM1_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM3_PWM2_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 82)    /* XBARA1_OUT82 output assigned to FLEXPWM3_PWM2_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM3_PWM3_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 83)    /* XBARA1_OUT83 output assigned to FLEXPWM3_PWM3_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM3_FAULT0_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 84)    /* XBARA1_OUT84 output assigned to FLEXPWM3_FAULT0 */
#define IMXRT_XBARA1_OUT_FLEXPWM3_FAULT1_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 85)    /* XBARA1_OUT85 output assigned to FLEXPWM3_FAULT1 */
#define IMXRT_XBARA1_OUT_FLEXPWM3_EXT_FORCE_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 86)    /* XBARA1_OUT86 output assigned to FLEXPWM3_EXT_FORCE */
#define IMXRT_XBARA1_OUT_FLEXPWM4_PWM0_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 87)    /* XBARA1_OUT87 output assigned to FLEXPWM4_PWM0_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM4_PWM1_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 88)    /* XBARA1_OUT88 output assigned to FLEXPWM4_PWM1_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM4_PWM2_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 89)    /* XBARA1_OUT89 output assigned to FLEXPWM4_PWM2_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM4_PWM3_EXT_SYNC_SEL_OFFSET   IMXRT_XBARA1(XBAR_OUTPUT, 90)    /* XBARA1_OUT90 output assigned to FLEXPWM4_PWM3_EXT_SYNC */
#define IMXRT_XBARA1_OUT_FLEXPWM4_FAULT0_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 91)    /* XBARA1_OUT91 output assigned to FLEXPWM4_FAULT0 */
#define IMXRT_XBARA1_OUT_FLEXPWM4_FAULT1_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 92)    /* XBARA1_OUT92 output assigned to FLEXPWM4_FAULT1 */
#define IMXRT_XBARA1_OUT_FLEXPWM4_EXT_FORCE_SEL_OFFSET       IMXRT_XBARA1(XBAR_OUTPUT, 93)    /* XBARA1_OUT93 output assigned to FLEXPWM4_EXT_FORCE */
#define IMXRT_XBARA1_OUT_RESERVED94_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 94)    /* XBARA1_OUT94 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED95_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 95)    /* XBARA1_OUT95 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED96_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 96)    /* XBARA1_OUT96 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED97_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 97)    /* XBARA1_OUT97 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED98_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 98)    /* XBARA1_OUT98 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED99_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 99)    /* XBARA1_OUT99 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED100_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 100)   /* XBARA1_OUT100 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED101_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 101)   /* XBARA1_OUT101 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED102_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 102)   /* XBARA1_OUT102 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED103_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 103)   /* XBARA1_OUT103 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED104_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 104)   /* XBARA1_OUT104 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED105_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 105)   /* XBARA1_OUT105 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED106_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 106)   /* XBARA1_OUT106 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED107_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 107)   /* XBARA1_OUT107 output is reserved. */
#define IMXRT_XBARA1_OUT_QDC1_PHASEA_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 108)   /* XBARA1_OUT108 output assigned to QDC1_PHASEA */
#define IMXRT_XBARA1_OUT_QDC1_PHASEB_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 109)   /* XBARA1_OUT109 output assigned to QDC1_PHASEB */
#define IMXRT_XBARA1_OUT_QDC1_INDEX_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 110)   /* XBARA1_OUT110 output assigned to QDC1_INDEX */
#define IMXRT_XBARA1_OUT_QDC1_HOME_SEL_OFFSET                IMXRT_XBARA1(XBAR_OUTPUT, 111)   /* XBARA1_OUT111 output assigned to QDC1_HOME */
#define IMXRT_XBARA1_OUT_QDC1_TRIGGER_SEL_OFFSET             IMXRT_XBARA1(XBAR_OUTPUT, 112)   /* XBARA1_OUT112 output assigned to QDC1_TRIGGER */
#define IMXRT_XBARA1_OUT_QDC2_PHASEA_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 113)   /* XBARA1_OUT113 output assigned to QDC2_PHASEA */
#define IMXRT_XBARA1_OUT_QDC2_PHASEB_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 114)   /* XBARA1_OUT114 output assigned to QDC2_PHASEB */
#define IMXRT_XBARA1_OUT_QDC2_INDEX_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 115)   /* XBARA1_OUT115 output assigned to QDC2_INDEX */
#define IMXRT_XBARA1_OUT_QDC2_HOME_SEL_OFFSET                IMXRT_XBARA1(XBAR_OUTPUT, 116)   /* XBARA1_OUT116 output assigned to QDC2_HOME */
#define IMXRT_XBARA1_OUT_QDC2_TRIGGER_SEL_OFFSET             IMXRT_XBARA1(XBAR_OUTPUT, 117)   /* XBARA1_OUT117 output assigned to QDC2_TRIGGER */
#define IMXRT_XBARA1_OUT_QDC3_PHASEA_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 118)   /* XBARA1_OUT118 output assigned to QDC3_PHASEA */
#define IMXRT_XBARA1_OUT_QDC3_PHASEB_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 119)   /* XBARA1_OUT119 output assigned to QDC3_PHASEB */
#define IMXRT_XBARA1_OUT_QDC3_INDEX_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 120)   /* XBARA1_OUT120 output assigned to QDC3_INDEX */
#define IMXRT_XBARA1_OUT_QDC3_HOME_SEL_OFFSET                IMXRT_XBARA1(XBAR_OUTPUT, 121)   /* XBARA1_OUT121 output assigned to QDC3_HOME */
#define IMXRT_XBARA1_OUT_QDC3_TRIGGER_SEL_OFFSET             IMXRT_XBARA1(XBAR_OUTPUT, 122)   /* XBARA1_OUT122 output assigned to QDC3_TRIGGER */
#define IMXRT_XBARA1_OUT_QDC4_PHASEA_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 123)   /* XBARA1_OUT123 output assigned to QDC4_PHASEA */
#define IMXRT_XBARA1_OUT_QDC4_PHASEB_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 124)   /* XBARA1_OUT124 output assigned to QDC4_PHASEB */
#define IMXRT_XBARA1_OUT_QDC4_INDEX_SEL_OFFSET               IMXRT_XBARA1(XBAR_OUTPUT, 125)   /* XBARA1_OUT125 output assigned to QDC4_INDEX */
#define IMXRT_XBARA1_OUT_QDC4_HOME_SEL_OFFSET                IMXRT_XBARA1(XBAR_OUTPUT, 126)   /* XBARA1_OUT126 output assigned to QDC4_HOME */
#define IMXRT_XBARA1_OUT_QDC4_TRIGGER_SEL_OFFSET             IMXRT_XBARA1(XBAR_OUTPUT, 127)   /* XBARA1_OUT127 output assigned to QDC4_TRIGGER */
#define IMXRT_XBARA1_OUT_RESERVED128_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 128)   /* XBARA1_OUT128 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED129_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 129)   /* XBARA1_OUT129 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED130_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 130)   /* XBARA1_OUT130 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED131_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 131)   /* XBARA1_OUT131 output is reserved. */
#define IMXRT_XBARA1_OUT_CAN1_SEL_OFFSET                     IMXRT_XBARA1(XBAR_OUTPUT, 132)   /* XBARA1_OUT132 output assigned to CAN1 */
#define IMXRT_XBARA1_OUT_CAN2_SEL_OFFSET                     IMXRT_XBARA1(XBAR_OUTPUT, 133)   /* XBARA1_OUT133 output assigned to CAN2 */
#define IMXRT_XBARA1_OUT_RESERVED134_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 134)   /* XBARA1_OUT134 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED135_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 135)   /* XBARA1_OUT135 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED136_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 136)   /* XBARA1_OUT136 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED137_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 137)   /* XBARA1_OUT137 output is reserved. */
#define IMXRT_XBARA1_OUT_QTIMER1_TMR0_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 138)   /* XBARA1_OUT138 output assigned to QTIMER1_TMR0_IN */
#define IMXRT_XBARA1_OUT_QTIMER1_TMR1_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 139)   /* XBARA1_OUT139 output assigned to QTIMER1_TMR1_IN */
#define IMXRT_XBARA1_OUT_QTIMER1_TMR2_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 140)   /* XBARA1_OUT140 output assigned to QTIMER1_TMR2_IN */
#define IMXRT_XBARA1_OUT_QTIMER1_TMR3_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 141)   /* XBARA1_OUT141 output assigned to QTIMER1_TMR3_IN */
#define IMXRT_XBARA1_OUT_QTIMER2_TMR0_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 142)   /* XBARA1_OUT142 output assigned to QTIMER2_TMR0_IN */
#define IMXRT_XBARA1_OUT_QTIMER2_TMR1_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 143)   /* XBARA1_OUT143 output assigned to QTIMER2_TMR1_IN */
#define IMXRT_XBARA1_OUT_QTIMER2_TMR2_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 144)   /* XBARA1_OUT144 output assigned to QTIMER2_TMR2_IN */
#define IMXRT_XBARA1_OUT_QTIMER2_TMR3_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 145)   /* XBARA1_OUT145 output assigned to QTIMER2_TMR3_IN */
#define IMXRT_XBARA1_OUT_QTIMER3_TMR0_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 146)   /* XBARA1_OUT146 output assigned to QTIMER3_TMR0_IN */
#define IMXRT_XBARA1_OUT_QTIMER3_TMR1_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 147)   /* XBARA1_OUT147 output assigned to QTIMER3_TMR1_IN */
#define IMXRT_XBARA1_OUT_QTIMER3_TMR2_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 148)   /* XBARA1_OUT148 output assigned to QTIMER3_TMR2_IN */
#define IMXRT_XBARA1_OUT_QTIMER3_TMR3_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 149)   /* XBARA1_OUT149 output assigned to QTIMER3_TMR3_IN */
#define IMXRT_XBARA1_OUT_QTIMER4_TMR0_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 150)   /* XBARA1_OUT150 output assigned to QTIMER4_TMR0_IN */
#define IMXRT_XBARA1_OUT_QTIMER4_TMR1_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 151)   /* XBARA1_OUT151 output assigned to QTIMER4_TMR1_IN */
#define IMXRT_XBARA1_OUT_QTIMER4_TMR2_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 152)   /* XBARA1_OUT152 output assigned to QTIMER4_TMR2_IN */
#define IMXRT_XBARA1_OUT_QTIMER4_TMR3_IN_SEL_OFFSET          IMXRT_XBARA1(XBAR_OUTPUT, 153)   /* XBARA1_OUT153 output assigned to QTIMER4_TMR3_IN */
#define IMXRT_XBARA1_OUT_EWM_IN_SEL_OFFSET                   IMXRT_XBARA1(XBAR_OUTPUT, 154)   /* XBARA1_OUT154 output assigned to EWM_IN */
#define IMXRT_XBARA1_OUT_ADC_ETC0_TRIG0_SEL_OFFSET           IMXRT_XBARA1(XBAR_OUTPUT, 155)   /* XBARA1_OUT155 output assigned to ADC_ETC0_TRIG0 */
#define IMXRT_XBARA1_OUT_ADC_ETC0_TRIG1_SEL_OFFSET           IMXRT_XBARA1(XBAR_OUTPUT, 156)   /* XBARA1_OUT156 output assigned to ADC_ETC0_TRIG1 */
#define IMXRT_XBARA1_OUT_ADC_ETC0_TRIG2_SEL_OFFSET           IMXRT_XBARA1(XBAR_OUTPUT, 157)   /* XBARA1_OUT157 output assigned to ADC_ETC0_TRIG2 */
#define IMXRT_XBARA1_OUT_ADC_ETC0_TRIG3_SEL_OFFSET           IMXRT_XBARA1(XBAR_OUTPUT, 158)   /* XBARA1_OUT158 output assigned to ADC_ETC0_TRIG3 */
#define IMXRT_XBARA1_OUT_ADC_ETC1_TRIG0_SEL_OFFSET           IMXRT_XBARA1(XBAR_OUTPUT, 159)   /* XBARA1_OUT159 output assigned to ADC_ETC1_TRIG0 */
#define IMXRT_XBARA1_OUT_ADC_ETC1_TRIG1_SEL_OFFSET           IMXRT_XBARA1(XBAR_OUTPUT, 160)   /* XBARA1_OUT160 output assigned to ADC_ETC1_TRIG1 */
#define IMXRT_XBARA1_OUT_ADC_ETC1_TRIG2_SEL_OFFSET           IMXRT_XBARA1(XBAR_OUTPUT, 161)   /* XBARA1_OUT161 output assigned to ADC_ETC1_TRIG2 */
#define IMXRT_XBARA1_OUT_ADC_ETC1_TRIG3_SEL_OFFSET           IMXRT_XBARA1(XBAR_OUTPUT, 162)   /* XBARA1_OUT162 output assigned to ADC_ETC1_TRIG3 */
#define IMXRT_XBARA1_OUT_RESERVED163_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 163)   /* XBARA1_OUT163 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED164_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 164)   /* XBARA1_OUT164 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED165_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 165)   /* XBARA1_OUT165 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED166_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 166)   /* XBARA1_OUT166 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED167_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 167)   /* XBARA1_OUT167 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED168_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 168)   /* XBARA1_OUT168 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED169_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 169)   /* XBARA1_OUT169 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED170_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 170)   /* XBARA1_OUT170 output is reserved. */
#define IMXRT_XBARA1_OUT_FLEXIO1_TRIGGER_IN0_SEL_OFFSET      IMXRT_XBARA1(XBAR_OUTPUT, 171)   /* XBARA1_OUT171 output assigned to FLEXIO1_TRIGGER_IN0 */
#define IMXRT_XBARA1_OUT_FLEXIO1_TRIGGER_IN1_SEL_OFFSET      IMXRT_XBARA1(XBAR_OUTPUT, 172)   /* XBARA1_OUT172 output assigned to FLEXIO1_TRIGGER_IN1 */
#define IMXRT_XBARA1_OUT_FLEXIO2_TRIGGER_IN0_SEL_OFFSET      IMXRT_XBARA1(XBAR_OUTPUT, 173)   /* XBARA1_OUT173 output assigned to FLEXIO2_TRIGGER_IN0 */
#define IMXRT_XBARA1_OUT_FLEXIO2_TRIGGER_IN1_SEL_OFFSET      IMXRT_XBARA1(XBAR_OUTPUT, 174)   /* XBARA1_OUT174 output assigned to FLEXIO2_TRIGGER_IN1 */
#define IMXRT_XBARA1_OUT_RESERVED175_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 175)   /* XBARA1_OUT175 output is reserved. */
#define IMXRT_XBARA1_OUT_RESERVED176_SEL_OFFSET              IMXRT_XBARA1(XBAR_OUTPUT, 176)   /* XBARA1_OUT176 output is reserved. */

/* XBARB2 Mux Inputs (I Values) *********************************************/

#define IMXRT_XBARB2_IN_LOGIC_LOW                            IMXRT_XBARB2(XBAR_INPUT, 0)     /* LOGIC_LOW output assigned to XBARB2_IN0 input. */
#define IMXRT_XBARB2_IN_LOGIC_HIGH                           IMXRT_XBARB2(XBAR_INPUT, 1)     /* LOGIC_HIGH output assigned to XBARB2_IN1 input. */
#define IMXRT_XBARB2_IN_ACMP1_OUT                            IMXRT_XBARB2(XBAR_INPUT, 2)     /* ACMP1_OUT output assigned to XBARB2_IN2 input. */
#define IMXRT_XBARB2_IN_ACMP2_OUT                            IMXRT_XBARB2(XBAR_INPUT, 3)     /* ACMP2_OUT output assigned to XBARB2_IN3 input. */
#define IMXRT_XBARB2_IN_ACMP3_OUT                            IMXRT_XBARB2(XBAR_INPUT, 4)     /* ACMP3_OUT output assigned to XBARB2_IN4 input. */
#define IMXRT_XBARB2_IN_ACMP4_OUT                            IMXRT_XBARB2(XBAR_INPUT, 5)     /* ACMP4_OUT output assigned to XBARB2_IN5 input. */
#define IMXRT_XBARB2_IN_GND6                                 IMXRT_XBARB2(XBAR_INPUT, 6)     /* GND assigned to XBARB2_IN6 input. */
#define IMXRT_XBARB2_IN_GND7                                 IMXRT_XBARB2(XBAR_INPUT, 7)     /* GND assigned to XBARB2_IN7 input. */
#define IMXRT_XBARB2_IN_GND8                                 IMXRT_XBARB2(XBAR_INPUT, 8)     /* GND assigned to XBARB2_IN8 input. */
#define IMXRT_XBARB2_IN_GND9                                 IMXRT_XBARB2(XBAR_INPUT, 9)     /* GND assigned to XBARB2_IN9 input. */
#define IMXRT_XBARB2_IN_QTIMER1_TMR0_OUT                     IMXRT_XBARB2(XBAR_INPUT, 10)    /* QTIMER1_TMR0_OUTPUT output assigned to XBARB2_IN10 input. */
#define IMXRT_XBARB2_IN_QTIMER1_TMR1_OUT                     IMXRT_XBARB2(XBAR_INPUT, 11)    /* QTIMER1_TMR1_OUTPUT output assigned to XBARB2_IN11 input. */
#define IMXRT_XBARB2_IN_QTIMER1_TMR2_OUT                     IMXRT_XBARB2(XBAR_INPUT, 12)    /* QTIMER1_TMR2_OUTPUT output assigned to XBARB2_IN12 input. */
#define IMXRT_XBARB2_IN_QTIMER1_TMR3_OUT                     IMXRT_XBARB2(XBAR_INPUT, 13)    /* QTIMER1_TMR3_OUTPUT output assigned to XBARB2_IN13 input. */
#define IMXRT_XBARB2_IN_QTIMER2_TMR0_OUT                     IMXRT_XBARB2(XBAR_INPUT, 14)    /* QTIMER2_TMR0_OUTPUT output assigned to XBARB2_IN14 input. */
#define IMXRT_XBARB2_IN_QTIMER2_TMR1_OUT                     IMXRT_XBARB2(XBAR_INPUT, 15)    /* QTIMER2_TMR1_OUTPUT output assigned to XBARB2_IN15 input. */
#define IMXRT_XBARB2_IN_QTIMER2_TMR2_OUT                     IMXRT_XBARB2(XBAR_INPUT, 16)    /* QTIMER2_TMR2_OUTPUT output assigned to XBARB2_IN16 input. */
#define IMXRT_XBARB2_IN_QTIMER2_TMR3_OUT                     IMXRT_XBARB2(XBAR_INPUT, 17)    /* QTIMER2_TMR3_OUTPUT output assigned to XBARB2_IN17 input. */
#define IMXRT_XBARB2_IN_QTIMER3_TMR0_OUT                     IMXRT_XBARB2(XBAR_INPUT, 18)    /* QTIMER3_TMR0_OUTPUT output assigned to XBARB2_IN18 input. */
#define IMXRT_XBARB2_IN_QTIMER3_TMR1_OUT                     IMXRT_XBARB2(XBAR_INPUT, 19)    /* QTIMER3_TMR1_OUTPUT output assigned to XBARB2_IN19 input. */
#define IMXRT_XBARB2_IN_QTIMER3_TMR2_OUT                     IMXRT_XBARB2(XBAR_INPUT, 20)    /* QTIMER3_TMR2_OUTPUT output assigned to XBARB2_IN20 input. */
#define IMXRT_XBARB2_IN_QTIMER3_TMR3_OUT                     IMXRT_XBARB2(XBAR_INPUT, 21)    /* QTIMER3_TMR3_OUTPUT output assigned to XBARB2_IN21 input. */
#define IMXRT_XBARB2_IN_QTIMER4_TMR0_OUT                     IMXRT_XBARB2(XBAR_INPUT, 22)    /* QTIMER4_TMR0_OUTPUT output assigned to XBARB2_IN22 input. */
#define IMXRT_XBARB2_IN_QTIMER4_TMR1_OUT                     IMXRT_XBARB2(XBAR_INPUT, 23)    /* QTIMER4_TMR1_OUTPUT output assigned to XBARB2_IN23 input. */
#define IMXRT_XBARB2_IN_QTIMER4_TMR2_OUT                     IMXRT_XBARB2(XBAR_INPUT, 24)    /* QTIMER4_TMR2_OUTPUT output assigned to XBARB2_IN24 input. */
#define IMXRT_XBARB2_IN_QTIMER4_TMR3_OUT                     IMXRT_XBARB2(XBAR_INPUT, 25)    /* QTIMER4_TMR3_OUTPUT output assigned to XBARB2_IN25 input. */
#define IMXRT_XBARB2_IN_GND26                                IMXRT_XBARB2(XBAR_INPUT, 26)    /* GND assigned to XBARB2_IN26 input. */
#define IMXRT_XBARB2_IN_GND27                                IMXRT_XBARB2(XBAR_INPUT, 27)    /* GND assigned to XBARB2_IN27 input. */
#define IMXRT_XBARB2_IN_GND28                                IMXRT_XBARB2(XBAR_INPUT, 28)    /* GND assigned to XBARB2_IN28 input. */
#define IMXRT_XBARB2_IN_GND29                                IMXRT_XBARB2(XBAR_INPUT, 29)    /* GND assigned to XBARB2_IN29 input. */
#define IMXRT_XBARB2_IN_GND30                                IMXRT_XBARB2(XBAR_INPUT, 30)    /* GND assigned to XBARB2_IN30 input. */
#define IMXRT_XBARB2_IN_GND31                                IMXRT_XBARB2(XBAR_INPUT, 31)    /* GND assigned to XBARB2_IN31 input. */
#define IMXRT_XBARB2_IN_GND32                                IMXRT_XBARB2(XBAR_INPUT, 32)    /* GND assigned to XBARB2_IN32 input. */
#define IMXRT_XBARB2_IN_GND33                                IMXRT_XBARB2(XBAR_INPUT, 33)    /* GND assigned to XBARB2_IN33 input. */
#define IMXRT_XBARB2_IN_FLEXPWM1_PWM0_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 34)    /* FLEXPWM1_PWM0_OUT_TRIG0_1 output assigned to XBARB2_IN34 input. */
#define IMXRT_XBARB2_IN_FLEXPWM1_PWM1_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 35)    /* FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARB2_IN35 input. */
#define IMXRT_XBARB2_IN_FLEXPWM1_PWM2_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 36)    /* FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARB2_IN36 input. */
#define IMXRT_XBARB2_IN_FLEXPWM1_PWM3_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 37)    /* FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARB2_IN37 input. */
#define IMXRT_XBARB2_IN_FLEXPWM2_PWM0_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 38)    /* FLEXPWM2_PWM0_OUT_TRIG0_1 output assigned to XBARB2_IN38 input. */
#define IMXRT_XBARB2_IN_FLEXPWM2_PWM1_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 39)    /* FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBARB2_IN39 input. */
#define IMXRT_XBARB2_IN_FLEXPWM2_PWM2_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 40)    /* FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBARB2_IN40 input. */
#define IMXRT_XBARB2_IN_FLEXPWM2_PWM3_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 41)    /* FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBARB2_IN41 input. */
#define IMXRT_XBARB2_IN_FLEXPWM3_PWM0_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 42)    /* FLEXPWM3_PWM0_OUT_TRIG0_1 output assigned to XBARB2_IN42 input. */
#define IMXRT_XBARB2_IN_FLEXPWM3_PWM1_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 43)    /* FLEXPWM3_PWM1_OUT_TRIG0_1 output assigned to XBARB2_IN43 input. */
#define IMXRT_XBARB2_IN_FLEXPWM3_PWM2_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 44)    /* FLEXPWM3_PWM2_OUT_TRIG0_1 output assigned to XBARB2_IN44 input. */
#define IMXRT_XBARB2_IN_FLEXPWM3_PWM3_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 45)    /* FLEXPWM3_PWM3_OUT_TRIG0_1 output assigned to XBARB2_IN45 input. */
#define IMXRT_XBARB2_IN_FLEXPWM4_PWM0_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 46)    /* FLEXPWM4_PWM0_OUT_TRIG0_1 output assigned to XBARB2_IN46 input. */
#define IMXRT_XBARB2_IN_FLEXPWM4_PWM1_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 47)    /* FLEXPWM4_PWM1_OUT_TRIG0_1 output assigned to XBARB2_IN47 input. */
#define IMXRT_XBARB2_IN_FLEXPWM4_PWM2_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 48)    /* FLEXPWM4_PWM2_OUT_TRIG0_1 output assigned to XBARB2_IN48 input. */
#define IMXRT_XBARB2_IN_FLEXPWM4_PWM3_OUT_TRIG01             IMXRT_XBARB2(XBAR_INPUT, 49)    /* FLEXPWM4_PWM3_OUT_TRIG0_1 output assigned to XBARB2_IN49 input. */
#define IMXRT_XBARB2_IN_GND50                                IMXRT_XBARB2(XBAR_INPUT, 50)    /* GND assigned to XBARB2_IN50 input. */
#define IMXRT_XBARB2_IN_GND51                                IMXRT_XBARB2(XBAR_INPUT, 51)    /* GND assigned to XBARB2_IN51 input. */
#define IMXRT_XBARB2_IN_GND52                                IMXRT_XBARB2(XBAR_INPUT, 52)    /* GND assigned to XBARB2_IN52 input. */
#define IMXRT_XBARB2_IN_GND53                                IMXRT_XBARB2(XBAR_INPUT, 53)    /* GND assigned to XBARB2_IN53 input. */
#define IMXRT_XBARB2_IN_GND54                                IMXRT_XBARB2(XBAR_INPUT, 54)    /* GND assigned to XBARB2_IN54 input. */
#define IMXRT_XBARB2_IN_GND55                                IMXRT_XBARB2(XBAR_INPUT, 55)    /* GND assigned to XBARB2_IN55 input. */
#define IMXRT_XBARB2_IN_GND56                                IMXRT_XBARB2(XBAR_INPUT, 56)    /* GND assigned to XBARB2_IN56 input. */
#define IMXRT_XBARB2_IN_GND57                                IMXRT_XBARB2(XBAR_INPUT, 57)    /* GND assigned to XBARB2_IN57 input. */
#define IMXRT_XBARB2_IN_PIT1_TRIGGER0                        IMXRT_XBARB2(XBAR_INPUT, 58)    /* PIT1_TRIGGER0 output assigned to XBARB2_IN58 input. */
#define IMXRT_XBARB2_IN_PIT1_TRIGGER1                        IMXRT_XBARB2(XBAR_INPUT, 59)    /* PIT1_TRIGGER1 output assigned to XBARB2_IN59 input. */
#define IMXRT_XBARB2_IN_ADC_ETC0_COCO0                       IMXRT_XBARB2(XBAR_INPUT, 60)    /* ADC_ETC0_COCO0 output assigned to XBARB2_IN60 input. */
#define IMXRT_XBARB2_IN_ADC_ETC0_COCO1                       IMXRT_XBARB2(XBAR_INPUT, 61)    /* ADC_ETC0_COCO1 output assigned to XBARB2_IN61 input. */
#define IMXRT_XBARB2_IN_ADC_ETC0_COCO2                       IMXRT_XBARB2(XBAR_INPUT, 62)    /* ADC_ETC0_COCO2 output assigned to XBARB2_IN62 input. */
#define IMXRT_XBARB2_IN_ADC_ETC0_COCO3                       IMXRT_XBARB2(XBAR_INPUT, 63)    /* ADC_ETC0_COCO3 output assigned to XBARB2_IN63 input. */
#define IMXRT_XBARB2_IN_ADC_ETC1_COCO0                       IMXRT_XBARB2(XBAR_INPUT, 64)    /* ADC_ETC1_COCO0 output assigned to XBARB2_IN64 input. */
#define IMXRT_XBARB2_IN_ADC_ETC1_COCO1                       IMXRT_XBARB2(XBAR_INPUT, 65)    /* ADC_ETC1_COCO1 output assigned to XBARB2_IN65 input. */
#define IMXRT_XBARB2_IN_ADC_ETC1_COCO2                       IMXRT_XBARB2(XBAR_INPUT, 66)    /* ADC_ETC1_COCO2 output assigned to XBARB2_IN66 input. */
#define IMXRT_XBARB2_IN_ADC_ETC1_COCO3                       IMXRT_XBARB2(XBAR_INPUT, 67)    /* ADC_ETC1_COCO3 output assigned to XBARB2_IN67 input. */
#define IMXRT_XBARB2_IN_GND68                                IMXRT_XBARB2(XBAR_INPUT, 68)    /* GND assigned to XBARB2_IN68 input. */
#define IMXRT_XBARB2_IN_GND69                                IMXRT_XBARB2(XBAR_INPUT, 69)    /* GND assigned to XBARB2_IN69 input. */
#define IMXRT_XBARB2_IN_GND70                                IMXRT_XBARB2(XBAR_INPUT, 70)    /* GND assigned to XBARB2_IN70 input. */
#define IMXRT_XBARB2_IN_GND71                                IMXRT_XBARB2(XBAR_INPUT, 71)    /* GND assigned to XBARB2_IN71 input. */
#define IMXRT_XBARB2_IN_GND72                                IMXRT_XBARB2(XBAR_INPUT, 72)    /* GND assigned to XBARB2_IN72 input. */
#define IMXRT_XBARB2_IN_GND73                                IMXRT_XBARB2(XBAR_INPUT, 73)    /* GND assigned to XBARB2_IN73 input. */
#define IMXRT_XBARB2_IN_GND74                                IMXRT_XBARB2(XBAR_INPUT, 74)    /* GND assigned to XBARB2_IN74 input. */
#define IMXRT_XBARB2_IN_GND75                                IMXRT_XBARB2(XBAR_INPUT, 75)    /* GND assigned to XBARB2_IN75 input. */
#define IMXRT_XBARB2_IN_QDC1_POSMATCH                        IMXRT_XBARB2(XBAR_INPUT, 76)    /* QDC1_POSMATCH output assigned to XBARB2_IN76 input. */
#define IMXRT_XBARB2_IN_QDC2_POSMATCH                        IMXRT_XBARB2(XBAR_INPUT, 77)    /* QDC2_POSMATCH output assigned to XBARB2_IN77 input. */
#define IMXRT_XBARB2_IN_QDC3_POSMATCH                        IMXRT_XBARB2(XBAR_INPUT, 78)    /* QDC3_POSMATCH output assigned to XBARB2_IN78 input. */
#define IMXRT_XBARB2_IN_QDC4_POSMATCH                        IMXRT_XBARB2(XBAR_INPUT, 79)    /* QDC4_POSMATCH output assigned to XBARB2_IN79 input. */
#define IMXRT_XBARB2_IN_GND80                                IMXRT_XBARB2(XBAR_INPUT, 80)    /* GND assigned to XBARB2_IN80 input. */
#define IMXRT_XBARB2_IN_GND81                                IMXRT_XBARB2(XBAR_INPUT, 81)    /* GND assigned to XBARB2_IN81 input. */
#define IMXRT_XBARB2_IN_EDMA_DONE0                           IMXRT_XBARB2(XBAR_INPUT, 82)    /* EDMA_DONE0 output assigned to XBARB2_IN82 input. */
#define IMXRT_XBARB2_IN_EDMA_DONE1                           IMXRT_XBARB2(XBAR_INPUT, 83)    /* EDMA_DONE1 output assigned to XBARB2_IN83 input. */
#define IMXRT_XBARB2_IN_EDMA_DONE2                           IMXRT_XBARB2(XBAR_INPUT, 84)    /* EDMA_DONE2 output assigned to XBARB2_IN84 input. */
#define IMXRT_XBARB2_IN_EDMA_DONE3                           IMXRT_XBARB2(XBAR_INPUT, 85)    /* EDMA_DONE3 output assigned to XBARB2_IN85 input. */
#define IMXRT_XBARB2_IN_EDMA_DONE4                           IMXRT_XBARB2(XBAR_INPUT, 86)    /* EDMA_DONE4 output assigned to XBARB2_IN86 input. */
#define IMXRT_XBARB2_IN_EDMA_DONE5                           IMXRT_XBARB2(XBAR_INPUT, 87)    /* EDMA_DONE5 output assigned to XBARB2_IN87 input. */
#define IMXRT_XBARB2_IN_EDMA_DONE6                           IMXRT_XBARB2(XBAR_INPUT, 88)    /* EDMA_DONE6 output assigned to XBARB2_IN88 input. */
#define IMXRT_XBARB2_IN_EDMA_DONE7                           IMXRT_XBARB2(XBAR_INPUT, 89)    /* EDMA_DONE7 output assigned to XBARB2_IN89 input. */
#define IMXRT_XBARB2_IN_EDMA_LPSR_DONE0                      IMXRT_XBARB2(XBAR_INPUT, 90)    /* EDMA_LPSR_DONE0 output assigned to XBARB2_IN90 input. */
#define IMXRT_XBARB2_IN_EDMA_LPSR_DONE1                      IMXRT_XBARB2(XBAR_INPUT, 91)    /* EDMA_LPSR_DONE1 output assigned to XBARB2_IN91 input. */
#define IMXRT_XBARB2_IN_EDMA_LPSR_DONE2                      IMXRT_XBARB2(XBAR_INPUT, 92)    /* EDMA_LPSR_DONE2 output assigned to XBARB2_IN92 input. */
#define IMXRT_XBARB2_IN_EDMA_LPSR_DONE3                      IMXRT_XBARB2(XBAR_INPUT, 93)    /* EDMA_LPSR_DONE3 output assigned to XBARB2_IN93 input. */
#define IMXRT_XBARB2_IN_EDMA_LPSR_DONE4                      IMXRT_XBARB2(XBAR_INPUT, 94)    /* EDMA_LPSR_DONE4 output assigned to XBARB2_IN94 input. */
#define IMXRT_XBARB2_IN_EDMA_LPSR_DONE5                      IMXRT_XBARB2(XBAR_INPUT, 95)    /* EDMA_LPSR_DONE5 output assigned to XBARB2_IN95 input. */
#define IMXRT_XBARB2_IN_EDMA_LPSR_DONE6                      IMXRT_XBARB2(XBAR_INPUT, 96)    /* EDMA_LPSR_DONE6 output assigned to XBARB2_IN96 input. */
#define IMXRT_XBARB2_IN_EDMA_LPSR_DONE7                      IMXRT_XBARB2(XBAR_INPUT, 97)    /* EDMA_LPSR_DONE7 output assigned to XBARB2_IN97 input. */
#define IMXRT_XBARB2_IN_GND98                                IMXRT_XBARB2(XBAR_INPUT, 98)    /* GND assigned to XBARB2_IN98 input. */
#define IMXRT_XBARB2_IN_GND99                                IMXRT_XBARB2(XBAR_INPUT, 99)    /* GND assigned to XBARB2_IN99 input. */

/* XBARB2 Mux Output (M Muxes) **********************************************/

#define IMXRT_XBARB2_OUT_AOI1_IN00_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 0)    /* XBARB2_OUT0 output assigned to AOI1_IN00 */
#define IMXRT_XBARB2_OUT_AOI1_IN01_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 1)    /* XBARB2_OUT1 output assigned to AOI1_IN01 */
#define IMXRT_XBARB2_OUT_AOI1_IN02_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 2)    /* XBARB2_OUT2 output assigned to AOI1_IN02 */
#define IMXRT_XBARB2_OUT_AOI1_IN03_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 3)    /* XBARB2_OUT3 output assigned to AOI1_IN03 */
#define IMXRT_XBARB2_OUT_AOI1_IN04_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 4)    /* XBARB2_OUT4 output assigned to AOI1_IN04 */
#define IMXRT_XBARB2_OUT_AOI1_IN05_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 5)    /* XBARB2_OUT5 output assigned to AOI1_IN05 */
#define IMXRT_XBARB2_OUT_AOI1_IN06_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 6)    /* XBARB2_OUT6 output assigned to AOI1_IN06 */
#define IMXRT_XBARB2_OUT_AOI1_IN07_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 7)    /* XBARB2_OUT7 output assigned to AOI1_IN07 */
#define IMXRT_XBARB2_OUT_AOI1_IN08_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 8)    /* XBARB2_OUT8 output assigned to AOI1_IN08 */
#define IMXRT_XBARB2_OUT_AOI1_IN09_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 9)    /* XBARB2_OUT9 output assigned to AOI1_IN09 */
#define IMXRT_XBARB2_OUT_AOI1_IN10_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 10)   /* XBARB2_OUT10 output assigned to AOI1_IN10 */
#define IMXRT_XBARB2_OUT_AOI1_IN11_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 11)   /* XBARB2_OUT11 output assigned to AOI1_IN11 */
#define IMXRT_XBARB2_OUT_AOI1_IN12_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 12)   /* XBARB2_OUT12 output assigned to AOI1_IN12 */
#define IMXRT_XBARB2_OUT_AOI1_IN13_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 13)   /* XBARB2_OUT13 output assigned to AOI1_IN13 */
#define IMXRT_XBARB2_OUT_AOI1_IN14_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 14)   /* XBARB2_OUT14 output assigned to AOI1_IN14 */
#define IMXRT_XBARB2_OUT_AOI1_IN15_SEL_OFFSET                IMXRT_XBARB2(XBAR_OUTPUT, 15)   /* XBARB2_OUT15 output assigned to AOI1_IN15 */

/* XBARB3 Mux Inputs (I Values) *********************************************/

#define IMXRT_XBARB3_IN_LOGIC_LOW                            IMXRT_XBARB3(XBAR_INPUT, 0)     /* LOGIC_LOW output assigned to XBARB3_IN0 input. */
#define IMXRT_XBARB3_IN_LOGIC_HIGH                           IMXRT_XBARB3(XBAR_INPUT, 1)     /* LOGIC_HIGH output assigned to XBARB3_IN1 input. */
#define IMXRT_XBARB3_IN_ACMP1_OUT                            IMXRT_XBARB3(XBAR_INPUT, 2)     /* ACMP1_OUT output assigned to XBARB3_IN2 input. */
#define IMXRT_XBARB3_IN_ACMP2_OUT                            IMXRT_XBARB3(XBAR_INPUT, 3)     /* ACMP2_OUT output assigned to XBARB3_IN3 input. */
#define IMXRT_XBARB3_IN_ACMP3_OUT                            IMXRT_XBARB3(XBAR_INPUT, 4)     /* ACMP3_OUT output assigned to XBARB3_IN4 input. */
#define IMXRT_XBARB3_IN_ACMP4_OUT                            IMXRT_XBARB3(XBAR_INPUT, 5)     /* ACMP4_OUT output assigned to XBARB3_IN5 input. */
#define IMXRT_XBARB3_IN_GND6                                 IMXRT_XBARB3(XBAR_INPUT, 6)     /* GND assigned to XBARB3_IN6 input. */
#define IMXRT_XBARB3_IN_GND7                                 IMXRT_XBARB3(XBAR_INPUT, 7)     /* GND assigned to XBARB3_IN7 input. */
#define IMXRT_XBARB3_IN_GND8                                 IMXRT_XBARB3(XBAR_INPUT, 8)     /* GND assigned to XBARB3_IN8 input. */
#define IMXRT_XBARB3_IN_GND9                                 IMXRT_XBARB3(XBAR_INPUT, 9)     /* GND assigned to XBARB3_IN9 input. */
#define IMXRT_XBARB3_IN_QTIMER1_TMR0_OUT                     IMXRT_XBARB3(XBAR_INPUT, 10)    /* QTIMER1_TMR0_OUTPUT output assigned to XBARB3_IN10 input. */
#define IMXRT_XBARB3_IN_QTIMER1_TMR1_OUT                     IMXRT_XBARB3(XBAR_INPUT, 11)    /* QTIMER1_TMR1_OUTPUT output assigned to XBARB3_IN11 input. */
#define IMXRT_XBARB3_IN_QTIMER1_TMR2_OUT                     IMXRT_XBARB3(XBAR_INPUT, 12)    /* QTIMER1_TMR2_OUTPUT output assigned to XBARB3_IN12 input. */
#define IMXRT_XBARB3_IN_QTIMER1_TMR3_OUT                     IMXRT_XBARB3(XBAR_INPUT, 13)    /* QTIMER1_TMR3_OUTPUT output assigned to XBARB3_IN13 input. */
#define IMXRT_XBARB3_IN_QTIMER2_TMR0_OUT                     IMXRT_XBARB3(XBAR_INPUT, 14)    /* QTIMER2_TMR0_OUTPUT output assigned to XBARB3_IN14 input. */
#define IMXRT_XBARB3_IN_QTIMER2_TMR1_OUT                     IMXRT_XBARB3(XBAR_INPUT, 15)    /* QTIMER2_TMR1_OUTPUT output assigned to XBARB3_IN15 input. */
#define IMXRT_XBARB3_IN_QTIMER2_TMR2_OUT                     IMXRT_XBARB3(XBAR_INPUT, 16)    /* QTIMER2_TMR2_OUTPUT output assigned to XBARB3_IN16 input. */
#define IMXRT_XBARB3_IN_QTIMER2_TMR3_OUT                     IMXRT_XBARB3(XBAR_INPUT, 17)    /* QTIMER2_TMR3_OUTPUT output assigned to XBARB3_IN17 input. */
#define IMXRT_XBARB3_IN_QTIMER3_TMR0_OUT                     IMXRT_XBARB3(XBAR_INPUT, 18)    /* QTIMER3_TMR0_OUTPUT output assigned to XBARB3_IN18 input. */
#define IMXRT_XBARB3_IN_QTIMER3_TMR1_OUT                     IMXRT_XBARB3(XBAR_INPUT, 19)    /* QTIMER3_TMR1_OUTPUT output assigned to XBARB3_IN19 input. */
#define IMXRT_XBARB3_IN_QTIMER3_TMR2_OUT                     IMXRT_XBARB3(XBAR_INPUT, 20)    /* QTIMER3_TMR2_OUTPUT output assigned to XBARB3_IN20 input. */
#define IMXRT_XBARB3_IN_QTIMER3_TMR3_OUT                     IMXRT_XBARB3(XBAR_INPUT, 21)    /* QTIMER3_TMR3_OUTPUT output assigned to XBARB3_IN21 input. */
#define IMXRT_XBARB3_IN_QTIMER4_TMR0_OUT                     IMXRT_XBARB3(XBAR_INPUT, 22)    /* QTIMER4_TMR0_OUTPUT output assigned to XBARB3_IN22 input. */
#define IMXRT_XBARB3_IN_QTIMER4_TMR1_OUT                     IMXRT_XBARB3(XBAR_INPUT, 23)    /* QTIMER4_TMR1_OUTPUT output assigned to XBARB3_IN23 input. */
#define IMXRT_XBARB3_IN_QTIMER4_TMR2_OUT                     IMXRT_XBARB3(XBAR_INPUT, 24)    /* QTIMER4_TMR2_OUTPUT output assigned to XBARB3_IN24 input. */
#define IMXRT_XBARB3_IN_QTIMER4_TMR3_OUT                     IMXRT_XBARB3(XBAR_INPUT, 25)    /* QTIMER4_TMR3_OUTPUT output assigned to XBARB3_IN25 input. */
#define IMXRT_XBARB3_IN_GND26                                IMXRT_XBARB3(XBAR_INPUT, 26)    /* GND assigned to XBARB3_IN26 input. */
#define IMXRT_XBARB3_IN_GND27                                IMXRT_XBARB3(XBAR_INPUT, 27)    /* GND assigned to XBARB3_IN27 input. */
#define IMXRT_XBARB3_IN_GND28                                IMXRT_XBARB3(XBAR_INPUT, 28)    /* GND assigned to XBARB3_IN28 input. */
#define IMXRT_XBARB3_IN_GND29                                IMXRT_XBARB3(XBAR_INPUT, 29)    /* GND assigned to XBARB3_IN29 input. */
#define IMXRT_XBARB3_IN_GND30                                IMXRT_XBARB3(XBAR_INPUT, 30)    /* GND assigned to XBARB3_IN30 input. */
#define IMXRT_XBARB3_IN_GND31                                IMXRT_XBARB3(XBAR_INPUT, 31)    /* GND assigned to XBARB3_IN31 input. */
#define IMXRT_XBARB3_IN_GND32                                IMXRT_XBARB3(XBAR_INPUT, 32)    /* GND assigned to XBARB3_IN32 input. */
#define IMXRT_XBARB3_IN_GND33                                IMXRT_XBARB3(XBAR_INPUT, 33)    /* GND assigned to XBARB3_IN33 input. */
#define IMXRT_XBARB3_IN_FLEXPWM1_PWM0_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 34)    /* FLEXPWM1_PWM0_OUT_TRIG0_1 output assigned to XBARB3_IN34 input. */
#define IMXRT_XBARB3_IN_FLEXPWM1_PWM1_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 35)    /* FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARB3_IN35 input. */
#define IMXRT_XBARB3_IN_FLEXPWM1_PWM2_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 36)    /* FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARB3_IN36 input. */
#define IMXRT_XBARB3_IN_FLEXPWM1_PWM3_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 37)    /* FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARB3_IN37 input. */
#define IMXRT_XBARB3_IN_FLEXPWM2_PWM0_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 38)    /* FLEXPWM2_PWM0_OUT_TRIG0_1 output assigned to XBARB3_IN38 input. */
#define IMXRT_XBARB3_IN_FLEXPWM2_PWM1_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 39)    /* FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBARB3_IN39 input. */
#define IMXRT_XBARB3_IN_FLEXPWM2_PWM2_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 40)    /* FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBARB3_IN40 input. */
#define IMXRT_XBARB3_IN_FLEXPWM2_PWM3_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 41)    /* FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBARB3_IN41 input. */
#define IMXRT_XBARB3_IN_FLEXPWM3_PWM0_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 42)    /* FLEXPWM3_PWM0_OUT_TRIG0_1 output assigned to XBARB3_IN42 input. */
#define IMXRT_XBARB3_IN_FLEXPWM3_PWM1_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 43)    /* FLEXPWM3_PWM1_OUT_TRIG0_1 output assigned to XBARB3_IN43 input. */
#define IMXRT_XBARB3_IN_FLEXPWM3_PWM2_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 44)    /* FLEXPWM3_PWM2_OUT_TRIG0_1 output assigned to XBARB3_IN44 input. */
#define IMXRT_XBARB3_IN_FLEXPWM3_PWM3_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 45)    /* FLEXPWM3_PWM3_OUT_TRIG0_1 output assigned to XBARB3_IN45 input. */
#define IMXRT_XBARB3_IN_FLEXPWM4_PWM0_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 46)    /* FLEXPWM4_PWM0_OUT_TRIG0_1 output assigned to XBARB3_IN46 input. */
#define IMXRT_XBARB3_IN_FLEXPWM4_PWM1_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 47)    /* FLEXPWM4_PWM1_OUT_TRIG0_1 output assigned to XBARB3_IN47 input. */
#define IMXRT_XBARB3_IN_FLEXPWM4_PWM2_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 48)    /* FLEXPWM4_PWM2_OUT_TRIG0_1 output assigned to XBARB3_IN48 input. */
#define IMXRT_XBARB3_IN_FLEXPWM4_PWM3_OUT_TRIG01             IMXRT_XBARB3(XBAR_INPUT, 49)    /* FLEXPWM4_PWM3_OUT_TRIG0_1 output assigned to XBARB3_IN49 input. */
#define IMXRT_XBARB3_IN_GND50                                IMXRT_XBARB3(XBAR_INPUT, 50)    /* GND assigned to XBARB3_IN50 input. */
#define IMXRT_XBARB3_IN_GND51                                IMXRT_XBARB3(XBAR_INPUT, 51)    /* GND assigned to XBARB3_IN51 input. */
#define IMXRT_XBARB3_IN_GND52                                IMXRT_XBARB3(XBAR_INPUT, 52)    /* GND assigned to XBARB3_IN52 input. */
#define IMXRT_XBARB3_IN_GND53                                IMXRT_XBARB3(XBAR_INPUT, 53)    /* GND assigned to XBARB3_IN53 input. */
#define IMXRT_XBARB3_IN_GND54                                IMXRT_XBARB3(XBAR_INPUT, 54)    /* GND assigned to XBARB3_IN54 input. */
#define IMXRT_XBARB3_IN_GND55                                IMXRT_XBARB3(XBAR_INPUT, 55)    /* GND assigned to XBARB3_IN55 input. */
#define IMXRT_XBARB3_IN_GND56                                IMXRT_XBARB3(XBAR_INPUT, 56)    /* GND assigned to XBARB3_IN56 input. */
#define IMXRT_XBARB3_IN_GND57                                IMXRT_XBARB3(XBAR_INPUT, 57)    /* GND assigned to XBARB3_IN57 input. */
#define IMXRT_XBARB3_IN_PIT1_TRIGGER0                        IMXRT_XBARB3(XBAR_INPUT, 58)    /* PIT1_TRIGGER0 output assigned to XBARB3_IN58 input. */
#define IMXRT_XBARB3_IN_PIT1_TRIGGER1                        IMXRT_XBARB3(XBAR_INPUT, 59)    /* PIT1_TRIGGER1 output assigned to XBARB3_IN59 input. */
#define IMXRT_XBARB3_IN_ADC_ETC0_COCO0                       IMXRT_XBARB3(XBAR_INPUT, 60)    /* ADC_ETC0_COCO0 output assigned to XBARB3_IN60 input. */
#define IMXRT_XBARB3_IN_ADC_ETC0_COCO1                       IMXRT_XBARB3(XBAR_INPUT, 61)    /* ADC_ETC0_COCO1 output assigned to XBARB3_IN61 input. */
#define IMXRT_XBARB3_IN_ADC_ETC0_COCO2                       IMXRT_XBARB3(XBAR_INPUT, 62)    /* ADC_ETC0_COCO2 output assigned to XBARB3_IN62 input. */
#define IMXRT_XBARB3_IN_ADC_ETC0_COCO3                       IMXRT_XBARB3(XBAR_INPUT, 63)    /* ADC_ETC0_COCO3 output assigned to XBARB3_IN63 input. */
#define IMXRT_XBARB3_IN_ADC_ETC1_COCO0                       IMXRT_XBARB3(XBAR_INPUT, 64)    /* ADC_ETC1_COCO0 output assigned to XBARB3_IN64 input. */
#define IMXRT_XBARB3_IN_ADC_ETC1_COCO1                       IMXRT_XBARB3(XBAR_INPUT, 65)    /* ADC_ETC1_COCO1 output assigned to XBARB3_IN65 input. */
#define IMXRT_XBARB3_IN_ADC_ETC1_COCO2                       IMXRT_XBARB3(XBAR_INPUT, 66)    /* ADC_ETC1_COCO2 output assigned to XBARB3_IN66 input. */
#define IMXRT_XBARB3_IN_ADC_ETC1_COCO3                       IMXRT_XBARB3(XBAR_INPUT, 67)    /* ADC_ETC1_COCO3 output assigned to XBARB3_IN67 input. */
#define IMXRT_XBARB3_IN_GND68                                IMXRT_XBARB3(XBAR_INPUT, 68)    /* GND assigned to XBARB3_IN68 input. */
#define IMXRT_XBARB3_IN_GND69                                IMXRT_XBARB3(XBAR_INPUT, 69)    /* GND assigned to XBARB3_IN69 input. */
#define IMXRT_XBARB3_IN_GND70                                IMXRT_XBARB3(XBAR_INPUT, 70)    /* GND assigned to XBARB3_IN70 input. */
#define IMXRT_XBARB3_IN_GND71                                IMXRT_XBARB3(XBAR_INPUT, 71)    /* GND assigned to XBARB3_IN71 input. */
#define IMXRT_XBARB3_IN_GND72                                IMXRT_XBARB3(XBAR_INPUT, 72)    /* GND assigned to XBARB3_IN72 input. */
#define IMXRT_XBARB3_IN_GND73                                IMXRT_XBARB3(XBAR_INPUT, 73)    /* GND assigned to XBARB3_IN73 input. */
#define IMXRT_XBARB3_IN_GND74                                IMXRT_XBARB3(XBAR_INPUT, 74)    /* GND assigned to XBARB3_IN74 input. */
#define IMXRT_XBARB3_IN_GND75                                IMXRT_XBARB3(XBAR_INPUT, 75)    /* GND assigned to XBARB3_IN75 input. */
#define IMXRT_XBARB3_IN_QDC1_POSMATCH                        IMXRT_XBARB3(XBAR_INPUT, 76)    /* QDC1_POSMATCH output assigned to XBARB3_IN76 input. */
#define IMXRT_XBARB3_IN_QDC2_POSMATCH                        IMXRT_XBARB3(XBAR_INPUT, 77)    /* QDC2_POSMATCH output assigned to XBARB3_IN77 input. */
#define IMXRT_XBARB3_IN_QDC3_POSMATCH                        IMXRT_XBARB3(XBAR_INPUT, 78)    /* QDC3_POSMATCH output assigned to XBARB3_IN78 input. */
#define IMXRT_XBARB3_IN_QDC4_POSMATCH                        IMXRT_XBARB3(XBAR_INPUT, 79)    /* QDC4_POSMATCH output assigned to XBARB3_IN79 input. */
#define IMXRT_XBARB3_IN_GND80                                IMXRT_XBARB3(XBAR_INPUT, 80)    /* GND assigned to XBARB3_IN80 input. */
#define IMXRT_XBARB3_IN_GND81                                IMXRT_XBARB3(XBAR_INPUT, 81)    /* GND assigned to XBARB3_IN81 input. */
#define IMXRT_XBARB3_IN_EDMA_DONE0                           IMXRT_XBARB3(XBAR_INPUT, 82)    /* EDMA_DONE0 output assigned to XBARB3_IN82 input. */
#define IMXRT_XBARB3_IN_EDMA_DONE1                           IMXRT_XBARB3(XBAR_INPUT, 83)    /* EDMA_DONE1 output assigned to XBARB3_IN83 input. */
#define IMXRT_XBARB3_IN_EDMA_DONE2                           IMXRT_XBARB3(XBAR_INPUT, 84)    /* EDMA_DONE2 output assigned to XBARB3_IN84 input. */
#define IMXRT_XBARB3_IN_EDMA_DONE3                           IMXRT_XBARB3(XBAR_INPUT, 85)    /* EDMA_DONE3 output assigned to XBARB3_IN85 input. */
#define IMXRT_XBARB3_IN_EDMA_DONE4                           IMXRT_XBARB3(XBAR_INPUT, 86)    /* EDMA_DONE4 output assigned to XBARB3_IN86 input. */
#define IMXRT_XBARB3_IN_EDMA_DONE5                           IMXRT_XBARB3(XBAR_INPUT, 87)    /* EDMA_DONE5 output assigned to XBARB3_IN87 input. */
#define IMXRT_XBARB3_IN_EDMA_DONE6                           IMXRT_XBARB3(XBAR_INPUT, 88)    /* EDMA_DONE6 output assigned to XBARB3_IN88 input. */
#define IMXRT_XBARB3_IN_EDMA_DONE7                           IMXRT_XBARB3(XBAR_INPUT, 89)    /* EDMA_DONE7 output assigned to XBARB3_IN89 input. */
#define IMXRT_XBARB3_IN_EDMA_LPSR_DONE0                      IMXRT_XBARB3(XBAR_INPUT, 90)    /* EDMA_LPSR_DONE0 output assigned to XBARB3_IN90 input. */
#define IMXRT_XBARB3_IN_EDMA_LPSR_DONE1                      IMXRT_XBARB3(XBAR_INPUT, 91)    /* EDMA_LPSR_DONE1 output assigned to XBARB3_IN91 input. */
#define IMXRT_XBARB3_IN_EDMA_LPSR_DONE2                      IMXRT_XBARB3(XBAR_INPUT, 92)    /* EDMA_LPSR_DONE2 output assigned to XBARB3_IN92 input. */
#define IMXRT_XBARB3_IN_EDMA_LPSR_DONE3                      IMXRT_XBARB3(XBAR_INPUT, 93)    /* EDMA_LPSR_DONE3 output assigned to XBARB3_IN93 input. */
#define IMXRT_XBARB3_IN_EDMA_LPSR_DONE4                      IMXRT_XBARB3(XBAR_INPUT, 94)    /* EDMA_LPSR_DONE4 output assigned to XBARB3_IN94 input. */
#define IMXRT_XBARB3_IN_EDMA_LPSR_DONE5                      IMXRT_XBARB3(XBAR_INPUT, 95)    /* EDMA_LPSR_DONE5 output assigned to XBARB3_IN95 input. */
#define IMXRT_XBARB3_IN_EDMA_LPSR_DONE6                      IMXRT_XBARB3(XBAR_INPUT, 96)    /* EDMA_LPSR_DONE6 output assigned to XBARB3_IN96 input. */
#define IMXRT_XBARB3_IN_EDMA_LPSR_DONE7                      IMXRT_XBARB3(XBAR_INPUT, 97)    /* EDMA_LPSR_DONE7 output assigned to XBARB3_IN97 input. */
#define IMXRT_XBARB3_IN_GND98                                IMXRT_XBARB3(XBAR_INPUT, 98)    /* GND assigned to XBARB3_IN98 input. */
#define IMXRT_XBARB3_IN_GND99                                IMXRT_XBARB3(XBAR_INPUT, 99)    /* GND assigned to XBARB3_IN99 input. */

/* XBARB3 Mux Output (M Muxes) **********************************************/

#define IMXRT_XBARB3_OUT_AOI2_IN00_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 0)    /* XBARB3_OUT0 output assigned to AOI2_IN00 */
#define IMXRT_XBARB3_OUT_AOI2_IN01_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 1)    /* XBARB3_OUT1 output assigned to AOI2_IN01 */
#define IMXRT_XBARB3_OUT_AOI2_IN02_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 2)    /* XBARB3_OUT2 output assigned to AOI2_IN02 */
#define IMXRT_XBARB3_OUT_AOI2_IN03_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 3)    /* XBARB3_OUT3 output assigned to AOI2_IN03 */
#define IMXRT_XBARB3_OUT_AOI2_IN04_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 4)    /* XBARB3_OUT4 output assigned to AOI2_IN04 */
#define IMXRT_XBARB3_OUT_AOI2_IN05_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 5)    /* XBARB3_OUT5 output assigned to AOI2_IN05 */
#define IMXRT_XBARB3_OUT_AOI2_IN06_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 6)    /* XBARB3_OUT6 output assigned to AOI2_IN06 */
#define IMXRT_XBARB3_OUT_AOI2_IN07_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 7)    /* XBARB3_OUT7 output assigned to AOI2_IN07 */
#define IMXRT_XBARB3_OUT_AOI2_IN08_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 8)    /* XBARB3_OUT8 output assigned to AOI2_IN08 */
#define IMXRT_XBARB3_OUT_AOI2_IN09_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 9)    /* XBARB3_OUT9 output assigned to AOI2_IN09 */
#define IMXRT_XBARB3_OUT_AOI2_IN10_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 10)   /* XBARB3_OUT10 output assigned to AOI2_IN10 */
#define IMXRT_XBARB3_OUT_AOI2_IN11_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 11)   /* XBARB3_OUT11 output assigned to AOI2_IN11 */
#define IMXRT_XBARB3_OUT_AOI2_IN12_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 12)   /* XBARB3_OUT12 output assigned to AOI2_IN12 */
#define IMXRT_XBARB3_OUT_AOI2_IN13_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 13)   /* XBARB3_OUT13 output assigned to AOI2_IN13 */
#define IMXRT_XBARB3_OUT_AOI2_IN14_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 14)   /* XBARB3_OUT14 output assigned to AOI2_IN14 */
#define IMXRT_XBARB3_OUT_AOI2_IN15_SEL_OFFSET                IMXRT_XBARB3(XBAR_OUTPUT, 15)   /* XBARB3_OUT15 output assigned to AOI2_IN15 */

#endif /* __ARCH_ARM_SRC_IMXRT_HARDWARE_RT117X_IMXRT117X_XBAR_H */
