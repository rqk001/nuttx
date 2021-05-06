/****************************************************************************
 * arch/xtensa/src/esp32/esp32_serial.c
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
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <debug.h>

#ifdef CONFIG_SERIAL_TERMIOS
#  include <termios.h>
#endif

#include <nuttx/irq.h>
#include <nuttx/arch.h>
#include <nuttx/fs/ioctl.h>
#include <nuttx/serial/serial.h>

#include <arch/board/board.h>

#include "xtensa.h"
#include "hardware/esp32_soc.h"
#include "hardware/esp32_iomux.h"
#include "hardware/esp32_gpio_sigmap.h"
#include "hardware/esp32_uart.h"
#include "esp32_config.h"
#include "esp32_gpio.h"
#include "esp32_cpuint.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifdef USE_SERIALDRIVER

/* Which UART with be tty0/console and which tty1-2? */

/* First pick the console and ttys0.  This could be any of UART0-5 */

#if defined(CONFIG_UART0_SERIAL_CONSOLE)
#    define CONSOLE_DEV         g_uart0port  /* UART0 is console */
#    define TTYS0_DEV           g_uart0port  /* UART0 is ttyS0 */
#    define UART0_ASSIGNED      1
#elif defined(CONFIG_UART1_SERIAL_CONSOLE)
#    define CONSOLE_DEV         g_uart1port  /* UART1 is console */
#    define TTYS0_DEV           g_uart1port  /* UART1 is ttyS0 */
#    define UART1_ASSIGNED      1
#elif defined(CONFIG_UART2_SERIAL_CONSOLE)
#    define CONSOLE_DEV         g_uart2port  /* UART2 is console */
#    define TTYS0_DEV           g_uart2port  /* UART2 is ttyS0 */
#    define UART2_ASSIGNED      1
#else
#  undef CONSOLE_DEV                         /* No console */
#  if defined(CONFIG_ESP32_UART0)
#    define TTYS0_DEV           g_uart0port  /* UART0 is ttyS0 */
#    define UART0_ASSIGNED      1
#  elif defined(CONFIG_ESP32_UART1)
#    define TTYS0_DEV           g_uart1port  /* UART1 is ttyS0 */
#    define UART1_ASSIGNED      1
#  elif defined(CONFIG_ESP32_UART2)
#    define TTYS0_DEV           g_uart2port  /* UART2 is ttyS0 */
#    define UART2_ASSIGNED      1
#  endif
#endif

/* Pick ttys1.  This could be any of UART0-2 excluding the console
 * UART.
 */

#if defined(CONFIG_ESP32_UART0) && !defined(UART0_ASSIGNED)
#  define TTYS1_DEV           g_uart0port  /* UART0 is ttyS1 */
#  define UART0_ASSIGNED      1
#elif defined(CONFIG_ESP32_UART1) && !defined(UART1_ASSIGNED)
#  define TTYS1_DEV           g_uart1port  /* UART1 is ttyS1 */
#  define UART1_ASSIGNED      1
#elif defined(CONFIG_ESP32_UART2) && !defined(UART2_ASSIGNED)
#  define TTYS1_DEV           g_uart2port  /* UART2 is ttyS1 */
#  define UART2_ASSIGNED      1
#endif

/* Pick ttys2.  This could be one of UART1-2. It can't be UART0
 * because that was either assigned as ttyS0 or ttys1.  One of these
 * could also be the console.
 */

#if defined(CONFIG_ESP32_UART1) && !defined(UART1_ASSIGNED)
#  define TTYS2_DEV           g_uart1port  /* UART1 is ttyS2 */
#  define UART1_ASSIGNED      1
#elif defined(CONFIG_ESP32_UART2) && !defined(UART2_ASSIGNED)
#  define TTYS2_DEV           g_uart2port  /* UART2 is ttyS2 */
#  define UART2_ASSIGNED      1
#endif

/* UART source clock for BAUD generation */

#define UART_CLK_FREQ         APB_CLK_FREQ

/****************************************************************************
 * Private Types
 ****************************************************************************/

/* Constant properties of the UART.  Other configuration setting may be
 * changeable via Termios IOCTL calls.
 */

struct esp32_config_s
{
  const uint8_t id;             /* UART id */
  uint8_t  periph;              /* UART peripheral ID */
  uint8_t  irq;                 /* IRQ number assigned to the peripheral */
  uint8_t  txpin;               /* Tx pin number (0-39) */
  uint8_t  rxpin;               /* Rx pin number (0-39) */
  uint8_t  txsig;               /* Tx signal */
  uint8_t  rxsig;               /* Rx signal */
#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
  uint8_t  rtspin;              /* RTS pin number (0-39) */
  uint8_t  ctspin;              /* CTS pin number (0-39) */
  uint8_t  rtssig;              /* RTS signal */
  uint8_t  ctssig;              /* CTS signal */
#endif
};

/* Current state of the UART */

struct esp32_dev_s
{
  const struct esp32_config_s *config; /* Constant configuration */
  uint32_t baud;                       /* Configured baud */
  uint32_t status;                     /* Saved status bits */
  int      cpuint;                     /* CPU interrupt assigned to this UART */
  uint8_t  parity;                     /* 0=none, 1=odd, 2=even */
  uint8_t  bits;                       /* Number of bits (5-9) */
  bool     stopbits2;                  /* true: Configure with 2 stop bits instead of 1 */
#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
  bool     flowc;                      /* Input flow control (RTS) enabled */
#endif
};

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static int  esp32_setup(struct uart_dev_s *dev);
static void esp32_shutdown(struct uart_dev_s *dev);
static int  esp32_attach(struct uart_dev_s *dev);
static void esp32_detach(struct uart_dev_s *dev);
static int  esp32_interrupt(int cpuint, void *context, FAR void *arg);
static int  esp32_ioctl(struct file *filep, int cmd, unsigned long arg);
static int  esp32_receive(struct uart_dev_s *dev, unsigned int *status);
static void esp32_rxint(struct uart_dev_s *dev, bool enable);
static bool esp32_rxavailable(struct uart_dev_s *dev);
static void esp32_send(struct uart_dev_s *dev, int ch);
static void esp32_txint(struct uart_dev_s *dev, bool enable);
static bool esp32_txready(struct uart_dev_s *dev);
static bool esp32_txempty(struct uart_dev_s *dev);

/****************************************************************************
 * Private Data
 ****************************************************************************/

#define UART_TX_FIFO_SIZE        128
#define UART_RX_FIFO_FULL_THRHD  112
#define UART_RX_TOUT_THRHD_VALUE 0x02

static const struct uart_ops_s g_uart_ops =
{
  .setup          = esp32_setup,
  .shutdown       = esp32_shutdown,
  .attach         = esp32_attach,
  .detach         = esp32_detach,
  .ioctl          = esp32_ioctl,
  .receive        = esp32_receive,
  .rxint          = esp32_rxint,
  .rxavailable    = esp32_rxavailable,
#ifdef CONFIG_SERIAL_IFLOWCONTROL
  .rxflowcontrol  = NULL,
#endif
  .send           = esp32_send,
  .txint          = esp32_txint,
  .txready        = esp32_txready,
  .txempty        = esp32_txempty,
};

/* I/O buffers */

#ifdef CONFIG_ESP32_UART0
static char g_uart0rxbuffer[CONFIG_UART0_RXBUFSIZE];
static char g_uart0txbuffer[CONFIG_UART0_TXBUFSIZE];
#endif
#ifdef CONFIG_ESP32_UART1
static char g_uart1rxbuffer[CONFIG_UART1_RXBUFSIZE];
static char g_uart1txbuffer[CONFIG_UART1_TXBUFSIZE];
#endif
#ifdef CONFIG_ESP32_UART2
static char g_uart2rxbuffer[CONFIG_UART2_RXBUFSIZE];
static char g_uart2txbuffer[CONFIG_UART2_TXBUFSIZE];
#endif

/* This describes the state of the UART0 port. */

#ifdef CONFIG_ESP32_UART0
static const struct esp32_config_s g_uart0config =
{
  .id             = 0,
  .periph         = ESP32_PERIPH_UART,
  .irq            = ESP32_IRQ_UART,
  .txpin          = CONFIG_ESP32_UART0_TXPIN,
  .rxpin          = CONFIG_ESP32_UART0_RXPIN,
  .txsig          = U0TXD_OUT_IDX,
  .rxsig          = U0RXD_IN_IDX,
#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
  .rtspin         = CONFIG_ESP32_UART0_RTSPIN,
  .ctspin         = CONFIG_ESP32_UART0_CTSPIN,
  .rtssig         = U0RTS_OUT_IDX,
  .ctssig         = U0CTS_IN_IDX,
#endif
};

static struct esp32_dev_s g_uart0priv =
{
  .config         = &g_uart0config,
  .baud           = CONFIG_UART0_BAUD,
  .parity         = CONFIG_UART0_PARITY,
  .bits           = CONFIG_UART0_BITS,
  .stopbits2      = CONFIG_UART0_2STOP,
};

static uart_dev_t g_uart0port =
{
  .recv     =
  {
    .size   = CONFIG_UART0_RXBUFSIZE,
    .buffer = g_uart0rxbuffer,
  },
  .xmit     =
  {
    .size   = CONFIG_UART0_TXBUFSIZE,
    .buffer = g_uart0txbuffer,
  },
  .ops      = &g_uart_ops,
  .priv     = &g_uart0priv,
};
#endif

/* This describes the state of the UART1 port. */

#ifdef CONFIG_ESP32_UART1
static const struct esp32_config_s g_uart1config =
{
  .id             = 1,
  .periph         = ESP32_PERIPH_UART1,
  .irq            = ESP32_IRQ_UART1,
  .txpin          = CONFIG_ESP32_UART1_TXPIN,
  .rxpin          = CONFIG_ESP32_UART1_RXPIN,
  .txsig          = U1TXD_OUT_IDX,
  .rxsig          = U1RXD_IN_IDX,
#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
  .rtspin         = CONFIG_ESP32_UART1_RTSPIN,
  .ctspin         = CONFIG_ESP32_UART1_CTSPIN,
  .rtssig         = U1RTS_OUT_IDX,
  .ctssig         = U1CTS_IN_IDX,
#endif
};

static struct esp32_dev_s g_uart1priv =
{
  .config         = &g_uart1config,
  .baud           = CONFIG_UART1_BAUD,
  .parity         = CONFIG_UART1_PARITY,
  .bits           = CONFIG_UART1_BITS,
  .stopbits2      = CONFIG_UART1_2STOP,
};

static uart_dev_t g_uart1port =
{
  .recv     =
  {
    .size   = CONFIG_UART1_RXBUFSIZE,
    .buffer = g_uart1rxbuffer,
  },
  .xmit     =
  {
    .size   = CONFIG_UART1_TXBUFSIZE,
    .buffer = g_uart1txbuffer,
  },
  .ops      = &g_uart_ops,
  .priv     = &g_uart1priv,
};
#endif

/* This describes the state of the UART2 port. */

#ifdef CONFIG_ESP32_UART2
static const struct esp32_config_s g_uart2config =
{
  .id             = 2,
  .periph         = ESP32_PERIPH_UART2,
  .irq            = ESP32_IRQ_UART2,
  .txpin          = CONFIG_ESP32_UART2_TXPIN,
  .rxpin          = CONFIG_ESP32_UART2_RXPIN,
  .txsig          = U2TXD_OUT_IDX,
  .rxsig          = U2RXD_IN_IDX,
#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
  .rtspin         = CONFIG_ESP32_UART2_RTSPIN,
  .ctspin         = CONFIG_ESP32_UART2_CTSPIN,
  .rtssig         = U2RTS_OUT_IDX,
  .ctssig         = U2CTS_IN_IDX,
#endif
};

static struct esp32_dev_s g_uart2priv =
{
  .config         = &g_uart2config,
  .baud           = CONFIG_UART2_BAUD,
  .parity         = CONFIG_UART2_PARITY,
  .bits           = CONFIG_UART2_BITS,
  .stopbits2      = CONFIG_UART2_2STOP,
};

static uart_dev_t g_uart2port =
{
  .recv     =
  {
    .size   = CONFIG_UART2_RXBUFSIZE,
    .buffer = g_uart2rxbuffer,
  },
  .xmit     =
  {
    .size   = CONFIG_UART2_TXBUFSIZE,
    .buffer = g_uart2txbuffer,
  },
  .ops      = &g_uart_ops,
  .priv     = &g_uart2priv,
};
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/
#ifndef CONFIG_SUPPRESS_UART_CONFIG
/****************************************************************************
 * Name: esp32_reset_rx_fifo
 *
 * Description:
 *   Resets the RX FIFO.
 *   NOTE: We can not use rxfifo_rst to reset the hardware RX FIFO.
 *
 * Parameters:
 *   priv        -  Pointer to the serial driver struct.
 *
 ****************************************************************************/

static void esp32_reset_rx_fifo(struct esp32_dev_s *priv)
{
  uint32_t rx_status_reg = getreg32(UART_STATUS_REG(priv->config->id));
  uint32_t fifo_cnt = REG_MASK(rx_status_reg, UART_RXFIFO_CNT);
  uint32_t mem_rx_status_reg = getreg32(UART_MEM_RX_STATUS_REG
                                        (priv->config->id));
  uint32_t rd_address = REG_MASK(mem_rx_status_reg, UART_RD_ADDRESS);
  uint32_t wr_address = REG_MASK(mem_rx_status_reg, UART_WR_ADDRESS);

  while ((fifo_cnt != 0) || (rd_address != wr_address))
    {
      getreg32(DR_UART_FIFO_REG(priv->config->id));

      rx_status_reg = getreg32(UART_STATUS_REG(priv->config->id));
      fifo_cnt = REG_MASK(rx_status_reg, UART_RXFIFO_CNT);
      mem_rx_status_reg = getreg32(UART_MEM_RX_STATUS_REG(priv->config->id));
      rd_address = REG_MASK(mem_rx_status_reg, UART_RD_ADDRESS);
      wr_address = REG_MASK(mem_rx_status_reg, UART_WR_ADDRESS);
    }
}

/****************************************************************************
 * Name: esp32_reset_tx_fifo
 *
 * Description:
 *   Resets the TX FIFO.
 *
 * Parameters:
 *   priv        -  Pointer to the serial driver struct.
 *
 ****************************************************************************/

static void esp32_reset_tx_fifo(struct esp32_dev_s *priv)
{
  modifyreg32(UART_CONF0_REG(priv->config->id), 0, UART_TXFIFO_RST_M);
  modifyreg32(UART_CONF0_REG(priv->config->id), UART_TXFIFO_RST_M, 0);
}
#endif

/****************************************************************************
 * Name: esp32_get_rx_fifo_len
 *
 * Description:
 *   Get the real value on rx fixo.
 *   RX_FIFO_CNT shouldn't be used alone accordingly to:
 *   https://www.espressif.com/sites/default/files/documentation/eco_
 *   and_workarounds_for_bugs_in_esp32_en.pdf.
 *   So, some arithmetic with the read and write RX FIFO pointers are
 *   necessary.
 *
 * Parameters:
 *   priv        -  Pointer to the serial driver struct.
 *
 * Return:
 *   The number of bytes in RX fifo.
 *
 ****************************************************************************/

static uint32_t esp32_get_rx_fifo_len(struct esp32_dev_s *priv)
{
  uint32_t rd_address;
  uint32_t wr_address;
  uint32_t fifo_cnt;
  uint32_t mem_rx_status_reg;
  uint32_t rx_status_reg;
  uint32_t len;

  mem_rx_status_reg = getreg32(UART_MEM_RX_STATUS_REG(priv->config->id));
  rd_address = REG_MASK(mem_rx_status_reg, UART_RD_ADDRESS);
  wr_address = REG_MASK(mem_rx_status_reg, UART_WR_ADDRESS);
  rx_status_reg = getreg32(UART_STATUS_REG(priv->config->id));
  fifo_cnt = REG_MASK(rx_status_reg, UART_RXFIFO_CNT);

  if (wr_address > rd_address)
    {
      len = wr_address - rd_address;
    }
  else if (wr_address < rd_address)
    {
      len = (wr_address + 128) - rd_address;
    }
  else
    {
      len = fifo_cnt > 0 ? 128 : 0;
    }

  return len;
}

/****************************************************************************
 * Name: esp32_restoreuartint
 ****************************************************************************/

static inline void esp32_restoreuartint(struct esp32_dev_s *priv,
                                        uint32_t intena)
{
  /* Restore the previous interrupt state
   * (assuming all interrupts disabled)
   */

  putreg32(intena, UART_INT_ENA_REG(priv->config->id));
}

/****************************************************************************
 * Name: esp32_disableallints
 ****************************************************************************/

static void esp32_disableallints(struct esp32_dev_s *priv, uint32_t *intena)
{
  irqstate_t flags;

  /* The following must be atomic */

  flags = enter_critical_section();

  if (intena)
    {
      /* Return the current interrupt mask */

      *intena = getreg32(UART_INT_ENA_REG(priv->config->id));
    }

  /* Disable all interrupts */

  putreg32(0, UART_INT_ENA_REG(priv->config->id));
  leave_critical_section(flags);
}

/****************************************************************************
 * Name: esp32_setup
 *
 * Description:
 *   Configure the UART baud, bits, parity, etc. This method is called the
 *   first time that the serial port is opened.
 *
 ****************************************************************************/

static int esp32_setup(struct uart_dev_s *dev)
{
#ifndef CONFIG_SUPPRESS_UART_CONFIG
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;
  uint32_t clkdiv;
  uint32_t regval;
  uint32_t conf0;

  /* Note: The logic here depends on the fact that that the UART module
   * was enabled and the pins were configured in esp32_lowsetup().
   */

  /* The shutdown method will put the UART in a known, disabled state */

  esp32_shutdown(dev);

  /* Set up the CONF0 register. */

  conf0 = UART_TICK_REF_ALWAYS_ON;

#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
  /* Check if flow control is enabled */

  if (priv->flowc)
    {
      /* Enable hardware flow control */

      conf0 |= UART_TX_FLOW_EN;
    }
#endif

  /* OR in settings for the selected number of bits */

  if (priv->bits == 5)
    {
      /* 0=5 bits */
    }
  else if (priv->bits == 6)
    {
      conf0 |= (1 << UART_BIT_NUM_S);  /* 1=6 bits */
    }
  else if (priv->bits == 7)
    {
      conf0 |= (2 << UART_BIT_NUM_S);  /* 2=7 bits */
    }
  else /* if (priv->bits == 8) */
    {
      conf0 |= (3 << UART_BIT_NUM_S);  /* 3=8 bits */
    }

  /* OR in settings for the selected parity */

  if (priv->parity == 1)
    {
      conf0 |= UART_PARITY_EN;
    }
  else if (priv->parity == 2)
    {
      conf0 |= UART_PARITY_EN | UART_PARITY;
    }

  /* OR in settings for the number of stop bits */

  if (priv->stopbits2)
    {
      conf0 |= 2 << UART_STOP_BIT_NUM_S;
    }
  else
    {
      conf0 |= 1 << UART_STOP_BIT_NUM_S;
    }

  /* Configure the UART BAUD */

  clkdiv  = (UART_CLK_FREQ << 4) / priv->baud;

  regval  = (clkdiv >> 4) << UART_CLKDIV_S;
  regval |= (clkdiv & 15) << UART_CLKDIV_FRAG_S;
  putreg32(regval, UART_CLKDIV_REG(priv->config->id));

  /* Enable RX and error interrupts.  Clear and pending interrtupt */

  regval = UART_RXFIFO_FULL_INT_ENA | UART_FRM_ERR_INT_ENA |
           UART_RXFIFO_TOUT_INT_ENA;
  putreg32(regval, UART_INT_ENA_REG(priv->config->id));

  putreg32(UINT32_MAX, UART_INT_CLR_REG(priv->config->id));

  /* Reset the RX and TX FIFO */

  esp32_reset_rx_fifo(priv);
  esp32_reset_tx_fifo(priv);

  /* Configure and enable the UART */

  putreg32(conf0, UART_CONF0_REG(priv->config->id));
  regval = VALUE_TO_FIELD(UART_RX_FIFO_FULL_THRHD, UART_RXFIFO_FULL_THRHD) |
           VALUE_TO_FIELD(UART_RX_TOUT_THRHD_VALUE, UART_RX_TOUT_THRHD) |
           UART_RX_TOUT_EN;
  putreg32(regval, UART_CONF1_REG(priv->config->id));
#endif

  return OK;
}

/****************************************************************************
 * Name: esp32_shutdown
 *
 * Description:
 *   Disable the UART.  This method is called when the serial port is
 *   closed.  It is assumed that esp32_detach was called earlier in the
 *   shutdown sequence.
 *
 ****************************************************************************/

static void esp32_shutdown(struct uart_dev_s *dev)
{
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;
  uint32_t status;

  /* Wait for outgoing FIFO to clear.   The ROM bootloader does not flush
   * the FIFO before handing over to user code, so some of this output is
   * not currently seen when the UART is reconfigured in early stages of
   * startup.
   */

  do
    {
      status = getreg32(UART_STATUS_REG(priv->config->id));
    }
  while ((status & UART_TXFIFO_CNT_M) != 0);

  /* Disable all UART interrupts */

  esp32_disableallints(priv, NULL);

  /* Unconfigure and disable the UART */

  putreg32(0, UART_CONF0_REG(priv->config->id));
  putreg32(0, UART_CONF1_REG(priv->config->id));

  putreg32(0, UART_INT_ENA_REG(priv->config->id));
  putreg32(UINT32_MAX, UART_INT_CLR_REG(priv->config->id));
}

/****************************************************************************
 * Name: esp32_attach
 *
 * Description:
 *   Configure the UART to operation in interrupt driven mode.  This method
 *   is called when the serial port is opened.  Normally, this is just after
 *   the the setup() method is called, however, the serial console may
 *   operate in a non-interrupt driven mode during the boot phase.
 *
 *   RX and TX interrupts are not enabled when by the attach method (unless
 *   the hardware supports multiple levels of interrupt enabling).  The RX
 *   and TX interrupts are not enabled until the txint() and rxint() methods
 *   are called.
 *
 ****************************************************************************/

static int esp32_attach(struct uart_dev_s *dev)
{
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;
  int cpu;
  int ret = OK;

  /* Allocate a level-sensitive, priority 1 CPU interrupt for the UART */

  priv->cpuint = esp32_alloc_levelint(1);
  if (priv->cpuint < 0)
    {
      /* Failed to allocate a CPU interrupt of this type */

      return priv->cpuint;
    }

  /* Set up to receive peripheral interrupts on the current CPU */

#ifdef CONFIG_SMP
  cpu = up_cpu_index();
#else
  cpu = 0;
#endif

  /* Attach the GPIO peripheral to the allocated CPU interrupt */

  up_disable_irq(priv->cpuint);
  esp32_attach_peripheral(cpu, priv->config->periph, priv->cpuint);

  /* Attach and enable the IRQ */

  ret = irq_attach(priv->config->irq, esp32_interrupt, dev);
  if (ret == OK)
    {
      /* Enable the CPU interrupt (RX and TX interrupts are still disabled
       * in the UART
       */

      up_enable_irq(priv->cpuint);
    }

  return ret;
}

/****************************************************************************
 * Name: esp32_detach
 *
 * Description:
 *   Detach UART interrupts.  This method is called when the serial port is
 *   closed normally just before the shutdown method is called.  The
 *   exception is the serial console which is never shutdown.
 *
 ****************************************************************************/

static void esp32_detach(struct uart_dev_s *dev)
{
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;
  int cpu;

  /* Disable and detach the CPU interrupt */

  up_disable_irq(priv->cpuint);
  irq_detach(priv->config->irq);

  /* Disassociate the peripheral interrupt from the CPU interrupt */

#ifdef CONFIG_SMP
  cpu = up_cpu_index();
#else
  cpu = 0;
#endif

  esp32_detach_peripheral(cpu, priv->config->periph, priv->cpuint);

  /* And release the CPU interrupt */

  esp32_free_cpuint(priv->cpuint);
  priv->cpuint = -1;
}

/****************************************************************************
 * Name: esp32_interrupt
 *
 * Description:
 *   This is the common UART interrupt handler.  It will be invoked
 *   when an interrupt received on the device.  It should call
 *   uart_transmitchars or uart_receivechar to perform the appropriate data
 *   transfers.
 *
 ****************************************************************************/

static int esp32_interrupt(int cpuint, void *context, FAR void *arg)
{
  struct uart_dev_s *dev = (struct uart_dev_s *)arg;
  struct esp32_dev_s *priv;
  uint32_t regval;
  uint32_t status;
  uint32_t enabled;
  unsigned int nfifo;
  int passes;
  bool handled;

  DEBUGASSERT(dev != NULL && dev->priv != NULL);
  priv = (struct esp32_dev_s *)dev->priv;

  /* Loop until there are no characters to be transferred or, until we have
   * been looping for a long time.
   */

  handled = true;
  for (passes = 0; passes < 256 && handled; passes++)
    {
      handled      = false;
      priv->status = getreg32(UART_INT_RAW_REG(priv->config->id));
      status       = getreg32(UART_STATUS_REG(priv->config->id));
      enabled      = getreg32(UART_INT_ENA_REG(priv->config->id));

      /* Clear pending interrupts */

      regval = (UART_RXFIFO_FULL_INT_CLR | UART_FRM_ERR_INT_CLR |
                UART_RXFIFO_TOUT_INT_CLR | UART_TX_DONE_INT_CLR |
                UART_TXFIFO_EMPTY_INT_CLR);
      putreg32(regval, UART_INT_CLR_REG(priv->config->id));

      /* Are Rx interrupts enabled?  The upper layer may hold off Rx input
       * by disabling the Rx interrupts if there is no place to saved the
       * data, possibly resulting in an overrun error.
       */

      if ((enabled & (UART_RXFIFO_FULL_INT_ENA |
                     UART_RXFIFO_TOUT_INT_ENA)) != 0)
        {
          /* Is there any data waiting in the Rx FIFO? */

          nfifo = esp32_get_rx_fifo_len(priv);
          if (nfifo > 0)
            {
              /* Received data in the RXFIFO! ... Process incoming bytes */

              uart_recvchars(dev);
              handled = true;
            }
        }

      /* Are Tx interrupts enabled?  The upper layer will disable Tx
       * interrupts when it has nothing to send.
       */

      if ((enabled & (UART_TX_DONE_INT_ENA | UART_TXFIFO_EMPTY_INT_ENA))
          != 0)
        {
          nfifo = REG_MASK(status, UART_TXFIFO_CNT);
          if (nfifo < 0x7f)
            {
              /* The TXFIFO is not full ... process outgoing bytes */

              uart_xmitchars(dev);
              handled = true;
            }
        }
    }

  return OK;
}

/****************************************************************************
 * Name: esp32_ioctl
 *
 * Description:
 *   All ioctl calls will be routed through this method
 *
 ****************************************************************************/

static int esp32_ioctl(struct file *filep, int cmd, unsigned long arg)
{
#if defined(CONFIG_SERIAL_TERMIOS) || defined(CONFIG_SERIAL_TIOCSERGSTRUCT)
  struct inode      *inode = filep->f_inode;
  struct uart_dev_s *dev   = inode->i_private;
#endif
  int                ret    = OK;

  switch (cmd)
    {
#ifdef CONFIG_SERIAL_TIOCSERGSTRUCT
    case TIOCSERGSTRUCT:
      {
         struct esp32_dev_s *user = (struct esp32_dev_s *)arg;
         if (!user)
           {
             ret = -EINVAL;
           }
         else
           {
             memcpy(user, dev, sizeof(struct esp32_dev_s));
           }
       }
       break;
#endif

#ifdef CONFIG_SERIAL_TERMIOS
    case TCGETS:
      {
        struct termios  *termiosp = (struct termios *)arg;
        struct esp32_dev_s *priv    = (struct esp32_dev_s *)dev->priv;

        if (!termiosp)
          {
            ret = -EINVAL;
            break;
          }

        /* Return parity */

        termiosp->c_cflag = ((priv->parity != 0) ? PARENB : 0) |
                            ((priv->parity == 1) ? PARODD : 0);

        /* Return stop bits */

        termiosp->c_cflag |= (priv->stopbits2) ? CSTOPB : 0;

        /* Return flow control */

#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
        termiosp->c_cflag |= (priv->flowc) ? (CCTS_OFLOW | CRTS_IFLOW): 0;
#endif
        /* Return baud */

        cfsetispeed(termiosp, priv->baud);

        /* Return number of bits */

        switch (priv->bits)
          {
          case 5:
            termiosp->c_cflag |= CS5;
            break;

          case 6:
            termiosp->c_cflag |= CS6;
            break;

          case 7:
            termiosp->c_cflag |= CS7;
            break;

          default:
          case 8:
            termiosp->c_cflag |= CS8;
            break;

          case 9:
            termiosp->c_cflag |= CS8 /* CS9 */ ;
            break;
          }
      }
      break;

    case TCSETS:
      {
        struct termios  *termiosp = (struct termios *)arg;
        struct esp32_dev_s *priv    = (struct esp32_dev_s *)dev->priv;
        uint32_t baud;
        uint32_t intena;
        uint8_t parity;
        uint8_t nbits;
        bool stop2;
#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
        bool flowc;
#endif

        if (!termiosp)
          {
            ret = -EINVAL;
            break;
          }

        /* Decode baud. */

        ret = OK;
        baud = cfgetispeed(termiosp);

        /* Decode number of bits */

        switch (termiosp->c_cflag & CSIZE)
          {
          case CS5:
            nbits = 5;
            break;

          case CS6:
            nbits = 6;
            break;

          case CS7:
            nbits = 7;
            break;

          case CS8:
            nbits = 8;
            break;
#if 0
          case CS9:
            nbits = 9;
            break;
#endif
          default:
            ret = -EINVAL;
            break;
          }

        /* Decode parity */

        if ((termiosp->c_cflag & PARENB) != 0)
          {
            parity = (termiosp->c_cflag & PARODD) ? 1 : 2;
          }
        else
          {
            parity = 0;
          }

        /* Decode stop bits */

        stop2 = (termiosp->c_cflag & CSTOPB) != 0;

        /* Decode flow control */

#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
        flowc = (termiosp->c_cflag & (CCTS_OFLOW | CRTS_IFLOW)) != 0;
#endif
        /* Verify that all settings are valid before committing */

        if (ret == OK)
          {
            /* Commit */

            priv->baud      = baud;
            priv->parity    = parity;
            priv->bits      = nbits;
            priv->stopbits2 = stop2;
#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
            priv->flowc     = flowc;
#endif
            /* effect the changes immediately - note that we do not
             * implement TCSADRAIN / TCSAFLUSH
             */

            esp32_disableallints(priv, &intena);
            ret = esp32_setup(dev);

            /* Restore the interrupt state */

            esp32_restoreuartint(priv, intena);
          }
      }
      break;
#endif /* CONFIG_SERIAL_TERMIOS */

    default:
      ret = -ENOTTY;
      break;
    }

  return ret;
}

/****************************************************************************
 * Name: esp32_receive
 *
 * Description:
 *   Called (usually) from the interrupt level to receive one
 *   character from the UART.  Error bits associated with the
 *   receipt are provided in the return 'status'.
 *
 ****************************************************************************/

static int  esp32_receive(struct uart_dev_s *dev, unsigned int *status)
{
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;
  uint32_t rx_fifo;

  /* Return the error information in the saved status */

  *status      = (unsigned int)priv->status;
  priv->status = 0;

  /* Then return the actual received byte */

  rx_fifo = getreg32(DR_UART_FIFO_REG(priv->config->id));

  return (int)REG_MASK(rx_fifo, UART_RXFIFO_RD_BYTE);
}

/****************************************************************************
 * Name: esp32_rxint
 *
 * Description:
 *   Call to enable or disable RXRDY interrupts
 *
 ****************************************************************************/

static void esp32_rxint(struct uart_dev_s *dev, bool enable)
{
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;
  irqstate_t flags;
  int regval;

  flags = enter_critical_section();

  if (enable)
    {
      /* Receive an interrupt when their is anything in the Rx data register
       * (or an Rx timeout occurs).
       */

#ifndef CONFIG_SUPPRESS_SERIAL_INTS
      regval  = getreg32(UART_INT_ENA_REG(priv->config->id));
      regval |= (UART_RXFIFO_FULL_INT_ENA | UART_FRM_ERR_INT_ENA |
                 UART_RXFIFO_TOUT_INT_ENA);
      putreg32(regval, UART_INT_ENA_REG(priv->config->id));
#endif
    }
  else
    {
      /* Disable the RX interrupts */

      regval  = getreg32(UART_INT_ENA_REG(priv->config->id));
      regval &= ~(UART_RXFIFO_FULL_INT_ENA | UART_FRM_ERR_INT_ENA |
                  UART_RXFIFO_TOUT_INT_ENA);
      putreg32(regval, UART_INT_ENA_REG(priv->config->id));
    }

  leave_critical_section(flags);
}

/****************************************************************************
 * Name: esp32_rxavailable
 *
 * Description:
 *   Return true if the receive holding register is not empty
 *
 ****************************************************************************/

static bool esp32_rxavailable(struct uart_dev_s *dev)
{
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;
  return esp32_get_rx_fifo_len(priv) > 0;
}

/****************************************************************************
 * Name: esp32_send
 *
 * Description:
 *   This method will send one byte on the UART.
 *
 ****************************************************************************/

static void esp32_send(struct uart_dev_s *dev, int ch)
{
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;

  putreg32((uint32_t)ch, AHB_UART_FIFO_REG(priv->config->id));
}

/****************************************************************************
 * Name: esp32_txint
 *
 * Description:
 *   Call to enable or disable TX interrupts
 *
 ****************************************************************************/

static void esp32_txint(struct uart_dev_s *dev, bool enable)
{
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;
  irqstate_t flags;

  flags = enter_critical_section();

  if (enable)
    {
      /* Set to receive an interrupt when the TX holding register is empty */

#ifndef CONFIG_SUPPRESS_SERIAL_INTS
      modifyreg32(UART_INT_ENA_REG(priv->config->id),
                  0, (UART_TX_DONE_INT_ENA | UART_TXFIFO_EMPTY_INT_ENA));

      /* Fake a TX interrupt here by just calling uart_xmitchars() with
       * interrupts disabled (note this may recurse).
       */

      uart_xmitchars(dev);
#endif
    }
  else
    {
      /* Disable the TX interrupt */

      modifyreg32(UART_INT_ENA_REG(priv->config->id),
                  (UART_TX_DONE_INT_ENA | UART_TXFIFO_EMPTY_INT_ENA), 0);
    }

  leave_critical_section(flags);
}

/****************************************************************************
 * Name: esp32_txready
 *
 * Description:
 *   Return true if the transmit holding register is empty (TXRDY)
 *
 ****************************************************************************/

static bool esp32_txready(struct uart_dev_s *dev)
{
  uint32_t txcnt;
  uint32_t reg;
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;

  reg = getreg32(UART_STATUS_REG(priv->config->id));
  txcnt = REG_MASK(reg, UART_TXFIFO_CNT);

  return (txcnt < (UART_TX_FIFO_SIZE - 1));
}

/****************************************************************************
 * Name: esp32_txempty
 *
 * Description:
 *   Return true if the transmit holding and shift registers are empty
 *
 ****************************************************************************/

static bool esp32_txempty(struct uart_dev_s *dev)
{
  struct esp32_dev_s *priv = (struct esp32_dev_s *)dev->priv;

  return ((getreg32(UART_STATUS_REG(priv->config->id))
          & UART_TXFIFO_CNT_M) == 0);
}

#ifndef CONFIG_SUPPRESS_UART_CONFIG
/****************************************************************************
 * Name: esp32_config_pins
 *
 * Description:
 *   Performs the pin configuration.
 *
 * Parameters:
 *   priv        -  Pointer to the serial driver struct.
 *
 ****************************************************************************/

static void esp32_config_pins(struct esp32_dev_s *priv)
{
  /* Configure UART pins
   *
   * Internal signals can be output to multiple GPIO pads.
   * But only one GPIO pad can connect with input signal
   */

  esp32_configgpio(priv->config->txpin, OUTPUT_FUNCTION_3);
  esp32_gpio_matrix_out(priv->config->txpin, priv->config->txsig, 0, 0);

  esp32_configgpio(priv->config->rxpin, INPUT_FUNCTION_3);
  esp32_gpio_matrix_in(priv->config->rxpin, priv->config->rxsig, 0);

#if defined(CONFIG_SERIAL_IFLOWCONTROL) || defined(CONFIG_SERIAL_OFLOWCONTROL)
  esp32_configgpio(priv->config->rtspin, OUTPUT_FUNCTION_3);
  esp32_gpio_matrix_out(priv->config->rtspin, priv->config->rtssig, 0, 0);

  esp32_configgpio(priv->config->ctspin, INPUT_FUNCTION_3);
  esp32_gpio_matrix_in(priv->config->ctspin, priv->config->ctssig, 0);
#endif
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: esp32_lowsetup
 *
 * Description:
 *   Performs the pin configuration for all UARTs.
 *   This functions is intended to be called in the __start function.
 *
 ****************************************************************************/

void esp32_lowsetup(void)
{
  esp32_config_pins(TTYS0_DEV.priv);
#ifdef TTYS1_DEV
  esp32_config_pins(TTYS1_DEV.priv);
#endif
#ifdef TTYS2_DEV
  esp32_config_pins(TTYS2_DEV.priv);
#endif
}

#endif /* CONFIG_SUPPRESS_UART_CONFIG */
/****************************************************************************
 * Name: xtensa_early_serial_initialize
 *
 * Description:
 *   Performs the low level UART initialization early in debug so that the
 *   serial console will be available during bootup.  This must be called
 *   before up_serialinit.
 *
 ****************************************************************************/

#ifdef USE_EARLYSERIALINIT
void xtensa_early_serial_initialize(void)
{
  /* NOTE:  All GPIO configuration for the UARTs was performed in
   * esp32_lowsetup
   */

  /* Disable all UARTS */

  esp32_disableallints(TTYS0_DEV.priv, NULL);
#ifdef TTYS1_DEV
  esp32_disableallints(TTYS1_DEV.priv, NULL);
#endif
#ifdef TTYS2_DEV
  esp32_disableallints(TTYS2_DEV.priv, NULL);
#endif

  /* Configuration whichever one is the console */

#ifdef HAVE_SERIAL_CONSOLE
  CONSOLE_DEV.isconsole = true;
  esp32_setup(&CONSOLE_DEV);
#endif
}
#endif

/****************************************************************************
 * Name: xtensa_serial_initialize
 *
 * Description:
 *   Register serial console and serial ports.  This assumes
 *   that up_earlyserialinit was called previously.
 *
 ****************************************************************************/

void xtensa_serial_initialize(void)
{
  /* Register the console */

#ifdef HAVE_SERIAL_CONSOLE
  uart_register("/dev/console", &CONSOLE_DEV);
#endif

  /* Register all UARTs */

  uart_register("/dev/ttyS0", &TTYS0_DEV);
#ifdef TTYS1_DEV
  uart_register("/dev/ttyS1", &TTYS1_DEV);
#endif
#ifdef TTYS2_DEV
  uart_register("/dev/ttyS2", &TTYS2_DEV);
#endif
}

/****************************************************************************
 * Name: up_putc
 *
 * Description:
 *   Provide priority, low-level access to support OS debug writes
 *
 ****************************************************************************/

int up_putc(int ch)
{
#ifdef HAVE_SERIAL_CONSOLE
  uint32_t intena;

  esp32_disableallints(CONSOLE_DEV.priv, &intena);

  /* Check for LF */

  if (ch == '\n')
    {
      /* Add CR */

      while (!esp32_txready(&CONSOLE_DEV));
      esp32_send(&CONSOLE_DEV, '\r');
    }

  while (!esp32_txready(&CONSOLE_DEV));
  esp32_send(&CONSOLE_DEV, ch);

  esp32_restoreuartint(CONSOLE_DEV.priv, intena);
#endif

  return ch;
}
#endif /* USE_SERIALDRIVER */
