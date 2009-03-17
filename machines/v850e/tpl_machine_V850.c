/*==============================================================================
** Trampoline OS
**
** Trampoline is copyright (c) IRCCyN 2005+
** Copyright ESEO for function and data structures documentation
** Trampoline is protected by the French intellectual property law.
**
** This software is distributed under the Lesser GNU Public Licence
**------------------------------------------------------------------------------
** Supported MCUs       : NEC V850E
** Supported Compilers  : GHS Multi
**------------------------------------------------------------------------------
** File name         : tpl_machine_v850e.c
**
** Module name       : OS
**
**
** Summary: functions of the OS specifics for the MCU NEC V850E that can only be
**          implemented in assembly
**              .
**= History ===================================================================
** 01.04  J.Monsimier 03/12/07
**  - creation
=============================================================================*/

/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_generated_configuration.h"
#include "tpl_os_kernel.h"
#include "tpl_os_it.h"
#include "tpl_os_task.h"
#include "tpl_os_error.h"

#include "Std_Types.h"
#include "Gpt.h"


/******************************************************************************/
/* DECLARATION OF CONSTANTS                                                   */
/******************************************************************************/
#define OS_STACK_PATERN         0xAA

#define OS_GPTCHANNEL_WATCHDOG  2
#define OS_GPTCHANNEL_TICK      0

#define OS_TIMER_GLOBALTIME_PRESCALECLOCK 32
#define OS_TIMER_GLOBALTIME_PERIOD        1000  /* timeout period in ns, can be changed */
#define OS_TIMER_GLOBALTIME_LOADVALUE     (OS_TIMER_GLOBALTIME_PERIOD*OS_TIMER_GLOBALTIME_PRESCALECLOCK) /* prescaled clock is 32MHz */

/******************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                            */
/******************************************************************************/
#define   OS_START_SEC_VAR_UNSPECIFIED
#include  "MemMap.h"

VAR(tpl_stack_word, OS_VAR) stack_zone_of_IdleTask[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];

VAR(v850e_context, OS_VAR) idle_task_context;

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
_STATIC_ VAR(tpl_watchdog_expire_function, OS_VAR) Os_WatchdogExpireCallback = NULL_PTR;
_STATIC_ VAR(tpl_time, OS_VAR) Os_GlobalTime;
#endif

#define   OS_STOP_SEC_VAR_UNSPECIFIED
#include  "MemMap.h"


#define OS_START_SEC_VAR_16BITS
#include  "MemMap.h"

_STATIC_ VAR(uint16, OS_VAR) Os_CptTaskLock;

#define   OS_STOP_SEC_VAR_16BITS
#include  "MemMap.h"


/******************************************************************************/
/* DECLARATION OF INTERNAL FUNCTIONS                                             */
/******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

_STATIC_ FUNC(void, OS_CODE) Os_StartBaseTimer(void);

_STATIC_ FUNC(void, OS_CODE) Os_ErrorTerminateTask(void);

#define OS_STOP_SEC_CODE
#include "MemMap.h"


/******************************************************************************/
/* DEFINITION OF GLOBAL FUNCTIONS                                             */
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
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_init_context(
    P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) exec_obj)
{
  P2VAR(v850e_context, OS_APPL_DATA, AUTOMATIC) ic = exec_obj->static_desc->context.ic;
  VAR(uint8, AUTOMATIC) i;

  /* initialises the registers to 0 */
  for(i=0; i<31; i++)
  {
    ic->Rn[i]=0;
  }


  #ifdef WITH_AUTOSAR_STACK_MONITORING
  for(ic->Rn[3] = (uint32)(exec_obj->static_desc->stack.stack_zone);
      ic->Rn[3] < (uint32)(exec_obj->static_desc->stack.stack_zone) + exec_obj->static_desc->stack.stack_size;
      (ic->Rn[3])++)
  {
    *(P2VAR(uint8, OS_APPL_DATA, AUTOMATIC))(ic->Rn[3]) = OS_STACK_PATERN;
  }

  ic->Rn[3] = ic->Rn[3] - 4;
  #else
  /* initialises the stack pointer of the task to
    start address + stack size = end of stack zone */
  ic->Rn[3] = (uint32)(exec_obj->static_desc->stack.stack_zone) + exec_obj->static_desc->stack.stack_size - 4;
  #endif


  /* initialize the return address of the object (task or isr2)
    this is used if the user forget to termiante a task or isr
    by TerminateTask() or TerminateISR2() */
  if(exec_obj->static_desc->type == IS_ROUTINE)
  {
    /* if object is an ISR2, initialize the return address to TerminateISR2() */
    ic->Rn[31] = (uint32)TerminateISR2;
  }
  else
  {
    /* if object is a TASK, initialize the return address to TerminateTask() */
    ic->Rn[31] = (uint32)Os_ErrorTerminateTask;
  }

  /* initialises the programm counter to the
    task function base address */
  ic->PC = (uint32)exec_obj->static_desc->entry;

  /* initialises the PSW with default reset value */
  ic->PSW = 0x00000020;

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
    VAR(uint8, AUTOMATIC) i;

    /* initializes the TaskLock counter */
  Os_CptTaskLock = 0;

  #ifdef WITH_AUTOSAR_TIMING_PROTECTION
  /* initializes the Watchdog expire function */
  Os_WatchdogExpireCallback = NULL_PTR;
  Os_GlobalTime = 0;
#endif

  /* initialises the PSW with default reset value */
  idle_task_context.PSW = 0x00000020;


  /* initialises the registers to 0 */
  for(i=0; i<31; i++)
  {
    idle_task_context.Rn[i]=0;
  }

  /* initialises the stack pointer of the idle task to
    start address + stack size = end of stack zone */
  /* if Stack Monitoring is enabled, fill the stack with a pattern in
    order to check later if the pattern was erased */
#ifdef WITH_AUTOSAR_STACK_MONITORING
  for(idle_task_context.Rn[3] = (uint32)(&stack_zone_of_IdleTask);
      idle_task_context.Rn[3] < (uint32)(&stack_zone_of_IdleTask) + SIZE_OF_IDLE_STACK;
      (idle_task_context.Rn[3])++)
  {
    *(P2VAR(uint8, OS_APPL_DATA, AUTOMATIC))(idle_task_context.Rn[3]) = OS_STACK_PATERN;
  }

  idle_task_context.Rn[3] = idle_task_context.Rn[3] -4;
#else
  /* initialises the stack pointer of the task to
    start address + stack size = end of stack zone */
  idle_task_context.Rn[3] = (uint32)(&stack_zone_of_IdleTask);
  idle_task_context.Rn[3] = idle_task_context.Rn[3] + SIZE_OF_IDLE_STACK - 4 ;
#endif

  /* initialises the programm counter to the
    sleep function base address */
  idle_task_context.Rn[31] = (uint32)tpl_sleep;

  idle_task_context.PC = (uint32)tpl_sleep;

  Os_StartBaseTimer();

  //EnableInterruptSource(Isr2GptChannel0);
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  //EnableInterruptSource(Isr2GptChannel1);
#endif
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
#define OS_START_SEC_CODE
#include "MemMap.h"

FUNC(void, OS_CODE) tpl_switch_context(
  P2VAR(tpl_context, OS_APPL_DATA, AUTOMATIC) old_context,
  P2VAR(tpl_context, OS_APPL_DATA, AUTOMATIC) new_context)
{

  asm("di");

  /* the stack pointer is shifted by the compiler on function entry, so we re-adjust it */
  asm("add    4,sp");

  /* empty the 5 level of pipeline */
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");

  /************************************************/
  /*  save running context in old context         */
  /************************************************/
  /* save r8 on stack in order to be used */
  asm("add    -4,sp");
  asm("st.w   r8,0[sp]");

  /* check if old context not NULL */
  asm("cmp    0,r6");
  asm("bz     nosave");                 /* if old context is NULL, do not save, go to nosave  */

  /* load r6 with object pointed by r6 ==> access to field old_context->ic */
  asm("ld.w   0[r6],r6");

  /* check if old context is idle_task_context */
  asm("mov    _idle_task_context,r8");
  asm("cmp    r8,r6");
  asm("bz     nosave");                 /* if old context is idle_task_context, do not save, go to nosave  */

  /* restore r8 from stack */
  asm("ld.w   0[sp],r8");
  asm("add    4,sp");

  /* save all global registers in old_context->ic.Rn[i] */
  asm("st.w   r0,0[r6]");
  asm("add    4,r6");
  asm("st.w   r1,4[r6]");
  asm("add    4,r6");
  asm("st.w   r2,0[r6]");
  asm("add    4,r6");
  asm("st.w   r3,0[r6]");
  asm("add    4,r6");
  asm("st.w   r4,0[r6]");
  asm("add    4,r6");
  asm("st.w   r5,0[r6]");
  asm("add    4,r6");
  asm("st.w   r6,0[r6]");
  asm("add    4,r6");
  asm("st.w   r7,0[r6]");
  asm("add    4,r6");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");
  asm("st.w   r9,0[r6]");
  asm("add    4,r6");
  asm("st.w   r10,0[r6]");
  asm("add    4,r6");
  asm("st.w   r11,0[r6]");
  asm("add    4,r6");
  asm("st.w   r12,0[r6]");
  asm("add    4,r6");
  asm("st.w   r13,0[r6]");
  asm("add    4,r6");
  asm("st.w   r14,0[r6]");
  asm("add    4,r6");
  asm("st.w   r15,0[r6]");
  asm("add    4,r6");
  asm("st.w   r16,0[r6]");
  asm("add    4,r6");
  asm("st.w   r17,0[r6]");
  asm("add    4,r6");
  asm("st.w   r18,0[r6]");
  asm("add    4,r6");
  asm("st.w   r19,0[r6]");
  asm("add    4,r6");
  asm("st.w   r20,0[r6]");
  asm("add    4,r6");
  asm("st.w   r21,0[r6]");
  asm("add    4,r6");
  asm("st.w   r22,0[r6]");
  asm("add    4,r6");
  asm("st.w   r23,0[r6]");
  asm("add    4,r6");
  asm("st.w   r24,0[r6]");
  asm("add    4,r6");
  asm("st.w   r25,0[r6]");
  asm("add    4,r6");
  asm("st.w   r26,0[r6]");
  asm("add    4,r6");
  asm("st.w   r27,0[r6]");
  asm("add    4,r6");
  asm("st.w   r28,0[r6]");
  asm("add    4,r6");
  asm("st.w   r29,0[r6]");
  asm("add    4,r6");
  asm("st.w   r30,0[r6]");
  asm("add    4,r6");
  asm("st.w   r31,0[r6]");
  asm("add    4,r6");

  /* save interrupt context save registers */
  asm("stsr   EIPC,r8");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");
  asm("stsr   EIPSW,r8");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");
  asm("stsr   FEPC,r8");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");
  asm("stsr   FEPSW,r8");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");

  /* save PSW register in old_context->ic.PSW */
  asm("stsr   5,r8");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");

  /* save lp to old_context->ic.PC */
  asm("st.w   lp,0[r6]");
  asm("add    4,r6");


  asm("nosave:  ");
  /************************************************/
  /*  load new context in running context         */
  /************************************************/

  /* load r7 with object pointed by r7 ==> access to field new_context->ic */
  asm("ld.w   0[r7],r7");

  /* load all global registers from new_context->ic.Rn[i] */
  asm("ld.w   0[r7],r0");
  asm("add    4,r7");
  asm("ld.w   0[r7],r1");
  asm("add    4,r7");
  asm("ld.w   0[r7],r2");
  asm("add    4,r7");
  asm("ld.w   0[r7],r3");
  asm("add    4,r7");
  asm("ld.w   0[r7],r4");
  asm("add    4,r7");
  asm("ld.w   0[r7],r5");
  asm("add    4,r7");
  asm("ld.w   0[r7],r6");
  asm("add    8,r7");
  /* do not load r7 yet, because we are currently using it */
  asm("ld.w   0[r7],r8");
  asm("add    4,r7");
  asm("ld.w   0[r7],r9");
  asm("add    4,r7");
  asm("ld.w   0[r7],r10");
  asm("add    4,r7");
  asm("ld.w   0[r7],r11");
  asm("add    4,r7");
  asm("ld.w   0[r7],r12");
  asm("add    4,r7");
  asm("ld.w   0[r7],r13");
  asm("add    4,r7");
  asm("ld.w   0[r7],r14");
  asm("add    4,r7");
  asm("ld.w   0[r7],r15");
  asm("add    4,r7");
  asm("ld.w   0[r7],r16");
  asm("add    4,r7");
  asm("ld.w   0[r7],r17");
  asm("add    4,r7");
  asm("ld.w   0[r7],r18");
  asm("add    4,r7");
  asm("ld.w   0[r7],r19");
  asm("add    4,r7");
  asm("ld.w   0[r7],r20");
  asm("add    4,r7");
  asm("ld.w   0[r7],r21");
  asm("add    4,r7");
  asm("ld.w   0[r7],r22");
  asm("add    4,r7");
  asm("ld.w   0[r7],r23");
  asm("add    4,r7");
  asm("ld.w   0[r7],r24");
  asm("add    4,r7");
  asm("ld.w   0[r7],r25");
  asm("add    4,r7");
  asm("ld.w   0[r7],r26");
  asm("add    4,r7");
  asm("ld.w   0[r7],r27");
  asm("add    4,r7");
  asm("ld.w   0[r7],r28");
  asm("add    4,r7");
  asm("ld.w   0[r7],r29");
  asm("add    4,r7");
  asm("ld.w   0[r7],r30");
  asm("add    4,r7");
  asm("ld.w   0[r7],r31");
  asm("add    4,r7");

  /* save r8, r9 and r10 on stack in order to be used */
  asm("add    -4,sp");
  asm("st.w   r8,0[sp]");
  asm("add    -4,sp");
  asm("st.w   r9,0[sp]");
  asm("add    -4,sp");
  asm("st.w   r10,0[sp]");

  /* load interrupt context save registers */
  asm("ld.w   0[r7],r8");
  asm("ldsr   r8,EIPC");
  asm("add    4,r7");
  asm("ld.w   0[r7],r8");
  asm("ldsr   r8,EIPSW");
  asm("add    4,r7");
  asm("ld.w   0[r7],r8");
  asm("ldsr   r8,FEPC");
  asm("add    4,r7");
  asm("ld.w   0[r7],r8");
  asm("ldsr   r8,FEPSW");
  asm("add    4,r7");

  /* load PSW register from new_context->ic.PSW */
  asm("ld.w   0[r7],r8");   /* load saved PSW in r8                       */
  asm("add    4,r7");
  asm("stsr   5,r9");
  asm("mov    0x0000001F,r10");     /* r10 = 0x0000001F                                     */
  asm("and    r10,r8");             /* r8 = r8 & 0x0000001F ==> we keep only 5 1st low bits */
  asm("mov    0xFFFFFFE0,r10");     /* r10 = 0xFFFFFFE0                                     */
  asm("and    r10,r9");             /* r9 = r9 & 0xFFFFFFC0 ==> we remove 5 1st low bits    */
  asm("or     r9,r8");              /* r8 = r8 | r9 ==> put together high bits of
                                       current PSW and low bits of saved PSW                */
  asm("ldsr   r8,5");               /* load PSW with r8                                     */

  /* restore r8,r9 and r10 from stack */
  asm("ld.w   0[sp],r10");
  asm("add    4,sp");
  asm("ld.w   0[sp],r9");
  asm("add    4,sp");
  asm("ld.w   0[sp],r8");
  asm("add    4,sp");

  asm("ld.w   0[r7],r6");


  /* finish by loading r7 from new_context->ic.Rn[7] */
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("ld.w   0[r7],r7");


  asm("add    -4, sp");
  asm("st.w   lp, 0[sp]");
  tpl_release_task_lock();
  asm("ld.w   0[sp], lp");
  asm("add    4,sp");

  /* empty the 5 level of pipeline */
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");

  asm("jmp    [r6]");   /* jump to old_context->ic.PC */

  tpl_get_task_lock();

}
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function name: tpl_switch_context(tpl_context *old_context, tpl_context *new_context)
** Description: function to switch context from It
** Parameter old_context: context to be saved / stored in the stack
** Parameter new_context: context to be loaded / stored in D register
** Return value: None
** Remarks: assembly function
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

FUNC(void, OS_CODE) tpl_switch_context_from_it(
  P2VAR(tpl_context, OS_APPL_DATA, AUTOMATIC) old_context,
  P2VAR(tpl_context, OS_APPL_DATA, AUTOMATIC) new_context)
{

  asm("di");

  /* empty the 5 level of pipeline */
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");

  /************************************************/
  /*  save running context in old context         */
  /************************************************/
  /* save r8 on stack in order to be used */
  asm("add    -4,sp");
  asm("st.w   r8,0[sp]");

  /* check if old context not NULL */
  asm("cmp    0,r6");
  asm("bz     nosaveit");                 /* if old context is NULL, do not save, go to nosave  */

  /* load r6 with object pointed by r6 ==> access to field old_context->ic */
  asm("ld.w   0[r6],r6");

  /* check if old context is idle_task_context */
  //asm("mov    _idle_task_context,r8");
  //asm("cmp    r8,r6");
  //asm("bz     nosave");                 /* if old context is idle_task_context, do not save, go to nosave  */

  /* restore r8 from stack */
  asm("ld.w   0[sp],r8");
  asm("add    4,sp");

  /* save all global registers in old_context->ic.Rn[i] */
  asm("st.w   r0,0[r6]");
  asm("add    4,r6");
  asm("st.w   r1,4[r6]");
  asm("add    4,r6");
  asm("st.w   r2,0[r6]");
  asm("add    4,r6");
  asm("st.w   r3,0[r6]");
  asm("add    4,r6");
  asm("st.w   r4,0[r6]");
  asm("add    4,r6");
  asm("st.w   r5,0[r6]");
  asm("add    4,r6");
  asm("st.w   r6,0[r6]");
  asm("add    4,r6");
  asm("st.w   r7,0[r6]");
  asm("add    4,r6");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");
  asm("st.w   r9,0[r6]");
  asm("add    4,r6");
  asm("st.w   r10,0[r6]");
  asm("add    4,r6");
  asm("st.w   r11,0[r6]");
  asm("add    4,r6");
  asm("st.w   r12,0[r6]");
  asm("add    4,r6");
  asm("st.w   r13,0[r6]");
  asm("add    4,r6");
  asm("st.w   r14,0[r6]");
  asm("add    4,r6");
  asm("st.w   r15,0[r6]");
  asm("add    4,r6");
  asm("st.w   r16,0[r6]");
  asm("add    4,r6");
  asm("st.w   r17,0[r6]");
  asm("add    4,r6");
  asm("st.w   r18,0[r6]");
  asm("add    4,r6");
  asm("st.w   r19,0[r6]");
  asm("add    4,r6");
  asm("st.w   r20,0[r6]");
  asm("add    4,r6");
  asm("st.w   r21,0[r6]");
  asm("add    4,r6");
  asm("st.w   r22,0[r6]");
  asm("add    4,r6");
  asm("st.w   r23,0[r6]");
  asm("add    4,r6");
  asm("st.w   r24,0[r6]");
  asm("add    4,r6");
  asm("st.w   r25,0[r6]");
  asm("add    4,r6");
  asm("st.w   r26,0[r6]");
  asm("add    4,r6");
  asm("st.w   r27,0[r6]");
  asm("add    4,r6");
  asm("st.w   r28,0[r6]");
  asm("add    4,r6");
  asm("st.w   r29,0[r6]");
  asm("add    4,r6");
  asm("st.w   r30,0[r6]");
  asm("add    4,r6");
  asm("st.w   r31,0[r6]");
  asm("add    4,r6");

  /* save interrupt context save registers */
  asm("stsr   EIPC,r8");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");
  asm("stsr   EIPSW,r8");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");
  asm("stsr   FEPC,r8");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");
  asm("stsr   FEPSW,r8");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");

  /* save PSW register in old_context->ic.PSW */
  asm("stsr   PSW,r8");
  asm("st.w   r8,0[r6]");
  asm("add    4,r6");

  /* save lp to old_context->ic.PC */
  asm("st.w   lp,0[r6]");
  asm("add    4,r6");


  asm("nosaveit:  ");
  /************************************************/
  /*  load new context in running context         */
  /************************************************/

  /* load r7 with object pointed by r7 ==> access to field new_context->ic */
  asm("ld.w   0[r7],r7");

  /* load all global registers from new_context->ic.Rn[i] */
  asm("ld.w   0[r7],r0");
  asm("add    4,r7");
  asm("ld.w   0[r7],r1");
  asm("add    4,r7");
  asm("ld.w   0[r7],r2");
  asm("add    4,r7");
  asm("ld.w   0[r7],r3");
  asm("add    4,r7");
  asm("ld.w   0[r7],r4");
  asm("add    4,r7");
  asm("ld.w   0[r7],r5");
  asm("add    4,r7");
  asm("ld.w   0[r7],r6");
  asm("add    8,r7");
  /* do not load r7 yet, because we are currently using it */
  asm("ld.w   0[r7],r8");
  asm("add    4,r7");
  asm("ld.w   0[r7],r9");
  asm("add    4,r7");
  asm("ld.w   0[r7],r10");
  asm("add    4,r7");
  asm("ld.w   0[r7],r11");
  asm("add    4,r7");
  asm("ld.w   0[r7],r12");
  asm("add    4,r7");
  asm("ld.w   0[r7],r13");
  asm("add    4,r7");
  asm("ld.w   0[r7],r14");
  asm("add    4,r7");
  asm("ld.w   0[r7],r15");
  asm("add    4,r7");
  asm("ld.w   0[r7],r16");
  asm("add    4,r7");
  asm("ld.w   0[r7],r17");
  asm("add    4,r7");
  asm("ld.w   0[r7],r18");
  asm("add    4,r7");
  asm("ld.w   0[r7],r19");
  asm("add    4,r7");
  asm("ld.w   0[r7],r20");
  asm("add    4,r7");
  asm("ld.w   0[r7],r21");
  asm("add    4,r7");
  asm("ld.w   0[r7],r22");
  asm("add    4,r7");
  asm("ld.w   0[r7],r23");
  asm("add    4,r7");
  asm("ld.w   0[r7],r24");
  asm("add    4,r7");
  asm("ld.w   0[r7],r25");
  asm("add    4,r7");
  asm("ld.w   0[r7],r26");
  asm("add    4,r7");
  asm("ld.w   0[r7],r27");
  asm("add    4,r7");
  asm("ld.w   0[r7],r28");
  asm("add    4,r7");
  asm("ld.w   0[r7],r29");
  asm("add    4,r7");
  asm("ld.w   0[r7],r30");
  asm("add    4,r7");
  asm("ld.w   0[r7],r31");
  asm("add    4,r7");

  /* save r8, r9 and r10 on stack in order to be used */
  asm("add    -4,sp");
  asm("st.w   r8,0[sp]");
  asm("add    -4,sp");
  asm("st.w   r9,0[sp]");
  asm("add    -4,sp");
  asm("st.w   r10,0[sp]");

  /* load interrupt context save registers */
  asm("ld.w   0[r7],r8");
  asm("ldsr   r8,EIPC");
  asm("add    4,r7");
  asm("ld.w   0[r7],r8");
  asm("ldsr   r8,EIPSW");
  asm("add    4,r7");
  asm("ld.w   0[r7],r8");
  asm("ldsr   r8,FEPC");
  asm("add    4,r7");
  asm("ld.w   0[r7],r8");
  asm("ldsr   r8,FEPSW");
  asm("add    4,r7");

  /* load PSW register from new_context->ic.PSW */
  asm("ld.w   0[r7],r8");   /* load saved PSW in r8                       */
  asm("add    4,r7");
  asm("stsr   PSW,r9");
  asm("mov    0x0000001F,r10");     /* r10 = 0x0000001F                                     */
  asm("and    r10,r8");             /* r8 = r8 & 0x0000001F ==> we keep only 5 1st low bits */
  asm("mov    0xFFFFFF00,r10");     /* r10 = 0xFFFFFF00                                     */
  asm("and    r10,r9");             /* r9 = r9 & 0xFFFFFF00 ==> we remove 5 1st low bits and interrupt bits   */
  asm("or     r9,r8");              /* r8 = r8 | r9 ==> put together high bits of
                                       current PSW and low bits of saved PSW                */
  asm("ldsr   r8,5");               /* load PSW with r8                                     */
  asm("ldsr   r8,EIPSW");
  asm("ldsr   r8,FEPSW");


  /* restore r8,r9 and r10 from stack */
  asm("ld.w   0[sp],r10");
  asm("add    4,sp");
  asm("ld.w   0[sp],r9");
  asm("add    4,sp");
  asm("ld.w   0[sp],r8");
  asm("add    4,sp");

  asm("ld.w   0[r7],r6");


  /* finish by loading r7 from new_context->ic.Rn[7] */
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("add    -16,r7");
  asm("ld.w   0[r7],r7");


  asm("ldsr   r6,EIPC");
  asm("ldsr   r6,FEPC");

  /* empty the 5 level of pipeline */
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");

  asm("reti");

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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_sleep(void)
{
  while(1);
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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_shutdown(void)
{
  __asm("di");  /* set the I bit of CCR, inhibits interrupts */
  __asm("halt");/* stop the CPU clock */
  while(1);     /* when using debugger, the "halt" mode can be exited,
                   so this infinite loop is used only in this case */

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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_get_task_lock(void)
{
  __asm("di");  /* inhibits interrupts */
  Os_CptTaskLock++;
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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_release_task_lock(void)
{
  if( Os_CptTaskLock > 0)
  {
    Os_CptTaskLock--;
  }
  if( Os_CptTaskLock == 0)
  {
    __asm("ei");/* re-allows interrupts */
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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) EnableAllInterrupts(void)
{
  __asm("ei");  /* re-allows interrupts */

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_disable_all_isr_lock_monitor (tpl_running_obj);
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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) DisableAllInterrupts(void)
{
  __asm("di");  /* inhibits interrupts */

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_start_all_isr_lock_monitor (tpl_running_obj);
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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) ResumeAllInterrupts(void)
{
  if( Os_CptTaskLock > 0)
  {
    Os_CptTaskLock--;
  }
  if( Os_CptTaskLock == 0)
  {
    __asm("ei");/* re-allows interrupts */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_disable_all_isr_lock_monitor (tpl_running_obj);
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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) SuspendAllInterrupts(void)
{
  __asm("di");  /* inhibits interrupts */
  Os_CptTaskLock++;

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  if( Os_CptTaskLock == 1)
  {
    tpl_start_all_isr_lock_monitor (tpl_running_obj);
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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) ResumeOSInterrupts(void)
{
  if( Os_CptTaskLock > 0)
  {
    Os_CptTaskLock--;
  }
  if( Os_CptTaskLock == 0)
  {
    __asm("ei");/* re-allows interrupts */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_disable_os_isr_lock_monitor (tpl_running_obj);
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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) SuspendOSInterrupts(void)
{
  __asm("di");  /* inhibits interrupts */
  Os_CptTaskLock++;

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  if( Os_CptTaskLock == 1)
  {
    tpl_start_os_isr_lock_monitor (tpl_running_obj);
  }
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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_set_watchdog(
  VAR(tpl_time, AUTOMATIC) delay,
  VAR(tpl_watchdog_expire_function, AUTOMATIC) function)
{
  VAR(Gpt_ValueType, AUTOMATIC) NbTicks =
      delay * OS_TIMER_GLOBALTIME_PRESCALECLOCK * OS_TIMER_GLOBALTIME_PERIOD;
  Os_WatchdogExpireCallback = function;

  Gpt_EnableNotification(OS_GPTCHANNEL_WATCHDOG);
  Gpt_StartTimer(OS_GPTCHANNEL_WATCHDOG, NbTicks);
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: tpl_cancel_watchdog
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) tpl_cancel_watchdog(void)
{
  Gpt_DisableNotification(OS_GPTCHANNEL_WATCHDOG);

  Gpt_StopTimer(OS_GPTCHANNEL_WATCHDOG);
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function name: tpl_get_local_current_date
** Description:
** Parameter : None
** Return value: None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(tpl_time, OS_CODE) tpl_get_local_current_date(void)
{
  return Os_GlobalTime;
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
  P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  VAR(uint32, AUTOMATIC) StackPointer = this_exec_obj->static_desc->context.ic->Rn[3];

  if( (this_exec_obj->static_desc->context.ic) != (&idle_task_context) )
  {
    if( (StackPointer < (uint32)this_exec_obj->static_desc->stack.stack_zone)
      ||(StackPointer > ((uint32)this_exec_obj->static_desc->stack.stack_zone
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
**                0 stack overflow detected
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(u8, OS_CODE) tpl_check_stack_footprint(
  P2VAR(tpl_exec_common, OS_APPL_DATA, AUTOMATIC) this_exec_obj)
{
  if( (this_exec_obj->static_desc->context.ic) != (&idle_task_context) )
  {
    if( OS_STACK_PATERN == (*(uint8 *)(this_exec_obj->static_desc->stack.stack_zone)) )
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
** Function name: Os_WatchdogCallback
** Description: This function is called by the Gpt when the timer of the
**              watchdog expires. it calls the function given in parameter of
**              the function tpl_set_watchdog.
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#define GPT_START_SEC_PUBLIC_CODE
#include "MemMap.h"
FUNC(void, GPT_PUBLIC_CODE) Os_WatchdogCallback(void)
{
  Gpt_DisableNotification(OS_GPTCHANNEL_WATCHDOG);

  Gpt_StopTimer(OS_GPTCHANNEL_WATCHDOG);

  if( NULL_PTR != Os_WatchdogExpireCallback )
  {
    Os_WatchdogExpireCallback();
  }
}
#define GPT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function name: Os_StartBaseTimer
** Description: This function can be called to start thebase timer of the Os
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
_STATIC_ FUNC(void, OS_CODE) Os_StartBaseTimer(void)
{
  Gpt_EnableNotification(OS_GPTCHANNEL_TICK);
  Gpt_StartTimer(OS_GPTCHANNEL_TICK,OS_TIMER_GLOBALTIME_LOADVALUE); //32 * 1/32MHz ==> 1ms

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
#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) Os_IncTime(void)
{
  Os_GlobalTime = (Os_GlobalTime+(OS_TIMER_GLOBALTIME_PERIOD));
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"



/*******************************************************************************
** Function name: ErrorTerminateTask
** Description: This function is called when leaving a Task entry function
**              without calling TerminateTask()
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
_STATIC_ FUNC(void, OS_CODE) Os_ErrorTerminateTask(void)
{
  PROCESS_ERROR(E_OS_MISSINGEND)

  TerminateTask();
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"

