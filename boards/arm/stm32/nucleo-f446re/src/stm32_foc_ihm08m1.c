/****************************************************************************
 * boards/arm/stm32/nucleo-f446re/src/stm32_foc_ihm08m1.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include "stm32_ihm08m1.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define CURRENT_SAMPLE_TIME    ADC_SMPR_15
#define VBUS_SAMPLE_TIME       ADC_SMPR_15
#define POT_SAMPLE_TIME        ADC_SMPR_15

/* ADC1 channels used in this example */

#define ADC1_INJECTED  (CONFIG_MOTOR_FOC_SHUNTS)

#ifdef CONFIG_BOARD_STM32_IHM08M1_VBUS
#  define IHM08M1_VBUS 1
#else
#  define IHM08M1_VBUS 0
#endif

#ifdef CONFIG_BOARD_STM32_IHM08M1_POT
#  define IHM08M1_POT 1
#else
#  define IHM08M1_POT 0
#endif

#define ADC1_REGULAR   (IHM08M1_VBUS + IHM08M1_POT)
#define ADC1_NCHANNELS (ADC1_INJECTED + ADC1_REGULAR)

/* Check ADC1 configuration */

#if ADC1_INJECTED != CONFIG_STM32_ADC1_INJECTED_CHAN
#  error
#endif

#if CONFIG_STM32_ADC1_RESOLUTION != 0
#  error
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* FOC ADC configuration:
 *    - Current Phase V    -> ADC1 INJ1 -> ADC1_IN0  (PA0)
 *    - Current Phase U    -> ADC1 INJ2 -> ADC1_IN11 (PC1)
 *    - Current Phase W    -> ADC1 INJ3 -> ADC1_IN10 (PC0)
 *  optional:
 *    - VBUS               -> ADC1 REG  -> ADC1_IN1  (PA1)
 *    - POT                -> ADC1 REG  -> ADC1_IN4  (PA4)
 *
 * TIM1 PWM configuration:
 *    - Phase U high -> TIM1_CH1  (PA8)
 *    - Phase U low  -> TIM1_CH1N (PA7)
 *    - Phase V high -> TIM1_CH2  (PA9)
 *    - Phase V low  -> TIM1_CH2N (PB0)
 *    - Phase W high -> TIM1_CH3  (PA10)
 *    - Phase W low  -> TIM1_CH3N (PB1)
 *
 */

static uint8_t g_adc1_chan[] =
{
#ifdef CONFIG_BOARD_STM32_IHM08M1_VBUS
  1,                            /* ADC1 REG1 - VBUS */
#endif
#ifdef CONFIG_BOARD_STM32_IHM08M1_POT
  4,                            /* ADC1 REG - POT */
#endif
  0,                            /* ADC1 INJ1 - PHASE 1 */
#if CONFIG_MOTOR_FOC_SHUNTS > 1
  11,                           /* ADC1 INJ2 - PHASE 2 */
#endif
#if CONFIG_MOTOR_FOC_SHUNTS > 2
  10,                           /* ADC1 INJ3 - PHASE 3 */
#endif
};

static uint32_t g_adc1_pins[] =
{
#ifdef CONFIG_BOARD_STM32_IHM08M1_VBUS
  GPIO_ADC1_IN1,
#endif
#ifdef CONFIG_BOARD_STM32_IHM08M1_POT
  GPIO_ADC1_IN4,
#endif
  GPIO_ADC1_IN0,
#if CONFIG_MOTOR_FOC_SHUNTS > 1
  GPIO_ADC1_IN11,
#endif
#if CONFIG_MOTOR_FOC_SHUNTS > 2
  GPIO_ADC1_IN10
#endif
};

/* ADC1 sample time configuration */

static adc_channel_t g_adc1_stime[] =
{
#ifdef CONFIG_BOARD_STM32_IHM08M1_VBUS
  {
    .channel     = 1,
    .sample_time = VBUS_SAMPLE_TIME
  },
#endif
#ifdef CONFIG_BOARD_STM32_IHM08M1_POT
  {
    .channel     = 4,
    .sample_time = POT_SAMPLE_TIME
  },
#endif
  {
    .channel     = 0,
    .sample_time = CURRENT_SAMPLE_TIME
  },
#if CONFIG_MOTOR_FOC_SHUNTS > 1
  {
    .channel     = 11,
    .sample_time = CURRENT_SAMPLE_TIME
  },
#endif
#if CONFIG_MOTOR_FOC_SHUNTS > 2
  {
    .channel     = 10,
    .sample_time = CURRENT_SAMPLE_TIME
  },
#endif
};

/* Board specific ADC configuration for FOC */

static struct stm32_foc_adc_s g_adc_cfg =
{
  .chan  = g_adc1_chan,
  .pins  = g_adc1_pins,
  .stime = g_adc1_stime,
  .nchan = ADC1_NCHANNELS,
  .regch = ADC1_REGULAR,
  .intf  = 1
};

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_foc_setup
 *
 * Description:
 *   Initialize FOC driver.
 *
 *   This function should be call by board_app_initialize().
 *
 * Returned Value:
 *   0 on success, a negated errno value on failure
 *
 ****************************************************************************/

int stm32_foc_setup(void)
{
  return board_ihm08m1_initialize(&g_adc_cfg);
}
