/****************************************************************************
 * fs/procfs/fs_procfstcbinfo.c
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/kmalloc.h>
#include <nuttx/fs/fs.h>
#include <nuttx/fs/procfs.h>

#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_PROCFS)
#ifdef CONFIG_DEBUG_TCBINFO

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Determines the size of an intermediate buffer that must be large enough
 * to handle the longest line generated by this logic.
 */

#define TCBINFO_LINELEN 128

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure describes one open "file" */

struct tcbinfo_file_s
{
  struct procfs_file_s  base;        /* Base open file structure */
  unsigned int linesize;             /* Number of valid characters in line[] */
  char line[TCBINFO_LINELEN];        /* Pre-allocated buffer for formatted lines */
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* File system methods */

static int     tcbinfo_open(FAR struct file *filep, FAR const char *relpath,
                 int oflags, mode_t mode);
static int     tcbinfo_close(FAR struct file *filep);
static ssize_t tcbinfo_read(FAR struct file *filep, FAR char *buffer,
                 size_t buflen);

static int     tcbinfo_dup(FAR const struct file *oldp,
                 FAR struct file *newp);

static int     tcbinfo_stat(FAR const char *relpath, FAR struct stat *buf);

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* See fs_mount.c -- this structure is explicitly externed there.
 * We use the old-fashioned kind of initializers so that this will compile
 * with any compiler.
 */

const struct procfs_operations tcbinfo_operations =
{
  tcbinfo_open,       /* open */
  tcbinfo_close,      /* close */
  tcbinfo_read,       /* read */
  NULL,               /* write */

  tcbinfo_dup,        /* dup */

  NULL,               /* opendir */
  NULL,               /* closedir */
  NULL,               /* readdir */
  NULL,               /* rewinddir */

  tcbinfo_stat        /* stat */
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: tcbinfo_open
 ****************************************************************************/

static int tcbinfo_open(FAR struct file *filep, FAR const char *relpath,
                      int oflags, mode_t mode)
{
  FAR struct tcbinfo_file_s *attr;

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

  /* "tcbinfo" is the only acceptable value for the relpath */

  if (strcmp(relpath, "tcbinfo") != 0)
    {
      ferr("ERROR: relpath is '%s'\n", relpath);
      return -ENOENT;
    }

  /* Allocate a container to hold the file attributes */

  attr = (FAR struct tcbinfo_file_s *)
    kmm_zalloc(sizeof(struct tcbinfo_file_s));

  if (attr == NULL)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* Save the attributes as the open-specific state in filep->f_priv */

  filep->f_priv = (FAR void *)attr;
  return OK;
}

/****************************************************************************
 * Name: tcbinfo_close
 ****************************************************************************/

static int tcbinfo_close(FAR struct file *filep)
{
  FAR struct tcbinfo_file_s *attr;

  /* Recover our private data from the struct file instance */

  attr = (FAR struct tcbinfo_file_s *)filep->f_priv;
  DEBUGASSERT(attr);

  /* Release the file attributes structure */

  kmm_free(attr);
  filep->f_priv = NULL;
  return OK;
}

/****************************************************************************
 * Name: tcbinfo_read
 ****************************************************************************/

static ssize_t tcbinfo_read(FAR struct file *filep, FAR char *buffer,
                            size_t buflen)
{
  FAR struct tcbinfo_file_s *attr;
  size_t linesize;
  off_t offset;
  ssize_t ret;

  finfo("buffer=%p buflen=%d\n", buffer, (int)buflen);

  /* Recover our private data from the struct file instance */

  attr = (FAR struct tcbinfo_file_s *)filep->f_priv;
  DEBUGASSERT(attr);

  if (filep->f_pos == 0)
    {
      linesize = procfs_snprintf(attr->line, TCBINFO_LINELEN,
                                 "pointer %p size %d\n", g_tcbinfo,
                                  sizeof(struct tcbinfo_s));

      /* Save the linesize in case we are re-entered with f_pos > 0 */

      attr->linesize = linesize;
    }

  offset = filep->f_pos;
  ret = procfs_memcpy(attr->line, attr->linesize, buffer, buflen, &offset);

  /* Update the file offset */

  if (ret > 0)
    {
      filep->f_pos += ret;
    }

  return ret;
}

/****************************************************************************
 * Name: tcbinfo_dup
 *
 * Description:
 *   Duplicate open file data in the new file structure.
 *
 ****************************************************************************/

static int tcbinfo_dup(FAR const struct file *oldp, FAR struct file *newp)
{
  FAR struct tcbinfo_file_s *oldattr;
  FAR struct tcbinfo_file_s *newattr;

  finfo("Dup %p->%p\n", oldp, newp);

  /* Recover our private data from the old struct file instance */

  oldattr = (FAR struct tcbinfo_file_s *)oldp->f_priv;
  DEBUGASSERT(oldattr);

  /* Allocate a new container to hold the task and attribute selection */

  newattr = (FAR struct tcbinfo_file_s *)
    kmm_malloc(sizeof(struct tcbinfo_file_s));

  if (!newattr)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* The copy the file attributes from the old attributes to the new */

  memcpy(newattr, oldattr, sizeof(struct tcbinfo_file_s));

  /* Save the new attributes in the new file structure */

  newp->f_priv = (FAR void *)newattr;
  return OK;
}

/****************************************************************************
 * Name: tcbinfo_stat
 *
 * Description: Return information about a file or directory
 *
 ****************************************************************************/

static int tcbinfo_stat(FAR const char *relpath, FAR struct stat *buf)
{
  /* "tcbinfo" is the only acceptable value for the relpath */

  if (strcmp(relpath, "tcbinfo") != 0)
    {
      ferr("ERROR: relpath is '%s'\n", relpath);
      return -ENOENT;
    }

  /* "tcbinfo" is the name for a read-only file */

  memset(buf, 0, sizeof(struct stat));
  buf->st_mode = S_IFREG | S_IROTH | S_IRGRP | S_IRUSR;
  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

#endif /* CONFIG_DEBUG_TCBINFO */
#endif /* !CONFIG_DISABLE_MOUNTPOINT && CONFIG_FS_PROCFS */
