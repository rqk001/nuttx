/****************************************************************************
 * libs/libnx/nxmu/nx_fill.c
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

#include <mqueue.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/nx/nxglib.h>
#include <nuttx/nx/nx.h>
#include <nuttx/nx/nxbe.h>
#include <nuttx/nx/nxmu.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: nx_fill
 *
 * Description:
 *  Fill the specified rectangle in the window with the specified color
 *
 * Input Parameters:
 *   hwnd  - The window handle
 *   rect  - The location to be filled
 *   color - The color to use in the fill
 *
 * Returned Value:
 *   OK on success; ERROR on failure with errno set appropriately
 *
 ****************************************************************************/

int nx_fill(NXWINDOW hwnd, FAR const struct nxgl_rect_s *rect,
            nxgl_mxpixel_t color[CONFIG_NX_NPLANES])
{
  FAR struct nxbe_window_s *wnd = (FAR struct nxbe_window_s *)hwnd;
  struct nxsvrmsg_fill_s  outmsg;

#ifdef CONFIG_DEBUG_FEATURES
  if (wnd == NULL || rect == NULL || color == NULL)
    {
      set_errno(EINVAL);
      return ERROR;
    }
#endif

  /* Format the fill command */

  outmsg.msgid = NX_SVRMSG_FILL;
  outmsg.wnd   = wnd;

  nxgl_rectcopy(&outmsg.rect, rect);
  nxgl_colorcopy(outmsg.color, color);

  /* Forward the fill command to the server */

  return nxmu_sendwindow(wnd, &outmsg, sizeof(struct nxsvrmsg_fill_s));
}
