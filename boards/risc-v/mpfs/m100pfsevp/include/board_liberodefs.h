/****************************************************************************
 * boards/risc-v/mpfs/m100pfsevp/include/board_liberodefs.h
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

#ifndef __BOARDS_RISCV_MPFS_M100PFSEVP_INCLUDE_BOARD_LIBERODEFS_H
#define __BOARDS_RISCV_MPFS_M100PFSEVP_INCLUDE_BOARD_LIBERODEFS_H

/* These are constants provided by the vendor. Values have been synced from
 * hart-software-services (HSS) with the tag: 2021.08
 */

#define LIBERO_SETTING_MSS_EXT_SGMII_REF_CLK 125000000
#define LIBERO_SETTING_MSS_RTC_TOGGLE_CLK    1000000
#define LIBERO_SETTING_MSS_ENVM_CR           0x40050006
#define LIBERO_SETTING_MSS_CLOCK_CONFIG_CR   0x00000024
#define LIBERO_SETTING_MSS_MSSCLKMUX         0x00000003
#define LIBERO_SETTING_MSS_PLL_CKMUX         0x00000155
#define LIBERO_SETTING_MSS_BCLKMUX           0x00000208
#define LIBERO_SETTING_MSS_FMETER_ADDR       0x00000000
#define LIBERO_SETTING_MSS_FMETER_DATAW      0x00000000
#define LIBERO_SETTING_MSS_FMETER_DATAR      0x00000000
#define LIBERO_SETTING_MSS_PLL_REF_FB        0x00000500
#define LIBERO_SETTING_MSS_PLL_CTRL          0x01000037
#define LIBERO_SETTING_MSS_PLL_DIV_0_1       0x01000200
#define LIBERO_SETTING_MSS_PLL_DIV_2_3       0x0f000600
#define LIBERO_SETTING_MSS_SSCG_REG_0        0x00000000
#define LIBERO_SETTING_MSS_SSCG_REG_1        0x00000000
#define LIBERO_SETTING_MSS_SSCG_REG_2        0x000000c0
#define LIBERO_SETTING_MSS_SSCG_REG_3        0x00000001
#define LIBERO_SETTING_MSS_PLL_FRACN         0x00000000
#define LIBERO_SETTING_MSS_PLL_CTRL2         0x00001020
#define LIBERO_SETTING_MSS_PLL_PHADJ         0x00004003

#define LIBERO_SETTING_CH0_CNTL              0x00fe0002
#define LIBERO_SETTING_CH1_CNTL              0x00fe0002
#define LIBERO_SETTING_SPARE_CNTL            0xff000000

#define LIBERO_SETTING_SGMII_SGMII_CLKMUX    0x00000005
#define LIBERO_SETTING_SGMII_CLK_XCVR        0x00002c30
#define LIBERO_SETTING_SGMII_REFCLKMUX       0x00000005
#define LIBERO_SETTING_SGMII_PLL_CTRL        0x0100003e
#define LIBERO_SETTING_SGMII_PLL_REF_FB      0x00000100
#define LIBERO_SETTING_SGMII_PLL_DIV_0_1     0x01000100
#define LIBERO_SETTING_SGMII_PLL_DIV_2_3     0x01000100
#define LIBERO_SETTING_SGMII_PLL_CTRL2       0x00001020
#define LIBERO_SETTING_SGMII_PLL_FRACN       0x00000000
#define LIBERO_SETTING_SGMII_SSCG_REG_0      0x00000000
#define LIBERO_SETTING_SGMII_SSCG_REG_1      0x00000000
#define LIBERO_SETTING_SGMII_SSCG_REG_2      0x00000019
#define LIBERO_SETTING_SGMII_SSCG_REG_3      0x00000001
#define LIBERO_SETTING_SGMII_PLL_PHADJ       0x00007443
#define LIBERO_SETTING_SGMII_MODE            0x08c0e6ff
#define LIBERO_SETTING_RECAL_CNTL            0x000020c8
#define LIBERO_SETTING_CLK_CNTL              0xf00050cc
#define LIBERO_SETTING_PLL_CNTL              0x80140101

#define LIBERO_SETTING_TRAINING_SKIP_SETTING 0x00000000

#define LIBERO_SETTING_DDRPHY_MODE_OFF       0x00000000
#define LIBERO_SETTING_DPC_BITS_OFF_MODE     0x00000000
#define LIBERO_SETTING_DDRPHY_MODE           0x00002122

#define LIBERO_SETTING_RPC_ODT_DQ            0x00000006
#define LIBERO_SETTING_RPC_ODT_DQS           0x00000006
#define LIBERO_SETTING_RPC_ODT_ADDCMD        0x00000006
#define LIBERO_SETTING_RPC_ODT_CLK           0x00000006
#define LIBERO_SETTING_RPC_EN_ADDCMD0_OVRT9  0x00000000
#define LIBERO_SETTING_RPC_EN_ADDCMD1_OVRT10 0x00000003
#define LIBERO_SETTING_RPC_EN_ADDCMD2_OVRT11 0x00000dc4
#define LIBERO_SETTING_RPC_EN_DATA0_OVRT12   0x00000000
#define LIBERO_SETTING_RPC_EN_DATA1_OVRT13   0x00000000
#define LIBERO_SETTING_RPC_EN_DATA2_OVRT14   0x00000000
#define LIBERO_SETTING_RPC_EN_DATA3_OVRT15   0x00000000
#define LIBERO_SETTING_RPC_EN_ECC_OVRT16     0x0000007f
#define LIBERO_SETTING_RPC235_WPD_ADD_CMD0   0x00000000
#define LIBERO_SETTING_RPC236_WPD_ADD_CMD1   0x00000000
#define LIBERO_SETTING_RPC237_WPD_ADD_CMD2   0x00000000
#define LIBERO_SETTING_RPC238_WPD_DATA0      0x00000000
#define LIBERO_SETTING_RPC239_WPD_DATA1      0x00000000
#define LIBERO_SETTING_RPC240_WPD_DATA2      0x00000000
#define LIBERO_SETTING_RPC241_WPD_DATA3      0x00000000
#define LIBERO_SETTING_RPC242_WPD_ECC        0x00000000
#define LIBERO_SETTING_RPC243_WPU_ADD_CMD0   0x00000fff
#define LIBERO_SETTING_RPC244_WPU_ADD_CMD1   0x00000fff
#define LIBERO_SETTING_RPC245_WPU_ADD_CMD2   0x00000fff
#define LIBERO_SETTING_RPC246_WPU_DATA0      0x000007ff
#define LIBERO_SETTING_RPC247_WPU_DATA1      0x000007ff
#define LIBERO_SETTING_RPC248_WPU_DATA2      0x000007ff
#define LIBERO_SETTING_RPC249_WPU_DATA3      0x000007ff
#define LIBERO_SETTING_RPC250_WPU_ECC        0x0000007f

#define LIBERO_SETTING_DDR_SOFT_RESET        0x00000000
#define LIBERO_SETTING_DDR_PLL_CTRL          0x0100003f
#define LIBERO_SETTING_DDR_PLL_REF_FB        0x00000500
#define LIBERO_SETTING_DDR_PLL_FRACN         0x00000000
#define LIBERO_SETTING_DDR_PLL_DIV_0_1       0x02000100
#define LIBERO_SETTING_DDR_PLL_DIV_2_3       0x01000100
#define LIBERO_SETTING_DDR_PLL_CTRL2         0x00001020
#define LIBERO_SETTING_DDR_PLL_CAL           0x00000d06
#define LIBERO_SETTING_DDR_PLL_PHADJ         0x00005003
#define LIBERO_SETTING_DDR_SSCG_REG_0        0x00000000
#define LIBERO_SETTING_DDR_SSCG_REG_1        0x00000000
#define LIBERO_SETTING_DDR_SSCG_REG_2        0x00000080
#define LIBERO_SETTING_DDR_SSCG_REG_3        0x00000001

#define LIBERO_SETTING_CFG_MANUAL_ADDRESS_MAP 0x00000000
#define LIBERO_SETTING_CFG_CHIPADDR_MAP       0x00000000
#define LIBERO_SETTING_CFG_CIDADDR_MAP        0x00000000
#define LIBERO_SETTING_CFG_BANKADDR_MAP_0     0x00000000
#define LIBERO_SETTING_CFG_BANKADDR_MAP_1     0x00000000
#define LIBERO_SETTING_CFG_ROWADDR_MAP_0      0x00000000
#define LIBERO_SETTING_CFG_ROWADDR_MAP_1      0x00000000
#define LIBERO_SETTING_CFG_ROWADDR_MAP_2      0x00000000
#define LIBERO_SETTING_CFG_ROWADDR_MAP_3      0x00000000
#define LIBERO_SETTING_CFG_COLADDR_MAP_0      0x00000000
#define LIBERO_SETTING_CFG_COLADDR_MAP_1      0x00000000
#define LIBERO_SETTING_CFG_COLADDR_MAP_2      0x00000000
#define LIBERO_SETTING_CFG_VRCG_ENABLE        0x00000140
#define LIBERO_SETTING_CFG_VRCG_DISABLE       0x000000a0
#define LIBERO_SETTING_CFG_WRITE_LATENCY_SET  0x00000000

#define LIBERO_SETTING_CFG_THERMAL_OFFSET      0x00000000
#define LIBERO_SETTING_CFG_SOC_ODT             0x00000000
#define LIBERO_SETTING_CFG_ODTE_CK             0x00000000
#define LIBERO_SETTING_CFG_ODTE_CS             0x00000000
#define LIBERO_SETTING_CFG_ODTD_CA             0x00000000
#define LIBERO_SETTING_CFG_LPDDR4_FSP_OP       0x00000000
#define LIBERO_SETTING_CFG_DBI_CL              0x0000000b
#define LIBERO_SETTING_CFG_NON_DBI_CL          0x0000000b
#define LIBERO_SETTING_CFG_WRITE_CRC           0x00000000
#define LIBERO_SETTING_CFG_MPR_READ_FORMAT     0x00000000
#define LIBERO_SETTING_CFG_WR_CMD_LAT_CRC_DM   0x00000000
#define LIBERO_SETTING_CFG_FINE_GRAN_REF_MODE  0x00000000
#define LIBERO_SETTING_CFG_TEMP_SENSOR_READOUT 0x00000000
#define LIBERO_SETTING_CFG_PER_DRAM_ADDR_EN    0x00000000
#define LIBERO_SETTING_CFG_GEARDOWN_MODE       0x00000000
#define LIBERO_SETTING_CFG_WR_PREAMBLE         0x00000000
#define LIBERO_SETTING_CFG_RD_PREAMBLE         0x00000000
#define LIBERO_SETTING_CFG_RD_PREAMB_TRN_MODE  0x00000000
#define LIBERO_SETTING_CFG_SR_ABORT            0x00000000

#define LIBERO_SETTING_CFG_INT_VREF_MON      0x00000000
#define LIBERO_SETTING_CFG_MAX_PWR_DOWN_MODE 0x00000000
#define LIBERO_SETTING_CFG_READ_DBI          0x00000000
#define LIBERO_SETTING_CFG_WRITE_DBI         0x00000000
#define LIBERO_SETTING_CFG_DATA_MASK         0x00000001
#define LIBERO_SETTING_CFG_RTT_PARK          0x00000000
#define LIBERO_SETTING_CFG_ODT_INBUF_4_PD    0x00000001
#define LIBERO_SETTING_CFG_CCD_S             0x00000004
#define LIBERO_SETTING_CFG_CCD_L             0x00000005
#define LIBERO_SETTING_CFG_VREFDQ_TRN_ENABLE 0x00000001
#define LIBERO_SETTING_CFG_VREFDQ_TRN_RANGE  0x00000001
#define LIBERO_SETTING_CFG_VREFDQ_TRN_VALUE  0x0000001e
#define LIBERO_SETTING_CFG_RRD_S             0x00000005
#define LIBERO_SETTING_CFG_RRD_L             0x00000006
#define LIBERO_SETTING_CFG_WTR_S             0x00000002
#define LIBERO_SETTING_CFG_WTR_L             0x00000006
#define LIBERO_SETTING_CFG_WTR_S_CRC_DM      0x00000007
#define LIBERO_SETTING_CFG_WTR_L_CRC_DM      0x0000000b
#define LIBERO_SETTING_CFG_WR_CRC_DM         0x00000011
#define LIBERO_SETTING_CFG_RFC1              0x00000118
#define LIBERO_SETTING_CFG_RFC2              0x00000000
#define LIBERO_SETTING_CFG_RFC4              0x00000000
#define LIBERO_SETTING_CFG_NIBBLE_DEVICES    0x00000000

#define LIBERO_SETTING_CFG_MB_AUTOPCH_COL_BIT_POS_LOW  0x00000004
#define LIBERO_SETTING_CFG_MB_AUTOPCH_COL_BIT_POS_HIGH 0x0000000a
#define LIBERO_SETTING_CFG_CA_PARITY_ERR_STATUS        0x00000000
#define LIBERO_SETTING_CFG_CRC_ERROR_CLEAR             0x00000000
#define LIBERO_SETTING_CFG_CA_PARITY_LATENCY           0x00000000
#define LIBERO_SETTING_CFG_CA_PARITY_PERSIST_ERR       0x00000000
#define LIBERO_SETTING_CFG_GENERATE_REFRESH_ON_SRX     0x00000001
#define LIBERO_SETTING_CFG_CS_TO_CMDADDR_LATENCY       0x00000000

#define LIBERO_SETTING_CFG_TEMP_CTRL_REF_MODE   0x00000000
#define LIBERO_SETTING_CFG_TEMP_CTRL_REF_RANGE  0x00000000

#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS0_0  0x81881881
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS0_1  0x00008818
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS1_0  0xa92a92a9
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS1_1  0x00002a92
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS2_0  0xc28c28c2
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS2_1  0x00008c28
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS3_0  0xea2ea2ea
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS3_1  0x00002ea2
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS4_0  0x03903903
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS4_1  0x00009039
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS5_0  0x2b32b32b
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS5_1  0x000032b3
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS6_0  0x44944944
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS6_1  0x00009449
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS7_0  0x6c36c36c
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS7_1  0x000036c3
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS8_0  0x85985985
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS8_1  0x00009859
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS9_0  0xad3ad3ad
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS9_1  0x00003ad3
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS10_0 0xc69c69c6
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS10_1 0x00009c69
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS11_0 0xee3ee3ee
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS11_1 0x00003ee3
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS12_0 0x07a07a07
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS12_1 0x0000a07a
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS13_0 0x2f42f42f
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS13_1 0x000042f4
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS14_0 0x48a48a48
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS14_1 0x0000a48a
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS15_0 0x70470470
#define LIBERO_SETTING_CFG_BIT_MAP_INDEX_CS15_1 0x00004704

#define LIBERO_SETTING_CFG_NUM_LOGICAL_RANKS_PER_3DS 0x00000000
#define LIBERO_SETTING_CFG_ADVANCE_ACTIVATE_READY    0x00000000

#define LIBERO_SETTING_CFG_RFC_DLR1           0x00000000
#define LIBERO_SETTING_CFG_RFC_DLR2           0x00000000
#define LIBERO_SETTING_CFG_RFC_DLR4           0x00000000
#define LIBERO_SETTING_CFG_RRD_DLR            0x00000000
#define LIBERO_SETTING_CFG_FAW_DLR            0x00000000
#define LIBERO_SETTING_CTRLR_SOFT_RESET_N     0x00000001
#define LIBERO_SETTING_CFG_LOOKAHEAD_PCH      0x00000000
#define LIBERO_SETTING_CFG_LOOKAHEAD_ACT      0x00000000
#define LIBERO_SETTING_CFG_BL                 0x00000000
#define LIBERO_SETTING_CTRLR_INIT             0x00000000
#define LIBERO_SETTING_CFG_AUTO_REF_EN        0x00000001
#define LIBERO_SETTING_CFG_RAS                0x0000001c
#define LIBERO_SETTING_CFG_RCD                0x0000000b
#define LIBERO_SETTING_CFG_RRD                0x00000007
#define LIBERO_SETTING_CFG_RP                 0x0000000b
#define LIBERO_SETTING_CFG_RC                 0x00000027
#define LIBERO_SETTING_CFG_FAW                0x0000001c
#define LIBERO_SETTING_CFG_RFC                0x00000076
#define LIBERO_SETTING_CFG_RTP                0x00000006
#define LIBERO_SETTING_CFG_WR                 0x0000000c
#define LIBERO_SETTING_CFG_WTR                0x00000008
#define LIBERO_SETTING_CFG_PASR               0x00000000
#define LIBERO_SETTING_CFG_XP                 0x00000003
#define LIBERO_SETTING_CFG_XSR                0x00000024
#define LIBERO_SETTING_CFG_CL                 0x0000000b
#define LIBERO_SETTING_CFG_READ_TO_WRITE      0x00000002
#define LIBERO_SETTING_CFG_WRITE_TO_WRITE     0x00000002
#define LIBERO_SETTING_CFG_READ_TO_READ       0x00000002
#define LIBERO_SETTING_CFG_WRITE_TO_READ      0x00000001
#define LIBERO_SETTING_CFG_READ_TO_WRITE_ODT  0x00000004
#define LIBERO_SETTING_CFG_WRITE_TO_WRITE_ODT 0x00000002
#define LIBERO_SETTING_CFG_READ_TO_READ_ODT   0x00000002
#define LIBERO_SETTING_CFG_WRITE_TO_READ_ODT  0x00000001
#define LIBERO_SETTING_CFG_MIN_READ_IDLE      0x00000007
#define LIBERO_SETTING_CFG_MRD                0x00000010
#define LIBERO_SETTING_CFG_BT                 0x00000000
#define LIBERO_SETTING_CFG_DS                 0x00000000
#define LIBERO_SETTING_CFG_QOFF               0x00000000
#define LIBERO_SETTING_CFG_RTT                0x00000001
#define LIBERO_SETTING_CFG_DLL_DISABLE        0x00000000
#define LIBERO_SETTING_CFG_REF_PER            0x00001860
#define LIBERO_SETTING_CFG_STARTUP_DELAY      0x00027100
#define LIBERO_SETTING_CFG_MEM_COLBITS        0x0000000a
#define LIBERO_SETTING_CFG_MEM_ROWBITS        0x00000010
#define LIBERO_SETTING_CFG_MEM_BANKBITS       0x00000003

#define LIBERO_SETTING_CFG_ODT_RD_MAP_CS0  0x00000000
#define LIBERO_SETTING_CFG_ODT_RD_MAP_CS1  0x00000000
#define LIBERO_SETTING_CFG_ODT_RD_MAP_CS2  0x00000000
#define LIBERO_SETTING_CFG_ODT_RD_MAP_CS3  0x00000000
#define LIBERO_SETTING_CFG_ODT_RD_MAP_CS4  0x00000000
#define LIBERO_SETTING_CFG_ODT_RD_MAP_CS5  0x00000000
#define LIBERO_SETTING_CFG_ODT_RD_MAP_CS6  0x00000000
#define LIBERO_SETTING_CFG_ODT_RD_MAP_CS7  0x00000000
#define LIBERO_SETTING_CFG_ODT_WR_MAP_CS0  0x00000000
#define LIBERO_SETTING_CFG_ODT_WR_MAP_CS1  0x00000000
#define LIBERO_SETTING_CFG_ODT_WR_MAP_CS2  0x00000000
#define LIBERO_SETTING_CFG_ODT_WR_MAP_CS3  0x00000000
#define LIBERO_SETTING_CFG_ODT_WR_MAP_CS4  0x00000000
#define LIBERO_SETTING_CFG_ODT_WR_MAP_CS5  0x00000000
#define LIBERO_SETTING_CFG_ODT_WR_MAP_CS6  0x00000000
#define LIBERO_SETTING_CFG_ODT_WR_MAP_CS7  0x00000000
#define LIBERO_SETTING_CFG_ODT_RD_TURN_ON  0x00000000
#define LIBERO_SETTING_CFG_ODT_WR_TURN_ON  0x00000000
#define LIBERO_SETTING_CFG_ODT_RD_TURN_OFF 0x00000000
#define LIBERO_SETTING_CFG_ODT_WR_TURN_OFF 0x00000000

#define LIBERO_SETTING_CFG_EMR3                         0x00000000
#define LIBERO_SETTING_CFG_TWO_T                        0x00000000
#define LIBERO_SETTING_CFG_TWO_T_SEL_CYCLE              0x00000001
#define LIBERO_SETTING_CFG_REGDIMM                      0x00000000
#define LIBERO_SETTING_CFG_MOD                          0x00000018
#define LIBERO_SETTING_CFG_XS                           0x00000120
#define LIBERO_SETTING_CFG_XSDLL                        0x00000200
#define LIBERO_SETTING_CFG_XPR                          0x00000120
#define LIBERO_SETTING_CFG_AL_MODE                      0x00000000
#define LIBERO_SETTING_CFG_CWL                          0x0000000b
#define LIBERO_SETTING_CFG_BL_MODE                      0x00000000
#define LIBERO_SETTING_CFG_TDQS                         0x00000000
#define LIBERO_SETTING_CFG_RTT_WR                       0x00000000
#define LIBERO_SETTING_CFG_LP_ASR                       0x00000003
#define LIBERO_SETTING_CFG_AUTO_SR                      0x00000000
#define LIBERO_SETTING_CFG_SRT                          0x00000000
#define LIBERO_SETTING_CFG_ADDR_MIRROR                  0x00000000
#define LIBERO_SETTING_CFG_ZQ_CAL_TYPE                  0x00000000
#define LIBERO_SETTING_CFG_ZQ_CAL_PER                   0x00027100
#define LIBERO_SETTING_CFG_AUTO_ZQ_CAL_EN               0x00000000
#define LIBERO_SETTING_CFG_MEMORY_TYPE                  0x00000080
#define LIBERO_SETTING_CFG_ONLY_SRANK_CMDS              0x00000000
#define LIBERO_SETTING_CFG_NUM_RANKS                    0x00000001
#define LIBERO_SETTING_CFG_QUAD_RANK                    0x00000000
#define LIBERO_SETTING_CFG_EARLY_RANK_TO_WR_START       0x00000000
#define LIBERO_SETTING_CFG_EARLY_RANK_TO_RD_START       0x00000000
#define LIBERO_SETTING_CFG_PASR_BANK                    0x00000000
#define LIBERO_SETTING_CFG_PASR_SEG                     0x00000000
#define LIBERO_SETTING_CFG_INIT_DURATION                0x000029b0
#define LIBERO_SETTING_CFG_ZQINIT_CAL_DURATION          0x00000400
#define LIBERO_SETTING_CFG_ZQ_CAL_L_DURATION            0x00000200
#define LIBERO_SETTING_CFG_ZQ_CAL_S_DURATION            0x00000080
#define LIBERO_SETTING_CFG_ZQ_CAL_R_DURATION            0x0000000b
#define LIBERO_SETTING_CFG_MRR                          0x00000002
#define LIBERO_SETTING_CFG_MRW                          0x00000010
#define LIBERO_SETTING_CFG_ODT_POWERDOWN                0x00000000
#define LIBERO_SETTING_CFG_WL                           0x00000009
#define LIBERO_SETTING_CFG_RL                           0x0000000e
#define LIBERO_SETTING_CFG_CAL_READ_PERIOD              0x00000000
#define LIBERO_SETTING_CFG_NUM_CAL_READS                0x00000001

#define LIBERO_SETTING_INIT_FORCE_WRITE_DATA_0          0x00000000
#define LIBERO_SETTING_INIT_AUTOINIT_DISABLE            0x00000000
#define LIBERO_SETTING_INIT_FORCE_RESET                 0x00000000
#define LIBERO_SETTING_INIT_GEARDOWN_EN                 0x00000000
#define LIBERO_SETTING_INIT_DISABLE_CKE                 0x00000000
#define LIBERO_SETTING_INIT_CS                          0x00000000
#define LIBERO_SETTING_INIT_PRECHARGE_ALL               0x00000000
#define LIBERO_SETTING_INIT_REFRESH                     0x00000000
#define LIBERO_SETTING_INIT_ZQ_CAL_REQ                  0x00000000
#define LIBERO_SETTING_INIT_MRR_MODE                    0x00000000
#define LIBERO_SETTING_INIT_MR_W_REQ                    0x00000000
#define LIBERO_SETTING_INIT_MR_ADDR                     0x00000000
#define LIBERO_SETTING_INIT_MR_WR_DATA                  0x00000000
#define LIBERO_SETTING_INIT_MR_WR_MASK                  0x00000000
#define LIBERO_SETTING_INIT_NOP                         0x00000000
#define LIBERO_SETTING_INIT_SELF_REFRESH                0x00000000
#define LIBERO_SETTING_INIT_POWER_DOWN                  0x00000000
#define LIBERO_SETTING_INIT_FORCE_WRITE                 0x00000000
#define LIBERO_SETTING_INIT_FORCE_WRITE_CS              0x00000000
#define LIBERO_SETTING_INIT_RDIMM_COMPLETE              0x00000000
#define LIBERO_SETTING_INIT_MEMORY_RESET_MASK           0x00000000
#define LIBERO_SETTING_INIT_CAL_SELECT                  0x00000000
#define LIBERO_SETTING_INIT_CAL_L_R_REQ                 0x00000000
#define LIBERO_SETTING_INIT_CAL_L_B_SIZE                0x00000000
#define LIBERO_SETTING_INIT_RWFIFO                      0x00000000
#define LIBERO_SETTING_INIT_RD_DQCAL                    0x00000000
#define LIBERO_SETTING_INIT_START_DQSOSC                0x00000000
#define LIBERO_SETTING_INIT_STOP_DQSOSC                 0x00000000
#define LIBERO_SETTING_INIT_ZQ_CAL_START                0x00000000
#define LIBERO_SETTING_INIT_CAL_L_ADDR_0                0x00000000
#define LIBERO_SETTING_INIT_CAL_L_ADDR_1                0x00000000
#define LIBERO_SETTING_INIT_ODT_FORCE_EN                0x00000000
#define LIBERO_SETTING_INIT_ODT_FORCE_RANK              0x00000000
#define LIBERO_SETTING_INIT_PDA_MR_W_REQ                0x00000000
#define LIBERO_SETTING_INIT_PDA_NIBBLE_SELECT           0x00000000
#define LIBERO_SETTING_INIT_WRITE_DATA_1B_ECC_ERROR_GEN 0x00000000
#define LIBERO_SETTING_INIT_WRITE_DATA_2B_ECC_ERROR_GEN 0x00000000
#define LIBERO_SETTING_INIT_READ_CAPTURE_ADDR           0x00000000
#define LIBERO_SETTING_INIT_CA_PARITY_ERROR_GEN_REQ     0x00000000
#define LIBERO_SETTING_INIT_CA_PARITY_ERROR_GEN_CMD     0x00000000
#define LIBERO_SETTING_INIT_DFI_LP_DATA_REQ             0x00000000
#define LIBERO_SETTING_INIT_DFI_LP_CTRL_REQ             0x00000000
#define LIBERO_SETTING_INIT_DFI_LP_WAKEUP               0x00000000
#define LIBERO_SETTING_INIT_DFI_DRAM_CLK_DISABLE        0x00000000

#define LIBERO_SETTING_CFG_CTRLR_INIT_DISABLE           0x00000000
#define LIBERO_SETTING_CFG_RDIMM_LAT                    0x00000000
#define LIBERO_SETTING_CFG_RDIMM_BSIDE_INVERT           0x00000001
#define LIBERO_SETTING_CFG_LRDIMM                       0x00000000
#define LIBERO_SETTING_CFG_RD_PREAMB_TOGGLE             0x00000000
#define LIBERO_SETTING_CFG_RD_POSTAMBLE                 0x00000000
#define LIBERO_SETTING_CFG_PU_CAL                       0x00000000
#define LIBERO_SETTING_CFG_DQ_ODT                       0x00000000
#define LIBERO_SETTING_CFG_CA_ODT                       0x00000000
#define LIBERO_SETTING_CFG_ZQLATCH_DURATION             0x00000030

#define LIBERO_SETTING_CFG_WR_POSTAMBLE                 0x00000000
#define LIBERO_SETTING_CFG_CTRLUPD_TRIG                 0x00000000
#define LIBERO_SETTING_CFG_CTRLUPD_START_DELAY          0x00000000
#define LIBERO_SETTING_CFG_DFI_T_CTRLUPD_MAX            0x00000000
#define LIBERO_SETTING_CFG_CTRLR_BUSY_SEL               0x00000000
#define LIBERO_SETTING_CFG_CTRLR_BUSY_VALUE             0x00000000
#define LIBERO_SETTING_CFG_CTRLR_BUSY_TURN_OFF_DELAY    0x00000000
#define LIBERO_SETTING_CFG_CTRLR_BUSY_SLOW_RESTART_WIN  0x00000000
#define LIBERO_SETTING_CFG_CTRLR_BUSY_RESTART_HOLDOFF   0x00000000
#define LIBERO_SETTING_CFG_PARITY_RDIMM_DELAY           0x00000000
#define LIBERO_SETTING_CFG_CTRLR_BUSY_ENABLE            0x00000000
#define LIBERO_SETTING_CFG_ASYNC_ODT                    0x00000000
#define LIBERO_SETTING_CFG_ZQ_CAL_DURATION              0x00000640
#define LIBERO_SETTING_CFG_MRRI                         0x00000000
#define LIBERO_SETTING_CFG_PHYUPD_ACK_DELAY             0x00000000
#define LIBERO_SETTING_CFG_MIRROR_X16_BG0_BG1           0x00000000
#define LIBERO_SETTING_CFG_DRAM_CLK_DISABLE_IN_SELF_RFH 0x00000000
#define LIBERO_SETTING_CFG_CKSRE                        0x00000008
#define LIBERO_SETTING_CFG_CKSRX                        0x0000000b
#define LIBERO_SETTING_CFG_RCD_STAB                     0x00000000
#define LIBERO_SETTING_CFG_DFI_T_CTRL_DELAY             0x00000000
#define LIBERO_SETTING_CFG_DFI_T_DRAM_CLK_ENABLE        0x00000000
#define LIBERO_SETTING_CFG_IDLE_TIME_TO_SELF_REFRESH    0x00000000
#define LIBERO_SETTING_CFG_IDLE_TIME_TO_POWER_DOWN      0x00000000
#define LIBERO_SETTING_CFG_BURST_RW_REFRESH_HOLDOFF     0x00000000
#define LIBERO_SETTING_CFG_BG_INTERLEAVE                0x00000001
#define LIBERO_SETTING_CFG_REFRESH_DURING_PHY_TRAINING  0x00000000
#define LIBERO_SETTING_CFG_STARVE_TIMEOUT_P0            0x00000000
#define LIBERO_SETTING_CFG_STARVE_TIMEOUT_P1            0x00000000
#define LIBERO_SETTING_CFG_STARVE_TIMEOUT_P2            0x00000000
#define LIBERO_SETTING_CFG_STARVE_TIMEOUT_P3            0x00000000
#define LIBERO_SETTING_CFG_STARVE_TIMEOUT_P4            0x00000000
#define LIBERO_SETTING_CFG_STARVE_TIMEOUT_P5            0x00000000
#define LIBERO_SETTING_CFG_STARVE_TIMEOUT_P6            0x00000000
#define LIBERO_SETTING_CFG_STARVE_TIMEOUT_P7            0x00000000
#define LIBERO_SETTING_CFG_REORDER_EN                   0x00000001
#define LIBERO_SETTING_CFG_REORDER_QUEUE_EN             0x00000001
#define LIBERO_SETTING_CFG_INTRAPORT_REORDER_EN         0x00000000
#define LIBERO_SETTING_CFG_MAINTAIN_COHERENCY           0x00000001
#define LIBERO_SETTING_CFG_Q_AGE_LIMIT                  0x000000ff
#define LIBERO_SETTING_CFG_RO_CLOSED_PAGE_POLICY        0x00000000
#define LIBERO_SETTING_CFG_REORDER_RW_ONLY              0x00000000
#define LIBERO_SETTING_CFG_RO_PRIORITY_EN               0x00000000
#define LIBERO_SETTING_CFG_DM_EN                        0x00000001
#define LIBERO_SETTING_CFG_RMW_EN                       0x00000000
#define LIBERO_SETTING_CFG_ECC_CORRECTION_EN            0x00000000
#define LIBERO_SETTING_CFG_ECC_BYPASS                   0x00000000
#define LIBERO_SETTING_CFG_ECC_1BIT_INT_THRESH          0x00000000
#define LIBERO_SETTING_CFG_ERROR_GROUP_SEL              0x00000000
#define LIBERO_SETTING_CFG_DATA_SEL                     0x00000000
#define LIBERO_SETTING_CFG_TRIG_MODE                    0x00000000
#define LIBERO_SETTING_CFG_POST_TRIG_CYCS               0x00000000
#define LIBERO_SETTING_CFG_TRIG_MASK                    0x00000000
#define LIBERO_SETTING_CFG_EN_MASK                      0x00000000
#define LIBERO_SETTING_CFG_TRIG_MT_ADDR_0               0x00000000
#define LIBERO_SETTING_CFG_TRIG_MT_ADDR_1               0x00000000
#define LIBERO_SETTING_CFG_TRIG_ERR_MASK_0              0x00000000
#define LIBERO_SETTING_CFG_TRIG_ERR_MASK_1              0x00000000
#define LIBERO_SETTING_CFG_TRIG_ERR_MASK_2              0x00000000
#define LIBERO_SETTING_CFG_TRIG_ERR_MASK_3              0x00000000
#define LIBERO_SETTING_CFG_TRIG_ERR_MASK_4              0x00000000

#define LIBERO_SETTING_MTC_ACQ_ADDR                     0x00000000
#define LIBERO_SETTING_MTC_ACQ_WR_DATA_0                0x00000000
#define LIBERO_SETTING_MTC_ACQ_WR_DATA_1                0x00000000
#define LIBERO_SETTING_MTC_ACQ_WR_DATA_2                0x00000000

#define LIBERO_SETTING_CFG_PRE_TRIG_CYCS                0x00000000
#define LIBERO_SETTING_CFG_DATA_SEL_FIRST_ERROR         0x00000000
#define LIBERO_SETTING_CFG_DQ_WIDTH                     0x00000000
#define LIBERO_SETTING_CFG_ACTIVE_DQ_SEL                0x00000000
#define LIBERO_SETTING_CFG_DFI_T_RDDATA_EN              0x00000014
#define LIBERO_SETTING_CFG_DFI_T_PHY_RDLAT              0x00000006
#define LIBERO_SETTING_CFG_DFI_T_PHY_WRLAT              0x00000001
#define LIBERO_SETTING_CFG_DFI_PHYUPD_EN                0x00000001
#define LIBERO_SETTING_CFG_DFI_DATA_BYTE_DISABLE        0x00000000
#define LIBERO_SETTING_CFG_DFI_LVL_SEL                  0x00000000
#define LIBERO_SETTING_CFG_DFI_LVL_PERIODIC             0x00000000
#define LIBERO_SETTING_CFG_DFI_LVL_PATTERN              0x00000000
#define LIBERO_SETTING_CFG_AXI_START_ADDRESS_AXI1_0     0x00000000
#define LIBERO_SETTING_CFG_AXI_START_ADDRESS_AXI1_1     0x00000000
#define LIBERO_SETTING_CFG_AXI_START_ADDRESS_AXI2_0     0x00000000
#define LIBERO_SETTING_CFG_AXI_START_ADDRESS_AXI2_1     0x00000000
#define LIBERO_SETTING_CFG_AXI_END_ADDRESS_AXI1_0       0xffffffff
#define LIBERO_SETTING_CFG_AXI_END_ADDRESS_AXI1_1       0x00000003
#define LIBERO_SETTING_CFG_AXI_END_ADDRESS_AXI2_0       0xffffffff
#define LIBERO_SETTING_CFG_AXI_END_ADDRESS_AXI2_1       0x00000003
#define LIBERO_SETTING_CFG_MEM_START_ADDRESS_AXI1_0     0x00000000
#define LIBERO_SETTING_CFG_MEM_START_ADDRESS_AXI1_1     0x00000000
#define LIBERO_SETTING_CFG_MEM_START_ADDRESS_AXI2_0     0x00000000
#define LIBERO_SETTING_CFG_MEM_START_ADDRESS_AXI2_1     0x00000000
#define LIBERO_SETTING_CFG_ENABLE_BUS_HOLD_AXI1         0x00000000
#define LIBERO_SETTING_CFG_ENABLE_BUS_HOLD_AXI2         0x00000000
#define LIBERO_SETTING_CFG_AXI_AUTO_PCH                 0x00000000

#define LIBERO_SETTING_PHY_DFI_INIT_START               0x00000000
#define LIBERO_SETTING_PHY_RESET_CONTROL                0x00008001
#define LIBERO_SETTING_PHY_PC_RANK                      0x00000001
#define LIBERO_SETTING_PHY_RANKS_TO_TRAIN               0x00000001
#define LIBERO_SETTING_PHY_WRITE_REQUEST                0x00000000
#define LIBERO_SETTING_PHY_READ_REQUEST                 0x00000000
#define LIBERO_SETTING_PHY_WRITE_LEVEL_DELAY            0x00000000
#define LIBERO_SETTING_PHY_GATE_TRAIN_DELAY             0x0000002f
#define LIBERO_SETTING_PHY_EYE_TRAIN_DELAY              0x0000003f
#define LIBERO_SETTING_PHY_EYE_PAT                      0x00000000
#define LIBERO_SETTING_PHY_START_RECAL                  0x00000000
#define LIBERO_SETTING_PHY_CLR_DFI_LVL_PERIODIC         0x00000000
#define LIBERO_SETTING_PHY_TRAIN_STEP_ENABLE            0x00000018
#define LIBERO_SETTING_PHY_LPDDR_DQ_CAL_PAT             0x00000000
#define LIBERO_SETTING_PHY_INDPNDT_TRAINING             0x00000001
#define LIBERO_SETTING_PHY_ENCODED_QUAD_CS              0x00000000
#define LIBERO_SETTING_PHY_HALF_CLK_DLY_ENABLE          0x00000000

#define LIBERO_SETTING_SEG0_0 0x00007f80
#define LIBERO_SETTING_SEG0_1 0x00007000
#define LIBERO_SETTING_SEG0_2 0x00000000
#define LIBERO_SETTING_SEG0_3 0x00000000
#define LIBERO_SETTING_SEG0_4 0x00000000
#define LIBERO_SETTING_SEG0_5 0x00000000
#define LIBERO_SETTING_SEG0_6 0x00000000
#define LIBERO_SETTING_SEG0_7 0x00000000
#define LIBERO_SETTING_SEG1_0 0x00000000
#define LIBERO_SETTING_SEG1_1 0x00000000
#define LIBERO_SETTING_SEG1_2 0x00007f40
#define LIBERO_SETTING_SEG1_3 0x00006c00
#define LIBERO_SETTING_SEG1_4 0x00007f30
#define LIBERO_SETTING_SEG1_5 0x00006800
#define LIBERO_SETTING_SEG1_6 0x00000000
#define LIBERO_SETTING_SEG1_7 0x00000000

#define LIBERO_SETTING_TIP_CONFIG_PARAMS_BCLK_VCOPHS_OFFSET  0x00000002
#define LIBERO_SETTING_DDR_CLK                               1600000000

#define LIBERO_SETTING_REFCLK_DDR3_1333_NUM_OFFSETS     3
#define LIBERO_SETTING_REFCLK_DDR3L_1333_NUM_OFFSETS    3
#define LIBERO_SETTING_REFCLK_DDR4_1600_NUM_OFFSETS     2
#define LIBERO_SETTING_REFCLK_LPDDR3_1600_NUM_OFFSETS   3
#define LIBERO_SETTING_REFCLK_LPDDR4_1600_NUM_OFFSETS   4
#define LIBERO_SETTING_REFCLK_DDR3_1067_NUM_OFFSETS     2
#define LIBERO_SETTING_REFCLK_DDR3L_1067_NUM_OFFSETS    2
#define LIBERO_SETTING_REFCLK_DDR4_1333_NUM_OFFSETS     3
#define LIBERO_SETTING_REFCLK_LPDDR3_1333_NUM_OFFSETS   2
#define LIBERO_SETTING_REFCLK_LPDDR4_1333_NUM_OFFSETS   3
#define LIBERO_SETTING_REFCLK_DDR3_1333_OFFSET_0        0
#define LIBERO_SETTING_REFCLK_DDR3_1333_OFFSET_1        1
#define LIBERO_SETTING_REFCLK_DDR3_1333_OFFSET_2        0
#define LIBERO_SETTING_REFCLK_DDR3_1333_OFFSET_3        1
#define LIBERO_SETTING_REFCLK_DDR3L_1333_OFFSET_0       0
#define LIBERO_SETTING_REFCLK_DDR3L_1333_OFFSET_1       1
#define LIBERO_SETTING_REFCLK_DDR3L_1333_OFFSET_2       0
#define LIBERO_SETTING_REFCLK_DDR3L_1333_OFFSET_3       0
#define LIBERO_SETTING_REFCLK_DDR4_1600_OFFSET_0        7
#define LIBERO_SETTING_REFCLK_DDR4_1600_OFFSET_1        0
#define LIBERO_SETTING_REFCLK_DDR4_1600_OFFSET_2        7
#define LIBERO_SETTING_REFCLK_DDR4_1600_OFFSET_3        0
#define LIBERO_SETTING_REFCLK_LPDDR3_1600_OFFSET_0      7
#define LIBERO_SETTING_REFCLK_LPDDR3_1600_OFFSET_1      0
#define LIBERO_SETTING_REFCLK_LPDDR3_1600_OFFSET_2      1
#define LIBERO_SETTING_REFCLK_LPDDR3_1600_OFFSET_3      0
#define LIBERO_SETTING_REFCLK_LPDDR4_1600_OFFSET_0      1
#define LIBERO_SETTING_REFCLK_LPDDR4_1600_OFFSET_1      5
#define LIBERO_SETTING_REFCLK_LPDDR4_1600_OFFSET_2      1
#define LIBERO_SETTING_REFCLK_LPDDR4_1600_OFFSET_3      5
#define LIBERO_SETTING_REFCLK_DDR3_1067_OFFSET_0        1
#define LIBERO_SETTING_REFCLK_DDR3_1067_OFFSET_1        2
#define LIBERO_SETTING_REFCLK_DDR3_1067_OFFSET_2        0
#define LIBERO_SETTING_REFCLK_DDR3_1067_OFFSET_3        2
#define LIBERO_SETTING_REFCLK_DDR3L_1067_OFFSET_0       1
#define LIBERO_SETTING_REFCLK_DDR3L_1067_OFFSET_1       2
#define LIBERO_SETTING_REFCLK_DDR3L_1067_OFFSET_2       0
#define LIBERO_SETTING_REFCLK_DDR3L_1067_OFFSET_3       2
#define LIBERO_SETTING_REFCLK_DDR4_1333_OFFSET_0        0
#define LIBERO_SETTING_REFCLK_DDR4_1333_OFFSET_1        1
#define LIBERO_SETTING_REFCLK_DDR4_1333_OFFSET_2        7
#define LIBERO_SETTING_REFCLK_DDR4_1333_OFFSET_3        0
#define LIBERO_SETTING_REFCLK_LPDDR3_1333_OFFSET_0      0
#define LIBERO_SETTING_REFCLK_LPDDR3_1333_OFFSET_1      1
#define LIBERO_SETTING_REFCLK_LPDDR3_1333_OFFSET_2      6
#define LIBERO_SETTING_REFCLK_LPDDR3_1333_OFFSET_3      0
#define LIBERO_SETTING_REFCLK_LPDDR4_1333_OFFSET_0      1
#define LIBERO_SETTING_REFCLK_LPDDR4_1333_OFFSET_1      2
#define LIBERO_SETTING_REFCLK_LPDDR4_1333_OFFSET_2      3
#define LIBERO_SETTING_REFCLK_LPDDR4_1333_OFFSET_3      0

#define LIBERO_SETTING_TIP_CFG_PARAMS        0x07CFE02B

#define LIBERO_SETTING_DDR_32_CACHE          0x80000000
#define LIBERO_SETTING_DDR_32_CACHE_SIZE     0x100000
#define LIBERO_SETTING_DDR_64_CACHE          0x1000000000
#define LIBERO_SETTING_DDR_64_CACHE_SIZE     0x100000
#define LIBERO_SETTING_DDR_32_NON_CACHE      0xc0000000
#define LIBERO_SETTING_DDR_32_NON_CACHE_SIZE 0x100000
#define LIBERO_SETTING_DDR_64_NON_CACHE      0x1400000000
#define LIBERO_SETTING_DDR_64_NON_CACHE_SIZE 0x100000

#define LIBERO_SETTING_DPC_BITS              0x0004E563
#define LIBERO_SETTING_DATA_LANES_USED       0x00000004

/* Cache settings */

#define LIBERO_SETTING_WAY_MASK_DMA          0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_AXI4_PORT_0  0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_AXI4_PORT_1  0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_AXI4_PORT_2  0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_AXI4_PORT_3  0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_E51_DCACHE   0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_E51_ICACHE   0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_U54_1_DCACHE 0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_U54_1_ICACHE 0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_U54_2_DCACHE 0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_U54_2_ICACHE 0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_U54_3_DCACHE 0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_U54_3_ICACHE 0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_U54_4_DCACHE 0x0000f0ff
#define LIBERO_SETTING_WAY_MASK_U54_4_ICACHE 0x0000f0ff
#define LIBERO_SETTING_NUM_SCRATCH_PAD_WAYS  0x00000004
#define LIBERO_SETTING_L2_SHUTDOWN_CR        0x00000000
#define LIBERO_SETTING_WAY_ENABLE            0x0000000b

/* IOMUX3 and IOMUX4, 0x4 signifies USB */

#define LIBERO_SETTING_IOMUX3_CR                    0x44444444
#define LIBERO_SETTING_IOMUX4_CR                    0x88cc4444

#define LIBERO_SETTING_MSSIO_BANK2_CFG_CR           0x00080907
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_0_1_CR    0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_2_3_CR    0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_4_5_CR    0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_6_7_CR    0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_8_9_CR    0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_10_11_CR  0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_12_13_CR  0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_14_15_CR  0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_16_17_CR  0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_18_19_CR  0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_20_21_CR  0x08290829
#define LIBERO_SETTING_MSSIO_BANK2_IO_CFG_22_23_CR  0x08290829
#define LIBERO_SETTING_MSSIO_VB2_CFG                0x00000828
#define LIBERO_SETTING_MSSIO_VB4_CFG                0x00000828

#endif /* __BOARDS_RISCV_MPFS_M100PFSEVP_INCLUDE_BOARD_LIBERODEFS_H */
