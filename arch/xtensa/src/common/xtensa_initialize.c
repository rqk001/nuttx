/****************************************************************************
 * arch/xtensa/src/common/xtensa_initialize.c
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

#include <nuttx/arch.h>
#include <nuttx/board.h>
#include <arch/board/board.h>

#include "xtensa.h"

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* g_current_regs[] holds a reference to the current interrupt level
 * register storage structure.  It is non-NULL only during interrupt
 * processing.  Access to g_current_regs[] must be through the
 * [get/set]_current_regs for portability.
 */

/* For the case of architectures with multiple CPUs, then there must be one
 * such value for each processor that can receive an interrupt.
 */

volatile uint32_t *g_current_regs[CONFIG_SMP_NCPUS];

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: xtensa_color_intstack
 *
 * Description:
 *   Set the interrupt stack to a value so that later we can determine how
 *   much stack space was used by interrupt handling logic
 *
 ****************************************************************************/

#if defined(CONFIG_STACK_COLORATION) && CONFIG_ARCH_INTERRUPTSTACK > 15
static inline void xtensa_color_intstack(void)
{
  int cpu;

  for (cpu = 0; cpu < CONFIG_SMP_NCPUS; cpu++)
    {
      xtensa_stack_color((void *)up_get_intstackbase(cpu), INTSTACK_SIZE);
    }
}
#else
#  define xtensa_color_intstack()
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_initialize
 *
 * Description:
 *   up_initialize will be called once during OS initialization after the
 *   basic OS services have been initialized.  The architecture specific
 *   details of initializing the OS will be handled here.  Such things as
 *   setting up interrupt service routines, starting the clock, and
 *   registering device drivers are some of the things that are different
 *   for each processor and hardware platform.
 *
 *   up_initialize is called after the OS initialized but before the user
 *   initialization logic has been started and before the libraries have
 *   been initialized.  OS services and driver services are available.
 *
 ****************************************************************************/

void up_initialize(void)
{
#if XCHAL_CP_NUM > 0
  xtensa_set_cpenable(CONFIG_XTENSA_CP_INITSET);
#endif

  xtensa_color_intstack();

  /* Add any extra memory fragments to the memory manager */

  xtensa_add_region();

#ifdef CONFIG_PM
  /* Initialize the power management subsystem.  This MCU-specific function
   * must be called *very* early in the initialization sequence *before* any
   * other device drivers are initialized (since they may attempt to register
   * with the power management subsystem).
   */

  xtensa_pminitialize();
#endif

#ifdef CONFIG_ARCH_DMA
  /* Initialize the DMA subsystem if the weak function xtensa_dma_initialize
   * has been brought into the build
   */

#ifdef CONFIG_HAVE_WEAKFUNCTIONS
  if (xtensa_dma_initialize)
#endif
    {
      xtensa_dma_initialize();
    }
#endif

  /* Initialize the serial device driver */

#ifdef USE_SERIALDRIVER
  xtensa_serialinit();
#endif

  /* Initialize the network */

  xtensa_netinitialize();

  /* Initialize USB -- device and/or host */

  xtensa_usbinitialize();

  board_autoled_on(LED_IRQSENABLED);
}
