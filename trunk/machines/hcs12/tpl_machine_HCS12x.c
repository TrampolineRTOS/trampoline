/**
 * @file tpl_machine_HCS12x.c
 *
 * @section desc File description
 *
 * functions of the OS specifics for the MCU S12X. Some of them need to be implemented in assembly.
 * Works only in near context because parameters are not passed in the same way in far context
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
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
/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_it.h"
#include "tpl_os_it_kernel.h"
#include "tpl_os_generated_configuration.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_error.h"
#include "tpl_os_std_types.h"
#ifdef WITH_AUTOSAR
#include "tpl_as_protec_hook.h"
#include "tpl_as_timing_protec.h"
#include "tpl_as_isr.h"
#endif

#include "Gpt.h"


/******************************************************************************/
/* DECLARATION OF CONSTANTS                                                   */
/******************************************************************************/

#define TIMER_GLOBALTIME_PERIOD 1  /* timeout period in ms, can be changed */
#define TIMER_GLOBALTIME_LOADVALUE ( ((TIMER_GLOBALTIME_PERIOD*BUS_CLK)/2)-1 )

#define OS_STACK_PATTERN 0xAA

/* maximum value corresponding to Gpt_ValueType (0xFFFF for a uint16) */
/* MISRA RULE 90 VIOLATION: this macro indirectly contains '{''}' by the
   sizeof() macro, but this macro is needed because the size of Gpt_ValueType
   is dependent on the MCAL, and connot be known before compilation */
#define MAX_TIMER_VALUE (((u32)(1)<<(u32)(sizeof(Gpt_ValueType)*8))-1)
/* maximum value in ms that can be loaded in Gpt_StartTimer, before conversion into number of ticks */
#define MAX_TIMER_LOAD_VALUE ((((u32)MAX_TIMER_VALUE+1)*2)/(u32)BUS_CLK)

/******************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                            */
/******************************************************************************/
#define   OS_START_SEC_VAR_UNSPECIFIED
#include  "MemMap.h"

VAR(tpl_stack_word, OS_VAR) stack_zone_of_IdleTask[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];
VAR(hcs12_context, OS_VAR) idle_task_context;
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
STATIC VAR(tpl_time, OS_VAR) tpl_global_time;
#endif

STATIC VAR(tpl_time, AUTOMATIC) tpl_remaining_watchdog_time;
#define   OS_STOP_SEC_VAR_UNSPECIFIED
#include  "MemMap.h"


#define OS_START_SEC_VAR_16BITS
#include  "MemMap.h"

STATIC VAR(uint16, OS_VAR) tpl_cpt_task_lock;
STATIC VAR(uint16, OS_VAR) tpl_cpt_user_task_lock;
STATIC VAR(uint16, OS_VAR) tpl_cpt_os_task_lock;
STATIC VAR(uint16, OS_VAR) tpl_user_task_lock;

#define   OS_STOP_SEC_VAR_16BITS
#include  "MemMap.h"


/******************************************************************************/
/* DECLARATION OF LOCAL FUNCTIONS                                             */
/******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
STATIC FUNC(void, OS_CODE) tpl_call_missing_end(void);
STATIC FUNC(void, OS_CODE)  tpl_start_base_timer(void);
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* DEFINITION OF GLOBAL FUNCTIONS                                            */
/******************************************************************************/

/******************************************************************************
** Function name: tpl_init_context(tpl_exec_common *exec_obj)
** Description: initialize a context to prepare a task to run.
** Parameter exec_obj : object to be initialized
** Return value: None
** Remarks: None
******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_init_context(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) exec_obj)
{
  P2VAR(hcs12_context, AUTOMATIC, OS_APPL_DATA) ic = exec_obj->static_desc->context.ic;

  /* initialises the registers to 0 */
  ic->d = 0;
  ic->x = 0;
  ic->y = 0;

  #ifdef WITH_AUTOSAR_STACK_MONITORING
  /* MISRA RULE 1 VIOLATION: cast from integer to pointer type is
    implemenation defined, but this part of OS is implementation specific,
    and the pointer size is controlled */
  ic->sp = (uint16)(exec_obj->static_desc->stack.stack_zone);
  ic->sp = (ic->sp) + (exec_obj->static_desc->stack.stack_size);
  ic->sp = (ic->sp) - 4;
  /* MISRA RULE 45 VIOLATION: a uint8 pattern is written in a uint32 pointer.
     We only need to write one byte */
  *(P2VAR(uint8, AUTOMATIC, OS_APPL_DATA))exec_obj->static_desc->stack.stack_zone = OS_STACK_PATTERN;
  #else
  /* initialises the stack pointer of the task to
    start address + stack size = end of stack zone */
  /* MISRA RULE 1 VIOLATION: cast from integer to pointer type is
    implemenation defined, but this part of OS is implementation specific,
    and the pointer size is controlled */
  ic->sp = (uint16)(exec_obj->static_desc->stack.stack_zone);
  ic->sp = (ic->sp) + (exec_obj->static_desc->stack.stack_size);
  ic->sp = (ic->sp) - 4;
  #endif
  /* initialises the CCR with 0: all flags reset */
  ic->ccr = 0;

  /* initialises the programm counter to the
    task function base address */
  ic->pc = exec_obj->static_desc->entry;
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/******************************************************************************
** Function name: tpl_init_machine(void)
** Description: called when the OS is started, used to do
**              initialisations specifics of the MCU
**              initialised the idle task, because its not done in tpl_init_context
** Parameter : None
** Return value: None
** Remarks: None
******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_init_machine(void)
{
  /* initializes the TaskLock counter */
  tpl_cpt_task_lock = 0;
  tpl_user_task_lock = FALSE;
  tpl_cpt_user_task_lock = 0;
  tpl_cpt_os_task_lock = 0;

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_global_time = 0;
#endif

  /* initialises the CCR with 0: all flags reset */
  idle_task_context.ccr = 0;

  /* initialises the registers to 0 */
  idle_task_context.d = 0;
  idle_task_context.x = 0;
  idle_task_context.y = 0;

  /* initialises the stack pointer of the idle task to
    start address + stack size = end of stack zone */
  /* if Stack Monitoring is enabled, fill the stack with a pattern in
    order to check later if the pattern was erased */
#ifdef WITH_AUTOSAR_STACK_MONITORING
  /* MISRA RULE 1 VIOLATION: cast from integer to pointer type is
    implemenation defined, but this part of OS is implementation specific,
    and the pointer size is controlled */
  idle_task_context.sp = (uint16)(&stack_zone_of_IdleTask);
  idle_task_context.sp = idle_task_context.sp + SIZE_OF_IDLE_STACK;
  idle_task_context.sp = idle_task_context.sp - 4;
  *(P2VAR(uint8, AUTOMATIC, OS_APPL_DATA))(idle_task_context.sp) = OS_STACK_PATTERN;
  #else
  /* initialises the stack pointer of the task to
    start address + stack size = end of stack zone */
  /* MISRA RULE 1 VIOLATION: cast from integer to pointer type is
    implemenation defined, but this part of OS is implementation specific,
    and the pointer size is controlled */
  idle_task_context.sp = (uint16)(&stack_zone_of_IdleTask);
  idle_task_context.sp = idle_task_context.sp + SIZE_OF_IDLE_STACK;
  idle_task_context.sp = idle_task_context.sp - 4;
#endif

  /* initialises the programm counter to the
    sleep function base address */
  idle_task_context.pc = tpl_sleep;

  tpl_start_base_timer();

}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
** Description: function to switch context
** Parameter old_context: context to be saved / stored in the stack
** Parameter new_context: context to be loaded / stored in D register
** Return value: None
** Remarks: assembly function
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific and controlled.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_switch_context(
  P2VAR(tpl_context, AUTOMATIC, OS_APPL_DATA) old_context,
  P2VAR(tpl_context, AUTOMATIC, OS_APPL_DATA) new_context)
{
    __asm PSHY                      ;/* save the current registers on stack */
    __asm PSHX                      ;
    __asm PSHD                      ;
    __asm PSHCW                     ;/* different from s12, CCR is 2 bytes */
    __asm LEAS  10,SP               ;/*replace SP   */
    __asm PULX                      ;
    __asm LEAS  -12,SP              ;
    __asm CPX   #0                  ;/* if(old_context*  == NULL) */
    __asm BEQ   nosave              ;/* do not save the old_context */
    __asm LDX   0,X                 ;/* charge X avec l'adresse pointé par X+0, soit charge x avec old_context->ic */
    __asm CPX   #idle_task_context  ; /* check if old_context is not the idle_task context */
    __asm BEQ   nosave              ;/* if it is the idle_task context, do not save the context */
    __asm PULY                      ;/* pull the CCR in Y */
    __asm STY   2,X+                ;/* copy the CCR in old_context */
    __asm PULY                      ;/* pull D in Y */
    __asm STY   2,X+                ;/* copy D in old_context */
    __asm PULY                      ;/* pull X in Y */
    __asm STY   2,X+                ;/* copy X in old_context */
    __asm PULY                      ;/* pull Y in Y */
    __asm STY   2,X+                ;/* copy Y in old_context */
    __asm TFR   Y,D                 ;/* copy Y in D (save new_context*) */
    __asm PULY                      ;/* pull the return PC */
    __asm STY   2,X+                ;/* save the return PC in old_context */
    __asm LEAS  2,SP                ;
    __asm TFR   SP,Y                ;
    __asm STY   2,X+                ;/* save the SP in old_context */
    __asm nosave:                   ;/* here we go, the old context is saved */
    __asm TFR   D,X                 ;/* copy D in X (new_context*) */
    __asm LDX   0,X                 ;
    __asm LEAX  10,X                ;/* point to the SP field in new_context struct */
    __asm LDY   2,X-                ;/* copy the SP in the old_context */
    __asm TYS                       ;/* adjust the SP from the new_context */
    __asm LDY   2,X-                ;/* copy PC in Y */
    __asm PSHY                      ;/* push pC */
    __asm LDY   2,X-                ;/* copy Y register in Y */
    __asm PSHY                      ;/* push Y */
    __asm LDY   2,X-                ;/* copy X register in Y */
    __asm PSHY                      ;/* push X */
    __asm LDY   2,X-                ;/* copy D register in Y */
    __asm TFR   Y,D                 ;/* Transfert in D */
    __asm LDY   0,X                 ;/* copy CCR in Y */
    __asm TFR   Y,CCR               ;/* Transfert in CCR */
    __asm PULX                      ;/* pull X */
    __asm PULY                      ;/* pull Y */
    tpl_release_task_lock();
    __asm LEAS  2,SP                ;
    __asm CLI                       ;
    __asm JSR   [-2,SP]             ;/* call the entry point of the task */
    __asm JSR   tpl_call_missing_end;
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function name: tpl_switch_context_from_it(tpl_context *old_context, tpl_context *new_context)
** Description: function to switch context from interrupt
** Parameter old_context: context to be saved / stored in the stack
** Parameter new_context: context to be loaded / stored in D register
** Return value: None
** Remarks: assembly function
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific and controlled.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_switch_context_from_it(
  P2VAR(tpl_context, AUTOMATIC, OS_APPL_DATA) old_context,
  P2VAR(tpl_context, AUTOMATIC, OS_APPL_DATA) new_context)
{
    __asm PSHY                      ;/* save the current registers on stack */
    __asm PSHX                      ;
    __asm PSHD                      ;
    __asm PSHCW                     ;/* different from s12, CCR is 2 bytes */
    __asm LEAS  10,SP               ;/*replace SP   */
    __asm PULX                      ;
    __asm LEAS  -12,SP              ;
    __asm CPX   #0                  ;/* if(old_context*  == NULL) */
    __asm BEQ   nosave              ;/* do not save the old_context */
    __asm LDX   0,X                 ;/* charge X avec l'adresse pointé par X+0, soit charge x avec old_context->ic */
    __asm PULY                      ;/* pull the CCR in Y */
    __asm ANDY  #$00FF               ;/* reset the current interrupt priority level to 0 */
    __asm STY   2,X+                ;/* copy the CCR in old_context */
    __asm PULY                      ;/* pull D in Y */
    __asm STY   2,X+                ;/* copy D in old_context */
    __asm PULY                      ;/* pull X in Y */
    __asm STY   2,X+                ;/* copy X in old_context */
    __asm PULY                      ;/* pull Y in Y */
    __asm STY   2,X+                ;/* copy Y in old_context */
    __asm TFR   Y,D                 ;/* copy Y in D (save new_context*) */
    __asm PULY                      ;/* pull the return PC */
    __asm STY   2,X+                ;/* save the return PC in old_context */
    __asm LEAS  2,SP                ;
    __asm TFR   SP,Y                ;
    __asm STY   2,X+                ;/* save the SP in old_context */
    __asm nosave:                   ;/* here we go, the old context is saved */
    __asm TFR   D,X                 ;/* copy D in X (new_context*) */
    __asm LDX   0,X                 ;/* load new_context->context */
    __asm LEAX  10,X                ;/* point to the SP field in new_context struct */
    __asm LDY   2,X-                ;/* copy the SP in the old_context */
    __asm TYS                       ;/* adjust the SP from the new_context */
    __asm LDY   2,X-                ;/* copy PC in Y */
    __asm PSHY                      ;/* push pC */
    __asm LDY   2,X-                ;/* copy Y register in Y */
    __asm PSHY                      ;/* push Y */
    __asm LDY   2,X-                ;/* copy X register in Y */
    __asm PSHY                      ;/* push X */
    __asm LDY   2,X-                ;/* copy D register in Y */
    __asm TFR   Y,D                 ;/* Transfert in D */
    __asm LDY   0,X                 ;/* copy CCR in Y */
    __asm ANDY  #$00FF              ;/* reset the current interrupt priority level to 0 */
    __asm TFR   Y,CCRW              ;/* Transfert in CCR */
    __asm PULX                      ;/* pull X */
    __asm PULY                      ;/* pull Y */
    __asm LEAS  2,SP                ;
    __asm CLI                       ;
    __asm JSR   [-2,SP]             ;/* call the entry point of the task */
    __asm JSR   tpl_call_missing_end;
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: tpl_sleep(void)
** Description: wait when there is no task to be executed
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific and controlled.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_sleep(void)
{
  while(1)
  {
    __asm CLI ;
  }
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: tpl_shutdown(void)
** Description: last function executed when leaving OS, disable interrupts and wait
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific and controlled.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_shutdown(void)
{
  __asm SEI                   ;/* set the I bit of CCR, inhibits interrupts */
  __asm shutdown_loop:        ;/* go in an infinit loop */
  __asm BRA shutdown_loop
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: tpl_get_task_lock(void)
** Description: inhibits interrupts
** Parameter : None
** Return value: None
** Remarks: assembly function
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific and controlled.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_get_task_lock(void)
{
  __asm SEI     ;/* set the I bit of CCR, inhibits interrupts */
  tpl_cpt_task_lock++;

#ifdef WITH_AUTOSAR
    tpl_cpt_os_task_lock++;
#endif
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: tpl_release_task_lock(void)
** Description: re-allows interrupts
** Parameter : None
** Return value: None
** Remarks: assembly function
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_release_task_lock(void)
{
  if( tpl_cpt_task_lock > 0)
  {
    tpl_cpt_task_lock--;

#ifdef WITH_AUTOSAR
    tpl_cpt_os_task_lock--;
#endif
  }
  if( tpl_cpt_task_lock == 0)
  {
    __asm CLI     ;/* clear the I bit of CCR, re-allows interrupts */
  }
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: EnableAllInterrupts(void)
** Description: enable interrupts
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) EnableAllInterrupts(void)
{
  __asm CLI     ;/* clear the I bit of CCR, re-allows interrupts */

#ifdef WITH_AUTOSAR
  tpl_user_task_lock = FALSE;
#endif

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_stop_all_isr_lock_monitor(tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: DisableAllInterrupts(void)
** Description: disable interrupts
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) DisableAllInterrupts(void)
{
  __asm SEI     ;/* set the I bit of CCR, inhibits interrupts */

#ifdef WITH_AUTOSAR
  tpl_user_task_lock = TRUE;
#endif

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_start_all_isr_lock_monitor(tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: ResumeAllInterrupts(void)
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) ResumeAllInterrupts(void)
{
  if( tpl_cpt_task_lock > 0)
  {
    tpl_cpt_task_lock--;

#ifdef WITH_AUTOSAR
    tpl_cpt_user_task_lock--;
#endif
  }
  if( tpl_cpt_task_lock == 0)
  {
    __asm("CLI");/* re-allows interrupts */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_stop_all_isr_lock_monitor(tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
  }
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: SuspendAllInterrupts(void)
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) SuspendAllInterrupts(void)
{
  __asm("SEI");  /* inhibits interrupts */
  tpl_cpt_task_lock++;

#ifdef WITH_AUTOSAR
  tpl_cpt_user_task_lock++;
#endif
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  if( tpl_cpt_task_lock == 1)
  {
    tpl_start_all_isr_lock_monitor(tpl_running_obj);
  }
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: ResumeOSInterrupts(void)
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) ResumeOSInterrupts(void)
{
  if( tpl_cpt_task_lock > 0)
  {
    tpl_cpt_task_lock--;

#ifdef WITH_AUTOSAR
    tpl_cpt_user_task_lock--;
#endif
  }
  if( tpl_cpt_task_lock == 0)
  {
    __asm("CLI");/* re-allows interrupts */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_stop_os_isr_lock_monitor(tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
  }
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: SuspendOSInterrupts(void)
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
/* MISRA RULE 1 VIOLATION: assembly instruction is implementation specific,
  but this part of OS is implementation specific.
  There is no other way than assembly to access core registers */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) SuspendOSInterrupts(void)
{
  __asm("SEI");  /* inhibits interrupts */
  tpl_cpt_task_lock++;

#ifdef WITH_AUTOSAR
    tpl_cpt_user_task_lock--;
#endif

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_start_os_isr_lock_monitor(tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


#ifdef WITH_AUTOSAR_TIMING_PROTECTION
/*******************************************************************************
** Function name: tpl_set_watchdog
** Description:
** Parameter :  delay: delay in ns before the callback shall be called
**              function: callbakc that shall be called when the delay expires
** Return value: None
** Remarks:
*******************************************************************************/
/* MISRA RULE 104 VIOLATION: using non-const pointer to function:
  to be justified in timing protection implementation */
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_set_watchdog(
  VAR(tpl_time, AUTOMATIC) delay)
{
  VAR(tpl_time, AUTOMATIC) NbTicks;

  tpl_remaining_watchdog_time = delay;

  /* as the given time is a uint32 and the Gpt_ValueType can be lower,
     we have to programm sub counters */
  if( tpl_remaining_watchdog_time > (tpl_time)(MAX_TIMER_LOAD_VALUE) )
  {
    /* if the remaining time is greater than the maximum loadable value,
       we load the max value and decrement the remaining time */
    tpl_remaining_watchdog_time = tpl_remaining_watchdog_time - (tpl_time)(MAX_TIMER_LOAD_VALUE);
    /* MISRA RULE 48 VIOLATION: the result of the mutlication operation could
       be wider than the original type, but this is controlled because the result
       of this operation is known to be under the max value of the type */
    NbTicks = (Gpt_ValueType)(((MAX_TIMER_LOAD_VALUE*BUS_CLK)>>1)-1);
  }
  else
  {
    /* if the remaining time is lower than the maximum loadable value,
       we can load the remaining time, next callback call
       will correspond to the watchdog expiration */
    tpl_remaining_watchdog_time = 0;
    NbTicks = (Gpt_ValueType)((tpl_remaining_watchdog_time*BUS_CLK)>>1)-1;
  }

  /* start the timer with the calculated value */
  Gpt_StartTimer(OS_GPTCHANNEL_WATCHDOG, (Gpt_ValueType)NbTicks);
  Gpt_EnableNotification(OS_GPTCHANNEL_WATCHDOG);
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: tpl_cancel_watchdog
** Description: Cancel the current running timer for the watchdog
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_cancel_watchdog(void)
{
  /* stop the timer */
  Gpt_DisableNotification(OS_GPTCHANNEL_WATCHDOG);
  Gpt_StopTimer(OS_GPTCHANNEL_WATCHDOG);
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: tpl_watchdog_callback
** Description: This function is called by the Gpt when the timer of the
**              watchdog expires. if there is some time remaining for
                this watchdog, the timer is restarted, until the remaining time
                is null, then the watchdog expiration callback is called
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#define GPT_START_SEC_CODE
#include "MemMap.h"
FUNC(void, GPT_CODE) tpl_watchdog_callback(void)
{
  VAR(Gpt_ValueType, AUTOMATIC) NbTicks;

  /* stop the timer */
  Gpt_DisableNotification(OS_GPTCHANNEL_WATCHDOG);
  Gpt_StopTimer(OS_GPTCHANNEL_WATCHDOG);

  if( tpl_remaining_watchdog_time > 0 )
  {
      if( tpl_remaining_watchdog_time > MAX_TIMER_LOAD_VALUE )
      {
          /* if the remaining time is greater than the maximum loadable value,
             we load the max value and decrement the remaining time */
          tpl_remaining_watchdog_time = tpl_remaining_watchdog_time - MAX_TIMER_LOAD_VALUE;
          NbTicks = (Gpt_ValueType)((MAX_TIMER_LOAD_VALUE*BUS_CLK)>>1)-1;
      }
      else
      {
          /* if the remaining time is lower than the maximum loadable value,
             we can load the remaining time, next callback call
             will correspond to the watchdog expiration */
          NbTicks = (Gpt_ValueType)((tpl_remaining_watchdog_time*BUS_CLK)>>1)-1;
          tpl_remaining_watchdog_time = 0;
      }

      /* restart the timer with the calculated value */
      Gpt_StartTimer(OS_GPTCHANNEL_WATCHDOG, NbTicks);
      Gpt_EnableNotification(OS_GPTCHANNEL_WATCHDOG);
  }
  else
  {
      tpl_watchdog_expiration();
  }
}
#define GPT_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function name: tpl_get_local_current_date
** Description: return the local current date of the ECU
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(tpl_time, OS_CODE) tpl_get_local_current_date(void)
{
  return tpl_global_time;
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* WITH_AUTOSAR_TIMING_PROTECTION */



#ifdef WITH_AUTOSAR_STACK_MONITORING
/*******************************************************************************
** Function name: tpl_check_stack_pointer
** Description: This function tells if the saved stack pointer
**              (into saved context) is located into the stack boundaries or not
** Parameter : None
** Return value:  1 no stack overflow detected
**                0 stack overflow deteted
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(u8, OS_CODE) tpl_check_stack_pointer(
  P2CONST(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) this_exec_obj)
{
  VAR(uint16, AUTOMATIC) StackPointer = this_exec_obj->static_desc->context.ic->sp;

  if( (this_exec_obj->static_desc->context.ic) != (&idle_task_context) )
  {
    /* MISRA RULE 1 VIOLATION: cast from integer to pointer type is
      implemenation defined, but this part of OS is implementation specific,
      and the pointer size is controlled */
    if( (StackPointer < (uint16)this_exec_obj->static_desc->stack.stack_zone)
      ||(StackPointer > ((uint16)this_exec_obj->static_desc->stack.stack_zone
                        + this_exec_obj->static_desc->stack.stack_size)) )
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    return 1; /* if idle task, we do not check the stack pointer */
  }
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: tpl_check_stack_footprint
** Description: This functions checks the stack did not overflowed by
**              looking if the stack tagging has not been completly erased.
** Parameter : None
** Return value:  1 no stack overflow detected
**                0 stack overflow deteted
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(u8, OS_CODE) tpl_check_stack_footprint(
  P2CONST(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) this_exec_obj)
{

  if( (this_exec_obj->static_desc->context.ic) != (&idle_task_context) )
  {
    /* MISRA RULE 45 VIOLATION: a uint8 pattern is read from a uint32 pointer.
       We only need to read one byte */
    if( OS_STACK_PATTERN == (*(uint8 *)(this_exec_obj->static_desc->stack.stack_zone)) )
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 1;
  }
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* WITH_AUTOSAR_STACK_MONITORING */


/*******************************************************************************
** Function name: tpl_start_base_timer
** Description: This function can be called to start thebase timer of the Os
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_start_base_timer(void)
{
  Gpt_StartTimer(OS_GPTCHANNEL_TICK,TIMER_GLOBALTIME_LOADVALUE);
  Gpt_EnableNotification(OS_GPTCHANNEL_TICK);
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"



/*******************************************************************************
** Function name: tpl_inc_time
** Description: This function increments the global time of the Os by the
**              tick value of the Os
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#ifdef WITH_AUTOSAR
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_inc_time(void)
{
  tpl_global_time = (tpl_global_time+(TIMER_GLOBALTIME_PERIOD));
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function name: tpl_get_interrupt_lock_status
** Description: this function checks if the user has released any call to
**              DisableAllInterrupt/SuspendAllInterrupt/SuspendOsInterrupt
** Parameter : None
** Return value:  tpl_bool: status of the interrupt inhibition
** Remarks:
*******************************************************************************/
#ifdef WITH_AUTOSAR
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(tpl_bool, OS_CODE) tpl_get_interrupt_lock_status(void)
{
  VAR(tpl_bool, AUTOMATIC) return_value;

  if( (TRUE==tpl_user_task_lock) || (tpl_cpt_user_task_lock > 0) )
  {
    return_value = TRUE;
  }
  else
  {
    return_value = FALSE;
  }

  return return_value;
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function name: tpl_reset_interrupt_lock_status
** Description: this function reset the status of interrupt lock by user
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#ifdef WITH_AUTOSAR
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_reset_interrupt_lock_status(void)
{
  tpl_user_task_lock = FALSE;

  tpl_cpt_user_task_lock = 0;

  tpl_cpt_task_lock = tpl_cpt_os_task_lock;
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*******************************************************************************
** Function name: tpl_exception_occured
** Description: This function is called when a exception occured in the µP
**              (e.g. a wrong op code)
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#ifdef WITH_AUTOSAR
#define OS_START_SEC_CODE
#include "MemMap.h"
/* MISRA RULE 27 VIOLATION: this function has an external linkage, but does
   not need to be declared as external in a header file because it is only
   called when the interrupt vector is reached */
__interrupt FUNC(void, OS_CODE) tpl_exception_occured(void)
{
  tpl_call_protection_hook(E_OS_PROTECTION_EXCEPTION);
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"
#endif



/******************************************************************************/
/* DEFINITION OF LOCAL FUNCTIONS                                              */
/******************************************************************************/

/*******************************************************************************
** Function name: tpl_call_missing_end(void)
** Description: this function is called by tpl_switch_context when a task
**              returns without call to TerminateTask or an isr without
**              call to TerminateISR
** Parameter context: pointer to the context of the faulty object
** Return value: None
** Remarks:
*******************************************************************************/
/* MISRA RULE 52 VIOLATION: the MISRA rule checker cannot see that this
  function is used because it is called only in assembly parts of code */
STATIC FUNC(void, OS_CODE) tpl_call_missing_end(void)
{
    VAR(StatusType, AUTOMATIC) result = E_OK;

    if( IS_ROUTINE == (tpl_running_obj->static_desc->type) )
    {
        result = TerminateISR();
    }
    else
    {
#if defined(WITH_ERROR_HOOK) && defined(WITH_AUTOSAR)
        tpl_call_error_hook(E_OS_MISSINGEND);
#endif
        result = TerminateTask();
    }
}
