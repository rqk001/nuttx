/****************************************************************************
 * fs/procfs/fs_procfscritmon.c
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
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

#include <sys/types.h>
#include <sys/stat.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/clock.h>
#include <nuttx/kmalloc.h>
#include <nuttx/fs/fs.h>
#include <nuttx/fs/procfs.h>

#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_PROCFS) && \
     defined(CONFIG_SCHED_CRITMONITOR)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Determines the size of an intermediate buffer that must be large enough
 * to handle the longest line generated by this logic.
 */

#define CRITMON_LINELEN 64

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure describes one open "file" */

struct critmon_file_s
{
  struct procfs_file_s  base;   /* Base open file structure */
  unsigned int linesize;        /* Number of valid characters in line[] */
  char line[CRITMON_LINELEN];   /* Pre-allocated buffer for formatted lines */
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* File system methods */

static int     critmon_open(FAR struct file *filep, FAR const char *relpath,
                 int oflags, mode_t mode);
static int     critmon_close(FAR struct file *filep);
static ssize_t critmon_read(FAR struct file *filep, FAR char *buffer,
                 size_t buflen);
static int     critmon_dup(FAR const struct file *oldp,
                 FAR struct file *newp);
static int     critmon_stat(FAR const char *relpath, FAR struct stat *buf);

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* See fs_mount.c -- this structure is explicitly externed there.
 * We use the old-fashioned kind of initializers so that this will compile
 * with any compiler.
 */

const struct procfs_operations critmon_operations =
{
  critmon_open,       /* open */
  critmon_close,      /* close */
  critmon_read,       /* read */
  NULL,               /* write */

  critmon_dup,        /* dup */

  NULL,              /* opendir */
  NULL,              /* closedir */
  NULL,              /* readdir */
  NULL,              /* rewinddir */

  critmon_stat        /* stat */
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: critmon_open
 ****************************************************************************/

static int critmon_open(FAR struct file *filep, FAR const char *relpath,
                      int oflags, mode_t mode)
{
  FAR struct critmon_file_s *attr;

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

  /* "critmon" is the only acceptable value for the relpath */

  if (strcmp(relpath, "critmon") != 0)
    {
      ferr("ERROR: relpath is '%s'\n", relpath);
      return -ENOENT;
    }

  /* Allocate a container to hold the file attributes */

  attr = kmm_zalloc(sizeof(struct critmon_file_s));
  if (!attr)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* Save the attributes as the open-specific state in filep->f_priv */

  filep->f_priv = (FAR void *)attr;
  return OK;
}

/****************************************************************************
 * Name: critmon_close
 ****************************************************************************/

static int critmon_close(FAR struct file *filep)
{
  FAR struct critmon_file_s *attr;

  /* Recover our private data from the struct file instance */

  attr = (FAR struct critmon_file_s *)filep->f_priv;
  DEBUGASSERT(attr);

  /* Release the file attributes structure */

  kmm_free(attr);
  filep->f_priv = NULL;
  return OK;
}

/****************************************************************************
 * Name: critmon_read_cpu
 ****************************************************************************/

static ssize_t critmon_read_cpu(FAR struct critmon_file_s *attr,
                                FAR char *buffer, size_t buflen,
                                FAR off_t *offset, int cpu)
{
  struct timespec maxtime;
  size_t remaining;
  size_t linesize;
  size_t copysize;
  size_t totalsize;

  remaining = buflen;
  totalsize = 0;

  /* Convert the for maximum time pre-emption disabled */

  if (g_premp_max[cpu] > 0)
    {
      up_critmon_convert(g_premp_max[cpu], &maxtime);
    }
  else
    {
      maxtime.tv_sec = 0;
      maxtime.tv_nsec = 0;
    }

  /* Reset the maximum */

  g_premp_max[cpu] = 0;

  /* Generate output for maximum time pre-emption disabled */

  linesize = snprintf(attr->line, CRITMON_LINELEN, "%d,%lu.%09lu,",
                     cpu, (unsigned long)maxtime.tv_sec,
                     (unsigned long)maxtime.tv_nsec);
  copysize = procfs_memcpy(attr->line, linesize, buffer, buflen, offset);

  totalsize += copysize;
  buffer    += copysize;
  remaining -= copysize;

  if (totalsize >= buflen)
    {
      return totalsize;
    }

  /* Convert and generate output for maximum time in a critical section */

  if (g_crit_max[cpu] > 0)
    {
      up_critmon_convert(g_crit_max[cpu], &maxtime);
    }
  else
    {
      maxtime.tv_sec = 0;
      maxtime.tv_nsec = 0;
    }

  /* Reset the maximum */

  g_crit_max[cpu] = 0;

  /* Generate output for maximum time in a critical section */

  linesize = snprintf(attr->line, CRITMON_LINELEN, "%lu.%09lu\n",
                     (unsigned long)maxtime.tv_sec,
                     (unsigned long)maxtime.tv_nsec);
  copysize = procfs_memcpy(attr->line, linesize, buffer, buflen, offset);

  totalsize += copysize;
  return totalsize;
}

/****************************************************************************
 * Name: critmon_read
 ****************************************************************************/

static ssize_t critmon_read(FAR struct file *filep, FAR char *buffer,
                            size_t buflen)
{
  FAR struct critmon_file_s *attr;
  off_t offset;
  ssize_t ret;
#ifdef CONFIG_SMP
  int cpu;
#endif

  finfo("buffer=%p buflen=%d\n", buffer, (int)buflen);

  /* Recover our private data from the struct file instance */

  attr = (FAR struct critmon_file_s *)filep->f_priv;
  DEBUGASSERT(attr);

  ret    = 0;
  offset = filep->f_pos;

#ifdef CONFIG_SMP
  /* Get the status for each CPU  */

  for (cpu = 0; cpu < CONFIG_SMP_NCPUS; cpu++)
    {
      ssize_t nbytes = critmon_read_cpu(attr, buffer + ret, buflen - ret,
                                        &offset, cpu);

      ret += nbytes;
      if (ret > buflen)
        {
          break;
        }

      offset += nbytes;
    }

#else
  /* Get status for the single CPU */

  ret = critmon_read_cpu(attr, buffer + ret, buflen -ret, &offset, 0);
#endif

  if (ret > 0)
    {
      filep->f_pos += ret;
    }

  return ret;
}

/****************************************************************************
 * Name: critmon_dup
 *
 * Description:
 *   Duplicate open file data in the new file structure.
 *
 ****************************************************************************/

static int critmon_dup(FAR const struct file *oldp, FAR struct file *newp)
{
  FAR struct critmon_file_s *oldattr;
  FAR struct critmon_file_s *newattr;

  finfo("Dup %p->%p\n", oldp, newp);

  /* Recover our private data from the old struct file instance */

  oldattr = (FAR struct critmon_file_s *)oldp->f_priv;
  DEBUGASSERT(oldattr);

  /* Allocate a new container to hold the task and attribute selection */

  newattr = kmm_malloc(sizeof(struct critmon_file_s));
  if (!newattr)
    {
      ferr("ERROR: Failed to allocate file attributes\n");
      return -ENOMEM;
    }

  /* The copy the file attributes from the old attributes to the new */

  memcpy(newattr, oldattr, sizeof(struct critmon_file_s));

  /* Save the new attributes in the new file structure */

  newp->f_priv = (FAR void *)newattr;
  return OK;
}

/****************************************************************************
 * Name: critmon_stat
 *
 * Description: Return information about a file or directory
 *
 ****************************************************************************/

static int critmon_stat(const char *relpath, struct stat *buf)
{
  /* "critmon" is the only acceptable value for the relpath */

  if (strcmp(relpath, "critmon") != 0)
    {
      ferr("ERROR: relpath is '%s'\n", relpath);
      return -ENOENT;
    }

  /* "critmon" is the name for a read-only file */

  memset(buf, 0, sizeof(struct stat));
  buf->st_mode = S_IFREG | S_IROTH | S_IRGRP | S_IRUSR;
  return OK;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

#endif /* !CONFIG_DISABLE_MOUNTPOINT && CONFIG_FS_PROCFS && CONFIG_SCHED_CRITMONITOR */
