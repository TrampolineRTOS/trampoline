/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protï¿½ï¿½par la loi sur la propriï¿½ï¿½intellectuelle
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
#include <AVRCS.H>	/*TODO: update with a more generic standard include file.*/


#pragma warning disable = 47 /* disables the "unreferenced parameter" warning */
							 /* used for the tpl_switch_context function      */


avr_context idle_task_context;


#define SMALL_MEMORY_MODEL

#ifdef SMALL_MEMORY_MODEL
/* use a register bank for interrupts and in the context switch function */
unsigned int registers_it[16];
unsigned int registers_avr[TASK_COUNT+ISR_COUNT+1][16];

/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
	while(1);
/*	__asm {
		IDLE
	}
*/
}

void tpl_shutdown(void)
{
	/* remove ITs */
	IEN = 0;
	/* TODO: update to set idle mode.*/
	while (1); 
}

void tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
{
     //mettre PC sur la pile du old
     //mettre SREG sur la pile du old
     //mettre registre 0-31 sur la pile du old
     //sortir registre 0-31 de la pile du new
     //sortir SREG de la pile du new
     //faire RET (ne pas dépiler le PC)
   
}

void tpl_switch_context_from_it(tpl_context * old_context, tpl_context * new_context)
{
}
#endif

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * WARNING: This function MUST NOT modify GPRs!!! (the task in parameter
 * can be the running one!!!)
 */
void tpl_init_context(tpl_task *task)
{
  	/* Gets a pointer to the static descriptor of the task whose context is going to be initialized */
	const tpl_exec_static *static_desc = task->static_desc;
	/* Gets a pointer to the context going to be initialized */
	avr_context *ic = static_desc->context.ic;
	/* Init stack pointer */
	*ic=(static_desc->stack.stack_zone) + static_desc->stack.stack_size;
	
    /* put the Program Counter on the stack */
    ic-=2; /* decrement ic */
    *ic->sp=static_desc->entry; /* put the entry function (pointer) on the stack */
    /* put the register SREG on the stack */
    ic--; /* decrement ic */
    *ic->sp=0x00; /* put the system register on the stack (system register at startup time) */
    /* put the register R00 to R31 on the stack */
    /* if someone criticizes my code, i will broke his face <-- just a joke */
    ic--;
    *ic->sp=R00;
    ic--;
    *ic->sp=R01;
    ic--;
    *ic->sp=R02;
    ic--;
    *ic->sp=R03;
    ic--;
    *ic->sp=R04;
    ic--;
    *ic->sp=R05;
    ic--;
    *ic->sp=R06;
    ic--;
    *ic->sp=R07;
    ic--;
    *ic->sp=R08;
    ic--;
    *ic->sp=R09;
    ic--;
    *ic->sp=R10;
    ic--;
    *ic->sp=R11;
    ic--;
    *ic->sp=R12;
    ic--;
    *ic->sp=R13;
    ic--;
    *ic->sp=R14;
    ic--;
    *ic->sp=R15;
    ic--;
    *ic->sp=R16;
    ic--;
    *ic->sp=R17;
    ic--;
    *ic->sp=R18;
    ic--;
    *ic->sp=R19;
    ic--;
    *ic->sp=R20;
    ic--;
    *ic->sp=R21;
    ic--;
    *ic->sp=R22;
    ic--;
    *ic->sp=R23;
    ic--;
    *ic->sp=R24;
    ic--;
    *ic->sp=R25;
    ic--;
    *ic->sp=R26;
    ic--;
    *ic->sp=R27;
    ic--;
    *ic->sp=R28;
    ic--;
    *ic->sp=R29;
    ic--;
    *ic->sp=R30;
    ic--;
    *ic->sp=R31;
}



void tpl_get_task_lock(void)
{
	IEN = 0;
}

void tpl_release_task_lock(void)
{
	IEN = 1;
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

