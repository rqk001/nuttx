/****************************************************************************
 * sched/mqueue/mq_timedreceive.c
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

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <mqueue.h>
#include <debug.h>

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/wdog.h>
#include <nuttx/mqueue.h>
#include <nuttx/cancelpt.h>

#include "sched/sched.h"
#include "clock/clock.h"
#include "mqueue/mqueue.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: nxmq_rcvtimeout
 *
 * Description:
 *   This function is called if the timeout elapses before the message queue
 *   becomes non-empty.
 *
 * Input Parameters:
 *   arg - the argument provided when the timeout was configured.
 *
 * Returned Value:
 *   None
 *
 * Assumptions:
 *
 ****************************************************************************/

static void nxmq_rcvtimeout(wdparm_t arg)
{
  FAR struct tcb_s *wtcb = (FAR struct tcb_s *)(uintptr_t)arg;
  irqstate_t flags;

  /* Disable interrupts.  This is necessary because an interrupt handler may
   * attempt to send a message while we are doing this.
   */

  flags = enter_critical_section();

  /* It is also possible that an interrupt/context switch beat us to the
   * punch and already changed the task's state.
   */

  if (wtcb->task_state == TSTATE_WAIT_MQNOTEMPTY)
    {
      /* Restart with task with a timeout error */

      nxmq_wait_irq(wtcb, ETIMEDOUT);
    }

  /* Interrupts may now be re-enabled. */

  leave_critical_section(flags);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: file_mq_timedreceive_internal
 *
 * Description:
 *   This is an internal function of file_mq_timedreceive()/
 *   file_mq_tickreceive(), please refer to the detailed description for
 *   more information.
 *
 * Input Parameters:
 *   mq      - Message Queue Descriptor
 *   msg     - Buffer to receive the message
 *   msglen  - Size of the buffer in bytes
 *   prio    - If not NULL, the location to store message priority.
 *   abstime - the absolute time to wait until a timeout is declared.
 *   ticks   - Ticks to wait from the start time until the semaphore is
 *             posted.
 *
 * Returned Value:
 *   This is an internal OS interface and should not be used by applications.
 *   It follows the NuttX internal error return policy:  Zero (OK) is
 *   returned on success.  A negated errno value is returned on failure.
 *   (see mq_timedreceive() for the list list valid return values).
 *
 ****************************************************************************/

static ssize_t
file_mq_timedreceive_internal(FAR struct file *mq, FAR char *msg,
                              size_t msglen, FAR unsigned int *prio,
                              FAR const struct timespec *abstime,
                              sclock_t ticks)
{
  FAR struct tcb_s *rtcb = this_task();
  FAR struct mqueue_inode_s *msgq;
  FAR struct mqueue_msg_s *mqmsg;
  irqstate_t flags;
  int ret;

  DEBUGASSERT(up_interrupt_context() == false);

  /* Verify the input parameters and, in case of an error, set
   * errno appropriately.
   */

  ret = nxmq_verify_receive(mq, msg, msglen);
  if (ret < 0)
    {
      return ret;
    }

  msgq = mq->f_inode->i_private;

  /* Furthermore, nxmq_wait_receive() expects to have interrupts disabled
   * because messages can be sent from interrupt level.
   */

  flags = enter_critical_section();

  /* Check if the message queue is empty.  If it is NOT empty, then we
   * will not need to start timer.
   */

  if (list_is_empty(&msgq->msglist))
    {
      if (abstime != NULL)
        {
          if (abstime->tv_nsec < 0 || abstime->tv_nsec >= 1000000000)
            {
              ret = -EINVAL;
            }
          else
            {
              /* Convert the timespec to clock ticks.
               * We must have interrupts disabled here so that
               * this time stays valid until the wait begins.
               */

              clock_abstime2ticks(CLOCK_REALTIME, abstime, &ticks);
            }

          /* Handle any time-related errors */

          if (ret != OK)
            {
              goto errout_in_critical_section;
            }
        }

      /* If the time has already expired and the message queue is empty,
       * return immediately.
       */

      if (ticks <= 0)
        {
          ret = -ETIMEDOUT;
          goto errout_in_critical_section;
        }

      /* Start the watchdog */

      wd_start(&rtcb->waitdog, ticks, nxmq_rcvtimeout, (wdparm_t)rtcb);
    }

  /* Get the message from the message queue */

  ret = nxmq_wait_receive(msgq, mq->f_oflags, &mqmsg);

  /* Stop the watchdog timer (this is not harmful in the case where
   * it was never started)
   */

  wd_cancel(&rtcb->waitdog);

  /* Check if we got a message from the message queue.  We might
   * not have a message if:
   *
   * - The message queue is empty and O_NONBLOCK is set in the mqdes
   * - The wait was interrupted by a signal
   * - The watchdog timeout expired
   */

  if (ret == OK)
    {
      DEBUGASSERT(mqmsg != NULL);
      ret = nxmq_do_receive(msgq, mqmsg, msg, prio);
    }

  /* We can now restore interrupts */

errout_in_critical_section:
  leave_critical_section(flags);

  return ret;
}

/****************************************************************************
 * Name: file_mq_timedreceive
 *
 * Description:
 *   This function receives the oldest of the highest priority messages from
 *   the message queue specified by "mq."  If the message queue is empty
 *   and O_NONBLOCK was not set, file_mq_timedreceive() will block until a
 *   message is added to the message queue (or until a timeout occurs).
 *
 *   file_mq_timedreceive() is an internal OS interface.  It is functionally
 *   equivalent to mq_timedreceive() except that:
 *
 *   - It is not a cancellation point, and
 *   - It does not modify the errno value.
 *
 *  See comments with mq_timedreceive() for a more complete description of
 *  the behavior of this function
 *
 * Input Parameters:
 *   mq      - Message Queue Descriptor
 *   msg     - Buffer to receive the message
 *   msglen  - Size of the buffer in bytes
 *   prio    - If not NULL, the location to store message priority.
 *   abstime - the absolute time to wait until a timeout is declared.
 *
 * Returned Value:
 *   This is an internal OS interface and should not be used by applications.
 *   It follows the NuttX internal error return policy:  Zero (OK) is
 *   returned on success.  A negated errno value is returned on failure.
 *   (see mq_timedreceive() for the list list valid return values).
 *
 ****************************************************************************/

ssize_t file_mq_timedreceive(FAR struct file *mq, FAR char *msg,
                             size_t msglen, FAR unsigned int *prio,
                             FAR const struct timespec *abstime)
{
  return file_mq_timedreceive_internal(mq, msg, msglen, prio, abstime, 0);
}

/****************************************************************************
 * Name: file_mq_tickreceive
 *
 * Description:
 *   This function receives the oldest of the highest priority messages from
 *   the message queue specified by "mq."  If the message queue is empty
 *   and O_NONBLOCK was not set, file_mq_tickreceive() will block until a
 *   message is added to the message queue (or until a timeout occurs).
 *
 *   file_mq_tickreceive() is an internal OS interface.  It is functionally
 *   equivalent to mq_timedreceive() except that:
 *
 *   - It is not a cancellation point, and
 *   - It does not modify the errno value.
 *
 *  See comments with mq_timedreceive() for a more complete description of
 *  the behavior of this function
 *
 * Input Parameters:
 *   mq      - Message Queue Descriptor
 *   msg     - Buffer to receive the message
 *   msglen  - Size of the buffer in bytes
 *   prio    - If not NULL, the location to store message priority.
 *   ticks   - Ticks to wait from the start time until the semaphore is
 *             posted.
 *
 * Returned Value:
 *   This is an internal OS interface and should not be used by applications.
 *   It follows the NuttX internal error return policy:  Zero (OK) is
 *   returned on success.  A negated errno value is returned on failure.
 *   (see mq_timedreceive() for the list list valid return values).
 *
 ****************************************************************************/

ssize_t file_mq_tickreceive(FAR struct file *mq, FAR char *msg,
                            size_t msglen, FAR unsigned int *prio,
                            sclock_t ticks)
{
  return file_mq_timedreceive_internal(mq, msg, msglen, prio, NULL, ticks);
}

/****************************************************************************
 * Name: nxmq_timedreceive
 *
 * Description:
 *   This function receives the oldest of the highest priority messages from
 *   the message queue specified by "mqdes."  If the message queue is empty
 *   and O_NONBLOCK was not set, nxmq_timedreceive() will block until a
 *   message is added to the message queue (or until a timeout occurs).
 *
 *   nxmq_timedreceive() is an internal OS interface.  It is functionally
 *   equivalent to mq_timedreceive() except that:
 *
 *   - It is not a cancellation point, and
 *   - It does not modify the errno value.
 *
 *  See comments with mq_timedreceive() for a more complete description of
 *  the behavior of this function
 *
 * Input Parameters:
 *   mqdes   - Message Queue Descriptor
 *   msg     - Buffer to receive the message
 *   msglen  - Size of the buffer in bytes
 *   prio    - If not NULL, the location to store message priority.
 *   abstime - the absolute time to wait until a timeout is declared.
 *
 * Returned Value:
 *   This is an internal OS interface and should not be used by applications.
 *   It follows the NuttX internal error return policy:  Zero (OK) is
 *   returned on success.  A negated errno value is returned on failure.
 *   (see mq_timedreceive() for the list list valid return values).
 *
 ****************************************************************************/

ssize_t nxmq_timedreceive(mqd_t mqdes, FAR char *msg, size_t msglen,
                          FAR unsigned int *prio,
                          FAR const struct timespec *abstime)
{
  FAR struct file *filep;
  ssize_t ret;

  ret = fs_getfilep(mqdes, &filep);
  if (ret < 0)
    {
      return ret;
    }

  ret = file_mq_timedreceive_internal(filep, msg, msglen, prio, abstime, 0);
  fs_putfilep(filep);
  return ret;
}

/****************************************************************************
 * Name: mq_timedreceive
 *
 * Description:
 *   This function receives the oldest of the highest priority messages from
 *   the message queue specified by "mqdes."  If the size of the buffer in
 *   bytes (msglen) is less than the "mq_msgsize" attribute of the message
 *   queue, mq_timedreceive will return an error.  Otherwise, the selected
 *   message is removed from the queue and copied to "msg."
 *
 *   If the message queue is empty and O_NONBLOCK was not set,
 *   mq_timedreceive() will block until a message is added to the message
 *   queue (or until a timeout occurs).  If more than one task is waiting
 *   to receive a message, only the task with the highest priority that has
 *   waited the longest will be unblocked.
 *
 *   mq_timedreceive() behaves just like mq_receive(), except that if the
 *   queue is empty and the O_NONBLOCK flag is not enabled for the message
 *   queue description, then abstime points to a structure which specifies a
 *   ceiling on the time for which the call will block.  This ceiling is an
 *   absolute timeout in seconds and nanoseconds since the Epoch (midnight
 *   on the morning of 1 January 1970).
 *
 *   If no message is available, and the timeout has already expired by the
 *   time of the call, mq_timedreceive() returns immediately.
 *
 * Input Parameters:
 *   mqdes   - Message Queue Descriptor
 *   msg     - Buffer to receive the message
 *   msglen  - Size of the buffer in bytes
 *   prio    - If not NULL, the location to store message priority.
 *   abstime - the absolute time to wait until a timeout is declared.
 *
 * Returned Value:
 *   On success, the length of the selected message in bytes is returned.
 *   On failure, -1 (ERROR) is returned and the errno is set appropriately:
 *
 *   EAGAIN    The queue was empty, and the O_NONBLOCK flag was set
 *             for the message queue description referred to by 'mqdes'.
 *   EPERM     Message queue opened not opened for reading.
 *   EMSGSIZE  'msglen' was less than the maxmsgsize attribute of the
 *             message queue.
 *   EINTR     The call was interrupted by a signal handler.
 *   EINVAL    Invalid 'msg' or 'mqdes' or 'abstime'
 *   ETIMEDOUT The call timed out before a message could be transferred.
 *
 ****************************************************************************/

ssize_t mq_timedreceive(mqd_t mqdes, FAR char *msg, size_t msglen,
                        FAR unsigned int *prio,
                        FAR const struct timespec *abstime)
{
  int ret;

  /* mq_timedreceive() is a cancellation point */

  enter_cancellation_point();

  /* Let nxmq_timedreceive do all of the work */

  ret = nxmq_timedreceive(mqdes, msg, msglen, prio, abstime);
  if (ret < 0)
    {
      set_errno(-ret);
      ret = ERROR;
    }

  leave_cancellation_point();
  return ret;
}
