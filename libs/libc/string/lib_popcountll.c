/****************************************************************************
 * libs/libc/string/lib_popcountll.c
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

#include <nuttx/compiler.h>
#include <strings.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: popcount
 ****************************************************************************/

unsigned int popcountll(unsigned long long j)
{
#ifdef CONFIG_HAVE_BUILTIN_POPCOUNT
  return __builtin_popcountll(j);
#else
  unsigned int count = 0;

  while (j > 0)
    {
      if ((j & 1) == 1)
        {
          count++;
        }

      j >>= 1;
    }

  return count;
#endif
}
