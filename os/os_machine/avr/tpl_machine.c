/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
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

#include "tpl_machine.h"
#include "tpl_os_application_def.h"   /* NO_ALARM */
#include "tpl_os_generated_configuration.h"	   /* TASK_COUNT and ISR_COUNT*/
#include "tpl_os_definitions.h" /* IS_ROUTINE  */
#include "tpl_os_internal_types.h"

avr_context idle_task_context;


/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
	while(1);
}

void tpl_shutdown(void)
{
	/* remove ITs */
	/* TODO: update to set idle mode.*/
	while (1); 
}

void tpl_switch_context(tpl_context *old_context, tpl_context *new_context);

void tpl_switch_context_from_it(tpl_context * old_context, tpl_context * new_context)
{
}


/*
 * tpl_init_context initialize a context to prepare a task to run.
 * WARNING: This function MUST NOT modify GPRs!!! (the task in parameter
 * can be the running one!!!)
 */
void tpl_init_context(tpl_task *task)
{
    int a=0; /*internal variable, used to put the register R00 to R31 on the stack*/
	avr_context * ic;
  	/* Gets a pointer to the static descriptor of the task whose context is going to be initialized */
	const tpl_exec_static *static_desc = task->exec_desc.static_desc;
	/* Init stack pointer */
	u8 *sp=(void *)((u16)(static_desc->stack.stack_zone) + static_desc->stack.stack_size);

	/* put the Program Counter on the stack */
    sp--;
    *sp=(u16)static_desc->entry;
	sp--;
	*sp=((u16)static_desc->entry<<8);

	/* put register 16 on the stack */
	sp--;
	*sp=0x00;

    /* put the register SREG on the stack */
    sp--;
    *sp=0x80; /* the system register with interrupt activated */
    /* initializes system register on the stack (system register at startup time) */
    for (a=0;a<31;a++)
    {
        sp--;
        *sp=0x00;
    }
	sp--;
	/* save the stack pointer */ 
	ic = static_desc->context.ic;
	*ic=(avr_context)sp;

}



void tpl_get_task_lock(void)
{
	//IEN = 0;
}

void tpl_release_task_lock(void)
{
	//IEN = 1;
}

/*
 * tpl_init_machine 
 */
void tpl_init_tick_timer();
void tpl_init_machine(void)
{
	#ifndef NO_ALARM
		tpl_init_tick_timer();
	#endif
}

