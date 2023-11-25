/****************************************************************************
 * sched/module/mod_procfs.c
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

#include <sys/stat.h>

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/kmalloc.h>
#include <nuttx/module.h>
#include <nuttx/lib/modlib.h>
#include <nuttx/fs/fs.h>
#include <nuttx/fs/procfs.h>

#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_PROCFS) && \
    !defined(CONFIG_FS_PROCFS_EXCLUDE_MODULE)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Determines the size of an intermediate buffer that must be large enough
 * to handle the longest line generated by this logic.
 */

#define MOD_LINELEN 64

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure describes one open "file" */

struct modprocfs_file_s
{
  struct procfs_file_s base;         /* Base open file structure */

  /* Read helpers */

  FAR char *buffer;                  /* User buffer pointer */
  size_t buflen;                     /* Size of the user buffer */
  size_t remaining;                  /* Space remaining in user buffer */
  size_t totalsize;                  /* Total size returned by read() */
  off_t offset;                      /* Offset skip on output */
  char line[MOD_LINELEN];            /* Buffer for line formatting */
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* File system methods */

static int     modprocfs_open(FAR struct file *filep,
                              FAR const char *relpath,
                              int oflags, mode_t mode);
static int     modprocfs_close(FAR struct file *filep);
static ssize_t modprocfs_read(FAR struct file *filep,
                              FAR char *buffer,
                              size_t buflen);
static int     modprocfs_dup(FAR const struct file *oldp,
                             FAR struct file *newp);
static int     modprocfs_stat(FAR const char *relpath, FAR struct stat *buf);

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* See include/nutts/fs/procfs.h
 * We use the old-fashioned kind of initializers so that this will compile
 * with any compiler.
 */

const struct procfs_operations g_module_operations =
{
  modprocfs_open,       /* open */
  modprocfs_close,      /* close */
  modprocfs_read,       /* read */
  NULL,                 /* write */
  NULL,                 /* poll */
  modprocfs_dup,        /* dup */

  NULL,                 /* opendir */
  NULL,                 /* closedir */
  NULL,                 /* readdir */
  NULL,                 /* rewinddir */

  modprocfs_stat        /* stat */
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: modprocfs_callback
 ****************************************************************************/

static int modprocfs_callback(FAR struct module_s *modp, FAR void *arg)
{
  FAR struct modprocfs_file_s *priv;
  size_t linesize;
  size_t copysize;

  DEBUGASSERT(modp != NULL && arg != NULL);
  priv = (FAR struct modprocfs_file_s *)arg;

  linesize = snprintf(priv->line, MOD_LINELEN,
                      "%s,%p,%p,%p,%u,%p,%lu,%p,%lu\n",
                      modp->modname, modp->initializer,
                      modp->modinfo.uninitializer, modp->modinfo.arg,
                      modp->modinfo.nexports,
                      modp->textalloc,
                      (unsigned long)modp->textsize,
                      (FAR uint8_t *)modp->dataalloc,
                      (unsigned long)modp->datasize);
  copysize = procfs_memcpy(priv->line, linesize, priv->buffer,
                           priv->remaining, &priv->offset);
  priv->totalsize += copysize;
  priv->buffer    += copysize;
  priv->remaining -= copysize;

  return priv->totalsize >= priv->buflen;
}

/****************************************************************************
 * Name: modprocfs_open
 ****************************************************************************/

static int modprocfs_open(FAR struct file *filep, FAR const char *relpath,
                          int oflags, mode_t mode)
{
  FAR struct modprocfs_file_s *priv;

  finfo("Open '%s'\n", relpath);

  /* PROCFS is read-only.  Any attempt to open with any kind of write
   * access is not permitted.
   *
   * REVISIT:  Write-able proc files could be quite useful.
   */

  if (((oflags & O_WRONLY) != 0 || (oflags & O_RDONLY) == 0))
    {
      ferr("ERROR: Only O_RDONLY supported\n");
      return -EACCES;
    }

  /* Allocate the open file structure */

  priv = (FAR struct modprocfs_file_s *)
         kmm_zalloc(sizeof(struct modprocfs_file_s));
  if (!priv)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* Save the open file structure as the open-specific state in
   * filep->f_priv.
   */

  filep->f_priv = priv;
  return OK;
}

/****************************************************************************
 * Name: modprocfs_close
 ****************************************************************************/

static int modprocfs_close(FAR struct file *filep)
{
  FAR struct modprocfs_file_s *priv;

  /* Recover our private data from the struct file instance */

  priv = (FAR struct modprocfs_file_s *)filep->f_priv;
  DEBUGASSERT(priv);

  /* Release the file attributes structure */

  kmm_free(priv);
  filep->f_priv = NULL;
  return OK;
}

/****************************************************************************
 * Name: modprocfs_read
 ****************************************************************************/

static ssize_t modprocfs_read(FAR struct file *filep, FAR char *buffer,
                              size_t buflen)
{
  FAR struct modprocfs_file_s *priv;
  int ret;

  finfo("buffer=%p buflen=%zu\n", buffer, buflen);

  /* Recover our private data from the struct file instance */

  priv = (FAR struct modprocfs_file_s *)filep->f_priv;
  DEBUGASSERT(priv);

  /* Traverse all installed modules */

  priv->remaining = buflen;
  priv->totalsize = 0;
  priv->buffer    = buffer;
  priv->buflen    = buflen;
  priv->offset    = filep->f_pos;

  ret = modlib_registry_foreach(modprocfs_callback, priv);
  if (ret >= 0)
    {
      filep->f_pos += priv->totalsize;
      return priv->totalsize;
    }

  return ret;
}

/****************************************************************************
 * Name: modprocfs_dup
 *
 * Description:
 *   Duplicate open file data in the new file structure.
 *
 ****************************************************************************/

static int modprocfs_dup(FAR const struct file *oldp, FAR struct file *newp)
{
  FAR struct modprocfs_file_s *oldpriv;
  FAR struct modprocfs_file_s *newpriv;

  finfo("Dup %p->%p\n", oldp, newp);

  /* Recover our private data from the old struct file instance */

  oldpriv = (FAR struct modprocfs_file_s *)oldp->f_priv;
  DEBUGASSERT(oldpriv);

  /* Allocate a new container to hold the task and attribute selection */

  newpriv = (FAR struct modprocfs_file_s *)
    kmm_zalloc(sizeof(struct modprocfs_file_s));
  if (!newpriv)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* The copy the file attributes from the old attributes to the new */

  memcpy(newpriv, oldpriv, sizeof(struct modprocfs_file_s));

  /* Save the new attributes in the new file structure */

  newp->f_priv = newpriv;
  return OK;
}

/****************************************************************************
 * Name: modprocfs_stat
 *
 * Description: Return information about a file or directory
 *
 ****************************************************************************/

static int modprocfs_stat(FAR const char *relpath, FAR struct stat *buf)
{
  memset(buf, 0, sizeof(struct stat));
  buf->st_mode = S_IFREG | S_IROTH | S_IRGRP | S_IRUSR;
  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

#endif /* !CONFIG_DISABLE_MOUNTPOINT && CONFIG_FS_PROCFS &&
        * !CONFIG_FS_PROCFS_EXCLUDE_MODULE */
