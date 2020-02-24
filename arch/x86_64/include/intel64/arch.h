/****************************************************************************
 * arch/x86_64/include/intel64/arch.h
 *
 *   Copyright (C) 2011, 2015, 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/* This file should never be included directed but, rather,
 * only indirectly through nuttx/arch.h
 */

#ifndef __ARCH_X86_64_INCLUDE_INTEL64_ARCH_H
#define __ARCH_X86_64_INCLUDE_INTEL64_ARCH_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#ifndef __ASSEMBLY__
#  include <nuttx/compiler.h>
#  include <stdint.h>
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define X86_64_LOAD_OFFSET 0x100000000


/* RFLAGS bits */

#define X86_64_RFLAGS_CF             (1 << 0)  /* Bit 0:  Carry Flag */
                                              /* Bit 1:  Reserved */
#define X86_64_RFLAGS_PF             (1 << 2)  /* Bit 2:  Parity Flag */
                                              /* Bit 3:  Reserved */
#define X86_64_RFLAGS_AF             (1 << 4)  /* Bit 4:  Auxillary carry Flag */
                                              /* Bit 5:  Reserved */
#define X86_64_RFLAGS_ZF             (1 << 6)  /* Bit 6:  Zero Flag */
#define X86_64_RFLAGS_SF             (1 << 7)  /* Bit 7:  Sign Flag */
#define X86_64_RFLAGS_TF             (1 << 8)  /* Bit 8:  Trap Flag */
#define X86_64_RFLAGS_IF             (1 << 9)  /* Bit 9:  Interrupt Flag */
#define X86_64_RFLAGS_DF             (1 << 10) /* Bit 10: Direction Flag */
#define X86_64_RFLAGS_OF             (1 << 11) /* Bit 11: Overflow Flag */
#define X86_64_RFLAGS_IOPL_SHIFT     (12)      /* Bits 12-13: IOPL mask (286+ only)*/
#define X86_64_RFLAGS_IOPL_MASK      (3 << X86_64_RFLAGS_IOPL_SHIFT)
#define X86_64_RFLAGS_NT             (1 << 14) /* Bit 14: Nested Task */
                                              /* Bit 15: Reserved */
#define X86_64_RFLAGS_RF            (1 << 16) /* Bit 16: Resume Flag (386+ only) */
#define X86_64_RFLAGS_VM            (1 << 17) /* Bit 17: Virtual Mode (386+ only) */
#define X86_64_RFLAGS_AC            (1 << 18) /* Bit 18: Alignment Check (486SX+ only) */
#define X86_64_RFLAGS_VIF           (1 << 19) /* Bit 19: Virtual Interrupt Flag (Pentium+) */
#define X86_64_RFLAGS_VIP           (1 << 20) /* Bit 20: Virtual Interrupt Pending (Pentium+) */
#define X86_64_RFLAGS_ID            (1 << 21) /* Bit 21: CPUID detection flag (Pentium+) */

/* GDT Definitions */


/* Starting from third selector to confirm the syscall interface */
#define X86_GDT_CODE_SEL_NUM    3
# define X86_GDT_CODE_SEL       (1 << X86_GDT_CODE_SEL_NUM)

#define X86_GDT_DATA_SEL_NUM    4
# define X86_GDT_DATA_SEL       (1 << X86_GDT_DATA_SEL_NUM)

#define X86_GDT_BASE      0x0000000000000000
#define X86_GDT_LIMIT     0x000f00000000ffff

#define X86_GDT_FLAG_LONG 0x0020000000000000

#define X86_GDT_ACC_PR    0x0000800000000000
#define X86_GDT_ACC_SEG   0x0000100000000000
#define X86_GDT_ACC_EX    0x0000080000000000
#define X86_GDT_ACC_WR    0x0000020000000000

#define X86_GDT_CODE64_ENTRY    (X86_GDT_BASE + X86_GDT_LIMIT + X86_GDT_FLAG_LONG + X86_GDT_ACC_PR + X86_GDT_ACC_SEG + X86_GDT_ACC_EX)
#define X86_GDT_CODE32_ENTRY    (X86_GDT_BASE + X86_GDT_LIMIT + X86_GDT_ACC_PR + X86_GDT_ACC_SEG + X86_GDT_ACC_EX)
#define X86_GDT_DATA_ENTRY      (X86_GDT_BASE + X86_GDT_LIMIT + X86_GDT_ACC_PR + X86_GDT_ACC_SEG + X86_GDT_ACC_WR)

/* CR0 Definitions */
#define X86_CR0_PE        0x00000001
#define X86_CR0_MP        0x00000002
#define X86_CR0_EM        0x00000004
#define X86_CR0_WP        0x00010000
#define X86_CR0_PG        0x80000000

/* CR4 Definitions */
#define X86_CR4_PAE      0x00000020
#define X86_CR4_PGE      0x00000080
#define X86_CR4_OSXFSR   0x00000200
#define X86_CR4_XMMEXCPT 0x00000400
#define X86_CR4_FGSBASE  0x00010000
#define X86_CR4_PCIDE    0x00020000

/* PAGE TABLE ENTRY Definitions */
#define X86_PAGE_PRESENT (1 << 0)
#define X86_PAGE_WR      (1 << 1)
#define X86_PAGE_USER    (1 << 2)
#define X86_PAGE_WRTHR   (1 << 3)
#define X86_PAGE_NOCACHE (1 << 4)
#define X86_PAGE_HUGE    (1 << 7)
#define X86_PAGE_GLOBAL  (1 << 8)
#define X86_PAGE_NX      (1 << 63)

#define X86_PAGE_ENTRY_SIZE 8
#define X86_NUM_PAGE_ENTRY (PAGE_SIZE / X86_PAGE_ENTRY_SIZE)

#define PAGE_SIZE        (0x1000)
# define PAGE_MASK        (~(PAGE_SIZE - 1))

#define HUGE_PAGE_SIZE   (0x200000)
# define HUGE_PAGE_MASK   (~(HUGE_PAGE_SIZE - 1))

/* CPUID Leaf 01H Definitaions */
#define X86_64_CPUID_01_SSE3   (1 << 0)
#define X86_64_CPUID_01_PCID   (1 << 17)
#define X86_64_CPUID_01_X2APIC (1 << 21)
#define X86_64_CPUID_01_TSCDEA (1 << 24)
#define X86_64_CPUID_01_XSAVE  (1 << 26)
#define X86_64_CPUID_01_RDRAND (1 << 30)

/* MSR Definitions */

#define MSR_FS_BASE             0xc0000100 /* 64bit FS base */

#define MSR_EFER                0xc0000080
# define EFER_LME               0x00000100

#define MSR_MTRR_DEF_TYPE       0x000002ff
# define MTRR_ENABLE            0x00000800

#define MSR_IA32_TSC_DEADLINE   0x6e0

#define MSR_X2APIC_ID           0x802
#define MSR_X2APIC_SPIV         0x80f
#define MSR_X2APIC_LVTT         0x832
#define MSR_X2APIC_TMICT        0x838
#define MSR_X2APIC_TMCCT        0x839
#define MSR_X2APIC_TDCR         0x83e

/* APIC related Definition */
#define LVTT_TSC_DEADLINE  (1 << 18)

#define BITS_PER_LONG    64

#ifndef __ASSEMBLY__
/****************************************************************************
 * Public Types
 ****************************************************************************/

/* IDT data structures ******************************************************
 *
 * The Interrupt Descriptor Table (IDT) is a data structure used by the x86
 * architecture to implement an interrupt vector table. The IDT is used by the
 * processor to determine the correct response to interrupts and exceptions.
 */

begin_packed_struct struct idt_entry_s
{
  uint16_t lobase;           /* Lower 16-bits of vector address for interrupt */
  uint16_t sel;              /* Kernel segment selector */
  uint8_t  ist;              /* 0..2 bits is Interrupt Stack Table offset, reset is zero */
  uint8_t  flags;            /* (See documentation) */
  uint16_t hibase;           /* Upper 16-bits of vector address for interrupt */
  uint32_t xhibase;          /* Top   32-bits of vector address for interrupt */
  uint32_t zero;             /* reserved */
} end_packed_struct;

/* A struct describing a pointer to an array of interrupt handlers.  This is
 * in a format suitable for giving to 'lidt'.
 */

begin_packed_struct struct idt_ptr_s
{
  uint16_t limit;
  uint64_t base;             /* The address of the first GDT entry */
} end_packed_struct;

/* A struct describing a pointer to an array of global descriptors.  This is
 * in a format suitable for giving to 'lgdt'.
 */

begin_packed_struct struct gdt_ptr_s
{
  uint16_t limit;
  uint64_t base;             /* The address of the first GDT entry */
} end_packed_struct;

/****************************************************************************
 * Inline functions
 ****************************************************************************/

static inline void setgdt(void* gdt, int size) {
  struct gdt_ptr_s gdt_ptr;
  gdt_ptr.limit = size;
  gdt_ptr.base = (uintptr_t)gdt;

  asm volatile ("lgdt %0"::"m"(gdt_ptr):"memory");
}

static inline uint64_t rdtsc(void)
{
	uint32_t lo, hi;

	asm volatile("rdtscp" : "=a" (lo), "=d" (hi)::"memory");
	return (uint64_t)lo | (((uint64_t)hi) << 32);
}

static inline uint64_t _rdtsc(void)
{
	uint32_t lo, hi;

	asm volatile("rdtsc" : "=a" (lo), "=d" (hi)::"memory");
	return (uint64_t)lo | (((uint64_t)hi) << 32);
}

static inline void set_pcid(uint64_t pcid)
{
    if(pcid < 4095)
        asm volatile("mov %%cr3, %%rbx; andq $-4096, %%rbx; or %0, %%rbx; mov %%rbx, %%cr3;"::"g"(pcid):"memory", "rbx", "rax");
    else
        PANIC();
}

static inline unsigned long read_msr(unsigned int msr)
{
	uint32_t low, high;

	asm volatile("rdmsr" : "=a" (low), "=d" (high) : "c" (msr));
	return low | ((unsigned long)high << 32);
}

static inline void write_msr(unsigned int msr, unsigned long val)
{
	asm volatile("wrmsr"
		: /* no output */
		: "c" (msr), "a" (val), "d" (val >> 32)
		: "memory");
}

static inline uint64_t read_fsbase()
{
    uint64_t val;
	asm volatile("rdfsbase %0"
		: "=r" (val)
		: /* no output */
		: "memory");

    return val;
}

static inline void write_fsbase(unsigned long val)
{
	asm volatile("wrfsbase %0"
		: /* no output */
		: "r" (val)
		: "memory");
}

static inline uint64_t read_gsbase()
{
    uint64_t val;
	asm volatile("rdgsbase %0"
		: "=r" (val)
		: /* no output */
		: "memory");

    return val;
}

static inline void write_gsbase(unsigned long val)
{
	asm volatile("wrgsbase %0"
		: /* no output */
		: "r" (val)
		: "memory");
}


/* Return stack pointer */

static inline uint64_t up_getrsp()
{
  uint64_t regval;

  asm volatile(
    "\tmovq %%rsp, %0\n"
    : "=rm" (regval)
    :
    : "memory");
  return regval;
}

/* Get segment registers */

static inline uint32_t up_getds()
{
  uint32_t regval;

  asm volatile(
    "\tmov %%ds, %0\n"
    : "=rm" (regval)
    :
    : "memory");
  return regval;
}

static inline uint32_t up_getcs()
{
  uint32_t regval;

  asm volatile(
    "\tmov %%cs, %0\n"
    : "=rm" (regval)
    :
    : "memory");
  return regval;
}

static inline uint32_t up_getss()
{
  uint32_t regval;

  asm volatile(
    "\tmov %%ss, %0\n"
    : "=rm" (regval)
    :
    : "memory");
  return regval;
}

static inline uint32_t up_getes()
{
  uint32_t regval;

  asm volatile(
    "\tmov %%es, %0\n"
    : "=rm" (regval)
    :
    : "memory");
  return regval;
}

static inline uint32_t up_getfs()
{
  uint32_t regval;

  asm volatile(
    "\tmov %%fs, %0\n"
    : "=rm" (regval)
    :
    : "memory");
  return regval;
}

static inline uint32_t up_getgs()
{
  uint32_t regval;

  asm volatile(
    "\tmov %%gs, %0\n"
    : "=rm" (regval)
    :
    : "memory");
  return regval;
}
/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* These are defined in intel64_head.S */
extern volatile uint8_t pdpt_low;
extern volatile uint8_t pd_low;
extern volatile uint8_t pt_low;

extern volatile uint8_t ist64_low;
extern volatile uint8_t gdt64_low;
extern volatile uint8_t gdt64_ist_low;
extern volatile uint8_t gdt64_low_end;

/* The actual address of the page table and gdt/ist after mapping the kernel in high address*/
volatile uint64_t* pdpt;
volatile uint64_t* pd;
volatile uint64_t* pt;

volatile uint32_t* ist64;
volatile uint64_t* gdt64;
volatile uint64_t* gdt64_ist;

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

int up_map_region(void* base, int size, int flags);
void x86_64_check_and_enable_capability(void);

extern void __enable_sse3(void);
extern void __enable_pcid(void);

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

void idt_flush(uint32_t idt_addr);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_X86_64_INCLUDE_INTEL64_ARCH_H */
