/****************************************************************************
 * video/videomode/videomode_lookup.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <string.h>
#include <debug.h>

#include <nuttx/video/videomode.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* These macros help the mode lines below fit on one line. */

#define HP VID_PHSYNC
#define HN VID_NHSYNC
#define VP VID_PVSYNC
#define VN VID_NVSYNC
#define I  VID_INTERLACE
#define DS VID_DBLSCAN

#define M(nm,hr,vr,clk,hs,he,ht,vs,ve,vt,f) \
  { \
    clk, hr, hs, he, ht, vr, vs, ve, vt, 0, f, nm \
  }

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const struct videomode_s g_videomodes[] =
{
  M("640x350x85",
    640,  350,  31500,  672,  736,  832,  382,  385,  445, HP | VN),
  M("640x400x85",
    640,  400,  31500,  672,  736,  832,  401,  404,  445, HN | VP),
  M("720x400x70",
    720,  400,  28320,  738,  846,  900,  412,  414,  449, HN | VP),
  M("720x400x85",
    720,  400,  35500,  756,  828,  936,  401,  404,  446, HN | VP),
  M("720x400x87",
    720,  400,  35500,  738,  846,  900,  421,  423,  449, HN | VN),
  M("640x480x60",
    640,  480,  25175,  656,  752,  800,  490,  492,  525, HN | VN),
  M("640x480x72",
    640,  480,  31500,  664,  704,  832,  489,  492,  520, HN | VN),
  M("640x480x75",
    640,  480,  31500,  656,  720,  840,  481,  484,  500, HN | VN),
  M("640x480x85",
    640,  480,  36000,  696,  752,  832,  481,  484,  509, HN | VN),
  M("800x600x56",
    800,  600,  36000,  824,  896, 1024,  601,  603,  625, HP | VP),
  M("800x600x60",
    800,  600,  40000,  840,  968, 1056,  601,  605,  628, HP | VP),
  M("800x600x72",
    800,  600,  50000,  856,  976, 1040,  637,  643,  666, HP | VP),
  M("800x600x75",
    800,  600,  49500,  816,  896, 1056,  601,  604,  625, HP | VP),
  M("800x600x85",
    800,  600,  56250,  832,  896, 1048,  601,  604,  631, HP | VP),
  M("1024x768x87i",
    1024,  768,  44900, 1032, 1208, 1264,  768,  776,  817, HP | VP | I),
  M("1024x768x60",
    1024,  768,  65000, 1048, 1184, 1344,  771,  777,  806, HN | VN),
  M("1024x768x70",
    1024,  768,  75000, 1048, 1184, 1328,  771,  777,  806, HN | VN),
  M("1024x768x75",
    1024,  768,  78750, 1040, 1136, 1312,  769,  772,  800, HP | VP),
  M("1024x768x85",
    1024,  768,  94500, 1072, 1168, 1376,  769,  772,  808, HP | VP),
  M("1024x768x89",
    1024,  768, 100000, 1108, 1280, 1408,  768,  780,  796, HP | VP),
  M("1152x864x75",
    1152,  864, 108000, 1216, 1344, 1600,  865,  868,  900, HP | VP),
  M("1280x768x75",
    1280,  768, 105640, 1312, 1712, 1744,  782,  792,  807, HN | VP),
  M("1280x960x60",
    1280,  960, 108000, 1376, 1488, 1800,  961,  964, 1000, HP | VP),
  M("1280x960x85",
    1280,  960, 148500, 1344, 1504, 1728,  961,  964, 1011, HP | VP),
  M("1280x1024x60",
    1280, 1024, 108000, 1328, 1440, 1688, 1025, 1028, 1066, HP | VP),
  M("1280x1024x70",
    1280, 1024, 126000, 1328, 1440, 1688, 1025, 1028, 1066, HP | VP),
  M("1280x1024x75",
    1280, 1024, 135000, 1296, 1440, 1688, 1025, 1028, 1066, HP | VP),
  M("1280x1024x85",
    1280, 1024, 157500, 1344, 1504, 1728, 1025, 1028, 1072, HP | VP),
  M("1600x1200x60",
    1600, 1200, 162000, 1664, 1856, 2160, 1201, 1204, 1250, HP | VP),
  M("1600x1200x65",
    1600, 1200, 175500, 1664, 1856, 2160, 1201, 1204, 1250, HP | VP),
  M("1600x1200x70",
    1600, 1200, 189000, 1664, 1856, 2160, 1201, 1204, 1250, HP | VP),
  M("1600x1200x75",
    1600, 1200, 202500, 1664, 1856, 2160, 1201, 1204, 1250, HP | VP),
  M("1600x1200x85",
    1600, 1200, 229500, 1664, 1856, 2160, 1201, 1204, 1250, HP | VP),
  M("1680x1050x60",
    1680, 1050, 147140, 1784, 1968, 2256, 1051, 1054, 1087, HP | VP),
  M("1792x1344x60",
    1792, 1344, 204800, 1920, 2120, 2448, 1345, 1348, 1394, HN | VP),
  M("1792x1344x75",
    1792, 1344, 261000, 1888, 2104, 2456, 1345, 1348, 1417, HN | VP),
  M("1856x1392x60",
    1856, 1392, 218300, 1952, 2176, 2528, 1393, 1396, 1439, HN | VP),
  M("1856x1392x75",
    1856, 1392, 288000, 1984, 2208, 2560, 1393, 1396, 1500, HN | VP),
  M("1920x1440x60",
    1920, 1440, 234000, 2048, 2256, 2600, 1441, 1444, 1500, HN | VP),
  M("1920x1440x75",
    1920, 1440, 297000, 2064, 2288, 2640, 1441, 1444, 1500, HN | VP),
  M("832x624x74",
    832,  624,  57284,  864,  928, 1152,  625,  628,  667, HN | VN),
  M("1152x768x54",
    1152,  768,  64995, 1178, 1314, 1472,  771,  777,  806, HP | VP),
  M("1400x1050x60",
    1400, 1050, 122000, 1488, 1640, 1880, 1052, 1064, 1082, HP | VP),
  M("1400x1050x74",
    1400, 1050, 155800, 1464, 1784, 1912, 1052, 1064, 1090, HP | VP),
  M("1152x900x66",
    1152,  900,  94500, 1192, 1320, 1528,  902,  906,  937, HN | VN),
  M("1152x900x76",
    1152,  900, 105560, 1168, 1280, 1472,  902,  906,  943, HN | VN),

  /* Derived Double Scan Modes */

  M("320x175x85",
    320,  175,  15750,  336,  368,  416,  191,  192,  222, HP | VN | DS),
  M("320x200x85",
    320,  200,  15750,  336,  368,  416,  200,  202,  222, HN | VP | DS),
  M("360x200x70",
    360,  200,  14160,  369,  423,  450,  206,  207,  224, HN | VP | DS),
  M("360x200x85",
    360,  200,  17750,  378,  414,  468,  200,  202,  223, HN | VP | DS),
  M("360x200x87",
    360,  200,  17750,  369,  423,  450,  210,  211,  224, HN | VN | DS),
  M("320x240x60",
    320,  240,  12587,  328,  376,  400,  245,  246,  262, HN | VN | DS),
  M("320x240x72",
    320,  240,  15750,  332,  352,  416,  244,  246,  260, HN | VN | DS),
  M("320x240x75",
    320,  240,  15750,  328,  360,  420,  240,  242,  250, HN | VN | DS),
  M("320x240x85",
    320,  240,  18000,  348,  376,  416,  240,  242,  254, HN | VN | DS),
  M("400x300x56",
    400,  300,  18000,  412,  448,  512,  300,  301,  312, HP | VP | DS),
  M("400x300x60",
    400,  300,  20000,  420,  484,  528,  300,  302,  314, HP | VP | DS),
  M("400x300x72",
    400,  300,  25000,  428,  488,  520,  318,  321,  333, HP | VP | DS),
  M("400x300x75",
    400,  300,  24750,  408,  448,  528,  300,  302,  312, HP | VP | DS),
  M("400x300x85",
    400,  300,  28125,  416,  448,  524,  300,  302,  315, HP | VP | DS),
  M("512x384x87i",
    512,  384,  22450,  516,  604,  632,  384,  388,  408, HP | VP | DS | I),
  M("512x384x60",
    512,  384,  32500,  524,  592,  672,  385,  388,  403, HN | VN | DS),
  M("512x384x70",
    512,  384,  37500,  524,  592,  664,  385,  388,  403, HN | VN | DS),
  M("512x384x75",
    512,  384,  39375,  520,  568,  656,  384,  386,  400, HP | VP | DS),
  M("512x384x85",
    512,  384,  47250,  536,  584,  688,  384,  386,  404, HP | VP | DS),
  M("512x384x89",
    512,  384,  50000,  554,  640,  704,  384,  390,  398, HP | VP | DS),
  M("576x432x75",
    576,  432,  54000,  608,  672,  800,  432,  434,  450, HP | VP | DS),
  M("640x384x75",
    640,  384,  52820,  656,  856,  872,  391,  396,  403, HN | VP | DS),
  M("640x480x60",
    640,  480,  54000,  688,  744,  900,  480,  482,  500, HP | VP | DS),
  M("640x480x85",
    640,  480,  74250,  672,  752,  864,  480,  482,  505, HP | VP | DS),
  M("640x512x60",
    640,  512,  54000,  664,  720,  844,  512,  514,  533, HP | VP | DS),
  M("640x512x70",
    640,  512,  63000,  664,  720,  844,  512,  514,  533, HP | VP | DS),
  M("640x512x75",
    640,  512,  67500,  648,  720,  844,  512,  514,  533, HP | VP | DS),
  M("640x512x85",
    640,  512,  78750,  672,  752,  864,  512,  514,  536, HP | VP | DS),
  M("800x600x60",
    800,  600,  81000,  832,  928, 1080,  600,  602,  625, HP | VP | DS),
  M("800x600x65",
    800,  600,  87750,  832,  928, 1080,  600,  602,  625, HP | VP | DS),
  M("800x600x70",
    800,  600,  94500,  832,  928, 1080,  600,  602,  625, HP | VP | DS),
  M("800x600x75",
    800,  600, 101250,  832,  928, 1080,  600,  602,  625, HP | VP | DS),
  M("800x600x85",
    800,  600, 114750,  832,  928, 1080,  600,  602,  625, HP | VP | DS),
  M("840x525x60",
    840,  525,  73570,  892,  984, 1128,  525,  527,  543, HP | VP | DS),
  M("896x672x60",
    896,  672, 102400,  960, 1060, 1224,  672,  674,  697, HN | VP | DS),
  M("896x672x75",
    896,  672, 130500,  944, 1052, 1228,  672,  674,  708, HN | VP | DS),
  M("928x696x60",
    928,  696, 109150,  976, 1088, 1264,  696,  698,  719, HN | VP | DS),
  M("928x696x75",
    928,  696, 144000,  992, 1104, 1280,  696,  698,  750, HN | VP | DS),
  M("960x720x60",
    960,  720, 117000, 1024, 1128, 1300,  720,  722,  750, HN | VP | DS),
  M("960x720x75",
    960,  720, 148500, 1032, 1144, 1320,  720,  722,  750, HN | VP | DS),
  M("416x312x74",
    416,  312,  28642,  432,  464,  576,  312,  314,  333, HN | VN | DS),
  M("576x384x54",
    576,  384,  32497,  589,  657,  736,  385,  388,  403, HP | VP | DS),
  M("700x525x60",
    700,  525,  61000,  744,  820,  940,  526,  532,  541, HP | VP | DS),
  M("700x525x74",
    700,  525,  77900,  732,  892,  956,  526,  532,  545, HP | VP | DS),
  M("576x450x66",
    576,  450,  47250,  596,  660,  764,  451,  453,  468, HN | VN | DS),
  M("576x450x76",
    576,  450,  52780,  584,  640,  736,  451,  453,  471, HN | VN | DS),
};

static const int g_nvideomodes = 46;

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name:  videomode_lookup_by_name
 *
 * Description:
 *   Find the video mode in a look-up table by the name assigned to the
 *   video mode.
 *
 ****************************************************************************/

FAR const struct videomode_s *videomode_lookup_by_name(FAR const char *name)
{
  int i;

  for (i = 0; i < g_nvideomodes; i++)
    {
      if (strcmp(name, g_videomodes[i].name) == 0)
        {
          return &g_videomodes[i];
        }
    }

  return NULL;
}

/****************************************************************************
 * Name:  videomode_lookup_by_dotclock
 *
 * Description:
 *   Find the video mode in a look-up table with the matching width and
 *   height and the closest dot clock that does not exceed the requested
 *   dot clock.
 *
 ****************************************************************************/

#if 0 /* Not used */
FAR const struct videomode_s *
  videomode_lookup_by_dotclock(uint16_t width, uint16_t height,
                               uint32_t dotclock)
{
  FAR const struct videomode_s *curr;
  FAR const struct videomode_s *best = NULL;
  int i;

  lcdinfo("Looking for %u x %u at up to %lu kHz\n",
          width, height, (unsigned long)dotclock);

  for (i = 0; i < g_nvideomodes; i++)
    {
      curr = &g_videomodes[i];

      if (curr->hdisplay == width && curr->vdisplay == height &&
          curr->dotclock <= dotclock)
        {
          if (best != NULL)
            {
              if (curr->dotclock > best->dotclock)
                {
                  best = curr;
                }
            }
        }
      else
        {
          best = curr;
        }
    }

  if (best != NULL)
    {
      lcdinfo("Found %s\n", best->name);
    }

  return best;
}
#endif

/****************************************************************************
 * Name:  videomode_lookup_by_refresh
 *
 * Description:
 *   Find the video mode in a look-up table with the matching width and
 *   height and the closest refresh rate that does not exceed the requested
 *   rate.
 *
 ****************************************************************************/

#if 0 /* Not used */
FAR const struct videomode_s *
  videomode_lookup_by_refresh(uint16_t width, uint16_t height,
                              uint16_t refresh)
{
  FAR const struct videomode_s *curr;
  FAR const struct videomode_s *best = NULL;
  uint32_t mref;
  int closest = 1000;
  int diff;
  int i;

  lcdinfo("Looking for %u x %u at up to %u Hz\n",
          width, height, refresh);

  for (i = 0; i < g_nvideomodes; i++)
    {
      curr = &g_videomodes[i];

      if (curr->hdisplay == width && curr->vdisplay == height)
        {
          mref = curr->dotclock * 1000 / (curr->htotal * curr->vtotal);
          diff = mref - (uint32_t)refresh;
          if (diff < 0)
            {
              diff = -diff;
            }

          lcdinfo("%s in %lu Hz, diff %d\n",
                  curr->name, (unsigned long)mref, diff);

          if (best != NULL)
            {
              if (diff < closest)
                {
                  best    = curr;
                  closest = diff;
                }
            }
          else
            {
              best    = curr;
              closest = diff;
            }
        }
    }

  if (best != NULL)
    {
      lcdinfo("Found %s %lu\n",
              best->name, (unsigned long)best->dotclock);
    }

  return best;
}
#endif
