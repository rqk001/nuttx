/****************************************************************************
 * net/udp/udp.h
 *
 *   Copyright (C) 2014-2015, 2018 Gregory Nutt. All rights reserved.
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

#ifndef __NET_UDP_UDP_H
#define __NET_UDP_UDP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <queue.h>

#include <nuttx/clock.h>
#include <nuttx/net/ip.h>

#ifdef CONFIG_NET_UDP_READAHEAD
#  include <nuttx/mm/iob.h>
#endif

#ifdef CONFIG_UDP_NOTIFIER
#  include <nuttx/wqueue.h>
#endif

#if defined(CONFIG_NET_UDP) && !defined(CONFIG_NET_UDP_NO_STACK)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define NET_UDP_HAVE_STACK 1

/* Conditions for support UDP poll/select operations */

#ifdef CONFIG_NET_UDP_READAHEAD
#  define HAVE_UDP_POLL
#endif

#ifdef CONFIG_NET_UDP_WRITE_BUFFERS
/* UDP write buffer dump macros */

#  ifdef CONFIG_DEBUG_FEATURES
#    define UDP_WBDUMP(msg,wrb,len,offset) \
       udp_wrbuffer_dump(msg,wrb,len,offset)
#  else
#    define UDP_WBDUMP(msg,wrb,len,offset)
#  endif
#endif

/* Allocate a new UDP data callback */

#define udp_callback_alloc(dev,conn) \
  devif_callback_alloc((dev), &(conn)->list)
#define udp_callback_free(dev,conn,cb) \
  devif_conn_callback_free((dev), (cb), &(conn)->list)

/* Definitions for the UDP connection struct flag field */

#define _UDP_FLAG_CONNECTMODE (1 << 0) /* Bit 0:  UDP connection-mode */

#define _UDP_ISCONNECTMODE(f) (((f) & _UDP_FLAG_CONNECTMODE) != 0)

/****************************************************************************
 * Public Type Definitions
 ****************************************************************************/

/* Representation of a UDP connection */

struct devif_callback_s;  /* Forward reference */
struct udp_hdr_s;         /* Forward reference */

struct udp_conn_s
{
  /* Common prologue of all connection structures. */

  dq_entry_t node;        /* Supports a doubly linked list */

  /* This is a list of UDP connection callbacks.  Each callback represents
   * a thread that is stalled, waiting for a device-specific event.
   */

  FAR struct devif_callback_s *list;

  /* UDP-specific content follows */

  union ip_binding_u u;   /* IP address binding */
  uint16_t lport;         /* Bound local port number (network byte order) */
  uint16_t rport;         /* Remote port number (network byte order) */
  uint8_t  flags;         /* See _UDP_FLAG_* definitions */
  uint8_t  domain;        /* IP domain: PF_INET or PF_INET6 */
  uint8_t  ttl;           /* Default time-to-live */
  uint8_t  crefs;         /* Reference counts on this instance */

#ifdef CONFIG_NET_UDP_BINDTODEVICE
  uint8_t  boundto;       /* Index of the interface we are bound to.
                           * Unbound: 0, Bound: 1-MAX_IFINDEX */
#endif

#ifdef CONFIG_NET_UDP_READAHEAD
  /* Read-ahead buffering.
   *
   *   readahead - A singly linked list of type struct iob_qentry_s
   *               where the UDP/IP read-ahead data is retained.
   */

  struct iob_queue_s readahead;   /* Read-ahead buffering */
#endif

#ifdef CONFIG_NET_UDP_WRITE_BUFFERS
  /* Write buffering
   *
   *   write_q   - The queue of unsent I/O buffers.  The head of this
   *               list may be partially sent.  FIFO ordering.
   */

  sq_queue_t write_q;             /* Write buffering for UDP packets */
  FAR struct net_driver_s *dev;   /* Last device */
#endif
};

/* This structure supports UDP write buffering.  It is simply a container
 * for a IOB list and associated destination address.
 */

#ifdef CONFIG_NET_UDP_WRITE_BUFFERS
struct udp_wrbuffer_s
{
  sq_entry_t wb_node;              /* Supports a singly linked list */
  struct sockaddr_storage wb_dest; /* Destination address */
#ifdef CONFIG_NET_SOCKOPTS
  clock_t wb_start;                /* Start time for timeout calculation */
#endif
  struct iob_s *wb_iob;            /* Head of the I/O buffer chain */
};
#endif

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifdef __cplusplus
#  define EXTERN extern "C"
extern "C"
{
#else
#  define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

struct sockaddr;      /* Forward reference */
struct socket;        /* Forward reference */
struct net_driver_s;  /* Forward reference */
struct pollfd;        /* Forward reference */

/****************************************************************************
 * Name: udp_initialize
 *
 * Description:
 *   Initialize the UDP connection structures.  Called once and only from
 *   the UIP layer.
 *
 ****************************************************************************/

void udp_initialize(void);

/****************************************************************************
 * Name: udp_alloc
 *
 * Description:
 *   Allocate a new, uninitialized UDP connection structure.  This is
 *   normally something done by the implementation of the socket() API
 *
 ****************************************************************************/

FAR struct udp_conn_s *udp_alloc(uint8_t domain);

/****************************************************************************
 * Name: udp_free
 *
 * Description:
 *   Free a UDP connection structure that is no longer in use. This should be
 *   done by the implementation of close().
 *
 ****************************************************************************/

void udp_free(FAR struct udp_conn_s *conn);

/****************************************************************************
 * Name: udp_active
 *
 * Description:
 *   Find a connection structure that is the appropriate
 *   connection to be used within the provided UDP/IP header
 *
 * Assumptions:
 *   Called from network stack logic with the network stack locked
 *
 ****************************************************************************/

FAR struct udp_conn_s *udp_active(FAR struct net_driver_s *dev,
                                  FAR struct udp_hdr_s *udp);

/****************************************************************************
 * Name: udp_nextconn
 *
 * Description:
 *   Traverse the list of allocated UDP connections
 *
 * Assumptions:
 *   Called from network stack logic with the network stack locked
 *
 ****************************************************************************/

FAR struct udp_conn_s *udp_nextconn(FAR struct udp_conn_s *conn);

/****************************************************************************
 * Name: udp_bind
 *
 * Description:
 *   This function implements the low-level parts of the standard UDP bind()
 *   operation.
 *
 * Assumptions:
 *   This function is called from normal user level code.
 *
 ****************************************************************************/

int udp_bind(FAR struct udp_conn_s *conn, FAR const struct sockaddr *addr);

/****************************************************************************
 * Name: udp_connect
 *
 * Description:
 *   This function simply assigns a remote address to UDP "connection"
 *   structure.  This function is called as part of the implementation of:
 *
 *   - connect().  If connect() is called for a SOCK_DGRAM socket, then
 *       this logic performs the moral equivalent of connect() operation
 *       for the UDP socket.
 *   - recvfrom() and sendto().  This function is called to set the
 *       remote address of the peer.
 *
 *   The function will automatically allocate an unused local port for the
 *   new connection if the socket is not yet bound to a local address.
 *   However, another port can be chosen by using the udp_bind() call,
 *   after the udp_connect() function has been called.
 *
 * Input Parameters:
 *   conn - A reference to UDP connection structure.  A value of NULL will
 *          disconnect from any previously connected address.
 *   addr - The address of the remote host.
 *
 * Assumptions:
 *   This function is called (indirectly) from user code.  Interrupts may
 *   be enabled.
 *
 ****************************************************************************/

int udp_connect(FAR struct udp_conn_s *conn, FAR const struct sockaddr *addr);

/****************************************************************************
 * Name: udp_ipv4_select
 *
 * Description:
 *   Configure to send or receive an UDP IPv4 packet
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv4
void udp_ipv4_select(FAR struct net_driver_s *dev);
#endif

/****************************************************************************
 * Name: udp_ipv6_select
 *
 * Description:
 *   Configure to send or receive an UDP IPv6 packet
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv6
void udp_ipv6_select(FAR struct net_driver_s *dev);
#endif

/****************************************************************************
 * Name: udp_poll
 *
 * Description:
 *   Poll a UDP "connection" structure for availability of TX data
 *
 * Input Parameters:
 *   dev  - The device driver structure to use in the send operation
 *   conn - The UDP "connection" to poll for TX data
 *
 * Returned Value:
 *   None
 *
 * Assumptions:
 *   Called from network stack logic with the network stack locked
 *
 ****************************************************************************/

void udp_poll(FAR struct net_driver_s *dev, FAR struct udp_conn_s *conn);

/****************************************************************************
 * Name: psock_udp_cansend
 *
 * Description:
 *   psock_udp_cansend() returns a value indicating if a write to the socket
 *   would block.  It is still possible that the write may block if another
 *   write occurs first.
 *
 * Input Parameters:
 *   psock    An instance of the internal socket structure.
 *
 * Returned Value:
 *   -ENOSYS (Function not implemented, always have to wait to send).
 *
 * Assumptions:
 *   None
 *
 ****************************************************************************/

int psock_udp_cansend(FAR struct socket *psock);

/****************************************************************************
 * Name: udp_send
 *
 * Description:
 *   Set-up to send a UDP packet
 *
 * Input Parameters:
 *   dev  - The device driver structure to use in the send operation
 *   conn - The UDP "connection" structure holding port information
 *
 * Returned Value:
 *   None
 *
 * Assumptions:
 *   Called from network stack logic with the network stack locked
 *
 ****************************************************************************/

void udp_send(FAR struct net_driver_s *dev, FAR struct udp_conn_s *conn);

/****************************************************************************
 * Name: udp_setsockopt
 *
 * Description:
 *   udp_setsockopt() sets the UDP-protocol option specified by the
 *   'option' argument to the value pointed to by the 'value' argument for
 *   the socket specified by the 'psock' argument.
 *
 *   See <netinet/udp.h> for the a complete list of values of UDP protocol
 *   options.
 *
 * Input Parameters:
 *   psock     Socket structure of socket to operate on
 *   option    identifies the option to set
 *   value     Points to the argument value
 *   value_len The length of the argument value
 *
 * Returned Value:
 *   Returns zero (OK) on success.  On failure, it returns a negated errno
 *   value to indicate the nature of the error.  See psock_setcockopt() for
 *   the list of possible error values.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_UDPPROTO_OPTIONS
int udp_setsockopt(FAR struct socket *psock, int option,
                   FAR const void *value, socklen_t value_len);
#endif

/****************************************************************************
 * Name: udp_wrbuffer_initialize
 *
 * Description:
 *   Initialize the list of free write buffers
 *
 * Assumptions:
 *   Called once early initialization.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_UDP_WRITE_BUFFERS
void udp_wrbuffer_initialize(void);
#endif /* CONFIG_NET_UDP_WRITE_BUFFERS */

/****************************************************************************
 * Name: udp_wrbuffer_alloc
 *
 * Description:
 *   Allocate a UDP write buffer by taking a pre-allocated buffer from
 *   the free list.  This function is called from UDP logic when a buffer
 *   of UDP data is about to sent
 *
 * Input Parameters:
 *   None
 *
 * Assumptions:
 *   Called from user logic with the network locked.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_UDP_WRITE_BUFFERS
struct udp_wrbuffer_s;

FAR struct udp_wrbuffer_s *udp_wrbuffer_alloc(void);
#endif /* CONFIG_NET_UDP_WRITE_BUFFERS */

/****************************************************************************
 * Name: udp_wrbuffer_tryalloc
 *
 * Description:
 *   Try to allocate a UDP write buffer by taking a pre-allocated buffer from
 *   the free list.  This function is called from UDP logic when a buffer
 *   of UDP data is about to be sent if the socket is non-blocking. Returns
 *   immediately if allocation fails.
 *
 * Input parameters:
 *   None
 *
 * Assumptions:
 *   Called from user logic with the network locked.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_UDP_WRITE_BUFFERS
FAR struct udp_wrbuffer_s *udp_wrbuffer_tryalloc(void);
#endif /* CONFIG_NET_UDP_WRITE_BUFFERS */

/****************************************************************************
 * Name: udp_wrbuffer_release
 *
 * Description:
 *   Release a UDP write buffer by returning the buffer to the free list.
 *   This function is called from user logic after it is consumed the
 *   buffered data.
 *
 * Assumptions:
 *   Called from network stack logic with the network stack locked
 *
 ****************************************************************************/

#ifdef CONFIG_NET_UDP_WRITE_BUFFERS
void udp_wrbuffer_release(FAR struct udp_wrbuffer_s *wrb);
#endif /* CONFIG_NET_UDP_WRITE_BUFFERS */

/****************************************************************************
 * Name: udp_wrbuffer_test
 *
 * Description:
 *   Check if there is room in the write buffer.  Does not reserve any space.
 *
 * Assumptions:
 *   None.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_UDP_WRITE_BUFFERS
int udp_wrbuffer_test(void);
#endif /* CONFIG_NET_UDP_WRITE_BUFFERS */

/****************************************************************************
 * Name: udp_wrbuffer_dump
 *
 * Description:
 *   Dump the contents of a write buffer.
 *
 ****************************************************************************/

#ifdef CONFIG_NET_UDP_WRITE_BUFFERS
#ifdef CONFIG_DEBUG_FEATURES
void udp_wrbuffer_dump(FAR const char *msg, FAR struct udp_wrbuffer_s *wrb,
                       unsigned int len, unsigned int offset);
#else
#  define udp_wrbuffer_dump(msg,wrb)
#endif
#endif /* CONFIG_NET_UDP_WRITE_BUFFERS */

/****************************************************************************
 * Name: udp_ipv4_input
 *
 * Description:
 *   Handle incoming UDP input in an IPv4 packet
 *
 * Input Parameters:
 *   dev - The device driver structure containing the received UDP packet
 *
 * Returned Value:
 *   OK  The packet has been processed  and can be deleted
 *   ERROR Hold the packet and try again later. There is a listening socket
 *         but no receive in place to catch the packet yet.
 *
 * Assumptions:
 *   Called from network stack logic with the network stack locked
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv4
int udp_ipv4_input(FAR struct net_driver_s *dev);
#endif

/****************************************************************************
 * Name: udp_ipv6_input
 *
 * Description:
 *   Handle incoming UDP input in an IPv6 packet
 *
 * Input Parameters:
 *   dev   - The device driver structure containing the received UDP packet
 *   iplen - The size of the IPv6 header.  This may be larger than
 *           IPv6_HDRLEN the IPv6 header if IPv6 extension headers are
 *           present.
 *
 * Returned Value:
 *   OK  The packet has been processed  and can be deleted
 *   ERROR Hold the packet and try again later. There is a listening socket
 *         but no receive in place to catch the packet yet.
 *
 * Assumptions:
 *   Called from network stack logic with the network stack locked
 *
 ****************************************************************************/

#ifdef CONFIG_NET_IPv6
int udp_ipv6_input(FAR struct net_driver_s *dev, unsigned int iplen);
#endif

/****************************************************************************
 * Name: udp_find_laddr_device
 *
 * Description:
 *   Select the network driver to use with the UDP transaction using the
 *   locally bound IP address.
 *
 * Input Parameters:
 *   conn - UDP connection structure (not currently used).
 *
 * Returned Value:
 *   A pointer to the network driver to use.  NULL is returned if driver is
 *   not bound to any local device.
 *
 ****************************************************************************/

FAR struct net_driver_s *udp_find_laddr_device(FAR struct udp_conn_s *conn);

/****************************************************************************
 * Name: udp_find_raddr_device
 *
 * Description:
 *   Select the network driver to use with the UDP transaction using the
 *   remote IP address.
 *
 * Input Parameters:
 *   conn - UDP connection structure (not currently used).
 *
 * Returned Value:
 *   A pointer to the network driver to use.
 *
 ****************************************************************************/

FAR struct net_driver_s *udp_find_raddr_device(FAR struct udp_conn_s *conn);

/****************************************************************************
 * Name: udp_callback
 *
 * Description:
 *   Inform the application holding the UDP socket of a change in state.
 *
 * Returned Value:
 *   OK if packet has been processed, otherwise ERROR.
 *
 * Assumptions:
 *   Called from network stack logic with the network stack locked
 *
 ****************************************************************************/

uint16_t udp_callback(FAR struct net_driver_s *dev,
                      FAR struct udp_conn_s *conn, uint16_t flags);

/****************************************************************************
 * Name: psock_udp_send
 *
 * Description:
 *   Implements send() for connected UDP sockets
 *
 ****************************************************************************/

ssize_t psock_udp_send(FAR struct socket *psock, FAR const void *buf,
                       size_t len);

/****************************************************************************
 * Name: psock_udp_sendto
 *
 * Description:
 *   This function implements the UDP-specific logic of the standard
 *   sendto() socket operation.
 *
 * Input Parameters:
 *   psock    A pointer to a NuttX-specific, internal socket structure
 *   buf      Data to send
 *   len      Length of data to send
 *   flags    Send flags
 *   to       Address of recipient
 *   tolen    The length of the address structure
 *
 *   NOTE: All input parameters were verified by sendto() before this
 *   function was called.
 *
 * Returned Value:
 *   On success, returns the number of characters sent.  On  error,
 *   a negated errno value is returned.  See the description in
 *   net/socket/sendto.c for the list of appropriate return value.
 *
 ****************************************************************************/

ssize_t psock_udp_sendto(FAR struct socket *psock, FAR const void *buf,
                         size_t len, int flags, FAR const struct sockaddr *to,
                         socklen_t tolen);

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

#ifdef HAVE_UDP_POLL
int udp_pollsetup(FAR struct socket *psock, FAR struct pollfd *fds);
#endif

/****************************************************************************
 * Name: udp_pollteardown
 *
 * Description:
 *   Teardown monitoring of events on an UDP/IP socket
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

#ifdef HAVE_UDP_POLL
int udp_pollteardown(FAR struct socket *psock, FAR struct pollfd *fds);
#endif

/****************************************************************************
 * Name: udp_readahead_notifier_setup
 *
 * Description:
 *   Set up to perform a callback to the worker function when an UDP data
 *   is added to the read-ahead buffer.  The worker function will execute
 *   on the low priority worker thread.
 *
 * Input Parameters:
 *   worker - The worker function to execute on the low priority work
 *            queue when data is available in the UDP read-ahead buffer.
 *   conn  - The UDP connection where read-ahead data is needed.
 *   arg    - A user-defined argument that will be available to the worker
 *            function when it runs.
 *
 * Returned Value:
 *   > 0   - The notification is in place.  The returned value is a key that
 *           may be used later in a call to udp_notifier_teardown().
 *   == 0  - There is already buffered read-ahead data.  No notification
 *           will be provided.
 *   < 0   - An unexpected error occurred and no notification will occur.
 *           The returned value is a negated errno value that indicates the
 *           nature of the failure.
 *
 ****************************************************************************/

#ifdef CONFIG_UDP_NOTIFIER
int udp_readahead_notifier_setup(worker_t worker,
                                 FAR struct udp_conn_s *conn,
                                 FAR void *arg);
#endif

/****************************************************************************
 * Name: udp_writebuffer_notifier_setup
 *
 * Description:
 *   Set up to perform a callback to the worker function when an UDP write
 *   buffer is emptied.  The worker function will execute on the high
 *   priority worker thread.
 *
 * Input Parameters:
 *   worker - The worker function to execute on the low priority work
 *            queue when data is available in the UDP read-ahead buffer.
 *   conn   - The UDP connection where read-ahead data is needed.
 *   arg    - A user-defined argument that will be available to the worker
 *            function when it runs.
 *
 * Returned Value:
 *   > 0   - The notification is in place.  The returned value is a key that
 *           may be used later in a call to udp_notifier_teardown().
 *   == 0  - There is already buffered read-ahead data.  No notification
 *           will be provided.
 *   < 0   - An unexpected error occurred and no notification will occur.
 *           The returned value is a negated errno value that indicates the
 *           nature of the failure.
 *
 ****************************************************************************/

#ifdef CONFIG_UDP_NOTIFIER
int udp_writebuffer_notifier_setup(worker_t worker,
                                   FAR struct udp_conn_s *conn,
                                   FAR void *arg);
#endif

/****************************************************************************
 * Name: udp_notifier_teardown
 *
 * Description:
 *   Eliminate a UDP read-ahead notification previously setup by
 *   udp_readahead_notifier_setup().  This function should only be called if the
 *   notification should be aborted prior to the notification.  The
 *   notification will automatically be torn down after the notification.
 *
 * Input Parameters:
 *   key - The key value returned from a previous call to
 *         udp_readahead_notifier_setup().
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.
 *
 ****************************************************************************/

#ifdef CONFIG_UDP_NOTIFIER
int udp_notifier_teardown(int key);
#endif

/****************************************************************************
 * Name: udp_readahead_signal
 *
 * Description:
 *   Read-ahead data has been buffered.  Notify all threads waiting for
 *   read-ahead data to become available.
 *
 *   When read-ahead data becomes available, *all* of the workers waiting
 *   for read-ahead data will be executed.  If there are multiple workers
 *   waiting for read-ahead data then only the first to execute will get the
 *   data.  Others will need to call udp_readahead_notifier_setup() once again.
 *
 * Input Parameters:
 *   conn  - The UDP connection where read-ahead data was just buffered.
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

#if defined(CONFIG_NET_UDP_READAHEAD) && defined(CONFIG_UDP_NOTIFIER)
void udp_readahead_signal(FAR struct udp_conn_s *conn);
#endif

/****************************************************************************
 * Name: udp_writebuffer_signal
 *
 * Description:
 *   All buffer Tx data has been sent.  Signal all threads waiting for the
 *   write buffers to become empty.
 *
 *   When write buffer becomes empty, *all* of the workers waiting
 *   for that event data will be executed.  If there are multiple workers
 *   waiting for read-ahead data then only the first to execute will get the
 *   data.  Others will need to call tcp_writebuffer_notifier_setup() once
 *   again.
 *
 * Input Parameters:
 *   conn  - The UDP connection where read-ahead data was just buffered.
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

#if defined(CONFIG_NET_UDP_WRITE_BUFFERS) && defined(CONFIG_UDP_NOTIFIER)
void udp_writebuffer_signal(FAR struct udp_conn_s *conn);
#endif

/****************************************************************************
 * Name: udp_txdrain
 *
 * Description:
 *   Wait for all write buffers to be sent (or for a timeout to occur).
 *
 * Input Parameters:
 *   psock   - An instance of the internal socket structure.
 *   abstime - The absolute time when the timeout will occur
 *
 * Returned Value:
 *   Zero (OK) is returned on success; a negated errno value is returned
 *   on any failure.
 *
 ****************************************************************************/

#if defined(CONFIG_NET_UDP_WRITE_BUFFERS) && defined(CONFIG_UDP_NOTIFIER)
struct timespec;
int udp_txdrain(FAR struct socket *psock,
                FAR const struct timespec *abstime);
#else
#  define udp_txdrain(conn, abstime) (0)
#endif

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* CONFIG_NET_UDP && !CONFIG_NET_UDP_NO_STACK */
#endif /* __NET_UDP_UDP_H */
