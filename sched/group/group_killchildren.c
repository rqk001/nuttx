/****************************************************************************
 * sched/group/group_killchildren.c
 *
 * SPDX-License-Identifier: Apache-2.0
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
#include <debug.h>
#include <pthread.h>
#include <sched.h>
#include <stdint.h>
#include <sys/types.h>

#include <nuttx/sched.h>
#include <nuttx/signal.h>

#include "sched/sched.h"
#include "group/group.h"

#ifdef HAVE_GROUP_MEMBERS

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: group_kill_children_handler
 *
 * Description:
 *   Callback from group_foreachchild that handles one member of the group.
 *
 * Input Parameters:
 *   pid - The ID of the group member that may be signaled.
 *   arg - The PID of the thread to be retained.
 *
 * Returned Value:
 *   0 (OK) always
 *
 ****************************************************************************/

#if defined(CONFIG_GROUP_KILL_CHILDREN_TIMEOUT_MS) && \
            CONFIG_GROUP_KILL_CHILDREN_TIMEOUT_MS != 0
static int group_kill_children_handler(pid_t pid, FAR void *arg)
{
  /* Cancel all threads except for the one specified by the argument */

  if (pid != (pid_t)((uintptr_t)arg))
    {
      tkill(pid, SIGTERM);
    }

  return OK;
}
#endif

/****************************************************************************
 * Name: group_cancel_children_handler
 *
 * Description:
 *   Callback from group_foreachchild that handles one member of the group.
 *
 * Input Parameters:
 *   pid - The ID of the group member that may be signaled.
 *   arg - The PID of the thread to be retained.
 *
 * Returned Value:
 *   0 (OK) always
 *
 ****************************************************************************/

static int group_cancel_children_handler(pid_t pid, FAR void *arg)
{
  FAR struct tcb_s *rtcb;
  int ret;

  /* Cancel all threads except for the one specified by the argument */

  if (pid != (pid_t)((uintptr_t)arg))
    {
      rtcb = nxsched_get_tcb(pid);
      if (rtcb != NULL)
        {
          /* Cancel this thread.  This is a forced cancellation. */

          rtcb->flags |= TCB_FLAG_FORCED_CANCEL;

          /* 'pid' could refer to the main task of the thread.  That pid
           * will appear in the group member list as well!
           */

          if ((rtcb->flags & TCB_FLAG_TTYPE_MASK) == TCB_FLAG_TTYPE_PTHREAD)
            {
              ret = pthread_cancel(pid);
            }
          else
            {
              ret = nxtask_delete(pid);
            }

          if (ret < 0)
            {
              serr("ERROR: Failed to kill %d: %d\n", ret, pid);
            }
        }
    }

  /* Always return zero.  We need to visit each member of the group. */

  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: group_kill_children
 *
 * Description:
 *   Delete all children of a task except for the specified task.  This is
 *   used by the task restart logic and by the default signal handling
 *   abnormal termination logic.  When the main task is restarted or killed,
 *   all of its child pthreads must be terminated.
 *
 * Input Parameters:
 *   tcb - TCB of the task to be retained.
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

int group_kill_children(FAR struct tcb_s *tcb)
{
  irqstate_t flags;
  int ret;

  DEBUGASSERT(tcb->group);

  if (tcb->group->tg_flags & GROUP_FLAG_EXITING)
    {
      return 0;
    }

  flags = enter_critical_section();

  /* Tell the children that this group has started exiting */

  tcb->group->tg_flags |= GROUP_FLAG_EXITING;

#if defined(CONFIG_GROUP_KILL_CHILDREN_TIMEOUT_MS) && \
            CONFIG_GROUP_KILL_CHILDREN_TIMEOUT_MS != 0

  if ((tcb->flags & TCB_FLAG_FORCED_CANCEL) == 0)
    {
      /* Send SIGTERM for each first */

      group_foreachchild(tcb->group, group_kill_children_handler,
                         (FAR void *)((uintptr_t)tcb->pid));

      /* Wait a bit for child exit */

      ret = CONFIG_GROUP_KILL_CHILDREN_TIMEOUT_MS;
      while (1)
        {
          if (sq_empty(&tcb->group->tg_members) ||
              sq_is_singular(&tcb->group->tg_members))
            {
              break;
            }

          nxsig_usleep(USEC_PER_MSEC);

#  if CONFIG_GROUP_KILL_CHILDREN_TIMEOUT_MS > 0
          if (--ret < 0)
            {
              break;
            }
#  endif
        }
    }
#endif

  /* Force cancel/delete again */

  ret = group_foreachchild(tcb->group, group_cancel_children_handler,
                           (FAR void *)((uintptr_t)tcb->pid));
  leave_critical_section(flags);

  return ret;
}

#endif /* HAVE_GROUP_MEMBERS */
