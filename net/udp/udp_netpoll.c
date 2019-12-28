/****************************************************************************
 * net/udp/udp_netpoll.c
 *
 *   Copyright (C) 2008-2009, 2011-2015, 2018 Gregory Nutt. All rights
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <poll.h>
#include <debug.h>

#include <nuttx/kmalloc.h>
#include <nuttx/wqueue.h>
#include <nuttx/mm/iob.h>
#include <nuttx/net/net.h>

#include "devif/devif.h"
#include "netdev/netdev.h"
#include "socket/socket.h"
#include "udp/udp.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: udp_poll_eventhandler
 *
 * Description:
 *   This function is called to perform the actual UDP receive operation
 *   via the device interface layer.
 *
 * Input Parameters:
 *   dev      The structure of the network driver that caused the event
 *   conn     The connection structure associated with the socket
 *   flags    Set of events describing why the callback was invoked
 *
 * Returned Value:
 *   None
 *
 * Assumptions:
 *   This function must be called with the network locked.
 *
 ****************************************************************************/

static uint16_t udp_poll_eventhandler(FAR struct net_driver_s *dev,
                                      FAR void *conn,
                                      FAR void *pvpriv, uint16_t flags)
{
  FAR struct udp_poll_s *info = (FAR struct udp_poll_s *)pvpriv;

  ninfo("flags: %04x\n", flags);

  DEBUGASSERT(!info || (info->psock && info->fds));

  /* 'priv' might be null in some race conditions (?) */

  if (info)
    {
      pollevent_t eventset = 0;

      /* Check for data or connection availability events. */

      if ((flags & UDP_NEWDATA) != 0)
        {
          eventset |= (POLLIN & info->fds->events);
        }

      /* Check for loss of connection events. */

      if ((flags & NETDEV_DOWN) != 0)
        {
          eventset |= (POLLHUP | POLLERR);
        }

      /* A poll is a sign that we are free to send data. */

      else if ((flags & UDP_POLL) != 0 && psock_udp_cansend(info->psock) >= 0)
        {
          eventset |= (POLLOUT & info->fds->events);
        }

      /* Awaken the caller of poll() is requested event occurred. */

      if (eventset)
        {
          info->fds->revents |= eventset;
          nxsem_post(info->fds->sem);
        }
    }

  return flags;
}

/****************************************************************************
 * Name: udp_iob_work
 *
 * Description:
 *   Work thread callback function execute when an IOB because available.
 *
 * Input Parameters:
 *   psock - Socket state structure
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

#if defined(CONFIG_NET_UDP_WRITE_BUFFERS) && defined(CONFIG_IOB_NOTIFIER)
static inline void udp_iob_work(FAR void *arg)
{
  FAR struct work_notifier_entry_s *entry;
  FAR struct work_notifier_s *ninfo;
  FAR struct udp_poll_s *pinfo;
  FAR struct socket *psock;
  FAR struct pollfd *fds;

  entry = (FAR struct work_notifier_entry_s *)arg;
  DEBUGASSERT(entry != NULL);

  ninfo = &entry->info;
  DEBUGASSERT(ninfo->arg != NULL);

  pinfo = (FAR struct udp_poll_s *)ninfo->arg;
  DEBUGASSERT(pinfo->psock != NULL && pinfo->fds != NULL);

  psock = pinfo->psock;
  fds   = pinfo->fds;

  /* Handle a race condition.  Check if we have already posted the POLLOUT
   * event.  If so, don't do it again.
   */

  if ((fds->events & POLLWRNORM) != 0 &&
      (fds->revents & POLLWRNORM) == 0)
    {
      /* Check if we are now able to send */

      if (psock_udp_cansend(psock) >= 0)
        {
          /* Yes.. then signal the poll logic */

          fds->revents |= POLLWRNORM;
          nxsem_post(fds->sem);
        }
      else
        {
          /* No.. ask for the IOB free notification again */

          pinfo->key = iob_notifier_setup(LPWORK, udp_iob_work, pinfo);
        }
    }

  /* Protocol for the use of the IOB notifier is that we free the argument
   * after the notification has been processed.
   */

  kmm_free(arg);
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: udp_pollsetup
 *
 * Description:
 *   Setup to monitor events on one UDP/IP socket
 *
 * Input Parameters:
 *   psock - The UDP/IP socket of interest
 *   fds   - The structure describing the events to be monitored, OR NULL if
 *           this is a request to stop monitoring events.
 *
 * Returned Value:
 *  0: Success; Negated errno on failure
 *
 ****************************************************************************/

int udp_pollsetup(FAR struct socket *psock, FAR struct pollfd *fds)
{
  FAR struct udp_conn_s *conn = psock->s_conn;
  FAR struct udp_poll_s *info;
  FAR struct devif_callback_s *cb;
  int ret;

  /* Sanity check */

#ifdef CONFIG_DEBUG_FEATURES
  if (conn == NULL || fds == NULL)
    {
      return -EINVAL;
    }
#endif

  /* Some of the  following must be atomic */

  net_lock();

  /* Find a container to hold the poll information */

  info = conn->pollinfo;
  while (info->psock != NULL)
    {
      if (++info >= &conn->pollinfo[CONFIG_NET_UDP_NPOLLWAITERS])
        {
          ret = -ENOMEM;
          goto errout_with_lock;
        }
    }

  /* Get the device that will provide the provide the NETDEV_DOWN event.
   * NOTE: in the event that the local socket is bound to INADDR_ANY, the
   * dev value will be zero and there will be no NETDEV_DOWN notifications.
   */

  info->dev = udp_find_laddr_device(conn);

  /* Allocate a UDP callback structure */

  cb = udp_callback_alloc(info->dev, conn);
  if (cb == NULL)
    {
      ret = -EBUSY;
      goto errout_with_lock;
    }

  /* Initialize the poll info container */

  info->psock  = psock;
  info->fds    = fds;
  info->cb     = cb;
#if defined(CONFIG_NET_UDP_WRITE_BUFFERS) && defined(CONFIG_IOB_NOTIFIER)
  info->key    = 0;
#endif

  /* Initialize the callback structure.  Save the reference to the info
   * structure as callback private data so that it will be available during
   * callback processing.
   */

  cb->flags    = NETDEV_DOWN;
  cb->priv     = (FAR void *)info;
  cb->event    = udp_poll_eventhandler;

  if ((fds->events & POLLOUT) != 0)
    {
      cb->flags |= UDP_POLL;
    }

  if ((fds->events & POLLIN) != 0)
    {
      cb->flags |= UDP_NEWDATA;
    }

  /* Save the reference in the poll info structure as fds private as well
   * for use during poll teardown as well.
   */

  fds->priv = (FAR void *)info;

#ifdef CONFIG_NET_UDP_READAHEAD
  /* Check for read data availability now */

  if (!IOB_QEMPTY(&conn->readahead))
    {
      /* Normal data may be read without blocking. */

      fds->revents |= (POLLRDNORM & fds->events);
    }
#endif

  if (psock_udp_cansend(psock) >= 0)
    {
      /* Normal data may be sent without blocking (at least one byte). */

      fds->revents |= (POLLWRNORM & fds->events);
    }

  /* Check if any requested events are already in effect */

  if (fds->revents != 0)
    {
      /* Yes.. then signal the poll logic */

      nxsem_post(fds->sem);
    }

#if defined(CONFIG_NET_UDP_WRITE_BUFFERS) && defined(CONFIG_IOB_NOTIFIER)
  /* If (1) revents == 0, (2) write buffering is enabled, and (3) the
   * POLLOUT event is needed, then setup to receive a notification an IOB
   * is freed.
   */

  else if ((fds->events & POLLOUT) != 0)
    {
      /* Ask for the IOB free notification */

      info->key = iob_notifier_setup(LPWORK, udp_iob_work, info);
    }
#endif

errout_with_lock:
  net_unlock();
  return ret;
}

/****************************************************************************
 * Name: udp_pollteardown
 *
 * Description:
 *   Teardown monitoring of events on an UDP/IP socket
 *
 * Input Parameters:
 *   psock - The UDP socket of interest
 *   fds   - The structure describing the events to be monitored, OR NULL if
 *           this is a request to stop monitoring events.
 *
 * Returned Value:
 *  0: Success; Negated errno on failure
 *
 ****************************************************************************/

int udp_pollteardown(FAR struct socket *psock, FAR struct pollfd *fds)
{
  FAR struct udp_conn_s *conn = psock->s_conn;
  FAR struct udp_poll_s *info;

  /* Sanity check */

#ifdef CONFIG_DEBUG_FEATURES
  if (!conn || !fds->priv)
    {
      return -EINVAL;
    }
#endif

  /* Recover the socket descriptor poll state info from the poll structure */

  info = (FAR struct udp_poll_s *)fds->priv;
  DEBUGASSERT(info != NULL && info->fds != NULL && info->cb != NULL);
  if (info != NULL)
    {
     #if defined(CONFIG_NET_UDP_WRITE_BUFFERS) && defined(CONFIG_IOB_NOTIFIER)
      /* Cancel any pending IOB free notification */

      if (info->key > 0)
        {
          /* Ask for the IOB free notification */

          iob_notifier_teardown(info->key);
        }
#endif

      /* Release the callback */

      udp_callback_free(info->dev, conn, info->cb);

      /* Release the poll/select data slot */

      info->fds->priv = NULL;

      /* Then free the poll info container */

      info->psock = NULL;
    }

  return OK;
}
