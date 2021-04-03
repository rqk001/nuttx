/****************************************************************************
 * libs/libnx/nxfonts/nxfonts_x11-misc-fixed-6x13.h
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

#ifndef __LIBNX_NXFONTS_NXFONTS_X11_MISC_FIXED_6X13_H
#define __LIBNX_NXFONTS_NXFONTS_X11_MISC_FIXED_6X13_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Pre-Processor Definitions
 ****************************************************************************/

/* Font ID */

#define NXFONT_ID         FONTID_X11_MISC_FIXED_6X13

/* Ranges of 7-bit and 8-bit fonts */

#define NXFONT_MIN7BIT    33
#define NXFONT_MAX7BIT    126

#define NXFONT_MIN8BIT    161
#define NXFONT_MAX8BIT    255

/* Maximum height and width of any glyph in the set */

#define NXFONT_MAXHEIGHT  13
#define NXFONT_MAXWIDTH   6

/* The width of a space */

#define NXFONT_SPACEWIDTH 6

/* exclam (33) */
#define NXFONT_METRICS_33 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_33 {0x0, 0x0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0, 0x20, 0x0, 0x0}

/* quotedbl (34) */
#define NXFONT_METRICS_34 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_34 {0x0, 0x0, 0x50, 0x50, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* numbersign (35) */
#define NXFONT_METRICS_35 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_35 {0x0, 0x0, 0x0, 0x50, 0x50, 0xf8, 0x50, 0xf8, 0x50, 0x50, 0x0, 0x0, 0x0}

/* dollar (36) */
#define NXFONT_METRICS_36 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_36 {0x0, 0x0, 0x20, 0x78, 0xa0, 0xa0, 0x70, 0x28, 0x28, 0xf0, 0x20, 0x0, 0x0}

/* percent (37) */
#define NXFONT_METRICS_37 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_37 {0x0, 0x0, 0x48, 0xa8, 0x50, 0x10, 0x20, 0x40, 0x50, 0xa8, 0x90, 0x0, 0x0}

/* ampersand (38) */
#define NXFONT_METRICS_38 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_38 {0x0, 0x0, 0x0, 0x40, 0xa0, 0xa0, 0x40, 0xa0, 0x98, 0x90, 0x68, 0x0, 0x0}

/* quotesingle (39) */
#define NXFONT_METRICS_39 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_39 {0x0, 0x0, 0x20, 0x20, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* parenleft (40) */
#define NXFONT_METRICS_40 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_40 {0x0, 0x10, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x10, 0x0}

/* parenright (41) */
#define NXFONT_METRICS_41 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_41 {0x0, 0x40, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x40, 0x0}

/* asterisk (42) */
#define NXFONT_METRICS_42 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_42 {0x0, 0x0, 0x20, 0xa8, 0x70, 0xa8, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* plus (43) */
#define NXFONT_METRICS_43 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_43 {0x0, 0x0, 0x0, 0x0, 0x20, 0x20, 0xf8, 0x20, 0x20, 0x0, 0x0, 0x0, 0x0}

/* comma (44) */
#define NXFONT_METRICS_44 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_44 {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x20, 0x40, 0x0}

/* hyphen (45) */
#define NXFONT_METRICS_45 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_45 {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* period (46) */
#define NXFONT_METRICS_46 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_46 {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x70, 0x20, 0x0}

/* slash (47) */
#define NXFONT_METRICS_47 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_47 {0x0, 0x0, 0x8, 0x8, 0x10, 0x10, 0x20, 0x40, 0x40, 0x80, 0x80, 0x0, 0x0}

/* zero (48) */
#define NXFONT_METRICS_48 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_48 {0x0, 0x0, 0x20, 0x50, 0x88, 0x88, 0x88, 0x88, 0x88, 0x50, 0x20, 0x0, 0x0}

/* one (49) */
#define NXFONT_METRICS_49 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_49 {0x0, 0x0, 0x20, 0x60, 0xa0, 0x20, 0x20, 0x20, 0x20, 0x20, 0xf8, 0x0, 0x0}

/* two (50) */
#define NXFONT_METRICS_50 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_50 {0x0, 0x0, 0x70, 0x88, 0x88, 0x8, 0x10, 0x20, 0x40, 0x80, 0xf8, 0x0, 0x0}

/* three (51) */
#define NXFONT_METRICS_51 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_51 {0x0, 0x0, 0xf8, 0x8, 0x10, 0x20, 0x70, 0x8, 0x8, 0x88, 0x70, 0x0, 0x0}

/* four (52) */
#define NXFONT_METRICS_52 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_52 {0x0, 0x0, 0x10, 0x10, 0x30, 0x50, 0x50, 0x90, 0xf8, 0x10, 0x10, 0x0, 0x0}

/* five (53) */
#define NXFONT_METRICS_53 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_53 {0x0, 0x0, 0xf8, 0x80, 0x80, 0xb0, 0xc8, 0x8, 0x8, 0x88, 0x70, 0x0, 0x0}

/* six (54) */
#define NXFONT_METRICS_54 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_54 {0x0, 0x0, 0x70, 0x88, 0x80, 0x80, 0xf0, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* seven (55) */
#define NXFONT_METRICS_55 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_55 {0x0, 0x0, 0xf8, 0x8, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x40, 0x0, 0x0}

/* eight (56) */
#define NXFONT_METRICS_56 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_56 {0x0, 0x0, 0x70, 0x88, 0x88, 0x88, 0x70, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* nine (57) */
#define NXFONT_METRICS_57 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_57 {0x0, 0x0, 0x70, 0x88, 0x88, 0x88, 0x78, 0x8, 0x8, 0x88, 0x70, 0x0, 0x0}

/* colon (58) */
#define NXFONT_METRICS_58 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_58 {0x0, 0x0, 0x0, 0x0, 0x20, 0x70, 0x20, 0x0, 0x0, 0x20, 0x70, 0x20, 0x0}

/* semicolon (59) */
#define NXFONT_METRICS_59 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_59 {0x0, 0x0, 0x0, 0x0, 0x20, 0x70, 0x20, 0x0, 0x0, 0x30, 0x20, 0x40, 0x0}

/* less (60) */
#define NXFONT_METRICS_60 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_60 {0x0, 0x0, 0x8, 0x10, 0x20, 0x40, 0x80, 0x40, 0x20, 0x10, 0x8, 0x0, 0x0}

/* equal (61) */
#define NXFONT_METRICS_61 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_61 {0x0, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x0, 0x0}

/* greater (62) */
#define NXFONT_METRICS_62 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_62 {0x0, 0x0, 0x80, 0x40, 0x20, 0x10, 0x8, 0x10, 0x20, 0x40, 0x80, 0x0, 0x0}

/* question (63) */
#define NXFONT_METRICS_63 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_63 {0x0, 0x0, 0x70, 0x88, 0x88, 0x8, 0x10, 0x20, 0x20, 0x0, 0x20, 0x0, 0x0}

/* at (64) */
#define NXFONT_METRICS_64 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_64 {0x0, 0x0, 0x70, 0x88, 0x88, 0x98, 0xa8, 0xa8, 0xb0, 0x80, 0x78, 0x0, 0x0}

/* A (65) */
#define NXFONT_METRICS_65 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_65 {0x0, 0x0, 0x20, 0x50, 0x88, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x88, 0x0, 0x0}

/* B (66) */
#define NXFONT_METRICS_66 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_66 {0x0, 0x0, 0xf0, 0x48, 0x48, 0x48, 0x70, 0x48, 0x48, 0x48, 0xf0, 0x0, 0x0}

/* C (67) */
#define NXFONT_METRICS_67 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_67 {0x0, 0x0, 0x70, 0x88, 0x80, 0x80, 0x80, 0x80, 0x80, 0x88, 0x70, 0x0, 0x0}

/* D (68) */
#define NXFONT_METRICS_68 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_68 {0x0, 0x0, 0xf0, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0xf0, 0x0, 0x0}

/* E (69) */
#define NXFONT_METRICS_69 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_69 {0x0, 0x0, 0xf8, 0x80, 0x80, 0x80, 0xf0, 0x80, 0x80, 0x80, 0xf8, 0x0, 0x0}

/* F (70) */
#define NXFONT_METRICS_70 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_70 {0x0, 0x0, 0xf8, 0x80, 0x80, 0x80, 0xf0, 0x80, 0x80, 0x80, 0x80, 0x0, 0x0}

/* G (71) */
#define NXFONT_METRICS_71 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_71 {0x0, 0x0, 0x70, 0x88, 0x80, 0x80, 0x80, 0x98, 0x88, 0x88, 0x70, 0x0, 0x0}

/* H (72) */
#define NXFONT_METRICS_72 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_72 {0x0, 0x0, 0x88, 0x88, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x88, 0x88, 0x0, 0x0}

/* I (73) */
#define NXFONT_METRICS_73 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_73 {0x0, 0x0, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* J (74) */
#define NXFONT_METRICS_74 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_74 {0x0, 0x0, 0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x90, 0x60, 0x0, 0x0}

/* K (75) */
#define NXFONT_METRICS_75 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_75 {0x0, 0x0, 0x88, 0x88, 0x90, 0xa0, 0xc0, 0xa0, 0x90, 0x88, 0x88, 0x0, 0x0}

/* L (76) */
#define NXFONT_METRICS_76 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_76 {0x0, 0x0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xf8, 0x0, 0x0}

/* M (77) */
#define NXFONT_METRICS_77 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_77 {0x0, 0x0, 0x88, 0x88, 0xd8, 0xa8, 0xa8, 0x88, 0x88, 0x88, 0x88, 0x0, 0x0}

/* N (78) */
#define NXFONT_METRICS_78 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_78 {0x0, 0x0, 0x88, 0xc8, 0xc8, 0xa8, 0xa8, 0x98, 0x98, 0x88, 0x88, 0x0, 0x0}

/* O (79) */
#define NXFONT_METRICS_79 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_79 {0x0, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* P (80) */
#define NXFONT_METRICS_80 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_80 {0x0, 0x0, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0x80, 0x80, 0x80, 0x80, 0x0, 0x0}

/* Q (81) */
#define NXFONT_METRICS_81 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_81 {0x0, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xa8, 0x70, 0x8, 0x0}

/* R (82) */
#define NXFONT_METRICS_82 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_82 {0x0, 0x0, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0xa0, 0x90, 0x88, 0x88, 0x0, 0x0}

/* S (83) */
#define NXFONT_METRICS_83 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_83 {0x0, 0x0, 0x70, 0x88, 0x80, 0x80, 0x70, 0x8, 0x8, 0x88, 0x70, 0x0, 0x0}

/* T (84) */
#define NXFONT_METRICS_84 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_84 {0x0, 0x0, 0xf8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0, 0x0}

/* U (85) */
#define NXFONT_METRICS_85 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_85 {0x0, 0x0, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* V (86) */
#define NXFONT_METRICS_86 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_86 {0x0, 0x0, 0x88, 0x88, 0x88, 0x88, 0x50, 0x50, 0x50, 0x20, 0x20, 0x0, 0x0}

/* W (87) */
#define NXFONT_METRICS_87 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_87 {0x0, 0x0, 0x88, 0x88, 0x88, 0x88, 0xa8, 0xa8, 0xa8, 0xa8, 0x50, 0x0, 0x0}

/* X (88) */
#define NXFONT_METRICS_88 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_88 {0x0, 0x0, 0x88, 0x88, 0x50, 0x50, 0x20, 0x50, 0x50, 0x88, 0x88, 0x0, 0x0}

/* Y (89) */
#define NXFONT_METRICS_89 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_89 {0x0, 0x0, 0x88, 0x88, 0x50, 0x50, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0, 0x0}

/* Z (90) */
#define NXFONT_METRICS_90 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_90 {0x0, 0x0, 0xf8, 0x8, 0x10, 0x10, 0x20, 0x40, 0x40, 0x80, 0xf8, 0x0, 0x0}

/* bracketleft (91) */
#define NXFONT_METRICS_91 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_91 {0x0, 0x70, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x70, 0x0}

/* backslash (92) */
#define NXFONT_METRICS_92 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_92 {0x0, 0x0, 0x80, 0x80, 0x40, 0x40, 0x20, 0x10, 0x10, 0x8, 0x8, 0x0, 0x0}

/* bracketright (93) */
#define NXFONT_METRICS_93 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_93 {0x0, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70, 0x0}

/* asciicircum (94) */
#define NXFONT_METRICS_94 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_94 {0x0, 0x0, 0x20, 0x50, 0x88, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* underscore (95) */
#define NXFONT_METRICS_95 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_95 {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x0}

/* grave (96) */
#define NXFONT_METRICS_96 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_96 {0x0, 0x20, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* a (97) */
#define NXFONT_METRICS_97 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_97 {0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x8, 0x78, 0x88, 0x98, 0x68, 0x0, 0x0}

/* b (98) */
#define NXFONT_METRICS_98 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_98 {0x0, 0x0, 0x80, 0x80, 0x80, 0xf0, 0x88, 0x88, 0x88, 0x88, 0xf0, 0x0, 0x0}

/* c (99) */
#define NXFONT_METRICS_99 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_99 {0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x88, 0x80, 0x80, 0x88, 0x70, 0x0, 0x0}

/* d (100) */
#define NXFONT_METRICS_100 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_100 {0x0, 0x0, 0x8, 0x8, 0x8, 0x78, 0x88, 0x88, 0x88, 0x88, 0x78, 0x0, 0x0}

/* e (101) */
#define NXFONT_METRICS_101 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_101 {0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x88, 0xf8, 0x80, 0x88, 0x70, 0x0, 0x0}

/* f (102) */
#define NXFONT_METRICS_102 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_102 {0x0, 0x0, 0x30, 0x48, 0x40, 0x40, 0xf0, 0x40, 0x40, 0x40, 0x40, 0x0, 0x0}

/* g (103) */
#define NXFONT_METRICS_103 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_103 {0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x88, 0x88, 0x88, 0x78, 0x8, 0x88, 0x70}

/* h (104) */
#define NXFONT_METRICS_104 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_104 {0x0, 0x0, 0x80, 0x80, 0x80, 0xb0, 0xc8, 0x88, 0x88, 0x88, 0x88, 0x0, 0x0}

/* i (105) */
#define NXFONT_METRICS_105 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_105 {0x0, 0x0, 0x0, 0x20, 0x0, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* j (106) */
#define NXFONT_METRICS_106 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_106 {0x0, 0x0, 0x0, 0x10, 0x0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x90, 0x90, 0x60}

/* k (107) */
#define NXFONT_METRICS_107 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_107 {0x0, 0x0, 0x80, 0x80, 0x80, 0x90, 0xa0, 0xc0, 0xa0, 0x90, 0x88, 0x0, 0x0}

/* l (108) */
#define NXFONT_METRICS_108 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_108 {0x0, 0x0, 0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* m (109) */
#define NXFONT_METRICS_109 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_109 {0x0, 0x0, 0x0, 0x0, 0x0, 0xd0, 0xa8, 0xa8, 0xa8, 0xa8, 0x88, 0x0, 0x0}

/* n (110) */
#define NXFONT_METRICS_110 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_110 {0x0, 0x0, 0x0, 0x0, 0x0, 0xb0, 0xc8, 0x88, 0x88, 0x88, 0x88, 0x0, 0x0}

/* o (111) */
#define NXFONT_METRICS_111 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_111 {0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* p (112) */
#define NXFONT_METRICS_112 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_112 {0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0x80, 0x80, 0x80}

/* q (113) */
#define NXFONT_METRICS_113 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_113 {0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x88, 0x88, 0x88, 0x78, 0x8, 0x8, 0x8}

/* r (114) */
#define NXFONT_METRICS_114 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_114 {0x0, 0x0, 0x0, 0x0, 0x0, 0xb0, 0xc8, 0x80, 0x80, 0x80, 0x80, 0x0, 0x0}

/* s (115) */
#define NXFONT_METRICS_115 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_115 {0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x88, 0x60, 0x10, 0x88, 0x70, 0x0, 0x0}

/* t (116) */
#define NXFONT_METRICS_116 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_116 {0x0, 0x0, 0x0, 0x40, 0x40, 0xf0, 0x40, 0x40, 0x40, 0x48, 0x30, 0x0, 0x0}

/* u (117) */
#define NXFONT_METRICS_117 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_117 {0x0, 0x0, 0x0, 0x0, 0x0, 0x88, 0x88, 0x88, 0x88, 0x98, 0x68, 0x0, 0x0}

/* v (118) */
#define NXFONT_METRICS_118 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_118 {0x0, 0x0, 0x0, 0x0, 0x0, 0x88, 0x88, 0x88, 0x50, 0x50, 0x20, 0x0, 0x0}

/* w (119) */
#define NXFONT_METRICS_119 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_119 {0x0, 0x0, 0x0, 0x0, 0x0, 0x88, 0x88, 0xa8, 0xa8, 0xa8, 0x50, 0x0, 0x0}

/* x (120) */
#define NXFONT_METRICS_120 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_120 {0x0, 0x0, 0x0, 0x0, 0x0, 0x88, 0x50, 0x20, 0x20, 0x50, 0x88, 0x0, 0x0}

/* y (121) */
#define NXFONT_METRICS_121 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_121 {0x0, 0x0, 0x0, 0x0, 0x0, 0x88, 0x88, 0x88, 0x98, 0x68, 0x8, 0x88, 0x70}

/* z (122) */
#define NXFONT_METRICS_122 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_122 {0x0, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x10, 0x20, 0x40, 0x80, 0xf8, 0x0, 0x0}

/* braceleft (123) */
#define NXFONT_METRICS_123 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_123 {0x0, 0x18, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x20, 0x20, 0x20, 0x20, 0x18, 0x0}

/* bar (124) */
#define NXFONT_METRICS_124 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_124 {0x0, 0x0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0, 0x0}

/* braceright (125) */
#define NXFONT_METRICS_125 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_125 {0x0, 0xc0, 0x20, 0x20, 0x20, 0x20, 0x18, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x0}

/* asciitilde (126) */
#define NXFONT_METRICS_126 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_126 {0x0, 0x0, 0x48, 0xa8, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* exclamdown (161) */
#define NXFONT_METRICS_161 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_161 {0x0, 0x0, 0x20, 0x0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0, 0x0}

/* cent (162) */
#define NXFONT_METRICS_162 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_162 {0x0, 0x0, 0x20, 0x70, 0xa8, 0xa0, 0xa0, 0xa8, 0x70, 0x20, 0x0, 0x0, 0x0}

/* sterling (163) */
#define NXFONT_METRICS_163 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_163 {0x0, 0x0, 0x30, 0x48, 0x40, 0x40, 0xe0, 0x40, 0x40, 0x48, 0xb0, 0x0, 0x0}

/* currency (164) */
#define NXFONT_METRICS_164 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_164 {0x0, 0x0, 0x0, 0x0, 0x88, 0x70, 0x50, 0x50, 0x70, 0x88, 0x0, 0x0, 0x0}

/* yen (165) */
#define NXFONT_METRICS_165 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_165 {0x0, 0x0, 0x88, 0x88, 0x50, 0x50, 0xf8, 0x20, 0xf8, 0x20, 0x20, 0x0, 0x0}

/* brokenbar (166) */
#define NXFONT_METRICS_166 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_166 {0x0, 0x0, 0x20, 0x20, 0x20, 0x20, 0x0, 0x20, 0x20, 0x20, 0x20, 0x0, 0x0}

/* section (167) */
#define NXFONT_METRICS_167 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_167 {0x0, 0x30, 0x48, 0x40, 0x30, 0x48, 0x48, 0x30, 0x8, 0x48, 0x30, 0x0, 0x0}

/* dieresis (168) */
#define NXFONT_METRICS_168 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_168 {0x0, 0x50, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* copyright (169) */
#define NXFONT_METRICS_169 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_169 {0x0, 0x70, 0x88, 0xa8, 0xd8, 0xc8, 0xd8, 0xa8, 0x88, 0x70, 0x0, 0x0, 0x0}

/* ordfeminine (170) */
#define NXFONT_METRICS_170 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_170 {0x0, 0x0, 0x70, 0x8, 0x78, 0x88, 0x78, 0x0, 0xf8, 0x0, 0x0, 0x0, 0x0}

/* guillemotleft (171) */
#define NXFONT_METRICS_171 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_171 {0x0, 0x0, 0x0, 0x0, 0x28, 0x50, 0xa0, 0xa0, 0x50, 0x28, 0x0, 0x0, 0x0}

/* logicalnot (172) */
#define NXFONT_METRICS_172 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_172 {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x8, 0x0, 0x0, 0x0, 0x0}

/* hyphen (173) */
#define NXFONT_METRICS_173 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_173 {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* registered (174) */
#define NXFONT_METRICS_174 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_174 {0x0, 0x70, 0x88, 0xe8, 0xd8, 0xd8, 0xe8, 0xd8, 0x88, 0x70, 0x0, 0x0, 0x0}

/* macron (175) */
#define NXFONT_METRICS_175 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_175 {0x0, 0x0, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* degree (176) */
#define NXFONT_METRICS_176 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_176 {0x0, 0x0, 0x30, 0x48, 0x48, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* plusminus (177) */
#define NXFONT_METRICS_177 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_177 {0x0, 0x0, 0x0, 0x20, 0x20, 0xf8, 0x20, 0x20, 0x0, 0xf8, 0x0, 0x0, 0x0}

/* twosuperior (178) */
#define NXFONT_METRICS_178 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_178 {0x0, 0x40, 0xa0, 0x20, 0x40, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* threesuperior (179) */
#define NXFONT_METRICS_179 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_179 {0x0, 0x40, 0xa0, 0x40, 0x20, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* acute (180) */
#define NXFONT_METRICS_180 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_180 {0x0, 0x10, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* mu (181) */
#define NXFONT_METRICS_181 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_181 {0x0, 0x0, 0x0, 0x0, 0x0, 0x88, 0x88, 0x88, 0x88, 0x98, 0xe8, 0x80, 0x80}

/* paragraph (182) */
#define NXFONT_METRICS_182 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_182 {0x0, 0x0, 0x78, 0xe8, 0xe8, 0xe8, 0xe8, 0x68, 0x28, 0x28, 0x28, 0x0, 0x0}

/* periodcentered (183) */
#define NXFONT_METRICS_183 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_183 {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* cedilla (184) */
#define NXFONT_METRICS_184 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_184 {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x20}

/* onesuperior (185) */
#define NXFONT_METRICS_185 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_185 {0x0, 0x40, 0xc0, 0x40, 0x40, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

/* ordmasculine (186) */
#define NXFONT_METRICS_186 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_186 {0x0, 0x0, 0x70, 0x88, 0x88, 0x88, 0x70, 0x0, 0xf8, 0x0, 0x0, 0x0, 0x0}

/* guillemotright (187) */
#define NXFONT_METRICS_187 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_187 {0x0, 0x0, 0x0, 0x0, 0xa0, 0x50, 0x28, 0x28, 0x50, 0xa0, 0x0, 0x0, 0x0}

/* onequarter (188) */
#define NXFONT_METRICS_188 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_188 {0x0, 0x40, 0xc0, 0x40, 0x40, 0xe0, 0x8, 0x18, 0x28, 0x38, 0x8, 0x0, 0x0}

/* onehalf (189) */
#define NXFONT_METRICS_189 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_189 {0x0, 0x40, 0xc0, 0x40, 0x40, 0xe0, 0x10, 0x28, 0x8, 0x10, 0x38, 0x0, 0x0}

/* threequarters (190) */
#define NXFONT_METRICS_190 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_190 {0x0, 0x40, 0xa0, 0x40, 0x20, 0xa0, 0x48, 0x18, 0x28, 0x38, 0x8, 0x0, 0x0}

/* questiondown (191) */
#define NXFONT_METRICS_191 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_191 {0x0, 0x0, 0x20, 0x0, 0x20, 0x20, 0x40, 0x80, 0x88, 0x88, 0x70, 0x0, 0x0}

/* Agrave (192) */
#define NXFONT_METRICS_192 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_192 {0x0, 0x40, 0x20, 0x0, 0x20, 0x50, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x0, 0x0}

/* Aacute (193) */
#define NXFONT_METRICS_193 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_193 {0x0, 0x10, 0x20, 0x0, 0x20, 0x50, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x0, 0x0}

/* Acircumflex (194) */
#define NXFONT_METRICS_194 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_194 {0x0, 0x30, 0x48, 0x0, 0x20, 0x50, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x0, 0x0}

/* Atilde (195) */
#define NXFONT_METRICS_195 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_195 {0x0, 0x28, 0x50, 0x0, 0x20, 0x50, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x0, 0x0}

/* Adieresis (196) */
#define NXFONT_METRICS_196 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_196 {0x0, 0x50, 0x50, 0x0, 0x20, 0x50, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x0, 0x0}

/* Aring (197) */
#define NXFONT_METRICS_197 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_197 {0x0, 0x20, 0x50, 0x20, 0x20, 0x50, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x0, 0x0}

/* AE (198) */
#define NXFONT_METRICS_198 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_198 {0x0, 0x0, 0x58, 0xa0, 0xa0, 0xa0, 0xb0, 0xe0, 0xa0, 0xa0, 0xb8, 0x0, 0x0}

/* Ccedilla (199) */
#define NXFONT_METRICS_199 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_199 {0x0, 0x0, 0x70, 0x88, 0x80, 0x80, 0x80, 0x80, 0x80, 0x88, 0x70, 0x20, 0x40}

/* Egrave (200) */
#define NXFONT_METRICS_200 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_200 {0x0, 0x40, 0x20, 0x0, 0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0xf8, 0x0, 0x0}

/* Eacute (201) */
#define NXFONT_METRICS_201 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_201 {0x0, 0x10, 0x20, 0x0, 0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0xf8, 0x0, 0x0}

/* Ecircumflex (202) */
#define NXFONT_METRICS_202 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_202 {0x0, 0x30, 0x48, 0x0, 0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0xf8, 0x0, 0x0}

/* Edieresis (203) */
#define NXFONT_METRICS_203 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_203 {0x0, 0x50, 0x50, 0x0, 0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0xf8, 0x0, 0x0}

/* Igrave (204) */
#define NXFONT_METRICS_204 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_204 {0x0, 0x40, 0x20, 0x0, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* Iacute (205) */
#define NXFONT_METRICS_205 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_205 {0x0, 0x10, 0x20, 0x0, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* Icircumflex (206) */
#define NXFONT_METRICS_206 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_206 {0x0, 0x30, 0x48, 0x0, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* Idieresis (207) */
#define NXFONT_METRICS_207 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_207 {0x0, 0x50, 0x50, 0x0, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* Eth (208) */
#define NXFONT_METRICS_208 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_208 {0x0, 0x0, 0xf0, 0x48, 0x48, 0x48, 0xe8, 0x48, 0x48, 0x48, 0xf0, 0x0, 0x0}

/* Ntilde (209) */
#define NXFONT_METRICS_209 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_209 {0x0, 0x28, 0x50, 0x0, 0x88, 0x88, 0xc8, 0xa8, 0x98, 0x88, 0x88, 0x0, 0x0}

/* Ograve (210) */
#define NXFONT_METRICS_210 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_210 {0x0, 0x40, 0x20, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* Oacute (211) */
#define NXFONT_METRICS_211 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_211 {0x0, 0x10, 0x20, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* Ocircumflex (212) */
#define NXFONT_METRICS_212 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_212 {0x0, 0x30, 0x48, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* Otilde (213) */
#define NXFONT_METRICS_213 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_213 {0x0, 0x28, 0x50, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* Odieresis (214) */
#define NXFONT_METRICS_214 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_214 {0x0, 0x50, 0x50, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* multiply (215) */
#define NXFONT_METRICS_215 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_215 {0x0, 0x0, 0x0, 0x0, 0x0, 0x88, 0x50, 0x20, 0x50, 0x88, 0x0, 0x0, 0x0}

/* Oslash (216) */
#define NXFONT_METRICS_216 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_216 {0x0, 0x8, 0x70, 0x98, 0x98, 0xa8, 0xa8, 0xa8, 0xc8, 0xc8, 0x70, 0x80, 0x0}

/* Ugrave (217) */
#define NXFONT_METRICS_217 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_217 {0x0, 0x40, 0x20, 0x0, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* Uacute (218) */
#define NXFONT_METRICS_218 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_218 {0x0, 0x10, 0x20, 0x0, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* Ucircumflex (219) */
#define NXFONT_METRICS_219 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_219 {0x0, 0x30, 0x48, 0x0, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* Udieresis (220) */
#define NXFONT_METRICS_220 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_220 {0x0, 0x50, 0x50, 0x0, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* Yacute (221) */
#define NXFONT_METRICS_221 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_221 {0x0, 0x10, 0x20, 0x0, 0x88, 0x88, 0x50, 0x20, 0x20, 0x20, 0x20, 0x0, 0x0}

/* Thorn (222) */
#define NXFONT_METRICS_222 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_222 {0x0, 0x0, 0x80, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0x80, 0x80, 0x80, 0x0, 0x0}

/* germandbls (223) */
#define NXFONT_METRICS_223 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_223 {0x0, 0x0, 0x60, 0x90, 0x90, 0xa0, 0xa0, 0x90, 0x88, 0x88, 0xb0, 0x0, 0x0}

/* agrave (224) */
#define NXFONT_METRICS_224 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_224 {0x0, 0x0, 0x40, 0x20, 0x0, 0x70, 0x8, 0x78, 0x88, 0x98, 0x68, 0x0, 0x0}

/* aacute (225) */
#define NXFONT_METRICS_225 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_225 {0x0, 0x0, 0x10, 0x20, 0x0, 0x70, 0x8, 0x78, 0x88, 0x98, 0x68, 0x0, 0x0}

/* acircumflex (226) */
#define NXFONT_METRICS_226 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_226 {0x0, 0x0, 0x30, 0x48, 0x0, 0x70, 0x8, 0x78, 0x88, 0x98, 0x68, 0x0, 0x0}

/* atilde (227) */
#define NXFONT_METRICS_227 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_227 {0x0, 0x0, 0x28, 0x50, 0x0, 0x70, 0x8, 0x78, 0x88, 0x98, 0x68, 0x0, 0x0}

/* adieresis (228) */
#define NXFONT_METRICS_228 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_228 {0x0, 0x0, 0x50, 0x50, 0x0, 0x70, 0x8, 0x78, 0x88, 0x98, 0x68, 0x0, 0x0}

/* aring (229) */
#define NXFONT_METRICS_229 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_229 {0x0, 0x30, 0x48, 0x30, 0x0, 0x70, 0x8, 0x78, 0x88, 0x98, 0x68, 0x0, 0x0}

/* ae (230) */
#define NXFONT_METRICS_230 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_230 {0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x28, 0x70, 0xa0, 0xa8, 0x50, 0x0, 0x0}

/* ccedilla (231) */
#define NXFONT_METRICS_231 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_231 {0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x88, 0x80, 0x80, 0x88, 0x70, 0x20, 0x40}

/* egrave (232) */
#define NXFONT_METRICS_232 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_232 {0x0, 0x0, 0x40, 0x20, 0x0, 0x70, 0x88, 0xf8, 0x80, 0x88, 0x70, 0x0, 0x0}

/* eacute (233) */
#define NXFONT_METRICS_233 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_233 {0x0, 0x0, 0x10, 0x20, 0x0, 0x70, 0x88, 0xf8, 0x80, 0x88, 0x70, 0x0, 0x0}

/* ecircumflex (234) */
#define NXFONT_METRICS_234 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_234 {0x0, 0x0, 0x30, 0x48, 0x0, 0x70, 0x88, 0xf8, 0x80, 0x88, 0x70, 0x0, 0x0}

/* edieresis (235) */
#define NXFONT_METRICS_235 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_235 {0x0, 0x0, 0x50, 0x50, 0x0, 0x70, 0x88, 0xf8, 0x80, 0x88, 0x70, 0x0, 0x0}

/* igrave (236) */
#define NXFONT_METRICS_236 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_236 {0x0, 0x0, 0x40, 0x20, 0x0, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* iacute (237) */
#define NXFONT_METRICS_237 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_237 {0x0, 0x0, 0x10, 0x20, 0x0, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* icircumflex (238) */
#define NXFONT_METRICS_238 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_238 {0x0, 0x0, 0x30, 0x48, 0x0, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* idieresis (239) */
#define NXFONT_METRICS_239 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_239 {0x0, 0x0, 0x50, 0x50, 0x0, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70, 0x0, 0x0}

/* eth (240) */
#define NXFONT_METRICS_240 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_240 {0x0, 0x50, 0x20, 0x60, 0x10, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* ntilde (241) */
#define NXFONT_METRICS_241 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_241 {0x0, 0x0, 0x28, 0x50, 0x0, 0xb0, 0xc8, 0x88, 0x88, 0x88, 0x88, 0x0, 0x0}

/* ograve (242) */
#define NXFONT_METRICS_242 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_242 {0x0, 0x0, 0x40, 0x20, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* oacute (243) */
#define NXFONT_METRICS_243 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_243 {0x0, 0x0, 0x10, 0x20, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* ocircumflex (244) */
#define NXFONT_METRICS_244 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_244 {0x0, 0x0, 0x30, 0x48, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* otilde (245) */
#define NXFONT_METRICS_245 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_245 {0x0, 0x0, 0x28, 0x50, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* odieresis (246) */
#define NXFONT_METRICS_246 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_246 {0x0, 0x0, 0x50, 0x50, 0x0, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0, 0x0}

/* divide (247) */
#define NXFONT_METRICS_247 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_247 {0x0, 0x0, 0x0, 0x20, 0x20, 0x0, 0xf8, 0x0, 0x20, 0x20, 0x0, 0x0, 0x0}

/* oslash (248) */
#define NXFONT_METRICS_248 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_248 {0x0, 0x0, 0x0, 0x0, 0x8, 0x70, 0x98, 0xa8, 0xa8, 0xc8, 0x70, 0x80, 0x0}

/* ugrave (249) */
#define NXFONT_METRICS_249 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_249 {0x0, 0x0, 0x40, 0x20, 0x0, 0x88, 0x88, 0x88, 0x88, 0x98, 0x68, 0x0, 0x0}

/* uacute (250) */
#define NXFONT_METRICS_250 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_250 {0x0, 0x0, 0x10, 0x20, 0x0, 0x88, 0x88, 0x88, 0x88, 0x98, 0x68, 0x0, 0x0}

/* ucircumflex (251) */
#define NXFONT_METRICS_251 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_251 {0x0, 0x0, 0x30, 0x48, 0x0, 0x88, 0x88, 0x88, 0x88, 0x98, 0x68, 0x0, 0x0}

/* udieresis (252) */
#define NXFONT_METRICS_252 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_252 {0x0, 0x0, 0x50, 0x50, 0x0, 0x88, 0x88, 0x88, 0x88, 0x98, 0x68, 0x0, 0x0}

/* yacute (253) */
#define NXFONT_METRICS_253 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_253 {0x0, 0x0, 0x10, 0x20, 0x0, 0x88, 0x88, 0x88, 0x98, 0x68, 0x8, 0x88, 0x70}

/* thorn (254) */
#define NXFONT_METRICS_254 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_254 {0x0, 0x0, 0x0, 0x80, 0x80, 0xb0, 0xc8, 0x88, 0x88, 0xc8, 0xb0, 0x80, 0x80}

/* ydieresis (255) */
#define NXFONT_METRICS_255 {1, 6, 13, 0, 0, 0}
#define NXFONT_BITMAP_255 {0x0, 0x0, 0x50, 0x50, 0x0, 0x88, 0x88, 0x88, 0x98, 0x68, 0x8, 0x88, 0x70}

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

#endif /* __LIBNX_NXFONTS_NXFONTS_X11_MISC_FIXED_6X13_H */
