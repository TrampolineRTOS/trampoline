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

	//check PC size (not the same for each AVR :-/)
#if defined (__AVR_ATmega2560__)
	#define __PC_USE_24_BITS__
#elif defined(__AVR_AT90CAN128__) || \
	  defined(__AVR_ATmega328__)  || \
	  defined(__AVR_ATmega328P__)
	#define __PC_USE_16_BITS__
#else
	#warning "The AVR CPU is not known -> Trampoline may crash if the Program Counter size is not OK. Assuming a program counter of 16 bits.".
	#define __PC_USE_16_BITS__
#endif

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * WARNING: This function MUST NOT modify GPRs!!! (the task in parameter
 * can be the running one!!!)
 */
FUNC(void, OS_CODE) tpl_init_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
	u16 tmp;
    int a=0; /*internal variable, used to put the register R00 to R31 on the tabular*/
	u8 *pointer;
  	/* Gets a pointer to the static descriptor of the task whose context is going to be initialized */
	tpl_proc_static *static_desc = tpl_stat_proc_table[proc_id];
	/* Init stack pointer */
	u8 *sp=(void *)((u16)(static_desc->stack.stack_zone) + static_desc->stack.stack_size - 1);

	//save the last return func call: TerminateTask() or TerminateISR2()
	if(static_desc->type == IS_ROUTINE) //ISR2. push CallTerminateISR2();
	{
		AVR_PUSH((u16)(CallTerminateISR2) & 0xFF)
		AVR_PUSH((u16)(CallTerminateISR2) >> 8)
	} else {  //normal task. push TerminateTask();
		AVR_PUSH((u16)(TerminateTask) & 0xFF)
		AVR_PUSH((u16)(TerminateTask) >> 8)
	}
#ifdef __PC_USE_24_BITS__
	AVR_PUSH(0)
#endif
	
	/* put the Task entry point on the stack */
	tmp = (u16)static_desc->entry;
	AVR_PUSH((tmp) & 0xFF)
	AVR_PUSH((tmp) >> 8)
#ifdef __PC_USE_24_BITS__
	AVR_PUSH(0)
#endif

	AVR_PUSH(0) //push GPR r16
	AVR_PUSH(0x80) //push SREG (enable interrupts)
	/* put GPR on the stack. r0 to r15 and r17 to r31 => 31 regs */
    for (a=0;a<31;a++) 
	{
		AVR_PUSH(0);
	}
	
	/* save the stack pointer */
	static_desc->context = (u16)(sp);
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
//void tpl_init_tick_timer();
void tpl_init_machine(void)
{
	//tpl_init_context(IDLE_TASK_ID);
	//sei();
}

void tpl_enable_interrupts(void)
{
	sei();
}

void tpl_disable_interrupts(void)
{
	cli();
}
