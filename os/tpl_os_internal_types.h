/**
 * @file tpl_os_internal_types.h
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 * @section descr File description
 *
 * Trampoline internal types. These types are not intended to be used in an application.
 *
 */

#ifndef __TPL_OS_INTERNAL_TYPES_H__
#define __TPL_OS_INTERNAL_TYPES_H__

#include "tpl_os_custom_types.h"
#include "tpl_os_types.h"
#include "tpl_machine.h"

/**
 * @def ECC1
 *
 * identifies the ECC1 conformance class
 *
 * @see #CONFORMANCE_CLASS
 */
#define ECC1 1

/**
 * @def ECC2
 *
 * identifies the ECC2 conformance class
 *
 * @see #CONFORMANCE_CLASS
 */
#define ECC2 2

/**
 * @def CONFORMANCE_CLASS
 *
 * represents the configured conformance class
 *
 * @warning at this time, Trampoline only supports ECC2
 */
#define CONFORMANCE_CLASS ECC2

/**************************************
 * Special result code for Trampoline *
 **************************************/

/**
 * @def NO_SPECIAL_CODE
 *
 * Nothing particular to Trampoline in this code.
 *
 * @note This is a Trampoline result code, not an OSEK one.
 *
 * @see #tpl_status
 */
#define NO_SPECIAL_CODE         0

/**
 * @def NEED_RESCHEDULING
 *
 * Scheduler have to be called, probably because the ready list
 * has changed.
 *
 * @note This is a Trampoline result code, not an OSEK one.
 *
 * @see #tpl_status
 */
#define NEED_RESCHEDULING       32

/**
 * @def E_OK_AND_SCHEDULE
 *
 * Combines OSEK-E_OK and Trampoline-NEED_RESCHEDULING result codes
 *
 * @see #tpl_status
 */
#define E_OK_AND_SCHEDULE       (E_OK | NEED_RESCHEDULING)

/**
 * @def OSEK_STATUS_MASK
 *
 * This AND mask can be used to keep only result code
 * specific to OSEK in a tpl_status (StatusType)
 * result code.
 *
 * @see #tpl_status
 */
#define OSEK_STATUS_MASK        0x1F

/**
 * @def TRAMPOLINE_STATUS_MASK
 *
 * This AND mask can be used to keep only result code
 * specific to Trampoline in a tpl_status (StatusType)
 * result code.
 *
 * @see #tpl_status
 */
#define TRAMPOLINE_STATUS_MASK  0xE0

/************************
 * Forward declarations *
 ************************/
struct TPL_TASK;
struct TPL_RESOURCE;

/**
 * @typedef tpl_exec_obj_type 
 * This type is used to distinguish kind
 * of tasks and ISR
 *
 * @see #tpl_is_basic
 * @see #tpl_is_extended
 * @see #tpl_is_full_preemptable
 * @see #tpl_is_non_preemptable
 * @see #tpl_is_isr
 */
typedef unsigned char tpl_exec_obj_type;
 
/**
 * @typedef tpl_exec_state
 *
 * This type represents the state of a task.
 *
 * See page 16+ of the OSEK/VDX spec
 *
 * Value can be one of :
 * - #AUTOSTART
 * - #RUNNING
 * - #READY
 * - #SUSPENDED
 * - #WAITING (only for ECC1 or ECC2 conformance classes)
 */
typedef unsigned char tpl_exec_state;

/**
 * @def AUTOSTART
 *
 * Task is automatically activated at system startup
 *
 * @see #tpl_exec_state
 */
#define AUTOSTART   0

/**
 * @def RUNNING
 *
 * Task is currently running
 *
 * @see #tpl_exec_state
 */
#define RUNNING     1

/**
 * @def READY
 *
 * Task is ready (to be run, or elected by scheduler)
 *
 * @see #tpl_exec_state
 */
#define READY       2

/**
 * @def SUSPENDED
 *
 * Task is suspended
 *
 * @see #tpl_exec_state
 */
#define SUSPENDED   3
#if CONFORMANCE_CLASS==ECC1 || CONFORMANCE_CLASS==ECC2
/**
 * @def WAITING
 *
 * Task is waiting
 *
 * @see #tpl_exec_state
 */
#define WAITING     4
#endif

/**
 * @typedef tpl_exec_function
 *
 * This type is used to specify the task entry point (function where the task begins)
 *
 * @see #TPL_EXEC_STATIC
 */
typedef void (*tpl_exec_function)(void);
 
/**
 * @struct TPL_EXEC_STATIC
 *
 * This is a data structure used to describe the members of task descriptors or 
 * category 2 Interrupt Service Routines. Static means this part of the descriptor
 * can be stored in ROM.
 */
struct TPL_EXEC_STATIC {
    tpl_context                     context;            /**< context(s) of the task/isr */
    tpl_stack                       stack;              /**< stack(s) of the task/isr */
    tpl_exec_function               entry;              /**< function that is the entry point of the task/isr */
    struct TPL_INTERNAL_RESOURCE    *internal_resource; /**< pointer to an internal resource. NULL if the task does not have an internal resource */
    tpl_task_id                     id;                 /**< id of task/isr */
    tpl_priority                    base_priority;      /**< base priority of the task/isr  */
    tpl_activate_counter            max_activate_count; /**< max activation count of a task/isr */
    tpl_exec_obj_type               type;               /**< type of the task/isr */
};

/**
 * @typedef tpl_exec_static
 *
 * This is an alias for the #TPL_EXEC_STATIC structure
 *
 * @see #TPL_EXEC_STATIC
 */
typedef struct TPL_EXEC_STATIC tpl_exec_static;

/**
 * @struct TPL_EXEC_COMMON
 *
 * This structure gathers the common members of executable objects dynamic descriptors
 */
struct TPL_EXEC_COMMON {
    tpl_exec_static         *static_desc;   /**<  pointer to static descriptor    */
    struct TPL_RESOURCE     *resources;     /**<  head of the ressources held     */
    struct TPL_EXEC_COMMON  *next_exec;     /**<  next ready exec with same prio  */
    struct TPL_EXEC_COMMON  *next_set;      /**<  next exec set with lower prio   */
    tpl_activate_counter    activate_count; /**<  current activate count          */
    tpl_priority            priority;       /**<  current priority                */
    tpl_exec_state          state;          /**<  state (READY, RUNNING, ...)     */
};

/**
 * @typedef tpl_exec_common
 *
 * This is an alias for the #TPL_EXEC_COMMON structure.
 *
 * @see #TPL_EXEC_COMMON
 */
typedef struct TPL_EXEC_COMMON tpl_exec_common;

/**
 * @struct TPL_TASK
 *
 * This structure glues together a common descriptor
 * and the dynamic members of the task descriptor.
 */
struct TPL_TASK {
    tpl_exec_common         exec_desc;  /**< the common descriptor of the task */
    tpl_event_mask          evt_set;    /**< @todo what's this ? */
    tpl_event_mask          evt_wait;   /**< @todo what's this ? */
};

/**
 * @typedef tpl_task
 *
 * This type is an alias for the #TPL_TASK structure.
 *
 * @see #TPL_TASK
 */
typedef struct TPL_TASK tpl_task;

/**
 * @struct TPL_RESOURCE
 *
 * This structure describes all attributes of a resource
 */
struct TPL_RESOURCE {
    tpl_priority            ceiling_priority;     /**< Ceiling priority as computed at system generation time. */
    tpl_priority            owner_prev_priority;  /**< Priority of the owner before accessing to the resource.
                                                       This field is used to restore the priority of the task when
                                                       the resource is released */
    struct TPL_EXEC_COMMON  *owner;               /**< Owner of the resource or NULL if the resource is not owned */
    struct TPL_RESOURCE     *next_res;            /**< Pointer to the next resource used to link them together when
                                                       a task get more than one resource */
};

/**
 * @typedef tpl_resource
 *
 * This type is an alias for the structure #TPL_RESOURCE.
 *
 * @see #TPL_RESOURCE
 */
typedef struct TPL_RESOURCE tpl_resource;

/**
 * @struct TPL_INTERNAL_RESOURCE
 *
 * This is is the internal resource descriptor structure. It is a simpler structure than
 * tpl_resource since only one internal resource can be taken and there is no need to store
 * the owner
 */
struct TPL_INTERNAL_RESOURCE {
    
    tpl_priority            ceiling_priority;    /**<  Ceiling priority as computed at system generation time */
    tpl_priority            owner_prev_priority; /**<  Priority of the owner prior to the access to the resource.
                                                       this field is used to restore the priority of the task when
                                                       the resource is released */
    bool                    taken;               /**<  Flag to tell if the internal resource is taken or not */
};

/**
 * @typedef tpl_internal_resource
 *
 * This is an alias for the structure #TPL_INTERNAL_RESOURCE
 *
 * @see #TPL_INTERNAL_RESOURCE
 */
typedef struct TPL_INTERNAL_RESOURCE tpl_internal_resource;

/**
 * @typedef tpl_alarm_state
 *
 * Describes an alarm state. Value can be one of :
 * - #ALARM_SLEEP
 * - #ALARM_ACTIVE
 * - #ALARM_AUTOSTART
 * - #ALARM_CALLBACK
 * - #ALARM_TASK_ACTIVATION
 * - #ALARM_EVENT_SETTING
 */
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
