/****************************************************************************
 * sched/misc/deadlock.c
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

#include <nuttx/mutex.h>
#include <nuttx/sched.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

struct deadlock_info_s
{
  FAR pid_t *pid;
  size_t count;
  size_t found;
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: waitmutex
 ****************************************************************************/

static FAR mutex_t *getmutex(FAR struct tcb_s *tcb)
{
  FAR sem_t *sem;

  if (tcb == NULL)
    {
      return NULL;
    }

  if (tcb->task_state == TSTATE_WAIT_SEM)
    {
      sem = tcb->waitobj;
      if (sem != NULL && (sem->flags & SEM_TYPE_MUTEX) != 0)
        {
          return (FAR mutex_t *)sem;
        }
    }

  return NULL;
}

/****************************************************************************
 * Name: collect_deadlock
 ****************************************************************************/

static void collect_deadlock(FAR struct tcb_s *tcb, FAR void *arg)
{
  FAR struct deadlock_info_s *info = arg;
  FAR mutex_t *mutex;
  size_t index;

  mutex = getmutex(tcb);
  if (mutex == NULL)
    {
      return;
    }

  for (index = 0; index < info->found; index++)
    {
      if (info->pid[index] == tcb->pid)
        {
          return;
        }
    }

  for (index = info->found; index < info->count; index++)
    {
      pid_t next;
      size_t i;

      next = mutex->holder;
      if (next == NXMUTEX_NO_HOLDER)
        {
          break;
        }

      for (i = info->found; i < index; i++)
        {
          if (info->pid[i] == next)
            {
              info->found = index;
              return;
            }
        }

      info->pid[index] = tcb->pid;
      tcb = nxsched_get_tcb(next);
      mutex = getmutex(tcb);
      if (mutex == NULL)
        {
          break;
        }
    }

  /* if we not find deadlock, clear the pid array */

  memset(&info->pid[info->found], 0,
         (info->count - info->found) * sizeof(pid_t));
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: nxsched_collect_deadlock
 *
 * Description:
 *   Check if there is a deadlock and get the thread pid of the deadlock.
 *
 * Input parameters:
 *   pid   - The array to store the thread pid of the deadlock.
 *   count - The size of the pid array.
 *
 * Returned Value:
 *   The number of thread deadlocks.
 *
 ****************************************************************************/

size_t nxsched_collect_deadlock(FAR pid_t *pid, size_t count)
{
  struct deadlock_info_s info;

  info.pid = pid;
  info.count = count;
  info.found = 0;
  nxsched_foreach(collect_deadlock, &info);
  return info.found;
}
