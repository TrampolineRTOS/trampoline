/*==============================================================================
** Trampoline OS
**
** Trampoline is copyright (c) IRCCyN 2005+
** Copyright ESEO for function and data structures documentation
** Trampoline is protected by the French intellectual property law.
**
** This software is distributed under the Lesser GNU Public Licence
**------------------------------------------------------------------------------
** Supported MCUs    : Freescale MC9S12XEP100
**------------------------------------------------------------------------------
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

#define OS_S12X_STACK_PATERN 0xAA

#define OS_GPTCHANNEL_WATCHDOG 1
#define OS_GPTCHANNEL_TICK     0

/******************************************************************************/
/* DEFINITION OF TYPES                                                        */
/******************************************************************************/
typedef void (*OS_APPL_CODE tpl_function_pointer)(void);

typedef struct
{
  uint16 ccr;                 /* condition code register                */
  uint16 d;                   /* double accumulator D (or acc A and B)  */
  uint16 x;                   /* index register X                       */
  uint16 y;                   /* index register Y                       */
  tpl_function_pointer pc;    /* program counter                        */
  uint16 sp;                  /* stack pointer                          */
} hcs12_context;

typedef struct
{
  hcs12_context * ic;
} tpl_context;

typedef struct
{
  tpl_stack_word  *stack_zone;
  tpl_stack_size  stack_size;
} tpl_stack;


/******************************************************************************/
/* DEFINITION OF MACROS                                                       */
/******************************************************************************/


/******************************************************************************/
/* DECLARATION OF VARIABLES                                                   */
/******************************************************************************/
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Memmap.h"

extern hcs12_context idle_task_context;

extern tpl_stack_word
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
