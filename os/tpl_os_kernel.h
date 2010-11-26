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

#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#include "tpl_as_timing_protec.h"
/* #include "tpl_as_st_kernel.h" */
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

#if WITH_OSAPPLICATION == YES
#include "tpl_as_app_kernel.h"
#include "tpl_as_trusted_fct_kernel.h"
#endif /* WITH_OSAPPLICATION */

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
typedef u8 tpl_proc_type;

/**
 * @typedef tpl_exec_function
 *
 * This type is used to specify the task entry point (function where the task
 * begins)
 *
 * @see #TPL_EXEC_STATIC
 */
typedef P2FUNC(void, OS_APPL_CODE, tpl_proc_function)(void);

/**
 * @typedef tpl_internal_resource
 *
 * This is is the internal resource descriptor structure. It is a simpler
 * structure than tpl_resource since only one internal resource can be taken
 * and there is no need to store the owner
 */
typedef struct {
  CONST(tpl_priority, TYPEDEF)
    ceiling_priority;     /**<  Ceiling priority as computed at system
                                generation time                               */
  VAR(tpl_priority, TYPEDEF)
    owner_prev_priority;  /**<  Priority of the owner prior to the access
                                to the resource. This field is used to
                                restore the priority of the task when the
                                resource is released                          */
  VAR(tpl_bool, TYPEDEF)
    taken;                /**<  Flag to tell if the internal resource
                                is taken or not                               */
} tpl_internal_resource;

/**
 * @struct TPL_PROC_STATIC
 *
 * This is a data structure used to describe the static members of task
 * descriptors or category 2 Interrupt Service Routines. Static means this
 * part of the descriptor can be stored in ROM.
 */
struct TPL_PROC_STATIC {
  VAR(tpl_context, TYPEDEF)
    context;            /**<  context(s) of the task/isr                      */
  VAR(tpl_stack, TYPEDEF)
    stack;              /**<  stack(s) of the  task/isr                       */
  CONST(tpl_proc_function, TYPEDEF)
    entry;              /**<  function that is the entry point
                              of the task/isr                                 */
  CONSTP2VAR(tpl_internal_resource, TYPEDEF, OS_APPL_DATA)
    internal_resource;  /**<  pointer to an internal resource. NULL if the
                              task does not have an internal resource         */
  CONST(tpl_task_id, TYPEDEF)
    id;                 /**<  id of task/isr                                  */
#if WITH_OSAPPLICATION == YES
  CONST(tpl_app_id, TYPEDEF)
    app_id;             /**<  id of the OS application which owns
                              the task/ISR                                    */
#endif
  CONST(tpl_priority, TYPEDEF)
    base_priority;      /**<  base priority of the task/isr                   */
  CONST(tpl_activate_counter, TYPEDEF)
    max_activate_count; /**<  max activation count of a task/isr              */
  CONST(tpl_proc_type, TYPEDEF)
    type;               /**<  type of the task/isr                            */
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
  P2CONST(tpl_timing_protection, TYPEDEF, OS_APPL_CONST)
    timing_protection;  /**<  timing protection configuration (can be NULL
                              if no timing protection is needed)              */
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
};

/**
 * @typedef tpl_exec_static
 *
 * This is an alias for the #TPL_PROC_STATIC structure
 *
 * @see #TPL_PROC_STATIC
 */
typedef struct TPL_PROC_STATIC tpl_proc_static;

/**
 * @struct TPL_PROC
 *
 * This structure gathers the common members of executable objects dynamic
 * descriptors
 */
struct TPL_PROC {
  struct P2VAR(TPL_RESOURCE, TYPEDEF, OS_APPL_DATA)
    resources;          /**< head of the ressources held          */
#if WITH_MEMORY_PROTECTION == YES
  VAR(tpl_trusted_count, TYPEDEF)
    trusted_counter;    /**<  if > 0 the process is trusted       */
#endif /* WITH_MEMORY_PROTECTION */
  VAR(tpl_activate_counter, TYPEDEF)
    activate_count;     /**< current activate count               */
  VAR(tpl_priority, TYPEDEF)
    priority;           /**< current priority                     */
  VAR(tpl_proc_state, TYPEDEF)
    state;              /**< state (READY, RUNNING, ...)          */
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
  VAR(tpl_bool, TYPEDEF)
    activation_allowed; /**< TRUE is the process may be activated */
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
};

/**
 * @typedef tpl_proc
 *
 * This is an alias for the #TPL_PROC structure.
 *
 * @see #TPL_PROC
 */
typedef struct TPL_PROC tpl_proc;

/**
 * @typedef tpl_kern_state
 */
typedef struct 
{
  P2CONST(tpl_proc_static, TYPEDEF, OS_CONST) s_old;
  P2CONST(tpl_proc_static, TYPEDEF, OS_CONST) s_running;
  P2VAR(tpl_proc, TYPEDEF, OS_VAR)            old;
  P2VAR(tpl_proc, TYPEDEF, OS_VAR)            running;
  VAR(int, TYPEDEF)                           running_id;
  VAR(u8, TYPEDEF)                            need_switch;
#if WITH_MEMORY_PROTECTION == YES
  VAR(u8, TYPEDEF)                            running_trusted; /** This flag is set when memory protection is (or needs to be) disabled */
#endif /* WITH_MEMORY_PROTECTION */
} tpl_kern_state;
 
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
    P2VAR(tpl_proc_id, TYPEDEF, OS_APPL_DATA) fifo;
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
    P2VAR(tpl_proc_id, TYPEDEF, OS_APPL_DATA) fifo;
    VAR(u8, AUTOMATIC) size;
} tpl_priority_level;

#endif /* WITH_POWEROF2QUEUE */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

extern VAR(tpl_kern_state, OS_VAR) tpl_kern;

/**
 * Currently running executable object id. This "executable object" can be
 * a task or an interrupt service routine
 * 
 * It has been changed to an int to ease its usage in asssembly language
 */
/* extern VAR(int, OS_VAR) tpl_running_id; */

/**
 * 2 bits are used in this variable.
 * bit 0 indicates a context switch is needed after calling a service,
 * bit 1 indicated the context of the processus that loses the cpu
 * should be saved.
 */
/* extern VAR(u8, OS_VAR) tpl_need_switch; */

/**
 * Internal RES_SCHEDULER resource
 */
extern VAR(tpl_internal_resource, OS_VAR) INTERNAL_RES_SCHEDULER;

/**
 * Dynamic descriptor of the idle task
 */
extern VAR(tpl_proc, OS_VAR) idle_task;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/**
 * Static descriptor of the idle task
 */
extern CONST(tpl_proc_static, OS_VAR) idle_task_static;

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * @def IDLE_TASK_ID
 *
 * Id of the Idle task
 */
#define IDLE_TASK_ID  (TASK_COUNT+ISR_COUNT)

/*
 * @def INVALID_PROC_ID
 *
 * @see #INVALID_TASK
 *
 */
#define INVALID_PROC_ID  -1

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/**
 * Arrays of all processes static and dynamic descriptors.
 *
 * Index in this array correspond to the #TaskType of the task.
 * The size of these tables are static and known at compile time
 * The last element of these arrays is the idle task descriptor.
 */
extern CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
  tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1];
            
extern CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA)
  tpl_dyn_proc_table[TASK_COUNT+ISR_COUNT+1];
            
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * Kernel functions
 */
FUNC(VAR(tpl_os_state, AUTOMATIC), OS_CODE) tpl_current_os_state(void);

FUNC(tpl_application_mode, OS_CODE) tpl_get_active_application_mode_service(
    void);

FUNC(void, OS_CODE) tpl_start_os_service(
    CONST(tpl_application_mode, AUTOMATIC) mode);

FUNC(void, OS_CODE) tpl_shutdown_os_service(
    CONST(tpl_status, AUTOMATIC) error);

FUNC(void, OS_CODE) tpl_schedule_from_running(void);

FUNC(void, OS_CODE) tpl_schedule_from_dying(void);

FUNC(void, OS_CODE) tpl_schedule_from_waiting(void);

FUNC(void, OS_CODE) tpl_init_proc(
  CONST(tpl_proc_id, AUTOMATIC) proc_id);

FUNC(void, OS_CODE) tpl_put_preempted_proc(
  CONST(tpl_proc_id, AUTOMATIC) proc_id);

FUNC(void, OS_CODE) tpl_put_new_proc(
  CONST(tpl_proc_id, AUTOMATIC) proc_id);

FUNC(void, OS_CODE) tpl_init_os(
  CONST(tpl_application_mode, AUTOMATIC) app_mode);

FUNC(void, OS_CODE) tpl_get_internal_resource(
  CONST(tpl_proc_id, AUTOMATIC) task_id);

FUNC(void, OS_CODE) tpl_release_internal_resource(
  CONST(tpl_proc_id, AUTOMATIC) task_id);

/**
 * If a task is ended without calling TerminateTask() :
 * enable interrupts if needed ; release resources if used ;
 * call ErrorHook if enabled by the user ; call 
 * tpl_terminate_task_service()
 */
FUNC(void, OS_CODE) tpl_call_terminate_task_service(void);

/**
 * Ending an ISR2 : enable interrupts if needed ;
 * release resources if used ; call ErrorHook if enabled
 * by the user ; call tpl_terminate_isr2_service()
 */
FUNC(void, OS_CODE) tpl_call_terminate_isr2_service(void);

#if WITH_OSAPPLICATION == YES
FUNC(void, OS_CODE) tpl_remove_proc(
  CONST(tpl_proc_id, AUTOMATIC) proc_id);
#endif

/**
 * @internal
 *
 * Low level fonction for task activation. This functions is used
 * internally by tpl_activate_task_service and by occurences that
 * will lead to task activation, ie alarm, schedule table expiry
 * point (if Autosar is on), message and so on.
 *
 * @param   a_task  pointer to the task structure of the task to activate.
 */
FUNC(tpl_status, OS_CODE) tpl_activate_task(
    CONST(tpl_task_id, AUTOMATIC) task_id);

/**
 * @internal
 *
 * Low level fontion for event setting. This functions is used
 * internally by tpl_set_event_service and by occurences that
 * will lead to event settings ie alarm, schedule table expiry
 * point (if Autosar is on), message and so on.
 *
 * @param   a_task          pointer to the task structure of the target task.
 * @param   incoming_event  the event mask.
 */
FUNC(tpl_status, OS_CODE) tpl_set_event(
    CONST(tpl_task_id, AUTOMATIC)     task_id,
    CONST(tpl_event_mask, AUTOMATIC)  incoming_event);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_KERNEL_H */

/* End of file tpl_os_kernel.h */
