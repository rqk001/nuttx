/****************************************************************************
 * arch/arm/src/imxrt/hardware/rt117x/imxrt117x_gpio.h
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

#ifndef __ARCH_ARM_SRC_IMXRT_HARDWARE_RT117X_IMXRT117X_GPIO_H
#define __ARCH_ARM_SRC_IMXRT_HARDWARE_RT117X_IMXRT117X_GPIO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include "hardware/imxrt_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register offsets *********************************************************/

#define IMXRT_GPIO_DR_OFFSET     0x0000  /* GPIO data register */
#define IMXRT_GPIO_GDIR_OFFSET   0x0004  /* GPIO direction register */
#define IMXRT_GPIO_PSR_OFFSET    0x0008  /* GPIO pad status register */
#define IMXRT_GPIO_ICR1_OFFSET   0x000c  /* GPIO interrupt configuration register1 */
#define IMXRT_GPIO_ICR2_OFFSET   0x0010  /* GPIO interrupt configuration register2 */
#define IMXRT_GPIO_IMR_OFFSET    0x0014  /* GPIO interrupt mask register */
#define IMXRT_GPIO_ISR_OFFSET    0x0018  /* GPIO interrupt status register */
#define IMXRT_GPIO_EDGE_OFFSET   0x001c  /* GPIO edge select register */
#define IMXRT_GPIO_SET_OFFSET    0x0084  /* GPIO data register SET */
#define IMXRT_GPIO_CLEAR_OFFSET  0x0088  /* GPIO data register CLEAR */
#define IMXRT_GPIO_TOGGLE_OFFSET 0x008c  /* GPIO data register TOGGLE */

/* Register addresses *******************************************************/

#define IMXRT_CM7_GPIO2_DR       (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_CM7_GPIO2_GDIR     (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_CM7_GPIO2_PSR      (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_CM7_GPIO2_ICR1     (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_CM7_GPIO2_ICR2     (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_CM7_GPIO2_IMR      (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_CM7_GPIO2_ISR      (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_CM7_GPIO2_EDGE     (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_CM7_GPIO2_SET      (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_CM7_GPIO2_CLEAR    (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_CM7_GPIO2_TOGGLE   (IMXRT_CM7_GPIO2_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_CM7_GPIO3_DR       (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_CM7_GPIO3_GDIR     (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_CM7_GPIO3_PSR      (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_CM7_GPIO3_ICR1     (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_CM7_GPIO3_ICR2     (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_CM7_GPIO3_IMR      (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_CM7_GPIO3_ISR      (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_CM7_GPIO3_EDGE     (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_CM7_GPIO3_SET      (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_CM7_GPIO3_CLEAR    (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_CM7_GPIO3_TOGGLE   (IMXRT_CM7_GPIO3_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO1_DR           (IMXRT_GPIO1_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO1_GDIR         (IMXRT_GPIO1_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO1_PSR          (IMXRT_GPIO1_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO1_ICR1         (IMXRT_GPIO1_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO1_ICR2         (IMXRT_GPIO1_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO1_IMR          (IMXRT_GPIO1_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO1_ISR          (IMXRT_GPIO1_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO1_EDGE         (IMXRT_GPIO1_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO1_SET          (IMXRT_GPIO1_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO1_CLEAR        (IMXRT_GPIO1_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO1_TOGGLE       (IMXRT_GPIO1_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO2_DR           (IMXRT_GPIO2_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO2_GDIR         (IMXRT_GPIO2_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO2_PSR          (IMXRT_GPIO2_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO2_ICR1         (IMXRT_GPIO2_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO2_ICR2         (IMXRT_GPIO2_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO2_IMR          (IMXRT_GPIO2_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO2_ISR          (IMXRT_GPIO2_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO2_EDGE         (IMXRT_GPIO2_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO2_SET          (IMXRT_GPIO2_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO2_CLEAR        (IMXRT_GPIO2_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO2_TOGGLE       (IMXRT_GPIO2_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO3_DR           (IMXRT_GPIO3_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO3_GDIR         (IMXRT_GPIO3_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO3_PSR          (IMXRT_GPIO3_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO3_ICR1         (IMXRT_GPIO3_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO3_ICR2         (IMXRT_GPIO3_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO3_IMR          (IMXRT_GPIO3_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO3_ISR          (IMXRT_GPIO3_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO3_EDGE         (IMXRT_GPIO3_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO3_SET          (IMXRT_GPIO3_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO3_CLEAR        (IMXRT_GPIO3_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO3_TOGGLE       (IMXRT_GPIO3_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO4_DR           (IMXRT_GPIO4_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO4_GDIR         (IMXRT_GPIO4_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO4_PSR          (IMXRT_GPIO4_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO4_ICR1         (IMXRT_GPIO4_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO4_ICR2         (IMXRT_GPIO4_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO4_IMR          (IMXRT_GPIO4_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO4_ISR          (IMXRT_GPIO4_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO4_EDGE         (IMXRT_GPIO4_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO4_SET          (IMXRT_GPIO4_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO4_CLEAR        (IMXRT_GPIO4_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO4_TOGGLE       (IMXRT_GPIO4_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO5_DR           (IMXRT_GPIO5_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO5_GDIR         (IMXRT_GPIO5_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO5_PSR          (IMXRT_GPIO5_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO5_ICR1         (IMXRT_GPIO5_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO5_ICR2         (IMXRT_GPIO5_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO5_IMR          (IMXRT_GPIO5_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO5_ISR          (IMXRT_GPIO5_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO5_EDGE         (IMXRT_GPIO5_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO5_SET          (IMXRT_GPIO5_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO5_CLEAR        (IMXRT_GPIO5_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO5_TOGGLE       (IMXRT_GPIO5_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO6_DR         (IMXRT_GPIO6_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO6_GDIR       (IMXRT_GPIO6_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO6_PSR        (IMXRT_GPIO6_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO6_ICR1       (IMXRT_GPIO6_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO6_ICR2       (IMXRT_GPIO6_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO6_IMR        (IMXRT_GPIO6_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO6_ISR        (IMXRT_GPIO6_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO6_EDGE       (IMXRT_GPIO6_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO6_SET        (IMXRT_GPIO6_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO6_CLEAR      (IMXRT_GPIO6_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO6_TOGGLE     (IMXRT_GPIO6_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO7_DR         (IMXRT_GPIO7_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO7_GDIR       (IMXRT_GPIO7_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO7_PSR        (IMXRT_GPIO7_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO7_ICR1       (IMXRT_GPIO7_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO7_ICR2       (IMXRT_GPIO7_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO7_IMR        (IMXRT_GPIO7_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO7_ISR        (IMXRT_GPIO7_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO7_EDGE       (IMXRT_GPIO7_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO7_SET        (IMXRT_GPIO7_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO7_CLEAR      (IMXRT_GPIO7_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO7_TOGGLE     (IMXRT_GPIO7_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO8_DR         (IMXRT_GPIO8_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO8_GDIR       (IMXRT_GPIO8_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO8_PSR        (IMXRT_GPIO8_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO8_ICR1       (IMXRT_GPIO8_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO8_ICR2       (IMXRT_GPIO8_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO8_IMR        (IMXRT_GPIO8_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO8_ISR        (IMXRT_GPIO8_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO8_EDGE       (IMXRT_GPIO8_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO8_SET        (IMXRT_GPIO8_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO8_CLEAR      (IMXRT_GPIO8_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO8_TOGGLE     (IMXRT_GPIO8_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO9_DR         (IMXRT_GPIO9_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO9_GDIR       (IMXRT_GPIO9_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO9_PSR        (IMXRT_GPIO9_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO9_ICR1       (IMXRT_GPIO9_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO9_ICR2       (IMXRT_GPIO9_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO9_IMR        (IMXRT_GPIO9_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO9_ISR        (IMXRT_GPIO9_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO9_EDGE       (IMXRT_GPIO9_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO9_SET        (IMXRT_GPIO9_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO9_CLEAR      (IMXRT_GPIO9_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO9_TOGGLE     (IMXRT_GPIO9_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO10_DR        (IMXRT_GPIO10_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO10_GDIR      (IMXRT_GPIO10_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO10_PSR       (IMXRT_GPIO10_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO10_ICR1      (IMXRT_GPIO10_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO10_ICR2      (IMXRT_GPIO10_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO10_IMR       (IMXRT_GPIO10_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO10_ISR       (IMXRT_GPIO10_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO10_EDGE      (IMXRT_GPIO10_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO10_SET       (IMXRT_GPIO10_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO10_CLEAR     (IMXRT_GPIO10_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO10_TOGGLE    (IMXRT_GPIO10_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO11_DR        (IMXRT_GPIO11_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO11_GDIR      (IMXRT_GPIO11_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO11_PSR       (IMXRT_GPIO11_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO11_ICR1      (IMXRT_GPIO11_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO11_ICR2      (IMXRT_GPIO11_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO11_IMR       (IMXRT_GPIO11_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO11_ISR       (IMXRT_GPIO11_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO11_EDGE      (IMXRT_GPIO11_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO11_SET       (IMXRT_GPIO11_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO11_CLEAR     (IMXRT_GPIO11_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO11_TOGGLE    (IMXRT_GPIO11_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO12_DR        (IMXRT_GPIO12_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO12_GDIR      (IMXRT_GPIO12_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO12_PSR       (IMXRT_GPIO12_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO12_ICR1      (IMXRT_GPIO12_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO12_ICR2      (IMXRT_GPIO12_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO12_IMR       (IMXRT_GPIO12_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO12_ISR       (IMXRT_GPIO12_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO12_EDGE      (IMXRT_GPIO12_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO12_SET       (IMXRT_GPIO12_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO12_CLEAR     (IMXRT_GPIO12_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO12_TOGGLE    (IMXRT_GPIO12_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#define IMXRT_GPIO13_DR        (IMXRT_GPIO13_BASE + IMXRT_GPIO_DR_OFFSET)
#define IMXRT_GPIO13_GDIR      (IMXRT_GPIO13_BASE + IMXRT_GPIO_GDIR_OFFSET)
#define IMXRT_GPIO13_PSR       (IMXRT_GPIO13_BASE + IMXRT_GPIO_PSR_OFFSET)
#define IMXRT_GPIO13_ICR1      (IMXRT_GPIO13_BASE + IMXRT_GPIO_ICR1_OFFSET)
#define IMXRT_GPIO13_ICR2      (IMXRT_GPIO13_BASE + IMXRT_GPIO_ICR2_OFFSET)
#define IMXRT_GPIO13_IMR       (IMXRT_GPIO13_BASE + IMXRT_GPIO_IMR_OFFSET)
#define IMXRT_GPIO13_ISR       (IMXRT_GPIO13_BASE + IMXRT_GPIO_ISR_OFFSET)
#define IMXRT_GPIO13_EDGE      (IMXRT_GPIO13_BASE + IMXRT_GPIO_EDGE_OFFSET)
#define IMXRT_GPIO13_SET       (IMXRT_GPIO13_BASE + IMXRT_GPIO_SET_OFFSET)
#define IMXRT_GPIO13_CLEAR     (IMXRT_GPIO13_BASE + IMXRT_GPIO_CLEAR_OFFSET)
#define IMXRT_GPIO13_TOGGLE    (IMXRT_GPIO13_BASE + IMXRT_GPIO_TOGGLE_OFFSET)

#endif /* __ARCH_ARM_SRC_IMXRT_HARDWARE_RT117X_IMXRT117X_GPIO_H */
