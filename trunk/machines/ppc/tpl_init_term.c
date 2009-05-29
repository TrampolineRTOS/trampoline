/**
 * @file tpl_init_term.c
 *
 * @section descr File description
 *
 * Trampoline machine dependant C implementation stuff for the PowerPC port.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
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
#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"
#include "tpl_os_it.h"
#include "tpl_os_it_kernel.h"
#include "tpl_assembler.h"
#include "MPC551x.h"

extern CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
  tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1];

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
u32 tpl_msr_start_value;
u32 tpl_register_r2;
u32 tpl_register_r13;
VAR(ppc_integer_context, OS_VAR) idle_task_context;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
STATIC FUNC(void, OS_CODE) tpl_call_missingend(void);
STATIC FUNC(void, OS_CODE) tpl_call_terminateISR(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * tpl_init_context
 *
 * This function initialize the machine dependant context of a process
 *
 * @param   proc_id   the id of the process
 */
FUNC(void, OS_CODE) tpl_init_context(
  VAR(tpl_proc_id, AUTOMATIC) proc_id)
{
	VAR(int, AUTOMATIC) i;
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc =
    tpl_stat_proc_table[proc_id];
	P2VAR(ppc_integer_context, AUTOMATIC, OS_APPL_DATA) ic =
    proc->context.ic;
	
	for (i = 0; i < 32; i++ )
  {
        ic->gpr[i] = 0;
	}
	
	ic->cr = 0;
	ic->xer = 0;
	ic->ctr = 0;
	
	/* address of the instruction to excute when returning
	   from the system call. So it is set to the entry point of the task
	*/
	ic->srr0 = (unsigned long)proc->entry;
	ic->srr1 = tpl_msr_start_value | EE_BIT;
	/*  The stack pointer is computed by adding the base address of
	    the stack to its size and by substracting the space needed
	    for the linkage area and 12 bytes that are pushed by the 
	    context switch function */
	ic->gpr[1] = ((unsigned long)proc->stack.stack_zone)
	               + proc->stack.stack_size
	               - 48;
  ic->gpr[2] = tpl_register_r2;
  ic->gpr[13] = tpl_register_r13;

  /* set the return address of the task/isr. This is usefull in case the
     user forgets to call TerminateTask/TerminateISR */
  if (IS_ROUTINE == proc->type)
  {
  /* MISRA RULE 1,45,85 VIOLATION: the function pointer is used and stored
     in a 32bits variable, but as the Os is dependant on the target,
     the behaviour is controled */
    ic->lr = (u32)(tpl_call_terminateISR);
  }
  else
  {
    ic->lr = (u32)(tpl_call_missingend);
  }
}

/**
 * TODO: document this
 */
STATIC FUNC(void, OS_CODE) tpl_call_missingend(void)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

#ifdef WITH_AUTOSAR
    CALL_ERROR_HOOK(E_OS_MISSINGEND);
#endif
/*    result = TerminateTask(); */
}

/**
 * TODO: document this
 */
STATIC FUNC(void, OS_CODE) tpl_call_terminateISR(void)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;
/*    VAR(uint8, AUTOMATIC) current_prio = 0; */

    asm("  wrteei  0");

/* MISRA RULE 43 VIOLATION: conversion uint32 to uint8, but PRI field is only
   4 bits, so the converted number fits in 8bits */
/*    current_prio = INTC.CPR_PRC0.B.PRI; */

/*    tpl_keep_prio[current_prio] = TRUE;

    result = TerminateISR(); */
}

/**
 * TODO: document this
 */
FUNC(void, OS_CODE) tpl_sleep(void)
{
    while (1)
    {
        /* do nothing */
        asm("   wrteei  1   ");
    }
}

/**
 * TODO: document this
 */
FUNC(void, OS_CODE) tpl_shutdown(void)
{
    /* sleep forever */
    asm("   wrteei  0   ");
    while (1)
    {
        /* do nothing */
    }
}

/*
 */
/*void tpl_init_machine(void)
 - {
 - #pragma asm
 -       subi  r1,r1,4
 -       stw   r3,0(r1)
 -       lis   r3,%hi(tpl_register_r2)
 -       stw     r2,%lo(tpl_register_r2)(r3)
 -       lis   r3,%hi(tpl_register_r13)
 -       stw     r13,%lo(tpl_register_r13)(r3)
 -       mfmsr r0
 -       lis     r3,%hi(tpl_msr_start_value)
 -       stw     r0,%lo(tpl_msr_start_value)(r3)
 -       lwz   r3,0(r1)
 -       addi  r1,r1,4
 -       blr
 - #pragma endasm
 - }
*/

FUNC(void, OS_CODE) tpl_init_machine(void)
{
  VAR(u8, AUTOMATIC) i;

    /* initializes the TaskLock counter */
/*  tpl_user_task_lock = FALSE;
  tpl_cpt_user_task_lock = 0;
  tpl_cpt_os_task_lock = 0;
  */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_remaining_watchdog_time = 0;
#endif
  /* these 3 variables are init right after
     in assemby but this init avoid a wrong
     MISRA rule violation */
  tpl_register_r2 = 0;
  tpl_register_r13 = 0;
  tpl_msr_start_value = 0;



  INTC.MCR.B.HVEN_PRC0 = 0;
  INTC.MCR.B.VTES_PRC0 = 0;
  INTC.IACKR_PRC0.R = (uint32_t)(&InterruptVectortable[0]);

  INTC.CPR_PRC0.R = 0;

  /* init idle_task context*/
  for (i = 0; i < 32; i++ )
  {
        idle_task_context.gpr[i] = 0;
  }

  idle_task_context.cr = 0;
  idle_task_context.xer = 0;
  idle_task_context.ctr = 0;

  idle_task_context.srr0 = (u32)tpl_sleep;
  idle_task_context.srr1 = tpl_msr_start_value | 0x00008000;

  /* initialises the stack pointer of the idle task to
    start address + stack size = end of stack zone */
  /* if Stack Monitoring is enabled, fill the stack with a pattern in
    order to check later if the pattern was erased */
#ifdef WITH_AUTOSAR_STACK_MONITORING
  /* MISRA RULE 1 VIOLATION: cast from integer to pointer type is
    implemenation defined, but this part of OS is implementation specific,
    and the pointer size is controlled */
  idle_task_context.gpr[1] = ((u32)(&stack_zone_of_IdleTask))
                   + SIZE_OF_IDLE_STACK
                   - 48;
  #else
  /* initialises the stack pointer of the task to
    start address + stack size = end of stack zone */
  /* MISRA RULE 1 VIOLATION: cast from integer to pointer type is
    implemenation defined, but this part of OS is implementation specific,
    and the pointer size is controlled */
/*  idle_task_context.sp = (u32)(&stack_zone_of_IdleTask);
  idle_task_context.sp = idle_task_context.sp + SIZE_OF_IDLE_STACK;
  idle_task_context.sp = idle_task_context.sp - 4;*/
#endif


#ifdef WITH_OS_DEBUG
  tpl_init_stack_debug();
  tpl_init_switch_debug();
#endif

#pragma asm
      .novle
      .align 2
      subi  sp,sp,4
      stw   r3,0(sp)
      lis   r3,%hi(tpl_register_r2)
      stw   r2,%lo(tpl_register_r2)(r3)
      lis   r3,%hi(tpl_register_r13)
      stw   r13,%lo(tpl_register_r13)(r3)
      mfmsr r0
      lis   r3,%hi(tpl_msr_start_value)
      stw   r0,%lo(tpl_msr_start_value)(r3)

;/* initializes ivpr register */
      lis     r3, __IVPR_VALUE@h
      ori     r3,r3, __IVPR_VALUE@l
      mtivpr  r3

      lwz   r3,0(r1)
      addi  sp,sp,4
#ifdef __vle__
      .vle
#endif
#pragma endasm

/*  tpl_init_tick(); */
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file tpl_init_term.c */
