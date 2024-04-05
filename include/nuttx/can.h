/****************************************************************************
 * include/nuttx/can.h
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

#ifndef __INCLUDE_NUTTX_CAN_H
#define __INCLUDE_NUTTX_CAN_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <stdint.h>

#ifdef CONFIG_NET_CAN

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Special address description flags for the CAN_ID */

#define CAN_EFF_FLAG 0x80000000  /* EFF/SFF is set in the MSB */
#define CAN_RTR_FLAG 0x40000000  /* Remote transmission request */
#define CAN_ERR_FLAG 0x20000000  /* Error message frame */
#define CAN_EVT_FLAG 0x10000000  /* Lower_half use this flags to report state switch event */

/* Valid bits in CAN ID for frame formats */

#define CAN_SFF_MASK 0x000007ff  /* Standard frame format (SFF) */
#define CAN_EFF_MASK 0x1fffffff  /* Extended frame format (EFF) */
#define CAN_ERR_MASK 0x1fffffff  /* Omit EFF, RTR, ERR flags */

#define CAN_SFF_ID_BITS 11
#define CAN_EFF_ID_BITS 29

#define CAN_MTU (sizeof(struct can_frame))
#define CANFD_MTU (sizeof(struct canfd_frame))

/* CAN payload length and DLC definitions according to ISO 11898-1 */

#define CAN_MAX_DLC 8
#define CAN_MAX_DLEN 8

/* CAN FD payload length and DLC definitions according to ISO 11898-7 */

#define CANFD_MAX_DLC 15
#define CANFD_MAX_DLEN 64

/* Defined bits for canfd_frame.flags
 *
 * The use of struct canfd_frame implies the Extended Data Length (EDL) bit
 * to be set in the CAN frame bitstream on the wire. The EDL bit switch turns
 * the CAN controllers bitstream processor into the CAN FD mode which creates
 * two new options within the CAN FD frame specification:
 *
 * Bit Rate Switch - to indicate a second bitrate is/was used for the payload
 * Error State Indicator - represents the error state of the transmitting
 * node
 *
 * As the CANFD_ESI bit is internally generated by the transmitting CAN
 * controller only the CANFD_BRS bit is relevant for real CAN controllers
 * when building a CAN FD frame for transmission. Setting the CANFD_ESI bit
 * can make sense for virtual CAN interfaces to test applications with echoed
 * frames.
 */

#define CANFD_BRS 0x01 /* Bit rate switch (second bitrate for payload data) */
#define CANFD_ESI 0x02 /* Error state indicator of the transmitting node */
#define CANFD_FDF 0x04 /* Mark CAN FD for dual use of struct canfd_frame */

#define CAN_INV_FILTER 0x20000000u /* To be set in can_filter.can_id */

/* PF_CAN protocols */

#define CAN_RAW      1           /* RAW sockets */
#define CAN_BCM      2           /* Broadcast Manager */
#define CAN_TP16     3           /* VAG Transport Protocol v1.6 */
#define CAN_TP20     4           /* VAG Transport Protocol v2.0 */
#define CAN_MCNET    5           /* Bosch MCNet */
#define CAN_ISOTP    6           /* ISO 15765-2 Transport Protocol */
#define CAN_J1939    7           /* SAE J1939 */
#define CAN_NPROTO   8

#define SOL_CAN_BASE 100
#define SOL_CAN_RAW  (SOL_CAN_BASE + CAN_RAW)

/* CAN_RAW socket options */

#define CAN_RAW_FILTER         (__SO_PROTOCOL + 0)
                                 /* Set 0 .. n can_filter(s) */
#define CAN_RAW_ERR_FILTER     (__SO_PROTOCOL + 1)
                                 /* Set filter for error frames */
#define CAN_RAW_LOOPBACK       (__SO_PROTOCOL + 2)
                                 /* Local loopback (default:on) */
#define CAN_RAW_RECV_OWN_MSGS  (__SO_PROTOCOL + 3)
                                 /* Receive my own msgs (default:off) */
#define CAN_RAW_FD_FRAMES      (__SO_PROTOCOL + 4)
                                 /* Allow CAN FD frames (default:off) */
#define CAN_RAW_JOIN_FILTERS   (__SO_PROTOCOL + 5)
                                 /* All filters must match to trigger */
#define CAN_RAW_TX_DEADLINE    (__SO_PROTOCOL + 6)
                                 /* Abort frame when deadline passed */

/* CAN filter support (Hardware level filtering) ****************************/

/* Some CAN hardware supports a notion of prioritizing messages that match
 * filters. Only two priority levels are currently supported and are encoded
 * as defined below:
 */

#define CAN_MSGPRIO_LOW   0
#define CAN_MSGPRIO_HIGH  1

/* Filter type.  Not all CAN hardware will support all filter types. */

#define CAN_FILTER_MASK   0  /* Address match under a mask */
#define CAN_FILTER_DUAL   1  /* Dual address match */
#define CAN_FILTER_RANGE  2  /* Match a range of addresses */

/* CAN Error Indications ****************************************************/

/* Error class in can_id */

#define CAN_ERR_TX_TIMEOUT       (1 << 0) /* Bit 0: TX timeout */
#define CAN_ERR_LOSTARB          (1 << 1) /* Bit 1: Lost arbitration (See CAN_ERR_LOSTARB_* definitions) */
#define CAN_ERR_CRTL             (1 << 2) /* Bit 2: Controller error (See CAN_ERR_CRTL_* definitions) */
#define CAN_ERR_PROT             (1 << 3) /* Bit 3: Protocol error (see CAN_ERR_PROT_* definitions) */
#define CAN_ERR_TRX              (1 << 4) /* Bit 4: Transceiver error (See CAN_TRX_* definitions)    */
#define CAN_ERR_ACK              (1 << 5) /* Bit 5: No ACK received on transmission */
#define CAN_ERR_BUSOFF           (1 << 6) /* Bit 6: Bus off */
#define CAN_ERR_BUSERROR         (1 << 7) /* Bit 7: Bus error */
#define CAN_ERR_RESTARTED        (1 << 8) /* Bit 8: Controller restarted */
#define CAN_ERR_CNT              (1 << 9) /* Tx error counter / data[6]
                                           * Rx error counter / data[7]
                                           */

/* The remaining definitions described the error report payload that follows
 * the CAN header.
 */

#define CAN_ERR_DLC              (8)      /* DLC of error report */

/* Data[0]: Arbitration lost in ch_error. */

#define CAN_ERR_LOSTARB_UNSPEC   0x00     /* Unspecified error */
#define CAN_ERR_LOSTARB_BIT(n)   (n)      /* Bit number in the bit stream */

/* Data[1]:  Error status of CAN-controller */

#define CAN_ERR_CRTL_UNSPEC      0x00     /* Unspecified error */
#define CAN_ERR_CRTL_RX_OVERFLOW (1 << 0) /* Bit 0: RX buffer overflow */
#define CAN_ERR_CRTL_TX_OVERFLOW (1 << 1) /* Bit 1: TX buffer overflow */
#define CAN_ERR_CRTL_RX_WARNING  (1 << 2) /* Bit 2: Reached warning level for RX errors */
#define CAN_ERR_CRTL_TX_WARNING  (1 << 3) /* Bit 3: Reached warning level for TX errors */
#define CAN_ERR_CRTL_RX_PASSIVE  (1 << 4) /* Bit 4: Reached passive level for RX errors */
#define CAN_ERR_CRTL_TX_PASSIVE  (1 << 5) /* Bit 5: Reached passive level for TX errors */

/* Data[2]:  Error in CAN protocol.  This provides the type of the error. */

#define CAN_ERR_PROT_UNSPEC      0x00     /* Unspecified error */
#define CAN_ERR_PROT_BIT         (1 << 0) /* Bit 0: Single bit error */
#define CAN_ERR_PROT_FORM        (1 << 1) /* Bit 1: Frame format error */
#define CAN_ERR_PROT_STUFF       (1 << 2) /* Bit 2: Bit stuffing error */
#define CAN_ERR_PROT_BIT0        (1 << 3) /* Bit 3: Unable to send dominant bit */
#define CAN_ERR_PROT_BIT1        (1 << 4) /* Bit 4: Unable to send recessive bit */
#define CAN_ERR_PROT_OVERLOAD    (1 << 5) /* Bit 5: Bus overload */
#define CAN_ERR_PROT_ACTIVE      (1 << 6) /* Bit 6: Active error announcement */
#define CAN_ERR_PROT_TX          (1 << 7) /* Bit 7: Error occurred on transmission */

/* Data[3]:  Error in CAN protocol.  This provides the loation of the error */

#define CAN_ERR_PROT_LOC_UNSPEC  0x00 /* Unspecified error */
#define CAN_ERR_PROT_LOC_SOF     0x01 /* start of frame */
#define CAN_ERR_PROT_LOC_ID0     0x02 /* ID bits 0-4 */
#define CAN_ERR_PROT_LOC_ID1     0x03 /* ID bits 5-12 */
#define CAN_ERR_PROT_LOC_ID2     0x04 /* ID bits 13-17 */
#define CAN_ERR_PROT_LOC_ID3     0x05 /* ID bits 21-28 */
#define CAN_ERR_PROT_LOC_ID4     0x06 /* ID bits 18-20 */
#define CAN_ERR_PROT_LOC_IDE     0x07 /* Identifier extension */
#define CAN_ERR_PROT_LOC_RTR     0x08 /* RTR */
#define CAN_ERR_PROT_LOC_SRTR    0x09 /* Substitute RTR */
#define CAN_ERR_PROT_LOC_RES0    0x0a /* Reserved bit 0 */
#define CAN_ERR_PROT_LOC_RES1    0x0b /* Reserved bit 1 */
#define CAN_ERR_PROT_LOC_DLC     0x0c /* Data length code */
#define CAN_ERR_PROT_LOC_DATA    0x0d /* Data section */
#define CAN_ERR_PROT_LOC_CRC_SEQ 0x0e /* CRC sequence */
#define CAN_ERR_PROT_LOC_CRC_DEL 0x0f /* CRC delimiter */
#define CAN_ERR_PROT_LOC_ACK     0x10 /* ACK slot */
#define CAN_ERR_PROT_LOC_ACK_DEL 0x11 /* ACK delimiter */
#define CAN_ERR_PROT_LOC_EOF     0x12 /* End of frame */
#define CAN_ERR_PROT_LOC_INTERM  0x13 /* Intermission */

/* Data[4]: Error status of CAN-transceiver */

#define CAN_ERR_TRX_UNSPEC             0x00 /* Unspecified error */
#define CAN_ERR_TRX_CANH_NO_WIRE       0x04
#define CAN_ERR_TRX_CANH_SHORT_TO_BAT  0x05
#define CAN_ERR_TRX_CANH_SHORT_TO_VCC  0x06
#define CAN_ERR_TRX_CANH_SHORT_TO_GND  0x07
#define CAN_ERR_TRX_CANL_NO_WIRE       0x40
#define CAN_ERR_TRX_CANL_SHORT_TO_BAT  0x50
#define CAN_ERR_TRX_CANL_SHORT_TO_VCC  0x60
#define CAN_ERR_TRX_CANL_SHORT_TO_GND  0x70
#define CAN_ERR_TRX_CANL_SHORT_TO_CANH 0x80

/* CAN state thresholds
 *
 * Error counter        Error state
 * -----------------------------------
 * 0 -  95              Error-active
 * 96 - 127             Error-warning
 * 128 - 255            Error-passive
 * 256 and greater      Bus-off
 */

#define CAN_ERROR_WARNING_THRESHOLD 96
#define CAN_ERROR_PASSIVE_THRESHOLD 128
#define CAN_BUS_OFF_THRESHOLD       256

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* Controller Area Network Identifier structure
 *
 * bit 0-28: CAN identifier (11/29 bit)
 * bit 29: error message frame flag (0 = data frame, 1 = error message)
 * bit 30: remote transmission request flag (1 = rtr frame)
 * bit 31: frame format flag (0 = standard 11 bit, 1 = extended 29 bit)
 */

typedef uint32_t canid_t;

/* Controller Area Network Error Message Frame Mask structure
 *
 * bit 0-28  : error class mask
 * bit 29-31 : set to zero
 */

typedef uint32_t can_err_mask_t;

/* struct can_frame - basic CAN frame structure
 * can_id:  CAN ID of the frame and CAN_*_FLAG flags, see canid_t definition
 * can_dlc: frame payload length in byte (0 .. 8) aka data length code
 *          N.B. the DLC field from ISO 11898-1 Chapter 8.4.2.3 has a 1:1
 *          mapping of the 'data length code' to the real payload length
 * __pad:   padding
 * __res0:  reserved / padding
 * __res1:  reserved / padding
 * data:    CAN frame payload (up to 8 byte)
 */

struct can_frame
{
  canid_t can_id;   /* 32 bit CAN_ID + EFF/RTR/ERR flags */
  uint8_t  can_dlc; /* frame payload length in byte (0 .. CAN_MAX_DLEN) */
  uint8_t  __pad;   /* padding */
  uint8_t  __res0;  /* reserved / padding */
  uint8_t  __res1;  /* reserved / padding */
  uint8_t  data[CAN_MAX_DLEN];
};

/* struct canfd_frame - CAN flexible data rate frame structure
 * can_id: CAN ID of the frame and CAN_*_FLAG flags, see canid_t definition
 * len:    frame payload length in byte (0 .. CANFD_MAX_DLEN)
 * flags:  additional flags for CAN FD
 * __res0: reserved / padding
 * __res1: reserved / padding
 * data:   CAN FD frame payload (up to CANFD_MAX_DLEN byte)
 */

struct canfd_frame
{
  canid_t can_id;  /* 32 bit CAN_ID + EFF/RTR/ERR flags */
  uint8_t len;     /* frame payload length in byte */
  uint8_t flags;   /* additional flags for CAN FD */
  uint8_t __res0;  /* reserved / padding */
  uint8_t __res1;  /* reserved / padding */
  uint8_t data[CANFD_MAX_DLEN];
};

/* The sockaddr structure for CAN sockets
 *
 *   can_family:  Address family number AF_CAN.
 *   can_ifindex: CAN network interface index.
 *   can_addr:    Protocol specific address information
 */

struct sockaddr_can
{
  sa_family_t can_family;
  int16_t     can_ifindex;
  union
  {
    /* Transport protocol class address information */

    struct
    {
      canid_t rx_id;
      canid_t tx_id;
    } tp;

    /* J1939 address information */

    struct
    {
      /* 8 byte name when using dynamic addressing */

      uint64_t name;

      /* pgn:
       *   8 bit: PS in PDU2 case, else 0
       *   8 bit: PF
       *   1 bit: DP
       *   1 bit: reserved
       */

      uint32_t pgn;

      /* 1 byte address */

      uint8_t addr;
    } j1939;
  } can_addr;
};

/* struct can_filter - CAN ID based filter in can_register().
 * can_id:   Relevant bits of CAN ID which are not masked out.
 * can_mask: CAN mask (see description)
 *
 * Description:
 * A filter matches, when
 *
 *   <received_can_id> & mask == can_id & mask
 *
 * The filter can be inverted (CAN_INV_FILTER bit set in can_id) or it can
 * filter for error message frames (CAN_ERR_FLAG bit set in mask).
 */

struct can_filter
{
  canid_t can_id;
  canid_t can_mask;
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* CONFIG_CAN */
#endif /* __INCLUDE_NUTTX_CAN_H */
