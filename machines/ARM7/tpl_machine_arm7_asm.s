/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * ARM7 port is copyright (c) ESEO 2007+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline ARM7 specifics
 *
 * $Date: 2008/07/21 13:01:11 $
 * $Rev$
 * $Author: JonathanIlias $
 * $URL$
 */


.text 
.align 2

.global tpl_shutdown
.global tpl_switch_context
.global tpl_switch_context_from_it
.global tpl_get_task_lock
.global tpl_release_task_lock

tpl_shutdown:
	/* remove ITs */
	STR	R0,[R13,#-4]!
	MRS	R0,CPSR
	ORR	R0,R0,#0b01100000
	MSR	CPSR,R0
	LDR	R0,[R13],#4
	/*il faut predecrementer pour stocker et post incrementer pour remettre*/
	/* TODO: update to set idle mode.*/
	foo:
		B foo

tpl_switch_context:
	
	CMP	R0,#0
	BEQ     nosave
	/*Save the current context in the old context  */
		/* old_context  get the context */
	LDR R0,[R0]
	STMIA R0,{R0-R14}
	MRS	R2,CPSR
	STR	R2,[R0,#60]
	BIC	R2,R2,#0x1F		/*clear mode bits*/
	ORR	R2,R2,#0x10		/*select user mode*/
	MSR	CPSR,R2	/*enter user mode*/

		/*
         * restore the current context to the new context
         */         
nosave:
	LDR	R2,[R1,#60]
	MSR	CPSR,R2	
	LDR R1,[R1]
	LDMIA R1,{R0-R14}
	/*that's all folks*/
	MOV	PC,LR

tpl_switch_context_from_it:
	CMP	R0,#0
	BEQ     nosave_it
	/* Save the current context in the old context  */
		/* old_context  get the context */
	LDR R0,[R0]
	STMIA	R0,{R0-R14}
	MRS	R2,CPSR
	STR	R2,[R0,#60]
	BIC	R2,R2,#0x1F		/*clear mode bits*/
	ORR	R2,R2,#0x10		/*select user mode*/
	MSR	CPSR,R2	/*enter user mode*/

		/*
         * restore the current context to the new context
         */         
nosave_it:
	LDR	R2,[R1,#60]
	MSR	CPSR,R2	
	LDR R1,[R1]
	LDMIA	R1,{R0-R14}
	/*that's all folks*/
	MOV	PC,LR
	/*that's all folks*/


tpl_get_task_lock:

	STR	R0,[R13,#-4]!
	MRS	R0,CPSR
	ORR	R0,R0,#0b1100000
	MSR	CPSR,R0;
	LDR	R0,[R13],#4
	MOV	PC,LR

tpl_release_task_lock:

	STR	R0,[R13,#-4]!
	MRS	R0,CPSR
	AND	R0,R0,#0b0011111
	MSR	CPSR,R0
	LDR	R0,[R13],#4
	MOV	PC,LR

	



