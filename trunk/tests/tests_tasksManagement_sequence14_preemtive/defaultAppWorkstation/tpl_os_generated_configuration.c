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
tpl_context integer_context_of_t1;

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
    /* context                  */  CONTEXT_OF_TASK_t1,
    /* stack                    */  STACK_OF_TASK_t1,
    /* entry point (function)   */  function_of_task_t1,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t1,
    /* task base priority       */  (tpl_priority)16,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
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
    /* task priority        */  (tpl_priority)16,
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
 * t10 stack
 */
tpl_stack_word stack_zone_of_t10[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t10 { stack_zone_of_t10, 32768 }

/*
 * t10 context
 */
tpl_context integer_context_of_t10;

#define CONTEXT_OF_TASK_t10 &integer_context_of_t10
/*
 * Task t10 function prototype
 */
void function_of_task_t10(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t10
 */
tpl_exec_static static_descriptor_of_task_t10 = {
    /* context                  */  CONTEXT_OF_TASK_t10,
    /* stack                    */  STACK_OF_TASK_t10,
    /* entry point (function)   */  function_of_task_t10,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t10,
    /* task base priority       */  (tpl_priority)7,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t10
 */
tpl_task descriptor_of_task_t10 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t10,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)7,
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
 * t11 stack
 */
tpl_stack_word stack_zone_of_t11[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t11 { stack_zone_of_t11, 32768 }

/*
 * t11 context
 */
tpl_context integer_context_of_t11;

#define CONTEXT_OF_TASK_t11 &integer_context_of_t11
/*
 * Task t11 function prototype
 */
void function_of_task_t11(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t11
 */
tpl_exec_static static_descriptor_of_task_t11 = {
    /* context                  */  CONTEXT_OF_TASK_t11,
    /* stack                    */  STACK_OF_TASK_t11,
    /* entry point (function)   */  function_of_task_t11,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t11,
    /* task base priority       */  (tpl_priority)6,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t11
 */
tpl_task descriptor_of_task_t11 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t11,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)6,
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
 * t12 stack
 */
tpl_stack_word stack_zone_of_t12[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t12 { stack_zone_of_t12, 32768 }

/*
 * t12 context
 */
tpl_context integer_context_of_t12;

#define CONTEXT_OF_TASK_t12 &integer_context_of_t12
/*
 * Task t12 function prototype
 */
void function_of_task_t12(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t12
 */
tpl_exec_static static_descriptor_of_task_t12 = {
    /* context                  */  CONTEXT_OF_TASK_t12,
    /* stack                    */  STACK_OF_TASK_t12,
    /* entry point (function)   */  function_of_task_t12,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t12,
    /* task base priority       */  (tpl_priority)5,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t12
 */
tpl_task descriptor_of_task_t12 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t12,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)5,
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
 * t13 stack
 */
tpl_stack_word stack_zone_of_t13[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t13 { stack_zone_of_t13, 32768 }

/*
 * t13 context
 */
tpl_context integer_context_of_t13;

#define CONTEXT_OF_TASK_t13 &integer_context_of_t13
/*
 * Task t13 function prototype
 */
void function_of_task_t13(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t13
 */
tpl_exec_static static_descriptor_of_task_t13 = {
    /* context                  */  CONTEXT_OF_TASK_t13,
    /* stack                    */  STACK_OF_TASK_t13,
    /* entry point (function)   */  function_of_task_t13,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t13,
    /* task base priority       */  (tpl_priority)4,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t13
 */
tpl_task descriptor_of_task_t13 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t13,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)4,
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
 * t14 stack
 */
tpl_stack_word stack_zone_of_t14[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t14 { stack_zone_of_t14, 32768 }

/*
 * t14 context
 */
tpl_context integer_context_of_t14;

#define CONTEXT_OF_TASK_t14 &integer_context_of_t14
/*
 * Task t14 function prototype
 */
void function_of_task_t14(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t14
 */
tpl_exec_static static_descriptor_of_task_t14 = {
    /* context                  */  CONTEXT_OF_TASK_t14,
    /* stack                    */  STACK_OF_TASK_t14,
    /* entry point (function)   */  function_of_task_t14,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t14,
    /* task base priority       */  (tpl_priority)3,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t14
 */
tpl_task descriptor_of_task_t14 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t14,
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


/*
 * t15 stack
 */
tpl_stack_word stack_zone_of_t15[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t15 { stack_zone_of_t15, 32768 }

/*
 * t15 context
 */
tpl_context integer_context_of_t15;

#define CONTEXT_OF_TASK_t15 &integer_context_of_t15
/*
 * Task t15 function prototype
 */
void function_of_task_t15(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t15
 */
tpl_exec_static static_descriptor_of_task_t15 = {
    /* context                  */  CONTEXT_OF_TASK_t15,
    /* stack                    */  STACK_OF_TASK_t15,
    /* entry point (function)   */  function_of_task_t15,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t15,
    /* task base priority       */  (tpl_priority)2,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t15
 */
tpl_task descriptor_of_task_t15 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t15,
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
 * t16 stack
 */
tpl_stack_word stack_zone_of_t16[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t16 { stack_zone_of_t16, 32768 }

/*
 * t16 context
 */
tpl_context integer_context_of_t16;

#define CONTEXT_OF_TASK_t16 &integer_context_of_t16
/*
 * Task t16 function prototype
 */
void function_of_task_t16(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t16
 */
tpl_exec_static static_descriptor_of_task_t16 = {
    /* context                  */  CONTEXT_OF_TASK_t16,
    /* stack                    */  STACK_OF_TASK_t16,
    /* entry point (function)   */  function_of_task_t16,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t16,
    /* task base priority       */  (tpl_priority)1,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t16
 */
tpl_task descriptor_of_task_t16 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t16,
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


/*
 * t2 stack
 */
tpl_stack_word stack_zone_of_t2[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t2 { stack_zone_of_t2, 32768 }

/*
 * t2 context
 */
tpl_context integer_context_of_t2;

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
    /* context                  */  CONTEXT_OF_TASK_t2,
    /* stack                    */  STACK_OF_TASK_t2,
    /* entry point (function)   */  function_of_task_t2,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t2,
    /* task base priority       */  (tpl_priority)15,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
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
    /* task priority        */  (tpl_priority)15,
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
tpl_context integer_context_of_t3;

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
    /* context                  */  CONTEXT_OF_TASK_t3,
    /* stack                    */  STACK_OF_TASK_t3,
    /* entry point (function)   */  function_of_task_t3,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t3,
    /* task base priority       */  (tpl_priority)14,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
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
    /* task priority        */  (tpl_priority)14,
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
 * t4 stack
 */
tpl_stack_word stack_zone_of_t4[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t4 { stack_zone_of_t4, 32768 }

/*
 * t4 context
 */
tpl_context integer_context_of_t4;

#define CONTEXT_OF_TASK_t4 &integer_context_of_t4
/*
 * Task t4 function prototype
 */
void function_of_task_t4(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t4
 */
tpl_exec_static static_descriptor_of_task_t4 = {
    /* context                  */  CONTEXT_OF_TASK_t4,
    /* stack                    */  STACK_OF_TASK_t4,
    /* entry point (function)   */  function_of_task_t4,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t4,
    /* task base priority       */  (tpl_priority)13,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t4
 */
tpl_task descriptor_of_task_t4 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t4,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)13,
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
 * t5 stack
 */
tpl_stack_word stack_zone_of_t5[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t5 { stack_zone_of_t5, 32768 }

/*
 * t5 context
 */
tpl_context integer_context_of_t5;

#define CONTEXT_OF_TASK_t5 &integer_context_of_t5
/*
 * Task t5 function prototype
 */
void function_of_task_t5(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t5
 */
tpl_exec_static static_descriptor_of_task_t5 = {
    /* context                  */  CONTEXT_OF_TASK_t5,
    /* stack                    */  STACK_OF_TASK_t5,
    /* entry point (function)   */  function_of_task_t5,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t5,
    /* task base priority       */  (tpl_priority)12,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t5
 */
tpl_task descriptor_of_task_t5 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t5,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)12,
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
 * t6 stack
 */
tpl_stack_word stack_zone_of_t6[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t6 { stack_zone_of_t6, 32768 }

/*
 * t6 context
 */
tpl_context integer_context_of_t6;

#define CONTEXT_OF_TASK_t6 &integer_context_of_t6
/*
 * Task t6 function prototype
 */
void function_of_task_t6(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t6
 */
tpl_exec_static static_descriptor_of_task_t6 = {
    /* context                  */  CONTEXT_OF_TASK_t6,
    /* stack                    */  STACK_OF_TASK_t6,
    /* entry point (function)   */  function_of_task_t6,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t6,
    /* task base priority       */  (tpl_priority)11,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t6
 */
tpl_task descriptor_of_task_t6 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t6,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)11,
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
 * t7 stack
 */
tpl_stack_word stack_zone_of_t7[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t7 { stack_zone_of_t7, 32768 }

/*
 * t7 context
 */
tpl_context integer_context_of_t7;

#define CONTEXT_OF_TASK_t7 &integer_context_of_t7
/*
 * Task t7 function prototype
 */
void function_of_task_t7(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t7
 */
tpl_exec_static static_descriptor_of_task_t7 = {
    /* context                  */  CONTEXT_OF_TASK_t7,
    /* stack                    */  STACK_OF_TASK_t7,
    /* entry point (function)   */  function_of_task_t7,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t7,
    /* task base priority       */  (tpl_priority)10,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t7
 */
tpl_task descriptor_of_task_t7 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t7,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)10,
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
 * t8 stack
 */
tpl_stack_word stack_zone_of_t8[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t8 { stack_zone_of_t8, 32768 }

/*
 * t8 context
 */
tpl_context integer_context_of_t8;

#define CONTEXT_OF_TASK_t8 &integer_context_of_t8
/*
 * Task t8 function prototype
 */
void function_of_task_t8(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t8
 */
tpl_exec_static static_descriptor_of_task_t8 = {
    /* context                  */  CONTEXT_OF_TASK_t8,
    /* stack                    */  STACK_OF_TASK_t8,
    /* entry point (function)   */  function_of_task_t8,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t8,
    /* task base priority       */  (tpl_priority)9,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t8
 */
tpl_task descriptor_of_task_t8 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t8,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)9,
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
 * t9 stack
 */
tpl_stack_word stack_zone_of_t9[32768/sizeof(tpl_stack_word)];

#define STACK_OF_TASK_t9 { stack_zone_of_t9, 32768 }

/*
 * t9 context
 */
tpl_context integer_context_of_t9;

#define CONTEXT_OF_TASK_t9 &integer_context_of_t9
/*
 * Task t9 function prototype
 */
void function_of_task_t9(void);

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

#endif

/*
 * Static descriptor of task t9
 */
tpl_exec_static static_descriptor_of_task_t9 = {
    /* context                  */  CONTEXT_OF_TASK_t9,
    /* stack                    */  STACK_OF_TASK_t9,
    /* entry point (function)   */  function_of_task_t9,
    /* internal ressource       */  FULL_PREEMPTABLE_TASK,
    /* task id                  */  task_id_of_t9,
    /* task base priority       */  (tpl_priority)8,
    /* max activation count     */  1,
    /* task type                */  TASK_EXTENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  NULL
#endif
};

/*
 * Dynamic descriptor of task t9
 */
tpl_task descriptor_of_task_t9 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &static_descriptor_of_task_t9,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)8,
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
    (tpl_task *)&descriptor_of_task_t10,
    (tpl_task *)&descriptor_of_task_t11,
    (tpl_task *)&descriptor_of_task_t12,
    (tpl_task *)&descriptor_of_task_t13,
    (tpl_task *)&descriptor_of_task_t14,
    (tpl_task *)&descriptor_of_task_t15,
    (tpl_task *)&descriptor_of_task_t16,
    (tpl_task *)&descriptor_of_task_t2,
    (tpl_task *)&descriptor_of_task_t3,
    (tpl_task *)&descriptor_of_task_t4,
    (tpl_task *)&descriptor_of_task_t5,
    (tpl_task *)&descriptor_of_task_t6,
    (tpl_task *)&descriptor_of_task_t7,
    (tpl_task *)&descriptor_of_task_t8,
    (tpl_task *)&descriptor_of_task_t9
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
tpl_exec_common *tpl_priority_1_fifo[1];
tpl_exec_common *tpl_priority_2_fifo[1];
tpl_exec_common *tpl_priority_3_fifo[1];
tpl_exec_common *tpl_priority_4_fifo[1];
tpl_exec_common *tpl_priority_5_fifo[1];
tpl_exec_common *tpl_priority_6_fifo[1];
tpl_exec_common *tpl_priority_7_fifo[1];
tpl_exec_common *tpl_priority_8_fifo[1];
tpl_exec_common *tpl_priority_9_fifo[1];
tpl_exec_common *tpl_priority_10_fifo[1];
tpl_exec_common *tpl_priority_11_fifo[1];
tpl_exec_common *tpl_priority_12_fifo[1];
tpl_exec_common *tpl_priority_13_fifo[1];
tpl_exec_common *tpl_priority_14_fifo[1];
tpl_exec_common *tpl_priority_15_fifo[1];
tpl_exec_common *tpl_priority_16_fifo[2];

tpl_fifo_state tpl_fifo_rw[17] = {
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 },
    { 0 , 0 }
};

tpl_priority_level tpl_ready_list[17] = {
    { tpl_priority_0_fifo , 1 },
    { tpl_priority_1_fifo , 1 },
    { tpl_priority_2_fifo , 1 },
    { tpl_priority_3_fifo , 1 },
    { tpl_priority_4_fifo , 1 },
    { tpl_priority_5_fifo , 1 },
    { tpl_priority_6_fifo , 1 },
    { tpl_priority_7_fifo , 1 },
    { tpl_priority_8_fifo , 1 },
    { tpl_priority_9_fifo , 1 },
    { tpl_priority_10_fifo , 1 },
    { tpl_priority_11_fifo , 1 },
    { tpl_priority_12_fifo , 1 },
    { tpl_priority_13_fifo , 1 },
    { tpl_priority_14_fifo , 1 },
    { tpl_priority_15_fifo , 1 },
    { tpl_priority_16_fifo , 2 }
};



/* End of file tpl_os_generated_configuration.c */
