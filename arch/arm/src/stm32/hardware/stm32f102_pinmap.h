/****************************************************************************
 * arch/arm/src/stm32/hardware/stm32f102_pinmap.h
 *
 *   Copyright (C) 2013 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *           Laurent Latil <laurent@latil.nom.fr>
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
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_STM32_HARDWARE_STM32F102_PINMAP_H
#define __ARCH_ARM_SRC_STM32_HARDWARE_STM32F102_PINMAP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Alternate Pin Functions: */

#define GPIO_ADC12_IN0          (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#define GPIO_ADC12_IN1          (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN1)
#define GPIO_ADC12_IN2          (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN2)
#define GPIO_ADC12_IN3          (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN3)
#define GPIO_ADC12_IN4          (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN4)
#define GPIO_ADC12_IN5          (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN5)
#define GPIO_ADC12_IN6          (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN6)
#define GPIO_ADC12_IN7          (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN7)
#define GPIO_ADC12_IN8          (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN0)
#define GPIO_ADC12_IN9          (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN1)
#define GPIO_ADC12_IN10         (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN0)
#define GPIO_ADC12_IN11         (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN1)
#define GPIO_ADC12_IN12         (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN2)
#define GPIO_ADC12_IN13         (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN3)
#define GPIO_ADC12_IN14         (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN4)
#define GPIO_ADC12_IN15         (GPIO_INPUT|GPIO_CNF_ANALOGIN|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN5)

#if defined(CONFIG_STM32_I2C1_REMAP)
#  define GPIO_I2C1_SCL         (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN8)
#  define GPIO_I2C1_SDA         (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN9)
#else
#  define GPIO_I2C1_SCL         (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN6)
#  define GPIO_I2C1_SDA         (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN7)
#endif
#define GPIO_I2C1_SMBA          (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN5)

#define GPIO_I2C2_SCL           (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN10)
#define GPIO_I2C2_SDA           (GPIO_ALT|GPIO_CNF_AFOD|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN11)
#define GPIO_I2C2_SMBA          (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN12)

#define GPIO_MCO                (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN8)

#if defined(CONFIG_STM32_SPI1_REMAP)
#  define GPIO_SPI1_NSS         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_SPI1_SCK         (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN3)
#  define GPIO_SPI1_MISO        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN4)
#  define GPIO_SPI1_MOSI        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN5)
#else
#  define GPIO_SPI1_NSS         (GPIO_INPUT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN4)
#  define GPIO_SPI1_SCK         (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN5)
#  define GPIO_SPI1_MISO        (GPIO_INPUT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN6)
#  define GPIO_SPI1_MOSI        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN7)
#endif

#define GPIO_SPI2_NSS           (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN12)
#define GPIO_SPI2_SCK           (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN13)
#define GPIO_SPI2_MISO          (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN14)
#define GPIO_SPI2_MOSI          (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN15)

#if defined(CONFIG_STM32_TIM2_FULL_REMAP)
#  define GPIO_TIM2_ETR         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH1IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH1OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH2IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN3)
#  define GPIO_TIM2_CH2OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN3)
#  define GPIO_TIM2_CH3IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN10)
#  define GPIO_TIM2_CH3OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN10)
#  define GPIO_TIM2_CH4IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN11)
#  define GPIO_TIM2_CH4OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN11)
#elif defined(CONFIG_STM32_TIM2_PARTIAL_REMAP_1)
#  define GPIO_TIM2_ETR         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH1IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH1OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN15)
#  define GPIO_TIM2_CH2IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN3)
#  define GPIO_TIM2_CH2OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN3)
#  define GPIO_TIM2_CH3IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN2)
#  define GPIO_TIM2_CH3OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN2)
#  define GPIO_TIM2_CH4IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN3)
#  define GPIO_TIM2_CH4OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN3)
#elif defined(CONFIG_STM32_TIM2_PARTIAL_REMAP_2)
#  define GPIO_TIM2_ETR         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH1IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH1OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH2IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN1)
#  define GPIO_TIM2_CH2OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN1)
#  define GPIO_TIM2_CH3IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN10)
#  define GPIO_TIM2_CH3OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN10)
#  define GPIO_TIM2_CH4IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN11)
#  define GPIO_TIM2_CH4OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN11)
#else
#  define GPIO_TIM2_ETR         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH1IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH1OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_TIM2_CH2IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN1)
#  define GPIO_TIM2_CH2OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN1)
#  define GPIO_TIM2_CH3IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN2)
#  define GPIO_TIM2_CH3OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN2)
#  define GPIO_TIM2_CH4IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN3)
#  define GPIO_TIM2_CH4OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN3)
#endif

#if defined(CONFIG_STM32_TIM3_FULL_REMAP)
#  define GPIO_TIM3_CH1IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN6)
#  define GPIO_TIM3_CH1OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTC|GPIO_PIN6)
#  define GPIO_TIM3_CH2IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN7)
#  define GPIO_TIM3_CH2OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTC|GPIO_PIN7)
#  define GPIO_TIM3_CH3IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN8)
#  define GPIO_TIM3_CH3OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTC|GPIO_PIN8)
#  define GPIO_TIM3_CH4IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN9)
#  define GPIO_TIM3_CH4OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTC|GPIO_PIN9)
#elif defined(CONFIG_STM32_TIM3_PARTIAL_REMAP)
#  define GPIO_TIM3_CH1IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN4)
#  define GPIO_TIM3_CH1OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN4)
#  define GPIO_TIM3_CH2IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN5)
#  define GPIO_TIM3_CH2OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN5)
#  define GPIO_TIM3_CH3IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN0)
#  define GPIO_TIM3_CH3OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN0)
#  define GPIO_TIM3_CH4IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN1)
#  define GPIO_TIM3_CH4OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN1)
#else
#  define GPIO_TIM3_CH1IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN6)
#  define GPIO_TIM3_CH1OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN6)
#  define GPIO_TIM3_CH2IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN7)
#  define GPIO_TIM3_CH2OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN7)
#  define GPIO_TIM3_CH3IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN0)
#  define GPIO_TIM3_CH3OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN0)
#  define GPIO_TIM3_CH4IN       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN1)
#  define GPIO_TIM3_CH4OUT      (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN1)
#endif
#define GPIO_TIM3_ETR           (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN2)

#if defined(CONFIG_STM32_TIM4_FULL_REMAP)
#  define GPIO_TIM4_CH1IN         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN12)
#  define GPIO_TIM4_CH1OUT        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTD|GPIO_PIN12)
#  define GPIO_TIM4_CH2IN         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN13)
#  define GPIO_TIM4_CH2OUT        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTD|GPIO_PIN13)
#  define GPIO_TIM4_CH3IN         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN14)
#  define GPIO_TIM4_CH3OUT        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTD|GPIO_PIN14)
#  define GPIO_TIM4_CH4IN         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN15)
#  define GPIO_TIM4_CH4OUT        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTD|GPIO_PIN15)
#else
#  define GPIO_TIM4_CH1IN         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN6)
#  define GPIO_TIM4_CH1OUT        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN6)
#  define GPIO_TIM4_CH2IN         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN7)
#  define GPIO_TIM4_CH2OUT        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN7)
#  define GPIO_TIM4_CH3IN         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN8)
#  define GPIO_TIM4_CH3OUT        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN8)
#  define GPIO_TIM4_CH4IN         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN9)
#  define GPIO_TIM4_CH4OUT        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN9)
#endif

/* USARTS */

#define GPIO_USART1_CTS         (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN11)
#define GPIO_USART1_RTS         (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN12)
#define GPIO_USART1_CK          (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN8)
#if defined(CONFIG_STM32_USART1_REMAP)
#  define GPIO_USART1_TX        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN6)
#  define GPIO_USART1_RX        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN7)
#else
#  define GPIO_USART1_TX        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN9)
#  define GPIO_USART1_RX        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN10)
#endif

#if defined(CONFIG_STM32_USART2_REMAP)
#  define GPIO_USART2_CTS        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN3)
#  define GPIO_USART2_RTS       (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTD|GPIO_PIN4)
#  define GPIO_USART2_TX        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTD|GPIO_PIN5)
#  define GPIO_USART2_RX        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN6)
#  define GPIO_USART2_CK        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTD|GPIO_PIN7)
#else
#  define GPIO_USART2_CTS       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN0)
#  define GPIO_USART2_RTS       (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN1)
#  define GPIO_USART2_TX        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN2)
#  define GPIO_USART2_RX        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTA|GPIO_PIN3)
#  define GPIO_USART2_CK        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN4)
#endif

#if defined(CONFIG_STM32_USART3_FULL_REMAP)
#  define GPIO_USART3_TX        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTD|GPIO_PIN8)
#  define GPIO_USART3_RX        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN9)
#  define GPIO_USART3_CK        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTD|GPIO_PIN10)
#  define GPIO_USART3_CTS        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN11)
#  define GPIO_USART3_RTS       (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTD|GPIO_PIN12)
#elif defined(CONFIG_STM32_USART3_PARTIAL_REMAP)
#  define GPIO_USART3_TX        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTC|GPIO_PIN10)
#  define GPIO_USART3_RX        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTC|GPIO_PIN11)
#  define GPIO_USART3_CK        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTC|GPIO_PIN12)
#  define GPIO_USART3_CTS       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN13)
#  define GPIO_USART3_RTS       (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN14)
#else
#  define GPIO_USART3_TX        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN10)
#  define GPIO_USART3_RX        (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN11)
#  define GPIO_USART3_CK        (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN12)
#  define GPIO_USART3_CTS       (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTB|GPIO_PIN13)
#  define GPIO_USART3_RTS       (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN14)
#endif

#define GPIO_WKUP               (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN0)

/* These GPIOs are shared with JTAG / SWD. */

#if defined(CONFIG_STM32_JTAG_DISABLE)
#  define GPIO_PA13               (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN13)
#  define GPIO_PA14               (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN14)
#endif
#if defined (CONFIG_STM32_JTAG_SW_ENABLE) || defined(CONFIG_STM32_JTAG_NOJNTRST_ENABLE) || defined(CONFIG_STM32_JTAG_DISABLE)
#    define GPIO_PB4                (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN4)
#    if defined (CONFIG_STM32_JTAG_SW_ENABLE) || defined(CONFIG_STM32_JTAG_DISABLE)
#      define GPIO_PA15               (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTA|GPIO_PIN15)
#      define GPIO_PB3                (GPIO_ALT|GPIO_CNF_AFPP|GPIO_MODE_50MHz|GPIO_PORTB|GPIO_PIN3)
#    endif
#endif

#endif /* __ARCH_ARM_SRC_STM32_HARDWARE_STM32F102_PINMAP_H */
