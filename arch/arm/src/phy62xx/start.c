/****************************************************************************
 * arch/arm/src/stm32f0l0g0/stm32_start.c
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

#include <nuttx/config.h>

#include <stdint.h>
#include <assert.h>
#include <debug.h>

#include <nuttx/init.h>
#include <arch/board/board.h>

#include "arm_arch.h"
#include "arm_internal.h"

#include "start.h"
#include "clock.h"
#include "flash.h"
#include "log.h"
#include "jump_function.h"
#include "rf_phy_driver.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
extern const uint32_t _sramscttexts;
extern const uint32_t _sramscttext;
extern const uint32_t _eramscttext;

extern const uint32_t _sjtblss;
extern const uint32_t _sjtbls;
extern const uint32_t _ejtbls;


#define IDLE_STACK ((uint32_t)&_ebss+CONFIG_IDLETHREAD_STACKSIZE)
const uintptr_t g_idle_topstack = IDLE_STACK;

/****************************************************************************
 * Public Data
 ****************************************************************************/



/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: showprogress
 *
 * Description:
 *   Print a character on the CONSOLE USART to show boot status.
 *
 ****************************************************************************/

#ifdef CONFIG_DEBUG_FEATURES
#  define showprogress(c) up_putc(c)
#else
#  define showprogress(c)
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: _start
 *
 * Description:
 *   This is the reset entry point.
 *
 ****************************************************************************/

extern uint32_t* jump_table_base[];

extern volatile sysclk_t g_system_clk;
void c_start(void)
{
  const uint32_t *src;
  uint32_t *dest;
  /* Configure the uart so that we can get debug output as soon as possible */

  //set stack to main stack point
  spif_config(SYS_CLK_DLL_64M, 1, 0x801003B, 0, 0);

  HAL_CRITICAL_SECTION_INIT();

  g_system_clk = SYS_CLK_DLL_48M;
  clk_init(SYS_CLK_DLL_48M);
  //clk_init(SYS_CLK_XTAL_16M);
#if 1
  //stm32_clockconfig();

  /* Clear .bss.  We'll do this inline (vs. calling memset) just to be
   * certain that there are no issues with the state of global variables.
   */

  for (dest = &_sbss; dest < &_ebss; )
    {
      *dest++ = 0;
    }

  //showprogress('B');

  /* Move the initialized data section from his temporary holding spot in
   * FLASH into the correct place in SRAM.  The correct place in SRAM is
   * give by _sdata and _edata.  The temporary location is in FLASH at the
   * end of all of the other read-only data (.text, .rodata) at _eronly.
   */

  for (src = &_eronly, dest = &_sdata; dest < &_edata; )
    {
      *dest++ = *src++;
    }

  //showprogress('C');
/*
  for (src = &_sramscttexts, dest = &_sramscttext; dest < &_eramscttext; )
  {
    *dest++ = *src++;
  }
*/
  for (src = &_sjtblss, dest = &_sjtbls; dest < &_ejtbls; )
  {
    *dest++ = *src++;
  }

  //showprogress('J');

  /* Perform early serial initialization */
  hal_gpio_init();
  LOG_INIT();
  showprogress('A');
#ifdef USE_EARLYSERIALINIT
  arm_earlyserialinit();
#endif
  showprogress('D');

  /* For the case of the separate user-/kernel-space build, perform whatever
   * platform specific initialization of the user memory is required.
   * Normally this just means initializing the user space .data and .bss
   * segments.
   */

#ifdef CONFIG_BUILD_PROTECTED
  //stm32_userspace();
  showprogress('E');
#endif

  /* Initialize onboard resources */

  //stm32_boardinitialize();
  showprogress('F');

  /* Then start NuttX */

  showprogress('\r');
  showprogress('\n');
#endif

#ifdef CONFIG_PHY6222_BLE
  phy62xx_ble_init();
#endif
  jump_table_base[0] = 0;
  nx_start();

  /* Shouldn't get here */

  for (; ; );
}
