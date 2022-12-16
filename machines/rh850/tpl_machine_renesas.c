#include "tpl_os.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_dispatch_table.h"
#include "iodefine.h" //FSY: usefull?

VAR (tpl_context, OS_VAR) idle_task_context;

VAR(tpl_stack_word, OS_VAR) idle_stack[IDLE_STACK_SIZE/sizeof(tpl_stack_word)];

FUNC (void, OS_CODE) tpl_sleep (void)
{
	while(1);
}

FUNC (void, OS_CODE) tpl_shutdown (void)
{
	while(1);
}

FUNC (void, OS_CODE) tpl_enable_interrupts (void)
{
	__EI();
}

FUNC (void, OS_CODE) tpl_disable_interrupts (void)
{
	__DI();
}

FUNC (void, OS_CODE) tpl_enable_os_interrupts (void)
{
	tpl_enable_interrupts();
}

FUNC (void, OS_CODE) tpl_disable_os_interrupts (void)
{
	tpl_disable_interrupts();
}

FUNC (void, OS_CODE) idle_function (void)
{
	while(1);
}

long lock;

#pragma inline_asm asm_snooze
static void asm_snooze (void)
{
	snooze
}

FUNC (void, OS_CODE) tpl_get_task_lock (void)
{
	u32 res;

Lock:
	res = __ldlw(&lock);
	if(res != 0) {
		asm_snooze();
		goto Lock;
	}

	res = __stcw(&lock, 1);
	if(res == 0) {
		asm_snooze();
		goto Lock;
	}
}

FUNC (void, OS_CODE) tpl_release_task_lock (void)
{
	lock = 0;
}

/**
 * Call Terminate Task function when no TerminateTask hasn't been called
 * or when TerminateTask didn't success because of resource hold or
 * interrupts disabled.
 *
 */
extern FUNC(void, OS_CODE) CallTerminateTask(void);


/**
 * Call Terminate ISR2 function when TerminateISR didn't success doing it
 * because of resource hold or interrupts disabled.
 *
 */
extern FUNC(void, OS_CODE) CallTerminateISR2(void);


FUNC(void, OS_CODE) tpl_init_context(
        CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
	/* initialize shortcuts */
	const tpl_proc_static * the_proc = tpl_stat_proc_table[proc_id];

	u32 size_of_stack_above_sc_handler_frame = 
		(the_proc->stack->stack_size >> 2) - NB_REG_ON_SC_HANDLER_FRAME ;

	tpl_stack_word* sc_handler_frame = the_proc->stack->stack_zone + size_of_stack_above_sc_handler_frame;

	/* current stack pointer */
	the_proc->context->stackPointer = (uint32)sc_handler_frame;

	/* setup entry point */
	sc_handler_frame[reg_pc] = (uint32)(the_proc->entry);

	/*
	 * set the return address of the task/isr. This is useful in case the
	 * user forgets to call TerminateTask/TerminateISR
	 * MISRA RULE 1,45,85 VIOLATION: the function pointer is used and stored
	 * in a 32bits variable, but as the Os is dependant on the target,
	 * the behaviour is controlled
	 */
 	sc_handler_frame[reg_lr] = (IS_ROUTINE == the_proc->type) ?
								(uint32)(CallTerminateISR2) :
								(uint32)(CallTerminateTask); /*  lr  */
}

extern u32 _tpl_syscall_table;

FUNC(void, OS_CODE) tpl_init_machine(void)
{
	/* Initialize Syscall registers */
	__ldsr_rh(11, 1, SYSCALL_COUNT); /* SCCFG */
	__ldsr_rh(12, 1, (u32) &_tpl_syscall_table); /* SCBP */
}

//defined in cstart0.asm... usefull?
#pragma interrupt irq_handler
void irq_handler(unsigned long arg) {}


