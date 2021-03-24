/************************************************************************************
 * arch/arm/src/stm32h7/stm32_uart.h
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

#ifndef __ARCH_ARM_SRC_STM32H7_STM32_UART_H
#define __ARCH_ARM_SRC_STM32H7_STM32_UART_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>
#include <nuttx/serial/serial.h>

#include "hardware/stm32_uart.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* Make sure that we have not enabled more U[S]ARTs than are supported by the
 * device.
 */

#if STM32H7_NUART < 4
#  undef CONFIG_STM32H7_UART8
#endif
#if STM32H7_NUART < 3
#  undef CONFIG_STM32H7_UART7
#endif
#if STM32H7_NUART < 2
#  undef CONFIG_STM32H7_UART5
#endif
#if STM32H7_NUART < 1
#  undef CONFIG_STM32H7_UART4
#endif

#if STM32H7_NUSART < 4
#  undef CONFIG_STM32H7_USART6
#endif
#if STM32H7_NUSART < 3
#  undef CONFIG_STM32H7_USART3
#endif
#if STM32H7_NUSART < 2
#  undef CONFIG_STM32H7_USART2
#endif
#if STM32H7_NUSART < 1
#  undef CONFIG_STM32H7_USART1
#endif

/* Is there a USART enabled? */

#if defined(CONFIG_STM32H7_USART1) || defined(CONFIG_STM32H7_USART2) || \
    defined(CONFIG_STM32H7_USART3) || defined(CONFIG_STM32H7_UART4)  || \
    defined(CONFIG_STM32H7_UART5)  || defined(CONFIG_STM32H7_USART6) || \
    defined(CONFIG_STM32H7_UART7)  || defined(CONFIG_STM32H7_UART8)
#  define HAVE_UART 1
#endif

/* Is there a serial console? */

#if defined(CONFIG_USART1_SERIAL_CONSOLE) && defined(CONFIG_STM32H7_USART1)
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_UART4_SERIAL_CONSOLE
#  undef CONFIG_UART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_UART7_SERIAL_CONSOLE
#  undef CONFIG_UART8_SERIAL_CONSOLE
#  define CONSOLE_UART 1
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_USART2_SERIAL_CONSOLE) && defined(CONFIG_STM32H7_USART2)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_UART4_SERIAL_CONSOLE
#  undef CONFIG_UART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_UART7_SERIAL_CONSOLE
#  undef CONFIG_UART8_SERIAL_CONSOLE
#  define CONSOLE_UART 2
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_USART3_SERIAL_CONSOLE) && defined(CONFIG_STM32H7_USART3)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_UART4_SERIAL_CONSOLE
#  undef CONFIG_UART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_UART7_SERIAL_CONSOLE
#  undef CONFIG_UART8_SERIAL_CONSOLE
#  define CONSOLE_UART 3
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_UART4_SERIAL_CONSOLE) && defined(CONFIG_STM32H7_UART4)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_UART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_UART7_SERIAL_CONSOLE
#  undef CONFIG_UART8_SERIAL_CONSOLE
#  define CONSOLE_UART 4
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_UART5_SERIAL_CONSOLE) && defined(CONFIG_STM32H7_UART5)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_UART4_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_UART7_SERIAL_CONSOLE
#  undef CONFIG_UART8_SERIAL_CONSOLE
#  define CONSOLE_UART 5
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_USART6_SERIAL_CONSOLE) && defined(CONFIG_STM32H7_USART6)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_UART4_SERIAL_CONSOLE
#  undef CONFIG_UART5_SERIAL_CONSOLE
#  undef CONFIG_UART7_SERIAL_CONSOLE
#  undef CONFIG_UART8_SERIAL_CONSOLE
#  define CONSOLE_UART 6
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_UART7_SERIAL_CONSOLE) && defined(CONFIG_STM32H7_UART7)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_UART4_SERIAL_CONSOLE
#  undef CONFIG_UART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_UART8_SERIAL_CONSOLE
#  define CONSOLE_UART 7
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_UART8_SERIAL_CONSOLE) && defined(CONFIG_STM32H7_UART8)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_UART4_SERIAL_CONSOLE
#  undef CONFIG_UART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_UART7_SERIAL_CONSOLE
#  define CONSOLE_UART 8
#  define HAVE_CONSOLE 1
#else
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_UART4_SERIAL_CONSOLE
#  undef CONFIG_UART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_UART7_SERIAL_CONSOLE
#  undef CONFIG_UART8_SERIAL_CONSOLE
#  define CONSOLE_UART 0
#  undef HAVE_CONSOLE
#endif

/* Is RS-485 used? */

#if defined(CONFIG_USART1_RS485) || defined(CONFIG_USART2_RS485) || \
    defined(CONFIG_USART3_RS485) || defined(CONFIG_UART4_RS485)  || \
    defined(CONFIG_UART5_RS485)  || defined(CONFIG_USART6_RS485)  || \
    defined(CONFIG_UART7_RS485)  || defined(CONFIG_UART8_RS485)
#  define HAVE_RS485 1
#endif

#ifdef HAVE_RS485
#  define USART_CR1_USED_INTS    (USART_CR1_RXNEIE | USART_CR1_TXEIE | USART_CR1_PEIE | USART_CR1_TCIE)
#else
#  define USART_CR1_USED_INTS    (USART_CR1_RXNEIE | USART_CR1_TXEIE | USART_CR1_PEIE)
#endif

/************************************************************************************
 * Public Types
 ************************************************************************************/

/************************************************************************************
 * Public Data
 ************************************************************************************/

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/************************************************************************************
 * Public Functions Prototypes
 ************************************************************************************/

/************************************************************************************
 * Name: stm32_serial_get_uart
 *
 * Description:
 *   Get serial driver structure for STM32 USART
 *
 ************************************************************************************/

FAR uart_dev_t *stm32_serial_get_uart(int uart_num);

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_STM32H7_STM32_UART_H */
