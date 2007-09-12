#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"
#include "tpl_machine.h"
#include "tpl_os_it.h"
#include "tpl_os_it_kernel.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_action.h"
#include "tpl_com_notification.h"
#include "tpl_com_mo.h"
#include "tpl_com_internal_com.h"
#include "tpl_com_app_copy.h"
#include "tpl_com_filters.h"

#include "tpl_os_generated_configuration.h"
#include "tpl_app_objects.h"

#ifdef WITH_AUTOSAR
#include "tpl_as_st_kernel.h"
#endif

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
    /* ceiling priority of the resource */  (tpl_priority)1,
    /* owner previous priority          */  (tpl_priority)0,
    /* owner of the resource            */  NULL,
    /* next resource in the list        */  NULL
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
/*
 * Task periodicTask function prototype
 */
void function_of_task_periodicTask(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
/*
 * Timing protection descriptor for $NAME$
 */
tpl_time task_periodicTask_rez_lock_time[1] = {
    1000000
};
 
tpl_timing_protection task_periodicTask_timing_prot = {
    /* execution budget/time    */  10,
    /* time limit               */  0,
    /* time frame               */  100,
    /* resource lock time       */  task_periodicTask_rez_lock_time,
    /* os interrupt lock time   */  1000000,
    /* all interrupt lock time  */  1000000
};


#endif

/*
 * Static descriptor of task periodicTask
 */
tpl_exec_static static_descriptor_of_task_periodicTask = {
    /* context                  */  CONTEXT_OF_TASK_periodicTask,
    /* stack                    */  STACK_OF_TASK_periodicTask,
    /* entry point (function)   */  function_of_task_periodicTask,
    /* internal ressource       */  NULL,
    /* task id                  */  task_id_of_periodicTask,
    /* task base priority       */  (tpl_priority)1,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  &task_periodicTask_timing_prot
#endif
};

/*
 * Dynamic descriptor of task periodicTask
 */
tpl_task descriptor_of_task_periodicTask = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_periodicTask,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)1,
    /* task state           */  SUSPENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* start date           */  0,
    /* time left            */  0,
#endif
    },    /* end of exec_desc part */
    /* event mask           */  0,
    /* event wait           */  0
};


tpl_task *tpl_task_table[TASK_COUNT] = {
    (tpl_task *)&descriptor_of_task_periodicTask
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
    /* first alarm          */  NULL,
    /* next alarm to raise  */  NULL
};


void tpl_schedule(int from);
tpl_status tpl_counter_tick(tpl_counter *counter);

void tpl_call_counter_tick()
{
	tpl_status  need_rescheduling = NO_SPECIAL_CODE;
    need_rescheduling |= tpl_counter_tick(&descriptor_of_counter_counter100ms);

	if (need_rescheduling == NEED_RESCHEDULING) {
		tpl_schedule(FROM_IT_LEVEL);
    }
}



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
    /* next alarm                   */  NULL,
    /* prev alarm                   */  NULL,
    /* cycle                        */  20,
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
    /* next alarm                   */  NULL,
    /* prev alarm                   */  NULL,
    /* cycle                        */  10,
    /* date                         */  1,
    /* State of the alarm           */  ALARM_AUTOSTART
};

tpl_time_obj *tpl_alarm_table[ALARM_COUNT] = {
    (tpl_time_obj *)&descriptor_of_alarm_alarm1s,
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
tpl_schedule_table *tpl_schedtable_table[0] = {
};

#endif

/*=============================================================================
 * Definition and initialization of Ready List structures
 */
tpl_exec_common *tpl_priority_0_fifo[1];
tpl_exec_common *tpl_priority_1_fifo[2];

tpl_fifo_state tpl_fifo_rw[2] = {
    { 0 , 0 },
    { 0 , 0 }
};

tpl_priority_level tpl_ready_list[2] = {
    { tpl_priority_0_fifo , 1 },
    { tpl_priority_1_fifo , 2 }
};



/* End of file tpl_os_generated_configuration.c */
