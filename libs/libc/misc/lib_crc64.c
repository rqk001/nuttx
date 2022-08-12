/****************************************************************************
 * libs/libc/misc/lib_crc64.c
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
#include <stdint.h>

#include <nuttx/crc64.h>

#ifdef CONFIG_HAVE_LONG_LONG

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * CRC64 table generated with:
 *
 *   #include <inttypes.h>
 *   #include <stdint.h>
 *   #include <stdio.h>
 *
 *   #define CRC64_POLY   ((uint64_t)0x42f0e1eba9ea3693)
 *   #define CRC64_TABLEN ((size_t)256)
 *
 *   int main(void)
 *   {
 *     uint64_t crc64val;
 *     size_t i;
 *     size_t j;
 *
 *     printf("static const uint64_t crc64_tab[%zu] =\n", CRC64_TABLEN);
 *     printf("{\n  ");
 *
 *     for (i = 0; i < CRC64_TABLEN; i++)
 *       {
 *         crc64val = (uint64_t)i << 56;
 *         for (j = 0; j < 8; j++)
 *           {
 *             if ((crc64val & ((uint64_t)1 << 63)) != 0)
 *               {
 *                 crc64val = (crc64val << 1) ^ CRC64_POLY;
 *               }
 *             else
 *               {
 *                 crc64val = crc64val << 1;
 *               }
 *           }
 *
 *         printf("0x%016"PRIx64, crc64val);
 *         if (i + 1 >= CRC64_TABLEN)
 *           {
 *             printf("\n");
 *           }
 *         else if (i % 2 == 1)
 *           {
 *             printf(",\n  ");
 *           }
 *         else
 *           {
 *             printf(", ");
 *           }
 *       }
 *
 *     printf("};\n");
 *     return 0;
 *   }
 *
 ****************************************************************************/

#ifdef CONFIG_LIBC_CRC64_FAST
static const uint64_t crc64_tab[256] =
{
  0x0000000000000000, 0x42f0e1eba9ea3693,
  0x85e1c3d753d46d26, 0xc711223cfa3e5bb5,
  0x493366450e42ecdf, 0x0bc387aea7a8da4c,
  0xccd2a5925d9681f9, 0x8e224479f47cb76a,
  0x9266cc8a1c85d9be, 0xd0962d61b56fef2d,
  0x17870f5d4f51b498, 0x5577eeb6e6bb820b,
  0xdb55aacf12c73561, 0x99a54b24bb2d03f2,
  0x5eb4691841135847, 0x1c4488f3e8f96ed4,
  0x663d78ff90e185ef, 0x24cd9914390bb37c,
  0xe3dcbb28c335e8c9, 0xa12c5ac36adfde5a,
  0x2f0e1eba9ea36930, 0x6dfeff5137495fa3,
  0xaaefdd6dcd770416, 0xe81f3c86649d3285,
  0xf45bb4758c645c51, 0xb6ab559e258e6ac2,
  0x71ba77a2dfb03177, 0x334a9649765a07e4,
  0xbd68d2308226b08e, 0xff9833db2bcc861d,
  0x388911e7d1f2dda8, 0x7a79f00c7818eb3b,
  0xcc7af1ff21c30bde, 0x8e8a101488293d4d,
  0x499b3228721766f8, 0x0b6bd3c3dbfd506b,
  0x854997ba2f81e701, 0xc7b97651866bd192,
  0x00a8546d7c558a27, 0x4258b586d5bfbcb4,
  0x5e1c3d753d46d260, 0x1cecdc9e94ace4f3,
  0xdbfdfea26e92bf46, 0x990d1f49c77889d5,
  0x172f5b3033043ebf, 0x55dfbadb9aee082c,
  0x92ce98e760d05399, 0xd03e790cc93a650a,
  0xaa478900b1228e31, 0xe8b768eb18c8b8a2,
  0x2fa64ad7e2f6e317, 0x6d56ab3c4b1cd584,
  0xe374ef45bf6062ee, 0xa1840eae168a547d,
  0x66952c92ecb40fc8, 0x2465cd79455e395b,
  0x3821458aada7578f, 0x7ad1a461044d611c,
  0xbdc0865dfe733aa9, 0xff3067b657990c3a,
  0x711223cfa3e5bb50, 0x33e2c2240a0f8dc3,
  0xf4f3e018f031d676, 0xb60301f359dbe0e5,
  0xda050215ea6c212f, 0x98f5e3fe438617bc,
  0x5fe4c1c2b9b84c09, 0x1d14202910527a9a,
  0x93366450e42ecdf0, 0xd1c685bb4dc4fb63,
  0x16d7a787b7faa0d6, 0x5427466c1e109645,
  0x4863ce9ff6e9f891, 0x0a932f745f03ce02,
  0xcd820d48a53d95b7, 0x8f72eca30cd7a324,
  0x0150a8daf8ab144e, 0x43a04931514122dd,
  0x84b16b0dab7f7968, 0xc6418ae602954ffb,
  0xbc387aea7a8da4c0, 0xfec89b01d3679253,
  0x39d9b93d2959c9e6, 0x7b2958d680b3ff75,
  0xf50b1caf74cf481f, 0xb7fbfd44dd257e8c,
  0x70eadf78271b2539, 0x321a3e938ef113aa,
  0x2e5eb66066087d7e, 0x6cae578bcfe24bed,
  0xabbf75b735dc1058, 0xe94f945c9c3626cb,
  0x676dd025684a91a1, 0x259d31cec1a0a732,
  0xe28c13f23b9efc87, 0xa07cf2199274ca14,
  0x167ff3eacbaf2af1, 0x548f120162451c62,
  0x939e303d987b47d7, 0xd16ed1d631917144,
  0x5f4c95afc5edc62e, 0x1dbc74446c07f0bd,
  0xdaad56789639ab08, 0x985db7933fd39d9b,
  0x84193f60d72af34f, 0xc6e9de8b7ec0c5dc,
  0x01f8fcb784fe9e69, 0x43081d5c2d14a8fa,
  0xcd2a5925d9681f90, 0x8fdab8ce70822903,
  0x48cb9af28abc72b6, 0x0a3b7b1923564425,
  0x70428b155b4eaf1e, 0x32b26afef2a4998d,
  0xf5a348c2089ac238, 0xb753a929a170f4ab,
  0x3971ed50550c43c1, 0x7b810cbbfce67552,
  0xbc902e8706d82ee7, 0xfe60cf6caf321874,
  0xe224479f47cb76a0, 0xa0d4a674ee214033,
  0x67c58448141f1b86, 0x253565a3bdf52d15,
  0xab1721da49899a7f, 0xe9e7c031e063acec,
  0x2ef6e20d1a5df759, 0x6c0603e6b3b7c1ca,
  0xf6fae5c07d3274cd, 0xb40a042bd4d8425e,
  0x731b26172ee619eb, 0x31ebc7fc870c2f78,
  0xbfc9838573709812, 0xfd39626eda9aae81,
  0x3a28405220a4f534, 0x78d8a1b9894ec3a7,
  0x649c294a61b7ad73, 0x266cc8a1c85d9be0,
  0xe17dea9d3263c055, 0xa38d0b769b89f6c6,
  0x2daf4f0f6ff541ac, 0x6f5faee4c61f773f,
  0xa84e8cd83c212c8a, 0xeabe6d3395cb1a19,
  0x90c79d3fedd3f122, 0xd2377cd44439c7b1,
  0x15265ee8be079c04, 0x57d6bf0317edaa97,
  0xd9f4fb7ae3911dfd, 0x9b041a914a7b2b6e,
  0x5c1538adb04570db, 0x1ee5d94619af4648,
  0x02a151b5f156289c, 0x4051b05e58bc1e0f,
  0x87409262a28245ba, 0xc5b073890b687329,
  0x4b9237f0ff14c443, 0x0962d61b56fef2d0,
  0xce73f427acc0a965, 0x8c8315cc052a9ff6,
  0x3a80143f5cf17f13, 0x7870f5d4f51b4980,
  0xbf61d7e80f251235, 0xfd913603a6cf24a6,
  0x73b3727a52b393cc, 0x31439391fb59a55f,
  0xf652b1ad0167feea, 0xb4a25046a88dc879,
  0xa8e6d8b54074a6ad, 0xea16395ee99e903e,
  0x2d071b6213a0cb8b, 0x6ff7fa89ba4afd18,
  0xe1d5bef04e364a72, 0xa3255f1be7dc7ce1,
  0x64347d271de22754, 0x26c49cccb40811c7,
  0x5cbd6cc0cc10fafc, 0x1e4d8d2b65facc6f,
  0xd95caf179fc497da, 0x9bac4efc362ea149,
  0x158e0a85c2521623, 0x577eeb6e6bb820b0,
  0x906fc95291867b05, 0xd29f28b9386c4d96,
  0xcedba04ad0952342, 0x8c2b41a1797f15d1,
  0x4b3a639d83414e64, 0x09ca82762aab78f7,
  0x87e8c60fded7cf9d, 0xc51827e4773df90e,
  0x020905d88d03a2bb, 0x40f9e43324e99428,
  0x2cffe7d5975e55e2, 0x6e0f063e3eb46371,
  0xa91e2402c48a38c4, 0xebeec5e96d600e57,
  0x65cc8190991cb93d, 0x273c607b30f68fae,
  0xe02d4247cac8d41b, 0xa2dda3ac6322e288,
  0xbe992b5f8bdb8c5c, 0xfc69cab42231bacf,
  0x3b78e888d80fe17a, 0x7988096371e5d7e9,
  0xf7aa4d1a85996083, 0xb55aacf12c735610,
  0x724b8ecdd64d0da5, 0x30bb6f267fa73b36,
  0x4ac29f2a07bfd00d, 0x08327ec1ae55e69e,
  0xcf235cfd546bbd2b, 0x8dd3bd16fd818bb8,
  0x03f1f96f09fd3cd2, 0x41011884a0170a41,
  0x86103ab85a2951f4, 0xc4e0db53f3c36767,
  0xd8a453a01b3a09b3, 0x9a54b24bb2d03f20,
  0x5d45907748ee6495, 0x1fb5719ce1045206,
  0x919735e51578e56c, 0xd367d40ebc92d3ff,
  0x1476f63246ac884a, 0x568617d9ef46bed9,
  0xe085162ab69d5e3c, 0xa275f7c11f7768af,
  0x6564d5fde549331a, 0x279434164ca30589,
  0xa9b6706fb8dfb2e3, 0xeb46918411358470,
  0x2c57b3b8eb0bdfc5, 0x6ea7525342e1e956,
  0x72e3daa0aa188782, 0x30133b4b03f2b111,
  0xf7021977f9cceaa4, 0xb5f2f89c5026dc37,
  0x3bd0bce5a45a6b5d, 0x79205d0e0db05dce,
  0xbe317f32f78e067b, 0xfcc19ed95e6430e8,
  0x86b86ed5267cdbd3, 0xc4488f3e8f96ed40,
  0x0359ad0275a8b6f5, 0x41a94ce9dc428066,
  0xcf8b0890283e370c, 0x8d7be97b81d4019f,
  0x4a6acb477bea5a2a, 0x089a2aacd2006cb9,
  0x14dea25f3af9026d, 0x562e43b4931334fe,
  0x913f6188692d6f4b, 0xd3cf8063c0c759d8,
  0x5dedc41a34bbeeb2, 0x1f1d25f19d51d821,
  0xd80c07cd676f8394, 0x9afce626ce85b507
};
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: crc64part
 *
 * Description:
 *   Continue CRC calculation on a part of the buffer.
 *
 ****************************************************************************/

#ifdef CONFIG_LIBC_CRC64_FAST
uint64_t crc64part(FAR const uint8_t *src, size_t len, uint64_t crc64val)
{
  size_t i;

  for (i = 0; i < len; i++)
    {
      crc64val = crc64_tab[((crc64val >> 56) & 0xff) ^ src[i]] ^
                 (crc64val << 8);
    }

  return crc64val;
}
#else
uint64_t crc64part(FAR const uint8_t *src, size_t len, uint64_t crc64val)
{
  size_t i;
  size_t j;

  for (i = 0; i < len; i++)
    {
      crc64val ^= (uint64_t)src[i] << 56;
      for (j = 0; j < 8; j++)
        {
          if ((crc64val & ((uint64_t)1 << 63)) != 0)
            {
              crc64val = (crc64val << 1) ^ CRC64_POLY;
            }
          else
            {
              crc64val = crc64val << 1;
            }
        }
    }

  return crc64val;
}
#endif

/****************************************************************************
 * Name: crc64
 *
 * Description:
 *   Return a 64-bit CRC of the contents of the 'src' buffer, length 'len'.
 *
 ****************************************************************************/

uint64_t crc64(FAR const uint8_t *src, size_t len)
{
  return crc64part(src, len, CRC64_INIT) ^ CRC64_XOROUT;
}

#endif /* CONFIG_HAVE_LONG_LONG */
