/****************************************************************************
 * arch/arm/src/common/arm_createstack.c
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

#include <sys/types.h>
#include <stdint.h>
#include <string.h>
#include <sched.h>
#include <assert.h>
#include <debug.h>

#include <nuttx/kmalloc.h>
#include <nuttx/arch.h>
#include <nuttx/tls.h>
#include <nuttx/board.h>
#include <arch/board/board.h>

#include "arm_arch.h"
#include "arm_internal.h"

/****************************************************************************
 * Pre-processor Macros
 ****************************************************************************/

/* Configuration */

/* For use with EABI and floating point, the stack must be aligned to 8-byte
 * addresses.
 */

#define CONFIG_STACK_ALIGNMENT 8

/* Stack alignment macros */

#define STACK_ALIGN_MASK    (CONFIG_STACK_ALIGNMENT - 1)
#define STACK_ALIGN_DOWN(a) ((a) & ~STACK_ALIGN_MASK)
#define STACK_ALIGN_UP(a)   (((a) + STACK_ALIGN_MASK) & ~STACK_ALIGN_MASK)

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_create_stack
 *
 * Description:
 *   Allocate a stack for a new thread and setup up stack-related information
 *   in the TCB.
 *
 *   The following TCB fields must be initialized by this function:
 *
 *   - adj_stack_size: Stack size after adjustment for hardware, processor,
 *     etc.  This value is retained only for debug purposes.
 *   - stack_alloc_ptr: Pointer to allocated stack
 *   - adj_stack_ptr: Adjusted stack_alloc_ptr for HW.  The initial value of
 *     the stack pointer.
 *
 * Input Parameters:
 *   - tcb: The TCB of new task
 *   - stack_size:  The requested stack size.  At least this much
 *     must be allocated.
 *   - ttype:  The thread type.  This may be one of following (defined in
 *     include/nuttx/sched.h):
 *
 *       TCB_FLAG_TTYPE_TASK     Normal user task
 *       TCB_FLAG_TTYPE_PTHREAD  User pthread
 *       TCB_FLAG_TTYPE_KERNEL   Kernel thread
 *
 *     This thread type is normally available in the flags field of the TCB,
 *     however, there are certain contexts where the TCB may not be fully
 *     initialized when up_create_stack is called.
 *
 *     If either CONFIG_BUILD_PROTECTED or CONFIG_BUILD_KERNEL are defined,
 *     then this thread type may affect how the stack is allocated.  For
 *     example, kernel thread stacks should be allocated from protected
 *     kernel memory.  Stacks for user tasks and threads must come from
 *     memory that is accessible to user code.
 *
 ****************************************************************************/

int up_create_stack(FAR struct tcb_s *tcb, size_t stack_size, uint8_t ttype)
{
  size_t alloc_size;

  /* Add the size of the TLS information structure and align */

  alloc_size = STACK_ALIGN_UP(stack_size + sizeof(struct tls_info_s));

#ifdef CONFIG_TLS_ALIGNED
  /* The allocated stack size must not exceed the maximum possible for the
   * TLS feature.
   */

  DEBUGASSERT(alloc_size <= TLS_MAXSTACK);
  if (alloc_size > TLS_MAXSTACK)
    {
      alloc_size = TLS_MAXSTACK;
      stack_size = alloc_size - sizeof(struct tls_info_s);
    }
#endif

  /* Is there already a stack allocated of a different size? */

  if (tcb->stack_alloc_ptr && tcb->adj_stack_size != stack_size)
    {
      /* Yes.. Release the old stack */

      up_release_stack(tcb, ttype);
    }

  /* Do we need to allocate a new stack? */

  if (!tcb->stack_alloc_ptr)
    {
      /* Allocate the stack.  If DEBUG is enabled (but not stack debug),
       * then create a zeroed stack to make stack dumps easier to trace.
       * If TLS is enabled, then we must allocate aligned stacks.
       */

#ifdef CONFIG_TLS_ALIGNED
#ifdef CONFIG_MM_KERNEL_HEAP
      /* Use the kernel allocator if this is a kernel thread */

      if (ttype == TCB_FLAG_TTYPE_KERNEL)
        {
          tcb->stack_alloc_ptr =
            (uint32_t *)kmm_memalign(TLS_STACK_ALIGN, alloc_size);
        }
      else
#endif
        {
          /* Use the user-space allocator if this is a task or pthread */

          tcb->stack_alloc_ptr =
            (uint32_t *)kumm_memalign(TLS_STACK_ALIGN, alloc_size);
        }

#else /* CONFIG_TLS_ALIGNED */
#ifdef CONFIG_MM_KERNEL_HEAP
      /* Use the kernel allocator if this is a kernel thread */

      if (ttype == TCB_FLAG_TTYPE_KERNEL)
        {
          tcb->stack_alloc_ptr =
              (uint32_t *)kmm_memalign(CONFIG_STACK_ALIGNMENT, alloc_size);
        }
      else
#endif
        {
          /* Use the user-space allocator if this is a task or pthread */

          tcb->stack_alloc_ptr =
              (uint32_t *)kumm_memalign(CONFIG_STACK_ALIGNMENT, alloc_size);
        }
#endif /* CONFIG_TLS_ALIGNED */

#ifdef CONFIG_DEBUG_FEATURES
      /* Was the allocation successful? */

      if (!tcb->stack_alloc_ptr)
        {
          serr("ERROR: Failed to allocate stack, size %d\n", stack_size);
        }
#endif
    }

  /* Did we successfully allocate a stack? */

  if (tcb->stack_alloc_ptr)
    {
      /* The ARM uses a push-down stack:  the stack grows toward lower
       * addresses in memory.  The stack pointer register, points to
       * the lowest, valid work address (the "top" of the stack).  Items
       * on the stack are referenced as positive word offsets from sp.
       */

      /* Since both stack_alloc_ptr and alloc_size are in
       * CONFIG_STACK_ALIGNMENT, and the stack ptr is decremented before
       * the first write, we can directly save our variables to struct
       * tcb_s.
       */

      tcb->adj_stack_size = stack_size;
      tcb->adj_stack_ptr  = (FAR void *)((uintptr_t)tcb->stack_alloc_ptr +
          alloc_size);

      /* Initialize the TLS data structure */

      memset(tcb->stack_alloc_ptr, 0, sizeof(struct tls_info_s));

#ifdef CONFIG_STACK_COLORATION
      /* If stack debug is enabled, then fill the stack with a
       * recognizable value that we can use later to test for high
       * water marks.
       */

      arm_stack_color((FAR void *)((uintptr_t)tcb->adj_stack_ptr -
          tcb->adj_stack_size), tcb->adj_stack_size);

#endif /* CONFIG_STACK_COLORATION */

      board_autoled_on(LED_STACKCREATED);
      return OK;
    }

  return ERROR;
}

/****************************************************************************
 * Name: arm_stack_color
 *
 * Description:
 *   Write a well know value into the stack
 *
 ****************************************************************************/

#ifdef CONFIG_STACK_COLORATION
void arm_stack_color(FAR void *stackbase, size_t nbytes)
{
  /* Take extra care that we do not write outsize the stack boundaries */

  uint32_t *stkptr = (uint32_t *)(((uintptr_t)stackbase + 3) & ~3);
  uintptr_t stkend = (((uintptr_t)stackbase + nbytes) & ~3);
  size_t    nwords = (stkend - (uintptr_t)stackbase) >> 2;

  /* Set the entire stack to the coloration value */

  while (nwords-- > 0)
    {
      *stkptr++ = STACK_COLOR;
    }
}
#endif
