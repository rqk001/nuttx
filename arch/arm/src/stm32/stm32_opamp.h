/************************************************************************************
 * arch/arm/src/stm32/stm32_opamp.h
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
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
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_STM32_STM32_OPAMP_H
#define __ARCH_ARM_SRC_STM32_STM32_OPAMP_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

#include "chip.h"

#ifdef CONFIG_STM32_OPAMP

#if defined(CONFIG_STM32_STM32F30XX)
#  error "OPAMP support for STM32F30XX not implemented yet"
#elif defined(CONFIG_STM32_STM32F33XX)
#  include "hardware/stm32f33xxx_opamp.h"
#endif

#include <nuttx/analog/opamp.h>

/************************************************************************************
 * Pre-processor definitions
 ************************************************************************************/

/* OPAMP operation mode */

#define OPAMP_MODE_STANDALONE 0
#define OPAMP_MODE_FOLLOWER 1
#define OPAMP_MODE_PGA 2

/* Timer controlled Mux mode */

#define OPAMP_MUX_DISABLE 0
#define OPAMP_MUX_ENABLE 1

/* User calibration  */

#define OPAMP_USERCAL_DISABLE 0
#define OPAMP_USERCAL_ENABLE  1

/* Default configuration */

#define OPAMP_MODE_DEFAULT    OPAMP_MODE_STANDALONE /* Standalone mode */
#define OPAMP_MUX_DEFAULT     OPAMP_MUX_DISABLE     /* MUX disabled */
#define OPAMP_USERCAL_DEFAULT OPAMP_USERCAL_DISABLE /* User calibration disabled */
#define OPAMP_GAIN_DEFAULT    OPAMP_GAIN_2          /* Gain in PGA mode = 2 */
#define OPAMP_LOCK_DEFAULT    OPAMP_LOCK_RW         /* Do not lock CSR register */

/************************************************************************************
 * Public Types
 ************************************************************************************/

/* CSR register lock state */

enum stm32_opamp_lock_e
{
  OPAMP_LOCK_RW,
  OPAMP_LOCK_RO
};

/* Gain in PGA mode */

enum stm32_opamp_gain_e
{
  OPAMP_GAIN_2,
  OPAMP_GAIN_4,
  OPAMP_GAIN_8,
  OPAMP_GAIN_2_VM0,
  OPAMP_GAIN_4_VM0,
  OPAMP_GAIN_8_VM0,
  OPAMP_GAIN_16_VM0,
  OPAMP_GAIN_2_VM1,
  OPAMP_GAIN_4_VM1,
  OPAMP_GAIN_8_VM1,
  OPAMP_GAIN_16_VM1
};

/* Input selection and secondary input selection use the same GPIOs */

#ifdef CONFIG_STM32_OPAMP1
enum stm32_opamp1_vpsel_e
{
  OPAMP1_VPSEL_PA7,
  OPAMP1_VPSEL_PA5,
  OPAMP1_VPSEL_PA3,
  OPAMP1_VPSEL_PA1
};

enum stm32_opamp1_vmsel_e
{
  OPAMP1_VMSEL_PC5,
  OPAMP1_VMSEL_PA3,
  OPAMP1_VMSEL_PGAMODE,
  OPAMP1_VMSEL_FOLLOWER,
};
#endif

#ifdef CONFIG_STM32_OPAMP2
enum stm32_opamp2_vpsel_e
{
#ifndef CONFIG_STM32_STM32F33XX
  /* TODO: STM32F303xB/C and STM32F358C devices only */
  OPAMP2_VPSEL_PD14,
#endif
  OPAMP2_VPSEL_PB14,
  OPAMP2_VPSEL_PB0,
  OPAMP2_VPSEL_PA7
};

enum stm32_opamp2_vmsel_e
{
  OPAMP2_VMSEL_PC5,
  OPAMP2_VMSEL_PA5,
  OPAMP2_VMSEL_PGAMODE,
  OPAMP2_VMSEL_FOLLOWER
};
#endif

#ifdef CONFIG_STM32_OPAMP3
enum stm32_opamp3_vpsel_e
{
  OPAMP3_VPSEL_PB13,
  OPAMP3_VPSEL_PA5,
  OPAMP3_VPSEL_PA1,
  OPAMP3_VPSEL_PB0
};

enum stm32_opamp3_vmsel_e
{
  OPAMP3_VMSEL_PB10,
  OPAMP3_VMSEL_PB2,
  OPAMP3_VMSEL_PGAMODE,
  OPAMP3_VMSEL_FOLLOWER
};
#endif

#ifdef CONFIG_STM32_OPAMP4
enum stm32_opamp4_vpsel_e
{
  OPAMP4_VPSEL_PD11,
  OPAMP4_VPSEL_PB11,
  OPAMP4_VPSEL_PA4,
  OPAMP4_VPSEL_PB13
};

enum stm32_opamp4_vmsel_e
{
  OPAMP4_VMSEL_PB10,
  OPAMP4_VMSEL_PD8,
  OPAMP4_VMSEL_PGAMODE,
  OPAMP4_VMSEL_FOLLOWER
};
#endif

/************************************************************************************
 * Public Function Prototypes
 ************************************************************************************/

#ifndef __ASSEMBLY__
#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
* Name: stm32_opampinitialize
*
* Description:
*   Initialize the OPAMP.
*
* Input Parameters:
*   intf - The OPAMP interface number.
*
* Returned Value:
*   Valid OPAMP device structure reference on success; a NULL on failure.
*
* Assumptions:
*   1. Clock to the OPAMP block has enabled,
*   2. Board-specific logic has already configured
*
****************************************************************************/

FAR struct opamp_dev_s* stm32_opampinitialize(int intf);

#undef EXTERN
#ifdef __cplusplus
}
#endif
#endif /* __ASSEMBLY__ */

#endif /* CONFIG_STM32_OPAMP */
#endif /* __ARCH_ARM_SRC_STM32_STM32_OPAMP_H */
