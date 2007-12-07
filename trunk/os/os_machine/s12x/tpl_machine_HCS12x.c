/*=============================================================================
** Trampoline OS
**
** Trampoline is copyright (c) IRCCyN 2005+
** Copyright ESEO for function and data structures documentation
** Trampoline is protected by the French intellectual property law.
**
** This software is distributed under the Lesser GNU Public Licence
**-----------------------------------------------------------------------------
** Supported MCUs      : Freescale MC9S12XEP100
** Supported Compilers : Code Warrior V4.6
**-----------------------------------------------------------------------------
** File name         : tpl_machine_HCS12X.c
**
** Module name       : OS
**
**
** Summary: functions of the OS specifics for the MCU S12X that can only be
**          implemented in assembly
**              .
**             / \     works only in near context
**            / | \    because parameters are not passed in the same way in far context
**           /__o__\
**
**= History ===================================================================
** 00.01  J.Monsimier 04/11/07
**  - creation
** 00.02  J.Monsimier 05/21/07
**  - for Tranmpoline Rev333
**  - modifications for the S12X MCU,
**    the S12X is different from the S12 by the size of the CCR register
** 00.03  J.Monsimier 23/08/07
**  - for Tranmpoline Rev346
**  - modifications for new Trampoline Rev
**    tpl_switch_context_from_it modified: stack pointer is now shifted of 12
**  - modification of TaskLock behavior, addition of a counter
**  - merge of files tpl_machine_HCS12X.c and tpl_machine_HCS12X_asm.c in 1 file
** 01.00  J.Monsimier 08/30/07
**  - from Tranmpoline Rev346
**  - OSEK compliant, tested and released version
** 01.01  J.Monsimier 10/04/07
**  - from Trampoline  Rev 377
**  - Addition of functions needed for Autosar
**  - Improvement of the support of Gpt driver
**  - Improvement of the switch_context functions
** 01.02  J.Monsimier 08/11/07
**  - from Trampoline Rev399
**  - Modifications to be compliant to Autosar implementation rules
** 01.03  J.Monsimier 28/11/07
**  - bug fixed in tpl_release_task_lock().
**    The deshibition of interrutps was not done as soon as CptTaskLock=0,
**    this was avoiding the OS to work with no autostart task configured
=============================================================================*/

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
#include "Std_Types.h"
#include "Gpt.h"


/******************************************************************************/
/* DECLARATION OF CONSTANTS                                                   */
/******************************************************************************/
#define BUS_CLK 16000   /* bus clock frequency in MHz*/
#define TIMER_GLOBALTIME_PERIOD 1  /* timeout period in ms, can be changed */
#define TIMER_GLOBALTIME_LOADVALUE ( ((TIMER_GLOBALTIME_PERIOD*BUS_CLK)/2)-1 )

/******************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                            */
/******************************************************************************/
#define   OS_START_SEC_VAR_UNSPECIFIED
#include  "Memmap.h"

VAR(tpl_stack_word, OS_VAR) stack_zone_of_IdleTask[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];

VAR(hcs12_context, OS_VAR) idle_task_context;

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
_STATIC_ VAR(tpl_watchdog_expire_function, OS_VAR) WatchdogExpireCallback;
_STATIC_ VAR(tpl_time, OS_VAR) tpl_s12x_GlobalTime;
#endif

#define   OS_STOP_SEC_VAR_UNSPECIFIED
#include  "Memmap.h"


#define OS_START_SEC_VAR_8BITS
#include  "Memmap.h"

_STATIC_ VAR(uint16, OS_VAR) Os_CptTaskLock;

#define   OS_STOP_SEC_VAR_8BITS
#include  "Memmap.h"

/******************************************************************************/
/* DEFINITION OF GLOBAL FUNCTIONS                                            */
/******************************************************************************/

/******************************************************************************
** Function name: tpl_init_context(tpl_exec_common *exec_obj)
** Description: initialize a context to prepare a task to run.
**              It sets up the stack and lr and init the other registers to 0
** Parameter exec_obj : object to be initialized
** Return value: None
** Remarks: None
******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) tpl_init_context(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) exec_obj)
{
  P2VAR(hcs12_context, OS_APPL_DATA, AUTOMATIC) ic = exec_obj->static_desc->context.ic;

  /* initialises the registers to 0 */
  ic->d = 0;
  ic->x = 0;
  ic->y = 0;

  #ifdef WITH_AUTOSAR_STACK_MONITORING
  for(ic->sp = (uint16)exec_obj->static_desc->stack.stack_zone;
      ic->sp <= ((uint16)exec_obj->static_desc->stack.stack_zone
                + exec_obj->static_desc->stack.stack_size);
      ic->sp++)
  {
    *(P2VAR(uint8, OS_APPL_DATA, AUTOMATIC))(ic->sp) = OS_S12X_STACK_PATERN;
  }
  ic->sp--; /* re-adjust stack-pointer that has been incremented once more that needed */
  #else
  /* initialises the stack pointer of the task to
    start address + stack size = end of stack zone */
  ic->sp = ((uint16)exec_obj->static_desc->stack.stack_zone)
                 + exec_obj->static_desc->stack.stack_size;
  #endif
  /* initialises the CCR with 0: all flags reset */
  ic->ccr = 0;

  /* initialises the programm counter to the
    task function base address */
  ic->pc = exec_obj->static_desc->entry;
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"

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
#include "Memmap.h"
FUNC(void, OS_CODE) tpl_init_machine(void)
{
  /* initializes the TaskLock counter */
  Os_CptTaskLock = 0;

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  /* initializes the Watchdog expire function */
  WatchdogExpireCallback = NULL_PTR;
  tpl_s12x_GlobalTime = 0;
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
  for(idle_task_context.sp = (uint16)(&stack_zone_of_IdleTask);
      idle_task_context.sp <= ((uint16)(&stack_zone_of_IdleTask)
                              + SIZE_OF_IDLE_STACK);
      idle_task_context.sp++)
  {
    *(P2VAR(uint8, OS_APPL_DATA, AUTOMATIC))(idle_task_context.sp) = OS_S12X_STACK_PATERN;
  }
  idle_task_context.sp--; /* re-adjust stack-pointer that has been incremented once more that needed */
#else
  /* initialises the stack pointer of the task to
    start address + stack size = end of stack zone */
  idle_task_context.sp = (uint16)(&stack_zone_of_IdleTask);
  idle_task_context.sp = idle_task_context.sp + SIZE_OF_IDLE_STACK;
#endif

  /* initialises the programm counter to the
    sleep function base address */
  idle_task_context.pc = tpl_sleep;

  Os_S12X_StartBaseTimer();

  EnableInterruptSource(Gpt_Isr2Channel0);
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  EnableInterruptSource(Gpt_Isr2Channel1);
#endif
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
** Description: function to switch context
** Parameter old_context: context to be saved / stored in the stack
** Parameter new_context: context to be loaded / stored in D register
** Return value: None
** Remarks: assembly function
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_RETURN
FUNC(void, OS_CODE) tpl_switch_context(
  P2VAR(tpl_context, OS_APPL_DATA, AUTOMATIC) old_context,
  P2VAR(tpl_context, OS_APPL_DATA, AUTOMATIC) new_context)
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
    __asm RTS                       ;/* pull all register and PC, return */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"

/*******************************************************************************
** Function name: tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
** Description: function to switch context from It
** Parameter old_context: context to be saved / stored in the stack
** Parameter new_context: context to be loaded / stored in D register
** Return value: None
** Remarks: assembly function
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"

#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_RETURN
FUNC(void, OS_CODE) tpl_switch_context_from_it(
  P2VAR(tpl_context, OS_APPL_DATA, AUTOMATIC) old_context,
  P2VAR(tpl_context, OS_APPL_DATA, AUTOMATIC) new_context)
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
    __asm RTS                       ;/* pull all register and PC, return */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: tpl_sleep(void)
** Description: wait when there is no task to be executed
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) tpl_sleep(void)
{
  while(1);
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: tpl_shutdown(void)
** Description: last function executed when leaving OS, disable interrupts and wait
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) tpl_shutdown(void)
{
  __asm SEI                   ;/* set the I bit of CCR, inhibits interrupts */
  __asm shutdown_loop:        ;/* go in an infinit loop */
  __asm BRA shutdown_loop
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: tpl_get_task_lock(void)
** Description: inhibits interrupts
** Parameter : None
** Return value: None
** Remarks: assembly function
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) tpl_get_task_lock(void)
{
  __asm SEI     ;/* set the I bit of CCR, inhibits interrupts */
  Os_CptTaskLock++;
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: tpl_release_task_lock(void)
** Description: re-allows interrupts
** Parameter : None
** Return value: None
** Remarks: assembly function
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) tpl_release_task_lock(void)
{
  if( Os_CptTaskLock > 0)
  {
    Os_CptTaskLock--;
  }
  if( Os_CptTaskLock == 0)
  {
    __asm CLI     ;/* clear the I bit of CCR, re-allows interrupts */
  }
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: EnableAllInterrupts(void)
** Description: enable interrupts
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) EnableAllInterrupts(void)
{
  __asm CLI     ;/* clear the I bit of CCR, re-allows interrupts */

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_disable_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: DisableAllInterrupts(void)
** Description: disable interrupts
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) DisableAllInterrupts(void)
{
  __asm SEI     ;/* set the I bit of CCR, inhibits interrupts */

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_start_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: ResumeAllInterrupts(void)
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) ResumeAllInterrupts(void)
{
  tpl_release_task_lock();

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_disable_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: SuspendAllInterrupts(void)
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) SuspendAllInterrupts(void)
{
  tpl_get_task_lock();

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_start_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: ResumeOSInterrupts(void)
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) ResumeOSInterrupts(void)
{
  tpl_release_task_lock();

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_disable_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: SuspendOSInterrupts(void)
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) SuspendOSInterrupts(void)
{
  tpl_get_task_lock();

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_start_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


#ifdef WITH_AUTOSAR_TIMING_PROTECTION
/*******************************************************************************
** Function name: tpl_set_watchdog
** Description:
** Parameter :  delay: delay in ns before the callback shall be called
**              function: callbakc that shall be called when the delay expires
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) tpl_set_watchdog(
  VAR(tpl_time, AUTOMATIC) delay,
  VAR(tpl_watchdog_expire_function, AUTOMATIC) function)
{
  VAR(Gpt_ValueType, AUTOMATIC) NbTicks = ((delay*BUS_CLK)>>1)-1;
  WatchdogExpireCallback = function;
  Gpt_StartTimer(OS_GPTCHANNEL_WATCHDOG, NbTicks);

  Gpt_EnableNotification(OS_GPTCHANNEL_WATCHDOG);
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: tpl_cancel_watchdog
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) tpl_cancel_watchdog(void)
{
  Gpt_DisableNotification(OS_GPTCHANNEL_WATCHDOG);

  Gpt_StopTimer(OS_GPTCHANNEL_WATCHDOG);
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"


/*******************************************************************************
** Function name: tpl_get_local_current_date
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(tpl_time, OS_CODE) tpl_get_local_current_date(void)
{
  return tpl_s12x_GlobalTime;
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"

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
#include "Memmap.h"
FUNC(u8, OS_CODE) tpl_check_stack_pointer(
  P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(uint16, AUTOMATIC) StackPointer = this_exec_obj->static_desc->context.ic->sp;

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
#define OS_STOP_SEC_CODE
#include "Memmap.h"


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
#include "Memmap.h"
FUNC(u8, OS_CODE) tpl_check_stack_footprint(
  P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  if( OS_S12X_STACK_PATERN == (*(uint8 *)(this_exec_obj->static_desc->stack.stack_zone)) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"

#endif /* WITH_AUTOSAR_STACK_MONITORING */


/*******************************************************************************
** Function name: Os_WatchdogCallback
** Description: This function is called by the Gpt when the timer of the
**              watchdog expires. it calls the function given in parameter of
**              the function tpl_set_watchdog.
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#define GPT_START_SEC_CODE
#include "Memmap.h"
FUNC(void, GPT_CODE) Os_WatchdogCallback(void)
{
  Gpt_DisableNotification(OS_GPTCHANNEL_WATCHDOG);

  Gpt_StopTimer(OS_GPTCHANNEL_WATCHDOG);

  if( NULL_PTR != WatchdogExpireCallback )
  {
    WatchdogExpireCallback();
  }
}
#define GPT_STOP_SEC_CODE
#include "Memmap.h"
#endif

/*******************************************************************************
** Function name: Os_S12X_StartBaseTimer
** Description: This function can be called to start thebase timer of the Os
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) Os_S12X_StartBaseTimer(void)
{
  Gpt_StartTimer(OS_GPTCHANNEL_TICK,TIMER_GLOBALTIME_LOADVALUE);
  Gpt_EnableNotification(OS_GPTCHANNEL_TICK);
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"



/*******************************************************************************
** Function name: tpl_s12x_inc_time
** Description: This function increments the global time of the Os by the
**              tick value of the Os
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"
FUNC(void, OS_CODE) tpl_s12x_inc_time(void)
{
  tpl_s12x_GlobalTime = (tpl_s12x_GlobalTime+(TIMER_GLOBALTIME_PERIOD));
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"
