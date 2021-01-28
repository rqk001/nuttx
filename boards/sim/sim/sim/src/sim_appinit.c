/****************************************************************************
 * boards/sim/sim/sim/src/sim_appinit.c
 *
 *   Copyright (C) 2015-2016 Gregory Nutt. All rights reserved.
 *   Author:  Gregory Nutt <gnutt@nuttx.org>
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
#include <nuttx/board.h>
#include <nuttx/sensors/fakesensor.h>
#include <nuttx/sensors/wtgahrs2.h>
#include <nuttx/rc/lirc_dev.h>
#include <nuttx/rc/dummy.h>

#include "sim.h"
#include "up_internal.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: board_app_initialize
 *
 * Description:
 *   Perform application specific initialization.  This function is never
 *   called directly from application code, but only indirectly via the
 *   (non-standard) boardctl() interface using the command BOARDIOC_INIT.
 *
 * Input Parameters:
 *   arg - The boardctl() argument is passed to the board_app_initialize()
 *         implementation without modification.  The argument has no
 *         meaning to NuttX; the meaning of the argument is a contract
 *         between the board-specific initialization logic and the
 *         matching application logic.  The value could be such things as a
 *         mode enumeration value, a set of DIP switch switch settings, a
 *         pointer to configuration data read from a file or serial FLASH,
 *         or whatever you would like to do with it.  Every implementation
 *         should accept zero/NULL as a default configuration.
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure to indicate the nature of the failure.
 *
 ****************************************************************************/

#ifdef CONFIG_LIB_BOARDCTL
int board_app_initialize(uintptr_t arg)
{
#ifndef CONFIG_BOARD_LATE_INITIALIZE
  sim_bringup();
#endif

#ifdef CONFIG_RPTUN
  up_rptun_init();
#endif

#ifdef CONFIG_SIM_WTGAHRS2_UARTN
#if CONFIG_SIM_WTGAHRS2_UARTN == 0
  wtgahrs2_initialize(CONFIG_SIM_UART0_NAME, 0);
#elif CONFIG_SIM_WTGAHRS2_UARTN == 1
  wtgahrs2_initialize(CONFIG_SIM_UART1_NAME, 1);
#elif CONFIG_SIM_WTGAHRS2_UARTN == 2
  wtgahrs2_initialize(CONFIG_SIM_UART2_NAME, 2);
#elif CONFIG_SIM_WTGAHRS2_UARTN == 3
  wtgahrs2_initialize(CONFIG_SIM_UART3_NAME, 3);
#endif
#endif

#ifdef CONFIG_SENSORS_FAKESENSOR
  fakesensor_init(SENSOR_TYPE_ACCELEROMETER,
                  "/data/boards/sim/sim/sim/src/csv/accel.csv", 0);

  fakesensor_init(SENSOR_TYPE_MAGNETIC_FIELD,
                  "/data/boards/sim/sim/sim/src/csv/mag.csv", 0);

  fakesensor_init(SENSOR_TYPE_GYROSCOPE,
                  "/data/boards/sim/sim/sim/src/csv/gyro.csv", 0);
#endif

#ifdef CONFIG_RC_DUMMY
  rc_dummy_initialize(0);
#endif

  return 0;
}
#endif /* CONFIG_LIB_BOARDCTL */