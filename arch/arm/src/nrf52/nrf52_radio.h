/****************************************************************************
 * arch/arm/src/nrf52/nrf52_radio.h
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

#ifndef __ARCH_ARM_SRC_NRF52_NRF52_RADIO_H
#define __ARCH_ARM_SRC_NRF52_NRF52_RADIO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>

#include <nuttx/semaphore.h>

#include "chip.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define NRF52_RADIO_LOGICAL_ADDRESS_MAX (8)

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* Radio mode */

enum nrf52_radio_mode_e
{
  NRF52_RADIO_MODE_NRF1MBIT     = 0,
  NRF52_RADIO_MODE_NRF2MBIT     = 1,
  NRF52_RADIO_MODE_BLE1MBIT     = 2,
  NRF52_RADIO_MODE_BLE2MBIT     = 3,
#if defined(CONFIG_ARCH_CHIP_NRF52832)
  NRF52_RADIO_MODE_NRF250KBIT   = 4,
#elif defined(CONFIG_ARCH_CHIP_NRF52840)
  NRF52_RADIO_MODE_BLELR125KBIT = 4,
  NRF52_RADIO_MODE_BLELR500KBIT = 5,
  NRF52_RADIO_MODE_IEEE802154   = 6
#endif
};

/* Preamble configuration */

enum nrf52_radio_preamble_e
{
  NRF52_RADIO_PREAMBLE_8BIT       = 0,
  NRF52_RADIO_PREAMBLE_16BIT      = 1,
  NRF52_RADIO_PREAMBLE_32BITZERO  = 2,
  NRF52_RADIO_PREAMBLE_LONGRANGE  = 3
};

/* Radio packet CRC length */

enum nrf52_radio_crc_len_e
{
  NRF52_RADIO_CRC_LEN_DIS   = 0,
  NRF52_RADIO_CRC_LEN_1B    = 1,
  NRF52_RADIO_CRC_LEN_2B    = 2,
  NRF52_RADIO_CRC_LEN_3B    = 3,
};

/* Radio packet CRC includes address */

enum nrf52_radio_crc_skipaddr_e
{
  NRF52_RADIO_CRC_SKIPADDR_INCLUDE    = 0,
  NRF52_RADIO_CRC_SKIPADDR_SKIP       = 1,
#if defined(CONFIG_ARCH_CHIP_NRF52840)
  NRF52_RADIO_CRC_SKIPADDR_IEEE802154 = 2,
#endif
};

/* On air packet layout:
 *
 * +---------------------------------------+
 * | FIRST                                 |
 * |----------+------+--------+----+-------+
 * | PREAMBLE | BASE | PREFIX | CI | TERM1 |
 * | LSB      | LSB  | LSB    |    |       |
 * |          | ADDRESS       |    |       |
 * +----------+---------------+----+-------+
 *
 *
 * +----------------------------+
 * | Stored on RAM              |
 * |----+--------+----+---------|
 * | S0 | LENGTH | S1 | PAYLOAD |
 * |    |        |    |         |
 * |    |        |    |         |
 * +----+--------+----+---------+
 *
 * +---------------+
 * |         LAST  |
 * |-------+-------|
 * | CRC32 | TERM2 |
 * | MSB   |       |
 * |       |       |
 * +-------+-------+
 *
 */

/* Radio packet configuration */

struct nrf52_radio_pktcfg_s
{
  uint8_t max_len;              /* Maximum length of payload */
  uint8_t stat_len;             /* Static payload length */
  uint8_t bal_len;              /* Base address length */
  uint8_t lf_len;               /* LENGTH length */
  uint8_t s0_len;               /* S0 length */
  uint8_t s1_len;               /* S1 length */
  uint8_t ci_len;               /* CI length */
  uint8_t pl_len;               /* Preable lenght */
  uint8_t term_len;             /* TERM length */
  bool    crcinc;               /* LENGTH includes CRC */
  bool    endian;               /* On air endianess of packet:
                                 * 0 - little
                                 * 1 - big
                                 */
  bool   whiteen;               /* Whitening enabled */
};

/* Radio packet CRC configuration */

struct nrf52_radio_crc_s
{
  uint8_t  len;                 /* CRC length in number of bytes */
  uint8_t  skip;                /* Include or exclude address field out of CRC */
  uint32_t poly;                /* CRC polynominal */
  uint32_t init;                /* CRC initial value */
};

/* NRF52 radio operations */

struct nrf52_radio_dev_s;
struct nrf52_radio_ops_s
{
  /* Turn-on/turn-off radio power */

  CODE int (*power)(FAR struct nrf52_radio_dev_s *dev, bool state);

  /* Set radio mode */

  CODE int (*mode_set)(FAR struct nrf52_radio_dev_s *dev, uint8_t mode);

  /* Set radio frequency (in MHz) */

  CODE int (*freq_set)(FAR struct nrf52_radio_dev_s *dev, uint32_t freq);

  /* Get RSSI sample */

  CODE int (*rssi_get)(FAR struct nrf52_radio_dev_s *dev, FAR int *rssi);

  /* Set TX power */

  CODE int (*txpower_set)(FAR struct nrf52_radio_dev_s *dev,
                          int8_t dbm);

  /* Set hardware interframe spacing time */

  CODE int (*tifs_set)(FAR struct nrf52_radio_dev_s *dev, uint16_t us);

  /* Configure radio packet */

  CODE int (*pkt_cfg)(FAR struct nrf52_radio_dev_s *dev,
                      const FAR struct nrf52_radio_pktcfg_s *cfg);

  /* Configure packet CRC */

  CODE int (*crc_cfg)(FAR struct nrf52_radio_dev_s *dev,
                      const FAR struct nrf52_radio_crc_s *cfg);

  /* Configure data whitening */

  CODE int (*white_set)(FAR struct nrf52_radio_dev_s *dev,
                        uint8_t init);

  /* Configure logical address */

  CODE int (*addr_set)(FAR struct nrf52_radio_dev_s *dev, uint8_t i,
                       uint8_t prefix, uint32_t base);

  /* Dump radio registers */

  CODE void (*dumpregs)(FAR struct nrf52_radio_dev_s *dev);

  /* Dump interrupt handler */

  CODE void (*setisr)(FAR struct nrf52_radio_dev_s *dev, xcpt_t handler,
                      FAR void * arg);

  /* Set packet pointer */

  CODE void (*set_packetptr)(FAR struct nrf52_radio_dev_s *dev, void *ptr);

  /* Start receive mode */

  CODE void (*rx_enable)(FAR struct nrf52_radio_dev_s *dev);

  /* Start transmit mode */

  CODE void (*tx_enable)(FAR struct nrf52_radio_dev_s *dev);
};

/* NRF52 radio board specific data */

struct nrf52_radio_board_s
{
  /* TODO: PA/LNA interface */

  uint32_t reserved;
};

/* NRF52 radio device */

struct nrf52_radio_dev_s
{
  FAR struct nrf52_radio_ops_s   *ops;       /* Radio operations */
  FAR struct nrf52_radio_board_s *board;     /* Radio board-specific */
  uint32_t                        base;      /* Radio base */
  uint32_t                        irq;       /* Radio IRQ number */
  uint8_t                         mode;      /* Radio mode */
  struct nrf52_radio_pktcfg_s     pktcfg;    /* Current packet */
  uint16_t                        tifs;      /* Interframe spacing time */
  int8_t                          txpower;   /* TX power in dBm */
  uint8_t                         txaddr;    /* TX address */
  uint8_t                         rxaddr;    /* RX addresses */
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: nrf52_radio_initialize
 *
 * Description:
 *   Initialize NRF52 radio device
 *
 ****************************************************************************/

FAR struct nrf52_radio_dev_s *
nrf52_radio_initialize(int intf, FAR struct nrf52_radio_board_s *board);

#endif /* __ARCH_ARM_SRC_NRF52_NRF52_RADIO_H */
