/****************************************************************************
 * drivers/djoystick.c
 *
 *   Copyright (C) 2014 Gregory Nutt. All rights reserved.
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
#include <stdbool.h>
#include <string.h>
#include <poll.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/kmalloc.h>
#include <nuttx/fs/fs.h>
#include <nuttx/input/djoystick.h>

#include <arch/irq.h>

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* This structure provides the state of one discrete joystick driver */

struct djoy_upperhalf_s
{
  /* Saved binding to the lower half discrete joystick driver */

  FAR const struct djoy_lowerhalf_s *du_lower;

  djoy_buttonset_t du_enabled; /* Set of currently enabled button interrupts */
  djoy_buttonset_t du_sample;  /* Last sampled button states */
  sem_t du_exclsem;            /* Supports exclusive access to the device */

  /* The following is a singly linked list of open references to the
   * joystick device.
   */

  FAR struct djoy_open_s *du_open;
};

/* This structure describes the state of one open joystick driver instance */

struct djoy_open_s
{
  /* Supports a singly linked list */

  FAR struct djoy_open_s *do_flink;

  /* The following will be true if we are closing */

  volatile bool do_closing;

#ifndef CONFIG_DISABLE_SIGNALS
  /* Joystick event notification information */

  pid_t do_pid;
  struct djoy_notify_s do_notify;
#endif

#ifndef CONFIG_DISABLE_POLL
  /* Poll event information */

  struct djoy_pollevents_s do_pollevents;

  /* The following is a list if poll structures of threads waiting for
   * driver events.
   */

  FAR struct pollfd *do_fds[CONFIG_DJOYSTICK_NPOLLWAITERS];
#endif
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/* Semaphore helpers */

static inline int djoy_takesem(sem_t *sem);
#define djoy_givesem(s) sem_post(s);

/* Sampling and Interrupt handling */

#if !defined(CONFIG_DISABLE_POLL) || !defined(CONFIG_DISABLE_SIGNALS)
static void    djoy_enable(FAR struct djoy_upperhalf_s *priv);
static void    djoy_interrupt(FAR const struct djoy_lowerhalf_s *lower,
                              FAR void *arg);
#endif

/* Sampling */

static void    djoy_sample(FAR struct djoy_upperhalf_s *priv);

/* Character driver methods */

static int     djoy_open(FAR struct file *filep);
static int     djoy_close(FAR struct file *filep);
static ssize_t djoy_read(FAR struct file *, FAR char *, size_t);
static int     djoy_ioctl(FAR struct file *filep, int cmd,
                          unsigned long arg);
#ifndef CONFIG_DISABLE_POLL
static int     djoy_poll(FAR struct file *filep, FAR struct pollfd *fds,
                         bool setup);
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const struct file_operations djoy_fops =
{
  djoy_open,  /* open */
  djoy_close, /* close */
  djoy_read,  /* read */
  0,          /* write */
  0,          /* seek */
  djoy_ioctl  /* ioctl */
#ifndef CONFIG_DISABLE_POLL
  , djoy_poll /* poll */
#endif
};

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: djoy_takesem
 ****************************************************************************/

static inline int djoy_takesem(sem_t *sem)
{
  /* Take a count from the semaphore, possibly waiting */

  if (sem_wait(sem) < 0)
    {
      /* EINTR is the only error that we expect */

      int errcode = get_errno();
      DEBUGASSERT(errcode == EINTR);
      return -errcode;
    }

  return OK;
}

/****************************************************************************
 * Name: djoy_enable
 ****************************************************************************/

#if !defined(CONFIG_DISABLE_POLL) || !defined(CONFIG_DISABLE_SIGNALS)
static void djoy_enable(FAR struct djoy_upperhalf_s *priv)
{
  FAR const struct djoy_lowerhalf_s *lower = priv->du_lower;
  FAR struct djoy_open_s *opriv;
  djoy_buttonset_t press;
  djoy_buttonset_t release;
  irqstate_t flags;
#ifndef CONFIG_DISABLE_POLL
  int i;
#endif

  DEBUGASSERT(priv && priv->du_lower);
  lower = priv->du_lower;

  /* This routine is called both task level and interrupt level, so
   * interrupts must be disabled.
   */

  flags = irqsave();

  /* Visit each opened reference to the device */

  press   = 0;
  release = 0;

  for (opriv = priv->du_open; opriv; opriv = opriv->do_flink)
    {
#ifndef CONFIG_DISABLE_POLL
      /* Are there any poll waiters? */

      for (i = 0; i < CONFIG_DJOYSTICK_NPOLLWAITERS; i++)
        {
          if (opriv->do_fds[i])
            {
              /* Yes.. OR in the poll event buttons */

              press   |= opriv->do_pollevents.dp_press;
              release |= opriv->do_pollevents.dp_release;
              break;
            }
        }
#endif

#ifndef CONFIG_DISABLE_SIGNALS
      /* OR in the signal events */

      press   |= opriv->do_notify.dn_press;
      release |= opriv->do_notify.dn_release;
#endif
    }

  /* Enable/disable button interrupts */

  DEBUGASSERT(lower->dl_enable);
  if (press != 0 || release != 0)
    {
      /* Enable interrupts with the new button set */

      lower->dl_enable(lower, press, release,
                       (djoy_interrupt_t)djoy_interrupt, priv);
    }
  else
    {
      /* Disable further interrupts */

      lower->dl_enable(lower, 0, 0, NULL, NULL);
    }

  irqrestore(flags);
}
#endif

/****************************************************************************
 * Name: djoy_interrupt
 ****************************************************************************/

#if !defined(CONFIG_DISABLE_POLL) || !defined(CONFIG_DISABLE_SIGNALS)
static void djoy_interrupt(FAR const struct djoy_lowerhalf_s *lower,
                           FAR void *arg)
{
  FAR struct djoy_upperhalf_s *priv = (FAR struct djoy_upperhalf_s *)arg;

  DEBUGASSERT(priv);

  /* Process the next sample */

  djoy_sample(priv);
}
#endif

/****************************************************************************
 * Name: djoy_sample
 ****************************************************************************/

static void djoy_sample(FAR struct djoy_upperhalf_s *priv)
{
  FAR const struct djoy_lowerhalf_s *lower = priv->du_lower;
  FAR struct djoy_open_s *opriv;
  djoy_buttonset_t sample;
#if !defined(CONFIG_DISABLE_POLL) || !defined(CONFIG_DISABLE_SIGNALS)
  djoy_buttonset_t change;
  djoy_buttonset_t press;
  djoy_buttonset_t release;
#endif
  irqstate_t flags;
#ifndef CONFIG_DISABLE_POLL
  int i;
#endif

  DEBUGASSERT(priv && priv->du_lower);
  lower = priv->du_lower;

  /* This routine is called both task level and interrupt level, so
   * interrupts must be disabled.
   */

  flags = irqsave();

  /* Sample the new button state */

  DEBUGASSERT(lower->dl_sample);
  sample = lower->dl_sample(lower);

#if !defined(CONFIG_DISABLE_POLL) || !defined(CONFIG_DISABLE_SIGNALS)
  /* Determine which buttons have been newly pressed and which have been
   * newly released.
   */

  change  = sample ^ priv->du_sample;
  press   = change & sample;

  DEBUGASSERT(lower->dl_supported);
  release = change & (lower->dl_supported(lower) & ~sample);

  /* Visit each opened reference to the device */

  for (opriv = priv->du_open; opriv; opriv = opriv->do_flink)
    {
#ifndef CONFIG_DISABLE_POLL
      /* Have any poll events occurred? */

      if ((press & opriv->do_pollevents.dp_press)     != 0 ||
          (release & opriv->do_pollevents.dp_release) != 0)
        {
          /* Yes.. Notify all waiters */

          for (i = 0; i < CONFIG_DJOYSTICK_NPOLLWAITERS; i++)
            {
              FAR struct pollfd *fds = opriv->do_fds[i];
              if (fds)
                {
                  fds->revents |= (fds->events & POLLIN);
                  if (fds->revents != 0)
                    {
                      ivdbg("Report events: %02x\n", fds->revents);
                      sem_post(fds->sem);
                    }
                }
            }
        }
#endif

#ifndef CONFIG_DISABLE_SIGNALS
      /* Have any signal events occurred? */

      if ((press & opriv->do_notify.dn_press)     != 0 ||
          (release & opriv->do_notify.dn_release) != 0)
        {
          /* Yes.. Signal the waiter */

#ifdef CONFIG_CAN_PASS_STRUCTS
          union sigval value;
          value.sival_int = (int)sample;
          (void)sigqueue(opriv->do_pid, opriv->do_notify.dn_signo, value);
#else
          (void)sigqueue(opriv->do_pid, opriv->do_notify.dn.signo,
                         (FAR void *)sample);
#endif
        }
#endif
    }

  /* Enable/disable interrupt handling */

  djoy_enable(priv);
#endif

  priv->du_sample = sample;
  irqrestore(flags);
}

/****************************************************************************
 * Name: djoy_open
 ****************************************************************************/

static int djoy_open(FAR struct file *filep)
{
  FAR struct inode *inode;
  FAR struct djoy_upperhalf_s *priv;
  FAR const struct djoy_lowerhalf_s *lower;
  FAR struct djoy_open_s *opriv;
#ifndef CONFIG_DISABLE_POLL
  djoy_buttonset_t supported;
#endif
  int ret;

  DEBUGASSERT(filep && filep->f_inode);
  inode = filep->f_inode;
  DEBUGASSERT(inode->i_private);
  priv = (FAR struct djoy_upperhalf_s *)inode->i_private;

  /* Get exclusive access to the driver structure */

  ret = djoy_takesem(&priv->du_exclsem);
  if (ret < 0)
    {
      ivdbg("ERROR: djoy_takesem failed: %d\n", ret);
      return ret;
    }

  /* Allocate a new open structure */

  opriv = (FAR struct djoy_open_s *)kmm_zalloc(sizeof(struct djoy_open_s));
  if (!opriv)
    {
      ivdbg("ERROR: Failled to allocate open structure\n");
      ret = -ENOMEM;
      goto errout_with_sem;
    }

  /* Initialize the open structure */

#ifndef CONFIG_DISABLE_POLL
  lower = priv->du_lower;
  DEBUGASSERT(lower && lower->dl_supported);
  supported = lower->dl_supported(lower);

  opriv->do_pollevents.dp_press   = supported;
  opriv->do_pollevents.dp_release = supported;
#endif

  /* Attach the open structure to the device */

  opriv->do_flink = priv->du_open;
  priv->du_open = opriv;

  /* Attach the open structure to the file structure */

  filep->f_priv = (FAR void *)opriv;
  ret = OK;

errout_with_sem:
  djoy_givesem(&priv->du_exclsem);
  return ret;
}

/****************************************************************************
 * Name: djoy_close
 ****************************************************************************/

static int djoy_close(FAR struct file *filep)
{
  FAR struct inode *inode;
  FAR struct djoy_upperhalf_s *priv;
  FAR struct djoy_open_s *opriv;
  FAR struct djoy_open_s *curr;
  FAR struct djoy_open_s *prev;
  irqstate_t flags;
  bool closing;
  int ret;

  DEBUGASSERT(filep && filep->f_priv && filep->f_inode);
  opriv = filep->f_priv;
  inode = filep->f_inode;
  DEBUGASSERT(inode->i_private);
  priv  = (FAR struct djoy_upperhalf_s *)inode->i_private;

  /* Handle an improbable race conditions with the following atomic test
   * and set.
   *
   * This is actually a pretty feeble attempt to handle this.  The
   * improbable race condition occurs if two different threads try to
   * close the joystick driver at the same time.  The rule:  don't do
   * that!  It is feeble because we do not really enforce stale pointer
   * detection anyway.
   */

  flags = irqsave();
  closing = opriv->do_closing;
  if (!closing)
    {
      opriv->do_closing = true;
    }

  irqrestore(flags);
  if (closing)
    {
      /* Another thread is doing the close */

      return OK;
    }

  /* Get exclusive access to the driver structure */

  ret = djoy_takesem(&priv->du_exclsem);
  if (ret < 0)
    {
      ivdbg("ERROR: djoy_takesem failed: %d\n", ret);
      return ret;
    }

  /* Find the open structure in the list of open structures for the device */

  for (prev = NULL, curr = priv->du_open;
       curr && curr != opriv;
       prev = curr, curr = curr->do_flink);

  DEBUGASSERT(curr);
  if (!curr)
    {
      ivdbg("ERROR: Failed to find open entry\n");
      ret = -ENOENT;
      goto errout_with_exclsem;
    }

  /* Remove the structure from the device */

  if (prev)
    {
      prev->do_flink = opriv->do_flink;
    }
  else
    {
      priv->du_open = opriv->do_flink;
    }

  /* And free the open structure */

  kmm_free(opriv);

  /* Enable/disable interrupt handling */

  djoy_enable(priv);
  djoy_givesem(&priv->du_exclsem);
  return OK;

errout_with_exclsem:
  djoy_givesem(&priv->du_exclsem);
  return ret;
}

/****************************************************************************
 * Name: djoy_read
 ****************************************************************************/

static ssize_t djoy_read(FAR struct file *filep, FAR char *buffer,
                         size_t len)
{
  FAR struct inode *inode;
  FAR struct djoy_upperhalf_s *priv;
  FAR const struct djoy_lowerhalf_s *lower;
  int ret;

  DEBUGASSERT(filep && filep->f_inode);
  inode = filep->f_inode;
  DEBUGASSERT(inode->i_private);
  priv  = (FAR struct djoy_upperhalf_s *)inode->i_private;

  /* Get exclusive access to the driver structure */

  ret = djoy_takesem(&priv->du_exclsem);
  if (ret < 0)
    {
      ivdbg("ERROR: djoy_takesem failed: %d\n", ret);
      return ret;
    }

  /* Read and return the current state of the joystick buttons */

  lower = priv->du_lower;
  DEBUGASSERT(lower && lower->dl_sample);
  priv->du_sample = lower->dl_sample(lower);
  *(djoy_buttonset_t*)buffer = priv->du_sample;
  ret = sizeof(djoy_buttonset_t);

  djoy_givesem(&priv->du_exclsem);
  return ret;
}

/****************************************************************************
 * Name: djoy_ioctl
 ****************************************************************************/

static int djoy_ioctl(FAR struct file *filep, int cmd, unsigned long arg)
{
  FAR struct inode *inode;
  FAR struct djoy_upperhalf_s *priv;
  FAR struct djoy_open_s *opriv;
  int ret;

  DEBUGASSERT(filep && filep->f_priv && filep->f_inode);
  opriv = filep->f_priv;
  inode = filep->f_inode;
  DEBUGASSERT(inode->i_private);
  priv  = (FAR struct djoy_upperhalf_s *)inode->i_private;

  /* Get exclusive access to the driver structure */

  ret = djoy_takesem(&priv->du_exclsem);
  if (ret < 0)
    {
      ivdbg("ERROR: djoy_takesem failed: %d\n", ret);
      return ret;
    }

  /* Handle the ioctl command */

  ret = -EINVAL;
  switch (cmd)
    {
#ifndef CONFIG_DISABLE_POLL
    /* Command:     DJOYIOC_POLLEVENTS
     * Description: Specify the set of button events that can cause a poll()
     *              to awaken.  The default is all button depressions and
     *              all button releases (all supported buttons);
     * Argument:    A read-only pointer to an instance of struct
     *              djoy_pollevents_s
     * Return:      Zero (OK) on success.  Minus one will be returned on
     *              failure with the errno value set appropriately.
     */

    case DJOYIOC_POLLEVENTS:
      {
        FAR struct djoy_pollevents_s *pollevents =
          (FAR struct djoy_pollevents_s *)((uintptr_t)arg);

        if (pollevents)
          {
            /* Save the poll events */

            opriv->do_pollevents.dp_press   = pollevents->dp_press;
            opriv->do_pollevents.dp_release = pollevents->dp_release;

            /* Enable/disable interrupt handling */

            djoy_enable(priv);
            ret = OK;
          }
      }
      break;
#endif

#ifndef CONFIG_DISABLE_SIGNALS
    /* Command:     DJOYIOC_REGISTER
     * Description: Register to receive a signal whenever there is a change
     *              in any of the joystick discrete inputs.  This feature,
     *              of course, depends upon interrupt GPIO support from the
     *              platform.
     * Argument:    A read-only pointer to an instance of struct
     *              djoy_notify_s
     * Return:      Zero (OK) on success.  Minus one will be returned on
     *              failure with the errno value set appropriately.
     */

    case DJOYIOC_REGISTER:
      {
        FAR struct djoy_notify_s *notify =
          (FAR struct djoy_notify_s *)((uintptr_t)arg);

        if (notify)
          {
            /* Save the notification events */

            opriv->do_notify.dn_press   = notify->dn_press;
            opriv->do_notify.dn_release = notify->dn_release;
            opriv->do_notify.dn_signo  = notify->dn_signo;
            opriv->do_pid               = getpid();

            /* Enable/disable interrupt handling */

            djoy_enable(priv);
            ret = OK;
          }
      }
      break;
#endif

    default:
      ivdbg("ERROR: Unrecognized command: %ld\n", cmd);
      ret = -ENOTTY;
      break;
    }

  djoy_givesem(&priv->du_exclsem);
  return ret;
}

/****************************************************************************
 * Name: djoy_poll
 ****************************************************************************/

#ifndef CONFIG_DISABLE_POLL
static int djoy_poll(FAR struct file *filep, FAR struct pollfd *fds,
                     bool setup)
{
  FAR struct inode *inode;
  FAR struct djoy_upperhalf_s *priv;
  FAR struct djoy_open_s *opriv;
  int ret;
  int i;

  DEBUGASSERT(filep && filep->f_priv && filep->f_inode);
  opriv = filep->f_priv;
  inode = filep->f_inode;
  DEBUGASSERT(inode->i_private);
  priv  = (FAR struct djoy_upperhalf_s *)inode->i_private;

  /* Get exclusive access to the driver structure */

  ret = djoy_takesem(&priv->du_exclsem);
  if (ret < 0)
    {
      ivdbg("ERROR: djoy_takesem failed: %d\n", ret);
      return ret;
    }

  /* Are we setting up the poll?  Or tearing it down? */

  if (setup)
    {
      /* This is a request to set up the poll.  Find an available
       * slot for the poll structure reference
       */

      for (i = 0; i < CONFIG_DJOYSTICK_NPOLLWAITERS; i++)
        {
          /* Find an available slot */

          if (!opriv->do_fds[i])
            {
              /* Bind the poll structure and this slot */

              opriv->do_fds[i] = fds;
              fds->priv = &opriv->do_fds[i];
              break;
            }
        }

      if (i >= CONFIG_DJOYSTICK_NPOLLWAITERS)
        {
          ivdbg("ERROR: Too man poll waiters\n");
          fds->priv    = NULL;
          ret          = -EBUSY;
          goto errout_with_dusem;
        }
    }
  else if (fds->priv)
    {
      /* This is a request to tear down the poll. */

      FAR struct pollfd **slot = (FAR struct pollfd **)fds->priv;

#ifdef CONFIG_DEBUG
      if (!slot)
        {
          ivdbg("ERROR: Poll slot not found\n");
          ret = -EIO;
          goto errout_with_dusem;
        }
#endif

      /* Remove all memory of the poll setup */

      *slot     = NULL;
      fds->priv = NULL;
    }

errout_with_dusem:
  djoy_givesem(&priv->du_exclsem);
  return ret;
}
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: djoy_register
 *
 * Description:
 *   Bind the lower half discrete joystick driver to an instance of the
 *   upper half discrete joystick driver and register the composite character
 *   driver as the specific device.
 *
 * Input Parameters:
 *   devname - The name of the discrete joystick device to be registers.
 *     This should be a string of the form "/priv/djoyN" where N is the the
 *     minor device number.
 *   lower - An instance of the platform-specific discrete joystick lower
 *     half driver.
 *
 * Returned Values:
 *   Zero (OK) is returned on success.  Otherwise a negated errno value is
 *   returned to indicate the nature of the failure.
 *
 ****************************************************************************/

int djoy_register(FAR const char *devname,
                  FAR const struct djoy_lowerhalf_s *lower)

{
  FAR struct djoy_upperhalf_s *priv;
  int ret;

  DEBUGASSERT(devname && lower);

  /* Allocate a new djoystick driver instance */

  priv = (FAR struct djoy_upperhalf_s *)
    kmm_zalloc(sizeof(struct djoy_upperhalf_s));

  if (!priv)
    {
      ivdbg("ERROR: Failed to allocate device structure\n");
      return -ENOMEM;
    }

  /* Make sure that all djoystick interrupts are disabled */

  DEBUGASSERT(lower->dl_enable);
  lower->dl_enable(lower, 0, 0, NULL, NULL);

  /* Initialize the new djoystick driver instance */

  priv->du_lower = lower;
  sem_init(&priv->du_exclsem, 0, 1);

  DEBUGASSERT(lower->dl_sample);
  priv->du_sample = lower->dl_sample(lower);

  /* And register the djoystick driver */

  ret = register_driver(devname, &djoy_fops, 0666, NULL);
  if (ret < 0)
    {
      ivdbg("ERROR: register_driver failed: %d\n", ret);
      sem_destroy(&priv->du_exclsem);
      kmm_free(priv);
    }

  return ret;
}
