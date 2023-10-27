/****************************************************************************
 * arch/arm64/src/common/arm64_perf.c
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

#include <nuttx/clock.h>

#include "arm64_pmu.h"

#ifdef CONFIG_ARCH_PERF_EVENTS

/****************************************************************************
 * Private Data
 ****************************************************************************/

static unsigned long g_cpu_freq = ULONG_MAX;

/****************************************************************************
 * Public Functions
 ****************************************************************************/

void up_perf_init(void *arg)
{
  g_cpu_freq = (unsigned long)(uintptr_t)arg;

  pmu_ccntr_ccfiltr_config(PMCCFILTR_EL0_NSH);
  pmu_cntr_control_config(PMCR_EL0_C | PMCR_EL0_E);
  pmu_cntr_trap_control(PMUSERENR_EL0_EN);
  pmu_cntr_irq_disable(PMINTENCLR_EL1_C);
  pmu_cntr_enable(PMCNTENSET_EL0_C);
}

unsigned long up_perf_getfreq(void)
{
  return g_cpu_freq;
}

unsigned long up_perf_gettime(void)
{
  return pmu_get_ccntr();
}

void up_perf_convert(unsigned long elapsed, struct timespec *ts)
{
  unsigned long left;

  ts->tv_sec  = elapsed / g_cpu_freq;
  left        = elapsed - ts->tv_sec * g_cpu_freq;
  ts->tv_nsec = NSEC_PER_SEC * left / g_cpu_freq;
}
#endif
