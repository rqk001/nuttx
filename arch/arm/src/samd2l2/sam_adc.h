/****************************************************************************
 * arch/arm/src/samd2l2/sam_adc.h
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

#ifndef __ARCH_ARM_SRC_SAMD2L2_SAM_ADC_H
#define __ARCH_ARM_SRC_SAMD2L2_SAM_ADC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>

#include "sam_config.h"
#include "sam_port.h"

#if defined(CONFIG_ARCH_FAMILY_SAMD20) || defined(CONFIG_ARCH_FAMILY_SAMD21)
#  include "hardware/samd_adc.h"
#elif defined(CONFIG_ARCH_FAMILY_SAML21)
#  include "hardware/saml_adc.h"
#else
#  error Unrecognized SAMD/L architecture
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Name: sam_adcinitialize
 *
 * Description:
 *   Initialize the ADC. See sam_adc.c for more details.
 *
 * Input Parameters:
 *   genclk      - Number of the Clock Generator to use.
 *
 * Returned Value:
 *   Valid ADC device structure reference on success; a NULL on failure
 *
 ****************************************************************************/

struct adc_dev_s;
struct adc_dev_s *sam_adcinitialize(int genclk);

#undef EXTERN
#if defined(__cplusplus)
}
#endif
#endif /* __ARCH_ARM_SRC_SAMD2L2_SAM_ADC_H */
