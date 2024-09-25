/****************************************************************************
 * libs/libc/unistd/lib_futimes.c
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

#include <sys/stat.h>
#include <sys/time.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int futimes(int fd, const struct timeval tv[2])
{
  struct timespec times[2];

  if (tv == NULL)
    {
      return futimens(fd, NULL);
    }

  times[0].tv_sec  = tv[0].tv_sec;
  times[0].tv_nsec = tv[0].tv_usec * 1000;
  times[1].tv_sec  = tv[1].tv_sec;
  times[1].tv_nsec = tv[1].tv_usec * 1000;

  return futimens(fd, times);
}
