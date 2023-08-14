/****************************************************************************
 * drivers/sensors/bmi160.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "bmi160.h"

#if defined(CONFIG_SENSORS_BMI160)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/* Character driver methods */

static int     bmi160_open(FAR struct file *filep);
static int     bmi160_close(FAR struct file *filep);
static ssize_t bmi160_read(FAR struct file *filep, FAR char *buffer,
                            size_t len);
static int     bmi160_ioctl(FAR struct file *filep, int cmd,
                            unsigned long arg);

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* This the vtable that supports the character driver interface */

static const struct file_operations g_bmi160fops =
{
  bmi160_open,     /* open */
  bmi160_close,    /* close */
  bmi160_read,     /* read */
  NULL,            /* write */
  NULL,            /* seek */
  bmi160_ioctl,    /* ioctl */
};

/****************************************************************************
 * Name: bmi160_set_normal_imu
 *
 * Description:
 *   set bmi160 to normal IMU mode.
 *
 ****************************************************************************/

static void bmi160_set_normal_imu(FAR struct bmi160_dev_s *priv)
{
  /* Set accel & gyro as normal mode. */

  bmi160_putreg8(priv, BMI160_CMD, ACCEL_PM_NORMAL);
  up_mdelay(30);
  bmi160_putreg8(priv, BMI160_CMD, GYRO_PM_NORMAL);
  up_mdelay(30);

  /* Set accel & gyro output data rate. */

  bmi160_putreg8(priv, BMI160_ACCEL_CONFIG,
                 ACCEL_NORMAL_AVG4 | ACCEL_ODR_100HZ);
  bmi160_putreg8(priv, BMI160_GYRO_CONFIG,
                 GYRO_NORMAL_MODE | GYRO_ODR_100HZ);
}

/****************************************************************************
 * Name: bmi160_open
 *
 * Description:
 *   Standard character driver open method.
 *
 ****************************************************************************/

static int bmi160_open(FAR struct file *filep)
{
  FAR struct inode        *inode = filep->f_inode;
  FAR struct bmi160_dev_s *priv  = inode->i_private;

  bmi160_set_normal_imu(priv);

  return OK;
}

/****************************************************************************
 * Name: bmi160_close
 *
 * Description:
 *   Standard character driver close method.
 *
 ****************************************************************************/

static int bmi160_close(FAR struct file *filep)
{
  FAR struct inode        *inode = filep->f_inode;
  FAR struct bmi160_dev_s *priv  = inode->i_private;

  /* Set suspend mode to each sensors. */

  bmi160_putreg8(priv, BMI160_CMD, ACCEL_PM_SUSPEND);
  up_mdelay(30);

  bmi160_putreg8(priv, BMI160_CMD, GYRO_PM_SUSPEND);
  up_mdelay(30);

  return OK;
}

/****************************************************************************
 * Name: bmi160_read
 *
 * Description:
 *   Standard character driver read method.
 *
 ****************************************************************************/

static ssize_t bmi160_read(FAR struct file *filep, FAR char *buffer,
                           size_t len)
{
  FAR struct inode        *inode = filep->f_inode;
  FAR struct bmi160_dev_s *priv  = inode->i_private;
  FAR struct accel_gyro_st_s *p = (FAR struct accel_gyro_st_s *)buffer;

  if (len < sizeof(struct accel_gyro_st_s))
    {
      snerr("Expected buffer size is %lu\n", sizeof(struct accel_gyro_st_s));
      return 0;
    }

  bmi160_getregs(priv, BMI160_DATA_8, (FAR uint8_t *)buffer, 15);

  /* Adjust sensing time into 24 bit */

  p->sensor_time >>= 8;

  return len;
}

static void bmi160_enable_stepcounter(FAR struct bmi160_dev_s *priv,
                                      int enable)
{
  uint8_t val;

  val = bmi160_getreg8(priv, BMI160_STEP_CONFIG_1);
  if (enable)
    {
      val |= STEP_CNT_EN;
    }
  else
    {
      val &= ~STEP_CNT_EN;
    }

  bmi160_putreg8(priv, BMI160_STEP_CONFIG_1, val);

  sninfo("Step counter %sabled.\n", val & STEP_CNT_EN ? "en" : "dis");
}

/****************************************************************************
 * Name: bmi160_ioctl
 *
 * Description:
 *   Standard character driver ioctl method.
 *
 ****************************************************************************/

static int bmi160_ioctl(FAR struct file *filep, int cmd, unsigned long arg)
{
  FAR struct inode        *inode = filep->f_inode;
  FAR struct bmi160_dev_s *priv  = inode->i_private;
  int ret = OK;

  switch (cmd)
    {
      /* Enable bmi160 step counter. Arg: int value */

      case SNIOC_ENABLESC:
        {
          bmi160_enable_stepcounter(priv, (int)arg);
        }
        break;

      /* Read bmi160 step count. Arg:  int16_t* pointer */

      case SNIOC_READSC:
        {
          int16_t *ptr = (FAR int16_t *)((uintptr_t)arg);

          DEBUGASSERT(ptr != NULL);

          *ptr = bmi160_getreg16(priv, BMI160_STEP_COUNT_0);
        }
        break;

      default:
        snerr("Unrecognized cmd: %d\n", cmd);
        ret = -ENOTTY;
        break;
    }

  return ret;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: bmi160_checkid
 *
 * Description:
 *   Read and verify the BMI160 chip ID
 *
 ****************************************************************************/

int bmi160_checkid(FAR struct bmi160_dev_s *priv)
{
  uint8_t devid = 0;

  /* Read device ID  */

  devid = bmi160_getreg8(priv, BMI160_CHIP_ID);
  sninfo("devid: %04x\n", devid);

  if (devid != (uint16_t) DEVID)
    {
      /* ID is not Correct */

      return -ENODEV;
    }

  return OK;
}

/****************************************************************************
 * Name: bmi160_getreg8
 *
 * Description:
 *   Read from an 8-bit BMI160 register
 *
 ****************************************************************************/

uint8_t bmi160_getreg8(FAR struct bmi160_dev_s *priv, uint8_t regaddr)
{
  uint8_t regval = 0;

#ifdef CONFIG_SENSORS_BMI160_I2C
  struct i2c_msg_s msg[2];
  int ret;

  msg[0].frequency = priv->freq;
  msg[0].addr      = priv->addr;
  msg[0].flags     = I2C_M_NOSTOP;
  msg[0].buffer    = &regaddr;
  msg[0].length    = 1;

  msg[1].frequency = priv->freq;
  msg[1].addr      = priv->addr;
  msg[1].flags     = I2C_M_READ;
  msg[1].buffer    = &regval;
  msg[1].length    = 1;

  ret = I2C_TRANSFER(priv->i2c, msg, 2);
  if (ret < 0)
    {
      snerr("I2C_TRANSFER failed: %d\n", ret);
    }

#else /* CONFIG_SENSORS_BMI160_SPI */
  /* If SPI bus is shared then lock and configure it */

  SPI_LOCK(priv->spi, true);
  bmi160_configspi(priv->spi);

  /* Select the BMI160 */

  SPI_SELECT(priv->spi, SPIDEV_ACCELEROMETER(0), true);

  /* Send register to read and get the next byte */

  SPI_SEND(priv->spi, regaddr | 0x80);
  SPI_RECVBLOCK(priv->spi, &regval, 1);

  /* Deselect the BMI160 */

  SPI_SELECT(priv->spi, SPIDEV_ACCELEROMETER(0), false);

  /* Unlock bus */

  SPI_LOCK(priv->spi, false);
#endif

  return regval;
}

/****************************************************************************
 * Name: bmi160_putreg8
 *
 * Description:
 *   Write a value to an 8-bit BMI160 register
 *
 ****************************************************************************/

void bmi160_putreg8(FAR struct bmi160_dev_s *priv, uint8_t regaddr,
                    uint8_t regval)
{
#ifdef CONFIG_SENSORS_BMI160_I2C
  struct i2c_msg_s msg[2];
  int ret;
  uint8_t txbuffer[2];

  txbuffer[0] = regaddr;
  txbuffer[1] = regval;

  msg[0].frequency = priv->freq;
  msg[0].addr      = priv->addr;
  msg[0].flags     = 0;
  msg[0].buffer    = txbuffer;
  msg[0].length    = 2;

  ret = I2C_TRANSFER(priv->i2c, msg, 1);
  if (ret < 0)
    {
      snerr("I2C_TRANSFER failed: %d\n", ret);
    }

#else /* CONFIG_SENSORS_BMI160_SPI */
  /* If SPI bus is shared then lock and configure it */

  SPI_LOCK(priv->spi, true);
  bmi160_configspi(priv->spi);

  /* Select the BMI160 */

  SPI_SELECT(priv->spi, SPIDEV_ACCELEROMETER(0), true);

  /* Send register address and set the value */

  SPI_SEND(priv->spi, regaddr);
  SPI_SEND(priv->spi, regval);

  /* Deselect the BMI160 */

  SPI_SELECT(priv->spi, SPIDEV_ACCELEROMETER(0), false);

  /* Unlock bus */

  SPI_LOCK(priv->spi, false);

#endif
}

/****************************************************************************
 * Name: bmi160_getreg16
 *
 * Description:
 *   Read 16-bits of data from an BMI160 register
 *
 ****************************************************************************/

uint16_t bmi160_getreg16(FAR struct bmi160_dev_s *priv, uint8_t regaddr)
{
  uint16_t regval = 0;

#ifdef CONFIG_SENSORS_BMI160_I2C
  struct i2c_msg_s msg[2];
  int ret;

  msg[0].frequency = priv->freq;
  msg[0].addr      = priv->addr;
  msg[0].flags     = I2C_M_NOSTOP;
  msg[0].buffer    = &regaddr;
  msg[0].length    = 1;

  msg[1].frequency = priv->freq;
  msg[1].addr      = priv->addr;
  msg[1].flags     = I2C_M_READ;
  msg[1].buffer    = (uint8_t *)&regval;
  msg[1].length    = 2;

  ret = I2C_TRANSFER(priv->i2c, msg, 2);
  if (ret < 0)
    {
      snerr("I2C_TRANSFER failed: %d\n", ret);
    }

#else /* CONFIG_SENSORS_BMI160_SPI */
  /* If SPI bus is shared then lock and configure it */

  SPI_LOCK(priv->spi, true);
  bmi160_configspi(priv->spi);

  /* Select the BMI160 */

  SPI_SELECT(priv->spi, SPIDEV_ACCELEROMETER(0), true);

  /* Send register to read and get the next 2 bytes */

  SPI_SEND(priv->spi, regaddr | 0x80);
  SPI_RECVBLOCK(priv->spi, &regval, 2);

  /* Deselect the BMI160 */

  SPI_SELECT(priv->spi, SPIDEV_ACCELEROMETER(0), false);

  /* Unlock bus */

  SPI_LOCK(priv->spi, false);
#endif

  return regval;
}

/****************************************************************************
 * Name: bmi160_getregs
 *
 * Description:
 *   Read cnt bytes from specified dev_addr and reg_addr
 *
 ****************************************************************************/

void bmi160_getregs(FAR struct bmi160_dev_s *priv, uint8_t regaddr,
                    uint8_t *regval, int len)
{
#ifdef CONFIG_SENSORS_BMI160_I2C
  struct i2c_msg_s msg[2];
  int ret;

  msg[0].frequency = priv->freq;
  msg[0].addr      = priv->addr;
  msg[0].flags     = I2C_M_NOSTOP;
  msg[0].buffer    = &regaddr;
  msg[0].length    = 1;

  msg[1].frequency = priv->freq;
  msg[1].addr      = priv->addr;
  msg[1].flags     = I2C_M_READ;
  msg[1].buffer    = regval;
  msg[1].length    = len;

  ret = I2C_TRANSFER(priv->i2c, msg, 2);
  if (ret < 0)
    {
      snerr("I2C_TRANSFER failed: %d\n", ret);
    }

#else /* CONFIG_SENSORS_BMI160_SPI */
  /* If SPI bus is shared then lock and configure it */

  SPI_LOCK(priv->spi, true);
  bmi160_configspi(priv->spi);

  /* Select the BMI160 */

  SPI_SELECT(priv->spi, SPIDEV_ACCELEROMETER(0), true);

  /* Send register to read and get the next 2 bytes */

  SPI_SEND(priv->spi, regaddr | 0x80);
  SPI_RECVBLOCK(priv->spi, regval, len);

  /* Deselect the BMI160 */

  SPI_SELECT(priv->spi, SPIDEV_ACCELEROMETER(0), false);

  /* Unlock bus */

  SPI_LOCK(priv->spi, false);

#endif
}

/****************************************************************************
 * Name: bmi160_register
 *
 * Description:
 *   Register the BMI160 character device as 'devpath'
 *
 * Input Parameters:
 *   devpath - The full path to the driver to register. E.g., "/dev/press0"
 *   dev     - An instance of the SPI interface to use to communicate with
 *             BMI160
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

#ifdef CONFIG_SENSORS_BMI160_I2C
int bmi160_register(FAR const char *devpath, FAR struct i2c_master_s *dev)
#else /* CONFIG_SENSORS_BMI160_SPI */
int bmi160_register(FAR const char *devpath, FAR struct spi_dev_s *dev)
#endif
{
  uint8_t devid = 0;

  priv = (FAR struct bmi160_dev_s *)kmm_malloc(sizeof(struct bmi160_dev_s));
  if (!priv)
    {
      snerr("Failed to allocate instance\n");
      return -ENOMEM;
    }

#ifdef CONFIG_SENSORS_BMI160_I2C
  priv->i2c = dev;
  priv->addr = BMI160_I2C_ADDR;
  priv->freq = BMI160_I2C_FREQ;

#else /* CONFIG_SENSORS_BMI160_SPI */
  priv->spi = dev;

  /* BMI160 detects communication bus is SPI by rising edge of CS. */

  bmi160_getreg8(priv, 0x7f);
  bmi160_getreg8(priv, 0x7f); /* workaround: fail to switch SPI, run twice */
  up_udelay(200);

#endif

  ret = bmi160_checkid(priv);
  if (ret < 0)
    {
      snerr("Wrong Device ID!\n");
      kmm_free(priv);
      return ret;
    }

  /* To avoid gyro wakeup it is required to write 0x00 to 0x6C */

  bmi160_putreg8(priv, BMI160_PMU_TRIGGER, 0);

  ret = register_driver(devpath, &g_bmi160fops, 0666, priv);
  if (ret < 0)
    {
      snerr("Failed to register driver: %d\n", ret);
      kmm_free(priv);
    }

  sninfo("BMI160 driver loaded successfully!\n");
  return OK;
}

#endif /* CONFIG_SENSORS_BMI160 */
