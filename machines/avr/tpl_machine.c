/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline avr specifics
 *
 */

#include <avr/io.h>
//interrupt.h declares sei() and cli() functions.
//but the 'ISR' macro is used to declare
//interrupt handlers.
//It is the same macro to declare ISR2 in OSEK.
#include <avr/interrupt.h>
#undef ISR

#include "tpl_machine.h"
#include "tpl_os_application_def.h"   /* NO_ALARM */
#include "tpl_app_config.h"	   /* TASK_COUNT and ISR_COUNT*/
#include "tpl_os_definitions.h" /* IS_ROUTINE  */
#include "tpl_os_internal_types.h"
#include "tpl_os_kernel.h" /*tpl_stat_proc_table and tpl_proc_static*/
#include "tpl_os.h"

extern FUNC(void, OS_CODE) CallTerminateTask();
extern FUNC(void, OS_CODE) CallTerminateISR2();

/*
 * tpl_sleep is used by the idle task
 */
void idle_function()
//void tpl_sleep(void)
{
	while(1);
}

void tpl_shutdown(void)
{
	/* remove ITs */
	/* TODO: update to set idle mode.*/
	while (1);
}

#define AVR_PUSH(val) {*sp=(u8)(val); sp--;}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 */
FUNC(void, OS_CODE) tpl_init_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
	u16 tmp;
    int a=0; /*internal variable, used to put the register R00 to R31 on the tabular*/
  	/* Gets a pointer to the static descriptor of the task whose context is going to be initialized */
	const tpl_proc_static *static_desc = tpl_stat_proc_table[proc_id];
	/* Init stack pointer */
	u8 *sp=(void *)((u16)(static_desc->stack.stack_zone) + static_desc->stack.stack_size - 1);

	//save the last return func call: TerminateTask() or TerminateISR2()
	if(static_desc->type == IS_ROUTINE) //ISR2. push CallTerminateISR2();
	{
		AVR_PUSH((u16)(CallTerminateISR2) & 0xFF)
		AVR_PUSH((u16)(CallTerminateISR2) >> 8)
	} else {  //normal task. push CallTerminateTask();
		AVR_PUSH((u16)(CallTerminateTask) & 0xFF)
		AVR_PUSH((u16)(CallTerminateTask) >> 8)
	}
#ifdef __AVR_3_BYTE_PC__
	AVR_PUSH(0)
#elif !defined(__AVR_2_BYTE_PC__)
	#warning "The AVR CPU is not known -> Trampoline may crash if the Program Counter size is not OK. Assuming a program counter of 16 bits.".
#endif

	/* put the Task entry point on the stack */
	tmp = (u16)static_desc->entry;
	AVR_PUSH((tmp) & 0xFF)
	AVR_PUSH((tmp) >> 8)
#ifdef __AVR_3_BYTE_PC__
	AVR_PUSH(0)
#endif

	//old version
//	AVR_PUSH(0) //push GPR r16
//	AVR_PUSH(0x80) //push SREG (enable interrupts)
//	/* put GPR on the stack. r2 to r17 (except r16), r28,r29 => 17 regs*/
//    for (a=0;a<17;a++)
//	{
//		AVR_PUSH(0);
//	}
	//new version
	//push r2 to r7 (6 regs)
	for (a=0;a<6;a++) AVR_PUSH(0);
	AVR_PUSH(0x80) //push SREG (enable interrupts)
	//push r28/29, r8 to 17 (12 regs)
	for (a=0;a<12;a++) AVR_PUSH(0);


	/* save the stack pointer */
	*(static_desc->context) = (u16)(sp);
}

void tpl_get_task_lock(void)
{
	cli();
}

void tpl_release_task_lock(void)
{
    sei();
}

/*
 * tpl_init_machine
 */
extern void tpl_init_board();
void tpl_init_machine(void)
{
	#if WITH_INIT_BOARD == YES
		tpl_init_board();
	#endif
}

void tpl_enable_interrupts(void)
{
	sei();
}

void tpl_disable_interrupts(void)
{
	cli();
}

void tpl_enable_os_interrupts(void)
{
	sei();
}

void tpl_disable_os_interrupts(void)
{
	cli();
}
