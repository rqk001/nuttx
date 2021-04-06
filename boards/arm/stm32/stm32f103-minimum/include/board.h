/****************************************************************************
 * boards/arm/stm32/stm32f103-minimum/include/board.h
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

#ifndef __BOARDS_ARM_STM32_STM32F103_MINIMUM_INCLUDE_BOARD_H
#define __BOARDS_ARM_STM32_STM32F103_MINIMUM_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#ifndef __ASSEMBLY__
#  include <stdint.h>
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

/* On-board crystal frequency is 8MHz (HSE) */

#define STM32_BOARD_XTAL        8000000ul

/* PLL source is HSE/1, PLL multiplier is 9: PLL frequency is
 * 8MHz (XTAL) x 9 = 72MHz
 */

#define STM32_CFGR_PLLSRC       RCC_CFGR_PLLSRC
#define STM32_CFGR_PLLXTPRE     0
#define STM32_CFGR_PLLMUL       RCC_CFGR_PLLMUL_CLKx9
#define STM32_PLL_FREQUENCY     (9*STM32_BOARD_XTAL)

/* Use the PLL and set the SYSCLK source to be the PLL */

#define STM32_SYSCLK_SW         RCC_CFGR_SW_PLL
#define STM32_SYSCLK_SWS        RCC_CFGR_SWS_PLL
#define STM32_SYSCLK_FREQUENCY  STM32_PLL_FREQUENCY

/* AHB clock (HCLK) is SYSCLK (72MHz) */

#define STM32_RCC_CFGR_HPRE     RCC_CFGR_HPRE_SYSCLK
#define STM32_HCLK_FREQUENCY    STM32_PLL_FREQUENCY

/* APB2 clock (PCLK2) is HCLK (72MHz) */

#define STM32_RCC_CFGR_PPRE2    RCC_CFGR_PPRE2_HCLK
#define STM32_PCLK2_FREQUENCY   STM32_HCLK_FREQUENCY

/* APB2 timers 1 and 8 will receive PCLK2. */

#define STM32_APB2_TIM1_CLKIN   (STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM8_CLKIN   (STM32_PCLK2_FREQUENCY)

/* APB1 clock (PCLK1) is HCLK/2 (36MHz) */

#define STM32_RCC_CFGR_PPRE1    RCC_CFGR_PPRE1_HCLKd2
#define STM32_PCLK1_FREQUENCY   (STM32_HCLK_FREQUENCY/2)

/* APB1 timers 2-7 will be twice PCLK1 */

#define STM32_APB1_TIM2_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM3_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM4_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM5_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM6_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM7_CLKIN   (2*STM32_PCLK1_FREQUENCY)

/* USB divider -- Divide PLL clock by 1.5 */

#define STM32_CFGR_USBPRE       0

/* Timer Frequencies, if APBx is set to 1, frequency is same to APBx
 * otherwise frequency is 2xAPBx.
 * Note: TIM1,8 are on APB2, others on APB1
 */

#define BOARD_TIM1_FREQUENCY    STM32_HCLK_FREQUENCY
#define BOARD_TIM2_FREQUENCY    STM32_PCLK1_FREQUENCY
#define BOARD_TIM3_FREQUENCY    STM32_PCLK1_FREQUENCY
#define BOARD_TIM4_FREQUENCY    STM32_PCLK1_FREQUENCY
#define BOARD_TIM5_FREQUENCY    STM32_PCLK1_FREQUENCY
#define BOARD_TIM6_FREQUENCY    STM32_PCLK1_FREQUENCY
#define BOARD_TIM7_FREQUENCY    STM32_PCLK1_FREQUENCY
#define BOARD_TIM8_FREQUENCY    STM32_HCLK_FREQUENCY

/* SDIO dividers.  Note that slower clocking is required when DMA is disabled
 * in order to avoid RX overrun/TX underrun errors due to delayed responses
 * to service FIFOs in interrupt driven mode.  These values have not been
 * tuned!!!
 *
 * HCLK=72MHz, SDIOCLK=72MHz, SDIO_CK=HCLK/(178+2)=400 KHz
 */

#define SDIO_INIT_CLKDIV        (178 << SDIO_CLKCR_CLKDIV_SHIFT)

/* DMA ON:  HCLK=72 MHz, SDIOCLK=72MHz, SDIO_CK=HCLK/(2+2)=18 MHz
 * DMA OFF: HCLK=72 MHz, SDIOCLK=72MHz, SDIO_CK=HCLK/(3+2)=14.4 MHz
 */

#ifdef CONFIG_SDIO_DMA
#  define SDIO_MMCXFR_CLKDIV    (2 << SDIO_CLKCR_CLKDIV_SHIFT)
#else
#  define SDIO_MMCXFR_CLKDIV    (3 << SDIO_CLKCR_CLKDIV_SHIFT)
#endif

/* DMA ON:  HCLK=72 MHz, SDIOCLK=72MHz, SDIO_CK=HCLK/(1+2)=24 MHz
 * DMA OFF: HCLK=72 MHz, SDIOCLK=72MHz, SDIO_CK=HCLK/(3+2)=14.4 MHz
 */

#ifdef CONFIG_SDIO_DMA
#  define SDIO_SDXFR_CLKDIV     (1 << SDIO_CLKCR_CLKDIV_SHIFT)
#else
#  define SDIO_SDXFR_CLKDIV     (3 << SDIO_CLKCR_CLKDIV_SHIFT)
#endif

/* BUTTON definitions *******************************************************/

#define NUM_BUTTONS       2

#define BUTTON_USER1      0
#define BUTTON_USER2      1
#define BUTTON_USER1_BIT  (1 << BUTTON_USER1)
#define BUTTON_USER2_BIT  (1 << BUTTON_USER2)

/* LED definitions **********************************************************/

/* Define how many LEDs this board has (needed by userleds) */

#define BOARD_NLEDS       1

/* The board has only one controllable LED */

#define LED_STARTED       0  /* No LEDs */
#define LED_HEAPALLOCATE  1  /* LED1 on */
#define LED_IRQSENABLED   2  /* LED2 on */
#define LED_STACKCREATED  3  /* LED1 on */
#define LED_INIRQ         4  /* LED1 off */
#define LED_SIGNAL        5  /* LED2 on */
#define LED_ASSERTION     6  /* LED1 + LED2 */
#define LED_PANIC         7  /* LED1 / LED2 blinking */

/* PWM
 *
 * The STM32F103-Minimum has no real on-board PWM devices, but the board can
 * be configured to output a pulse train using TIM3 CH3 on PB0.
 *
 * Note: we don't need redefine GPIO_TIM3_CH3OUT because PB0 is not
 * remap pin.
 */

/* RGB LED
 *
 * R = TIM1 CH1 on PA8 | G = TIM2 CH2 on PA1 | B = TIM4 CH4 on PB9
 *
 * Note: Pin boards: GPIO_TIM1_CH1OUT ; GPIO_TIM2_CH2OUT ; GPIO_TIM4_CH4OUT
 */

#define RGBLED_RPWMTIMER   1
#define RGBLED_RPWMCHANNEL 1
#define RGBLED_GPWMTIMER   2
#define RGBLED_GPWMCHANNEL 2
#define RGBLED_BPWMTIMER   4
#define RGBLED_BPWMCHANNEL 4

/* Tone Driver **************************************************************/

#define BOARD_TONE_PWM_TIM         2   /* PWM timer for tone generation  */
#define BOARD_TONE_ONESHOT_TIM     3   /* Oneshot timer for note timings */
#define BOARD_TONE_ONESHOT_TIM_RES 10  /* Oneshot timer resolution (us)  */

/* NRF24L01 Driver **********************************************************/

/* Chip enable:  PB.1 */

#define GPIO_NRF24L01_CE  (GPIO_OUTPUT|GPIO_CNF_OUTPP|GPIO_MODE_50MHz|\
                           GPIO_OUTPUT_CLEAR|GPIO_PORTB|GPIO_PIN1)

/* IRQ line:  PA.0 */

#define GPIO_NRF24L01_IRQ (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_PORTA|GPIO_PIN0)

#define BOARD_NRF24L01_GPIO_CE     GPIO_NRF24L01_CE
#define BOARD_NRF24L01_GPIO_IRQ    GPIO_NRF24L01_IRQ

/* HCSR04 driver */

/* Pins config to use with HC-SR04 sensor */

#define GPIO_HCSR04_INT   (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_PORTA|GPIO_PIN0)
#define GPIO_HCSR04_TRIG  (GPIO_OUTPUT|GPIO_CNF_OUTPP|GPIO_MODE_50MHz|\
                           GPIO_OUTPUT_CLEAR|GPIO_PORTA|GPIO_PIN1)

#define BOARD_HCSR04_GPIO_INT  GPIO_HCSR04_INT
#define BOARD_HCSR04_GPIO_TRIG GPIO_HCSR04_TRIG
#define BOARD_HCSR04_FRTIMER   1    /* TIM1 as free running timer */

/* Pin for APDS-9960 sensor */

#define GPIO_APDS9960_INT (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_PORTA|GPIO_PIN0)

#define BOARD_APDS9960_GPIO_INT GPIO_APDS9960_INT

/* ZERO CROSS pin definition */

#define BOARD_ZEROCROSS_GPIO \
  (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_PORTA|GPIO_PIN0)

#endif /* __BOARDS_ARM_STM32_STM32F103_MINIMUM_INCLUDE_BOARD_H */
