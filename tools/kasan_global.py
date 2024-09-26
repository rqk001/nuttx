#!/usr/bin/env python3
############################################################################
# tools/kasan_global.py
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
############################################################################

import argparse
import os

from construct import Int32ul, Int64ul, Struct
from elftools.elf.elffile import ELFFile

debug = False

# The maximum gap that two data segments can tolerate
KASAN_MAX_DATA_GAP = 1 << 16

# The section where the global variable descriptor
# generated by the compiler is located
KASAN_SECTION = ".kasan.global"

# Segments stored in the shadow area
KASAN_SHADOW_SECTION = ".kasan.shadows"

# The structure of parsing strings required for 32-bit and 64 bit
KASAN_GLOBAL_STRUCT_32 = Struct(
    "beg" / Int32ul,
    "size" / Int32ul,
    "size_with_redzone" / Int32ul,
    "name" / Int32ul,
    "module_name" / Int32ul,
    "has_dynamic_init" / Int32ul,
    "location" / Int32ul,
    "odr_indicator" / Int32ul,
)

KASAN_GLOBAL_STRUCT_64 = Struct(
    "beg" / Int64ul,
    "size" / Int64ul,
    "size_with_redzone" / Int64ul,
    "name" / Int64ul,
    "module_name" / Int64ul,
    "has_dynamic_init" / Int64ul,
    "location" / Int64ul,
    "odr_indicator" / Int64ul,
)


# Global configuration information
class Config:
    def __init__(self, outpath, elf, ldscript, align):
        self.outpath = outpath
        self.elf = elf
        self.ldscript = ldscript
        self.align = align

        if self.elf is None or os.path.exists(self.elf) is False:
            self.elf = None
            return

        with open(self.elf, "rb") as file:
            elf_file = ELFFile(file)
            elf_header = elf_file.header

            # Obtain bit width
            bitness = elf_header["e_ident"]["EI_CLASS"]
            if bitness == "ELFCLASS32":
                self.bitwides = 32
            elif bitness == "ELFCLASS64":
                self.bitwides = 64

            # Big and little end
            endianness = elf_header["e_ident"]["EI_DATA"]
            if endianness == "ELFDATA2LSB":
                self.endian = "little"
            elif endianness == "ELFDATA2MSB":
                self.endian = "big"


class KASanRegion:
    def __init__(self, start, end, align, endian, bitwides) -> None:
        self.start = start
        self.end = end
        self.align = align
        self.endian = endian
        self.bitwides = bitwides
        self.size = int((end - start) // self.align // self.bitwides) + 1
        self.__shadow = [0] * self.size

    def shadow(self) -> bytearray:
        ret = bytearray()
        for i in self.__shadow:
            for j in range(self.bitwides // 8):
                if self.endian == "little":
                    ret.append((i >> (j * 8)) & 0xFF)
                else:
                    ret.append((i >> ((self.bitwides // 8 - j - 1) * 8)) & 0xFF)
        return ret

    def mark_bit(self, index, nbit, nbits):
        for i in range(nbits):
            self.__shadow[index] |= 1 << nbit
            nbit += 1
            if nbit == self.bitwides:
                index += 1
                nbit = 0

    def poison(self, dict):
        dict_size = dict["size"]
        if dict_size % self.align:
            dict_size = int((dict_size + self.align - 1) // self.align) * self.align

        distance = (dict["beg"] + dict_size - self.start) // self.align

        # Index of the marked shadow area
        index = int(distance // self.bitwides)

        # The X-th bit of the specific byte marked
        nbit = distance % self.bitwides

        # Number of digits to be marked
        nbits = (dict["size_with_redzone"] - dict_size) // self.align

        if debug:
            print(
                "regin: %08x addr: %08x size: %d bits: %d || poison index: %d nbit: %d nbits: %d"
                % (
                    self.start,
                    dict["beg"],
                    dict["size"],
                    int(dict["size_with_redzone"] // self.align),
                    index,
                    nbit,
                    nbits,
                )
            )

        # Using 32bytes: with 1bit alignment,
        # only one bit of inaccessible area exists for each pair of global variables.
        self.mark_bit(index, nbit, nbits)


class KASanInfo:
    def __init__(self, align, endian, bitwides) -> None:
        self.align = align
        self.endian = endian
        self.bitwides = bitwides
        # Record the starting position of the merged data block
        self.data_sections = []
        # Record the kasan region corresponding to each data block
        self.regions: list[KASanRegion] = []

    def merge_ranges(self, dict):
        if len(self.data_sections) == 0:
            self.data_sections.append(
                [dict["beg"], dict["beg"] + dict["size_with_redzone"]]
            )
            return
        start = dict["beg"]
        end = dict["beg"] + dict["size_with_redzone"]
        if start - self.data_sections[-1][1] <= KASAN_MAX_DATA_GAP:
            self.data_sections[-1][1] = end
        else:
            self.data_sections.append([start, end])

    def create_region(self):
        for i in self.data_sections:
            start = i[0]
            end = i[1]
            if debug:
                print("KAsan Shadow Block: %08x ---- %08x" % (start, end))
            self.regions.append(
                KASanRegion(start, end, self.align, self.endian, self.bitwides)
            )

    def mark_shadow(self, dict):
        for i in self.regions:
            start = i.start
            end = i.end
            if start <= dict["beg"] and dict["beg"] + dict["size_with_redzone"] <= end:
                i.poison(dict)
                break


# Global variable descriptor
def get_global_dict(GLOBAL_STRUCT: Struct, bytes: bytes):
    dict = GLOBAL_STRUCT.parse(bytes)
    return {
        "beg": dict.beg,
        "size": dict.size,
        "size_with_redzone": dict.size_with_redzone,
    }


def get_elf_section(elf, section) -> bytes:
    with open(elf, "rb") as file:
        elf = ELFFile(file)
        for i in elf.iter_sections():
            if i.name == section:
                return i.data()
    return None


def long_to_bytestring(bitwides, endian, value: int) -> str:
    res = ""
    byte_array = value.to_bytes(length=int(bitwides / 8), byteorder=endian)
    for i in byte_array:
        res += "0x%02x, " % (i)
    return res


def create_kasan_file(config: Config, region_list=[]):
    region: KASanRegion = None
    with open(config.outpath, "w") as file:

        file.write("#include <nuttx/nuttx.h>\n")

        # Write the kasan region array
        for i in range(len(region_list)):
            file.write(
                'static const unsigned char locate_data("%s")'
                "\nglobals_region%d[] = {\n" % (KASAN_SHADOW_SECTION, i)
            )
            region = region_list[i]

            # Fill the array of regions
            # The filling order is as follows, from mm/kasan/generic.c
            # This type will be used to record the size of the shadow area
            # to facilitate the program to traverse the array.
            # 2. uintptr_t                  begin;
            # 3. uintptr_t                  end;
            # 4. uintptr_t                  shadow[1];

            file.write(
                "%s\n"
                % (long_to_bytestring(config.bitwides, config.endian, region.start))
            )
            file.write(
                "%s\n"
                % (long_to_bytestring(config.bitwides, config.endian, region.end))
            )

            shadow = region.shadow()
            for j in range(len(shadow)):
                if j % 8 == 0:
                    file.write("\n")
                file.write("0x%02x, " % (shadow[j]))

            file.write("\n};")

        # Record kasan region pointer location
        file.write("\nconst unsigned long g_global_region[] = {\n")
        for i in range(len(region_list)):
            file.write("\n(const unsigned long)&globals_region%d," % (i))
        file.write("0x00\n};")


# Error extraction section processing to enable the program to compile successfully
def handle_error(config: Config, string=None):
    if string:
        print(string)
    create_kasan_file(config)
    exit(0)


def parse_args() -> Config:
    global debug
    parser = argparse.ArgumentParser(description="Build kasan global variable region")
    parser.add_argument("-o", "--outpath", help="outpath")
    parser.add_argument("-a", "--align", default=32, type=int, help="alignment")
    parser.add_argument("-d", "--ldscript", help="ld script path(Only support sim)")
    parser.add_argument("-e", "--elffile", help="elffile")
    parser.add_argument(
        "--debug",
        action="store_true",
        default=False,
        help="if enabled, it will show more logs.",
    )

    args = parser.parse_args()
    debug = args.debug
    return Config(args.outpath, args.elffile, args.ldscript, args.align)


def main():

    config = parse_args()
    if config.elf is None:
        handle_error(config)

    # Identify the segment information that needs to be extracted
    section = get_elf_section(config.elf, KASAN_SECTION)
    if section is None:
        handle_error(
            config,
            "Please update the link script, section ['%s'] cannot be found"
            % (KASAN_SECTION),
        )

    # List of global variable descriptors
    dict_list = []

    # Extract all global variable descriptors within the
    if config.bitwides == 32:
        global_struct = KASAN_GLOBAL_STRUCT_32
    elif config.bitwides == 64:
        global_struct = KASAN_GLOBAL_STRUCT_64

    step = global_struct.sizeof()
    for i in range(0, len(section), step):
        dict = get_global_dict(global_struct, section[i : i + step])
        dict_list.append(dict)

    dict_list = sorted(dict_list, key=lambda item: item["beg"])

    # Merge all global variables to obtain several segments of the distribution range
    kasan = KASanInfo(config.align, config.endian, config.bitwides)
    for i in dict_list:
        kasan.merge_ranges(i)

    # Create empty shadow zone
    kasan.create_region()

    # Mark on the shadow area
    for i in dict_list:
        kasan.mark_shadow(i)

    create_kasan_file(config, kasan.regions)


if __name__ == "__main__":
    main()
