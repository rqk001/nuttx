/************************************************************************************
 * arch/arm/src/am335x/hardware/am335x_wdog.h
 *
 *   Copyright (C) 2019 Petro Karashchenko. All rights reserved.
 *   Author: Petro Karashchenko <petro.karashchenko@gmail.com>
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

#ifndef __ARCH_ARM_SRC_AM335X_HARDWARE_AM335X_WDOG_H
#define __ARCH_ARM_SRC_AM335X_HARDWARE_AM335X_WDOG_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>
#include "hardware/am335x_memorymap.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* Register offsets *****************************************************************/

#define AM335X_WDT_IDR_OFFSET           0x0000  /* Watchdog Identification Register */
#define AM335X_WDT_DSC_OFFSET           0x0010  /* Watchdog System Control Register */
#define AM335X_WDT_DST_OFFSET           0x0014  /* Watchdog Status Register */
#define AM335X_WDT_ISR_OFFSET           0x0018  /* Watchdog Interrupt Status Register */
#define AM335X_WDT_IER_OFFSET           0x001c  /* Watchdog Interrupt Enable Register */
#define AM335X_WDT_CLR_OFFSET           0x0024  /* Watchdog Control Register */
#define AM335X_WDT_CRR_OFFSET           0x0028  /* Watchdog Counter Register */
#define AM335X_WDT_LDR_OFFSET           0x002c  /* Watchdog Load Register */
#define AM335X_WDT_TGR_OFFSET           0x0030  /* Watchdog Trigger Register  */
#define AM335X_WDT_WPS_OFFSET           0x0034  /* Watchdog Write Posting Bits Register */
#define AM335X_WDT_DLY_OFFSET           0x0044  /* Watchdog Delay Configuration Register */
#define AM335X_WDT_SPR_OFFSET           0x0048  /* Watchdog Start/Stop Register */
#define AM335X_WDT_IRQ_STAT_RAW_OFFSET  0x0054  /* Watchdog Raw Interrupt Status Register */
#define AM335X_WDT_IRQ_STAT_OFFSET      0x0058  /* Watchdog Interrupt Status Register */
#define AM335X_WDT_IRQ_EN_SET_OFFSET    0x005c  /* Watchdog Interrupt Enable Set Register */
#define AM335X_WDT_IRQ_EN_CLR_OFFSET    0x0060  /* Watchdog Interrupt Enable Clear Register */

/* Register addresses ***************************************************************/

#define AM335X_WDT_IDR                  (AM335X_WDT1_VADDR + AM335X_WDT_IDR_OFFSET)
#define AM335X_WDT_DSC                  (AM335X_WDT1_VADDR + AM335X_WDT_DSC_OFFSET)
#define AM335X_WDT_DST                  (AM335X_WDT1_VADDR + AM335X_WDT_DST_OFFSET)
#define AM335X_WDT_ISR                  (AM335X_WDT1_VADDR + AM335X_WDT_ISR_OFFSET)
#define AM335X_WDT_IER                  (AM335X_WDT1_VADDR + AM335X_WDT_IER_OFFSET)
#define AM335X_WDT_CLR                  (AM335X_WDT1_VADDR + AM335X_WDT_CLR_OFFSET)
#define AM335X_WDT_CRR                  (AM335X_WDT1_VADDR + AM335X_WDT_CRR_OFFSET)
#define AM335X_WDT_LDR                  (AM335X_WDT1_VADDR + AM335X_WDT_LDR_OFFSET)
#define AM335X_WDT_TGR                  (AM335X_WDT1_VADDR + AM335X_WDT_TGR_OFFSET)
#define AM335X_WDT_WPS                  (AM335X_WDT1_VADDR + AM335X_WDT_WPS_OFFSET)
#define AM335X_WDT_DLY                  (AM335X_WDT1_VADDR + AM335X_WDT_DLY_OFFSET)
#define AM335X_WDT_SPR                  (AM335X_WDT1_VADDR + AM335X_WDT_SPR_OFFSET)
#define AM335X_WDT_IRQ_STAT_RAW         (AM335X_WDT1_VADDR + AM335X_WDT_IRQ_STAT_RAW_OFFSET)
#define AM335X_WDT_IRQ_STAT             (AM335X_WDT1_VADDR + AM335X_WDT_IRQ_STAT_OFFSET)
#define AM335X_WDT_IRQ_EN_SET           (AM335X_WDT1_VADDR + AM335X_WDT_IRQ_EN_SET_OFFSET)
#define AM335X_WDT_IRQ_EN_CLR           (AM335X_WDT1_VADDR + AM335X_WDT_IRQ_EN_CLR_OFFSET)

/* Register bit definitions *********************************************************/

/* Watchdog System Control Register */

#define WDT_DSC_SOFT_RST                (1 << 1)  /* Bit 1:  Watchdog Software Reset */
#define WDT_DSC_IDLE_SHIFT              (3)  /* Bit 3-4:  Watchdog Idle Mode */
#  define WDT_DSC_IDLE_FORCE            (0 << WDT_DSC_IDLE_SHIFT)  /* Force-idle Mode */
#  define WDT_DSC_IDLE_NO               (1 << WDT_DSC_IDLE_SHIFT)  /* No-idle Mode */
#  define WDT_DSC_IDLE_SMART            (2 << WDT_DSC_IDLE_SHIFT)  /* Smart-idle Mode */
#  define WDT_DSC_IDLE_SMART_WKUP       (3 << WDT_DSC_IDLE_SHIFT)  /* Smart-idle Wakeup-capable Mode */
#define WDT_DSC_EMU_FREE                (1 << 5)  /* Bit 5:  Watchdog DEBUG Disable */

/* Watchdog Status Register */

#define WDT_DST_RST_DONE                (1 << 0)  /* Bit 0:  Watchdog Reset Completed */

/* Watchdog Interrupt Registers */

#define WDT_IRQ_FLAG_OVERFLOW           (1 << 0)  /* Bit 0:  Overflow Interrupt Pending */
#define WDT_IRQ_FLAG_DELAY              (1 << 1)  /* Bit 1:  Delay Interrupt Pending */

/* Watchdog Control Register */

#define WDT_CLR_PTV_SHIFT               (2)  /* Bits 2-4:  Prescaler Value */
#define WDT_CLR_PTV_MASK                (7 << WDT_CLR_PTV_SHIFT)
#  define WDT_CLR_PTV(n)                ((uint32_t)(n) << WDT_CLR_PTV_SHIFT)
#define WDT_CLR_PRE_ENABLE              (1 << 5)  /* Bit 5:  Prescaler Enabled */

/* Watchdog Write Posting Bits Register */

#define WDT_WPS_W_PEND_WCLR             (1 << 0)  /* Bit 0:  Write Pending for Register WCLR */
#define WDT_WPS_W_PEND_WCRR             (1 << 1)  /* Bit 1:  Write pending for register WCRR */
#define WDT_WPS_W_PEND_WLDR             (1 << 2)  /* Bit 2:  Write pending for register WLDR */
#define WDT_WPS_W_PEND_WTGR             (1 << 3)  /* Bit 3:  Write pending for register WTGR */
#define WDT_WPS_W_PEND_WSPR             (1 << 4)  /* Bit 4:  Write pending for register WSPR */
#define WDT_WPS_W_PEND_WDLY             (1 << 5)  /* Bit 5:  Write pending for register WDLY */

/* Watchdog Start/Stop Register */

#define WDT_SPR_START_FEED_A            (0x0000bbbb)
#define WDT_SPR_START_FEED_B            (0x00004444)
#define WDT_SPR_STOP_FEED_A             (0x0000aaaa)
#define WDT_SPR_STOP_FEED_B             (0x00005555)

#endif /* __ARCH_ARM_SRC_AM335X_HARDWARE_AM335X_WDOG_H */
