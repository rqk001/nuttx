/****************************************************************************
 * arch/arm/src/cxd56xx/cxd56_gauge.c
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

/* CXD5247GF is Li-Ion Battery Charger with Power-Path Management. */

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <debug.h>

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/kmalloc.h>
#include <nuttx/mutex.h>
#include <nuttx/power/battery_gauge.h>
#include <nuttx/power/battery_ioctl.h>

#include <arch/chip/battery_ioctl.h>

#include "cxd56_pmic.h"

#ifdef CONFIG_CXD56_GAUGE

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

struct bat_gauge_dev_s
{
  mutex_t batlock;
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static ssize_t gauge_read(struct file *filep, char *buffer,
                            size_t buflen);
static ssize_t gauge_write(struct file *filep,
                             const char *buffer, size_t buflen);
static int gauge_ioctl(struct file *filep, int cmd,
                       unsigned long arg);

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const struct file_operations g_gaugeops =
{
  NULL,         /* open */
  NULL,         /* close */
  gauge_read,   /* read */
  gauge_write,  /* write */
  NULL,         /* seek */
  gauge_ioctl,  /* ioctl */
  NULL          /* poll */
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
  , NULL        /* unlink */
#endif
};

static struct bat_gauge_dev_s g_gaugedev =
{
  .batlock = NXMUTEX_INITIALIZER,
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gauge_get_status
 ****************************************************************************/

static int gauge_get_status(enum battery_status_e *status)
{
  uint8_t state;
  int ret;

  if (status == NULL)
    {
      return -EINVAL;
    }

  *status = BATTERY_UNKNOWN;

  ret = cxd56_pmic_getchargestate(&state);
  if (ret < 0)
    {
      return -EIO;
    }

  switch (state)
    {
      /* Is the charging done? */

      case PMIC_STAT_CHG_COMPLETE:
        *status = BATTERY_FULL;
        break;

      /* Is the charging in progress? */

      case PMIC_STAT_GB_QCKCHARGE:
      case PMIC_STAT_GB_LOWCHARGE:
      case PMIC_STAT_GB_HIGHCHARGE:
        *status = BATTERY_CHARGING;
        break;

      /* Is the discharging */

      case PMIC_STAT_CHG_STOP:
        *status = BATTERY_DISCHARGING;
        break;

      default:
        batinfo("Charge state %d\n", state);
        *status = BATTERY_IDLE;
        break;
    }

  return OK;
}

/****************************************************************************
 * Name: gauge_get_vol
 ****************************************************************************/

static int gauge_get_vol(b16_t *voltage)
{
  struct pmic_gauge_s gauge;
  int ret;

  if (voltage == NULL)
    {
      return -EINVAL;
    }

  *voltage = 0;

  ret = cxd56_pmic_get_gauge(&gauge);
  if (ret < 0)
    {
      return -EIO;
    }

  *voltage = gauge.voltage * 112 / 100;
  return OK;
}

/****************************************************************************
 * Name: gauge_get_capacity
 ****************************************************************************/

static int gauge_get_capacity(b16_t *capacity)
{
  b16_t vol;
  int lower;
  int upper;
  int ret;

  if (capacity == NULL)
    {
      return -EINVAL;
    }

  /* Get current battery voltage and upper/lower limit settings from PMIC. */

  ret = gauge_get_vol(&vol);
  if (ret < 0)
    {
      return -EIO;
    }

  ret = cxd56_pmic_getchargevol(&upper);
  if (ret < 0)
    {
      return -EIO;
    }

  ret = cxd56_pmic_getlowervol(&lower);
  if (ret < 0)
    {
      return -EIO;
    }

  /* Calculate capacity (0-100%)
   * Actually, battery voltage possible to be under lower limit voltage.
   *
   * NOTE: This logic is tentative, linear from lower to upper. But it
   * depends on the battery. Thus, user should be apply a voltage
   * characteristic for capacity calculation if you want to more accuracy.
   */

  if (vol > lower)
    {
      upper -= lower;
      vol -= lower;
      *capacity = (vol * 100) / upper;
    }
  else
    {
      *capacity = 0;
    }

  return OK;
}

/****************************************************************************
 * Name: gauge_online
 ****************************************************************************/

static int gauge_online(bool *online)
{
  if (online == NULL)
    {
      return -EINVAL;
    }

  *online = true;
  return OK;
}

/****************************************************************************
 * Name: gauge_read
 ****************************************************************************/

static ssize_t gauge_read(struct file *filep, char *buffer,
                            size_t buflen)
{
  /* Return nothing read */

  return 0;
}

/****************************************************************************
 * Name: gauge_write
 ****************************************************************************/

static ssize_t gauge_write(struct file *filep,
                             const char *buffer, size_t buflen)
{
  /* Return nothing written */

  return 0;
}

/****************************************************************************
 * Name: gauge_ioctl
 ****************************************************************************/

static int gauge_ioctl(struct file *filep, int cmd, unsigned long arg)
{
  struct inode *inode = filep->f_inode;
  struct bat_gauge_dev_s *priv = inode->i_private;
  int ret = -ENOTTY;

  nxmutex_lock(&priv->batlock);

  switch (cmd)
    {
      case BATIOC_STATE:
        {
          enum battery_status_e *status =
            (enum battery_status_e *)(uintptr_t)arg;
          ret = gauge_get_status(status);
        }
        break;

      case BATIOC_VOLTAGE:
        {
          b16_t *voltage = (b16_t *)(uintptr_t)arg;
          ret = gauge_get_vol(voltage);
        }
        break;

      case BATIOC_CAPACITY:
        {
          b16_t *capacity = (b16_t *)(uintptr_t)arg;
          ret = gauge_get_capacity(capacity);
        }
        break;

      case BATIOC_ONLINE:
        {
          bool *online = (bool *)(uintptr_t)arg;
          ret = gauge_online(online);
        }
        break;

      default:
        ret = -ENOTTY;
        break;
    }

  nxmutex_unlock(&priv->batlock);
  return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: cxd56_gauge_initialize
 *
 * Description:
 *   Initialize the CXD5247 battery driver.
 *
 * Input Parameters:
 *   devpath - Device file path
 *
 * Returned Value:
 *   Return 0 on success. Otherwise, return a negated errno.
 *
 ****************************************************************************/

int cxd56_gauge_initialize(const char *devpath)
{
  struct bat_gauge_dev_s *priv = &g_gaugedev;
  int ret;

  /* Register battery driver */

  ret = register_driver(devpath, &g_gaugeops, 0666, priv);
  if (ret < 0)
    {
      baterr("ERROR: register_driver failed: %d\n", ret);
      return -EFAULT;
    }

  return OK;
}

/****************************************************************************
 * Name: cxd56_gauge_uninitialize
 *
 * Description:
 *   Uninitialize the CXD5247 battery driver.
 *
 * Input Parameters:
 *   devpath - Device file path
 *
 * Returned Value:
 *   Return 0 on success. Otherwise, return a negated errno.
 *
 ****************************************************************************/

int cxd56_gauge_uninitialize(const char *devpath)
{
  unregister_driver(devpath);
  return OK;
}

#endif /* CONFIG_CXD56_GAUGE */
