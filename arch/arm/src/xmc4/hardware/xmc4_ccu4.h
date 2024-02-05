/****************************************************************************
 * arch/arm/src/xmc4/hardware/xmc4_ccu4.h
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
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
 * May include some logic from sample code provided by Infineon:
 *
 * Copyright (C) 2011-2015 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use
 * with Infineon's microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such microcontrollers.
 *
 * THIS SOFTWARE IS PROVIDED AS IS. NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS
 * SOFTWARE. INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL,
 * INCIDENTAL, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ****************************************************************************/

/* Reference: XMC4500 Reference Manual V1.5 2014-07 Microcontrollers. */

#ifndef __ARCH_ARM_SRC_XMC4_HARDWARE_XMC4_CCU4_H
#define __ARCH_ARM_SRC_XMC4_HARDWARE_XMC4_CCU4_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include "hardware/xmc4_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register Offsets *********************************************************/

/* CCU4 Global Registers */

#define XMC4_CCU4_GCTRL_OFFSET             0x0000   /* Module General Control Register */
#define XMC4_CCU4_GSTAT_OFFSET             0x0004   /* General Slice Status Register */
#define XMC4_CCU4_GIDLS_OFFSET             0x0008   /* General Idle Enable Register */
#define XMC4_CCU4_GIDLC_OFFSET             0x000C   /* General Idle Disable Register */
#define XMC4_CCU4_GCSS_OFFSET              0x0010   /* General Channel Set Register */
#define XMC4_CCU4_GCSC_OFFSET              0x0014   /* General Channel Clear Register */
#define XMC4_CCU4_GCST_OFFSET              0x0018   /* General Channel Status Register */
#define XMC4_CCU4_MIDR_OFFSET              0x0080   /* Module Identification Register */

/* CCU40 Registers */

#define XMC4_CCU4_CC40INS_OFFSET           0x0100   /* Input Selector Unit Configuration */
#define XMC4_CCU4_CC40CMC_OFFSET           0x0104   /* Connection Matrix Configuration */
#define XMC4_CCU4_CC40TST_OFFSET           0x0108   /* Timer Run Status */
#define XMC4_CCU4_CC40TCSET_OFFSET         0x010C   /* Timer Run Set */
#define XMC4_CCU4_CC40TCCLR_OFFSET         0x0110   /* Timer Run Clear */
#define XMC4_CCU4_CC40TC_OFFSET            0x0114   /* General Timer Configuration */
#define XMC4_CCU4_CC40PSL_OFFSET           0x0118   /* Output Passive Level Configuration */
#define XMC4_CCU4_CC40DIT_OFFSET           0x011C   /* Dither Configuration */
#define XMC4_CCU4_CC40DITS_OFFSET          0x0120   /* Dither Shadow Register */
#define XMC4_CCU4_CC40PSC_OFFSET           0x0124   /* Prescaler Configuration */
#define XMC4_CCU4_CC40FPC_OFFSET           0x0128   /* Prescaler Compare Value */
#define XMC4_CCU4_CC40FPCS_OFFSET          0x012C   /* Prescaler Shadow Compare Value */
#define XMC4_CCU4_CC40PR_OFFSET            0x0130   /* Timer Period Value */
#define XMC4_CCU4_CC40PRS_OFFSET           0x0134   /* Timer Period Shadow Value */
#define XMC4_CCU4_CC40CR_OFFSET            0x0138   /* Timer Compare Value */
#define XMC4_CCU4_CC40CRS_OFFSET           0x013C   /* Timer Compare Shadow Value */
#define XMC4_CCU4_CC40TIMER_OFFSET         0x0170   /* Timer Current Value */
#define XMC4_CCU4_CC40C0V_OFFSET           0x0174   /* Capture Register 0 Value */
#define XMC4_CCU4_CC40C1V_OFFSET           0x0178   /* Capture Register 1 Value */
#define XMC4_CCU4_CC40C2V_OFFSET           0x017C   /* Capture Register 2 Value */
#define XMC4_CCU4_CC40C3V_OFFSET           0x0180   /* Capture Register 3 Value */
#define XMC4_CCU4_CC40INTS_OFFSET          0x01A0   /* Interrupt Status */
#define XMC4_CCU4_CC40INTE_OFFSET          0x01A4   /* Interrupt Enable */
#define XMC4_CCU4_CC40SRS_OFFSET           0x01A8   /* Interrupt Configuration */
#define XMC4_CCU4_CC40SWS_OFFSET           0x01AC   /* Interrupt Status Set */
#define XMC4_CCU4_CC40SWR_OFFSET           0x01B0   /* Interrupt Status Clear */
#define XMC4_CCU4_CC40ECRD0_OFFSET         0x01B8   /* Extended Read Back 0 */
#define XMC4_CCU4_CC40ECRD1_OFFSET         0x01BC   /* Extended Read Back 1 */

/* CCU41 Registers */

#define XMC4_CCU4_CC41INS_OFFSET           0x0200   /* Input Selector Unit Configuration */
#define XMC4_CCU4_CC41CMC_OFFSET           0x0204   /* Connection Matrix Configuration */
#define XMC4_CCU4_CC41TST_OFFSET           0x0208   /* Timer Run Status */
#define XMC4_CCU4_CC41TCSET_OFFSET         0x020C   /* Timer Run Set */
#define XMC4_CCU4_CC41TCCLR_OFFSET         0x0210   /* Timer Run Clear */
#define XMC4_CCU4_CC41TC_OFFSET            0x0214   /* General Timer Configuration */
#define XMC4_CCU4_CC41PSL_OFFSET           0x0218   /* Output Passive Level Configuration */
#define XMC4_CCU4_CC41DIT_OFFSET           0x021C   /* Dither Configuration */
#define XMC4_CCU4_CC41DITS_OFFSET          0x0220   /* Dither Shadow Register */
#define XMC4_CCU4_CC41PSC_OFFSET           0x0224   /* Prescaler Configuration */
#define XMC4_CCU4_CC41FPC_OFFSET           0x0228   /* Prescaler Compare Value */
#define XMC4_CCU4_CC41FPCS_OFFSET          0x022C   /* Prescaler Shadow Compare Value */
#define XMC4_CCU4_CC41PR_OFFSET            0x0230   /* Timer Period Value */
#define XMC4_CCU4_CC41PRS_OFFSET           0x0234   /* Timer Period Shadow Value */
#define XMC4_CCU4_CC41CR_OFFSET            0x0238   /* Timer Compare Value */
#define XMC4_CCU4_CC41CRS_OFFSET           0x023C   /* Timer Compare Shadow Value */
#define XMC4_CCU4_CC41TIMER_OFFSET         0x0270   /* Timer Current Value */
#define XMC4_CCU4_CC41C0V_OFFSET           0x0274   /* Capture Register 0 Value */
#define XMC4_CCU4_CC41C1V_OFFSET           0x0278   /* Capture Register 1 Value */
#define XMC4_CCU4_CC41C2V_OFFSET           0x027C   /* Capture Register 2 Value */
#define XMC4_CCU4_CC41C3V_OFFSET           0x0280   /* Capture Register 3 Value */
#define XMC4_CCU4_CC41INTS_OFFSET          0x02A0   /* Interrupt Status */
#define XMC4_CCU4_CC41INTE_OFFSET          0x02A4   /* Interrupt Enable */
#define XMC4_CCU4_CC41SRS_OFFSET           0x02A8   /* Interrupt Configuration */
#define XMC4_CCU4_CC41SWS_OFFSET           0x02AC   /* Interrupt Status Set */
#define XMC4_CCU4_CC41SWR_OFFSET           0x02B0   /* Interrupt Status Clear */
#define XMC4_CCU4_CC41ECRD0_OFFSET         0x02B8   /* Extended Read Back 0 */
#define XMC4_CCU4_CC41ECRD1_OFFSET         0x02BC   /* Extended Read Back 1 */

/* CCU42 Registers */

#define XMC4_CCU4_CC42INS_OFFSET           0x0300   /* Input Selector Unit Configuration */
#define XMC4_CCU4_CC42CMC_OFFSET           0x0304   /* Connection Matrix Configuration */
#define XMC4_CCU4_CC42TST_OFFSET           0x0308   /* Timer Run Status */
#define XMC4_CCU4_CC42TCSET_OFFSET         0x030C   /* Timer Run Set */
#define XMC4_CCU4_CC42TCCLR_OFFSET         0x0310   /* Timer Run Clear */
#define XMC4_CCU4_CC42TC_OFFSET            0x0314   /* General Timer Configuration */
#define XMC4_CCU4_CC42PSL_OFFSET           0x0318   /* Output Passive Level Configuration */
#define XMC4_CCU4_CC42DIT_OFFSET           0x031C   /* Dither Configuration */
#define XMC4_CCU4_CC42DITS_OFFSET          0x0320   /* Dither Shadow Register */
#define XMC4_CCU4_CC42PSC_OFFSET           0x0324   /* Prescaler Configuration */
#define XMC4_CCU4_CC42FPC_OFFSET           0x0328   /* Prescaler Compare Value */
#define XMC4_CCU4_CC42FPCS_OFFSET          0x032C   /* Prescaler Shadow Compare Value */
#define XMC4_CCU4_CC42PR_OFFSET            0x0330   /* Timer Period Value */
#define XMC4_CCU4_CC42PRS_OFFSET           0x0334   /* Timer Period Shadow Value */
#define XMC4_CCU4_CC42CR_OFFSET            0x0338   /* Timer Compare Value */
#define XMC4_CCU4_CC42CRS_OFFSET           0x033C   /* Timer Compare Shadow Value */
#define XMC4_CCU4_CC42TIMER_OFFSET         0x0370   /* Timer Current Value */
#define XMC4_CCU4_CC42C0V_OFFSET           0x0374   /* Capture Register 0 Value */
#define XMC4_CCU4_CC42C1V_OFFSET           0x0378   /* Capture Register 1 Value */
#define XMC4_CCU4_CC42C2V_OFFSET           0x037C   /* Capture Register 2 Value */
#define XMC4_CCU4_CC42C3V_OFFSET           0x0380   /* Capture Register 3 Value */
#define XMC4_CCU4_CC42INTS_OFFSET          0x03A0   /* Interrupt Status */
#define XMC4_CCU4_CC42INTE_OFFSET          0x03A4   /* Interrupt Enable */
#define XMC4_CCU4_CC42SRS_OFFSET           0x03A8   /* Interrupt Configuration */
#define XMC4_CCU4_CC42SWS_OFFSET           0x03AC   /* Interrupt Status Set */
#define XMC4_CCU4_CC42SWR_OFFSET           0x03B0   /* Interrupt Status Clear */
#define XMC4_CCU4_CC42ECRD0_OFFSET         0x03B8   /* Extended Read Back 0 */
#define XMC4_CCU4_CC42ECRD1_OFFSET         0x03BC   /* Extended Read Back 1 */

/* CCU43 Registers */

#define XMC4_CCU4_CC43INS_OFFSET           0x0400   /* Input Selector Unit Configuration */
#define XMC4_CCU4_CC43CMC_OFFSET           0x0404   /* Connection Matrix Configuration */
#define XMC4_CCU4_CC43TST_OFFSET           0x0408   /* Timer Run Status */
#define XMC4_CCU4_CC43TCSET_OFFSET         0x040C   /* Timer Run Set */
#define XMC4_CCU4_CC43TCCLR_OFFSET         0x0410   /* Timer Run Clear */
#define XMC4_CCU4_CC43TC_OFFSET            0x0414   /* General Timer Configuration */
#define XMC4_CCU4_CC43PSL_OFFSET           0x0418   /* Output Passive Level Configuration */
#define XMC4_CCU4_CC43DIT_OFFSET           0x041C   /* Dither Configuration */
#define XMC4_CCU4_CC43DITS_OFFSET          0x0420   /* Dither Shadow Register */
#define XMC4_CCU4_CC43PSC_OFFSET           0x0424   /* Prescaler Configuration */
#define XMC4_CCU4_CC43FPC_OFFSET           0x0428   /* Prescaler Compare Value */
#define XMC4_CCU4_CC43FPCS_OFFSET          0x042C   /* Prescaler Shadow Compare Value */
#define XMC4_CCU4_CC43PR_OFFSET            0x0430   /* Timer Period Value */
#define XMC4_CCU4_CC43PRS_OFFSET           0x0434   /* Timer Period Shadow Value */
#define XMC4_CCU4_CC43CR_OFFSET            0x0438   /* Timer Compare Value */
#define XMC4_CCU4_CC43CRS_OFFSET           0x043C   /* Timer Compare Shadow Value */
#define XMC4_CCU4_CC43TIMER_OFFSET         0x0470   /* Timer Current Value */
#define XMC4_CCU4_CC43C0V_OFFSET           0x0474   /* Capture Register 0 Value */
#define XMC4_CCU4_CC43C1V_OFFSET           0x0478   /* Capture Register 1 Value */
#define XMC4_CCU4_CC43C2V_OFFSET           0x047C   /* Capture Register 2 Value */
#define XMC4_CCU4_CC43C3V_OFFSET           0x0480   /* Capture Register 3 Value */
#define XMC4_CCU4_CC43INTS_OFFSET          0x04A0   /* Interrupt Status */
#define XMC4_CCU4_CC43INTE_OFFSET          0x04A4   /* Interrupt Enable */
#define XMC4_CCU4_CC43SRS_OFFSET           0x04A8   /* Interrupt Configuration */
#define XMC4_CCU4_CC43SWS_OFFSET           0x04AC   /* Interrupt Status Set */
#define XMC4_CCU4_CC43SWR_OFFSET           0x04B0   /* Interrupt Status Clear */
#define XMC4_CCU4_CC43ECRD0_OFFSET         0x04B8   /* Extended Read Back 0 */
#define XMC4_CCU4_CC43ECRD1_OFFSET         0x04BC   /* Extended Read Back 1 */

/* Register Addresses *******************************************************/

/* CCU40 Registers */

#define XMC4_CCU40_GCTRL             (XMC4_CCU40_BASE+XMC4_CCU4_GCTRL_OFFSET)
#define XMC4_CCU40_GSTAT             (XMC4_CCU40_BASE+XMC4_CCU4_GSTAT_OFFSET)
#define XMC4_CCU40_GIDLS             (XMC4_CCU40_BASE+XMC4_CCU4_GIDLS_OFFSET)
#define XMC4_CCU40_GIDLC             (XMC4_CCU40_BASE+XMC4_CCU4_GIDLC_OFFSET)
#define XMC4_CCU40_GCSS              (XMC4_CCU40_BASE+XMC4_CCU4_GCSS_OFFSET)
#define XMC4_CCU40_GCSC              (XMC4_CCU40_BASE+XMC4_CCU4_GCSC_OFFSET)
#define XMC4_CCU40_GCST              (XMC4_CCU40_BASE+XMC4_CCU4_GCST_OFFSET)
#define XMC4_CCU40_MIDR              (XMC4_CCU40_BASE+XMC4_CCU4_MIDR_OFFSET)

#define XMC4_CCU4_CC40INS            (XMC4_CCU40_BASE+XMC4_CCU4_CC40INS_OFFSET)
#define XMC4_CCU4_CC40CMC            (XMC4_CCU40_BASE+XMC4_CCU4_CC40CMC_OFFSET)
#define XMC4_CCU4_CC40TST            (XMC4_CCU40_BASE+XMC4_CCU4_CC40TST_OFFSET)
#define XMC4_CCU4_CC40TCSET          (XMC4_CCU40_BASE+XMC4_CCU4_CC40TCSET_OFFSET)
#define XMC4_CCU4_CC40TCCLR          (XMC4_CCU40_BASE+XMC4_CCU4_CC40TCCLR_OFFSET)
#define XMC4_CCU4_CC40TC             (XMC4_CCU40_BASE+XMC4_CCU4_CC40TC_OFFSET)
#define XMC4_CCU4_CC40PSL            (XMC4_CCU40_BASE+XMC4_CCU4_CC40PSL_OFFSET)
#define XMC4_CCU4_CC40DIT            (XMC4_CCU40_BASE+XMC4_CCU4_CC40DIT_OFFSET)
#define XMC4_CCU4_CC40DITS           (XMC4_CCU40_BASE+XMC4_CCU4_CC40DITS_OFFSET)
#define XMC4_CCU4_CC40PSC            (XMC4_CCU40_BASE+XMC4_CCU4_CC40PSC_OFFSET)
#define XMC4_CCU4_CC40FPC            (XMC4_CCU40_BASE+XMC4_CCU4_CC40FPC_OFFSET)
#define XMC4_CCU4_CC40FPCS           (XMC4_CCU40_BASE+XMC4_CCU4_CC40FPCS_OFFSET)
#define XMC4_CCU4_CC40PR             (XMC4_CCU40_BASE+XMC4_CCU4_CC40PR_OFFSET)
#define XMC4_CCU4_CC40PRS            (XMC4_CCU40_BASE+XMC4_CCU4_CC40PRS_OFFSET)
#define XMC4_CCU4_CC40CR             (XMC4_CCU40_BASE+XMC4_CCU4_CC40CR_OFFSET)
#define XMC4_CCU4_CC40CRS            (XMC4_CCU40_BASE+XMC4_CCU4_CC40CRS_OFFSET)
#define XMC4_CCU4_CC40TIMER          (XMC4_CCU40_BASE+XMC4_CCU4_CC40TIMER_OFFSET)
#define XMC4_CCU4_CC40C0V            (XMC4_CCU40_BASE+XMC4_CCU4_CC40C0V_OFFSET)
#define XMC4_CCU4_CC40C1V            (XMC4_CCU40_BASE+XMC4_CCU4_CC40C1V_OFFSET)
#define XMC4_CCU4_CC40C2V            (XMC4_CCU40_BASE+XMC4_CCU4_CC40C2V_OFFSET)
#define XMC4_CCU4_CC40C3V            (XMC4_CCU40_BASE+XMC4_CCU4_CC40C3V_OFFSET)
#define XMC4_CCU4_CC40INTS           (XMC4_CCU40_BASE+XMC4_CCU4_CC40INTS_OFFSET)
#define XMC4_CCU4_CC40INTE           (XMC4_CCU40_BASE+XMC4_CCU4_CC40INTE_OFFSET)
#define XMC4_CCU4_CC40SRS            (XMC4_CCU40_BASE+XMC4_CCU4_CC40SRS_OFFSET)
#define XMC4_CCU4_CC40SWS            (XMC4_CCU40_BASE+XMC4_CCU4_CC40SWS_OFFSET)
#define XMC4_CCU4_CC40SWR            (XMC4_CCU40_BASE+XMC4_CCU4_CC40SWR_OFFSET)
#define XMC4_CCU4_CC40ECRD0          (XMC4_CCU40_BASE+XMC4_CCU4_CC40ECRD0_OFFSET)
#define XMC4_CCU4_CC40ECRD1          (XMC4_CCU40_BASE+XMC4_CCU4_CC40ECRD1_OFFSET)

/* CCU41 Registers */

#define XMC4_CCU41_GCTRL             (XMC4_CCU41_BASE+XMC4_CCU4_GCTRL_OFFSET)
#define XMC4_CCU41_GSTAT             (XMC4_CCU41_BASE+XMC4_CCU4_GSTAT_OFFSET)
#define XMC4_CCU41_GIDLS             (XMC4_CCU41_BASE+XMC4_CCU4_GIDLS_OFFSET)
#define XMC4_CCU41_GIDLC             (XMC4_CCU41_BASE+XMC4_CCU4_GIDLC_OFFSET)
#define XMC4_CCU41_GCSS              (XMC4_CCU41_BASE+XMC4_CCU4_GCSS_OFFSET)
#define XMC4_CCU41_GCSC              (XMC4_CCU41_BASE+XMC4_CCU4_GCSC_OFFSET)
#define XMC4_CCU41_GCST              (XMC4_CCU41_BASE+XMC4_CCU4_GCST_OFFSET)
#define XMC4_CCU41_MIDR              (XMC4_CCU41_BASE+XMC4_CCU4_MIDR_OFFSET)

#define XMC4_CCU4_CC41INS            (XMC4_CCU41_BASE+XMC4_CCU4_CC41INS_OFFSET)
#define XMC4_CCU4_CC41CMC            (XMC4_CCU41_BASE+XMC4_CCU4_CC41CMC_OFFSET)
#define XMC4_CCU4_CC41TST            (XMC4_CCU41_BASE+XMC4_CCU4_CC41TST_OFFSET)
#define XMC4_CCU4_CC41TCSET          (XMC4_CCU41_BASE+XMC4_CCU4_CC41TCSET_OFFSET)
#define XMC4_CCU4_CC41TCCLR          (XMC4_CCU41_BASE+XMC4_CCU4_CC41TCCLR_OFFSET)
#define XMC4_CCU4_CC41TC             (XMC4_CCU41_BASE+XMC4_CCU4_CC41TC_OFFSET)
#define XMC4_CCU4_CC41PSL            (XMC4_CCU41_BASE+XMC4_CCU4_CC41PSL_OFFSET)
#define XMC4_CCU4_CC41DIT            (XMC4_CCU41_BASE+XMC4_CCU4_CC41DIT_OFFSET)
#define XMC4_CCU4_CC41DITS           (XMC4_CCU41_BASE+XMC4_CCU4_CC41DITS_OFFSET)
#define XMC4_CCU4_CC41PSC            (XMC4_CCU41_BASE+XMC4_CCU4_CC41PSC_OFFSET)
#define XMC4_CCU4_CC41FPC            (XMC4_CCU41_BASE+XMC4_CCU4_CC41FPC_OFFSET)
#define XMC4_CCU4_CC41FPCS           (XMC4_CCU41_BASE+XMC4_CCU4_CC41FPCS_OFFSET)
#define XMC4_CCU4_CC41PR             (XMC4_CCU41_BASE+XMC4_CCU4_CC41PR_OFFSET)
#define XMC4_CCU4_CC41PRS            (XMC4_CCU41_BASE+XMC4_CCU4_CC41PRS_OFFSET)
#define XMC4_CCU4_CC41CR             (XMC4_CCU41_BASE+XMC4_CCU4_CC41CR_OFFSET)
#define XMC4_CCU4_CC41CRS            (XMC4_CCU41_BASE+XMC4_CCU4_CC41CRS_OFFSET)
#define XMC4_CCU4_CC41TIMER          (XMC4_CCU41_BASE+XMC4_CCU4_CC41TIMER_OFFSET)
#define XMC4_CCU4_CC41C0V            (XMC4_CCU41_BASE+XMC4_CCU4_CC41C0V_OFFSET)
#define XMC4_CCU4_CC41C1V            (XMC4_CCU41_BASE+XMC4_CCU4_CC41C1V_OFFSET)
#define XMC4_CCU4_CC41C2V            (XMC4_CCU41_BASE+XMC4_CCU4_CC41C2V_OFFSET)
#define XMC4_CCU4_CC41C3V            (XMC4_CCU41_BASE+XMC4_CCU4_CC41C3V_OFFSET)
#define XMC4_CCU4_CC41INTS           (XMC4_CCU41_BASE+XMC4_CCU4_CC41INTS_OFFSET)
#define XMC4_CCU4_CC41INTE           (XMC4_CCU41_BASE+XMC4_CCU4_CC41INTE_OFFSET)
#define XMC4_CCU4_CC41SRS            (XMC4_CCU41_BASE+XMC4_CCU4_CC41SRS_OFFSET)
#define XMC4_CCU4_CC41SWS            (XMC4_CCU41_BASE+XMC4_CCU4_CC41SWS_OFFSET)
#define XMC4_CCU4_CC41SWR            (XMC4_CCU41_BASE+XMC4_CCU4_CC41SWR_OFFSET)
#define XMC4_CCU4_CC41ECRD0          (XMC4_CCU41_BASE+XMC4_CCU4_CC41ECRD0_OFFSET)
#define XMC4_CCU4_CC41ECRD1          (XMC4_CCU41_BASE+XMC4_CCU4_CC41ECRD1_OFFSET)

/* CCU42 Registers */

#define XMC4_CCU42_GCTRL             (XMC4_CCU42_BASE+XMC4_CCU4_GCTRL_OFFSET)
#define XMC4_CCU42_GSTAT             (XMC4_CCU42_BASE+XMC4_CCU4_GSTAT_OFFSET)
#define XMC4_CCU42_GIDLS             (XMC4_CCU42_BASE+XMC4_CCU4_GIDLS_OFFSET)
#define XMC4_CCU42_GIDLC             (XMC4_CCU42_BASE+XMC4_CCU4_GIDLC_OFFSET)
#define XMC4_CCU42_GCSS              (XMC4_CCU42_BASE+XMC4_CCU4_GCSS_OFFSET)
#define XMC4_CCU42_GCSC              (XMC4_CCU42_BASE+XMC4_CCU4_GCSC_OFFSET)
#define XMC4_CCU42_GCST              (XMC4_CCU42_BASE+XMC4_CCU4_GCST_OFFSET)
#define XMC4_CCU42_MIDR              (XMC4_CCU42_BASE+XMC4_CCU4_MIDR_OFFSET)

#define XMC4_CCU4_CC42INS            (XMC4_CCU42_BASE+XMC4_CCU4_CC42INS_OFFSET)
#define XMC4_CCU4_CC42CMC            (XMC4_CCU42_BASE+XMC4_CCU4_CC42CMC_OFFSET)
#define XMC4_CCU4_CC42TST            (XMC4_CCU42_BASE+XMC4_CCU4_CC42TST_OFFSET)
#define XMC4_CCU4_CC42TCSET          (XMC4_CCU42_BASE+XMC4_CCU4_CC42TCSET_OFFSET)
#define XMC4_CCU4_CC42TCCLR          (XMC4_CCU42_BASE+XMC4_CCU4_CC42TCCLR_OFFSET)
#define XMC4_CCU4_CC42TC             (XMC4_CCU42_BASE+XMC4_CCU4_CC42TC_OFFSET)
#define XMC4_CCU4_CC42PSL            (XMC4_CCU42_BASE+XMC4_CCU4_CC42PSL_OFFSET)
#define XMC4_CCU4_CC42DIT            (XMC4_CCU42_BASE+XMC4_CCU4_CC42DIT_OFFSET)
#define XMC4_CCU4_CC42DITS           (XMC4_CCU42_BASE+XMC4_CCU4_CC42DITS_OFFSET)
#define XMC4_CCU4_CC42PSC            (XMC4_CCU42_BASE+XMC4_CCU4_CC42PSC_OFFSET)
#define XMC4_CCU4_CC42FPC            (XMC4_CCU42_BASE+XMC4_CCU4_CC42FPC_OFFSET)
#define XMC4_CCU4_CC42FPCS           (XMC4_CCU42_BASE+XMC4_CCU4_CC42FPCS_OFFSET)
#define XMC4_CCU4_CC42PR             (XMC4_CCU42_BASE+XMC4_CCU4_CC42PR_OFFSET)
#define XMC4_CCU4_CC42PRS            (XMC4_CCU42_BASE+XMC4_CCU4_CC42PRS_OFFSET)
#define XMC4_CCU4_CC42CR             (XMC4_CCU42_BASE+XMC4_CCU4_CC42CR_OFFSET)
#define XMC4_CCU4_CC42CRS            (XMC4_CCU42_BASE+XMC4_CCU4_CC42CRS_OFFSET)
#define XMC4_CCU4_CC42TIMER          (XMC4_CCU42_BASE+XMC4_CCU4_CC42TIMER_OFFSET)
#define XMC4_CCU4_CC42C0V            (XMC4_CCU42_BASE+XMC4_CCU4_CC42C0V_OFFSET)
#define XMC4_CCU4_CC42C1V            (XMC4_CCU42_BASE+XMC4_CCU4_CC42C1V_OFFSET)
#define XMC4_CCU4_CC42C2V            (XMC4_CCU42_BASE+XMC4_CCU4_CC42C2V_OFFSET)
#define XMC4_CCU4_CC42C3V            (XMC4_CCU42_BASE+XMC4_CCU4_CC42C3V_OFFSET)
#define XMC4_CCU4_CC42INTS           (XMC4_CCU42_BASE+XMC4_CCU4_CC42INTS_OFFSET)
#define XMC4_CCU4_CC42INTE           (XMC4_CCU42_BASE+XMC4_CCU4_CC42INTE_OFFSET)
#define XMC4_CCU4_CC42SRS            (XMC4_CCU42_BASE+XMC4_CCU4_CC42SRS_OFFSET)
#define XMC4_CCU4_CC42SWS            (XMC4_CCU42_BASE+XMC4_CCU4_CC42SWS_OFFSET)
#define XMC4_CCU4_CC42SWR            (XMC4_CCU42_BASE+XMC4_CCU4_CC42SWR_OFFSET)
#define XMC4_CCU4_CC42ECRD0          (XMC4_CCU42_BASE+XMC4_CCU4_CC42ECRD0_OFFSET)
#define XMC4_CCU4_CC42ECRD1          (XMC4_CCU42_BASE+XMC4_CCU4_CC42ECRD1_OFFSET)

/* CCU43 Registers */

#define XMC4_CCU43_GCTRL             (XMC4_CCU43_BASE+XMC4_CCU4_GCTRL_OFFSET)
#define XMC4_CCU43_GSTAT             (XMC4_CCU43_BASE+XMC4_CCU4_GSTAT_OFFSET)
#define XMC4_CCU43_GIDLS             (XMC4_CCU43_BASE+XMC4_CCU4_GIDLS_OFFSET)
#define XMC4_CCU43_GIDLC             (XMC4_CCU43_BASE+XMC4_CCU4_GIDLC_OFFSET)
#define XMC4_CCU43_GCSS              (XMC4_CCU43_BASE+XMC4_CCU4_GCSS_OFFSET)
#define XMC4_CCU43_GCSC              (XMC4_CCU43_BASE+XMC4_CCU4_GCSC_OFFSET)
#define XMC4_CCU43_GCST              (XMC4_CCU43_BASE+XMC4_CCU4_GCST_OFFSET)
#define XMC4_CCU43_MIDR              (XMC4_CCU43_BASE+XMC4_CCU4_MIDR_OFFSET)

#define XMC4_CCU4_CC43INS            (XMC4_CCU43_BASE+XMC4_CCU4_CC43INS_OFFSET)
#define XMC4_CCU4_CC43CMC            (XMC4_CCU43_BASE+XMC4_CCU4_CC43CMC_OFFSET)
#define XMC4_CCU4_CC43TST            (XMC4_CCU43_BASE+XMC4_CCU4_CC43TST_OFFSET)
#define XMC4_CCU4_CC43TCSET          (XMC4_CCU43_BASE+XMC4_CCU4_CC43TCSET_OFFSET)
#define XMC4_CCU4_CC43TCCLR          (XMC4_CCU43_BASE+XMC4_CCU4_CC43TCCLR_OFFSET)
#define XMC4_CCU4_CC43TC             (XMC4_CCU43_BASE+XMC4_CCU4_CC43TC_OFFSET)
#define XMC4_CCU4_CC43PSL            (XMC4_CCU43_BASE+XMC4_CCU4_CC43PSL_OFFSET)
#define XMC4_CCU4_CC43DIT            (XMC4_CCU43_BASE+XMC4_CCU4_CC43DIT_OFFSET)
#define XMC4_CCU4_CC43DITS           (XMC4_CCU43_BASE+XMC4_CCU4_CC43DITS_OFFSET)
#define XMC4_CCU4_CC43PSC            (XMC4_CCU43_BASE+XMC4_CCU4_CC43PSC_OFFSET)
#define XMC4_CCU4_CC43FPC            (XMC4_CCU43_BASE+XMC4_CCU4_CC43FPC_OFFSET)
#define XMC4_CCU4_CC43FPCS           (XMC4_CCU43_BASE+XMC4_CCU4_CC43FPCS_OFFSET)
#define XMC4_CCU4_CC43PR             (XMC4_CCU43_BASE+XMC4_CCU4_CC43PR_OFFSET)
#define XMC4_CCU4_CC43PRS            (XMC4_CCU43_BASE+XMC4_CCU4_CC43PRS_OFFSET)
#define XMC4_CCU4_CC43CR             (XMC4_CCU43_BASE+XMC4_CCU4_CC43CR_OFFSET)
#define XMC4_CCU4_CC43CRS            (XMC4_CCU43_BASE+XMC4_CCU4_CC43CRS_OFFSET)
#define XMC4_CCU4_CC43TIMER          (XMC4_CCU43_BASE+XMC4_CCU4_CC43TIMER_OFFSET)
#define XMC4_CCU4_CC43C0V            (XMC4_CCU43_BASE+XMC4_CCU4_CC43C0V_OFFSET)
#define XMC4_CCU4_CC43C1V            (XMC4_CCU43_BASE+XMC4_CCU4_CC43C1V_OFFSET)
#define XMC4_CCU4_CC43C2V            (XMC4_CCU43_BASE+XMC4_CCU4_CC43C2V_OFFSET)
#define XMC4_CCU4_CC43C3V            (XMC4_CCU43_BASE+XMC4_CCU4_CC43C3V_OFFSET)
#define XMC4_CCU4_CC43INTS           (XMC4_CCU43_BASE+XMC4_CCU4_CC43INTS_OFFSET)
#define XMC4_CCU4_CC43INTE           (XMC4_CCU43_BASE+XMC4_CCU4_CC43INTE_OFFSET)
#define XMC4_CCU4_CC43SRS            (XMC4_CCU43_BASE+XMC4_CCU4_CC43SRS_OFFSET)
#define XMC4_CCU4_CC43SWS            (XMC4_CCU43_BASE+XMC4_CCU4_CC43SWS_OFFSET)
#define XMC4_CCU4_CC43SWR            (XMC4_CCU43_BASE+XMC4_CCU4_CC43SWR_OFFSET)
#define XMC4_CCU4_CC43ECRD0          (XMC4_CCU43_BASE+XMC4_CCU4_CC43ECRD0_OFFSET)
#define XMC4_CCU4_CC43ECRD1          (XMC4_CCU43_BASE+XMC4_CCU4_CC43ECRD1_OFFSET)

/* Register Bit-Field Definitions *******************************************/

/* CCU4 Global Registers */

/* Global Control Register (GCTRL) */

#define CCU4_GCTRL_PRBC_SHIFT                (0)                            /* Bits 0-2: Prescaler Clear Configuration */
#define CCU4_GCTRL_PRBC_MASK                 (7 << CCU4_GCTRL_PRBC_SHIFT)
#   define CCU4_GCTRL_PRBC_SW                (0 << CCU4_GCTRL_PRBC_SHIFT)   /*  SW only */
#   define CCU4_GCTRL_PRBC_CC40              (1 << CCU4_GCTRL_PRBC_SHIFT)   /*  When the Run Bit of CC40 is cleared */
#   define CCU4_GCTRL_PRBC_CC41              (2 << CCU4_GCTRL_PRBC_SHIFT)   /*  When the Run Bit of CC41 is cleared */
#   define CCU4_GCTRL_PRBC_CC42              (3 << CCU4_GCTRL_PRBC_SHIFT)   /*  When the Run Bit of CC42 is cleared */
#   define CCU4_GCTRL_PRBC_CC43              (4 << CCU4_GCTRL_PRBC_SHIFT)   /*  When the Run Bit of CC43 is cleared */
#define CCU4_GCTRL_PCIS_SHIFT                (4)                            /* Bits 4-5: Prescaler Input Clock Selection */
#define CCU4_GCTRL_PCIS_MASK                 (3 << CCU4_GCTRL_PCIS_SHIFT)
#   define CCU4_GCTRL_PCIS_MODULE_CLK        (0 << CCU4_GCTRL_PCIS_SHIFT)   /*  Module clock */
#   define CCU4_GCTRL_PCIS_ECLKA             (1 << CCU4_GCTRL_PCIS_SHIFT)   /*  CCU4x.ECLKA */
#   define CCU4_GCTRL_PCIS_ECLKB             (2 << CCU4_GCTRL_PCIS_SHIFT)   /*  CCU4x.ECLKB */
#   define CCU4_GCTRL_PCIS_ECLKC             (3 << CCU4_GCTRL_PCIS_SHIFT)   /*  CCU4x.ECLKC */
#define CCU4_GCTRL_SUSCFG_SHIFT              (8)                            /* Bits 8-9: Suspend Mode Configuration */
#define CCU4_GCTRL_SUSCFG_MASK               (3 << CCU4_GCTRL_SUSCFG_SHIFT)
#define CCU4_GCTRL_MSE0_SHIFT                (10)                           /* Bits 10: Slice 0 Multi Channel shadow transfer enable */
#define CCU4_GCTRL_MSE0_MASK                 (1 << CCU4_GCTRL_MSE0_SHIFT)
#define CCU4_GCTRL_MSE1_SHIFT                (11)                           /* Bits 11: Slice 1 Multi Channel shadow transfer enable */
#define CCU4_GCTRL_MSE1_MASK                 (1 << CCU4_GCTRL_MSE1_SHIFT)
#define CCU4_GCTRL_MSE2_SHIFT                (12)                           /* Bits 12: Slice 2 Multi Channel shadow transfer enable */
#define CCU4_GCTRL_MSE2_MASK                 (1 << CCU4_GCTRL_MSE2_SHIFT)
#define CCU4_GCTRL_MSE3_SHIFT                (13)                           /* Bits 13: Slice 3 Multi Channel shadow transfer enable */
#define CCU4_GCTRL_MSE3_MASK                 (1 << CCU4_GCTRL_MSE3_SHIFT)
#define CCU4_GCTRL_MSDE_SHIFT                (15)                           /* Bits 14-15: Multi Channel shadow transfer request configuration */
#define CCU4_GCTRL_MSDE_MASK                 (3 << CCU4_GCTRL_MSDE_SHIFT)

/* Global Status Register (GSTAT) */

#define CCU4_GSTAT_S0I_SHIFT          (0)                            /* Bits 0: CC40 IDLE status */
#define CCU4_GSTAT_S0I_MASK           (1 << CCU4_GSTAT_S0I_SHIFT)
#define CCU4_GSTAT_S1I_SHIFT          (1)                            /* Bits 1: CC41 IDLE status */
#define CCU4_GSTAT_S1I_MASK           (1 << CCU4_GSTAT_S1I_SHIFT)
#define CCU4_GSTAT_S2I_SHIFT          (2)                            /* Bits 2: CC42 IDLE status */
#define CCU4_GSTAT_S2I_MASK           (1 << CCU4_GSTAT_S2I_SHIFT)
#define CCU4_GSTAT_S3I_SHIFT          (3)                            /* Bits 3: CC43 IDLE status */
#define CCU4_GSTAT_S3I_MASK           (1 << CCU4_GSTAT_SI_SHIFT)
#define CCU4_GSTAT_PRB_SHIFT          (8)                            /* Bits 8: Prescaler Run Bit */
#define CCU4_GSTAT_PRB_MASK           (1 << CCU4_GSTAT_SI_SHIFT)

/* Global Idle Set (GIDLS) */

#define CCU4_GIDLS_SS0I_SHIFT          (0)                            /* Bits 0: CC40 IDLE mode set */
#define CCU4_GIDLS_SS0I_MASK           (1 << CCU4_GIDLS_SS0I_SHIFT)
#define CCU4_GIDLS_SS1I_SHIFT          (1)                            /* Bits 1: CC41 IDLE mode set */
#define CCU4_GIDLS_SS1I_MASK           (1 << CCU4_GIDLS_SS1I_SHIFT)
#define CCU4_GIDLS_SS2I_SHIFT          (2)                            /* Bits 2: CC42 IDLE mode set */
#define CCU4_GIDLS_SS2I_MASK           (1 << CCU4_GIDLS_SS2I_SHIFT)
#define CCU4_GIDLS_SS3I_SHIFT          (3)                            /* Bits 3: CC43 IDLE mode set */
#define CCU4_GIDLS_SS3I_MASK           (1 << CCU4_GIDLS_SS3I_SHIFT)
#define CCU4_GIDLS_CPRB_SHIFT          (8)                            /* Bits 8: Prescaler Run Bit Clear */
#define CCU4_GIDLS_CPRB_MASK           (1 << CCU4_GIDLS_CPRB_SHIFT)
#define CCU4_GIDLS_PSIC_SHIFT          (9)                            /* Bits 9: Prescaler clear */
#define CCU4_GIDLS_PSIC_MASK           (1 << CCU4_GIDLS_PSIC_SHIFT)

/* Global Idle Clear (GIDLC) */

#define CCU4_GIDLC_CS0I_SHIFT          (0)                            /* Bits 0: CC40 IDLE mode clear */
#define CCU4_GIDLC_CS0I_MASK           (1 << CCU4_GIDLC_CS0I_SHIFT)
#define CCU4_GIDLC_CS1I_SHIFT          (1)                            /* Bits 1: CC41 IDLE mode clear */
#define CCU4_GIDLC_CS1I_MASK           (1 << CCU4_GIDLC_CS1I_SHIFT)
#define CCU4_GIDLC_CS2I_SHIFT          (2)                            /* Bits 2: CC42 IDLE mode clear */
#define CCU4_GIDLC_CS2I_MASK           (1 << CCU4_GIDLC_CS2I_SHIFT)
#define CCU4_GIDLC_CS3I_SHIFT          (3)                            /* Bits 3: CC43 IDLE mode clear */
#define CCU4_GIDLC_CS3I_MASK           (1 << CCU4_GIDLC_CS3I_SHIFT)
#define CCU4_GIDLC_SPRB_SHIFT          (8)                            /* Bits 8: Prescaler Run Bit Set */
#define CCU4_GIDLC_SPRB_MASK           (1 << CCU4_GIDLC_SPRB_SHIFT)

/* Global Channel Set (GCSS) */

#define CCU4_GCSS_S0SE_SHIFT            (0)                             /* Bits 0: Slice 0 shadow transfer set enable */
#define CCU4_GCSS_S0SE_MASK             (1 << CCU4_GCSS_S0SE_SHIFT)
#define CCU4_GCSS_S0DSE_SHIFT           (1)                             /* Bits 1: Slice 0 Dither shadow transfer set enable */
#define CCU4_GCSS_S0DSE_MASK            (1 << CCU4_GCSS_S0DSE_SHIFT)
#define CCU4_GCSS_S0PSE_SHIFT           (2)                             /* Bits 2: Slice 0 Prescaler shadow transfer set enable */
#define CCU4_GCSS_S0PSE_MASK            (1 << CCU4_GCSS_S0PSE_SHIFT)
#define CCU4_GCSS_S1SE_SHIFT            (4)                             /* Bits 4: Slice 1 shadow transfer set enable */
#define CCU4_GCSS_S1SE_MASK             (1 << CCU4_GCSS_S1SE_SHIFT)
#define CCU4_GCSS_S1DSE_SHIFT           (5)                             /* Bits 5: Slice 1 Dither shadow transfer set enable */
#define CCU4_GCSS_S1DSE_MASK            (1 << CCU4_GCSS_S1DSE_SHIFT)
#define CCU4_GCSS_S1PSE_SHIFT           (6)                             /* Bits 6: Slice 1 Prescaler shadow transfer set enable */
#define CCU4_GCSS_S1PSE_MASK            (1 << CCU4_GCSS_S1PSE_SHIFT)
#define CCU4_GCSS_S2SE_SHIFT            (8)                             /* Bits 8: Slice 2 shadow transfer set enable */
#define CCU4_GCSS_S2SE_MASK             (1 << CCU4_GCSS_S2SE_SHIFT)
#define CCU4_GCSS_S2DSE_SHIFT           (9)                             /* Bits 9: Slice 2 Dither shadow transfer set enable */
#define CCU4_GCSS_S2DSE_MASK            (1 << CCU4_GCSS_S2DSE_SHIFT)
#define CCU4_GCSS_S2PSE_SHIFT           (10)                            /* Bits 10: Slice 2 Prescaler shadow transfer set enable */
#define CCU4_GCSS_S2PSE_MASK            (1 << CCU4_GCSS_S2PSE_SHIFT)
#define CCU4_GCSS_S3SE_SHIFT            (12)                            /* Bits 12: Slice 3 shadow transfer set enable */
#define CCU4_GCSS_S3SE_MASK             (1 << CCU4_GCSS_S3SE_SHIFT)
#define CCU4_GCSS_S3DSE_SHIFT           (13)                            /* Bits 13: Slice 3 Dither shadow transfer set enable */
#define CCU4_GCSS_S3DSE_MASK            (1 << CCU4_GCSS_S3DSE_SHIFT)
#define CCU4_GCSS_S3PSE_SHIFT           (14)                            /* Bits 14: Slice 3 Prescaler shadow transfer set enable */
#define CCU4_GCSS_S3PSE_MASK            (1 << CCU4_GCSS_S3PSE_SHIFT)
#define CCU4_GCSS_S0STS_SHIFT           (16)                            /* Bits 16: Slice 0 status bit set */
#define CCU4_GCSS_S0STS_MASK            (1 << CCU4_GCSS_S0STS_SHIFT)
#define CCU4_GCSS_S1STS_SHIFT           (17)                            /* Bits 17: Slice 1 status bit set */
#define CCU4_GCSS_S1STS_MASK            (1 << CCU4_GCSS_S1STS_SHIFT)
#define CCU4_GCSS_S2STS_SHIFT           (18)                            /* Bits 18: Slice 2 status bit set */
#define CCU4_GCSS_S2STS_MASK            (1 << CCU4_GCSS_S2STS_SHIFT)
#define CCU4_GCSS_S3STS_SHIFT           (19)                            /* Bits 19: Slice 3 status bit set */
#define CCU4_GCSS_S3STS_MASK            (1 << CCU4_GCSS_S3STS_SHIFT)

/* Global Channel Clear (GCSC) */

#define CCU4_GCSC_S0SC_SHIFT            (0)                             /* Bits 0: Slice 0 shadow transfer clear */
#define CCU4_GCSC_S0SC_MASK             (1 << CCU4_GCSC_S0SC_SHIFT)
#define CCU4_GCSC_S0DSC_SHIFT           (1)                             /* Bits 1: Slice 0 Dither shadow transfer clear */
#define CCU4_GCSC_S0DSC_MASK            (1 << CCU4_GCSC_S0DSC_SHIFT)
#define CCU4_GCSC_S0PSC_SHIFT           (2)                             /* Bits 2: Slice 0 Prescaler shadow transfer clear */
#define CCU4_GCSC_S0PSC_MASK            (1 << CCU4_GCSC_S0PSC_SHIFT)
#define CCU4_GCSC_S1SC_SHIFT            (4)                             /* Bits 4: Slice 1 shadow transfer clear */
#define CCU4_GCSC_S1SC_MASK             (1 << CCU4_GCSC_S1SC_SHIFT)
#define CCU4_GCSC_S1DSC_SHIFT           (5)                             /* Bits 5: Slice 1 Dither shadow transfer clear */
#define CCU4_GCSC_S1DSC_MASK            (1 << CCU4_GCSC_S1DSC_SHIFT)
#define CCU4_GCSC_S1PSC_SHIFT           (6)                             /* Bits 6: Slice 1 Prescaler shadow transfer clear */
#define CCU4_GCSC_S1PSC_MASK            (1 << CCU4_GCSC_S1PSC_SHIFT)
#define CCU4_GCSC_S2SC_SHIFT            (8)                             /* Bits 8: Slice 2 shadow transfer clear */
#define CCU4_GCSC_S2SC_MASK             (1 << CCU4_GCSC_S2SC_SHIFT)
#define CCU4_GCSC_S2DSC_SHIFT           (9)                             /* Bits 9: Slice 2 Dither shadow transfer clear */
#define CCU4_GCSC_S2DSC_MASK            (1 << CCU4_GCSC_S2DSC_SHIFT)
#define CCU4_GCSC_S2PSC_SHIFT           (10)                            /* Bits 10: Slice 2 Prescaler shadow transfer clear */
#define CCU4_GCSC_S2PSC_MASK            (1 << CCU4_GCSC_S2PSC_SHIFT)
#define CCU4_GCSC_S3SC_SHIFT            (12)                            /* Bits 12: Slice 3 shadow transfer clear */
#define CCU4_GCSC_S3SC_MASK             (1 << CCU4_GCSC_S3SC_SHIFT)
#define CCU4_GCSC_S3DSC_SHIFT           (13)                            /* Bits 13: Slice 3 Dither shadow transfer clear */
#define CCU4_GCSC_S3DSC_MASK            (1 << CCU4_GCSC_S3DSC_SHIFT)
#define CCU4_GCSC_S3PSC_SHIFT           (14)                            /* Bits 14: Slice 3 Prescaler shadow transfer clear */
#define CCU4_GCSC_S3PSC_MASK            (1 << CCU4_GCSC_S3PSC_SHIFT)
#define CCU4_GCSC_S0STC_SHIFT           (16)                            /* Bits 16: Slice 0 status bit clear */
#define CCU4_GCSC_S0STC_MASK            (1 << CCU4_GCSC_S0STC_SHIFT)
#define CCU4_GCSC_S1STC_SHIFT           (17)                            /* Bits 17: Slice 1 status bit clear */
#define CCU4_GCSC_S1STC_MASK            (1 << CCU4_GCSC_S1STC_SHIFT)
#define CCU4_GCSC_S2STC_SHIFT           (18)                            /* Bits 18: Slice 2 status bit clear */
#define CCU4_GCSC_S2STC_MASK            (1 << CCU4_GCSC_S2STC_SHIFT)
#define CCU4_GCSC_S3STC_SHIFT           (19)                            /* Bits 19: Slice 3 status bit clear */
#define CCU4_GCSC_S3STC_MASK            (1 << CCU4_GCSC_S3STC_SHIFT)

/* Global Channel Clear (GCST) */

#define CCU4_GCST_S0SS_SHIFT            (0)                             /* Bits 0: Slice 0 shadow transfer status */
#define CCU4_GCST_S0SS_MASK             (1 << CCU4_GCST_S0SS_SHIFT)
#define CCU4_GCST_S0DSS_SHIFT           (1)                             /* Bits 1: Slice 0 Dither shadow transfer status */
#define CCU4_GCST_S0DSS_MASK            (1 << CCU4_GCST_S0DSS_SHIFT)
#define CCU4_GCST_S0PSS_SHIFT           (2)                             /* Bits 2: Slice 0 Prescaler shadow transfer status */
#define CCU4_GCST_S0PSS_MASK            (1 << CCU4_GCST_S0PSS_SHIFT)
#define CCU4_GCST_S1SS_SHIFT            (4)                             /* Bits 4: Slice 1 shadow transfer status */
#define CCU4_GCST_S1SS_MASK             (1 << CCU4_GCST_S1SS_SHIFT)
#define CCU4_GCST_S1DSS_SHIFT           (5)                             /* Bits 5: Slice 1 Dither shadow transfer status */
#define CCU4_GCST_S1DSS_MASK            (1 << CCU4_GCST_S1DSS_SHIFT)
#define CCU4_GCST_S1PSS_SHIFT           (6)                             /* Bits 6: Slice 1 Prescaler shadow transfer status */
#define CCU4_GCST_S1PSS_MASK            (1 << CCU4_GCST_S1PSS_SHIFT)
#define CCU4_GCST_S2SS_SHIFT            (8)                             /* Bits 8: Slice 2 shadow transfer status */
#define CCU4_GCST_S2SS_MASK             (1 << CCU4_GCST_S2SS_SHIFT)
#define CCU4_GCST_S2DSS_SHIFT           (9)                             /* Bits 9: Slice 2 Dither shadow transfer status */
#define CCU4_GCST_S2DSS_MASK            (1 << CCU4_GCST_S2DSS_SHIFT)
#define CCU4_GCST_S2PSS_SHIFT           (10)                            /* Bits 10: Slice 2 Prescaler shadow transfer status */
#define CCU4_GCST_S2PSS_MASK            (1 << CCU4_GCST_S2PSS_SHIFT)
#define CCU4_GCST_S3SS_SHIFT            (12)                            /* Bits 12: Slice 3 shadow transfer status */
#define CCU4_GCST_S3SS_MASK             (1 << CCU4_GCST_S3SS_SHIFT)
#define CCU4_GCST_S3DSS_SHIFT           (13)                            /* Bits 13: Slice 3 Dither shadow transfer status */
#define CCU4_GCST_S3DSS_MASK            (1 << CCU4_GCST_S3DSS_SHIFT)
#define CCU4_GCST_S3PSS_SHIFT           (14)                            /* Bits 14: Slice 3 Prescaler shadow transfer status */
#define CCU4_GCST_S3PSS_MASK            (1 << CCU4_GCST_S3PSS_SHIFT)
#define CCU4_GCST_CC40ST_SHIFT          (16)                            /* Bits 16: Slice 0 status bit */
#define CCU4_GCST_CC40ST_MASK           (1 << CCU4_GCST_CC40ST_SHIFT)
#define CCU4_GCST_CC41ST_SHIFT          (17)                            /* Bits 17: Slice 1 status bit */
#define CCU4_GCST_CC41ST_MASK           (1 << CCU4_GCST_CC41ST_SHIFT)
#define CCU4_GCST_CC42ST_SHIFT          (18)                            /* Bits 18: Slice 2 status bit */
#define CCU4_GCST_CC42ST_MASK           (1 << CCU4_GCST_CC42ST_SHIFT)
#define CCU4_GCST_CC43ST_SHIFT          (19)                            /* Bits 19: Slice 3 status bit */
#define CCU4_GCST_CC43ST_MASK           (1 << CCU4_GCST_CC43ST_SHIFT)

/* Module Identification (MIDR) */

#define CCU4_MIDR_MODR_SHIFT            (0)                               /* Bits 0: Module Revision */
#define CCU4_MIDR_MODR_MASK             (0xFF << CCU4_MIDR_MODR_SHIFT)
#define CCU4_MIDR_MODT_SHIFT            (8)                               /* Bits 8: Module Type */
#define CCU4_MIDR_MODT_MASK             (0xFF << CCU4_MIDR_MODT_SHIFT)
#define CCU4_MIDR_MODN_SHIFT            (16)                              /* Bits 16: Module Number */
#define CCU4_MIDR_MODN_MASK             (0xFFFF << CCU4_MIDR_MODN_SHIFT)

/* Slice (CC4y) Registers [y = 0-3] */

/* Input Selector Configuration (CC4yINS) */

#define CCU4_CC4_INS_EV0IS_SHIFT                (0)                                     /* Bits 0-3: Event 0 signal selection */
#define CCU4_CC4_INS_EV0IS_MASK                 (15 << CCU4_CC4_INS_EV0IS_SHIFT)        
#   define CCU4_CC4_INS_EV0IS_INA               (0 << CCU4_CC4_INS_EV0IS_SHIFT)         /* CCU4x.INyA */
#   define CCU4_CC4_INS_EV0IS_INB               (1 << CCU4_CC4_INS_EV0IS_SHIFT)         /* CCU4x.INyB */
#   define CCU4_CC4_INS_EV0IS_INC               (2 << CCU4_CC4_INS_EV0IS_SHIFT)         /* CCU4x.INyC */
#   define CCU4_CC4_INS_EV0IS_IND               (3 << CCU4_CC4_INS_EV0IS_SHIFT)         /* CCU4x.INyD */
#   define CCU4_CC4_INS_EV0IS_INE               (4 << CCU4_CC4_INS_EV0IS_SHIFT)         /* CCU4x.INyE */
#   define CCU4_CC4_INS_EV0IS_INF               (5 << CCU4_CC4_INS_EV0IS_SHIFT)         /* CCU4x.INyF */
#   define CCU4_CC4_INS_EV0IS_ING               (6 << CCU4_CC4_INS_EV0IS_SHIFT)         /* CCU4x.INyG */
#   define CCU4_CC4_INS_EV0IS_INH               (7 << CCU4_CC4_INS_EV0IS_SHIFT)         /* CCU4x.INyH */
#   define CCU4_CC4_INS_EV0IS_INI               (8 << CCU4_CC4_INS_EV0IS_SHIFT)         /* CCU4x.INyI */
#   define CCU4_CC4_INS_EV0IS_INJ               (9 << CCU4_CC4_INS_EV0IS_SHIFT)         /* CCU4x.INyJ */
#   define CCU4_CC4_INS_EV0IS_INK               (10 << CCU4_CC4_INS_EV0IS_SHIFT)        /* CCU4x.INyK */
#   define CCU4_CC4_INS_EV0IS_INL               (11 << CCU4_CC4_INS_EV0IS_SHIFT)        /* CCU4x.INyL */
#   define CCU4_CC4_INS_EV0IS_INM               (12 << CCU4_CC4_INS_EV0IS_SHIFT)        /* CCU4x.INyM */
#   define CCU4_CC4_INS_EV0IS_INN               (13 << CCU4_CC4_INS_EV0IS_SHIFT)        /* CCU4x.INyN */
#   define CCU4_CC4_INS_EV0IS_INO               (14 << CCU4_CC4_INS_EV0IS_SHIFT)        /* CCU4x.INyO */
#   define CCU4_CC4_INS_EV0IS_INP               (15 << CCU4_CC4_INS_EV0IS_SHIFT)        /* CCU4x.INyP */
#define CCU4_CC4_INS_EV1IS_SHIFT                (4)                                     /* Bits 4-7: Event 1 signal selection */
#define CCU4_CC4_INS_EV1IS_MASK                 (15 << CCU4_CC4_INS_EV1IS_SHIFT)        
#   define CCU4_CC4_INS_EV1IS_INA               (0 << CCU4_CC4_INS_EV1IS_SHIFT)         /* CCU4x.INyA */
#   define CCU4_CC4_INS_EV1IS_INB               (1 << CCU4_CC4_INS_EV1IS_SHIFT)         /* CCU4x.INyB */
#   define CCU4_CC4_INS_EV1IS_INC               (2 << CCU4_CC4_INS_EV1IS_SHIFT)         /* CCU4x.INyC */
#   define CCU4_CC4_INS_EV1IS_IND               (3 << CCU4_CC4_INS_EV1IS_SHIFT)         /* CCU4x.INyD */
#   define CCU4_CC4_INS_EV1IS_INE               (4 << CCU4_CC4_INS_EV1IS_SHIFT)         /* CCU4x.INyE */
#   define CCU4_CC4_INS_EV1IS_INF               (5 << CCU4_CC4_INS_EV1IS_SHIFT)         /* CCU4x.INyF */
#   define CCU4_CC4_INS_EV1IS_ING               (6 << CCU4_CC4_INS_EV1IS_SHIFT)         /* CCU4x.INyG */
#   define CCU4_CC4_INS_EV1IS_INH               (7 << CCU4_CC4_INS_EV1IS_SHIFT)         /* CCU4x.INyH */
#   define CCU4_CC4_INS_EV1IS_INI               (8 << CCU4_CC4_INS_EV1IS_SHIFT)         /* CCU4x.INyI */
#   define CCU4_CC4_INS_EV1IS_INJ               (9 << CCU4_CC4_INS_EV1IS_SHIFT)         /* CCU4x.INyJ */
#   define CCU4_CC4_INS_EV1IS_INK               (10 << CCU4_CC4_INS_EV1IS_SHIFT)        /* CCU4x.INyK */
#   define CCU4_CC4_INS_EV1IS_INL               (11 << CCU4_CC4_INS_EV1IS_SHIFT)        /* CCU4x.INyL */
#   define CCU4_CC4_INS_EV1IS_INM               (12 << CCU4_CC4_INS_EV1IS_SHIFT)        /* CCU4x.INyM */
#   define CCU4_CC4_INS_EV1IS_INN               (13 << CCU4_CC4_INS_EV1IS_SHIFT)        /* CCU4x.INyN */
#   define CCU4_CC4_INS_EV1IS_INO               (14 << CCU4_CC4_INS_EV1IS_SHIFT)        /* CCU4x.INyO */
#   define CCU4_CC4_INS_EV1IS_INP               (15 << CCU4_CC4_INS_EV1IS_SHIFT)        /* CCU4x.INyP */
#define CCU4_CC4_INS_EV2IS_SHIFT                (8)                                     /* Bits 8-11: Event 2 signal selection */
#define CCU4_CC4_INS_EV2IS_MASK                 (15 << CCU4_CC4_INS_EV2IS_SHIFT)        
#   define CCU4_CC4_INS_EV2IS_INA               (0 << CCU4_CC4_INS_EV2IS_SHIFT)         /* CCU4x.INyA */
#   define CCU4_CC4_INS_EV2IS_INB               (1 << CCU4_CC4_INS_EV2IS_SHIFT)         /* CCU4x.INyB */
#   define CCU4_CC4_INS_EV2IS_INC               (2 << CCU4_CC4_INS_EV2IS_SHIFT)         /* CCU4x.INyC */
#   define CCU4_CC4_INS_EV2IS_IND               (3 << CCU4_CC4_INS_EV2IS_SHIFT)         /* CCU4x.INyD */
#   define CCU4_CC4_INS_EV2IS_INE               (4 << CCU4_CC4_INS_EV2IS_SHIFT)         /* CCU4x.INyE */
#   define CCU4_CC4_INS_EV2IS_INF               (5 << CCU4_CC4_INS_EV2IS_SHIFT)         /* CCU4x.INyF */
#   define CCU4_CC4_INS_EV2IS_ING               (6 << CCU4_CC4_INS_EV2IS_SHIFT)         /* CCU4x.INyG */
#   define CCU4_CC4_INS_EV2IS_INH               (7 << CCU4_CC4_INS_EV2IS_SHIFT)         /* CCU4x.INyH */
#   define CCU4_CC4_INS_EV2IS_INI               (8 << CCU4_CC4_INS_EV2IS_SHIFT)         /* CCU4x.INyI */
#   define CCU4_CC4_INS_EV2IS_INJ               (9 << CCU4_CC4_INS_EV2IS_SHIFT)         /* CCU4x.INyJ */
#   define CCU4_CC4_INS_EV2IS_INK               (10 << CCU4_CC4_INS_EV2IS_SHIFT)        /* CCU4x.INyK */
#   define CCU4_CC4_INS_EV2IS_INL               (11 << CCU4_CC4_INS_EV2IS_SHIFT)        /* CCU4x.INyL */
#   define CCU4_CC4_INS_EV2IS_INM               (12 << CCU4_CC4_INS_EV2IS_SHIFT)        /* CCU4x.INyM */
#   define CCU4_CC4_INS_EV2IS_INN               (13 << CCU4_CC4_INS_EV2IS_SHIFT)        /* CCU4x.INyN */
#   define CCU4_CC4_INS_EV2IS_INO               (14 << CCU4_CC4_INS_EV2IS_SHIFT)        /* CCU4x.INyO */
#   define CCU4_CC4_INS_EV2IS_INP               (15 << CCU4_CC4_INS_EV2IS_SHIFT)        /* CCU4x.INyP */
#define CCU4_CC4_INS_EV0EM_SHIFT                (16)                                    /* Bits 16-17: Event 0 Edge Selection */
#define CCU4_CC4_INS_EV0EM_MASK                 (3 << CCU4_CC4_INS_EV0EM_SHIFT)
#   define CCU4_CC4_INS_EV0EM_NA                (0 << CCU4_CC4_INS_EV0EM_SHIFT)         /* No action */
#   define CCU4_CC4_INS_EV0EM_RE                (1 << CCU4_CC4_INS_EV0EM_SHIFT)         /* Signal active on rising edge */
#   define CCU4_CC4_INS_EV0EM_FE                (2 << CCU4_CC4_INS_EV0EM_SHIFT)         /* Signal active on falling edge */
#   define CCU4_CC4_INS_EV0EM_BE                (3 << CCU4_CC4_INS_EV0EM_SHIFT)         /* Signal active on both edges */
#define CCU4_CC4_INS_EV1EM_SHIFT                (18)                                    /* Bits 18-19: Event 1 Edge Selection */
#define CCU4_CC4_INS_EV1EM_MASK                 (3 << CCU4_CC4_INS_EV1EM_SHIFT)
#   define CCU4_CC4_INS_EV1EM_NA                (0 << CCU4_CC4_INS_EV1EM_SHIFT)         /* No action */
#   define CCU4_CC4_INS_EV1EM_RE                (1 << CCU4_CC4_INS_EV1EM_SHIFT)         /* Signal active on rising edge */
#   define CCU4_CC4_INS_EV1EM_FE                (2 << CCU4_CC4_INS_EV1EM_SHIFT)         /* Signal active on falling edge */
#   define CCU4_CC4_INS_EV1EM_BE                (3 << CCU4_CC4_INS_EV1EM_SHIFT)         /* Signal active on both edges */
#define CCU4_CC4_INS_EV2EM_SHIFT                (20)                                    /* Bits 20-21: Event 2 Edge Selection */
#define CCU4_CC4_INS_EV2EM_MASK                 (0x300000 << CCU4_CC4_INS_EV2EM_SHIFT)
#   define CCU4_CC4_INS_EV2EM_NA                (0 << CCU4_CC4_INS_EV2EM_SHIFT)         /* No action */
#   define CCU4_CC4_INS_EV2EM_RE                (1 << CCU4_CC4_INS_EV2EM_SHIFT)         /* Signal active on rising edge */
#   define CCU4_CC4_INS_EV2EM_FE                (2 << CCU4_CC4_INS_EV2EM_SHIFT)         /* Signal active on falling edge */
#   define CCU4_CC4_INS_EV2EM_BE                (3 << CCU4_CC4_INS_EV2EM_SHIFT)         /* Signal active on both edges */
#define CCU4_CC4_INS_EV0LM_SHIFT                (22)                                    /* Bit 22: Event 0 Level Selection */
#define CCU4_CC4_INS_EV0LM_MASK                 (1 << CCU4_CC4_INS_EV0LM_SHIFT)
#define CCU4_CC4_INS_EV1LM_SHIFT                (23)                                    /* Bit 23: Event 1 Level Selection */
#define CCU4_CC4_INS_EV1LM_MASK                 (1 << CCU4_CC4_INS_EV1LM_SHIFT)
#define CCU4_CC4_INS_EV2LM_SHIFT                (24)                                    /* Bit 24: Event 2 Level Selection */
#define CCU4_CC4_INS_EV2LM_MASK                 (1 << CCU4_CC4_INS_EV2LM_SHIFT)
#define CCU4_CC4_INS_LPF0M_SHIFT                (25)                                    /* Bits 25-26: Event 0 Low Pass Filter Configuration */
#define CCU4_CC4_INS_LPF0M_MASK                 (3 << CCU4_CC4_INS_LPF0M_SHIFT)
#   define CCU4_CC4_INS_LPF0M_DISABLED          (0 << CCU4_CC4_INS_LPF0M_SHIFT)         /* LPF is disabled */
#   define CCU4_CC4_INS_LPF0M_3CC               (1 << CCU4_CC4_INS_LPF0M_SHIFT)         /* 3 clock cycles of fCCU4 */
#   define CCU4_CC4_INS_LPF0M_5CC               (2 << CCU4_CC4_INS_LPF0M_SHIFT)         /* 5 clock cycles of fCCU4 */
#   define CCU4_CC4_INS_LPF0M_7CC               (3 << CCU4_CC4_INS_LPF0M_SHIFT)         /* 7 clock cycles of fCCU4 */
#define CCU4_CC4_INS_LPF1M_SHIFT                (27)                                    /* Bits 27-28: Event 1 Low Pass Filter Configuration */
#define CCU4_CC4_INS_LPF1M_MASK                 (3 << CCU4_CC4_INS_LPF1M_SHIFT)
#   define CCU4_CC4_INS_LPF1M_DISABLED          (0 << CCU4_CC4_INS_LPF1M_SHIFT)         /* LPF is disabled */
#   define CCU4_CC4_INS_LPF1M_3CC               (1 << CCU4_CC4_INS_LPF1M_SHIFT)         /* 3 clock cycles of fCCU4 */
#   define CCU4_CC4_INS_LPF1M_5CC               (2 << CCU4_CC4_INS_LPF1M_SHIFT)         /* 5 clock cycles of fCCU4 */
#   define CCU4_CC4_INS_LPF1M_7CC               (3 << CCU4_CC4_INS_LPF1M_SHIFT)         /* 7 clock cycles of fCCU4 */
#define CCU4_CC4_INS_LPF2M_SHIFT                (29)                                    /* Bits 29-30: Event 2 Low Pass Filter Configuration */
#define CCU4_CC4_INS_LPF2M_MASK                 (3 << CCU4_CC4_INS_LPF2M_SHIFT)
#   define CCU4_CC4_INS_LPF2M_DISABLED          (0 << CCU4_CC4_INS_LPF2M_SHIFT)         /* LPF is disabled */
#   define CCU4_CC4_INS_LPF2M_3CC               (1 << CCU4_CC4_INS_LPF2M_SHIFT)         /* 3 clock cycles of fCCU4 */
#   define CCU4_CC4_INS_LPF2M_5CC               (2 << CCU4_CC4_INS_LPF2M_SHIFT)         /* 5 clock cycles of fCCU4 */
#   define CCU4_CC4_INS_LPF2M_7CC               (3 << CCU4_CC4_INS_LPF2M_SHIFT)         /* 7 clock cycles of fCCU4 */

/* Connection Matrix Control (CC4yCMC) */

#define CCU4_CC4_CMC_STRTS_SHIFT           (0)                                          /* Bits 0-1: External Start Functionality Selector */
#define CCU4_CC4_CMC_STRTS_MASK            (3 << CCU4_CC4_CMC_STRTS_SHIFT)
#define CCU4_CC4_CMC_ENDS_SHIFT            (2)                                          /* Bits 2-3: External Stop Functionality Selector */
#define CCU4_CC4_CMC_ENDS_MASK             (3 << CCU4_CC4_CMC_ENDS_SHIFT)
#define CCU4_CC4_CMC_CAP0S_SHIFT           (4)                                          /* Bits 4-5: External Capture 0 Functionality Selector */
#define CCU4_CC4_CMC_CAP0S_MASK            (3 << CCU4_CC4_CMC_CAP0S_SHIFT)
#define CCU4_CC4_CMC_CAP1S_SHIFT           (6)                                          /* Bits 6-7: External Capture 1 Functionality Selector */
#define CCU4_CC4_CMC_CAP1S_MASK            (3 << CCU4_CC4_CMC_CAP1S_SHIFT)
#define CCU4_CC4_CMC_GATES_SHIFT           (8)                                          /* Bits 8-9: External Gate Functionality Selector */
#define CCU4_CC4_CMC_GATES_MASK            (3 << CCU4_CC4_CMC_GATES_SHIFT)
#define CCU4_CC4_CMC_UDS_SHIFT             (10)                                         /* Bits 10-11: External Up/Down Functionality Selector */
#define CCU4_CC4_CMC_UDS_MASK              (3 << CCU4_CC4_CMC_UDS_SHIFT)
#define CCU4_CC4_CMC_LDS_SHIFT             (12)                                         /* Bits 12-13: External Timer Load Functionality Selector */
#define CCU4_CC4_CMC_LDS_MASK              (3 << CCU4_CC4_CMC_LDS_SHIFT)
#define CCU4_CC4_CMC_CNTS_SHIFT            (14)                                         /* Bits 14-15: External Count Selector */
#define CCU4_CC4_CMC_CNTS_MASK             (3 << CCU4_CC4_CMC_CNTS_SHIFT)
#define CCU4_CC4_CMC_OFS_SHIFT             (16)                                         /* Bit 16: Override Function Selector */
#define CCU4_CC4_CMC_OFS_MASK              (1 << CCU4_CC4_CMC_OFS_SHIFT)
#define CCU4_CC4_CMC_TS_SHIFT              (17)                                         /* Bit 17: Trap Function Selector */
#define CCU4_CC4_CMC_TS_MASK               (1 << CCU4_CC4_CMC_TS_SHIFT)
#define CCU4_CC4_CMC_MOS_SHIFT             (18)                                         /* Bits 18-19: External Modulation Functionality Selector */
#define CCU4_CC4_CMC_MOS_MASK              (3 << CCU4_CC4_CMC_MOS_SHIFT)
#define CCU4_CC4_CMC_TCE_SHIFT             (20)                                         /* Bit 20: Timer Concatenation Enable */
#define CCU4_CC4_CMC_TCE_MASK              (1 << CCU4_CC4_CMC_TCE_SHIFT)

/* Slice Timer Status (CC4yTCST) */

#define CCU4_CC4_TCST_TRB_SHIFT             (0)                                     /* Bit 0: Timer Run Bit */
#define CCU4_CC4_TCST_TRB_MASK              (1 << CCU4_CC4_TCST_TRB_SHIFT)
#define CCU4_CC4_TCST_CDIR_SHIFT            (1)                                     /* Bit 1: Timer Counting Direction */
#define CCU4_CC4_TCST_CDIR_MASK             (1 << CCU4_CC4_TCST_CDIR_SHIFT)

/* Slice Timer Run Set (CC4yTCSET) */

#define CCU4_CC4_TCSET_TRBS_SHIFT           (0)                                     /* Bit 0: Timer Run Bit set */
#define CCU4_CC4_TCSET_TRBS_MASK            (1 << CCU4_CC4_TCSET_TRBS_SHIFT)

/* Slice Timer Clear (CC4yTCCLR) */

#define CCU4_CC4_TCCLR_TRBC_SHIFT           (0)                                     /* Bit 0: Timer Run Bit Clear */
#define CCU4_CC4_TCCLR_TRBC_MASK            (1 << CCU4_CC4_TCCLR_TRBC_SHIFT)
#define CCU4_CC4_TCCLR_TCC_SHIFT            (1)                                     /* Bit 1: Timer Clear */
#define CCU4_CC4_TCCLR_TCC_MASK             (1 << CCU4_CC4_TCCLR_TCC_SHIFT)
#define CCU4_CC4_TCCLR_DITC_SHIFT           (2)                                     /* Bit 2: Dither Counter Clear */
#define CCU4_CC4_TCCLR_DITC_MASK            (1 << CCU4_CC4_TCCLR_DITC_SHIFT)

/* Slice Timer Control  (CC4yTC) */

#define CCU4_CC4_TC_TCM_SHIFT               (0)                                     /* Bit 0: Timer Counting Mode */
#define CCU4_CC4_TC_TCM_MASK                (1 << CCU4_CC4_TC_TCM_SHIFT)
#define CCU4_CC4_TC_TSSM_SHIFT              (1)                                     /* Bit 1: Timer Single Shot Mode */
#define CCU4_CC4_TC_TSSM_MASK               (1 << CCU4_CC4_TC_TSSM_SHIFT)
#define CCU4_CC4_TC_CLST_SHIFT              (2)                                     /* Bit 2: Shadow Transfer on Clear */
#define CCU4_CC4_TC_CLST_MASK               (1 << CCU4_CC4_TC_CLST_SHIFT)
#define CCU4_CC4_TC_CMOD_SHIFT              (3)                                     /* Bit 3: Capture Compare Mode */
#define CCU4_CC4_TC_CMOD_MASK               (1 << CCU4_CC4_TC_CMOD_SHIFT)
#define CCU4_CC4_TC_ECM_SHIFT               (4)                                     /* Bit 4: Extended Capture Mode */
#define CCU4_CC4_TC_ECM_MASK                (1 << CCU4_CC4_TC_ECM_SHIFT)
#define CCU4_CC4_TC_CAPC_SHIFT              (5)                                     /* Bits 5-6: Clear on Capture Control */
#define CCU4_CC4_TC_CAPC_MASK               (3 << CCU4_CC4_TC_CAPC_SHIFT)
#define CCU4_CC4_TC_ENDM_SHIFT              (8)                                     /* Bits 8-9: Extended Stop Function Control */
#define CCU4_CC4_TC_ENDM_MASK               (3 << CCU4_CC4_TC_ENDM_SHIFT)
#define CCU4_CC4_TC_STRM_SHIFT              (10)                                    /* Bit 10: Extended Start Function Control */
#define CCU4_CC4_TC_STRM_MASK               (1 << CCU4_CC4_TC_STRM_SHIFT)
#define CCU4_CC4_TC_SCE_SHIFT               (11)                                    /* Bit 11: Equal Capture Event enable */
#define CCU4_CC4_TC_SCE_MASK                (1 << CCU4_CC4_TC_SCE_SHIFT)
#define CCU4_CC4_TC_CCS_SHIFT               (12)                                    /* Bit 12: Continuous Capture Enable */
#define CCU4_CC4_TC_CCS_MASK                (1 << CCU4_CC4_TC_CCS_SHIFT)
#define CCU4_CC4_TC_DITHE_SHIFT             (13)                                    /* Bits 13-14: Dither Enable */
#define CCU4_CC4_TC_DITHE_MASK              (3 << CCU4_CC4_TC_DITHE_SHIFT)
#define CCU4_CC4_TC_DIM_SHIFT               (15)                                    /* Bit 15: Dither input selector */
#define CCU4_CC4_TC_DIM_MASK                (1 << CCU4_CC4_TC_DIM_SHIFT)
#define CCU4_CC4_TC_FPE_SHIFT               (16)                                    /* Bit 16: Floating Prescaler enable */
#define CCU4_CC4_TC_FPE_MASK                (1 << CCU4_CC4_TC_FPE_SHIFT)
#define CCU4_CC4_TC_TRAPE_SHIFT             (17)                                    /* Bit 17: TRAP enable */
#define CCU4_CC4_TC_TRAPE_MASK              (1 << CCU4_CC4_TC_TRAPE_SHIFT)
#define CCU4_CC4_TC_TRPSE_SHIFT             (21)                                    /* Bit 21: TRAP Synchronization Enable */
#define CCU4_CC4_TC_TRPSE_MASK              (1 << CCU4_CC4_TC_TRPSE_SHIFT)
#define CCU4_CC4_TC_TRPSW_SHIFT             (22)                                    /* Bit 22: TRAP State Clear Control */
#define CCU4_CC4_TC_TRPSW_MASK              (1 << CCU4_CC4_TC_TRPSW_SHIFT)
#define CCU4_CC4_TC_EMS_SHIFT               (23)                                    /* Bit 23: External Modulation Synchronization */
#define CCU4_CC4_TC_EMS_MASK                (1 << CCU4_CC4_TC_EMS_SHIFT)
#define CCU4_CC4_TC_EMT_SHIFT               (24)                                    /* Bit 24: External Modulation Type */
#define CCU4_CC4_TC_EMT_MASK                (1 << CCU4_CC4_TC_EMT_SHIFT)
#define CCU4_CC4_TC_MCME_SHIFT              (25)                                    /* Bit 25: Multi Channel Mode Enable */
#define CCU4_CC4_TC_MCME_MASK               (1 << CCU4_CC4_TC_MCME_SHIFT)

/* Passive Level Config (CC4yPSL) */

#define CCU4_CC4_PSL_PSL_SHIFT               (0)                                    /* Bit 0: Output Passive Level */
#define CCU4_CC4_PSL_PSL_MASK                (1 << CCU4_CC4_PSL_PSL_SHIFT)

/* Dither Config (CC4yDIT) */

#define CCU4_CC4_DIT_DCV_SHIFT               (0)                                    /* Bits 0-3: Dither compare Value */
#define CCU4_CC4_DIT_DCV_MASK                (15 << CCU4_CC4_DIT_DCV_SHIFT)
#define CCU4_CC4_DIT_DCNT_SHIFT              (8)                                    /* Bits 8-11: Dither counter actual value */
#define CCU4_CC4_DIT_DCNT_MASK               (15 << CCU4_CC4_DIT_DCNT_SHIFT)

/* Dither Shadow Register (CC4yDITS) */

#define CCU4_CC4_DITS_DCVS_SHIFT             (0)                                    /* Bits 0-3: Dither Shadow Compare Value */
#define CCU4_CC4_DITS_DCVS_MASK              (15 << CCU4_CC4_DITS_DCVS_SHIFT)

/* Prescaler Control (CC4yPSC) */

#define CCU4_CC4_PSC_PSIV_SHIFT              (0)                                    /* Bits 0-3: Passive State Configuration */
#define CCU4_CC4_PSC_PSIV_MASK               (15 << CCU4_CC4_PSC_PSIV_SHIFT)

/* Floating Prescaler Control (CC4yFPC) */

#define CCU4_CC4_FPC_PCMP_SHIFT              (0)                                    /* Bits 0-3: Floating Prescaler Compare Value */
#define CCU4_CC4_FPC_PCMP_MASK               (15 << CCU4_CC4_FPC_PCMP_SHIFT)
#define CCU4_CC4_FPC_PVAL_SHIFT              (8)                                    /* Bits 8-11: Actual Prescaler Value */
#define CCU4_CC4_FPC_PVAL_MASK               (15 << CCU4_CC4_FPC_PVAL_SHIFT)

/* Floating Prescaler Shadow (CC4yFPCS) */

#define CCU4_CC4_FPCS_PCMP_SHIFT             (0)                                    /* Bits 0-3: Passive Comparator Pattern */
#define CCU4_CC4_FPCS_PCMP_MASK              (15 << CCU4_CC4_FPCS_PCMP_SHIFT)

/* Timer Period Value (CC4yPR) */

#define CCU4_CC4_PR_PR_SHIFT                 (0)                                    /* Bits 0-15: Period Register */
#define CCU4_CC4_PR_PR_MASK                  (0xFFFF << CCU4_CC4_PR_PR_SHIFT)

/* Timer Shadow Period Value (CC4yPRS) */

#define CCU4_CC4_PRS_PRS_SHIFT               (0)                                    /* Bits 0-15: Period Register */
#define CCU4_CC4_PRS_PRS_MASK                (0xFFFF << CCU4_CC4_PRS_PRS_SHIFT)

/* Timer Compare Value (CC4yCR) */

#define CCU4_CC4_CR_CR_SHIFT                 (0)                                    /* Bits 0-15: Compare Register Value */
#define CCU4_CC4_CR_CR_MASK                  (0xFFFF << CCU4_CC4_CR_CR_SHIFT)

/* Timer Shadow Compare Value (CC4yCRS) */

#define CCU4_CC4_CRS_CRS_SHIFT               (0)                                    /* Bits 0-15: Compare Register */
#define CCU4_CC4_CRS_CRS_MASK                (0xFFFF << CCU4_CC4_CRS_CRS_SHIFT)

/* Timer Value (CC4yTIMER) */

#define CCU4_CC4_TIMER_TVAL_SHIFT            (0)                                    /* Bits 0-15: Timer Value */
#define CCU4_CC4_TIMER_TVAL_MASK             (0xFFFF << CCU4_CC4_TIMER_TVAL_SHIFT)

/* Capture Register 0 (CC4yC0V) */

#define CCU4_CC4_C0V_CAPTV_SHIFT              (0)                                   /* Bits 0-15: Capture Value */
#define CCU4_CC4_C0V_CAPTV_MASK               (0xFFFF << CCU4_CC4_C0V_CAPTV_SHIFT)
#define CCU4_CC4_C0V_FPCV_SHIFT               (16)                                  /* Bits 16-19: Prescaler Value */
#define CCU4_CC4_C0V_FPCV_MASK                (15 << CCU4_CC4_C0V_FPCV_SHIFT)
#define CCU4_CC4_C0V_FFL_SHIFT                (20)                                  /* Bit 20: Full Flag */
#define CCU4_CC4_C0V_FFL_MASK                 (1 << CCU4_CC4_C0V_FFL_SHIFT)

/* Capture Register 1 (CC4yC1V) */

#define CCU4_CC4_C1V_CAPTV_SHIFT              (0)                                   /* Bits 0-15: Capture Value */
#define CCU4_CC4_C1V_CAPTV_MASK               (0xFFFF << CCU4_CC4_C1V_CAPTV_SHIFT)
#define CCU4_CC4_C1V_FPCV_SHIFT               (16)                                  /* Bits 16-19: Prescaler Value */
#define CCU4_CC4_C1V_FPCV_MASK                (15 << CCU4_CC4_C1V_FPCV_SHIFT)
#define CCU4_CC4_C1V_FFL_SHIFT                (20)                                  /* Bit 20: Full Flag */
#define CCU4_CC4_C1V_FFL_MASK                 (1 << CCU4_CC4_C1V_FFL_SHIFT)

/* Capture Register 2 (CC4yC2V) */

#define CCU4_CC4_C2V_CAPTV_SHIFT              (0)                                   /* Bits 0-15: Capture Value */
#define CCU4_CC4_C2V_CAPTV_MASK               (0xFFFF << CCU4_CC4_C2V_CAPTV_SHIFT)
#define CCU4_CC4_C2V_FPCV_SHIFT               (16)                                  /* Bits 16-19: Prescaler Value */
#define CCU4_CC4_C2V_FPCV_MASK                (15 << CCU4_CC4_C2V_FPCV_SHIFT)
#define CCU4_CC4_C2V_FFL_SHIFT                (20)                                  /* Bit 20: Full Flag */
#define CCU4_CC4_C2V_FFL_MASK                 (1 << CCU4_CC4_C2V_FFL_SHIFT)

/* Capture Register 3 (CC4yC3V) */

#define CCU4_CC4_C3V_CAPTV_SHIFT              (0)                                   /* Bits 0-15: Capture Value */
#define CCU4_CC4_C3V_CAPTV_MASK               (0xFFFF << CCU4_CC4_C3V_CAPTV_SHIFT)
#define CCU4_CC4_C3V_FPCV_SHIFT               (16)                                  /* Bits 16-19: Prescaler Value */
#define CCU4_CC4_C3V_FPCV_MASK                (15 << CCU4_CC4_C3V_FPCV_SHIFT)
#define CCU4_CC4_C3V_FFL_SHIFT                (20)                                  /* Bit 20: Full Flag */
#define CCU4_CC4_C3V_FFL_MASK                 (1 << CCU4_CC4_C3V_FFL_SHIFT)

/* Interrupt Status (CC4yINTS) */

#define CCU4_CC4_INTS_PMUS_SHIFT             (0)                                    /* Bit 0: Period Match while Counting Up */
#define CCU4_CC4_INTS_PMUS_MASK              (1 << CCU4_CC4_INTS_PMUS_SHIFT)
#define CCU4_CC4_INTS_OMDS_SHIFT             (1)                                    /* Bit 1: One Match while Counting Down */
#define CCU4_CC4_INTS_OMDS_MASK              (1 << CCU4_CC4_INTS_OMDS_SHIFT)
#define CCU4_CC4_INTS_CMUS_SHIFT             (2)                                    /* Bit 2: Compare Match while Counting Up */
#define CCU4_CC4_INTS_CMUS_MASK              (1 << CCU4_CC4_INTS_CMUS_SHIFT)
#define CCU4_CC4_INTS_CMDS_SHIFT             (3)                                    /* Bit 3: Compare Match while Counting Down */
#define CCU4_CC4_INTS_CMDS_MASK              (1 << CCU4_CC4_INTS_CMDS_SHIFT)
#define CCU4_CC4_INTS_E0AS_SHIFT             (8)                                    /* Bit 8: Event 0 Detection Status */
#define CCU4_CC4_INTS_E0AS_MASK              (1 << CCU4_CC4_INTS_E0AS_SHIFT)
#define CCU4_CC4_INTS_E1AS_SHIFT             (9)                                    /* Bit 9: Event 1 Detection Status */
#define CCU4_CC4_INTS_E1AS_MASK              (1 << CCU4_CC4_INTS_E1AS_SHIFT)
#define CCU4_CC4_INTS_E2AS_SHIFT             (10)                                   /* Bit 10: Event 2 Detection Status */
#define CCU4_CC4_INTS_E2AS_MASK              (1 << CCU4_CC4_INTS_E2AS_SHIFT)
#define CCU4_CC4_INTS_TRPF_SHIFT             (11)                                   /* Bit 11: Trap Flag Status */
#define CCU4_CC4_INTS_TRPF_MASK              (1 << CCU4_CC4_INTS_TRPF_SHIFT)

/* Interrupt Enable Control (CC4yINTE) */

#define CCU4_CC4_INTE_PME_SHIFT              (0)                                    /* Bit 0: Period match while counting up enable */
#define CCU4_CC4_INTE_PME_MASK               (1 << CCU4_CC4_INTE_PME_SHIFT)
#define CCU4_CC4_INTE_OME_SHIFT              (1)                                    /* Bit 1: One match while counting down enable */
#define CCU4_CC4_INTE_OME_MASK               (1 << CCU4_CC4_INTE_OME_SHIFT)
#define CCU4_CC4_INTE_CMUE_SHIFT             (2)                                    /* Bit 2: Compare match while counting up enable */
#define CCU4_CC4_INTE_CMUE_MASK              (1 << CCU4_CC4_INTE_CMUE_SHIFT)
#define CCU4_CC4_INTE_CMDE_SHIFT             (3)                                    /* Bit 3: Compare match while counting down enable */
#define CCU4_CC4_INTE_CMDE_MASK              (1 << CCU4_CC4_INTE_CMDE_SHIFT)
#define CCU4_CC4_INTE_E0AE_SHIFT             (8)                                    /* Bit 8: Event 0 interrupt enable */
#define CCU4_CC4_INTE_E0AE_MASK              (1 << CCU4_CC4_INTE_E0AE_SHIFT)
#define CCU4_CC4_INTE_E1AE_SHIFT             (9)                                    /* Bit 9: Event 1 interrupt enable */
#define CCU4_CC4_INTE_E1AE_MASK              (1 << CCU4_CC4_INTE_E1AE_SHIFT)
#define CCU4_CC4_INTE_E2AE_SHIFT             (10)                                   /* Bit 10: Event 2 interrupt enable */
#define CCU4_CC4_INTE_E2AE_MASK              (1 << CCU4_CC4_INTE_E2AE_SHIFT)

/* Service Request Selector (CC4ySRS) */

#define CCU4_CC4_SRS_POSR_SHIFT              (0)                                    /* Bits 0-1: Period/One match Service request selector */
#define CCU4_CC4_SRS_POSR_MASK               (3 << CCU4_CC4_SRS_POSR_SHIFT)
#define CCU4_CC4_SRS_CMSR_SHIFT              (2)                                    /* Bits 2-3: Compare match Service request selector */
#define CCU4_CC4_SRS_CMSR_MASK               (3 << CCU4_CC4_SRS_CMSR_SHIFT)
#define CCU4_CC4_SRS_E0SR_SHIFT              (8)                                    /* Bits 8-9: Event 0 Service request selector */
#define CCU4_CC4_SRS_E0SR_MASK               (3 << CCU4_CC4_SRS_E0SR_SHIFT)
#define CCU4_CC4_SRS_E1SR_SHIFT              (10)                                   /* Bits 10-11: Event 1 Service request selector */
#define CCU4_CC4_SRS_E1SR_MASK               (3 << CCU4_CC4_SRS_E1SR_SHIFT)
#define CCU4_CC4_SRS_E2SR_SHIFT              (12)                                   /* Bits 12-13: Event 2 Service request selector */
#define CCU4_CC4_SRS_E2SR_MASK               (3 << CCU4_CC4_SRS_E2SR_SHIFT)

/* Interrupt Status Set (CC4ySWS) */

#define CCU4_CC4_SWS_SPM_SHIFT               (0)                                    /* Bit 0: Period match while counting up set */
#define CCU4_CC4_SWS_SPM_MASK                (1 << CCU4_CC4_SWS_SPM_SHIFT)
#define CCU4_CC4_SWS_SOM_SHIFT               (1)                                    /* Bit 1: One match while counting down set */
#define CCU4_CC4_SWS_SOM_MASK                (1 << CCU4_CC4_SWS_SOM_SHIFT)
#define CCU4_CC4_SWS_SCMU_SHIFT              (2)                                    /* Bit 2: Compare match while counting up set */
#define CCU4_CC4_SWS_SCMU_MASK               (1 << CCU4_CC4_SWS_SCMU_SHIFT)
#define CCU4_CC4_SWS_SCMD_SHIFT              (3)                                    /* Bit 3: Compare match while counting down set */
#define CCU4_CC4_SWS_SCMD_MASK               (1 << CCU4_CC4_SWS_SCMD_SHIFT)
#define CCU4_CC4_SWS_SE0A_SHIFT              (8)                                    /* Bit 8: Event 0 detection set */
#define CCU4_CC4_SWS_SE0A_MASK               (1 << CCU4_CC4_SWS_SE0A_SHIFT)
#define CCU4_CC4_SWS_SE1A_SHIFT              (9)                                    /* Bit 9: Event 1 detection set */
#define CCU4_CC4_SWS_SE1A_MASK               (1 << CCU4_CC4_SWS_SE1A_SHIFT)
#define CCU4_CC4_SWS_SE2A_SHIFT              (10)                                   /* Bit 10: Event 2 detection set */
#define CCU4_CC4_SWS_SE2A_MASK               (1 << CCU4_CC4_SWS_SE2A_SHIFT)
#define CCU4_CC4_SWS_STRPF_SHIFT             (11)                                   /* Bit 11: Trap Flag status set */
#define CCU4_CC4_SWS_STRPF_MASK              (1 << CCU4_CC4_SWS_STRPF_SHIFT)

/* Interrupt Status Clear (CC4ySWR) */

#define CCU4_CC4_SWR_RPM_SHIFT               (0)                                    /* Bit 0: Period match while counting up clear */
#define CCU4_CC4_SWR_RPM_MASK                (1 << CCU4_CC4_SWR_RPM_SHIFT)
#define CCU4_CC4_SWR_ROM_SHIFT               (1)                                    /* Bit 1: One match while counting down clear */
#define CCU4_CC4_SWR_ROM_MASK                (1 << CCU4_CC4_SWR_ROM_SHIFT)
#define CCU4_CC4_SWR_RCMU_SHIFT              (2)                                    /* Bit 2: Compare match while counting up clear */
#define CCU4_CC4_SWR_RCMU_MASK               (1 << CCU4_CC4_SWR_RCMU_SHIFT)
#define CCU4_CC4_SWR_RCMD_SHIFT              (3)                                    /* Bit 3: Compare match while counting down clear */
#define CCU4_CC4_SWR_RCMD_MASK               (1 << CCU4_CC4_SWR_RCMD_SHIFT)
#define CCU4_CC4_SWR_RE0A_SHIFT              (8)                                    /* Bit 8: Event 0 detection clear */
#define CCU4_CC4_SWR_RE0A_MASK               (1 << CCU4_CC4_SWR_RE0A_SHIFT)
#define CCU4_CC4_SWR_RE1A_SHIFT              (9)                                    /* Bit 9: Event 1 detection clear */
#define CCU4_CC4_SWR_RE1A_MASK               (1 << CCU4_CC4_SWR_RE1A_SHIFT)
#define CCU4_CC4_SWR_RE2A_SHIFT              (10)                                   /* Bit 10: Event 2 detection clear */
#define CCU4_CC4_SWR_RE2A_MASK               (1 << CCU4_CC4_SWR_RE2A_SHIFT)
#define CCU4_CC4_SWR_RTRPF_SHIFT             (11)                                   /* Bit 11: Trap Flag status clear */
#define CCU4_CC4_SWR_RTRPF_MASK              (1 << CCU4_CC4_SWR_RTRPF_SHIFT)

/* Extended Read Back 0 (CC4yECRD0) */

#define CCU4_CC4_ECRD0_CAPV_SHIFT            (0)                                    /* Bits 0-15: Timer Capture Value */
#define CCU4_CC4_ECRD0_CAPV_MASK             (0xFFFF << CCU4_CC4_ECRD0_CAPV_SHIFT)
#define CCU4_CC4_ECRD0_FPCV_SHIFT            (16)                                   /* Bits 16-19: Prescaler Capture value */
#define CCU4_CC4_ECRD0_FPCV_MASK             (15 << CCU4_CC4_ECRD0_FPCV_SHIFT)
#define CCU4_CC4_ECRD0_SPTR_SHIFT            (20)                                   /* Bits 20-21: Slice pointer */
#define CCU4_CC4_ECRD0_SPTR_MASK             (3 << CCU4_CC4_ECRD0_SPTR_SHIFT)
#define CCU4_CC4_ECRD0_VPTR_SHIFT            (22)                                   /* Bits 22-23: Capture register pointer */
#define CCU4_CC4_ECRD0_VPTR_MASK             (3 << CCU4_CC4_ECRD0_VPTR_SHIFT)
#define CCU4_CC4_ECRD0_FFL_SHIFT             (24)                                   /* Bit 24: Full Flag */
#define CCU4_CC4_ECRD0_FFL_MASK              (1 << CCU4_CC4_ECRD0_FFL_SHIFT)
#define CCU4_CC4_ECRD0_LCV_SHIFT             (25)                                   /* Bit 25: Lost Capture Value */
#define CCU4_CC4_ECRD0_LCV_MASK              (1 << CCU4_CC4_ECRD0_LCV_SHIFT)

/* Extended Read Back 1 (CC4yECRD1) */

#define CCU4_CC4_ECRD1_CAPV_SHIFT            (0)                                    /* Bits 0-15: Timer Capture Value */
#define CCU4_CC4_ECRD1_CAPV_MASK             (0xFFFF << CCU4_CC4_ECRD1_CAPV_SHIFT)
#define CCU4_CC4_ECRD1_FPCV_SHIFT            (16)                                   /* Bits 16-19: Prescaler Capture value */
#define CCU4_CC4_ECRD1_FPCV_MASK             (15 << CCU4_CC4_ECRD1_FPCV_SHIFT)
#define CCU4_CC4_ECRD1_SPTR_SHIFT            (20)                                   /* Bits 20-21: Slice pointer */
#define CCU4_CC4_ECRD1_SPTR_MASK             (3 << CCU4_CC4_ECRD1_SPTR_SHIFT)
#define CCU4_CC4_ECRD1_VPTR_SHIFT            (22)                                   /* Bits 22-23: Capture register pointer */
#define CCU4_CC4_ECRD1_VPTR_MASK             (3 << CCU4_CC4_ECRD1_VPTR_SHIFT)
#define CCU4_CC4_ECRD1_FFL_SHIFT             (24)                                   /* Bit 24: Full Flag */
#define CCU4_CC4_ECRD1_FFL_MASK              (1 << CCU4_CC4_ECRD1_FFL_SHIFT)
#define CCU4_CC4_ECRD1_LCV_SHIFT             (25)                                   /* Bit 25: Lost Capture Value */
#define CCU4_CC4_ECRD1_LCV_MASK              (1 << CCU4_CC4_ECRD1_LCV_SHIFT)

#endif /* __ARCH_ARM_SRC_XMC4_HARDWARE_XMC4_CCU4_H */
