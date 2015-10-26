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
#if WITH_AUTOSAR == YES
#include "tpl_as_definitions.h"
#endif
#include "tpl_os_interrupt.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/**
 * Stack for the idle task
 */
VAR(tpl_stack_word, OS_VAR) idle_stack[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];

/**
 * Context for the idle task
 */
VAR (arm_context, OS_VAR) idle_task_context;

/**
 * Kernel entry counter
 */
volatile VAR (uint32, OS_VAR) nested_kernel_entrance_counter;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define API_START_SEC_CODE
#include "tpl_memmap.h"

#if TASK_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateTask(void);
#endif

#if ISR_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateISR2(void);
#endif

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC (void, OS_CODE) tpl_init_machine_generic (void)
{
  nested_kernel_entrance_counter = 0;
#if WITH_MEMORY_PROTECTION == YES
  tpl_init_mp();
#endif
}

/*
 * tpl_sleep is used by the idle task
 */
void idle_function(void)
{
    while(1);
}

/**
 * Call Terminate Task function when no TerminateTask hasn't been called
 * or when TerminateTask didn't success because of resource hold or
 * interrupts disabled.
 *
 */
extern FUNC(void, OS_CODE) CallTerminateTask(void);


/**
 * Call Terminate ISR2 function when TerminateISR didn't success doing it
 * because of resource hold or interrupts disabled.
 *
 */
extern FUNC(void, OS_CODE) CallTerminateISR2(void);

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
  "mrs r0, spsr ;"
  "bic r0, r0, #0b11000000 ;"
  "msr spsr, r0 ;"
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
  "mrs r0, cpsr ;"
  "orr r0, r0, #0b11000000 ;"
  "msr cpsr, r0 ;"
  "mrs r0, spsr ;" // interrupts remain locked in user space
  "orr r0, r0, #0b11000000 ;"
  "msr spsr, r0"
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
  struct ARM_CONTEXT *core_context;
  const tpl_proc_static *the_proc;

  /* initialize shortcuts */
  the_proc = tpl_stat_proc_table[proc_id];
  core_context = the_proc->context;

  /* setup entry point */
  core_context->r[armreg_pc] = (uint32)(the_proc->entry);
  /* setup initial stack pointer */
  core_context->r[armreg_sp] = ((uint32)the_proc->stack.stack_zone)
      + the_proc->stack.stack_size;
  /* task runs at a defined processor mode */
  core_context->psr = USER_TASKS_ARM_MODE; /* macro defined into subarch part */

  /*
   * set the return address of the task/isr. This is usefull in case the
   * user forgets to call TerminateTask/TerminateISR
   * MISRA RULE 1,45,85 VIOLATION: the function pointer is used and stored
   * in a 32bits variable, but as the Os is dependant on the target,
   * the behaviour is controled
   */
  core_context->r[armreg_lr] = (IS_ROUTINE == the_proc->type) ?
                                (uint32)(CallTerminateISR2) :
                                (uint32)(CallTerminateTask); /*  lr  */

  /* TODO: initialize stack footprint */
}

FUNC(uint8, OS_CODE) tpl_check_stack_footprint (
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
  uint8 tmp;
  /*to do*/
  tmp=0;
  return tmp;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_machine_arm_generic.c */
