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
#include "tpl_timers.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_registers.h"

#if (TASK_COUNT > 0)
extern FUNC(void, OS_CODE) CallTerminateTask();
#endif
#if (ISR_COUNT > 0)
extern FUNC(void, OS_CODE) CallTerminateISR2();
#endif

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
extern VAR(uint32, OS_VAR) tpl_tick_init_value;
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
extern CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
  tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+NUMBER_OF_CORES];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(uint32, OS_VAR) tpl_msr_start_value;
VAR(uint32, OS_VAR) tpl_register_r2;
VAR(uint32, OS_VAR) tpl_register_r13;
VAR(tpl_stack_word, OS_VAR)   tpl_kernel_stack[NUMBER_OF_CORES][KERNEL_STACK_SIZE/sizeof(tpl_stack_word)];
P2VAR(tpl_stack_word, OS_VAR, OS_VAR) tpl_kernel_stack_bottom[NUMBER_OF_CORES];
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
extern FUNC(void, OS_CODE) tpl_init_regs(void);
extern FUNC(void, OS_CODE) tpl_init_ivpr(void);
extern FUNC(void, OS_CODE) tpl_init_isr_prio(void);
#if WITH_MEMORY_PROTECTION == YES
extern FUNC(void, OS_CODE) tpl_init_mp(void);
#endif
#if (TPL_USE_DECREMENTER == YES)
extern CONST(tpl_it_handler, OS_CONST) tpl_dec_table[NUMBER_OF_CORES];
extern FUNC(void, OS_CODE) tpl_init_dec(void);
#endif


/**
 * TODO: document this
 */
FUNC(void, OS_CODE) tpl_sleep(void)
{
    /* MISRA RULE 14.3, 14.8 VIOLATION: infinite loop of idle task */
    while (1);
}

FUNC(void, OS_CODE) idle_function(void)
{
    /* MISRA RULE 14.3, 14.8 VIOLATION: infinite loop of idle task */
    while (1);
}


FUNC(void, OS_CODE) tpl_init_interrupts(void)
{
  GET_CURRENT_CORE_ID(core)

  TPL_INTC(core).CPR = 0;
  GET_CURRENT_DATE(core) = 0;
  tpl_init_ivpr();
}

FUNC(void, OS_CODE) tpl_init_kernel_stack(void)
{
  GET_CURRENT_CORE_ID(core)

  GET_KERNEL_STACK_BOTTOM(core) = &(GET_KERNEL_STACK(core)[KERNEL_STACK_SIZE/sizeof(tpl_stack_word) - 1]);
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
  VAR(uint32, OS_VAR) msr_mode = tpl_msr_start_value;


/*  ic->cr = 0; */
  my_ic->xer = 0;
  my_ic->ctr = 0;

  /* address of the instruction to excute when returning
     from the system call. So it is set to the entry point of the task
  */

  my_ic->srr0 = (uint32)proc->entry;

  /* External interrupt enabled */
  msr_mode = msr_mode | EE_BIT_1;
#if !(defined DEBUG_OS_MCU_IN_SUPERVISOR_MODE) && (WITH_MEMORY_PROTECTION == YES)
  /* MSR in User mode */
  msr_mode = msr_mode | PR_BIT_1;
#endif
#if (WITH_FLOAT == YES)
  /* Floating-point available */
  msr_mode = msr_mode | FP_BIT_1;
#endif
  my_ic->srr1 = msr_mode;

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
#if (TASK_COUNT > 0) && (ISR_COUNT > 0)
  *stack_addr = (IS_ROUTINE == proc->type) ?
                (uint32)(&CallTerminateISR2) :
                (uint32)(&CallTerminateTask); /*  lr  */
#elif (TASK_COUNT > 0)
  *stack_addr = (uint32)(&CallTerminateTask);
#elif (ISR_COUNT > 0)
  *stack_addr = (uint32)(&CallTerminateISR2);
#endif
  stack_addr++;

  *stack_addr = 0; /*  cr  */
  stack_addr++;
  *stack_addr = 0; /*  r0  */
  stack_addr++;
}

FUNC(void, OS_CODE) tpl_init_core(void)
{
  GET_CURRENT_CORE_ID(core)
  tpl_init_regs();
#if (TPL_USE_DECREMENTER == YES) && (NUMBER_OF_CORES == 1)
  tpl_init_dec();
#elif (TPL_USE_DECREMENTER == YES) && (NUMBER_OF_CORES > 1)
  /* Enable the decrementer only if this core has a dec handler */
  if(tpl_dec_table[core] != NULL)
  {
    tpl_init_dec();
  }
#endif
#if WITH_ORTI == YES
  tpl_fill_stack_pattern();
#endif
#if WITH_MEMORY_PROTECTION == YES
  tpl_init_mp();
#endif
}

FUNC(void, OS_CODE) tpl_init_mode_entry_module(void)
{
  /* PC1 Mode behaviour : Peripheral active in RUN0-3 modes   */
  TPL_ME.RUN_PC[ME_PC1_CONFIGURATION] = ME_RUNPC_RUN0
                                      | ME_RUNPC_RUN1
                                      | ME_RUNPC_RUN2
                                      | ME_RUNPC_RUN3;

#if (TPL_USE_PIT == YES)
  /* Set PIT in PC1 mode  */
  TPL_ME.PCTL[ME_PCTL_PIT] = ME_PC1_CONFIGURATION;
#endif

  /* Enable RUN0 Mode     */
  TPL_ME.MCTL = ME_MCTL_TGT_RUN0 | ME_MCTL_KEY1;
  TPL_ME.MCTL = ME_MCTL_TGT_RUN0 | ME_MCTL_KEY2;

  /* Loop and wait until mode has changed  */
  while (!(TPL_ME.IS & ME_IS_IMTC));
  /* Ack mode change                       */
  TPL_ME.IS = ME_IS_IMTC;
}

FUNC(void, OS_CODE) tpl_rgm_clear(void)
{
  /* RGM Clear safe mode status */
  while(TPL_RGM.FES || TPL_RGM.DES) {
      TPL_RGM.FES = (uint16) 0xFFFF;
      TPL_RGM.DES = (uint16) 0xFFFF;
  }
}

FUNC(void, OS_CODE) tpl_init_machine(void)
{

  /* these 3 variables are init right after
     in assemby but this init avoid a wrong
     MISRA rule violation */
  tpl_register_r2 = 0;
  tpl_register_r13 = 0;
  tpl_msr_start_value = 0;

  tpl_init_mode_entry_module();

  tpl_rgm_clear();

  tpl_init_isr_prio();

#if (TPL_USE_PIT == YES)
  tpl_init_pit();
  tpl_load_pits();
#endif

#if (WITH_MULTICORE == NO)
  /* In multicore, core dependant initialization is done in StartOS by
   * all cores
   */
  tpl_init_core();
#endif
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file tpl_init_term.c */
