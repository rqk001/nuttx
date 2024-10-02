/****************************************************************************
 * include/nuttx/pci/pci_ids.h
 *
 * SPDX-License-Identifier: Apache-2.0
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

#ifndef __INCLUDE_NUTTX_PCI_PCI_IDS_H
#define __INCLUDE_NUTTX_PCI_PCI_IDS_H

/* Device classes and subclasses */

#define PCI_CLASS_NOT_DEFINED                                     0x0000
#define PCI_CLASS_NOT_DEFINED_VGA                                 0x0001

#define PCI_BASE_CLASS_STORAGE                                    0x01
#define PCI_CLASS_STORAGE_SCSI                                    0x0100
#define PCI_CLASS_STORAGE_IDE                                     0x0101
#define PCI_CLASS_STORAGE_FLOPPY                                  0x0102
#define PCI_CLASS_STORAGE_IPI                                     0x0103
#define PCI_CLASS_STORAGE_RAID                                    0x0104
#define PCI_CLASS_STORAGE_SATA                                    0x0106
#define PCI_CLASS_STORAGE_SATA_AHCI                               0x010601
#define PCI_CLASS_STORAGE_SAS                                     0x0107
#define PCI_CLASS_STORAGE_EXPRESS                                 0x010802
#define PCI_CLASS_STORAGE_OTHER                                   0x0180

#define PCI_BASE_CLASS_NETWORK                                    0x02
#define PCI_CLASS_NETWORK_ETHERNET                                0x0200
#define PCI_CLASS_NETWORK_TOKEN_RING                              0x0201
#define PCI_CLASS_NETWORK_FDDI                                    0x0202
#define PCI_CLASS_NETWORK_ATM                                     0x0203
#define PCI_CLASS_NETWORK_OTHER                                   0x0280

#define PCI_BASE_CLASS_DISPLAY                                    0x03
#define PCI_CLASS_DISPLAY_VGA                                     0x0300
#define PCI_CLASS_DISPLAY_XGA                                     0x0301
#define PCI_CLASS_DISPLAY_3D                                      0x0302
#define PCI_CLASS_DISPLAY_OTHER                                   0x0380

#define PCI_BASE_CLASS_MULTIMEDIA                                 0x04
#define PCI_CLASS_MULTIMEDIA_VIDEO                                0x0400
#define PCI_CLASS_MULTIMEDIA_AUDIO                                0x0401
#define PCI_CLASS_MULTIMEDIA_PHONE                                0x0402
#define PCI_CLASS_MULTIMEDIA_HD_AUDIO                             0x0403
#define PCI_CLASS_MULTIMEDIA_OTHER                                0x0480

#define PCI_BASE_CLASS_MEMORY                                     0x05
#define PCI_CLASS_MEMORY_RAM                                      0x0500
#define PCI_CLASS_MEMORY_FLASH                                    0x0501
#define PCI_CLASS_MEMORY_OTHER                                    0x0580

#define PCI_BASE_CLASS_BRIDGE                                     0x06
#define PCI_CLASS_BRIDGE_HOST                                     0x0600
#define PCI_CLASS_BRIDGE_ISA                                      0x0601
#define PCI_CLASS_BRIDGE_EISA                                     0x0602
#define PCI_CLASS_BRIDGE_MC                                       0x0603
#define PCI_CLASS_BRIDGE_PCI                                      0x0604
#define PCI_CLASS_BRIDGE_PCMCIA                                   0x0605
#define PCI_CLASS_BRIDGE_NUBUS                                    0x0606
#define PCI_CLASS_BRIDGE_CARDBUS                                  0x0607
#define PCI_CLASS_BRIDGE_RACEWAY                                  0x0608
#define PCI_CLASS_BRIDGE_OTHER                                    0x0680

#define PCI_BASE_CLASS_COMMUNICATION                              0x07
#define PCI_CLASS_COMMUNICATION_SERIAL                            0x0700
#define PCI_CLASS_COMMUNICATION_PARALLEL                          0x0701
#define PCI_CLASS_COMMUNICATION_MULTISERIAL                       0x0702
#define PCI_CLASS_COMMUNICATION_MODEM                             0x0703
#define PCI_CLASS_COMMUNICATION_OTHER                             0x0780

#define PCI_BASE_CLASS_SYSTEM                                     0x08
#define PCI_CLASS_SYSTEM_PIC                                      0x0800
#define PCI_CLASS_SYSTEM_PIC_IOAPIC                               0x080010
#define PCI_CLASS_SYSTEM_PIC_IOXAPIC                              0x080020
#define PCI_CLASS_SYSTEM_DMA                                      0x0801
#define PCI_CLASS_SYSTEM_TIMER                                    0x0802
#define PCI_CLASS_SYSTEM_RTC                                      0x0803
#define PCI_CLASS_SYSTEM_PCI_HOTPLUG                              0x0804
#define PCI_CLASS_SYSTEM_SDHCI                                    0x0805
#define PCI_CLASS_SYSTEM_OTHER                                    0x0880

#define PCI_BASE_CLASS_INPUT                                      0x09
#define PCI_CLASS_INPUT_KEYBOARD                                  0x0900
#define PCI_CLASS_INPUT_PEN                                       0x0901
#define PCI_CLASS_INPUT_MOUSE                                     0x0902
#define PCI_CLASS_INPUT_SCANNER                                   0x0903
#define PCI_CLASS_INPUT_GAMEPORT                                  0x0904
#define PCI_CLASS_INPUT_OTHER                                     0x0980

#define PCI_BASE_CLASS_DOCKING                                    0x0a
#define PCI_CLASS_DOCKING_GENERIC                                 0x0a00
#define PCI_CLASS_DOCKING_OTHER                                   0x0a80

#define PCI_BASE_CLASS_PROCESSOR                                  0x0b
#define PCI_CLASS_PROCESSOR_386                                   0x0b00
#define PCI_CLASS_PROCESSOR_486                                   0x0b01
#define PCI_CLASS_PROCESSOR_PENTIUM                               0x0b02
#define PCI_CLASS_PROCESSOR_ALPHA                                 0x0b10
#define PCI_CLASS_PROCESSOR_POWERPC                               0x0b20
#define PCI_CLASS_PROCESSOR_MIPS                                  0x0b30
#define PCI_CLASS_PROCESSOR_CO                                    0x0b40

#define PCI_BASE_CLASS_SERIAL                                     0x0c
#define PCI_CLASS_SERIAL_FIREWIRE                                 0x0c00
#define PCI_CLASS_SERIAL_FIREWIRE_OHCI                            0x0c0010
#define PCI_CLASS_SERIAL_ACCESS                                   0x0c01
#define PCI_CLASS_SERIAL_SSA                                      0x0c02
#define PCI_CLASS_SERIAL_USB                                      0x0c03
#define PCI_CLASS_SERIAL_USB_UHCI                                 0x0c0300
#define PCI_CLASS_SERIAL_USB_OHCI                                 0x0c0310
#define PCI_CLASS_SERIAL_USB_EHCI                                 0x0c0320
#define PCI_CLASS_SERIAL_USB_XHCI                                 0x0c0330
#define PCI_CLASS_SERIAL_USB_DEVICE                               0x0c03fe
#define PCI_CLASS_SERIAL_FIBER                                    0x0c04
#define PCI_CLASS_SERIAL_SMBUS                                    0x0c05
#define PCI_CLASS_SERIAL_IPMI                                     0x0c07
#define PCI_CLASS_SERIAL_IPMI_SMIC                                0x0c0700
#define PCI_CLASS_SERIAL_IPMI_KCS                                 0x0c0701
#define PCI_CLASS_SERIAL_IPMI_BT                                  0x0c0702

#define PCI_BASE_CLASS_WIRELESS                                   0x0d
#define PCI_CLASS_WIRELESS_RF_CONTROLLER                          0x0d10
#define PCI_CLASS_WIRELESS_WHCI                                   0x0d1010

#define PCI_BASE_CLASS_INTELLIGENT                                0x0e
#define PCI_CLASS_INTELLIGENT_I2O                                 0x0e00

#define PCI_BASE_CLASS_SATELLITE                                  0x0f
#define PCI_CLASS_SATELLITE_TV                                    0x0f00
#define PCI_CLASS_SATELLITE_AUDIO                                 0x0f01
#define PCI_CLASS_SATELLITE_VOICE                                 0x0f03
#define PCI_CLASS_SATELLITE_DATA                                  0x0f04

#define PCI_BASE_CLASS_CRYPT                                      0x10
#define PCI_CLASS_CRYPT_NETWORK                                   0x1000
#define PCI_CLASS_CRYPT_ENTERTAINMENT                             0x1001
#define PCI_CLASS_CRYPT_OTHER                                     0x1080

#define PCI_BASE_CLASS_SIGNAL_PROCESSING                          0x11
#define PCI_CLASS_SP_DPIO                                         0x1100
#define PCI_CLASS_SP_OTHER                                        0x1180

#define PCI_CLASS_OTHERS                                          0xff

/* Vendors and devices.  Sort key: vendor first, device next. */

#define PCI_VENDOR_ID_TTTECH                                      0x0357
#define PCI_DEVICE_ID_TTTECH_MC322                                0x000a

#define PCI_VENDOR_ID_DYNALINK                                    0x0675
#define PCI_DEVICE_ID_DYNALINK_IS64PH                             0x1702

#define PCI_VENDOR_ID_UBIQUITI                                    0x0777

#define PCI_VENDOR_ID_BERKOM                                      0x0871
#define PCI_DEVICE_ID_BERKOM_A1T                                  0xffa1
#define PCI_DEVICE_ID_BERKOM_T_CONCEPT                            0xffa2
#define PCI_DEVICE_ID_BERKOM_A4T                                  0xffa4
#define PCI_DEVICE_ID_BERKOM_SCITEL_QUADRO                        0xffa8

#define PCI_VENDOR_ID_COMPAQ                                      0x0e11
#define PCI_DEVICE_ID_COMPAQ_TOKENRING                            0x0508
#define PCI_DEVICE_ID_COMPAQ_TACHYON                              0xa0fc
#define PCI_DEVICE_ID_COMPAQ_SMART2P                              0xae10
#define PCI_DEVICE_ID_COMPAQ_NETEL100                             0xae32
#define PCI_DEVICE_ID_COMPAQ_NETEL10                              0xae34
#define PCI_DEVICE_ID_COMPAQ_TRIFLEX_IDE                          0xae33
#define PCI_DEVICE_ID_COMPAQ_NETFLEX3I                            0xae35
#define PCI_DEVICE_ID_COMPAQ_NETEL100D                            0xae40
#define PCI_DEVICE_ID_COMPAQ_NETEL100PI                           0xae43
#define PCI_DEVICE_ID_COMPAQ_NETEL100I                            0xb011
#define PCI_DEVICE_ID_COMPAQ_CISS                                 0xb060
#define PCI_DEVICE_ID_COMPAQ_CISSB                                0xb178
#define PCI_DEVICE_ID_COMPAQ_CISSC                                0x46
#define PCI_DEVICE_ID_COMPAQ_THUNDER                              0xf130
#define PCI_DEVICE_ID_COMPAQ_NETFLEX3B                            0xf150

#define PCI_VENDOR_ID_NCR                                         0x1000
#define PCI_VENDOR_ID_LSI_LOGIC                                   0x1000
#define PCI_DEVICE_ID_NCR_53C810                                  0x0001
#define PCI_DEVICE_ID_NCR_53C820                                  0x0002
#define PCI_DEVICE_ID_NCR_53C825                                  0x0003
#define PCI_DEVICE_ID_NCR_53C815                                  0x0004
#define PCI_DEVICE_ID_LSI_53C810AP                                0x0005
#define PCI_DEVICE_ID_NCR_53C860                                  0x0006
#define PCI_DEVICE_ID_LSI_53C1510                                 0x000a
#define PCI_DEVICE_ID_NCR_53C896                                  0x000b
#define PCI_DEVICE_ID_NCR_53C895                                  0x000c
#define PCI_DEVICE_ID_NCR_53C885                                  0x000d
#define PCI_DEVICE_ID_NCR_53C875                                  0x000f
#define PCI_DEVICE_ID_NCR_53C1510                                 0x0010
#define PCI_DEVICE_ID_LSI_53C895A                                 0x0012
#define PCI_DEVICE_ID_LSI_53C875A                                 0x0013
#define PCI_DEVICE_ID_LSI_53C1010_33                              0x0020
#define PCI_DEVICE_ID_LSI_53C1010_66                              0x0021
#define PCI_DEVICE_ID_LSI_53C1030                                 0x0030
#define PCI_DEVICE_ID_LSI_1030_53C1035                            0x0032
#define PCI_DEVICE_ID_LSI_53C1035                                 0x0040
#define PCI_DEVICE_ID_NCR_53C875J                                 0x008f
#define PCI_DEVICE_ID_LSI_FC909                                   0x0621
#define PCI_DEVICE_ID_LSI_FC929                                   0x0622
#define PCI_DEVICE_ID_LSI_FC929_LAN                               0x0623
#define PCI_DEVICE_ID_LSI_FC919                                   0x0624
#define PCI_DEVICE_ID_LSI_FC919_LAN                               0x0625
#define PCI_DEVICE_ID_LSI_FC929X                                  0x0626
#define PCI_DEVICE_ID_LSI_FC939X                                  0x0642
#define PCI_DEVICE_ID_LSI_FC949X                                  0x0640
#define PCI_DEVICE_ID_LSI_FC949ES                                 0x0646
#define PCI_DEVICE_ID_LSI_FC919X                                  0x0628
#define PCI_DEVICE_ID_NCR_YELLOWFIN                               0x0701
#define PCI_DEVICE_ID_LSI_61C102                                  0x0901
#define PCI_DEVICE_ID_LSI_63C815                                  0x1000
#define PCI_DEVICE_ID_LSI_SAS1064                                 0x0050
#define PCI_DEVICE_ID_LSI_SAS1064R                                0x0411
#define PCI_DEVICE_ID_LSI_SAS1066                                 0x005e
#define PCI_DEVICE_ID_LSI_SAS1068                                 0x0054
#define PCI_DEVICE_ID_LSI_SAS1064A                                0x005c
#define PCI_DEVICE_ID_LSI_SAS1064E                                0x0056
#define PCI_DEVICE_ID_LSI_SAS1066E                                0x005a
#define PCI_DEVICE_ID_LSI_SAS1068E                                0x0058
#define PCI_DEVICE_ID_LSI_SAS1078                                 0x0060

#define PCI_VENDOR_ID_ATI                                         0x1002

/* Mach64 */

#define PCI_DEVICE_ID_ATI_68800                                   0x4158
#define PCI_DEVICE_ID_ATI_215CT222                                0x4354
#define PCI_DEVICE_ID_ATI_210888CX                                0x4358
#define PCI_DEVICE_ID_ATI_215ET222                                0x4554

/* Mach64 / Rage */

#define PCI_DEVICE_ID_ATI_215GB                                   0x4742
#define PCI_DEVICE_ID_ATI_215GD                                   0x4744
#define PCI_DEVICE_ID_ATI_215GI                                   0x4749
#define PCI_DEVICE_ID_ATI_215GP                                   0x4750
#define PCI_DEVICE_ID_ATI_215GQ                                   0x4751
#define PCI_DEVICE_ID_ATI_215XL                                   0x4752
#define PCI_DEVICE_ID_ATI_215GT                                   0x4754
#define PCI_DEVICE_ID_ATI_215GTB                                  0x4755
#define PCI_DEVICE_ID_ATI_215_IV                                  0x4756
#define PCI_DEVICE_ID_ATI_215_IW                                  0x4757
#define PCI_DEVICE_ID_ATI_215_IZ                                  0x475a
#define PCI_DEVICE_ID_ATI_210888GX                                0x4758
#define PCI_DEVICE_ID_ATI_215_LB                                  0x4c42
#define PCI_DEVICE_ID_ATI_215_LD                                  0x4c44
#define PCI_DEVICE_ID_ATI_215_LG                                  0x4c47
#define PCI_DEVICE_ID_ATI_215_LI                                  0x4c49
#define PCI_DEVICE_ID_ATI_215_LM                                  0x4c4d
#define PCI_DEVICE_ID_ATI_215_LN                                  0x4c4e
#define PCI_DEVICE_ID_ATI_215_LR                                  0x4c52
#define PCI_DEVICE_ID_ATI_215_LS                                  0x4c53
#define PCI_DEVICE_ID_ATI_264_LT                                  0x4c54

/* Mach64 VT */

#define PCI_DEVICE_ID_ATI_264VT                                   0x5654
#define PCI_DEVICE_ID_ATI_264VU                                   0x5655
#define PCI_DEVICE_ID_ATI_264VV                                   0x5656

/* Rage128 GL */

#define PCI_DEVICE_ID_ATI_RAGE128_RE                              0x5245
#define PCI_DEVICE_ID_ATI_RAGE128_RF                              0x5246
#define PCI_DEVICE_ID_ATI_RAGE128_RG                              0x5247

/* Rage128 VR */

#define PCI_DEVICE_ID_ATI_RAGE128_RK                              0x524b
#define PCI_DEVICE_ID_ATI_RAGE128_RL                              0x524c
#define PCI_DEVICE_ID_ATI_RAGE128_SE                              0x5345
#define PCI_DEVICE_ID_ATI_RAGE128_SF                              0x5346
#define PCI_DEVICE_ID_ATI_RAGE128_SG                              0x5347
#define PCI_DEVICE_ID_ATI_RAGE128_SH                              0x5348
#define PCI_DEVICE_ID_ATI_RAGE128_SK                              0x534b
#define PCI_DEVICE_ID_ATI_RAGE128_SL                              0x534c
#define PCI_DEVICE_ID_ATI_RAGE128_SM                              0x534d
#define PCI_DEVICE_ID_ATI_RAGE128_SN                              0x534e

/* Rage128 Ultra */

#define PCI_DEVICE_ID_ATI_RAGE128_TF                              0x5446
#define PCI_DEVICE_ID_ATI_RAGE128_TL                              0x544c
#define PCI_DEVICE_ID_ATI_RAGE128_TR                              0x5452
#define PCI_DEVICE_ID_ATI_RAGE128_TS                              0x5453
#define PCI_DEVICE_ID_ATI_RAGE128_TT                              0x5454
#define PCI_DEVICE_ID_ATI_RAGE128_TU                              0x5455

/* Rage128 M3 */

#define PCI_DEVICE_ID_ATI_RAGE128_LE                              0x4c45
#define PCI_DEVICE_ID_ATI_RAGE128_LF                              0x4c46

/* Rage128 M4 */

#define PCI_DEVICE_ID_ATI_RAGE128_MF                              0x4d46
#define PCI_DEVICE_ID_ATI_RAGE128_ML                              0x4d4c

/* Rage128 Pro GL */

#define PCI_DEVICE_ID_ATI_RAGE128_PA                              0x5041
#define PCI_DEVICE_ID_ATI_RAGE128_PB                              0x5042
#define PCI_DEVICE_ID_ATI_RAGE128_PC                              0x5043
#define PCI_DEVICE_ID_ATI_RAGE128_PD                              0x5044
#define PCI_DEVICE_ID_ATI_RAGE128_PE                              0x5045
#define PCI_DEVICE_ID_ATI_RAGE128_PF                              0x5046

/* Rage128 Pro VR */

#define PCI_DEVICE_ID_ATI_RAGE128_PG                              0x5047
#define PCI_DEVICE_ID_ATI_RAGE128_PH                              0x5048
#define PCI_DEVICE_ID_ATI_RAGE128_PI                              0x5049
#define PCI_DEVICE_ID_ATI_RAGE128_PJ                              0x504a
#define PCI_DEVICE_ID_ATI_RAGE128_PK                              0x504b
#define PCI_DEVICE_ID_ATI_RAGE128_PL                              0x504c
#define PCI_DEVICE_ID_ATI_RAGE128_PM                              0x504d
#define PCI_DEVICE_ID_ATI_RAGE128_PN                              0x504e
#define PCI_DEVICE_ID_ATI_RAGE128_PO                              0x504f
#define PCI_DEVICE_ID_ATI_RAGE128_PP                              0x5050
#define PCI_DEVICE_ID_ATI_RAGE128_PQ                              0x5051
#define PCI_DEVICE_ID_ATI_RAGE128_PR                              0x5052
#define PCI_DEVICE_ID_ATI_RAGE128_PS                              0x5053
#define PCI_DEVICE_ID_ATI_RAGE128_PT                              0x5054
#define PCI_DEVICE_ID_ATI_RAGE128_PU                              0x5055
#define PCI_DEVICE_ID_ATI_RAGE128_PV                              0x5056
#define PCI_DEVICE_ID_ATI_RAGE128_PW                              0x5057
#define PCI_DEVICE_ID_ATI_RAGE128_PX                              0x5058

/* Rage128 M4 */

/* Radeon R100 */

#define PCI_DEVICE_ID_ATI_RADEON_QD                               0x5144
#define PCI_DEVICE_ID_ATI_RADEON_QE                               0x5145
#define PCI_DEVICE_ID_ATI_RADEON_QF                               0x5146
#define PCI_DEVICE_ID_ATI_RADEON_QG                               0x5147

/* Radeon RV100 (VE) */

#define PCI_DEVICE_ID_ATI_RADEON_QY                               0x5159
#define PCI_DEVICE_ID_ATI_RADEON_QZ                               0x515a

/* Radeon R200 (8500) */

#define PCI_DEVICE_ID_ATI_RADEON_QL                               0x514c
#define PCI_DEVICE_ID_ATI_RADEON_QN                               0x514e
#define PCI_DEVICE_ID_ATI_RADEON_QO                               0x514f
#define PCI_DEVICE_ID_ATI_RADEON_Ql                               0x516c
#define PCI_DEVICE_ID_ATI_RADEON_BB                               0x4242

/* Radeon R200 (9100) */

#define PCI_DEVICE_ID_ATI_RADEON_QM                               0x514d

/* Radeon RV200 (7500) */

#define PCI_DEVICE_ID_ATI_RADEON_QW                               0x5157
#define PCI_DEVICE_ID_ATI_RADEON_QX                               0x5158

/* Radeon NV-100 */

/* Radeon RV250 (9000) */

#define PCI_DEVICE_ID_ATI_RADEON_Id                               0x4964
#define PCI_DEVICE_ID_ATI_RADEON_Ie                               0x4965
#define PCI_DEVICE_ID_ATI_RADEON_If                               0x4966
#define PCI_DEVICE_ID_ATI_RADEON_Ig                               0x4967

/* Radeon RV280 (9200) */

#define PCI_DEVICE_ID_ATI_RADEON_Ya                               0x5961
#define PCI_DEVICE_ID_ATI_RADEON_Yd                               0x5964

/* Radeon R300 (9500) */

/* Radeon R300 (9700) */

#define PCI_DEVICE_ID_ATI_RADEON_ND                               0x4e44
#define PCI_DEVICE_ID_ATI_RADEON_NE                               0x4e45
#define PCI_DEVICE_ID_ATI_RADEON_NF                               0x4e46
#define PCI_DEVICE_ID_ATI_RADEON_NG                               0x4e47

/* Radeon R350 (9800) */

/* Radeon RV350 (9600) */

/* Radeon M6 */

#define PCI_DEVICE_ID_ATI_RADEON_LY                               0x4c59
#define PCI_DEVICE_ID_ATI_RADEON_LZ                               0x4c5a

/* Radeon M7 */

#define PCI_DEVICE_ID_ATI_RADEON_LW                               0x4c57
#define PCI_DEVICE_ID_ATI_RADEON_LX                               0x4c58

/* Radeon M9 */

#define PCI_DEVICE_ID_ATI_RADEON_Ld                               0x4c64
#define PCI_DEVICE_ID_ATI_RADEON_Le                               0x4c65
#define PCI_DEVICE_ID_ATI_RADEON_Lf                               0x4c66
#define PCI_DEVICE_ID_ATI_RADEON_Lg                               0x4c67

/* Radeon */

/* RadeonIGP */

#define PCI_DEVICE_ID_ATI_RS100                                   0xcab0
#define PCI_DEVICE_ID_ATI_RS200                                   0xcab2
#define PCI_DEVICE_ID_ATI_RS200_B                                 0xcbb2
#define PCI_DEVICE_ID_ATI_RS250                                   0xcab3
#define PCI_DEVICE_ID_ATI_RS300_100                               0x5830
#define PCI_DEVICE_ID_ATI_RS300_133                               0x5831
#define PCI_DEVICE_ID_ATI_RS300_166                               0x5832
#define PCI_DEVICE_ID_ATI_RS300_200                               0x5833
#define PCI_DEVICE_ID_ATI_RS350_100                               0x7830
#define PCI_DEVICE_ID_ATI_RS350_133                               0x7831
#define PCI_DEVICE_ID_ATI_RS350_166                               0x7832
#define PCI_DEVICE_ID_ATI_RS350_200                               0x7833
#define PCI_DEVICE_ID_ATI_RS400_100                               0x5a30
#define PCI_DEVICE_ID_ATI_RS400_133                               0x5a31
#define PCI_DEVICE_ID_ATI_RS400_166                               0x5a32
#define PCI_DEVICE_ID_ATI_RS400_200                               0x5a33
#define PCI_DEVICE_ID_ATI_RS480                                   0x5950

/* ATI IXP Chipset */

#define PCI_DEVICE_ID_ATI_IXP200_IDE                              0x4349
#define PCI_DEVICE_ID_ATI_IXP200_SMBUS                            0x4353
#define PCI_DEVICE_ID_ATI_IXP300_SMBUS                            0x4363
#define PCI_DEVICE_ID_ATI_IXP300_IDE                              0x4369
#define PCI_DEVICE_ID_ATI_IXP300_SATA                             0x436e
#define PCI_DEVICE_ID_ATI_IXP400_SMBUS                            0x4372
#define PCI_DEVICE_ID_ATI_IXP400_IDE                              0x4376
#define PCI_DEVICE_ID_ATI_IXP400_SATA                             0x4379
#define PCI_DEVICE_ID_ATI_IXP400_SATA2                            0x437a
#define PCI_DEVICE_ID_ATI_IXP600_SATA                             0x4380
#define PCI_DEVICE_ID_ATI_SBX00_SMBUS                             0x4385
#define PCI_DEVICE_ID_ATI_IXP600_IDE                              0x438c
#define PCI_DEVICE_ID_ATI_IXP700_SATA                             0x4390
#define PCI_DEVICE_ID_ATI_IXP700_IDE                              0x439c

#define PCI_VENDOR_ID_VLSI                                        0x1004
#define PCI_DEVICE_ID_VLSI_82C592                                 0x0005
#define PCI_DEVICE_ID_VLSI_82C593                                 0x0006
#define PCI_DEVICE_ID_VLSI_82C594                                 0x0007
#define PCI_DEVICE_ID_VLSI_82C597                                 0x0009
#define PCI_DEVICE_ID_VLSI_82C541                                 0x000c
#define PCI_DEVICE_ID_VLSI_82C543                                 0x000d
#define PCI_DEVICE_ID_VLSI_82C532                                 0x0101
#define PCI_DEVICE_ID_VLSI_82C534                                 0x0102
#define PCI_DEVICE_ID_VLSI_82C535                                 0x0104
#define PCI_DEVICE_ID_VLSI_82C147                                 0x0105
#define PCI_DEVICE_ID_VLSI_VAS96011                               0x0702

/* AMD RD890 Chipset */

#define PCI_DEVICE_ID_RD890_IOMMU                                 0x5a23

#define PCI_VENDOR_ID_ADL                                         0x1005
#define PCI_DEVICE_ID_ADL_2301                                    0x2301

#define PCI_VENDOR_ID_NS                                          0x100b
#define PCI_DEVICE_ID_NS_87415                                    0x0002
#define PCI_DEVICE_ID_NS_87560_LIO                                0x000e
#define PCI_DEVICE_ID_NS_87560_USB                                0x0012
#define PCI_DEVICE_ID_NS_83815                                    0x0020
#define PCI_DEVICE_ID_NS_83820                                    0x0022
#define PCI_DEVICE_ID_NS_CS5535_ISA                               0x002b
#define PCI_DEVICE_ID_NS_CS5535_IDE                               0x002d
#define PCI_DEVICE_ID_NS_CS5535_AUDIO                             0x002e
#define PCI_DEVICE_ID_NS_CS5535_USB                               0x002f
#define PCI_DEVICE_ID_NS_GX_VIDEO                                 0x0030
#define PCI_DEVICE_ID_NS_SATURN                                   0x0035
#define PCI_DEVICE_ID_NS_SCx200_BRIDGE                            0x0500
#define PCI_DEVICE_ID_NS_SCx200_SMI                               0x0501
#define PCI_DEVICE_ID_NS_SCx200_IDE                               0x0502
#define PCI_DEVICE_ID_NS_SCx200_AUDIO                             0x0503
#define PCI_DEVICE_ID_NS_SCx200_VIDEO                             0x0504
#define PCI_DEVICE_ID_NS_SCx200_XBUS                              0x0505
#define PCI_DEVICE_ID_NS_SC1100_BRIDGE                            0x0510
#define PCI_DEVICE_ID_NS_SC1100_SMI                               0x0511
#define PCI_DEVICE_ID_NS_SC1100_XBUS                              0x0515
#define PCI_DEVICE_ID_NS_87410                                    0xd001

#define PCI_DEVICE_ID_NS_GX_HOST_BRIDGE                           0x0028

#define PCI_VENDOR_ID_TSENG                                       0x100c
#define PCI_DEVICE_ID_TSENG_W32P_2                                0x3202
#define PCI_DEVICE_ID_TSENG_W32P_b                                0x3205
#define PCI_DEVICE_ID_TSENG_W32P_c                                0x3206
#define PCI_DEVICE_ID_TSENG_W32P_d                                0x3207
#define PCI_DEVICE_ID_TSENG_ET6000                                0x3208

#define PCI_VENDOR_ID_WEITEK                                      0x100e
#define PCI_DEVICE_ID_WEITEK_P9000                                0x9001
#define PCI_DEVICE_ID_WEITEK_P9100                                0x9100

#define PCI_VENDOR_ID_DEC                                         0x1011
#define PCI_DEVICE_ID_DEC_BRD                                     0x0001
#define PCI_DEVICE_ID_DEC_TULIP                                   0x0002
#define PCI_DEVICE_ID_DEC_TGA                                     0x0004
#define PCI_DEVICE_ID_DEC_TULIP_FAST                              0x0009
#define PCI_DEVICE_ID_DEC_TGA2                                    0x000d
#define PCI_DEVICE_ID_DEC_FDDI                                    0x000f
#define PCI_DEVICE_ID_DEC_TULIP_PLUS                              0x0014
#define PCI_DEVICE_ID_DEC_21142                                   0x0019
#define PCI_DEVICE_ID_DEC_21052                                   0x0021
#define PCI_DEVICE_ID_DEC_21150                                   0x0022
#define PCI_DEVICE_ID_DEC_21152                                   0x0024
#define PCI_DEVICE_ID_DEC_21153                                   0x0025
#define PCI_DEVICE_ID_DEC_21154                                   0x0026
#define PCI_DEVICE_ID_DEC_21285                                   0x1065
#define PCI_DEVICE_ID_COMPAQ_42XX                                 0x0046

#define PCI_VENDOR_ID_CIRRUS                                      0x1013
#define PCI_DEVICE_ID_CIRRUS_7548                                 0x0038
#define PCI_DEVICE_ID_CIRRUS_5430                                 0x00a0
#define PCI_DEVICE_ID_CIRRUS_5434_4                               0x00a4
#define PCI_DEVICE_ID_CIRRUS_5434_8                               0x00a8
#define PCI_DEVICE_ID_CIRRUS_5436                                 0x00ac
#define PCI_DEVICE_ID_CIRRUS_5446                                 0x00b8
#define PCI_DEVICE_ID_CIRRUS_5480                                 0x00bc
#define PCI_DEVICE_ID_CIRRUS_5462                                 0x00d0
#define PCI_DEVICE_ID_CIRRUS_5464                                 0x00d4
#define PCI_DEVICE_ID_CIRRUS_5465                                 0x00d6
#define PCI_DEVICE_ID_CIRRUS_6729                                 0x1100
#define PCI_DEVICE_ID_CIRRUS_6832                                 0x1110
#define PCI_DEVICE_ID_CIRRUS_7543                                 0x1202
#define PCI_DEVICE_ID_CIRRUS_4610                                 0x6001
#define PCI_DEVICE_ID_CIRRUS_4612                                 0x6003
#define PCI_DEVICE_ID_CIRRUS_4615                                 0x6004

#define PCI_VENDOR_ID_IBM                                         0x1014
#define PCI_DEVICE_ID_IBM_TR                                      0x0018
#define PCI_DEVICE_ID_IBM_TR_WAKE                                 0x003e
#define PCI_DEVICE_ID_IBM_CPC710_PCI64                            0x00fc
#define PCI_DEVICE_ID_IBM_SNIPE                                   0x0180
#define PCI_DEVICE_ID_IBM_CITRINE                                 0x028c
#define PCI_DEVICE_ID_IBM_GEMSTONE                                0xb166
#define PCI_DEVICE_ID_IBM_OBSIDIAN                                0x02bd
#define PCI_DEVICE_ID_IBM_ICOM_DEV_ID_1                           0x0031
#define PCI_DEVICE_ID_IBM_ICOM_DEV_ID_2                           0x0219
#define PCI_DEVICE_ID_IBM_ICOM_V2_TWO_PORTS_RVX                   0x021a
#define PCI_DEVICE_ID_IBM_ICOM_V2_ONE_PORT_RVX_ONE_PORT_MDM       0x0251
#define PCI_DEVICE_ID_IBM_ICOM_V2_ONE_PORT_RVX_ONE_PORT_MDM_PCIE  0x0361
#define PCI_DEVICE_ID_IBM_ICOM_FOUR_PORT_MODEL                    0x252

#define PCI_SUBVENDOR_ID_IBM                                      0x1014
#define PCI_SUBDEVICE_ID_IBM_SATURN_SERIAL_ONE_PORT               0x03d4

#define PCI_VENDOR_ID_UNISYS                                      0x1018
#define PCI_DEVICE_ID_UNISYS_DMA_DIRECTOR                         0x001c

#define PCI_VENDOR_ID_COMPEX2                                     0x101a /* pci.ids says "AT&T GIS (NCR)" */
#define PCI_DEVICE_ID_COMPEX2_100VG                               0x0005

#define PCI_VENDOR_ID_WD                                          0x101c
#define PCI_DEVICE_ID_WD_90C                                      0xc24a

#define PCI_VENDOR_ID_AMI                                         0x101e
#define PCI_DEVICE_ID_AMI_MEGARAID3                               0x1960
#define PCI_DEVICE_ID_AMI_MEGARAID                                0x9010
#define PCI_DEVICE_ID_AMI_MEGARAID2                               0x9060

#define PCI_VENDOR_ID_AMD                                         0x1022
#define PCI_DEVICE_ID_AMD_K8_NB                                   0x1100
#define PCI_DEVICE_ID_AMD_K8_NB_ADDRMAP                           0x1101
#define PCI_DEVICE_ID_AMD_K8_NB_MEMCTL                            0x1102
#define PCI_DEVICE_ID_AMD_K8_NB_MISC                              0x1103
#define PCI_DEVICE_ID_AMD_10H_NB_HT                               0x1200
#define PCI_DEVICE_ID_AMD_10H_NB_MAP                              0x1201
#define PCI_DEVICE_ID_AMD_10H_NB_DRAM                             0x1202
#define PCI_DEVICE_ID_AMD_10H_NB_MISC                             0x1203
#define PCI_DEVICE_ID_AMD_10H_NB_LINK                             0x1204
#define PCI_DEVICE_ID_AMD_11H_NB_HT                               0x1300
#define PCI_DEVICE_ID_AMD_11H_NB_MAP                              0x1301
#define PCI_DEVICE_ID_AMD_11H_NB_DRAM                             0x1302
#define PCI_DEVICE_ID_AMD_11H_NB_MISC                             0x1303
#define PCI_DEVICE_ID_AMD_11H_NB_LINK                             0x1304
#define PCI_DEVICE_ID_AMD_15H_M10H_F3                             0x1403
#define PCI_DEVICE_ID_AMD_15H_M30H_NB_F3                          0x141d
#define PCI_DEVICE_ID_AMD_15H_M30H_NB_F4                          0x141e
#define PCI_DEVICE_ID_AMD_15H_M60H_NB_F3                          0x1573
#define PCI_DEVICE_ID_AMD_15H_M60H_NB_F4                          0x1574
#define PCI_DEVICE_ID_AMD_15H_NB_F0                               0x1600
#define PCI_DEVICE_ID_AMD_15H_NB_F1                               0x1601
#define PCI_DEVICE_ID_AMD_15H_NB_F2                               0x1602
#define PCI_DEVICE_ID_AMD_15H_NB_F3                               0x1603
#define PCI_DEVICE_ID_AMD_15H_NB_F4                               0x1604
#define PCI_DEVICE_ID_AMD_15H_NB_F5                               0x1605
#define PCI_DEVICE_ID_AMD_16H_NB_F3                               0x1533
#define PCI_DEVICE_ID_AMD_16H_NB_F4                               0x1534
#define PCI_DEVICE_ID_AMD_16H_M30H_NB_F3                          0x1583
#define PCI_DEVICE_ID_AMD_16H_M30H_NB_F4                          0x1584
#define PCI_DEVICE_ID_AMD_CNB17H_F3                               0x1703
#define PCI_DEVICE_ID_AMD_LANCE                                   0x2000
#define PCI_DEVICE_ID_AMD_LANCE_HOME                              0x2001
#define PCI_DEVICE_ID_AMD_SCSI                                    0x2020
#define PCI_DEVICE_ID_AMD_SERENADE                                0x36c0
#define PCI_DEVICE_ID_AMD_FE_GATE_7006                            0x7006
#define PCI_DEVICE_ID_AMD_FE_GATE_7007                            0x7007
#define PCI_DEVICE_ID_AMD_FE_GATE_700C                            0x700c
#define PCI_DEVICE_ID_AMD_FE_GATE_700E                            0x700e
#define PCI_DEVICE_ID_AMD_COBRA_7401                              0x7401
#define PCI_DEVICE_ID_AMD_VIPER_7409                              0x7409
#define PCI_DEVICE_ID_AMD_VIPER_740B                              0x740b
#define PCI_DEVICE_ID_AMD_VIPER_7410                              0x7410
#define PCI_DEVICE_ID_AMD_VIPER_7411                              0x7411
#define PCI_DEVICE_ID_AMD_VIPER_7413                              0x7413
#define PCI_DEVICE_ID_AMD_VIPER_7440                              0x7440
#define PCI_DEVICE_ID_AMD_OPUS_7441                               0x7441
#define PCI_DEVICE_ID_AMD_OPUS_7443                               0x7443
#define PCI_DEVICE_ID_AMD_VIPER_7443                              0x7443
#define PCI_DEVICE_ID_AMD_OPUS_7445                               0x7445
#define PCI_DEVICE_ID_AMD_GOLAM_7450                              0x7450
#define PCI_DEVICE_ID_AMD_8111_PCI                                0x7460
#define PCI_DEVICE_ID_AMD_8111_LPC                                0x7468
#define PCI_DEVICE_ID_AMD_8111_IDE                                0x7469
#define PCI_DEVICE_ID_AMD_8111_SMBUS2                             0x746a
#define PCI_DEVICE_ID_AMD_8111_SMBUS                              0x746b
#define PCI_DEVICE_ID_AMD_8111_AUDIO                              0x746d
#define PCI_DEVICE_ID_AMD_8151_0                                  0x7454
#define PCI_DEVICE_ID_AMD_8131_BRIDGE                             0x7450
#define PCI_DEVICE_ID_AMD_8131_APIC                               0x7451
#define PCI_DEVICE_ID_AMD_8132_BRIDGE                             0x7458
#define PCI_DEVICE_ID_AMD_NL_USB                                  0x7912
#define PCI_DEVICE_ID_AMD_CS5535_IDE                              0x208f
#define PCI_DEVICE_ID_AMD_CS5536_ISA                              0x2090
#define PCI_DEVICE_ID_AMD_CS5536_FLASH                            0x2091
#define PCI_DEVICE_ID_AMD_CS5536_AUDIO                            0x2093
#define PCI_DEVICE_ID_AMD_CS5536_OHC                              0x2094
#define PCI_DEVICE_ID_AMD_CS5536_EHC                              0x2095
#define PCI_DEVICE_ID_AMD_CS5536_UDC                              0x2096
#define PCI_DEVICE_ID_AMD_CS5536_UOC                              0x2097
#define PCI_DEVICE_ID_AMD_CS5536_DEV_IDE                          0x2092
#define PCI_DEVICE_ID_AMD_CS5536_IDE                              0x209a
#define PCI_DEVICE_ID_AMD_LX_VIDEO                                0x2081
#define PCI_DEVICE_ID_AMD_LX_AES                                  0x2082
#define PCI_DEVICE_ID_AMD_HUDSON2_SATA_IDE                        0x7800
#define PCI_DEVICE_ID_AMD_HUDSON2_SMBUS                           0x780b
#define PCI_DEVICE_ID_AMD_HUDSON2_IDE                             0x780c
#define PCI_DEVICE_ID_AMD_KERNCZ_SMBUS                            0x790b

#define PCI_VENDOR_ID_TRIDENT                                     0x1023
#define PCI_DEVICE_ID_TRIDENT_4DWAVE_DX                           0x2000
#define PCI_DEVICE_ID_TRIDENT_4DWAVE_NX                           0x2001
#define PCI_DEVICE_ID_TRIDENT_9320                                0x9320
#define PCI_DEVICE_ID_TRIDENT_9388                                0x9388
#define PCI_DEVICE_ID_TRIDENT_9397                                0x9397
#define PCI_DEVICE_ID_TRIDENT_939A                                0x939a
#define PCI_DEVICE_ID_TRIDENT_9520                                0x9520
#define PCI_DEVICE_ID_TRIDENT_9525                                0x9525
#define PCI_DEVICE_ID_TRIDENT_9420                                0x9420
#define PCI_DEVICE_ID_TRIDENT_9440                                0x9440
#define PCI_DEVICE_ID_TRIDENT_9660                                0x9660
#define PCI_DEVICE_ID_TRIDENT_9750                                0x9750
#define PCI_DEVICE_ID_TRIDENT_9850                                0x9850
#define PCI_DEVICE_ID_TRIDENT_9880                                0x9880
#define PCI_DEVICE_ID_TRIDENT_8400                                0x8400
#define PCI_DEVICE_ID_TRIDENT_8420                                0x8420
#define PCI_DEVICE_ID_TRIDENT_8500                                0x8500

#define PCI_VENDOR_ID_AI                                          0x1025
#define PCI_DEVICE_ID_AI_M1435                                    0x1435

#define PCI_VENDOR_ID_DELL                                        0x1028
#define PCI_DEVICE_ID_DELL_RACIII                                 0x0008
#define PCI_DEVICE_ID_DELL_RAC4                                   0x0012
#define PCI_DEVICE_ID_DELL_PERC5                                  0x0015

#define PCI_VENDOR_ID_MATROX                                      0x102b
#define PCI_DEVICE_ID_MATROX_MGA_2                                0x0518
#define PCI_DEVICE_ID_MATROX_MIL                                  0x0519
#define PCI_DEVICE_ID_MATROX_MYS                                  0x051a
#define PCI_DEVICE_ID_MATROX_MIL_2                                0x051b
#define PCI_DEVICE_ID_MATROX_MYS_AGP                              0x051e
#define PCI_DEVICE_ID_MATROX_MIL_2_AGP                            0x051f
#define PCI_DEVICE_ID_MATROX_MGA_IMP                              0x0d10
#define PCI_DEVICE_ID_MATROX_G100_MM                              0x1000
#define PCI_DEVICE_ID_MATROX_G100_AGP                             0x1001
#define PCI_DEVICE_ID_MATROX_G200_PCI                             0x0520
#define PCI_DEVICE_ID_MATROX_G200_AGP                             0x0521
#define PCI_DEVICE_ID_MATROX_G400                                 0x0525
#define PCI_DEVICE_ID_MATROX_G200EV_PCI                           0x0530
#define PCI_DEVICE_ID_MATROX_G550                                 0x2527
#define PCI_DEVICE_ID_MATROX_VIA                                  0x4536

#define PCI_VENDOR_ID_MOBILITY_ELECTRONICS                        0x14f2

#define PCI_VENDOR_ID_CT                                          0x102c
#define PCI_DEVICE_ID_CT_69000                                    0x00c0
#define PCI_DEVICE_ID_CT_65545                                    0x00d8
#define PCI_DEVICE_ID_CT_65548                                    0x00dc
#define PCI_DEVICE_ID_CT_65550                                    0x00e0
#define PCI_DEVICE_ID_CT_65554                                    0x00e4
#define PCI_DEVICE_ID_CT_65555                                    0x00e5

#define PCI_VENDOR_ID_MIRO                                        0x1031
#define PCI_DEVICE_ID_MIRO_36050                                  0x5601
#define PCI_DEVICE_ID_MIRO_DC10PLUS                               0x7efe
#define PCI_DEVICE_ID_MIRO_DC30PLUS                               0xd801

#define PCI_VENDOR_ID_NEC                                         0x1033
#define PCI_DEVICE_ID_NEC_CBUS_1                                  0x0001 /* PCI-Cbus Bridge */
#define PCI_DEVICE_ID_NEC_LOCAL                                   0x0002 /* Local Bridge */
#define PCI_DEVICE_ID_NEC_ATM                                     0x0003 /* ATM LAN Controller */
#define PCI_DEVICE_ID_NEC_R4000                                   0x0004 /* R4000 Bridge */
#define PCI_DEVICE_ID_NEC_486                                     0x0005 /* 486 Like Peripheral Bus Bridge */
#define PCI_DEVICE_ID_NEC_ACCEL_1                                 0x0006 /* Graphic Accelerator */
#define PCI_DEVICE_ID_NEC_UXBUS                                   0x0007 /* UX-Bus Bridge */
#define PCI_DEVICE_ID_NEC_ACCEL_2                                 0x0008 /* Graphic Accelerator */
#define PCI_DEVICE_ID_NEC_GRAPH                                   0x0009 /* PCI-CoreGraph Bridge */
#define PCI_DEVICE_ID_NEC_VL                                      0x0016 /* PCI-VL Bridge */
#define PCI_DEVICE_ID_NEC_STARALPHA2                              0x002c /* STAR ALPHA2 */
#define PCI_DEVICE_ID_NEC_CBUS_2                                  0x002d /* PCI-Cbus Bridge */
#define PCI_DEVICE_ID_NEC_USB                                     0x0035 /* PCI-USB Host */
#define PCI_DEVICE_ID_NEC_CBUS_3                                  0x003b
#define PCI_DEVICE_ID_NEC_NAPCCARD                                0x003e
#define PCI_DEVICE_ID_NEC_PCX2                                    0x0046 /* PowerVR */
#define PCI_DEVICE_ID_NEC_VRC5476                                 0x009b
#define PCI_DEVICE_ID_NEC_VRC4173                                 0x00a5
#define PCI_DEVICE_ID_NEC_VRC5477_AC97                            0x00a6
#define PCI_DEVICE_ID_NEC_PC9821CS01                              0x800c /* PC-9821-CS01 */
#define PCI_DEVICE_ID_NEC_PC9821NRB06                             0x800d /* PC-9821NR-B06 */

#define PCI_VENDOR_ID_FD                                          0x1036
#define PCI_DEVICE_ID_FD_36C70                                    0x0000

#define PCI_VENDOR_ID_SI                                          0x1039
#define PCI_DEVICE_ID_SI_5591_AGP                                 0x0001
#define PCI_DEVICE_ID_SI_6202                                     0x0002
#define PCI_DEVICE_ID_SI_503                                      0x0008
#define PCI_DEVICE_ID_SI_ACPI                                     0x0009
#define PCI_DEVICE_ID_SI_SMBUS                                    0x0016
#define PCI_DEVICE_ID_SI_LPC                                      0x0018
#define PCI_DEVICE_ID_SI_5597_VGA                                 0x0200
#define PCI_DEVICE_ID_SI_6205                                     0x0205
#define PCI_DEVICE_ID_SI_501                                      0x0406
#define PCI_DEVICE_ID_SI_496                                      0x0496
#define PCI_DEVICE_ID_SI_300                                      0x0300
#define PCI_DEVICE_ID_SI_315H                                     0x0310
#define PCI_DEVICE_ID_SI_315                                      0x0315
#define PCI_DEVICE_ID_SI_315PRO                                   0x0325
#define PCI_DEVICE_ID_SI_530                                      0x0530
#define PCI_DEVICE_ID_SI_540                                      0x0540
#define PCI_DEVICE_ID_SI_550                                      0x0550
#define PCI_DEVICE_ID_SI_540_VGA                                  0x5300
#define PCI_DEVICE_ID_SI_550_VGA                                  0x5315
#define PCI_DEVICE_ID_SI_620                                      0x0620
#define PCI_DEVICE_ID_SI_630                                      0x0630
#define PCI_DEVICE_ID_SI_633                                      0x0633
#define PCI_DEVICE_ID_SI_635                                      0x0635
#define PCI_DEVICE_ID_SI_640                                      0x0640
#define PCI_DEVICE_ID_SI_645                                      0x0645
#define PCI_DEVICE_ID_SI_646                                      0x0646
#define PCI_DEVICE_ID_SI_648                                      0x0648
#define PCI_DEVICE_ID_SI_650                                      0x0650
#define PCI_DEVICE_ID_SI_651                                      0x0651
#define PCI_DEVICE_ID_SI_655                                      0x0655
#define PCI_DEVICE_ID_SI_661                                      0x0661
#define PCI_DEVICE_ID_SI_730                                      0x0730
#define PCI_DEVICE_ID_SI_733                                      0x0733
#define PCI_DEVICE_ID_SI_630_VGA                                  0x6300
#define PCI_DEVICE_ID_SI_735                                      0x0735
#define PCI_DEVICE_ID_SI_740                                      0x0740
#define PCI_DEVICE_ID_SI_741                                      0x0741
#define PCI_DEVICE_ID_SI_745                                      0x0745
#define PCI_DEVICE_ID_SI_746                                      0x0746
#define PCI_DEVICE_ID_SI_755                                      0x0755
#define PCI_DEVICE_ID_SI_760                                      0x0760
#define PCI_DEVICE_ID_SI_900                                      0x0900
#define PCI_DEVICE_ID_SI_961                                      0x0961
#define PCI_DEVICE_ID_SI_962                                      0x0962
#define PCI_DEVICE_ID_SI_963                                      0x0963
#define PCI_DEVICE_ID_SI_965                                      0x0965
#define PCI_DEVICE_ID_SI_966                                      0x0966
#define PCI_DEVICE_ID_SI_968                                      0x0968
#define PCI_DEVICE_ID_SI_1180                                     0x1180
#define PCI_DEVICE_ID_SI_5511                                     0x5511
#define PCI_DEVICE_ID_SI_5513                                     0x5513
#define PCI_DEVICE_ID_SI_5517                                     0x5517
#define PCI_DEVICE_ID_SI_5518                                     0x5518
#define PCI_DEVICE_ID_SI_5571                                     0x5571
#define PCI_DEVICE_ID_SI_5581                                     0x5581
#define PCI_DEVICE_ID_SI_5582                                     0x5582
#define PCI_DEVICE_ID_SI_5591                                     0x5591
#define PCI_DEVICE_ID_SI_5596                                     0x5596
#define PCI_DEVICE_ID_SI_5597                                     0x5597
#define PCI_DEVICE_ID_SI_5598                                     0x5598
#define PCI_DEVICE_ID_SI_5600                                     0x5600
#define PCI_DEVICE_ID_SI_7012                                     0x7012
#define PCI_DEVICE_ID_SI_7013                                     0x7013
#define PCI_DEVICE_ID_SI_7016                                     0x7016
#define PCI_DEVICE_ID_SI_7018                                     0x7018

#define PCI_VENDOR_ID_HP                                          0x103c
#define PCI_VENDOR_ID_HP_3PAR                                     0x1590
#define PCI_DEVICE_ID_HP_VISUALIZE_EG                             0x1005
#define PCI_DEVICE_ID_HP_VISUALIZE_FX6                            0x1006
#define PCI_DEVICE_ID_HP_VISUALIZE_FX4                            0x1008
#define PCI_DEVICE_ID_HP_VISUALIZE_FX2                            0x100a
#define PCI_DEVICE_ID_HP_TACHYON                                  0x1028
#define PCI_DEVICE_ID_HP_TACHLITE                                 0x1029
#define PCI_DEVICE_ID_HP_J2585A                                   0x1030
#define PCI_DEVICE_ID_HP_J2585B                                   0x1031
#define PCI_DEVICE_ID_HP_J2973A                                   0x1040
#define PCI_DEVICE_ID_HP_J2970A                                   0x1042
#define PCI_DEVICE_ID_HP_DIVA                                     0x1048
#define PCI_DEVICE_ID_HP_DIVA_TOSCA1                              0x1049
#define PCI_DEVICE_ID_HP_DIVA_TOSCA2                              0x104a
#define PCI_DEVICE_ID_HP_DIVA_MAESTRO                             0x104b
#define PCI_DEVICE_ID_HP_REO_IOC                                  0x10f1
#define PCI_DEVICE_ID_HP_VISUALIZE_FXE                            0x108b
#define PCI_DEVICE_ID_HP_DIVA_HALFDOME                            0x1223
#define PCI_DEVICE_ID_HP_DIVA_KEYSTONE                            0x1226
#define PCI_DEVICE_ID_HP_DIVA_POWERBAR                            0x1227
#define PCI_DEVICE_ID_HP_ZX1_IOC                                  0x122a
#define PCI_DEVICE_ID_HP_PCIX_LBA                                 0x122e
#define PCI_DEVICE_ID_HP_SX1000_IOC                               0x127c
#define PCI_DEVICE_ID_HP_DIVA_EVEREST                             0x1282
#define PCI_DEVICE_ID_HP_DIVA_AUX                                 0x1290
#define PCI_DEVICE_ID_HP_DIVA_RMP3                                0x1301
#define PCI_DEVICE_ID_HP_DIVA_HURRICANE                           0x132a
#define PCI_DEVICE_ID_HP_CISSA                                    0x3220
#define PCI_DEVICE_ID_HP_CISSC                                    0x3230
#define PCI_DEVICE_ID_HP_CISSD                                    0x3238
#define PCI_DEVICE_ID_HP_CISSE                                    0x323a
#define PCI_DEVICE_ID_HP_CISSF                                    0x323b
#define PCI_DEVICE_ID_HP_CISSH                                    0x323c
#define PCI_DEVICE_ID_HP_CISSI                                    0x3239
#define PCI_DEVICE_ID_HP_ZX2_IOC                                  0x4031

#define PCI_VENDOR_ID_PCTECH                                      0x1042
#define PCI_DEVICE_ID_PCTECH_RZ1000                               0x1000
#define PCI_DEVICE_ID_PCTECH_RZ1001                               0x1001
#define PCI_DEVICE_ID_PCTECH_SAMURAI_IDE                          0x3020

#define PCI_VENDOR_ID_ASUSTEK                                     0x1043
#define PCI_DEVICE_ID_ASUSTEK_0675                                0x0675

#define PCI_VENDOR_ID_DPT                                         0x1044
#define PCI_DEVICE_ID_DPT                                         0xa400

#define PCI_VENDOR_ID_OPTI                                        0x1045
#define PCI_DEVICE_ID_OPTI_82C558                                 0xc558
#define PCI_DEVICE_ID_OPTI_82C621                                 0xc621
#define PCI_DEVICE_ID_OPTI_82C700                                 0xc700
#define PCI_DEVICE_ID_OPTI_82C825                                 0xd568

#define PCI_VENDOR_ID_ELSA                                        0x1048
#define PCI_DEVICE_ID_ELSA_MICROLINK                              0x1000
#define PCI_DEVICE_ID_ELSA_QS3000                                 0x3000

#define PCI_VENDOR_ID_STMICRO                                     0x104a
#define PCI_DEVICE_ID_STMICRO_USB_HOST                            0xcc00
#define PCI_DEVICE_ID_STMICRO_USB_OHCI                            0xcc01
#define PCI_DEVICE_ID_STMICRO_USB_OTG                             0xcc02
#define PCI_DEVICE_ID_STMICRO_UART_HWFC                           0xcc03
#define PCI_DEVICE_ID_STMICRO_UART_NO_HWFC                        0xcc04
#define PCI_DEVICE_ID_STMICRO_SOC_DMA                             0xcc05
#define PCI_DEVICE_ID_STMICRO_SATA                                0xcc06
#define PCI_DEVICE_ID_STMICRO_I2C                                 0xcc07
#define PCI_DEVICE_ID_STMICRO_SPI_HS                              0xcc08
#define PCI_DEVICE_ID_STMICRO_MAC                                 0xcc09
#define PCI_DEVICE_ID_STMICRO_SDIO_EMMC                           0xcc0a
#define PCI_DEVICE_ID_STMICRO_SDIO                                0xcc0b
#define PCI_DEVICE_ID_STMICRO_GPIO                                0xcc0c
#define PCI_DEVICE_ID_STMICRO_VIP                                 0xcc0d
#define PCI_DEVICE_ID_STMICRO_AUDIO_ROUTER_DMA                    0xcc0e
#define PCI_DEVICE_ID_STMICRO_AUDIO_ROUTER_SRCS                   0xcc0f
#define PCI_DEVICE_ID_STMICRO_AUDIO_ROUTER_MSPS                   0xcc10
#define PCI_DEVICE_ID_STMICRO_CAN                                 0xcc11
#define PCI_DEVICE_ID_STMICRO_MLB                                 0xcc12
#define PCI_DEVICE_ID_STMICRO_DBP                                 0xcc13
#define PCI_DEVICE_ID_STMICRO_SATA_PHY                            0xcc14
#define PCI_DEVICE_ID_STMICRO_ESRAM                               0xcc15
#define PCI_DEVICE_ID_STMICRO_VIC                                 0xcc16

#define PCI_VENDOR_ID_BUSLOGIC                                    0x104b
#define PCI_DEVICE_ID_BUSLOGIC_MULTIMASTER_NC                     0x0140
#define PCI_DEVICE_ID_BUSLOGIC_MULTIMASTER                        0x1040
#define PCI_DEVICE_ID_BUSLOGIC_FLASHPOINT                         0x8130

#define PCI_VENDOR_ID_TI                                          0x104c
#define PCI_DEVICE_ID_TI_TVP4020                                  0x3d07
#define PCI_DEVICE_ID_TI_4450                                     0x8011
#define PCI_DEVICE_ID_TI_XX21_XX11                                0x8031
#define PCI_DEVICE_ID_TI_XX21_XX11_FM                             0x8033
#define PCI_DEVICE_ID_TI_XX21_XX11_SD                             0x8034
#define PCI_DEVICE_ID_TI_X515                                     0x8036
#define PCI_DEVICE_ID_TI_XX12                                     0x8039
#define PCI_DEVICE_ID_TI_XX12_FM                                  0x803b
#define PCI_DEVICE_ID_TI_XIO2000A                                 0x8231
#define PCI_DEVICE_ID_TI_1130                                     0xac12
#define PCI_DEVICE_ID_TI_1031                                     0xac13
#define PCI_DEVICE_ID_TI_1131                                     0xac15
#define PCI_DEVICE_ID_TI_1250                                     0xac16
#define PCI_DEVICE_ID_TI_1220                                     0xac17
#define PCI_DEVICE_ID_TI_1221                                     0xac19
#define PCI_DEVICE_ID_TI_1210                                     0xac1a
#define PCI_DEVICE_ID_TI_1450                                     0xac1b
#define PCI_DEVICE_ID_TI_1225                                     0xac1c
#define PCI_DEVICE_ID_TI_1251A                                    0xac1d
#define PCI_DEVICE_ID_TI_1211                                     0xac1e
#define PCI_DEVICE_ID_TI_1251B                                    0xac1f
#define PCI_DEVICE_ID_TI_4410                                     0xac41
#define PCI_DEVICE_ID_TI_4451                                     0xac42
#define PCI_DEVICE_ID_TI_4510                                     0xac44
#define PCI_DEVICE_ID_TI_4520                                     0xac46
#define PCI_DEVICE_ID_TI_7510                                     0xac47
#define PCI_DEVICE_ID_TI_7610                                     0xac48
#define PCI_DEVICE_ID_TI_7410                                     0xac49
#define PCI_DEVICE_ID_TI_1410                                     0xac50
#define PCI_DEVICE_ID_TI_1420                                     0xac51
#define PCI_DEVICE_ID_TI_1451A                                    0xac52
#define PCI_DEVICE_ID_TI_1620                                     0xac54
#define PCI_DEVICE_ID_TI_1520                                     0xac55
#define PCI_DEVICE_ID_TI_1510                                     0xac56
#define PCI_DEVICE_ID_TI_X620                                     0xac8d
#define PCI_DEVICE_ID_TI_X420                                     0xac8e
#define PCI_DEVICE_ID_TI_XX20_FM                                  0xac8f
#define PCI_DEVICE_ID_TI_DRA74x                                   0xb500
#define PCI_DEVICE_ID_TI_DRA72x                                   0xb501

#define PCI_VENDOR_ID_SONY                                        0x104d

/* Winbond have two vendor IDs! See 0x10ad as well */

#define PCI_VENDOR_ID_WINBOND2                                    0x1050
#define PCI_DEVICE_ID_WINBOND2_89C940F                            0x5a5a
#define PCI_DEVICE_ID_WINBOND2_6692                               0x6692

#define PCI_VENDOR_ID_ANIGMA                                      0x1051
#define PCI_DEVICE_ID_ANIGMA_MC145575                             0x0100

#define PCI_VENDOR_ID_EFAR                                        0x1055
#define PCI_DEVICE_ID_EFAR_SLC90E66_1                             0x9130
#define PCI_DEVICE_ID_EFAR_SLC90E66_3                             0x9463

#define PCI_VENDOR_ID_MOTOROLA                                    0x1057
#define PCI_DEVICE_ID_MOTOROLA_MPC105                             0x0001
#define PCI_DEVICE_ID_MOTOROLA_MPC106                             0x0002
#define PCI_DEVICE_ID_MOTOROLA_MPC107                             0x0004
#define PCI_DEVICE_ID_MOTOROLA_RAVEN                              0x4801
#define PCI_DEVICE_ID_MOTOROLA_FALCON                             0x4802
#define PCI_DEVICE_ID_MOTOROLA_HAWK                               0x4803
#define PCI_DEVICE_ID_MOTOROLA_HARRIER                            0x480b
#define PCI_DEVICE_ID_MOTOROLA_MPC5200                            0x5803
#define PCI_DEVICE_ID_MOTOROLA_MPC5200B                           0x5809

#define PCI_VENDOR_ID_PROMISE                                     0x105a
#define PCI_DEVICE_ID_PROMISE_20265                               0x0d30
#define PCI_DEVICE_ID_PROMISE_20267                               0x4d30
#define PCI_DEVICE_ID_PROMISE_20246                               0x4d33
#define PCI_DEVICE_ID_PROMISE_20262                               0x4d38
#define PCI_DEVICE_ID_PROMISE_20263                               0x0D38
#define PCI_DEVICE_ID_PROMISE_20268                               0x4d68
#define PCI_DEVICE_ID_PROMISE_20269                               0x4d69
#define PCI_DEVICE_ID_PROMISE_20270                               0x6268
#define PCI_DEVICE_ID_PROMISE_20271                               0x6269
#define PCI_DEVICE_ID_PROMISE_20275                               0x1275
#define PCI_DEVICE_ID_PROMISE_20276                               0x5275
#define PCI_DEVICE_ID_PROMISE_20277                               0x7275

#define PCI_VENDOR_ID_FOXCONN                                     0x105b

#define PCI_VENDOR_ID_UMC                                         0x1060
#define PCI_DEVICE_ID_UMC_UM8673F                                 0x0101
#define PCI_DEVICE_ID_UMC_UM8886BF                                0x673a
#define PCI_DEVICE_ID_UMC_UM8886A                                 0x886a

#define PCI_VENDOR_ID_PICOPOWER                                   0x1066
#define PCI_DEVICE_ID_PICOPOWER_PT86C523                          0x0002
#define PCI_DEVICE_ID_PICOPOWER_PT86C523BBP                       0x8002

#define PCI_VENDOR_ID_MYLEX                                       0x1069
#define PCI_DEVICE_ID_MYLEX_DAC960_P                              0x0001
#define PCI_DEVICE_ID_MYLEX_DAC960_PD                             0x0002
#define PCI_DEVICE_ID_MYLEX_DAC960_PG                             0x0010
#define PCI_DEVICE_ID_MYLEX_DAC960_LA                             0x0020
#define PCI_DEVICE_ID_MYLEX_DAC960_LP                             0x0050
#define PCI_DEVICE_ID_MYLEX_DAC960_BA                             0xba56
#define PCI_DEVICE_ID_MYLEX_DAC960_GEM                            0xb166

#define PCI_VENDOR_ID_APPLE                                       0x106b
#define PCI_DEVICE_ID_APPLE_BANDIT                                0x0001
#define PCI_DEVICE_ID_APPLE_HYDRA                                 0x000e
#define PCI_DEVICE_ID_APPLE_UNI_N_FW                              0x0018
#define PCI_DEVICE_ID_APPLE_UNI_N_AGP                             0x0020
#define PCI_DEVICE_ID_APPLE_UNI_N_GMAC                            0x0021
#define PCI_DEVICE_ID_APPLE_UNI_N_GMACP                           0x0024
#define PCI_DEVICE_ID_APPLE_UNI_N_AGP_P                           0x0027
#define PCI_DEVICE_ID_APPLE_UNI_N_AGP15                           0x002d
#define PCI_DEVICE_ID_APPLE_UNI_N_PCI15                           0x002e
#define PCI_DEVICE_ID_APPLE_UNI_N_GMAC2                           0x0032
#define PCI_DEVICE_ID_APPLE_UNI_N_ATA                             0x0033
#define PCI_DEVICE_ID_APPLE_UNI_N_AGP2                            0x0034
#define PCI_DEVICE_ID_APPLE_IPID_ATA100                           0x003b
#define PCI_DEVICE_ID_APPLE_K2_ATA100                             0x0043
#define PCI_DEVICE_ID_APPLE_U3_AGP                                0x004b
#define PCI_DEVICE_ID_APPLE_K2_GMAC                               0x004c
#define PCI_DEVICE_ID_APPLE_SH_ATA                                0x0050
#define PCI_DEVICE_ID_APPLE_SH_SUNGEM                             0x0051
#define PCI_DEVICE_ID_APPLE_U3L_AGP                               0x0058
#define PCI_DEVICE_ID_APPLE_U3H_AGP                               0x0059
#define PCI_DEVICE_ID_APPLE_U4_PCIE                               0x005b
#define PCI_DEVICE_ID_APPLE_IPID2_AGP                             0x0066
#define PCI_DEVICE_ID_APPLE_IPID2_ATA                             0x0069
#define PCI_DEVICE_ID_APPLE_IPID2_FW                              0x006a
#define PCI_DEVICE_ID_APPLE_IPID2_GMAC                            0x006b
#define PCI_DEVICE_ID_APPLE_TIGON3                                0x1645

#define PCI_VENDOR_ID_YAMAHA                                      0x1073
#define PCI_DEVICE_ID_YAMAHA_724                                  0x0004
#define PCI_DEVICE_ID_YAMAHA_724F                                 0x000d
#define PCI_DEVICE_ID_YAMAHA_740                                  0x000a
#define PCI_DEVICE_ID_YAMAHA_740C                                 0x000c
#define PCI_DEVICE_ID_YAMAHA_744                                  0x0010
#define PCI_DEVICE_ID_YAMAHA_754                                  0x0012

#define PCI_VENDOR_ID_QLOGIC                                      0x1077
#define PCI_DEVICE_ID_QLOGIC_ISP10160                             0x1016
#define PCI_DEVICE_ID_QLOGIC_ISP1020                              0x1020
#define PCI_DEVICE_ID_QLOGIC_ISP1080                              0x1080
#define PCI_DEVICE_ID_QLOGIC_ISP12160                             0x1216
#define PCI_DEVICE_ID_QLOGIC_ISP1240                              0x1240
#define PCI_DEVICE_ID_QLOGIC_ISP1280                              0x1280
#define PCI_DEVICE_ID_QLOGIC_ISP2100                              0x2100
#define PCI_DEVICE_ID_QLOGIC_ISP2200                              0x2200
#define PCI_DEVICE_ID_QLOGIC_ISP2300                              0x2300
#define PCI_DEVICE_ID_QLOGIC_ISP2312                              0x2312
#define PCI_DEVICE_ID_QLOGIC_ISP2322                              0x2322
#define PCI_DEVICE_ID_QLOGIC_ISP6312                              0x6312
#define PCI_DEVICE_ID_QLOGIC_ISP6322                              0x6322
#define PCI_DEVICE_ID_QLOGIC_ISP2422                              0x2422
#define PCI_DEVICE_ID_QLOGIC_ISP2432                              0x2432
#define PCI_DEVICE_ID_QLOGIC_ISP2512                              0x2512
#define PCI_DEVICE_ID_QLOGIC_ISP2522                              0x2522
#define PCI_DEVICE_ID_QLOGIC_ISP5422                              0x5422
#define PCI_DEVICE_ID_QLOGIC_ISP5432                              0x5432

#define PCI_VENDOR_ID_CYRIX                                       0x1078
#define PCI_DEVICE_ID_CYRIX_5510                                  0x0000
#define PCI_DEVICE_ID_CYRIX_PCI_MASTER                            0x0001
#define PCI_DEVICE_ID_CYRIX_5520                                  0x0002
#define PCI_DEVICE_ID_CYRIX_5530_LEGACY                           0x0100
#define PCI_DEVICE_ID_CYRIX_5530_IDE                              0x0102
#define PCI_DEVICE_ID_CYRIX_5530_AUDIO                            0x0103
#define PCI_DEVICE_ID_CYRIX_5530_VIDEO                            0x0104

#define PCI_VENDOR_ID_CONTAQ                                      0x1080
#define PCI_DEVICE_ID_CONTAQ_82C693                               0xc693

#define PCI_VENDOR_ID_OLICOM                                      0x108d
#define PCI_DEVICE_ID_OLICOM_OC2325                               0x0012
#define PCI_DEVICE_ID_OLICOM_OC2183                               0x0013
#define PCI_DEVICE_ID_OLICOM_OC2326                               0x0014

#define PCI_VENDOR_ID_SUN                                         0x108e
#define PCI_DEVICE_ID_SUN_EBUS                                    0x1000
#define PCI_DEVICE_ID_SUN_HAPPYMEAL                               0x1001
#define PCI_DEVICE_ID_SUN_RIO_EBUS                                0x1100
#define PCI_DEVICE_ID_SUN_RIO_GEM                                 0x1101
#define PCI_DEVICE_ID_SUN_RIO_1394                                0x1102
#define PCI_DEVICE_ID_SUN_RIO_USB                                 0x1103
#define PCI_DEVICE_ID_SUN_GEM                                     0x2bad
#define PCI_DEVICE_ID_SUN_SIMBA                                   0x5000
#define PCI_DEVICE_ID_SUN_PBM                                     0x8000
#define PCI_DEVICE_ID_SUN_SCHIZO                                  0x8001
#define PCI_DEVICE_ID_SUN_SABRE                                   0xa000
#define PCI_DEVICE_ID_SUN_HUMMINGBIRD                             0xa001
#define PCI_DEVICE_ID_SUN_TOMATILLO                               0xa801
#define PCI_DEVICE_ID_SUN_CASSINI                                 0xabba

#define PCI_VENDOR_ID_NI                                          0x1093
#define PCI_DEVICE_ID_NI_PCI2322                                  0xd130
#define PCI_DEVICE_ID_NI_PCI2324                                  0xd140
#define PCI_DEVICE_ID_NI_PCI2328                                  0xd150
#define PCI_DEVICE_ID_NI_PXI8422_2322                             0xd190
#define PCI_DEVICE_ID_NI_PXI8422_2324                             0xd1a0
#define PCI_DEVICE_ID_NI_PXI8420_2322                             0xd1d0
#define PCI_DEVICE_ID_NI_PXI8420_2324                             0xd1e0
#define PCI_DEVICE_ID_NI_PXI8420_2328                             0xd1f0
#define PCI_DEVICE_ID_NI_PXI8420_23216                            0xd1f1
#define PCI_DEVICE_ID_NI_PCI2322I                                 0xd250
#define PCI_DEVICE_ID_NI_PCI2324I                                 0xd270
#define PCI_DEVICE_ID_NI_PCI23216                                 0xd2b0
#define PCI_DEVICE_ID_NI_PXI8430_2322                             0x7080
#define PCI_DEVICE_ID_NI_PCI8430_2322                             0x70db
#define PCI_DEVICE_ID_NI_PXI8430_2324                             0x70dd
#define PCI_DEVICE_ID_NI_PCI8430_2324                             0x70df
#define PCI_DEVICE_ID_NI_PXI8430_2328                             0x70e2
#define PCI_DEVICE_ID_NI_PCI8430_2328                             0x70e4
#define PCI_DEVICE_ID_NI_PXI8430_23216                            0x70e6
#define PCI_DEVICE_ID_NI_PCI8430_23216                            0x70e7
#define PCI_DEVICE_ID_NI_PXI8432_2322                             0x70e8
#define PCI_DEVICE_ID_NI_PCI8432_2322                             0x70ea
#define PCI_DEVICE_ID_NI_PXI8432_2324                             0x70ec
#define PCI_DEVICE_ID_NI_PCI8432_2324                             0x70ee

#define PCI_VENDOR_ID_CMD                                         0x1095
#define PCI_DEVICE_ID_CMD_643                                     0x0643
#define PCI_DEVICE_ID_CMD_646                                     0x0646
#define PCI_DEVICE_ID_CMD_648                                     0x0648
#define PCI_DEVICE_ID_CMD_649                                     0x0649

#define PCI_DEVICE_ID_SII_680                                     0x0680
#define PCI_DEVICE_ID_SII_3112                                    0x3112
#define PCI_DEVICE_ID_SII_1210SA                                  0x0240

#define PCI_VENDOR_ID_BROOKTREE                                   0x109e
#define PCI_DEVICE_ID_BROOKTREE_878                               0x0878
#define PCI_DEVICE_ID_BROOKTREE_879                               0x0879

#define PCI_VENDOR_ID_SGI                                         0x10a9
#define PCI_DEVICE_ID_SGI_IOC3                                    0x0003
#define PCI_DEVICE_ID_SGI_LITHIUM                                 0x1002
#define PCI_DEVICE_ID_SGI_IOC4                                    0x100a

#define PCI_VENDOR_ID_WINBOND                                     0x10ad
#define PCI_DEVICE_ID_WINBOND_82C105                              0x0105
#define PCI_DEVICE_ID_WINBOND_83C553                              0x0565

#define PCI_VENDOR_ID_PLX                                         0x10b5
#define PCI_DEVICE_ID_PLX_R685                                    0x1030
#define PCI_DEVICE_ID_PLX_ROMULUS                                 0x106a
#define PCI_DEVICE_ID_PLX_SPCOM800                                0x1076
#define PCI_DEVICE_ID_PLX_1077                                    0x1077
#define PCI_DEVICE_ID_PLX_SPCOM200                                0x1103
#define PCI_DEVICE_ID_PLX_DJINN_ITOO                              0x1151
#define PCI_DEVICE_ID_PLX_R753                                    0x1152
#define PCI_DEVICE_ID_PLX_OLITEC                                  0x1187
#define PCI_DEVICE_ID_PLX_PCI200SYN                               0x3196
#define PCI_DEVICE_ID_PLX_9030                                    0x9030
#define PCI_DEVICE_ID_PLX_9050                                    0x9050
#define PCI_DEVICE_ID_PLX_9056                                    0x9056
#define PCI_DEVICE_ID_PLX_9080                                    0x9080
#define PCI_DEVICE_ID_PLX_GTEK_SERIAL2                            0xa001

#define PCI_VENDOR_ID_MADGE                                       0x10b6
#define PCI_DEVICE_ID_MADGE_MK2                                   0x0002

#define PCI_VENDOR_ID_3COM                                        0x10b7
#define PCI_DEVICE_ID_3COM_3C985                                  0x0001
#define PCI_DEVICE_ID_3COM_3C940                                  0x1700
#define PCI_DEVICE_ID_3COM_3C339                                  0x3390
#define PCI_DEVICE_ID_3COM_3C359                                  0x3590
#define PCI_DEVICE_ID_3COM_3C940B                                 0x80eb
#define PCI_DEVICE_ID_3COM_3CR990                                 0x9900
#define PCI_DEVICE_ID_3COM_3CR990_TX_95                           0x9902
#define PCI_DEVICE_ID_3COM_3CR990_TX_97                           0x9903
#define PCI_DEVICE_ID_3COM_3CR990B                                0x9904
#define PCI_DEVICE_ID_3COM_3CR990_FX                              0x9905
#define PCI_DEVICE_ID_3COM_3CR990SVR95                            0x9908
#define PCI_DEVICE_ID_3COM_3CR990SVR97                            0x9909
#define PCI_DEVICE_ID_3COM_3CR990SVR                              0x990a

#define PCI_VENDOR_ID_AL                                          0x10b9
#define PCI_DEVICE_ID_AL_M1533                                    0x1533
#define PCI_DEVICE_ID_AL_M1535                                    0x1535
#define PCI_DEVICE_ID_AL_M1541                                    0x1541
#define PCI_DEVICE_ID_AL_M1563                                    0x1563
#define PCI_DEVICE_ID_AL_M1621                                    0x1621
#define PCI_DEVICE_ID_AL_M1631                                    0x1631
#define PCI_DEVICE_ID_AL_M1632                                    0x1632
#define PCI_DEVICE_ID_AL_M1641                                    0x1641
#define PCI_DEVICE_ID_AL_M1644                                    0x1644
#define PCI_DEVICE_ID_AL_M1647                                    0x1647
#define PCI_DEVICE_ID_AL_M1651                                    0x1651
#define PCI_DEVICE_ID_AL_M1671                                    0x1671
#define PCI_DEVICE_ID_AL_M1681                                    0x1681
#define PCI_DEVICE_ID_AL_M1683                                    0x1683
#define PCI_DEVICE_ID_AL_M1689                                    0x1689
#define PCI_DEVICE_ID_AL_M5219                                    0x5219
#define PCI_DEVICE_ID_AL_M5228                                    0x5228
#define PCI_DEVICE_ID_AL_M5229                                    0x5229
#define PCI_DEVICE_ID_AL_M5451                                    0x5451
#define PCI_DEVICE_ID_AL_M7101                                    0x7101

#define PCI_VENDOR_ID_NEOMAGIC                                    0x10c8
#define PCI_DEVICE_ID_NEOMAGIC_NM256AV_AUDIO                      0x8005
#define PCI_DEVICE_ID_NEOMAGIC_NM256ZX_AUDIO                      0x8006
#define PCI_DEVICE_ID_NEOMAGIC_NM256XL_PLUS_AUDIO                 0x8016

#define PCI_VENDOR_ID_TCONRAD                                     0x10da
#define PCI_DEVICE_ID_TCONRAD_TOKENRING                           0x0508

#define PCI_VENDOR_ID_NVIDIA                                      0x10de
#define PCI_DEVICE_ID_NVIDIA_TNT                                  0x0020
#define PCI_DEVICE_ID_NVIDIA_TNT2                                 0x0028
#define PCI_DEVICE_ID_NVIDIA_UTNT2                                0x0029
#define PCI_DEVICE_ID_NVIDIA_TNT_UNKNOWN                          0x002a
#define PCI_DEVICE_ID_NVIDIA_VTNT2                                0x002c
#define PCI_DEVICE_ID_NVIDIA_UVTNT2                               0x002d
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP04_SMBUS                   0x0034
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP04_IDE                     0x0035
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP04_SATA                    0x0036
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP04_SATA2                   0x003e
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6800_ULTRA                   0x0040
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6800                         0x0041
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6800_LE                      0x0042
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6800_GT                      0x0045
#define PCI_DEVICE_ID_NVIDIA_QUADRO_FX_4000                       0x004e
#define PCI_DEVICE_ID_NVIDIA_NFORCE4_SMBUS                        0x0052
#define PCI_DEVICE_ID_NVIDIA_NFORCE_CK804_IDE                     0x0053
#define PCI_DEVICE_ID_NVIDIA_NFORCE_CK804_SATA                    0x0054
#define PCI_DEVICE_ID_NVIDIA_NFORCE_CK804_SATA2                   0x0055
#define PCI_DEVICE_ID_NVIDIA_CK804_AUDIO                          0x0059
#define PCI_DEVICE_ID_NVIDIA_CK804_PCIE                           0x005d
#define PCI_DEVICE_ID_NVIDIA_NFORCE2_SMBUS                        0x0064
#define PCI_DEVICE_ID_NVIDIA_NFORCE2_IDE                          0x0065
#define PCI_DEVICE_ID_NVIDIA_MCP2_MODEM                           0x0069
#define PCI_DEVICE_ID_NVIDIA_MCP2_AUDIO                           0x006a
#define PCI_DEVICE_ID_NVIDIA_NFORCE2S_SMBUS                       0x0084
#define PCI_DEVICE_ID_NVIDIA_NFORCE2S_IDE                         0x0085
#define PCI_DEVICE_ID_NVIDIA_MCP2S_MODEM                          0x0089
#define PCI_DEVICE_ID_NVIDIA_CK8_AUDIO                            0x008a
#define PCI_DEVICE_ID_NVIDIA_NFORCE2S_SATA                        0x008e
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_7800_GT                      0x0090
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_7800_GTX                     0x0091
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_GO_7800                      0x0098
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_GO_7800_GTX                  0x0099
#define PCI_DEVICE_ID_NVIDIA_ITNT2                                0x00a0
#define PCI_DEVICE_ID_GEFORCE_6800A                               0x00c1
#define PCI_DEVICE_ID_GEFORCE_6800A_LE                            0x00c2
#define PCI_DEVICE_ID_GEFORCE_GO_6800                             0x00c8
#define PCI_DEVICE_ID_GEFORCE_GO_6800_ULTRA                       0x00c9
#define PCI_DEVICE_ID_QUADRO_FX_GO1400                            0x00cc
#define PCI_DEVICE_ID_QUADRO_FX_1400                              0x00ce
#define PCI_DEVICE_ID_NVIDIA_NFORCE3                              0x00d1
#define PCI_DEVICE_ID_NVIDIA_NFORCE3_SMBUS                        0x00d4
#define PCI_DEVICE_ID_NVIDIA_NFORCE3_IDE                          0x00d5
#define PCI_DEVICE_ID_NVIDIA_MCP3_MODEM                           0x00d9
#define PCI_DEVICE_ID_NVIDIA_MCP3_AUDIO                           0x00da
#define PCI_DEVICE_ID_NVIDIA_NFORCE3S                             0x00e1
#define PCI_DEVICE_ID_NVIDIA_NFORCE3S_SATA                        0x00e3
#define PCI_DEVICE_ID_NVIDIA_NFORCE3S_SMBUS                       0x00e4
#define PCI_DEVICE_ID_NVIDIA_NFORCE3S_IDE                         0x00e5
#define PCI_DEVICE_ID_NVIDIA_CK8S_AUDIO                           0x00ea
#define PCI_DEVICE_ID_NVIDIA_NFORCE3S_SATA2                       0x00ee
#define PCIE_DEVICE_ID_NVIDIA_GEFORCE_6800_ALT1                   0x00f0
#define PCIE_DEVICE_ID_NVIDIA_GEFORCE_6600_ALT1                   0x00f1
#define PCIE_DEVICE_ID_NVIDIA_GEFORCE_6600_ALT2                   0x00f2
#define PCIE_DEVICE_ID_NVIDIA_GEFORCE_6200_ALT1                   0x00f3
#define PCIE_DEVICE_ID_NVIDIA_GEFORCE_6800_GT                     0x00f9
#define PCIE_DEVICE_ID_NVIDIA_QUADRO_NVS280                       0x00fd
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_SDR                          0x0100
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_DDR                          0x0101
#define PCI_DEVICE_ID_NVIDIA_QUADRO                               0x0103
#define PCI_DEVICE_ID_NVIDIA_GEFORCE2_MX                          0x0110
#define PCI_DEVICE_ID_NVIDIA_GEFORCE2_MX2                         0x0111
#define PCI_DEVICE_ID_NVIDIA_GEFORCE2_GO                          0x0112
#define PCI_DEVICE_ID_NVIDIA_QUADRO2_MXR                          0x0113
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6600_GT                      0x0140
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6600                         0x0141
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6610_XL                      0x0145
#define PCI_DEVICE_ID_NVIDIA_QUADRO_FX_540                        0x014e
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6200                         0x014f
#define PCI_DEVICE_ID_NVIDIA_GEFORCE2_GTS                         0x0150
#define PCI_DEVICE_ID_NVIDIA_GEFORCE2_GTS2                        0x0151
#define PCI_DEVICE_ID_NVIDIA_GEFORCE2_ULTRA                       0x0152
#define PCI_DEVICE_ID_NVIDIA_QUADRO2_PRO                          0x0153
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6200_TURBOCACHE              0x0161
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_GO_6200                      0x0164
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_GO_6250                      0x0166
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_GO_6200_1                    0x0167
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_GO_6250_1                    0x0168
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_MX_460                      0x0170
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_MX_440                      0x0171
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_MX_420                      0x0172
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_MX_440_SE                   0x0173
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_440_GO                      0x0174
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_420_GO                      0x0175
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_420_GO_M32                  0x0176
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_460_GO                      0x0177
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_500XGL                       0x0178
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_440_GO_M64                  0x0179
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_200                          0x017a
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_550XGL                       0x017b
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_500_GOGL                     0x017c
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_410_GO_M16                  0x017d
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_MX_440_8X                   0x0181
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_MX_440SE_8X                 0x0182
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_MX_420_8X                   0x0183
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_MX_4000                     0x0185
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_448_GO                      0x0186
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_488_GO                      0x0187
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_580_XGL                      0x0188
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_MX_MAC                      0x0189
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_280_NVS                      0x018a
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_380_XGL                      0x018b
#define PCI_DEVICE_ID_NVIDIA_IGEFORCE2                            0x01a0
#define PCI_DEVICE_ID_NVIDIA_NFORCE                               0x01a4
#define PCI_DEVICE_ID_NVIDIA_MCP1_AUDIO                           0x01b1
#define PCI_DEVICE_ID_NVIDIA_NFORCE_SMBUS                         0x01b4
#define PCI_DEVICE_ID_NVIDIA_NFORCE_IDE                           0x01bc
#define PCI_DEVICE_ID_NVIDIA_MCP1_MODEM                           0x01c1
#define PCI_DEVICE_ID_NVIDIA_NFORCE2                              0x01e0
#define PCI_DEVICE_ID_NVIDIA_GEFORCE3                             0x0200
#define PCI_DEVICE_ID_NVIDIA_GEFORCE3_1                           0x0201
#define PCI_DEVICE_ID_NVIDIA_GEFORCE3_2                           0x0202
#define PCI_DEVICE_ID_NVIDIA_QUADRO_DDC                           0x0203
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6800B                        0x0211
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6800B_LE                     0x0212
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_6800B_GT                     0x0215
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_TI_4600                     0x0250
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_TI_4400                     0x0251
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_TI_4200                     0x0253
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_900XGL                       0x0258
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_750XGL                       0x0259
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_700XGL                       0x025b
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP51_SMBUS                   0x0264
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP51_IDE                     0x0265
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP51_SATA                    0x0266
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP51_SATA2                   0x0267
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP55_SMBUS                   0x0368
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP55_IDE                     0x036e
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP55_SATA                    0x037e
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP55_SATA2                   0x037f
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_TI_4800                     0x0280
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_TI_4800_8X                  0x0281
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_TI_4800SE                   0x0282
#define PCI_DEVICE_ID_NVIDIA_GEFORCE4_4200_GO                     0x0286
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_980_XGL                      0x0288
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_780_XGL                      0x0289
#define PCI_DEVICE_ID_NVIDIA_QUADRO4_700_GOGL                     0x028c
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5800_ULTRA                0x0301
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5800                      0x0302
#define PCI_DEVICE_ID_NVIDIA_QUADRO_FX_2000                       0x0308
#define PCI_DEVICE_ID_NVIDIA_QUADRO_FX_1000                       0x0309
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5600_ULTRA                0x0311
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5600                      0x0312
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5600SE                    0x0314
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_GO5600                    0x031a
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_GO5650                    0x031b
#define PCI_DEVICE_ID_NVIDIA_QUADRO_FX_GO700                      0x031c
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5200                      0x0320
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5200_ULTRA                0x0321
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5200_1                    0x0322
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5200SE                    0x0323
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_GO5200                    0x0324
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_GO5250                    0x0325
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5500                      0x0326
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5100                      0x0327
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_GO5250_32                 0x0328
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_GO_5200                   0x0329
#define PCI_DEVICE_ID_NVIDIA_QUADRO_NVS_280_PCI                   0x032a
#define PCI_DEVICE_ID_NVIDIA_QUADRO_FX_500                        0x032b
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_GO5300                    0x032c
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_GO5100                    0x032d
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5900_ULTRA                0x0330
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5900                      0x0331
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5900XT                    0x0332
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5950_ULTRA                0x0333
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5900ZT                    0x0334
#define PCI_DEVICE_ID_NVIDIA_QUADRO_FX_3000                       0x0338
#define PCI_DEVICE_ID_NVIDIA_QUADRO_FX_700                        0x033f
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5700_ULTRA                0x0341
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5700                      0x0342
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5700LE                    0x0343
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_5700VE                    0x0344
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_GO5700_1                  0x0347
#define PCI_DEVICE_ID_NVIDIA_GEFORCE_FX_GO5700_2                  0x0348
#define PCI_DEVICE_ID_NVIDIA_QUADRO_FX_GO1000                     0x034c
#define PCI_DEVICE_ID_NVIDIA_QUADRO_FX_1100                       0x034e
#define PCI_DEVICE_ID_NVIDIA_MCP55_BRIDGE_V0                      0x0360
#define PCI_DEVICE_ID_NVIDIA_MCP55_BRIDGE_V4                      0x0364
#define PCI_DEVICE_ID_NVIDIA_NVENET_15                            0x0373
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP61_SATA                    0x03e7
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP61_SMBUS                   0x03eb
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP61_IDE                     0x03ec
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP61_SATA2                   0x03f6
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP61_SATA3                   0x03f7
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP65_SMBUS                   0x0446
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP65_IDE                     0x0448
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP67_SMBUS                   0x0542
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP67_IDE                     0x0560
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP73_IDE                     0x056c
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP78S_SMBUS                  0x0752
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP77_IDE                     0x0759
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP73_SMBUS                   0x0d8
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP79_SMBUS                   0x0aa2
#define PCI_DEVICE_ID_NVIDIA_NFORCE_MCP89_SATA                    0x0d85

#define PCI_VENDOR_ID_IMS                                         0x10e0
#define PCI_DEVICE_ID_IMS_TT128                                   0x9128
#define PCI_DEVICE_ID_IMS_TT3D                                    0x9135

#define PCI_VENDOR_ID_AMCC                                        0x10e8
#define PCI_VENDOR_ID_AMPERE                                      0x1def

#define PCI_VENDOR_ID_INTERG                                      0x10ea
#define PCI_DEVICE_ID_INTERG_1682                                 0x1682
#define PCI_DEVICE_ID_INTERG_2000                                 0x2000
#define PCI_DEVICE_ID_INTERG_2010                                 0x2010
#define PCI_DEVICE_ID_INTERG_5000                                 0x5000
#define PCI_DEVICE_ID_INTERG_5050                                 0x5050

#define PCI_VENDOR_ID_REALTEK                                     0x10ec
#define PCI_DEVICE_ID_REALTEK_8139                                0x8139

#define PCI_VENDOR_ID_XILINX                                      0x10ee
#define PCI_DEVICE_ID_RME_DIGI96                                  0x3fc0
#define PCI_DEVICE_ID_RME_DIGI96_8                                0x3fc1
#define PCI_DEVICE_ID_RME_DIGI96_8_PRO                            0x3fc2
#define PCI_DEVICE_ID_RME_DIGI96_8_PAD_OR_PST                     0x3fc3
#define PCI_DEVICE_ID_XILINX_HAMMERFALL_DSP                       0x3fc5
#define PCI_DEVICE_ID_XILINX_HAMMERFALL_DSP_MADI                  0x3fc6

#define PCI_VENDOR_ID_INIT                                        0x1101

#define PCI_VENDOR_ID_CREATIVE                                    0x1102 /* duplicate: ECTIVA */
#define PCI_DEVICE_ID_CREATIVE_EMU10K1                            0x0002
#define PCI_DEVICE_ID_CREATIVE_20K1                               0x0005
#define PCI_DEVICE_ID_CREATIVE_20K2                               0x000b
#define PCI_SUBDEVICE_ID_CREATIVE_SB0760                          0x0024
#define PCI_SUBDEVICE_ID_CREATIVE_SB08801                         0x0041
#define PCI_SUBDEVICE_ID_CREATIVE_SB08802                         0x0042
#define PCI_SUBDEVICE_ID_CREATIVE_SB08803                         0x0043
#define PCI_SUBDEVICE_ID_CREATIVE_SB1270                          0x0062
#define PCI_SUBDEVICE_ID_CREATIVE_HENDRIX                         0x6000

#define PCI_VENDOR_ID_ECTIVA                                      0x1102 /* duplicate: CREATIVE */
#define PCI_DEVICE_ID_ECTIVA_EV1938                               0x8938

#define PCI_VENDOR_ID_TTI                                         0x1103
#define PCI_DEVICE_ID_TTI_HPT343                                  0x0003
#define PCI_DEVICE_ID_TTI_HPT366                                  0x0004
#define PCI_DEVICE_ID_TTI_HPT372                                  0x0005
#define PCI_DEVICE_ID_TTI_HPT302                                  0x0006
#define PCI_DEVICE_ID_TTI_HPT371                                  0x0007
#define PCI_DEVICE_ID_TTI_HPT374                                  0x0008
#define PCI_DEVICE_ID_TTI_HPT372N                                 0x0009 /* Apparently a 372N variant? */

#define PCI_VENDOR_ID_SIGMA                                       0x1105

#define PCI_VENDOR_ID_VIA                                         0x1106
#define PCI_DEVICE_ID_VIA_8763_0                                  0x0198
#define PCI_DEVICE_ID_VIA_8380_0                                  0x0204
#define PCI_DEVICE_ID_VIA_3238_0                                  0x0238
#define PCI_DEVICE_ID_VIA_PT880                                   0x0258
#define PCI_DEVICE_ID_VIA_PT880ULTRA                              0x0308
#define PCI_DEVICE_ID_VIA_PX8X0_0                                 0x0259
#define PCI_DEVICE_ID_VIA_3269_0                                  0x0269
#define PCI_DEVICE_ID_VIA_K8T800PRO_0                             0x0282
#define PCI_DEVICE_ID_VIA_3296_0                                  0x0296
#define PCI_DEVICE_ID_VIA_8363_0                                  0x0305
#define PCI_DEVICE_ID_VIA_P4M800CE                                0x0314
#define PCI_DEVICE_ID_VIA_P4M890                                  0x0327
#define PCI_DEVICE_ID_VIA_VT3324                                  0x0324
#define PCI_DEVICE_ID_VIA_VT3336                                  0x0336
#define PCI_DEVICE_ID_VIA_VT3351                                  0x0351
#define PCI_DEVICE_ID_VIA_VT3364                                  0x0364
#define PCI_DEVICE_ID_VIA_8371_0                                  0x0391
#define PCI_DEVICE_ID_VIA_6415                                    0x0415
#define PCI_DEVICE_ID_VIA_8501_0                                  0x0501
#define PCI_DEVICE_ID_VIA_82C561                                  0x0561
#define PCI_DEVICE_ID_VIA_82C586_1                                0x0571
#define PCI_DEVICE_ID_VIA_82C576                                  0x0576
#define PCI_DEVICE_ID_VIA_82C586_0                                0x0586
#define PCI_DEVICE_ID_VIA_82C596                                  0x0596
#define PCI_DEVICE_ID_VIA_82C597_0                                0x0597
#define PCI_DEVICE_ID_VIA_82C598_0                                0x0598
#define PCI_DEVICE_ID_VIA_8601_0                                  0x0601
#define PCI_DEVICE_ID_VIA_8605_0                                  0x0605
#define PCI_DEVICE_ID_VIA_82C686                                  0x0686
#define PCI_DEVICE_ID_VIA_82C691_0                                0x0691
#define PCI_DEVICE_ID_VIA_82C576_1                                0x1571
#define PCI_DEVICE_ID_VIA_82C586_2                                0x3038
#define PCI_DEVICE_ID_VIA_82C586_3                                0x3040
#define PCI_DEVICE_ID_VIA_82C596_3                                0x3050
#define PCI_DEVICE_ID_VIA_82C596B_3                               0x3051
#define PCI_DEVICE_ID_VIA_82C686_4                                0x3057
#define PCI_DEVICE_ID_VIA_82C686_5                                0x3058
#define PCI_DEVICE_ID_VIA_8233_5                                  0x3059
#define PCI_DEVICE_ID_VIA_8233_0                                  0x3074
#define PCI_DEVICE_ID_VIA_8633_0                                  0x3091
#define PCI_DEVICE_ID_VIA_8367_0                                  0x3099
#define PCI_DEVICE_ID_VIA_8653_0                                  0x3101
#define PCI_DEVICE_ID_VIA_8622                                    0x3102
#define PCI_DEVICE_ID_VIA_8235_USB_2                              0x3104
#define PCI_DEVICE_ID_VIA_8233C_0                                 0x3109
#define PCI_DEVICE_ID_VIA_8361                                    0x3112
#define PCI_DEVICE_ID_VIA_XM266                                   0x3116
#define PCI_DEVICE_ID_VIA_612X                                    0x3119
#define PCI_DEVICE_ID_VIA_862X_0                                  0x3123
#define PCI_DEVICE_ID_VIA_8753_0                                  0x3128
#define PCI_DEVICE_ID_VIA_8233A                                   0x3147
#define PCI_DEVICE_ID_VIA_8703_51_0                               0x3148
#define PCI_DEVICE_ID_VIA_8237_SATA                               0x3149
#define PCI_DEVICE_ID_VIA_XN266                                   0x3156
#define PCI_DEVICE_ID_VIA_6410                                    0x3164
#define PCI_DEVICE_ID_VIA_8754C_0                                 0x3168
#define PCI_DEVICE_ID_VIA_8235                                    0x3177
#define PCI_DEVICE_ID_VIA_8385_0                                  0x3188
#define PCI_DEVICE_ID_VIA_8377_0                                  0x3189
#define PCI_DEVICE_ID_VIA_8378_0                                  0x3205
#define PCI_DEVICE_ID_VIA_8783_0                                  0x3208
#define PCI_DEVICE_ID_VIA_8237                                    0x3227
#define PCI_DEVICE_ID_VIA_8251                                    0x3287
#define PCI_DEVICE_ID_VIA_8261                                    0x3402
#define PCI_DEVICE_ID_VIA_8237A                                   0x3337
#define PCI_DEVICE_ID_VIA_8237S                                   0x3372
#define PCI_DEVICE_ID_VIA_SATA_EIDE                               0x5324
#define PCI_DEVICE_ID_VIA_8231                                    0x8231
#define PCI_DEVICE_ID_VIA_8231_4                                  0x8235
#define PCI_DEVICE_ID_VIA_8365_1                                  0x8305
#define PCI_DEVICE_ID_VIA_CX700                                   0x8324
#define PCI_DEVICE_ID_VIA_CX700_IDE                               0x0581
#define PCI_DEVICE_ID_VIA_VX800                                   0x8353
#define PCI_DEVICE_ID_VIA_VX855                                   0x8409
#define PCI_DEVICE_ID_VIA_VX900                                   0x8410
#define PCI_DEVICE_ID_VIA_8371_1                                  0x8391
#define PCI_DEVICE_ID_VIA_82C598_1                                0x8598
#define PCI_DEVICE_ID_VIA_838X_1                                  0xb188
#define PCI_DEVICE_ID_VIA_83_87XX_1                               0xb198
#define PCI_DEVICE_ID_VIA_VX855_IDE                               0xc409
#define PCI_DEVICE_ID_VIA_ANON                                    0xffff

#define PCI_VENDOR_ID_SIEMENS                                     0x110a
#define PCI_DEVICE_ID_SIEMENS_DSCC4                               0x2102

#define PCI_VENDOR_ID_VORTEX                                      0x1119
#define PCI_DEVICE_ID_VORTEX_GDT60x0                              0x0000
#define PCI_DEVICE_ID_VORTEX_GDT6000B                             0x0001
#define PCI_DEVICE_ID_VORTEX_GDT6x10                              0x0002
#define PCI_DEVICE_ID_VORTEX_GDT6x20                              0x0003
#define PCI_DEVICE_ID_VORTEX_GDT6530                              0x0004
#define PCI_DEVICE_ID_VORTEX_GDT6550                              0x0005
#define PCI_DEVICE_ID_VORTEX_GDT6x17                              0x0006
#define PCI_DEVICE_ID_VORTEX_GDT6x27                              0x0007
#define PCI_DEVICE_ID_VORTEX_GDT6537                              0x0008
#define PCI_DEVICE_ID_VORTEX_GDT6557                              0x0009
#define PCI_DEVICE_ID_VORTEX_GDT6x15                              0x000a
#define PCI_DEVICE_ID_VORTEX_GDT6x25                              0x000b
#define PCI_DEVICE_ID_VORTEX_GDT6535                              0x000c
#define PCI_DEVICE_ID_VORTEX_GDT6555                              0x000d
#define PCI_DEVICE_ID_VORTEX_GDT6x17RP                            0x0100
#define PCI_DEVICE_ID_VORTEX_GDT6x27RP                            0x0101
#define PCI_DEVICE_ID_VORTEX_GDT6537RP                            0x0102
#define PCI_DEVICE_ID_VORTEX_GDT6557RP                            0x0103
#define PCI_DEVICE_ID_VORTEX_GDT6x11RP                            0x0104
#define PCI_DEVICE_ID_VORTEX_GDT6x21RP                            0x0105

#define PCI_VENDOR_ID_EF                                          0x111a
#define PCI_DEVICE_ID_EF_ATM_FPGA                                 0x0000
#define PCI_DEVICE_ID_EF_ATM_ASIC                                 0x0002
#define PCI_DEVICE_ID_EF_ATM_LANAI2                               0x0003
#define PCI_DEVICE_ID_EF_ATM_LANAIHB                              0x0005

#define PCI_VENDOR_ID_IDT                                         0x111d
#define PCI_DEVICE_ID_IDT_IDT77201                                0x0001

#define PCI_VENDOR_ID_FORE                                        0x1127
#define PCI_DEVICE_ID_FORE_PCA200E                                0x0300

#define PCI_VENDOR_ID_PHILIPS                                     0x1131
#define PCI_DEVICE_ID_PHILIPS_SAA7146                             0x7146
#define PCI_DEVICE_ID_PHILIPS_SAA9730                             0x9730

#define PCI_VENDOR_ID_EICON                                       0x1133
#define PCI_DEVICE_ID_EICON_DIVA20                                0xe002
#define PCI_DEVICE_ID_EICON_DIVA20_U                              0xe004
#define PCI_DEVICE_ID_EICON_DIVA201                               0xe005
#define PCI_DEVICE_ID_EICON_DIVA202                               0xe00b
#define PCI_DEVICE_ID_EICON_MAESTRA                               0xe010
#define PCI_DEVICE_ID_EICON_MAESTRAQ                              0xe012
#define PCI_DEVICE_ID_EICON_MAESTRAQ_U                            0xe013
#define PCI_DEVICE_ID_EICON_MAESTRAP                              0xe014

#define PCI_VENDOR_ID_CISCO                                       0x1137

#define PCI_VENDOR_ID_ZIATECH                                     0x1138
#define PCI_DEVICE_ID_ZIATECH_5550_HC                             0x5550

#define PCI_VENDOR_ID_SYSKONNECT                                  0x1148
#define PCI_DEVICE_ID_SYSKONNECT_TR                               0x4200
#define PCI_DEVICE_ID_SYSKONNECT_GE                               0x4300
#define PCI_DEVICE_ID_SYSKONNECT_YU                               0x4320
#define PCI_DEVICE_ID_SYSKONNECT_9DXX                             0x4400
#define PCI_DEVICE_ID_SYSKONNECT_9MXX                             0x4500

#define PCI_VENDOR_ID_DIGI                                        0x114f
#define PCI_DEVICE_ID_DIGI_DF_M_IOM2_E                            0x0070
#define PCI_DEVICE_ID_DIGI_DF_M_E                                 0x0071
#define PCI_DEVICE_ID_DIGI_DF_M_IOM2_A                            0x0072
#define PCI_DEVICE_ID_DIGI_DF_M_A                                 0x0073
#define PCI_DEVICE_ID_DIGI_NEO_8                                  0x00b1
#define PCI_DEVICE_ID_NEO_2DB9                                    0x00c8
#define PCI_DEVICE_ID_NEO_2DB9PRI                                 0x00c9
#define PCI_DEVICE_ID_NEO_2RJ45                                   0x00ca
#define PCI_DEVICE_ID_NEO_2RJ45PRI                                0x00cb
#define PCIE_DEVICE_ID_NEO_4_IBM                                  0x00f4

#define PCI_VENDOR_ID_XIRCOM                                      0x115d
#define PCI_DEVICE_ID_XIRCOM_RBM56G                               0x0101
#define PCI_DEVICE_ID_XIRCOM_X3201_MDM                            0x0103

#define PCI_VENDOR_ID_SERVERWORKS                                 0x1166
#define PCI_DEVICE_ID_SERVERWORKS_HE                              0x0008
#define PCI_DEVICE_ID_SERVERWORKS_LE                              0x0009
#define PCI_DEVICE_ID_SERVERWORKS_GCNB_LE                         0x0017
#define PCI_DEVICE_ID_SERVERWORKS_HT1000_PXB                      0x0036
#define PCI_DEVICE_ID_SERVERWORKS_EPB                             0x0103
#define PCI_DEVICE_ID_SERVERWORKS_HT2000_PCIE                     0x0132
#define PCI_DEVICE_ID_SERVERWORKS_OSB4                            0x0200
#define PCI_DEVICE_ID_SERVERWORKS_CSB5                            0x0201
#define PCI_DEVICE_ID_SERVERWORKS_CSB6                            0x0203
#define PCI_DEVICE_ID_SERVERWORKS_HT1000SB                        0x0205
#define PCI_DEVICE_ID_SERVERWORKS_OSB4IDE                         0x0211
#define PCI_DEVICE_ID_SERVERWORKS_CSB5IDE                         0x0212
#define PCI_DEVICE_ID_SERVERWORKS_CSB6IDE                         0x0213
#define PCI_DEVICE_ID_SERVERWORKS_HT1000IDE                       0x0214
#define PCI_DEVICE_ID_SERVERWORKS_CSB6IDE2                        0x0217
#define PCI_DEVICE_ID_SERVERWORKS_CSB6LPC                         0x0227
#define PCI_DEVICE_ID_SERVERWORKS_HT1100LD                        0x0408

#define PCI_VENDOR_ID_ALTERA                                      0x1172

#define PCI_VENDOR_ID_SBE                                         0x1176
#define PCI_DEVICE_ID_SBE_WANXL100                                0x0301
#define PCI_DEVICE_ID_SBE_WANXL200                                0x0302
#define PCI_DEVICE_ID_SBE_WANXL400                                0x0104
#define PCI_SUBDEVICE_ID_SBE_T3E3                                 0x0009
#define PCI_SUBDEVICE_ID_SBE_2T3E3_P0                             0x0901
#define PCI_SUBDEVICE_ID_SBE_2T3E3_P1                             0x0902

#define PCI_VENDOR_ID_TOSHIBA                                     0x1179
#define PCI_DEVICE_ID_TOSHIBA_PICCOLO_1                           0x0101
#define PCI_DEVICE_ID_TOSHIBA_PICCOLO_2                           0x0102
#define PCI_DEVICE_ID_TOSHIBA_PICCOLO_3                           0x0103
#define PCI_DEVICE_ID_TOSHIBA_PICCOLO_5                           0x0105
#define PCI_DEVICE_ID_TOSHIBA_TOPIC95                             0x060a
#define PCI_DEVICE_ID_TOSHIBA_TOPIC97                             0x060f
#define PCI_DEVICE_ID_TOSHIBA_TOPIC100                            0x0617

#define PCI_VENDOR_ID_TOSHIBA_2                                   0x102f
#define PCI_DEVICE_ID_TOSHIBA_TC35815CF                           0x0030
#define PCI_DEVICE_ID_TOSHIBA_TC35815_NWU                         0x0031
#define PCI_DEVICE_ID_TOSHIBA_TC35815_TX4939                      0x0032
#define PCI_DEVICE_ID_TOSHIBA_TC86C001_IDE                        0x0105
#define PCI_DEVICE_ID_TOSHIBA_TC86C001_MISC                       0x0108
#define PCI_DEVICE_ID_TOSHIBA_SPIDER_NET                          0x01b3

#define PCI_VENDOR_ID_ATTO                                        0x117c

#define PCI_VENDOR_ID_RICOH                                       0x1180
#define PCI_DEVICE_ID_RICOH_RL5C465                               0x0465
#define PCI_DEVICE_ID_RICOH_RL5C466                               0x0466
#define PCI_DEVICE_ID_RICOH_RL5C475                               0x0475
#define PCI_DEVICE_ID_RICOH_RL5C476                               0x0476
#define PCI_DEVICE_ID_RICOH_RL5C478                               0x0478
#define PCI_DEVICE_ID_RICOH_R5C822                                0x0822
#define PCI_DEVICE_ID_RICOH_R5CE822                               0xe822
#define PCI_DEVICE_ID_RICOH_R5CE823                               0xe823
#define PCI_DEVICE_ID_RICOH_R5C832                                0x0832
#define PCI_DEVICE_ID_RICOH_R5C843                                0x0843

#define PCI_VENDOR_ID_DLINK                                       0x1186
#define PCI_DEVICE_ID_DLINK_DGE510T                               0x4c00

#define PCI_VENDOR_ID_ARTOP                                       0x1191
#define PCI_DEVICE_ID_ARTOP_ATP850UF                              0x0005
#define PCI_DEVICE_ID_ARTOP_ATP860                                0x0006
#define PCI_DEVICE_ID_ARTOP_ATP860R                               0x0007
#define PCI_DEVICE_ID_ARTOP_ATP865                                0x0008
#define PCI_DEVICE_ID_ARTOP_ATP865R                               0x0009
#define PCI_DEVICE_ID_ARTOP_ATP867A                               0x000a
#define PCI_DEVICE_ID_ARTOP_ATP867B                               0x000b
#define PCI_DEVICE_ID_ARTOP_AEC7610                               0x8002
#define PCI_DEVICE_ID_ARTOP_AEC7612UW                             0x8010
#define PCI_DEVICE_ID_ARTOP_AEC7612U                              0x8020
#define PCI_DEVICE_ID_ARTOP_AEC7612S                              0x8030
#define PCI_DEVICE_ID_ARTOP_AEC7612D                              0x8040
#define PCI_DEVICE_ID_ARTOP_AEC7612SUW                            0x8050
#define PCI_DEVICE_ID_ARTOP_8060                                  0x8060

#define PCI_VENDOR_ID_ZEITNET                                     0x1193
#define PCI_DEVICE_ID_ZEITNET_1221                                0x0001
#define PCI_DEVICE_ID_ZEITNET_1225                                0x0002

#define PCI_VENDOR_ID_FUJITSU_ME                                  0x119e
#define PCI_DEVICE_ID_FUJITSU_FS155                               0x0001
#define PCI_DEVICE_ID_FUJITSU_FS50                                0x0003

#define PCI_SUBVENDOR_ID_KEYSPAN                                  0x11a9
#define PCI_SUBDEVICE_ID_KEYSPAN_SX2                              0x5334

#define PCI_VENDOR_ID_MARVELL                                     0x11ab
#define PCI_VENDOR_ID_MARVELL_EXT                                 0x1b4b
#define PCI_DEVICE_ID_MARVELL_GT64111                             0x4146
#define PCI_DEVICE_ID_MARVELL_GT64260                             0x6430
#define PCI_DEVICE_ID_MARVELL_MV64360                             0x6460
#define PCI_DEVICE_ID_MARVELL_MV64460                             0x6480
#define PCI_DEVICE_ID_MARVELL_88ALP01_NAND                        0x4100
#define PCI_DEVICE_ID_MARVELL_88ALP01_SD                          0x4101
#define PCI_DEVICE_ID_MARVELL_88ALP01_CCIC                        0x4102

#define PCI_VENDOR_ID_V3                                          0x11b0
#define PCI_DEVICE_ID_V3_V960                                     0x0001
#define PCI_DEVICE_ID_V3_V351                                     0x0002

#define PCI_VENDOR_ID_ATT                                         0x11c1
#define PCI_DEVICE_ID_ATT_VENUS_MODEM                             0x480

#define PCI_VENDOR_ID_SPECIALIX                                   0x11cb
#define PCI_SUBDEVICE_ID_SPECIALIX_SPEED4                         0xa004

#define PCI_VENDOR_ID_ANALOG_DEVICES                              0x11d4
#define PCI_DEVICE_ID_AD1889JS                                    0x1889

#define PCI_DEVICE_ID_SEGA_BBA                                    0x1234

#define PCI_VENDOR_ID_ZORAN                                       0x11de
#define PCI_DEVICE_ID_ZORAN_36057                                 0x6057
#define PCI_DEVICE_ID_ZORAN_36120                                 0x6120

#define PCI_VENDOR_ID_COMPEX                                      0x11f6
#define PCI_DEVICE_ID_COMPEX_ENET100VG4                           0x0112

#define PCI_VENDOR_ID_PMC_Sierra                                  0x11f8
#define PCI_VENDOR_ID_MICROSEMI                                   0x11f8

#define PCI_VENDOR_ID_RP                                          0x11fe
#define PCI_DEVICE_ID_RP32INTF                                    0x0001
#define PCI_DEVICE_ID_RP8INTF                                     0x0002
#define PCI_DEVICE_ID_RP16INTF                                    0x0003
#define PCI_DEVICE_ID_RP4QUAD                                     0x0004
#define PCI_DEVICE_ID_RP8OCTA                                     0x0005
#define PCI_DEVICE_ID_RP8J                                        0x0006
#define PCI_DEVICE_ID_RP4J                                        0x0007
#define PCI_DEVICE_ID_RP8SNI                                      0x0008
#define PCI_DEVICE_ID_RP16SNI                                     0x0009
#define PCI_DEVICE_ID_RPP4                                        0x000a
#define PCI_DEVICE_ID_RPP8                                        0x000b
#define PCI_DEVICE_ID_RP4M                                        0x000d
#define PCI_DEVICE_ID_RP2_232                                     0x000e
#define PCI_DEVICE_ID_RP2_422                                     0x000f
#define PCI_DEVICE_ID_URP32INTF                                   0x0801
#define PCI_DEVICE_ID_URP8INTF                                    0x0802
#define PCI_DEVICE_ID_URP16INTF                                   0x0803
#define PCI_DEVICE_ID_URP8OCTA                                    0x0805
#define PCI_DEVICE_ID_UPCI_RM3_8PORT                              0x080c
#define PCI_DEVICE_ID_UPCI_RM3_4PORT                              0x080d
#define PCI_DEVICE_ID_CRP16INTF                                   0x0903

#define PCI_VENDOR_ID_CYCLADES                                    0x120e
#define PCI_DEVICE_ID_CYCLOM_Y_Lo                                 0x0100
#define PCI_DEVICE_ID_CYCLOM_Y_Hi                                 0x0101
#define PCI_DEVICE_ID_CYCLOM_4Y_Lo                                0x0102
#define PCI_DEVICE_ID_CYCLOM_4Y_Hi                                0x0103
#define PCI_DEVICE_ID_CYCLOM_8Y_Lo                                0x0104
#define PCI_DEVICE_ID_CYCLOM_8Y_Hi                                0x0105
#define PCI_DEVICE_ID_CYCLOM_Z_Lo                                 0x0200
#define PCI_DEVICE_ID_CYCLOM_Z_Hi                                 0x0201
#define PCI_DEVICE_ID_PC300_RX_2                                  0x0300
#define PCI_DEVICE_ID_PC300_RX_1                                  0x0301
#define PCI_DEVICE_ID_PC300_TE_2                                  0x0310
#define PCI_DEVICE_ID_PC300_TE_1                                  0x0311
#define PCI_DEVICE_ID_PC300_TE_M_2                                0x0320
#define PCI_DEVICE_ID_PC300_TE_M_1                                0x0321

#define PCI_VENDOR_ID_ESSENTIAL                                   0x120f
#define PCI_DEVICE_ID_ESSENTIAL_ROADRUNNER                        0x0001

#define PCI_VENDOR_ID_O2                                          0x1217
#define PCI_DEVICE_ID_O2_6729                                     0x6729
#define PCI_DEVICE_ID_O2_6730                                     0x673a
#define PCI_DEVICE_ID_O2_6832                                     0x6832
#define PCI_DEVICE_ID_O2_6836                                     0x6836
#define PCI_DEVICE_ID_O2_6812                                     0x6872
#define PCI_DEVICE_ID_O2_6933                                     0x6933
#define PCI_DEVICE_ID_O2_8120                                     0x8120
#define PCI_DEVICE_ID_O2_8220                                     0x8220
#define PCI_DEVICE_ID_O2_8221                                     0x8221
#define PCI_DEVICE_ID_O2_8320                                     0x8320
#define PCI_DEVICE_ID_O2_8321                                     0x8321

#define PCI_VENDOR_ID_3DFX                                        0x121a
#define PCI_DEVICE_ID_3DFX_VOODOO                                 0x0001
#define PCI_DEVICE_ID_3DFX_VOODOO2                                0x0002
#define PCI_DEVICE_ID_3DFX_BANSHEE                                0x0003
#define PCI_DEVICE_ID_3DFX_VOODOO3                                0x0005
#define PCI_DEVICE_ID_3DFX_VOODOO5                                0x0009

#define PCI_VENDOR_ID_AVM                                         0x1244
#define PCI_DEVICE_ID_AVM_B1                                      0x0700
#define PCI_DEVICE_ID_AVM_C4                                      0x0800
#define PCI_DEVICE_ID_AVM_A1                                      0x0a00
#define PCI_DEVICE_ID_AVM_A1_V2                                   0x0e00
#define PCI_DEVICE_ID_AVM_C2                                      0x1100
#define PCI_DEVICE_ID_AVM_T1                                      0x1200

#define PCI_VENDOR_ID_STALLION                                    0x124d

/* Allied Telesyn */

#define PCI_VENDOR_ID_AT                                          0x1259
#define PCI_SUBDEVICE_ID_AT_2700FX                                0x2701
#define PCI_SUBDEVICE_ID_AT_2701FX                                0x2703

#define PCI_VENDOR_ID_ESS                                         0x125d
#define PCI_DEVICE_ID_ESS_ESS1968                                 0x1968
#define PCI_DEVICE_ID_ESS_ESS1978                                 0x1978
#define PCI_DEVICE_ID_ESS_ALLEGRO_1                               0x1988
#define PCI_DEVICE_ID_ESS_ALLEGRO                                 0x1989
#define PCI_DEVICE_ID_ESS_CANYON3D_2LE                            0x1990
#define PCI_DEVICE_ID_ESS_CANYON3D_2                              0x1992
#define PCI_DEVICE_ID_ESS_MAESTRO3                                0x1998
#define PCI_DEVICE_ID_ESS_MAESTRO3_1                              0x1999
#define PCI_DEVICE_ID_ESS_MAESTRO3_HW                             0x199a
#define PCI_DEVICE_ID_ESS_MAESTRO3_2                              0x199b

#define PCI_VENDOR_ID_SATSAGEM                                    0x1267
#define PCI_DEVICE_ID_SATSAGEM_NICCY                              0x1016

#define PCI_VENDOR_ID_ENSONIQ                                     0x1274
#define PCI_DEVICE_ID_ENSONIQ_CT5880                              0x5880
#define PCI_DEVICE_ID_ENSONIQ_ES1370                              0x5000
#define PCI_DEVICE_ID_ENSONIQ_ES1371                              0x1371

#define PCI_VENDOR_ID_TRANSMETA                                   0x1279
#define PCI_DEVICE_ID_EFFICEON                                    0x0060

#define PCI_VENDOR_ID_ROCKWELL                                    0x127a

#define PCI_VENDOR_ID_ITE                                         0x1283
#define PCI_DEVICE_ID_ITE_8172                                    0x8172
#define PCI_DEVICE_ID_ITE_8211                                    0x8211
#define PCI_DEVICE_ID_ITE_8212                                    0x8212
#define PCI_DEVICE_ID_ITE_8213                                    0x8213
#define PCI_DEVICE_ID_ITE_8152                                    0x8152
#define PCI_DEVICE_ID_ITE_8872                                    0x8872
#define PCI_DEVICE_ID_ITE_IT8330G_0                               0xe886

/* Formerly Platform Tech */

#define PCI_DEVICE_ID_ESS_ESS0100                                 0x0100

#define PCI_VENDOR_ID_ALTEON                                      0x12ae

#define PCI_SUBVENDOR_ID_CONNECT_TECH                             0x12c4
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH8_232                     0x0001
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH4_232                     0x0002
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH2_232                     0x0003
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH8_485                     0x0004
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH8_485_4_4                 0x0005
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH4_485                     0x0006
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH4_485_2_2                 0x0007
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH2_485                     0x0008
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH8_485_2_6                 0x0009
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH081101V1                  0x000a
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH041101V1                  0x000b
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH2_20MHZ                   0x000c
#define PCI_SUBDEVICE_ID_CONNECT_TECH_BH2_PTM                     0x000d
#define PCI_SUBDEVICE_ID_CONNECT_TECH_NT960PCI                    0x0100
#define PCI_SUBDEVICE_ID_CONNECT_TECH_TITAN_2                     0x0201
#define PCI_SUBDEVICE_ID_CONNECT_TECH_TITAN_4                     0x0202
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_2_232              0x0300
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_4_232              0x0301
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_8_232              0x0302
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_1_1                0x0310
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_2_2                0x0311
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_4_4                0x0312
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_2                  0x0320
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_4                  0x0321
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_8                  0x0322
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_2_485              0x0330
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_4_485              0x0331
#define PCI_SUBDEVICE_ID_CONNECT_TECH_PCI_UART_8_485              0x0332

#define PCI_VENDOR_ID_NVIDIA_SGS                                  0x12d2
#define PCI_DEVICE_ID_NVIDIA_SGS_RIVA128                          0x0018

#define PCI_SUBVENDOR_ID_CHASE_PCIFAST                            0x12e0
#define PCI_SUBDEVICE_ID_CHASE_PCIFAST4                           0x0031
#define PCI_SUBDEVICE_ID_CHASE_PCIFAST8                           0x0021
#define PCI_SUBDEVICE_ID_CHASE_PCIFAST16                          0x0011
#define PCI_SUBDEVICE_ID_CHASE_PCIFAST16FMC                       0x0041
#define PCI_SUBVENDOR_ID_CHASE_PCIRAS                             0x124d
#define PCI_SUBDEVICE_ID_CHASE_PCIRAS4                            0xf001
#define PCI_SUBDEVICE_ID_CHASE_PCIRAS8                            0xf010

#define PCI_VENDOR_ID_AUREAL                                      0x12eb
#define PCI_DEVICE_ID_AUREAL_VORTEX_1                             0x0001
#define PCI_DEVICE_ID_AUREAL_VORTEX_2                             0x0002
#define PCI_DEVICE_ID_AUREAL_ADVANTAGE                            0x0003

#define PCI_VENDOR_ID_ELECTRONICDESIGNGMBH                        0x12f8
#define PCI_DEVICE_ID_LML_33R10                                   0x8a02

#define PCI_VENDOR_ID_ESDGMBH                                     0x12fe
#define PCI_DEVICE_ID_ESDGMBH_CPCIASIO4                           0x0111

#define PCI_VENDOR_ID_CB                                          0x1307 /* Measurement Computing */

#define PCI_VENDOR_ID_SIIG                                        0x131f
#define PCI_SUBVENDOR_ID_SIIG                                     0x131f
#define PCI_DEVICE_ID_SIIG_1S_10x_550                             0x1000
#define PCI_DEVICE_ID_SIIG_1S_10x_650                             0x1001
#define PCI_DEVICE_ID_SIIG_1S_10x_850                             0x1002
#define PCI_DEVICE_ID_SIIG_1S1P_10x_550                           0x1010
#define PCI_DEVICE_ID_SIIG_1S1P_10x_650                           0x1011
#define PCI_DEVICE_ID_SIIG_1S1P_10x_850                           0x1012
#define PCI_DEVICE_ID_SIIG_1P_10x                                 0x1020
#define PCI_DEVICE_ID_SIIG_2P_10x                                 0x1021
#define PCI_DEVICE_ID_SIIG_2S_10x_550                             0x1030
#define PCI_DEVICE_ID_SIIG_2S_10x_650                             0x1031
#define PCI_DEVICE_ID_SIIG_2S_10x_850                             0x1032
#define PCI_DEVICE_ID_SIIG_2S1P_10x_550                           0x1034
#define PCI_DEVICE_ID_SIIG_2S1P_10x_650                           0x1035
#define PCI_DEVICE_ID_SIIG_2S1P_10x_850                           0x1036
#define PCI_DEVICE_ID_SIIG_4S_10x_550                             0x1050
#define PCI_DEVICE_ID_SIIG_4S_10x_650                             0x1051
#define PCI_DEVICE_ID_SIIG_4S_10x_850                             0x1052
#define PCI_DEVICE_ID_SIIG_1S_20x_550                             0x2000
#define PCI_DEVICE_ID_SIIG_1S_20x_650                             0x2001
#define PCI_DEVICE_ID_SIIG_1S_20x_850                             0x2002
#define PCI_DEVICE_ID_SIIG_1P_20x                                 0x2020
#define PCI_DEVICE_ID_SIIG_2P_20x                                 0x2021
#define PCI_DEVICE_ID_SIIG_2S_20x_550                             0x2030
#define PCI_DEVICE_ID_SIIG_2S_20x_650                             0x2031
#define PCI_DEVICE_ID_SIIG_2S_20x_850                             0x2032
#define PCI_DEVICE_ID_SIIG_2P1S_20x_550                           0x2040
#define PCI_DEVICE_ID_SIIG_2P1S_20x_650                           0x2041
#define PCI_DEVICE_ID_SIIG_2P1S_20x_850                           0x2042
#define PCI_DEVICE_ID_SIIG_1S1P_20x_550                           0x2010
#define PCI_DEVICE_ID_SIIG_1S1P_20x_650                           0x2011
#define PCI_DEVICE_ID_SIIG_1S1P_20x_850                           0x2012
#define PCI_DEVICE_ID_SIIG_4S_20x_550                             0x2050
#define PCI_DEVICE_ID_SIIG_4S_20x_650                             0x2051
#define PCI_DEVICE_ID_SIIG_4S_20x_850                             0x2052
#define PCI_DEVICE_ID_SIIG_2S1P_20x_550                           0x2060
#define PCI_DEVICE_ID_SIIG_2S1P_20x_650                           0x2061
#define PCI_DEVICE_ID_SIIG_2S1P_20x_850                           0x2062
#define PCI_DEVICE_ID_SIIG_8S_20x_550                             0x2080
#define PCI_DEVICE_ID_SIIG_8S_20x_650                             0x2081
#define PCI_DEVICE_ID_SIIG_8S_20x_850                             0x2082
#define PCI_SUBDEVICE_ID_SIIG_QUARTET_SERIAL                      0x2050

#define PCI_VENDOR_ID_RADISYS                                     0x1331

#define PCI_VENDOR_ID_MICRO_MEMORY                                0x1332
#define PCI_DEVICE_ID_MICRO_MEMORY_5415CN                         0x5415
#define PCI_DEVICE_ID_MICRO_MEMORY_5425CN                         0x5425
#define PCI_DEVICE_ID_MICRO_MEMORY_6155                           0x6155

#define PCI_VENDOR_ID_DOMEX                                       0x134a
#define PCI_DEVICE_ID_DOMEX_DMX3191D                              0x0001

#define PCI_VENDOR_ID_INTASHIELD                                  0x135a
#define PCI_DEVICE_ID_INTASHIELD_IS200                            0x0d80
#define PCI_DEVICE_ID_INTASHIELD_IS400                            0x0dc0

#define PCI_VENDOR_ID_QUATECH                                     0x135c
#define PCI_DEVICE_ID_QUATECH_QSC100                              0x0010
#define PCI_DEVICE_ID_QUATECH_DSC100                              0x0020
#define PCI_DEVICE_ID_QUATECH_DSC200                              0x0030
#define PCI_DEVICE_ID_QUATECH_QSC200                              0x0040
#define PCI_DEVICE_ID_QUATECH_ESC100D                             0x0050
#define PCI_DEVICE_ID_QUATECH_ESC100M                             0x0060
#define PCI_DEVICE_ID_QUATECH_QSCP100                             0x0120
#define PCI_DEVICE_ID_QUATECH_DSCP100                             0x0130
#define PCI_DEVICE_ID_QUATECH_QSCP200                             0x0140
#define PCI_DEVICE_ID_QUATECH_DSCP200                             0x0150
#define PCI_DEVICE_ID_QUATECH_QSCLP100                            0x0170
#define PCI_DEVICE_ID_QUATECH_DSCLP100                            0x0180
#define PCI_DEVICE_ID_QUATECH_DSC100E                             0x0181
#define PCI_DEVICE_ID_QUATECH_SSCLP100                            0x0190
#define PCI_DEVICE_ID_QUATECH_QSCLP200                            0x01a0
#define PCI_DEVICE_ID_QUATECH_DSCLP200                            0x01b0
#define PCI_DEVICE_ID_QUATECH_DSC200E                             0x01b1
#define PCI_DEVICE_ID_QUATECH_SSCLP200                            0x01c0
#define PCI_DEVICE_ID_QUATECH_ESCLP100                            0x01e0
#define PCI_DEVICE_ID_QUATECH_SPPXP_100                           0x0278

#define PCI_VENDOR_ID_SEALEVEL                                    0x135e
#define PCI_DEVICE_ID_SEALEVEL_U530                               0x7101
#define PCI_DEVICE_ID_SEALEVEL_UCOMM2                             0x7201
#define PCI_DEVICE_ID_SEALEVEL_UCOMM422                           0x7402
#define PCI_DEVICE_ID_SEALEVEL_UCOMM232                           0x7202
#define PCI_DEVICE_ID_SEALEVEL_COMM4                              0x7401
#define PCI_DEVICE_ID_SEALEVEL_COMM8                              0x7801
#define PCI_DEVICE_ID_SEALEVEL_7803                               0x7803
#define PCI_DEVICE_ID_SEALEVEL_UCOMM8                             0x7804

#define PCI_VENDOR_ID_HYPERCOPE                                   0x1365
#define PCI_DEVICE_ID_HYPERCOPE_PLX                               0x9050
#define PCI_SUBDEVICE_ID_HYPERCOPE_OLD_ERGO                       0x0104
#define PCI_SUBDEVICE_ID_HYPERCOPE_ERGO                           0x0106
#define PCI_SUBDEVICE_ID_HYPERCOPE_METRO                          0x0107
#define PCI_SUBDEVICE_ID_HYPERCOPE_CHAMP2                         0x0108

#define PCI_VENDOR_ID_DIGIGRAM                                    0x1369
#define PCI_SUBDEVICE_ID_DIGIGRAM_LX6464ES_SERIAL_SUBSYSTEM       0xc001
#define PCI_SUBDEVICE_ID_DIGIGRAM_LX6464ES_CAE_SERIAL_SUBSYSTEM   0xc002

#define PCI_VENDOR_ID_KAWASAKI                                    0x136b
#define PCI_DEVICE_ID_MCHIP_KL5A72002                             0xff01

#define PCI_VENDOR_ID_CNET                                        0x1371
#define PCI_DEVICE_ID_CNET_GIGACARD                               0x434e

#define PCI_VENDOR_ID_LMC                                         0x1376
#define PCI_DEVICE_ID_LMC_HSSI                                    0x0003
#define PCI_DEVICE_ID_LMC_DS3                                     0x0004
#define PCI_DEVICE_ID_LMC_SSI                                     0x0005
#define PCI_DEVICE_ID_LMC_T1                                      0x0006

#define PCI_VENDOR_ID_NETGEAR                                     0x1385
#define PCI_DEVICE_ID_NETGEAR_GA620                               0x620a

#define PCI_VENDOR_ID_APPLICOM                                    0x1389
#define PCI_DEVICE_ID_APPLICOM_PCIGENERIC                         0x0001
#define PCI_DEVICE_ID_APPLICOM_PCI2000IBS_CAN                     0x0002
#define PCI_DEVICE_ID_APPLICOM_PCI2000PFB                         0x0003

#define PCI_VENDOR_ID_MOXA                                        0x1393
#define PCI_DEVICE_ID_MOXA_RC7000                                 0x0001
#define PCI_DEVICE_ID_MOXA_CP102                                  0x1020
#define PCI_DEVICE_ID_MOXA_CP102UL                                0x1021
#define PCI_DEVICE_ID_MOXA_CP102U                                 0x1022
#define PCI_DEVICE_ID_MOXA_C104                                   0x1040
#define PCI_DEVICE_ID_MOXA_CP104U                                 0x1041
#define PCI_DEVICE_ID_MOXA_CP104JU                                0x1042
#define PCI_DEVICE_ID_MOXA_CP104EL                                0x1043
#define PCI_DEVICE_ID_MOXA_CT114                                  0x1140
#define PCI_DEVICE_ID_MOXA_CP114                                  0x1141
#define PCI_DEVICE_ID_MOXA_CP118U                                 0x1180
#define PCI_DEVICE_ID_MOXA_CP118EL                                0x1181
#define PCI_DEVICE_ID_MOXA_CP132                                  0x1320
#define PCI_DEVICE_ID_MOXA_CP132U                                 0x1321
#define PCI_DEVICE_ID_MOXA_CP134U                                 0x1340
#define PCI_DEVICE_ID_MOXA_C168                                   0x1680
#define PCI_DEVICE_ID_MOXA_CP168U                                 0x1681
#define PCI_DEVICE_ID_MOXA_CP168EL                                0x1682
#define PCI_DEVICE_ID_MOXA_CP204J                                 0x2040
#define PCI_DEVICE_ID_MOXA_C218                                   0x2180
#define PCI_DEVICE_ID_MOXA_C320                                   0x3200

#define PCI_VENDOR_ID_CCD                                         0x1397
#define PCI_DEVICE_ID_CCD_HFC4S                                   0x08b4
#define PCI_SUBDEVICE_ID_CCD_PMX2S                                0x1234
#define PCI_DEVICE_ID_CCD_HFC8S                                   0x16b8
#define PCI_DEVICE_ID_CCD_2BD0                                    0x2bd0
#define PCI_DEVICE_ID_CCD_HFCE1                                   0x30b1
#define PCI_SUBDEVICE_ID_CCD_SPD4S                                0x3136
#define PCI_SUBDEVICE_ID_CCD_SPDE1                                0x3137
#define PCI_DEVICE_ID_CCD_B000                                    0xb000
#define PCI_DEVICE_ID_CCD_B006                                    0xb006
#define PCI_DEVICE_ID_CCD_B007                                    0xb007
#define PCI_DEVICE_ID_CCD_B008                                    0xb008
#define PCI_DEVICE_ID_CCD_B009                                    0xb009
#define PCI_DEVICE_ID_CCD_B00A                                    0xb00a
#define PCI_DEVICE_ID_CCD_B00B                                    0xb00b
#define PCI_DEVICE_ID_CCD_B00C                                    0xb00c
#define PCI_DEVICE_ID_CCD_B100                                    0xb100
#define PCI_SUBDEVICE_ID_CCD_IOB4ST                               0xb520
#define PCI_SUBDEVICE_ID_CCD_IOB8STR                              0xb521
#define PCI_SUBDEVICE_ID_CCD_IOB8ST                               0xb522
#define PCI_SUBDEVICE_ID_CCD_IOB1E1                               0xb523
#define PCI_SUBDEVICE_ID_CCD_SWYX4S                               0xb540
#define PCI_SUBDEVICE_ID_CCD_JH4S20                               0xb550
#define PCI_SUBDEVICE_ID_CCD_IOB8ST_1                             0xb552
#define PCI_SUBDEVICE_ID_CCD_JHSE1                                0xb553
#define PCI_SUBDEVICE_ID_CCD_JH8S                                 0xb55B
#define PCI_SUBDEVICE_ID_CCD_BN4S                                 0xb560
#define PCI_SUBDEVICE_ID_CCD_BN8S                                 0xb562
#define PCI_SUBDEVICE_ID_CCD_BNE1                                 0xb563
#define PCI_SUBDEVICE_ID_CCD_BNE1D                                0xb564
#define PCI_SUBDEVICE_ID_CCD_BNE1DP                               0xb565
#define PCI_SUBDEVICE_ID_CCD_BN2S                                 0xb566
#define PCI_SUBDEVICE_ID_CCD_BN1SM                                0xb567
#define PCI_SUBDEVICE_ID_CCD_BN4SM                                0xb568
#define PCI_SUBDEVICE_ID_CCD_BN2SM                                0xb569
#define PCI_SUBDEVICE_ID_CCD_BNE1M                                0xb56a
#define PCI_SUBDEVICE_ID_CCD_BN8SP                                0xb56b
#define PCI_SUBDEVICE_ID_CCD_HFC4S                                0xb620
#define PCI_SUBDEVICE_ID_CCD_HFC8S                                0xb622
#define PCI_DEVICE_ID_CCD_B700                                    0xb700
#define PCI_DEVICE_ID_CCD_B701                                    0xb701
#define PCI_SUBDEVICE_ID_CCD_HFCE1                                0xc523
#define PCI_SUBDEVICE_ID_CCD_OV2S                                 0xe884
#define PCI_SUBDEVICE_ID_CCD_OV4S                                 0xe888
#define PCI_SUBDEVICE_ID_CCD_OV8S                                 0xe998

#define PCI_VENDOR_ID_EXAR                                        0x13a8
#define PCI_DEVICE_ID_EXAR_XR17C152                               0x0152
#define PCI_DEVICE_ID_EXAR_XR17C154                               0x0154
#define PCI_DEVICE_ID_EXAR_XR17C158                               0x0158
#define PCI_DEVICE_ID_EXAR_XR17V352                               0x0352
#define PCI_DEVICE_ID_EXAR_XR17V354                               0x0354
#define PCI_DEVICE_ID_EXAR_XR17V358                               0x0358

#define PCI_VENDOR_ID_MICROGATE                                   0x13c0
#define PCI_DEVICE_ID_MICROGATE_USC                               0x0010
#define PCI_DEVICE_ID_MICROGATE_SCA                               0x0030

#define PCI_VENDOR_ID_3WARE                                       0x13c1
#define PCI_DEVICE_ID_3WARE_1000                                  0x1000
#define PCI_DEVICE_ID_3WARE_7000                                  0x1001
#define PCI_DEVICE_ID_3WARE_9000                                  0x1002

#define PCI_VENDOR_ID_IOMEGA                                      0x13ca
#define PCI_DEVICE_ID_IOMEGA_BUZ                                  0x4231

#define PCI_VENDOR_ID_ABOCOM                                      0x13d1
#define PCI_DEVICE_ID_ABOCOM_2BD1                                 0x2bd1

#define PCI_VENDOR_ID_SUNDANCE                                    0x13f0

#define PCI_VENDOR_ID_CMEDIA                                      0x13f6
#define PCI_DEVICE_ID_CMEDIA_CM8338A                              0x0100
#define PCI_DEVICE_ID_CMEDIA_CM8338B                              0x0101
#define PCI_DEVICE_ID_CMEDIA_CM8738                               0x0111
#define PCI_DEVICE_ID_CMEDIA_CM8738B                              0x0112

#define PCI_VENDOR_ID_ADVANTECH                                   0x13fe

#define PCI_VENDOR_ID_MEILHAUS                                    0x1402

#define PCI_VENDOR_ID_LAVA                                        0x1407
#define PCI_DEVICE_ID_LAVA_DSERIAL                                0x0100 /* 2x 16550 */
#define PCI_DEVICE_ID_LAVA_QUATRO_A                               0x0101 /* 2x 16550, half of 4 port */
#define PCI_DEVICE_ID_LAVA_QUATRO_B                               0x0102 /* 2x 16550, half of 4 port */
#define PCI_DEVICE_ID_LAVA_QUATTRO_A                              0x0120 /* 2x 16550A, half of 4 port */
#define PCI_DEVICE_ID_LAVA_QUATTRO_B                              0x0121 /* 2x 16550A, half of 4 port */
#define PCI_DEVICE_ID_LAVA_OCTO_A                                 0x0180 /* 4x 16550A, half of 8 port */
#define PCI_DEVICE_ID_LAVA_OCTO_B                                 0x0181 /* 4x 16550A, half of 8 port */
#define PCI_DEVICE_ID_LAVA_PORT_PLUS                              0x0200 /* 2x 16650 */
#define PCI_DEVICE_ID_LAVA_QUAD_A                                 0x0201 /* 2x 16650, half of 4 port */
#define PCI_DEVICE_ID_LAVA_QUAD_B                                 0x0202 /* 2x 16650, half of 4 port */
#define PCI_DEVICE_ID_LAVA_SSERIAL                                0x0500 /* 1x 16550 */
#define PCI_DEVICE_ID_LAVA_PORT_650                               0x0600 /* 1x 16650 */
#define PCI_DEVICE_ID_LAVA_PARALLEL                               0x8000
#define PCI_DEVICE_ID_LAVA_DUAL_PAR_A                             0x8002 /* The Lava Dual Parallel is */
#define PCI_DEVICE_ID_LAVA_DUAL_PAR_B                             0x8003 /* Two PCI devices on a card */
#define PCI_DEVICE_ID_LAVA_BOCA_IOPPAR                            0x8800

#define PCI_VENDOR_ID_TIMEDIA                                     0x1409
#define PCI_DEVICE_ID_TIMEDIA_1889                                0x7168

#define PCI_VENDOR_ID_ICE                                         0x1412
#define PCI_DEVICE_ID_ICE_1712                                    0x1712
#define PCI_DEVICE_ID_VT1724                                      0x1724

#define PCI_VENDOR_ID_OXSEMI                                      0x1415
#define PCI_DEVICE_ID_OXSEMI_12PCI840                             0x8403
#define PCI_DEVICE_ID_OXSEMI_PCIe840                              0xc000
#define PCI_DEVICE_ID_OXSEMI_PCIe840_G                            0xc004
#define PCI_DEVICE_ID_OXSEMI_PCIe952_0                            0xc100
#define PCI_DEVICE_ID_OXSEMI_PCIe952_0_G                          0xc104
#define PCI_DEVICE_ID_OXSEMI_PCIe952_1                            0xc110
#define PCI_DEVICE_ID_OXSEMI_PCIe952_1_G                          0xc114
#define PCI_DEVICE_ID_OXSEMI_PCIe952_1_U                          0xc118
#define PCI_DEVICE_ID_OXSEMI_PCIe952_1_GU                         0xc11c
#define PCI_DEVICE_ID_OXSEMI_16PCI954                             0x9501
#define PCI_DEVICE_ID_OXSEMI_C950                                 0x950b
#define PCI_DEVICE_ID_OXSEMI_16PCI95N                             0x9511
#define PCI_DEVICE_ID_OXSEMI_16PCI954PP                           0x9513
#define PCI_DEVICE_ID_OXSEMI_16PCI952                             0x9521
#define PCI_DEVICE_ID_OXSEMI_16PCI952PP                           0x9523
#define PCI_SUBDEVICE_ID_OXSEMI_C950                              0x0001

#define PCI_VENDOR_ID_CHELSIO                                     0x1425

#define PCI_VENDOR_ID_ADLINK                                      0x144a

#define PCI_VENDOR_ID_SAMSUNG                                     0x144d

#define PCI_VENDOR_ID_GIGABYTE                                    0x1458

#define PCI_VENDOR_ID_AMBIT                                       0x1468

#define PCI_VENDOR_ID_MYRICOM                                     0x14c1

#define PCI_VENDOR_ID_MEDIATEK                                    0x14c3

#define PCI_VENDOR_ID_TITAN                                       0x14d2
#define PCI_DEVICE_ID_TITAN_010L                                  0x8001
#define PCI_DEVICE_ID_TITAN_100L                                  0x8010
#define PCI_DEVICE_ID_TITAN_110L                                  0x8011
#define PCI_DEVICE_ID_TITAN_200L                                  0x8020
#define PCI_DEVICE_ID_TITAN_210L                                  0x8021
#define PCI_DEVICE_ID_TITAN_400L                                  0x8040
#define PCI_DEVICE_ID_TITAN_800L                                  0x8080
#define PCI_DEVICE_ID_TITAN_100                                   0xa001
#define PCI_DEVICE_ID_TITAN_200                                   0xa005
#define PCI_DEVICE_ID_TITAN_400                                   0xa003
#define PCI_DEVICE_ID_TITAN_800B                                  0xa004

#define PCI_VENDOR_ID_PANACOM                                     0x14d4
#define PCI_DEVICE_ID_PANACOM_QUADMODEM                           0x0400
#define PCI_DEVICE_ID_PANACOM_DUALMODEM                           0x0402

#define PCI_VENDOR_ID_SIPACKETS                                   0x14d9
#define PCI_DEVICE_ID_SP1011                                      0x0010

#define PCI_VENDOR_ID_AFAVLAB                                     0x14db
#define PCI_DEVICE_ID_AFAVLAB_P028                                0x2180
#define PCI_DEVICE_ID_AFAVLAB_P030                                0x2182
#define PCI_SUBDEVICE_ID_AFAVLAB_P061                             0x2150

#define PCI_VENDOR_ID_AMPLICON                                    0x14dc

#define PCI_VENDOR_ID_BCM_GVC                                     0x14a4
#define PCI_VENDOR_ID_BROADCOM                                    0x14e4
#define PCI_DEVICE_ID_TIGON3_5752                                 0x1600
#define PCI_DEVICE_ID_TIGON3_5752M                                0x1601
#define PCI_DEVICE_ID_NX2_5709                                    0x1639
#define PCI_DEVICE_ID_NX2_5709S                                   0x163a
#define PCI_DEVICE_ID_TIGON3_5700                                 0x1644
#define PCI_DEVICE_ID_TIGON3_5701                                 0x1645
#define PCI_DEVICE_ID_TIGON3_5702                                 0x1646
#define PCI_DEVICE_ID_TIGON3_5703                                 0x1647
#define PCI_DEVICE_ID_TIGON3_5704                                 0x1648
#define PCI_DEVICE_ID_TIGON3_5704S_2                              0x1649
#define PCI_DEVICE_ID_NX2_5706                                    0x164a
#define PCI_DEVICE_ID_NX2_5708                                    0x164c
#define PCI_DEVICE_ID_TIGON3_5702FE                               0x164d
#define PCI_DEVICE_ID_NX2_57710                                   0x164e
#define PCI_DEVICE_ID_NX2_57711                                   0x164f
#define PCI_DEVICE_ID_NX2_57711E                                  0x1650
#define PCI_DEVICE_ID_TIGON3_5705                                 0x1653
#define PCI_DEVICE_ID_TIGON3_5705_2                               0x1654
#define PCI_DEVICE_ID_TIGON3_5719                                 0x1657
#define PCI_DEVICE_ID_TIGON3_5721                                 0x1659
#define PCI_DEVICE_ID_TIGON3_5722                                 0x165a
#define PCI_DEVICE_ID_TIGON3_5723                                 0x165b
#define PCI_DEVICE_ID_TIGON3_5705M                                0x165d
#define PCI_DEVICE_ID_TIGON3_5705M_2                              0x165e
#define PCI_DEVICE_ID_NX2_57712                                   0x1662
#define PCI_DEVICE_ID_NX2_57712E                                  0x1663
#define PCI_DEVICE_ID_NX2_57712_MF                                0x1663
#define PCI_DEVICE_ID_TIGON3_5714                                 0x1668
#define PCI_DEVICE_ID_TIGON3_5714S                                0x1669
#define PCI_DEVICE_ID_TIGON3_5780                                 0x166a
#define PCI_DEVICE_ID_TIGON3_5780S                                0x166b
#define PCI_DEVICE_ID_TIGON3_5705F                                0x166e
#define PCI_DEVICE_ID_NX2_57712_VF                                0x166f
#define PCI_DEVICE_ID_TIGON3_5754M                                0x1672
#define PCI_DEVICE_ID_TIGON3_5755M                                0x1673
#define PCI_DEVICE_ID_TIGON3_5756                                 0x1674
#define PCI_DEVICE_ID_TIGON3_5750                                 0x1676
#define PCI_DEVICE_ID_TIGON3_5751                                 0x1677
#define PCI_DEVICE_ID_TIGON3_5715                                 0x1678
#define PCI_DEVICE_ID_TIGON3_5715S                                0x1679
#define PCI_DEVICE_ID_TIGON3_5754                                 0x167a
#define PCI_DEVICE_ID_TIGON3_5755                                 0x167b
#define PCI_DEVICE_ID_TIGON3_5751M                                0x167d
#define PCI_DEVICE_ID_TIGON3_5751F                                0x167e
#define PCI_DEVICE_ID_TIGON3_5787F                                0x167f
#define PCI_DEVICE_ID_TIGON3_5761E                                0x1680
#define PCI_DEVICE_ID_TIGON3_5761                                 0x1681
#define PCI_DEVICE_ID_TIGON3_5764                                 0x1684
#define PCI_DEVICE_ID_NX2_57800                                   0x168a
#define PCI_DEVICE_ID_NX2_57840                                   0x168d
#define PCI_DEVICE_ID_NX2_57810                                   0x168e
#define PCI_DEVICE_ID_TIGON3_5787M                                0x1693
#define PCI_DEVICE_ID_TIGON3_5782                                 0x1696
#define PCI_DEVICE_ID_TIGON3_5784                                 0x1698
#define PCI_DEVICE_ID_TIGON3_5786                                 0x169a
#define PCI_DEVICE_ID_TIGON3_5787                                 0x169b
#define PCI_DEVICE_ID_TIGON3_5788                                 0x169c
#define PCI_DEVICE_ID_TIGON3_5789                                 0x169d
#define PCI_DEVICE_ID_NX2_57840_4_10                              0x16a1
#define PCI_DEVICE_ID_NX2_57840_2_20                              0x16a2
#define PCI_DEVICE_ID_NX2_57840_MF                                0x16a4
#define PCI_DEVICE_ID_NX2_57800_MF                                0x16a5
#define PCI_DEVICE_ID_TIGON3_5702X                                0x16a6
#define PCI_DEVICE_ID_TIGON3_5703X                                0x16a7
#define PCI_DEVICE_ID_TIGON3_5704S                                0x16a8
#define PCI_DEVICE_ID_NX2_57800_VF                                0x16a9
#define PCI_DEVICE_ID_NX2_5706S                                   0x16aa
#define PCI_DEVICE_ID_NX2_5708S                                   0x16ac
#define PCI_DEVICE_ID_NX2_57840_VF                                0x16ad
#define PCI_DEVICE_ID_NX2_57810_MF                                0x16ae
#define PCI_DEVICE_ID_NX2_57810_VF                                0x16af
#define PCI_DEVICE_ID_TIGON3_5702A3                               0x16c6
#define PCI_DEVICE_ID_TIGON3_5703A3                               0x16c7
#define PCI_DEVICE_ID_TIGON3_5781                                 0x16dd
#define PCI_DEVICE_ID_TIGON3_5753                                 0x16f7
#define PCI_DEVICE_ID_TIGON3_5753M                                0x16fd
#define PCI_DEVICE_ID_TIGON3_5753F                                0x16fe
#define PCI_DEVICE_ID_TIGON3_5901                                 0x170d
#define PCI_DEVICE_ID_BCM4401B1                                   0x170c
#define PCI_DEVICE_ID_TIGON3_5901_2                               0x170e
#define PCI_DEVICE_ID_TIGON3_5906                                 0x1712
#define PCI_DEVICE_ID_TIGON3_5906M                                0x1713
#define PCI_DEVICE_ID_BCM4401                                     0x4401
#define PCI_DEVICE_ID_BCM4401B0                                   0x4402

#define PCI_VENDOR_ID_TOPIC                                       0x151f
#define PCI_DEVICE_ID_TOPIC_TP560                                 0x0000

#define PCI_VENDOR_ID_MAINPINE                                    0x1522
#define PCI_DEVICE_ID_MAINPINE_PBRIDGE                            0x0100
#define PCI_VENDOR_ID_ENE                                         0x1524
#define PCI_DEVICE_ID_ENE_CB710_FLASH                             0x0510
#define PCI_DEVICE_ID_ENE_CB712_SD                                0x0550
#define PCI_DEVICE_ID_ENE_CB712_SD_2                              0x0551
#define PCI_DEVICE_ID_ENE_CB714_SD                                0x0750
#define PCI_DEVICE_ID_ENE_CB714_SD_2                              0x0751
#define PCI_DEVICE_ID_ENE_1211                                    0x1211
#define PCI_DEVICE_ID_ENE_1225                                    0x1225
#define PCI_DEVICE_ID_ENE_1410                                    0x1410
#define PCI_DEVICE_ID_ENE_710                                     0x1411
#define PCI_DEVICE_ID_ENE_712                                     0x1412
#define PCI_DEVICE_ID_ENE_1420                                    0x1420
#define PCI_DEVICE_ID_ENE_720                                     0x1421
#define PCI_DEVICE_ID_ENE_722                                     0x1422

#define PCI_SUBVENDOR_ID_PERLE                                    0x155f
#define PCI_SUBDEVICE_ID_PCI_RAS4                                 0xf001
#define PCI_SUBDEVICE_ID_PCI_RAS8                                 0xf010

#define PCI_VENDOR_ID_SYBA                                        0x1592
#define PCI_DEVICE_ID_SYBA_2P_EPP                                 0x0782
#define PCI_DEVICE_ID_SYBA_1P_ECP                                 0x0783

#define PCI_VENDOR_ID_MORETON                                     0x15aa
#define PCI_DEVICE_ID_RASTEL_2PORT                                0x2000

#define PCI_VENDOR_ID_VMWARE                                      0x15ad
#define PCI_DEVICE_ID_VMWARE_VMXNET3                              0x07b0

#define PCI_VENDOR_ID_ZOLTRIX                                     0x15b0
#define PCI_DEVICE_ID_ZOLTRIX_2BD0                                0x2bd0

#define PCI_VENDOR_ID_MELLANOX                                    0x15b3
#define PCI_DEVICE_ID_MELLANOX_CONNECTX3                          0x1003
#define PCI_DEVICE_ID_MELLANOX_CONNECTX3_PRO                      0x1007
#define PCI_DEVICE_ID_MELLANOX_CONNECTIB                          0x1011
#define PCI_DEVICE_ID_MELLANOX_CONNECTX4                          0x1013
#define PCI_DEVICE_ID_MELLANOX_CONNECTX4_LX                       0x1015
#define PCI_DEVICE_ID_MELLANOX_TAVOR                              0x5a44
#define PCI_DEVICE_ID_MELLANOX_TAVOR_BRIDGE                       0x5a46
#define PCI_DEVICE_ID_MELLANOX_SINAI_OLD                          0x5e8c
#define PCI_DEVICE_ID_MELLANOX_SINAI                              0x6274
#define PCI_DEVICE_ID_MELLANOX_ARBEL_COMPAT                       0x6278
#define PCI_DEVICE_ID_MELLANOX_ARBEL                              0x6282
#define PCI_DEVICE_ID_MELLANOX_HERMON_SDR                         0x6340
#define PCI_DEVICE_ID_MELLANOX_HERMON_DDR                         0x634a
#define PCI_DEVICE_ID_MELLANOX_HERMON_QDR                         0x6354
#define PCI_DEVICE_ID_MELLANOX_HERMON_EN                          0x6368
#define PCI_DEVICE_ID_MELLANOX_CONNECTX_EN                        0x6372
#define PCI_DEVICE_ID_MELLANOX_HERMON_DDR_GEN2                    0x6732
#define PCI_DEVICE_ID_MELLANOX_HERMON_QDR_GEN2                    0x673c
#define PCI_DEVICE_ID_MELLANOX_CONNECTX_EN_5_GEN2                 0x6746
#define PCI_DEVICE_ID_MELLANOX_HERMON_EN_GEN2                     0x6750
#define PCI_DEVICE_ID_MELLANOX_CONNECTX_EN_T_GEN2                 0x675a
#define PCI_DEVICE_ID_MELLANOX_CONNECTX_EN_GEN2                   0x6764
#define PCI_DEVICE_ID_MELLANOX_CONNECTX2                          0x676e

#define PCI_VENDOR_ID_DFI                                         0x15bd

#define PCI_VENDOR_ID_QUICKNET                                    0x15e2
#define PCI_DEVICE_ID_QUICKNET_XJ                                 0x0500

/* ADDI-DATA GmbH communication cards <info@addi-data.com> */

#define PCI_VENDOR_ID_ADDIDATA                                    0x15b8
#define PCI_DEVICE_ID_ADDIDATA_APCI7500                           0x7000
#define PCI_DEVICE_ID_ADDIDATA_APCI7420                           0x7001
#define PCI_DEVICE_ID_ADDIDATA_APCI7300                           0x7002
#define PCI_DEVICE_ID_ADDIDATA_APCI7500_2                         0x7009
#define PCI_DEVICE_ID_ADDIDATA_APCI7420_2                         0x700a
#define PCI_DEVICE_ID_ADDIDATA_APCI7300_2                         0x700b
#define PCI_DEVICE_ID_ADDIDATA_APCI7500_3                         0x700c
#define PCI_DEVICE_ID_ADDIDATA_APCI7420_3                         0x700d
#define PCI_DEVICE_ID_ADDIDATA_APCI7300_3                         0x700e
#define PCI_DEVICE_ID_ADDIDATA_APCI7800_3                         0x700f
#define PCI_DEVICE_ID_ADDIDATA_APCIe7300                          0x7010
#define PCI_DEVICE_ID_ADDIDATA_APCIe7420                          0x7011
#define PCI_DEVICE_ID_ADDIDATA_APCIe7500                          0x7012
#define PCI_DEVICE_ID_ADDIDATA_APCIe7800                          0x7013

#define PCI_VENDOR_ID_PDC                                         0x15e9

#define PCI_VENDOR_ID_FARSITE                                     0x1619
#define PCI_DEVICE_ID_FARSITE_T2P                                 0x0400
#define PCI_DEVICE_ID_FARSITE_T4P                                 0x0440
#define PCI_DEVICE_ID_FARSITE_T1U                                 0x0610
#define PCI_DEVICE_ID_FARSITE_T2U                                 0x0620
#define PCI_DEVICE_ID_FARSITE_T4U                                 0x0640
#define PCI_DEVICE_ID_FARSITE_TE1                                 0x1610
#define PCI_DEVICE_ID_FARSITE_TE1C                                0x1612

#define PCI_VENDOR_ID_ARIMA                                       0x161f

#define PCI_VENDOR_ID_BROCADE                                     0x1657
#define PCI_DEVICE_ID_BROCADE_CT                                  0x0014
#define PCI_DEVICE_ID_BROCADE_FC_8G1P                             0x0017
#define PCI_DEVICE_ID_BROCADE_CT_FC                               0x0021

#define PCI_VENDOR_ID_SIBYTE                                      0x166d
#define PCI_DEVICE_ID_BCM1250_PCI                                 0x0001
#define PCI_DEVICE_ID_BCM1250_HT                                  0x0002

#define PCI_VENDOR_ID_ATHEROS                                     0x168c

#define PCI_VENDOR_ID_NETCELL                                     0x169c
#define PCI_DEVICE_ID_REVOLUTION                                  0x0044

#define PCI_VENDOR_ID_CENATEK                                     0x16ca
#define PCI_DEVICE_ID_CENATEK_IDE                                 0x0001

#define PCI_VENDOR_ID_SYNOPSYS                                    0x16c3

#define PCI_VENDOR_ID_VITESSE                                     0x1725
#define PCI_DEVICE_ID_VITESSE_VSC7174                             0x7174

#define PCI_VENDOR_ID_LINKSYS                                     0x1737
#define PCI_DEVICE_ID_LINKSYS_EG1064                              0x1064

#define PCI_VENDOR_ID_ALTIMA                                      0x173b
#define PCI_DEVICE_ID_ALTIMA_AC1000                               0x03e8
#define PCI_DEVICE_ID_ALTIMA_AC1001                               0x03e9
#define PCI_DEVICE_ID_ALTIMA_AC9100                               0x03ea
#define PCI_DEVICE_ID_ALTIMA_AC1003                               0x03eb

#define PCI_VENDOR_ID_CAVIUM                                      0x177d

#define PCI_VENDOR_ID_TECHWELL                                    0x1797
#define PCI_DEVICE_ID_TECHWELL_6800                               0x6800
#define PCI_DEVICE_ID_TECHWELL_6801                               0x6801
#define PCI_DEVICE_ID_TECHWELL_6804                               0x6804
#define PCI_DEVICE_ID_TECHWELL_6816_1                             0x6810
#define PCI_DEVICE_ID_TECHWELL_6816_2                             0x6811
#define PCI_DEVICE_ID_TECHWELL_6816_3                             0x6812
#define PCI_DEVICE_ID_TECHWELL_6816_4                             0x6813

#define PCI_VENDOR_ID_BELKIN                                      0x1799
#define PCI_DEVICE_ID_BELKIN_F5D7010V7                            0x701f

#define PCI_VENDOR_ID_RDC                                         0x17f3
#define PCI_DEVICE_ID_RDC_R6020                                   0x6020
#define PCI_DEVICE_ID_RDC_R6030                                   0x6030
#define PCI_DEVICE_ID_RDC_R6040                                   0x6040
#define PCI_DEVICE_ID_RDC_R6060                                   0x6060
#define PCI_DEVICE_ID_RDC_R6061                                   0x6061
#define PCI_DEVICE_ID_RDC_D1010                                   0x1010

#define PCI_VENDOR_ID_LENOVO                                      0x17aa

#define PCI_VENDOR_ID_QCOM                                        0x17cb

#define PCI_VENDOR_ID_CDNS                                        0x17cd

#define PCI_VENDOR_ID_ARECA                                       0x17d3
#define PCI_DEVICE_ID_ARECA_1110                                  0x1110
#define PCI_DEVICE_ID_ARECA_1120                                  0x1120
#define PCI_DEVICE_ID_ARECA_1130                                  0x1130
#define PCI_DEVICE_ID_ARECA_1160                                  0x1160
#define PCI_DEVICE_ID_ARECA_1170                                  0x1170
#define PCI_DEVICE_ID_ARECA_1200                                  0x1200
#define PCI_DEVICE_ID_ARECA_1201                                  0x1201
#define PCI_DEVICE_ID_ARECA_1202                                  0x1202
#define PCI_DEVICE_ID_ARECA_1210                                  0x1210
#define PCI_DEVICE_ID_ARECA_1220                                  0x1220
#define PCI_DEVICE_ID_ARECA_1230                                  0x1230
#define PCI_DEVICE_ID_ARECA_1260                                  0x1260
#define PCI_DEVICE_ID_ARECA_1270                                  0x1270
#define PCI_DEVICE_ID_ARECA_1280                                  0x1280
#define PCI_DEVICE_ID_ARECA_1380                                  0x1380
#define PCI_DEVICE_ID_ARECA_1381                                  0x1381
#define PCI_DEVICE_ID_ARECA_1680                                  0x1680
#define PCI_DEVICE_ID_ARECA_1681                                  0x1681

#define PCI_VENDOR_ID_S2IO                                        0x17d5
#define PCI_DEVICE_ID_S2IO_WIN                                    0x5731
#define PCI_DEVICE_ID_S2IO_UNI                                    0x5831
#define PCI_DEVICE_ID_HERC_WIN                                    0x5732
#define PCI_DEVICE_ID_HERC_UNI                                    0x5832

#define PCI_VENDOR_ID_SITECOM                                     0x182d
#define PCI_DEVICE_ID_SITECOM_DC105V2                             0x3069

#define PCI_VENDOR_ID_TOPSPIN                                     0x1867

#define PCI_VENDOR_ID_COMMTECH                                    0x18f7

#define PCI_VENDOR_ID_SILAN                                       0x1904

#define PCI_VENDOR_ID_RENESAS                                     0x1912
#define PCI_DEVICE_ID_RENESAS_SH7781                              0x0001
#define PCI_DEVICE_ID_RENESAS_SH7780                              0x0002
#define PCI_DEVICE_ID_RENESAS_SH7763                              0x0004
#define PCI_DEVICE_ID_RENESAS_SH7785                              0x0007
#define PCI_DEVICE_ID_RENESAS_SH7786                              0x0010

#define PCI_VENDOR_ID_SOLARFLARE                                  0x1924
#define PCI_DEVICE_ID_SOLARFLARE_SFC4000A_0                       0x0703
#define PCI_DEVICE_ID_SOLARFLARE_SFC4000A_1                       0x6703
#define PCI_DEVICE_ID_SOLARFLARE_SFC4000B                         0x0710

#define PCI_VENDOR_ID_TDI                                         0x192e
#define PCI_DEVICE_ID_TDI_EHCI                                    0x0101

#define PCI_VENDOR_ID_FREESCALE                                   0x1957
#define PCI_DEVICE_ID_MPC8308                                     0xc006
#define PCI_DEVICE_ID_MPC8315E                                    0x00b4
#define PCI_DEVICE_ID_MPC8315                                     0x00b5
#define PCI_DEVICE_ID_MPC8314E                                    0x00b6
#define PCI_DEVICE_ID_MPC8314                                     0x00b7
#define PCI_DEVICE_ID_MPC8378E                                    0x00c4
#define PCI_DEVICE_ID_MPC8378                                     0x00c5
#define PCI_DEVICE_ID_MPC8377E                                    0x00c6
#define PCI_DEVICE_ID_MPC8377                                     0x00c7
#define PCI_DEVICE_ID_MPC8548E                                    0x0012
#define PCI_DEVICE_ID_MPC8548                                     0x0013
#define PCI_DEVICE_ID_MPC8543E                                    0x0014
#define PCI_DEVICE_ID_MPC8543                                     0x0015
#define PCI_DEVICE_ID_MPC8547E                                    0x0018
#define PCI_DEVICE_ID_MPC8545E                                    0x0019
#define PCI_DEVICE_ID_MPC8545                                     0x001a
#define PCI_DEVICE_ID_MPC8569E                                    0x0061
#define PCI_DEVICE_ID_MPC8569                                     0x0060
#define PCI_DEVICE_ID_MPC8568E                                    0x0020
#define PCI_DEVICE_ID_MPC8568                                     0x0021
#define PCI_DEVICE_ID_MPC8567E                                    0x0022
#define PCI_DEVICE_ID_MPC8567                                     0x0023
#define PCI_DEVICE_ID_MPC8533E                                    0x0030
#define PCI_DEVICE_ID_MPC8533                                     0x0031
#define PCI_DEVICE_ID_MPC8544E                                    0x0032
#define PCI_DEVICE_ID_MPC8544                                     0x0033
#define PCI_DEVICE_ID_MPC8572E                                    0x0040
#define PCI_DEVICE_ID_MPC8572                                     0x0041
#define PCI_DEVICE_ID_MPC8536E                                    0x0050
#define PCI_DEVICE_ID_MPC8536                                     0x0051
#define PCI_DEVICE_ID_P2020E                                      0x0070
#define PCI_DEVICE_ID_P2020                                       0x0071
#define PCI_DEVICE_ID_P2010E                                      0x0078
#define PCI_DEVICE_ID_P2010                                       0x0079
#define PCI_DEVICE_ID_P1020E                                      0x0100
#define PCI_DEVICE_ID_P1020                                       0x0101
#define PCI_DEVICE_ID_P1021E                                      0x0102
#define PCI_DEVICE_ID_P1021                                       0x0103
#define PCI_DEVICE_ID_P1011E                                      0x0108
#define PCI_DEVICE_ID_P1011                                       0x0109
#define PCI_DEVICE_ID_P1022E                                      0x0110
#define PCI_DEVICE_ID_P1022                                       0x0111
#define PCI_DEVICE_ID_P1013E                                      0x0118
#define PCI_DEVICE_ID_P1013                                       0x0119
#define PCI_DEVICE_ID_P4080E                                      0x0400
#define PCI_DEVICE_ID_P4080                                       0x0401
#define PCI_DEVICE_ID_P4040E                                      0x0408
#define PCI_DEVICE_ID_P4040                                       0x0409
#define PCI_DEVICE_ID_P2040E                                      0x0410
#define PCI_DEVICE_ID_P2040                                       0x0411
#define PCI_DEVICE_ID_P3041E                                      0x041e
#define PCI_DEVICE_ID_P3041                                       0x041f
#define PCI_DEVICE_ID_P5020E                                      0x0420
#define PCI_DEVICE_ID_P5020                                       0x0421
#define PCI_DEVICE_ID_P5010E                                      0x0428
#define PCI_DEVICE_ID_P5010                                       0x0429
#define PCI_DEVICE_ID_MPC8641                                     0x7010
#define PCI_DEVICE_ID_MPC8641D                                    0x7011
#define PCI_DEVICE_ID_MPC8610                                     0x7018

#define PCI_VENDOR_ID_PASEMI                                      0x1959

#define PCI_VENDOR_ID_ATTANSIC                                    0x1969
#define PCI_DEVICE_ID_ATTANSIC_L1                                 0x1048
#define PCI_DEVICE_ID_ATTANSIC_L2                                 0x2048

#define PCI_VENDOR_ID_JMICRON                                     0x197b
#define PCI_DEVICE_ID_JMICRON_JMB360                              0x2360
#define PCI_DEVICE_ID_JMICRON_JMB361                              0x2361
#define PCI_DEVICE_ID_JMICRON_JMB362                              0x2362
#define PCI_DEVICE_ID_JMICRON_JMB363                              0x2363
#define PCI_DEVICE_ID_JMICRON_JMB364                              0x2364
#define PCI_DEVICE_ID_JMICRON_JMB365                              0x2365
#define PCI_DEVICE_ID_JMICRON_JMB366                              0x2366
#define PCI_DEVICE_ID_JMICRON_JMB368                              0x2368
#define PCI_DEVICE_ID_JMICRON_JMB369                              0x2369
#define PCI_DEVICE_ID_JMICRON_JMB38X_SD                           0x2381
#define PCI_DEVICE_ID_JMICRON_JMB38X_MMC                          0x2382
#define PCI_DEVICE_ID_JMICRON_JMB38X_MS                           0x2383
#define PCI_DEVICE_ID_JMICRON_JMB385_MS                           0x2388
#define PCI_DEVICE_ID_JMICRON_JMB388_SD                           0x2391
#define PCI_DEVICE_ID_JMICRON_JMB388_ESD                          0x2392
#define PCI_DEVICE_ID_JMICRON_JMB390_MS                           0x2393

#define PCI_VENDOR_ID_KORENIX                                     0x1982
#define PCI_DEVICE_ID_KORENIX_JETCARDF0                           0x1600
#define PCI_DEVICE_ID_KORENIX_JETCARDF1                           0x16ff
#define PCI_DEVICE_ID_KORENIX_JETCARDF2                           0x1700
#define PCI_DEVICE_ID_KORENIX_JETCARDF3                           0x17ff

#define PCI_VENDOR_ID_HUAWEI                                      0x19e5

#define PCI_VENDOR_ID_NETRONOME                                   0x19ee
#define PCI_DEVICE_ID_NETRONOME_NFP4000                           0x4000
#define PCI_DEVICE_ID_NETRONOME_NFP5000                           0x5000
#define PCI_DEVICE_ID_NETRONOME_NFP6000                           0x6000
#define PCI_DEVICE_ID_NETRONOME_NFP6000_VF                        0x6003

#define PCI_VENDOR_ID_QMI                                         0x1a32

#define PCI_VENDOR_ID_AZWAVE                                      0x1a3b

#define PCI_VENDOR_ID_REDHAT_QUMRANET                             0x1af4
#define PCI_SUBVENDOR_ID_REDHAT_QUMRANET                          0x1af4
#define PCI_SUBDEVICE_ID_QEMU                                     0x1100

#define PCI_VENDOR_ID_ASMEDIA                                     0x1b21

#define PCI_VENDOR_ID_CIRCUITCO                                   0x1cc8
#define PCI_SUBSYSTEM_ID_CIRCUITCO_MINNOWBOARD                    0x0001

#define PCI_VENDOR_ID_AMAZON                                      0x1d0f

#define PCI_VENDOR_ID_HYGON                                       0x1d94

#define PCI_VENDOR_ID_TEKRAM                                      0x1de1
#define PCI_DEVICE_ID_TEKRAM_DC290                                0xdc29

#define PCI_VENDOR_ID_TEHUTI                                      0x1fc9
#define PCI_DEVICE_ID_TEHUTI_3009                                 0x3009
#define PCI_DEVICE_ID_TEHUTI_3010                                 0x3010
#define PCI_DEVICE_ID_TEHUTI_3014                                 0x3014

#define PCI_VENDOR_ID_SUNIX                                       0x1fd4
#define PCI_DEVICE_ID_SUNIX_1999                                  0x1999

#define PCI_VENDOR_ID_HINT                                        0x3388
#define PCI_DEVICE_ID_HINT_VXPROII_IDE                            0x8013

#define PCI_VENDOR_ID_3DLABS                                      0x3d3d
#define PCI_DEVICE_ID_3DLABS_PERMEDIA2                            0x0007
#define PCI_DEVICE_ID_3DLABS_PERMEDIA2V                           0x0009

#define PCI_VENDOR_ID_NETXEN                                      0x4040
#define PCI_DEVICE_ID_NX2031_10GXSR                               0x0001
#define PCI_DEVICE_ID_NX2031_10GCX4                               0x0002
#define PCI_DEVICE_ID_NX2031_4GCU                                 0x0003
#define PCI_DEVICE_ID_NX2031_IMEZ                                 0x0004
#define PCI_DEVICE_ID_NX2031_HMEZ                                 0x0005
#define PCI_DEVICE_ID_NX2031_XG_MGMT                              0x0024
#define PCI_DEVICE_ID_NX2031_XG_MGMT2                             0x0025
#define PCI_DEVICE_ID_NX3031                                      0x0100

#define PCI_VENDOR_ID_AKS                                         0x416c
#define PCI_DEVICE_ID_AKS_ALADDINCARD                             0x0100

#define PCI_VENDOR_ID_ACCESSIO                                    0x494f
#define PCI_DEVICE_ID_ACCESSIO_WDG_CSM                            0x22c0

#define PCI_VENDOR_ID_S3                                          0x5333
#define PCI_DEVICE_ID_S3_TRIO                                     0x8811
#define PCI_DEVICE_ID_S3_868                                      0x8880
#define PCI_DEVICE_ID_S3_968                                      0x88f0
#define PCI_DEVICE_ID_S3_SAVAGE4                                  0x8a25
#define PCI_DEVICE_ID_S3_PROSAVAGE8                               0x8d04
#define PCI_DEVICE_ID_S3_SONICVIBES                               0xca00

#define PCI_VENDOR_ID_DUNORD                                      0x5544
#define PCI_DEVICE_ID_DUNORD_I3000                                0x0001

#define PCI_VENDOR_ID_DCI                                         0x6666
#define PCI_DEVICE_ID_DCI_PCCOM4                                  0x0001
#define PCI_DEVICE_ID_DCI_PCCOM8                                  0x0002
#define PCI_DEVICE_ID_DCI_PCCOM2                                  0x0004

#define PCI_VENDOR_ID_INTEL                                       0x8086
#define PCI_DEVICE_ID_INTEL_EESSC                                 0x0008
#define PCI_DEVICE_ID_INTEL_PXHD_0                                0x0320
#define PCI_DEVICE_ID_INTEL_PXHD_1                                0x0321
#define PCI_DEVICE_ID_INTEL_PXH_0                                 0x0329
#define PCI_DEVICE_ID_INTEL_PXH_1                                 0x032a
#define PCI_DEVICE_ID_INTEL_PXHV                                  0x032c
#define PCI_DEVICE_ID_INTEL_80332_0                               0x0330
#define PCI_DEVICE_ID_INTEL_80332_1                               0x0332
#define PCI_DEVICE_ID_INTEL_80333_0                               0x0370
#define PCI_DEVICE_ID_INTEL_80333_1                               0x0372
#define PCI_DEVICE_ID_INTEL_82375                                 0x0482
#define PCI_DEVICE_ID_INTEL_82424                                 0x0483
#define PCI_DEVICE_ID_INTEL_82378                                 0x0484
#define PCI_DEVICE_ID_INTEL_MRST_SD0                              0x0807
#define PCI_DEVICE_ID_INTEL_MRST_SD1                              0x0808
#define PCI_DEVICE_ID_INTEL_MFD_SD                                0x0820
#define PCI_DEVICE_ID_INTEL_MFD_SDIO1                             0x0821
#define PCI_DEVICE_ID_INTEL_MFD_SDIO2                             0x0822
#define PCI_DEVICE_ID_INTEL_MFD_EMMC0                             0x0823
#define PCI_DEVICE_ID_INTEL_MFD_EMMC1                             0x0824
#define PCI_DEVICE_ID_INTEL_MRST_SD2                              0x084f
#define PCI_DEVICE_ID_INTEL_QUARK_X1000_ILB                       0x095e
#define PCI_DEVICE_ID_INTEL_I960                                  0x0960
#define PCI_DEVICE_ID_INTEL_I960RM                                0x0962
#define PCI_DEVICE_ID_INTEL_CENTERTON_ILB                         0x0c60
#define PCI_DEVICE_ID_INTEL_8257X_SOL                             0x1062
#define PCI_DEVICE_ID_INTEL_82573E_SOL                            0x1085
#define PCI_DEVICE_ID_INTEL_82573L_SOL                            0x108f
#define PCI_DEVICE_ID_INTEL_82815_MC                              0x1130
#define PCI_DEVICE_ID_INTEL_82815_CGC                             0x1132
#define PCI_DEVICE_ID_INTEL_82092AA_0                             0x1221
#define PCI_DEVICE_ID_INTEL_7505_0                                0x2550
#define PCI_DEVICE_ID_INTEL_7205_0                                0x255d
#define PCI_DEVICE_ID_INTEL_82437                                 0x122d
#define PCI_DEVICE_ID_INTEL_82371FB_0                             0x122e
#define PCI_DEVICE_ID_INTEL_82371FB_1                             0x1230
#define PCI_DEVICE_ID_INTEL_82371MX                               0x1234
#define PCI_DEVICE_ID_INTEL_82441                                 0x1237
#define PCI_DEVICE_ID_INTEL_82380FB                               0x124b
#define PCI_DEVICE_ID_INTEL_82439                                 0x1250
#define PCI_DEVICE_ID_INTEL_LIGHT_RIDGE                           0x1513 /* Tbt 1 Gen 1 */
#define PCI_DEVICE_ID_INTEL_EAGLE_RIDGE                           0x151a
#define PCI_DEVICE_ID_INTEL_LIGHT_PEAK                            0x151b
#define PCI_DEVICE_ID_INTEL_CACTUS_RIDGE_4C                       0x1547 /* Tbt 1 Gen 2 */
#define PCI_DEVICE_ID_INTEL_CACTUS_RIDGE_2C                       0x1548
#define PCI_DEVICE_ID_INTEL_PORT_RIDGE                            0x1549
#define PCI_DEVICE_ID_INTEL_REDWOOD_RIDGE_2C_NHI                  0x1566 /* Tbt 1 Gen 3 */
#define PCI_DEVICE_ID_INTEL_REDWOOD_RIDGE_2C_BRIDGE               0x1567
#define PCI_DEVICE_ID_INTEL_REDWOOD_RIDGE_4C_NHI                  0x1568
#define PCI_DEVICE_ID_INTEL_REDWOOD_RIDGE_4C_BRIDGE               0x1569
#define PCI_DEVICE_ID_INTEL_FALCON_RIDGE_2C_NHI                   0x156a /* Thunderbolt 2 */
#define PCI_DEVICE_ID_INTEL_FALCON_RIDGE_2C_BRIDGE                0x156b
#define PCI_DEVICE_ID_INTEL_FALCON_RIDGE_4C_NHI                   0x156c
#define PCI_DEVICE_ID_INTEL_FALCON_RIDGE_4C_BRIDGE                0x156d
#define PCI_DEVICE_ID_INTEL_ALPINE_RIDGE_2C_NHI                   0x1575 /* Thunderbolt 3 */
#define PCI_DEVICE_ID_INTEL_ALPINE_RIDGE_2C_BRIDGE                0x1576
#define PCI_DEVICE_ID_INTEL_ALPINE_RIDGE_4C_NHI                   0x1577
#define PCI_DEVICE_ID_INTEL_ALPINE_RIDGE_4C_BRIDGE                0x1578
#define PCI_DEVICE_ID_INTEL_80960_RP                              0x1960
#define PCI_DEVICE_ID_INTEL_82840_HB                              0x1a21
#define PCI_DEVICE_ID_INTEL_82845_HB                              0x1a30
#define PCI_DEVICE_ID_INTEL_IOAT                                  0x1a38
#define PCI_DEVICE_ID_INTEL_COUGARPOINT_LPC_MIN                   0x1c41
#define PCI_DEVICE_ID_INTEL_COUGARPOINT_LPC_MAX                   0x1c5f
#define PCI_DEVICE_ID_INTEL_PATSBURG_LPC_0                        0x1d40
#define PCI_DEVICE_ID_INTEL_PATSBURG_LPC_1                        0x1d41
#define PCI_DEVICE_ID_INTEL_PANTHERPOINT_XHCI                     0x1e31
#define PCI_DEVICE_ID_INTEL_PANTHERPOINT_LPC_MIN                  0x1e40
#define PCI_DEVICE_ID_INTEL_PANTHERPOINT_LPC_MAX                  0x1e5f
#define PCI_DEVICE_ID_INTEL_VMD_201D                              0x201d
#define PCI_DEVICE_ID_INTEL_DH89XXCC_LPC_MIN                      0x2310
#define PCI_DEVICE_ID_INTEL_DH89XXCC_LPC_MAX                      0x231f
#define PCI_DEVICE_ID_INTEL_82801AA_0                             0x2410
#define PCI_DEVICE_ID_INTEL_82801AA_1                             0x2411
#define PCI_DEVICE_ID_INTEL_82801AA_3                             0x2413
#define PCI_DEVICE_ID_INTEL_82801AA_5                             0x2415
#define PCI_DEVICE_ID_INTEL_82801AA_6                             0x2416
#define PCI_DEVICE_ID_INTEL_82801AA_8                             0x2418
#define PCI_DEVICE_ID_INTEL_82801AB_0                             0x2420
#define PCI_DEVICE_ID_INTEL_82801AB_1                             0x2421
#define PCI_DEVICE_ID_INTEL_82801AB_3                             0x2423
#define PCI_DEVICE_ID_INTEL_82801AB_5                             0x2425
#define PCI_DEVICE_ID_INTEL_82801AB_6                             0x2426
#define PCI_DEVICE_ID_INTEL_82801AB_8                             0x2428
#define PCI_DEVICE_ID_INTEL_82801BA_0                             0x2440
#define PCI_DEVICE_ID_INTEL_82801BA_2                             0x2443
#define PCI_DEVICE_ID_INTEL_82801BA_4                             0x2445
#define PCI_DEVICE_ID_INTEL_82801BA_6                             0x2448
#define PCI_DEVICE_ID_INTEL_82801BA_8                             0x244a
#define PCI_DEVICE_ID_INTEL_82801BA_9                             0x244b
#define PCI_DEVICE_ID_INTEL_82801BA_10                            0x244c
#define PCI_DEVICE_ID_INTEL_82801BA_11                            0x244e
#define PCI_DEVICE_ID_INTEL_82801E_0                              0x2450
#define PCI_DEVICE_ID_INTEL_82801E_11                             0x245b
#define PCI_DEVICE_ID_INTEL_82801CA_0                             0x2480
#define PCI_DEVICE_ID_INTEL_82801CA_3                             0x2483
#define PCI_DEVICE_ID_INTEL_82801CA_5                             0x2485
#define PCI_DEVICE_ID_INTEL_82801CA_6                             0x2486
#define PCI_DEVICE_ID_INTEL_82801CA_10                            0x248a
#define PCI_DEVICE_ID_INTEL_82801CA_11                            0x248b
#define PCI_DEVICE_ID_INTEL_82801CA_12                            0x248c
#define PCI_DEVICE_ID_INTEL_82801DB_0                             0x24c0
#define PCI_DEVICE_ID_INTEL_82801DB_1                             0x24c1
#define PCI_DEVICE_ID_INTEL_82801DB_2                             0x24c2
#define PCI_DEVICE_ID_INTEL_82801DB_3                             0x24c3
#define PCI_DEVICE_ID_INTEL_82801DB_5                             0x24c5
#define PCI_DEVICE_ID_INTEL_82801DB_6                             0x24c6
#define PCI_DEVICE_ID_INTEL_82801DB_9                             0x24c9
#define PCI_DEVICE_ID_INTEL_82801DB_10                            0x24ca
#define PCI_DEVICE_ID_INTEL_82801DB_11                            0x24cb
#define PCI_DEVICE_ID_INTEL_82801DB_12                            0x24cc
#define PCI_DEVICE_ID_INTEL_82801EB_0                             0x24d0
#define PCI_DEVICE_ID_INTEL_82801EB_1                             0x24d1
#define PCI_DEVICE_ID_INTEL_82801EB_3                             0x24d3
#define PCI_DEVICE_ID_INTEL_82801EB_5                             0x24d5
#define PCI_DEVICE_ID_INTEL_82801EB_6                             0x24d6
#define PCI_DEVICE_ID_INTEL_82801EB_11                            0x24db
#define PCI_DEVICE_ID_INTEL_82801EB_12                            0x24dc
#define PCI_DEVICE_ID_INTEL_82801EB_13                            0x24dd
#define PCI_DEVICE_ID_INTEL_ESB_1                                 0x25a1
#define PCI_DEVICE_ID_INTEL_ESB_2                                 0x25a2
#define PCI_DEVICE_ID_INTEL_ESB_4                                 0x25a4
#define PCI_DEVICE_ID_INTEL_ESB_5                                 0x25a6
#define PCI_DEVICE_ID_INTEL_ESB_9                                 0x25ab
#define PCI_DEVICE_ID_INTEL_ESB_10                                0x25ac
#define PCI_DEVICE_ID_INTEL_82820_HB                              0x2500
#define PCI_DEVICE_ID_INTEL_82820_UP_HB                           0x2501
#define PCI_DEVICE_ID_INTEL_82850_HB                              0x2530
#define PCI_DEVICE_ID_INTEL_82860_HB                              0x2531
#define PCI_DEVICE_ID_INTEL_E7501_MCH                             0x254c
#define PCI_DEVICE_ID_INTEL_82845G_HB                             0x2560
#define PCI_DEVICE_ID_INTEL_82845G_IG                             0x2562
#define PCI_DEVICE_ID_INTEL_82865_HB                              0x2570
#define PCI_DEVICE_ID_INTEL_82865_IG                              0x2572
#define PCI_DEVICE_ID_INTEL_82875_HB                              0x2578
#define PCI_DEVICE_ID_INTEL_82915G_HB                             0x2580
#define PCI_DEVICE_ID_INTEL_82915G_IG                             0x2582
#define PCI_DEVICE_ID_INTEL_82915GM_HB                            0x2590
#define PCI_DEVICE_ID_INTEL_82915GM_IG                            0x2592
#define PCI_DEVICE_ID_INTEL_5000_ERR                              0x25f0
#define PCI_DEVICE_ID_INTEL_5000_FBD0                             0x25f5
#define PCI_DEVICE_ID_INTEL_5000_FBD1                             0x25f6
#define PCI_DEVICE_ID_INTEL_82945G_HB                             0x2770
#define PCI_DEVICE_ID_INTEL_82945G_IG                             0x2772
#define PCI_DEVICE_ID_INTEL_3000_HB                               0x2778
#define PCI_DEVICE_ID_INTEL_82945GM_HB                            0x27a0
#define PCI_DEVICE_ID_INTEL_82945GM_IG                            0x27a2
#define PCI_DEVICE_ID_INTEL_ICH6_0                                0x2640
#define PCI_DEVICE_ID_INTEL_ICH6_1                                0x2641
#define PCI_DEVICE_ID_INTEL_ICH6_2                                0x2642
#define PCI_DEVICE_ID_INTEL_ICH6_16                               0x266a
#define PCI_DEVICE_ID_INTEL_ICH6_17                               0x266d
#define PCI_DEVICE_ID_INTEL_ICH6_18                               0x266e
#define PCI_DEVICE_ID_INTEL_ICH6_19                               0x266f
#define PCI_DEVICE_ID_INTEL_ESB2_0                                0x2670
#define PCI_DEVICE_ID_INTEL_ESB2_14                               0x2698
#define PCI_DEVICE_ID_INTEL_ESB2_17                               0x269b
#define PCI_DEVICE_ID_INTEL_ESB2_18                               0x269e
#define PCI_DEVICE_ID_INTEL_ICH7_0                                0x27b8
#define PCI_DEVICE_ID_INTEL_ICH7_1                                0x27b9
#define PCI_DEVICE_ID_INTEL_ICH7_30                               0x27b0
#define PCI_DEVICE_ID_INTEL_TGP_LPC                               0x27bc
#define PCI_DEVICE_ID_INTEL_ICH7_31                               0x27bd
#define PCI_DEVICE_ID_INTEL_ICH7_17                               0x27da
#define PCI_DEVICE_ID_INTEL_ICH7_19                               0x27dd
#define PCI_DEVICE_ID_INTEL_ICH7_20                               0x27de
#define PCI_DEVICE_ID_INTEL_ICH7_21                               0x27df
#define PCI_DEVICE_ID_INTEL_ICH8_0                                0x2810
#define PCI_DEVICE_ID_INTEL_ICH8_1                                0x2811
#define PCI_DEVICE_ID_INTEL_ICH8_2                                0x2812
#define PCI_DEVICE_ID_INTEL_ICH8_3                                0x2814
#define PCI_DEVICE_ID_INTEL_ICH8_4                                0x2815
#define PCI_DEVICE_ID_INTEL_ICH8_5                                0x283e
#define PCI_DEVICE_ID_INTEL_ICH8_6                                0x2850
#define PCI_DEVICE_ID_INTEL_VMD_28C0                              0x28c0
#define PCI_DEVICE_ID_INTEL_ICH9_0                                0x2910
#define PCI_DEVICE_ID_INTEL_ICH9_1                                0x2917
#define PCI_DEVICE_ID_INTEL_ICH9_2                                0x2912
#define PCI_DEVICE_ID_INTEL_ICH9_3                                0x2913
#define PCI_DEVICE_ID_INTEL_ICH9_4                                0x2914
#define PCI_DEVICE_ID_INTEL_ICH9_5                                0x2919
#define PCI_DEVICE_ID_INTEL_ICH9_6                                0x2930
#define PCI_DEVICE_ID_INTEL_ICH9_7                                0x2916
#define PCI_DEVICE_ID_INTEL_ICH9_8                                0x2918
#define PCI_DEVICE_ID_INTEL_I7_MCR                                0x2c18
#define PCI_DEVICE_ID_INTEL_I7_MC_TAD                             0x2c19
#define PCI_DEVICE_ID_INTEL_I7_MC_RAS                             0x2c1a
#define PCI_DEVICE_ID_INTEL_I7_MC_TEST                            0x2c1c
#define PCI_DEVICE_ID_INTEL_I7_MC_CH0_CTRL                        0x2c20
#define PCI_DEVICE_ID_INTEL_I7_MC_CH0_ADDR                        0x2c21
#define PCI_DEVICE_ID_INTEL_I7_MC_CH0_RANK                        0x2c22
#define PCI_DEVICE_ID_INTEL_I7_MC_CH0_TC                          0x2c23
#define PCI_DEVICE_ID_INTEL_I7_MC_CH1_CTRL                        0x2c28
#define PCI_DEVICE_ID_INTEL_I7_MC_CH1_ADDR                        0x2c29
#define PCI_DEVICE_ID_INTEL_I7_MC_CH1_RANK                        0x2c2a
#define PCI_DEVICE_ID_INTEL_I7_MC_CH1_TC                          0x2c2b
#define PCI_DEVICE_ID_INTEL_I7_MC_CH2_CTRL                        0x2c30
#define PCI_DEVICE_ID_INTEL_I7_MC_CH2_ADDR                        0x2c31
#define PCI_DEVICE_ID_INTEL_I7_MC_CH2_RANK                        0x2c32
#define PCI_DEVICE_ID_INTEL_I7_MC_CH2_TC                          0x2c33
#define PCI_DEVICE_ID_INTEL_I7_NONCORE                            0x2c41
#define PCI_DEVICE_ID_INTEL_I7_NONCORE_ALT                        0x2c40
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_NONCORE                     0x2c50
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_NONCORE_ALT                 0x2c51
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_NONCORE_REV2                0x2c70
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_SAD                         0x2c81
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_QPI_LINK0                   0x2c90
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_QPI_PHY0                    0x2c91
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MCR                         0x2c98
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_TAD                      0x2c99
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_TEST                     0x2c9c
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH0_CTRL                 0x2ca0
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH0_ADDR                 0x2ca1
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH0_RANK                 0x2ca2
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH0_TC                   0x2ca3
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH1_CTRL                 0x2ca8
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH1_ADDR                 0x2ca9
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH1_RANK                 0x2caa
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH1_TC                   0x2cab
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MCR_REV2                    0x2d98
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_TAD_REV2                 0x2d99
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_RAS_REV2                 0x2d9a
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_TEST_REV2                0x2d9c
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH0_CTRL_REV2            0x2da0
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH0_ADDR_REV2            0x2da1
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH0_RANK_REV2            0x2da2
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH0_TC_REV2              0x2da3
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH1_CTRL_REV2            0x2da8
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH1_ADDR_REV2            0x2da9
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH1_RANK_REV2            0x2daa
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH1_TC_REV2              0x2dab
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH2_CTRL_REV2            0x2db0
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH2_ADDR_REV2            0x2db1
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH2_RANK_REV2            0x2db2
#define PCI_DEVICE_ID_INTEL_LYNNFIELD_MC_CH2_TC_REV2              0x2db3
#define PCI_DEVICE_ID_INTEL_82855PM_HB                            0x3340
#define PCI_DEVICE_ID_INTEL_IOAT_TBG4                             0x3429
#define PCI_DEVICE_ID_INTEL_IOAT_TBG5                             0x342a
#define PCI_DEVICE_ID_INTEL_IOAT_TBG6                             0x342b
#define PCI_DEVICE_ID_INTEL_IOAT_TBG7                             0x342c
#define PCI_DEVICE_ID_INTEL_X58_HUB_MGMT                          0x342e
#define PCI_DEVICE_ID_INTEL_IOAT_TBG0                             0x3430
#define PCI_DEVICE_ID_INTEL_IOAT_TBG1                             0x3431
#define PCI_DEVICE_ID_INTEL_IOAT_TBG2                             0x3432
#define PCI_DEVICE_ID_INTEL_IOAT_TBG3                             0x3433
#define PCI_DEVICE_ID_INTEL_82830_HB                              0x3575
#define PCI_DEVICE_ID_INTEL_82830_CGC                             0x3577
#define PCI_DEVICE_ID_INTEL_82854_HB                              0x358c
#define PCI_DEVICE_ID_INTEL_82854_IG                              0x358e
#define PCI_DEVICE_ID_INTEL_82855GM_HB                            0x3580
#define PCI_DEVICE_ID_INTEL_82855GM_IG                            0x3582
#define PCI_DEVICE_ID_INTEL_E7520_MCH                             0x3590
#define PCI_DEVICE_ID_INTEL_E7320_MCH                             0x3592
#define PCI_DEVICE_ID_INTEL_MCH_PA                                0x3595
#define PCI_DEVICE_ID_INTEL_MCH_PA1                               0x3596
#define PCI_DEVICE_ID_INTEL_MCH_PB                                0x3597
#define PCI_DEVICE_ID_INTEL_MCH_PB1                               0x3598
#define PCI_DEVICE_ID_INTEL_MCH_PC                                0x3599
#define PCI_DEVICE_ID_INTEL_MCH_PC1                               0x359a
#define PCI_DEVICE_ID_INTEL_E7525_MCH                             0x359e
#define PCI_DEVICE_ID_INTEL_I7300_MCH_ERR                         0x360c
#define PCI_DEVICE_ID_INTEL_I7300_MCH_FB0                         0x360f
#define PCI_DEVICE_ID_INTEL_I7300_MCH_FB1                         0x3610
#define PCI_DEVICE_ID_INTEL_IOAT_CNB                              0x360b
#define PCI_DEVICE_ID_INTEL_FBD_CNB                               0x360c
#define PCI_DEVICE_ID_INTEL_IOAT_JSF0                             0x3710
#define PCI_DEVICE_ID_INTEL_IOAT_JSF1                             0x3711
#define PCI_DEVICE_ID_INTEL_IOAT_JSF2                             0x3712
#define PCI_DEVICE_ID_INTEL_IOAT_JSF3                             0x3713
#define PCI_DEVICE_ID_INTEL_IOAT_JSF4                             0x3714
#define PCI_DEVICE_ID_INTEL_IOAT_JSF5                             0x3715
#define PCI_DEVICE_ID_INTEL_IOAT_JSF6                             0x3716
#define PCI_DEVICE_ID_INTEL_IOAT_JSF7                             0x3717
#define PCI_DEVICE_ID_INTEL_IOAT_JSF8                             0x3718
#define PCI_DEVICE_ID_INTEL_IOAT_JSF9                             0x3719
#define PCI_DEVICE_ID_INTEL_ICH10_0                               0x3a14
#define PCI_DEVICE_ID_INTEL_ICH10_1                               0x3a16
#define PCI_DEVICE_ID_INTEL_ICH10_2                               0x3a18
#define PCI_DEVICE_ID_INTEL_ICH10_3                               0x3a1a
#define PCI_DEVICE_ID_INTEL_ICH10_4                               0x3a30
#define PCI_DEVICE_ID_INTEL_ICH10_5                               0x3a60
#define PCI_DEVICE_ID_INTEL_5_3400_SERIES_LPC_MIN                 0x3b00
#define PCI_DEVICE_ID_INTEL_5_3400_SERIES_LPC_MAX                 0x3b1f
#define PCI_DEVICE_ID_INTEL_IOAT_SNB0                             0x3c20
#define PCI_DEVICE_ID_INTEL_IOAT_SNB1                             0x3c21
#define PCI_DEVICE_ID_INTEL_IOAT_SNB2                             0x3c22
#define PCI_DEVICE_ID_INTEL_IOAT_SNB3                             0x3c23
#define PCI_DEVICE_ID_INTEL_IOAT_SNB4                             0x3c24
#define PCI_DEVICE_ID_INTEL_IOAT_SNB5                             0x3c25
#define PCI_DEVICE_ID_INTEL_IOAT_SNB6                             0x3c26
#define PCI_DEVICE_ID_INTEL_IOAT_SNB7                             0x3c27
#define PCI_DEVICE_ID_INTEL_IOAT_SNB8                             0x3c2e
#define PCI_DEVICE_ID_INTEL_IOAT_SNB9                             0x3c2f
#define PCI_DEVICE_ID_INTEL_UNC_HA                                0x3c46
#define PCI_DEVICE_ID_INTEL_UNC_IMC0                              0x3cb0
#define PCI_DEVICE_ID_INTEL_UNC_IMC1                              0x3cb1
#define PCI_DEVICE_ID_INTEL_UNC_IMC2                              0x3cb4
#define PCI_DEVICE_ID_INTEL_UNC_IMC3                              0x3cb5
#define PCI_DEVICE_ID_INTEL_UNC_QPI0                              0x3c41
#define PCI_DEVICE_ID_INTEL_UNC_QPI1                              0x3c42
#define PCI_DEVICE_ID_INTEL_UNC_R2PCIE                            0x3c43
#define PCI_DEVICE_ID_INTEL_UNC_R3QPI0                            0x3c44
#define PCI_DEVICE_ID_INTEL_UNC_R3QPI1                            0x3c45
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_RAS                       0x3c71 /* 15.1 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_ERR0                      0x3c72 /* 16.2 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_ERR1                      0x3c73 /* 16.3 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_ERR2                      0x3c76 /* 16.6 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_ERR3                      0x3c77 /* 16.7 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_HA0                       0x3ca0 /* 14.0 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TA                        0x3ca8 /* 15.0 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TAD0                      0x3caa /* 15.2 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TAD1                      0x3cab /* 15.3 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TAD2                      0x3cac /* 15.4 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_TAD3                      0x3cad /* 15.5 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_IMC_DDRIO                     0x3cb8 /* 17.0 */
#define PCI_DEVICE_ID_INTEL_JAKETOWN_UBOX                         0x3ce0
#define PCI_DEVICE_ID_INTEL_SBRIDGE_SAD0                          0x3cf4 /* 12.6 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_BR                            0x3cf5 /* 13.6 */
#define PCI_DEVICE_ID_INTEL_SBRIDGE_SAD1                          0x3cf6 /* 12.7 */
#define PCI_DEVICE_ID_INTEL_IOAT_SNB                              0x402f
#define PCI_DEVICE_ID_INTEL_5100_16                               0x65f0
#define PCI_DEVICE_ID_INTEL_5100_19                               0x65f3
#define PCI_DEVICE_ID_INTEL_5100_21                               0x65f5
#define PCI_DEVICE_ID_INTEL_5100_22                               0x65f6
#define PCI_DEVICE_ID_INTEL_5400_ERR                              0x4030
#define PCI_DEVICE_ID_INTEL_5400_FBD0                             0x4035
#define PCI_DEVICE_ID_INTEL_5400_FBD1                             0x4036
#define PCI_DEVICE_ID_INTEL_IOAT_SCNB                             0x65ff
#define PCI_DEVICE_ID_INTEL_EP80579_0                             0x5031
#define PCI_DEVICE_ID_INTEL_EP80579_1                             0x5032
#define PCI_DEVICE_ID_INTEL_82371SB_0                             0x7000
#define PCI_DEVICE_ID_INTEL_82371SB_1                             0x7010
#define PCI_DEVICE_ID_INTEL_82371SB_2                             0x7020
#define PCI_DEVICE_ID_INTEL_82437VX                               0x7030
#define PCI_DEVICE_ID_INTEL_82439TX                               0x7100
#define PCI_DEVICE_ID_INTEL_82371AB_0                             0x7110
#define PCI_DEVICE_ID_INTEL_82371AB                               0x7111
#define PCI_DEVICE_ID_INTEL_82371AB_2                             0x7112
#define PCI_DEVICE_ID_INTEL_82371AB_3                             0x7113
#define PCI_DEVICE_ID_INTEL_82810_MC1                             0x7120
#define PCI_DEVICE_ID_INTEL_82810_IG1                             0x7121
#define PCI_DEVICE_ID_INTEL_82810_MC3                             0x7122
#define PCI_DEVICE_ID_INTEL_82810_IG3                             0x7123
#define PCI_DEVICE_ID_INTEL_82810E_MC                             0x7124
#define PCI_DEVICE_ID_INTEL_82810E_IG                             0x7125
#define PCI_DEVICE_ID_INTEL_82443LX_0                             0x7180
#define PCI_DEVICE_ID_INTEL_82443LX_1                             0x7181
#define PCI_DEVICE_ID_INTEL_82443BX_0                             0x7190
#define PCI_DEVICE_ID_INTEL_82443BX_1                             0x7191
#define PCI_DEVICE_ID_INTEL_82443BX_2                             0x7192
#define PCI_DEVICE_ID_INTEL_440MX                                 0x7195
#define PCI_DEVICE_ID_INTEL_440MX_6                               0x7196
#define PCI_DEVICE_ID_INTEL_82443MX_0                             0x7198
#define PCI_DEVICE_ID_INTEL_82443MX_1                             0x7199
#define PCI_DEVICE_ID_INTEL_82443MX_3                             0x719b
#define PCI_DEVICE_ID_INTEL_82443GX_0                             0x71a0
#define PCI_DEVICE_ID_INTEL_82443GX_2                             0x71a2
#define PCI_DEVICE_ID_INTEL_82372FB_1                             0x7601
#define PCI_DEVICE_ID_INTEL_SCH_LPC                               0x8119
#define PCI_DEVICE_ID_INTEL_SCH_IDE                               0x811a
#define PCI_DEVICE_ID_INTEL_E6XX_CU                               0x8183
#define PCI_DEVICE_ID_INTEL_ITC_LPC                               0x8186
#define PCI_DEVICE_ID_INTEL_82454GX                               0x84c4
#define PCI_DEVICE_ID_INTEL_82450GX                               0x84c5
#define PCI_DEVICE_ID_INTEL_82451NX                               0x84ca
#define PCI_DEVICE_ID_INTEL_82454NX                               0x84cb
#define PCI_DEVICE_ID_INTEL_84460GX                               0x84ea
#define PCI_DEVICE_ID_INTEL_IXP4XX                                0x8500
#define PCI_DEVICE_ID_INTEL_IXP2800                               0x9004
#define PCI_DEVICE_ID_INTEL_S21152BB                              0xb152

#define PCI_VENDOR_ID_SCALEMP                                     0x8686
#define PCI_DEVICE_ID_SCALEMP_VSMP_CTL                            0x1010

#define PCI_VENDOR_ID_COMPUTONE                                   0x8e0e
#define PCI_DEVICE_ID_COMPUTONE_PG                                0x0302
#define PCI_SUBVENDOR_ID_COMPUTONE                                0x8e0e
#define PCI_SUBDEVICE_ID_COMPUTONE_PG4                            0x0001
#define PCI_SUBDEVICE_ID_COMPUTONE_PG8                            0x0002
#define PCI_SUBDEVICE_ID_COMPUTONE_PG6                            0x0003

#define PCI_VENDOR_ID_KTI                                         0x8e2e

#define PCI_VENDOR_ID_ADAPTEC                                     0x9004
#define PCI_DEVICE_ID_ADAPTEC_7810                                0x1078
#define PCI_DEVICE_ID_ADAPTEC_7821                                0x2178
#define PCI_DEVICE_ID_ADAPTEC_38602                               0x3860
#define PCI_DEVICE_ID_ADAPTEC_7850                                0x5078
#define PCI_DEVICE_ID_ADAPTEC_7855                                0x5578
#define PCI_DEVICE_ID_ADAPTEC_3860                                0x6038
#define PCI_DEVICE_ID_ADAPTEC_1480A                               0x6075
#define PCI_DEVICE_ID_ADAPTEC_7860                                0x6078
#define PCI_DEVICE_ID_ADAPTEC_7861                                0x6178
#define PCI_DEVICE_ID_ADAPTEC_7870                                0x7078
#define PCI_DEVICE_ID_ADAPTEC_7871                                0x7178
#define PCI_DEVICE_ID_ADAPTEC_7872                                0x7278
#define PCI_DEVICE_ID_ADAPTEC_7873                                0x7378
#define PCI_DEVICE_ID_ADAPTEC_7874                                0x7478
#define PCI_DEVICE_ID_ADAPTEC_7895                                0x7895
#define PCI_DEVICE_ID_ADAPTEC_7880                                0x8078
#define PCI_DEVICE_ID_ADAPTEC_7881                                0x8178
#define PCI_DEVICE_ID_ADAPTEC_7882                                0x8278
#define PCI_DEVICE_ID_ADAPTEC_7883                                0x8378
#define PCI_DEVICE_ID_ADAPTEC_7884                                0x8478
#define PCI_DEVICE_ID_ADAPTEC_7885                                0x8578
#define PCI_DEVICE_ID_ADAPTEC_7886                                0x8678
#define PCI_DEVICE_ID_ADAPTEC_7887                                0x8778
#define PCI_DEVICE_ID_ADAPTEC_7888                                0x8878

#define PCI_VENDOR_ID_ADAPTEC2                                    0x9005
#define PCI_DEVICE_ID_ADAPTEC2_2940U2                             0x0010
#define PCI_DEVICE_ID_ADAPTEC2_2930U2                             0x0011
#define PCI_DEVICE_ID_ADAPTEC2_7890B                              0x0013
#define PCI_DEVICE_ID_ADAPTEC2_7890                               0x001f
#define PCI_DEVICE_ID_ADAPTEC2_3940U2                             0x0050
#define PCI_DEVICE_ID_ADAPTEC2_3950U2D                            0x0051
#define PCI_DEVICE_ID_ADAPTEC2_7896                               0x005f
#define PCI_DEVICE_ID_ADAPTEC2_7892A                              0x0080
#define PCI_DEVICE_ID_ADAPTEC2_7892B                              0x0081
#define PCI_DEVICE_ID_ADAPTEC2_7892D                              0x0083
#define PCI_DEVICE_ID_ADAPTEC2_7892P                              0x008f
#define PCI_DEVICE_ID_ADAPTEC2_7899A                              0x00c0
#define PCI_DEVICE_ID_ADAPTEC2_7899B                              0x00c1
#define PCI_DEVICE_ID_ADAPTEC2_7899D                              0x00c3
#define PCI_DEVICE_ID_ADAPTEC2_7899P                              0x00cf
#define PCI_DEVICE_ID_ADAPTEC2_OBSIDIAN                           0x0500
#define PCI_DEVICE_ID_ADAPTEC2_SCAMP                              0x0503

#define PCI_VENDOR_ID_HOLTEK                                      0x9412
#define PCI_DEVICE_ID_HOLTEK_6565                                 0x6565

#define PCI_VENDOR_ID_NETMOS                                      0x9710
#define PCI_DEVICE_ID_NETMOS_9705                                 0x9705
#define PCI_DEVICE_ID_NETMOS_9715                                 0x9715
#define PCI_DEVICE_ID_NETMOS_9735                                 0x9735
#define PCI_DEVICE_ID_NETMOS_9745                                 0x9745
#define PCI_DEVICE_ID_NETMOS_9755                                 0x9755
#define PCI_DEVICE_ID_NETMOS_9805                                 0x9805
#define PCI_DEVICE_ID_NETMOS_9815                                 0x9815
#define PCI_DEVICE_ID_NETMOS_9835                                 0x9835
#define PCI_DEVICE_ID_NETMOS_9845                                 0x9845
#define PCI_DEVICE_ID_NETMOS_9855                                 0x9855
#define PCI_DEVICE_ID_NETMOS_9865                                 0x9865
#define PCI_DEVICE_ID_NETMOS_9900                                 0x9900
#define PCI_DEVICE_ID_NETMOS_9901                                 0x9901
#define PCI_DEVICE_ID_NETMOS_9904                                 0x9904
#define PCI_DEVICE_ID_NETMOS_9912                                 0x9912
#define PCI_DEVICE_ID_NETMOS_9922                                 0x9922

#define PCI_VENDOR_ID_3COM_2                                      0xa727

#define PCI_VENDOR_ID_DIGIUM                                      0xd161
#define PCI_DEVICE_ID_DIGIUM_HFC4S                                0xb410

#define PCI_SUBVENDOR_ID_EXSYS                                    0xd84d
#define PCI_SUBDEVICE_ID_EXSYS_4014                               0x4014
#define PCI_SUBDEVICE_ID_EXSYS_4055                               0x4055

#define PCI_VENDOR_ID_TIGERJET                                    0xe159
#define PCI_DEVICE_ID_TIGERJET_300                                0x0001
#define PCI_DEVICE_ID_TIGERJET_100                                0x0002

#define PCI_VENDOR_ID_XILINX_RME                                  0xea60
#define PCI_DEVICE_ID_RME_DIGI32                                  0x9896
#define PCI_DEVICE_ID_RME_DIGI32_PRO                              0x9897
#define PCI_DEVICE_ID_RME_DIGI32_8                                0x9898

#define PCI_VENDOR_ID_XEN                                         0x5853
#define PCI_DEVICE_ID_XEN_PLATFORM                                0x0001

#define PCI_VENDOR_ID_OCZ                                         0x1b85

#define PCI_VENDOR_ID_NCUBE                                       0x10ff

#endif /* __INCLUDE_NUTTX_PCI_PCI_IDS_H */
