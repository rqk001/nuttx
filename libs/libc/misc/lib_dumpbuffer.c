/****************************************************************************
 * libs/libc/misc/lib_dumpbuffer.c
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
#include <nuttx/compiler.h>

#include <stdint.h>
#include <debug.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lib_dumpbuffer
 *
 * Description:
 *  Do a pretty buffer dump.
 *
 *  A fairly large on-stack buffer is used for the case where timestamps are
 *  applied to each line.
 *
 ****************************************************************************/

void lib_dumpbuffer(FAR const char *msg, FAR const uint8_t *buffer,
                    unsigned int buflen)
{
  struct iovec buf =
    {
      .iov_base = (FAR char *)buffer,
      .iov_len = buflen,
    };

  lib_dumpvbuffer(msg, &buf, 1);
}

/****************************************************************************
 * Name: lib_writebuffer
 *
 * Description:
 *  Do a pretty buffer dump to a specified file descriptor.
 *
 *  A fairly large on-stack buffer is used for the case where timestamps are
 *  applied to each line.
 *
 ****************************************************************************/

void lib_writebuffer(int fd, FAR const char *msg,
                     FAR const uint8_t *buffer, unsigned int buflen)
{
  struct iovec buf =
    {
      .iov_base = (FAR char *)buffer,
      .iov_len = buflen,
    };

  lib_writevbuffer(fd, msg, &buf, 1);
}
