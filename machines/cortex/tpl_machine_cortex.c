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

#if TASK_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateTask(void);
#endif

/*
 * The kernel stack. When a system call is done, the sc handler switches
 * to the kernel stack.
 */
VAR (uint32, OS_VAR) tpl_kernel_stack[KERNEL_STACK_SIZE];
VAR (uint32, OS_VAR) tpl_kernel_stack_top;

/*
 * Kernel entry counter
 */
volatile VAR (uint32, OS_VAR) nested_kernel_entrance_counter;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) setTimer()
{
	if (SysTick_Config(SystemCoreClock / 1000))
	{
		while(1);
	}
}

FUNC (void, OS_CODE) tpl_init_machine_generic (void)
{
#if WITH_MEMORY_PROTECTION == YES
  tpl_init_mp();
#endif
}

FUNC (void, OS_CODE) tpl_init_machine_specific (void)
{
	tpl_kernel_stack_top = (uint32)&tpl_kernel_stack[KERNEL_STACK_SIZE - 1];
	nested_kernel_entrance_counter = 0;
	__set_MSP(tpl_kernel_stack_top);
  setTimer();
	__set_CONTROL(0x3); // Switch to use Process Stack, privileged state
	__ISB(); // Execute ISB after changing CONTROL (architectural recommendation)
  /* Set SVCall priority to 2 */
//	NVIC_SetPriority(SVCall_IRQn, 2);
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
  for (i = 0; i < 16; i++ )
  {
	  l_tpl_context->gpr[i] = 0;
  }
  /* sp : setup initial stack pointer.
   * The SP points to (stack_zone + stack_size - ARM_CORE_EXCEPTION_FRAME_SIZE)
   * ARM_CORE_EXCEPTION_FRAME_SIZE is the frame pushed by the core at each exception.
   * This frame consists in pushing xpsr, pc, lr, r12, r3, r2, r1, r0
   *  */
  l_tpl_context->stackPointer = ((uint32)the_proc->stack.stack_zone) + ((uint32)the_proc->stack.stack_size) - ARM_CORE_EXCEPTION_FRAME_SIZE;

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
#if TASK_COUNT > 0
#if   ISR_COUNT > 0
  /*
   * at least a task and at least an ISR2 exist. So we have to deal with
   * what to put in the return function
   */
  *stack++ = (IS_ROUTINE == the_proc->type) ? (uint32)(CallTerminateISR2) : (uint32)(CallTerminateTask);
#else
  /*
   * At least a task but no ISR2. The return function is CallTerminateTask
   */
  *stack++ = (uint32)(CallTerminateTask);
#endif
#else
#if   ISR_COUNT > 0
  /*
   * No task but at least an ISR2 exists. The return function is CallTerminateISR2
   */
  *stack++ = (uint32)(CallTerminateISR2);
#else
  /*
   * Never go there
   */
  *stack++ = NULL;
#endif
#endif
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

void tpl_init_machine()
{
    tpl_init_machine_generic ();
	tpl_init_machine_specific();
    //Init();
}

void tpl_shutdown ()
{
    /* FIXME: this is does not conform to AUTOSAR OS specifications,
     * should return to main with initial context */
    //DISABLE_FIQ ();
    //DISABLE_IRQ ();
	// remove ITs

  	// spurious events can wake up processor :
	__asm__ (" CPSID	I");

	// we need a loop to ensure sleep
	while(1)
	{
		__asm__ ("   wfi ;"); 	// go to sleep until NMI/HARD FAULT/RESET
	}

    /* TODO : fall into very low consumption mode : all
     * internal CPU clocks are disabled.
     */

    while (1);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_machine_arm_generic.c */
