/****************************************************************************
 * boards/arm/stm32/nucleo-f207zg/include/board.h
 * include/arch/board/board.h
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
 *   Author: Mateusz Szafoni <raiden00@railab.me>
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

#ifndef __BOARDS_ARM_STM32_NUCLEOF207ZG_INCLUDE_BOARD_H
#define __BOARDS_ARM_STM32_NUCLEOF207ZG_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#ifndef __ASSEMBLY__
#  include <stdint.h>
#  include <stdbool.h>
#endif

#ifdef __KERNEL__
#  include "stm32.h"
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

/* HSI - 16 MHz RC factory-trimmed
 * LSI - 32 KHz RC
 * HSE - 8 MHz from MCO output of ST-LINK
 * LSE - 32.768 kHz
 */

#define STM32_BOARD_XTAL        8000000ul

#define STM32_HSI_FREQUENCY     16000000ul
#define STM32_LSI_FREQUENCY     32000
#define STM32_HSE_FREQUENCY     STM32_BOARD_XTAL
#define STM32_LSE_FREQUENCY     32768            /* X2 on board */

/* Main PLL Configuration.
 *
 * Formulae:
 *
 *   VCO input frequency        = PLL input clock frequency / PLLM, 2 <= PLLM <= 63
 *   VCO output frequency       = VCO input frequency × PLLN,       50 <= PLLN <= 432
 *   PLL output clock frequency = VCO frequency / PLLP,             PLLP = 2, 4, 6, or 8
 *   USB OTG FS clock frequency = VCO frequency / PLLQ,             2 <= PLLQ <= 15
 *
 * We will configure like this
 *
 *   PLL source is HSE
 *   PLL_VCO = (STM32_HSE_FREQUENCY / PLLM) * PLLN
 *           = (8,000,000 / 2) * 100
 *           = 400,000,000
 *   SYSCLK  = PLL_VCO / PLLP
 *           = 400,000,000 / 4 = 100,000,000
 *   RNG Clock
 *           = PLL_VCO / PLLQ
 *           = 400,000,000 / 8 = 50,000,000
 *
 */

#define STM32_PLLCFG_PLLM       RCC_PLLCFG_PLLM(2)
#define STM32_PLLCFG_PLLN       RCC_PLLCFG_PLLN(100)
#define STM32_PLLCFG_PLLP       RCC_PLLCFG_PLLP_4
#define STM32_PLLCFG_PLLQ       RCC_PLLCFG_PLLQ(8)

#define STM32_SYSCLK_FREQUENCY  100000000ul

/* AHB clock (HCLK) is SYSCLK (100MHz) */

#define STM32_RCC_CFGR_HPRE     RCC_CFGR_HPRE_SYSCLK      /* HCLK  = SYSCLK / 1 */
#define STM32_HCLK_FREQUENCY    STM32_SYSCLK_FREQUENCY
#define STM32_BOARD_HCLK        STM32_HCLK_FREQUENCY      /* Same as above, to satisfy compiler */

/* APB1 clock (PCLK1) is HCLK/2 (25MHz) */

#define STM32_RCC_CFGR_PPRE1    RCC_CFGR_PPRE1_HCLKd4     /* PCLK1 = HCLK / 4 */
#define STM32_PCLK1_FREQUENCY   (STM32_HCLK_FREQUENCY/4)

/* APB2 clock (PCLK2) is HCLK/2 (50MHz) */

#define STM32_RCC_CFGR_PPRE2    RCC_CFGR_PPRE2_HCLK       /* PCLK2 = HCLK / 2 */
#define STM32_PCLK2_FREQUENCY   (STM32_HCLK_FREQUENCY/2)

/* Timers driven from APB2 will be twice PCLK2 (100Mhz) */

#define STM32_APB2_TIM1_CLKIN   (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM8_CLKIN   (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM9_CLKIN   (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM10_CLKIN  (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM11_CLKIN  (2*STM32_PCLK2_FREQUENCY)

/* Timers driven from APB1 will be twice PCLK1 (50MHz) */

#define STM32_APB1_TIM2_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM3_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM4_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM5_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM6_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM7_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM12_CLKIN  (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM13_CLKIN  (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM14_CLKIN  (2*STM32_PCLK1_FREQUENCY)

/* LED definitions **********************************************************/
/* The Nucleo-144 board has numerous LEDs but only three, LD1 a Green LED, LD2 a Blue
 * LED and LD3 a Red LED, that can be controlled by software. The following
 * definitions assume the default Solder Bridges are installed.
 *
 * If CONFIG_ARCH_LEDS is not defined, then the user can control the LEDs in any way.
 * The following definitions are used to access individual LEDs.
 */

/* LED index values for use with board_userled() */

#define BOARD_LED1        0
#define BOARD_LED2        1
#define BOARD_LED3        2
#define BOARD_NLEDS       3

#define BOARD_LED_GREEN   BOARD_LED1
#define BOARD_LED_BLUE    BOARD_LED2
#define BOARD_LED_RED     BOARD_LED3

/* LED bits for use with board_userled_all() */

#define BOARD_LED1_BIT    (1 << BOARD_LED1)
#define BOARD_LED2_BIT    (1 << BOARD_LED2)
#define BOARD_LED3_BIT    (1 << BOARD_LED3)

/* If CONFIG_ARCH_LEDS is defined, the usage by the board port is defined in
 * include/board.h and src/stm32_leds.c. The LEDs are used to encode OS-related
 * events as follows:
 *
 *
 *   SYMBOL                     Meaning                      LED state
 *                                                        Red   Green Blue
 *   ----------------------  --------------------------  ------ ------ ----*/

#define LED_STARTED        0 /* NuttX has been started   OFF    OFF   OFF  */
#define LED_HEAPALLOCATE   1 /* Heap has been allocated  OFF    OFF   ON   */
#define LED_IRQSENABLED    2 /* Interrupts enabled       OFF    ON    OFF  */
#define LED_STACKCREATED   3 /* Idle stack created       OFF    ON    ON   */
#define LED_INIRQ          4 /* In an interrupt          N/C    N/C   GLOW */
#define LED_SIGNAL         5 /* In a signal handler      N/C    GLOW  N/C  */
#define LED_ASSERTION      6 /* An assertion failed      GLOW   N/C   GLOW */
#define LED_PANIC          7 /* The system has crashed   Blink  OFF   N/C  */
#define LED_IDLE           8 /* MCU is is sleep mode     ON     OFF   OFF  */

/* Button definitions *******************************************************/
/* The NUCLEO board supports one button:  Pushbutton B1, labeled "User", is
 * connected to GPIO PC13.  A high value will be sensed when the button is depressed.
 */

#define BUTTON_USER      0
#define NUM_BUTTONS      1

#define BUTTON_USER_BIT  (1 << BUTTON_USER)

/* Alternate function pin selections ****************************************/
/* USART3 (Nucleo Virtual Console) */

#define GPIO_USART3_RX     GPIO_USART3_RX_3  /* PD9 */
#define GPIO_USART3_TX     GPIO_USART3_TX_3  /* PD8 */

/* PWM configuration ********************************************************/

/* TIM1 PWM */

#define GPIO_TIM1_CH1OUT  GPIO_TIM1_CH1OUT_2  /* PE9 */
#define GPIO_TIM1_CH1NOUT GPIO_TIM1_CH1N_3    /* PE8 */
#define GPIO_TIM1_CH2OUT  GPIO_TIM1_CH2OUT_2  /* PE11 */
#define GPIO_TIM1_CH2NOUT GPIO_TIM1_CH2N_3    /* PE10 */
#define GPIO_TIM1_CH3OUT  GPIO_TIM1_CH3OUT_2  /* PE13 */
#define GPIO_TIM1_CH3NOUT GPIO_TIM1_CH3N_3    /* PE12 */

/* DMA channels *************************************************************/
/* ADC */

#define ADC1_DMA_CHAN DMAMAP_ADC1_1

#endif /* __BOARDS_ARM_STM32_NUCLEO_F207ZG_INCLUDE_BOARD_H */
