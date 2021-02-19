/****************************************************************************
 * net/socket/accept.c
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
#include <sys/socket.h>

#include <errno.h>
#include <assert.h>
#include <debug.h>

#include <nuttx/cancelpt.h>
#include <arch/irq.h>

#include "socket/socket.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: psock_accept
 *
 * Description:
 *   The psock_accept function is used with connection-based socket types
 *   (SOCK_STREAM, SOCK_SEQPACKET and SOCK_RDM). It extracts the first
 *   connection request on the queue of pending connections, creates a new
 *   connected socket with mostly the same properties as 'sockfd', and
 *   allocates a new socket descriptor for the socket, which is returned. The
 *   newly created socket is no longer in the listening state. The original
 *   socket 'sockfd' is unaffected by this call.  Per file descriptor flags
 *   are not inherited across an psock_accept.
 *
 *   The 'sockfd' argument is a socket descriptor that has been created with
 *   socket(), bound to a local address with bind(), and is listening for
 *   connections after a call to listen().
 *
 *   On return, the 'addr' structure is filled in with the address of the
 *   connecting entity. The 'addrlen' argument initially contains the size
 *   of the structure pointed to by 'addr'; on return it will contain the
 *   actual length of the address returned.
 *
 *   If no pending connections are present on the queue, and the socket is
 *   not marked as non-blocking, psock_accept blocks the caller until a
 *   connection is present. If the socket is marked non-blocking and no
 *   pending connections are present on the queue, psock_accept returns
 *   EAGAIN.
 *
 * Input Parameters:
 *   psock    Reference to the listening socket structure
 *   addr     Receives the address of the connecting client
 *   addrlen  Input: allocated size of 'addr', Return: returned size
 *            of 'addr'
 *   newsock  Location to return the accepted socket information.
 *
 * Returned Value:
 *  Returns 0 (OK) on success.  On failure, it returns a negated errno value
 *  to indicate the nature of the error.
 *
 * EAGAIN or EWOULDBLOCK
 *   The socket is marked non-blocking and no connections are present to
 *   be accepted.
 * EOPNOTSUPP
 *   The referenced socket is not of type SOCK_STREAM.
 * EINTR
 *   The system call was interrupted by a signal that was caught before
 *   a valid connection arrived.
 * ECONNABORTED
 *   A connection has been aborted.
 * EINVAL
 *   Socket is not listening for connections.
 * EMFILE
 *   The per-process limit of open file descriptors has been reached.
 * ENFILE
 *   The system maximum for file descriptors has been reached.
 * EFAULT
 *   The addr parameter is not in a writable part of the user address space.
 * ENOBUFS or ENOMEM
 *   Not enough free memory.
 * EPROTO
 *   Protocol error.
 * EPERM
 *   Firewall rules forbid connection.
 *
 ****************************************************************************/

int psock_accept(FAR struct socket *psock, FAR struct sockaddr *addr,
                 FAR socklen_t *addrlen, FAR struct socket *newsock)
{
  int ret;

  DEBUGASSERT(psock != NULL && psock->s_conn != NULL && newsock != NULL);

  /* May sure that the socket has been opened with socket() */

  if (psock == NULL || psock->s_conn == NULL)
    {
      nerr("ERROR: Socket invalid or not opened\n");
      return -EINVAL;
    }

  /* Is the socket listening for a connection? */

  if (!_SS_ISLISTENING(psock->s_flags))
    {
      nerr("ERROR: Socket is not listening for a connection.\n");
      return -EINVAL;
    }

  /* Let the address family's accept() method handle the operation */

  DEBUGASSERT(psock->s_sockif != NULL && psock->s_sockif->si_accept != NULL);

  net_lock();
  ret = psock->s_sockif->si_accept(psock, addr, addrlen, newsock);
  if (ret < 0)
    {
      nerr("ERROR: si_accept failed: %d\n", ret);
      goto errout_with_lock;
    }

  /* Mark the new socket as connected. */

  newsock->s_flags |= _SF_CONNECTED;
  newsock->s_flags &= ~_SF_CLOSED;

  ret = OK;

errout_with_lock:
  net_unlock();
  return ret;
}

/****************************************************************************
 * Name: accept
 *
 * Description:
 *   The accept function is used with connection-based socket types
 *   (SOCK_STREAM, SOCK_SEQPACKET and SOCK_RDM). It extracts the first
 *   connection request on the queue of pending connections, creates a new
 *   connected socket with mostly the same properties as 'sockfd', and
 *   allocates a new socket descriptor for the socket, which is returned. The
 *   newly created socket is no longer in the listening state. The original
 *   socket 'sockfd' is unaffected by this call.  Per file descriptor flags
 *   are not inherited across an accept.
 *
 *   The 'sockfd' argument is a socket descriptor that has been created with
 *   socket(), bound to a local address with bind(), and is listening for
 *   connections after a call to listen().
 *
 *   On return, the 'addr' structure is filled in with the address of the
 *   connecting entity. The 'addrlen' argument initially contains the size
 *   of the structure pointed to by 'addr'; on return it will contain the
 *   actual length of the address returned.
 *
 *   If no pending connections are present on the queue, and the socket is
 *   not marked as non-blocking, accept blocks the caller until a connection
 *   is present. If the socket is marked non-blocking and no pending
 *   connections are present on the queue, accept returns EAGAIN.
 *
 * Input Parameters:
 *   sockfd   The listening socket descriptor
 *   addr     Receives the address of the connecting client
 *   addrlen  Input: allocated size of 'addr',
 *            Return: returned size of 'addr'
 *
 * Returned Value:
 *  Returns -1 on error. If it succeeds, it returns a non-negative integer
 *  that is a descriptor for the accepted socket.
 *
 * EAGAIN or EWOULDBLOCK
 *   The socket is marked non-blocking and no connections are present to
 *   be accepted.
 * EBADF
 *   The descriptor is invalid.
 * ENOTSOCK
 *  The descriptor references a file, not a socket.
 * EOPNOTSUPP
 *   The referenced socket is not of type SOCK_STREAM.
 * EINTR
 *   The system call was interrupted by a signal that was caught before
 *   a valid connection arrived.
 * ECONNABORTED
 *   A connection has been aborted.
 * EINVAL
 *   Socket is not listening for connections.
 * EMFILE
 *   The per-process limit of open file descriptors has been reached.
 * ENFILE
 *   The system maximum for file descriptors has been reached.
 * EFAULT
 *   The addr parameter is not in a writable part of the user address
 *   space.
 * ENOBUFS or ENOMEM
 *   Not enough free memory.
 * EPROTO
 *   Protocol error.
 * EPERM
 *   Firewall rules forbid connection.
 *
 ****************************************************************************/

int accept(int sockfd, FAR struct sockaddr *addr, FAR socklen_t *addrlen)
{
  FAR struct socket *psock = sockfd_socket(sockfd);
  FAR struct socket *newsock;
  int newfd;
  int errcode;
  int ret;

  /* accept() is a cancellation point */

  enter_cancellation_point();

  /* Verify that the sockfd corresponds to valid, allocated socket */

  if (psock == NULL || psock->s_crefs <= 0)
    {
      /* It is not a valid socket description.  Distinguish between the cases
       * where sockfd is a just valid and when it is a valid file descriptor
       * used in the wrong context.
       */

      if ((unsigned int)sockfd < CONFIG_NFILE_DESCRIPTORS)
        {
          errcode = ENOTSOCK;
        }
      else
        {
          errcode = EBADF;
        }

      goto errout;
    }

  /* Allocate a socket descriptor for the new connection now (so that it
   * cannot fail later)
   */

  newfd = sockfd_allocate(0);
  if (newfd < 0)
    {
      errcode = ENFILE;
      goto errout;
    }

  newsock = sockfd_socket(newfd);
  if (newsock == NULL)
    {
      errcode = ENFILE;
      goto errout_with_socket;
    }

  ret = psock_accept(psock, addr, addrlen, newsock);
  if (ret < 0)
    {
      errcode = -ret;
      goto errout_with_socket;
    }

  leave_cancellation_point();
  return newfd;

errout_with_socket:
  sockfd_release(newfd);

errout:
  leave_cancellation_point();

  _SO_SETERRNO(psock, errcode);
  return ERROR;
}
