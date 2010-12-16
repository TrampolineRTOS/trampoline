/**
 * @file tpl_app_config.c
 *
 * @section desc File description
 *
 * OS data structure generated from application test
 * Automatically generated by goil on Thu Dec 16 15:37:05 2010
 * from root OIL file lonely.oil
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

#include "tpl_app_config.h"

#include "tpl_os_internal_types.h"
#include "tpl_machine.h"
#include "tpl_os_it.h"
#include "tpl_os_it_kernel.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_alarm.h"
#include "tpl_os_rez_kernel.h"
#include "tpl_os_rez.h"
#include "tpl_os_event_kernel.h"
#include "tpl_os_event.h"
#include "tpl_os_action.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"


#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Declaration of processes IDs
 */

/* Task task1 identifier */
#define task1_id 0
CONST(TaskType, AUTOMATIC) task1 = task1_id;

/* Task task2 identifier */
#define task2_id 1
CONST(TaskType, AUTOMATIC) task2 = task2_id;

/* Task task3 identifier */
#define task3_id 2
CONST(TaskType, AUTOMATIC) task3 = task3_id;

#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONSTP2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA)
tpl_resource_table[RESOURCE_COUNT] = {
  &res_sched_rez_desc  
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*=============================================================================
 * Definition and initialization of Counters related defines and structures
 */
/*-----------------------------------------------------------------------------
 * Counter SystemCounter descriptor
 */

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_tick, OS_CONST) OSTICKSPERBASE = 1;
CONST(tpl_tick, OS_CONST) OSMAXALLOWEDVALUE = 32767;
CONST(tpl_tick, OS_CONST) OSMINCYCLE = 1;

#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_counter, OS_VAR) SystemCounter_counter_desc = {
  /* ticks per base       */  1,
  /* max allowed value    */  32767,
  /* minimum cycle        */  1,
  /* current tick         */  0,
  /* current date         */  0,
#if WITH_OSAPPLICATION == YES
    /* OS Application id    */  
#endif
    /* first alarm          */  NULL_PTR,
    /* next alarm to raise  */  NULL_PTR
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#include "tpl_os_kernel.h"          /* tpl_schedule */
#include "tpl_os_timeobj_kernel.h"  /* tpl_counter_tick */
#include "tpl_machine_interface.h"  /* tpl_switch_context_from_it */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#include <stm_regs.h>

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/*=============================================================================
 * Definition and initialization of Task related defines and structures
 */
/*-----------------------------------------------------------------------------
 * Task task1 descriptor
 */
#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Task task1 function prototype
 */
FUNC(void, OS_APPL_CODE) task1_function(void);
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */
/*
 * Task task1 stack
 */
#define APP_Task_task1_START_SEC_STACK
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_APPL_DATA) task1_stack_zone[50/sizeof(tpl_stack_word)];
#define APP_Task_task1_STOP_SEC_STACK
#include "tpl_memmap.h"

#define task1_STACK {task1_stack_zone, 50}

/*
 * Task task1 context
 */
#define OS_START_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"
VAR(arm_context, OS_VAR) task1_int_context;

#define task1_CONTEXT &task1_int_context

#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"



#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif

/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task task1
 */
CONST(tpl_proc_static, OS_CONST) task1_task_stat_desc = {
  /* context                  */  task1_CONTEXT,
  /* stack                    */  task1_STACK,
  /* entry point (function)   */  task1_function,
  /* internal ressource       */  NULL,
  /* task id                  */  task1_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  1,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
  /* pointer to the timing
     protection descriptor    */  $TIMING_PROT_REF$
#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task task1
 */
VAR(tpl_proc, OS_VAR) task1_task_desc = {
  /* resources                      */  NULL,
#if WITH_MEMORY_PROTECTION == YES
  /* if > 0 the process is trusted  */  0,    
#endif /* WITH_MEMORY_PROTECTION */
  /* activate count                 */  0,
  /* task priority                  */  1,
  /* task state                     */  AUTOSTART
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Task task2 descriptor
 */
#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Task task2 function prototype
 */
FUNC(void, OS_APPL_CODE) task2_function(void);
#define APP_Task_task2_STOP_SEC_CODE
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */
/*
 * Task task2 stack
 */
#define APP_Task_task2_START_SEC_STACK
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_APPL_DATA) task2_stack_zone[50/sizeof(tpl_stack_word)];
#define APP_Task_task2_STOP_SEC_STACK
#include "tpl_memmap.h"

#define task2_STACK {task2_stack_zone, 50}

/*
 * Task task2 context
 */
#define OS_START_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"
VAR(arm_context, OS_VAR) task2_int_context;

#define task2_CONTEXT &task2_int_context

#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"



#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif

/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task task2
 */
CONST(tpl_proc_static, OS_CONST) task2_task_stat_desc = {
  /* context                  */  task2_CONTEXT,
  /* stack                    */  task2_STACK,
  /* entry point (function)   */  task2_function,
  /* internal ressource       */  NULL,
  /* task id                  */  task2_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  2,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
  /* pointer to the timing
     protection descriptor    */  $TIMING_PROT_REF$
#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task task2
 */
VAR(tpl_proc, OS_VAR) task2_task_desc = {
  /* resources                      */  NULL,
#if WITH_MEMORY_PROTECTION == YES
  /* if > 0 the process is trusted  */  0,    
#endif /* WITH_MEMORY_PROTECTION */
  /* activate count                 */  0,
  /* task priority                  */  2,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Task task3 descriptor
 */
#define APP_Task_task3_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Task task3 function prototype
 */
FUNC(void, OS_APPL_CODE) task3_function(void);
#define APP_Task_task3_STOP_SEC_CODE
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */
/*
 * Task task3 stack
 */
#define APP_Task_task3_START_SEC_STACK
#include "tpl_memmap.h"
VAR(tpl_stack_word, OS_APPL_DATA) task3_stack_zone[50/sizeof(tpl_stack_word)];
#define APP_Task_task3_STOP_SEC_STACK
#include "tpl_memmap.h"

#define task3_STACK {task3_stack_zone, 50}

/*
 * Task task3 context
 */
#define OS_START_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"
VAR(arm_context, OS_VAR) task3_int_context;

#define task3_CONTEXT &task3_int_context

#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"



#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif

/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task task3
 */
CONST(tpl_proc_static, OS_CONST) task3_task_stat_desc = {
  /* context                  */  task3_CONTEXT,
  /* stack                    */  task3_STACK,
  /* entry point (function)   */  task3_function,
  /* internal ressource       */  NULL,
  /* task id                  */  task3_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  3,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
  /* pointer to the timing
     protection descriptor    */  $TIMING_PROT_REF$
#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task task3
 */
VAR(tpl_proc, OS_VAR) task3_task_desc = {
  /* resources                      */  NULL,
#if WITH_MEMORY_PROTECTION == YES
  /* if > 0 the process is trusted  */  0,    
#endif /* WITH_MEMORY_PROTECTION */
  /* activate count                 */  0,
  /* task priority                  */  3,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#include "tpl_machine.h"

/* Interrupt functions */

#define OS_START_SEC_CODE
#include "stm_regs.h"

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*=============================================================================
 * Definition and initialization of process tables (tasks and isrs)
 */
CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1] = {
  &task1_task_stat_desc,
  &task2_task_stat_desc,
  &task3_task_stat_desc,
  &idle_task_static
};

CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA)
tpl_dyn_proc_table[TASK_COUNT+ISR_COUNT+1] = {
  &task1_task_desc,
  &task2_task_desc,
  &task3_task_desc,
  &idle_task
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*=============================================================================
 * Declaration of flags functions
 */
/* $FLAGSFUNCTIONS$ */


/*=============================================================================
 * Definition and initialization of Ready List structures
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_proc_id, OS_VAR) tpl_priority_0_fifo[1];
VAR(tpl_proc_id, OS_VAR) tpl_priority_1_fifo[1];
VAR(tpl_proc_id, OS_VAR) tpl_priority_2_fifo[1];
VAR(tpl_proc_id, OS_VAR) tpl_priority_3_fifo[2];

VAR(tpl_fifo_state, OS_VAR) tpl_fifo_rw[4] = {
  { 0 , 0 },
  { 0 , 0 },
  { 0 , 0 },
  { 0 , 0 }
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_priority_level, OS_CONST) tpl_ready_list[4] = {
  { tpl_priority_0_fifo, 1 },
  { tpl_priority_1_fifo, 1 },
  { tpl_priority_2_fifo, 1 },
  { tpl_priority_3_fifo, 2 }
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONSTP2CONST(char, AUTOMATIC, OS_APPL_DATA) proc_name_table[TASK_COUNT + ISR_COUNT] = {
  "task1",
  "task2",
  "task3"
};
#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/* End of file tpl_app_config.c */
