/****************************************************************************
 * arch/xtensa/src/esp32/esp32_rt_timer.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this args for additional information regarding copyright ownership.  The
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
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/irq.h>
#include <nuttx/kthread.h>
#include <nuttx/kmalloc.h>
#include <nuttx/semaphore.h>
#include <nuttx/spinlock.h>

#include "hardware/esp32_soc.h"
#include "esp32_tim.h"
#include "esp32_rt_timer.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifdef CONFIG_SCHED_HPWORKPRIORITY
#  if CONFIG_ESP32_RT_TIMER_TASK_PRIORITY >= CONFIG_SCHED_HPWORKPRIORITY
#    error "RT timer priority should be smaller that high-prio workqueue"
#  endif
#endif

#define RT_TIMER_TASK_NAME        CONFIG_ESP32_RT_TIMER_TASK_NAME
#define RT_TIMER_TASK_PRIORITY    CONFIG_ESP32_RT_TIMER_TASK_PRIORITY
#define RT_TIMER_TASK_STACK_SIZE  CONFIG_ESP32_RT_TIMER_TASK_STACK_SIZE

#define ESP32_TIMER_PRESCALER     (APB_CLK_FREQ / (1000 * 1000))
#define ESP32_RT_TIMER            0 /* Timer 0 */

/****************************************************************************
 * Private Data
 ****************************************************************************/

static int s_pid;

static sem_t s_toutsem;

static struct list_node s_runlist;
static struct list_node s_toutlist;

static spinlock_t g_lock;
static struct esp32_tim_dev_s *s_esp32_tim_dev;

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: start_rt_timer
 *
 * Description:
 *   Start the timer by inserting it into the running list and reset the
 *   hardware timer alarm value if this timer is at the head of the list.
 *
 * Input Parameters:
 *   timer - RT timer pointer
 *   timeout - Timeout value
 *   repeat  - repeat mode (true: enabled, false: disabled)
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

static void start_rt_timer(struct rt_timer_s *timer,
                           uint64_t timeout,
                           bool repeat)
{
  irqstate_t flags;
  struct rt_timer_s *p;
  bool inserted = false;
  uint64_t counter;
  struct esp32_tim_dev_s *tim = s_esp32_tim_dev;

  flags = spin_lock_irqsave(&g_lock);

  /* Only idle timer can be started */

  if (timer->state == RT_TIMER_IDLE)
    {
      /* Calculate the timer's alarm value */

      ESP32_TIM_GETCTR(tim, &counter);
      timer->timeout = timeout;
      timer->alarm = timer->timeout + counter;

      if (repeat)
        {
          timer->flags |= RT_TIMER_REPEAT;
        }
      else
        {
          timer->flags &= ~RT_TIMER_REPEAT;
        }

      /* Scan the timer list and insert the new timer into previous
       * node of timer whose alarm value is larger than new one
       */

      list_for_every_entry(&s_runlist, p, struct rt_timer_s, list)
        {
          if (p->alarm > timer->alarm)
            {
              list_add_before(&p->list, &timer->list);
              inserted = true;
              break;
            }
        }

      /* If we didn't find a larger one, insert the new timer at the tail
       * of the list.
       */

      if (!inserted)
        {
          list_add_tail(&s_runlist, &timer->list);
        }

      timer->state = RT_TIMER_READY;

      /* If this timer is at the head of the list */

      if (timer == container_of(s_runlist.next, struct rt_timer_s, list))
        {
          /* Reset the hardware timer alarm */

          ESP32_TIM_SETALRVL(tim, timer->alarm);
          ESP32_TIM_SETALRM(tim, true);
        }
    }

  spin_unlock_irqrestore(&g_lock, flags);
}

/****************************************************************************
 * Name: stop_rt_timer
 *
 * Description:
 *   Stop the timer by removing it from the running list and reset the
 *   hardware timer alarm value if this timer is at the head of list.
 *
 * Input Parameters:
 *   timer - RT timer pointer
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

static void stop_rt_timer(struct rt_timer_s *timer)
{
  irqstate_t flags;
  bool ishead;
  struct rt_timer_s *next_timer;
  uint64_t alarm;
  struct esp32_tim_dev_s *tim = s_esp32_tim_dev;

  flags = spin_lock_irqsave(&g_lock);

  /* "start" function can set the timer's repeat flag, and function "stop"
   * should remove this flag.
   */

  timer->flags &= ~RT_TIMER_REPEAT;

  /* Only timers in "ready" state can be stopped */

  if (timer->state == RT_TIMER_READY)
    {
      /* Check if the timer is at the head of the list */

      if (timer == container_of(s_runlist.next, struct rt_timer_s, list))
        {
          ishead = true;
        }
      else
        {
          ishead = false;
        }

      list_delete(&timer->list);
      timer->state = RT_TIMER_IDLE;

      /* If the timer is at the head of the list */

      if (ishead)
        {
          if (!list_is_empty(&s_runlist))
            {
              /* Set the value from the next timer as the new hardware timer
               * alarm value
               */

              next_timer = container_of(s_runlist.next,
                                        struct rt_timer_s,
                                        list);
              alarm = next_timer->alarm;

              ESP32_TIM_SETALRVL(tim, alarm);
              ESP32_TIM_SETALRM(tim, true);
            }
        }
    }

  spin_unlock_irqrestore(&g_lock, flags);
}

/****************************************************************************
 * Name: delete_rt_timer
 *
 * Description:
 *   Delete the timer by removing it from the list, then set the timer's
 *   state to "RT_TIMER_DELETE" and finally insert it into the work list
 *   to let the rt-timer's thread to delete it and free the resources.
 *
 * Input Parameters:
 *   timer - RT timer pointer
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

static void delete_rt_timer(struct rt_timer_s *timer)
{
  irqstate_t flags;

  flags = spin_lock_irqsave(&g_lock);

  if (timer->state == RT_TIMER_READY)
    {
      stop_rt_timer(timer);
    }
  else if (timer->state == RT_TIMER_TIMEOUT)
    {
      list_delete(&timer->list);
    }
  else if (timer->state == RT_TIMER_DELETE)
    {
      goto exit;
    }

  list_add_after(&s_toutlist, &timer->list);
  timer->state = RT_TIMER_DELETE;

exit:
  spin_unlock_irqrestore(&g_lock, flags);
}

/****************************************************************************
 * Name: rt_timer_thread
 *
 * Description:
 *   RT timer working thread: Waits for a timeout semaphore, scans
 *   the timeout list and processes all the timers in the list.
 *
 * Input Parameters:
 *   argc - Not used
 *   argv - Not used
 *
 * Returned Value:
 *   0.
 *
 ****************************************************************************/

static int rt_timer_thread(int argc, char *argv[])
{
  int ret;
  irqstate_t flags;
  struct rt_timer_s *timer;
  enum rt_timer_state_e raw_state;

  while (1)
    {
      /* Waiting for all the timers to time out */

      ret = nxsem_wait(&s_toutsem);
      if (ret)
        {
          tmrerr("ERROR: Wait s_toutsem error=%d\n", ret);
          assert(0);
        }

      flags = spin_lock_irqsave(&g_lock);

      /* Process all the timers in the list */

      while (!list_is_empty(&s_toutlist))
        {
          /* Get the first timer in the list */

          timer = container_of(s_toutlist.next, struct rt_timer_s, list);

          /* Cache the raw state to decide how to deal with this timer */

          raw_state = timer->state;

          /* Delete the timer from list */

          list_delete(&timer->list);

          /* Set timer's state to idle so it can be restarted by the user. */

          timer->state = RT_TIMER_IDLE;

          spin_unlock_irqrestore(&g_lock, flags);

          if (raw_state == RT_TIMER_TIMEOUT)
            {
              timer->callback(timer->arg);
            }
          else if (raw_state == RT_TIMER_DELETE)
            {
              kmm_free(timer);
            }

          /* Enter critical section for next scanning list */

          flags = spin_lock_irqsave(&g_lock);

          if (raw_state == RT_TIMER_TIMEOUT)
            {
              /* Check if the timer is in "repeat" mode */

              if (timer->flags & RT_TIMER_REPEAT)
                {
                  start_rt_timer(timer, timer->timeout, true);
                }
            }
        }

      spin_unlock_irqrestore(&g_lock, flags);
    }

  return 0;
}

/****************************************************************************
 * Name: rt_timer_isr
 *
 * Description:
 *   Hardware timer interrupt service routine.
 *
 * Input Parameters:
 *   irq     - Not used
 *   context - Not used
 *   arg     - Not used
 *
 * Returned Value:
 *   0.
 *
 ****************************************************************************/

static int rt_timer_isr(int irq, void *context, void *arg)
{
  irqstate_t flags;
  struct rt_timer_s *timer;
  uint64_t alarm;
  uint64_t counter;
  struct esp32_tim_dev_s *tim = s_esp32_tim_dev;

  /* Clear interrupt register status */

  ESP32_TIM_ACKINT(tim);

  /* Wake up the thread to process timed-out timers */

  nxsem_post(&s_toutsem);

  flags = spin_lock_irqsave(&g_lock);

  /* Check if there is a timer running */

  if (!list_is_empty(&s_runlist))
    {
      /**
       * When stop/delete timer, in the same time the hardware timer
       * interrupt triggers, function "stop/delete" remove the timer
       * from running list, so the 1st timer is not which triggers.
       */

      timer = container_of(s_runlist.next, struct rt_timer_s, list);
      ESP32_TIM_GETCTR(tim, &counter);
      if (timer->alarm <= counter)
        {
          /* Remove the first timer in the running list and add it to
           * the timeout list.
           *
           * Set the timer's state to be RT_TIMER_TIMEOUT to avoid
           * other operations.
           */

          list_delete(&timer->list);
          timer->state = RT_TIMER_TIMEOUT;
          list_add_after(&s_toutlist, &timer->list);

          /* Check if there is a timer running */

          if (!list_is_empty(&s_runlist))
            {
              /* Reset hardware timer alarm with next timer's alarm value */

              timer = container_of(s_runlist.next, struct rt_timer_s, list);
              alarm = timer->alarm;

              ESP32_TIM_SETALRVL(tim, alarm);
              ESP32_TIM_SETALRM(tim, true);
            }
        }
    }

  spin_unlock_irqrestore(&g_lock, flags);

  return 0;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: rt_timer_create
 *
 * Description:
 *   Create a RT timer from the provided arguments.
 *
 * Input Parameters:
 *   args         - Input RT timer creation arguments
 *   timer_handle - Output RT timer handle pointer
 *
 * Returned Value:
 *   0 is returned on success. Otherwise, a negated errno value is returned.
 *
 ****************************************************************************/

int rt_timer_create(const struct rt_timer_args_s *args,
                    struct rt_timer_s **timer_handle)
{
  struct rt_timer_s *timer;

  timer = (struct rt_timer_s *)kmm_malloc(sizeof(*timer));
  if (!timer)
    {
      tmrerr("ERROR: Failed to allocate %d bytes\n", sizeof(*timer));
      return -ENOMEM;
    }

  timer->callback = args->callback;
  timer->arg      = args->arg;
  timer->flags    = RT_TIMER_NOFLAGS;
  timer->state    = RT_TIMER_IDLE;
  list_initialize(&timer->list);

  *timer_handle = timer;

  return 0;
}

/****************************************************************************
 * Name: rt_timer_start
 *
 * Description:
 *   Start the RT timer.
 *
 * Input Parameters:
 *   timer   - RT timer pointer
 *   timeout - Timeout value
 *   repeat  - repeat mode (true: enabled, false: disabled)
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void rt_timer_start(struct rt_timer_s *timer,
                    uint64_t timeout,
                    bool repeat)
{
  stop_rt_timer(timer);

  start_rt_timer(timer, timeout, repeat);
}

/****************************************************************************
 * Name: rt_timer_stop
 *
 * Description:
 *   Stop the RT timer.
 *
 * Input Parameters:
 *   timer - RT timer pointer
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void rt_timer_stop(struct rt_timer_s *timer)
{
  stop_rt_timer(timer);
}

/****************************************************************************
 * Name: rt_timer_delete
 *
 * Description:
 *   Stop and delete RT timer.
 *
 * Input Parameters:
 *   timer - RT timer pointer
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

void rt_timer_delete(struct rt_timer_s *timer)
{
  delete_rt_timer(timer);
}

/****************************************************************************
 * Name: rt_timer_time_us
 *
 * Description:
 *   Get time of the RT timer in microseconds.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Time of the RT timer in microseconds.
 *
 ****************************************************************************/

uint64_t IRAM_ATTR rt_timer_time_us(void)
{
  uint64_t counter;
  struct esp32_tim_dev_s *tim = s_esp32_tim_dev;

  ESP32_TIM_GETCTR(tim, &counter);

  return counter;
}

/****************************************************************************
 * Name: rt_timer_get_alarm
 *
 * Description:
 *   Get the timestamp when the next timeout is expected to occur.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Timestamp of the nearest timer event in microseconds.
 *
 ****************************************************************************/

uint64_t IRAM_ATTR rt_timer_get_alarm(void)
{
  irqstate_t flags;
  uint64_t counter;
  struct esp32_tim_dev_s *tim = s_esp32_tim_dev;
  uint64_t alarm_value = 0;

  flags = spin_lock_irqsave(&g_lock);

  ESP32_TIM_GETCTR(tim, &counter);
  ESP32_TIM_GETALRVL(tim, &alarm_value);

  if (alarm_value <= counter)
    {
      alarm_value = 0;
    }
  else
    {
      alarm_value -= counter;
    }

  spin_unlock_irqrestore(&g_lock, flags);

  return alarm_value;
}

/****************************************************************************
 * Name: rt_timer_calibration
 *
 * Description:
 *   Adjust current RT timer by a certain value.
 *
 * Input Parameters:
 *   time_us - adjustment to apply to the RT timer in microseconds.
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

void IRAM_ATTR rt_timer_calibration(uint64_t time_us)
{
  uint64_t counter;
  struct esp32_tim_dev_s *tim = s_esp32_tim_dev;
  irqstate_t flags;

  flags = spin_lock_irqsave(&g_lock);

  ESP32_TIM_GETCTR(tim, &counter);
  counter += time_us;
  ESP32_TIM_SETCTR(tim, counter);
  ESP32_TIM_RLD_NOW(tim);

  spin_unlock_irqrestore(&g_lock, flags);
}

/****************************************************************************
 * Name: esp32_rt_timer_init
 *
 * Description:
 *   Initialize ESP32 RT timer.
 *
 * Input Parameters:
 *   timer_no - Hardware timer number
 *
 * Returned Value:
 *   0 is returned on success. Otherwise, a negated errno value is returned.
 *
 ****************************************************************************/

int esp32_rt_timer_init(void)
{
  int pid;
  irqstate_t flags;
  struct esp32_tim_dev_s *tim;

  tim = esp32_tim_init(ESP32_RT_TIMER);
  if (!tim)
    {
      tmrerr("ERROR: Failed to initialize ESP32 timer0\n");
      return -EINVAL;
    }

  nxsem_init(&s_toutsem, 0, 0);

  pid = kthread_create(RT_TIMER_TASK_NAME,
                       RT_TIMER_TASK_PRIORITY,
                       RT_TIMER_TASK_STACK_SIZE,
                       rt_timer_thread,
                       NULL);
  if (pid < 0)
    {
      tmrerr("ERROR: Failed to create RT timer task error=%d\n", pid);
      esp32_tim_deinit(tim);
      return pid;
    }

  list_initialize(&s_runlist);
  list_initialize(&s_toutlist);

  s_esp32_tim_dev = tim;
  s_pid = pid;

  flags = spin_lock_irqsave(&g_lock);

  /* ESP32 hardware timer configuration:
   *   - 1 counter = 1us
   *   - Counter increase mode
   *   - Non-reload mode
   */

  ESP32_TIM_SETPRE(tim, ESP32_TIMER_PRESCALER);
  ESP32_TIM_SETMODE(tim, ESP32_TIM_MODE_UP);
  ESP32_TIM_SETARLD(tim, false);
  ESP32_TIM_CLEAR(tim);

  ESP32_TIM_SETISR(tim, rt_timer_isr, NULL);
  ESP32_TIM_ENABLEINT(tim);

  ESP32_TIM_START(tim);

  spin_unlock_irqrestore(&g_lock, flags);

  return 0;
}

/****************************************************************************
 * Name: esp32_rt_timer_deinit
 *
 * Description:
 *   Deinitialize ESP32 RT timer.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None.
 *
 ****************************************************************************/

void esp32_rt_timer_deinit(void)
{
  irqstate_t flags;

  flags = spin_lock_irqsave(&g_lock);

  ESP32_TIM_STOP(s_esp32_tim_dev);
  esp32_tim_deinit(s_esp32_tim_dev);
  s_esp32_tim_dev = NULL;

  spin_unlock_irqrestore(&g_lock, flags);

  kthread_delete(s_pid);
  nxsem_destroy(&s_toutsem);
}

