/****************************************************************************
 * arch/arm/src/lc823450/lc823450_adc.c
 *
 *   Copyright 2014,2015,2017 Sony Video & Sound Products Inc.
 *   Author: Masayuki Ishikawa <Masayuki.Ishikawa@jp.sony.com>
 *   Author: Nobutaka Toyoshima <Nobutaka.Toyoshima@jp.sony.com>
 *   Author: Satoshi Mihara <Satoshi.Mihara@jp.sony.com>
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

#include <stdio.h>
#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <debug.h>
#include <unistd.h>

#include <arch/board/board.h>

#include <nuttx/arch.h>
#include <nuttx/irq.h>
#include <nuttx/kmalloc.h>
#include <nuttx/fs/ioctl.h>
#include <nuttx/analog/adc.h>
#include <nuttx/analog/ioctl.h>
#include <nuttx/semaphore.h>

#include "up_arch.h"
#include "lc823450_adc.h"
#include "lc823450_syscontrol.h"
#include "lc823450_clockconfig.h"

#ifdef CONFIG_ADC
#ifdef CONFIG_ARCH_CHIP_LC823450

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define LC823450_ADCHST(c)    (((c) & 0xf) << rADCCTL_fADCHST_SHIFT)
#define LC823450_ADC0DT(d)    (rADC0DT + ((d) << 2))

#define LC823450_MAX_ADCCLK   (5 * 1000 * 1000)   /* Hz */

#ifndef CONFIG_LC823450_ADC_NCHANNELS
#  define CONFIG_LC823450_ADC_NCHANNELS 6
#endif

#if defined(CONFIG_DVFS) && !defined(CONFIG_ADC_POLLED)
#  warning "ADCCLK may be changed during A/D conversion"
#endif

/****************************************************************************
 * Private Types
 ****************************************************************************/

struct lc823450_adc_inst_s
{
  FAR const struct adc_callback_s *cb;
  struct adc_dev_s dev;

  sem_t sem_excl;           /* Mutual exclusion semaphore */
#ifndef CONFIG_ADC_POLLED
  sem_t sem_isr;            /* Interrupt wait semaphore */
#endif
  uint8_t nchannels;        /* Number of channels */
  const uint8_t *chanlist;  /* Pointer to gloval chanlist */
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static inline void lc823450_adc_clearirq(void);
static inline void lc823450_adc_sem_wait(FAR struct lc823450_adc_inst_s *inst);
static inline void lc823450_adc_sem_post(FAR struct lc823450_adc_inst_s *inst);

static int  lc823450_adc_bind(FAR struct adc_dev_s *dev,
                              FAR const struct adc_callback_s *callback);
static void lc823450_adc_reset(FAR struct adc_dev_s *dev);
static int  lc823450_adc_setup(FAR struct adc_dev_s *dev);
static void lc823450_adc_shutdown(FAR struct adc_dev_s *dev);
static void lc823450_adc_rxint(FAR struct adc_dev_s *dev, bool enable);
static int  lc823450_adc_ioctl(FAR struct adc_dev_s *dev, int cmd, unsigned long arg);

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* ADC driver instance */

static struct lc823450_adc_inst_s *g_inst = NULL;

/* IDs to recognize each AD channel */

static const uint8_t lc823450_chanlist[CONFIG_LC823450_ADC_NCHANNELS] =
{
  0,    /* Channel 0 */
  1,    /* Channel 1 */
  2,    /* Channel 2 */
  3,    /* Channel 3 */
  4,    /* Channel 4 */
  5,    /* Channel 5 */
};

/* ADC interface operations */

static const struct adc_ops_s lc823450_adc_ops =
{
  .ao_bind     = lc823450_adc_bind,
  .ao_reset    = lc823450_adc_reset,
  .ao_setup    = lc823450_adc_setup,
  .ao_shutdown = lc823450_adc_shutdown,
  .ao_rxint    = lc823450_adc_rxint,
  .ao_ioctl    = lc823450_adc_ioctl,
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lc823450_adc_clearirq
 *
 * Description:
 *   Clear interrupt factor
 *
 ****************************************************************************/

static inline void lc823450_adc_clearirq(void)
{
  putreg32(rADCSTS_fADCMPL, rADCSTS);
}

/****************************************************************************
 * Name: lc823450_adc_standby
 *
 * Description:
 *   Standby on/off ADC controller
 *
 ****************************************************************************/

static void lc823450_adc_standby(int on)
{
  if (on != 0)
    {
      /* Initialize ADC */

      lc823450_adc_clearirq();

      /* Enter standby mode */

      modifyreg32(rADCSTBY, 0, rADCSTBY_STBY);

      /* disable clock */

      modifyreg32(MCLKCNTAPB, MCLKCNTAPB_ADC_CLKEN, 0);

    }
  else
    {
      /* enable clock */

      modifyreg32(MCLKCNTAPB, 0, MCLKCNTAPB_ADC_CLKEN);

      /* Exit standby mode */

      modifyreg32(rADCSTBY, rADCSTBY_STBY, 0);

      up_udelay(10);

      /* Initialize ADC */

      lc823450_adc_clearirq();
    }
}

/****************************************************************************
 * Name: lc823450_adc_start
 *
 * Description:
 *   Clear interrupt factor
 *
 ****************************************************************************/

static void lc823450_adc_start(FAR struct lc823450_adc_inst_s *inst)
{
  uint32_t pclk;  /* APB clock in Hz */
  uint8_t i;
  uint32_t div;

#ifdef CONFIG_ADC_POLLED
  irqstate_t flags;

  flags = enter_critical_section();
#endif

  pclk = lc823450_get_apb();

  for (i = 0, div = 2; i < 6; i++, div <<= 1)
    {
      if (pclk / div <= LC823450_MAX_ADCCLK)
        {
          ainfo("ADCCLK: %d[Hz]\n", pclk / div);
          break;
        }
    }

  DEBUGASSERT(i < 6);

  /* Setup ADC channels */

  putreg32((i << rADCCTL_fADCNVCK_SHIFT) |
           LC823450_ADCHST(CONFIG_LC823450_ADC_NCHANNELS - 1) |
           rADCCTL_fADCHSCN, rADCCTL);

  /* Start A/D conversion */

  modifyreg32(rADCCTL, rADCCTL_fADACT, rADCCTL_fADACT);

  /* Wait for completion */

#ifdef CONFIG_ADC_POLLED
  while ((getreg32(rADCSTS) & rADCSTS_fADCMPL) == 0)
    ;
#else
  nxsem_wait_uninterruptible(&inst->sem_isr);
#endif

#ifdef CONFIG_ADC_POLLED
  leave_critical_section(flags);
#endif
}

/****************************************************************************
 * Name: lc823450_adc_sem_wait
 *
 * Description:
 *   Take the exclusive access, waiting as necessary
 *
 ****************************************************************************/

static inline void lc823450_adc_sem_wait(FAR struct lc823450_adc_inst_s *inst)
{
  nxsem_wait_uninterruptible(&inst->sem_excl);
}

/****************************************************************************
 * Name: lc823450_adc_sem_post
 *
 * Description:
 *   Release the mutual exclusion semaphore
 *
 ****************************************************************************/

static inline void lc823450_adc_sem_post(FAR struct lc823450_adc_inst_s *inst)
{
  nxsem_post(&inst->sem_excl);
}

/****************************************************************************
 * Name: lc823450_adc_isr
 *
 * Description:
 *   Interrupt service routine
 *
 ****************************************************************************/

#ifndef CONFIG_ADC_POLLED
static int lc823450_adc_isr(int irq, void *context, FAR void *arg)
{
  ainfo("interrupt\n");

  lc823450_adc_clearirq();
  nxsem_post(&g_inst->sem_isr);
  return OK;
}
#endif

/****************************************************************************
 * Name: lc823450_adc_bind
 *
 * Description:
 *   Bind the upper-half driver callbacks to the lower-half implementation.
 *   This must be called early in order to receive ADC event notifications.
 *
 ****************************************************************************/

static int lc823450_adc_bind(FAR struct adc_dev_s *dev,
                             FAR const struct adc_callback_s *callback)
{
  FAR struct lc823450_adc_inst_s *priv =
    (FAR struct lc823450_adc_inst_s *)dev->ad_priv;

  DEBUGASSERT(priv != NULL);
  priv->cb = callback;
  return OK;
}

/****************************************************************************
 * Name: lc823450_adc_reset
 *
 * Description:
 *   Reset the ADC device. Called early to initialize the hardware. This
 *   is called, before adc_setup() and on error conditions.
 *
 * Input Parameters:
 *
 * Returned Value:
 *
 ****************************************************************************/

static void lc823450_adc_reset(FAR struct adc_dev_s *dev)
{
  ainfo("\n");
}

/****************************************************************************
 * Name: lc823450_adc_setup
 *
 * Description:
 *   Configure the ADC. This method is called the first time that the ADC
 *   device is opened. This will occur when the port is first opened.
 *   This setup includes configuring and attaching ADC interrupts. Interrupts
 *   are all disabled upon return.
 *
 * Input Parameters:
 *
 * Returned Value:
 *
 ****************************************************************************/

static int lc823450_adc_setup(FAR struct adc_dev_s *dev)
{
  ainfo("\n");
  return OK;
}

/****************************************************************************
 * Name: lc823450_adc_shutdown
 *
 * Description:
 *   Disable the ADC.  This method is called when the ADC device is closed.
 *   This method reverses the operation the setup method.
 *
 * Input Parameters:
 *
 * Returned Value:
 *
 ****************************************************************************/

static void lc823450_adc_shutdown(FAR struct adc_dev_s *dev)
{
  ainfo("\n");
}

/****************************************************************************
 * Name: lc823450_adc_rxint
 *
 * Description:
 *   Call to enable or disable RX interrupts.
 *
 * Input Parameters:
 *
 * Returned Value:
 *
 ****************************************************************************/

static void lc823450_adc_rxint(FAR struct adc_dev_s *dev, bool enable)
{
  FAR struct lc823450_adc_inst_s *inst =
    (FAR struct lc823450_adc_inst_s *)dev->ad_priv;
  ainfo("enable: %d\n", enable);

  lc823450_adc_sem_wait(inst);

#ifndef CONFIG_ADC_POLLED
  if (enable)
    {
      up_enable_irq(LC823450_IRQ_ADC);
    }
  else
    {
      up_disable_irq(LC823450_IRQ_ADC);
    }
#endif

  lc823450_adc_sem_post(inst);
}

/****************************************************************************
 * Name: lc823450_adc_ioctl
 *
 * Description:
 *   All ioctl calls will be routed through this method.
 *
 * Input Parameters:
 *
 * Returned Value:
 *
 ****************************************************************************/

static int lc823450_adc_ioctl(FAR struct adc_dev_s *dev, int cmd,
                              unsigned long arg)
{
  int ret = 0;
  uint32_t val;
  uint8_t ch;
  FAR struct lc823450_adc_inst_s *priv =
    (FAR struct lc823450_adc_inst_s *)dev->ad_priv;

  ainfo("cmd=%xh\n", cmd);

  lc823450_adc_sem_wait(priv);

  switch (cmd)
    {
      case ANIOC_TRIGGER: /* Software trigger */

        lc823450_adc_standby(0);

        lc823450_adc_start(priv);

        /* Get ADC data */

        for (ch = 0; ch < CONFIG_LC823450_ADC_NCHANNELS; ch++)
          {
            val = getreg32(LC823450_ADC0DT(ch));

            /* Give the ADC data to the ADC driver framework.
             * adc_receive accepts 3 parameters:
             *
             * 1) The first is the ADC device instance for this ADC block.
             * 2) The second is the channel number for the data, and
             * 3) The third is the converted data for the channel.
             */

            priv->cb->au_receive(dev, priv->chanlist[ch], val);
            DEBUGASSERT(ret == OK);
          }

        lc823450_adc_standby(1);
        break;

    default:
      ret = -ENOTTY;
      break;
    }

  lc823450_adc_sem_post(priv);

  return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lc823450_adcinitialize
 *
 * Description:
 *   Initialize ADC device driver.
 *
 * Input Parameters:
 *
 * Returned Value:
 *   Valid ADC device structure reference on success; a NULL on failure
 *
 ****************************************************************************/

FAR struct adc_dev_s *lc823450_adcinitialize(void)
{
  int ret;
  struct lc823450_adc_inst_s *inst;

  if (!g_inst)
    {
      ainfo("Initializing ADC driver\n");

      if ((inst = kmm_malloc(sizeof(struct lc823450_adc_inst_s))) == NULL)
        {
          return NULL;
        }

      memset(inst, 0, sizeof(struct lc823450_adc_inst_s));

      /* Initialize driver instance */

      inst->dev.ad_ops = &lc823450_adc_ops;
      inst->dev.ad_priv = inst;
      inst->nchannels = CONFIG_LC823450_ADC_NCHANNELS;
      inst->chanlist = lc823450_chanlist;

      nxsem_init(&inst->sem_excl, 0, 1);
#ifndef CONFIG_ADC_POLLED
      nxsem_init(&inst->sem_isr, 0, 0);
#endif

      lc823450_adc_sem_wait(inst);

      /* enable clock & unreset (include exitting standby mode) */

      modifyreg32(MCLKCNTAPB, 0, MCLKCNTAPB_ADC_CLKEN);
      modifyreg32(MRSTCNTAPB, MRSTCNTAPB_ADC_RSTB, 0);
      modifyreg32(MRSTCNTAPB, 0, MRSTCNTAPB_ADC_RSTB);
      up_udelay(10);

      /* Setup sample time. Following value of 53 is available in
       * all ADCCLK between 2MHz and 5MHz. [PDFW15IS-1847]
       */

      putreg32(53, rADCSMPL);

      /* Setup ADC interrupt */

#ifndef CONFIG_ADC_POLLED
      irq_attach(LC823450_IRQ_ADC, lc823450_adc_isr, NULL);
      up_enable_irq(LC823450_IRQ_ADC);
#endif

      /* Register the ADC driver at "/dev/adc0" */

      ret = adc_register("/dev/adc0", &inst->dev);

      if (ret < 0)
        {
          aerr("adc_register failed: %d\n", ret);
          lc823450_adc_sem_post(inst);
          kmm_free(g_inst);
          return NULL;
        }

      /* Enter standby mode */

      lc823450_adc_standby(1);

      /* Now we are initialized */

      g_inst = inst;

      lc823450_adc_sem_post(inst);
    }

  return &g_inst->dev;
}

/****************************************************************************
 * Name: lc823450_adc_receive
 ****************************************************************************/

int lc823450_adc_receive(FAR struct adc_dev_s *dev, FAR struct adc_msg_s *msg)
{
  uint8_t ch;
  FAR struct lc823450_adc_inst_s *inst =
    (FAR struct lc823450_adc_inst_s *)dev->ad_priv;

  if (!g_inst)
    {
      return -EIO;
    }

  if (dev != &inst->dev || !msg)
    {
      return -EINVAL;
    }

  lc823450_adc_sem_wait(inst);
  lc823450_adc_standby(0);
  lc823450_adc_start(inst);

  for (ch = 0; ch < CONFIG_LC823450_ADC_NCHANNELS; ch++)
    {
      msg[ch].am_channel = ch;
      msg[ch].am_data = getreg32(LC823450_ADC0DT(ch));
    }

  lc823450_adc_standby(1);
  lc823450_adc_sem_post(inst);

  return OK;
}

#endif /* CONFIG_ARCH_CHIP_LC823450 */
#endif /* CONFIG_ADC */
