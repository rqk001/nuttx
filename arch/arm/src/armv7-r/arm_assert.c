/****************************************************************************
 * arch/arm/src/armv7-r/arm_assert.c
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
#include <stdlib.h>
#include <assert.h>
#include <debug.h>

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/board.h>
#include <nuttx/syslog/syslog.h>
#include <nuttx/usb/usbdev_trace.h>

#include <arch/board/board.h>

#include "arm_arch.h"
#include "sched/sched.h"
#include "arm_internal.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* USB trace dumping */

#ifndef CONFIG_USBDEV_TRACE
#  undef CONFIG_ARCH_USBDUMP
#endif

#ifndef CONFIG_BOARD_RESET_ON_ASSERT
#  define CONFIG_BOARD_RESET_ON_ASSERT 0
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

#ifdef CONFIG_ARCH_STACKDUMP
static uint32_t s_last_regs[XCPTCONTEXT_REGS];
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: arm_stackdump
 ****************************************************************************/

#ifdef CONFIG_ARCH_STACKDUMP
static void arm_stackdump(uint32_t sp, uint32_t stack_top)
{
  uint32_t stack;

  /* Flush any buffered SYSLOG data to avoid overwrite */

  syslog_flush();

  for (stack = sp & ~0x1f; stack < (stack_top & ~0x1f); stack += 32)
    {
      uint32_t *ptr = (uint32_t *)stack;
      _alert("%08x: %08x %08x %08x %08x %08x %08x %08x %08x\n",
             stack, ptr[0], ptr[1], ptr[2], ptr[3],
             ptr[4], ptr[5], ptr[6], ptr[7]);
    }
}
#endif

/****************************************************************************
 * Name: arm_registerdump
 ****************************************************************************/

#ifdef CONFIG_ARCH_STACKDUMP
static inline void arm_registerdump(FAR volatile uint32_t *regs)
{
  int reg;

  /* Are user registers available from interrupt processing? */

  if (regs == NULL)
    {
      /* No.. capture user registers by hand */

      arm_saveusercontext(s_last_regs);
      regs = s_last_regs;
    }

  /* Dump the interrupt registers */

  for (reg = REG_R0; reg <= REG_R15; reg += 8)
    {
      uint32_t *ptr = (uint32_t *)&regs[reg];
      _alert("R%d: %08x %08x %08x %08x %08x %08x %08x %08x\n",
             reg, ptr[0], ptr[1], ptr[2], ptr[3],
             ptr[4], ptr[5], ptr[6], ptr[7]);
    }

  _alert("CPSR: %08x\n", regs[REG_CPSR]);
}
#else
# define arm_registerdump(regs)
#endif

/****************************************************************************
 * Name: arm_dump_task
 ****************************************************************************/

static void arm_dump_task(FAR struct tcb_s *tcb, FAR void *arg)
{
#ifdef CONFIG_STACK_COLORATION
  uint32_t stack_filled = 0;
  uint32_t stack_used;
#endif
#ifdef CONFIG_SCHED_CPULOAD
  struct cpuload_s cpuload;
  uint32_t fracpart;
  uint32_t intpart;
  uint32_t tmp;

  clock_cpuload(tcb->pid, &cpuload);

  if (cpuload.total > 0)
    {
      tmp      = (1000 * cpuload.active) / cpuload.total;
      intpart  = tmp / 10;
      fracpart = tmp - 10 * intpart;
    }
  else
    {
      intpart  = 0;
      fracpart = 0;
    }
#endif

#ifdef CONFIG_STACK_COLORATION
  stack_used = up_check_tcbstack(tcb);
  if (tcb->adj_stack_size > 0 && stack_used > 0)
    {
      /* Use fixed-point math with one decimal place */

      stack_filled = 10 * 100 * stack_used / tcb->adj_stack_size;
    }
#endif

  /* Dump interesting properties of this task */

  _alert("  %4d   %4d"
#ifdef CONFIG_STACK_COLORATION
         "   %7lu"
#endif
         "   %7lu"
#ifdef CONFIG_STACK_COLORATION
         "   %3" PRId32 ".%1" PRId32 "%%%c"
#endif
#ifdef CONFIG_SCHED_CPULOAD
         "   %3" PRId32 ".%01" PRId32 "%%"
#endif
#if CONFIG_TASK_NAME_SIZE > 0
         "   %s"
#endif
         "\n",
         tcb->pid, tcb->sched_priority,
#ifdef CONFIG_STACK_COLORATION
         (unsigned long)up_check_tcbstack(tcb),
#endif
         (unsigned long)tcb->adj_stack_size
#ifdef CONFIG_STACK_COLORATION
         , stack_filled / 10, stack_filled % 10,
         (stack_filled >= 10 * 80 ? '!' : ' ')
#endif
#ifdef CONFIG_SCHED_CPULOAD
         , intpart, fracpart
#endif
#if CONFIG_TASK_NAME_SIZE > 0
         , tcb->name
#endif
        );
}

/****************************************************************************
 * Name: arm_dump_backtrace
 ****************************************************************************/

#ifdef CONFIG_SCHED_BACKTRACE
static void arm_dump_backtrace(FAR struct tcb_s *tcb, FAR void *arg)
{
  /* Show back trace */

  sched_dumpstack(tcb->pid);
}
#endif

/****************************************************************************
 * Name: arm_showtasks
 ****************************************************************************/

static inline void arm_showtasks(void)
{
#if CONFIG_ARCH_INTERRUPTSTACK > 7
#  ifdef CONFIG_STACK_COLORATION
  uint32_t stack_used = up_check_intstack();
  uint32_t stack_filled = 0;

  if ((CONFIG_ARCH_INTERRUPTSTACK & ~7) > 0 && stack_used > 0)
    {
      /* Use fixed-point math with one decimal place */

      stack_filled = 10 * 100 *
                     stack_used / (CONFIG_ARCH_INTERRUPTSTACK & ~7);
    }
#  endif
#endif

  /* Dump interesting properties of each task in the crash environment */

  _alert("   PID    PRI"
#ifdef CONFIG_STACK_COLORATION
         "      USED"
#endif
         "     STACK"
#ifdef CONFIG_STACK_COLORATION
         "   FILLED "
#endif
#ifdef CONFIG_SCHED_CPULOAD
         "      CPU"
#endif
#if CONFIG_TASK_NAME_SIZE > 0
         "   COMMAND"
#endif
         "\n");

#if CONFIG_ARCH_INTERRUPTSTACK > 7
  _alert("  ----   ----"
#  ifdef CONFIG_STACK_COLORATION
         "   %7lu"
#  endif
         "   %7lu"
#  ifdef CONFIG_STACK_COLORATION
         "   %3" PRId32 ".%1" PRId32 "%%%c"
#  endif
#  ifdef CONFIG_SCHED_CPULOAD
         "     ----"
#  endif
#  if CONFIG_TASK_NAME_SIZE > 0
         "   irq"
#  endif
         "\n"
#  ifdef CONFIG_STACK_COLORATION
         , (unsigned long)stack_used
#  endif
         , (unsigned long)(CONFIG_ARCH_INTERRUPTSTACK & ~7)
#  ifdef CONFIG_STACK_COLORATION
         , stack_filled / 10, stack_filled % 10,
         (stack_filled >= 10 * 80 ? '!' : ' ')
#  endif
        );
#endif

  nxsched_foreach(arm_dump_task, NULL);
#ifdef CONFIG_SCHED_BACKTRACE
  nxsched_foreach(arm_dump_backtrace, NULL);
#endif
}

/****************************************************************************
 * Name: assert_tracecallback
 ****************************************************************************/

#ifdef CONFIG_ARCH_USBDUMP
static int usbtrace_syslog(FAR const char *fmt, ...)
{
  va_list ap;

  /* Let vsyslog do the real work */

  va_start(ap, fmt);
  vsyslog(LOG_EMERG, fmt, ap);
  va_end(ap);
  return OK;
}

static int assert_tracecallback(FAR struct usbtrace_s *trace, FAR void *arg)
{
  usbtrace_trprintf(usbtrace_syslog, trace->event, trace->value);
  return 0;
}
#endif

/****************************************************************************
 * Name: up_dumpstate
 ****************************************************************************/

#ifdef CONFIG_ARCH_STACKDUMP
static void up_dumpstate(void)
{
  FAR struct tcb_s *rtcb = running_task();
  uint32_t sp = up_getsp();
  uint32_t ustackbase;
  uint32_t ustacksize;
#if CONFIG_ARCH_INTERRUPTSTACK > 7
  uint32_t istackbase;
  uint32_t istacksize;
#endif
#ifdef CONFIG_ARCH_KERNEL_STACK
  uint32_t kstackbase = 0;
#endif

  /* Show back trace */

#ifdef CONFIG_SCHED_BACKTRACE
  sched_dumpstack(rtcb->pid);
#endif

  /* Dump the registers (if available) */

  arm_registerdump(CURRENT_REGS);

  /* Get the limits on the user stack memory */

  ustackbase = (uint32_t)rtcb->stack_base_ptr;
  ustacksize = (uint32_t)rtcb->adj_stack_size;

  _alert("Current sp: %08x\n", sp);

#if CONFIG_ARCH_INTERRUPTSTACK > 7
  /* Get the limits on the interrupt stack memory */

  istackbase = (uint32_t)&g_intstackalloc;
  istacksize = (CONFIG_ARCH_INTERRUPTSTACK & ~7);

  /* Show interrupt stack info */

  _alert("Interrupt stack:\n");
  _alert("  base: %08x\n", istackbase);
  _alert("  size: %08x\n", istacksize);
#endif

  /* Show user stack info */

  _alert("User stack:\n");
  _alert("  base: %08x\n", ustackbase);
  _alert("  size: %08x\n", ustacksize);

#ifdef CONFIG_ARCH_KERNEL_STACK
  /* Does this thread have a kernel stack allocated? */

  if (rtcb->xcp.kstack)
    {
      kstackbase = (uint32_t)rtcb->xcp.kstack;

      _alert("Kernel stack:\n");
      _alert("  base: %08x\n", kstackbase);
      _alert("  size: %08x\n", CONFIG_ARCH_KERNEL_STACKSIZE);
    }
#endif

#if CONFIG_ARCH_INTERRUPTSTACK > 7
  /* Does the current stack pointer lie within the interrupt stack? */

  if (sp >= istackbase && sp < istackbase + istacksize)
    {
      /* Yes.. dump the interrupt stack */

      _alert("Interrupt Stack\n", sp);
      arm_stackdump(sp, istackbase + istacksize);
    }
  else if (CURRENT_REGS)
    {
      _alert("ERROR: Stack pointer is not within the interrupt stack\n");
      arm_stackdump(istackbase, istackbase + istacksize);
    }
#endif

  /* Extract the user stack pointer if we are in an interrupt handler.
   * If we are not in an interrupt handler.  Then sp is the user stack
   * pointer (and the above range check should have failed).
   */

  if (CURRENT_REGS)
    {
      sp = CURRENT_REGS[REG_R13];
      _alert("User sp: %08x\n", sp);
    }

  /* Dump the user stack if the stack pointer lies within the allocated user
   * stack memory.
   */

  if (sp >= ustackbase && sp < ustackbase + ustacksize)
    {
      _alert("User Stack\n", sp);
      arm_stackdump(sp, ustackbase + ustacksize);
    }

#ifdef CONFIG_ARCH_KERNEL_STACK
  /* Dump the user stack if the stack pointer lies within the allocated
   * kernel stack memory.
   */

  else if (sp >= kstackbase &&
           sp < kstackbase + CONFIG_ARCH_KERNEL_STACKSIZE)
    {
      _alert("Kernel Stack\n", sp);
      arm_stackdump(sp, kstackbase + CONFIG_ARCH_KERNEL_STACKSIZE);
    }
#endif
  else
    {
      _alert("ERROR: Stack pointer is not within the allocated stack\n");
      arm_stackdump(ustackbase, ustackbase + ustacksize);
#ifdef CONFIG_ARCH_KERNEL_STACK
      arm_stackdump(kstackbase, kstackbase + CONFIG_ARCH_KERNEL_STACKSIZE);
#endif
    }

  /* Dump the state of all tasks (if available) */

  arm_showtasks();

#ifdef CONFIG_ARCH_USBDUMP
  /* Dump USB trace data */

  usbtrace_enumerate(assert_tracecallback, NULL);
#endif
}
#else
# define up_dumpstate()
#endif

/****************************************************************************
 * Name: _up_assert
 ****************************************************************************/

static void _up_assert(void)
{
  /* Flush any buffered SYSLOG data */

  syslog_flush();

  /* Are we in an interrupt handler or the idle task? */

  if (CURRENT_REGS || (running_task())->flink == NULL)
    {
      up_irq_save();
      for (; ; )
        {
#if CONFIG_BOARD_RESET_ON_ASSERT >= 1
          board_reset(CONFIG_BOARD_ASSERT_RESET_VALUE);
#endif
#ifdef CONFIG_ARCH_LEDS
          board_autoled_on(LED_PANIC);
          up_mdelay(250);
          board_autoled_off(LED_PANIC);
          up_mdelay(250);
#endif
        }
    }
  else
    {
#if CONFIG_BOARD_RESET_ON_ASSERT >= 2
      board_reset(CONFIG_BOARD_ASSERT_RESET_VALUE);
#endif
    }
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_assert
 ****************************************************************************/

void up_assert(const char *filename, int lineno)
{
  board_autoled_on(LED_ASSERTION);

  /* Flush any buffered SYSLOG data (prior to the assertion) */

  syslog_flush();

#if CONFIG_TASK_NAME_SIZE > 0
  _alert("Assertion failed at file:%s line: %d task: %s\n",
         filename, lineno, running_task()->name);
#else
  _alert("Assertion failed at file:%s line: %d\n",
         filename, lineno);
#endif

  up_dumpstate();

  /* Flush any buffered SYSLOG data (from the above) */

  syslog_flush();

#ifdef CONFIG_BOARD_CRASHDUMP
  board_crashdump(up_getsp(), running_task(), filename, lineno);
#endif

  _up_assert();
}
