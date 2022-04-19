/****************************************************************************
 * arch/arm/src/cxd56xx/hardware/cxd5602_isop_hadc0_highspeed.h
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

/* This file is generated at Mar 27 2020 12:00:17 */

/****************************************************************************
 * Public Data
 ****************************************************************************/

const unsigned long scu_isopprog_array[] =
{
  0xf7f8d600, 0xa2024f86, 0x0001a200, 0x18004081,
  0x00008014, 0x00000000, 0x0000a207, 0x00000000,
  0x0000a070, 0xac2d4ec6, 0xd000ac27, 0x50a2e444,
  0x70111801, 0x50011c01, 0xf350d000, 0x0004800a,
  0x40110114, 0x50031f43, 0x9ff42801, 0x90062911,
  0x8fec5043, 0x00140003, 0x40640113, 0x1f344011,
  0x9fe42121, 0xd2005001, 0x5203f35a, 0x50155004,
  0x04150845, 0x90082905, 0x2d444014, 0x00259ff2,
  0x40110115, 0x21311f54, 0xd1009fe4, 0x5ff2e824,
  0xe808d400, 0x01f8fc43, 0x07fffc33, 0xe804d000,
  0xf000d700, 0x1c431c12, 0xe800d100, 0x1c025013,
  0x0103fc40, 0x0300fc30, 0xf3dcd200, 0x1c135be4,
  0xe418d100, 0x1c105003, 0xf47250a1, 0x1c230300,
  0x0004f721, 0xf7235e61, 0xf7230005, 0xf7230016,
  0x00250017, 0x4fc10215, 0xf7531d53, 0xf753fffe,
  0x2141ffff, 0xd1009fee, 0xd209f340, 0xd000ec00,
  0x5004f4bc, 0x1c125005, 0x0304f470, 0x44020002,
  0x0308f472, 0x41a10001, 0x00020053, 0x106350a7,
  0x1c240132, 0x0004f727, 0x0005f724, 0x0016f724,
  0x0017f724, 0x1d340013, 0xfffef734, 0xfffff734,
  0x40434ff7, 0x9ff02907, 0x44014015, 0x9fca2925,
  0xd3005001, 0x5004f344, 0xf39cd200, 0x01150035,
  0x1f544011, 0x9ff62941, 0xd4005fe3, 0x5005f348,
  0x00415f67, 0x4fc30231, 0xfffef512, 0x1f154202,
  0x9ff02173, 0xf334d200, 0xf000d100, 0xd4005003,
  0x5005f53c, 0x030cf412, 0xac115001, 0xa819ac19,
  0x00470052, 0x00710112, 0x01211032, 0x00201c13,
  0x70407052, 0x1f450104, 0x00740070, 0xf350d700,
  0x01200157, 0x1e724015, 0xf7131f02, 0xa8110016,
  0x210550a0, 0x9fc44021, 0xf37ad000, 0x1000fc11,
  0x00345f02, 0x4ff30005, 0x21231014, 0x1d510245,
  0x50029ff2, 0xf334d000, 0xf000d700, 0xf45cd300,
  0x1d025004, 0xf332d000, 0x0310f470, 0x00350041,
  0x01151041, 0x0004f452, 0x0008f454, 0xf7524014,
  0xf752000c, 0x1c52000d, 0x9fe22964, 0xd2005001,
  0xfc43f330, 0xfc332020, 0x1f210327, 0x0001f721,
  0x5834d211, 0xf5711d01, 0xf77102fe, 0x1c7302fc,
  0xe412d000, 0x0004f472, 0xf4715012, 0x1f020008,
  0x0d66fa00, 0xa82da827, 0x41465000, 0x0000a070,
  0xac3d4e46, 0xf601ac37, 0x28010005, 0xf6029178,
  0xac200004, 0x10110021, 0xd100ac29, 0xa828f53c,
  0x10300120, 0x7050ac18, 0x1e150101, 0xfa000050,
  0x00500ddc, 0x29006fb0, 0x0050901a, 0xfa004010,
  0x00500dcc, 0xfa004020, 0x00500dc4, 0xfa004030,
  0xd1000dbc, 0x5010e000, 0x08501811, 0x28010401,
  0xac15906c, 0x0128fa00, 0x5003a822, 0xf6205005,
  0xa8110004, 0xfa004062, 0xa8230290, 0xf53cd400,
  0x91022900, 0x5021a818, 0xf334d700, 0x1c410104,
  0xf6305011, 0x1a720004, 0x05120801, 0xf6301d72,
  0xf7400005, 0x28000016, 0x500090dc, 0x00320041,
  0x01524010, 0xf6220151, 0xf7120006, 0x00050006,
  0x0005f632, 0x24256ff5, 0x80ba9fe4, 0xd100a822,
  0xf620e404, 0x18110004, 0x28016201, 0xd3009028,
  0x6ff0f330, 0x0001f631, 0x90222101, 0x6ff01e30,
  0x901a2910, 0x0ccefa00, 0x5030a822, 0xf330d100,
  0x800a1f10, 0xf330d000, 0x1f015001, 0x0004f620,
  0xf000d100, 0x01011050, 0x0005f620, 0x0024f213,
  0xac1b2800, 0x0024f211, 0x905a0050, 0xac100015,
  0x03b2fa00, 0x0053a814, 0x904a2910, 0x60f31243,
  0x61f34013, 0x903e2803, 0x5002a818, 0x60f05001,
  0x0030ac18, 0x00470043, 0xf41cd400, 0x10234011,
  0xf2430134, 0x1a440002, 0x0152a81d, 0x0125a825,
  0x0006f652, 0x00741f42, 0x00031f32, 0x6ff20012,
  0x9fd02432, 0xa83da837, 0xa07041c6, 0xac4d4dc6,
  0xd000ac47, 0xfc41e400, 0x18000400, 0x28000410,
  0x5000915e, 0xf33cd100, 0x0e10ac18, 0xfc41ac10,
  0xd0000400, 0xac21e804, 0xd1001c01, 0x1810e080,
  0xe084d100, 0x00021811, 0xf76260f2, 0x00620018,
  0x0018fc02, 0x00040023, 0x13007022, 0x70131284,
  0x1f346034, 0xf5611d20, 0x1301001c, 0xe088d000,
  0xf5615012, 0x1c02001e, 0x0018f265, 0x6ff5ac2d,
  0xfa000050, 0xa82f02e0, 0xd100a812, 0x2910f41c,
  0x10259086, 0xf000d000, 0x12870013, 0x0100fc41,
  0x40170150, 0x0280f000, 0x04106ff7, 0x29005001,
  0x50009032, 0x28070023, 0x0062905e, 0x40101011,
  0x0018fc02, 0x0018f664, 0xf2210112, 0x10240002,
  0x2000fc34, 0x1d311d41, 0x6ff10001, 0x9fdc2471,
  0x50008036, 0x28070035, 0xf662902e, 0x00530018,
  0x40101011, 0x01231022, 0x0002f232, 0x00641a33,
  0x0018fc04, 0xf6410114, 0x1f310003, 0x00011f21,
  0x24716ff1, 0xd0009fd6, 0x1800e400, 0x0410a821,
  0x900c2800, 0x4010a818, 0x2c40ac18, 0xf6619f02,
  0x50000018, 0x90142c41, 0x4fc00010, 0x90062e30,
  0x80085010, 0x00fafc01, 0xd1000010, 0x1811e404,
  0x28016201, 0xd5009022, 0x6ff0f330, 0x0001f651,
  0x901c2101, 0x6ff01e50, 0x90142910, 0x0ad6fa00,
  0x1f505030, 0xd000800a, 0x5001f330, 0xa8471f01,
  0x4246a84d, 0x4e06a070, 0xac3fac45, 0xe400d300,
  0xfc431834, 0x04340200, 0x90322804, 0xd400ac21,
  0x1841e404, 0x28016201, 0xd1009032, 0xf614f330,
  0x21040001, 0x1e11902e, 0x29316ff1, 0xd0009026,
  0xf001f000, 0x701102c8, 0x02c8f401, 0xe808d000,
  0x05311801, 0x50001c01, 0xd1008108, 0x5003f330,
  0x10501f13, 0xf000d100, 0xe808d300, 0xfdfffc45,
  0xfffffc35, 0x01015007, 0xf210ac19, 0x18340026,
  0xfc450454, 0x12c00200, 0xd3001c34, 0x1c35e804,
  0x0026f213, 0xf214ac10, 0xf2100026, 0xf2150026,
  0x12830026, 0x124512c4, 0x601060f3, 0x01326034,
  0x28006075, 0x902a4014, 0x00615003, 0x40131017,
  0x0014fc01, 0x01711e20, 0x0001f627, 0x10804022,
  0x08500570, 0x00371d10, 0x24476ff7, 0x80289fde,
  0x00605003, 0x40131017, 0x0014fc00, 0x01701e21,
  0x0001f627, 0x10874022, 0x08570517, 0x00371d07,
  0x24476ff7, 0xa8119fde, 0xf262a820, 0xd3000014,
  0x1081e004, 0xfc211102, 0x05010300, 0xd2000521,
  0x1c31e008, 0xfc000060, 0xf2610014, 0x70200018,
  0x11011a00, 0x1c210501, 0xe00cd100, 0xf020a81a,
  0x1c100028, 0xe010d100, 0x002cf020, 0xd1001c10,
  0xf020e014, 0x1c100030, 0xd1005010, 0x1c10e018,
  0xa845a83f, 0xa0704206, 0xac354e86, 0xa83dac2f,
  0x0002ac1a, 0x2805ac12, 0xac21901e, 0x1801a820,
  0xa81a0020, 0x001cfa00, 0xa821a812, 0x4ff5a818,
  0x40412905, 0xa82f9fe6, 0x5010a835, 0xa0704186,
  0xac2d4ec6, 0xac12ac27, 0x0005ac19, 0x0036fa00,
  0x90282910, 0x1025a810, 0x90102800, 0xf41cd000,
  0x1a000150, 0x1c01a819, 0xa8198012, 0xf33cd000,
  0x2000fc35, 0x1d510e00, 0xa8271d01, 0x4146a82d,
  0xd200a070, 0x0001f000, 0x00231020, 0x50100103,
  0x0280f033, 0x28036033, 0x29239078, 0x0014904c,
  0xd3001021, 0x0112f37a, 0xf0211014, 0x01430280,
  0x12415094, 0x40a16031, 0x081460f1, 0xe404d100,
  0x04141811, 0x904c2804, 0x50001a31, 0x90422801,
  0x1000fc10, 0x90442101, 0x0280f020, 0xfc201280,
  0x1d300fff, 0xa0705010, 0x90242913, 0x01121021,
  0xf0205091, 0xd2000280, 0x1240e404, 0x40a06030,
  0x080160f0, 0x04011820, 0xa3002901, 0x5000a070,
  0xfc11a070, 0x1d311000, 0x4ff1a070, 0x1d315010,
  0x4e46a070, 0xac37ac3d, 0x18450004, 0x901e2905,
  0xe404d000, 0x18032801, 0xd0000017, 0x90a0e410,
  0x60431802, 0x90b42803, 0x809e7042, 0x93322915,
  0xf6410017, 0x6ff10004, 0x00400012, 0x01201022,
  0x0019f602, 0x0018f603, 0x90262123, 0xd2001051,
  0x0112f000, 0x0020f021, 0x0020f022, 0x13821301,
  0x61f267f1, 0x0018f701, 0x40110121, 0x0019f701,
  0xd200ac17, 0x5041e444, 0x18232807, 0xd7000871,
  0x0513f000, 0xd800d100, 0xd3001c23, 0xa432d400,
  0x0023a512, 0x0004f641, 0x00740045, 0x105176c3,
  0xf0410114, 0x50040020, 0x00141c34, 0x0400fc24,
  0x902e2804, 0x03fffc21, 0x1000fc31, 0x18028026,
  0x28036023, 0x70229110, 0xd0001c02, 0xfc11e804,
  0x1c010400, 0xf8005000, 0x5fb10524, 0x80faac24,
  0x704267f1, 0x50121c21, 0x1c325001, 0xd410d200,
  0x0018f604, 0xf754ac25, 0xf7510017, 0x00030005,
  0xd810d100, 0xa810ac1b, 0x00302800, 0xf601a512,
  0x6ff10019, 0x0041ac29, 0x6ff1a82b, 0x915a2513,
  0x10114014, 0x0018f704, 0x01140074, 0x0160f247,
  0x0160f245, 0x607512c5, 0xf2430051, 0x40110160,
  0x0100fc23, 0x90102803, 0xf603a820, 0x01130005,
  0x0005f703, 0xfc04a818, 0x0e530160, 0x90082903,
  0x07fffc27, 0x00738026, 0xfc232821, 0x1c2305ff,
  0x28159016, 0x00719012, 0xfc214ff5, 0x4ff501ff,
  0x29051c21, 0xfc279ffa, 0x1c2703ff, 0xf000d700,
  0xf6041a41, 0xfc210018, 0x28010800, 0xf6019f7a,
  0x25410019, 0x101490d4, 0xc000d200, 0xf2710147,
  0xfc210160, 0x2121e000, 0xfc0790ba, 0x1a710160,
  0x40116ff1, 0x001af501, 0x0018f601, 0xf7014011,
  0x80a60018, 0x5fd1ac24, 0xd1000412, 0x1c02e400,
  0x18115000, 0x03fffc21, 0xf9002801, 0x50a20410,
  0x51432807, 0xf000d500, 0xa534a424, 0x000cf053,
  0xd4000943, 0x0413f35a, 0x00450031, 0x011561f1,
  0x29511e51, 0x1253900a, 0x1e410134, 0x20214051,
  0x5013903c, 0xe804d400, 0x08135012, 0x00141c43,
  0x1024a823, 0xf2340143, 0x2804001a, 0xd1009020,
  0x1814e408, 0xf655a825, 0x08520004, 0x1c120542,
  0x001af231, 0xf5314ff1, 0x83a0001a, 0x50a30012,
  0x20326ff2, 0xa8249396, 0xf7415010, 0x1c400004,
  0x50018dc6, 0x001af501, 0xf640a824, 0x28000005,
  0xa8139016, 0xd438d200, 0xd838d100, 0x28034ff0,
  0x1c20a512, 0xa8128014, 0xd438d100, 0xd838d000,
  0x51f22802, 0x1c12a501, 0xe404d000, 0xfc201800,
  0x28000200, 0xd000908e, 0x5011e41b, 0xe408d500,
  0x18521f01, 0x0004f643, 0x08314103, 0xe808d300,
  0xfc420521, 0xfc32fff8, 0x1c51ffff, 0xfffffc41,
  0x1ffffc31, 0x4000fc15, 0x2800a810, 0x1832a521,
  0x04122800, 0xfc131c32, 0xfc422000, 0xa4310001,
  0xe804d300, 0xd200a521, 0x28008000, 0xfc411c31,
  0xa5120004, 0xfc412800, 0x1c320002, 0x5005a452,
  0x1c32a512, 0x0004f642, 0x10220041, 0xf5150121,
  0xf642001a, 0xf7120017, 0xfa000018, 0xa824051a,
  0xa812801c, 0xe000d100, 0x0007fc40, 0xe808d300,
  0x28025025, 0x1832a501, 0x1c320512, 0xa8111c45,
  0x92942925, 0xe400d000, 0x28010047, 0x00131804,
  0xfc429022, 0x04240004, 0x902a2804, 0xfc421801,
  0x04210001, 0x901e2901, 0xfc411800, 0x04100002,
  0xfc2481c6, 0x28048000, 0x1801900c, 0x2000fc21,
  0x91ae2801, 0xfc410032, 0xfc31ffff, 0xfc401fff,
  0xfc30fff8, 0xd300ffff, 0xfc45e808, 0x28020004,
  0xa501ac12, 0xac292802, 0x04101830, 0x2000fc11,
  0xfc401c30, 0xa4140001, 0x8000d300, 0xd000a504,
  0x2802e804, 0xa5531c04, 0x00711c03, 0x0005f615,
  0x902e2805, 0xd500a810, 0xd700d410, 0x2800d810,
  0x5007a575, 0x00100072, 0x6ff24017, 0x1e520120,
  0x0006f702, 0xf6120070, 0x6ff00005, 0x9fe62420,
  0xe404d000, 0x18000017, 0x0200fc20, 0x90602800,
  0xe41bd000, 0x1f025012, 0xe408d000, 0x00751801,
  0xf657ac25, 0x41070004, 0x05120872, 0xd2001c02,
  0x1820e808, 0x0410a829, 0xe804d100, 0x00171c20,
  0x4000fc11, 0x0002fc42, 0x1c731c74, 0xa8105003,
  0xa5212800, 0xf6521c71, 0x00510004, 0x01211022,
  0x001af513, 0x0017f652, 0x0018f712, 0xa8108160,
  0xd46cd100, 0xd86cd200, 0x28005004, 0x1c14a521,
  0xe804d400, 0xd4001c43, 0x5013e408, 0x00751841,
  0x0004f652, 0x50420823, 0x08020513, 0xd4001c43,
  0x0723e444, 0x04321842, 0xfa001c42, 0x0050038a,
  0xd3005031, 0x1c01f000, 0x0004f602, 0x10520031,
  0xf0170121, 0x00710020, 0x603112c1, 0x90562801,
  0x50124ff1, 0x08121287, 0xe414d100, 0xac2a6307,
  0x01370724, 0xfc071812, 0x042402bc, 0x1f1460f4,
  0x0004f604, 0x01431054, 0x0024f234, 0x0024f233,
  0x124360f4, 0x60f30104, 0x40134064, 0x4ff31e45,
  0x29034014, 0x40171f75, 0xa82b9ff4, 0x60f20532,
  0x800a1f12, 0xfaff0005, 0x0050f53a, 0x80a65005,
  0xfc201800, 0x28004000, 0xd10090aa, 0x2803d46c,
  0xd86cd000, 0xa5015014, 0x1c105000, 0xe408d100,
  0x18120035, 0x2805ac27, 0x0004f673, 0x08344103,
  0x1c140524, 0xfffffc44, 0x1ffffc34, 0xfff8fc41,
  0xfffffc31, 0xd400a442, 0xa512e808, 0x28051843,
  0x0001fc41, 0x1c430423, 0x2000fc13, 0x4000fc14,
  0xd300a432, 0xa5128000, 0xe804d100, 0x1c122805,
  0x0004fc42, 0x2805a523, 0x0002fc42, 0xa4431c13,
  0x1c13a523, 0x0004f671, 0x10210072, 0xf5200112,
  0xf670001a, 0xf7200017, 0x00500018, 0x0268fa00,
  0x5005a820, 0x29051c05, 0xa837a300, 0x41c6a83d,
  0x5025a070, 0x8ff01c75, 0xac6d4cc6, 0xac2aac67,
  0xd100ac21, 0xfc44e808, 0xfc34fdff, 0x2623ffff,
  0x04421812, 0x0200fc44, 0xd2001c12, 0x5001e804,
  0xa8741c24, 0x9014ac34, 0x90322803, 0x90382913,
  0xf000d100, 0x0268f011, 0x28338052, 0x29439038,
  0xd200903e, 0xf021f000, 0xa82b0274, 0x903c2913,
  0x0278f022, 0xe010d300, 0x80301c32, 0xf000d100,
  0x0264f011, 0x29238026, 0xd1009022, 0xf011f000,
  0x8018026c, 0xf000d100, 0x0270f011, 0x2953800e,
  0xd100900a, 0xf011f000, 0xd200027c, 0x1c21e00c,
  0x2801a831, 0xa829911e, 0xd4005003, 0x1081e400,
  0xac190501, 0xf33cd100, 0xac100e10, 0xa8210030,
  0xe004d500, 0x01011020, 0x00011810, 0x1101a81a,
  0x1c520512, 0x2911a829, 0x1300900a, 0xe008d100,
  0xd0001c10, 0x5011e018, 0x1c01ac3b, 0xfc401841,
  0x04010400, 0x9ff62801, 0x04011841, 0x28015010,
  0xfc4190b8, 0xd2000400, 0xac58e804, 0xe084d000,
  0x1c21ac51, 0xe080d100, 0x18155012, 0xe088d100,
  0x60f5ac4d, 0xac401800, 0x00501c12, 0xf836faff,
  0x90702910, 0x1025a84c, 0xf000d100, 0x0100fc42,
  0x00400151, 0x0280f011, 0x0300fc20, 0x28010421,
  0xd2009016, 0x1384f41c, 0xf2230152, 0x1a220002,
  0x1f341f24, 0x00528010, 0xfc321304, 0x1d242000,
  0x1d24a812, 0x902c2800, 0x901c2801, 0xf41cd000,
  0xf2010150, 0x1a000002, 0xfc22a842, 0x1282ff00,
  0x1f121f02, 0xa841800e, 0x2000fc35, 0xa8101d51,
  0xd4001d01, 0x1840e400, 0x0410a851, 0xa8582800,
  0x2c409008, 0x9f4c4010, 0xa830a83b, 0x21034013,
  0xfc409efc, 0xd1000200, 0x1c10e804, 0xa8675010,
  0x4346a86d, 0xd000a070, 0xd200f000, 0xf201e404,
  0x401102fe, 0x02fef501, 0x62011821, 0x901c2801,
  0xf330d100, 0x29021e12, 0x5012901a, 0xf0021f12,
  0x60f202c4, 0x0001f712, 0xd100800a, 0x5002f330,
  0xd1001f12, 0x5082e440, 0xd1001d12, 0xd200e400,
  0x8012dc80, 0xf0041823, 0x12e40260, 0xfc3463c4,
  0x1d432000, 0xfc441813, 0x04430080, 0x9ff62803,
  0xd0008fe4, 0x1801e414, 0x00126071, 0x1f027082,
  0xa0701f01, 0xe404d100, 0x18112800, 0x60419012,
  0x90262801, 0xe410d000, 0x70411801, 0x60218010,
  0x90162801, 0xe410d000, 0x70211801, 0xd0001c01,
  0xfc12e804, 0x1c020400, 0xd100a070, 0x0101f000,
  0xf6111020, 0x00130314, 0x60130002, 0x2000fc02,
  0x900e2803, 0xfc311011, 0xfc212000, 0x800621fc,
  0xf33cd100, 0xf41cd300, 0x1d320103, 0x0002f531,
  0x0000a070,
};
const unsigned long sizeof_scu_isopprog_array = 4276; /* 0x000010b4 */
