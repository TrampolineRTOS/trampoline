#include <avr/io.h>
.section .text

#include "tpl_asm_definitions.h"

/**
 * @file avr_switch_context.s
 * initial version Guillaume Forget - 04/2008
 * major update M. Briday - 10/2014
 */

//************ new version **********
/** We have to save the context.
 * The current stack is the one of kernel stack.
 * On the user stack there is already:
 *  _______ 
 * |  @ret |  \
 * |  @ret |   |> return address from service call with 2 or 3 bytes.
 * |  @ret |  /
 * |  R2   | 
 * |  R3   | 
 * |  R4   | 
 * |  R5   | 
 * |  R6   | 
 * |  R7   | 
 * |  SREG | 
 * |  R28  | 
 * |  R29  | 
 * |       | <- User SP
 * 
 * on the Kernel stack, we have the current return address (2 or 3 bytes)
 * and the user stack pointer.
 *  ________ 
 * |  @ret  |  \
 * |  @ret  |   |> return address of this function with 2 or 3 bytes.
 * |  @ret  |  /
 * |        | <- Kernel SP
 * function uses r0, r30,r31
 */
.global tpl_avr_save_context
tpl_avr_save_context:
	//User SP is in Y.
//	//we have to set in Z the User SP (stored in kernel stack)
//	//first get the user SP address in X (r26:r27)
//	in r26,_SFR_IO_ADDR(SPL)
//	in r27,_SFR_IO_ADDR(SPH)
//#ifdef __AVR_3_BYTE_PC__
//	adiw r26,4
//#else
//	adiw r26,3
//#endif
//	ld r31,X+
//	ld r30,X
//	sbiw r26,1
//	//ok, User SP is in Z.
	/* The store (st) is pre-decremented, but the push is post-decremented.
	 * we have to init with +1
	 */
	adiw r28,1
	//Ok Now, save r8 -> r17 according to ABI
	st -Y,r8
	st -Y,r9
	st -Y,r10
	st -Y,r11
	st -Y,r12
	st -Y,r13
	st -Y,r14
	st -Y,r15
	st -Y,r16
	st -Y,r17
	sbiw r28,1 //sub 1 because push is post-decremented.
	//store the User SP in the context of the running task.
	//first, get the static desc.
	lds r30,tpl_kern+TPL_KERN_OFFSET_S_RUNNING
	lds r31,tpl_kern+TPL_KERN_OFFSET_S_RUNNING+1
	//then get the tpl_context (dereference to Z)
	ldd r0,Z+0
	ldd r31,Z+1
	mov r30,r0
	//save Y (user SP) in tpl_context.
	std Z+0, r28
	std Z+1, r29
	ret

/** We have to restore the context.
 * The current stack is the one of kernel stack.
 * On the user stack should be like this:
 *  _______ 
 * |  @ret |  \
 * |  @ret |   |> return address with 2 or 3 bytes.
 * |  @ret |  /
 * |  R2   | 
 * |  R3   | 
 * |  R4   | 
 * |  R5   | 
 * |  R6   | 
 * |  R7   | 
 * |  SREG | 
 * |  R8   | 
 * |  R9   | 
 * |  R10  | 
 * |  R11  | 
 * |  R12  | 
 * |  R13  | 
 * |  R14  | 
 * |  R15  | 
 * |  R16  | 
 * |  R17  | 
 * |  R28  | 
 * |  R29  | 
 * |       | <- User SP
 * 
 * on the Kernel stack, we have the current return address (2 or 3 bytes)
 * and the user stack pointer.
 *  ________________ 
 * |  User SP Low   | 
 * |  User SP High  | 
 * |  @ret          |  \
 * |  @ret          |   |> return address with 2 or 3 bytes.
 * |  @ret          |  /
 * |                | <- Kernel SP
 * function uses r0, r30,r31
 */
.global tpl_avr_restore_context
tpl_avr_restore_context:
	//we have to set in Y the User SP (stored in the context of the elected task)
	//first, get a pointer to the static context of elected task in Y
	lds r28,tpl_kern+TPL_KERN_OFFSET_S_ELECTED
	lds r29,tpl_kern+TPL_KERN_OFFSET_S_ELECTED+1
	//then get the pointer to the tpl_context (dereference to Z)
	ldd r30,Y+0
	ldd r31,Y+1
	//...to get the user SP in Y
	ldd r28,Z+0
	ldd r29,Z+1
	//ok, User SP is in Y.
	/* The load (st) is post-incremented, but the pop is pre-incremented
	 * we have to init with +1
	 */
	adiw r28,1
	ld r17,Y+
	ld r16,Y+
	ld r15,Y+
	ld r14,Y+
	ld r13,Y+
	ld r12,Y+
	ld r11,Y+
	ld r10,Y+
	ld r9,Y+
	ld r8,Y+
	sbiw r28,1 //sub 1 because pop is pre-incremented.
	ret
	

