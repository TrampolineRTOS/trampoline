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
** File name         : tpl_machine.h
**
** Module name       : OS
**
** Summary:   context and task types specific for the target
**
**= History ====================================================================
** 00.01  J.Monsimier 04/11/07
**  - creation
** 00.01  J-L Bechennec 07/05/07
**  - cut line to 80 characters
**  - removed __ before and after multiple inclusion symbol definition
**   __ should not be used to avoid clash with symbols defined by compilers
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
** 01.05  J.Monsimier 12/02/2008
**  - the way to initialize the stack for stack monitoring is changed
**  - some minor changes in the memory mapping
==============================================================================*/

#ifndef TPL_MACHINE_HCS12_H
#define TPL_MACHINE_HCS12_H

/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "Std_Types.h"
#include "tpl_os_custom_types.h"

/******************************************************************************/
/* DEFINITION OF CONSTANTS                                                    */
/******************************************************************************/
#define IDLE_CONTEXT &idle_task_context

#define SIZE_OF_IDLE_STACK  100

#define IDLE_STACK { &stack_zone_of_IdleTask, SIZE_OF_IDLE_STACK }

/******************************************************************************/
/* DEFINITION OF TYPES                                                        */
/******************************************************************************/
typedef P2FUNC(void, OS_APPL_CODE, tpl_function_pointer)(void);

typedef struct
{
  VAR(uint16, AUTOMATIC) ccr;                 /* condition code register                */
  VAR(uint16, AUTOMATIC) d;                   /* double accumulator D (or acc A and B)  */
  VAR(uint16, AUTOMATIC) x;                   /* index register X                       */
  VAR(uint16, AUTOMATIC) y;                   /* index register Y                       */
  VAR(tpl_function_pointer, AUTOMATIC) pc;    /* program counter                        */
  VAR(uint16, AUTOMATIC) sp;                  /* stack pointer                          */
} hcs12_context;

typedef struct
{
  P2VAR(hcs12_context, OS_APPL_DATA, AUTOMATIC) ic;
} tpl_context;

typedef struct
{
  P2VAR(tpl_stack_word, OS_APPL_DATA, AUTOMATIC)  stack_zone;
  VAR(tpl_stack_size, AUTOMATIC)                  stack_size;
} tpl_stack;


/******************************************************************************/
/* DEFINITION OF MACROS                                                       */
/******************************************************************************/


/******************************************************************************/
/* DECLARATION OF VARIABLES                                                   */
/******************************************************************************/
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

extern VAR(hcs12_context, OS_VAR) idle_task_context;

extern VAR(tpl_stack_word, OS_VAR)
    stack_zone_of_IdleTask[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

/******************************************************************************/
/* DECLARATION OF FUNCTIONS                                                   */
/******************************************************************************/
#define OS_START_SEC_CODE
#include "Memmap.h"

/*******************************************************************************
** Function name: Os_CounterBaseTickCallback
** Description: This function can be called to start thebase timer of the Os
** Parameter : None
** Return value:  None
** Remarks:
*******************************************************************************/
extern FUNC(void, OS_CODE) Os_S12X_StartBaseTimer(void);

#define OS_STOP_SEC_CODE
#include "Memmap.h"

/* TPL_MACHINE_HCS12_H */
#endif
