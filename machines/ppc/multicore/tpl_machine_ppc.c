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
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
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
#if WITH_MULTICORE == YES
# include "tpl_os_multicore_macros.h"
#endif
#include "tpl_app_custom_types.h"
#include "tpl_registers.h"

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"

VAR(uint32, OS_VAR)   tpl_current_date[NUMBER_OF_CORES];

#if WITH_MULTICORE == YES
extern FUNC(void, OS_CODE) tpl_slave_core_startup();
#endif

#if WITH_MULTICORE == YES
extern volatile VAR(uint32, OS_VAR) tpl_locking_depth[NUMBER_OF_CORES];
extern VAR(uint32, OS_VAR) tpl_cpt_os_task_lock[NUMBER_OF_CORES];
#else
extern volatile VAR(uint32, OS_VAR) tpl_locking_depth;
extern VAR(uint32, OS_VAR) tpl_cpt_os_task_lock;
#endif

#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#if WITH_MULTICORE == YES
STATIC FUNC(void, OS_CODE) tpl_get_spin_lock(
  VAR(uint32, AUTOMATIC) lock);

STATIC FUNC(void, OS_CODE) tpl_release_spin_lock(
  VAR(uint32, AUTOMATIC) lock);
#endif


FUNC(void, OS_CODE) tpl_get_task_lock(void)
{
  GET_CURRENT_CORE_ID(core_id)

  if (0 == GET_LOCK_CNT_FOR_CORE(tpl_locking_depth,core_id) )
  {
    tpl_disable_interrupts();
  }

  GET_LOCK_CNT_FOR_CORE(tpl_locking_depth,core_id)++;

  GET_LOCK_CNT_FOR_CORE(tpl_cpt_os_task_lock,core_id)++;

}


FUNC(void, OS_CODE) tpl_release_task_lock(void)
{
  GET_CURRENT_CORE_ID(core_id)

  if( GET_LOCK_CNT_FOR_CORE(tpl_cpt_os_task_lock,core_id) != 0 )
  {
    GET_LOCK_CNT_FOR_CORE(tpl_locking_depth,core_id)--;

    GET_LOCK_CNT_FOR_CORE(tpl_cpt_os_task_lock,core_id)--;

    if( GET_LOCK_CNT_FOR_CORE(tpl_locking_depth,core_id) == 0)
    {
      tpl_enable_interrupts();
    }
  }
}

FUNC(void, OS_CODE) tpl_get_task_lock_with_sc(void)
{
  GET_CURRENT_CORE_ID(core_id)

  GET_LOCK_CNT_FOR_CORE(tpl_locking_depth,core_id)++;
  GET_LOCK_CNT_FOR_CORE(tpl_cpt_os_task_lock,core_id)++;
}


FUNC(void, OS_CODE) tpl_release_task_lock_with_sc(void)
{
  GET_CURRENT_CORE_ID(core_id)

  if( GET_LOCK_CNT_FOR_CORE(tpl_cpt_os_task_lock,core_id) != 0 )
  {
    GET_LOCK_CNT_FOR_CORE(tpl_locking_depth,core_id)--;
    GET_LOCK_CNT_FOR_CORE(tpl_cpt_os_task_lock,core_id)--;
  }
}


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

/* FIXME : The file os/tpl_machine_interface.h must be updated with
 *         using stack as an argument instead of proc_id, as it is
 *         written in autosar/tpl_as_stack_monitor.c
 */
#if 0
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
#else
FUNC(uint8, OS_CODE) tpl_check_stack_footprint(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
    CONSTP2CONST(tpl_stack, AUTOMATIC, OS_APPL_DATA) stack =
         &(tpl_stat_proc_table[proc_id]->stack);

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
#endif
#endif /* WITH_STACK_MONITORING */

#if WITH_ORTI == YES
/**
 * tpl_fill_stack_pattern fills all the stacks with the pattern,
 * so stack usage can be mesured by ORTI debugger
 *
 */
FUNC(void, OS_CODE) tpl_fill_stack_pattern(void)
{
  GET_CURRENT_CORE_ID(core_id)
  P2VAR(uint32, AUTOMATIC, OS_VAR) addr;
  P2VAR(uint8, AUTOMATIC, OS_VAR) stack_top;
  P2VAR(uint8, AUTOMATIC, OS_VAR) stack_bottom;
  VAR(uint8, AUTOMATIC) i;


#if TASK_COUNT > 0
for (i = 0; i < TASK_COUNT; i++) {
# if NUMBER_OF_CORES > 1
    /* In multicore, we must check if the task belongs to the core */
    if (tpl_stat_proc_table[i]->core_id == core_id)
# endif
    {
      /*
       * MISRA RULE 11.4 VIOLATION: casting from uint32* to uint8*, but that is
       * the expected behavior, we want to access per byte the stack
       * MISRA RULE 17.4 VIOLATION: performing pointer arithmetic needed to
       * compute stack address
       */
      stack_top = (uint8*)((tpl_stat_proc_table[i]->stack.stack_zone));
      stack_bottom = stack_top + (tpl_stat_proc_table[i]->stack.stack_size);

      for(addr=(uint32*)stack_top; addr < (uint32*)stack_bottom; addr++)
      {
        *addr = TPL_FULL_STACK_PATTERN;
      }
    }
  }
#endif

#if ISR_COUNT > 0
  for (i = TASK_COUNT; i < TASK_COUNT + ISR_COUNT; i++)
  {
# if NUMBER_OF_CORES > 1
    /* In multicore, we must check if the task belongs to the core */
    if (tpl_stat_proc_table[i]->core_id == core_id)
# endif
    {
      /*
       * MISRA RULE 11.4 VIOLATION: casting from uint32* to uint8*, but that is
       * the expected behavior, we want to access per byte the stack
       */
      stack_top = (uint8*)((tpl_stat_proc_table[i]->stack.stack_zone));
      stack_bottom = stack_top + tpl_stat_proc_table[i]->stack.stack_size;

      for(addr=(uint32*)stack_top; addr < (uint32*)stack_bottom; addr++)
      {
        *addr = TPL_FULL_STACK_PATTERN;
      }
    }
  }
#endif

  /* fill system stack */
  /*
   * MISRA RULE 11.4 VIOLATION: casting from uint32* to uint8*, but that is the
   * expected behavior, we want to access per byte the stack
   * MISRA RULE 17.4 VIOLATION: performing pointer arithmetic needed to compute
   * stack address
   */
  stack_top = (uint8*)(GET_KERNEL_STACK(core_id));
  stack_bottom = (uint8*)(GET_KERNEL_STACK_BOTTOM(core_id));

  for(addr=(uint32*)stack_top; addr < (uint32*)stack_bottom; addr++)
  {
    *addr = TPL_FULL_STACK_PATTERN;
  }

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
FUNC(void, OS_CODE) tpl_set_tpwatchdog(
  VAR(tpl_time, AUTOMATIC) delay)
{
  GET_CURRENT_CORE_ID(core_id)
  TPL_SET_TPWATCHDOG(core_id, delay);
}


/**
 * tpl_cancel_watchdog stops a watchdog previously started
 *
 *
 */
FUNC(void, OS_CODE) tpl_cancel_tpwatchdog(void)
{
  GET_CURRENT_CORE_ID(core_id)
  TPL_CANCEL_TPWATCHDOG(core_id);
}

/**
 * tpl_get_tptimer
 *
 * @return the current date
 *
 * FIXME : Should take core_id as a parameter
 */
FUNC(tpl_time, OS_CODE) tpl_get_tptimer(void)
{
  GET_CURRENT_CORE_ID(core_id)
  return GET_CURRENT_DATE(core_id);
}

/**
 * tpl_get_local_current_date returns the current date in number of ticks
 *
 * @return the current date
 *
 * FIXME : Only works when using one timer per core
 *
 */
FUNC(tpl_time, OS_CODE) tpl_get_local_current_date(void)
{
  GET_CURRENT_CORE_ID(core_id)
  return GET_CURRENT_DATE(core_id);
}

#endif

#if WITH_MULTICORE == YES

/**
 * @internal
 *
 * This function starts the processing core given in the argument
 */
FUNC(void, OS_CODE) tpl_start_core(
  CONST(CoreIdType, AUTOMATIC) core_id)
{

  if(core_id!=0)
  {
    /* write slave core start adresse */
#if WITH_VLE == YES
    TPL_SSCM.DPMBOOT = (uint32)tpl_slave_core_startup | SSCM_DPMBOOT_VLE;
#else
    TPL_SSCM.DPMBOOT = (uint32)tpl_slave_core_startup;
#endif

    /* write key and inverted key to start the core */
    TPL_SSCM.DPMKEY = SSCM_DPMKEY_KEY1;
    TPL_SSCM.DPMKEY = SSCM_DPMKEY_KEY2;
  }
}

/**
 * @internal
 *
 * This function sends an interrupt to the other core to force a context switch
 */
FUNC(void, OS_CODE) tpl_send_intercore_it(
  CONST(CoreIdType, AUTOMATIC) to_core_id)
{
  /* set software interrupt flag on the given core */
  if(to_core_id == 0)
  {
    TPL_INTC(0).SSCIR[INTC_SSCIR_CORE0_SW_ISR] = INTC_SSCIR_SET;
  }
  else
  {
    TPL_INTC(1).SSCIR[INTC_SSCIR_CORE1_SW_ISR] = INTC_SSCIR_SET;
  }
}

/**
 * @internal
 *
 *
 */
FUNC(void, OS_CODE) tpl_get_lock(
  CONSTP2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock)
{
  volatile VAR(tpl_lock, AUTOMATIC) tmp_lock;

  do
  {
    tpl_get_spin_lock(TPL_GATE_LOCK);
    tmp_lock=*lock;
    if(*lock==UNLOCKED_LOCK)
    {
      *lock = LOCKED_LOCK;
    }
    tpl_release_spin_lock(TPL_GATE_LOCK);
  } while(tmp_lock!=UNLOCKED_LOCK);

}


/**
 * @internal
 *
 *
 */
FUNC(void, OS_CODE) tpl_release_lock(
  CONSTP2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock)
{

  tpl_get_spin_lock(TPL_GATE_LOCK);
  *lock = UNLOCKED_LOCK;
  tpl_release_spin_lock(TPL_GATE_LOCK);

}


/**
 * @internal
 *
 *
 */
FUNC(void, OS_CODE) tpl_try_to_get_lock(
  CONSTP2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock,
  P2VAR(tpl_try_to_get_spinlock_type, AUTOMATIC, OS_VAR) success)
{
  volatile VAR(tpl_lock, AUTOMATIC) tmp_lock;


    tpl_get_spin_lock(TPL_GATE_LOCK);
    if(*lock==UNLOCKED_LOCK)
    {
      *lock = LOCKED_LOCK;
      *success = TRYTOGETSPINLOCK_SUCCESS;
    }
    else
    {
      *success = TRYTOGETSPINLOCK_NOSUCCESS;
    }
    tpl_release_spin_lock(TPL_GATE_LOCK);



}


/**
 * @internal
 *
 *
 */
STATIC FUNC(void, OS_CODE) tpl_get_spin_lock(
  VAR(uint32, AUTOMATIC) lock)
{
  VAR(uint16, AUTOMATIC) core_id = tpl_get_core_id();
  VAR(uint8, AUTOMATIC) core_lock;
  volatile VAR(uint8, AUTOMATIC) current_value;
  /*
   * retrieve the key to lock the core */
  if(core_id==OS_CORE_ID_0)
  {
    core_lock=TPL_GATE_CPU0_LOCK;
  }
  else
  {
    core_lock=TPL_GATE_CPU1_LOCK;
  }

  /* wait until the lock is free */
  do
  {
    current_value = TPL_SEMA4(0).GATE[lock];
  } while(TPL_GATE_UNLOCK != current_value);

  /* try to get the lock, until we have it */
  do
  {
    TPL_SEMA4(0).GATE[lock] = core_lock;
    current_value = TPL_SEMA4(0).GATE[lock];
  } while(current_value != core_lock);
}


/**
 * @internal
 *
 *
 */
STATIC FUNC(void, OS_CODE) tpl_release_spin_lock(
  VAR(uint32, AUTOMATIC) lock)
{
  VAR(uint16, AUTOMATIC) core_id = tpl_get_core_id();
  VAR(uint8, AUTOMATIC) core_lock;
  volatile VAR(uint8, AUTOMATIC) current_value;
  /*
   * retrieve the key to lock the core */
  if(core_id==OS_CORE_ID_0)
  {
    core_lock=TPL_GATE_CPU0_LOCK;
  }
  else
  {
    core_lock=TPL_GATE_CPU1_LOCK;
  }

  /* check we actually have the lock */
  current_value = TPL_SEMA4(0).GATE[lock];
  if(current_value==core_lock)
  {
    /* release the lock */
    TPL_SEMA4(0).GATE[lock] = TPL_GATE_UNLOCK;
  }

}
#endif


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
