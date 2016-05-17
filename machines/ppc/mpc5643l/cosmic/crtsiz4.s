/*
 * @file tpl_init_mmu.s
 *
 * @section desc File description
 *
 * C STARTUP CODE WITH DATA INITIALIZATION
 *
 * Copyright (c) 2010 by COSMIC Software
 * Modified by Kamel Hacene for Trampoline OS
 *
 * Trampoline OS
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */
	xdef	_exit, _tpl_master_core_startup
	xref.l	_main, __sdata, __sram, __eram, __idesc__
    xref _tpl_reset_registers
    xref _tpl_init_mmu
    xref __stack_addr
;
;.osCode:	section	.text
#define OS_START_SEC_CODE
#include "AsMemMap.h"

;
atab:
	dc.l	__sdata			; init value of data pointer
	dc.l	__sram-4		; start of ram to clear
	dc.l	__eram-4		; end of ram to clear
	dc.l	__stack_addr			; init value of stack pointer
	dc.l	__idesc__		; descriptor start address
_tpl_master_core_startup:

    bl _tpl_reset_registers
    bl _tpl_init_mmu

	lis	    r31,.atab		; get table
	addi	r31,.atab		; address
	lwz	    r1,12(r31)		; initialize SP
	lwz	    r13,0(r31)		; initialize DP
	lwz	    r5,8(r31)		; get end of ram
	lwz	    r4,4(r31)		; get start of ram
;;;;;;;;;;;;;; CLEAR RAM
	sub.	r5,r4			; byte size
	beq	init			    ; empty, skip
	srwi	r5,2			; word size
	li	r0,0			    ; to clear the bss
	mtctr	r5			    ; set counter
zbcl:
	stwu	r0,4(r4)		; clear memory
	bdnz	zbcl			; count down and loop back
;;;;;;;;;;;;;; COPY INITIALIZED DATA
init:
	lwz	r4,16(r31)		; descriptor address
	lwz	r5,0(r4)		; first image address
idbcl:
	subi	r5,4			; adjust address
dbcl:
	lwzu	r2,4(r4)		; get flag word
	cmpi	r2,0			; test flag
	beq	start			; end continue
	andis.	r2,$6000		; test for moveable code segment
	beq	skip			; yes, skip it
	lwzu	r6,4(r4)		; ram start address
	lwzu	r2,4(r4)		; code end address
	subi	r2,4			; adjust address
	sub	r2,r5			; block size
	srwi	r2,2			; word size
	mtctr	r2
	subi	r6,4			; adjust address
cbcl:
	lwzu	r0,4(r5)		; get and
	stwu	r0,4(r6)		; store
	bdnz	cbcl			; count down and loop back
	b	dbcl			; next segment
skip:
	lwzu	r5,8(r4)		; load next code address
	b	idbcl			; and loop back
start:
	bl	_main			; execute main
_exit:
	b	_exit			; stay here
;
	end


#define OS_STOP_SEC_CODE
#include "AsMemMap.h"

