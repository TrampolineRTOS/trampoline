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

/*
 * Include the tpl_cortex_defenitions.h generated header that set the
 * priority of various Handlers
 */
#include "tpl_cortex_definitions.h"

#define OS_START_SEC_VAR_8BIT
#include "tpl_memmap.h"

tpl_bool tpl_isr2_disabled = FALSE;

#define OS_STOP_SEC_VAR_8BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern void decPeriode(void);
extern void test_toggle(void);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#define API_START_SEC_CODE
#include "tpl_memmap.h"

#if TASK_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateTask(void);
#endif
#if ISR_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateISR2();
#endif

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Generated functions prototypes
 */
extern FUNC(void, OS_CODE) tpl_init_external_interrupts();
extern FUNC(void, OS_CODE) tpl_init_it_priority();

FUNC (void, OS_CODE) tpl_init_machine_generic (void)
{
#if WITH_MEMORY_PROTECTION == YES
  tpl_init_mp();
#endif
}

FUNC (void, OS_CODE) tpl_init_machine_specific (void)
{
  tpl_set_systick_timer();
  tpl_init_external_interrupts();
  tpl_init_it_priority();
  /*
   * Set the SVC priority to KERNEL_PRIO
   */
  NVIC_SetPriority(SVCall_IRQn, KERNEL_PRIO_UNSHIFTED);
  /*
   * Switch to use PSP, unprivileged state
   */
  __set_CONTROL(0x3);
  /*
   * Instruction SynchronizationBarrier
   * Execute ISB after changing CONTROL (architectural recommendation)
   */
  __ISB();
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and the entry point
 *
 * Initializing the context consists in the initializing the context structure.
 * The initialization of r4 to r11 is not mandatory but the PSP is:
 * +------------------+
 * | R4               | <- CTX_GPR4
 * +------------------+
 * | R5               | <- CTX_GPR5
 * +------------------+
 * | R6               | <- CTX_GPR6
 * +------------------+
 * | R7               | <- CTX_GPR7
 * +------------------+
 * | R8               | <- CTX_GPR8
 * +------------------+
 * | R9               | <- CTX_GPR9
 * +------------------+
 * | R10              | <- CTX_GPR10
 * +------------------+
 * | R11              | <- CTX_GPR11
 * +------------------+
 * | PSP (R13)        | <- CTX_PSP
 * +------------------+
 * And the initialization of the exception frame.
 * The initialization of r0 to r3 and r12 is not mandatory but the LR, the PC
 * and the xPSR is:
 * +-------------------------------+
 * | R0                            | <- PSP
 * +-------------------------------+
 * | R1                            | <- PSP+4
 * +-------------------------------+
 * | R2                            | <- PSP+8
 * +-------------------------------+
 * | R3                            | <- PSP+12
 * +-------------------------------+
 * | R12                           | <- PSP+16
 * +-------------------------------+
 * | LR (aka R14)                  | <- PSP+20
 * +-------------------------------+
 * | Return Address (saved PC/R15) | <- PSP+24
 * +-------------------------------+
 * | xPSR (bit 9 = 1)              | <- PSP+28
 * +-------------------------------+
 */

#define GPR_ON_EXCEPTION_FRAME  5 /* registers r0-r3 and r12 */
#define LR_IDX                  5
#define PC_IDX                  6
#define xPSR_IDX                7

FUNC(void, OS_CODE) tpl_init_context(
  CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
#if WITH_PAINT_REGISTERS == YES || WITH_PAINT_STACK == YES
  VAR(int, AUTOMATIC) i;
#endif

  /* The pointer to the static descriptor of the process */
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) the_proc =
    tpl_stat_proc_table[proc_id];

  /* The pointer to the context of the process */
  CONSTP2VAR(arm_core_context, AUTOMATIC, OS_APPL_DATA) l_tpl_context =
    the_proc->context;

  /* The pointer to the stack of the process */
  CONSTP2VAR(tpl_stack_word, AUTOMATIC, OS_APPL_DATA) stack =
    the_proc->stack.stack_zone;

  /* The size of the stack in 32 bits word above the esception frame */
  CONST(uint32, AUTOMATIC) size_of_stack_above_exception_frame =
    (the_proc->stack.stack_size - ARM_CORE_EXCEPTION_FRAME_SIZE) >> 2;

  /* The pointer to the exception frame */
  CONSTP2VAR(tpl_stack_word, AUTOMATIC, OS_APPL_DATA) exception_frame =
    stack + size_of_stack_above_exception_frame;

#if WITH_PAINT_REGISTERS == YES
  /*
   * Set GPRs to the stack pattern to track changes.
   * This is not mandatory, so it is done only if the OIL OS attribute
   * PAINT_REGISTERS is set to TRUE. Otherwise the registers are not
   * initialized.
   */
  l_tpl_context->gpr4 =
  l_tpl_context->gpr5 =
  l_tpl_context->gpr6 =
  l_tpl_context->gpr7 =
  l_tpl_context->gpr8 =
  l_tpl_context->gpr9 =
  l_tpl_context->gpr10 =
  l_tpl_context->gpr11 = OS_STACK_PATTERN;

  /*
   * Paint the registers on the exception frame : r0, r1, r2, r3 and r12
   */
  for (i = 0; i < GPR_ON_EXCEPTION_FRAME; i++)
  {
    exception_frame[i] = OS_STACK_PATTERN;
  }
#endif
  /* sp : setup initial stack pointer.
   * The SP points to (stack_zone + stack_size - ARM_CORE_EXCEPTION_FRAME_SIZE)
   * ARM_CORE_EXCEPTION_FRAME_SIZE is the frame pushed by the core at each exception.
   * This frame consists in pushing xpsr, pc, lr, r12, r3, r2, r1, r0
   *  */
  l_tpl_context->stackPointer = (uint32)exception_frame;

#if WITH_PAINT_STACK == YES
  /*
   * Paint the stack with a pattern. This is not mandatory, so it is done
   * only if the OIL OS attribute PAINT_STACK is set to TRUE. Otherwise the
   * stack above the exception frame is not initialized.
   */
  for (i = 0; i < size_of_stack_above_exception_frame; i++)
  {
    stack[i] = OS_STACK_PATTERN;
  }
#endif

  /* lr
   * Set the return address of the task/isr. This is usefull in case the
   * user forgets to call TerminateTask/TerminateISR
   * MISRA RULE 1,45,85 VIOLATION: the function pointer is used and stored
   * in a 32bits variable, but as the Os is dependant on the target,
   * the behaviour is controlled
   */
#if TASK_COUNT > 0
#if   ISR_COUNT > 0
  /*
   * at least a task and at least an ISR2 exist. So we have to deal with
   * what to put in the return function
   */
  exception_frame[LR_IDX] =
    (IS_ROUTINE == the_proc->type) ?
      (uint32)(CallTerminateISR2) :
      (uint32)(CallTerminateTask) ;
#else
  /*
   * At least a task but no ISR2. The return function is CallTerminateTask
   */
  exception_frame[LR_IDX] = (uint32)(CallTerminateTask);
#endif
#else
#if   ISR_COUNT > 0
  /*
   * No task but at least an ISR2 exists. The return function is CallTerminateISR2
   */
  exception_frame[LR_IDX] = (uint32)(CallTerminateISR2);
#else
  /*
   * Never go there : no task and no ISR
   */
  exception_frame[LR_IDX] = NULL;
#endif
#endif
  /* pc */
  exception_frame[PC_IDX] = (uint32)(the_proc->entry);
  /* xpsr */
  exception_frame[xPSR_IDX] = 0x01000000;

#if WITH_AUTOSAR_STACK_MONITORING == YES && WITH_PAINT_STACK == NO
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
    while(1)
  {
      __WFE();
  }
}

void tpl_init_machine()
{
    tpl_init_machine_generic ();
    tpl_init_machine_specific();
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
