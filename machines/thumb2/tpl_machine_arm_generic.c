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
#include "tpl_machine_interface.h"
#include "tpl_os_application_def.h"
#include "tpl_os_definitions.h"
#include "tpl_os.h"
#if WITH_MEMORY_PROTECTION == YES
#include "tpl_memory_protection.h"
#endif
#if WITH_AUTOSAR == YES
#include "tpl_as_definitions.h"
#endif
#include "tpl_os_interrupt.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

extern void decPeriode(void);
extern void test_toggle(void);
extern FUNC(void, OS_CODE) CallTerminateTask(void);

/**
 * Kernel entry counter
 */
volatile VAR (uint32, OS_VAR) nested_kernel_entrance_counter;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC (void, OS_CODE) tpl_init_machine_generic (void)
{
#if WITH_MEMORY_PROTECTION == YES
  tpl_init_mp();
#endif
}

FUNC (void, OS_CODE) tpl_init_machine_specific (void)
{
	nested_kernel_entrance_counter = 0;
	__set_CONTROL(0x3); // Switch to use Process Stack, privileged state
	__ISB(); // Execute ISB after changing CONTROL (architectural recommendation)
}

/*
 * As kernel mode is non-interruptible, these function does nothing
 */
FUNC(void, OS_CODE) tpl_get_task_lock (void)
{
}

FUNC(void, OS_CODE) tpl_release_task_lock (void)
{
}

/**
 * Enable interrupts
 */
void tpl_enable_interrupts(void)
{
  /* unlock is scheduled to next switch back to task */
  __asm__
  (
  //TODO find in stack frame xpsr to disable interrupts 
  //"mrs r0, xpsr ;"
  "bic r0, r0, #0b11000000 ;"
  //"msr spsr, r0 ;"
  : : : "r0" // clobbered register
  );

}

/**
 * Disable interrupts
 */
void tpl_disable_interrupts(void)
{

  __asm__
  (
	//TODO the same
  //"mrs r0, cpsr ;"
  "orr r0, r0, #0b11000000 ;"
  //"msr cpsr, r0 ;"
  //"mrs r0, spsr ;" // interrupts remain locked in user space
  "orr r0, r0, #0b11000000 ;"
  //"msr spsr, r0"
  : : : "r0" // clobbered register
  );
     
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and the entry point
 */
FUNC(void, OS_CODE) tpl_init_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
  VAR(int, AUTOMATIC) i;
  const tpl_proc_static *the_proc;
  struct ARM_CORE_CONTEXT *l_tpl_context;
  P2VAR(tpl_stack_word, AUTOMATIC, OS_APPL_DATA) stack;

  /* initialize shortcuts */
  the_proc = tpl_stat_proc_table[proc_id];
  l_tpl_context = the_proc->context;
  stack = the_proc->stack.stack_zone;

  /*
   * Initialize context
   */

  /* Set GPRs to 0 */
  for (i = 0; i < 8; i++ )
  {
	  l_tpl_context->gpr[i] = 0;
  }
  /* sp : setup initial stack pointer.
   * The SP points to (stack_zone + stack_size - ARM_CORE_EXCEPTION_FRAME_SIZE)
   * ARM_CORE_EXCEPTION_FRAME_SIZE is the frame pushed by the core at each exception.
   * This frame consists in pushing xpsr, pc, lr, r12, r3, r2, r1, r0
   *  */
  l_tpl_context->sp = ((uint32)the_proc->stack.stack_zone) + ((uint32)the_proc->stack.stack_size) - ARM_CORE_EXCEPTION_FRAME_SIZE;

  /* Initialize stack footprint */
  for (i = (the_proc->stack.stack_size - ARM_CORE_EXCEPTION_FRAME_SIZE) >> 2; i > 0; i-- )
  {
    *stack++ = OS_STACK_PATTERN;
  };
  /* Build the process stack context in the following order :
   * psr, pc, lr, r12, r3, r2, r1, r0
   * Starts at the top of the stack
   */
  //  stack += (the_proc->stack.stack_size - ARM_CORE_EXCEPTION_FRAME_SIZE) >> 2;
  /* r0 */
  *stack++ = (uint32)0;
  /* r1 */
  *stack++ = (uint32)0;
  /* r2 */
  *stack++ = (uint32)0;
  /* r3 */
  *stack++ = (uint32)0;
  /* r12 */
  *stack++ = (uint32)0;
  /* lr
   * Set the return address of the task/isr. This is usefull in case the
   * user forgets to call TerminateTask/TerminateISR
   * MISRA RULE 1,45,85 VIOLATION: the function pointer is used and stored
   * in a 32bits variable, but as the Os is dependant on the target,
   * the behaviour is controled
   */
  *stack++ = (IS_ROUTINE == the_proc->type) ? (uint32)(CallTerminateISR2) : (uint32)(CallTerminateTask);
  /* pc */
  *stack++ = (uint32)(the_proc->entry);
  /* xpsr */
  *stack++ = 0x01000000;

  /* task runs at a defined processor mode */
  //core_context->sp = USER_TASKS_ARM_MODE; /* macro defined into subarch part */

#if WITH_AUTOSAR_STACK_MONITORING == YES
    (*(uint8 *)(the_proc->stack.stack_zone)) = OS_STACK_PATTERN;
#endif
}

FUNC(uint8, OS_CODE) tpl_check_stack_footprint(CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
  uint8 tmp;
  /*to do*/
  tmp=0;
  return tmp;
}

/*
 * tpl_sleep is used by the idle task
 */
void idle_function(void)
{
    while(1);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_machine_arm_generic.c */
