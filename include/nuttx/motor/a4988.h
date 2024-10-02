/****************************************************************************
 * include/nuttx/motor/a4988.h
 *
 * SPDX-License-Identifier: Apache-2.0
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

#ifndef __INCLUDE_NUTTX_MOTOR_A4988_H
#define __INCLUDE_NUTTX_MOTOR_A4988_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/motor/stepper.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#if defined(CONFIG_STEPPER_A4988)

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct a4988_ops_s
{
  /* Initialize the control, called at register step */

  CODE void (*initialize)(void);

  /* Control step output */

  CODE void (*step)(int level);

  /* Direction */

  CODE void (*direction)(int level);

  /* Configure microstepping */

  CODE void (*microstepping)(int ms1, int ms2, int ms3);

  /* Enable control */

  CODE void (*enable)(int level);

  /* Idle control */

  CODE void (*idle)(int level);
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Name: a4988_register
 *
 * Description:
 *  Register the a4988 character device as 'devpath'
 *
 * Input Parameters:
 *  devpath - The full path to the driver to register. E.g., "/dev/stepper0"
 * Returned Value:
 *  ops - operations on the concrete hardware
 *  Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int a4988_register(FAR const char *devpath, FAR struct a4988_ops_s *ops);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* CONFIG_STEPPER_A4988 */
#endif /* __INCLUDE_NUTTX_DRIVERS_MOTOR_A4988_H */
