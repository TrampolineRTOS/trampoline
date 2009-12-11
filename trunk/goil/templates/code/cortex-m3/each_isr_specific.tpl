/*	_______________________________________________________________________
 * ISR2 $EXEC_NAME$ stacks
 *
 * System stack
 */
tpl_stack_word  $SYS_STACK_ZONE$[$SYS_STACK_SIZE$/sizeof(tpl_stack_word)];


#define $EXEC_STACK$ { $SYS_STACK_ZONE$, $SYS_STACK_SIZE$}

/* 
 * ISR2 $EXEC_NAME$ Handler that calls the central handler
 */

/*
//#include <C167CS.H> //TODO: C166 
#pragma NOFRAME
#pragma warning disable = 138 // disables the "expression with possibly no effect" warning 
void $EXEC_NAME$_handler(void) interrupt $TRAP_NUMBER$
{
	__asm {
		BCLR IEN //disable interrupt *
		SCXT DPP3, #3
		NOP
		SCXT CP,#registers_it
		NOP
		MOV R0,0xfe12 
		MOV R0,[R0] //get R0<-CP
		MOV R0,[R0] //get the previous user stack.
		NOP
		PUSH DPP0
	}
	tpl_central_interrupt_handler(isr_id_of_$EXEC_NAME$);
	// dummy code to allow the use of registers_it in
	// the assembly code
	//
	if(registers_it[0]);
	__asm {
		POP DPP0
		POP CP
		POP DPP3
	}

}
*/

/*
 * ISR2 $EXEC_NAME$ context
 */
cm3_context $EXEC_INTEGER_CONTEXT$;

#define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$ }
