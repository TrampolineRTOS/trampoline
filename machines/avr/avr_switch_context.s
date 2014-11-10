#include <avr/io.h>

.section .text

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