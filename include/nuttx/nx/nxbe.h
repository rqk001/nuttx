/****************************************************************************
 * include/nuttx/nx/nxbe.h
 *
 *   Copyright (C) 2008-2011, 2013, 2017, 2019 Gregory Nutt. All rights
 *     reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
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

#ifndef __INCLUDE_NUTTX_NX_NXBE_H
#define __INCLUDE_NUTTX_NX_NXBE_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>

#include <nuttx/nx/nx.h>
#include <nuttx/nx/nxglib.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

#ifndef CONFIG_NX_NPLANES
#  define CONFIG_NX_NPLANES      1  /* Max number of color planes supported */
#endif

#ifndef CONFIG_NX_NCOLORS
#  define CONFIG_NX_NCOLORS 256
#endif

/* NXBE Definitions *********************************************************/

/* Window flags and helper macros:
 *
 * NXBE_WINDOW_BLOCKED   - Window input is blocked (internal use only)
 * NXBE_WINDOW_FRAMED    - Framed (NxTK) Window
 * NXBE_WINDOW_RAMBACKED - Window is backed by a framebuffer
 * NXBE_WINDOW_MODAL     - Window is in a focused, modal state
 * NXBE_WINDOW_HIDDEN    - Window is hidden
 */

#define NXBE_WINDOW_BLOCKED   (1 << 0) /* Bit 0: The window is blocked and will
                                        *        not receive further input. */
#define NXBE_WINDOW_FRAMED    (1 << 1) /* Bit 1: Framed (NxTK) Window */
#define NXBE_WINDOW_RAMBACKED (1 << 2) /* Bit 2: Window is backed by a framebuffer */
#define NXBE_WINDOW_MODAL     (1 << 3) /* Bit 3: Window is in a focused, modal state */
#define NXBE_WINDOW_HIDDEN    (1 << 4) /* Bit 4: Window is hidden */

/* Valid user flags for different window types.  This is the subset of flags
 * that may be passed with nx_openwindow() or nxtk_openwindow.  Most of the
 * flags are controlled internally or must be selected via NX interfaces.
 * These may be selected by the user when the window is created.
 *
 * Exception:  NXBE_WINDOW_FRAMED is not user-selectable.  It is
 * automatically set by nxtk_openwindow() but appears to be a user
 * setting from the point of view of lower layers.
 */

#ifdef CONFIG_NX_RAMBACKED
#  define NX_WINDOW_USER      (NXBE_WINDOW_RAMBACKED | NXBE_WINDOW_HIDDEN)
#else
#  define NX_WINDOW_USER      NXBE_WINDOW_HIDDEN
#endif

#define NXTK_WINDOW_USER      (NXBE_WINDOW_FRAMED | NX_WINDOW_USER)

/* This is the set of startup flags that could be received in NXBE. */

#define NXBE_WINDOW_USER      (NXBE_WINDOW_FRAMED | NX_WINDOW_USER)

/* Helpful flag macros */

#define NXBE_ISBLOCKED(wnd) \
  (((wnd)->flags & NXBE_WINDOW_BLOCKED) != 0)
#define NXBE_SETBLOCKED(wnd) \
  do { (wnd)->flags |= NXBE_WINDOW_BLOCKED; } while (0)
#define NXBE_CLRBLOCKED(wnd) \
  do { (wnd)->flags &= ~NXBE_WINDOW_BLOCKED; } while (0)

#define NXBE_ISFRAMED(wnd) \
  (((wnd)->flags & NXBE_WINDOW_FRAMED) != 0)
#define NXBE_SETFRAMED(wnd) \
  do { (wnd)->flags |= NXBE_WINDOW_FRAMED; } while (0)
#define NXBE_CLRFRAMED(wnd) \
  do { (wnd)->flags &= ~NXBE_WINDOW_FRAMED; } while (0)

#define NXBE_ISRAMBACKED(wnd) \
  (((wnd)->flags & NXBE_WINDOW_RAMBACKED) != 0)
#define NXBE_SETRAMBACKED(wnd) \
  do { (wnd)->flags |= NXBE_WINDOW_RAMBACKED; } while (0)
#define NXBE_CLRRAMBACKED(wnd) \
  do { (wnd)->flags &= ~NXBE_WINDOW_RAMBACKED; } while (0)

#define NXBE_ISMODAL(wnd) \
  (((wnd)->flags & NXBE_WINDOW_MODAL) != 0)
#define NXBE_SETMODAL(wnd) \
  do { (wnd)->flags |= NXBE_WINDOW_MODAL; } while (0)
#define NXBE_CLRMODAL(wnd) \
  do { (wnd)->flags &= ~NXBE_WINDOW_MODAL; } while (0)

#define NXBE_ISHIDDEN(wnd) \
  (((wnd)->flags & NXBE_WINDOW_HIDDEN) != 0)
#define NXBE_SETHIDDEN(wnd) \
  do { (wnd)->flags |= NXBE_WINDOW_HIDDEN; } while (0)
#define NXBE_CLRHIDDEN(wnd) \
  do { (wnd)->flags &= ~NXBE_WINDOW_HIDDEN; } while (0)

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* Windows ******************************************************************/

/* This structure represents one window.  This is the "base" form of the
 * opaque types NXWINDOW and NXTKWINDOW.  Any Window implementation must
 * be described with a structure that is at least cast-compatible with
 * struct nxbe_window_s.
 */

struct nxbe_state_s;
struct nxmu_conn_s;
struct nxbe_window_s
{
  /* State information */

  FAR struct nxbe_state_s *be;        /* The back-end state structure */
  FAR struct nxmu_conn_s *conn;       /* Connection to the window client */
  FAR const struct nx_callback_s *cb; /* Event handling callbacks */

  /* The following links provide the window's vertical position using a
   * singly linked list.
   */

  FAR struct nxbe_window_s *above;    /* The window "above" this window */
  FAR struct nxbe_window_s *below;    /* The window "below this one */

  /* Window geometry.  The window is described by a rectangle in the
   * absolute screen coordinate system (0,0)->(xres,yres)
   */

  struct nxgl_rect_s bounds;          /* The bounding rectangle of the window */

  /* Window flags (see the NXBE_* bit definitions above) */

  uint8_t flags;

#ifdef CONFIG_NX_RAMBACKED
  /* Per-window framebuffer support */

#ifdef CONFIG_BUILD_KERNEL
  uint16_t npages;                    /* Number of pages in allocation */
#endif
  nxgl_coord_t stride;                /* Width of framebuffer in bytes */
  FAR nxgl_mxpixel_t *fbmem;          /* Allocated framebuffer in kernel
                                       * address spaced.  Must be contiguous.
                                       */
#endif

  /* Client state information this is provide in window callbacks
   * Set by nx_openwindow, nx_requestbkgd, nxtk_openwindow, or
   * nxtk_opentoolbar and persists for the life of the window.
   */

  FAR void *arg;
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Functions Definitions
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __INCLUDE_NUTTX_NX_NXBE_H */
