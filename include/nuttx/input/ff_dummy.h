/****************************************************************************
 * include/nuttx/input/ff_dummy.h
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

#ifndef __INCLUDE_NUTTX_INPUT_FF_DUMMY_H_
#define __INCLUDE_NUTTX_INPUT_FF_DUMMY_H_

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: ff_dummy_initialize
 *
 * Description:
 *   This function gengrate a vibrator node under /dev/ named lran. Which
 *   indicates a dummy vibrator device.
 *
 * Input Parameters:
 *   devno - The user specifies device number, from 0. If the
 *           devno alerady exists, -EEXIST will be returned.
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int ff_dummy_initialize(int devno);

#endif /* __INCLUDE_NUTTX_INPUT_FF_DUMMY_H_ */
