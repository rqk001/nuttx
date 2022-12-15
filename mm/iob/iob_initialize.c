/****************************************************************************
 * mm/iob/iob_initialize.c
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

#include <stdbool.h>

#include <nuttx/mm/iob.h>

#include "iob.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define ROUNDUP(x, y)     (((x) + (y) - 1) / (y) * (y))

/* Fix the I/O Buffer size with specified alignment size */

#define IOB_BUFSIZE   ROUNDUP(CONFIG_IOB_BUFSIZE, CONFIG_IOB_ALIGNMENT)
#define IOB_POOLSIZE  (IOB_BUFSIZE * CONFIG_IOB_NBUFFERS)

#ifdef CONFIG_IOB_SHARED
#  define IOB_NBUFFERS (CONFIG_IOB_NBUFFERS + CONFIG_IOB_SHARED_NBUFFERS)
#else
#  define IOB_NBUFFERS (CONFIG_IOB_NBUFFERS)
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* Following raw buffer will be divided into iob_s instances, the initial
 * procedure will ensure that the member io_data of each iob_s is aligned
 * to the CONFIG_IOB_ALIGNMENT memory boundary.
 */

#ifdef IOB_SECTION
static uint8_t g_iob_buffer[IOB_POOLSIZE] locate_data(IOB_SECTION);
#else
static uint8_t g_iob_buffer[IOB_POOLSIZE];
#endif

static struct iob_s g_iob_list[IOB_NBUFFERS];

#if CONFIG_IOB_NCHAINS > 0
/* This is a pool of pre-allocated iob_qentry_s buffers */

static struct iob_qentry_s g_iob_qpool[CONFIG_IOB_NCHAINS];
#endif

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* A list of all free, unallocated I/O buffers */

FAR struct iob_s *g_iob_freelist;

#ifdef CONFIG_IOB_SHARED
FAR struct iob_s *g_iob_sharelist;
#endif

/* A list of I/O buffers that are committed for allocation */

FAR struct iob_s *g_iob_committed;

#if CONFIG_IOB_NCHAINS > 0
/* A list of all free, unallocated I/O buffer queue containers */

FAR struct iob_qentry_s *g_iob_freeqlist;

/* A list of I/O buffer queue containers that are committed for allocation */

FAR struct iob_qentry_s *g_iob_qcommitted;
#endif

/* Counting semaphores that tracks the number of free IOBs/qentries */

sem_t g_iob_sem = SEM_INITIALIZER(CONFIG_IOB_NBUFFERS);

#if CONFIG_IOB_THROTTLE > 0
/* Counts available I/O buffers when throttled */

sem_t g_throttle_sem = SEM_INITIALIZER(CONFIG_IOB_NBUFFERS -
                                       CONFIG_IOB_THROTTLE);
#endif

#if CONFIG_IOB_NCHAINS > 0
/* Counts free I/O buffer queue containers */

sem_t g_qentry_sem = SEM_INITIALIZER(CONFIG_IOB_NCHAINS);
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: iob_initialize
 *
 * Description:
 *   Set up the I/O buffers for normal operations.
 *
 ****************************************************************************/

void iob_initialize(void)
{
  int i;

  /* Get I/O buffer instance from the start address and add each I/O buffer
   * to the free list
   */

  for (i = 0; i < CONFIG_IOB_NBUFFERS; i++)
    {
      FAR struct iob_s *iob = &g_iob_list[i];

      /* Add the pre-allocate I/O buffer to the head of the free list */

      iob->io_data   = &g_iob_buffer[i * IOB_BUFSIZE];
      iob->io_flink  = g_iob_freelist;
      g_iob_freelist = iob;
    }

#ifdef CONFIG_IOB_SHARED
  /* Initialize the shared iob pool */

  for (i = CONFIG_IOB_NBUFFERS; i < IOB_NBUFFERS; i++)
    {
      FAR struct iob_s *iob = &g_iob_list[i];

      /* Add the pre-allocate I/O buffer to the head of the free list */

      iob->io_flink   = g_iob_sharelist;
      g_iob_sharelist = iob;
    }
#endif

#if CONFIG_IOB_NCHAINS > 0
  /* Add each I/O buffer chain queue container to the free list */

  for (i = 0; i < CONFIG_IOB_NCHAINS; i++)
    {
      FAR struct iob_qentry_s *iobq = &g_iob_qpool[i];

      /* Add the pre-allocate buffer container to the head of the free
       * list
       */

      iobq->qe_flink  = g_iob_freeqlist;
      g_iob_freeqlist = iobq;
    }
#endif
}
