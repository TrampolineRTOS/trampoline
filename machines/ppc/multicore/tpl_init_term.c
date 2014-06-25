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
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
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
#include "tpl_os_interrupt_kernel.h"
#include "tpl_os_error.h"
#include "tpl_os.h"
#include "tpl_app_config.h"
#if (WITH_IOC ==  YES)
#include "tpl_ioc_kernel.h"
#endif
#include "tpl_timers.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_registers.h"


/*
 * External interrupt bit mask in MSR
 */
#define EE_BIT_1  0x8000
#define RI_BIT_1  0x0002



#define OS_START_SEC_VAR_32
#include "tpl_memmap.h"
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
VAR(tpl_stack_word, OS_VAR)   tpl_kernel_stack[NUMBER_OF_CORES][KERNEL_STACK_SIZE/sizeof(tpl_stack_word)];
P2VAR(tpl_stack_word, OS_VAR, OS_VAR) tpl_kernel_stack_bottom[NUMBER_OF_CORES];
#define OS_STOP_SEC_VAR_32
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
extern FUNC(void, OS_CODE) tpl_init_regs(void);
extern FUNC(void, OS_CODE) tpl_init_interrupts(void);
extern FUNC(void, OS_CODE) tpl_init_isr_prio(void);
#if WITH_MEMORY_PROTECTION == YES
extern FUNC(void, OS_CODE) tpl_init_mp(void);
#endif
#if (TPL_TICK_TIMER == TPL_DECREMENTER)
extern FUNC(void, OS_CODE) tpl_init_dec(void);
#endif
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define USER_MODE 0x4000

#define OS_START_SEC_CODE
#include "tpl_memmap.h"


FUNC(void, OS_CODE) Os_Init(void)
{
  uint8 core;
  
  for(core=0; core<NUMBER_OF_CORES; core++)
  {
    tpl_kernel_stack_bottom[core] = &(tpl_kernel_stack[core][KERNEL_STACK_SIZE/sizeof(tpl_stack_word) - 1]);
  }
  tpl_init_interrupts();
}


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
#if (defined DEBUG_OS_MCU_IN_SUPERVISOR_MODE) || (WITH_MEMORY_PROTECTION == NO)
  /* Keep MCU in Supervisor mode */
  my_ic->srr1 = tpl_msr_start_value | EE_BIT_1;
#else /* !DEBUG_OS_MCU_IN_SUPERVISOR_MODE */
  /* Set MCU in User mode */
  my_ic->srr1 = tpl_msr_start_value | EE_BIT_1 | USER_MODE;
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
                (uint32)(&CallTerminateTask); /*  lr  */
  stack_addr++;

  *stack_addr = 0; /*  cr  */
  stack_addr++;
  *stack_addr = 0; /*  r0  */
  stack_addr++;
}


/**
 * TODO: document this
 */
FUNC(void, OS_CODE) tpl_sleep(void)
{
    /* MISRA RULE 14.3, 14.8 VIOLATION: infinite loop of idle task */
    while (1);
}



FUNC(void, OS_CODE) tpl_init_core(void)
{
  
  tpl_init_regs();
  tpl_init_dec();
  
}


FUNC(void, OS_CODE) tpl_init_machine(void)
{
  VAR(uint8, AUTOMATIC) core;
  
  for(core=0; core<NUMBER_OF_CORES; core++)
  {
    tpl_current_date[core] = 0;
    *(uint32*)(tpl_intc[core] + TPL_INTC_CPR_PRC0) = 0;
  }

  /* these 3 variables are init right after
     in assemby but this init avoid a wrong
     MISRA rule violation */
  tpl_register_r2 = 0;
  tpl_register_r13 = 0;
  tpl_msr_start_value = 0;



#if WITH_ORTI == YES
  tpl_fill_stack_pattern();
#endif

#if (WITH_MULTICORE==NO)
  tpl_init_regs();
#endif
  tpl_init_interrupts();

  tpl_init_isr_prio();

#if WITH_MEMORY_PROTECTION == YES
  tpl_init_mp();
#endif

#if ((WITH_IOC == YES) && (IOC_UNQUEUED_COUNT > 0))
  tpl_ioc_init_unqueued();
#endif

#if ((TPL_TICK_TIMER != TPL_DECREMENTER) || (WITH_AUTOSAR_TIMING_PROTECTION==YES))
  tpl_init_pit();
#endif

#if ( (TPL_TICK_TIMER == TPL_DECREMENTER) && (WITH_MULTICORE==NO))
  tpl_init_dec();
#else
  tpl_load_pit(TPL_TICK_TIMER, tpl_tick_init_value);
#endif

}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file tpl_init_term.c */
