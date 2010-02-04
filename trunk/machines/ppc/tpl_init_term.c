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

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_VAR)
  idle_stack[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
extern CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
  tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_VAR) tpl_msr_start_value;
VAR(u32, OS_VAR) tpl_register_r2;
VAR(u32, OS_VAR) tpl_register_r13;
VAR(ppc_integer_context, OS_VAR) idle_task_context = {
  { /* r0 */   0,
    /* sp */   0,
    /* r2 */   0,
    /* r3 */   0,
    /* r4 */   0,
    /* r5 */   0,
    /* r6 */   0,
    /* r7 */   0,
    /* r8 */   0,
    /* r9 */   0,
    /* r10 */  0,
    /* r11 */  0,
    /* r12 */  0,
    /* r13 */  0,
    /* r14 */  0,
    /* r15 */  0,
    /* r16 */  0,
    /* r17 */  0,
    /* r18 */  0,
    /* r19 */  0,
    /* r20 */  0,
    /* r21 */  0,
    /* r22 */  0,
    /* r23 */  0,
    /* r24 */  0,
    /* r25 */  0,
    /* r26 */  0,
    /* r27 */  0,
    /* r28 */  0,
    /* r29 */  0,
    /* r30 */  0,
    /* r31 */  0
  },
  /* cr   */ 0,
  /* xer  */ 0,
  /* lr   */ 0,
  /* ctr  */ 0,
  /* srr0 */ (u32)tpl_sleep,
  /* srr1 */ 0x00008000
};
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
STATIC FUNC(void, OS_CODE) tpl_call_missingend(void);
STATIC FUNC(void, OS_CODE) tpl_call_terminateISR(void);
extern FUNC(void, OS_CODE) tpl_init_regs(void);
extern FUNC(void, OS_CODE) tpl_init_interrupts(void);
extern FUNC(void, OS_CODE) tpl_init_mp(void);
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
  P2VAR(tpl_stack_word, AUTOMATIC, OS_APPL_DATA) stack =
    proc->stack.stack_zone;
  
  for (i = 0; i < 32; i++ )
  {
        ic->gpr[i] = 0;
  }
	
/*	ic->cr = 0; */
  ic->xer = 0;
 	ic->ctr = 0;
	
	/* address of the instruction to excute when returning
	   from the system call. So it is set to the entry point of the task
	*/
  ic->srr0 = (unsigned long)proc->entry;
  ic->srr1 = tpl_msr_start_value | EE_BIT_1;
  /*  The stack pointer is computed by adding the base address of
      the stack to its size and by substracting the space needed
      for the linkage area and 12 bytes that are pushed by the 
      context switch function */
  ic->gpr[1] = ((unsigned long)proc->stack.stack_zone)
                + proc->stack.stack_size
                - 48;
  ic->gpr[2] = tpl_register_r2;
  ic->gpr[13] = tpl_register_r13;

  /*
   * r11, r12, lr, cr and r0 have to be initialized on the process stack
   * these registers are located in this order, starting at stack_size - 48
   * divided by 4 (32 bits implementation)
   */
  stack += (proc->stack.stack_size - 48) >> 2;
  *stack++ = 0; /*  r11 */
  *stack++ = 0; /*  r12 */
  /*
   * set the return address of the task/isr. This is usefull in case the
   * user forgets to call TerminateTask/TerminateISR
   * MISRA RULE 1,45,85 VIOLATION: the function pointer is used and stored
   * in a 32bits variable, but as the Os is dependant on the target,
   * the behaviour is controled
   */   
  *stack++ = (IS_ROUTINE == proc->type) ?
                (u32)(tpl_call_terminateISR) :
                (u32)(tpl_call_missingend); /*  lr  */

  *stack++ = 0; /*  cr  */
  *stack++ = 0; /*  r0  */
}

/**
 * TODO: document this
 */
STATIC FUNC(void, OS_CODE) tpl_call_missingend(void)
{
/*    VAR(StatusType, AUTOMATIC) result = E_OK; */

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
/*    VAR(StatusType, AUTOMATIC) result = E_OK; */
/*    VAR(uint8, AUTOMATIC) current_prio = 0; */

/*    asm("  wrteei  0"); */

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
/*        asm("   wrteei  1   "); */
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
/*  VAR(u8, AUTOMATIC) i; */

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

  
  idle_task_context.gpr[1] = ((u32)(idle_stack)) + SIZE_OF_IDLE_STACK - 48;
/*  INTC.MCR.B.HVEN_PRC0 = 0;
  INTC.MCR.B.VTES_PRC0 = 0;
  INTC.IACKR_PRC0.R = (uint32_t)(&InterruptVectortable[0]);

  INTC.CPR_PRC0.R = 0;*/

#ifdef WITH_OS_DEBUG
  tpl_init_stack_debug();
  tpl_init_switch_debug();
#endif

  tpl_init_regs();
  tpl_init_interrupts();
  tpl_init_mp();
/*  tpl_init_tick(); */
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file tpl_init_term.c */
