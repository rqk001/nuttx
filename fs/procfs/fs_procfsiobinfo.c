/****************************************************************************
 * fs/procfs/fs_procfsiobinfo.c
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
#include <sys/stat.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/kmalloc.h>
#include <nuttx/mm/iob.h>
#include <nuttx/fs/fs.h>
#include <nuttx/fs/procfs.h>

#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_PROCFS) && \
    defined(CONFIG_MM_IOB) && !defined(CONFIG_FS_PROCFS_EXCLUDE_IOBINFO)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Determines the size of an intermediate buffer that must be large enough
 * to handle the longest line generated by this logic.
 */

#define IOBINFO_LINELEN 80

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure describes one open "file" */

struct iobinfo_file_s
{
  struct procfs_file_s base;      /* Base open file structure */
  unsigned int linesize;          /* Number of valid characters in line[] */
  char line[IOBINFO_LINELEN];     /* Pre-allocated buffer for formatted lines */
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* File system methods */

static int     iobinfo_open(FAR struct file *filep, FAR const char *relpath,
                 int oflags, mode_t mode);
static int     iobinfo_close(FAR struct file *filep);
static ssize_t iobinfo_read(FAR struct file *filep, FAR char *buffer,
                 size_t buflen);
static int     iobinfo_dup(FAR const struct file *oldp,
                 FAR struct file *newp);
static int     iobinfo_stat(FAR const char *relpath, FAR struct stat *buf);

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* CAUTION: The order of these entries and the preprocessor logic must match
 * logic found in the enum iob_user_e declaration found in iob.h
 */

static FAR const char *g_iob_user_names[] =
{
#ifdef CONFIG_SYSLOG_BUFFER
  "syslog",
#endif
#ifdef CONFIG_IOB_UNITTEST
  "unittest",
#endif
#ifdef CONFIG_NET_6LOWPAN
  "sixlowpan",
#endif
#ifdef CONFIG_NET_ICMP_SOCKET
  "icmp_sock",
#endif
#ifdef CONFIG_NET_ICMPv6_SOCKET
  "icmpv6_sock",
#endif
#ifdef CONFIG_NET_UDP
  "udp_sock",
#endif
#ifdef CONFIG_NET_TCP
  "tcp_sock",
#endif
#ifdef CONFIG_NET_IEEE802154
  "ieee802154_sock",
#endif
#ifdef CONFIG_NET_BLUETOOTH
  "bluetooth_sock",
#endif
#if defined(CONFIG_NET_UDP) && !defined(NET_UDP_NO_STACK)
  "udp_readahead",
#endif
#ifdef CONFIG_NET_UDP_WRITE_BUFFERS
  "udp_writebuffer",
#endif
#if defined(CONFIG_NET_TCP) && !defined(NET_TCP_NO_STACK)
  "tcp_readahead",
#endif
#ifdef CONFIG_NET_TCP_WRITE_BUFFERS
  "tcp_writebuffer",
#endif
#ifdef CONFIG_NET_IPFORWARD
  "ipforward",
#endif
#ifdef CONFIG_WIRELESS_IEEE802154
  "rad802154",
#endif
#ifdef CONFIG_IEEE802154_MAC
  "mac802154",
#endif
#ifdef CONFIG_IEEE802154_MACDEV
  "mac802154_macdev",
#endif
#ifdef CONFIG_IEEE802154_NETDEV
  "mac802154_netdev",
#endif
 #ifdef CONFIG_WL_SPIRIT
  "packetradio",
#endif
#ifdef CONFIG_WIRELESS_BLUETOOTH
  "bluetooth",
#endif
#ifdef CONFIG_NET_CAN
  "can",
#endif
  "global",
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* See fs_mount.c -- this structure is explicitly externed there.
 * We use the old-fashioned kind of initializers so that this will compile
 * with any compiler.
 */

const struct procfs_operations iobinfo_operations =
{
  iobinfo_open,   /* open */
  iobinfo_close,  /* close */
  iobinfo_read,   /* read */
  NULL,           /* write */
  iobinfo_dup,    /* dup */
  NULL,           /* opendir */
  NULL,           /* closedir */
  NULL,           /* readdir */
  NULL,           /* rewinddir */
  iobinfo_stat    /* stat */
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: iobinfo_open
 ****************************************************************************/

static int iobinfo_open(FAR struct file *filep, FAR const char *relpath,
                      int oflags, mode_t mode)
{
  FAR struct iobinfo_file_s *procfile;

  finfo("Open '%s'\n", relpath);

  /* PROCFS is read-only.  Any attempt to open with any kind of write
   * access is not permitted.
   *
   * REVISIT:  Write-able proc files could be quite useful.
   */

  if ((oflags & O_WRONLY) != 0 || (oflags & O_RDONLY) == 0)
    {
      ferr("ERROR: Only O_RDONLY supported\n");
      return -EACCES;
    }

  /* "iobinfo" is the only acceptable value for the relpath */

  if (strcmp(relpath, "iobinfo") != 0)
    {
      ferr("ERROR: relpath is '%s'\n", relpath);
      return -ENOENT;
    }

  /* Allocate a container to hold the file attributes */

  procfile = (FAR struct iobinfo_file_s *)
    kmm_zalloc(sizeof(struct iobinfo_file_s));
  if (!procfile)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* Save the attributes as the open-specific state in filep->f_priv */

  filep->f_priv = (FAR void *)procfile;
  return OK;
}

/****************************************************************************
 * Name: iobinfo_close
 ****************************************************************************/

static int iobinfo_close(FAR struct file *filep)
{
  FAR struct iobinfo_file_s *procfile;

  /* Recover our private data from the struct file instance */

  procfile = (FAR struct iobinfo_file_s *)filep->f_priv;
  DEBUGASSERT(procfile);

  /* Release the file attributes structure */

  kmm_free(procfile);
  filep->f_priv = NULL;
  return OK;
}

/****************************************************************************
 * Name: iobinfo_read
 ****************************************************************************/

static ssize_t iobinfo_read(FAR struct file *filep, FAR char *buffer,
                            size_t buflen)
{
  FAR struct iobinfo_file_s *iobfile;
  FAR struct iob_userstats_s *userstats;
  size_t linesize;
  size_t copysize;
  size_t totalsize;
  off_t offset;
  int i;

  finfo("buffer=%p buflen=%d\n", buffer, (int)buflen);

  DEBUGASSERT(filep != NULL && buffer != NULL && buflen > 0);
  offset = filep->f_pos;

  /* Recover our private data from the struct file instance */

  iobfile = (FAR struct iobinfo_file_s *)filep->f_priv;
  DEBUGASSERT(iobfile);

  /* The first line is the headers */

  linesize  = snprintf(iobfile->line, IOBINFO_LINELEN,
                       "                           TOTAL           TOTAL\n");

  copysize  = procfs_memcpy(iobfile->line, linesize, buffer, buflen,
                            &offset);
  totalsize = copysize;

  if (totalsize < buflen)
    {
      buffer    += copysize;
      buflen    -= copysize;

      linesize  = snprintf(iobfile->line, IOBINFO_LINELEN,
                           "        USER            CONSUMED        "
                           "PRODUCED\n");

      copysize  = procfs_memcpy(iobfile->line, linesize, buffer, buflen,
                                &offset);
      totalsize += copysize;
    }

  /* Loop through each IOB user printing the usage statistics */

  for (i = 0; i < IOBUSER_GLOBAL; i++)
    {
      if (totalsize < buflen)
        {
          buffer    += copysize;
          buflen    -= copysize;

          userstats  = iob_getuserstats(i);
          linesize   = snprintf(iobfile->line, IOBINFO_LINELEN,
                                "%-16s%16lu%16lu\n",
                                g_iob_user_names[i],
                                (unsigned long)userstats->totalconsumed,
                                (unsigned long)userstats->totalproduced);

          copysize   = procfs_memcpy(iobfile->line, linesize, buffer, buflen,
                                     &offset);
          totalsize += copysize;
        }
    }

  if (totalsize < buflen)
    {
      buffer    += copysize;
      buflen    -= copysize;

      userstats  = iob_getuserstats(IOBUSER_GLOBAL);
      linesize   = snprintf(iobfile->line, IOBINFO_LINELEN,
                            "\n%-16s%16lu%16lu\n",
                            g_iob_user_names[IOBUSER_GLOBAL],
                            (unsigned long)userstats->totalconsumed,
                            (unsigned long)userstats->totalproduced);

      copysize   = procfs_memcpy(iobfile->line, linesize, buffer, buflen,
                                 &offset);
      totalsize += copysize;
    }

  /* Update the file offset */

  filep->f_pos += totalsize;
  return totalsize;
}

/****************************************************************************
 * Name: iobinfo_dup
 *
 * Description:
 *   Duplicate open file data in the new file structure.
 *
 ****************************************************************************/

static int iobinfo_dup(FAR const struct file *oldp, FAR struct file *newp)
{
  FAR struct iobinfo_file_s *oldattr;
  FAR struct iobinfo_file_s *newattr;

  finfo("Dup %p->%p\n", oldp, newp);

  /* Recover our private data from the old struct file instance */

  oldattr = (FAR struct iobinfo_file_s *)oldp->f_priv;
  DEBUGASSERT(oldattr);

  /* Allocate a new container to hold the task and attribute selection */

  newattr = (FAR struct iobinfo_file_s *)
    kmm_malloc(sizeof(struct iobinfo_file_s));
  if (!newattr)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* The copy the file attributes from the old attributes to the new */

  memcpy(newattr, oldattr, sizeof(struct iobinfo_file_s));

  /* Save the new attributes in the new file structure */

  newp->f_priv = (FAR void *)newattr;
  return OK;
}

/****************************************************************************
 * Name: iobinfo_stat
 *
 * Description: Return information about a file or directory
 *
 ****************************************************************************/

static int iobinfo_stat(FAR const char *relpath, FAR struct stat *buf)
{
  /* "iobinfo" is the only acceptable value for the relpath */

  if (strcmp(relpath, "iobinfo") != 0)
    {
      ferr("ERROR: relpath is '%s'\n", relpath);
      return -ENOENT;
    }

  /* "iobinfo" is the name for a read-only file */

  memset(buf, 0, sizeof(struct stat));
  buf->st_mode = S_IFREG | S_IROTH | S_IRGRP | S_IRUSR;
  return OK;
}

#endif /* !CONFIG_DISABLE_MOUNTPOINT && CONFIG_FS_PROCFS &&
        * CONFIG_MM_IOB && !CONFIG_FS_PROCFS_EXCLUDE_IOBINFO */
