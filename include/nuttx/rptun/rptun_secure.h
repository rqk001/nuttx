/****************************************************************************
 * include/nuttx/rptun/rptun_secure.h
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

#ifndef __INCLUDE_NUTTX_RPTUN_RPTUN_SECURE_H
#define __INCLUDE_NUTTX_RPTUN_RPTUN_SECURE_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/rptun/rptun.h>

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
 * Name: rptun_secure_init
 *
 * Description:
 *   Initializes the rptun device.
 *
 * Input Parameters:
 *   cpuname - Local CPU name
 *   master - If is master
 *   rsc - The resource for shared memory
 *   irq_event - Interrupt ID to attach
 *   irq_trigger - Interrupt ID to trigger
 *
 * Returned Value:
 *   OK on success, negated errno on failure
 *
 ****************************************************************************/

int rptun_secure_init(FAR const char *cpuname, bool master,
                      FAR struct rptun_rsc_s *rsc, int irq_event,
                      int irq_trigger);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __INCLUDE_NUTTX_RPTUN_RPTUN_SECURE_H */
