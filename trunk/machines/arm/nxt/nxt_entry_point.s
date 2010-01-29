/*
   nxt_entry_point.s

   This assembly code is used for executing a nxtOSEK
   application in John Hansen's enhanced NXT standard firmare
   and this approach is developed by Sivan Toledo.
   Takashi Chikamasa, May 2008

   Sivan Toledo, May 2008
   to enable calling a native AT91SAM7 program 
   from the NXT's firmware, using a modification
   implemented by John Hansen.
   
   The NXT firmware recognizes a native file by the
   string "NXTBINARY" at the beginning of the file.
   To keep the changes in the NXT's firmware minimal,
   the file name must be .rxe (same as the stadard
   NXT binaries which are for a virtual machine).
   
   When the NXT's firmware recognizes a native file,
   it calls a function at offset X in the file, where
   X is the 32-bit number stored in offset 12 in the file.
   The firmware passes two arguments to the function: the 
   address of the file in flash, and the length of the file. 

    The code in this file uses the arguments (location and size
    of the native file) to relocate the file (except for the first 16
    bytes, which are a header) to the beginning of RAM, initialize
    the AT91SAM7S, and initialize the C environment (stack and variables
    that initialized to zero).
*/

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	.global NXT_Entry_Point

	.text
	.code 32
	.align 	0

/*
 * nxtOSEK application is stored as a file in NXT's enhanced firmware
 * and it needs to be re-allocated to RAM to make the address
 * deterministic.
 * r0: the address of the file in Flash
 * r1: the length of the file
 */
NXT_Entry_Point:
    /*added by fp*/
    
	/* globally disable interrupts */
	STMDB	SP!, {R0}		/* Push R0.						*/
	MRS	R0, CPSR			/* Get CPSR.					*/
	ORR	R0, R0, #0xC0		/* Disable IRQ, FIQ.			*/
	MSR	CPSR, R0			/* Write back modified value.	*/
	LDMIA	SP!, {R0}		/* Pop R0.						*/

Copier:
 	add	r2, r0, r1      @ r2 now holds the address just beyond
 	                    @ the end of this binary file
 	mov	r1, #2097152	@ 0x200000, beginning of RAM
 	add	r0, r0, #16	    @ skip the header!

 	b	CopierCompare
CopierLoop:
  	ldr	r3, [r0], #4
   	str	r3, [r1], #4
CopierCompare:
  	cmp	r0, r2
   	bcc	CopierLoop
   		
JumpToResetVector:
 	mov	PC, #2097152
