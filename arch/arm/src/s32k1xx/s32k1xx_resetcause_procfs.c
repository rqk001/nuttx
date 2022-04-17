/****************************************************************************
 * arch/arm/src/s32k1xx/s32k1xx_resetcause_procfs.c
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
#include <nuttx/fs/fs.h>
#include <nuttx/fs/procfs.h>
#include <nuttx/kmalloc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <debug.h>

#include "arm_internal.h"
#include "hardware/s32k1xx_rcm.h"
#include "s32k1xx_resetcause_procfs.h"

#ifdef CONFIG_S32K1XX_RESETCAUSE_PROCFS

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Determines the size of an intermediate buffer that must be large enough
 * to handle the longest line generated by this logic.
 */

#define S32K1XX_RESETCAUSE_LINELEN  11

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure describes one open "file" */

struct s32k1xx_resetcause_procfs_file_s
{
  struct procfs_file_s base;             /* Base open file structure */
  unsigned int linesize;                 /* Number of valid characters in line[] */
  char line[S32K1XX_RESETCAUSE_LINELEN]; /* Pre-allocated buffer for formatted lines */
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static int s32k1xx_resetcause_procfs_open(struct file *filep,
                                          const char *relpath,
                                          int oflags, mode_t mode);
static int s32k1xx_resetcause_procfs_close(struct file *filep);
static ssize_t s32k1xx_resetcause_procfs_read(struct file *filep,
                                              char *buffer,
                                              size_t buflen);
static int s32k1xx_resetcause_procfs_dup(const struct file *oldp,
                                         struct file *newp);
static int s32k1xx_resetcause_procfs_stat(const char *relpath,
                                          struct stat *buf);

/****************************************************************************
 * Private Data
 ****************************************************************************/

const struct procfs_operations s32k1xx_resetcause_procfs_ops =
{
  s32k1xx_resetcause_procfs_open,  /* open */
  s32k1xx_resetcause_procfs_close, /* close */
  s32k1xx_resetcause_procfs_read,  /* read */
  NULL,                            /* write */
  s32k1xx_resetcause_procfs_dup,   /* dup */
  NULL,                            /* opendir */
  NULL,                            /* closedir */
  NULL,                            /* readdir */
  NULL,                            /* rewinddir */
  s32k1xx_resetcause_procfs_stat,  /* stat */
};

static const struct procfs_entry_s g_s32k1xx_resetcause_procfs =
{
  "resetcause", &s32k1xx_resetcause_procfs_ops
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: s32k1xx_resetcause_procfs_open
 ****************************************************************************/

static int s32k1xx_resetcause_procfs_open(struct file *filep,
                                          const char *relpath,
                                          int oflags, mode_t mode)
{
  struct s32k1xx_resetcause_procfs_file_s *attr;

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

  /* Allocate a container to hold the file attributes */

  attr = kmm_zalloc(sizeof(struct s32k1xx_resetcause_procfs_file_s));
  if (!attr)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* Save the attributes as the open-specific state in filep->f_priv */

  filep->f_priv = (void *)attr;
  return OK;
}

/****************************************************************************
 * Name: s32k1xx_resetcause_procfs_close
 ****************************************************************************/

static int s32k1xx_resetcause_procfs_close(struct file *filep)
{
  struct s32k1xx_resetcause_procfs_file_s *attr;

  /* Recover our private data from the struct file instance */

  attr = (struct s32k1xx_resetcause_procfs_file_s *)filep->f_priv;
  DEBUGASSERT(attr);

  /* Release the file attributes structure */

  kmm_free(attr);
  filep->f_priv = NULL;
  return OK;
}

/****************************************************************************
 * Name: s32k1xx_resetcause_procfs_read
 ****************************************************************************/

static ssize_t s32k1xx_resetcause_procfs_read(struct file *filep,
                                              char *buffer,
                                              size_t buflen)
{
  struct s32k1xx_resetcause_procfs_file_s *attr;
  uint32_t resetcause;
  off_t offset;

  finfo("buffer=%p buflen=%d\n", buffer, (int)buflen);

  /* Recover our private data from the struct file instance */

  attr = (struct s32k1xx_resetcause_procfs_file_s *)filep->f_priv;
  DEBUGASSERT(attr);

  /* Retrieve the reset cause */

  resetcause = getreg32(S32K1XX_RCM_SRS);

  /* Convert the resetcause to a string and save the linesize in case we are
   * re-entered with f_pos > 0
   */

  attr->linesize = snprintf(attr->line, S32K1XX_RESETCAUSE_LINELEN,
                            "0x%08" PRIx32, resetcause);

  /* Transfer the system reset cause to user receive buffer */

  offset = filep->f_pos;

  return procfs_memcpy(attr->line, attr->linesize, buffer, buflen, &offset);
}

/****************************************************************************
 * Name: s32k1xx_resetcause_procfs_dup
 *
 * Description:
 *   Duplicate open file data in the new file structure.
 *
 ****************************************************************************/

static int s32k1xx_resetcause_procfs_dup(const struct file *oldp,
                                         struct file *newp)
{
  struct s32k1xx_resetcause_procfs_file_s *oldattr;
  struct s32k1xx_resetcause_procfs_file_s *newattr;

  finfo("Dup %p->%p\n", oldp, newp);

  /* Recover our private data from the old struct file instance */

  oldattr = (struct s32k1xx_resetcause_procfs_file_s *)oldp->f_priv;
  DEBUGASSERT(oldattr);

  /* Allocate a new container to hold the task and attribute selection */

  newattr = kmm_malloc(sizeof(struct s32k1xx_resetcause_procfs_file_s));
  if (!newattr)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* The copy the file attributes from the old attributes to the new */

  memcpy(newattr, oldattr, sizeof(struct s32k1xx_resetcause_procfs_file_s));

  /* Save the new attributes in the new file structure */

  newp->f_priv = (void *)newattr;
  return OK;
}

/****************************************************************************
 * Name: s32k1xx_resetcause_procfs_stat
 *
 * Description: Return information about a file or directory
 *
 ****************************************************************************/

static int s32k1xx_resetcause_procfs_stat(const char *relpath,
                                          struct stat *buf)
{
  /* "resetcause" is the name for a read-only file */

  memset(buf, 0, sizeof(struct stat));
  buf->st_mode = S_IFREG | S_IROTH | S_IRGRP | S_IRUSR;
  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: s32k1xx_resetcause_procfs_register
 *
 * Description:
 *   Register the S32K1XX Reset Cause procfs file system entry
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure
 *
 ****************************************************************************/

int s32k1xx_resetcause_procfs_register(void)
{
  return procfs_register(&g_s32k1xx_resetcause_procfs);
}

#endif /* CONFIG_S32K1XX_RESETCAUSE_PROCFS */
