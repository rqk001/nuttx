/****************************************************************************
 * arch/xtensa/src/common/xtensa_createstack.c
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
#include <sched.h>
#include <debug.h>

#include <nuttx/kmalloc.h>
#include <nuttx/arch.h>
#include <nuttx/tls.h>
#include <nuttx/board.h>

#include <arch/xtensa/xtensa_coproc.h>
#include <arch/chip/tie.h>
#include <arch/board/board.h>

#include "xtensa.h"
#include "xtensa_mm.h"

/****************************************************************************
 * Pre-processor Macros
 ****************************************************************************/

/* XTENSA requires at least a 16-byte stack alignment. */

#define STACK_ALIGNMENT     16

/* Stack alignment macros */

#define STACK_ALIGN_MASK    (STACK_ALIGNMENT - 1)
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
 *   - stack_base_ptr: Adjusted stack base pointer after the TLS Data and
 *     Arguments has been removed from the stack allocation.
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
 *     If CONFIG_BUILD_KERNEL is defined, then this thread type may affect
 *     how the stack is allocated.  For example, kernel thread stacks should
 *     be allocated from protected kernel memory.  Stacks for user tasks and
 *     threads must come from memory that is accessible to user code.
 *
 ****************************************************************************/

int up_create_stack(FAR struct tcb_s *tcb, size_t stack_size, uint8_t ttype)
{
#if XCHAL_CP_NUM > 0
  struct xcptcontext *xcp;
  uintptr_t cpstart;
#endif

#ifdef CONFIG_TLS_ALIGNED
  /* The allocated stack size must not exceed the maximum possible for the
   * TLS feature.
   */

  DEBUGASSERT(stack_size <= TLS_MAXSTACK);
  if (stack_size >= TLS_MAXSTACK)
    {
      stack_size = TLS_MAXSTACK;
    }
#endif

  /* Is there already a stack allocated of a different size?  Because of
   * alignment issues, stack_size might erroneously appear to be of a
   * different size.  Fortunately, this is not a critical operation.
   */

  if (tcb->stack_alloc_ptr && tcb->adj_stack_size != stack_size)
    {
      /* Yes.. Release the old stack */

      up_release_stack(tcb, ttype);
    }

#if XCHAL_CP_NUM > 0
  /* Add the size of the co-processor save area to the stack allocation.
   * REVISIT:  This may waste memory.  Increasing the caller's requested
   * stack size should only be necessary if the requested size could not
   * hold the co-processor save area.
   */

  stack_size += XTENSA_CP_SA_SIZE;
#endif

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
          tcb->stack_alloc_ptr = kmm_memalign(TLS_STACK_ALIGN, stack_size);
        }
      else
#endif
        {
          /* Use the user-space allocator if this is a task or pthread */

          tcb->stack_alloc_ptr = UMM_MEMALIGN(TLS_STACK_ALIGN, stack_size);
        }

#else /* CONFIG_TLS_ALIGNED */
#ifdef CONFIG_MM_KERNEL_HEAP
      /* Use the kernel allocator if this is a kernel thread */

      if (ttype == TCB_FLAG_TTYPE_KERNEL)
        {
          tcb->stack_alloc_ptr = kmm_malloc(stack_size);
        }
      else
#endif
        {
          /* Use the user-space allocator if this is a task or pthread */

          tcb->stack_alloc_ptr = UMM_MALLOC(stack_size);
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
      uintptr_t top_of_stack;
      size_t size_of_stack;

      /* XTENSA uses a push-down stack:  the stack grows toward lower
       * addresses in memory.  The stack pointer register points to the
       * lowest, valid working address (the "top" of the stack).  Items on
       * the stack are referenced as positive word offsets from sp.
       */

      top_of_stack = (uintptr_t)tcb->stack_alloc_ptr + stack_size;

#if XCHAL_CP_NUM > 0
      /* Allocate the co-processor save area at the top of the (push down)
       * stack.
       *
       * REVISIT:  This is not secure.  In secure built configurations it
       * be more appropriate to use kmm_memalign() to allocate protected
       * memory rather than using the stack.
       */

      cpstart      = (uintptr_t)_CP_ALIGNDOWN(XCHAL_CP0_SA_ALIGN,
                                              top_of_stack -
                                              XCHAL_CP1_SA_ALIGN);
      top_of_stack = cpstart;

      /* Initialize the coprocessor save area (see xtensa_coproc.h) */

      xcp                   = &tcb->xcp;
      xcp->cpstate.cpenable = 0;                   /* No coprocessors active
                                                    * for this thread */
      xcp->cpstate.cpstored = 0;                   /* No coprocessors saved
                                                    * for this thread */
      xcp->cpstate.cpasa    = (uint32_t *)cpstart; /* Start of aligned save
                                                    * area */
#endif

      /* The XTENSA stack must be aligned.  If necessary top_of_stack must be
       * rounded down to the next boundary to meet this alignment
       * requirement.
       *
       * NOTE: Co-processor save area not included in the size of the stack.
       */

      top_of_stack  = STACK_ALIGN_DOWN(top_of_stack);
      size_of_stack = top_of_stack - (uintptr_t)tcb->stack_alloc_ptr;

      /* Save the adjusted stack values in the struct tcb_s */

      tcb->stack_base_ptr = tcb->stack_alloc_ptr;
      tcb->adj_stack_size = size_of_stack;

#ifdef CONFIG_STACK_COLORATION
      /* If stack debug is enabled, then fill the stack with a
       * recognizable value that we can use later to test for high
       * water marks.
       */

      up_stack_color(tcb->stack_base_ptr, tcb->adj_stack_size);
#endif
      tcb->flags |= TCB_FLAG_FREE_STACK;

      board_autoled_on(LED_STACKCREATED);
      return OK;
    }

  return ERROR;
}

/****************************************************************************
 * Name: up_stack_color
 *
 * Description:
 *   Write a well know value into the stack
 *
 ****************************************************************************/

#ifdef CONFIG_STACK_COLORATION
void up_stack_color(FAR void *stackbase, size_t nbytes)
{
  uintptr_t start;
  uintptr_t end;
  size_t nwords;
  FAR uint32_t *ptr;

  /* Take extra care that we do not write outside the stack boundaries */

  start = STACK_ALIGN_UP((uintptr_t)stackbase);
  end   = nbytes ? STACK_ALIGN_DOWN((uintptr_t)stackbase + nbytes) :
          up_getsp(); /* 0: colorize the running stack */

  /* Get the adjusted size based on the top and bottom of the stack */

  nwords = (end - start) >> 2;
  ptr  = (FAR uint32_t *)start;

  /* Set the entire stack to the coloration value */

  while (nwords-- > 0)
    {
      *ptr++ = STACK_COLOR;
    }
}
#endif
