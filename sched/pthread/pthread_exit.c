/****************************************************************************
 * sched/pthread/pthread_exit.c
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
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/arch.h>
#include <nuttx/signal.h>

#include "sched/sched.h"
#include "task/task.h"
#include "pthread/pthread.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: pthread_exit
 *
 * Description:
 *   Terminate execution of a thread started with pthread_create.
 *
 * Input Parameters:
 *   exit_value
 *
 * Returned Value:
 *   None
 *
 * Assumptions:
 *
 ****************************************************************************/

void nx_pthread_exit(FAR void *exit_value)
{
  FAR struct tcb_s *tcb = this_task();
  sigset_t set = ALL_SIGNAL_SET;
  int status;

  sinfo("exit_value=%p\n", exit_value);

  DEBUGASSERT(tcb != NULL);
  DEBUGASSERT((tcb->flags & TCB_FLAG_TTYPE_MASK) == TCB_FLAG_TTYPE_PTHREAD);

  /* Block any signal actions that would awaken us while were
   * are performing the JOIN handshake.
   */

  nxsig_procmask(SIG_SETMASK, &set, NULL);

  /* Complete pending join operations */

  status = pthread_completejoin(getpid(), exit_value);
  if (status != OK)
    {
      /* Assume that the join completion failured because this
       * not really a pthread.  Exit by calling exit().
       */

      exit(EXIT_FAILURE);
    }

  /* Perform common task termination logic.  This will get called again later
   * through logic kicked off by _exit().  However, we need to call it before
   * calling _exit() in order certain operations if this is the last thread
   * of a task group:  (2) To handle atexit() and on_exit() callbacks and
   * (2) so that we can flush buffered I/O (which may required suspending).
   */

  nxtask_exithook(tcb, EXIT_SUCCESS, false);

  /* Then just exit, retaining all file descriptors and without
   * calling atexit() functions.
   */

  up_exit(EXIT_SUCCESS);
}
