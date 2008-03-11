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

void tpl_switch_context(tpl_context *old_context, tpl_context *new_context) // a traduire en assembleur
{
    //mettre PC sur la pile du old
    old_context-=2;
    old_context->sp=PCMSB; /* see the page 335 of the datasheet */
    //mettre SREG sur la pile du old
    old_context--;
    old_context->sp=SREG;
    /* put the register R00 to R31 on the stack of old_context */
    old_context--;
    old_context->sp=R00;
    old_context--;
    old_context->sp=R01;
    old_context--;
    old_context->sp=R02;
    old_context--;
    old_context->sp=R03;
    old_context--;
    old_context->sp=R04;
    old_context--;
    old_context->sp=R05;
    old_context--;
    old_context->sp=R06;
    old_context--;
    old_context->sp=R07;
    old_context--;
    old_context->sp=R08;
    old_context--;
    old_context->sp=R09;
    old_context--;
    old_context->sp=R10;
    old_context--;
    old_context->sp=R11;
    old_context--;
    old_context->sp=R12;
    old_context--;
    old_context->sp=R13;
    old_context--;
    old_context->sp=R14;
    old_context--;
    old_context->sp=R15;
    old_context--;
    old_context->sp=R16;
    old_context--;
    old_context->sp=R17;
    old_context--;
    old_context->sp=R18;
    old_context--;
    old_context->sp=R19;
    old_context--;
    old_context->sp=R20;
    old_context--;
    old_context->sp=R21;
    old_context--;
    old_context->sp=R22;
    old_context--;
    old_context->sp=R23;
    old_context--;
    old_context->sp=R24;
    old_context--;
    old_context->sp=R25;
    old_context--;
    old_context->sp=R26;
    old_context--;
    old_context->sp=R27;
    old_context--;
    old_context->sp=R28;
    old_context--;
    old_context->sp=R29;
    old_context--;
    old_context->sp=R30;
    old_context--;
    old_context->sp=R31;
    //sortir registre 0-31 de la pile du new
    R31=new_context->sp;
    new_context++;
    R30=new_context->sp;
    new_context++;
    R29=new_context->sp;
    new_context++;
    R28=new_context->sp;
    new_context++;
    R27=new_context->sp;
    new_context++;
    R26=new_context->sp;
    new_context++;
    R25=new_context->sp;
    new_context++;
    R24=new_context->sp;
    new_context++;
    R23=new_context->sp;
    new_context++;
    R22=new_context->sp;
    new_context++;
    R21=new_context->sp;
    new_context++;
    R20=new_context->sp;
    new_context++;
    R19=new_context->sp;
    new_context++;
    R18=new_context->sp;
    new_context++;
    R17=new_context->sp;
    new_context++;
    R16=new_context->sp;
    new_context++;
    R15=new_context->sp;
    new_context++;
    R14=new_context->sp;
    new_context++;
    R13=new_context->sp;
    new_context++;
    R12=new_context->sp;
    new_context++;
    R11=new_context->sp;
    new_context++;
    R10=new_context->sp;
    new_context++;
    R09=new_context->sp;
    new_context++;
    R08=new_context->sp;
    new_context++;
    R07=new_context->sp;
    new_context++;
    R06=new_context->sp;
    new_context++;
    R05=new_context->sp;
    new_context++;
    R04=new_context->sp;
    new_context++;
    R03=new_context->sp;
    new_context++;
    R02=new_context->sp;
    new_context++;
    R01=new_context->sp;
    new_context++;
    R00=new_context->sp;
    new_context++;
    //sortir SREG de la pile du new
    SREG=new_context->sp;
    new_context++;
    //faire RET (ne pas dépiler le PC)
   __asm
   {
       ret
   }
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
    int a=0; /*internal variable, used to put the register R00 to R31 on the stack*/
  	/* Gets a pointer to the static descriptor of the task whose context is going to be initialized */
	const tpl_exec_static *static_desc = task->static_desc;
	/* Gets a pointer to the context going to be initialized */
	avr_context *ic = static_desc->context.ic;
	/* Init stack pointer */
	*ic=(static_desc->stack.stack_zone) + static_desc->stack.stack_size;
	
    /* put the Program Counter on the stack */
    ic-=2; /* decrement ic */
    ic->sp=static_desc->entry; /* put the entry function (pointer) on the stack */
    /* put the register SREG on the stack */
    ic--; /* decrement ic */
    ic->sp=0x00; /* the SREG register without interrupt */
    /* initializes system register on the stack (system register at startup time) */
    for (a=0;a<32;a++)
    {
        ic--;
        ic->sp=0x00;
    }
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

