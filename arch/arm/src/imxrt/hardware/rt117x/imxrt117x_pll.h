/*********************************************************************************
 * arch/arm/src/imxrt/hardware/rt117x/imxrt117x_pll.h
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
 *********************************************************************************/

/* Copyright 2022 NXP */

#ifndef __ARCH_ARM_SRC_IMXRT_HARDWARE_RT117X_IMXRT117X_PLL_H
#define __ARCH_ARM_SRC_IMXRT_HARDWARE_RT117X_IMXRT117X_PLL_H

/*********************************************************************************
 * Included Files
 *********************************************************************************/

#include <nuttx/config.h>
#include "hardware/imxrt_memorymap.h"

/*********************************************************************************
 * Pre-processor Definitions
 *********************************************************************************/

/* ANADIG_PLL Register Offsets ***************************************************/
#define IMXRT_ANADIG_PLL_ARM_PLL_CTRL_OFFSET           (0x0200)
#define IMXRT_ANADIG_PLL_SYS_PLL3_CTRL_OFFSET          (0x0210)
#define IMXRT_ANADIG_PLL_SYS_PLL3_UPDATE_OFFSET        (0x0220)
#define IMXRT_ANADIG_PLL_SYS_PLL3_PFD_OFFSET           (0x0230)
#define IMXRT_ANADIG_PLL_SYS_PLL2_CTRL_OFFSET          (0x0240)
#define IMXRT_ANADIG_PLL_SYS_PLL2_UPDATE_OFFSET        (0x0250)
#define IMXRT_ANADIG_PLL_SYS_PLL2_SS_OFFSET            (0x0260)
#define IMXRT_ANADIG_PLL_SYS_PLL2_PFD_OFFSET           (0x0270)
#define IMXRT_ANADIG_PLL_SYS_PLL2_MFD_OFFSET           (0x02a0)
#define IMXRT_ANADIG_PLL_SYS_PLL1_SS_OFFSET            (0x02b0)
#define IMXRT_ANADIG_PLL_SYS_PLL1_CTRL_OFFSET          (0x02c0)
#define IMXRT_ANADIG_PLL_SYS_PLL1_DENOMINATOR_OFFSET   (0x02d0)
#define IMXRT_ANADIG_PLL_SYS_PLL1_NUMERATOR_OFFSET     (0x02e0)
#define IMXRT_ANADIG_PLL_SYS_PLL1_DIV_SELECT_OFFSET    (0x02f0)
#define IMXRT_ANADIG_PLL_PLL_AUDIO_CTRL_OFFSET         (0x0300)
#define IMXRT_ANADIG_PLL_PLL_AUDIO_SS_OFFSET           (0x0310)
#define IMXRT_ANADIG_PLL_PLL_AUDIO_DENOMINATOR_OFFSET  (0x0320)
#define IMXRT_ANADIG_PLL_PLL_AUDIO_NUMERATOR_OFFSET    (0x0330)
#define IMXRT_ANADIG_PLL_PLL_AUDIO_DIV_SELECT_OFFSET   (0x0340)
#define IMXRT_ANADIG_PLL_PLL_VIDEO_CTRL_OFFSET         (0x0350)
#define IMXRT_ANADIG_PLL_PLL_VIDEO_SS_OFFSET           (0x0360)
#define IMXRT_ANADIG_PLL_PLL_VIDEO_DENOMINATOR_OFFSET  (0x0370)
#define IMXRT_ANADIG_PLL_PLL_VIDEO_NUMERATOR_OFFSET    (0x0380)
#define IMXRT_ANADIG_PLL_PLL_VIDEO_DIV_SELECT_OFFSET   (0x0390)

/* ANADIG_PLL Register Addresses *************************************************/
#define IMXRT_ANADIG_PLL_ARM_PLL_CTRL           (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_ARM_PLL_CTRL_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL3_CTRL          (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL3_CTRL_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL3_UPDATE        (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL3_UPDATE_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL3_PFD           (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL3_PFD_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL2_CTRL          (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL2_CTRL_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL2_UPDATE        (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL2_UPDATE_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL2_SS            (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL2_SS_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL2_PFD           (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL2_PFD_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL2_MFD           (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL2_MFD_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL1_SS            (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL1_SS_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL1_CTRL          (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL1_CTRL_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL1_DENOMINATOR   (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL1_DENOMINATOR_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL1_NUMERATOR     (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL1_NUMERATOR_OFFSET)
#define IMXRT_ANADIG_PLL_SYS_PLL1_DIV_SELECT    (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_SYS_PLL1_DIV_SELECT_OFFSET)
#define IMXRT_ANADIG_PLL_PLL_AUDIO_CTRL         (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_PLL_AUDIO_CTRL_OFFSET)
#define IMXRT_ANADIG_PLL_PLL_AUDIO_SS           (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_PLL_AUDIO_SS_OFFSET)
#define IMXRT_ANADIG_PLL_PLL_AUDIO_DENOMINATOR  (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_PLL_AUDIO_DENOMINATOR_OFFSET)
#define IMXRT_ANADIG_PLL_PLL_AUDIO_NUMERATOR    (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_PLL_AUDIO_NUMERATOR_OFFSET)
#define IMXRT_ANADIG_PLL_PLL_AUDIO_DIV_SELECT   (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_PLL_AUDIO_DIV_SELECT_OFFSET)
#define IMXRT_ANADIG_PLL_PLL_VIDEO_CTRL         (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_PLL_VIDEO_CTRL_OFFSET)
#define IMXRT_ANADIG_PLL_PLL_VIDEO_SS           (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_PLL_VIDEO_SS_OFFSET)
#define IMXRT_ANADIG_PLL_PLL_VIDEO_DENOMINATOR  (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_PLL_VIDEO_DENOMINATOR_OFFSET)
#define IMXRT_ANADIG_PLL_PLL_VIDEO_NUMERATOR    (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_PLL_VIDEO_NUMERATOR_OFFSET)
#define IMXRT_ANADIG_PLL_PLL_VIDEO_DIV_SELECT   (IMXRT_ANADIG_BASE + IMXRT_ANADIG_PLL_PLL_VIDEO_DIV_SELECT_OFFSET)

/* ARM_PLL_CTRL_REGISTER (ARM_PLL_CTRL) */
#define ANADIG_PLL_ARM_PLL_CTRL_DIV_SELECT_SHIFT      (0)        /* Bits 0-8: DIV_SELECT */
#define ANADIG_PLL_ARM_PLL_CTRL_DIV_SELECT_MASK       (0xFF << ANADIG_PLL_ARM_PLL_CTRL_DIV_SELECT_SHIFT)
#define ANADIG_PLL_ARM_PLL_CTRL_DIV_SELECT(n)         (((n) << ANADIG_PLL_ARM_PLL_CTRL_DIV_SELECT_SHIFT) & ANADIG_PLL_ARM_PLL_CTRL_DIV_SELECT_MASK)
#define ANADIG_PLL_ARM_PLL_CTRL_HOLD_RING_OFF         (1 << 12)  /* Bit 12: PLL Start up initialization */
#define ANADIG_PLL_ARM_PLL_CTRL_POWERUP               (1 << 13)  /* Bit 13: Powers up the PLL. */
#define ANADIG_PLL_ARM_PLL_CTRL_ENABLE_CLK            (1 << 14)  /* Bit 14: Enable the clock output. */
#define ANADIG_PLL_ARM_PLL_CTRL_POST_DIV_SEL_SHIFT    (15)       /* Bits 15-17: POST_DIV_SEL */
#define ANADIG_PLL_ARM_PLL_CTRL_POST_DIV_SEL_MASK     (0x3 << ANADIG_PLL_ARM_PLL_CTRL_POST_DIV_SEL_SHIFT)
#define ANADIG_PLL_ARM_PLL_CTRL_POST_DIV_SEL(n)       (((n) << ANADIG_PLL_ARM_PLL_CTRL_POST_DIV_SEL_SHIFT) & ANADIG_PLL_ARM_PLL_CTRL_POST_DIV_SEL_MASK)
#define ANADIG_PLL_ARM_PLL_CTRL_BYPASS                (1 << 17)  /* Bit 17: Bypass the pll. */
#define ANADIG_PLL_ARM_PLL_CTRL_ARM_PLL_STABLE        (1 << 29)  /* Bit 29: ARM_PLL_STABLE */
#define ANADIG_PLL_ARM_PLL_CTRL_ARM_PLL_GATE          (1 << 30)  /* Bit 30: ARM_PLL_GATE */
#define ANADIG_PLL_ARM_PLL_CTRL_ARM_PLL_CONTROL_MODE  (1 << 31)  /* Bit 31: pll_arm_control_mode */

/* SYS_PLL3_CTRL_REGISTER (SYS_PLL3_CTRL) */
#define ANADIG_PLL_SYS_PLL3_CTRL_SYS_PLL3_DIV2               (1 << 3)   /* Bit 3: SYS PLL3 DIV2 gate */
#define ANADIG_PLL_SYS_PLL3_CTRL_PLL_REG_EN                  (1 << 4)   /* Bit 4: Enable Internal PLL Regulator */
#define ANADIG_PLL_SYS_PLL3_CTRL_HOLD_RING_OFF               (1 << 11)  /* Bit 11: PLL Start up initialization */
#define ANADIG_PLL_SYS_PLL3_CTRL_ENABLE_CLK                  (1 << 13)  /* Bit 13: Enable the clock output. */
#define ANADIG_PLL_SYS_PLL3_CTRL_BYPASS                      (1 << 16)  /* Bit 16: BYPASS */
#define ANADIG_PLL_SYS_PLL3_CTRL_POWERUP                     (1 << 21)  /* Bit 21: Powers up the PLL. */
#define ANADIG_PLL_SYS_PLL3_CTRL_SYS_PLL3_DIV2_CONTROL_MODE  (1 << 28)  /* Bit 28: SYS_PLL3_DIV2_CONTROL_MODE */
#define ANADIG_PLL_SYS_PLL3_CTRL_SYS_PLL3_STABLE             (1 << 29)  /* Bit 29: SYS_PLL3_STABLE */
#define ANADIG_PLL_SYS_PLL3_CTRL_SYS_PLL3_GATE               (1 << 30)  /* Bit 30: SYS_PLL3_GATE */
#define ANADIG_PLL_SYS_PLL3_CTRL_SYS_PLL3_CONTROL_MODE       (1 << 31)  /* Bit 31: SYS_PLL3_control_mode */

/* SYS_PLL3_UPDATE_REGISTER (SYS_PLL3_UPDATE) */
#define ANADIG_PLL_SYS_PLL3_UPDATE_PFD0_UPDATE        (1 << 1)  /* Bit 1: PFD0_OVERRIDE */
#define ANADIG_PLL_SYS_PLL3_UPDATE_PFD1_UPDATE        (1 << 2)  /* Bit 2: PFD1_OVERRIDE */
#define ANADIG_PLL_SYS_PLL3_UPDATE_PFD2_UPDATE        (1 << 3)  /* Bit 3: PFD2_OVERRIDE */
#define ANADIG_PLL_SYS_PLL3_UPDATE_PFD3_UPDATE        (1 << 4)  /* Bit 4: PFD3_UPDATE */
#define ANADIG_PLL_SYS_PLL3_UPDATE_PFD0_CONTROL_MODE  (1 << 5)  /* Bit 5: pfd0_control_mode */
#define ANADIG_PLL_SYS_PLL3_UPDATE_PFD1_CONTROL_MODE  (1 << 6)  /* Bit 6: pfd1_control_mode */
#define ANADIG_PLL_SYS_PLL3_UPDATE_PDF2_CONTROL_MODE  (1 << 7)  /* Bit 7: pdf2_control_mode */
#define ANADIG_PLL_SYS_PLL3_UPDATE_PFD3_CONTROL_MODE  (1 << 8)  /* Bit 8: pfd3_control_mode */

/* SYS_PLL3_PFD_REGISTER (SYS_PLL3_PFD) */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD0_FRAC_SHIFT    (0)        /* Bits 0-6: PFD0_FRAC */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD0_FRAC_MASK     (0x3F << ANADIG_PLL_SYS_PLL3_PFD_PFD0_FRAC_SHIFT)
#define ANADIG_PLL_SYS_PLL3_PFD_PFD0_FRAC(n)       (((n) << ANADIG_PLL_SYS_PLL3_PFD_PFD0_FRAC_SHIFT) & ANADIG_PLL_SYS_PLL3_PFD_PFD0_FRAC_MASK)
#define ANADIG_PLL_SYS_PLL3_PFD_PFD0_STABLE        (1 << 6)   /* Bit 6: PFD0_STABLE */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD0_DIV1_CLKGATE  (1 << 7)   /* Bit 7: PFD0_DIV1_CLKGATE */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD1_FRAC_SHIFT    (8)        /* Bits 8-14: PFD1_FRAC */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD1_FRAC_MASK     (0x3F << ANADIG_PLL_SYS_PLL3_PFD_PFD1_FRAC_SHIFT)
#define ANADIG_PLL_SYS_PLL3_PFD_PFD1_FRAC(n)       (((n) << ANADIG_PLL_SYS_PLL3_PFD_PFD1_FRAC_SHIFT) & ANADIG_PLL_SYS_PLL3_PFD_PFD1_FRAC_MASK)
#define ANADIG_PLL_SYS_PLL3_PFD_PFD1_STABLE        (1 << 14)  /* Bit 14: PFD1_STABLE */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD1_DIV1_CLKGATE  (1 << 15)  /* Bit 15: PFD1_DIV1_CLKGATE */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD2_FRAC_SHIFT    (16)       /* Bits 16-22: PFD2_FRAC */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD2_FRAC_MASK     (0x3F << ANADIG_PLL_SYS_PLL3_PFD_PFD2_FRAC_SHIFT)
#define ANADIG_PLL_SYS_PLL3_PFD_PFD2_FRAC(n)       (((n) << ANADIG_PLL_SYS_PLL3_PFD_PFD2_FRAC_SHIFT) & ANADIG_PLL_SYS_PLL3_PFD_PFD2_FRAC_MASK)
#define ANADIG_PLL_SYS_PLL3_PFD_PFD2_STABLE        (1 << 22)  /* Bit 22: PFD2_STABLE */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD2_DIV1_CLKGATE  (1 << 23)  /* Bit 23: PFD2_DIV1_CLKGATE */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD3_FRAC_SHIFT    (24)       /* Bits 24-30: PFD3_FRAC */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD3_FRAC_MASK     (0x3F << ANADIG_PLL_SYS_PLL3_PFD_PFD3_FRAC_SHIFT)
#define ANADIG_PLL_SYS_PLL3_PFD_PFD3_FRAC(n)       (((n) << ANADIG_PLL_SYS_PLL3_PFD_PFD3_FRAC_SHIFT) & ANADIG_PLL_SYS_PLL3_PFD_PFD3_FRAC_MASK)
#define ANADIG_PLL_SYS_PLL3_PFD_PFD3_STABLE        (1 << 30)  /* Bit 30: PFD3_STABLE */
#define ANADIG_PLL_SYS_PLL3_PFD_PFD3_DIV1_CLKGATE  (1 << 31)  /* Bit 31: PFD3_DIV1_CLKGATE */

/* SYS_PLL2_CTRL_REGISTER (SYS_PLL2_CTRL) */
#define ANADIG_PLL_SYS_PLL2_CTRL_PLL_REG_EN             (1 << 3)   /* Bit 3: Enable Internal PLL Regulator */
#define ANADIG_PLL_SYS_PLL2_CTRL_HOLD_RING_OFF          (1 << 11)  /* Bit 11: PLL Start up initialization */
#define ANADIG_PLL_SYS_PLL2_CTRL_ENABLE_CLK             (1 << 13)  /* Bit 13: Enable the clock output. */
#define ANADIG_PLL_SYS_PLL2_CTRL_BYPASS                 (1 << 16)  /* Bit 16: Bypass the pll. */
#define ANADIG_PLL_SYS_PLL2_CTRL_DITHER_ENABLE          (1 << 17)  /* Bit 17: DITHER_ENABLE */
#define ANADIG_PLL_SYS_PLL2_CTRL_PFD_OFFSET_EN          (1 << 18)  /* Bit 18: PFD_OFFSET_EN */
#define ANADIG_PLL_SYS_PLL2_CTRL_PLL_DDR_OVERRIDE       (1 << 19)  /* Bit 19: PLL_DDR_OVERRIDE */
#define ANADIG_PLL_SYS_PLL2_CTRL_POWERUP                (1 << 23)  /* Bit 23: Powers up the PLL. */
#define ANADIG_PLL_SYS_PLL2_CTRL_SYS_PLL2_STABLE        (1 << 29)  /* Bit 29: SYS_PLL2_STABLE */
#define ANADIG_PLL_SYS_PLL2_CTRL_SYS_PLL2_GATE          (1 << 30)  /* Bit 30: SYS_PLL2_GATE */
#define ANADIG_PLL_SYS_PLL2_CTRL_SYS_PLL2_CONTROL_MODE  (1 << 31)  /* Bit 31: SYS_PLL2_control_mode */

/* SYS_PLL2_UPDATE_REGISTER (SYS_PLL2_UPDATE) */
#define ANADIG_PLL_SYS_PLL2_UPDATE_PFD0_UPDATE        (1 << 1)  /* Bit 1: PFD0_UPDATE */
#define ANADIG_PLL_SYS_PLL2_UPDATE_PFD1_UPDATE        (1 << 2)  /* Bit 2: PFD1_UPDATE */
#define ANADIG_PLL_SYS_PLL2_UPDATE_PFD2_UPDATE        (1 << 3)  /* Bit 3: PFD2_UPDATE */
#define ANADIG_PLL_SYS_PLL2_UPDATE_PFD3_UPDATE        (1 << 4)  /* Bit 4: PFD3_UPDATE */
#define ANADIG_PLL_SYS_PLL2_UPDATE_PFD0_CONTROL_MODE  (1 << 5)  /* Bit 5: pfd0_control_mode */
#define ANADIG_PLL_SYS_PLL2_UPDATE_PFD1_CONTROL_MODE  (1 << 6)  /* Bit 6: pfd1_control_mode */
#define ANADIG_PLL_SYS_PLL2_UPDATE_PFD2_CONTROL_MODE  (1 << 7)  /* Bit 7: pfd2_control_mode */
#define ANADIG_PLL_SYS_PLL2_UPDATE_PFD3_CONTROL_MODE  (1 << 8)  /* Bit 8: pfd3_control_mode */

/* SYS_PLL2_SS_REGISTER (SYS_PLL2_SS) */
#define ANADIG_PLL_SYS_PLL2_SS_STEP_SHIFT  (0)        /* Bits 0-15: STEP */
#define ANADIG_PLL_SYS_PLL2_SS_STEP_MASK   (0x7FFF << ANADIG_PLL_SYS_PLL2_SS_STEP_SHIFT)
#define ANADIG_PLL_SYS_PLL2_SS_STEP(n)     (((n) << ANADIG_PLL_SYS_PLL2_SS_STEP_SHIFT) & ANADIG_PLL_SYS_PLL2_SS_STEP_MASK)
#define ANADIG_PLL_SYS_PLL2_SS_ENABLE      (1 << 15)  /* Bit 15: ENABLE */
#define ANADIG_PLL_SYS_PLL2_SS_STOP_SHIFT  (16)       /* Bits 16-32: STOP */
#define ANADIG_PLL_SYS_PLL2_SS_STOP_MASK   (0xFFFF << ANADIG_PLL_SYS_PLL2_SS_STOP_SHIFT)
#define ANADIG_PLL_SYS_PLL2_SS_STOP(n)     (((n) << ANADIG_PLL_SYS_PLL2_SS_STOP_SHIFT) & ANADIG_PLL_SYS_PLL2_SS_STOP_MASK)

/* SYS_PLL2_PFD_REGISTER (SYS_PLL2_PFD) */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD0_FRAC_SHIFT    (0)        /* Bits 0-6: PFD0_FRAC */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD0_FRAC_MASK     (0x3F << ANADIG_PLL_SYS_PLL2_PFD_PFD0_FRAC_SHIFT)
#define ANADIG_PLL_SYS_PLL2_PFD_PFD0_FRAC(n)       (((n) << ANADIG_PLL_SYS_PLL2_PFD_PFD0_FRAC_SHIFT) & ANADIG_PLL_SYS_PLL2_PFD_PFD0_FRAC_MASK)
#define ANADIG_PLL_SYS_PLL2_PFD_PFD0_STABLE        (1 << 6)   /* Bit 6: PFD0_STABLE */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD0_DIV1_CLKGATE  (1 << 7)   /* Bit 7: PFD0_DIV1_CLKGATE */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD1_FRAC_SHIFT    (8)        /* Bits 8-14: PFD1_FRAC */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD1_FRAC_MASK     (0x3F << ANADIG_PLL_SYS_PLL2_PFD_PFD1_FRAC_SHIFT)
#define ANADIG_PLL_SYS_PLL2_PFD_PFD1_FRAC(n)       (((n) << ANADIG_PLL_SYS_PLL2_PFD_PFD1_FRAC_SHIFT) & ANADIG_PLL_SYS_PLL2_PFD_PFD1_FRAC_MASK)
#define ANADIG_PLL_SYS_PLL2_PFD_PFD1_STABLE        (1 << 14)  /* Bit 14: PFD1_STABLE */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD1_DIV1_CLKGATE  (1 << 15)  /* Bit 15: PFD1_DIV1_CLKGATE */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD2_FRAC_SHIFT    (16)       /* Bits 16-22: PFD2_FRAC */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD2_FRAC_MASK     (0x3F << ANADIG_PLL_SYS_PLL2_PFD_PFD2_FRAC_SHIFT)
#define ANADIG_PLL_SYS_PLL2_PFD_PFD2_FRAC(n)       (((n) << ANADIG_PLL_SYS_PLL2_PFD_PFD2_FRAC_SHIFT) & ANADIG_PLL_SYS_PLL2_PFD_PFD2_FRAC_MASK)
#define ANADIG_PLL_SYS_PLL2_PFD_PFD2_STABLE        (1 << 22)  /* Bit 22: PFD2_STABLE */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD2_DIV1_CLKGATE  (1 << 23)  /* Bit 23: PFD2_DIV1_CLKGATE */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD3_FRAC_SHIFT    (24)       /* Bits 24-30: PFD3_FRAC */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD3_FRAC_MASK     (0x3F << ANADIG_PLL_SYS_PLL2_PFD_PFD3_FRAC_SHIFT)
#define ANADIG_PLL_SYS_PLL2_PFD_PFD3_FRAC(n)       (((n) << ANADIG_PLL_SYS_PLL2_PFD_PFD3_FRAC_SHIFT) & ANADIG_PLL_SYS_PLL2_PFD_PFD3_FRAC_MASK)
#define ANADIG_PLL_SYS_PLL2_PFD_PFD3_STABLE        (1 << 30)  /* Bit 30: PFD3_STABLE */
#define ANADIG_PLL_SYS_PLL2_PFD_PFD3_DIV1_CLKGATE  (1 << 31)  /* Bit 31: PFD3_DIV1_CLKGATE */

/* SYS_PLL2_MFD_REGISTER (SYS_PLL2_MFD) */
#define ANADIG_PLL_SYS_PLL2_MFD_MFD_SHIFT  (0)  /* Bits 0-30: Denominator */
#define ANADIG_PLL_SYS_PLL2_MFD_MFD_MASK   (0x3FFFFFFF << ANADIG_PLL_SYS_PLL2_MFD_MFD_SHIFT)
#define ANADIG_PLL_SYS_PLL2_MFD_MFD(n)     (((n) << ANADIG_PLL_SYS_PLL2_MFD_MFD_SHIFT) & ANADIG_PLL_SYS_PLL2_MFD_MFD_MASK)

/* SYS_PLL1_SS_REGISTER (SYS_PLL1_SS) */
#define ANADIG_PLL_SYS_PLL1_SS_STEP_SHIFT  (0)        /* Bits 0-15: STEP */
#define ANADIG_PLL_SYS_PLL1_SS_STEP_MASK   (0x7FFF << ANADIG_PLL_SYS_PLL1_SS_STEP_SHIFT)
#define ANADIG_PLL_SYS_PLL1_SS_STEP(n)     (((n) << ANADIG_PLL_SYS_PLL1_SS_STEP_SHIFT) & ANADIG_PLL_SYS_PLL1_SS_STEP_MASK)
#define ANADIG_PLL_SYS_PLL1_SS_ENABLE      (1 << 15)  /* Bit 15: ENABLE */
#define ANADIG_PLL_SYS_PLL1_SS_STOP_SHIFT  (16)       /* Bits 16-32: STOP */
#define ANADIG_PLL_SYS_PLL1_SS_STOP_MASK   (0xFFFF << ANADIG_PLL_SYS_PLL1_SS_STOP_SHIFT)
#define ANADIG_PLL_SYS_PLL1_SS_STOP(n)     (((n) << ANADIG_PLL_SYS_PLL1_SS_STOP_SHIFT) & ANADIG_PLL_SYS_PLL1_SS_STOP_MASK)

/* SYS_PLL1_CTRL_REGISTER (SYS_PLL1_CTRL) */
#define ANADIG_PLL_SYS_PLL1_CTRL_ENABLE_CLK                  (1 << 13)  /* Bit 13: ENABLE_CLK */
#define ANADIG_PLL_SYS_PLL1_CTRL_SYS_PLL1_GATE               (1 << 14)  /* Bit 14: SYS_PLL1_GATE */
#define ANADIG_PLL_SYS_PLL1_CTRL_SYS_PLL1_DIV2               (1 << 25)  /* Bit 25: SYS_PLL1_DIV2 */
#define ANADIG_PLL_SYS_PLL1_CTRL_SYS_PLL1_DIV5               (1 << 26)  /* Bit 26: SYS_PLL1_DIV5 */
#define ANADIG_PLL_SYS_PLL1_CTRL_SYS_PLL1_DIV5_CONTROL_MODE  (1 << 27)  /* Bit 27: SYS_PLL1_DIV5_CONTROL_MODE */
#define ANADIG_PLL_SYS_PLL1_CTRL_SYS_PLL1_DIV2_CONTROL_MODE  (1 << 28)  /* Bit 28: SYS_PLL1_DIV2_CONTROL_MODE */
#define ANADIG_PLL_SYS_PLL1_CTRL_SYS_PLL1_STABLE             (1 << 29)  /* Bit 29: SYS_PLL1_STABLE */
#define ANADIG_PLL_SYS_PLL1_CTRL_SYS_PLL1_AI_BUSY            (1 << 30)  /* Bit 30: SYS_PLL1_AI_BUSY */
#define ANADIG_PLL_SYS_PLL1_CTRL_SYS_PLL1_CONTROL_MODE       (1 << 31)  /* Bit 31: SYS_PLL1_CONTROL_MODE */

/* SYS_PLL1_DENOMINATOR_REGISTER (SYS_PLL1_DENOMINATOR) */
#define ANADIG_PLL_SYS_PLL1_DENOMINATOR_DENOM_SHIFT  (0)  /* Bits 0-30: DENOM */
#define ANADIG_PLL_SYS_PLL1_DENOMINATOR_DENOM_MASK   (0x3FFFFFFF << ANADIG_PLL_SYS_PLL1_DENOMINATOR_DENOM_SHIFT)
#define ANADIG_PLL_SYS_PLL1_DENOMINATOR_DENOM(n)     (((n) << ANADIG_PLL_SYS_PLL1_DENOMINATOR_DENOM_SHIFT) & ANADIG_PLL_SYS_PLL1_DENOMINATOR_DENOM_MASK)

/* SYS_PLL1_NUMERATOR_REGISTER (SYS_PLL1_NUMERATOR) */
#define ANADIG_PLL_SYS_PLL1_NUMERATOR_NUM_SHIFT  (0)  /* Bits 0-30: NUM */
#define ANADIG_PLL_SYS_PLL1_NUMERATOR_NUM_MASK   (0x3FFFFFFF << ANADIG_PLL_SYS_PLL1_NUMERATOR_NUM_SHIFT)
#define ANADIG_PLL_SYS_PLL1_NUMERATOR_NUM(n)     (((n) << ANADIG_PLL_SYS_PLL1_NUMERATOR_NUM_SHIFT) & ANADIG_PLL_SYS_PLL1_NUMERATOR_NUM_MASK)

/* SYS_PLL1_DIV_SELECT_REGISTER (SYS_PLL1_DIV_SELECT) */
#define ANADIG_PLL_SYS_PLL1_DIV_SELECT_DIV_SELECT_SHIFT  (0)  /* Bits 0-7: DIV_SELECT */
#define ANADIG_PLL_SYS_PLL1_DIV_SELECT_DIV_SELECT_MASK   (0x7F << ANADIG_PLL_SYS_PLL1_DIV_SELECT_DIV_SELECT_SHIFT)
#define ANADIG_PLL_SYS_PLL1_DIV_SELECT_DIV_SELECT(n)     (((n) << ANADIG_PLL_SYS_PLL1_DIV_SELECT_DIV_SELECT_SHIFT) & ANADIG_PLL_SYS_PLL1_DIV_SELECT_DIV_SELECT_MASK)

/* PLL_AUDIO_CTRL_REGISTER (PLL_AUDIO_CTRL) */
#define ANADIG_PLL_PLL_AUDIO_CTRL_ENABLE_CLK              (1 << 13)  /* Bit 13: ENABLE_CLK */
#define ANADIG_PLL_PLL_AUDIO_CTRL_PLL_AUDIO_GATE          (1 << 14)  /* Bit 14: PLL_AUDIO_GATE */
#define ANADIG_PLL_PLL_AUDIO_CTRL_PLL_AUDIO_STABLE        (1 << 29)  /* Bit 29: PLL_AUDIO_STABLE */
#define ANADIG_PLL_PLL_AUDIO_CTRL_PLL_AUDIO_AI_BUSY       (1 << 30)  /* Bit 30: pll_audio_ai_busy */
#define ANADIG_PLL_PLL_AUDIO_CTRL_PLL_AUDIO_CONTROL_MODE  (1 << 31)  /* Bit 31: pll_audio_control_mode */

/* PLL_AUDIO_SS_REGISTER (PLL_AUDIO_SS) */
#define ANADIG_PLL_PLL_AUDIO_SS_STEP_SHIFT  (0)        /* Bits 0-15: STEP */
#define ANADIG_PLL_PLL_AUDIO_SS_STEP_MASK   (0x7FFF << ANADIG_PLL_PLL_AUDIO_SS_STEP_SHIFT)
#define ANADIG_PLL_PLL_AUDIO_SS_STEP(n)     (((n) << ANADIG_PLL_PLL_AUDIO_SS_STEP_SHIFT) & ANADIG_PLL_PLL_AUDIO_SS_STEP_MASK)
#define ANADIG_PLL_PLL_AUDIO_SS_ENABLE      (1 << 15)  /* Bit 15: ENABLE */
#define ANADIG_PLL_PLL_AUDIO_SS_STOP_SHIFT  (16)       /* Bits 16-32: STOP */
#define ANADIG_PLL_PLL_AUDIO_SS_STOP_MASK   (0xFFFF << ANADIG_PLL_PLL_AUDIO_SS_STOP_SHIFT)
#define ANADIG_PLL_PLL_AUDIO_SS_STOP(n)     (((n) << ANADIG_PLL_PLL_AUDIO_SS_STOP_SHIFT) & ANADIG_PLL_PLL_AUDIO_SS_STOP_MASK)

/* PLL_AUDIO_DENOMINATOR_REGISTER (PLL_AUDIO_DENOMINATOR) */
#define ANADIG_PLL_PLL_AUDIO_DENOMINATOR_DENOM_SHIFT  (0)  /* Bits 0-30: DENOM */
#define ANADIG_PLL_PLL_AUDIO_DENOMINATOR_DENOM_MASK   (0x3FFFFFFF << ANADIG_PLL_PLL_AUDIO_DENOMINATOR_DENOM_SHIFT)
#define ANADIG_PLL_PLL_AUDIO_DENOMINATOR_DENOM(n)     (((n) << ANADIG_PLL_PLL_AUDIO_DENOMINATOR_DENOM_SHIFT) & ANADIG_PLL_PLL_AUDIO_DENOMINATOR_DENOM_MASK)

/* PLL_AUDIO_NUMERATOR_REGISTER (PLL_AUDIO_NUMERATOR) */
#define ANADIG_PLL_PLL_AUDIO_NUMERATOR_NUM_SHIFT  (0)  /* Bits 0-30: NUM */
#define ANADIG_PLL_PLL_AUDIO_NUMERATOR_NUM_MASK   (0x3FFFFFFF << ANADIG_PLL_PLL_AUDIO_NUMERATOR_NUM_SHIFT)
#define ANADIG_PLL_PLL_AUDIO_NUMERATOR_NUM(n)     (((n) << ANADIG_PLL_PLL_AUDIO_NUMERATOR_NUM_SHIFT) & ANADIG_PLL_PLL_AUDIO_NUMERATOR_NUM_MASK)

/* PLL_AUDIO_DIV_SELECT_REGISTER (PLL_AUDIO_DIV_SELECT) */
#define ANADIG_PLL_PLL_AUDIO_DIV_SELECT_PLL_AUDIO_DIV_SELECT_SHIFT  (0)  /* Bits 0-7: PLL_AUDIO_DIV_SELECT */
#define ANADIG_PLL_PLL_AUDIO_DIV_SELECT_PLL_AUDIO_DIV_SELECT_MASK   (0x7F << ANADIG_PLL_PLL_AUDIO_DIV_SELECT_PLL_AUDIO_DIV_SELECT_SHIFT)
#define ANADIG_PLL_PLL_AUDIO_DIV_SELECT_PLL_AUDIO_DIV_SELECT(n)     (((n) << ANADIG_PLL_PLL_AUDIO_DIV_SELECT_PLL_AUDIO_DIV_SELECT_SHIFT) & ANADIG_PLL_PLL_AUDIO_DIV_SELECT_PLL_AUDIO_DIV_SELECT_MASK)

/* PLL_VIDEO_CTRL_REGISTER (PLL_VIDEO_CTRL) */
#define ANADIG_PLL_PLL_VIDEO_CTRL_ENABLE_CLK              (1 << 13)  /* Bit 13: ENABLE_CLK */
#define ANADIG_PLL_PLL_VIDEO_CTRL_PLL_VIDEO_GATE          (1 << 14)  /* Bit 14: PLL_VIDEO_GATE */
#define ANADIG_PLL_PLL_VIDEO_CTRL_PLL_VIDEO_COUNTER_CLR   (1 << 24)  /* Bit 24: pll_video_counter_clr */
#define ANADIG_PLL_PLL_VIDEO_CTRL_PLL_VIDEO_STABLE        (1 << 29)  /* Bit 29: PLL_VIDEO_STABLE */
#define ANADIG_PLL_PLL_VIDEO_CTRL_PLL_VIDEO_AI_BUSY       (1 << 30)  /* Bit 30: pll_video_ai_busy */
#define ANADIG_PLL_PLL_VIDEO_CTRL_PLL_VIDEO_CONTROL_MODE  (1 << 31)  /* Bit 31: pll_video_control_mode */

/* PLL_VIDEO_SS_REGISTER (PLL_VIDEO_SS) */
#define ANADIG_PLL_PLL_VIDEO_SS_STEP_SHIFT  (0)        /* Bits 0-15: STEP */
#define ANADIG_PLL_PLL_VIDEO_SS_STEP_MASK   (0x7FFF << ANADIG_PLL_PLL_VIDEO_SS_STEP_SHIFT)
#define ANADIG_PLL_PLL_VIDEO_SS_STEP(n)     (((n) << ANADIG_PLL_PLL_VIDEO_SS_STEP_SHIFT) & ANADIG_PLL_PLL_VIDEO_SS_STEP_MASK)
#define ANADIG_PLL_PLL_VIDEO_SS_ENABLE      (1 << 15)  /* Bit 15: ENABLE */
#define ANADIG_PLL_PLL_VIDEO_SS_STOP_SHIFT  (16)       /* Bits 16-32: STOP */
#define ANADIG_PLL_PLL_VIDEO_SS_STOP_MASK   (0xFFFF << ANADIG_PLL_PLL_VIDEO_SS_STOP_SHIFT)
#define ANADIG_PLL_PLL_VIDEO_SS_STOP(n)     (((n) << ANADIG_PLL_PLL_VIDEO_SS_STOP_SHIFT) & ANADIG_PLL_PLL_VIDEO_SS_STOP_MASK)

/* PLL_VIDEO_DENOMINATOR_REGISTER (PLL_VIDEO_DENOMINATOR) */
#define ANADIG_PLL_PLL_VIDEO_DENOMINATOR_DENOM_SHIFT  (0)  /* Bits 0-30: DENOM */
#define ANADIG_PLL_PLL_VIDEO_DENOMINATOR_DENOM_MASK   (0x3FFFFFFF << ANADIG_PLL_PLL_VIDEO_DENOMINATOR_DENOM_SHIFT)
#define ANADIG_PLL_PLL_VIDEO_DENOMINATOR_DENOM(n)     (((n) << ANADIG_PLL_PLL_VIDEO_DENOMINATOR_DENOM_SHIFT) & ANADIG_PLL_PLL_VIDEO_DENOMINATOR_DENOM_MASK)

/* PLL_VIDEO_NUMERATOR_REGISTER (PLL_VIDEO_NUMERATOR) */
#define ANADIG_PLL_PLL_VIDEO_NUMERATOR_NUM_SHIFT  (0)  /* Bits 0-30: NUM */
#define ANADIG_PLL_PLL_VIDEO_NUMERATOR_NUM_MASK   (0x3FFFFFFF << ANADIG_PLL_PLL_VIDEO_NUMERATOR_NUM_SHIFT)
#define ANADIG_PLL_PLL_VIDEO_NUMERATOR_NUM(n)     (((n) << ANADIG_PLL_PLL_VIDEO_NUMERATOR_NUM_SHIFT) & ANADIG_PLL_PLL_VIDEO_NUMERATOR_NUM_MASK)

/* PLL_VIDEO_DIV_SELECT_REGISTER (PLL_VIDEO_DIV_SELECT) */
#define ANADIG_PLL_PLL_VIDEO_DIV_SELECT_DIV_SELECT_SHIFT  (0)  /* Bits 0-7: DIV_SELECT */
#define ANADIG_PLL_PLL_VIDEO_DIV_SELECT_DIV_SELECT_MASK   (0x7F << ANADIG_PLL_PLL_VIDEO_DIV_SELECT_DIV_SELECT_SHIFT)
#define ANADIG_PLL_PLL_VIDEO_DIV_SELECT_DIV_SELECT(n)     (((n) << ANADIG_PLL_PLL_VIDEO_DIV_SELECT_DIV_SELECT_SHIFT) & ANADIG_PLL_PLL_VIDEO_DIV_SELECT_DIV_SELECT_MASK)

#endif /* __ARCH_ARM_SRC_IMXRT_HARDWARE_RT117X_IMXRT117X_PLL_H */
