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
#include <nuttx/sched.h>
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

#define MEMINFO_LINELEN 80

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
  int aordblks;                   /* This is the number of allocated chunks */
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
#ifndef CONFIG_FS_PROCFS_EXCLUDE_MEMDUMP
static ssize_t memdump_read(FAR struct file *filep, FAR char *buffer,
                             size_t buflen);
static ssize_t memdump_write(FAR struct file *filep, FAR const char *buffer,
                             size_t buflen);
#endif
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

#ifndef CONFIG_FS_PROCFS_EXCLUDE_MEMDUMP
const struct procfs_operations memdump_operations =
{
  meminfo_open,   /* open */
  meminfo_close,  /* close */
  memdump_read,   /* read */
  memdump_write,  /* write */
  meminfo_dup,    /* dup */
  NULL,           /* opendir */
  NULL,           /* closedir */
  NULL,           /* readdir */
  NULL,           /* rewinddir */
  meminfo_stat    /* stat */
};
#endif

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
  progmem->ordblks  = 0;
  progmem->aordblks = 0;
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
          progmem->ordblks++;
        }
      else if (status != 0)
        {
          progmem->aordblks++;
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

  /* Allocate a container to hold the file attributes */

  procfile = kmm_zalloc(sizeof(struct meminfo_file_s));
  if (!procfile)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* Save the attributes as the open-specific state in filep->f_priv */

  filep->f_priv = procfile;
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

  linesize  = procfs_snprintf(procfile->line, MEMINFO_LINELEN,
                              "%13s%11s%11s%11s%11s%7s%7s\n", "", "total",
                              "used", "free", "largest", "nused", "nfree");

  copysize  = procfs_memcpy(procfile->line, linesize, buffer, buflen,
                            &offset);
  totalsize = copysize;

  /* Followed by information about the memory resources */

  FAR const struct procfs_meminfo_entry_s *entry;

  for (entry = g_procfs_meminfo; entry != NULL; entry = entry->next)
    {
      if (buflen > 0)
        {
          struct mallinfo minfo;

          buffer    += copysize;
          buflen    -= copysize;

          /* Show heap information */

          mm_mallinfo(entry->heap, &minfo);
          linesize   = procfs_snprintf(procfile->line, MEMINFO_LINELEN,
                                       "%12s:%11lu%11lu%11lu%11lu%7lu%7lu\n",
                                       entry->name,
                                       (unsigned long)minfo.arena,
                                       (unsigned long)minfo.uordblks,
                                       (unsigned long)minfo.fordblks,
                                       (unsigned long)minfo.mxordblk,
                                       (unsigned long)minfo.aordblks,
                                       (unsigned long)minfo.ordblks);
          copysize   = procfs_memcpy(procfile->line, linesize, buffer,
                                     buflen, &offset);
          totalsize += copysize;
        }
    }

#ifdef CONFIG_MM_PGALLOC
  if (buflen > 0)
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

      linesize   = procfs_snprintf(procfile->line, MEMINFO_LINELEN,
                                   "%12s:%11lu%11lu%11lu%11lu\n",
                                   "Page", total, allocated, available, max);

      copysize   = procfs_memcpy(procfile->line, linesize, buffer, buflen,
                                 &offset);
      totalsize += copysize;
    }
#endif

#if defined(CONFIG_ARCH_HAVE_PROGMEM) && defined(CONFIG_FS_PROCFS_INCLUDE_PROGMEM)
  if (buflen > 0)
    {
      struct progmem_info_s progmem;

      buffer    += copysize;
      buflen    -= copysize;

      /* The second line is the memory data */

      meminfo_progmem(&progmem);

      linesize   = procfs_snprintf(procfile->line, MEMINFO_LINELEN,
                                   "%12s:%11lu%11lu%11lu%11lu%7lu%7lu\n",
                                   "Prog",
                                   (unsigned long)progmem.arena,
                                   (unsigned long)progmem.uordblks,
                                   (unsigned long)progmem.fordblks,
                                   (unsigned long)progmem.mxordblk,
                                   (unsigned long)progmem.aordblks,
                                   (unsigned long)progmem.ordblks);
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
 * Name: memdump_read
 ****************************************************************************/

#ifndef CONFIG_FS_PROCFS_EXCLUDE_MEMDUMP
static ssize_t memdump_read(FAR struct file *filep, FAR char *buffer,
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

#if CONFIG_MM_BACKTRACE >= 0
  linesize  = procfs_snprintf(procfile->line, MEMINFO_LINELEN,
                              "usage: <pid/used/free/on/off>\n"
                              "on/off backtrace\n"
                              "pid: dump pid allocated node\n");
#else
  linesize  = procfs_snprintf(procfile->line, MEMINFO_LINELEN,
                              "usage: <used/free>\n");
#endif

  copysize  = procfs_memcpy(procfile->line, linesize, buffer, buflen,
                            &offset);
  totalsize = copysize;
  buffer   += copysize;
  buflen   -= copysize;
  linesize  = procfs_snprintf(procfile->line, MEMINFO_LINELEN,
                              "used: dump all allocated node\n"
                              "free: dump all free node\n");

  totalsize += procfs_memcpy(procfile->line, linesize, buffer, buflen,
                             &offset);
  filep->f_pos += totalsize;
  return totalsize;
}
#endif

/****************************************************************************
 * Name: memdump_write
 ****************************************************************************/

#ifndef CONFIG_FS_PROCFS_EXCLUDE_MEMDUMP
static ssize_t memdump_write(FAR struct file *filep, FAR const char *buffer,
                             size_t buflen)
{
  FAR struct procfs_meminfo_entry_s *entry;
  FAR struct meminfo_file_s *procfile;
  pid_t pid = INVALID_PROCESS_ID;
#if CONFIG_MM_BACKTRACE > 0
  FAR struct tcb_s *tcb;
  FAR char *p;
#endif

  DEBUGASSERT(filep != NULL && buffer != NULL && buflen > 0);

  /* Recover our private data from the struct file instance */

  procfile = filep->f_priv;
  DEBUGASSERT(procfile);

#if CONFIG_MM_BACKTRACE > 0
  if (strcmp(buffer, "on") == 0)
    {
      for (entry = g_procfs_meminfo; entry != NULL; entry = entry->next)
        {
          entry->backtrace = true;
        }

      return buflen;
    }
  else if (strcmp(buffer, "off") == 0)
    {
      for (entry = g_procfs_meminfo; entry != NULL; entry = entry->next)
        {
          entry->backtrace = false;
        }

      return buflen;
    }
  else if ((p = strstr(buffer, "on")) != NULL)
    {
      *p = '\0';
      pid = atoi(buffer);
      tcb = nxsched_get_tcb(pid);
      if (tcb == NULL)
        {
          return -EINVAL;
        }

      tcb->flags |= TCB_FLAG_HEAP_DUMP;
      return buflen;
    }
  else if ((p = strstr(buffer, "off")) != NULL)
    {
      *p = '\0';
      pid = atoi(buffer);
      tcb = nxsched_get_tcb(pid);
      if (tcb == NULL)
        {
          return -EINVAL;
        }

      tcb->flags &= ~TCB_FLAG_HEAP_DUMP;
      return buflen;
    }
#endif

  switch (buffer[0])
    {
      case 'u':
        pid = (pid_t)-1;
        break;

      case 'f':
        pid = (pid_t)-2;
        break;
#if CONFIG_MM_BACKTRACE >= 0
      default:
        pid = atoi(buffer);
#endif
    }

  for (entry = g_procfs_meminfo; entry != NULL; entry = entry->next)
    {
      mm_memdump(entry->heap, pid);
    }

  return buflen;
}
#endif

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
  if (NULL == entry->name)
    {
      return;
    }

  entry->next = g_procfs_meminfo;
  g_procfs_meminfo = entry;
}

/****************************************************************************
 * Name: procfs_unregister_meminfo
 *
 * Description:
 *   Remove a meminfo entry from the procfs file system.
 *
 * Input Parameters:
 *   entry - Describes the entry to be unregistered.
 *
 ****************************************************************************/

void procfs_unregister_meminfo(FAR struct procfs_meminfo_entry_s *entry)
{
  FAR struct procfs_meminfo_entry_s **cur;

  for (cur = &g_procfs_meminfo; *cur != NULL; cur = &(*cur)->next)
    {
      if (*cur == entry)
        {
          *cur = entry->next;
          break;
        }
    }
}
#endif /* !CONFIG_FS_PROCFS_EXCLUDE_MEMINFO */
