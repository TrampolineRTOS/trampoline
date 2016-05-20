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
 * MPC5674F port - copyright(c) 2016 propriété de l'IRT Saint Exupery, tous droits reservés
 *
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
#include "tpl_os_interrupt.h"
#include "tpl_os_interrupt_kernel.h"
#include "tpl_os_error.h"
#include "tpl_os.h"
#include "tpl_app_config.h"
#if (WITH_IOC ==  YES)
#include "tpl_ioc_kernel.h"
#endif
#include "tpl_timers.h"
#include "tpl_compiler.h"
#include "tpl_mpc5674f_define.h"

/*
 * External interrupt bit mask in MSR
 */
#define EE_BIT_1  0x8000
#define RI_BIT_1  0x0002


#define OS_START_SEC_VAR_32
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_VAR)
  idle_stack[IDLE_STACK_SIZE/sizeof(tpl_stack_word)];
extern VAR(uint32, OS_VAR) tpl_tick_init_value;
#define OS_STOP_SEC_VAR_32
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
extern CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
  tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_32
#include "tpl_memmap.h"
VAR(uint32, OS_VAR) tpl_msr_start_value;
VAR(uint32, OS_VAR) tpl_register_r2;
VAR(uint32, OS_VAR) tpl_register_r13;
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
  /* srr0 */ (uint32)&idle_function,
  /* srr1 */ 0x00008000
};


#define OS_STOP_SEC_VAR_32
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
extern FUNC(void, OS_CODE) tpl_init_regs(void);
extern FUNC(void, OS_CODE) tpl_init_interrupts(void);
extern FUNC(void, OS_CODE) tpl_init_isr_prio(void);
/* MPC5674F_Porting_Modif : Add the declaration of this function since it is called after task execution */ 
extern FUNC(void, OS_CODE) CallTerminateTask(void);
#if WITH_MEMORY_PROTECTION == YES
extern FUNC(void, OS_CODE) tpl_init_mp(void);
#endif
#if INTC_HW_MODE == YES
extern FUNC(void, OS_CODE) tpl_set_it_prio(void);
#endif
#if (TPL_TICK_TIMER == TPL_DECREMENTER)
extern FUNC(void, OS_CODE) tpl_init_dec(void);
#endif
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define USER_MODE 0x4000

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
  CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) proc = tpl_stat_proc_table[proc_id];
  P2VAR(ppc_integer_context, AUTOMATIC, OS_APPL_DATA) my_ic = proc->context.ic;
  P2VAR(tpl_stack_word, AUTOMATIC, OS_APPL_DATA) stack_addr = proc->stack.stack_zone;


/*  ic->cr = 0; */
  my_ic->xer = 0;
  my_ic->ctr = 0;

  /* address of the instruction to excute when returning
     from the system call. So it is set to the entry point of the task
  */

  my_ic->srr0 = (uint32)proc->entry;
#ifdef DEBUG_OS_MCU_IN_SUPERVISOR_MODE
  /* Keep MCU in Supervisor mode */
  my_ic->srr1 = tpl_msr_start_value | EE_BIT_1;
#else /* !DEBUG_OS_MCU_IN_SUPERVISOR_MODE */
  /* Set MCU in User mode */
  my_ic->srr1 = tpl_msr_start_value | EE_BIT_1; //| USER_MODE; /* just to test, it is mandatory to change priority of INTC when calling an OS service (system call) */
#endif /* DEBUG_OS_MCU_IN_SUPERVISOR_MODE */

  /*  The stack pointer is computed by adding the base address of
      the stack to its size and by substracting the space needed
      for the linkage area and 12 bytes that are pushed by the
      context switch function */
  my_ic->gpr[1] = ((((uint32)(proc->stack).stack_zone))
                + ((proc->stack).stack_size))
                - 48;
  my_ic->gpr[2] = tpl_register_r2;
  my_ic->gpr[13] = tpl_register_r13;

  /* write a pattern a the bottom of the stack in order to detect
   * stack overflow with the stack monitoring */
  *(proc->stack.stack_zone) = TPL_FULL_STACK_PATTERN;

  /*
   * r11, r12, lr, cr and r0 have to be initialized on the process stack
   * these registers are located in this order, starting at stack_size - 48
   * divided by 4 (32 bits implementation)
   */
  /*
   * MISRA RULE 17.4 VIOLATION: performing arithmetic on pointer
   * is mandatory here because we compute the stack address
   */
  stack_addr += (proc->stack.stack_size - 48) >> 2;
  *stack_addr = 0; /*  r11 */
  stack_addr++;
  *stack_addr = 0; /*  r12 */
  stack_addr++;

  /*
   * set the return address of the task/isr. This is usefull in case the
   * user forgets to call TerminateTask/TerminateISR
   */
  /*
   * MISRA RULE 11.3 VIOLATION: the function pointer is used and stored
   * in a 32bits variable, but as the Os is dependant on the target,
   * the behaviour is controled
   */
   *stack_addr = (IS_ROUTINE == proc->type) ?
                (uint32)(&CallTerminateISR2) :
                (uint32)(&CallTerminateTask);   /*  lr  */ 
  stack_addr++;

  *stack_addr = 0; /*  cr  */
  stack_addr++;
  *stack_addr = 0; /*  r0  */
  stack_addr++;
}


/* MPC5674F_Porting_Modif : Add this function since it used in the goil generated file tpl_app_config.c and must be defined */ 
FUNC(void, OS_CODE) idle_function(void)
{
    while (1)
    {
        /* do nothing */
/*        asm("   wrteei  1   "); */
    }
}


FUNC(void, OS_CODE) tpl_init_machine(void)
{

    /* initializes the TaskLock counter */
/*  tpl_user_task_lock = FALSE;
  tpl_cpt_user_task_lock = 0;
  tpl_cpt_os_task_lock = 0;
  */

  tpl_current_date = 0;


  /* these 3 variables are init right after
     in assemby but this init avoid a wrong
     MISRA rule violation */
  tpl_register_r2 = 0;
  tpl_register_r13 = 0;
  tpl_msr_start_value = 0;


  idle_task_context.gpr[1] = (((uint32)(idle_stack)) + IDLE_STACK_SIZE) - 48;

#if WITH_ORTI == YES
  tpl_fill_stack_pattern();
#endif


  tpl_init_regs();
  tpl_init_interrupts();

/* MPC5674F_Porting_Modif: Assign priorities of ISR1 when there are some declared in application */  
#if INTC_HW_MODE == YES  
  tpl_set_it_prio();
#endif  
  /* tpl_init_isr_prio(); */ /* MPC5674F_Porting_Modif : not found in generated files */ 

#if WITH_MEMORY_PROTECTION == YES
  tpl_init_mp();
#endif

#if ((WITH_IOC == YES) && (IOC_UNQUEUED_COUNT > 0))
  tpl_ioc_init_unqueued();
#endif

#if ((TPL_TICK_TIMER != TPL_DECREMENTER) || (WITH_AUTOSAR_TIMING_PROTECTION==YES))
  tpl_init_pit();
#endif

#if (TPL_TICK_TIMER == TPL_DECREMENTER)
  tpl_init_dec();   
#else
  tpl_load_pit(TPL_TICK_TIMER, PIT_OS_TICK_VALUE);
#endif

}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file tpl_init_term.c */
