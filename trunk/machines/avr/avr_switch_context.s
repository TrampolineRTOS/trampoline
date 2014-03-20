#include <avr/io.h>

.section .text

/**
 * @file avr_switch_context.s
 *
 * @section File informations
 * initial file from Guillaume Forget. Copyright IRCCyN 2008-
 * $Date: 2008-07-29 11:06:28 +0200 (lun., 28 avr. 2008) $
 * $Rev: 500 $
 * $Author: gforget $
 * $URL: https://trampoline.rts-software.org/svn/trunk/os/os_machine/avr/avr_switch_context.s $
 *
 */

.global tpl_switch_context
.global tpl_switch_context_from_it 
tpl_switch_context:
tpl_switch_context_from_it:
	/* push r16 and the sreg register on the stack */
	push r16
	in   r16, _SFR_IO_ADDR(SREG)
	push r16

	/* verification if the first parameter is equal to 0 (Old_context == NULL)*/
	ldi r16, 0
	cp r16, r24
	breq first_part_equal // if the first 8 bits are null jump to first_part_equal
	rjmp save_context // else jump to save_context

first_part_equal :
	cp r16, r25
	breq unsave_context // if the second part is null Old_context == NULL then jump to unsave_context
	
	/* we have to save the old context*/
save_context :

	/* put all register on the stack */
	push r31
	push r30
	push r29
	push r28
	push r27
	push r26
	push r25	
	push r24
	push r23
	push r22
	push r21
	push r20
	push r19
	push r18
	push r17
	// r16 is pushed at the start of the function
	push r15
	push r14
	push r13
	push r12
	push r11
	push r10
	push r9
	push r8
	push r7
	push r6
	push r5
	push r4
	push r3
	push r2
	push r1
	push r0


	/* save the old stack pointer */
	/* R24 is a pointer on the old context. */
	movw r28,r24 // mov R24 to Y.
	ldd  r30,Y+0 // dereference to access the first field
	ldd  r31,Y+1
	in   r26, _SFR_IO_ADDR(SPL) //save the Stack pointer into Z (through X)
	in   r27, _SFR_IO_ADDR(SPH)

	adiw r26,0x21 // we add 21 to the old stack pointer because we have done 0x21 pushs 

	std  Z+0, r26 //save (updated) SP into the first field of the old context.
	std  Z+1, r27

	// we make a "for" loops for(r24=0;r24<=r25;r24++)
	ldi  r24,0x00
	ldi  r25,0x21
	
	adiw r30,0x01 //because SP is 16 bits wide.

less1 :
	pop  r26 // we take a register
	adiw r30,0x01 // we increment the address
	std  Z+0,r26 // we put the register on the chart

	inc  r24 // r24++
	cp   r24,r25 
	brlt less1 // if r24<=r25 jump to less1

	push r16
	push r16
unsave_context : // we have pushed 2 registers on the stack, we have to pop them

	pop r16
	pop r16

	/* Get the new stack pointer */
    movw r28,r22 // the adress of the new stack pointer is in r22,r23
	// we have to dereference it
	ldd  r30,Y+0
	ldd  r31,Y+1
    ldd  r28,Z+0
	ldd  r29,Z+1

	/* put the new stack pointer */
	out _SFR_IO_ADDR(SPL), r28
	out _SFR_IO_ADDR(SPH), r29 

	// we make a "for" loops for(r24=0;r24<=r25;r24++)
	ldi  r24,0x00
	ldi  r25,0x21
	adiw r30,0x23 // here we fill the tab by the end

less2 :
	sbiw r30,0x01 
	ldd  r26,Z+0 // get the old value of the register from the chart
	push r26 // push the register

	inc  r24 // r24++
	cp   r24,r25
	brlt less2 // if r24<=r25 jump to less2

	/* Get all register from the stack */
	pop r0
	pop r1
	pop r2
	pop r3
	pop r4
	pop r5
	pop r6
	pop r7
	pop r8
	pop r9
	pop r10
	pop r11
	pop r12
	pop r13
	pop r14
	pop r15
	// r16 is pop at the end of the function
	pop r17
	pop r18
	pop r19
	pop r20
	pop r21
	pop r22
	pop r23
	pop r24
	pop r25
	pop r26
	pop r27
	pop r28
	pop r29
	pop r30
	pop r31


	/* get sreg register and r16 from the stack */
	pop r16
	out _SFR_IO_ADDR(SREG), r16
	pop r16

	ret
