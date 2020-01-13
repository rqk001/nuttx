/****************************************************************************
 * boards/arm/stm32l4/nucleo-l432kc/include/nucleo-l432kc.h
 *
 *   Copyright (C) 2016 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
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

#ifndef __BOARDS_ARM_STM32L4_NUCLEO_L432KC_INCLUDE_NUCLEO_L432KC_H
#define __BOARDS_ARM_STM32L4_NUCLEO_L432KC_INCLUDE_NUCLEO_L432KC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#ifndef __ASSEMBLY__
# include <stdint.h>
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#if 1
#  define HSI_CLOCK_CONFIG          /* HSI-16 clock configuration */
#elif 0
/* Make sure you installed one! */

#  define HSE_CLOCK_CONFIG          /* HSE with 8 MHz xtal */
#else
#  define MSI_CLOCK_CONFIG          /* MSI @ 4 MHz autotrimmed via LSE */
#endif

/* Clocking *****************************************************************/

#if defined(HSI_CLOCK_CONFIG)
/* The NUCLEOL432KC supports both HSE and LSE crystals (X2 and X3).
 * However, asshipped, the X3 crystal is not populated.  Therefore the
 * Nucleo-L432KC will need to run off the 16MHz HSI clock, or the 32khz-
 * synced MSI.
 *
 *   System Clock source           : PLL (HSI)
 *   SYSCLK(Hz)                    : 80000000      Determined by PLL
 *                                                 configuration
 *   HCLK(Hz)                      : 80000000     (STM32L4_RCC_CFGR_HPRE)
 *                                                (Max 80 MHz)
 *   AHB Prescaler                 : 1            (STM32L4_RCC_CFGR_HPRE)
 *                                                (Max 80 MHz)
 *   APB1 Prescaler                : 1            (STM32L4_RCC_CFGR_PPRE1)
 *                                                (Max 80 MHz)
 *   APB2 Prescaler                : 1            (STM32L4_RCC_CFGR_PPRE2)
 *                                                (Max 80 MHz)
 *   HSI Frequency(Hz)             : 16000000     (nominal)
 *   PLLM                          : 1            (STM32L4_PLLCFG_PLLM)
 *   PLLN                          : 10           (STM32L4_PLLCFG_PLLN)
 *   PLLP                          : 0            (STM32L4_PLLCFG_PLLP)
 *   PLLQ                          : 0            (STM32L4_PLLCFG_PLLQ)
 *   PLLR                          : 2            (STM32L4_PLLCFG_PLLR)
 *   PLLSAI1N                      : 12
 *   PLLSAI1Q                      : 4
 *   Flash Latency(WS)             : 4
 *   Prefetch Buffer               : OFF
 *   48MHz for USB OTG FS,         : Doable if required using PLLSAI1 or MSI
 *   RNG clock
 */

/* HSI - 16 MHz RC factory-trimmed
 * LSI - 32 KHz RC
 * MSI - variable up to 48 MHz, synchronized to LSE
 * HSE - not installed
 * LSE - 32.768 kHz installed
 */

#define STM32L4_HSI_FREQUENCY     16000000ul
#define STM32L4_LSI_FREQUENCY     32000
#define STM32L4_LSE_FREQUENCY     32768

#define STM32L4_BOARD_USEHSI      1

/* XXX sysclk mux = pllclk */

/* XXX pll source mux = hsi */

/* REVISIT: Trimming of the HSI and MSI is not yet supported. */

/* Main PLL Configuration.
 *
 * Formulae:
 *
 *   VCO input frequency        = PLL input clock frequency / PLLM,
 *                                1 <= PLLM <= 8
 *   VCO output frequency       = VCO input frequency × PLLN,
 *                                8 <= PLLN <= 86, frequency range 64 to
 *                                 344 MHz
 *   PLL output P (SAI3) clock frequency = VCO frequency / PLLP,
 *                                 PLLP = 7, or 17, or 0 to disable
 *   PLL output Q (48M1) clock frequency = VCO frequency / PLLQ,
 *                                 PLLQ = 2, 4, 6, or 8, or 0 to disable
 *   PLL output R (CLK)  clock frequency = VCO frequency / PLLR,
 *                                 PLLR = 2, 4, 6, or 8, or 0 to disable
 *
 * PLL output P is used for SAI
 * PLL output Q is used for OTG FS, SDMMC, RNG
 * PLL output R is used for SYSCLK
 * PLLP = 0 (not used)
 * PLLQ = 0 (not used)
 * PLLR = 2
 * PLLN = 10
 * PLLM = 1
 *
 * We will configure like this
 *
 *   PLL source is HSI
 *
 *   PLL_REF  = STM32L4_HSI_FREQUENCY / PLLM
 *            = 16,000,000 / 1
 *            = 16,000,000
 *
 *   PLL_VCO  = PLL_REF * PLLN
 *            = 16,000,000 * 10
 *            = 160,000,000
 *
 *   PLL_CLK  = PLL_VCO / PLLR
 *            = 160,000,000 / 2 = 80,000,000
 *   PLL_48M1 = disabled
 *   PLL_SAI3 = disabled
 *
 * ----------------------------------------
 *
 * PLLSAI1 Configuration
 *
 * The clock input and M divider are identical to the main PLL.
 * However the multiplier and postscalers are independent.
 * The PLLSAI1 is configured only if CONFIG_STM32L4_SAI1PLL is defined
 *
 *   SAI1VCO input frequency        = PLL input clock frequency
 *   SAI1VCO output frequency       = SAI1VCO input frequency × PLLSAI1N,
 *                                    8 <= PLLSAI1N <= 86, frequency range
 *                                    64 to 344 MHz
 *   SAI1PLL output P (SAI1) clock frequency = SAI1VCO frequency / PLLSAI1P,
 *                                    PLLP = 7, or 17, or 0 to disable
 *   SAI1PLL output Q (48M2) clock frequency = SAI1VCO frequency / PLLSAI1Q,
 *                                    PLLQ = 2, 4, 6, or 8, or 0 to disable
 *   SAI1PLL output R (ADC1) clock frequency = SAI1VCO frequency / PLLSAI1R,
 *                                    PLLR = 2, 4, 6, or 8, or 0 to disable
 *
 * We will configure like this
 *
 * PLLSAI1 disabled
 *
 * ----------------------------------------
 *
 * PLLSAI2 Configuration
 *
 * The clock input and M divider are identical to the main PLL.
 * However the multiplier and postscalers are independent.
 * The PLLSAI2 is configured only if CONFIG_STM32L4_SAI2PLL is defined
 *
 *   SAI2VCO input frequency        = PLL input clock frequency
 *   SAI2VCO output frequency       = SAI2VCO input frequency × PLLSAI2N,
 *                                    8 <= PLLSAI1N <= 86, frequency range
 *                                    64 to 344 MHz
 *   SAI2PLL output P (SAI2) clock frequency = SAI2VCO frequency / PLLSAI2P,
 *                                    PLLP = 7, or 17, or 0 to disable
 *   SAI2PLL output R (ADC2) clock frequency = SAI2VCO frequency / PLLSAI2R,
 *                                    PLLR = 2, 4, 6, or 8, or 0 to disable
 *
 * We will configure like this
 *
 * PLLSAI2 disabled
 *
 * ----------------------------------------
 *
 * TODO: The STM32L is a low power peripheral and all these clocks should be
 *       configurable at runtime.
 *
 * ----------------------------------------
 *
 * TODO These clock sources can be configured in Kconfig (this is not a
 *      board feature)
 *
 * USART1
 * USART2
 * USART3
 * UART4
 * UART5
 * LPUART1
 * I2C1
 * I2C3
 * LPTIM1
 * LPTIM2
 * SAI1
 * SAI2
 * CLK48
 * ADC
 * SWPMI
 * DFSDM
 */

/* prescaler common to all PLL inputs; will be 1 (XXX source is implicitly
 * as per comment above HSI)
 */

#define STM32L4_PLLCFG_PLLM             RCC_PLLCFG_PLLM(1)

/* 'main' PLL config; we use this to generate our system clock via the R
 *  output.  We set it up as 16 MHz / 1 * 10 / 2 = 80 MHz
 *
 * XXX NOTE:  currently the main PLL is implicitly turned on and is
 * implicitly the system clock; this should be configurable since not all
 * applications may want things done this way.
 */

#define STM32L4_PLLCFG_PLLN             RCC_PLLCFG_PLLN(10)
#define STM32L4_PLLCFG_PLLP             0
#undef  STM32L4_PLLCFG_PLLP_ENABLED
#define STM32L4_PLLCFG_PLLQ             RCC_PLLCFG_PLLQ_2
#define STM32L4_PLLCFG_PLLQ_ENABLED
#define STM32L4_PLLCFG_PLLR             RCC_PLLCFG_PLLR(2)
#define STM32L4_PLLCFG_PLLR_ENABLED

/* 'SAIPLL1' is used to generate the 48 MHz clock, since we can't
 * do that with the main PLL's N value.  We set N = 12, and enable
 * the Q output (ultimately for CLK48) with /4.  So,
 * 16 MHz / 1 * 12 / 4 = 48 MHz
 *
 * XXX NOTE:  currently the SAIPLL /must/ be explicitly selected in the
 * menuconfig, or else all this is a moot point, and the various 48 MHz
 * peripherals will not work (RNG at present).  I would suggest removing
 * that option from Kconfig altogether, and simply making it an option
 * that is selected via a #define here, like all these other params.
 */

#define STM32L4_PLLSAI1CFG_PLLN         RCC_PLLSAI1CFG_PLLN(12)
#define STM32L4_PLLSAI1CFG_PLLP         0
#undef  STM32L4_PLLSAI1CFG_PLLP_ENABLED
#define STM32L4_PLLSAI1CFG_PLLQ         RCC_PLLSAI1CFG_PLLQ_4
#define STM32L4_PLLSAI1CFG_PLLQ_ENABLED
#define STM32L4_PLLSAI1CFG_PLLR         0
#undef  STM32L4_PLLSAI1CFG_PLLR_ENABLED

/* 'SAIPLL2' is not used in this application */

#define STM32L4_PLLSAI2CFG_PLLN         RCC_PLLSAI2CFG_PLLN(8)
#define STM32L4_PLLSAI2CFG_PLLP         0
#undef  STM32L4_PLLSAI2CFG_PLLP_ENABLED
#define STM32L4_PLLSAI2CFG_PLLR         0
#undef  STM32L4_PLLSAI2CFG_PLLR_ENABLED

#define STM32L4_SYSCLK_FREQUENCY  80000000ul

/* CLK48 will come from PLLSAI1 (implicitly Q) */

#if defined(CONFIG_STM32L4_USBFS) || defined(CONFIG_STM32L4_RNG)
#  define STM32L4_USE_CLK48       1
#  define STM32L4_CLK48_SEL       RCC_CCIPR_CLK48SEL_PLLSAI1
#  define STM32L4_HSI48_SYNCSRC   SYNCSRC_NONE
#endif

/* enable the LSE oscillator, used automatically trim the MSI, and for RTC */

#define STM32L4_USE_LSE           1

/* AHB clock (HCLK) is SYSCLK (80MHz) */

#define STM32L4_RCC_CFGR_HPRE     RCC_CFGR_HPRE_SYSCLK      /* HCLK  = SYSCLK / 1 */
#define STM32L4_HCLK_FREQUENCY    STM32L4_SYSCLK_FREQUENCY
#define STM32L4_BOARD_HCLK        STM32L4_HCLK_FREQUENCY      /* Same as above, to satisfy compiler */

/* APB1 clock (PCLK1) is HCLK / 1 (80MHz) */

#define STM32L4_RCC_CFGR_PPRE1    RCC_CFGR_PPRE1_HCLK       /* PCLK1 = HCLK / 1 */
#define STM32L4_PCLK1_FREQUENCY   (STM32L4_HCLK_FREQUENCY / 1)

/* The timer clock frequencies are automatically defined by hardware.
 * If the APB prescaler equals 1, the timer clock frequencies are set to the
 * same frequency as that of the APB domain. Otherwise they are set to twice.
 *
 * REVISIT : this can be configured
 */

#define STM32L4_APB1_TIM2_CLKIN   (STM32L4_PCLK1_FREQUENCY)
#define STM32L4_APB1_TIM6_CLKIN   (STM32L4_PCLK1_FREQUENCY)
#define STM32L4_APB1_TIM7_CLKIN   (STM32L4_PCLK1_FREQUENCY)
#define STM32L4_APB1_LPTIM1_CLKIN (STM32L4_PCLK1_FREQUENCY)
#define STM32L4_APB1_LPTIM2_CLKIN (STM32L4_PCLK1_FREQUENCY)

/* APB2 clock (PCLK2) is HCLK (80MHz) */

#define STM32L4_RCC_CFGR_PPRE2    RCC_CFGR_PPRE2_HCLK       /* PCLK2 = HCLK / 1 */
#define STM32L4_PCLK2_FREQUENCY   (STM32L4_HCLK_FREQUENCY / 1)

/* The timer clock frequencies are automatically defined by hardware.
 * If the APB prescaler equals 1, the timer clock frequencies are set to the
 * same frequency as that of the APB domain. Otherwise they are set to twice.
 *
 * REVISIT : this can be configured
 */

#define STM32L4_APB2_TIM1_CLKIN   (STM32L4_PCLK2_FREQUENCY)
#define STM32L4_APB2_TIM15_CLKIN  (STM32L4_PCLK2_FREQUENCY)
#define STM32L4_APB2_TIM16_CLKIN  (STM32L4_PCLK2_FREQUENCY)

/* TODO SDMMC */

#elif defined(HSE_CLOCK_CONFIG)

/* Use the HSE */

#define STM32L4_BOARD_USEHSE      1

/* XXX sysclk mux = pllclk */

/* XXX pll source mux = hse */

/* Prescaler common to all PLL inputs */

#define STM32L4_PLLCFG_PLLM             RCC_PLLCFG_PLLM(1)

/* 'main' PLL config; we use this to generate our system clock */

#define STM32L4_PLLCFG_PLLN             RCC_PLLCFG_PLLN(20)
#define STM32L4_PLLCFG_PLLP             0
#undef  STM32L4_PLLCFG_PLLP_ENABLED
#define STM32L4_PLLCFG_PLLQ             0
#undef STM32L4_PLLCFG_PLLQ_ENABLED
#define STM32L4_PLLCFG_PLLR             RCC_PLLCFG_PLLR_2
#define STM32L4_PLLCFG_PLLR_ENABLED

/* 'SAIPLL1' is used to generate the 48 MHz clock */

#define STM32L4_PLLSAI1CFG_PLLN         RCC_PLLSAI1CFG_PLLN(12)
#define STM32L4_PLLSAI1CFG_PLLP         0
#undef  STM32L4_PLLSAI1CFG_PLLP_ENABLED
#define STM32L4_PLLSAI1CFG_PLLQ         RCC_PLLSAI1CFG_PLLQ_2
#define STM32L4_PLLSAI1CFG_PLLQ_ENABLED
#define STM32L4_PLLSAI1CFG_PLLR         0
#undef  STM32L4_PLLSAI1CFG_PLLR_ENABLED

/* 'SAIPLL2' is not used in this application */

#define STM32L4_PLLSAI2CFG_PLLN         RCC_PLLSAI2CFG_PLLN(8)
#define STM32L4_PLLSAI2CFG_PLLP         0
#undef  STM32L4_PLLSAI2CFG_PLLP_ENABLED
#define STM32L4_PLLSAI2CFG_PLLR         0
#undef  STM32L4_PLLSAI2CFG_PLLR_ENABLED

#define STM32L4_SYSCLK_FREQUENCY  80000000ul

/* Enable CLK48; get it from PLLSAI1 */

#if defined(CONFIG_STM32L4_USBFS) || defined(CONFIG_STM32L4_RNG)
#  define STM32L4_USE_CLK48       1
#  define STM32L4_CLK48_SEL       RCC_CCIPR_CLK48SEL_PLLSAI1
#  define STM32L4_HSI48_SYNCSRC   SYNCSRC_NONE
#endif

/* Enable LSE (for the RTC) */

#define STM32L4_USE_LSE           1

/* Configure the HCLK divisor (for the AHB bus, core, memory, and DMA */

#define STM32L4_RCC_CFGR_HPRE     RCC_CFGR_HPRE_SYSCLK      /* HCLK  = SYSCLK / 1 */
#define STM32L4_HCLK_FREQUENCY    STM32L4_SYSCLK_FREQUENCY
#define STM32L4_BOARD_HCLK        STM32L4_HCLK_FREQUENCY    /* Same as above, to satisfy compiler */

/* Configure the APB1 prescaler */

#define STM32L4_RCC_CFGR_PPRE1    RCC_CFGR_PPRE1_HCLK       /* PCLK1 = HCLK / 1 */
#define STM32L4_PCLK1_FREQUENCY   (STM32L4_HCLK_FREQUENCY / 1)

/* The timer clock frequencies are automatically defined by hardware.
 * If the APB prescaler equals 1, the timer clock frequencies are set to the
 * same frequency as that of the APB domain. Otherwise they are set to twice.
 *
 * REVISIT : this can be configured
 */

#define STM32L4_APB1_TIM2_CLKIN   (STM32L4_PCLK1_FREQUENCY)
#define STM32L4_APB1_TIM6_CLKIN   (STM32L4_PCLK1_FREQUENCY)
#define STM32L4_APB1_TIM7_CLKIN   (STM32L4_PCLK1_FREQUENCY)

/* Configure the APB2 prescaler */

#define STM32L4_RCC_CFGR_PPRE2    RCC_CFGR_PPRE2_HCLK       /* PCLK2 = HCLK / 1 */
#define STM32L4_PCLK2_FREQUENCY   (STM32L4_HCLK_FREQUENCY / 1)

/* The timer clock frequencies are automatically defined by hardware.
 * If the APB prescaler equals 1, the timer clock frequencies are set to the
 * same frequency as that of the APB domain. Otherwise they are set to twice.
 *
 * REVISIT : this can be configured
 */

#define STM32L4_APB2_TIM1_CLKIN   (STM32L4_PCLK2_FREQUENCY)
#define STM32L4_APB2_TIM15_CLKIN  (STM32L4_PCLK2_FREQUENCY)
#define STM32L4_APB2_TIM16_CLKIN  (STM32L4_PCLK2_FREQUENCY)

#elif defined(MSI_CLOCK_CONFIG)

/* Use the MSI; frequ = 4 MHz; autotrim from LSE */

#define STM32L4_BOARD_USEMSI      1
#define STM32L4_BOARD_MSIRANGE    RCC_CR_MSIRANGE_4M

/* XXX sysclk mux = pllclk */

/* XXX pll source mux = msi */

/* prescaler common to all PLL inputs */

#define STM32L4_PLLCFG_PLLM             RCC_PLLCFG_PLLM(1)

/* 'main' PLL config; we use this to generate our system clock */

#define STM32L4_PLLCFG_PLLN             RCC_PLLCFG_PLLN(40)
#define STM32L4_PLLCFG_PLLP             0
#undef  STM32L4_PLLCFG_PLLP_ENABLED
#define STM32L4_PLLCFG_PLLQ             0
#undef STM32L4_PLLCFG_PLLQ_ENABLED
#define STM32L4_PLLCFG_PLLR             RCC_PLLCFG_PLLR_2
#define STM32L4_PLLCFG_PLLR_ENABLED

/* 'SAIPLL1' is used to generate the 48 MHz clock */

#define STM32L4_PLLSAI1CFG_PLLN         RCC_PLLSAI1CFG_PLLN(24)
#define STM32L4_PLLSAI1CFG_PLLP         0
#undef  STM32L4_PLLSAI1CFG_PLLP_ENABLED
#define STM32L4_PLLSAI1CFG_PLLQ         RCC_PLLSAI1CFG_PLLQ_2
#define STM32L4_PLLSAI1CFG_PLLQ_ENABLED
#define STM32L4_PLLSAI1CFG_PLLR         0
#undef  STM32L4_PLLSAI1CFG_PLLR_ENABLED

/* 'SAIPLL2' is not used in this application */

#define STM32L4_PLLSAI2CFG_PLLN         RCC_PLLSAI2CFG_PLLN(8)
#define STM32L4_PLLSAI2CFG_PLLP         0
#undef  STM32L4_PLLSAI2CFG_PLLP_ENABLED
#define STM32L4_PLLSAI2CFG_PLLR         0
#undef  STM32L4_PLLSAI2CFG_PLLR_ENABLED

#define STM32L4_SYSCLK_FREQUENCY  80000000ul

/* Enable CLK48; get it from PLLSAI1 */

#if defined(CONFIG_STM32L4_USBFS) || defined(CONFIG_STM32L4_RNG)
#  define STM32L4_USE_CLK48       1
#  define STM32L4_CLK48_SEL       RCC_CCIPR_CLK48SEL_PLLSAI1
#  define STM32L4_HSI48_SYNCSRC   SYNCSRC_NONE
#endif

/* Enable LSE (for the RTC) */

#define STM32L4_USE_LSE           1

/* Configure the HCLK divisor (for the AHB bus, core, memory, and DMA */

#define STM32L4_RCC_CFGR_HPRE     RCC_CFGR_HPRE_SYSCLK      /* HCLK  = SYSCLK / 1 */
#define STM32L4_HCLK_FREQUENCY    STM32L4_SYSCLK_FREQUENCY
#define STM32L4_BOARD_HCLK        STM32L4_HCLK_FREQUENCY      /* Same as above, to satisfy compiler */

/* Configure the APB1 prescaler */

#define STM32L4_RCC_CFGR_PPRE1    RCC_CFGR_PPRE1_HCLK       /* PCLK1 = HCLK / 1 */
#define STM32L4_PCLK1_FREQUENCY   (STM32L4_HCLK_FREQUENCY / 1)

#define STM32L4_APB1_TIM2_CLKIN   (STM32L4_PCLK1_FREQUENCY)
#define STM32L4_APB1_TIM6_CLKIN   (STM32L4_PCLK1_FREQUENCY)
#define STM32L4_APB1_TIM7_CLKIN   (STM32L4_PCLK1_FREQUENCY)
#define STM32L4_APB1_LPTIM1_CLKIN (STM32L4_PCLK1_FREQUENCY)
#define STM32L4_APB1_LPTIM2_CLKIN (STM32L4_PCLK1_FREQUENCY)

/* Configure the APB2 prescaler */

#define STM32L4_RCC_CFGR_PPRE2    RCC_CFGR_PPRE2_HCLK       /* PCLK2 = HCLK / 1 */
#define STM32L4_PCLK2_FREQUENCY   (STM32L4_HCLK_FREQUENCY / 1)

#define STM32L4_APB2_TIM1_CLKIN   (STM32L4_PCLK2_FREQUENCY)
#define STM32L4_APB2_TIM15_CLKIN  (STM32L4_PCLK2_FREQUENCY)
#define STM32L4_APB2_TIM16_CLKIN  (STM32L4_PCLK2_FREQUENCY)

#endif

/* The timer clock frequencies are automatically defined by hardware. If the
 * APB prescaler equals 1, the timer clock frequencies are set to the same
 * frequency as that of the APB domain. Otherwise they are set to twice.
 * Note: TIM1,15,16 are on APB2, others on APB1
 */

#define BOARD_TIM1_FREQUENCY    STM32L4_HCLK_FREQUENCY
#define BOARD_TIM2_FREQUENCY    STM32L4_HCLK_FREQUENCY
#define BOARD_TIM6_FREQUENCY    STM32L4_HCLK_FREQUENCY
#define BOARD_TIM7_FREQUENCY    STM32L4_HCLK_FREQUENCY
#define BOARD_TIM15_FREQUENCY   STM32L4_HCLK_FREQUENCY
#define BOARD_TIM16_FREQUENCY   STM32L4_HCLK_FREQUENCY
#define BOARD_LPTIM1_FREQUENCY  STM32L4_HCLK_FREQUENCY
#define BOARD_LPTIM2_FREQUENCY  STM32L4_HCLK_FREQUENCY

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif  /* __BOARDS_ARM_STM32L4_NUCLEO_L432KC_INCLUDE_NUCLEO_L432KC_H */
