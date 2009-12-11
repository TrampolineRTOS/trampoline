/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline cm3 specifics
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
#include "tpl_os_internal_types.h" /*struct tpl_task*/
#include "STM32_Reg.h"
#include "STM32_Init.h"
#include "port_macros.h"
#include "tpl_os_kernel.h" /*tpl_stat_proc_table and tpl_proc_static*/


/*
 * IDLE task context definition
 */

cm3_context idle_task_context;
void tpl_sleep(void);

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_VAR)
idle_stack[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"
//unsigned int idle_stack_frame [8];

// stack frame to be used on exception return (	 ACDC are values to help debug)
//unsigned int idle_stack_frame[8] = {0xACDC0000,0xACDC0001,0xACDC0002,0xACDC0003,0xACDC0012,0,(unsigned int) &tpl_sleep, portINITIAL_XPSR};
// 									R0		R1	  R2	R3	  R12     LR	return address						PSR

//cm3_context idle_task_context = { 
//	.r4_11 = {0xACDC0004,0xACDC0005,0xACDC0006,0xACDC0007,0xACDC0008,0xACDC0009,0xACDC0010,0xACDC0011}, //r4_r11
//	.sp = idle_stack_frame
//	};


/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
	 // spurious events like debug can wake up processor :
	 // we need a loop to ensure sleep		 
	while(1)
	{    	
		__asm__ ("   wfi ;"); 	// go to sleep until NMI/HARD FAULT/RESET
	} 
}

void tpl_shutdown(void)
{
	// remove ITs
	portDISABLE_INTERRUPTS();
	  
  	// spurious events can wake up processor :
	// we need a loop to ensure sleep		 
	while(1)
	{    	
		__asm__ ("   wfi ;"); 	// go to sleep until NMI/HARD FAULT/RESET
	} 
 }

void tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
{
	 // R0 has a pointer to the old context. It seems to be 0 when no old context has to be saved
	 // R1 has a pointer to the new context.
	 // first of all: store the current context in old_context

	__asm__ ("pop {r4-r8,lr} ;"); // clean psr stack from previous C calls  
	__asm__ ("pop {r4,lr} ;"); 
				// now lr is the return address

				// CHECK if there is previous context to save or not 
	__asm__ ("cbz r0, set_new_context;");			 
 
	 			// SAVE OLD CONTEXT
				// 1 - fake a stack frame that return to old context
				//______________________________________________________
				// >>>> task stack / LR / PSR / return @ / R12 / R3-R0
				//_______________________________________________________
	__asm__ ("push {lr}  ;");  //lr is also the return address 
	__asm__ ("mrs  r14 , psr;"); //cannot push directly psr use r14=lr
	__asm__ ("push {r14} ;");          // make a copy of the return address
	__asm__ ("ldr r14, [sp , #4] ;");  // onto the stack itself
	__asm__ ("push {r14} ;");
	__asm__ ("push {r12} ;");
	__asm__ ("push {r3} ;");
	__asm__ ("push {r2} ;");
	__asm__ ("push {r1} ;");
	__asm__ ("push {r0} ;");	
	
				// 2 - store R4-R11 in the cm3_context still pointed by R0
	__asm__ ("ldr r0, [r0] ; "); 	
	__asm__ ("stmia r0! , {r4-r11} ;"); 
	__asm__ ("mrs r2, psp ; ");   // psp is pointing on fake stack frame
	__asm__ ("str  r2 , [r0] ; ");// save it on the cm3_context
				
				//SET NEW CONTEXT
	__asm__ ("set_new_context : ");
	__asm__ ("svc 0 ;"); //Processor is in thread mode : we need to make
							 // a SVC call to get Handler mode and fake a return
							 // to new context
}

				// SET NEW CONTEXT from R1 using SVC call
void SVC_Handler ( void)
{  // processor is now in Handler mode
	__asm__ ("ldr r1, [r1] ; "); // r1 pointer to new task cm3_context
	__asm__ ("ldmia r1 ! , {r4-r11} ;"); // backup gpr not in stack frame from new context
	__asm__ ("ldr r0, [r1]  ; ");  // get psp on the new context stack frame
	__asm__ ("msr psp, r0 ; "); 
				// Enable interrupts 
	__asm__ ("mov r0, #0	;");
	__asm__ ("msr basepri, r0	 ;");
				// Exception return using psp fake stack frame of new task
	__asm__ ("mov lr, #0xfffffffd ;");
	__asm__ ("bx  lr ");
	
};
	
void tpl_switch_context_from_it(tpl_context * old_context, tpl_context * new_context)
{
	//context is stored in psp stack frame by SysTickHandler 
	//processor is in Handler mode
	// R0 has a pointer to the old context. It seems to be 0 when no old context has to be saved
	// R1 has a pointer to the new context.

		// CHECK wether a previous context has to be saved 
	__asm__ ("cbz r0, set_new_context_from_it ;");

	__asm__ (" ldr r0, [r0] ;"); // r0 now point to old task cm3_context	

				// Do not save context if old task is idle task !
				//   at the first shot IDLE is using MSP and not PSP
				//   saving context using PSP will make wrong memory accesses... 
	__asm__ (" cmp R0 ,%[idle_context]   ;" : : [idle_context] "p" (& idle_task_context) ); 
	__asm__	(" beq set_new_context_from_it ;");

			// SAVE OLD CONTEXT FROM IT
	__asm__ ("  stmia r0! , {r4-r11} ;"); // save gpr not in stack frame to old context
	__asm__ ("  mrs r2, psp ; ");       // r2 is it stack frame of old task
	__asm__ ("  str r2, [r0] ; ");	 // save SP with the old context stack frame 

			// SET NEW CONTEXT FROM IT
	__asm__ (" set_new_context_from_it : ");
	__asm__ ("ldr r1, [r1] ; "); // r1 point now to new task cm3_context
	__asm__ ("ldmia r1 ! , {r4-r11} ;"); // restore new stak gpr that arenot in stack frame 
	__asm__ ("ldr r0, [r1 ] ; "); // get PSP on new task	stack frame
	__asm__ (" msr psp, r0 ; "); //  now psp is in new task stack zone

				// enable interrupts
	__asm__ (" mov r0, #0	;");
	__asm__ (" msr basepri, r0	 ;");
				// Exception return using psp fake stack frame of new task
	__asm__ (" mov lr, #0xfffffffd ;");
	__asm__ (" bx  lr ");
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * WARNING: This function MUST NOT modify GPRs!!! (the task in parameter
 * can be the running one!!!)
 */
FUNC(void, OS_CODE) tpl_init_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
	int i;

  	/* Gets a pointer to the static descriptor of the task whose context is going to be initialized */
	const tpl_proc_static *static_desc = tpl_stat_proc_table[proc_id];
	/* Gets a pointer to the static descriptor of the task whose context is going to be inited */
	//tpl_exec_static * static_desc = task->exec_desc.static_desc;

	/* Gets a pointer to the context going to be initialized */
	cm3_context *ic = static_desc->context.ic;

	/* find id of the tpl_exec_obj  */
	//objId = static_desc->id;
    //if (static_desc->type & IS_ROUTINE) objId += TASK_COUNT;

//	ic->r4_11 = {4, 5 , 6,7,8,9,10,11};
	ic->sp= (unsigned int *) ((unsigned int)(static_desc->stack.stack_zone) + static_desc->stack.stack_size );// - 16*sizeof(unsigned int);
	*(ic->sp--) =   portINITIAL_XPSR ; //psr
	*(ic->sp--) =   (unsigned int)(static_desc->entry); // pc
	*(ic->sp--)  =    0; // lr
	*(ic->sp--)  =    (proc_id<<8) + 0xABBA0012; // r12
	*(ic->sp--)  =    (proc_id<<8) + 0xABBA0003; // r3
	*(ic->sp--)  =    (proc_id<<8) + 0xABBA0002; // r2
	*(ic->sp--)  =    (proc_id<<8) + 0xABBA0001; // r1 <= proc_id for debug
	*(ic->sp) 	 =	  (proc_id<<8) + 0xABBA0000; // r0 
	for (i=4;i<=11;i++)
	{
		ic->r4_11[i-4] =   (proc_id<<8) + i + 0xABBA0000;
	}
}

void tpl_enable_interrupts(void)
{
	portENABLE_INTERRUPTS();
}

void tpl_disable_interrupts(void)
{
	portDISABLE_INTERRUPTS();
}

/*
 * tpl_init_machine 
 */
//void tpl_init_tick_timer();
void tpl_init_machine(void)
{
//	#ifndef NO_ALARM
//		tpl_init_tick_timer();
//	#endif
}

void tpl_get_task_lock(void)
{
	tpl_disable_interrupts();
}

void tpl_release_task_lock(void)
{
	tpl_enable_interrupts();
}

