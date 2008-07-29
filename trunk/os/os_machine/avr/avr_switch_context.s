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
	movw r28,r24
	ldd r30,Y+0
	ldd r31,Y+1
	in r26, _SFR_IO_ADDR(SPL)
	in r27, _SFR_IO_ADDR(SPH)
	ADIW r26,0x21
	std Z+0, r26
	std Z+1, r27

	movw    r30,r24
	LDI		r24,0x00
	LDI		r25,0x21
	
	ADIW    R30,0x01

less1 :
	pop		r26
	inc     R24
	ADIW    R30,0x01 	
	STD     Z+0,r26

	CP      r24,r25
	BRLT    less1
   
	push r16
	push r16
equal :
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


	LDI		r24,0x00
	LDI		r25,0x21
	movw    r30,r22
	ADIW    R30,0x23

less2 :
	inc     R24
	SBIW    R30,0x01 
	LDD		r26,Z+0	
	push    r26

	CP      r24,r25
	BRLT    less2

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
