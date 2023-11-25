/****************************************************************************
 * mm/mempool/mempool_procfs.c
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

#include <nuttx/kmalloc.h>
#include <nuttx/mm/mempool.h>
#include <nuttx/nuttx.h>
#include <nuttx/fs/procfs.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Determines the size of an intermediate buffer that must be large enough
 * to handle the longest line generated by this logic.
 */

#define MEMPOOLINFO_LINELEN 80

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure describes one open "file" */

struct mempool_file_s
{
  struct procfs_file_s base;      /* Base open file structure */
  unsigned int linesize;          /* Number of valid characters in line[] */
  char line[MEMPOOLINFO_LINELEN]; /* Pre-allocated buffer for formatted lines */
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static int     mempool_open(FAR struct file *filep, FAR const char *relpath,
                            int oflags, mode_t mode);
static int     mempool_close(FAR struct file *filep);
static int     mempool_dup(FAR const struct file *oldp,
                           FAR struct file *newp);
static int     mempool_stat(FAR const char *relpath, FAR struct stat *buf);
static ssize_t mempool_read(FAR struct file *filep, FAR char *buffer,
                            size_t buflen);

/****************************************************************************
 * Public Data
 ****************************************************************************/

const struct procfs_operations g_mempool_operations =
{
  mempool_open,   /* open */
  mempool_close,  /* close */
  mempool_read,   /* read */
  NULL,           /* write */
  NULL,           /* poll */
  mempool_dup,    /* dup */
  NULL,           /* opendir */
  NULL,           /* closedir */
  NULL,           /* readdir */
  NULL,           /* rewinddir */
  mempool_stat    /* stat */
};

static FAR struct mempool_procfs_entry_s *g_mempool_procfs = NULL;

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mempool_open
 ****************************************************************************/

static int mempool_open(FAR struct file *filep, FAR const char *relpath,
                        int oflags, mode_t mode)
{
  FAR struct mempool_file_s *procfile;

  procfile = kmm_zalloc(sizeof(struct mempool_file_s));
  if (procfile == NULL)
    {
      return -ENOMEM;
    }

  filep->f_priv = procfile;
  return 0;
}

/****************************************************************************
 * Name: mempool_close
 ****************************************************************************/

static int mempool_close(FAR struct file *filep)
{
  kmm_free(filep->f_priv);
  filep->f_priv = NULL;
  return 0;
}

/****************************************************************************
 * Name: mempool_read
 ****************************************************************************/

static ssize_t mempool_read(FAR struct file *filep, FAR char *buffer,
                            size_t buflen)
{
  FAR const struct mempool_procfs_entry_s *entry;
  FAR struct mempool_file_s *procfile;
  size_t linesize;
  size_t copysize;
  size_t totalsize;
  off_t offset;

  offset    = filep->f_pos;
  procfile  = filep->f_priv;
  linesize  = procfs_snprintf(procfile->line, MEMPOOLINFO_LINELEN,
                              "%13s%11s%9s%9s%9s%9s%9s\n", "", "total",
                              "bsize", "nused", "nfree", "nifree",
                              "nwaiter");

  copysize  = procfs_memcpy(procfile->line, linesize, buffer, buflen,
                            &offset);
  totalsize = copysize;

  for (entry = g_mempool_procfs; entry != NULL; entry = entry->next)
    {
      if (totalsize < buflen)
        {
          FAR struct mempool_s *pool = container_of(entry, struct mempool_s,
                                                    procfs);
          struct mempoolinfo_s minfo;

          buffer    += copysize;
          buflen    -= copysize;

          mempool_info(pool, &minfo);
          linesize   = procfs_snprintf(procfile->line, MEMPOOLINFO_LINELEN,
                                       "%12s:%11lu%9lu%9lu%9lu%9lu%9lu\n",
                                       entry->name, minfo.arena,
                                       minfo.sizeblks, minfo.aordblks,
                                       minfo.ordblks, minfo.iordblks,
                                       minfo.nwaiter);
          copysize   = procfs_memcpy(procfile->line, linesize, buffer,
                                     buflen, &offset);
          totalsize += copysize;
        }
    }

  filep->f_pos += totalsize;
  return totalsize;
}

/****************************************************************************
 * Name: mempool_dup
 *
 * Description:
 *   Duplicate open file data in the new file structure.
 *
 ****************************************************************************/

static int mempool_dup(FAR const struct file *oldp, FAR struct file *newp)
{
  FAR struct mempool_file_s *oldattr;
  FAR struct mempool_file_s *newattr;

  oldattr = oldp->f_priv;
  newattr = kmm_malloc(sizeof(struct mempool_file_s));
  if (newattr == NULL)
    {
      return -ENOMEM;
    }

  memcpy(newattr, oldattr, sizeof(struct mempool_file_s));
  newp->f_priv = newattr;
  return 0;
}

/****************************************************************************
 * Name: mempool_stat
 *
 * Description: Return information about a file or directory
 *
 ****************************************************************************/

static int mempool_stat(FAR const char *relpath, FAR struct stat *buf)
{
  memset(buf, 0, sizeof(struct stat));
  buf->st_mode = S_IFREG | S_IROTH | S_IRGRP | S_IRUSR;
  return 0;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mempool_procfs_register
 *
 * Description:
 *   Add a new mempool entry to the procfs file system.
 *
 * Input Parameters:
 *   entry - Describes the entry to be registered.
 *
 ****************************************************************************/

void mempool_procfs_register(FAR struct mempool_procfs_entry_s *entry,
                             FAR const char *name)
{
  entry->name = name;
  entry->next = g_mempool_procfs;
  g_mempool_procfs = entry;
}

/****************************************************************************
 * Name: mempool_procfs_unregister
 *
 * Description:
 *   Remove a mempool entry from the procfs file system.
 *
 * Input Parameters:
 *   entry - Describes the entry to be unregistered.
 *
 ****************************************************************************/

void mempool_procfs_unregister(FAR struct mempool_procfs_entry_s *entry)
{
  FAR struct mempool_procfs_entry_s **cur;

  for (cur = &g_mempool_procfs; *cur != NULL; cur = &(*cur)->next)
    {
      if (*cur == entry)
        {
          *cur = entry->next;
          break;
        }
    }
}
