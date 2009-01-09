#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"
#include "tpl_machine.h"
#include "tpl_os_it.h"
#include "tpl_os_it_kernel.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_action.h"

#ifndef WITH_AUTOSAR
#include "tpl_com_notification.h"
#include "tpl_com_mo.h"
#include "tpl_com_internal_com.h"
#include "tpl_com_app_copy.h"
#include "tpl_com_filters.h"
#endif

#include "tpl_os_generated_configuration.h"
#include "tpl_app_objects.h"

#ifdef WITH_AUTOSAR
#include "tpl_as_st_kernel.h"
#include "tpl_as_action.h"
#endif

/*=============================================================================
 * Definition and initialization of event related defines and structures
 */


/*=============================================================================
 * Definition and initialization of Resource related structures
 */



/*=============================================================================
 * Definition and initialization of Task related defines and structures
 */


/*
 * t1 stack
 */
tpl_stack_word stack_zone_of_t1[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t1 { stack_zone_of_t1, 32768 } 

/*
 * t1 context
 */
arm7_context integer_context_of_t1;

#define CONTEXT_OF_TASK_t1 &integer_context_of_t1
/*
 * Task t1 function prototype
 */
void function_of_task_t1(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t1
 */
tpl_exec_static static_descriptor_of_task_t1 = {
    /* context                  */  {CONTEXT_OF_TASK_t1},
    /* stack                    */  STACK_OF_TASK_t1,
    /* entry point (function)   */  function_of_task_t1,
    /* internal ressource       */  NON_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t1,
    /* task base priority       */  (tpl_priority)1,
    /* max activation count     */  1,
    /* task type                */  TASK_BASIC,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION

    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t1
 */
tpl_task descriptor_of_task_t1 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t1,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)1,
    /* task state           */  AUTOSTART,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* start date           */  0,
    /* time left            */  0,
#endif
    },    /* end of exec_desc part */
    /* event mask           */  0,
    /* event wait           */  0
};


/*
 * t2 stack
 */
tpl_stack_word stack_zone_of_t2[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t2 { stack_zone_of_t2, 32768 } 

/*
 * t2 context
 */
arm7_context integer_context_of_t2;

#define CONTEXT_OF_TASK_t2 &integer_context_of_t2
/*
 * Task t2 function prototype
 */
void function_of_task_t2(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t2
 */
tpl_exec_static static_descriptor_of_task_t2 = {
    /* context                  */  {CONTEXT_OF_TASK_t2},
    /* stack                    */  STACK_OF_TASK_t2,
    /* entry point (function)   */  function_of_task_t2,
    /* internal ressource       */  NON_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t2,
    /* task base priority       */  (tpl_priority)2,
    /* max activation count     */  1,
    /* task type                */  TASK_BASIC,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION

    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t2
 */
tpl_task descriptor_of_task_t2 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t2,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)2,
    /* task state           */  SUSPENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* start date           */  0,
    /* time left            */  0,
#endif
    },    /* end of exec_desc part */
    /* event mask           */  0,
    /* event wait           */  0
};

/*
 * t3 stack
 */
tpl_stack_word stack_zone_of_t3[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t3 { stack_zone_of_t3, 32768 } 

/*
 * t3 context
 */
arm7_context integer_context_of_t3;

#define CONTEXT_OF_TASK_t3 &integer_context_of_t3
/*
 * Task t3 function prototype
 */
void function_of_task_t3(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t3
 */
tpl_exec_static static_descriptor_of_task_t3 = {
    /* context                  */  {CONTEXT_OF_TASK_t3},
    /* stack                    */  STACK_OF_TASK_t3,
    /* entry point (function)   */  function_of_task_t3,
    /* internal ressource       */  NON_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t3,
    /* task base priority       */  (tpl_priority)3,
    /* max activation count     */  1,
    /* task type                */  TASK_BASIC,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION

    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t3
 */
tpl_task descriptor_of_task_t3 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t3,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)3,
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
    (tpl_task *)&descriptor_of_task_t1,
    (tpl_task *)&descriptor_of_task_t2,
    (tpl_task *)&descriptor_of_task_t3
};


/*=============================================================================
 * Definition and initialization of ISR2 related defines and structures
 */


/*
 * isr1 stack
 */
tpl_stack_word stack_zone_of_isr1[32768/sizeof(tpl_stack_word)];

#define STACK_OF_ISR_isr1 { stack_zone_of_isr1, 32768 }

/*
 * isr1 context
 */
tpl_context integer_context_of_isr1;

#define CONTEXT_OF_ISR_isr1 &integer_context_of_isr1
/*
 * ISR isr1 function prototype
 */
void function_of_isr_isr1(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of ISR isr1
 */
tpl_exec_static static_descriptor_of_isr_isr1 = {
    /* context                  */ CONTEXT_OF_ISR_isr1,
    /* stack                    */ STACK_OF_ISR_isr1,
    /* entry point (function)   */ function_of_isr_isr1,
    /* internal ressource       */ NULL,
    /* isr id                   */ 0,
    /* isr base priority        */ (tpl_priority)1,
    /* max activation count     */ 1,
    /* isr type                 */ IS_ROUTINE,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

tpl_isr_static static_helper_of_isr_isr1 = {
	/* helper */ NULL,
	/* next */   NULL
};

/*
 * Dynamic descriptor of ISR isr1
 */
tpl_isr descriptor_of_isr_isr1 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_isr_isr1,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* isr priority         */  (tpl_priority)1,
    /* isr state            */  SUSPENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* start date           */  0,
    /* time left            */  0,
#endif
    },    /* end of exec_desc part */
    /* more static desc     */  &static_helper_of_isr_isr1
#ifdef WITH_AUTOSAR
    ,
    /* enabled field        */  TRUE
#endif
};

/*
 * isr2 stack
 */
tpl_stack_word stack_zone_of_isr2[32768/sizeof(tpl_stack_word)];

#define STACK_OF_ISR_isr2 { stack_zone_of_isr2, 32768 }

/*
 * isr2 context
 */
tpl_context integer_context_of_isr2;

#define CONTEXT_OF_ISR_isr2 &integer_context_of_isr2
/*
 * ISR isr2 function prototype
 */
void function_of_isr_isr2(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of ISR isr2
 */
tpl_exec_static static_descriptor_of_isr_isr2 = {
    /* context                  */ CONTEXT_OF_ISR_isr2,
    /* stack                    */ STACK_OF_ISR_isr2,
    /* entry point (function)   */ function_of_isr_isr2,
    /* internal ressource       */ NULL,
    /* isr id                   */ 0,
    /* isr base priority        */ (tpl_priority)2,
    /* max activation count     */ 1,
    /* isr type                 */ IS_ROUTINE,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

tpl_isr_static static_helper_of_isr_isr2 = {
	/* helper */ NULL,
	/* next */   NULL
};

/*
 * Dynamic descriptor of ISR isr2
 */
tpl_isr descriptor_of_isr_isr2 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_isr_isr2,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* isr priority         */  (tpl_priority)2,
    /* isr state            */  SUSPENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* start date           */  0,
    /* time left            */  0,
#endif
    },    /* end of exec_desc part */
    /* more static desc     */  &static_helper_of_isr_isr2
#ifdef WITH_AUTOSAR
    ,
    /* enabled field        */  TRUE
#endif
};


tpl_isr *tpl_isr_table[ISR_COUNT] = {
    (tpl_isr *)&descriptor_of_isr_isr1,
    (tpl_isr *)&descriptor_of_isr_isr2
};
#if ISR_COUNT > 0
#include <signal.h>

int signal_for_isr_id[] = {
	NULL
};
#endif

/*=============================================================================
 * Definition and initialization of Counters related defines and structures
 */

void tpl_schedule(int from);
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
#endif

/*=============================================================================
 * Definition and initialization of Ready List structures
 */
tpl_exec_common *tpl_priority_0_fifo[1];
tpl_exec_common *tpl_priority_1_fifo[4];
tpl_exec_common *tpl_priority_2_fifo[2];
tpl_exec_common *tpl_priority_3_fifo[2];
tpl_exec_common *tpl_priority_4_fifo[5];

tpl_fifo_state tpl_fifo_rw[5] = {
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 }
};

tpl_priority_level tpl_ready_list[5] = {
    { tpl_priority_0_fifo , 1 },
    { tpl_priority_1_fifo , 4 },
    { tpl_priority_2_fifo , 2 },
    { tpl_priority_3_fifo , 2 },
    { tpl_priority_4_fifo , 5 }
};



/* End of file tpl_os_generated_configuration.c */
