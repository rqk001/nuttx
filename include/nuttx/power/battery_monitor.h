/****************************************************************************
 * include/nuttx/power/battery_monitor.h
 * NuttX Battery battery manager & monitor interfaces
 *
 *   Copyright (C) 2019 2G Engineering. All rights reserved.
 *   Author: Josh Lange <jlange@2g-eng.com>
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

#ifndef __INCLUDE_NUTTX_POWER_BATTERY_MONITOR_H
#define __INCLUDE_NUTTX_POWER_BATTERY_MONITOR_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/fs/ioctl.h>

#include <stdbool.h>
#include <stdint.h>
#include <semaphore.h>
#include <fixedmath.h>

#ifdef CONFIG_BATTERY_MONITOR

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* Configuration ************************************************************/
/* CONFIG_BATTERY_MONITOR - Upper half battery monitor driver support
 *
 * Specific, lower-half drivers will have other configuration requirements
 * such as:
 *
 *   CONFIG_I2C - I2C support *may* be needed
 *   CONFIG_I2C_BQ769X0 - The BQ769X0 driver must be explicitly selected.
 */

/* IOCTL Commands ***********************************************************/
/* The upper-half battery monitor driver provides a character driver "wrapper"
 * around the lower-half battery monitor driver that does all of the real work.
 * Since there is no real data transfer to/or from a battery, all of the
 * driver interaction is through IOCTL commands.  The IOCTL commands
 * supported by the upper-half driver simply provide calls into the
 * lower half as summarized below:
 *
 * BATIOC_STATE - Return the current state of the battery (see
 *   enum battery_monitor_status_e).
 *   Input value:  A pointer to type int.
 * BATIOC_HEALTH - Return the current health of the battery (see
 *   enum battery_monitor_health_e).
 *   Input value:  A pointer to type int.
 * BATIOC_ONLINE - Return 1 if the battery is online; 0 if offline.
 *   Input value:  A pointer to type bool.
 * BATIOC_VOLTAGE - Return the current battery pack voltage. The returned value
 *   is a fixed precision number in units of volts.
 *   Input value:  A pointer to type b32_t.
 * BATIOC_CURRENT - Return the current battery pack current. The returned value
 *   is a fixed precision number in units of Amperes.
 *   Input value:  A pointer to type b32_t.
 * BATIOC_INPUT_CURRENT - Define the input current limit of power supply.
 *   Input value:  An int defining the input current limit value.
 * BATIOC_OPERATE - Perform miscellaneous, device-specific charger operation.
 *   Input value:  An uintptr_t that can hold a pointer to struct batio_operate_msg_s.
 */

/* Special input values for BATIOC_INPUT_CURRENT that may optionally
 * be supported by lower-half driver:
 */

#define BATTERY_INPUT_CURRENT_EXT_LIM   (-1) /* External input current limit */

/****************************************************************************
 * Public Types
 ****************************************************************************/
/* Battery status */

enum battery_monitor_status_e
{
  BATTERY_UNKNOWN = 0, /* Battery state is not known */
  BATTERY_FAULT,       /* Charger reported a fault, get health for more info */
  BATTERY_IDLE,        /* Not full, not charging, not discharging */
  BATTERY_FULL,        /* Full, not discharging */
  BATTERY_CHARGING,    /* Not full, charging */
  BATTERY_DISCHARGING  /* Probably not full, discharging */
};

/* Battery Health status */

enum battery_monitor_health_e
{
  BATTERY_HEALTH_UNKNOWN = 0,  /* Battery health state is not known */
  BATTERY_HEALTH_GOOD,         /* Battery is in good condition */
  BATTERY_HEALTH_DEAD,         /* Battery is dead, nothing we can do */
  BATTERY_HEALTH_OVERHEAT,     /* Battery is over recommended temperature */
  BATTERY_HEALTH_OVERVOLTAGE,  /* Battery voltage is over recommended level */
  BATTERY_HEALTH_UNSPEC_FAIL,  /* Battery monitor reported an unspecified failure */
  BATTERY_HEALTH_COLD,         /* Battery is under recommended temperature */
  BATTERY_HEALTH_WD_TMR_EXP,   /* Battery WatchDog Timer Expired */
  BATTERY_HEALTH_DISCONNECTED  /* Battery is not connected */
};

struct battery_monitor_voltage_s
{
  /* Before call, contains the desired number of cells to read.
   * After call, contains the actual number of cells read.
   */

  int cell_count;

  /* Pointer to array where cell voltages should be stored.
   * MUST contain at least cell_count elements.
   * Cell voltages are stored in microvolts (uV)
   */

  uint32_t *cell_voltages;
};

struct battery_monitor_temperature_s
{
  /* Before call, contains the desired number of temperature sensors to read.
   * After call, contains the actual number of temperature sensors read.
   */

  int sensor_count;

  /* Pointer to array where temperature values should be stored.
   * MUST contain at least sensor_count elements.
   * Temperatures are stored in fixed-point degrees C
   */

  b8_t *temperatures;
};

struct battery_monitor_balance_s
{
  int balance_count;

  bool *balance;
};
 /* This structure defines the lower half battery interface */

struct battery_monitor_dev_s;
struct battery_monitor_operations_s
{
  /* Return the current battery state (see enum battery_monitor_status_e) */

  int (*state)(struct battery_monitor_dev_s *dev, int *status);

  /* Return the current battery health (see enum battery_monitor_health_e) */

  int (*health)(struct battery_monitor_dev_s *dev, int *health);

  /* Return true if the battery is online */

  int (*online)(struct battery_monitor_dev_s *dev, bool *status);

  /* Get the battery pack voltage */

  int (*voltage)(struct battery_monitor_dev_s *dev, int *value);

  /* Get the battery cell voltages */

  int (*cell_voltage)(struct battery_monitor_dev_s *dev, struct battery_monitor_voltage_s *cellv);

  /* Get the battery pack current */

  int (*current)(struct battery_monitor_dev_s *dev, int *value);

  /* Get the battery pack state of charge */

  int (*soc)(struct battery_monitor_dev_s *dev, b16_t *value);

  /* Get the battery pack Couloumb count value*/

  int (*coulombs)(struct battery_monitor_dev_s *dev, int *value);

  /* Read battery pack temperature sensor(s) */

  int (*temperature)(struct battery_monitor_dev_s *dev, struct battery_monitor_temperature_s *temps);

  /* Set balance switches on battery cells */

  int (*balance)(struct battery_monitor_dev_s *dev, struct battery_monitor_balance_s *bal);

  /* Do device specific operation */

  int (*operate)(struct battery_monitor_dev_s *dev, uintptr_t param);
};

/* This structure defines the battery driver state structure */

struct battery_monitor_dev_s
{
  /* Fields required by the upper-half driver */

  FAR const struct battery_monitor_operations_s *ops; /* Battery operations */
  sem_t batsem;  /* Enforce mutually exclusive access */

  /* Data fields specific to the lower-half driver may follow */
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifndef __ASSEMBLY__

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/
/****************************************************************************
 * Name: battery_monitor_register
 *
 * Description:
 *   Register a lower half battery driver with the common, upper-half
 *   battery driver.
 *
 * Input Parameters:
 *   devpath - The location in the pseudo-filesystem to create the driver.
 *     Recommended standard is "/dev/bat0", "/dev/bat1", etc.
 *   dev - An instance of the battery state structure .
 *
 * Returned Value:
 *    Zero on success or a negated errno value on failure.
 *
 ****************************************************************************/

int battery_monitor_register(FAR const char *devpath,
                             FAR struct battery_monitor_dev_s *dev);

/****************************************************************************
 * Name: BQ769X0_initialize
 *
 * Description:
 *   Initialize the BQ769X0 battery driver and return an instance of the
 *   lower-half interface that may be used with battery_monitor_register().
 *
 * This is for:
 *   BQ7692000XXX
 *   BQ7693000XXX
 *   bq7694000XXX
 *
 *   This driver requires:
 *
 *   CONFIG_BATTERY_MONITOR - Upper half battery monitor driver support
 *   CONFIG_I2C - I2C support
 *   CONFIG_I2C_BQ769X0 - And the driver must be explictly selected.
 *
 * Input Parameters:
 *   i2c       - An instance of the I2C interface to use to communicate with
 *               the BQ769X0
 *   addr      - The I2C address of the BQ769X0 (Can be 0x08 or 0x18).
 *   frequency - The I2C frequency
 *   crc       - True if the device has CRC enabled (see TI datasheet)
 *
 * Returned Value:
 *   A pointer to the initialized battery driver instance.  A NULL pointer
 *   is returned on a failure to initialize the BQ769X0 lower half.
 *
 ****************************************************************************/

#if defined(CONFIG_I2C) && defined(CONFIG_I2C_BQ769X0)

struct i2c_master_s;
FAR struct battery_monitor_dev_s *BQ769X0_initialize(FAR struct i2c_master_s *i2c,
                                                     uint8_t addr,
                                                     uint32_t frequency,
                                                     bool crc);
#endif

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* CONFIG_BATTERY_MONITOR */
#endif /* __INCLUDE_NUTTX_POWER_BATTERY_H */
