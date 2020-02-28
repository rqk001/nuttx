/****************************************************************************
 * sched/group/group_setgid.c
 *
 *   Copyright (C) 2019 Gregory Nutt. All rights reserved.
 *   Author:  Gregory Nutt <gnutt@nuttx.net>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <unistd.h>
#include <errno.h>

#include <sched/sched.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: setgid
 *
 * Description:
 *   The setgid() function sets the real group ID, effective group ID, and
 *   the saved set-group-ID of the calling process to gid, given appropriate
 *   privileges.
 *
 * Input Parameters:
 *   gid - Identity to set the various process's group ID attributes to.
 *
 * Returned Value:
 *   Zero if successful and -1 in case of failure, in which case errno is set
 *   to one of he following values:
 *
 *   EINVAL - The value of the uid argument is invalid and not supported by
 *            the implementation.
 *   EPERM  - The process does not have appropriate privileges and uid does
 *            not match the real group ID or the saved set-group-ID.
 *
 ****************************************************************************/

int setgid(gid_t gid)
{
  FAR struct tcb_s *rtcb;
  FAR struct task_group_s *rgroup;

  /* Verify that the GID is in the valid range of 0 through INT16_MAX.
   * OpenGroup.org does not specify a GID_MAX or GID_MIN.  Instead we use a
   * priori knowledge that gid_t is type int16_t.
   */

  if ((uint16_t)gid > INT16_MAX)
    {
      set_errno(EINVAL);
      return ERROR;
    }

  /* Get the currently executing thread's task group. */

  rtcb   = this_task();
  rgroup = rtcb->group;

  /* Set the task group's group identity. */

  DEBUGASSERT(group != NULL);
  rgroup->tg_gid = gid;
  return OK;
}
