/**
 * @file tpl_machine.h
 *
 * @section desc File description
 *
 * functions of the OS specifics for the MCU S12X.
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

#ifndef TPL_MACHINE_HCS12_H
#define TPL_MACHINE_HCS12_H

/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "tpl_os_custom_types.h"

/******************************************************************************/
/* DEFINITION OF CONSTANTS                                                    */
/******************************************************************************/
#define IDLE_CONTEXT { &idle_task_context }

#define SIZE_OF_IDLE_STACK  100

#define IDLE_STACK { stack_zone_of_IdleTask, SIZE_OF_IDLE_STACK }

/******************************************************************************/
/* DEFINITION OF TYPES                                                        */
/******************************************************************************/
typedef P2FUNC(void, OS_APPL_CODE, tpl_function_pointer)(void);

typedef struct
{
  VAR(u16, TYPEDEF) ccr;                 /* condition code register                */
  VAR(u16, TYPEDEF) d;                   /* double accumulator D (or acc A and B)  */
  VAR(u16, TYPEDEF) x;                   /* index register X                       */
  VAR(u16, TYPEDEF) y;                   /* index register Y                       */
  VAR(tpl_function_pointer, TYPEDEF) pc; /* program counter                        */
  VAR(u16, TYPEDEF) sp;                  /* stack pointer                          */
} hcs12_context;

typedef struct
{
  P2VAR(hcs12_context, AUTOMATIC, OS_APPL_DATA) ic;
} tpl_context;

typedef struct
{
  P2VAR(tpl_stack_word, TYPEDEF, OS_APPL_DATA)  stack_zone;
  VAR(tpl_stack_size, TYPEDEF)                  stack_size;
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

extern FUNC(void, GPT_CODE) tpl_watchdog_callback(void);
extern FUNC(void, OS_CODE)  tpl_inc_time(void);

#define OS_STOP_SEC_CODE
#include "Memmap.h"

/* TPL_MACHINE_HCS12_H */
#endif
