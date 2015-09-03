#include <avr/io.h>
.section .text

#include "tpl_asm_definitions.h"

/**
 * @file avr_switch_context.s
 * initial version Guillaume Forget - 04/2008
 * major update M. Briday - 10/2014
 */

 /*  first argument is a pointer to the old context (i.e. a pointer to tpl_context) -> R25:R24
  * second argument is a pointer to the new context (i.e. a pointer to tpl_context) -> R22:R23
  * no output
  */
.global tpl_switch_context
.global tpl_switch_context_from_it 
tpl_switch_context:
tpl_switch_context_from_it:
	/* push r16 and the sreg register on the stack */
	push r16
	in   r16, _SFR_IO_ADDR(SREG)
	push r16 //push sreg

	/* verification if the first parameter is equal to 0 (Old_context == NULL)*/
	ldi r16, 0 /* ldi requires a reg number > 15 */
	cp r16, r24 //low byte of address
	breq first_part_equal // if the first 8 bits are null jump to first_part_equal
	rjmp save_context // else jump to save_context

first_part_equal :
	cp r16, r25 //high byte of address
	breq unsave_context // if the second part is null Old_context == NULL then jump to unsave_context
	
	/* we have to save the old context*/
save_context :

	/* put all register on the stack */
	//push r0
	//push r1
	push r2
	push r3
	push r4
	push r5
	push r6
	push r7	
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
	/* push r16 done */
	push r17	
	//push r18
	//push r19
	//push r20
	//push r21
	//push r22
	//push r23
	//push r24
	//push r25
	//push r26
	//push r27	
	push r28
	push r29
	//push r30
	//push r31

	/* save the old stack pointer */
	/* R24 is a pointer on the old context (tpl_context *) */
	movw r28,r24 // mov R24 to Y (r29:r28)
	ldd  r30,Y+0 // dereference to Z (got tpl_context, which is a avr_context *) 
	ldd  r31,Y+1
	in   r26, _SFR_IO_ADDR(SPL) //get the actual SP into X (r27:r26)
	in   r27, _SFR_IO_ADDR(SPH)
	std  Z+0, r26 //save SP into the first field of the old context.
	std  Z+1, r27

	//push 2 dummy regs, because r0 and sreg have been pushed in all cases
	push r16
	push r16
unsave_context : // we have pushed 2 registers on the stack, we have to pop them

	pop r16
	pop r16

	/* Get the new stack pointer */
    // the adress of the new tpl_context is in r22,r23
	// mov it to Z (r31:r30)
    movw r30,r22 // the adress of the new stack pointer is in r22,r23
	// we have to dereference it => got a avr_context*
    ldd  r28,Z+0
	ldd  r29,Z+1
    ldd  r30,Y+0
	ldd  r31,Y+1

	/* put the new stack pointer */
	out _SFR_IO_ADDR(SPL), r30
	out _SFR_IO_ADDR(SPH), r31 

	/* Get all register from the stack */
	//pop r31
	//pop r30
	pop r29
	pop r28
	//pop r27
	//pop r26
	//pop r25
	//pop r24
	//pop r23
	//pop r22
	//pop r21
	//pop r20
	//pop r19
	//pop r18
	pop r17
	/* pop r16 at the end */
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop r7
	pop r6
	pop r5
	pop r4
	pop r3
	pop r2
	//pop r1
	//pop r0
	/* get sreg register and r16 from the stack */
	pop r16
	out _SFR_IO_ADDR(SREG), r16
	/* and last register */
	pop r16

	ret


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
	

