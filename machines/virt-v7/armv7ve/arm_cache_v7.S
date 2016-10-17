/**
 * Copyright (c) 2014 Anup Patel.
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
 * @file arm_cache_v7.S
 * @author Anup Patel (anup@brainfault.org)
 * @brief ARMv7 cache operations
 */

#include <arm_asm_macro.h>

/*
 * dcache_line_size - get the minimum D-cache line size from the CTR register
 * on ARMv7.
 */
.macro	dcache_line_size, reg, tmp
	mrc	p15, 0, \tmp, c0, c0, 1		@ read ctr
	lsr	\tmp, \tmp, #16
	and	\tmp, \tmp, #0xf		@ cache line size encoding
	mov	\reg, #4			@ bytes per word
	mov	\reg, \reg, lsl \tmp		@ actual cache line size
.endm

/* 
 * Generic mechanism for operations on the entire data or unified cache to the Point
 * of Coherence. This code is taken from 'Example code for cache maintenance operations'
 * provided in "ARM Architecture Reference Manual ARMv7-A and ARMv7-R edition 
 * (ARM DDI 0406)". 
 * Registers r0 - r9 are used.
 */
#define ARM_ENTIRE_DCACHE_OP(crm) 	\
					\
        stmfd   sp!, {r0-r9}		/* save registers */;\
					\
	mrc 	p15, 1, r0, c0, c0, 1  	/* Read CLIDR */;\
	ands	r3, r0, #0x7000000 	;\
	mov 	r3, r3, LSR #23 	/* Cache level value (naturally aligned) */; \
	beq 	5f 			;\
	mov 	r8, #0 		;\
1: 					;\
	add 	r2, r8, r8, LSR #1 	/* Work out 3xcachelevel */; \
	mov 	r1, r0, LSR r2 		/* bottom 3 bits are the Cache type for this level */; \
	and 	r1, r1, #7		/* get those 3 bits alone */; \
	cmp 	r1, #2			;\
	blt 	4f 			/* no cache or only instruction cache at this level */; \
	mcr 	p15, 2, r8, c0, c0, 0 	/* write the Cache Size selection register */; \
	isb 				/* isb to sync the change to the CacheSizeID reg */; \
	mrc 	p15, 1, r1, c0, c0, 0 	/* reads current Cache Size ID register */; \
	and 	r2, r1, #7 		/* extract the line length field */; \
	add 	r2, r2, #4 		/* add 4 for the line length offset (log2 16 bytes) */; \
	ldr 	r4, =0x3FF		;\
	ands	r4, r4, r1, LSR #3 	/* r4 is the max number on the way size (right aligned) */; \
	clz 	r5, r4 			/* r5 is the bit position of the way size increment */; \
	ldr 	r6, =0x00007FFF		;\
	ands	r6, r6, r1, LSR #13 	/* r6 is the max number of the index size (right aligned) */; \
2: 					;\
	mov 	r7, r4 			/* r7 working copy of the max way size (right aligned) */; \
3:					;\
	orr 	r9, r8, r7, LSL r5 	/* factor in the way number and cache number into r9 */; \
	orr 	r9, r9, r6, LSL r2 	/* factor in the index number */; \
	mcr 	p15, 0, r9, c7, crm, 2 /* clean by set/way */; \
	subs	r7, r7, #1 		/* decrement the way number */; \
	bge 	3b			;\
	subs 	r6, r6, #1 		/* decrement the index */; \
	bge 	2b			;\
4:					;\
	add 	r8, r8, #2 		/* increment the cache number */; \
	cmp 	r3, r8			;\
	bgt 	1b			;\
					\
5:					;\
	ldmia   sp!, {r0-r9}		/* restore registers */;

	/* clean the entire data cache */	
	.globl arm_clean_dcache
arm_clean_dcache:
	ARM_ENTIRE_DCACHE_OP(c10) 	/* clean all */
	dsb
	isb
	bx	lr

	/* clean & invalidate the entire data cache */	
	.globl arm_clean_invalidate_dcache
arm_clean_invalidate_dcache:
	ARM_ENTIRE_DCACHE_OP(c14) 	/* clean and invalidate all */
	dsb
	isb
	bx	lr

	/* clean by memory region by mva range 
	 *  r0 - start address of region
	 *  r1 - end address of region
	 */
	.globl arm_clean_dcache_mva_range
arm_clean_dcache_mva_range:
	push	{r0, r1, r2, r3}
	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r0, r0, r3
1:
	mcr     p15, 0, r0, c7, c10, 1
	add	r0, r0, r2
	cmp	r0, r1
	blo	1b
	dsb
	isb
	pop	{r0, r1, r2, r3}
	bx	lr

	/* clean and invalidate a memory region by mva
	 *  r0 - start address of region
	 *  r1 - end address of region
	 */
	.globl arm_clean_invalidate_dcache_mva_range
arm_clean_invalidate_dcache_mva_range:
	push	{r0, r1, r2, r3}
	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r0, r0, r3
1:
	mcr	p15, 0, r0, c7, c14, 1		/* clean & invalidate D / U line */
	add	r0, r0, r2
	cmp	r0, r1
	blo	1b
	dsb
	isb
	pop	{r0, r1, r2, r3}
	bx	lr

	/* invalidate the entire i-cache */
	.globl arm_invalidate_icache
arm_invalidate_icache:
	push	{r0}
	mov	r0, #0
	mcr     p15, 0, r0, c7, c5, 0 	/* invalidate all */
	isb
	pop	{r0}
	bx	lr


