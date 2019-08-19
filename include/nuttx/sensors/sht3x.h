/****************************************************************************
 * include/nuttx/sensors/sht3x.h
 *
 *   Copyright (C) 2019 Hexagon AB. All rights reserved.
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

#ifndef __INCLUDE_NUTT_SENSORS_SHT3X_H
#define __INCLUDE_NUTT_SENSORS_SHT3X_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/sensors/ioctl.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct i2c_master_s;  /* Forward reference */

struct sht3x_meas_data_s
{
  float temperature;
  float humidity;
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: sht3x_register
 *
 * Description:
 *   Register the SHT3x character device as 'devpath'
 *
 * Input Parameters:
 *   devpath - The full path to the driver to register. E.g., "/dev/temp0"
 *   i2c     - An instance of the I2C interface to use to communicate with
 *             the SHT3x
 *   addr    - The I2C address of the SHT3x.
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int sht3x_register(FAR const char *devpath, FAR struct i2c_master_s *i2c,
                   uint8_t addr);

#endif /* __INCLUDE_NUTT_SENSORS_SHT3X_H */
