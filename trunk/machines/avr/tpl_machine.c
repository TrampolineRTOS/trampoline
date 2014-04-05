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
 * $Date:$
 * $Rev$
 * $Author$
 * $URL$
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


/*
 * tpl_init_context initialize a context to prepare a task to run.
 * WARNING: This function MUST NOT modify GPRs!!! (the task in parameter
 * can be the running one!!!)
 */
FUNC(void, OS_CODE) tpl_init_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{

    int a=0; /*internal variable, used to put the register R00 to R31 on the tabular*/
	u8 *pointer;
  	/* Gets a pointer to the static descriptor of the task whose context is going to be initialized */
	const tpl_proc_static *static_desc = tpl_stat_proc_table[proc_id];
	/* Init stack pointer */
	u8 *sp=(void *)((u16)(static_desc->stack.stack_zone) + static_desc->stack.stack_size - 1);

	/* put the Program Counter on the stack */
    
    *sp=(u16)static_desc->entry;
	sp--;
	*sp=((u16)static_desc->entry>>8);
	sp--;
#if defined (__AVR_ATmega2560__)
	*sp=0; /* Program Counter size is 24 bits on ATMega2560 */
	sp--;
#elif defined(__AVR_AT90CAN128__) || \
	  defined(__AVR_ATmega328__)  || \
	  defined(__AVR_ATmega328P__)
	//Ok. Program Counter size is 16 bits.
#else
#warning "The AVR CPU is not known -> Trampoline may crash if the Program Counter size is not OK. Assuming a program counter of 24 bits.".
	*sp=0; /* Program Counter size assumed to be 24 bits */
	sp--;
#endif
	/* save the stack pointer */ 
	pointer = (u8*)(&(static_desc->context.ic->sp));
	*pointer = (u8)((u16)sp & 0xFF);
	pointer++;
	*pointer = (u8)((u16)sp >> 8);

  /* initializes system register the chart (system register at startup time) */
    for (a=0;a<31;a++)
    {
        pointer++;
        *pointer=0x00;
    }

    /* put the register SREG on the chart */
    pointer++;
    *pointer=0x80; /* the system register with interrupt activated */

	/* put register 16 on the chart */
	pointer++;
	*pointer=0x00;
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
	tpl_init_context(IDLE_TASK_ID);
	sei();
}

void tpl_enable_interrupts(void)
{
	sei();
}

void tpl_disable_interrupts(void)
{
	cli();
}
