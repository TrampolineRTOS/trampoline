/**
 * @file tpl_machine_pp.c
 *
 * @section descr File description
 *
 * Trampoline machine dependant functions
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
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */

#include "tpl_os_internal_types.h"
#include "tpl_os_kernel.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os.h"
#include "tpl_app_define.h"
#include "tpl_timers.h"



#define OS_START_SEC_VAR_32
#include "tpl_memmap.h"

VAR(uint32, OS_VAR) tpl_current_date;

#define OS_STOP_SEC_VAR_32
#include "tpl_memmap.h"



#define OS_START_SEC_CODE
#include "tpl_memmap.h"


#if WITH_STACK_MONITORING == YES
/**
 * tpl_check_stack_pointer checks the stack pointer is in the bounds of the process stack
 *
 * @param proc_id   id of the task.isr to check the stack pointer
 *
 * @return  1 if in the bounds
 *          0 if not in the bounds
 *
 */
FUNC(tpl_bool, OS_CODE) tpl_check_stack_pointer(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    VAR(uint32, AUTOMATIC) stack_pointer = tpl_stat_proc_table[proc_id]->context.ic->gpr[1];
    VAR(tpl_bool, AUTOMATIC) ret;


/* MISRA RULE 1,45 VIOLATION: cast between pointer and integer is
   implementation specific, but Os is implementation specific and
   this cast is absolutely needed */

    if( (stack_pointer < (uint32)tpl_stat_proc_table[proc_id]->stack.stack_zone)
      ||(stack_pointer > ((uint32)tpl_stat_proc_table[proc_id]->stack.stack_zone
                        + tpl_stat_proc_table[proc_id]->stack.stack_size)) )
    {
        ret = 0;
    }
    else
    {
        ret = 1;
    }

    return ret;
}


/**
 * tpl_check_stack_footprint checks the footprint at the bottom of
 * the stack has not been erased, meaning there was a stack overflow
 *
 * @param stack   pointer to the stack to check
 *
 * @return  1 if stack pattern is there
 *          0 if stack pattern has been erased
 *
 */
FUNC(tpl_bool, OS_CODE) tpl_check_stack_footprint(
  P2CONST(tpl_stack, AUTOMATIC,OS_APPL_DATA) stack)
{
    VAR(tpl_bool, AUTOMATIC) ret;


    if( TPL_FULL_STACK_PATTERN == (*(uint32 *)(stack->stack_zone)) )
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }

    return ret;
}
#endif /* WITH_STACK_MONITORING */


#if WITH_ORTI == YES
/**
 * tpl_fill_stack_pattern fills all the stacks with the pattern,
 * so stack usage can be mesured by ORTI debugger
 *
 */
FUNC(void, OS_CODE) tpl_fill_stack_pattern(void)
{
  P2VAR(uint32, AUTOMATIC, OS_VAR) addr;
  P2VAR(uint8, AUTOMATIC, OS_VAR) stack_top;
  P2VAR(uint8, AUTOMATIC, OS_VAR) stack_bottom;
  VAR(uint8, AUTOMATIC) i;


#if TASK_COUNT > 0

  /*  Look for autostart tasks    */
  for (i = 0; i < TASK_COUNT; i++)
  {
    /*
     * MISRA RULE 11.4 VIOLATION: casting from uint32* to uint8*,
     * but that is the expected behavior, we want to access per byte the stack
     * MISRA RULE 17.4 VIOLATION: performing pointer arithmetic needed to compute stack address
     */
    stack_top = (uint8*)((tpl_stat_proc_table[i]->stack.stack_zone));
    stack_bottom = stack_top + (tpl_stat_proc_table[i]->stack.stack_size);

    for(addr=(uint32*)stack_top; addr < (uint32*)stack_bottom; addr++)
    {
      *addr = TPL_FULL_STACK_PATTERN;
    }

  }
#endif

#if ISR_COUNT > 0
  /*  Look for autostart tasks    */
  for (i = TASK_COUNT; i < TASK_COUNT + ISR_COUNT; i++)
  {
    /*
     * MISRA RULE 11.4 VIOLATION: casting from uint32* to uint8*,
     * but that is the expected behavior, we want to access per byte the stack
     */
    stack_top = (uint8*)((tpl_stat_proc_table[i]->stack.stack_zone));
    stack_bottom = stack_top + tpl_stat_proc_table[i]->stack.stack_size;

    for(addr=(uint32*)stack_top; addr < (uint32*)stack_bottom; addr++)
    {
      *addr = TPL_FULL_STACK_PATTERN;
    }

  }
#endif

}
#endif



#if WITH_AUTOSAR_TIMING_PROTECTION == YES
/**
 * tpl_set_watchdog sets a watchdog for timing protection with a given timeout
 *
 * @param delay   delay before the watchdog expires
 *
 *
 */
FUNC(void, OS_CODE) tpl_set_watchdog(
  VAR(tpl_time, AUTOMATIC) delay)
{
  tpl_load_pit(TPL_WDG_TIMER, TPL_PIT_VALUE(delay));
}


/**
 * tpl_cancel_watchdog stops a watchdog previously started
 *
 *
 */
FUNC(void, OS_CODE) tpl_cancel_watchdog(void)
{
  tpl_stop_pit(TPL_WDG_TIMER);
}


/**
 * tpl_get_local_current_date returns the current date in number of ticks
 *
 * @return the current date
 *
 *
 */
FUNC(tpl_time, OS_CODE) tpl_get_local_current_date(void)
{
  return tpl_current_date;
}

#endif


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
