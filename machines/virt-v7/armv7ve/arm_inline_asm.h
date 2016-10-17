/**
 * Copyright (c) 2011 Anup Patel.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * @file arm_inline_asm.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief  Frequently required inline assembly macros
 */
#ifndef __ARM_INLINE_ASM_H__
#define __ARM_INLINE_ASM_H__

#include <arm_types.h>

#define read_sctlr()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c1, c0, 0\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_sctlr(val)	__asm__ volatile(\
				" mcr     p15, 0, %0, c1, c0, 0\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define read_dacr()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c3, c0, 0\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_dacr(val)		__asm__ volatile(\
				" mcr     p15, 0, %0, c3, c0, 0\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define read_ttbr0()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c2, c0, 0\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_ttbr0(val)	__asm__ volatile(\
				" mcr     p15, 0, %0, c2, c0, 0\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define read_ttbr1()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c2, c0, 1\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_ttbr1(val)	__asm__ volatile(\
				" mcr     p15, 0, %0, c2, c0, 1\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define read_ttbcr()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c2, c0, 2\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_ttbcr(val)	__asm__ volatile(\
				" mcr     p15, 0, %0, c2, c0, 2\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define read_dfsr()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c5, c0, 0\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_dfsr(val)		asm volatile(\
				" mcr     p15, 0, %0, c5, c0, 0\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define read_ifsr()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c5, c0, 1\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_ifsr(val)		asm volatile(\
				" mcr     p15, 0, %0, c5, c0, 1\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define read_dfar()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c6, c0, 0\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_dfar(val)		asm volatile(\
				" mcr     p15, 0, %0, c6, c0, 0\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define read_ifar()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c6, c0, 2\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_ifar(val)		__asm__ volatile(\
				" mcr     p15, 0, %0, c6, c0, 2\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define invalid_tlb()		({ u32 rval=0; __asm__ volatile(\
				" mcr     p15, 0, %0, c8, c7, 0\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define invalid_tlb_line(va)	__asm__ volatile(\
				" mcr     p15, 0, %0, c8, c7, 1\n\t" \
				:: "r" ((va)) : "memory", "cc")

#define invalid_i_tlb()		({ u32 rval=0; __asm__ volatile(\
				" mcr     p15, 0, %0, c8, c5, 0\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define invalid_i_tlb_line(va)	__asm__ volatile(\
				" mcr     p15, 0, %0, c8, c5, 1\n\t" \
				:: "r" ((va)) : "memory", "cc")

#define invalid_d_tlb()		({ u32 rval=0; __asm__ volatile(\
				" mcr     p15, 0, %0, c8, c6, 0\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define invalid_d_tlb_line(va)	__asm__ volatile(\
				" mcr     p15, 0, %0, c8, c6, 1\n\t" \
				:: "r" ((va)) : "memory", "cc")

#endif
