/****************************************************************************
 *  arch/arm/src/s32k1xx/s32k1xx_pindma.c
 *
 *   Copyright (C) 2019 Gregory Nutt. All rights reserved.
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/arch.h>
#include <nuttx/arch.h>
#include "up_arch.h"
#include "up_internal.h"

#include "s32k1xx_pin.h"

#ifdef CONFIG_S32K1XX_DMA

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/************************************************************************************
 * Name: s32k1xx_pindmaenable
 *
 * Description:
 *   Enable DMA for specified pin
 *
 ************************************************************************************/

void s32k1xx_pindmaenable(uint32_t pinset)
{
  uintptr_t    base;
  uint32_t     regval;
  unsigned int port;
  unsigned int pin;

  /* Get the port number and pin number */

  port = (pinset & _PIN_PORT_MASK) >> _PIN_PORT_SHIFT;
  pin  = (pinset & _PIN_MASK)      >> _PIN_SHIFT;

  DEBUGASSERT(port < S32K1XX_NPORTS);
  if (port < S32K1XX_NPORTS)
    {
      /* Get the base address of PORT block for this port */

      base =  S32K1XX_PORT_BASE(port);

      /* Modify the IRQC field of the port PCR register in order to enable DMA. */

      regval = getreg32(base + S32K1XX_PORT_PCR_OFFSET(pin));
      regval &= ~PORT_PCR_IRQC_MASK;

      switch (pinset & _PIN_INT_MASK)
        {
          case PIN_DMA_RISING : /* DMA Request on rising edge */
            regval |= PORT_PCR_IRQC_DMARISING;
            break;

          case PIN_DMA_FALLING : /* DMA Request on falling edge */
            regval |= PORT_PCR_IRQC_DMAFALLING;
            break;

          case PIN_DMA_BOTH : /* DMA Request on either edge */
            regval |= PORT_PCR_IRQC_DMABOTH;
            break;

          default:
            return;
        }

      putreg32(regval, base + S32K1XX_PORT_PCR_OFFSET(pin));
    }
}

/************************************************************************************
 * Name: s32k1xx_pindmadisable
 *
 * Description:
 *   Disable DMA for specified pin
 *
 ************************************************************************************/

void s32k1xx_pindmadisable(uint32_t pinset)
{
  uintptr_t    base;
  uint32_t     regval;
  unsigned int port;
  unsigned int pin;

  /* Get the port number and pin number */

  port = (pinset & _PIN_PORT_MASK) >> _PIN_PORT_SHIFT;
  pin  = (pinset & _PIN_MASK)      >> _PIN_SHIFT;

  DEBUGASSERT(port < S32K1XX_NPORTS);
  if (port < S32K1XX_NPORTS)
    {
      /* Get the base address of PORT block for this port */

      base =  S32K1XX_PORT_BASE(port);

      /* Clear the IRQC field of the port PCR register in order to disable DMA. */

      regval = getreg32(base + S32K1XX_PORT_PCR_OFFSET(pin));
      regval &= ~PORT_PCR_IRQC_MASK;
      putreg32(regval, base + S32K1XX_PORT_PCR_OFFSET(pin));
    }
}

#endif
