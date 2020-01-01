/****************************************************************************
 * arch/arm/src/nrf52/nrf52_rng.c
 *
 *   Copyright (C) 2019 Gregory Nutt. All rights reserved.
 *   Author: Levin Li <levin.li@outlook.com>
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

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <debug.h>
#include <errno.h>
#include <fcntl.h>
#include <nuttx/fs/fs.h>
#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/semaphore.h>
#include <nuttx/fs/ioctl.h>
#include <nuttx/drivers/drivers.h>

#include "up_arch.h"
#include "chip.h"
#include "hardware/nrf52_utils.h"
#include "hardware/nrf52_rng.h"
#include "up_internal.h"

#if defined(CONFIG_NRF52_RNG)
#if defined(CONFIG_DEV_RANDOM) || defined(CONFIG_DEV_URANDOM_ARCH)

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static int nrf52_rng_initialize(void);
static int nrf52_rng_irqhandler(int irq, void *context, FAR void *arg);
static ssize_t nrf52_rng_read(FAR struct file *filep, FAR char *buffer,
                              size_t buflen);
static int nrf52_rng_open(FAR struct file *filep);

/****************************************************************************
 * Private Types
 ****************************************************************************/

struct rng_dev_s
{
  uint8_t *rd_buf;
  size_t   rd_count;
  size_t   buflen;
  sem_t    rd_sem;         /* semphore for read RNG data */
  sem_t    excl_sem;       /* semphore for access RNG dev */
};

/****************************************************************************
 * Private Data
 ****************************************************************************/

static struct rng_dev_s g_rngdev;

static const struct file_operations g_rngops =
{
  .open  = nrf52_rng_open,       /* open   */
  .read  = nrf52_rng_read,       /* read   */
};

/****************************************************************************
 * Private functions
 ****************************************************************************/

static void nrf52_rng_start(void)
{
  irqstate_t flag;
  flag = enter_critical_section();

  nrf52_event_clear(NRF52_RNG_EVENT_RDY);

  putreg32(1, NRF52_RNG_CONFIG);
  nrf52_interrupt_enable(NRF52_RNG_INT_SET, NRF52_RNG_INT_EVENT_RDY);
  nrf52_task_trigger(NRF52_RNG_T_START);

  up_enable_irq(NRF52_IRQ_RNG);

  leave_critical_section(flag);
}

static void nrf52_rng_stop(void)
{
  irqstate_t flag;
  flag = enter_critical_section();

  up_disable_irq(NRF52_IRQ_RNG);

  nrf52_task_trigger(NRF52_RNG_T_STOP);
  nrf52_interrupt_disable(NRF52_RNG_INT_CLR, NRF52_RNG_INT_EVENT_RDY);

  nrf52_event_clear(NRF52_RNG_EVENT_RDY);

  leave_critical_section(flag);
}

static int nrf52_rng_initialize(void)
{
  static bool first_flag = true;

  if (false == first_flag)
    return OK;

  first_flag = false;

  _info("Initializing RNG\n");

  memset(&g_rngdev, 0, sizeof(struct rng_dev_s));

  nxsem_init(&g_rngdev.rd_sem, 0, 0);
  nxsem_setprotocol(&g_rngdev.rd_sem, SEM_PRIO_NONE);

  nxsem_init(&g_rngdev.excl_sem, 0, 1);
  nxsem_setprotocol(&g_rngdev.excl_sem, SEM_PRIO_NONE);

  _info("Ready to stop\n");
  nrf52_rng_stop();

  if (irq_attach(NRF52_IRQ_RNG, nrf52_rng_irqhandler, NULL) != 0)
    {
      /* We could not attach the ISR to the interrupt */

      _warn("Could not attach NRF52_IRQ_RNG.\n");

      return -EAGAIN;
    }

  return OK;
}

static int nrf52_rng_irqhandler(int irq, FAR void *context, FAR void *arg)
{
  FAR struct rng_dev_s *priv = (struct rng_dev_s *) &g_rngdev;
  uint8_t *addr;

  if (getreg32(NRF52_RNG_EVENT_RDY) == NRF52_RNG_INT_EVENT_RDY)
    {
      nrf52_event_clear(NRF52_RNG_EVENT_RDY);
      if (priv->rd_count < priv->buflen)
        {
          addr = priv->rd_buf + priv->rd_count++;
          *addr = getreg32(NRF52_RNG_VALUE);
          irqwarn("%d\n", *addr);
        }

      if (priv->rd_count == priv->buflen)
        {
          nrf52_rng_stop();
          nxsem_post(&priv->rd_sem);
        }
    }

  return OK;
}

/****************************************************************************
 * Name: nrf52_rng_open
 ****************************************************************************/

static int nrf52_rng_open(FAR struct file *filep)
{
  /* O_NONBLOCK is not supported */

  if (filep->f_oflags & O_NONBLOCK)
    {
      _err("nRF52 rng didn't support O_NONBLOCK mode.\n");
      return -EPERM;
    }

  return OK;
}

/****************************************************************************
 * Name: nrf52_rng_read
 ****************************************************************************/

static ssize_t nrf52_rng_read(FAR struct file *filep, FAR char *buffer,
                              size_t buflen)
{
  FAR struct rng_dev_s *priv = (struct rng_dev_s *)&g_rngdev;
  ssize_t read_len;

  if (nxsem_wait(&priv->excl_sem) != OK)
    {
      return -EBUSY;
    }

  priv->rd_buf = (uint8_t *) buffer;
  priv->buflen = buflen;
  priv->rd_count = 0;

  /* start RNG and Wait until the buffer is filled */

  nrf52_rng_start();

  nxsem_wait(&priv->rd_sem);
  read_len = priv->rd_count;

  if (priv->rd_count > priv->buflen)
    {
      _err("Bad rd_count: Too much data, exceeds buffer size: %d\n",
           priv->rd_count);
    }

  /* Now , got data, and release rd_sem for next read */

  nxsem_post(&priv->excl_sem);

  return read_len;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: devrandom_register
 *
 * Description:
 *   Initialize the RNG hardware and register the /dev/random driver.
 *   Must be called BEFORE devurandom_register.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

#ifdef CONFIG_DEV_RANDOM
void devrandom_register(void)
{
  nrf52_rng_initialize();
  (void)register_driver("/dev/random", FAR & g_rngops, 0444, NULL);
}
#endif

/****************************************************************************
 * Name: devurandom_register
 *
 * Description:
 *   Register /dev/urandom
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

#ifdef CONFIG_DEV_URANDOM_ARCH
void devurandom_register(void)
{
#ifndef CONFIG_DEV_RANDOM
  nrf52_rng_initialize();
#endif
  (void)register_driver("dev/urandom", FAR & g_rngops, 0444, NULL);
}
#endif

#endif /* CONFIG_DEV_RANDOM || CONFIG_DEV_URANDOM_ARCH */
#endif /* CONFIG_NRF52_RNG */
