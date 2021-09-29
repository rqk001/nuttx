/****************************************************************************
 * libs/libc/sched/task_exit.c
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

#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <debug.h>
#include <errno.h>

#include <nuttx/sched.h>
#include <nuttx/tls.h>

/****************************************************************************
 * Private Functions
 ****************************************************************************/

#if defined(CONFIG_SCHED_ATEXIT) || defined(CONFIG_SCHED_ONEXIT)

/****************************************************************************
 * Name: nxtask_onexit
 *
 * Description:
 *   Handle SIGEXIT (Call atexit/on_exit callbacks on exit).
 *
 ****************************************************************************/

static void nxtask_onexit(FAR struct task_info_s *info, int status)
{
  int index;

  DEBUGASSERT(info);

  /* Call each on_exit function in reverse order of registration.
       * on_exit() functions are registered from lower to higher array
       * indices; they must be called in the reverse order of registration
       * when the task group exits, i.e., from higher to lower indices.
       */

  for (index = CONFIG_SCHED_EXIT_MAX - 1; index >= 0; index--)
    {
      if (info->ta_exit[index].func.on)
        {
          onexitfunc_t func;
          FAR void *arg;

          /* Nullify the on_exit function to prevent its reuse. */

          func = info->ta_exit[index].func.on;
          arg = info->ta_exit[index].arg;

          info->ta_exit[index].func.on = NULL;
          info->ta_exit[index].arg = NULL;

          /* Call the on_exit function */

          (*func)(status, arg);
        }
    }
}

#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: exit
 *
 * Description:
 *   The exit() function causes normal process termination and the value of
 *   status & 0377 to be returned to the parent.
 *
 *   All open streams are flushed and closed.
 *
 ****************************************************************************/

void exit(int status)
{
#if defined(CONFIG_SCHED_ATEXIT) || defined(CONFIG_SCHED_ONEXIT)
  FAR struct task_info_s *info = task_get_info();

  DEBUGASSERT(info);

  if (info->ta_nmembers == 1)
    {
      nxtask_onexit(info, status);
    }
#endif

  nx_exit(status);
}
