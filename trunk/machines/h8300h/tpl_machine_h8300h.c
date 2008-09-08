/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline C166 specifics
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
#include "tpl_os_internal_types.h" /* tpl_task structure*/
#include "tpl_machine_interface.h" /* tpl_get_task_lock */
#include "api_moniteur.h"

h8300h_context idle_task_context;
tpl_stack_word stack_zone_of_idleTask[512/sizeof(tpl_stack_word)];


/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
	while(1);
}

void tpl_shutdown(void)
{
	tpl_get_task_lock();
	while(1);
}

/*
 */
void createContext (u32 * * sp, const u32 entryPoint) ; /* Written in assembly language */

void tpl_init_context(tpl_exec_common *task)
{
	/* Gets a pointer to the static descriptor of the task whose context is going to be initialized */
	const tpl_exec_static *static_desc = task->static_desc;
	/* Gets a pointer to the context going to be initialized */
	h8300h_context *ic = static_desc->context.ic;
	/* Init stack pointer */
	* ic = ((u32 *)(static_desc->stack.stack_zone)) + static_desc->stack.stack_size;
	createContext (ic, (u32) static_desc->entry) ;
	/*PBDR |=8 ;
    printChar (' ') ;
	printHex8((u32)*ic);
	*/
}

void h8300h_switch_context(u32 * * old_context,
                           u32 * * new_context) ;  /* Written in assembly language */

void tpl_switch_context (tpl_context *old_context,
                         tpl_context *new_context) {
	if(old_context)
		h8300h_switch_context(old_context->ic, new_context->ic);
	else
		h8300h_switch_context(NULL, new_context->ic);
}

void tpl_switch_context_from_it (tpl_context *old_context,
                                 tpl_context *new_context) {
	if(old_context)
		h8300h_switch_context(old_context->ic, new_context->ic);
	else
		h8300h_switch_context(NULL, new_context->ic);
}

void tpl_init_machine(void)
{
	initInterrupt();
}

