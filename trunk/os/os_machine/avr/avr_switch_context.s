#include <avr/io.h>

.section .text

/*
	organization of the stack

	 __ __ __ __
	|           |
	| Program   |
	| Counter   |
	|__ __ __ __|
	|           |
	| Program   |
	| Counter   |
	|__ __ __ __|
	|           |
	|   r16     |
	|           |
	|__ __ __ __|
	|           |
	|   SREG    |
	|           |
	|__ __ __ __|
	|           |
	| register  |
	| r0 to r15 |
	|__ __ __ __|
	|           |
	| register  |
	|r17 to r31 |
	|__ __ __ __|
	|           |
	|           |
	|           |

	the stack pointer is save in the task structure

*/

.global tpl_switch_context
.global tpl_switch_context_from_it 
tpl_switch_context:
tpl_switch_context_from_it:

	/* put r16 and the sreg register on the stack */
	push r16
	in r16, _SFR_IO_ADDR(SREG)
	push r16

	/* verification if the first parameter is equal to 0 (Old_context == NULL)*/
	ldi r16, 0
	cp r16, r24
	breq equal1
	rjmp not_equal
	equal1 : nop
	cp r16, r25
	breq equal
	not_equal : nop

	/* put all register on the stack */
	push r0
	push r1
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

	push r17
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r28
	push r29
	push r30
	push r31

	/* save the old stack pointer */
	movw r28,r24
	ldd r30,Y+0
	ldd r31,Y+1
	in r26, _SFR_IO_ADDR(SPL)
	in r27, _SFR_IO_ADDR(SPH)
	std Z+0, r26
	std Z+1, r27
   
	push r16
	push r16
equal : nop
	pop r16
	pop r16

	/* Get the new stack pointer */
    movw r28,r22
	ldd r30,Y+0
	ldd r31,Y+1
    ldd r28,Z+0
	ldd r29,Z+1
	out _SFR_IO_ADDR(SPL), r28
	out _SFR_IO_ADDR(SPH), r29 

	/* Get all register from the stack */
	pop r31
	pop r30
	pop r29
	pop r28
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r17

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
	pop r1
	pop r0

	/* get sreg register and r16 from the stack */
	pop r16
	out _SFR_IO_ADDR(SREG), r16
	pop r16

	ret
