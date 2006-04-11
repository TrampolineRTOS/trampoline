/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Test process machine dependant stuff
 * based on the powerPC Mac OS X version. Remove the assembly fonction that
 * switch contexts.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_machine.h"
#include <signal.h>
#include <stdio.h>

void tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
{
	printf("switch context.\n");
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and lr and init the other registers to 0
 */
void tpl_init_context(tpl_task *task)
{
	int i;
	ppc_integer_context *ic = task->static_desc->context.ic;
	
	for (i = 0; i < 32; i++ ) {
		ic->gpr[i] = 0;
	}
	
	ic->cr = 0;
	ic->xer = 0;
	ic->ctr = 0;
	
	ic->lr = (unsigned long)task->static_desc->entry;
	ic->gpr[1] = ((unsigned long)task->static_desc->stack.stack_zone)
	               + task->static_desc->stack.stack_size - 12; 
	/*  12 seems to be a magic number :) it is the size of
		the linkage area used to store (among other) the link
		registre if the task calls a function   */
}

/*
 * tpl_init_machine init the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{
    /*
     * Install the signal handler used to emulate interruptions
     */
    /* signal(SIGUSR1,catch_interrupt); */

}
