/****************************************************************************
 * arch/xtensa/src/esp32s3/hardware/esp32s3_uart.h
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

#ifndef __ARCH_XTENSA_SRC_ESP32S3_HARDWARE_ESP32S3_UART_H
#define __ARCH_XTENSA_SRC_ESP32S3_HARDWARE_ESP32S3_UART_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "esp32s3_soc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* UART_FIFO_REG register
 * FIFO data register
 */

#define UART_FIFO_REG(i) (REG_UART_BASE(i) + 0x0)

/* UART_RXFIFO_RD_BYTE : RO; bitpos: [7:0]; default: 0;
 * UART $n accesses FIFO via this register.
 */

#define UART_RXFIFO_RD_BYTE    0x000000ff
#define UART_RXFIFO_RD_BYTE_M  (UART_RXFIFO_RD_BYTE_V << UART_RXFIFO_RD_BYTE_S)
#define UART_RXFIFO_RD_BYTE_V  0x000000ff
#define UART_RXFIFO_RD_BYTE_S  0

/* UART_INT_RAW_REG register
 * Raw interrupt status
 */

#define UART_INT_RAW_REG(i) (REG_UART_BASE(i) + 0x4)

/* UART_WAKEUP_INT_RAW : R/WTC/SS; bitpos: [19]; default: 0;
 * This interrupt raw bit turns to high level when input rxd edge changes
 * more times than what reg_active_threshold specifies in light sleeping
 * mode.
 */

#define UART_WAKEUP_INT_RAW    (BIT(19))
#define UART_WAKEUP_INT_RAW_M  (UART_WAKEUP_INT_RAW_V << UART_WAKEUP_INT_RAW_S)
#define UART_WAKEUP_INT_RAW_V  0x00000001
#define UART_WAKEUP_INT_RAW_S  19

/* UART_AT_CMD_CHAR_DET_INT_RAW : R/WTC/SS; bitpos: [18]; default: 0;
 * This interrupt raw bit turns to high level when receiver detects the
 * configured at_cmd char.
 */

#define UART_AT_CMD_CHAR_DET_INT_RAW    (BIT(18))
#define UART_AT_CMD_CHAR_DET_INT_RAW_M  (UART_AT_CMD_CHAR_DET_INT_RAW_V << UART_AT_CMD_CHAR_DET_INT_RAW_S)
#define UART_AT_CMD_CHAR_DET_INT_RAW_V  0x00000001
#define UART_AT_CMD_CHAR_DET_INT_RAW_S  18

/* UART_RS485_CLASH_INT_RAW : R/WTC/SS; bitpos: [17]; default: 0;
 * This interrupt raw bit turns to high level when detects a clash between
 * transmitter and receiver in rs485 mode.
 */

#define UART_RS485_CLASH_INT_RAW    (BIT(17))
#define UART_RS485_CLASH_INT_RAW_M  (UART_RS485_CLASH_INT_RAW_V << UART_RS485_CLASH_INT_RAW_S)
#define UART_RS485_CLASH_INT_RAW_V  0x00000001
#define UART_RS485_CLASH_INT_RAW_S  17

/* UART_RS485_FRM_ERR_INT_RAW : R/WTC/SS; bitpos: [16]; default: 0;
 * This interrupt raw bit turns to high level when receiver detects a data
 * frame error from the echo of transmitter in rs485 mode.
 */

#define UART_RS485_FRM_ERR_INT_RAW    (BIT(16))
#define UART_RS485_FRM_ERR_INT_RAW_M  (UART_RS485_FRM_ERR_INT_RAW_V << UART_RS485_FRM_ERR_INT_RAW_S)
#define UART_RS485_FRM_ERR_INT_RAW_V  0x00000001
#define UART_RS485_FRM_ERR_INT_RAW_S  16

/* UART_RS485_PARITY_ERR_INT_RAW : R/WTC/SS; bitpos: [15]; default: 0;
 * This interrupt raw bit turns to high level when receiver detects a parity
 * error from the echo of transmitter in rs485 mode.
 */

#define UART_RS485_PARITY_ERR_INT_RAW    (BIT(15))
#define UART_RS485_PARITY_ERR_INT_RAW_M  (UART_RS485_PARITY_ERR_INT_RAW_V << UART_RS485_PARITY_ERR_INT_RAW_S)
#define UART_RS485_PARITY_ERR_INT_RAW_V  0x00000001
#define UART_RS485_PARITY_ERR_INT_RAW_S  15

/* UART_TX_DONE_INT_RAW : R/WTC/SS; bitpos: [14]; default: 0;
 * This interrupt raw bit turns to high level when transmitter has send out
 * all data in FIFO.
 */

#define UART_TX_DONE_INT_RAW    (BIT(14))
#define UART_TX_DONE_INT_RAW_M  (UART_TX_DONE_INT_RAW_V << UART_TX_DONE_INT_RAW_S)
#define UART_TX_DONE_INT_RAW_V  0x00000001
#define UART_TX_DONE_INT_RAW_S  14

/* UART_TX_BRK_IDLE_DONE_INT_RAW : R/WTC/SS; bitpos: [13]; default: 0;
 * This interrupt raw bit turns to high level when transmitter has kept the
 * shortest duration after sending the  last data.
 */

#define UART_TX_BRK_IDLE_DONE_INT_RAW    (BIT(13))
#define UART_TX_BRK_IDLE_DONE_INT_RAW_M  (UART_TX_BRK_IDLE_DONE_INT_RAW_V << UART_TX_BRK_IDLE_DONE_INT_RAW_S)
#define UART_TX_BRK_IDLE_DONE_INT_RAW_V  0x00000001
#define UART_TX_BRK_IDLE_DONE_INT_RAW_S  13

/* UART_TX_BRK_DONE_INT_RAW : R/WTC/SS; bitpos: [12]; default: 0;
 * This interrupt raw bit turns to high level when transmitter completes
 * sending  NULL characters, after all data in Tx-FIFO are sent.
 */

#define UART_TX_BRK_DONE_INT_RAW    (BIT(12))
#define UART_TX_BRK_DONE_INT_RAW_M  (UART_TX_BRK_DONE_INT_RAW_V << UART_TX_BRK_DONE_INT_RAW_S)
#define UART_TX_BRK_DONE_INT_RAW_V  0x00000001
#define UART_TX_BRK_DONE_INT_RAW_S  12

/* UART_GLITCH_DET_INT_RAW : R/WTC/SS; bitpos: [11]; default: 0;
 * This interrupt raw bit turns to high level when receiver detects a glitch
 * in the middle of a start bit.
 */

#define UART_GLITCH_DET_INT_RAW    (BIT(11))
#define UART_GLITCH_DET_INT_RAW_M  (UART_GLITCH_DET_INT_RAW_V << UART_GLITCH_DET_INT_RAW_S)
#define UART_GLITCH_DET_INT_RAW_V  0x00000001
#define UART_GLITCH_DET_INT_RAW_S  11

/* UART_SW_XOFF_INT_RAW : R/WTC/SS; bitpos: [10]; default: 0;
 * This interrupt raw bit turns to high level when receiver receives Xoff
 * char when uart_sw_flow_con_en is set to 1.
 */

#define UART_SW_XOFF_INT_RAW    (BIT(10))
#define UART_SW_XOFF_INT_RAW_M  (UART_SW_XOFF_INT_RAW_V << UART_SW_XOFF_INT_RAW_S)
#define UART_SW_XOFF_INT_RAW_V  0x00000001
#define UART_SW_XOFF_INT_RAW_S  10

/* UART_SW_XON_INT_RAW : R/WTC/SS; bitpos: [9]; default: 0;
 * This interrupt raw bit turns to high level when receiver recevies Xon
 * char when uart_sw_flow_con_en is set to 1.
 */

#define UART_SW_XON_INT_RAW    (BIT(9))
#define UART_SW_XON_INT_RAW_M  (UART_SW_XON_INT_RAW_V << UART_SW_XON_INT_RAW_S)
#define UART_SW_XON_INT_RAW_V  0x00000001
#define UART_SW_XON_INT_RAW_S  9

/* UART_RXFIFO_TOUT_INT_RAW : R/WTC/SS; bitpos: [8]; default: 0;
 * This interrupt raw bit turns to high level when receiver takes more time
 * than rx_tout_thrhd to receive a byte.
 */

#define UART_RXFIFO_TOUT_INT_RAW    (BIT(8))
#define UART_RXFIFO_TOUT_INT_RAW_M  (UART_RXFIFO_TOUT_INT_RAW_V << UART_RXFIFO_TOUT_INT_RAW_S)
#define UART_RXFIFO_TOUT_INT_RAW_V  0x00000001
#define UART_RXFIFO_TOUT_INT_RAW_S  8

/* UART_BRK_DET_INT_RAW : R/WTC/SS; bitpos: [7]; default: 0;
 * This interrupt raw bit turns to high level when receiver detects a 0
 * after the stop bit.
 */

#define UART_BRK_DET_INT_RAW    (BIT(7))
#define UART_BRK_DET_INT_RAW_M  (UART_BRK_DET_INT_RAW_V << UART_BRK_DET_INT_RAW_S)
#define UART_BRK_DET_INT_RAW_V  0x00000001
#define UART_BRK_DET_INT_RAW_S  7

/* UART_CTS_CHG_INT_RAW : R/WTC/SS; bitpos: [6]; default: 0;
 * This interrupt raw bit turns to high level when receiver detects the edge
 * change of CTSn signal.
 */

#define UART_CTS_CHG_INT_RAW    (BIT(6))
#define UART_CTS_CHG_INT_RAW_M  (UART_CTS_CHG_INT_RAW_V << UART_CTS_CHG_INT_RAW_S)
#define UART_CTS_CHG_INT_RAW_V  0x00000001
#define UART_CTS_CHG_INT_RAW_S  6

/* UART_DSR_CHG_INT_RAW : R/WTC/SS; bitpos: [5]; default: 0;
 * This interrupt raw bit turns to high level when receiver detects the edge
 * change of DSRn signal.
 */

#define UART_DSR_CHG_INT_RAW    (BIT(5))
#define UART_DSR_CHG_INT_RAW_M  (UART_DSR_CHG_INT_RAW_V << UART_DSR_CHG_INT_RAW_S)
#define UART_DSR_CHG_INT_RAW_V  0x00000001
#define UART_DSR_CHG_INT_RAW_S  5

/* UART_RXFIFO_OVF_INT_RAW : R/WTC/SS; bitpos: [4]; default: 0;
 * This interrupt raw bit turns to high level when receiver receives more
 * data than the FIFO can store.
 */

#define UART_RXFIFO_OVF_INT_RAW    (BIT(4))
#define UART_RXFIFO_OVF_INT_RAW_M  (UART_RXFIFO_OVF_INT_RAW_V << UART_RXFIFO_OVF_INT_RAW_S)
#define UART_RXFIFO_OVF_INT_RAW_V  0x00000001
#define UART_RXFIFO_OVF_INT_RAW_S  4

/* UART_FRM_ERR_INT_RAW : R/WTC/SS; bitpos: [3]; default: 0;
 * This interrupt raw bit turns to high level when receiver detects a data
 * frame error .
 */

#define UART_FRM_ERR_INT_RAW    (BIT(3))
#define UART_FRM_ERR_INT_RAW_M  (UART_FRM_ERR_INT_RAW_V << UART_FRM_ERR_INT_RAW_S)
#define UART_FRM_ERR_INT_RAW_V  0x00000001
#define UART_FRM_ERR_INT_RAW_S  3

/* UART_PARITY_ERR_INT_RAW : R/WTC/SS; bitpos: [2]; default: 0;
 * This interrupt raw bit turns to high level when receiver detects a parity
 * error in the data.
 */

#define UART_PARITY_ERR_INT_RAW    (BIT(2))
#define UART_PARITY_ERR_INT_RAW_M  (UART_PARITY_ERR_INT_RAW_V << UART_PARITY_ERR_INT_RAW_S)
#define UART_PARITY_ERR_INT_RAW_V  0x00000001
#define UART_PARITY_ERR_INT_RAW_S  2

/* UART_TXFIFO_EMPTY_INT_RAW : R/WTC/SS; bitpos: [1]; default: 1;
 * This interrupt raw bit turns to high level when the amount of data in
 * Tx-FIFO is less than what txfifo_empty_thrhd specifies .
 */

#define UART_TXFIFO_EMPTY_INT_RAW    (BIT(1))
#define UART_TXFIFO_EMPTY_INT_RAW_M  (UART_TXFIFO_EMPTY_INT_RAW_V << UART_TXFIFO_EMPTY_INT_RAW_S)
#define UART_TXFIFO_EMPTY_INT_RAW_V  0x00000001
#define UART_TXFIFO_EMPTY_INT_RAW_S  1

/* UART_RXFIFO_FULL_INT_RAW : R/WTC/SS; bitpos: [0]; default: 0;
 * This interrupt raw bit turns to high level when receiver receives more
 * data than what rxfifo_full_thrhd specifies.
 */

#define UART_RXFIFO_FULL_INT_RAW    (BIT(0))
#define UART_RXFIFO_FULL_INT_RAW_M  (UART_RXFIFO_FULL_INT_RAW_V << UART_RXFIFO_FULL_INT_RAW_S)
#define UART_RXFIFO_FULL_INT_RAW_V  0x00000001
#define UART_RXFIFO_FULL_INT_RAW_S  0

/* UART_INT_ST_REG register
 * Masked interrupt status
 */

#define UART_INT_ST_REG(i) (REG_UART_BASE(i) + 0x8)

/* UART_WAKEUP_INT_ST : RO; bitpos: [19]; default: 0;
 * This is the status bit for uart_wakeup_int_raw when uart_wakeup_int_ena
 * is set to 1.
 */

#define UART_WAKEUP_INT_ST    (BIT(19))
#define UART_WAKEUP_INT_ST_M  (UART_WAKEUP_INT_ST_V << UART_WAKEUP_INT_ST_S)
#define UART_WAKEUP_INT_ST_V  0x00000001
#define UART_WAKEUP_INT_ST_S  19

/* UART_AT_CMD_CHAR_DET_INT_ST : RO; bitpos: [18]; default: 0;
 * This is the status bit for at_cmd_det_int_raw when
 * at_cmd_char_det_int_ena is set to 1.
 */

#define UART_AT_CMD_CHAR_DET_INT_ST    (BIT(18))
#define UART_AT_CMD_CHAR_DET_INT_ST_M  (UART_AT_CMD_CHAR_DET_INT_ST_V << UART_AT_CMD_CHAR_DET_INT_ST_S)
#define UART_AT_CMD_CHAR_DET_INT_ST_V  0x00000001
#define UART_AT_CMD_CHAR_DET_INT_ST_S  18

/* UART_RS485_CLASH_INT_ST : RO; bitpos: [17]; default: 0;
 * This is the status bit for rs485_clash_int_raw when rs485_clash_int_ena
 * is set to 1.
 */

#define UART_RS485_CLASH_INT_ST    (BIT(17))
#define UART_RS485_CLASH_INT_ST_M  (UART_RS485_CLASH_INT_ST_V << UART_RS485_CLASH_INT_ST_S)
#define UART_RS485_CLASH_INT_ST_V  0x00000001
#define UART_RS485_CLASH_INT_ST_S  17

/* UART_RS485_FRM_ERR_INT_ST : RO; bitpos: [16]; default: 0;
 * This is the status bit for rs485_frm_err_int_raw when
 * rs485_fm_err_int_ena is set to 1.
 */

#define UART_RS485_FRM_ERR_INT_ST    (BIT(16))
#define UART_RS485_FRM_ERR_INT_ST_M  (UART_RS485_FRM_ERR_INT_ST_V << UART_RS485_FRM_ERR_INT_ST_S)
#define UART_RS485_FRM_ERR_INT_ST_V  0x00000001
#define UART_RS485_FRM_ERR_INT_ST_S  16

/* UART_RS485_PARITY_ERR_INT_ST : RO; bitpos: [15]; default: 0;
 * This is the status bit for rs485_parity_err_int_raw when
 * rs485_parity_int_ena is set to 1.
 */

#define UART_RS485_PARITY_ERR_INT_ST    (BIT(15))
#define UART_RS485_PARITY_ERR_INT_ST_M  (UART_RS485_PARITY_ERR_INT_ST_V << UART_RS485_PARITY_ERR_INT_ST_S)
#define UART_RS485_PARITY_ERR_INT_ST_V  0x00000001
#define UART_RS485_PARITY_ERR_INT_ST_S  15

/* UART_TX_DONE_INT_ST : RO; bitpos: [14]; default: 0;
 * This is the status bit for tx_done_int_raw when tx_done_int_ena is set to
 * 1.
 */

#define UART_TX_DONE_INT_ST    (BIT(14))
#define UART_TX_DONE_INT_ST_M  (UART_TX_DONE_INT_ST_V << UART_TX_DONE_INT_ST_S)
#define UART_TX_DONE_INT_ST_V  0x00000001
#define UART_TX_DONE_INT_ST_S  14

/* UART_TX_BRK_IDLE_DONE_INT_ST : RO; bitpos: [13]; default: 0;
 * This is the stauts bit for tx_brk_idle_done_int_raw when
 * tx_brk_idle_done_int_ena is set to 1.
 */

#define UART_TX_BRK_IDLE_DONE_INT_ST    (BIT(13))
#define UART_TX_BRK_IDLE_DONE_INT_ST_M  (UART_TX_BRK_IDLE_DONE_INT_ST_V << UART_TX_BRK_IDLE_DONE_INT_ST_S)
#define UART_TX_BRK_IDLE_DONE_INT_ST_V  0x00000001
#define UART_TX_BRK_IDLE_DONE_INT_ST_S  13

/* UART_TX_BRK_DONE_INT_ST : RO; bitpos: [12]; default: 0;
 * This is the status bit for tx_brk_done_int_raw when tx_brk_done_int_ena
 * is set to 1.
 */

#define UART_TX_BRK_DONE_INT_ST    (BIT(12))
#define UART_TX_BRK_DONE_INT_ST_M  (UART_TX_BRK_DONE_INT_ST_V << UART_TX_BRK_DONE_INT_ST_S)
#define UART_TX_BRK_DONE_INT_ST_V  0x00000001
#define UART_TX_BRK_DONE_INT_ST_S  12

/* UART_GLITCH_DET_INT_ST : RO; bitpos: [11]; default: 0;
 * This is the status bit for glitch_det_int_raw when glitch_det_int_ena is
 * set to 1.
 */

#define UART_GLITCH_DET_INT_ST    (BIT(11))
#define UART_GLITCH_DET_INT_ST_M  (UART_GLITCH_DET_INT_ST_V << UART_GLITCH_DET_INT_ST_S)
#define UART_GLITCH_DET_INT_ST_V  0x00000001
#define UART_GLITCH_DET_INT_ST_S  11

/* UART_SW_XOFF_INT_ST : RO; bitpos: [10]; default: 0;
 * This is the status bit for sw_xoff_int_raw when sw_xoff_int_ena is set to
 * 1.
 */

#define UART_SW_XOFF_INT_ST    (BIT(10))
#define UART_SW_XOFF_INT_ST_M  (UART_SW_XOFF_INT_ST_V << UART_SW_XOFF_INT_ST_S)
#define UART_SW_XOFF_INT_ST_V  0x00000001
#define UART_SW_XOFF_INT_ST_S  10

/* UART_SW_XON_INT_ST : RO; bitpos: [9]; default: 0;
 * This is the status bit for sw_xon_int_raw when sw_xon_int_ena is set to 1.
 */

#define UART_SW_XON_INT_ST    (BIT(9))
#define UART_SW_XON_INT_ST_M  (UART_SW_XON_INT_ST_V << UART_SW_XON_INT_ST_S)
#define UART_SW_XON_INT_ST_V  0x00000001
#define UART_SW_XON_INT_ST_S  9

/* UART_RXFIFO_TOUT_INT_ST : RO; bitpos: [8]; default: 0;
 * This is the status bit for rxfifo_tout_int_raw when rxfifo_tout_int_ena
 * is set to 1.
 */

#define UART_RXFIFO_TOUT_INT_ST    (BIT(8))
#define UART_RXFIFO_TOUT_INT_ST_M  (UART_RXFIFO_TOUT_INT_ST_V << UART_RXFIFO_TOUT_INT_ST_S)
#define UART_RXFIFO_TOUT_INT_ST_V  0x00000001
#define UART_RXFIFO_TOUT_INT_ST_S  8

/* UART_BRK_DET_INT_ST : RO; bitpos: [7]; default: 0;
 * This is the status bit for brk_det_int_raw when brk_det_int_ena is set to
 * 1.
 */

#define UART_BRK_DET_INT_ST    (BIT(7))
#define UART_BRK_DET_INT_ST_M  (UART_BRK_DET_INT_ST_V << UART_BRK_DET_INT_ST_S)
#define UART_BRK_DET_INT_ST_V  0x00000001
#define UART_BRK_DET_INT_ST_S  7

/* UART_CTS_CHG_INT_ST : RO; bitpos: [6]; default: 0;
 * This is the status bit for cts_chg_int_raw when cts_chg_int_ena is set to
 * 1.
 */

#define UART_CTS_CHG_INT_ST    (BIT(6))
#define UART_CTS_CHG_INT_ST_M  (UART_CTS_CHG_INT_ST_V << UART_CTS_CHG_INT_ST_S)
#define UART_CTS_CHG_INT_ST_V  0x00000001
#define UART_CTS_CHG_INT_ST_S  6

/* UART_DSR_CHG_INT_ST : RO; bitpos: [5]; default: 0;
 * This is the status bit for dsr_chg_int_raw when dsr_chg_int_ena is set to
 * 1.
 */

#define UART_DSR_CHG_INT_ST    (BIT(5))
#define UART_DSR_CHG_INT_ST_M  (UART_DSR_CHG_INT_ST_V << UART_DSR_CHG_INT_ST_S)
#define UART_DSR_CHG_INT_ST_V  0x00000001
#define UART_DSR_CHG_INT_ST_S  5

/* UART_RXFIFO_OVF_INT_ST : RO; bitpos: [4]; default: 0;
 * This is the status bit for rxfifo_ovf_int_raw when rxfifo_ovf_int_ena is
 * set to 1.
 */

#define UART_RXFIFO_OVF_INT_ST    (BIT(4))
#define UART_RXFIFO_OVF_INT_ST_M  (UART_RXFIFO_OVF_INT_ST_V << UART_RXFIFO_OVF_INT_ST_S)
#define UART_RXFIFO_OVF_INT_ST_V  0x00000001
#define UART_RXFIFO_OVF_INT_ST_S  4

/* UART_FRM_ERR_INT_ST : RO; bitpos: [3]; default: 0;
 * This is the status bit for frm_err_int_raw when frm_err_int_ena is set to
 * 1.
 */

#define UART_FRM_ERR_INT_ST    (BIT(3))
#define UART_FRM_ERR_INT_ST_M  (UART_FRM_ERR_INT_ST_V << UART_FRM_ERR_INT_ST_S)
#define UART_FRM_ERR_INT_ST_V  0x00000001
#define UART_FRM_ERR_INT_ST_S  3

/* UART_PARITY_ERR_INT_ST : RO; bitpos: [2]; default: 0;
 * This is the status bit for parity_err_int_raw when parity_err_int_ena is
 * set to 1.
 */

#define UART_PARITY_ERR_INT_ST    (BIT(2))
#define UART_PARITY_ERR_INT_ST_M  (UART_PARITY_ERR_INT_ST_V << UART_PARITY_ERR_INT_ST_S)
#define UART_PARITY_ERR_INT_ST_V  0x00000001
#define UART_PARITY_ERR_INT_ST_S  2

/* UART_TXFIFO_EMPTY_INT_ST : RO; bitpos: [1]; default: 0;
 * This is the status bit for  txfifo_empty_int_raw  when
 * txfifo_empty_int_ena is set to 1.
 */

#define UART_TXFIFO_EMPTY_INT_ST    (BIT(1))
#define UART_TXFIFO_EMPTY_INT_ST_M  (UART_TXFIFO_EMPTY_INT_ST_V << UART_TXFIFO_EMPTY_INT_ST_S)
#define UART_TXFIFO_EMPTY_INT_ST_V  0x00000001
#define UART_TXFIFO_EMPTY_INT_ST_S  1

/* UART_RXFIFO_FULL_INT_ST : RO; bitpos: [0]; default: 0;
 * This is the status bit for rxfifo_full_int_raw when rxfifo_full_int_ena
 * is set to 1.
 */

#define UART_RXFIFO_FULL_INT_ST    (BIT(0))
#define UART_RXFIFO_FULL_INT_ST_M  (UART_RXFIFO_FULL_INT_ST_V << UART_RXFIFO_FULL_INT_ST_S)
#define UART_RXFIFO_FULL_INT_ST_V  0x00000001
#define UART_RXFIFO_FULL_INT_ST_S  0

/* UART_INT_ENA_REG register
 * Interrupt enable bits
 */

#define UART_INT_ENA_REG(i) (REG_UART_BASE(i) + 0xc)

/* UART_WAKEUP_INT_ENA : R/W; bitpos: [19]; default: 0;
 * This is the enable bit for uart_wakeup_int_st register.
 */

#define UART_WAKEUP_INT_ENA    (BIT(19))
#define UART_WAKEUP_INT_ENA_M  (UART_WAKEUP_INT_ENA_V << UART_WAKEUP_INT_ENA_S)
#define UART_WAKEUP_INT_ENA_V  0x00000001
#define UART_WAKEUP_INT_ENA_S  19

/* UART_AT_CMD_CHAR_DET_INT_ENA : R/W; bitpos: [18]; default: 0;
 * This is the enable bit for at_cmd_char_det_int_st register.
 */

#define UART_AT_CMD_CHAR_DET_INT_ENA    (BIT(18))
#define UART_AT_CMD_CHAR_DET_INT_ENA_M  (UART_AT_CMD_CHAR_DET_INT_ENA_V << UART_AT_CMD_CHAR_DET_INT_ENA_S)
#define UART_AT_CMD_CHAR_DET_INT_ENA_V  0x00000001
#define UART_AT_CMD_CHAR_DET_INT_ENA_S  18

/* UART_RS485_CLASH_INT_ENA : R/W; bitpos: [17]; default: 0;
 * This is the enable bit for rs485_clash_int_st register.
 */

#define UART_RS485_CLASH_INT_ENA    (BIT(17))
#define UART_RS485_CLASH_INT_ENA_M  (UART_RS485_CLASH_INT_ENA_V << UART_RS485_CLASH_INT_ENA_S)
#define UART_RS485_CLASH_INT_ENA_V  0x00000001
#define UART_RS485_CLASH_INT_ENA_S  17

/* UART_RS485_FRM_ERR_INT_ENA : R/W; bitpos: [16]; default: 0;
 * This is the enable bit for rs485_parity_err_int_st register.
 */

#define UART_RS485_FRM_ERR_INT_ENA    (BIT(16))
#define UART_RS485_FRM_ERR_INT_ENA_M  (UART_RS485_FRM_ERR_INT_ENA_V << UART_RS485_FRM_ERR_INT_ENA_S)
#define UART_RS485_FRM_ERR_INT_ENA_V  0x00000001
#define UART_RS485_FRM_ERR_INT_ENA_S  16

/* UART_RS485_PARITY_ERR_INT_ENA : R/W; bitpos: [15]; default: 0;
 * This is the enable bit for rs485_parity_err_int_st register.
 */

#define UART_RS485_PARITY_ERR_INT_ENA    (BIT(15))
#define UART_RS485_PARITY_ERR_INT_ENA_M  (UART_RS485_PARITY_ERR_INT_ENA_V << UART_RS485_PARITY_ERR_INT_ENA_S)
#define UART_RS485_PARITY_ERR_INT_ENA_V  0x00000001
#define UART_RS485_PARITY_ERR_INT_ENA_S  15

/* UART_TX_DONE_INT_ENA : R/W; bitpos: [14]; default: 0;
 * This is the enable bit for tx_done_int_st register.
 */

#define UART_TX_DONE_INT_ENA    (BIT(14))
#define UART_TX_DONE_INT_ENA_M  (UART_TX_DONE_INT_ENA_V << UART_TX_DONE_INT_ENA_S)
#define UART_TX_DONE_INT_ENA_V  0x00000001
#define UART_TX_DONE_INT_ENA_S  14

/* UART_TX_BRK_IDLE_DONE_INT_ENA : R/W; bitpos: [13]; default: 0;
 * This is the enable bit for tx_brk_idle_done_int_st register.
 */

#define UART_TX_BRK_IDLE_DONE_INT_ENA    (BIT(13))
#define UART_TX_BRK_IDLE_DONE_INT_ENA_M  (UART_TX_BRK_IDLE_DONE_INT_ENA_V << UART_TX_BRK_IDLE_DONE_INT_ENA_S)
#define UART_TX_BRK_IDLE_DONE_INT_ENA_V  0x00000001
#define UART_TX_BRK_IDLE_DONE_INT_ENA_S  13

/* UART_TX_BRK_DONE_INT_ENA : R/W; bitpos: [12]; default: 0;
 * This is the enable bit for tx_brk_done_int_st register.
 */

#define UART_TX_BRK_DONE_INT_ENA    (BIT(12))
#define UART_TX_BRK_DONE_INT_ENA_M  (UART_TX_BRK_DONE_INT_ENA_V << UART_TX_BRK_DONE_INT_ENA_S)
#define UART_TX_BRK_DONE_INT_ENA_V  0x00000001
#define UART_TX_BRK_DONE_INT_ENA_S  12

/* UART_GLITCH_DET_INT_ENA : R/W; bitpos: [11]; default: 0;
 * This is the enable bit for glitch_det_int_st register.
 */

#define UART_GLITCH_DET_INT_ENA    (BIT(11))
#define UART_GLITCH_DET_INT_ENA_M  (UART_GLITCH_DET_INT_ENA_V << UART_GLITCH_DET_INT_ENA_S)
#define UART_GLITCH_DET_INT_ENA_V  0x00000001
#define UART_GLITCH_DET_INT_ENA_S  11

/* UART_SW_XOFF_INT_ENA : R/W; bitpos: [10]; default: 0;
 * This is the enable bit for sw_xoff_int_st register.
 */

#define UART_SW_XOFF_INT_ENA    (BIT(10))
#define UART_SW_XOFF_INT_ENA_M  (UART_SW_XOFF_INT_ENA_V << UART_SW_XOFF_INT_ENA_S)
#define UART_SW_XOFF_INT_ENA_V  0x00000001
#define UART_SW_XOFF_INT_ENA_S  10

/* UART_SW_XON_INT_ENA : R/W; bitpos: [9]; default: 0;
 * This is the enable bit for sw_xon_int_st register.
 */

#define UART_SW_XON_INT_ENA    (BIT(9))
#define UART_SW_XON_INT_ENA_M  (UART_SW_XON_INT_ENA_V << UART_SW_XON_INT_ENA_S)
#define UART_SW_XON_INT_ENA_V  0x00000001
#define UART_SW_XON_INT_ENA_S  9

/* UART_RXFIFO_TOUT_INT_ENA : R/W; bitpos: [8]; default: 0;
 * This is the enable bit for rxfifo_tout_int_st register.
 */

#define UART_RXFIFO_TOUT_INT_ENA    (BIT(8))
#define UART_RXFIFO_TOUT_INT_ENA_M  (UART_RXFIFO_TOUT_INT_ENA_V << UART_RXFIFO_TOUT_INT_ENA_S)
#define UART_RXFIFO_TOUT_INT_ENA_V  0x00000001
#define UART_RXFIFO_TOUT_INT_ENA_S  8

/* UART_BRK_DET_INT_ENA : R/W; bitpos: [7]; default: 0;
 * This is the enable bit for brk_det_int_st register.
 */

#define UART_BRK_DET_INT_ENA    (BIT(7))
#define UART_BRK_DET_INT_ENA_M  (UART_BRK_DET_INT_ENA_V << UART_BRK_DET_INT_ENA_S)
#define UART_BRK_DET_INT_ENA_V  0x00000001
#define UART_BRK_DET_INT_ENA_S  7

/* UART_CTS_CHG_INT_ENA : R/W; bitpos: [6]; default: 0;
 * This is the enable bit for cts_chg_int_st register.
 */

#define UART_CTS_CHG_INT_ENA    (BIT(6))
#define UART_CTS_CHG_INT_ENA_M  (UART_CTS_CHG_INT_ENA_V << UART_CTS_CHG_INT_ENA_S)
#define UART_CTS_CHG_INT_ENA_V  0x00000001
#define UART_CTS_CHG_INT_ENA_S  6

/* UART_DSR_CHG_INT_ENA : R/W; bitpos: [5]; default: 0;
 * This is the enable bit for dsr_chg_int_st register.
 */

#define UART_DSR_CHG_INT_ENA    (BIT(5))
#define UART_DSR_CHG_INT_ENA_M  (UART_DSR_CHG_INT_ENA_V << UART_DSR_CHG_INT_ENA_S)
#define UART_DSR_CHG_INT_ENA_V  0x00000001
#define UART_DSR_CHG_INT_ENA_S  5

/* UART_RXFIFO_OVF_INT_ENA : R/W; bitpos: [4]; default: 0;
 * This is the enable bit for rxfifo_ovf_int_st register.
 */

#define UART_RXFIFO_OVF_INT_ENA    (BIT(4))
#define UART_RXFIFO_OVF_INT_ENA_M  (UART_RXFIFO_OVF_INT_ENA_V << UART_RXFIFO_OVF_INT_ENA_S)
#define UART_RXFIFO_OVF_INT_ENA_V  0x00000001
#define UART_RXFIFO_OVF_INT_ENA_S  4

/* UART_FRM_ERR_INT_ENA : R/W; bitpos: [3]; default: 0;
 * This is the enable bit for frm_err_int_st register.
 */

#define UART_FRM_ERR_INT_ENA    (BIT(3))
#define UART_FRM_ERR_INT_ENA_M  (UART_FRM_ERR_INT_ENA_V << UART_FRM_ERR_INT_ENA_S)
#define UART_FRM_ERR_INT_ENA_V  0x00000001
#define UART_FRM_ERR_INT_ENA_S  3

/* UART_PARITY_ERR_INT_ENA : R/W; bitpos: [2]; default: 0;
 * This is the enable bit for parity_err_int_st register.
 */

#define UART_PARITY_ERR_INT_ENA    (BIT(2))
#define UART_PARITY_ERR_INT_ENA_M  (UART_PARITY_ERR_INT_ENA_V << UART_PARITY_ERR_INT_ENA_S)
#define UART_PARITY_ERR_INT_ENA_V  0x00000001
#define UART_PARITY_ERR_INT_ENA_S  2

/* UART_TXFIFO_EMPTY_INT_ENA : R/W; bitpos: [1]; default: 0;
 * This is the enable bit for txfifo_empty_int_st register.
 */

#define UART_TXFIFO_EMPTY_INT_ENA    (BIT(1))
#define UART_TXFIFO_EMPTY_INT_ENA_M  (UART_TXFIFO_EMPTY_INT_ENA_V << UART_TXFIFO_EMPTY_INT_ENA_S)
#define UART_TXFIFO_EMPTY_INT_ENA_V  0x00000001
#define UART_TXFIFO_EMPTY_INT_ENA_S  1

/* UART_RXFIFO_FULL_INT_ENA : R/W; bitpos: [0]; default: 0;
 * This is the enable bit for rxfifo_full_int_st register.
 */

#define UART_RXFIFO_FULL_INT_ENA    (BIT(0))
#define UART_RXFIFO_FULL_INT_ENA_M  (UART_RXFIFO_FULL_INT_ENA_V << UART_RXFIFO_FULL_INT_ENA_S)
#define UART_RXFIFO_FULL_INT_ENA_V  0x00000001
#define UART_RXFIFO_FULL_INT_ENA_S  0

/* UART_WAKEUP_INT_CLR : WT; bitpos: [19]; default: 0;
 * Set this bit to clear the uart_wakeup_int_raw interrupt.
 */

#define UART_WAKEUP_INT_CLR    (BIT(19))
#define UART_WAKEUP_INT_CLR_M  (UART_WAKEUP_INT_CLR_V << UART_WAKEUP_INT_CLR_S)
#define UART_WAKEUP_INT_CLR_V  0x00000001
#define UART_WAKEUP_INT_CLR_S  19

/* UART_AT_CMD_CHAR_DET_INT_CLR : WT; bitpos: [18]; default: 0;
 * Set this bit to clear the at_cmd_char_det_int_raw interrupt.
 */

#define UART_AT_CMD_CHAR_DET_INT_CLR    (BIT(18))
#define UART_AT_CMD_CHAR_DET_INT_CLR_M  (UART_AT_CMD_CHAR_DET_INT_CLR_V << UART_AT_CMD_CHAR_DET_INT_CLR_S)
#define UART_AT_CMD_CHAR_DET_INT_CLR_V  0x00000001
#define UART_AT_CMD_CHAR_DET_INT_CLR_S  18

/* UART_RS485_CLASH_INT_CLR : WT; bitpos: [17]; default: 0;
 * Set this bit to clear the rs485_clash_int_raw interrupt.
 */

#define UART_RS485_CLASH_INT_CLR    (BIT(17))
#define UART_RS485_CLASH_INT_CLR_M  (UART_RS485_CLASH_INT_CLR_V << UART_RS485_CLASH_INT_CLR_S)
#define UART_RS485_CLASH_INT_CLR_V  0x00000001
#define UART_RS485_CLASH_INT_CLR_S  17

/* UART_RS485_FRM_ERR_INT_CLR : WT; bitpos: [16]; default: 0;
 * Set this bit to clear the rs485_frm_err_int_raw interrupt.
 */

#define UART_RS485_FRM_ERR_INT_CLR    (BIT(16))
#define UART_RS485_FRM_ERR_INT_CLR_M  (UART_RS485_FRM_ERR_INT_CLR_V << UART_RS485_FRM_ERR_INT_CLR_S)
#define UART_RS485_FRM_ERR_INT_CLR_V  0x00000001
#define UART_RS485_FRM_ERR_INT_CLR_S  16

/* UART_RS485_PARITY_ERR_INT_CLR : WT; bitpos: [15]; default: 0;
 * Set this bit to clear the rs485_parity_err_int_raw interrupt.
 */

#define UART_RS485_PARITY_ERR_INT_CLR    (BIT(15))
#define UART_RS485_PARITY_ERR_INT_CLR_M  (UART_RS485_PARITY_ERR_INT_CLR_V << UART_RS485_PARITY_ERR_INT_CLR_S)
#define UART_RS485_PARITY_ERR_INT_CLR_V  0x00000001
#define UART_RS485_PARITY_ERR_INT_CLR_S  15

/* UART_TX_DONE_INT_CLR : WT; bitpos: [14]; default: 0;
 * Set this bit to clear the tx_done_int_raw interrupt.
 */

#define UART_TX_DONE_INT_CLR    (BIT(14))
#define UART_TX_DONE_INT_CLR_M  (UART_TX_DONE_INT_CLR_V << UART_TX_DONE_INT_CLR_S)
#define UART_TX_DONE_INT_CLR_V  0x00000001
#define UART_TX_DONE_INT_CLR_S  14

/* UART_TX_BRK_IDLE_DONE_INT_CLR : WT; bitpos: [13]; default: 0;
 * Set this bit to clear the tx_brk_idle_done_int_raw interrupt.
 */

#define UART_TX_BRK_IDLE_DONE_INT_CLR    (BIT(13))
#define UART_TX_BRK_IDLE_DONE_INT_CLR_M  (UART_TX_BRK_IDLE_DONE_INT_CLR_V << UART_TX_BRK_IDLE_DONE_INT_CLR_S)
#define UART_TX_BRK_IDLE_DONE_INT_CLR_V  0x00000001
#define UART_TX_BRK_IDLE_DONE_INT_CLR_S  13

/* UART_TX_BRK_DONE_INT_CLR : WT; bitpos: [12]; default: 0;
 * Set this bit to clear the tx_brk_done_int_raw interrupt..
 */

#define UART_TX_BRK_DONE_INT_CLR    (BIT(12))
#define UART_TX_BRK_DONE_INT_CLR_M  (UART_TX_BRK_DONE_INT_CLR_V << UART_TX_BRK_DONE_INT_CLR_S)
#define UART_TX_BRK_DONE_INT_CLR_V  0x00000001
#define UART_TX_BRK_DONE_INT_CLR_S  12

/* UART_GLITCH_DET_INT_CLR : WT; bitpos: [11]; default: 0;
 * Set this bit to clear the glitch_det_int_raw interrupt.
 */

#define UART_GLITCH_DET_INT_CLR    (BIT(11))
#define UART_GLITCH_DET_INT_CLR_M  (UART_GLITCH_DET_INT_CLR_V << UART_GLITCH_DET_INT_CLR_S)
#define UART_GLITCH_DET_INT_CLR_V  0x00000001
#define UART_GLITCH_DET_INT_CLR_S  11

/* UART_SW_XOFF_INT_CLR : WT; bitpos: [10]; default: 0;
 * Set this bit to clear the sw_xoff_int_raw interrupt.
 */

#define UART_SW_XOFF_INT_CLR    (BIT(10))
#define UART_SW_XOFF_INT_CLR_M  (UART_SW_XOFF_INT_CLR_V << UART_SW_XOFF_INT_CLR_S)
#define UART_SW_XOFF_INT_CLR_V  0x00000001
#define UART_SW_XOFF_INT_CLR_S  10

/* UART_SW_XON_INT_CLR : WT; bitpos: [9]; default: 0;
 * Set this bit to clear the sw_xon_int_raw interrupt.
 */

#define UART_SW_XON_INT_CLR    (BIT(9))
#define UART_SW_XON_INT_CLR_M  (UART_SW_XON_INT_CLR_V << UART_SW_XON_INT_CLR_S)
#define UART_SW_XON_INT_CLR_V  0x00000001
#define UART_SW_XON_INT_CLR_S  9

/* UART_RXFIFO_TOUT_INT_CLR : WT; bitpos: [8]; default: 0;
 * Set this bit to clear the rxfifo_tout_int_raw interrupt.
 */

#define UART_RXFIFO_TOUT_INT_CLR    (BIT(8))
#define UART_RXFIFO_TOUT_INT_CLR_M  (UART_RXFIFO_TOUT_INT_CLR_V << UART_RXFIFO_TOUT_INT_CLR_S)
#define UART_RXFIFO_TOUT_INT_CLR_V  0x00000001
#define UART_RXFIFO_TOUT_INT_CLR_S  8

/* UART_BRK_DET_INT_CLR : WT; bitpos: [7]; default: 0;
 * Set this bit to clear the brk_det_int_raw interrupt.
 */

#define UART_BRK_DET_INT_CLR    (BIT(7))
#define UART_BRK_DET_INT_CLR_M  (UART_BRK_DET_INT_CLR_V << UART_BRK_DET_INT_CLR_S)
#define UART_BRK_DET_INT_CLR_V  0x00000001
#define UART_BRK_DET_INT_CLR_S  7

/* UART_CTS_CHG_INT_CLR : WT; bitpos: [6]; default: 0;
 * Set this bit to clear the cts_chg_int_raw interrupt.
 */

#define UART_CTS_CHG_INT_CLR    (BIT(6))
#define UART_CTS_CHG_INT_CLR_M  (UART_CTS_CHG_INT_CLR_V << UART_CTS_CHG_INT_CLR_S)
#define UART_CTS_CHG_INT_CLR_V  0x00000001
#define UART_CTS_CHG_INT_CLR_S  6

/* UART_DSR_CHG_INT_CLR : WT; bitpos: [5]; default: 0;
 * Set this bit to clear the dsr_chg_int_raw interrupt.
 */

#define UART_DSR_CHG_INT_CLR    (BIT(5))
#define UART_DSR_CHG_INT_CLR_M  (UART_DSR_CHG_INT_CLR_V << UART_DSR_CHG_INT_CLR_S)
#define UART_DSR_CHG_INT_CLR_V  0x00000001
#define UART_DSR_CHG_INT_CLR_S  5

/* UART_RXFIFO_OVF_INT_CLR : WT; bitpos: [4]; default: 0;
 * Set this bit to clear rxfifo_ovf_int_raw interrupt.
 */

#define UART_RXFIFO_OVF_INT_CLR    (BIT(4))
#define UART_RXFIFO_OVF_INT_CLR_M  (UART_RXFIFO_OVF_INT_CLR_V << UART_RXFIFO_OVF_INT_CLR_S)
#define UART_RXFIFO_OVF_INT_CLR_V  0x00000001
#define UART_RXFIFO_OVF_INT_CLR_S  4

/* UART_FRM_ERR_INT_CLR : WT; bitpos: [3]; default: 0;
 * Set this bit to clear frm_err_int_raw interrupt.
 */

#define UART_FRM_ERR_INT_CLR    (BIT(3))
#define UART_FRM_ERR_INT_CLR_M  (UART_FRM_ERR_INT_CLR_V << UART_FRM_ERR_INT_CLR_S)
#define UART_FRM_ERR_INT_CLR_V  0x00000001
#define UART_FRM_ERR_INT_CLR_S  3

/* UART_PARITY_ERR_INT_CLR : WT; bitpos: [2]; default: 0;
 * Set this bit to clear parity_err_int_raw interrupt.
 */

#define UART_PARITY_ERR_INT_CLR    (BIT(2))
#define UART_PARITY_ERR_INT_CLR_M  (UART_PARITY_ERR_INT_CLR_V << UART_PARITY_ERR_INT_CLR_S)
#define UART_PARITY_ERR_INT_CLR_V  0x00000001
#define UART_PARITY_ERR_INT_CLR_S  2

/* UART_TXFIFO_EMPTY_INT_CLR : WT; bitpos: [1]; default: 0;
 * Set this bit to clear txfifo_empty_int_raw interrupt.
 */

#define UART_TXFIFO_EMPTY_INT_CLR    (BIT(1))
#define UART_TXFIFO_EMPTY_INT_CLR_M  (UART_TXFIFO_EMPTY_INT_CLR_V << UART_TXFIFO_EMPTY_INT_CLR_S)
#define UART_TXFIFO_EMPTY_INT_CLR_V  0x00000001
#define UART_TXFIFO_EMPTY_INT_CLR_S  1

/* UART_INT_CLR_REG register
 *  Interrupt clear bits
 */

#define UART_INT_CLR_REG(i) (REG_UART_BASE(i) + 0x10)

/* UART_RXFIFO_FULL_INT_CLR : WT; bitpos: [0]; default: 0;
 * Set this bit to clear the rxfifo_full_int_raw interrupt.
 */

#define UART_RXFIFO_FULL_INT_CLR    (BIT(0))
#define UART_RXFIFO_FULL_INT_CLR_M  (UART_RXFIFO_FULL_INT_CLR_V << UART_RXFIFO_FULL_INT_CLR_S)
#define UART_RXFIFO_FULL_INT_CLR_V  0x00000001
#define UART_RXFIFO_FULL_INT_CLR_S  0

/* UART_CLKDIV_REG register
 * Clock divider configuration
 */

#define UART_CLKDIV_REG(i) (REG_UART_BASE(i) + 0x14)

/* UART_CLKDIV_FRAG : R/W; bitpos: [23:20]; default: 0;
 * The decimal part of the frequency divider factor.
 */

#define UART_CLKDIV_FRAG    0x0000000f
#define UART_CLKDIV_FRAG_M  (UART_CLKDIV_FRAG_V << UART_CLKDIV_FRAG_S)
#define UART_CLKDIV_FRAG_V  0x0000000f
#define UART_CLKDIV_FRAG_S  20

/* Configuration Register */

/* UART_CLKDIV : R/W; bitpos: [11:0]; default: 694;
 * The integral part of the frequency divider factor.
 */

#define UART_CLKDIV    0x00000fff
#define UART_CLKDIV_M  (UART_CLKDIV_V << UART_CLKDIV_S)
#define UART_CLKDIV_V  0x00000fff
#define UART_CLKDIV_S  0

/* UART_RX_FILT_REG register
 * Rx Filter configuration
 */

#define UART_RX_FILT_REG(i) (REG_UART_BASE(i) + 0x18)

/* UART_GLITCH_FILT_EN : R/W; bitpos: [8]; default: 0;
 * Set this bit to enable Rx signal filter.
 */

#define UART_GLITCH_FILT_EN    (BIT(8))
#define UART_GLITCH_FILT_EN_M  (UART_GLITCH_FILT_EN_V << UART_GLITCH_FILT_EN_S)
#define UART_GLITCH_FILT_EN_V  0x00000001
#define UART_GLITCH_FILT_EN_S  8

/* UART_GLITCH_FILT : R/W; bitpos: [7:0]; default: 8;
 * when input pulse width is lower than this value, the pulse is ignored.
 */

#define UART_GLITCH_FILT    0x000000ff
#define UART_GLITCH_FILT_M  (UART_GLITCH_FILT_V << UART_GLITCH_FILT_S)
#define UART_GLITCH_FILT_V  0x000000ff
#define UART_GLITCH_FILT_S  0

/* UART_STATUS_REG register
 * UART status register
 */

#define UART_STATUS_REG(i) (REG_UART_BASE(i) + 0x1c)

/* UART_TXD : RO; bitpos: [31]; default: 1;
 * This bit represents the  level of the internal uart txd signal.
 */

#define UART_TXD    (BIT(31))
#define UART_TXD_M  (UART_TXD_V << UART_TXD_S)
#define UART_TXD_V  0x00000001
#define UART_TXD_S  31

/* UART_RTSN : RO; bitpos: [30]; default: 1;
 * This bit represents the level of the internal uart rts signal.
 */

#define UART_RTSN    (BIT(30))
#define UART_RTSN_M  (UART_RTSN_V << UART_RTSN_S)
#define UART_RTSN_V  0x00000001
#define UART_RTSN_S  30

/* UART_DTRN : RO; bitpos: [29]; default: 1;
 * This bit represents the level of the internal uart dtr signal.
 */

#define UART_DTRN    (BIT(29))
#define UART_DTRN_M  (UART_DTRN_V << UART_DTRN_S)
#define UART_DTRN_V  0x00000001
#define UART_DTRN_S  29

/* UART_TXFIFO_CNT : RO; bitpos: [25:16]; default: 0;
 * Stores the byte number of data in Tx-FIFO.
 */

#define UART_TXFIFO_CNT    0x000003ff
#define UART_TXFIFO_CNT_M  (UART_TXFIFO_CNT_V << UART_TXFIFO_CNT_S)
#define UART_TXFIFO_CNT_V  0x000003ff
#define UART_TXFIFO_CNT_S  16

/* UART_RXD : RO; bitpos: [15]; default: 1;
 * This register represent the  level value of the internal uart rxd signal.
 */

#define UART_RXD    (BIT(15))
#define UART_RXD_M  (UART_RXD_V << UART_RXD_S)
#define UART_RXD_V  0x00000001
#define UART_RXD_S  15

/* UART_CTSN : RO; bitpos: [14]; default: 1;
 * This register represent the level value of the internal uart cts signal.
 */

#define UART_CTSN    (BIT(14))
#define UART_CTSN_M  (UART_CTSN_V << UART_CTSN_S)
#define UART_CTSN_V  0x00000001
#define UART_CTSN_S  14

/* UART_DSRN : RO; bitpos: [13]; default: 0;
 * The register represent the level value of the internal uart dsr signal.
 */

#define UART_DSRN    (BIT(13))
#define UART_DSRN_M  (UART_DSRN_V << UART_DSRN_S)
#define UART_DSRN_V  0x00000001
#define UART_DSRN_S  13

/* UART_RXFIFO_CNT : RO; bitpos: [9:0]; default: 0;
 * Stores the byte number of valid data in Rx-FIFO.
 */

#define UART_RXFIFO_CNT    0x000003ff
#define UART_RXFIFO_CNT_M  (UART_RXFIFO_CNT_V << UART_RXFIFO_CNT_S)
#define UART_RXFIFO_CNT_V  0x000003ff
#define UART_RXFIFO_CNT_S  0

/* UART_CONF0_REG register
 * a
 */

#define UART_CONF0_REG(i) (REG_UART_BASE(i) + 0x20)

/* UART_MEM_CLK_EN : R/W; bitpos: [28]; default: 1;
 * UART memory clock gate enable signal.
 */

#define UART_MEM_CLK_EN    (BIT(28))
#define UART_MEM_CLK_EN_M  (UART_MEM_CLK_EN_V << UART_MEM_CLK_EN_S)
#define UART_MEM_CLK_EN_V  0x00000001
#define UART_MEM_CLK_EN_S  28

/* UART_AUTOBAUD_EN : R/W; bitpos: [27]; default: 0;
 * This is the enable bit for detecting baudrate.
 */

#define UART_AUTOBAUD_EN    (BIT(27))
#define UART_AUTOBAUD_EN_M  (UART_AUTOBAUD_EN_V << UART_AUTOBAUD_EN_S)
#define UART_AUTOBAUD_EN_V  0x00000001
#define UART_AUTOBAUD_EN_S  27

/* UART_ERR_WR_MASK : R/W; bitpos: [26]; default: 0;
 * 1'h1: Receiver stops storing data into FIFO when data is wrong. 1'h0:
 * Receiver stores the data even if the  received data is wrong.
 */

#define UART_ERR_WR_MASK    (BIT(26))
#define UART_ERR_WR_MASK_M  (UART_ERR_WR_MASK_V << UART_ERR_WR_MASK_S)
#define UART_ERR_WR_MASK_V  0x00000001
#define UART_ERR_WR_MASK_S  26

/* UART_CLK_EN : R/W; bitpos: [25]; default: 0;
 * 1'h1: Force clock on for register. 1'h0: Support clock only when
 * application writes registers.
 */

#define UART_CLK_EN    (BIT(25))
#define UART_CLK_EN_M  (UART_CLK_EN_V << UART_CLK_EN_S)
#define UART_CLK_EN_V  0x00000001
#define UART_CLK_EN_S  25

/* UART_DTR_INV : R/W; bitpos: [24]; default: 0;
 * Set this bit to inverse the level value of uart dtr signal.
 */

#define UART_DTR_INV    (BIT(24))
#define UART_DTR_INV_M  (UART_DTR_INV_V << UART_DTR_INV_S)
#define UART_DTR_INV_V  0x00000001
#define UART_DTR_INV_S  24

/* UART_RTS_INV : R/W; bitpos: [23]; default: 0;
 * Set this bit to inverse the level value of uart rts signal.
 */

#define UART_RTS_INV    (BIT(23))
#define UART_RTS_INV_M  (UART_RTS_INV_V << UART_RTS_INV_S)
#define UART_RTS_INV_V  0x00000001
#define UART_RTS_INV_S  23

/* UART_TXD_INV : R/W; bitpos: [22]; default: 0;
 * Set this bit to inverse the level value of uart txd signal.
 */

#define UART_TXD_INV    (BIT(22))
#define UART_TXD_INV_M  (UART_TXD_INV_V << UART_TXD_INV_S)
#define UART_TXD_INV_V  0x00000001
#define UART_TXD_INV_S  22

/* UART_DSR_INV : R/W; bitpos: [21]; default: 0;
 * Set this bit to inverse the level value of uart dsr signal.
 */

#define UART_DSR_INV    (BIT(21))
#define UART_DSR_INV_M  (UART_DSR_INV_V << UART_DSR_INV_S)
#define UART_DSR_INV_V  0x00000001
#define UART_DSR_INV_S  21

/* UART_CTS_INV : R/W; bitpos: [20]; default: 0;
 * Set this bit to inverse the level value of uart cts signal.
 */

#define UART_CTS_INV    (BIT(20))
#define UART_CTS_INV_M  (UART_CTS_INV_V << UART_CTS_INV_S)
#define UART_CTS_INV_V  0x00000001
#define UART_CTS_INV_S  20

/* UART_RXD_INV : R/W; bitpos: [19]; default: 0;
 * Set this bit to inverse the level value of uart rxd signal.
 */

#define UART_RXD_INV    (BIT(19))
#define UART_RXD_INV_M  (UART_RXD_INV_V << UART_RXD_INV_S)
#define UART_RXD_INV_V  0x00000001
#define UART_RXD_INV_S  19

/* UART_TXFIFO_RST : R/W; bitpos: [18]; default: 0;
 * Set this bit to reset the uart transmit-FIFO.
 */

#define UART_TXFIFO_RST    (BIT(18))
#define UART_TXFIFO_RST_M  (UART_TXFIFO_RST_V << UART_TXFIFO_RST_S)
#define UART_TXFIFO_RST_V  0x00000001
#define UART_TXFIFO_RST_S  18

/* UART_RXFIFO_RST : R/W; bitpos: [17]; default: 0;
 * Set this bit to reset the uart receive-FIFO.
 */

#define UART_RXFIFO_RST    (BIT(17))
#define UART_RXFIFO_RST_M  (UART_RXFIFO_RST_V << UART_RXFIFO_RST_S)
#define UART_RXFIFO_RST_V  0x00000001
#define UART_RXFIFO_RST_S  17

/* UART_IRDA_EN : R/W; bitpos: [16]; default: 0;
 * Set this bit to enable IrDA protocol.
 */

#define UART_IRDA_EN    (BIT(16))
#define UART_IRDA_EN_M  (UART_IRDA_EN_V << UART_IRDA_EN_S)
#define UART_IRDA_EN_V  0x00000001
#define UART_IRDA_EN_S  16

/* UART_TX_FLOW_EN : R/W; bitpos: [15]; default: 0;
 * Set this bit to enable flow control function for transmitter.
 */

#define UART_TX_FLOW_EN    (BIT(15))
#define UART_TX_FLOW_EN_M  (UART_TX_FLOW_EN_V << UART_TX_FLOW_EN_S)
#define UART_TX_FLOW_EN_V  0x00000001
#define UART_TX_FLOW_EN_S  15

/* UART_LOOPBACK : R/W; bitpos: [14]; default: 0;
 * Set this bit to enable uart loopback test mode.
 */

#define UART_LOOPBACK    (BIT(14))
#define UART_LOOPBACK_M  (UART_LOOPBACK_V << UART_LOOPBACK_S)
#define UART_LOOPBACK_V  0x00000001
#define UART_LOOPBACK_S  14

/* UART_IRDA_RX_INV : R/W; bitpos: [13]; default: 0;
 * Set this bit to invert the level of IrDA receiver.
 */

#define UART_IRDA_RX_INV    (BIT(13))
#define UART_IRDA_RX_INV_M  (UART_IRDA_RX_INV_V << UART_IRDA_RX_INV_S)
#define UART_IRDA_RX_INV_V  0x00000001
#define UART_IRDA_RX_INV_S  13

/* UART_IRDA_TX_INV : R/W; bitpos: [12]; default: 0;
 * Set this bit to invert the level of  IrDA transmitter.
 */

#define UART_IRDA_TX_INV    (BIT(12))
#define UART_IRDA_TX_INV_M  (UART_IRDA_TX_INV_V << UART_IRDA_TX_INV_S)
#define UART_IRDA_TX_INV_V  0x00000001
#define UART_IRDA_TX_INV_S  12

/* UART_IRDA_WCTL : R/W; bitpos: [11]; default: 0;
 * 1'h1: The IrDA transmitter's 11th bit is the same as 10th bit. 1'h0: Set
 * IrDA transmitter's 11th bit to 0.
 */

#define UART_IRDA_WCTL    (BIT(11))
#define UART_IRDA_WCTL_M  (UART_IRDA_WCTL_V << UART_IRDA_WCTL_S)
#define UART_IRDA_WCTL_V  0x00000001
#define UART_IRDA_WCTL_S  11

/* UART_IRDA_TX_EN : R/W; bitpos: [10]; default: 0;
 * This is the start enable bit for IrDA transmitter.
 */

#define UART_IRDA_TX_EN    (BIT(10))
#define UART_IRDA_TX_EN_M  (UART_IRDA_TX_EN_V << UART_IRDA_TX_EN_S)
#define UART_IRDA_TX_EN_V  0x00000001
#define UART_IRDA_TX_EN_S  10

/* UART_IRDA_DPLX : R/W; bitpos: [9]; default: 0;
 * Set this bit to enable IrDA loopback mode.
 */

#define UART_IRDA_DPLX    (BIT(9))
#define UART_IRDA_DPLX_M  (UART_IRDA_DPLX_V << UART_IRDA_DPLX_S)
#define UART_IRDA_DPLX_V  0x00000001
#define UART_IRDA_DPLX_S  9

/* UART_TXD_BRK : R/W; bitpos: [8]; default: 0;
 * Set this bit to enbale transmitter to  send NULL when the process of
 * sending data is done.
 */

#define UART_TXD_BRK    (BIT(8))
#define UART_TXD_BRK_M  (UART_TXD_BRK_V << UART_TXD_BRK_S)
#define UART_TXD_BRK_V  0x00000001
#define UART_TXD_BRK_S  8

/* UART_SW_DTR : R/W; bitpos: [7]; default: 0;
 * This register is used to configure the software dtr signal which is used
 * in software flow control.
 */

#define UART_SW_DTR    (BIT(7))
#define UART_SW_DTR_M  (UART_SW_DTR_V << UART_SW_DTR_S)
#define UART_SW_DTR_V  0x00000001
#define UART_SW_DTR_S  7

/* UART_SW_RTS : R/W; bitpos: [6]; default: 0;
 * This register is used to configure the software rts signal which is used
 * in software flow control.
 */

#define UART_SW_RTS    (BIT(6))
#define UART_SW_RTS_M  (UART_SW_RTS_V << UART_SW_RTS_S)
#define UART_SW_RTS_V  0x00000001
#define UART_SW_RTS_S  6

/* UART_STOP_BIT_NUM : R/W; bitpos: [5:4]; default: 1;
 * This register is used to set the length of  stop bit.
 */

#define UART_STOP_BIT_NUM    0x00000003
#define UART_STOP_BIT_NUM_M  (UART_STOP_BIT_NUM_V << UART_STOP_BIT_NUM_S)
#define UART_STOP_BIT_NUM_V  0x00000003
#define UART_STOP_BIT_NUM_S  4

/* UART_BIT_NUM : R/W; bitpos: [3:2]; default: 3;
 * This register is used to set the length of data.
 */

#define UART_BIT_NUM    0x00000003
#define UART_BIT_NUM_M  (UART_BIT_NUM_V << UART_BIT_NUM_S)
#define UART_BIT_NUM_V  0x00000003
#define UART_BIT_NUM_S  2

/* UART_PARITY_EN : R/W; bitpos: [1]; default: 0;
 * Set this bit to enable uart parity check.
 */

#define UART_PARITY_EN    (BIT(1))
#define UART_PARITY_EN_M  (UART_PARITY_EN_V << UART_PARITY_EN_S)
#define UART_PARITY_EN_V  0x00000001
#define UART_PARITY_EN_S  1

/* UART_PARITY : R/W; bitpos: [0]; default: 0;
 * This register is used to configure the parity check mode.
 */

#define UART_PARITY    (BIT(0))
#define UART_PARITY_M  (UART_PARITY_V << UART_PARITY_S)
#define UART_PARITY_V  0x00000001
#define UART_PARITY_S  0

/* UART_CONF1_REG register
 * Configuration register 1
 */

#define UART_CONF1_REG(i) (REG_UART_BASE(i) + 0x24)

/* UART_RX_TOUT_EN : R/W; bitpos: [23]; default: 0;
 * This is the enble bit for uart receiver's timeout function.
 */

#define UART_RX_TOUT_EN    (BIT(23))
#define UART_RX_TOUT_EN_M  (UART_RX_TOUT_EN_V << UART_RX_TOUT_EN_S)
#define UART_RX_TOUT_EN_V  0x00000001
#define UART_RX_TOUT_EN_S  23

/* UART_RX_FLOW_EN : R/W; bitpos: [22]; default: 0;
 * This is the flow enable bit for UART receiver.
 */

#define UART_RX_FLOW_EN    (BIT(22))
#define UART_RX_FLOW_EN_M  (UART_RX_FLOW_EN_V << UART_RX_FLOW_EN_S)
#define UART_RX_FLOW_EN_V  0x00000001
#define UART_RX_FLOW_EN_S  22

/* UART_RX_TOUT_FLOW_DIS : R/W; bitpos: [21]; default: 0;
 * Set this bit to stop accumulating idle_cnt when hardware flow control
 * works.
 */

#define UART_RX_TOUT_FLOW_DIS    (BIT(21))
#define UART_RX_TOUT_FLOW_DIS_M  (UART_RX_TOUT_FLOW_DIS_V << UART_RX_TOUT_FLOW_DIS_S)
#define UART_RX_TOUT_FLOW_DIS_V  0x00000001
#define UART_RX_TOUT_FLOW_DIS_S  21

/* UART_DIS_RX_DAT_OVF : R/W; bitpos: [20]; default: 0;
 * Disable UART Rx data overflow detect.
 */

#define UART_DIS_RX_DAT_OVF    (BIT(20))
#define UART_DIS_RX_DAT_OVF_M  (UART_DIS_RX_DAT_OVF_V << UART_DIS_RX_DAT_OVF_S)
#define UART_DIS_RX_DAT_OVF_V  0x00000001
#define UART_DIS_RX_DAT_OVF_S  20

/* UART_TXFIFO_EMPTY_THRHD : R/W; bitpos: [19:10]; default: 96;
 * It will produce txfifo_empty_int interrupt when the data amount in
 * Tx-FIFO is less than this register value.
 */

#define UART_TXFIFO_EMPTY_THRHD    0x000003ff
#define UART_TXFIFO_EMPTY_THRHD_M  (UART_TXFIFO_EMPTY_THRHD_V << UART_TXFIFO_EMPTY_THRHD_S)
#define UART_TXFIFO_EMPTY_THRHD_V  0x000003ff
#define UART_TXFIFO_EMPTY_THRHD_S  10

/* UART_RXFIFO_FULL_THRHD : R/W; bitpos: [9:0]; default: 96;
 * It will produce rxfifo_full_int interrupt when receiver receives more
 * data than this register value.
 */

#define UART_RXFIFO_FULL_THRHD    0x000003ff
#define UART_RXFIFO_FULL_THRHD_M  (UART_RXFIFO_FULL_THRHD_V << UART_RXFIFO_FULL_THRHD_S)
#define UART_RXFIFO_FULL_THRHD_V  0x000003ff
#define UART_RXFIFO_FULL_THRHD_S  0

/* UART_LOWPULSE_REG register
 * Autobaud minimum low pulse duration register
 */

#define UART_LOWPULSE_REG(i) (REG_UART_BASE(i) + 0x28)

/* UART_LOWPULSE_MIN_CNT : RO; bitpos: [11:0]; default: 4095;
 * This register stores the value of the minimum duration time of the low
 * level pulse. It is used in baud rate-detect process.
 */

#define UART_LOWPULSE_MIN_CNT    0x00000fff
#define UART_LOWPULSE_MIN_CNT_M  (UART_LOWPULSE_MIN_CNT_V << UART_LOWPULSE_MIN_CNT_S)
#define UART_LOWPULSE_MIN_CNT_V  0x00000fff
#define UART_LOWPULSE_MIN_CNT_S  0

/* UART_HIGHPULSE_REG register
 * Autobaud minimum high pulse duration register
 */

#define UART_HIGHPULSE_REG(i) (REG_UART_BASE(i) + 0x2c)

/* UART_HIGHPULSE_MIN_CNT : RO; bitpos: [11:0]; default: 4095;
 * This register stores  the value of the maximum duration time for the high
 * level pulse. It is used in baud rate-detect process.
 */

#define UART_HIGHPULSE_MIN_CNT    0x00000fff
#define UART_HIGHPULSE_MIN_CNT_M  (UART_HIGHPULSE_MIN_CNT_V << UART_HIGHPULSE_MIN_CNT_S)
#define UART_HIGHPULSE_MIN_CNT_V  0x00000fff
#define UART_HIGHPULSE_MIN_CNT_S  0

/* UART_RXD_CNT_REG register
 * Autobaud edge change count register
 */

#define UART_RXD_CNT_REG(i) (REG_UART_BASE(i) + 0x30)

/* UART_RXD_EDGE_CNT : RO; bitpos: [9:0]; default: 0;
 * This register stores the count of rxd edge change. It is used in baud
 * rate-detect process.
 */

#define UART_RXD_EDGE_CNT    0x000003ff
#define UART_RXD_EDGE_CNT_M  (UART_RXD_EDGE_CNT_V << UART_RXD_EDGE_CNT_S)
#define UART_RXD_EDGE_CNT_V  0x000003ff
#define UART_RXD_EDGE_CNT_S  0

/* UART_FLOW_CONF_REG register
 * Software flow-control configuration
 */

#define UART_FLOW_CONF_REG(i) (REG_UART_BASE(i) + 0x34)

/* UART_SEND_XOFF : R/W/SS/SC; bitpos: [5]; default: 0;
 * Set this bit to send Xoff char. It is cleared by hardware automatically.
 */

#define UART_SEND_XOFF    (BIT(5))
#define UART_SEND_XOFF_M  (UART_SEND_XOFF_V << UART_SEND_XOFF_S)
#define UART_SEND_XOFF_V  0x00000001
#define UART_SEND_XOFF_S  5

/* UART_SEND_XON : R/W/SS/SC; bitpos: [4]; default: 0;
 * Set this bit to send Xon char. It is cleared by hardware automatically.
 */

#define UART_SEND_XON    (BIT(4))
#define UART_SEND_XON_M  (UART_SEND_XON_V << UART_SEND_XON_S)
#define UART_SEND_XON_V  0x00000001
#define UART_SEND_XON_S  4

/* UART_FORCE_XOFF : R/W; bitpos: [3]; default: 0;
 * Set this bit to stop the  transmitter from sending data.
 */

#define UART_FORCE_XOFF    (BIT(3))
#define UART_FORCE_XOFF_M  (UART_FORCE_XOFF_V << UART_FORCE_XOFF_S)
#define UART_FORCE_XOFF_V  0x00000001
#define UART_FORCE_XOFF_S  3

/* UART_FORCE_XON : R/W; bitpos: [2]; default: 0;
 * Set this bit to enable the transmitter to go on sending data.
 */

#define UART_FORCE_XON    (BIT(2))
#define UART_FORCE_XON_M  (UART_FORCE_XON_V << UART_FORCE_XON_S)
#define UART_FORCE_XON_V  0x00000001
#define UART_FORCE_XON_S  2

/* UART_XONOFF_DEL : R/W; bitpos: [1]; default: 0;
 * Set this bit to remove flow control char from the received data.
 */

#define UART_XONOFF_DEL    (BIT(1))
#define UART_XONOFF_DEL_M  (UART_XONOFF_DEL_V << UART_XONOFF_DEL_S)
#define UART_XONOFF_DEL_V  0x00000001
#define UART_XONOFF_DEL_S  1

/* UART_SW_FLOW_CON_EN : R/W; bitpos: [0]; default: 0;
 * Set this bit to enable software flow control. It is used with register
 * sw_xon or sw_xoff.
 */

#define UART_SW_FLOW_CON_EN    (BIT(0))
#define UART_SW_FLOW_CON_EN_M  (UART_SW_FLOW_CON_EN_V << UART_SW_FLOW_CON_EN_S)
#define UART_SW_FLOW_CON_EN_V  0x00000001
#define UART_SW_FLOW_CON_EN_S  0

/* UART_SLEEP_CONF_REG register
 * Sleep-mode configuration
 */

#define UART_SLEEP_CONF_REG(i) (REG_UART_BASE(i) + 0x38)

/* UART_ACTIVE_THRESHOLD : R/W; bitpos: [9:0]; default: 240;
 * The uart is activated from light sleeping mode when the input rxd edge
 * changes more times than this register value.
 */

#define UART_ACTIVE_THRESHOLD    0x000003ff
#define UART_ACTIVE_THRESHOLD_M  (UART_ACTIVE_THRESHOLD_V << UART_ACTIVE_THRESHOLD_S)
#define UART_ACTIVE_THRESHOLD_V  0x000003ff
#define UART_ACTIVE_THRESHOLD_S  0

/* UART_SWFC_CONF0_REG register
 * Software flow-control character configuration
 */

#define UART_SWFC_CONF0_REG(i) (REG_UART_BASE(i) + 0x3c)

/* UART_XOFF_CHAR : R/W; bitpos: [17:10]; default: 19;
 * This register stores the Xoff flow control char.
 */

#define UART_XOFF_CHAR    0x000000ff
#define UART_XOFF_CHAR_M  (UART_XOFF_CHAR_V << UART_XOFF_CHAR_S)
#define UART_XOFF_CHAR_V  0x000000ff
#define UART_XOFF_CHAR_S  10

/* UART_XOFF_THRESHOLD : R/W; bitpos: [9:0]; default: 224;
 * When the data amount in Rx-FIFO is more than this register value with
 * uart_sw_flow_con_en set to 1, it will send a Xoff char.
 */

#define UART_XOFF_THRESHOLD    0x000003ff
#define UART_XOFF_THRESHOLD_M  (UART_XOFF_THRESHOLD_V << UART_XOFF_THRESHOLD_S)
#define UART_XOFF_THRESHOLD_V  0x000003ff
#define UART_XOFF_THRESHOLD_S  0

/* UART_SWFC_CONF1_REG register
 * Software flow-control character configuration
 */

#define UART_SWFC_CONF1_REG(i) (REG_UART_BASE(i) + 0x40)

/* UART_XON_CHAR : R/W; bitpos: [17:10]; default: 17;
 * This register stores the Xon flow control char.
 */

#define UART_XON_CHAR    0x000000ff
#define UART_XON_CHAR_M  (UART_XON_CHAR_V << UART_XON_CHAR_S)
#define UART_XON_CHAR_V  0x000000ff
#define UART_XON_CHAR_S  10

/* UART_XON_THRESHOLD : R/W; bitpos: [9:0]; default: 0;
 * When the data amount in Rx-FIFO is less than this register value with
 * uart_sw_flow_con_en set to 1, it will send a Xon char.
 */

#define UART_XON_THRESHOLD    0x000003ff
#define UART_XON_THRESHOLD_M  (UART_XON_THRESHOLD_V << UART_XON_THRESHOLD_S)
#define UART_XON_THRESHOLD_V  0x000003ff
#define UART_XON_THRESHOLD_S  0

/* UART_TXBRK_CONF_REG register
 * Tx Break character configuration
 */

#define UART_TXBRK_CONF_REG(i) (REG_UART_BASE(i) + 0x44)

/* UART_TX_BRK_NUM : R/W; bitpos: [7:0]; default: 10;
 * This register is used to configure the number of 0 to be sent after the
 * process of sending data is done. It is active when txd_brk is set to 1.
 */

#define UART_TX_BRK_NUM    0x000000ff
#define UART_TX_BRK_NUM_M  (UART_TX_BRK_NUM_V << UART_TX_BRK_NUM_S)
#define UART_TX_BRK_NUM_V  0x000000ff
#define UART_TX_BRK_NUM_S  0

/* UART_IDLE_CONF_REG register
 * Frame-end idle configuration
 */

#define UART_IDLE_CONF_REG(i) (REG_UART_BASE(i) + 0x48)

/* UART_TX_IDLE_NUM : R/W; bitpos: [19:10]; default: 256;
 * This register is used to configure the duration time between transfers.
 */

#define UART_TX_IDLE_NUM    0x000003ff
#define UART_TX_IDLE_NUM_M  (UART_TX_IDLE_NUM_V << UART_TX_IDLE_NUM_S)
#define UART_TX_IDLE_NUM_V  0x000003ff
#define UART_TX_IDLE_NUM_S  10

/* UART_RX_IDLE_THRHD : R/W; bitpos: [9:0]; default: 256;
 * It will produce frame end signal when receiver takes more time to receive
 * one byte data than this register value.
 */

#define UART_RX_IDLE_THRHD    0x000003ff
#define UART_RX_IDLE_THRHD_M  (UART_RX_IDLE_THRHD_V << UART_RX_IDLE_THRHD_S)
#define UART_RX_IDLE_THRHD_V  0x000003ff
#define UART_RX_IDLE_THRHD_S  0

/* UART_RS485_CONF_REG register
 * RS485 mode configuration
 */

#define UART_RS485_CONF_REG(i) (REG_UART_BASE(i) + 0x4c)

/* UART_RS485_TX_DLY_NUM : R/W; bitpos: [9:6]; default: 0;
 * This register is used to delay the transmitter's internal data signal.
 */

#define UART_RS485_TX_DLY_NUM    0x0000000f
#define UART_RS485_TX_DLY_NUM_M  (UART_RS485_TX_DLY_NUM_V << UART_RS485_TX_DLY_NUM_S)
#define UART_RS485_TX_DLY_NUM_V  0x0000000f
#define UART_RS485_TX_DLY_NUM_S  6

/* UART_RS485_RX_DLY_NUM : R/W; bitpos: [5]; default: 0;
 * This register is used to delay the receiver's internal data signal.
 */

#define UART_RS485_RX_DLY_NUM    (BIT(5))
#define UART_RS485_RX_DLY_NUM_M  (UART_RS485_RX_DLY_NUM_V << UART_RS485_RX_DLY_NUM_S)
#define UART_RS485_RX_DLY_NUM_V  0x00000001
#define UART_RS485_RX_DLY_NUM_S  5

/* UART_RS485RXBY_TX_EN : R/W; bitpos: [4]; default: 0;
 * 1'h1: enable rs485 transmitter to send data when rs485 receiver line is
 * busy.
 */

#define UART_RS485RXBY_TX_EN    (BIT(4))
#define UART_RS485RXBY_TX_EN_M  (UART_RS485RXBY_TX_EN_V << UART_RS485RXBY_TX_EN_S)
#define UART_RS485RXBY_TX_EN_V  0x00000001
#define UART_RS485RXBY_TX_EN_S  4

/* UART_RS485TX_RX_EN : R/W; bitpos: [3]; default: 0;
 * Set this bit to enable receiver could receive data when the transmitter
 * is transmitting data in rs485 mode.
 */

#define UART_RS485TX_RX_EN    (BIT(3))
#define UART_RS485TX_RX_EN_M  (UART_RS485TX_RX_EN_V << UART_RS485TX_RX_EN_S)
#define UART_RS485TX_RX_EN_V  0x00000001
#define UART_RS485TX_RX_EN_S  3

/* UART_DL1_EN : R/W; bitpos: [2]; default: 0;
 * Set this bit to delay the stop bit by 1 bit.
 */

#define UART_DL1_EN    (BIT(2))
#define UART_DL1_EN_M  (UART_DL1_EN_V << UART_DL1_EN_S)
#define UART_DL1_EN_V  0x00000001
#define UART_DL1_EN_S  2

/* UART_DL0_EN : R/W; bitpos: [1]; default: 0;
 * Set this bit to delay the stop bit by 1 bit.
 */

#define UART_DL0_EN    (BIT(1))
#define UART_DL0_EN_M  (UART_DL0_EN_V << UART_DL0_EN_S)
#define UART_DL0_EN_V  0x00000001
#define UART_DL0_EN_S  1

/* UART_RS485_EN : R/W; bitpos: [0]; default: 0;
 * Set this bit to choose the rs485 mode.
 */

#define UART_RS485_EN    (BIT(0))
#define UART_RS485_EN_M  (UART_RS485_EN_V << UART_RS485_EN_S)
#define UART_RS485_EN_V  0x00000001
#define UART_RS485_EN_S  0

/* UART_AT_CMD_PRECNT_REG register
 * Pre-sequence timing configuration
 */

#define UART_AT_CMD_PRECNT_REG(i) (REG_UART_BASE(i) + 0x50)

/* UART_PRE_IDLE_NUM : R/W; bitpos: [15:0]; default: 2305;
 * This register is used to configure the idle duration time before the
 * first at_cmd is received by receiver.
 */

#define UART_PRE_IDLE_NUM    0x0000ffff
#define UART_PRE_IDLE_NUM_M  (UART_PRE_IDLE_NUM_V << UART_PRE_IDLE_NUM_S)
#define UART_PRE_IDLE_NUM_V  0x0000ffff
#define UART_PRE_IDLE_NUM_S  0

/* UART_AT_CMD_POSTCNT_REG register
 * Post-sequence timing configuration
 */

#define UART_AT_CMD_POSTCNT_REG(i) (REG_UART_BASE(i) + 0x54)

/* UART_POST_IDLE_NUM : R/W; bitpos: [15:0]; default: 2305;
 * This register is used to configure the duration time between the last
 * at_cmd and the next data.
 */

#define UART_POST_IDLE_NUM    0x0000ffff
#define UART_POST_IDLE_NUM_M  (UART_POST_IDLE_NUM_V << UART_POST_IDLE_NUM_S)
#define UART_POST_IDLE_NUM_V  0x0000ffff
#define UART_POST_IDLE_NUM_S  0

/* UART_AT_CMD_GAPTOUT_REG register
 * Timeout configuration
 */

#define UART_AT_CMD_GAPTOUT_REG(i) (REG_UART_BASE(i) + 0x58)

/* UART_RX_GAP_TOUT : R/W; bitpos: [15:0]; default: 11;
 * This register is used to configure the duration time between the at_cmd
 * chars.
 */

#define UART_RX_GAP_TOUT    0x0000ffff
#define UART_RX_GAP_TOUT_M  (UART_RX_GAP_TOUT_V << UART_RX_GAP_TOUT_S)
#define UART_RX_GAP_TOUT_V  0x0000ffff
#define UART_RX_GAP_TOUT_S  0

/* UART_AT_CMD_CHAR_REG register
 * AT escape sequence detection configuration
 */

#define UART_AT_CMD_CHAR_REG(i) (REG_UART_BASE(i) + 0x5c)

/* UART_CHAR_NUM : R/W; bitpos: [15:8]; default: 3;
 * This register is used to configure the num of continuous at_cmd chars
 * received by receiver.
 */

#define UART_CHAR_NUM    0x000000ff
#define UART_CHAR_NUM_M  (UART_CHAR_NUM_V << UART_CHAR_NUM_S)
#define UART_CHAR_NUM_V  0x000000ff
#define UART_CHAR_NUM_S  8

/* UART_AT_CMD_CHAR : R/W; bitpos: [7:0]; default: 43;
 * This register is used to configure the content of at_cmd char.
 */

#define UART_AT_CMD_CHAR    0x000000ff
#define UART_AT_CMD_CHAR_M  (UART_AT_CMD_CHAR_V << UART_AT_CMD_CHAR_S)
#define UART_AT_CMD_CHAR_V  0x000000ff
#define UART_AT_CMD_CHAR_S  0

/* UART_MEM_CONF_REG register
 * UART threshold and allocation configuration
 */

#define UART_MEM_CONF_REG(i) (REG_UART_BASE(i) + 0x60)

/* UART_MEM_FORCE_PU : R/W; bitpos: [28]; default: 0;
 * Set this bit to force power up UART memory.
 */

#define UART_MEM_FORCE_PU    (BIT(28))
#define UART_MEM_FORCE_PU_M  (UART_MEM_FORCE_PU_V << UART_MEM_FORCE_PU_S)
#define UART_MEM_FORCE_PU_V  0x00000001
#define UART_MEM_FORCE_PU_S  28

/* UART_MEM_FORCE_PD : R/W; bitpos: [27]; default: 0;
 * Set this bit to force power down UART memory.
 */

#define UART_MEM_FORCE_PD    (BIT(27))
#define UART_MEM_FORCE_PD_M  (UART_MEM_FORCE_PD_V << UART_MEM_FORCE_PD_S)
#define UART_MEM_FORCE_PD_V  0x00000001
#define UART_MEM_FORCE_PD_S  27

/* UART_RX_TOUT_THRHD : R/W; bitpos: [26:17]; default: 10;
 * This register is used to configure the threshold time that receiver takes
 * to receive one byte. The rxfifo_tout_int interrupt will be trigger when
 * the receiver takes more time to receive one byte with rx_tout_en set to 1.
 */

#define UART_RX_TOUT_THRHD    0x000003ff
#define UART_RX_TOUT_THRHD_M  (UART_RX_TOUT_THRHD_V << UART_RX_TOUT_THRHD_S)
#define UART_RX_TOUT_THRHD_V  0x000003ff
#define UART_RX_TOUT_THRHD_S  17

/* UART_RX_FLOW_THRHD : R/W; bitpos: [16:7]; default: 0;
 * This register is used to configure the maximum amount of data that can be
 * received  when hardware flow control works.
 */

#define UART_RX_FLOW_THRHD    0x000003ff
#define UART_RX_FLOW_THRHD_M  (UART_RX_FLOW_THRHD_V << UART_RX_FLOW_THRHD_S)
#define UART_RX_FLOW_THRHD_V  0x000003ff
#define UART_RX_FLOW_THRHD_S  7

/* UART_TX_SIZE : R/W; bitpos: [6:4]; default: 1;
 * This register is used to configure the amount of mem allocated for
 * transmit-FIFO. The default number is 128 bytes.
 */

#define UART_TX_SIZE    0x00000007
#define UART_TX_SIZE_M  (UART_TX_SIZE_V << UART_TX_SIZE_S)
#define UART_TX_SIZE_V  0x00000007
#define UART_TX_SIZE_S  4

/* UART_RX_SIZE : R/W; bitpos: [3:1]; default: 1;
 * This register is used to configure the amount of mem allocated for
 * receive-FIFO. The default number is 128 bytes.
 */

#define UART_RX_SIZE    0x00000007
#define UART_RX_SIZE_M  (UART_RX_SIZE_V << UART_RX_SIZE_S)
#define UART_RX_SIZE_V  0x00000007
#define UART_RX_SIZE_S  1

/* UART_MEM_TX_STATUS_REG register
 * Tx-FIFO write and read offset address.
 */

#define UART_MEM_TX_STATUS_REG(i) (REG_UART_BASE(i) + 0x64)

/* UART_TX_RADDR : RO; bitpos: [20:11]; default: 0;
 * This register stores the offset address in Tx-FIFO when Tx-FSM reads data
 * via Tx-FIFO_Ctrl.
 */

#define UART_TX_RADDR    0x000003ff
#define UART_TX_RADDR_M  (UART_TX_RADDR_V << UART_TX_RADDR_S)
#define UART_TX_RADDR_V  0x000003ff
#define UART_TX_RADDR_S  11

/* UART_APB_TX_WADDR : RO; bitpos: [9:0]; default: 0;
 * This register stores the offset address in Tx-FIFO when software writes
 * Tx-FIFO via APB.
 */

#define UART_APB_TX_WADDR    0x000003ff
#define UART_APB_TX_WADDR_M  (UART_APB_TX_WADDR_V << UART_APB_TX_WADDR_S)
#define UART_APB_TX_WADDR_V  0x000003ff
#define UART_APB_TX_WADDR_S  0

/* UART_MEM_RX_STATUS_REG register
 * Rx-FIFO write and read offset address.
 */

#define UART_MEM_RX_STATUS_REG(i) (REG_UART_BASE(i) + 0x68)

/* UART_RX_WADDR : RO; bitpos: [20:11]; default: 512;
 * This register stores the offset address in Rx-FIFO when Rx-FIFO_Ctrl
 * writes Rx-FIFO. UART0 is 10'h200. UART1 is 10'h280. UART2 is 10'h300.
 */

#define UART_RX_WADDR    0x000003ff
#define UART_RX_WADDR_M  (UART_RX_WADDR_V << UART_RX_WADDR_S)
#define UART_RX_WADDR_V  0x000003ff
#define UART_RX_WADDR_S  11

/* UART_APB_RX_RADDR : RO; bitpos: [9:0]; default: 512;
 * This register stores the offset address in RX-FIFO when software reads
 * data from Rx-FIFO via APB. UART0 is 10'h200. UART1 is 10'h280. UART2 is
 * 10'h300.
 */

#define UART_APB_RX_RADDR    0x000003ff
#define UART_APB_RX_RADDR_M  (UART_APB_RX_RADDR_V << UART_APB_RX_RADDR_S)
#define UART_APB_RX_RADDR_V  0x000003ff
#define UART_APB_RX_RADDR_S  0

/* UART_FSM_STATUS_REG register
 * UART transmit and receive status.
 */

#define UART_FSM_STATUS_REG(i) (REG_UART_BASE(i) + 0x6c)

/* UART_ST_UTX_OUT : RO; bitpos: [7:4]; default: 0;
 * This is the status register of transmitter.
 */

#define UART_ST_UTX_OUT    0x0000000f
#define UART_ST_UTX_OUT_M  (UART_ST_UTX_OUT_V << UART_ST_UTX_OUT_S)
#define UART_ST_UTX_OUT_V  0x0000000f
#define UART_ST_UTX_OUT_S  4

/* UART_ST_URX_OUT : RO; bitpos: [3:0]; default: 0;
 * This is the status register of receiver.
 */

#define UART_ST_URX_OUT    0x0000000f
#define UART_ST_URX_OUT_M  (UART_ST_URX_OUT_V << UART_ST_URX_OUT_S)
#define UART_ST_URX_OUT_V  0x0000000f
#define UART_ST_URX_OUT_S  0

/* UART_POSPULSE_REG register
 * Autobaud high pulse register
 */

#define UART_POSPULSE_REG(i) (REG_UART_BASE(i) + 0x70)

/* UART_POSEDGE_MIN_CNT : RO; bitpos: [11:0]; default: 4095;
 * This register stores the minimal input clock count between two positive
 * edges. It is used in boudrate-detect process.
 */

#define UART_POSEDGE_MIN_CNT    0x00000fff
#define UART_POSEDGE_MIN_CNT_M  (UART_POSEDGE_MIN_CNT_V << UART_POSEDGE_MIN_CNT_S)
#define UART_POSEDGE_MIN_CNT_V  0x00000fff
#define UART_POSEDGE_MIN_CNT_S  0

/* UART_NEGPULSE_REG register
 * Autobaud low pulse register
 */

#define UART_NEGPULSE_REG(i) (REG_UART_BASE(i) + 0x74)

/* UART_NEGEDGE_MIN_CNT : RO; bitpos: [11:0]; default: 4095;
 * This register stores the minimal input clock count between two negative
 * edges. It is used in boudrate-detect process.
 */

#define UART_NEGEDGE_MIN_CNT    0x00000fff
#define UART_NEGEDGE_MIN_CNT_M  (UART_NEGEDGE_MIN_CNT_V << UART_NEGEDGE_MIN_CNT_S)
#define UART_NEGEDGE_MIN_CNT_V  0x00000fff
#define UART_NEGEDGE_MIN_CNT_S  0

/* UART_CLK_CONF_REG register
 * UART core clock configuration
 */

#define UART_CLK_CONF_REG(i) (REG_UART_BASE(i) + 0x78)

/* UART_RX_RST_CORE : R/W; bitpos: [27]; default: 0;
 * Write 1 then write 0 to this bit, reset UART Rx.
 */

#define UART_RX_RST_CORE    (BIT(27))
#define UART_RX_RST_CORE_M  (UART_RX_RST_CORE_V << UART_RX_RST_CORE_S)
#define UART_RX_RST_CORE_V  0x00000001
#define UART_RX_RST_CORE_S  27

/* UART_TX_RST_CORE : R/W; bitpos: [26]; default: 0;
 * Write 1 then write 0 to this bit, reset UART Tx.
 */

#define UART_TX_RST_CORE    (BIT(26))
#define UART_TX_RST_CORE_M  (UART_TX_RST_CORE_V << UART_TX_RST_CORE_S)
#define UART_TX_RST_CORE_V  0x00000001
#define UART_TX_RST_CORE_S  26

/* UART_RX_SCLK_EN : R/W; bitpos: [25]; default: 1;
 * Set this bit to enable UART Rx clock.
 */

#define UART_RX_SCLK_EN    (BIT(25))
#define UART_RX_SCLK_EN_M  (UART_RX_SCLK_EN_V << UART_RX_SCLK_EN_S)
#define UART_RX_SCLK_EN_V  0x00000001
#define UART_RX_SCLK_EN_S  25

/* UART_TX_SCLK_EN : R/W; bitpos: [24]; default: 1;
 * Set this bit to enable UART Tx clock.
 */

#define UART_TX_SCLK_EN    (BIT(24))
#define UART_TX_SCLK_EN_M  (UART_TX_SCLK_EN_V << UART_TX_SCLK_EN_S)
#define UART_TX_SCLK_EN_V  0x00000001
#define UART_TX_SCLK_EN_S  24

/* UART_RST_CORE : R/W; bitpos: [23]; default: 0;
 * Write 1 then write 0 to this bit, reset UART Tx/Rx.
 */

#define UART_RST_CORE    (BIT(23))
#define UART_RST_CORE_M  (UART_RST_CORE_V << UART_RST_CORE_S)
#define UART_RST_CORE_V  0x00000001
#define UART_RST_CORE_S  23

/* UART_SCLK_EN : R/W; bitpos: [22]; default: 1;
 * Set this bit to enable UART Tx/Rx clock.
 */

#define UART_SCLK_EN    (BIT(22))
#define UART_SCLK_EN_M  (UART_SCLK_EN_V << UART_SCLK_EN_S)
#define UART_SCLK_EN_V  0x00000001
#define UART_SCLK_EN_S  22

/* UART_SCLK_SEL : R/W; bitpos: [21:20]; default: 3;
 * UART clock source select. 1: 80Mhz, 2: 8Mhz, 3: XTAL.
 */

#define UART_SCLK_SEL    0x00000003
#define UART_SCLK_SEL_M  (UART_SCLK_SEL_V << UART_SCLK_SEL_S)
#define UART_SCLK_SEL_V  0x00000003
#define UART_SCLK_SEL_S  20

/* UART_SCLK_DIV_NUM : R/W; bitpos: [19:12]; default: 1;
 * The integral part of the frequency divider factor.
 */

#define UART_SCLK_DIV_NUM    0x000000ff
#define UART_SCLK_DIV_NUM_M  (UART_SCLK_DIV_NUM_V << UART_SCLK_DIV_NUM_S)
#define UART_SCLK_DIV_NUM_V  0x000000ff
#define UART_SCLK_DIV_NUM_S  12

/* UART_SCLK_DIV_A : R/W; bitpos: [11:6]; default: 0;
 * The numerator of the frequency divider factor.
 */

#define UART_SCLK_DIV_A    0x0000003f
#define UART_SCLK_DIV_A_M  (UART_SCLK_DIV_A_V << UART_SCLK_DIV_A_S)
#define UART_SCLK_DIV_A_V  0x0000003f
#define UART_SCLK_DIV_A_S  6

/* UART_SCLK_DIV_B : R/W; bitpos: [5:0]; default: 0;
 * The  denominator of the frequency divider factor.
 */

#define UART_SCLK_DIV_B    0x0000003f
#define UART_SCLK_DIV_B_M  (UART_SCLK_DIV_B_V << UART_SCLK_DIV_B_S)
#define UART_SCLK_DIV_B_V  0x0000003f
#define UART_SCLK_DIV_B_S  0

/* UART_DATE_REG register
 * UART Version register
 */

#define UART_DATE_REG(i) (REG_UART_BASE(i) + 0x7c)

/* UART_DATE : R/W; bitpos: [31:0]; default: 33587824;
 * This is the version register.
 */

#define UART_DATE    0xffffffff
#define UART_DATE_M  (UART_DATE_V << UART_DATE_S)
#define UART_DATE_V  0xffffffff
#define UART_DATE_S  0

/* UART_ID_REG register
 * UART ID register
 */

#define UART_ID_REG(i) (REG_UART_BASE(i) + 0x80)

/* UART_REG_UPDATE : R/W/SC; bitpos: [31]; default: 0;
 * Software write 1 would synchronize registers into UART Core clock domain
 * and would be cleared by hardware after synchronization is done.
 */

#define UART_REG_UPDATE    (BIT(31))
#define UART_REG_UPDATE_M  (UART_REG_UPDATE_V << UART_REG_UPDATE_S)
#define UART_REG_UPDATE_V  0x00000001
#define UART_REG_UPDATE_S  31

/* UART_HIGH_SPEED : R/W; bitpos: [30]; default: 1;
 * This bit used to select synchronize mode. 1: Registers are auto
 * synchronized into UART Core clock and UART core should be keep the same
 * with APB clock. 0: After configure registers, software needs to write 1
 * to UART_REG_UPDATE to synchronize registers.
 */

#define UART_HIGH_SPEED    (BIT(30))
#define UART_HIGH_SPEED_M  (UART_HIGH_SPEED_V << UART_HIGH_SPEED_S)
#define UART_HIGH_SPEED_V  0x00000001
#define UART_HIGH_SPEED_S  30

/* UART_ID : R/W; bitpos: [29:0]; default: 1280;
 * This register is used to configure the uart_id.
 */

#define UART_ID    0x3fffffff
#define UART_ID_M  (UART_ID_V << UART_ID_S)
#define UART_ID_V  0x3fffffff
#define UART_ID_S  0

#endif /* __ARCH_XTENSA_SRC_ESP32S3_HARDWARE_ESP32S3_UART_H */
