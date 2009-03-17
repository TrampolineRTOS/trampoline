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
** File name         : tpl_machine.h
**
** Module name       : OS
**
** Summary:   context and task types specific for the target
**
**= History ====================================================================
** 01.04  J.Monsimier 03/12/07
**  - creation
==============================================================================*/

#ifndef TPL_MACHINE_V850E_H
#define TPL_MACHINE_V850E_H

/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "Std_Types.h"
#include "tpl_os_custom_types.h"

/******************************************************************************/
/* DEFINITION OF CONSTANTS                                                    */
/******************************************************************************/
#define IDLE_CONTEXT &idle_task_context

#define SIZE_OF_IDLE_STACK  200

#define IDLE_STACK { stack_zone_of_IdleTask, SIZE_OF_IDLE_STACK }


/******************************************************************************/
/* DEFINITION OF TYPES                                                        */
/******************************************************************************/
typedef P2FUNC(void, OS_APPL_CODE, tpl_function_pointer)(void);

typedef struct
{
  VAR(uint32, AUTOMATIC) Rn[32];            /* Global Registers               */
  VAR(uint32, AUTOMATIC) EIPC;              /* EIPC Register                  */
  VAR(uint32, AUTOMATIC) EIPSW;             /* EIPSW Register                 */
  VAR(uint32, AUTOMATIC) FEPC;              /* FEPC Register                  */
  VAR(uint32, AUTOMATIC) FEPSW;             /* FEPSW Register                 */
  VAR(uint32, AUTOMATIC) PSW;               /* Programm Status Register       */
  VAR(uint32, AUTOMATIC) PC;                /* Programm Status Register       */
} v850e_context;

typedef struct
{
  P2VAR(v850e_context, OS_APPL_DATA, AUTOMATIC) ic;
} tpl_context;

typedef struct
{
  P2VAR(tpl_stack_word, OS_APPL_DATA, AUTOMATIC)  stack_zone;
  VAR(tpl_stack_size, AUTOMATIC)                  stack_size;
} tpl_stack;


/******************************************************************************/
/* DEFINITION OF MACROS                                                       */
/******************************************************************************/
#define E_OS_MISSINGEND 35

/******************************************************************************/
/* DECLARATION OF VARIABLES                                                   */
/******************************************************************************/
#define OS_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

extern VAR(v850e_context, OS_VAR) idle_task_context;

extern VAR(tpl_stack_word, OS_VAR)
    stack_zone_of_IdleTask[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"



/* TPL_MACHINE_V850E_H */
#endif
