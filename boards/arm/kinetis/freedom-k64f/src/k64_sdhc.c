/****************************************************************************
 * boards/arm/kinetis/freedom-k64f/src/k64_sdhc.c
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

/* A micro Secure Digital (SD) card slot is available on the FRDM-K64F
 * connected to the SD Host Controller (SDHC) signals of the MCU.
 * This slot will accept micro format SD memory cards.
 * The SD card detect pin (PTE6) is an open switch that shorts with VDD when
 * card is inserted.
 *
 *   ------------ ------------- --------
 *    SD Card Slot Board Signal  K64F Pin
 *    ------------ ------------- --------
 *    DAT0         SDHC0_D0      PTE0
 *    DAT1         SDHC0_D1      PTE1
 *    DAT2         SDHC0_D2      PTE5
 *    CD/DAT3      SDHC0_D3      PTE4
 *    CMD          SDHC0_CMD     PTE3
 *    CLK          SDHC0_DCLK    PTE2
 *    SWITCH       D_CARD_DETECT PTE6
 *    ------------ ------------- --------
 *
 * There is no Write Protect pin available to the K64F.
 */

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdbool.h>
#include <stdio.h>
#include <debug.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/sdio.h>
#include <nuttx/mmcsd.h>

#include "kinetis.h"

#include "freedom-k64f.h"

#ifdef HAVE_MMCSD

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure holds static information unique to one SDHC peripheral */

struct k64_sdhc_state_s
{
  struct sdio_dev_s *sdhc;    /* R/W device handle */
  bool inserted;              /* TRUE: card is inserted */
};

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* HSCMI device state */

static struct k64_sdhc_state_s g_sdhc;

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: k64_mediachange
 ****************************************************************************/

static void k64_mediachange(void)
{
  bool inserted;

  /* Get the current value of the card detect pin.  This pin is pulled up on
   * board.  So low means that a card is present.
   */

  inserted = !kinetis_gpioread(GPIO_SD_CARDDETECT);
  mcinfo("inserted: %s\n", inserted ? "Yes" : "No");

  /* Has the pin changed state? */

  if (inserted != g_sdhc.inserted)
    {
      mcinfo("Media change: %d->%d\n",  g_sdhc.inserted, inserted);

      /* Yes.. perform the appropriate action (this might need some debounce). */

      g_sdhc.inserted = inserted;
      sdhc_mediachange(g_sdhc.sdhc, inserted);

#ifdef CONFIG_FRDMK64F_SDHC_AUTOMOUNT
      /* Let the automounter know about the insertion event */

      k64_automount_event(k64_cardinserted());
#endif
    }
}

/****************************************************************************
 * Name: k64_cdinterrupt
 ****************************************************************************/

static int k64_cdinterrupt(int irq, FAR void *context, FAR void *arg)
{
  /* All of the work is done by k64_mediachange() */

  k64_mediachange();
  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: k64_sdhc_initialize
 *
 * Description:
 *   Inititialize the SDHC SD card slot
 *
 ****************************************************************************/

int k64_sdhc_initialize(void)
{
  int ret;

  /* Configure GPIO pins */

  kinetis_pinconfig(GPIO_SD_CARDDETECT);

  /* Attached the card detect interrupt (but don't enable it yet) */

  (void)kinetis_pinirqattach(GPIO_SD_CARDDETECT, k64_cdinterrupt, NULL);

  /* Configure the write protect GPIO -- None */

  /* Mount the SDHC-based MMC/SD block driver */

  /* First, get an instance of the SDHC interface */

  mcinfo("Initializing SDHC slot %d\n", MMCSD_SLOTNO);

  g_sdhc.sdhc = sdhc_initialize(MMCSD_SLOTNO);
  if (!g_sdhc.sdhc)
    {
      mcerr("ERROR: Failed to initialize SDHC slot %d\n", MMCSD_SLOTNO);
      return -ENODEV;
    }

  /* Now bind the SDHC interface to the MMC/SD driver */

  mcinfo("Bind SDHC to the MMC/SD driver, minor=%d\n", MMSCD_MINOR);

  ret = mmcsd_slotinitialize(MMSCD_MINOR, g_sdhc.sdhc);
  if (ret != OK)
    {
      syslog(LOG_ERR, "ERROR: Failed to bind SDHC to the MMC/SD driver: %d\n",
             ret);
      return ret;
    }

  syslog(LOG_INFO, "Successfully bound SDHC to the MMC/SD driver\n");

  /* Handle the initial card state */

  k64_mediachange();

  /* Enable CD interrupts to handle subsequent media changes */

  kinetis_pinirqenable(GPIO_SD_CARDDETECT);
  return OK;
}

/****************************************************************************
 * Name: k64_cardinserted
 *
 * Description:
 *   Check if a card is inserted into the SDHC slot
 *
 ****************************************************************************/

#ifdef HAVE_AUTOMOUNTER
bool k64_cardinserted(void)
{
  bool inserted;

  /* Get the current value of the card detect pin.  This pin is pulled up on
   * board.  So low means that a card is present.
   */

  inserted = !kinetis_gpioread(GPIO_SD_CARDDETECT);
  mcinfo("inserted: %s\n", inserted ? "Yes" : "No");
  return inserted;
}
#endif

/****************************************************************************
 * Name: k64_writeprotected
 *
 * Description:
 *   Check if a card is inserted into the SDHC slot
 *
 ****************************************************************************/

#ifdef HAVE_AUTOMOUNTER
bool k64_writeprotected(void)
{
  /* There are no write protect pins */

  return false;
}
#endif

#endif /* HAVE_MMCSD */
