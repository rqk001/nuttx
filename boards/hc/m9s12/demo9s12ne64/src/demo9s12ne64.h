/****************************************************************************
 * boards/hc/m9s12/demo9s12ne64/src/demo9s12ne64.h
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

#ifndef __BOARDS_HC_MCS92S12NE64_DEMO9S12NE64_SRC_DEMO9S12NE64_H
#define __BOARDS_HC_MCS92S12NE64_DEMO9S12NE64_SRC_DEMO9S12NE64_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* DEMO9S12NE64 GPIOs *******************************************************/

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public data
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Public Functions Definitions
 ****************************************************************************/

/****************************************************************************
 * Name: hcs12_spidev_initialize
 *
 * Description:
 *  Called to configure SPI chip select GPIO pins for the STM3210E-EVAL
 *  board.
 *
 ****************************************************************************/

void weak_function hcs12_spidev_initialize(void);

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_HC_MCS92S12NE64_DEMO9S12NE64_SRC_DEMO9S12NE64_H */
