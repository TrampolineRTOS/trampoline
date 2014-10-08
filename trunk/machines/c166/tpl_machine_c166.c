/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
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

#include "tpl_os_internal_types.h"
#include "tpl_machine.h"
#include "tpl_os_application_def.h"   /* NO_ALARM */
#include "tpl_app_config.h"	   /* TASK_COUNT and ISR_COUNT*/
#include "tpl_os_definitions.h" /* IS_ROUTINE  */
#include "tpl_os_kernel.h" /*tpl_stat_proc_table and tpl_proc_static*/
#include <C167CS.H>	/*TODO: update with a more generic standard include file.*/

#include "tpl_os.h" //TerminateTask() and CallTerminateISR2()

#pragma warning disable = 47 /* disables the "unreferenced parameter" warning */
							 /* used for the tpl_switch_context function      */

uint16 Os_CptTaskLock;


#define SMALL_MEMORY_MODEL

#ifdef SMALL_MEMORY_MODEL
/* use a register bank for interrupts and in the context switch function */
unsigned int idata registers_it[16];
unsigned int idata registers_c166[TASK_COUNT+ISR_COUNT+1][16];

/*
 * idle_function is used the idle task
 */
void idle_function(void)
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
	//enter idle mode.
	__asm {
		IDLE
	}
	
}

void tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
{
	
	/* Only works with a near memory model.
	 *  
	 * R8 has a pointer to the old context.
	 * R9 has a pointer to the new context.
	 * first of all: store the current context in old_context
	 * R1 stores DPP3 of the context we're working on 
	 * R5 stores the context we're working on
	 * R2 stores intermediate values (IP, stack)
	 * R3 stores the old CP 
	 */
	__asm {
	PUSH CP /*store the current register bank */
	MOVW CP, #registers_it
	NOP /* pipeline effect */
	POP R3 /* the old CP */
	/* store DPP3 on R1 */
	MOVW R1, DPP3
	MOVW DPP3, #3
	NOP
	MOVW R0, [R3] //get old user stack in R0
	MOVW R8, [R3+#16]
	MOVW R9, [R3+#18]
	#ifdef LARGE_POINTER 
		/* pointer does not fill in only one 16 bit register*/
		MOVW R10,[R3+#20] 
		MOVW R11,[R3+#22]
	#endif
	/*ok, now, all the other registers may be changed. */
	/* if old_context */
	CMP R8,#0
	JMPR CC_Z,NO_OLD_CONTEXT_TO_SAVE
			/* R5 get the context */
			MOVW R5,[R8]
		
			MOVW [R5],MDC	/* store mdc  */
			ADD R5,#2	
			MOVW [R5],DPP0	/* store dpp0 */
			ADD R5,#2
			MOVW [R5],DPP1	/* store dpp1 */
			ADD R5,#2
			MOVW [R5],DPP2	/* store dpp2 */
			ADD R5,#2
			MOVW [R5],R1	/* store dpp3 */
			ADD R5,#2
			MOVW [R5],MDH	/* store mdh */
			ADD R5,#2
			MOVW [R5],MDL	/* store mdl */
			POP R2		/*R2 get return ip*/
			ADD R5,#2
			MOVW [R5],SP	/* store sp */
			ADD R5,#2
			MOVW [R5],STKOV	/* store stkov */
			ADD R5,#2
			MOVW [R5],STKUN	/* store stkun */
			ADD R5,#2
			MOVW [R5],PSW	/* store psw */
			ADD R5,#2
			MOVW [R5],CSP	/* store csp */
			ADD R5,#2
			MOVW [R5],R2	/* store ip */
			ADD R5,#2
			MOVW [R5],R3	/* store cp */
			ADD R5,#2
			MOVW [R5],R0	/* store user stack */
NO_OLD_CONTEXT_TO_SAVE:
	 	/* then set the new context */
		MOVW R5, [R9] /*the new context */
		MOVW MDC, [R5]	/* restore mdc */
		ADD R5,#2
		MOVW DPP0, [R5]	/* restore dpp0 */
		ADD R5,#2           /* no dpp use allowed after writing in DPPx, pipeline effect */
		MOVW DPP1, [R5]	/* restore dpp1 */
		ADD R5,#2
		MOVW DPP2, [R5]	/* restore dpp2 */
		ADD R5,#2
		MOVW R1, [R5]	/* get the dpp3 to restore at the end.*/
		ADD R5,#2
		MOVW MDH, [R5]	/* restore mdh */
		ADD R5,#2
		MOVW MDL, [R5]	/* restore mdl */
		/* no exception after a stkov or stkun change.
		 * only after a sp change -> not true with the monitor.
 		 */

		MOVW R2,#0xf200   /*low limit of iram -> stkov. */
        	MOVW STKOV,R2	
	        MOVW R2,#0xfdfe   /*high limit of iram -> stkun */
	        MOVW STKUN,R2

		/* then set the new sp */
		ADD R5,#2
		MOVW SP, [R5]	/* restore sp ********* STACK CHANGE **********/
		ADD R5,#2
		MOVW STKOV, [R5]	/* restore stkov */
		ADD R5,#2
		MOVW STKUN, [R5]	/* restore stkun */

		/* store PSW, CSP and IP on top of the stack -> RETI*/
		ADD R5,#2
		MOVW R2, [R5]	/* get PSW */
		PUSH R2		/* store in stack */
		ADD R5,#2
		MOVW R2, [R5]	/* get CSP */
		PUSH R2		/* store in stack */
		ADD R5,#2
		MOVW R2, [R5]	/* get IP */
		PUSH R2		/* store in stack */

		ADD R5,#2
		MOVW R2, [R5] //R2 <- CP of the new task
		ADD R5,#2
		MOVW [R2], [R5] //init R0 of the new task.
		PUSH R1 		/*store DPP3 on stack */
		MOVW CP, R2	/* restore cp */
		/* Warning next instruction MUST NOT use GPRs!!! (pipeline effect) */
		POP DPP3		/* restore DPP3 */
		/* the next "reti" instruction will pop the IP, CSP and PSW registers */
		RETI
	}
}

void tpl_switch_context_from_it(tpl_context * old_context, tpl_context * new_context)
{
	/* Only works with a near memory model.
	 * current register bank is registers_it
	 * R8 has a pointer to the old context.
	 * R9 has a pointer to the new context.
	 * DPP3 = 3 (value set in interrupt handler).
	 * first of all: store the current context in old_context
	 */
	__asm {
		/*don't store context if pointer is NULL. */
	 	CMP R8,#0
		JMPR CC_Z,NO_OLD_CONTEXT_TO_SAVE_IT
		/* R1, R2 used to get values from the stack (see documentation). */
		/* R5 used to get fields in the context. */

			MOVW R5,[R8]		/* init*/
			MOVW R1,0xfe12   

			MOVW [R5], MDC	/* store mdc  */
			
			MOVW R2, [R1+#2]
			ADD R5,#2
			MOVW [R5],R2		/* store dpp0 */
			
			ADD R5,#2
			MOVW [R5],DPP1	/* store dpp1 */
			ADD R5,#2
			MOVW [R5],DPP2	/* store dpp2 */

			MOVW R2, [R1+#6]
			ADD R5,#2
			MOVW [R5],R2		/* store dpp3 */
			
			ADD R5,#2
			MOVW [R5],MDH		/* store mdh */

			ADD R5,#2
			MOVW [R5],MDL		/* store mdl */
			
			MOVW R2, R1 		 
			ADD R2, #14
			ADD R5,#2
			MOVW [R5],R2		 /* store sp */
			
			ADD R5,#2
			MOVW [R5],STKOV	/* store stkov */
			ADD R5,#2
			MOVW [R5],STKUN	/* store stkun */

			MOVW R2, [R1+#12]
			ADD R5,#2
			MOVW [R5],R2		/* store psw */

			MOVW R2, [R1+#10]
			ADD R5,#2
			MOVW [R5],R2		/* store csp */

			MOVW R2, [R1+#8]
			ADD R5,#2
			MOVW [R5],R2		/* store ip */

			MOVW R2, [R1+#4]
			ADD R5,#2
			MOVW [R5],R2	/* store cp */
		
			ADD R5,#2
			MOVW [R5],R0	/* store user stack */
NO_OLD_CONTEXT_TO_SAVE_IT:			
	/* then set the new context */
		MOVW R5, [R9] /*the new context */
		MOVW MDC, [R5]	/* restore mdc */
		ADD R5,#2
		MOVW DPP0, [R5]	/* restore dpp0 */
		ADD R5,#2           /* no dpp use allowed after writing in DPPx, pipeline effect */
		MOVW DPP1, [R5]	/* restore dpp1 */
		ADD R5,#2
		MOVW DPP2, [R5]	/* restore dpp2 */
		ADD R5,#2
		MOVW R1, [R5]	/* get the dpp3 to restore at the end.*/
		ADD R5,#2
		MOVW MDH, [R5]	/* restore mdh */
		ADD R5,#2
		MOVW MDL, [R5]	/* restore mdl */
		/* no exception after a stkov or stkun change.
		 * only after a sp change -> not true with the monitor.
 		 */

		MOVW R2,#0xf200   /*low limit of iram -> stkov. */
		MOVW STKOV,R2	
		MOVW R2,#0xfdfe   /*high limit of iram -> stkun */
		MOVW STKUN,R2

		/* then set the new sp */
		ADD R5,#2
		MOVW SP, [R5]	/* restore sp ********* STACK CHANGE **********/
		ADD R5,#2
		MOVW STKOV, [R5]	/* restore stkov */
		ADD R5,#2
		MOVW STKUN, [R5]	/* restore stkun */

		/* store PSW, CSP and IP on top of the stack -> RETI*/
		ADD R5,#2
		MOVW R2, [R5]	/* get PSW */
		PUSH R2		/* store in stack */
		ADD R5,#2
		MOVW R2, [R5]	/* get CSP */
		PUSH R2		/* store in stack */
		ADD R5,#2
		MOVW R2, [R5]	/* get IP */
		PUSH R2		/* store in stack */

		ADD R5,#2
		MOVW R2, [R5] //R2 <- CP of the new task
		ADD R5,#2
		MOVW [R2], [R5] //init R0 of the new task.
		PUSH R1 		/*store DPP3 on stack */
		MOVW CP, R2	/* restore cp */
		/* Warning next instruction MUST NOT use GPRs!!! (pipeline effect) */
		POP DPP3		/* restore DPP3 */
		/* the next "reti" instruction will pop the IP, CSP and PSW registers */
		RETI
	}
}
#endif

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * WARNING: This function MUST NOT modify GPRs!!! (the task in parameter
 * can be the running one!!!)
 */
FUNC(void, OS_CODE) tpl_init_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
	int i;
	int objId;
	unsigned int stack;

	/* Gets a pointer to the static descriptor of the task whose context is going to be initialized */
	const tpl_proc_static * static_desc = tpl_stat_proc_table[proc_id];

	/* Gets a pointer to the context going to be initialized */
	c166_context *ic = static_desc->context.ic;

	/* CP init */
	ic->cp = (unsigned int)&(registers_c166[proc_id][0]);

	/* Init of the system stack and storage of the task's entry point address on system stack */
	stack = ((unsigned int)(static_desc->stack.sys_stack_zone)) + 
				static_desc->stack.sys_stack_size;
	ic->stkun = stack;
	ic->stkov = (unsigned int)(static_desc->stack.sys_stack_zone);
	/* push the address of TerminateTask() system call on top of stack */
	stack -= sizeof(unsigned int);
	*((unsigned int *)stack) = (static_desc->type == IS_ROUTINE) ?
														 (unsigned int)(CallTerminateISR2) :
														 (unsigned int)(TerminateTask);
//	FUNC(StatusType, OS_CODE) TerminateTask(void)
	ic->sp = 	stack;
	/* push entry: will be pushed on the stack by the context swich. */
	ic->psw = 0x0800;
	ic->csp = (unsigned int)(((unsigned long)(static_desc->entry)) >> 16); 
	ic->ip = (unsigned int)(static_desc->entry); 
	/* Init of the user stack :  R0 = upper address of the user stack zone */
	ic->ustack = (unsigned int)(static_desc->stack.user_stack_zone) + 
									static_desc->stack.user_stack_size;  
	/* Init Others to 0 */
	ic->mdh = 0;
	ic->mdl = 0;
    /* Init DPPx registers */
#ifdef SMALL_MEMORY_MODEL
	ic->dpp0 = DPP0;
#else
	ic->dpp0 = (unsigned int)((unsigned long)ic >> 14);
#endif
	ic->dpp1 = DPP1;
	ic->dpp2 = DPP2;
	ic->dpp3 = DPP3;
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
void tpl_init_benchmark_timer();
void tpl_init_machine(void)
{
	#if ALARM_COUNT > 0
		tpl_init_tick_timer();
	#endif
}

FUNC(void, OS_CODE) tpl_disable_interrupts(void)
{
  IEN = 0;/* dis-allows interrupts */
}

FUNC(void, OS_CODE) tpl_enable_interrupts(void)
{
  IEN = 1;/* re-allows interrupts */
}

void tpl_init_tick_timer()
{
	/* use interrupt mode: 
	 * T6IE:1 Interrupt enable
	 * ilvl:13 Interrupt Level
	 * glvl:1 Group Level
	*/
	T6IC = 0x61;
	/* at 40 MHz, resolution max is 100ns.
	 * To get 1ms, we need 10 000 ticks.
	 * 65536 - 10000 = 55536
	*/
	#ifdef F40MHZ
		#message "Attention : frequence CPU = 40 MHz"
		CAPREL = 55536;
	#elif defined F20MHZ
		#message "Attention : frequence CPU = 20 MHz"	 
		CAPREL = 60536;  // config pour 20 MHZ et 1 ms
	#else
		#error "No CPU Frequency defined: should use F20MHZ or F40MHZ"
	#endif

	/* T6SR :1 reload with CAPREL
	 * T6OTL:0 No toggle latch.
	 * T6OE :0 Output Function disabled
	 * T6UDE:0 No external Up/Down
	 * T6UD :0 Count Up
	 * T6R  :1 Run
	 * T6M  :0 Timer mode
	 * T6I  :0 100ns resolution
	 */
	T6CON = 0x8040;
}
