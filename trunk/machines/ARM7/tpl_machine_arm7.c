/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline ARM7 specifics
 *
 * $Date:$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_machine.h"
#include "tpl_machine_arm7_asm.h"
#include "tpl_os_application_def.h"
#include <stdio.h>

arm7_context idle_task_context;

/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
    while (1);
}



/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and lr and init the other registers to 0
 */
void tpl_init_context(tpl_exec_common *exec_obj)
{
	int i;
	arm7_context *ic = exec_obj->static_desc->context.ic;
	
	for (i = 0; i < 17; i++ ) {
        ic->R[i] = 0;
	}
	
	ic->R[14] = (unsigned long)exec_obj->static_desc->entry;
	ic->R[13] = ((unsigned long)exec_obj->static_desc->stack.stack_zone)
	               + exec_obj->static_desc->stack.stack_size; 
	/*  Size of the linkage area used to store (among others)
        the link register if the task calls a function          */
}

void tpl_init_machine(void)
{
}
