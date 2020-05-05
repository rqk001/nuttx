/****************************************************************************
 * libs/libc/fixedmath/tls_getelem.c
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
#include <assert.h>

#include <nuttx/arch.h>
#include <nuttx/tls.h>
#include <arch/tls.h>

#ifdef CONFIG_TLS

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: tls_get_element
 *
 * Description:
 *   Return an the TLS element associated with the 'elem' index
 *
 * Input Parameters:
 *   elem - Index of TLS element to return
 *
 * Returned Value:
 *   The value of TLS element associated with 'elem'. Errors are not
 *   reported.  Zero is returned in the event of an error, but zero may also
 *   be valid value and returned when there is no error.  The only possible
 *   error would be if elem < 0 or elem >=CONFIG_TLS_NELEM.
 *
 ****************************************************************************/

uintptr_t tls_get_element(int elem)
{
  FAR struct tls_info_s *info;
  uintptr_t ret = 0;

  DEBUGASSERT(elem >= 0 && elem < CONFIG_TLS_NELEM);
  if (elem >= 0 && elem < CONFIG_TLS_NELEM)
    {
      /* Get the TLS info structure from the current threads stack */

      info = up_tls_info();
      DEBUGASSERT(info != NULL);

      /* Get the element value from the TLS info. */

      ret = info->tl_elem[elem];
    }

  return ret;
}

#endif /* CONFIG_TLS */
