#include "tpl_os.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_dispatch_table.h"
#include "iodefine.h"

VAR (tpl_context, OS_VAR) idle_task_context;

VAR(tpl_stack_word, OS_VAR) idle_stack[IDLE_STACK_SIZE/sizeof(tpl_stack_word)];

#define SYSTICK_HZ		((u32) 80000000) /* 80MHz */
#define TICKS_FOR_10MS	SYSTICK_HZ / 100

static void stop_systick()
{
	/* Stop timer */
	TAUJ1.TT.BIT.TT00 = 1;

	/* Clear interrupt request */
	INTC2.EIC364.BIT.EIRF364 = 0;
}

static void init_systick()
{
	/* Enable access to clock registers */
	SYSCTRL.MSRKCPROT.UINT32 = 0xA5A5A501;

	/* Supply TAUJ1 clock */
	SYSCTRL.MSR_TAUJ_ISO.BIT.MS_TAUJ_1 = 0;

	/* Disable interrupts */
	INTC2.EIC364.BIT.EIMK364 = 1;

	/* Stop timer */
	stop_systick();

	/* clear TAUJnPRS0 to use PCLK clock for CK0 (ie diviser = 2^0) */
	TAUJ1.TPS.BIT.PRS0 = 0;

	/* set systick as interval timer */
	TAUJ1.CMOR0.BIT.MD = 0;

	/* use rising edge */
	TAUJ1.CMUR0.BIT.TIS = 0x1;

	/* set interval for 10ms period */
	TAUJ1.CDR0 = TICKS_FOR_10MS;

	/* Enable interrupts */
	INTC2.EIC364.BIT.EIMK364 = 0;

	/* Start timer */
	TAUJ1.TS.BIT.TS00 = 1;
}

FUNC (void, OS_CODE) tpl_sleep (void)
{
	while(1);
}

FUNC (void, OS_CODE) tpl_shutdown (void)
{
	stop_systick();
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
	volatile uint32 val = 0;

	/* Initialize Syscall registers */
	__ldsr_rh(11, 1, SYSCALL_COUNT); /* SCCFG */
	__ldsr_rh(12, 1, (u32) &_tpl_syscall_table); /* SCBP */

	init_systick();

	/* Enable access to the bus */
	MCCR_SELB1.STBY_CTRL.UINT32 = 0x00000001;
	do {
		val = MCCR_SELB1.STBY_CTRL.UINT32;
	} while (val != 0x00000001);
}
