/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline internal types
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#ifndef __TPL_OS_INTERNAL_TYPES_H__
#define __TPL_OS_INTERNAL_TYPES_H__

#include "tpl_os_types.h"
#include "tpl_machine.h"

#define ECC1 1
#define ECC2 2

#define CONFORMANCE_CLASS ECC2

/*
 * Forward declarations
 */
struct TPL_TASK;
struct TPL_RESOURCE;

/*
 * standard bool declaration
 */
typedef unsigned char bool;

/*
 * tpl_status_type is used for return
 * status of services (ie one of the result
 * codes specified below).
 */
typedef unsigned char tpl_status;

/*
 * tpl_exec_obj_type is used to distinguish kind
 * of tasks and isr
 */
typedef unsigned char tpl_exec_obj_type;
 
/*
 * tpl_exec_state is the state of a task
 * See page 16+ of the OSEK/VDX spec
 */
#define AUTOSTART   0
#define RUNNING     1
#define READY       2
#define SUSPENDED   3
#if CONFORMANCE_CLASS==ECC1 || CONFORMANCE_CLASS==ECC2
#define WAITING     4
#endif

typedef unsigned char tpl_exec_state;

/*
 * Function pointer prototype for tasks
 */
typedef void (*tpl_exec_function)(void);
 
/*
 * tpl_exec_static is a data structure used
 * to describe the members of task descriptors or 
 * isr2 handlers that may be stored in ROM
 */
struct TPL_EXEC_STATIC {
    /*  context(s) of the task/isr                                                              */
    tpl_context                     context;
    /*  stack(s) of the task/isr                                                                */
    tpl_stack                       stack;
    /*  function of the task/isr                                                                */
    tpl_exec_function               entry;
    /*  pointer to an internal resource. NULL if the task does not have an internal resource    */
    struct TPL_INTERNAL_RESOURCE    *internal_resource;
    /*  id of task/isr                                                                          */
    tpl_task_id                     id;
    /*  base priority of the task/isr                                                           */
    tpl_priority                    base_priority;
    /*  max activation count of a task/isr                                                      */
    tpl_activate_counter            max_activate_count;
    /*  type of the task/isr                                                                    */
    tpl_exec_obj_type               type;           
};

typedef struct TPL_EXEC_STATIC tpl_exec_static;

/*
 * tpl_exec_common gathers the common members
 * of executable objects dynamic descriptors
 */
struct TPL_EXEC_COMMON {
    tpl_exec_static         *static_desc;   /*  pointer to static descriptor    */
    struct TPL_RESOURCE     *resources;     /*  head of the ressources held     */
    struct TPL_EXEC_COMMON  *next_exec;     /*  next ready exec with same prio  */
    struct TPL_EXEC_COMMON  *next_set;      /*  next exec set with lower prio   */
    tpl_activate_counter    activate_count; /*  current activate count          */
    tpl_priority            priority;       /*  current priority                */
    tpl_exec_state          state;          /*  state (READY, RUNNING, ...)     */
};

typedef struct TPL_EXEC_COMMON tpl_exec_common;

/*
 * tpl_task glues together a common descriptor
 * and the dynamic members of the task descriptor.
 */
struct TPL_TASK {
    tpl_exec_common         exec_desc;
    tpl_event_mask          evt_set;
    tpl_event_mask          evt_wait;
};

typedef struct TPL_TASK tpl_task;

/*
 * tpl_resource is the resource descriptor
 * structure
 */
struct TPL_RESOURCE {
    /*  Ceiling priority as computed at system generation time.         */
    tpl_priority            ceiling_priority;
    /*  Priority of the owner prior to the access to the resource.
        this field is used to restore the priority of the task when
        the resource is released                                        */
    tpl_priority            owner_prev_priority;
    /*  Owner of the resource or NULL if the resource is not owned      */
    struct TPL_EXEC_COMMON  *owner;
    /*  Pointer to the next resource used to link them together when
        a task get more than one resource                               */
    struct TPL_RESOURCE     *next_res;
};

typedef struct TPL_RESOURCE tpl_resource;

/*
 * tpl_internal_resource is the internal resource
 * descriptor structure. It is a simpler structure than
 * the tpl_resource one since only one internal resource can
 * be taken and there is no need to store the owner
 */
struct TPL_INTERNAL_RESOURCE {
    /*  Ceiling priority as computed at system generation time          */
    tpl_priority            ceiling_priority;
    /*  Priority of the owner prior to the access to the resource.
        this field is used to restore the priority of the task when
        the resource is released                                        */
    tpl_priority            owner_prev_priority;
    /*  Flag to state the internal resource is taken or not             */
    bool                    taken;
};

typedef struct TPL_INTERNAL_RESOURCE tpl_internal_resource;

/*
 * tpl_callback_func is used for various
 * callback function type in the os
 */
typedef void (*tpl_callback_func)(void);


typedef unsigned char tpl_alarm_state;
typedef  int tpl_alarm_kind;

struct TPL_ALARM_ACTION {
    union {
        tpl_callback_func   callback;
        tpl_task            *task;      }   task_or_callback;
    tpl_event_mask                          mask;
};

typedef struct TPL_ALARM_ACTION tpl_alarm_action;

struct TPL_COUNTER;

/*
 * tpl_alarm is the data structure
 * used to describe an alarm.
 */
struct TPL_ALARM {
    tpl_alarm_state     state;          /*  state of the alarm. An alarm
                                            may have 2 states: ALARM_SLEEP
                                            and ALARM_ACTIVE                */
    tpl_alarm_kind      kind;           /*  kind of the alarm. An alarm may
                                            be of 3 kind: ALARM_CALLBACK,
                                            ALARM_TASK_ACTIVATION and
                                            ALARM_EVENT_SETTING             */
    tpl_alarm_action    action;         /*  action to be done when the
                                            alarm is raised according to
                                            kind                            */
    struct TPL_COUNTER  *counter;       /*  a pointer to the counter the
                                            alarm belongs to                */
    tpl_tick            cycle;          /*  cycle delay for cyclic alarms   */
    tpl_tick            date;           /*  absolute date of the alarm      */
    struct TPL_ALARM    *next_alarm;    /*  next alarm in the active
                                            alarm list                      */
    struct TPL_ALARM    *prev_alarm;    /*  previous alarm in the active
                                            alarm list                      */
};

typedef struct TPL_ALARM tpl_alarm;

/*
 * tpl_counter is the data structure
 * used to describe a counter
 */
struct TPL_COUNTER {
    tpl_tick    ticks_per_base;         /*  number of tick until the
                                            counter inc                     */
    tpl_tick    current_tick;           /*  current tick value of the
                                            counter                         */
    tpl_tick    current_date;           /*  current value of the counter    */
    tpl_alarm   *first_alarm;           /*  active alarms list head         */
    tpl_alarm   *next_alarm_to_raise;   /*  next active alarms              */
};

typedef struct TPL_COUNTER tpl_counter;

/*
 * OSEK/VDX API definitions and prototypes
 */
struct ALARM_BASE_TYPE {
    tpl_tick    maxallowedvalue;    /*  see page 62 of OSEK/VDX os spec */
    tpl_tick    ticksperbase;
    tpl_tick    mincycle;
};

typedef struct ALARM_BASE_TYPE tpl_alarm_base;

/*
 * Locks
 */
struct TPL_LOCK {
    tpl_exec_common *taker;
    tpl_exec_common *waiters;
};

typedef struct TPL_LOCK tpl_lock;

typedef unsigned char tpl_application_mode;



#endif
