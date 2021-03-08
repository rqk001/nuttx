/*******************************************************************************************************************************
 * arch/arm/src/efm32/hardware/efm32_rmu.h
 *
 *  Copyright 2014 Silicon Laboratories, Inc. http://www.silabs.com</b>
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.@n
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.@n
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Silicon Laboratories, Inc.
 * has no obligation to support this Software. Silicon Laboratories, Inc. is
 * providing the Software "AS IS", with no express or implied warranties of any
 * kind, including, but not limited to, any implied warranties of
 * merchantability or fitness for any particular purpose or warranties against
 * infringement of any proprietary rights of a third party.
 *
 * Silicon Laboratories, Inc. will not be liable for any consequential,
 * incidental, or special damages, or any other relief, or for any claim by
 * any third party, arising from your use of this Software.
 *
 *   Copyright (C) 2014 Pierre-noel Bouteville . All rights reserved.
 *   Copyright (C) 2014 Gregory Nutt. All rights reserved.
 *   Authors: Pierre-noel Bouteville <pnb990@gmail.com>
 *            Gregory Nutt <gnutt@nuttx.org>
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
 *******************************************************************************************************************************/

#ifndef __ARCH_ARM_SRC_EFM32_CHIP_EFM32_RMU_H
#define __ARCH_ARM_SRC_EFM32_CHIP_EFM32_RMU_H

/*******************************************************************************************************************************
 * Included Files
 *******************************************************************************************************************************/

#include <nuttx/config.h>
#include "hardware/efm32_memorymap.h"

#if !defined(CONFIG_EFM32_EFM32GG)
#  warning This is the EFM32GG header file; Review/modification needed for this architecture
#endif

/*******************************************************************************************************************************
 * Pre-processor Definitions
 *******************************************************************************************************************************/
/* RMU Register Offsets ********************************************************************************************************/

#define EFM32_RMU_CTRL_OFFSET                 0x0000  /* Control Register */
#define EFM32_RMU_RSTCAUSE_OFFSET             0x0004  /* Reset Cause Register */
#define EFM32_RMU_CMD_OFFSET                  0x0008  /* Command Register */

/* RMU Register Addresses ******************************************************************************************************/

#define EFM32_RMU_CTRL                        (EFM32_RMU_BASE+EFM32_RMU_CTRL_OFFSET)
#define EFM32_RMU_RSTCAUSE                    (EFM32_RMU_BASE+EFM32_RMU_RSTCAUSE_OFFSET)
#define EFM32_RMU_CMD                         (EFM32_RMU_BASE+EFM32_RMU_CMD_OFFSET)

/* RMU Register Bit Field Definitions ******************************************************************************************/

/* Bit fields for RMU CTRL */

#define _RMU_CTRL_RESETVALUE                  0x00000002UL                        /**< Default value for RMU_CTRL */
#define _RMU_CTRL_MASK                        0x00000003UL                        /**< Mask for RMU_CTRL */

#define RMU_CTRL_LOCKUPRDIS                   (0x1UL << 0)                        /**< Lockup Reset Disable */
#define _RMU_CTRL_LOCKUPRDIS_SHIFT            0                                   /**< Shift value for RMU_LOCKUPRDIS */
#define _RMU_CTRL_LOCKUPRDIS_MASK             0x1UL                               /**< Bit mask for RMU_LOCKUPRDIS */
#define _RMU_CTRL_LOCKUPRDIS_DEFAULT          0x00000000UL                        /**< Mode DEFAULT for RMU_CTRL */
#define RMU_CTRL_LOCKUPRDIS_DEFAULT           (_RMU_CTRL_LOCKUPRDIS_DEFAULT << 0) /**< Shifted mode DEFAULT for RMU_CTRL */
#define RMU_CTRL_BURSTEN                      (0x1UL << 1)                        /**< Backup domain reset enable */
#define _RMU_CTRL_BURSTEN_SHIFT               1                                   /**< Shift value for RMU_BURSTEN */
#define _RMU_CTRL_BURSTEN_MASK                0x2UL                               /**< Bit mask for RMU_BURSTEN */
#define _RMU_CTRL_BURSTEN_DEFAULT             0x00000001UL                        /**< Mode DEFAULT for RMU_CTRL */
#define RMU_CTRL_BURSTEN_DEFAULT              (_RMU_CTRL_BURSTEN_DEFAULT << 1)    /**< Shifted mode DEFAULT for RMU_CTRL */

/* Bit fields for RMU RSTCAUSE */

#define _RMU_RSTCAUSE_RESETVALUE              0x00000000UL                               /**< Default value for RMU_RSTCAUSE */
#define _RMU_RSTCAUSE_MASK                    0x0000FFFFUL                               /**< Mask for RMU_RSTCAUSE */

#define RMU_RSTCAUSE_PORST                    (0x1UL << 0)                               /**< Power On Reset */
#define _RMU_RSTCAUSE_PORST_SHIFT             0                                          /**< Shift value for RMU_PORST */
#define _RMU_RSTCAUSE_PORST_MASK              0x1UL                                      /**< Bit mask for RMU_PORST */
#define _RMU_RSTCAUSE_PORST_DEFAULT           0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_PORST_DEFAULT            (_RMU_RSTCAUSE_PORST_DEFAULT << 0)         /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BODUNREGRST              (0x1UL << 1)                               /**< Brown Out Detector Unregulated Domain Reset */
#define _RMU_RSTCAUSE_BODUNREGRST_SHIFT       1                                          /**< Shift value for RMU_BODUNREGRST */
#define _RMU_RSTCAUSE_BODUNREGRST_MASK        0x2UL                                      /**< Bit mask for RMU_BODUNREGRST */
#define _RMU_RSTCAUSE_BODUNREGRST_DEFAULT     0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BODUNREGRST_DEFAULT      (_RMU_RSTCAUSE_BODUNREGRST_DEFAULT << 1)   /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BODREGRST                (0x1UL << 2)                               /**< Brown Out Detector Regulated Domain Reset */
#define _RMU_RSTCAUSE_BODREGRST_SHIFT         2                                          /**< Shift value for RMU_BODREGRST */
#define _RMU_RSTCAUSE_BODREGRST_MASK          0x4UL                                      /**< Bit mask for RMU_BODREGRST */
#define _RMU_RSTCAUSE_BODREGRST_DEFAULT       0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BODREGRST_DEFAULT        (_RMU_RSTCAUSE_BODREGRST_DEFAULT << 2)     /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_EXTRST                   (0x1UL << 3)                               /**< External Pin Reset */
#define _RMU_RSTCAUSE_EXTRST_SHIFT            3                                          /**< Shift value for RMU_EXTRST */
#define _RMU_RSTCAUSE_EXTRST_MASK             0x8UL                                      /**< Bit mask for RMU_EXTRST */
#define _RMU_RSTCAUSE_EXTRST_DEFAULT          0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_EXTRST_DEFAULT           (_RMU_RSTCAUSE_EXTRST_DEFAULT << 3)        /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_WDOGRST                  (0x1UL << 4)                               /**< Watchdog Reset */
#define _RMU_RSTCAUSE_WDOGRST_SHIFT           4                                          /**< Shift value for RMU_WDOGRST */
#define _RMU_RSTCAUSE_WDOGRST_MASK            0x10UL                                     /**< Bit mask for RMU_WDOGRST */
#define _RMU_RSTCAUSE_WDOGRST_DEFAULT         0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_WDOGRST_DEFAULT          (_RMU_RSTCAUSE_WDOGRST_DEFAULT << 4)       /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_LOCKUPRST                (0x1UL << 5)                               /**< LOCKUP Reset */
#define _RMU_RSTCAUSE_LOCKUPRST_SHIFT         5                                          /**< Shift value for RMU_LOCKUPRST */
#define _RMU_RSTCAUSE_LOCKUPRST_MASK          0x20UL                                     /**< Bit mask for RMU_LOCKUPRST */
#define _RMU_RSTCAUSE_LOCKUPRST_DEFAULT       0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_LOCKUPRST_DEFAULT        (_RMU_RSTCAUSE_LOCKUPRST_DEFAULT << 5)     /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_SYSREQRST                (0x1UL << 6)                               /**< System Request Reset */
#define _RMU_RSTCAUSE_SYSREQRST_SHIFT         6                                          /**< Shift value for RMU_SYSREQRST */
#define _RMU_RSTCAUSE_SYSREQRST_MASK          0x40UL                                     /**< Bit mask for RMU_SYSREQRST */
#define _RMU_RSTCAUSE_SYSREQRST_DEFAULT       0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_SYSREQRST_DEFAULT        (_RMU_RSTCAUSE_SYSREQRST_DEFAULT << 6)     /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_EM4RST                   (0x1UL << 7)                               /**< EM4 Reset */
#define _RMU_RSTCAUSE_EM4RST_SHIFT            7                                          /**< Shift value for RMU_EM4RST */
#define _RMU_RSTCAUSE_EM4RST_MASK             0x80UL                                     /**< Bit mask for RMU_EM4RST */
#define _RMU_RSTCAUSE_EM4RST_DEFAULT          0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_EM4RST_DEFAULT           (_RMU_RSTCAUSE_EM4RST_DEFAULT << 7)        /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_EM4WURST                 (0x1UL << 8)                               /**< EM4 Wake-up Reset */
#define _RMU_RSTCAUSE_EM4WURST_SHIFT          8                                          /**< Shift value for RMU_EM4WURST */
#define _RMU_RSTCAUSE_EM4WURST_MASK           0x100UL                                    /**< Bit mask for RMU_EM4WURST */
#define _RMU_RSTCAUSE_EM4WURST_DEFAULT        0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_EM4WURST_DEFAULT         (_RMU_RSTCAUSE_EM4WURST_DEFAULT << 8)      /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BODAVDD0                 (0x1UL << 9)                               /**< AVDD0 Bod Reset */
#define _RMU_RSTCAUSE_BODAVDD0_SHIFT          9                                          /**< Shift value for RMU_BODAVDD0 */
#define _RMU_RSTCAUSE_BODAVDD0_MASK           0x200UL                                    /**< Bit mask for RMU_BODAVDD0 */
#define _RMU_RSTCAUSE_BODAVDD0_DEFAULT        0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BODAVDD0_DEFAULT         (_RMU_RSTCAUSE_BODAVDD0_DEFAULT << 9)      /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BODAVDD1                 (0x1UL << 10)                              /**< AVDD1 Bod Reset */
#define _RMU_RSTCAUSE_BODAVDD1_SHIFT          10                                         /**< Shift value for RMU_BODAVDD1 */
#define _RMU_RSTCAUSE_BODAVDD1_MASK           0x400UL                                    /**< Bit mask for RMU_BODAVDD1 */
#define _RMU_RSTCAUSE_BODAVDD1_DEFAULT        0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BODAVDD1_DEFAULT         (_RMU_RSTCAUSE_BODAVDD1_DEFAULT << 10)     /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUBODVDDDREG             (0x1UL << 11)                              /**< Backup Brown Out Detector, VDD_DREG */
#define _RMU_RSTCAUSE_BUBODVDDDREG_SHIFT      11                                         /**< Shift value for RMU_BUBODVDDDREG */
#define _RMU_RSTCAUSE_BUBODVDDDREG_MASK       0x800UL                                    /**< Bit mask for RMU_BUBODVDDDREG */
#define _RMU_RSTCAUSE_BUBODVDDDREG_DEFAULT    0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUBODVDDDREG_DEFAULT     (_RMU_RSTCAUSE_BUBODVDDDREG_DEFAULT << 11) /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUBODBUVIN               (0x1UL << 12)                              /**< Backup Brown Out Detector, BU_VIN */
#define _RMU_RSTCAUSE_BUBODBUVIN_SHIFT        12                                         /**< Shift value for RMU_BUBODBUVIN */
#define _RMU_RSTCAUSE_BUBODBUVIN_MASK         0x1000UL                                   /**< Bit mask for RMU_BUBODBUVIN */
#define _RMU_RSTCAUSE_BUBODBUVIN_DEFAULT      0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUBODBUVIN_DEFAULT       (_RMU_RSTCAUSE_BUBODBUVIN_DEFAULT << 12)   /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUBODUNREG               (0x1UL << 13)                              /**< Backup Brown Out Detector Unregulated Domain */
#define _RMU_RSTCAUSE_BUBODUNREG_SHIFT        13                                         /**< Shift value for RMU_BUBODUNREG */
#define _RMU_RSTCAUSE_BUBODUNREG_MASK         0x2000UL                                   /**< Bit mask for RMU_BUBODUNREG */
#define _RMU_RSTCAUSE_BUBODUNREG_DEFAULT      0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUBODUNREG_DEFAULT       (_RMU_RSTCAUSE_BUBODUNREG_DEFAULT << 13)   /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUBODREG                 (0x1UL << 14)                              /**< Backup Brown Out Detector Regulated Domain */
#define _RMU_RSTCAUSE_BUBODREG_SHIFT          14                                         /**< Shift value for RMU_BUBODREG */
#define _RMU_RSTCAUSE_BUBODREG_MASK           0x4000UL                                   /**< Bit mask for RMU_BUBODREG */
#define _RMU_RSTCAUSE_BUBODREG_DEFAULT        0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUBODREG_DEFAULT         (_RMU_RSTCAUSE_BUBODREG_DEFAULT << 14)     /**< Shifted mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUMODERST                (0x1UL << 15)                              /**< Backup mode reset */
#define _RMU_RSTCAUSE_BUMODERST_SHIFT         15                                         /**< Shift value for RMU_BUMODERST */
#define _RMU_RSTCAUSE_BUMODERST_MASK          0x8000UL                                   /**< Bit mask for RMU_BUMODERST */
#define _RMU_RSTCAUSE_BUMODERST_DEFAULT       0x00000000UL                               /**< Mode DEFAULT for RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUMODERST_DEFAULT        (_RMU_RSTCAUSE_BUMODERST_DEFAULT << 15)    /**< Shifted mode DEFAULT for RMU_RSTCAUSE */

/* Bit fields for RMU CMD */

#define _RMU_CMD_RESETVALUE                   0x00000000UL                  /**< Default value for RMU_CMD */
#define _RMU_CMD_MASK                         0x00000001UL                  /**< Mask for RMU_CMD */

#define RMU_CMD_RCCLR                         (0x1UL << 0)                  /**< Reset Cause Clear */
#define _RMU_CMD_RCCLR_SHIFT                  0                             /**< Shift value for RMU_RCCLR */
#define _RMU_CMD_RCCLR_MASK                   0x1UL                         /**< Bit mask for RMU_RCCLR */
#define _RMU_CMD_RCCLR_DEFAULT                0x00000000UL                  /**< Mode DEFAULT for RMU_CMD */
#define RMU_CMD_RCCLR_DEFAULT                 (_RMU_CMD_RCCLR_DEFAULT << 0) /**< Shifted mode DEFAULT for RMU_CMD */

#endif /* __ARCH_ARM_SRC_EFM32_CHIP_EFM32_RMU_H */
