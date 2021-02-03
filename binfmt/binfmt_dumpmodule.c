/****************************************************************************
 * binfmt/binfmt_dumpmodule.c
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

#include <sched.h>
#include <debug.h>
#include <errno.h>

#include <nuttx/binfmt/binfmt.h>

#include "binfmt.h"

#if defined(CONFIG_DEBUG_FEATURES) && defined(CONFIG_DEBUG_BINFMT) && !defined(CONFIG_BINFMT_DISABLE)

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: dump_module
 *
 * Description:
 *   Load a module into memory and prep it for execution.
 *
 * Returned Value:
 *   This is a NuttX internal function so it follows the convention that
 *   0 (OK) is returned on success and a negated errno is returned on
 *   failure.
 *
 ****************************************************************************/

int dump_module(FAR const struct binary_s *bin)
{
  if (bin)
    {
      binfo("Module:\n");
      binfo("  filename:  %s\n", bin->filename);
      binfo("  argv:      %p\n", bin->argv);
      binfo("  entrypt:   %p\n", bin->entrypt);
      binfo("  mapped:    %p size=%zd\n", bin->mapped, bin->mapsize);
      binfo("  alloc:     %p %p %p\n", bin->alloc[0],
                                       bin->alloc[1],
                                       bin->alloc[2]);
#ifdef CONFIG_BINFMT_CONSTRUCTORS
      binfo("  ctors:     %p nctors=%d\n", bin->ctors, bin->nctors);
      binfo("  dtors:     %p ndtors=%d\n", bin->dtors, bin->ndtors);
#endif
#ifdef CONFIG_ARCH_ADDRENV
      binfo("  addrenv:   %p\n", bin->addrenv);
#endif
      binfo("  stacksize: %zd\n", bin->stacksize);
      binfo("  unload:    %p\n", bin->unload);
    }

  return OK;
}
#endif
