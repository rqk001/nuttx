/****************************************************************************
 * fs/procfs/fs_procfsmeminfo.c
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
#include <nuttx/pgalloc.h>
#include <nuttx/progmem.h>
#include <nuttx/mm/mm.h>
#include <nuttx/fs/fs.h>
#include <nuttx/fs/procfs.h>

#ifndef CONFIG_FS_PROCFS_EXCLUDE_MEMINFO

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Determines the size of an intermediate buffer that must be large enough
 * to handle the longest line generated by this logic.
 */

#define MEMINFO_LINELEN 62

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure describes one open "file" */

struct meminfo_file_s
{
  struct procfs_file_s base;      /* Base open file structure */
  unsigned int linesize;          /* Number of valid characters in line[] */
  char line[MEMINFO_LINELEN];     /* Pre-allocated buffer for formatted lines */
};

#if defined(CONFIG_ARCH_HAVE_PROGMEM) && defined(CONFIG_FS_PROCFS_INCLUDE_PROGMEM)
struct progmem_info_s
{
  int arena;                      /* Total size of available progmem. */
  int ordblks;                    /* This is the number of free chunks */
  int mxordblk;                   /* Size of the largest free chunk */
  int uordblks;                   /* Total size of memory for allocated chunks */
  int fordblks;                   /* Total size of memory for free chunks. */
};
#endif

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

#if defined(CONFIG_ARCH_HAVE_PROGMEM) && defined(CONFIG_FS_PROCFS_INCLUDE_PROGMEM)
static void    meminfo_progmem(FAR struct progmem_info_s *progmem);
#endif

/* File system methods */

static int     meminfo_open(FAR struct file *filep, FAR const char *relpath,
                 int oflags, mode_t mode);
static int     meminfo_close(FAR struct file *filep);
static ssize_t meminfo_read(FAR struct file *filep, FAR char *buffer,
                 size_t buflen);
static int     meminfo_dup(FAR const struct file *oldp,
                 FAR struct file *newp);
static int     meminfo_stat(FAR const char *relpath, FAR struct stat *buf);

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* See fs_mount.c -- this structure is explicitly externed there.
 * We use the old-fashioned kind of initializers so that this will compile
 * with any compiler.
 */

const struct procfs_operations meminfo_operations =
{
  meminfo_open,   /* open */
  meminfo_close,  /* close */
  meminfo_read,   /* read */
  NULL,           /* write */
  meminfo_dup,    /* dup */
  NULL,           /* opendir */
  NULL,           /* closedir */
  NULL,           /* readdir */
  NULL,           /* rewinddir */
  meminfo_stat    /* stat */
};

FAR struct procfs_meminfo_entry_s *g_procfs_meminfo = NULL;

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: meminfo_progmem
 *
 * Description:
 *   The moral equivalent of mallinfo() for prog mem
 *
 *   TODO Max block size only works on uniform prog mem
 *
 ****************************************************************************/

#if defined(CONFIG_ARCH_HAVE_PROGMEM) && defined(CONFIG_FS_PROCFS_INCLUDE_PROGMEM)
static void meminfo_progmem(FAR struct progmem_info_s *progmem)
{
  size_t page = 0;
  size_t stpage = 0xffff;
  size_t pagesize = 0;
  ssize_t status;

  progmem->arena    = 0;
  progmem->fordblks = 0;
  progmem->uordblks = 0;
  progmem->mxordblk = 0;

  for (status = 0, page = 0; status >= 0; page++)
    {
      status   = up_progmem_ispageerased(page);
      pagesize = up_progmem_pagesize(page);

      progmem->arena += pagesize;

      /* Is this beginning of new free space section */

      if (status == 0)
        {
          if (stpage == 0xffff)
            {
              stpage = page;
            }

          progmem->fordblks += pagesize;
        }
      else if (status != 0)
        {
          progmem->uordblks += pagesize;

          if (stpage != 0xffff && up_progmem_isuniform())
            {
              stpage = page - stpage;
              if (stpage > progmem->mxordblk)
                {
                  progmem->mxordblk = stpage;
                }

              stpage = 0xffff;
            }
        }
    }

  progmem->mxordblk *= pagesize;
}
#endif

/****************************************************************************
 * Name: meminfo_open
 ****************************************************************************/

static int meminfo_open(FAR struct file *filep, FAR const char *relpath,
                      int oflags, mode_t mode)
{
  FAR struct meminfo_file_s *procfile;

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

  /* "meminfo" is the only acceptable value for the relpath */

  if (strcmp(relpath, "meminfo") != 0)
    {
      ferr("ERROR: relpath is '%s'\n", relpath);
      return -ENOENT;
    }

  /* Allocate a container to hold the file attributes */

  procfile = (FAR struct meminfo_file_s *)
    kmm_zalloc(sizeof(struct meminfo_file_s));
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
 * Name: meminfo_close
 ****************************************************************************/

static int meminfo_close(FAR struct file *filep)
{
  FAR struct meminfo_file_s *procfile;

  /* Recover our private data from the struct file instance */

  procfile = (FAR struct meminfo_file_s *)filep->f_priv;
  DEBUGASSERT(procfile);

  /* Release the file attributes structure */

  kmm_free(procfile);
  filep->f_priv = NULL;
  return OK;
}

/****************************************************************************
 * Name: meminfo_read
 ****************************************************************************/

static ssize_t meminfo_read(FAR struct file *filep, FAR char *buffer,
                            size_t buflen)
{
  FAR struct meminfo_file_s *procfile;
  size_t linesize;
  size_t copysize;
  size_t totalsize;
  off_t offset;

  finfo("buffer=%p buflen=%d\n", buffer, (int)buflen);

  DEBUGASSERT(filep != NULL && buffer != NULL && buflen > 0);
  offset = filep->f_pos;

  /* Recover our private data from the struct file instance */

  procfile = (FAR struct meminfo_file_s *)filep->f_priv;
  DEBUGASSERT(procfile);

  /* The first line is the headers */

  linesize  =
    snprintf(procfile->line, MEMINFO_LINELEN,
             "                     "
             "total       used       free    largest\n");

  copysize  = procfs_memcpy(procfile->line, linesize, buffer, buflen,
                            &offset);
  totalsize = copysize;

  /* Followed by information about the memory resources */

  FAR const struct procfs_meminfo_entry_s *entry;

  for (entry = g_procfs_meminfo; entry != NULL; entry = entry->next)
    {
      if (totalsize < buflen)
        {
          struct mallinfo minfo;

          buffer    += copysize;
          buflen    -= copysize;

          /* Show heap information */

          entry->mallinfo(entry->user_data, &minfo);
          linesize   = snprintf(procfile->line, MEMINFO_LINELEN,
                                "%12s:  %11lu%11lu%11lu%11lu\n",
                                entry->name,
                                (unsigned long)minfo.arena,
                                (unsigned long)minfo.uordblks,
                                (unsigned long)minfo.fordblks,
                                (unsigned long)minfo.mxordblk);
          copysize   = procfs_memcpy(procfile->line, linesize, buffer,
                                     buflen, &offset);
          totalsize += copysize;
        }
    }

#ifdef CONFIG_MM_PGALLOC
  if (totalsize < buflen)
    {
      struct pginfo_s pginfo;
      unsigned long total;
      unsigned long available;
      unsigned long allocated;
      unsigned long max;

      buffer    += copysize;
      buflen    -= copysize;

      /* Show page allocator information */

      mm_pginfo(&pginfo);

      total      = (unsigned long)pginfo.ntotal << MM_PGSHIFT;
      available  = (unsigned long)pginfo.nfree  << MM_PGSHIFT;
      allocated  = total - available;
      max        = (unsigned long)pginfo.mxfree << MM_PGSHIFT;

      linesize   = snprintf(procfile->line, MEMINFO_LINELEN,
                            "Page:  %11lu%11lu%11lu%11lu\n",
                            total, allocated, available, max);

      copysize   = procfs_memcpy(procfile->line, linesize, buffer, buflen,
                                 &offset);
      totalsize += copysize;
    }
#endif

#if defined(CONFIG_ARCH_HAVE_PROGMEM) && defined(CONFIG_FS_PROCFS_INCLUDE_PROGMEM)
  if (totalsize < buflen)
    {
      struct progmem_info_s progmem;

      buffer    += copysize;
      buflen    -= copysize;

      /* The second line is the memory data */

      meminfo_progmem(&progmem);

      linesize   = snprintf(procfile->line, MEMINFO_LINELEN,
                            "Prog:  %11lu%11lu%11lu%11lu\n",
                            (unsigned long)progmem.arena,
                            (unsigned long)progmem.uordblks,
                            (unsigned long)progmem.fordblks,
                            (unsigned long)progmem.mxordblk);
      copysize   = procfs_memcpy(procfile->line, linesize, buffer, buflen,
                                 &offset);
      totalsize += copysize;
    }
#endif

  /* Update the file offset */

  filep->f_pos += totalsize;
  return totalsize;
}

/****************************************************************************
 * Name: meminfo_dup
 *
 * Description:
 *   Duplicate open file data in the new file structure.
 *
 ****************************************************************************/

static int meminfo_dup(FAR const struct file *oldp, FAR struct file *newp)
{
  FAR struct meminfo_file_s *oldattr;
  FAR struct meminfo_file_s *newattr;

  finfo("Dup %p->%p\n", oldp, newp);

  /* Recover our private data from the old struct file instance */

  oldattr = (FAR struct meminfo_file_s *)oldp->f_priv;
  DEBUGASSERT(oldattr);

  /* Allocate a new container to hold the task and attribute selection */

  newattr = (FAR struct meminfo_file_s *)
    kmm_malloc(sizeof(struct meminfo_file_s));
  if (!newattr)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* The copy the file attributes from the old attributes to the new */

  memcpy(newattr, oldattr, sizeof(struct meminfo_file_s));

  /* Save the new attributes in the new file structure */

  newp->f_priv = (FAR void *)newattr;
  return OK;
}

/****************************************************************************
 * Name: meminfo_stat
 *
 * Description: Return information about a file or directory
 *
 ****************************************************************************/

static int meminfo_stat(FAR const char *relpath, FAR struct stat *buf)
{
  /* "meminfo" is the only acceptable value for the relpath */

  if (strcmp(relpath, "meminfo") != 0)
    {
      ferr("ERROR: relpath is '%s'\n", relpath);
      return -ENOENT;
    }

  /* "meminfo" is the name for a read-only file */

  memset(buf, 0, sizeof(struct stat));
  buf->st_mode = S_IFREG | S_IROTH | S_IRGRP | S_IRUSR;
  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: procfs_register_meminfo
 *
 * Description:
 *   Add a new meminfo entry to the procfs file system.
 *
 * Input Parameters:
 *   entry - Describes the entry to be registered.
 *
 ****************************************************************************/

void procfs_register_meminfo(FAR struct procfs_meminfo_entry_s *entry)
{
  entry->next = g_procfs_meminfo;
  g_procfs_meminfo = entry;
}

#endif /* !CONFIG_FS_PROCFS_EXCLUDE_MEMINFO */
