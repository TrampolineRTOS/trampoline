/*=============================================================================
**                             AYRTON TECHNOLOGY
**                      Proprietary - Copyright (C) 2007
**-----------------------------------------------------------------------------
** Customer          : Internal
** Project           : O4A (06-01-BEE-055)
**-----------------------------------------------------------------------------
** Supported MCUs    : Freescale MC9S12XEP100
**-----------------------------------------------------------------------------
** File name         : tpl_machine_HCS12X.c
**
** Module name       : tpl_machine_HCS12X
**
**
** Summary: functions of the OS specifics for the MCU S12X that can be 
**          implemented in C
**
**= History ===================================================================
** 00.01  J.Monsimier	04/11/07 
** - creation
=============================================================================*/

/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "tpl_machine.h"
#include "tpl_os_it.h"
#include "tpl_os_it_kernel.h"
#include "tpl_machine_interface.h"

 
/******************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                            */
/******************************************************************************/
#define   OS_START_SEC_VAR_UNSPECIFIED
#include  "Memmap.h"

tpl_stack_word stack_zone_of_IdleTask[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];

hcs12_context idle_task_context;

#define   OS_STOP_SEC_VAR_UNSPECIFIED
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
void tpl_init_context(tpl_exec_common *exec_obj)
{
	hcs12_context *ic = exec_obj->static_desc->context.ic;
  
  /* initialises the registers to 0 */
  ic->d = 0;
  ic->x = 0;
  ic->y = 0;
  
  /* initialises the stack pointer of the task to 
    start address + stack size = end of stack zone */
  ic->sp = ((uint16)exec_obj->static_desc->stack.stack_zone)
	               + exec_obj->static_desc->stack.stack_size -2;
                 
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
tpl_exec_function idle_function = tpl_sleep;

void tpl_init_machine(void)
{ 
  /* configure the idle task */
  
  /* initialises the CCR with 0: all flags reset */
  idle_task_context.ccr = 0;
  
  /* initialises the registers to 0 */
  idle_task_context.d = 0;
  idle_task_context.x = 0;
  idle_task_context.y = 0;
  
  /* initialises the stack pointer of the idle task to 
    start address + stack size = end of stack zone */
  idle_task_context.sp = (uint16)((&stack_zone_of_IdleTask)
	               + SIZE_OF_IDLE_STACK -2);
                 
  /* initialises the programm counter to the 
    sleep function base address */               
  idle_task_context.pc = idle_function;
}
#define OS_STOP_SEC_CODE
#include "Memmap.h"



