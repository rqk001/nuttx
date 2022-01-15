/************************************************************************************
 * arch/sparc/src/bm3803/bm3803-uart.h
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

#ifndef __ARCH_SPARC_SRC_BM3803_BM3803_UART_H
#define __ARCH_SPARC_SRC_BM3803_BM3803_UART_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

#include "chip.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/
 /* Register Offsets *****************************************************************/

#define BM3803_UART_TXREG_OFFSET    0x0000 /* UARTx transmit register */
#define BM3803_UART_RXREG_OFFSET    0x0000 /* UARTx receive register */
#define BM3803_UART_STATREG_OFFSET  0x0004 /* UARTx status register */
#define BM3803_UART_CTRLREG_OFFSET  0x0008 /* UARTx control register */
#define BM3803_UART_SCALREG_OFFSET  0x000c /* UARTx scaler register */


/* Register Addresses ****************************************************************/

#if CHIP_NUARTS > 0
#define BM3803_UART1_TXREG          (BM3803_UART1_BASE+BM3803_UART_TXREG_OFFSET)
#define BM3803_UART1_RXREG          (BM3803_UART1_BASE+BM3803_UART_RXREG_OFFSET)
#define BM3803_UART1_STATREG        (BM3803_UART1_BASE+BM3803_UART_STATREG_OFFSET)
#define BM3803_UART1_CTRLREG        (BM3803_UART1_BASE+BM3803_UART_CTRLREG_OFFSET)
#define BM3803_UART1_SCALREG        (BM3803_UART1_BASE+BM3803_UART_SCALREG_OFFSET)
#endif

#if CHIP_NUARTS > 1
#define BM3803_UART2_TXREG          (BM3803_UART2_BASE+BM3803_UART_TXREG_OFFSET)
#define BM3803_UART2_RXREG          (BM3803_UART2_BASE+BM3803_UART_RXREG_OFFSET)
#define BM3803_UART2_STATREG        (BM3803_UART2_BASE+BM3803_UART_STATREG_OFFSET)
#define BM3803_UART2_CTRLREG        (BM3803_UART2_BASE+BM3803_UART_CTRLREG_OFFSET)
#define BM3803_UART2_SCALREG        (BM3803_UART2_BASE+BM3803_UART_SCALREG_OFFSET)
#endif

#if CHIP_NUARTS > 2
#define BM3803_UART3_TXREG          (BM3803_UART3_BASE+BM3803_UART_TXREG_OFFSET)
#define BM3803_UART3_RXREG          (BM3803_UART3_BASE+BM3803_UART_RXREG_OFFSET)
#define BM3803_UART3_STATREG        (BM3803_UART3_BASE+BM3803_UART_STATREG_OFFSET)
#define BM3803_UART3_CTRLREG        (BM3803_UART3_BASE+BM3803_UART_CTRLREG_OFFSET)
#define BM3803_UART3_SCALREG        (BM3803_UART3_BASE+BM3803_UART_SCALREG_OFFSET)
#endif


/* Register Bit-Field Definitions ****************************************************/

#define ODD	1
#define EVEN    0
#define ON 	1
#define OFF     0
#define NONE    2
#define RX      0
#define TX      1
#define RXTX    3
/** Uart control list - Mask*/
#define MSK_UART_ENABLE_RX    0x01
#define MSK_UART_ENABLE_TX    0x02
#define MSK_UART_ENABLE_RXIT  0x04
#define MSK_UART_ENABLE_TXIT  0x08
#define MSK_UART_ENABLE_PAR   0x20
#define MSK_UART_PAR          0x10
#define MSK_UART_ENABLE_FLOW  0x40
#define MSK_UART_LOOPBACK     0x80
#define MSK_UART_CLOCK        0x100
#define MSK_UART_ALLINTS      0x0C

#define MSK_UART_DATA_READY   0x01
#define MSK_UART_TXs_READY    0x02
#define MSK_UART_TXh_READY    0x04
#define MSK_UART_BREAK        0x08
#define MSK_UART_OVERRUN      0x10
#define MSK_UART_PAR_ERR      0x20
#define MSK_UART_FRAME_ERR    0x40

/* UARTx transmit register */

#define UART_TXREG_MASK             0xff

/* UARTx receive register */

#define UART_RXREG_MASK             0xff

/* UARTx baud rate register */

#define UART_BRG_MASK               0xfff
/****************************************************************************
 * Private Types
 ****************************************************************************/

#define Uart1_set_baudrate(baudrate)	    (BM3803_REG.UartScaler1 = (uint32_t)((((BOARD_CPU_CLOCK*10)/(baudrate * 8))-5)/10))

#define Uart1_parity_config(uart_parity)     ( uart_parity    ==  ODD                                                      \
                                            ? (BM3803_REG.UartCtrl1   =   ((BM3803_REG.UartCtrl1 |  MSK_UART_PAR) | MSK_UART_ENABLE_PAR)) \
                                            : ( uart_parity  ==  EVEN                                                     \
                                              ? (BM3803_REG.UartCtrl1 =   ((BM3803_REG.UartCtrl1 & ~MSK_UART_PAR) | MSK_UART_ENABLE_PAR)) \
                                              : (BM3803_REG.UartCtrl1 &= ~MSK_UART_ENABLE_PAR )                                   \
                                              )                                                                           \
                                            )

#define Uart_interrupt_config(uart_its)     ( uart_its     ==  RXTX                                                \
                                            ? (UART_CONTROL     |=  (MSK_UART_ENABLE_RXIT |  MSK_UART_ENABLE_TXIT))\
                                            : ( uart_its   ==  RX                                                  \
                                              ? (UART_CONTROL   |=  (MSK_UART_ENABLE_RXIT & ~MSK_UART_ENABLE_TXIT))\
                                              : ( uart_its ==  TX                                                  \
                                                ? (UART_CONTROL |=  (MSK_UART_ENABLE_TXIT & ~MSK_UART_ENABLE_RXIT))\
                                                : (UART_CONTROL &= ~(MSK_UART_ENABLE_RXIT |  MSK_UART_ENABLE_TXIT))\
                                                )                                                                  \
                                              )                                                                    \
                                            ) 

#define Uart1_flow_ctrl_config(uart_flow)    ( uart_flow    ==  ON                     \
                                            ? (BM3803_REG.UartCtrl1 |=  MSK_UART_ENABLE_FLOW) \
                                            : (BM3803_REG.UartCtrl1 &= ~MSK_UART_ENABLE_FLOW) \
                                            )      
                                           
#define Uart1_loopback_config(uart_loopb)    ( uart_loopb   ==  ON                     \
                                            ? (BM3803_REG.UartCtrl1 |=  MSK_UART_LOOPBACK)    \
                                            : (BM3803_REG.UartCtrl1 &= ~MSK_UART_LOOPBACK)    \
                                            )    

#define Uart1_enable()                       (BM3803_REG.UartCtrl1 |=  (MSK_UART_ENABLE_RX | MSK_UART_ENABLE_TX))
#define Uart1_disable()                      (BM3803_REG.UartCtrl1 &= ~(MSK_UART_ENABLE_RX | MSK_UART_ENABLE_TX))

#define Uart1_tx_ready()                     ((BM3803_REG.UartStatus1 & MSK_UART_TXh_READY)  == MSK_UART_TXh_READY )
#define Uart1_rx_ready()                     ((BM3803_REG.UartStatus1 & MSK_UART_DATA_READY) == MSK_UART_DATA_READY)

#define Uart1_send_byte(ch)  		     (BM3803_REG.UartData1 = ch)

/***************************************************************************************************************************************/

#define Uart2_set_baudrate(baudrate)	    (BM3803_REG.UartScaler2 = (((BOARD_CPU_CLOCK*10)/(baudrate*8))-5)/10)

#define Uart2_parity_config(uart_parity)     ( uart_parity    ==  ODD                                                      \
                                            ? (BM3803_REG.UartCtrl2   =   ((BM3803_REG.UartCtrl2 |  MSK_UART_PAR) | MSK_UART_ENABLE_PAR)) \
                                            : ( uart_parity  ==  EVEN                                                     \
                                              ? (BM3803_REG.UartCtrl2 =   ((BM3803_REG.UartCtrl2 & ~MSK_UART_PAR) | MSK_UART_ENABLE_PAR)) \
                                              : (BM3803_REG.UartCtrl2 &= ~MSK_UART_ENABLE_PAR )                                   \
                                              )                                                                           \
                                            )

#define Uart2_flow_ctrl_config(uart_flow)    ( uart_flow    ==  ON                     \
                                            ? (BM3803_REG.UartCtrl2 |=  MSK_UART_ENABLE_FLOW) \
                                            : (BM3803_REG.UartCtrl2 &= ~MSK_UART_ENABLE_FLOW) \
                                            )      
                                           
#define Uart2_loopback_config(uart_loopb)    ( uart_loopb   ==  ON                     \
                                            ? (BM3803_REG.UartCtrl2 |=  MSK_UART_LOOPBACK)    \
                                            : (BM3803_REG.UartCtrl2 &= ~MSK_UART_LOOPBACK)    \
                                            )    

#define Uart2_enable()                       (BM3803_REG.UartCtrl2 |=  (MSK_UART_ENABLE_RX | MSK_UART_ENABLE_TX))
#define Uart2_disable()                      (BM3803_REG.UartCtrl2 &= ~(MSK_UART_ENABLE_RX | MSK_UART_ENABLE_TX))

#define Uart2_tx_ready()                     ((BM3803_REG.UartStatus2 & MSK_UART_TXh_READY)  == MSK_UART_TXh_READY )
#define Uart2_rx_ready()                     ((BM3803_REG.UartStatus2 & MSK_UART_DATA_READY) == MSK_UART_DATA_READY)

#define Uart2_send_byte(ch)  		     (BM3803_REG.UartData2 = ch)

/***************************************************************************************************************************************/

#define Uart3_set_baudrate(baudrate)	    (BM3803_REG.UartScaler3 = (((BOARD_CPU_CLOCK*10)/(baudrate*8))-5)/10)

#define Uart3_parity_config(uart_parity)     ( uart_parity    ==  ODD                                                      \
                                            ? (BM3803_REG.UartCtrl3   =   ((BM3803_REG.UartCtrl3 |  MSK_UART_PAR) | MSK_UART_ENABLE_PAR)) \
                                            : ( uart_parity  ==  EVEN                                                     \
                                              ? (BM3803_REG.UartCtrl3 =   ((BM3803_REG.UartCtrl3 & ~MSK_UART_PAR) | MSK_UART_ENABLE_PAR)) \
                                              : (BM3803_REG.UartCtrl3 &= ~MSK_UART_ENABLE_PAR )                                   \
                                              )                                                                           \
                                            )

#define Uart3_flow_ctrl_config(uart_flow)    ( uart_flow    ==  ON                     \
                                            ? (BM3803_REG.UartCtrl3 |=  MSK_UART_ENABLE_FLOW) \
                                            : (BM3803_REG.UartCtrl3 &= ~MSK_UART_ENABLE_FLOW) \
                                            )      
                                           
#define Uart3_loopback_config(uart_loopb)    ( uart_loopb   ==  ON                     \
                                            ? (BM3803_REG.UartCtrl3 |=  MSK_UART_LOOPBACK)    \
                                            : (BM3803_REG.UartCtrl3 &= ~MSK_UART_LOOPBACK)    \
                                            )    

#define Uart3_enable()                       (BM3803_REG.UartCtrl3 |=  (MSK_UART_ENABLE_RX | MSK_UART_ENABLE_TX))
#define Uart3_disable()                      (BM3803_REG.UartCtrl3 &= ~(MSK_UART_ENABLE_RX | MSK_UART_ENABLE_TX))

#define Uart3_tx_ready()                     ((BM3803_REG.UartStatus3 & MSK_UART_TXh_READY)  == MSK_UART_TXh_READY )
#define Uart3_rx_ready()                     ((BM3803_REG.UartStatus3 & MSK_UART_DATA_READY) == MSK_UART_DATA_READY)

#define Uart3_send_byte(ch)  		     (BM3803_REG.UartData3 = ch)
/************************************************************************************
 * Public Types
 ************************************************************************************/

#ifndef __ASSEMBLY__

/************************************************************************************
 * Inline Functions
 ************************************************************************************/

/************************************************************************************
 * Public Function Prototypes
 ************************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_SPARC_SRC_BM3803_BM3803_UART_H */
