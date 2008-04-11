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

void tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
{
   __asm
   {
    
    
	SPSE ?,#0                   //if there is no context
	JMP RESTORE_NEW_CONTEXT     //jump directly to RESTORE_NEW_CONTEXT
	
    // We are on the old context stack and the PCMSB is allready saved.
    // So, we can now save the system registers (on the old context stack)	
    PUSH SREG
    PUSH R00
    PUSH R01
    PUSH R02
    PUSH R03
    PUSH R04
    PUSH R05
    PUSH R06
    PUSH R07
    PUSH R08
    PUSH R09
    PUSH R10
    PUSH R11
    PUSH R12
    PUSH R13
    PUSH R14
    PUSH R15
    PUSH R16
    PUSH R17
    PUSH R18
    PUSH R19
    PUSH R20
    PUSH R21
    PUSH R22
    PUSH R23
    PUSH R24
    PUSH R25
    PUSH R26
    PUSH R27
    PUSH R28
    PUSH R29
    PUSH R30
    PUSH R31
    
    
RESTORE_NEW_CONTEXT:     
    
    //Now, we go to the new context stack
    out SPH, ?
    out SPL, ?
       
    //And we can restore the system registers.
    POP R31
    POP R30
    POP R29
    POP R28
    POP R27
    POP R26
    POP R25    
    POP R24
    POP R23
    POP R22
    POP R21
    POP R20
    POP R19
    POP R18    
    POP R17
    POP R16
    POP R15
    POP R14
    POP R13
    POP R12
    POP R11    
    POP R10
    POP R09
    POP R08
    POP R07
    POP R06
    POP R05
    POP R04        
    POP R03
    POP R02
    POP R01
    POP R00
    POP SREG
    // We must NOT "POP" the PSMSB, Just RET !        
    ret
   }
}

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
  	/* Gets a pointer to the static descriptor of the task whose context is going to be initialized */
	const tpl_exec_static *static_desc = task->exec_desc.static_desc;
	/* Init stack pointer */
	u16 *sp=(void *)((u16)(static_desc->stack.stack_zone) + static_desc->stack.stack_size);

    /* put the Program Counter on the stack */
    sp-=2;
    *sp=(u16)static_desc->entry;
    /* put the register SREG on the stack */
    sp--;
    *sp=0x80; /* the system register with interrupt activated */
    /* initializes system register on the stack (system register at startup time) */
    for (a=0;a<32;a++)
    {
        sp--;
        *sp=0x00;
    }
	/* I'm not sure of the line is under !!!  */
	static_desc->context.ic=sp;
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

