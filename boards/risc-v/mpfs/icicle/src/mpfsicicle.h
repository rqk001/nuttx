/****************************************************************************
 * boards/risc-v/mpfs/icicle/src/mpfsicicle.h
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

#ifndef __BOARDS_RISCV_ICICLE_MPFS_SRC_MPFSICICLE_H
#define __BOARDS_RISCV_ICICLE_MPFS_SRC_MPFSICICLE_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#define ICICLE_GPIO_LED1 (GPIO_BANK2 | GPIO_PIN19 | GPIO_OUTPUT)
#define ICICLE_GPIO_LED2 (GPIO_BANK2 | GPIO_PIN18 | GPIO_OUTPUT)
#define ICICLE_GPIO_LED3 (GPIO_BANK2 | GPIO_PIN17 | GPIO_OUTPUT)
#define ICICLE_GPIO_LED4 (GPIO_BANK2 | GPIO_PIN16 | GPIO_OUTPUT)

/* note: button1 don't have gpio. Only irq */

#define ICICLE_GPIO_BUTTON2     (GPIO_BANK2 | GPIO_PIN30 | GPIO_INPUT | \
                                 GPIO_IRQ_ENABLE | GPIO_IRQ_EDGE_POS)
#define ICICLE_GPIO_BUTTON2_ALT (GPIO_BANK2 | GPIO_PIN26 | GPIO_OUTPUT)
#define ICICLE_GPIO_BUTTON3     (GPIO_BANK2 | GPIO_PIN31 | GPIO_INPUT | \
                                 GPIO_IRQ_ENABLE | GPIO_IRQ_EDGE_POS)
#define ICICLE_GPIO_BUTTON3_ALT (GPIO_BANK2 | GPIO_PIN27 | GPIO_OUTPUT)

int mpfs_bringup(void);

#endif /* __BOARDS_RISCV_ICICLE_MPFS_SRC_MPFSICICLE_H */
