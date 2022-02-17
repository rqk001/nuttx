/****************************************************************************
 * include/nuttx/sensors/sht21.h
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

#ifndef __INCLUDE_NUTTX_SENSORS_SHT21_H
#define __INCLUDE_NUTTX_SENSORS_SHT21_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/sensors/ioctl.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define CONFIG_SHT21_ADDR 0x40

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct i2c_master_s;  /* Forward reference */

struct sht21_conv_data_s
{
  int temperature;
  int humidity;
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: sht21_register
 *
 * Description:
 *   Register the SHT2x character device as 'devpath'
 *
 * Input Parameters:
 *   devpath - The full path to the driver to register. E.g., "/dev/temp0"
 *   i2c     - An instance of the I2C interface to use to communicate with
 *             the SHT2x
 *   addr    - The I2C address of the SHT2x. The I2C address of both SHT20
 *             and SHT21 is always 0x40.
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int sht21_register(FAR const char *devpath, FAR struct i2c_master_s *i2c,
                   uint8_t addr);

#endif /* __INCLUDE_NUTTX_SENSORS_SHT21_H */
