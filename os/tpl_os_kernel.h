/**
 * @file tpl_os_kernel.h
 *
 * @section desc File description
 *
 * Trampoline kernel structures header file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Copyright ESEO for function and data structures documentation
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

#ifndef TPL_OS_KERNEL_H
#define TPL_OS_KERNEL_H

#include "tpl_compiler.h"
#include "tpl_os_internal_types.h"

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#include "tpl_as_timing_protec.h"
/* #include "tpl_as_st_kernel.h" */
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

/**
 * @def INVALID_TASK
 *
 * This value is used to specify an invalid #TaskType
 */
#define INVALID_TASK    (-1)

/**
 * @typedef tpl_os_state
 *
 * States of Trampoline : 
 * - #OS_INIT means initialization
 * - #OS_TASK means running a task
 * - #OS_IDLE means no task running and the OS has nothing else to do
 * - #OS_ISR2 means running a category 2 interrupt service routine
 * - #OS_UNKNOWN means the OS is not in a known state. This should not happen.
 */
typedef u8 tpl_os_state;

/**
 * @def OS_INIT
 *
 * Trampoline is initializing. Trampoline is in this state from the start
 * and until a task get the CPU (#OS_TASK), it goes idle (#OS_IDLE) or an ISR2
 * takes the CPU (#OS_ISR2)
 */
#define OS_INIT     0

/**
 * @def OS_TASK
 *
 * A task is running
 */
#define OS_TASK     1

/**
 * @def OS_IDLE
 *
 * A task is running
 */
#define OS_IDLE     2

/**
 * @def OS_IDLE
 *
 * An ISR2 is running
 */
#define OS_ISR2     3

/**
 * @def OS_INKNOWN
 *
 * The state is unknown. This should not happen.
 */
#define OS_UNKNOWN  4


/**
 * @def SUSPENDED
 *
 * Task is suspended.
 *
 * @see #tpl_exec_state
 */
#define SUSPENDED       0x0

/**
 * @def READY
 *
 * Task is ready (to be run, or elected by scheduler).
 *
 * @see #tpl_exec_state
 */
#define READY           0x1

/**
 * @def RUNNING
 *
 * Task is currently running.
 *
 * @see #tpl_exec_state
 */
#define RUNNING         0x2

#if (CONFORMANCE_CLASS == CONFORM_ECC1) || (CONFORMANCE_CLASS == CONFORM_ECC2)
/**
 * @def WAITING
 *
 * Task is waiting
 *
 * @see #tpl_exec_state
 */
#define WAITING         0x3
#endif

/**
 * @def DYING
 *
 * Task is dying. This is an transient state
 * used to  tell the scheduler the currently
 * running task relinquishes the CPU and its
 * context should not be saved
 *
 * @see #tpl_exec_state
 */
#define DYING           0x7

/**
 * @def RESURRECT
 *
 * Task is resurrecting. This is an transient state
 * used to  tell the scheduler the currently
 * running task relinquishes the CPU,
 * its context should not be saved,
 * it should be put in the ready list like a new task
 *
 * @see #tpl_exec_state
 */
#define RESURRECT       0xB

/**
 * @def AUTOSTART
 *
 * Task is automatically activated at system startup
 *
 * @see #tpl_exec_state
 */
#define AUTOSTART       0x4

/**
 * @def READY_AND_NEW
 *
 * Task is ready and should be initialized when it get the CPU.
 *
 * @see #tpl_exec_state
 */
#define READY_AND_NEW   0x5

/**
 * @typedef tpl_exec_obj_type
 *
 * This type is used to distinguish kind
 * of tasks and ISR
 * - #TASK_BASIC identifies a basic task
 * - #TASK_EXTENDED identifies an extended task
 * - #IS_ROUTINE identifies a category 2 Interrupt Service Routine
 *
 * @see #TPL_EXEC_STATIC
 */
typedef u8 tpl_exec_obj_type;

/**
 * @typedef tpl_exec_function
 *
 * This type is used to specify the task entry point (function where the task
 * begins)
 *
 * @see #TPL_EXEC_STATIC
 */
typedef P2FUNC(void, OS_APPL_CODE, tpl_exec_function)(void);

/**
 * @struct TPL_EXEC_STATIC
 *
 * This is a data structure used to describe the static members of task
 * descriptors or category 2 Interrupt Service Routines. Static means this
 * part of the descriptor can be stored in ROM.
 */
struct TPL_EXEC_STATIC {
    VAR(tpl_context, TYPEDEF)       context;            /**< context(s) of
                                                             the task/isr
                                                             */
    VAR(tpl_stack, TYPEDEF)         stack;              /**< stack(s) of the
                                                             task/isr
                                                             */
    CONST(tpl_exec_function, TYPEDEF)
                                    entry;              /**< function that is
                                                             the entry point
                                                             of the task/isr
                                                             */
    struct P2VAR(TPL_INTERNAL_RESOURCE, TYPEDEF, OS_APPL_DATA)
                                    internal_resource;  /**< pointer to an
                                                             internal resource.
                                                             NULL if the task
                                                             does not have an
                                                             internal resource
                                                             */
    CONST(tpl_task_id, TYPEDEF)     id;                 /**< id of task/isr
                                                             */
    CONST(tpl_priority, TYPEDEF)    base_priority;      /**< base priority of
                                                             the task/isr
                                                             */
    CONST(tpl_activate_counter, TYPEDEF)
                                    max_activate_count; /**< max activation
                                                             count of a
                                                             task/isr
                                                             */
    CONST(tpl_exec_obj_type, TYPEDEF)
                                    type;               /**< type of the
                                                             task/isr
                                                             */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    P2CONST(tpl_timing_protection, TYPEDEF, OS_APPL_CONST)
                                    timing_protection;  /**< timing protection
                                                             configuration
                                                             (can be NULL
                                                             if no timing
                                                             protection is
                                                             needed)
                                                             */
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
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
 * This structure gathers the common members of executable objects dynamic
 * descriptors
 */
struct TPL_EXEC_COMMON {
    P2CONST(tpl_exec_static, TYPEDEF, OS_CONST)
                                    static_desc;        /**< pointer to static
                                                             descriptor
                                                             */
    struct P2VAR(TPL_RESOURCE, TYPEDEF, OS_APPL_DATA)
                                    resources;          /**< head of the
                                                             ressources held
                                                             */
    VAR(tpl_activate_counter, TYPEDEF)
                                    activate_count;     /**< current activate
                                                             count
                                                             */
    VAR(tpl_priority, TYPEDEF)      priority;           /**< current priority
                                                             */
    VAR(tpl_exec_state, TYPEDEF)    state;              /**< state (READY,
                                                             RUNING, ...)
                                                             */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    VAR(tpl_bool, TYPEDEF)          activation_allowed;
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
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
 * @typedef tpl_internal_resource
 *
 * This is is the internal resource descriptor structure. It is a simpler
 * structure than tpl_resource since only one internal resource can be taken
 * and there is no need to store the owner
 */
typedef struct {
    CONST(tpl_priority, TYPEDEF)
                        ceiling_priority;    /**< Ceiling priority as
                                                  computed at system
                                                  generation time
                                                  */
    VAR(tpl_priority, TYPEDEF)
                        owner_prev_priority; /**< Priority of the owner prior
                                                  to the access to the resource.
                                                  This field is used to restore
                                                  the priority of the task when
                                                  the resource is released
                                                  */
    VAR(tpl_bool, TYPEDEF)
                        taken;               /**< Flag to tell if the internal
                                                  resource is taken or not
                                                  */
} tpl_internal_resource;

/**
 * @typedef tpl_fifo_state
 *
 * This type gathers a read index and a size for fifo management
 */
typedef struct {
    VAR(u8, TYPEDEF) read;
    VAR(u8, TYPEDEF) size;
} tpl_fifo_state;

#ifdef WITH_POWEROF2QUEUE

/**
 * @typedef tpl_priority_level
 *
 * This type is a structure used to store the information for a priority
 * level (pointer to a fifo and the mask of the fifo. The mask is used
 * to keep read and write index within the fifo.
 * It is the element of the ready list table.
 */
typedef struct {
    P2VAR(tpl_exec_common, TYPEDEF, OS_APPL_DATA) *fifo;
    VAR(u8, AUTOMATIC) mask;
} tpl_priority_level;

#else /* WITH_POWEROF2QUEUE */

/**
 * @typedef tpl_priority_level
 *
 * This type is a structure used to store the information for a priority
 * level (pointer to a fifo and the size of the fifo.
 * It is the element of the ready list table.
 */
typedef struct {
    P2VAR(tpl_exec_common, TYPEDEF, OS_APPL_DATA) *fifo;
    VAR(u8, AUTOMATIC) size;
} tpl_priority_level;

#endif /* WITH_POWEROF2QUEUE */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * Currently running executable object. This "executable object" can be a task
 * or an interrupt service routine
 */
extern P2VAR(tpl_exec_common, OS_VAR, OS_APPL_DATA) tpl_running_obj;

/**
 * the exec object that just lost the CPU
 */
extern P2VAR(tpl_exec_common, OS_VAR, OS_APPL_DATA) tpl_old_running_obj;

/*
 * Internal RES_SCHEDULER resource
 */
extern VAR(tpl_internal_resource, OS_VAR) INTERNAL_RES_SCHEDULER;


#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * Kernel functions
 */
FUNC(VAR(tpl_os_state, AUTOMATIC), OS_CODE) tpl_current_os_state(
    void);

FUNC(tpl_application_mode, OS_CODE) tpl_get_active_application_mode_service(
    void);

FUNC(void, OS_CODE) tpl_start_os_service(
    CONST(tpl_application_mode, AUTOMATIC) mode);

FUNC(void, OS_CODE) tpl_shutdown_os_service(
    CONST(tpl_status, AUTOMATIC) error);
    
FUNC(tpl_status, OS_CODE) tpl_schedule(
    CONST(u8, AUTOMATIC) from);

FUNC(tpl_status, OS_CODE) tpl_schedule_from_running(
    CONST(u8, AUTOMATIC) from);

FUNC(tpl_status, OS_CODE) tpl_schedule_from_dying(void);

FUNC(tpl_status, OS_CODE) tpl_schedule_from_idle(void);

FUNC(tpl_status, OS_CODE) tpl_schedule_from_waiting(void);

FUNC(void, OS_CODE) tpl_init_exec_object(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) exec_obj);

FUNC(void, OS_CODE) tpl_put_preempted_exec_object(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) exec_obj);

FUNC(void, OS_CODE) tpl_put_new_exec_object(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) exec_obj);

FUNC(void, OS_CODE) tpl_init_os(
    CONST(tpl_application_mode, AUTOMATIC) app_mode);

FUNC(void, OS_CODE) tpl_get_internal_resource(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) a_task);

FUNC(void, OS_CODE) tpl_release_internal_resource(
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) a_task);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_KERNEL_H */

/* End of file tpl_os_kernel.h */
