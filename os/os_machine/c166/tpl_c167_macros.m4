define(`task_context',`dnl
c167_context task_$1_context;')

define(`isr_context',`dnl
c167_context isr2_$1_context;')

define(`task_context_ref',`dnl
&task_$1_context')

define(`isr_context_ref',`dnl
&isr2_$1_context')

define(`stack_ref',`dnl
{task_$1_stack_zone`,'$5`,'task_$1_ustack_zone`,'$6}')

define(`isr_stack_ref',`dnl
{isr2_$1_stack_zone`,'$5`,'isr2_$1_ustack_zone`,'$6}')

define(`AD_task_def',`dnl
/*
 * Task $1 stack
 */

/* system stack */
tpl_stack_word idata task_$1_stack_zone[$5/sizeof(tpl_stack_word)];

/* user stack */
tpl_stack_word task_$1_ustack_zone[$6/sizeof(tpl_stack_word)];')

define(`AD_Global',`dnl
ifdef(`header',`dnl
extern unsigned int idata c167_registers[TASK_COUNT+ISR_COUNT+1][16];
extern unsigned int idata registers_it[16];',`dnl
unsigned int idata c167_registers[TASK_COUNT+ISR_COUNT+1][16];')')

define(`AD_isr_def',`dnl
/*
 * ISR2 $1 stack
 */
extern unsigned int registers_it[16]; 
/* system stack */
tpl_stack_word idata isr2_$1_stack_zone[$5/sizeof(tpl_stack_word)];

/* user stack */
tpl_stack_word isr2_$1_ustack_zone[$6/sizeof(tpl_stack_word)];

/* 
 * ISR2 $1 Handler that calls the central handler
 */
`#'pragma NOFRAME
`#'pragma warning disable = 138 /* disables the "expression with possibly no
									effect" warning */
void $1_handler(void) interrupt $4
{
	`#'pragma asm
		BCLR IEN /*disable interrupt */
		SCXT DPP3`,' `#'3
		NOP
		SCXT CP`,'#registers_it
		NOP
		MOV R0`,'0xfe12 
		MOV R0`,'[R0] //get R0<-CP
		MOV R0`,'[R0] //get the previous user stack.
		NOP
		PUSH DPP0
	`#'pragma endasm
	tpl_central_interrupt_handler($1);
	/* dummy code to allow the use of registers_it in
	 * the assembly code
	 */
	if(registers_it[0]);
	#pragma asm
		POP DPP0
		POP CP
		POP DPP3
	#pragma endasm
}')

define(`AD_isr_addon',`')
