#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"
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

/*#ifndef WITH_AUTOSAR*/
#ifndef WITH_NOCOM
#include "tpl_com_notification.h"
#include "tpl_com_mo.h"
#include "tpl_com_internal.h"
#include "tpl_com_internal_com.h"
#include "tpl_com_external_com.h"
#include "tpl_com_app_copy.h"
#include "tpl_com_filters.h"
#endif
/*#endif*/

#include "tpl_os_generated_configuration.h"
#include "tpl_app_objects.h"

#ifdef WITH_AUTOSAR
#include "tpl_as_schedtable.h"
#include "tpl_as_st_kernel.h"
#include "tpl_as_action.h"
#include "tpl_as_isr_kernel.h"
#include "tpl_as_counter.h"
#include "tpl_as_app_kernel.h"
#endif

/* #include "Application_types.h" */

/*=============================================================================
 * Declaration of event masks
 */


/*=============================================================================
 * Declaration of Resource IDs
 */


/*=============================================================================
 * Declaration of Task IDs
 */
#define t1_id  0
CONST(TaskType, AUTOMATIC) t1 = t1_id;
#define t2_id  1
CONST(TaskType, AUTOMATIC) t2 = t2_id;
#define isr1_id  2
#define isr2_id  3


/*=============================================================================
 * Declaration of Alarm IDs
 */


/*=============================================================================
 * Declaration of Counter IDs
 */
#ifdef WITH_AUTOSAR

#endif

/*=============================================================================
 * Declaration of messages IDs
 */




/*=============================================================================
 * Declaration of Scheduletables IDs
 */
#ifdef WITH_AUTOSAR
$SCHEDTABLEIDS$
#endif

/*=============================================================================
 * Declaration of OS Application IDs
 */
#ifdef WITH_AUTOSAR
$OSAPPIDS$
#endif

/*=============================================================================
 * Definition and initialization of Resource related structures
 */

CONSTP2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA)
  tpl_resource_table[RESOURCE_COUNT] = {
  &res_sched_rez_desc
};


/*=============================================================================
 * Definition and initialization of Task related defines and structures
 */
extern tpl_internal_resource INTERNAL_RES_SCHEDULER;


/*
 * task t1 stack
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_stack_word t1_stack[32768/sizeof(tpl_stack_word)];

#define t1_STACK { t1_stack, 32768 }

/*
 * task t1 context
 */
arm7_context t1_int_context;

#define t1_CONTEXT { &t1_int_context, NULL }

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Task t1 function prototype
 */
void t1_function(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif


#define OS_START_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Static descriptor of task t1
 */
CONST(tpl_proc_static, OS_CONST) t1_task_stat_desc = {
    /* context                  */  t1_CONTEXT,
    /* stack                    */  t1_STACK,
    /* entry point (function)   */  t1_function,
    /* internal ressource       */  &INTERNAL_RES_SCHEDULER,
    /* task id                  */  t1_id,
#ifdef WITH_OSAPPLICATION
    /* OS application id        */  $APP_ID$,
#endif
    /* task base priority       */  1,
    /* max activation count     */  1,
    /* task type                */  TASK_BASIC,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

#define OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task t1
 */
VAR(tpl_proc, OS_VAR) t1_task_desc = {
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)1,
    /* task state           */  AUTOSTART
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* activation allowed   */  ,TRUE
#endif
};



#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * task t2 stack
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_stack_word t2_stack[32768/sizeof(tpl_stack_word)];

#define t2_STACK { t2_stack, 32768 }

/*
 * task t2 context
 */
arm7_context t2_int_context;

#define t2_CONTEXT { &t2_int_context, NULL }

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Task t2 function prototype
 */
void t2_function(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif


#define OS_START_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Static descriptor of task t2
 */
CONST(tpl_proc_static, OS_CONST) t2_task_stat_desc = {
    /* context                  */  t2_CONTEXT,
    /* stack                    */  t2_STACK,
    /* entry point (function)   */  t2_function,
    /* internal ressource       */  &INTERNAL_RES_SCHEDULER,
    /* task id                  */  t2_id,
#ifdef WITH_OSAPPLICATION
    /* OS application id        */  $APP_ID$,
#endif
    /* task base priority       */  2,
    /* max activation count     */  1,
    /* task type                */  TASK_BASIC,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

#define OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task t2
 */
VAR(tpl_proc, OS_VAR) t2_task_desc = {
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)2,
    /* task state           */  SUSPENDED
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* activation allowed   */  ,TRUE
#endif
};



#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Definition and initialization of ISR2 related defines and structures
 */

/*
 * isr isr1 stack
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_stack_word isr1_stack[32768/sizeof(tpl_stack_word)];

#define isr1_STACK { isr1_stack, 32768 }

/*
 * isr isr1 context
 */
arm7_context isr1_int_context;

#define isr1_CONTEXT { &isr1_int_context, NULL }

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * ISR isr1 function prototype
 */
void isr1_function(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif


#define OS_START_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Static descriptor of ISR isr1
 */
CONST(tpl_proc_static, OS_CONST) isr1_isr_stat_desc = {
    /* context                  */ isr1_CONTEXT,
    /* stack                    */ isr1_STACK,
    /* entry point (function)   */ isr1_function,
    /* internal ressource       */ NULL,
    /* isr id                   */ isr1_id,
    /* isr base priority        */ (tpl_priority)3,
    /* max activation count     */ 1,
    /* isr type                 */ IS_ROUTINE,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

#define OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_isr_static isr1_isr_helper = {
  /* helper */ NULL,
  /* next */   NULL,
  /* id */     isr1_id
};

/*
 * Dynamic descriptor of ISR isr1
 */
VAR(tpl_proc, OS_VAR) isr1_isr_desc = {
    /* resources            */  NULL,
    /* activate count       */  0,
    /* isr priority         */  (tpl_priority)3,
    /* isr state            */  SUSPENDED
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* activation allowed   */  ,TRUE
#endif
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*
 * isr isr2 stack
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_stack_word isr2_stack[32768/sizeof(tpl_stack_word)];

#define isr2_STACK { isr2_stack, 32768 }

/*
 * isr isr2 context
 */
arm7_context isr2_int_context;

#define isr2_CONTEXT { &isr2_int_context, NULL }

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * ISR isr2 function prototype
 */
void isr2_function(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif


#define OS_START_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Static descriptor of ISR isr2
 */
CONST(tpl_proc_static, OS_CONST) isr2_isr_stat_desc = {
    /* context                  */ isr2_CONTEXT,
    /* stack                    */ isr2_STACK,
    /* entry point (function)   */ isr2_function,
    /* internal ressource       */ NULL,
    /* isr id                   */ isr2_id,
    /* isr base priority        */ (tpl_priority)3,
    /* max activation count     */ 1,
    /* isr type                 */ IS_ROUTINE,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

#define OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_isr_static isr2_isr_helper = {
  /* helper */ NULL,
  /* next */   NULL,
  /* id */     isr2_id
};

/*
 * Dynamic descriptor of ISR isr2
 */
VAR(tpl_proc, OS_VAR) isr2_isr_desc = {
    /* resources            */  NULL,
    /* activate count       */  0,
    /* isr priority         */  (tpl_priority)3,
    /* isr state            */  SUSPENDED
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* activation allowed   */  ,TRUE
#endif
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
 

/*=============================================================================
 * Definition and initialization of process tables (tasks and isrs)
 */
#if (TASK_COUNT != 0) || (ISR_COUNT != 0)

CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1] = {
  &t1_task_stat_desc,
  &t2_task_stat_desc,
  &isr1_isr_stat_desc,
  &isr2_isr_stat_desc,
  &idle_task_static
};


CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA)
tpl_dyn_proc_table[TASK_COUNT+ISR_COUNT+1] = {
  &t1_task_desc,
  &t2_task_desc,
  &isr1_isr_desc,
  &isr2_isr_desc,
  &idle_task
};


#if EXTENDED_TASK_COUNT > 0
CONSTP2VAR(tpl_task_events, AUTOMATIC, OS_APPL_DATA)
tpl_task_events_table[EXTENDED_TASK_COUNT] = {

};
#endif

#if ISR_COUNT > 0
CONSTP2CONST(tpl_isr_static, AUTOMATIC, OS_APPL_DATA)
tpl_isr_stat_table[ISR_COUNT] = {
  &isr1_isr_helper,
  &isr2_isr_helper
};

#ifdef WITH_AUTOSAR
VAR(tpl_isr2_enable_state, OS_VAR)
tpl_isr2_enable_table[ISR_COUNT] = {
  ENABLED,
  ENABLED
};
#endif

#endif

#endif
 
/*=============================================================================
 * Definition and initialization of Counters related defines and structures
 */

tpl_status tpl_counter_tick(tpl_counter *counter);

void tpl_call_counter_tick()
{
	tpl_status  need_rescheduling = NO_SPECIAL_CODE;

	if (need_rescheduling == NEED_RESCHEDULING) {
		tpl_schedule(FROM_IT_LEVEL);
    }
}



/*=============================================================================
 * Definition and initialization of Alarm related structures
 */



/*=============================================================================
 * Declaration of flags functions
 */


/*=============================================================================
 * Definition and initialization of Messages related structures
 */




#ifdef WITH_AUTOSAR
/*=============================================================================
 * Declaration of schedule tables related defines and structures
 */
$SCHEDULETABLES$

/*=============================================================================
 * Declaration of OS applications related defines and structures
 */
$OSAPPLICATIONS$
#endif

/*=============================================================================
 * Definition and initialization of Ready List structures
 */
tpl_proc_id tpl_priority_0_fifo[1];
tpl_proc_id tpl_priority_1_fifo[1];
tpl_proc_id tpl_priority_2_fifo[2];
tpl_proc_id tpl_priority_3_fifo[2];

tpl_fifo_state tpl_fifo_rw[4] = {
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 }
};

tpl_priority_level tpl_ready_list[4] = {
    { tpl_priority_0_fifo , 1 },
    { tpl_priority_1_fifo , 1 },
    { tpl_priority_2_fifo , 2 },
    { tpl_priority_3_fifo , 2 }
};



#if !defined(NO_TASK) || !defined(NO_ISR)
char *proc_name_table[TASK_COUNT + ISR_COUNT] = {
  "t1",
  "t2",
  "isr1",
  "isr2",
};
#endif

/*
#if CRC_LEVEL > 0
$CRC_TABLE$
#endif
*/

/* End of file tpl_os_generated_configuration.c */
