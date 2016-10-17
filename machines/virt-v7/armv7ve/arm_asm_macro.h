/**
 * Copyright (c) 2010 Anup Patel.
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
 * @file arm_asm_macros.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief  common assembly macros
 */
#ifndef __ARM_ASM_MACRO_H__
#define __ARM_ASM_MACRO_H__

#include <arm_defines.h>

#ifdef __ASSEMBLY__

.macro TRACE fun
  push {r0-r12,lr}
  bl \fun
  pop {r0-r12,lr}
.endm

.macro TRACEREG reg
  // push {r0-r12,lr}
  // mov r0, \reg
  // bl tracereg
  // pop {r0-r12,lr}
.endm

.macro TRACEKERN
  // push {r0-r12,lr}
  // bl tracekern
  // pop {r0-r12,lr}
.endm

.macro SET_CURRENT_FLAGS flags, treg
	mrs	\treg, cpsr
	orr	\treg, \treg, #(\flags)
	msr 	cpsr, \treg
.endm

.macro SET_CURRENT_MODE mode
	cps	#(\mode)
.endm

.macro SET_CURRENT_STACK new_stack
	ldr	sp, \new_stack
.endm

.macro START_EXCEPTION_HANDLER irqname, lroffset
	.align 5
\irqname:
	sub	lr, lr, #\lroffset
.endm

/* Save User Registers */
.macro PUSH_USER_REGS
	str     lr, [sp, #-4]!;         /* Push the return address */
	sub     sp, sp, #(4*15);        /* Adjust the stack pointer */
	stmia   sp, {r0-r12};           /* Push user mode registers */
	add     r0, sp, #(4*13);        /* Adjust the stack pointer */
	stmia   r0, {r13-r14}^;         /* Push user mode registers */
	mov     r0, r0;                 /* NOP for previous inst */
	mrs     r0, spsr_all;           /* Put the SPSR on the stack */
	str     r0, [sp, #-4]!
.endm

/* Save User Registers in FIQ */
.macro PUSH_FIQUSER_REGS
	str     lr, [sp, #-4]!;         /* Push the return address */
	sub     sp, sp, #(4*15);        /* Adjust the stack pointer */
	stmia   sp, {r0-r7};            /* Push user mode registers */
	add     r0, sp, #(4*8);         /* Adjust the stack pointer */
	stmia   r0, {r8-r14}^;          /* Push user mode registers */
	mov     r0, r0;                 /* NOP for previous inst */
	mrs     r0, spsr_all;           /* Put the SPSR on the stack */
	str     r0, [sp, #-4]!
.endm

/* Call C function to handle exception */
.macro CALL_EXCEPTION_CFUNC cfunc
  push {r0-r12,lr}
	mov	r0, sp
	bl	\cfunc
  pop {r0-r12,lr}
.endm

/* Restore User Registers */
.macro PULL_USER_REGS
	ldr     r0, [sp], #0x0004;      /* Get SPSR from stack */
	msr     spsr_all, r0;
	ldmia   sp, {r0-r14}^;          /* Restore registers (user) */
	mov     r0, r0;                 /* NOP for previous isnt */
	add     sp, sp, #(4*15);        /* Adjust the stack pointer */
	ldr     lr, [sp], #0x0004       /* Pull return address */
.endm

.macro END_EXCEPTION_HANDLER
	movs	pc, lr
.endm

#endif /* __ASSEMBLY__ */

#endif
