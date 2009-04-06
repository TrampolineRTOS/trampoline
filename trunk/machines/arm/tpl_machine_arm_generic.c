/**
 * @file tpl_machine_arm_generic.c
 *
 * @section descr File description
 *
 * common routines and variables for generic ARM platform
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */
#include "tpl_machine.h"
#include "tpl_machine_arm_generic.h"
#include "tpl_os_application_def.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * FIXME: find a way (more elegant) to provide the size of
 * this structure to assembly part of the code
 */
CONST (int, OS_VAR) tpl_proc_static_size = sizeof (tpl_proc_static);

/**
 * This variable is used for context switch. It is used in
 * assembler module but defined here to follow the best
 * the type of a proc identifier
 */
VAR (int, OS_VAR) old_running_id;

/**
 * Context for the idle task
 */
VAR (arm_context, OS_VAR) idle_task_context;

/* FIXME : should be static (private)
 * TODO: should this variable be shared with get_task_lock etc... ? */
volatile VAR (u32, OS_VAR) tpl_locking_depth;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern FUNC(void, OS_CODE) tpl_init_machine_low_level (void);
extern FUNC(void, OS_CODE) tpl_sleep (void);

/* FIXME: follow the way proposed by JLB to catch abnormally exits of tasks */
FUNC(void, OS_CODE) tpl_catch_missing_terminate (void)
{
  /* hangs here */
  DISABLE_IRQ();
  DISABLE_FIQ();
  while (1);
}

/*
 * As kernel mode is non-interruptible, these function does nothing */
FUNC(void, OS_CODE) tpl_get_task_lock (void)
{
}
FUNC(void, OS_CODE) tpl_release_task_lock (void)
{
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and the entry point
 */
FUNC(void, OS_CODE) tpl_init_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
	struct ARM_CONTEXT *core_context;
	const tpl_proc_static *the_proc;

	/* initialize shortcuts */	
	the_proc = tpl_stat_proc_table[proc_id];
	core_context = the_proc->context;
	
	/* setup entry point */
	core_context->r[armreg_pc] = (u32)(the_proc->entry);
	/* setup initial stack pointer */
	core_context->r[armreg_sp] = ((u32)the_proc->stack.stack_zone)
	               + the_proc->stack.stack_size;
	/* tasks run privileged at user level, FIXME: has to be choosen in
   * sub-architecture part */
	core_context->psr = 0x1f;

  /* if the task's main function returns without calling
   * TerminateTask, catch it into tpl_catch_missing_terminate */
  core_context->r[armreg_lr] = (u32)(tpl_catch_missing_terminate);

  /* TODO initialize stack footprint */
}

FUNC (void, OS_CODE) tpl_init_machine_generic (void)
{
	 tpl_locking_depth = 0;
	 old_running_id = IDLE_TASK_ID;
	 tpl_init_machine_low_level ();
}

FUNC(u8, OS_CODE) tpl_check_stack_footprint (
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
	u8 tmp;
	/*to do*/
	tmp=0;
	return tmp;
}

FUNC(void, OS_CODE) tpl_enable_all_interrupts_service (void)
{
  /* lock is scheduled to next switch back to task */
	__asm__ ("mrs r0, spsr ;"
			     "bic r0, r0, #0b11000000 ;"
					 "msr spsr, r0 ;" : : : "r0");
	
	#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_disable_all_isr_lock_monitor (tpl_running_obj);
	#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

FUNC(void, OS_CODE) tpl_disable_all_interrupts_service (void)
{
	__asm__ ("mrs r0, cpsr ;"
			     "orr r0, r0, #0b11000000 ;"
					 "msr cpsr, r0 ;"
					 "mrs r0, spsr ;" /* interrupts remained locked in user space */
					 "orr r0, r0, #0b11000000 ;"
					 "msr spsr, r0" : : : "r0");
	
	#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_start_all_isr_lock_monitor (tpl_running_obj);
	#endif /*WITH_AUTOSAR_TIMING_PROTECTION */	
}

FUNC(void, OS_CODE) tpl_resume_all_interrupts_service(void)
{
    tpl_locking_depth--;
    
    if (tpl_locking_depth == 0)
    {
			__asm__ ("mrs r0, spsr ;"
					     "bic r0, r0, #0b11000000 ;"
							 "msr spsr, r0 ;" : : : "r0");
	
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
        tpl_disable_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
    }
}

FUNC(void, OS_CODE) tpl_suspend_all_interrupts_service(void)
{
	__asm__ ("mrs r0, cpsr ;"
			     "orr r0, r0, #0b11000000 ;"
					 "msr cpsr, r0 ;"
					 "mrs r0, spsr ;" /* interrupts remained locked in user space */
					 "orr r0, r0, #0b11000000 ;"
					 "msr spsr, r0" : : : "r0");
   
    tpl_locking_depth++;
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    if (tpl_locking_depth == 1)
    {
      tpl_start_all_isr_lock_monitor (tpl_running_obj);
    }
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

FUNC(void, OS_CODE) tpl_resume_os_interrupts_service(void)
{
    tpl_locking_depth--;
    
    if (tpl_locking_depth == 0)
    {
			__asm__ ("mrs r0, spsr ;"
					     "bic r0, r0, #0b10000000 ;"
							 "msr spsr, r0 ;" : : : "r0");

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
        tpl_disable_os_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
    }
}

FUNC(void, OS_CODE) tpl_suspend_os_interrupts_service(void)
{
	__asm__ ("mrs r0, cpsr ;"
			     "orr r0, r0, #0b10000000 ;"
					 "msr cpsr, r0 ;"
					 "mrs r0, spsr ;" /* interrupts remained locked in user space */
					 "orr r0, r0, #0b10000000 ;"
					 "msr spsr, r0" : : : "r0");
    
    tpl_locking_depth++;
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    if (tpl_locking_depth == 1)
    {
      tpl_start_os_isr_lock_monitor (tpl_running_obj); 
    }
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

