/****************************************************************************
 * libs/libnx/nxfonts/nxfonts_serif22x29.h
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

#ifndef __LIBS_LIBNX_NXFONTS_NXFONTS_SERIF22X29_H
#define __LIBS_LIBNX_NXFONTS_NXFONTS_SERIF22X29_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Pre-Processor Definitions
 ****************************************************************************/

/* Font ID */

#define NXFONT_ID         FONTID_SERIF22X29

/* Ranges of 7-bit and 8-bit fonts */

#define NXFONT_MIN7BIT    33
#define NXFONT_MAX7BIT    126

#define NXFONT_MIN8BIT    161
#define NXFONT_MAX8BIT    255

/* Maximum height and width of any glyph in the set */

#define NXFONT_MAXHEIGHT  29
#define NXFONT_MAXWIDTH   22

/* The width of a space */

#define NXFONT_SPACEWIDTH 5

/* exclam (33) */
#define NXFONT_METRICS_33 {1, 2, 13, 1, 9, 0}
#define NXFONT_BITMAP_33 {0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0x40, 0x40, 0x0, 0x0, 0xc0, 0xc0}

/* quotedbl (34) */
#define NXFONT_METRICS_34 {1, 6, 4, 1, 9, 0}
#define NXFONT_BITMAP_34 {0xcc, 0xcc, 0xcc, 0x88}

/* numbersign (35) -- NOTE: Xoffset should be -1, not 0. */
#define NXFONT_METRICS_35 {2, 12, 11, 0, 10, 0}
#define NXFONT_BITMAP_35 {0xc, 0xc0, 0xc, 0xc0, 0xc, 0xc0, 0x7f, 0xf0, 0x19, 0x80, 0x19, 0x80, 0x19, 0x80, 0xff, 0xe0, 0x33, 0x0, 0x33, 0x0, 0x33, 0x0}

/* dollar (36) */
#define NXFONT_METRICS_36 {1, 7, 16, 1, 8, 0}
#define NXFONT_BITMAP_36 {0x10, 0x7c, 0xd6, 0xd2, 0xd0, 0xf0, 0x78, 0x3c, 0x1c, 0x16, 0x16, 0x96, 0xd6, 0x7c, 0x10, 0x10}

/* percent (37) */
#define NXFONT_METRICS_37 {2, 13, 13, 1, 9, 0}
#define NXFONT_BITMAP_37 {0x38, 0x30, 0x6f, 0xe0, 0xc4, 0x40, 0xc4, 0x80, 0xcd, 0x80, 0xfb, 0x0, 0x72, 0x70, 0x6, 0xd8, 0xd, 0x88, 0x9, 0x88, 0x19, 0x98, 0x31, 0xf0, 0x20, 0xe0}

/* ampersand (38) */
#define NXFONT_METRICS_38 {2, 12, 13, 1, 9, 0}
#define NXFONT_BITMAP_38 {0x1c, 0x0, 0x32, 0x0, 0x32, 0x0, 0x32, 0x0, 0x34, 0x0, 0x19, 0xe0, 0x38, 0xc0, 0x6d, 0x80, 0xcf, 0x0, 0xc7, 0x0, 0xc7, 0x80, 0xed, 0xf0, 0x78, 0xe0}

/* quotesingle (39) */
#define NXFONT_METRICS_39 {1, 2, 4, 1, 9, 0}
#define NXFONT_BITMAP_39 {0xc0, 0xc0, 0xc0, 0x80}

/* parenleft (40) */
#define NXFONT_METRICS_40 {1, 5, 17, 1, 9, 0}
#define NXFONT_BITMAP_40 {0x18, 0x30, 0x60, 0x60, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0x60, 0x60, 0x30, 0x18}

/* parenright (41) */
#define NXFONT_METRICS_41 {1, 5, 17, 1, 9, 0}
#define NXFONT_BITMAP_41 {0xc0, 0x60, 0x30, 0x30, 0x10, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x10, 0x30, 0x30, 0x60, 0xc0}

/* asterisk (42) */
#define NXFONT_METRICS_42 {1, 7, 7, 1, 9, 0}
#define NXFONT_BITMAP_42 {0x10, 0xd6, 0x54, 0x38, 0xd6, 0x92, 0x10}

/* plus (43) */
#define NXFONT_METRICS_43 {1, 8, 8, 1, 13, 0}
#define NXFONT_BITMAP_43 {0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18}

/* comma (44) */
#define NXFONT_METRICS_44 {1, 3, 5, 0, 20, 0}
#define NXFONT_BITMAP_44 {0x60, 0x60, 0x20, 0x60, 0xc0}

/* hyphen (45) */
#define NXFONT_METRICS_45 {1, 5, 2, 0, 17, 0}
#define NXFONT_BITMAP_45 {0xf8, 0xf8}

/* period (46) */
#define NXFONT_METRICS_46 {1, 2, 2, 1, 20, 0}
#define NXFONT_BITMAP_46 {0xc0, 0xc0}

/* slash (47) -- NOTE: Xoffset should be -1, not 0. */
#define NXFONT_METRICS_47 {1, 7, 17, 0, 9, 0}
#define NXFONT_BITMAP_47 {0x2, 0x2, 0x6, 0x4, 0xc, 0xc, 0x8, 0x18, 0x18, 0x10, 0x30, 0x30, 0x20, 0x60, 0x60, 0x40, 0xc0}

/* zero (48) */
#define NXFONT_METRICS_48 {1, 8, 13, 1, 9, 0}
#define NXFONT_BITMAP_48 {0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x66, 0x3c}

/* one (49) */
#define NXFONT_METRICS_49 {1, 6, 13, 2, 9, 0}
#define NXFONT_BITMAP_49 {0x30, 0x70, 0xf0, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0xfc}

/* two (50) */
#define NXFONT_METRICS_50 {1, 7, 13, 1, 9, 0}
#define NXFONT_BITMAP_50 {0x3c, 0x7e, 0xce, 0x86, 0x6, 0x6, 0xc, 0xc, 0x18, 0x30, 0x62, 0xfe, 0xfe}

/* three (51) */
#define NXFONT_METRICS_51 {1, 7, 13, 1, 9, 0}
#define NXFONT_BITMAP_51 {0x7c, 0xce, 0x86, 0x6, 0xc, 0x38, 0x3c, 0xe, 0x6, 0x6, 0x6, 0xcc, 0xf8}

/* four (52) */
#define NXFONT_METRICS_52 {1, 8, 13, 0, 9, 0}
#define NXFONT_BITMAP_52 {0x2, 0x6, 0xe, 0xe, 0x16, 0x26, 0x46, 0x46, 0xff, 0xff, 0x6, 0x6, 0x6}

/* five (53) */
#define NXFONT_METRICS_53 {1, 7, 13, 1, 9, 0}
#define NXFONT_BITMAP_53 {0x7e, 0x7c, 0xc0, 0xc0, 0xf0, 0x3c, 0xc, 0xe, 0x6, 0x6, 0xc, 0xdc, 0xf0}

/* six (54) */
#define NXFONT_METRICS_54 {1, 8, 13, 1, 9, 0}
#define NXFONT_BITMAP_54 {0x7, 0x1c, 0x30, 0x60, 0x60, 0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xe3, 0x76, 0x3c}

/* seven (55) */
#define NXFONT_METRICS_55 {1, 8, 13, 1, 9, 0}
#define NXFONT_BITMAP_55 {0x7f, 0xff, 0x82, 0x6, 0x4, 0xc, 0xc, 0x8, 0x18, 0x18, 0x10, 0x30, 0x30}

/* eight (56) */
#define NXFONT_METRICS_56 {1, 8, 13, 1, 9, 0}
#define NXFONT_BITMAP_56 {0x3c, 0x66, 0xc2, 0xe6, 0x7c, 0x38, 0x3c, 0x6e, 0xc7, 0xc3, 0xc3, 0x66, 0x3c}

/* nine (57) */
#define NXFONT_METRICS_57 {1, 8, 13, 1, 9, 0}
#define NXFONT_BITMAP_57 {0x3c, 0x6e, 0xc6, 0xc3, 0xc3, 0xc3, 0xe3, 0x7f, 0x36, 0x6, 0xc, 0x38, 0xe0}

/* colon (58) */
#define NXFONT_METRICS_58 {1, 2, 9, 1, 13, 0}
#define NXFONT_BITMAP_58 {0xc0, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc0, 0xc0}

/* semicolon (59) */
#define NXFONT_METRICS_59 {1, 3, 12, 0, 13, 0}
#define NXFONT_BITMAP_59 {0x60, 0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x60, 0x60, 0x20, 0x60, 0xc0}

/* less (60) */
#define NXFONT_METRICS_60 {2, 9, 9, 1, 13, 0}
#define NXFONT_BITMAP_60 {0x1, 0x80, 0x7, 0x0, 0x1c, 0x0, 0x70, 0x0, 0xc0, 0x0, 0x70, 0x0, 0x1c, 0x0, 0x7, 0x0, 0x1, 0x80}

/* equal (61) */
#define NXFONT_METRICS_61 {2, 9, 5, 1, 15, 0}
#define NXFONT_BITMAP_61 {0xff, 0x80, 0xff, 0x80, 0x0, 0x0, 0xff, 0x80, 0xff, 0x80}

/* greater (62) */
#define NXFONT_METRICS_62 {2, 9, 9, 1, 13, 0}
#define NXFONT_BITMAP_62 {0xc0, 0x0, 0x70, 0x0, 0x1c, 0x0, 0x7, 0x0, 0x1, 0x80, 0x7, 0x0, 0x1c, 0x0, 0x70, 0x0, 0xc0, 0x0}

/* question (63) */
#define NXFONT_METRICS_63 {1, 6, 13, 1, 9, 0}
#define NXFONT_BITMAP_63 {0x78, 0x8c, 0xc4, 0xcc, 0xc, 0x18, 0x18, 0x30, 0x20, 0x20, 0x0, 0x30, 0x30}

/* at (64) */
#define NXFONT_METRICS_64 {2, 14, 16, 1, 9, 0}
#define NXFONT_BITMAP_64 {0x7, 0xe0, 0xe, 0x30, 0x38, 0x18, 0x30, 0x8, 0x63, 0xec, 0x67, 0xe4, 0xc6, 0x64, 0xcc, 0x64, 0xcc, 0xcc, 0xcc, 0xc8, 0xcd, 0xd8, 0x67, 0x70, 0x60, 0x0, 0x30, 0x0, 0x1c, 0x30, 0x7, 0xe0}

/* A (65) */
#define NXFONT_METRICS_65 {2, 13, 13, 1, 9, 0}
#define NXFONT_BITMAP_65 {0x2, 0x0, 0x7, 0x0, 0x7, 0x0, 0x5, 0x0, 0xd, 0x80, 0x9, 0x80, 0x19, 0xc0, 0x10, 0xc0, 0x1f, 0xc0, 0x30, 0xe0, 0x20, 0x60, 0x60, 0x70, 0xf0, 0xf8}

/* B (66) */
#define NXFONT_METRICS_66 {2, 10, 13, 2, 9, 0}
#define NXFONT_BITMAP_66 {0xff, 0x0, 0x63, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x63, 0x0, 0x7f, 0x80, 0x61, 0xc0, 0x60, 0xc0, 0x60, 0xc0, 0x60, 0xc0, 0x61, 0x80, 0xff, 0x0}

/* C (67) */
#define NXFONT_METRICS_67 {2, 11, 13, 1, 9, 0}
#define NXFONT_BITMAP_67 {0xf, 0x20, 0x30, 0xe0, 0x60, 0x60, 0x60, 0x20, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0x60, 0x0, 0x60, 0x60, 0x38, 0xc0, 0xf, 0x0}

/* D (68) */
#define NXFONT_METRICS_68 {2, 11, 13, 2, 9, 0}
#define NXFONT_BITMAP_68 {0xff, 0x0, 0x63, 0x80, 0x60, 0xc0, 0x60, 0xc0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xc0, 0x60, 0xc0, 0x63, 0x80, 0xff, 0x0}

/* E (69) */
#define NXFONT_METRICS_69 {2, 9, 13, 1, 9, 0}
#define NXFONT_BITMAP_69 {0xff, 0x80, 0x61, 0x80, 0x60, 0x80, 0x60, 0x0, 0x60, 0x0, 0x61, 0x0, 0x7f, 0x0, 0x61, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x80, 0x61, 0x80, 0xff, 0x80}

/* F (70) */
#define NXFONT_METRICS_70 {2, 9, 13, 1, 9, 0}
#define NXFONT_BITMAP_70 {0xff, 0x80, 0x61, 0x80, 0x60, 0x80, 0x60, 0x0, 0x60, 0x0, 0x61, 0x0, 0x7f, 0x0, 0x61, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0xf0, 0x0}

/* G (71) */
#define NXFONT_METRICS_71 {2, 12, 13, 1, 9, 0}
#define NXFONT_BITMAP_71 {0xf, 0x20, 0x30, 0xe0, 0x60, 0x60, 0x60, 0x20, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0xf0, 0xc0, 0x60, 0xc0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x39, 0xc0, 0xf, 0x0}

/* H (72) */
#define NXFONT_METRICS_72 {2, 12, 13, 1, 9, 0}
#define NXFONT_BITMAP_72 {0xf0, 0xf0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7f, 0xe0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0, 0xf0}

/* I (73) */
#define NXFONT_METRICS_73 {1, 4, 13, 1, 9, 0}
#define NXFONT_BITMAP_73 {0xf0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* J (74) */
#define NXFONT_METRICS_74 {1, 6, 13, 0, 9, 0}
#define NXFONT_BITMAP_74 {0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xd8, 0xf0}

/* K (75) */
#define NXFONT_METRICS_75 {2, 12, 13, 1, 9, 0}
#define NXFONT_BITMAP_75 {0xf3, 0xe0, 0x61, 0x80, 0x63, 0x0, 0x66, 0x0, 0x6c, 0x0, 0x78, 0x0, 0x78, 0x0, 0x7c, 0x0, 0x6e, 0x0, 0x67, 0x0, 0x63, 0x80, 0x61, 0xc0, 0xf0, 0xf0}

/* L (76) */
#define NXFONT_METRICS_76 {2, 10, 13, 1, 9, 0}
#define NXFONT_BITMAP_76 {0xf0, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x40, 0x60, 0xc0, 0xff, 0xc0}

/* M (77) */
#define NXFONT_METRICS_77 {2, 14, 13, 1, 9, 0}
#define NXFONT_BITMAP_77 {0xe0, 0x1c, 0x70, 0x38, 0x70, 0x38, 0x78, 0x78, 0x58, 0x58, 0x58, 0xd8, 0x5c, 0xd8, 0x4c, 0x98, 0x4d, 0x98, 0x47, 0x18, 0x47, 0x18, 0x42, 0x18, 0xe2, 0x3c}

/* N (78) */
#define NXFONT_METRICS_78 {2, 12, 13, 1, 9, 0}
#define NXFONT_BITMAP_78 {0xe0, 0x70, 0x60, 0x20, 0x70, 0x20, 0x78, 0x20, 0x5c, 0x20, 0x4c, 0x20, 0x4e, 0x20, 0x47, 0x20, 0x43, 0xa0, 0x41, 0xe0, 0x40, 0xe0, 0x40, 0x60, 0xe0, 0x20}

/* O (79) */
#define NXFONT_METRICS_79 {2, 12, 13, 1, 9, 0}
#define NXFONT_BITMAP_79 {0xf, 0x0, 0x30, 0xc0, 0x60, 0x60, 0x60, 0x60, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0x60, 0x60, 0x60, 0x60, 0x30, 0xc0, 0xf, 0x0}

/* P (80) */
#define NXFONT_METRICS_80 {2, 9, 13, 1, 9, 0}
#define NXFONT_BITMAP_80 {0xff, 0x0, 0x63, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x63, 0x0, 0x7e, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x0, 0xf0, 0x0}

/* Q (81) */
#define NXFONT_METRICS_81 {2, 12, 17, 1, 9, 0}
#define NXFONT_BITMAP_81 {0xf, 0x0, 0x30, 0xc0, 0x60, 0x60, 0x60, 0x60, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0x60, 0x60, 0x60, 0x60, 0x30, 0xc0, 0xf, 0x0, 0x6, 0x0, 0x3, 0x0, 0x1, 0xc0, 0x0, 0xf0}

/* R (82) */
#define NXFONT_METRICS_82 {2, 11, 13, 1, 9, 0}
#define NXFONT_BITMAP_82 {0xff, 0x0, 0x63, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x63, 0x0, 0x7e, 0x0, 0x6e, 0x0, 0x66, 0x0, 0x63, 0x0, 0x61, 0x80, 0x60, 0xc0, 0xf0, 0xe0}

/* S (83) */
#define NXFONT_METRICS_83 {1, 8, 13, 2, 9, 0}
#define NXFONT_BITMAP_83 {0x3a, 0x46, 0xc2, 0xc0, 0xe0, 0x78, 0x3c, 0xe, 0x7, 0x3, 0x83, 0xc6, 0xb8}

/* T (84) */
#define NXFONT_METRICS_84 {2, 10, 13, 1, 9, 0}
#define NXFONT_BITMAP_84 {0xff, 0xc0, 0xcc, 0xc0, 0x8c, 0x40, 0xc, 0x0, 0xc, 0x0, 0xc, 0x0, 0xc, 0x0, 0xc, 0x0, 0xc, 0x0, 0xc, 0x0, 0xc, 0x0, 0xc, 0x0, 0x1e, 0x0}

/* U (85) */
#define NXFONT_METRICS_85 {2, 11, 13, 2, 9, 0}
#define NXFONT_BITMAP_85 {0xf0, 0xe0, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x70, 0xc0, 0x39, 0x80, 0x1f, 0x0}

/* V (86) */
#define NXFONT_METRICS_86 {2, 13, 13, 0, 9, 0}
#define NXFONT_BITMAP_86 {0xf8, 0x78, 0x70, 0x30, 0x30, 0x20, 0x38, 0x20, 0x18, 0x60, 0x18, 0x40, 0x1c, 0x40, 0xc, 0xc0, 0xe, 0x80, 0x6, 0x80, 0x7, 0x80, 0x3, 0x0, 0x3, 0x0}

/* W (87) */
#define NXFONT_METRICS_87 {3, 18, 13, 0, 9, 0}
#define NXFONT_BITMAP_87 {0xf9, 0xe3, 0xc0, 0x70, 0xc1, 0x80, 0x30, 0xc1, 0x0, 0x38, 0xe1, 0x0, 0x18, 0x63, 0x0, 0x18, 0xe2, 0x0, 0x18, 0xe2, 0x0, 0x1d, 0xa6, 0x0, 0xd, 0x34, 0x0, 0xf, 0x3c, 0x0, 0xe, 0x38, 0x0, 0x6, 0x18, 0x0, 0x6, 0x18, 0x0}

/* X (88) */
#define NXFONT_METRICS_88 {2, 12, 13, 1, 9, 0}
#define NXFONT_BITMAP_88 {0xf0, 0x70, 0x70, 0x60, 0x38, 0xc0, 0x19, 0x80, 0xd, 0x0, 0xe, 0x0, 0x6, 0x0, 0xf, 0x0, 0x1b, 0x0, 0x11, 0x80, 0x31, 0xc0, 0x60, 0xe0, 0xf0, 0xf0}

/* Y (89) */
#define NXFONT_METRICS_89 {2, 12, 13, 1, 9, 0}
#define NXFONT_BITMAP_89 {0xf0, 0xf0, 0x70, 0x60, 0x30, 0xc0, 0x18, 0x80, 0x19, 0x0, 0xf, 0x0, 0x6, 0x0, 0x6, 0x0, 0x6, 0x0, 0x6, 0x0, 0x6, 0x0, 0x6, 0x0, 0xf, 0x0}

/* Z (90) */
#define NXFONT_METRICS_90 {2, 10, 13, 1, 9, 0}
#define NXFONT_BITMAP_90 {0x7f, 0xc0, 0x61, 0xc0, 0x41, 0x80, 0x3, 0x80, 0x7, 0x0, 0x6, 0x0, 0xe, 0x0, 0x1c, 0x0, 0x38, 0x0, 0x30, 0x0, 0x70, 0x40, 0xe0, 0xc0, 0xff, 0xc0}

/* bracketleft (91) */
#define NXFONT_METRICS_91 {1, 4, 16, 2, 9, 0}
#define NXFONT_BITMAP_91 {0xf0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xf0}

/* backslash (92) */
#define NXFONT_METRICS_92 {1, 5, 13, 0, 9, 0}
#define NXFONT_BITMAP_92 {0x80, 0x80, 0xc0, 0x40, 0x60, 0x60, 0x20, 0x30, 0x30, 0x10, 0x18, 0x8, 0x8}

/* bracketright (93) */
#define NXFONT_METRICS_93 {1, 4, 16, 0, 9, 0}
#define NXFONT_BITMAP_93 {0xf0, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0xf0}

/* asciicircum (94) */
#define NXFONT_METRICS_94 {1, 7, 7, 1, 9, 0}
#define NXFONT_BITMAP_94 {0x10, 0x38, 0x28, 0x6c, 0x44, 0xc6, 0x82}

/* underscore (95) */
#define NXFONT_METRICS_95 {2, 9, 2, 0, 24, 0}
#define NXFONT_BITMAP_95 {0xff, 0x80, 0xff, 0x80}

/* grave (96) */
#define NXFONT_METRICS_96 {1, 4, 3, 0, 9, 0}
#define NXFONT_BITMAP_96 {0xc0, 0x60, 0x10}

/* a (97) */
#define NXFONT_METRICS_97 {1, 7, 9, 1, 13, 0}
#define NXFONT_BITMAP_97 {0x78, 0xc8, 0xcc, 0x1c, 0x6c, 0xcc, 0xcc, 0xfc, 0x66}

/* b (98) */
#define NXFONT_METRICS_98 {1, 8, 13, 0, 9, 0}
#define NXFONT_BITMAP_98 {0x60, 0xe0, 0x60, 0x60, 0x6e, 0x77, 0x63, 0x63, 0x63, 0x63, 0x63, 0x66, 0x5c}

/* c (99) */
#define NXFONT_METRICS_99 {1, 7, 9, 0, 13, 0}
#define NXFONT_BITMAP_99 {0x3c, 0x66, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x66, 0x3c}

/* d (100) */
#define NXFONT_METRICS_100 {1, 8, 13, 0, 9, 0}
#define NXFONT_BITMAP_100 {0x6, 0xe, 0x6, 0x6, 0x3e, 0x66, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x66, 0x3f}

/* e (101) */
#define NXFONT_METRICS_101 {1, 7, 9, 0, 13, 0}
#define NXFONT_BITMAP_101 {0x3c, 0x66, 0xc2, 0xfe, 0xc0, 0xc0, 0xc0, 0x66, 0x3c}

/* f (102) */
#define NXFONT_METRICS_102 {1, 6, 13, 0, 9, 0}
#define NXFONT_BITMAP_102 {0x1c, 0x34, 0x20, 0x60, 0xf8, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* g (103) */
#define NXFONT_METRICS_103 {1, 8, 13, 0, 13, 0}
#define NXFONT_BITMAP_103 {0x3e, 0xcc, 0xc4, 0xc4, 0xcc, 0x78, 0x40, 0x7c, 0x7f, 0x83, 0xc1, 0xe2, 0x7c}

/* h (104) */
#define NXFONT_METRICS_104 {2, 9, 13, 0, 9, 0}
#define NXFONT_BITMAP_104 {0x60, 0x0, 0xe0, 0x0, 0x60, 0x0, 0x60, 0x0, 0x66, 0x0, 0x6f, 0x0, 0x73, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0xf3, 0x80}

/* i (105) */
#define NXFONT_METRICS_105 {1, 4, 13, 0, 9, 0}
#define NXFONT_BITMAP_105 {0x60, 0x60, 0x0, 0x0, 0x60, 0xe0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* j (106) -- NOTE: Xoffset should be -1, not 0. */
#define NXFONT_METRICS_106 {1, 4, 17, 0, 9, 0}
#define NXFONT_BITMAP_106 {0x30, 0x30, 0x0, 0x0, 0x30, 0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0xe0, 0xc0}

/* k (107) */
#define NXFONT_METRICS_107 {2, 10, 13, 0, 9, 0}
#define NXFONT_BITMAP_107 {0x60, 0x0, 0xe0, 0x0, 0x60, 0x0, 0x60, 0x0, 0x67, 0x0, 0x62, 0x0, 0x64, 0x0, 0x68, 0x0, 0x78, 0x0, 0x6c, 0x0, 0x6e, 0x0, 0x67, 0x0, 0xe3, 0xc0}

/* l (108) */
#define NXFONT_METRICS_108 {1, 4, 13, 0, 9, 0}
#define NXFONT_BITMAP_108 {0x60, 0xe0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* m (109) */
#define NXFONT_METRICS_109 {2, 14, 9, 0, 13, 0}
#define NXFONT_BITMAP_109 {0x66, 0x30, 0xef, 0x78, 0x73, 0x98, 0x63, 0x18, 0x63, 0x18, 0x63, 0x18, 0x63, 0x18, 0x63, 0x18, 0xf7, 0xbc}

/* n (110) */
#define NXFONT_METRICS_110 {2, 9, 9, 0, 13, 0}
#define NXFONT_BITMAP_110 {0x66, 0x0, 0xef, 0x0, 0x73, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0xf3, 0x80}

/* o (111) */
#define NXFONT_METRICS_111 {1, 8, 9, 0, 13, 0}
#define NXFONT_BITMAP_111 {0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c}

/* p (112) */
#define NXFONT_METRICS_112 {1, 8, 13, 0, 13, 0}
#define NXFONT_BITMAP_112 {0x6e, 0xf7, 0x63, 0x63, 0x63, 0x63, 0x63, 0x76, 0x7c, 0x60, 0x60, 0x60, 0xf0}

/* q (113) */
#define NXFONT_METRICS_113 {1, 8, 13, 0, 13, 0}
#define NXFONT_BITMAP_113 {0x3e, 0x66, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x66, 0x3e, 0x6, 0x6, 0x6, 0xf}

/* r (114) */
#define NXFONT_METRICS_114 {1, 6, 9, 0, 13, 0}
#define NXFONT_BITMAP_114 {0x6c, 0xec, 0x70, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* s (115) */
#define NXFONT_METRICS_115 {1, 5, 9, 1, 13, 0}
#define NXFONT_BITMAP_115 {0x68, 0x98, 0xc8, 0xe0, 0x70, 0x38, 0x98, 0xc8, 0xb0}

/* t (116) */
#define NXFONT_METRICS_116 {1, 6, 11, 0, 11, 0}
#define NXFONT_BITMAP_116 {0x20, 0x60, 0xf8, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x74, 0x38}

/* u (117) */
#define NXFONT_METRICS_117 {2, 9, 9, 0, 13, 0}
#define NXFONT_BITMAP_117 {0xe7, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x77, 0x0, 0x3b, 0x80}

/* v (118) -- NOTE: Xoffset should be -1, not 0. */
#define NXFONT_METRICS_118 {2, 9, 9, 0, 13, 0}
#define NXFONT_BITMAP_118 {0xf3, 0x80, 0x63, 0x0, 0x62, 0x0, 0x32, 0x0, 0x36, 0x0, 0x14, 0x0, 0x1c, 0x0, 0x8, 0x0, 0x8, 0x0}

/* w (119) */
#define NXFONT_METRICS_119 {2, 13, 9, 0, 13, 0}
#define NXFONT_BITMAP_119 {0xe7, 0x38, 0x66, 0x30, 0x62, 0x60, 0x36, 0x60, 0x37, 0x60, 0x1d, 0x40, 0x1d, 0xc0, 0x8, 0x80, 0x8, 0x80}

/* x (120) */
#define NXFONT_METRICS_120 {2, 9, 9, 0, 13, 0}
#define NXFONT_BITMAP_120 {0xe1, 0x80, 0x63, 0x0, 0x36, 0x0, 0x1c, 0x0, 0x1c, 0x0, 0x1c, 0x0, 0x36, 0x0, 0x63, 0x0, 0xc3, 0x80}

/* y (121) */
#define NXFONT_METRICS_121 {1, 8, 13, 0, 13, 0}
#define NXFONT_BITMAP_121 {0xf3, 0x63, 0x72, 0x32, 0x36, 0x1c, 0x1c, 0xc, 0x8, 0x18, 0x10, 0xf0, 0xe0}

/* z (122) */
#define NXFONT_METRICS_122 {1, 7, 9, 0, 13, 0}
#define NXFONT_BITMAP_122 {0xfe, 0xce, 0x8c, 0x18, 0x30, 0x30, 0x62, 0xe6, 0xfe}

/* braceleft (123) */
#define NXFONT_METRICS_123 {1, 7, 17, 1, 9, 0}
#define NXFONT_BITMAP_123 {0xe, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0xe}

/* bar (124) */
#define NXFONT_METRICS_124 {1, 1, 13, 1, 9, 0}
#define NXFONT_BITMAP_124 {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80}

/* braceright (125) */
#define NXFONT_METRICS_125 {1, 7, 17, 1, 9, 0}
#define NXFONT_BITMAP_125 {0xe0, 0x30, 0x18, 0x18, 0x18, 0x18, 0x18, 0xc, 0x6, 0xc, 0x18, 0x18, 0x18, 0x18, 0x18, 0x30, 0xe0}

/* asciitilde (126) */
#define NXFONT_METRICS_126 {2, 9, 4, 1, 15, 0}
#define NXFONT_BITMAP_126 {0x30, 0x0, 0x79, 0x80, 0xcf, 0x0, 0x6, 0x0}

/* exclamdown (161) */
#define NXFONT_METRICS_161 {1, 2, 13, 1, 13, 0}
#define NXFONT_BITMAP_161 {0xc0, 0xc0, 0x0, 0x0, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0}

/* cent (162) */
#define NXFONT_METRICS_162 {1, 7, 14, 1, 11, 0}
#define NXFONT_BITMAP_162 {0x6, 0x4, 0x3c, 0x6e, 0xc8, 0xd8, 0xd0, 0xd0, 0xf0, 0x72, 0x7c, 0x40, 0xc0, 0x80}

/* sterling (163) */
#define NXFONT_METRICS_163 {2, 10, 13, 0, 9, 0}
#define NXFONT_BITMAP_163 {0xf, 0x0, 0x19, 0x80, 0x19, 0x80, 0x18, 0x0, 0x18, 0x0, 0x18, 0x0, 0x7e, 0x0, 0x18, 0x0, 0x18, 0x0, 0x10, 0x0, 0x78, 0x40, 0xbf, 0xc0, 0xe7, 0x80}

/* currency (164) */
#define NXFONT_METRICS_164 {2, 9, 7, 1, 12, 0}
#define NXFONT_BITMAP_164 {0xdd, 0x80, 0xf7, 0x80, 0x63, 0x0, 0x41, 0x0, 0x63, 0x0, 0xf7, 0x80, 0xdd, 0x80}

/* yen (165) */
#define NXFONT_METRICS_165 {1, 8, 13, 0, 9, 0}
#define NXFONT_BITMAP_165 {0xf7, 0x62, 0x62, 0x76, 0x34, 0x34, 0x7e, 0x18, 0x7e, 0x18, 0x18, 0x18, 0x7e}

/* brokenbar (166) */
#define NXFONT_METRICS_166 {1, 1, 13, 1, 9, 0}
#define NXFONT_BITMAP_166 {0x80, 0x80, 0x80, 0x80, 0x80, 0x0, 0x0, 0x0, 0x80, 0x80, 0x80, 0x80, 0x80}

/* section (167) */
#define NXFONT_METRICS_167 {1, 8, 16, 1, 9, 0}
#define NXFONT_BITMAP_167 {0x3c, 0x66, 0x66, 0x70, 0x38, 0x7c, 0x8e, 0xc7, 0xe3, 0x71, 0x3e, 0x1c, 0xe, 0x66, 0x66, 0x3c}

/* dieresis (168) */
#define NXFONT_METRICS_168 {1, 5, 2, 0, 10, 0}
#define NXFONT_BITMAP_168 {0xd8, 0xd8}

/* copyright (169) */
#define NXFONT_METRICS_169 {2, 13, 13, 1, 9, 0}
#define NXFONT_BITMAP_169 {0xf, 0x80, 0x30, 0x60, 0x40, 0x10, 0x47, 0x90, 0x88, 0x88, 0x90, 0x8, 0x90, 0x8, 0x90, 0x8, 0x88, 0x88, 0x47, 0x10, 0x40, 0x10, 0x30, 0x60, 0xf, 0x80}

/* ordfeminine (170) */
#define NXFONT_METRICS_170 {1, 5, 8, 0, 9, 0}
#define NXFONT_BITMAP_170 {0x60, 0x90, 0x10, 0x70, 0x90, 0xe8, 0x0, 0xf8}

/* guillemotleft (171) */
#define NXFONT_METRICS_171 {1, 8, 7, 1, 14, 0}
#define NXFONT_BITMAP_171 {0x11, 0x33, 0x66, 0xcc, 0x66, 0x33, 0x11}

/* logicalnot (172) */
#define NXFONT_METRICS_172 {2, 9, 5, 1, 15, 0}
#define NXFONT_BITMAP_172 {0xff, 0x80, 0xff, 0x80, 0x1, 0x80, 0x1, 0x80, 0x1, 0x80}

/* hyphen (173) */
#define NXFONT_METRICS_173 {1, 5, 2, 0, 17, 0}
#define NXFONT_BITMAP_173 {0xf8, 0xf8}

/* registered (174) */
#define NXFONT_METRICS_174 {2, 13, 13, 1, 9, 0}
#define NXFONT_BITMAP_174 {0xf, 0x80, 0x30, 0x60, 0x40, 0x10, 0x5f, 0x10, 0x88, 0x88, 0x88, 0x88, 0x8f, 0x8, 0x89, 0x8, 0x88, 0x88, 0x5c, 0xd0, 0x40, 0x10, 0x30, 0x60, 0xf, 0x80}

/* macron (175) */
#define NXFONT_METRICS_175 {1, 5, 2, 0, 10, 0}
#define NXFONT_BITMAP_175 {0xf8, 0xf8}

/* degree (176) */
#define NXFONT_METRICS_176 {1, 5, 5, 1, 9, 0}
#define NXFONT_BITMAP_176 {0x70, 0x88, 0x88, 0x88, 0x70}

/* plusminus (177) */
#define NXFONT_METRICS_177 {1, 8, 11, 1, 11, 0}
#define NXFONT_BITMAP_177 {0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18, 0x0, 0xff, 0xff}

/* twosuperior (178) */
#define NXFONT_METRICS_178 {1, 5, 8, 0, 9, 0}
#define NXFONT_BITMAP_178 {0x70, 0x98, 0x18, 0x10, 0x20, 0x20, 0x40, 0xf8}

/* threesuperior (179) */
#define NXFONT_METRICS_179 {1, 5, 8, 0, 9, 0}
#define NXFONT_BITMAP_179 {0x70, 0x88, 0x18, 0x70, 0x18, 0x8, 0x88, 0x70}

/* acute (180) */
#define NXFONT_METRICS_180 {1, 4, 3, 0, 9, 0}
#define NXFONT_BITMAP_180 {0x30, 0x60, 0x80}

/* mu (181) -- NOTE: Xoffset should be -1, not 0. */
#define NXFONT_METRICS_181 {2, 9, 13, 0, 13, 0}
#define NXFONT_BITMAP_181 {0xe7, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x77, 0x0, 0x7b, 0x80, 0x40, 0x0, 0x40, 0x0, 0x60, 0x0, 0x60, 0x0}

/* paragraph (182) */
#define NXFONT_METRICS_182 {1, 7, 17, 1, 9, 0}
#define NXFONT_BITMAP_182 {0x3e, 0x74, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0x74, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14}

/* periodcentered (183) */
#define NXFONT_METRICS_183 {1, 2, 2, 1, 16, 0}
#define NXFONT_BITMAP_183 {0xc0, 0xc0}

/* cedilla (184) */
#define NXFONT_METRICS_184 {1, 4, 5, 1, 21, 0}
#define NXFONT_BITMAP_184 {0x20, 0x20, 0x10, 0xb0, 0x70}

/* onesuperior (185) */
#define NXFONT_METRICS_185 {1, 3, 8, 1, 9, 0}
#define NXFONT_BITMAP_185 {0x40, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0xe0}

/* ordmasculine (186) */
#define NXFONT_METRICS_186 {1, 5, 8, 0, 9, 0}
#define NXFONT_BITMAP_186 {0x70, 0xd8, 0x88, 0x88, 0xd8, 0x70, 0x0, 0xf8}

/* guillemotright (187) */
#define NXFONT_METRICS_187 {1, 8, 7, 1, 14, 0}
#define NXFONT_BITMAP_187 {0x88, 0xcc, 0x66, 0x33, 0x66, 0xcc, 0x88}

/* onequarter (188) */
#define NXFONT_METRICS_188 {2, 11, 13, 1, 9, 0}
#define NXFONT_BITMAP_188 {0x40, 0x80, 0xc1, 0x80, 0x41, 0x0, 0x43, 0x0, 0x46, 0x0, 0x44, 0x40, 0x4c, 0xc0, 0xe9, 0x40, 0x1b, 0x40, 0x32, 0x40, 0x27, 0xe0, 0x60, 0x40, 0x40, 0x40}

/* onehalf (189) */
#define NXFONT_METRICS_189 {2, 11, 13, 1, 9, 0}
#define NXFONT_BITMAP_189 {0x40, 0x80, 0xc1, 0x80, 0x41, 0x0, 0x43, 0x0, 0x46, 0x0, 0x45, 0xc0, 0x4e, 0x60, 0xe8, 0x60, 0x18, 0x40, 0x30, 0x80, 0x20, 0x80, 0x61, 0x0, 0x43, 0xe0}

/* threequarters (190) -- NOTE: Xoffset should be -1, not 0. */
#define NXFONT_METRICS_190 {2, 13, 13, 0, 9, 0}
#define NXFONT_BITMAP_190 {0x70, 0x20, 0x88, 0x60, 0x18, 0x40, 0x70, 0xc0, 0x19, 0x80, 0x9, 0x10, 0x8b, 0x30, 0x72, 0x50, 0x6, 0xd0, 0xc, 0x90, 0x9, 0xf8, 0x18, 0x10, 0x10, 0x10}

/* questiondown (191) */
#define NXFONT_METRICS_191 {1, 6, 13, 1, 13, 0}
#define NXFONT_BITMAP_191 {0x30, 0x30, 0x0, 0x10, 0x10, 0x30, 0x60, 0x60, 0xc0, 0xcc, 0x8c, 0xc4, 0x78}

/* Agrave (192) */
#define NXFONT_METRICS_192 {2, 13, 17, 1, 5, 0}
#define NXFONT_BITMAP_192 {0x18, 0x0, 0xc, 0x0, 0x2, 0x0, 0x0, 0x0, 0x2, 0x0, 0x7, 0x0, 0x7, 0x0, 0x5, 0x0, 0xd, 0x80, 0x9, 0x80, 0x19, 0xc0, 0x10, 0xc0, 0x1f, 0xc0, 0x30, 0xe0, 0x20, 0x60, 0x60, 0x70, 0xf0, 0xf8}

/* Aacute (193) */
#define NXFONT_METRICS_193 {2, 13, 17, 1, 5, 0}
#define NXFONT_BITMAP_193 {0x0, 0xc0, 0x1, 0x80, 0x2, 0x0, 0x0, 0x0, 0x2, 0x0, 0x7, 0x0, 0x7, 0x0, 0x5, 0x0, 0xd, 0x80, 0x9, 0x80, 0x19, 0xc0, 0x10, 0xc0, 0x1f, 0xc0, 0x30, 0xe0, 0x20, 0x60, 0x60, 0x70, 0xf0, 0xf8}

/* Acircumflex (194) */
#define NXFONT_METRICS_194 {2, 13, 17, 1, 5, 0}
#define NXFONT_BITMAP_194 {0x2, 0x0, 0x7, 0x0, 0xd, 0x80, 0x0, 0x0, 0x2, 0x0, 0x7, 0x0, 0x7, 0x0, 0x5, 0x0, 0xd, 0x80, 0x9, 0x80, 0x19, 0xc0, 0x10, 0xc0, 0x1f, 0xc0, 0x30, 0xe0, 0x20, 0x60, 0x60, 0x70, 0xf0, 0xf8}

/* Atilde (195) */
#define NXFONT_METRICS_195 {2, 13, 17, 1, 5, 0}
#define NXFONT_BITMAP_195 {0xc, 0x80, 0x1f, 0x80, 0x13, 0x0, 0x0, 0x0, 0x2, 0x0, 0x7, 0x0, 0x7, 0x0, 0x5, 0x0, 0xd, 0x80, 0x9, 0x80, 0x19, 0xc0, 0x10, 0xc0, 0x1f, 0xc0, 0x30, 0xe0, 0x20, 0x60, 0x60, 0x70, 0xf0, 0xf8}

/* Adieresis (196) */
#define NXFONT_METRICS_196 {2, 13, 16, 1, 6, 0}
#define NXFONT_BITMAP_196 {0xd, 0x80, 0xd, 0x80, 0x0, 0x0, 0x2, 0x0, 0x7, 0x0, 0x7, 0x0, 0x5, 0x0, 0xd, 0x80, 0x9, 0x80, 0x19, 0xc0, 0x10, 0xc0, 0x1f, 0xc0, 0x30, 0xe0, 0x20, 0x60, 0x60, 0x70, 0xf0, 0xf8}

/* Aring (197) */
#define NXFONT_METRICS_197 {2, 13, 18, 1, 4, 0}
#define NXFONT_BITMAP_197 {0x6, 0x0, 0x9, 0x0, 0x9, 0x0, 0x6, 0x0, 0x0, 0x0, 0x2, 0x0, 0x7, 0x0, 0x7, 0x0, 0x5, 0x0, 0xd, 0x80, 0x9, 0x80, 0x19, 0xc0, 0x10, 0xc0, 0x1f, 0xc0, 0x30, 0xe0, 0x20, 0x60, 0x60, 0x70, 0xf0, 0xf8}

/* AE (198) */
#define NXFONT_METRICS_198 {2, 15, 13, 1, 9, 0}
#define NXFONT_BITMAP_198 {0xf, 0xfc, 0x7, 0x8c, 0x5, 0x84, 0x5, 0x80, 0xd, 0x80, 0x9, 0x88, 0x19, 0xf8, 0x1f, 0x88, 0x11, 0x80, 0x31, 0x80, 0x21, 0x82, 0x61, 0x86, 0xf7, 0xfe}

/* Ccedilla (199) */
#define NXFONT_METRICS_199 {2, 11, 17, 1, 9, 0}
#define NXFONT_BITMAP_199 {0xf, 0x20, 0x30, 0xe0, 0x60, 0x60, 0x60, 0x20, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0xc0, 0x0, 0x60, 0x0, 0x60, 0x60, 0x38, 0xc0, 0xf, 0x0, 0x4, 0x0, 0x2, 0x0, 0x16, 0x0, 0xe, 0x0}

/* Egrave (200) */
#define NXFONT_METRICS_200 {2, 9, 17, 1, 5, 0}
#define NXFONT_BITMAP_200 {0x30, 0x0, 0x18, 0x0, 0x4, 0x0, 0x0, 0x0, 0xff, 0x80, 0x61, 0x80, 0x60, 0x80, 0x60, 0x0, 0x60, 0x0, 0x61, 0x0, 0x7f, 0x0, 0x61, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x80, 0x61, 0x80, 0xff, 0x80}

/* Eacute (201) */
#define NXFONT_METRICS_201 {2, 9, 17, 1, 5, 0}
#define NXFONT_BITMAP_201 {0x3, 0x0, 0x6, 0x0, 0x8, 0x0, 0x0, 0x0, 0xff, 0x80, 0x61, 0x80, 0x60, 0x80, 0x60, 0x0, 0x60, 0x0, 0x61, 0x0, 0x7f, 0x0, 0x61, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x80, 0x61, 0x80, 0xff, 0x80}

/* Ecircumflex (202) */
#define NXFONT_METRICS_202 {2, 9, 17, 1, 5, 0}
#define NXFONT_BITMAP_202 {0x8, 0x0, 0x1c, 0x0, 0x36, 0x0, 0x0, 0x0, 0xff, 0x80, 0x61, 0x80, 0x60, 0x80, 0x60, 0x0, 0x60, 0x0, 0x61, 0x0, 0x7f, 0x0, 0x61, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x80, 0x61, 0x80, 0xff, 0x80}

/* Edieresis (203) */
#define NXFONT_METRICS_203 {2, 9, 16, 1, 6, 0}
#define NXFONT_BITMAP_203 {0x36, 0x0, 0x36, 0x0, 0x0, 0x0, 0xff, 0x80, 0x61, 0x80, 0x60, 0x80, 0x60, 0x0, 0x60, 0x0, 0x61, 0x0, 0x7f, 0x0, 0x61, 0x0, 0x60, 0x0, 0x60, 0x0, 0x60, 0x80, 0x61, 0x80, 0xff, 0x80}

/* Igrave (204) -- NOTE: Xoffset should be -1, not 0. */
#define NXFONT_METRICS_204 {1, 6, 17, 0, 5, 0}
#define NXFONT_BITMAP_204 {0xc0, 0x60, 0x10, 0x0, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c}

/* Iacute (205) */
#define NXFONT_METRICS_205 {1, 6, 17, 1, 5, 0}
#define NXFONT_BITMAP_205 {0xc, 0x18, 0x20, 0x0, 0xf0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* Icircumflex (206) */
#define NXFONT_METRICS_206 {1, 5, 17, 1, 5, 0}
#define NXFONT_BITMAP_206 {0x20, 0x70, 0xd8, 0x0, 0xf0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* Idieresis (207) */
#define NXFONT_METRICS_207 {1, 5, 16, 1, 6, 0}
#define NXFONT_BITMAP_207 {0xd8, 0xd8, 0x0, 0xf0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* Eth (208) */
#define NXFONT_METRICS_208 {2, 12, 13, 0, 9, 0}
#define NXFONT_BITMAP_208 {0x7f, 0x80, 0x31, 0xc0, 0x30, 0x60, 0x30, 0x60, 0x30, 0x30, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x60, 0x30, 0x60, 0x31, 0xc0, 0x7f, 0x80}

/* Ntilde (209) */
#define NXFONT_METRICS_209 {2, 12, 17, 1, 5, 0}
#define NXFONT_BITMAP_209 {0xc, 0x80, 0x1f, 0x80, 0x13, 0x0, 0x0, 0x0, 0xe0, 0x70, 0x60, 0x20, 0x70, 0x20, 0x78, 0x20, 0x5c, 0x20, 0x4c, 0x20, 0x4e, 0x20, 0x47, 0x20, 0x43, 0xa0, 0x41, 0xe0, 0x40, 0xe0, 0x40, 0x60, 0xe0, 0x20}

/* Ograve (210) */
#define NXFONT_METRICS_210 {2, 12, 17, 1, 5, 0}
#define NXFONT_BITMAP_210 {0x30, 0x0, 0x18, 0x0, 0x4, 0x0, 0x0, 0x0, 0xf, 0x0, 0x30, 0xc0, 0x60, 0x60, 0x60, 0x60, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0x60, 0x60, 0x60, 0x60, 0x30, 0xc0, 0xf, 0x0}

/* Oacute (211) */
#define NXFONT_METRICS_211 {2, 12, 17, 1, 5, 0}
#define NXFONT_BITMAP_211 {0x0, 0xc0, 0x1, 0x80, 0x2, 0x0, 0x0, 0x0, 0xf, 0x0, 0x30, 0xc0, 0x60, 0x60, 0x60, 0x60, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0x60, 0x60, 0x60, 0x60, 0x30, 0xc0, 0xf, 0x0}

/* Ocircumflex (212) */
#define NXFONT_METRICS_212 {2, 12, 17, 1, 5, 0}
#define NXFONT_BITMAP_212 {0x4, 0x0, 0xe, 0x0, 0x1b, 0x0, 0x0, 0x0, 0xf, 0x0, 0x30, 0xc0, 0x60, 0x60, 0x60, 0x60, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0x60, 0x60, 0x60, 0x60, 0x30, 0xc0, 0xf, 0x0}

/* Otilde (213) */
#define NXFONT_METRICS_213 {2, 12, 17, 1, 5, 0}
#define NXFONT_BITMAP_213 {0xc, 0x80, 0x1f, 0x80, 0x13, 0x0, 0x0, 0x0, 0xf, 0x0, 0x30, 0xc0, 0x60, 0x60, 0x60, 0x60, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0x60, 0x60, 0x60, 0x60, 0x30, 0xc0, 0xf, 0x0}

/* Odieresis (214) */
#define NXFONT_METRICS_214 {2, 12, 16, 1, 6, 0}
#define NXFONT_BITMAP_214 {0x1b, 0x0, 0x1b, 0x0, 0x0, 0x0, 0xf, 0x0, 0x30, 0xc0, 0x60, 0x60, 0x60, 0x60, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0x60, 0x60, 0x60, 0x60, 0x30, 0xc0, 0xf, 0x0}

/* multiply (215) */
#define NXFONT_METRICS_215 {1, 8, 7, 1, 14, 0}
#define NXFONT_BITMAP_215 {0xc3, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0xc3}

/* Oslash (216) */
#define NXFONT_METRICS_216 {2, 12, 15, 1, 8, 0}
#define NXFONT_BITMAP_216 {0x0, 0x30, 0xf, 0x60, 0x30, 0xc0, 0x60, 0xe0, 0x61, 0xa0, 0xc3, 0x30, 0xc3, 0x30, 0xc6, 0x30, 0xcc, 0x30, 0xcc, 0x30, 0x58, 0x60, 0x70, 0x60, 0x30, 0xc0, 0x6f, 0x0, 0xc0, 0x0}

/* Ugrave (217) */
#define NXFONT_METRICS_217 {2, 11, 17, 2, 5, 0}
#define NXFONT_BITMAP_217 {0x30, 0x0, 0x18, 0x0, 0x4, 0x0, 0x0, 0x0, 0xf0, 0xe0, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x70, 0xc0, 0x39, 0x80, 0x1f, 0x0}

/* Uacute (218) */
#define NXFONT_METRICS_218 {2, 11, 17, 2, 5, 0}
#define NXFONT_BITMAP_218 {0x0, 0xc0, 0x1, 0x80, 0x2, 0x0, 0x0, 0x0, 0xf0, 0xe0, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x70, 0xc0, 0x39, 0x80, 0x1f, 0x0}

/* Ucircumflex (219) */
#define NXFONT_METRICS_219 {2, 11, 17, 2, 5, 0}
#define NXFONT_BITMAP_219 {0x4, 0x0, 0xe, 0x0, 0x1b, 0x0, 0x0, 0x0, 0xf0, 0xe0, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x70, 0xc0, 0x39, 0x80, 0x1f, 0x0}

/* Udieresis (220) */
#define NXFONT_METRICS_220 {2, 11, 16, 2, 6, 0}
#define NXFONT_BITMAP_220 {0x1b, 0x0, 0x1b, 0x0, 0x0, 0x0, 0xf0, 0xe0, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x60, 0x40, 0x70, 0xc0, 0x39, 0x80, 0x1f, 0x0}

/* Yacute (221) */
#define NXFONT_METRICS_221 {2, 12, 17, 1, 5, 0}
#define NXFONT_BITMAP_221 {0x0, 0xc0, 0x1, 0x80, 0x2, 0x0, 0x0, 0x0, 0xf0, 0xf0, 0x70, 0x60, 0x30, 0xc0, 0x18, 0x80, 0x19, 0x0, 0xf, 0x0, 0x6, 0x0, 0x6, 0x0, 0x6, 0x0, 0x6, 0x0, 0x6, 0x0, 0x6, 0x0, 0xf, 0x0}

/* Thorn (222) */
#define NXFONT_METRICS_222 {2, 9, 13, 1, 9, 0}
#define NXFONT_BITMAP_222 {0xf0, 0x0, 0x60, 0x0, 0x60, 0x0, 0x7f, 0x0, 0x63, 0x80, 0x61, 0x80, 0x61, 0x80, 0x61, 0x80, 0x63, 0x0, 0x7e, 0x0, 0x60, 0x0, 0x60, 0x0, 0xf0, 0x0}

/* germandbls (223) */
#define NXFONT_METRICS_223 {1, 8, 13, 0, 9, 0}
#define NXFONT_BITMAP_223 {0x1c, 0x32, 0x63, 0x63, 0x66, 0x6e, 0x7c, 0x66, 0x63, 0x63, 0x6b, 0x6f, 0xee}

/* agrave (224) */
#define NXFONT_METRICS_224 {1, 7, 13, 1, 9, 0}
#define NXFONT_BITMAP_224 {0xc0, 0x60, 0x10, 0x0, 0x78, 0xc8, 0xcc, 0x1c, 0x6c, 0xcc, 0xcc, 0xfc, 0x66}

/* aacute (225) */
#define NXFONT_METRICS_225 {1, 7, 13, 1, 9, 0}
#define NXFONT_BITMAP_225 {0xc, 0x18, 0x20, 0x0, 0x78, 0xc8, 0xcc, 0x1c, 0x6c, 0xcc, 0xcc, 0xfc, 0x66}

/* acircumflex (226) */
#define NXFONT_METRICS_226 {1, 7, 13, 1, 9, 0}
#define NXFONT_BITMAP_226 {0x10, 0x38, 0x6c, 0x0, 0x78, 0xc8, 0xcc, 0x1c, 0x6c, 0xcc, 0xcc, 0xfc, 0x66}

/* atilde (227) */
#define NXFONT_METRICS_227 {1, 7, 13, 1, 9, 0}
#define NXFONT_BITMAP_227 {0x64, 0xfc, 0x98, 0x0, 0x78, 0xc8, 0xcc, 0x1c, 0x6c, 0xcc, 0xcc, 0xfc, 0x66}

/* adieresis (228) */
#define NXFONT_METRICS_228 {1, 7, 12, 1, 10, 0}
#define NXFONT_BITMAP_228 {0x6c, 0x6c, 0x0, 0x78, 0xc8, 0xcc, 0x1c, 0x6c, 0xcc, 0xcc, 0xfc, 0x66}

/* aring (229) */
#define NXFONT_METRICS_229 {1, 7, 14, 1, 8, 0}
#define NXFONT_BITMAP_229 {0x30, 0x48, 0x48, 0x30, 0x0, 0x78, 0xc8, 0xcc, 0x1c, 0x6c, 0xcc, 0xcc, 0xfc, 0x66}

/* ae (230) */
#define NXFONT_METRICS_230 {2, 11, 9, 0, 13, 0}
#define NXFONT_BITMAP_230 {0x7b, 0xc0, 0xce, 0x60, 0xcc, 0x20, 0x1f, 0xe0, 0x6c, 0x0, 0xcc, 0x0, 0xcc, 0x0, 0xfe, 0x60, 0x63, 0xc0}

/* ccedilla (231) */
#define NXFONT_METRICS_231 {1, 7, 13, 0, 13, 0}
#define NXFONT_BITMAP_231 {0x3c, 0x66, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x66, 0x3c, 0x10, 0x8, 0x58, 0x38}

/* egrave (232) */
#define NXFONT_METRICS_232 {1, 7, 13, 0, 9, 0}
#define NXFONT_BITMAP_232 {0xc0, 0x60, 0x10, 0x0, 0x3c, 0x66, 0xc2, 0xfe, 0xc0, 0xc0, 0xc0, 0x66, 0x3c}

/* eacute (233) */
#define NXFONT_METRICS_233 {1, 7, 13, 0, 9, 0}
#define NXFONT_BITMAP_233 {0x6, 0xc, 0x10, 0x0, 0x3c, 0x66, 0xc2, 0xfe, 0xc0, 0xc0, 0xc0, 0x66, 0x3c}

/* ecircumflex (234) */
#define NXFONT_METRICS_234 {1, 7, 13, 0, 9, 0}
#define NXFONT_BITMAP_234 {0x10, 0x38, 0x6c, 0x0, 0x3c, 0x66, 0xc2, 0xfe, 0xc0, 0xc0, 0xc0, 0x66, 0x3c}

/* edieresis (235) */
#define NXFONT_METRICS_235 {1, 7, 12, 0, 10, 0}
#define NXFONT_BITMAP_235 {0x6c, 0x6c, 0x0, 0x3c, 0x66, 0xc2, 0xfe, 0xc0, 0xc0, 0xc0, 0x66, 0x3c}

/* igrave (236) -- NOTE: Xoffset should be -2, not 0. */
#define NXFONT_METRICS_236 {1, 6, 13, 0, 9, 0}
#define NXFONT_BITMAP_236 {0xc0, 0x60, 0x10, 0x0, 0x18, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c}

/* iacute (237) */
#define NXFONT_METRICS_237 {1, 6, 13, 0, 9, 0}
#define NXFONT_BITMAP_237 {0xc, 0x18, 0x20, 0x0, 0x60, 0xe0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* icircumflex (238) */
#define NXFONT_METRICS_238 {1, 5, 13, 0, 9, 0}
#define NXFONT_BITMAP_238 {0x20, 0x70, 0xd8, 0x0, 0x60, 0xe0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* idieresis (239) */
#define NXFONT_METRICS_239 {1, 5, 12, 0, 10, 0}
#define NXFONT_BITMAP_239 {0xd8, 0xd8, 0x0, 0x60, 0xe0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xf0}

/* eth (240) */
#define NXFONT_METRICS_240 {1, 8, 13, 0, 9, 0}
#define NXFONT_BITMAP_240 {0x60, 0x36, 0x38, 0x4c, 0x3e, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c}

/* ntilde (241) */
#define NXFONT_METRICS_241 {2, 9, 13, 0, 9, 0}
#define NXFONT_BITMAP_241 {0x32, 0x0, 0x7e, 0x0, 0x4c, 0x0, 0x0, 0x0, 0x66, 0x0, 0xef, 0x0, 0x73, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0xf3, 0x80}

/* ograve (242) */
#define NXFONT_METRICS_242 {1, 8, 13, 0, 9, 0}
#define NXFONT_BITMAP_242 {0x30, 0x18, 0x4, 0x0, 0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c}

/* oacute (243) */
#define NXFONT_METRICS_243 {1, 8, 13, 0, 9, 0}
#define NXFONT_BITMAP_243 {0x6, 0xc, 0x10, 0x0, 0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c}

/* ocircumflex (244) */
#define NXFONT_METRICS_244 {1, 8, 13, 0, 9, 0}
#define NXFONT_BITMAP_244 {0x10, 0x38, 0x6c, 0x0, 0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c}

/* otilde (245) */
#define NXFONT_METRICS_245 {1, 8, 13, 0, 9, 0}
#define NXFONT_BITMAP_245 {0x32, 0x7e, 0x4c, 0x0, 0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c}

/* odieresis (246) */
#define NXFONT_METRICS_246 {1, 8, 12, 0, 10, 0}
#define NXFONT_BITMAP_246 {0x6c, 0x6c, 0x0, 0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c}

/* divide (247) */
#define NXFONT_METRICS_247 {1, 8, 8, 1, 13, 0}
#define NXFONT_BITMAP_247 {0x18, 0x18, 0x0, 0xff, 0xff, 0x0, 0x18, 0x18}

/* oslash (248) */
#define NXFONT_METRICS_248 {1, 8, 11, 0, 12, 0}
#define NXFONT_BITMAP_248 {0x1, 0x3f, 0x66, 0xcf, 0xcb, 0xdb, 0xd3, 0xf3, 0x66, 0x7c, 0xc0}

/* ugrave (249) */
#define NXFONT_METRICS_249 {2, 9, 13, 0, 9, 0}
#define NXFONT_BITMAP_249 {0x60, 0x0, 0x30, 0x0, 0x8, 0x0, 0x0, 0x0, 0xe7, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x77, 0x0, 0x3b, 0x80}

/* uacute (250) */
#define NXFONT_METRICS_250 {2, 9, 13, 0, 9, 0}
#define NXFONT_BITMAP_250 {0x6, 0x0, 0xc, 0x0, 0x10, 0x0, 0x0, 0x0, 0xe7, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x77, 0x0, 0x3b, 0x80}

/* ucircumflex (251) */
#define NXFONT_METRICS_251 {2, 9, 13, 0, 9, 0}
#define NXFONT_BITMAP_251 {0x8, 0x0, 0x1c, 0x0, 0x36, 0x0, 0x0, 0x0, 0xe7, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x77, 0x0, 0x3b, 0x80}

/* udieresis (252) */
#define NXFONT_METRICS_252 {2, 9, 12, 0, 10, 0}
#define NXFONT_BITMAP_252 {0x36, 0x0, 0x36, 0x0, 0x0, 0x0, 0xe7, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x63, 0x0, 0x77, 0x0, 0x3b, 0x80}

/* yacute (253) -- NOTE: Xoffset should be -1, not 0. */
#define NXFONT_METRICS_253 {1, 8, 17, 0, 9, 0}
#define NXFONT_BITMAP_253 {0x3, 0x6, 0x8, 0x0, 0xf3, 0x63, 0x72, 0x32, 0x36, 0x1c, 0x1c, 0xc, 0x8, 0x18, 0x10, 0xf0, 0xe0}

/* thorn (254) */
#define NXFONT_METRICS_254 {1, 8, 17, 0, 9, 0}
#define NXFONT_BITMAP_254 {0x60, 0xe0, 0x60, 0x60, 0x6e, 0x77, 0x63, 0x63, 0x63, 0x63, 0x63, 0x76, 0x7c, 0x60, 0x60, 0x60, 0xf0}

/* ydieresis (255) */
#define NXFONT_METRICS_255 {1, 8, 16, 0, 10, 0}
#define NXFONT_BITMAP_255 {0x36, 0x36, 0x0, 0xf3, 0x63, 0x72, 0x32, 0x36, 0x1c, 0x1c, 0xc, 0x8, 0x18, 0x10, 0xf0, 0xe0}

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Functions Definitions
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __LIBS_LIBNX_NXFONTS_NXFONTS_SERIF22X29_H */
