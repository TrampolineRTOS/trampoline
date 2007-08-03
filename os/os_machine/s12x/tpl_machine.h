/*==============================================================================
**                             AYRTON TECHNOLOGY
**                      Proprietary - Copyright (C) 2005
**------------------------------------------------------------------------------
** Customer          : intern
** Project           : O4A
**------------------------------------------------------------------------------
** Supported MCUs    : Freescale MC9S12H256
**------------------------------------------------------------------------------
** File name         : tpl_machine.h
**
** Module name       : OS
**
** Summary:   context and task types specific for the target
**
**= History ====================================================================
** 00.01  J.Monsimier	04/11/07
** - creation
** 00.01  J-L Bechennec 07/05/07
** - cut line to 80 characters
** - removed __ before and after multiple inclusion symbol definition
**   __ should not be used to avoid clash with symbols defined by compilers
==============================================================================*/
#include "tpl_os_internal_types.h"
#include "Platform_Types.h"
 

#ifndef TPL_MACHINE_HCS12_H
#define TPL_MACHINE_HCS12_H

/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/



/******************************************************************************/
/* DEFINITION OF CONSTANTS                                                    */
/******************************************************************************/
#define IDLE_CONTEXT &idle_task_context 

#define SIZE_OF_IDLE_STACK  100

#define IDLE_STACK { &stack_zone_of_IdleTask, SIZE_OF_IDLE_STACK }

/******************************************************************************/
/* DEFINITION OF TYPES                                                        */
/******************************************************************************/
typedef void (*tpl_function_pointer)(void);

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

/* TPL_MACHINE_HCS12_H */
#endif
