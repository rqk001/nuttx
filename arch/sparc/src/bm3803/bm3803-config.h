/****************************************************************************
 * arch/sparc/src/bm3803/bm3803-config.h
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

#ifndef __ARCH_SPARC_SRC_BM3803_CONFIG_H
#define __ARCH_SPARC_SRC_BM3803_CONFIG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <arch/board/board.h>

#include "chip.h"

#include "bm3803-memorymap.h"
#include "bm3803-uart.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* SYS calls ****************************************************************/

/* SYS call 1 and 2 are defined for internal use by the BM3803 port (see
 * arch/sparc/include/sparc32/syscall.h).  In addition, SYS call 3 is the
 * return from a SYS call in kernel mode.  The first four syscall values
 * must, therefore, be reserved (0 is not used).
 */

#ifdef CONFIG_BUILD_KERNEL
#  if !defined(CONFIG_SYS_RESERVED) || CONFIG_SYS_RESERVED < 4
#    error "CONFIG_SYS_RESERVED must be defined to be 4 for a kernel build"
#  elif CONFIG_SYS_RESERVED > 4
#    warning "CONFIG_SYS_RESERVED should be defined to be 4 for a kernel build"
#  endif
#endif

/* UARTs ********************************************************************/

/* Don't enable UARTs not supported by the chip. */

#if CHIP_NUARTS < 1
#  undef CONFIG_BM3803_UART1
#  undef CONFIG_BM3803_UART2
#  undef CONFIG_BM3803_UART3
#elif CHIP_NUARTS < 2
#  undef CONFIG_BM3803_UART2
#  undef CONFIG_BM3803_UART3
#elif CHIP_NUARTS < 3
#  undef CONFIG_BM3803_UART3
#endif

/* Are any UARTs enabled? */

#undef HAVE_UART_DEVICE
#if defined(CONFIG_BM3803_UART1) || defined(CONFIG_BM3803_UART2) || defined(CONFIG_BM3803_UART3)
#  define HAVE_UART_DEVICE 1
#endif

/* Is there a serial console?  There should be no more than one defined.  It
 * could be on any UARTn, n=1,.. CHIP_NUARTS
 */

#if defined(CONFIG_UART1_SERIAL_CONSOLE) && defined(CONFIG_BM3803_UART1)
#  undef CONFIG_UART2_SERIAL_CONSOLE
#  undef CONFIG_UART3_SERIAL_CONSOLE
#  define HAVE_SERIAL_CONSOLE 1
#elif defined(CONFIG_UART2_SERIAL_CONSOLE) && defined(CONFIG_BM3803_UART2)
#  undef CONFIG_UART1_SERIAL_CONSOLE
#  undef CONFIG_UART3_SERIAL_CONSOLE
#  define HAVE_SERIAL_CONSOLE 1
#elif defined(CONFIG_UART3_SERIAL_CONSOLE) && defined(CONFIG_BM3803_UART3)
#  undef CONFIG_UART1_SERIAL_CONSOLE
#  undef CONFIG_UART2_SERIAL_CONSOLE
#  define HAVE_SERIAL_CONSOLE 1
#else
#  undef CONFIG_UART1_SERIAL_CONSOLE
#  undef CONFIG_UART2_SERIAL_CONSOLE
#  undef CONFIG_UART3_SERIAL_CONSOLE
#  undef HAVE_SERIAL_CONSOLE
#endif

#endif /* __ARCH_SPARC_SRC_BM3803_CONFIG_H */
