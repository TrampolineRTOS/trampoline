extern unsigned int registers_it[16]; 

/*
 * ISR2 $EXEC_NAME$ stacks
 *
 * System stack
 */
tpl_stack_word idata $SYS_STACK_ZONE$[$SYS_STACK_SIZE$/sizeof(tpl_stack_word)];

/*
 * User stack
 */
tpl_stack_word $USR_STACK_ZONE$[$USR_STACK_SIZE$/sizeof(tpl_stack_word)];

#define $EXEC_STACK$ { $SYS_STACK_ZONE$, $SYS_STACK_SIZE$, $USR_STACK_ZONE$, $USR_STACK_SIZE$ }

/* 
 * ISR2 $EXEC_NAME$ Handler that calls the central handler
 */
#pragma NOFRAME
#pragma warning disable = 138 /* disables the "expression with possibly no effect" warning */
void $EXEC_NAME$_handler(void) interrupt 32
{
	#pragma asm
		BCLR IEN /*disable interrupt */
		SCXT DPP3, #3
		NOP
		SCXT CP,#registers_it
		NOP
		MOV R0,0xfe12 
		MOV R0,[R0] //get R0<-CP
		MOV R0,[R0] //get the previous user stack.
		NOP
		PUSH DPP0
	#pragma endasm
	tpl_central_interrupt_handler($EXEC_NAME$);
	/* dummy code to allow the use of registers_it in
	 * the assembly code
	 */
	if(registers_it[0]);
	#pragma asm
		POP DPP0
		POP CP
		POP DPP3
	#pragma endasm
}

/*
 * ISR2 $EXEC_NAME$ context
 */
c167_context $EXEC_INTEGER_CONTEXT$;

#define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$ }

