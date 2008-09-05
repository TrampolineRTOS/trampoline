#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"
#include "tpl_machine.h"
#include "tpl_os_it.h"
#include "tpl_os_it_kernel.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_action.h"
#include "tpl_os_kernel.h"

#ifndef WITH_AUTOSAR
#ifndef WITH_NOCOM
#include "tpl_com_notification.h"
#include "tpl_com_mo.h"
#include "tpl_com_internal_com.h"
#include "tpl_com_external_com.h"
#include "tpl_com_app_copy.h"
#include "tpl_com_filters.h"
#endif
#endif

#include "tpl_os_generated_configuration.h"
#include "tpl_app_objects.h"

#ifdef WITH_AUTOSAR
#include "tpl_as_st_kernel.h"
#include "tpl_as_action.h"
#include "tpl_as_isr_kernel.h"
#endif

/* #include "Application_types.h" */

/*=============================================================================
 * Definition and initialization of event related defines and structures
 */


/*=============================================================================
 * Definition and initialization of Resource related structures
 */

/*
 * Resource descriptor of resource r1
 *
 * Tasks which use this resource :
 * $TASKS$
 *
 * ISRs which use this resource :
 * $ISRS$
 */
tpl_resource descriptor_of_resource_r1 = {
    /* ceiling priority of the resource */  (tpl_priority)2,
    /* owner previous priority          */  (tpl_priority)0,
    /* owner of the resource            */  NULL_PTR,
    /* next resource in the list        */  NULL_PTR
};


tpl_resource *tpl_resource_table[RESOURCE_COUNT] = {
    (tpl_resource *)&descriptor_of_resource_r1
};


/*=============================================================================
 * Definition and initialization of Task related defines and structures
 */

/*
 * periodicTask stack
 */
tpl_stack_word stack_zone_of_periodicTask[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_periodicTask { stack_zone_of_periodicTask, 32768 }

/*
 * periodicTask context
 */
tpl_context integer_context_of_periodicTask;

#define CONTEXT_OF_TASK_periodicTask &integer_context_of_periodicTask

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Task periodicTask function prototype
 */
void function_of_task_periodicTask(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Timing protection descriptor for $NAME$
 */
tpl_time task_periodicTask_rez_lock_time[1] = {
    1000
};
 
tpl_timing_protection task_periodicTask_timing_prot = {
    /* execution budget/time    */  100,
    /* time frame               */  1000,
    /* resource lock time       */  task_periodicTask_rez_lock_time,
    /* os interrupt lock time   */  1000,
    /* all interrupt lock time  */  1000
};


#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif


#define OS_START_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Static descriptor of task periodicTask
 */
CONST(tpl_exec_static, OS_CONST) static_descriptor_of_task_periodicTask = {
    /* context                  */  CONTEXT_OF_TASK_periodicTask,
    /* stack                    */  STACK_OF_TASK_periodicTask,
    /* entry point (function)   */  function_of_task_periodicTask,
    /* internal ressource       */  NULL_PTR,
    /* task id                  */  task_id_of_periodicTask,
    /* task base priority       */  (tpl_priority)1,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  &task_periodicTask_timing_prot
#endif
};

#define OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task periodicTask
 */
tpl_task descriptor_of_task_periodicTask = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_periodicTask,
    /* resources            */  NULL_PTR,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)1,
    /* task state           */  SUSPENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* activation allowed   */  TRUE,
#endif
    },    /* end of exec_desc part */
    /* event mask           */  0,
    /* event wait           */  0
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * r1_squatter stack
 */
tpl_stack_word stack_zone_of_r1_squatter[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_r1_squatter { stack_zone_of_r1_squatter, 32768 }

/*
 * r1_squatter context
 */
tpl_context integer_context_of_r1_squatter;

#define CONTEXT_OF_TASK_r1_squatter &integer_context_of_r1_squatter

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Task r1_squatter function prototype
 */
void function_of_task_r1_squatter(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Timing protection descriptor for $NAME$
 */
tpl_time task_r1_squatter_rez_lock_time[1] = {
    100
};
 
tpl_timing_protection task_r1_squatter_timing_prot = {
    /* execution budget/time    */  1000,
    /* time frame               */  10000,
    /* resource lock time       */  task_r1_squatter_rez_lock_time,
    /* os interrupt lock time   */  1000,
    /* all interrupt lock time  */  1000
};


#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif


#define OS_START_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Static descriptor of task r1_squatter
 */
CONST(tpl_exec_static, OS_CONST) static_descriptor_of_task_r1_squatter = {
    /* context                  */  CONTEXT_OF_TASK_r1_squatter,
    /* stack                    */  STACK_OF_TASK_r1_squatter,
    /* entry point (function)   */  function_of_task_r1_squatter,
    /* internal ressource       */  NULL_PTR,
    /* task id                  */  task_id_of_r1_squatter,
    /* task base priority       */  (tpl_priority)2,
    /* max activation count     */  1,
    /* task type                */  TASK_BASIC,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  &task_r1_squatter_timing_prot
#endif
};

#define OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task r1_squatter
 */
tpl_task descriptor_of_task_r1_squatter = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_r1_squatter,
    /* resources            */  NULL_PTR,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)2,
    /* task state           */  SUSPENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* activation allowed   */  TRUE,
#endif
    },    /* end of exec_desc part */
    /* event mask           */  0,
    /* event wait           */  0
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
tpl_task *tpl_task_table[TASK_COUNT] = {
    (tpl_task *)&descriptor_of_task_periodicTask,
    (tpl_task *)&descriptor_of_task_r1_squatter
};


/*=============================================================================
 * Definition and initialization of ISR2 related defines and structures
 */

#if ISR_COUNT > 0
#include <signal.h>

int signal_for_isr_id[] = {

};
#endif


/*=============================================================================
 * Definition and initialization of Counters related defines and structures
 */

/*
 * Counter descriptor of counter counter100ms
 */
tpl_counter descriptor_of_counter_counter100ms = {
    /* ticks per base       */  2,
    /* max allowed value    */  255,
    /* minimum cycle        */  1,
    /* current tick         */  0,
    /* current date         */  0,
#ifdef WITH_AUTOSAR
    /* kind the counter     */  HARDWARE_COUNTER,
#endif
    /* first alarm          */  NULL_PTR,
    /* next alarm to raise  */  NULL_PTR
};

#include <tpl_os_kernel.h>        //tpl_schedule
#include <tpl_os_alarm_kernel.h> //tpl_counter_tick

void tpl_call_counter_tick()
{
	tpl_status  need_rescheduling = NO_SPECIAL_CODE;
    need_rescheduling |= tpl_counter_tick(&descriptor_of_counter_counter100ms);

	if (need_rescheduling == NEED_RESCHEDULING) {
		tpl_schedule(FROM_IT_LEVEL);
    }
}

tpl_counter *tpl_counter_table[1] = {
    &descriptor_of_counter_counter100ms
};


/*=============================================================================
 * Definition and initialization of Alarm related structures
 */

/*
 * Alarm descriptor of alarm alarm1s
 */
tpl_task_activation_action task_act_of_alarm1s = {
    {
        /* action function  */  tpl_action_activate_task
    },
    /* task descriptor ptr  */  &descriptor_of_task_periodicTask
};

tpl_alarm_static stat_descriptor_of_alarm_alarm1s = {
    {
        /* pointer to counter           */  &descriptor_of_counter_counter100ms,
        /* pointer to the expiration    */  tpl_raise_alarm
    },
    /* action of the alarm  */  (tpl_action *)&task_act_of_alarm1s
};

tpl_time_obj descriptor_of_alarm_alarm1s = {
    /* pointer to the static part   */  (tpl_time_obj_static *)&stat_descriptor_of_alarm_alarm1s,
    /* next alarm                   */  NULL_PTR,
    /* prev alarm                   */  NULL_PTR,
    /* cycle                        */  20,
    /* date                         */  1,
    /* State of the alarm           */  ALARM_AUTOSTART
};

/*
 * Alarm descriptor of alarm alarm200ms
 */
tpl_task_activation_action task_act_of_alarm200ms = {
    {
        /* action function  */  tpl_action_activate_task
    },
    /* task descriptor ptr  */  &descriptor_of_task_r1_squatter
};

tpl_alarm_static stat_descriptor_of_alarm_alarm200ms = {
    {
        /* pointer to counter           */  &descriptor_of_counter_counter100ms,
        /* pointer to the expiration    */  tpl_raise_alarm
    },
    /* action of the alarm  */  (tpl_action *)&task_act_of_alarm200ms
};

tpl_time_obj descriptor_of_alarm_alarm200ms = {
    /* pointer to the static part   */  (tpl_time_obj_static *)&stat_descriptor_of_alarm_alarm200ms,
    /* next alarm                   */  NULL_PTR,
    /* prev alarm                   */  NULL_PTR,
    /* cycle                        */  4,
    /* date                         */  1,
    /* State of the alarm           */  ALARM_AUTOSTART
};

/*
 * Alarm descriptor of alarm alarmevent
 */
 
tpl_setevent_action set_event_of_alarmevent = {
    {
        /* action function  */  tpl_action_setevent
    },
    /* task descriptor ptr  */  &descriptor_of_task_periodicTask,
    /* event mask           */  mask_of_evt1
};

tpl_alarm_static stat_descriptor_of_alarm_alarmevent = {
    {
        /* pointer to counter           */  &descriptor_of_counter_counter100ms,
        /* pointer to the expiration    */  tpl_raise_alarm
    },
    /* action of the alarm  */  (tpl_action *)&set_event_of_alarmevent
};

tpl_time_obj descriptor_of_alarm_alarmevent = {
    /* pointer to the static part   */  (tpl_time_obj_static *)&stat_descriptor_of_alarm_alarmevent,
    /* next alarm                   */  NULL_PTR,
    /* prev alarm                   */  NULL_PTR,
    /* cycle                        */  10,
    /* date                         */  1,
    /* State of the alarm           */  ALARM_AUTOSTART
};

tpl_time_obj *tpl_alarm_table[ALARM_COUNT] = {
    (tpl_time_obj *)&descriptor_of_alarm_alarm1s,
    (tpl_time_obj *)&descriptor_of_alarm_alarm200ms,
    (tpl_time_obj *)&descriptor_of_alarm_alarmevent
};


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

#endif

/*=============================================================================
 * Definition and initialization of Ready List structures
 */
tpl_exec_common *tpl_priority_0_fifo[1];
tpl_exec_common *tpl_priority_1_fifo[1];
tpl_exec_common *tpl_priority_2_fifo[3];

tpl_fifo_state tpl_fifo_rw[3] = {
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 }
};

tpl_priority_level tpl_ready_list[3] = {
    { tpl_priority_0_fifo , 1 },
    { tpl_priority_1_fifo , 1 },
    { tpl_priority_2_fifo , 3 }
};



/*
#if CRC_LEVEL > 0
$CRC_TABLE$
#endif
*/

/* End of file tpl_os_generated_configuration.c */
