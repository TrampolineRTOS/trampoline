/**
 * @file tpl_os_kernel.h
 *
 * @section desc File description
 *
 * Trampoline kernel structures header file
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de
 * Nantes Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
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

#if NUMBER_OF_CORES > 1
#include "tpl_os_multicore.h"
#endif

#include "tpl_os_multicore_macros.h"

/**
 * @typedef tpl_os_state
 *
 * States of Trampoline :
 * - #OS_INIT means initialization
 * - #OS_TASK means running a task
 * - #OS_IDLE means no task running and the OS has nothing else to do
 * - #OS_ISR2 means running a category 2 interrupt service routine
 * - #OS_CALLBACK means an alarm callback is running
 * - #OS_UNKNOWN means the OS is not in a known state. This should not happen.
 */
typedef uint8 tpl_os_state;

/**
 * @def OS_INIT
 *
 * Trampoline is initializing. Trampoline is in this state from the start
 * and until a task get the CPU (#OS_TASK), it goes idle (#OS_IDLE) or an ISR2
 * takes the CPU (#OS_ISR2)
 */
#define OS_INIT 0

/**
 * @def OS_TASK
 *
 * A task is running
 */
#define OS_TASK 1

/**
 * @def OS_IDLE
 *
 * A task is running
 */
#define OS_IDLE 2

/**
 * @def OS_IDLE
 *
 * An ISR2 is running
 */
#define OS_ISR2 3

/**
 * @def OS_CALLBACK
 *
 * An alarm callback is running
 */
#define OS_CALLBACK 4

/**
 * @def OS_UNKNOWN
 *
 * The state is unknown. This should not happen.
 */
#define OS_UNKNOWN 5

/**
 * @def AUTOSTART
 *
 * Task is automatically activated at system startup
 *
 * @see #tpl_exec_state
 */
#define AUTOSTART 0x4

/**
 * @def READY_AND_NEW
 *
 * Task is ready and should be initialized when it get the CPU.
 *
 * @see #tpl_exec_state
 */
#define READY_AND_NEW 0x5

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
typedef uint8 tpl_proc_type;

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
typedef struct
{
  CONST(tpl_priority, TYPEDEF)
  ceiling_priority; /**<  Ceiling priority as computed at system
                          generation time                               */
  VAR(tpl_priority, TYPEDEF)
  owner_prev_priority; /**<  Priority of the owner prior to the access
                             to the resource. This field is used to
                             restore the priority of the task when the
                             resource is released                          */
  VAR(tpl_bool, TYPEDEF)
  taken; /**<  Flag to tell if the internal resource
               is taken or not                               */
} tpl_internal_resource;

/**
 * @struct TPL_PROC_STATIC
 *
 * This is a data structure used to describe the static members of task
 * descriptors or category 2 Interrupt Service Routines. Static means this
 * part of the descriptor can be stored in ROM.
 */
struct TPL_PROC_STATIC
{
  VAR(tpl_context, TYPEDEF)
  context; /**<  context(s) of the task/isr                     */
  VAR(tpl_stack, TYPEDEF)
  stack; /**<  stack(s) of the  task/isr                      */
  CONST(tpl_proc_function, TYPEDEF)
  entry; /**<  function that is the entry point
               of the task/isr                                */
  CONSTP2VAR(tpl_internal_resource, TYPEDEF, OS_APPL_DATA)
  internal_resource; /**<  pointer to an internal resource. NULL if the
                           task does not have an internal resource        */
  CONST(tpl_task_id, TYPEDEF)
  id; /**<  id of task/isr                                 */
#if WITH_OSAPPLICATION == YES
  CONST(tpl_app_id, TYPEDEF)
  app_id; /**<  id of the OS application which owns
                the task/ISR                                    */
#endif
#if NUMBER_OF_CORES > 1
  CONST(tpl_core_id, TYPEDEF)
  core_id; /**<  id of the core the process is assigned to      */
#endif
  CONST(tpl_priority, TYPEDEF)
  base_priority; /**<  base priority of the task/isr                  */
  CONST(tpl_activate_counter, TYPEDEF)
  max_activate_count; /**<  max activation count of a task/isr             */
  CONST(tpl_proc_type, TYPEDEF)
  type; /**<  TASK_BASIC,TASK_EXTENDED or IS_ROUTINE         */
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
  CONST(tpl_time, TYPEDEF)
  executionbudget; /**<  execution budget                               */
  CONST(tpl_time, TYPEDEF)
  timeframe; /**<  length of the time frame                       */
  CONSTP2VAR(tpl_timing_protection, TYPEDEF, OS_APPL_CONST)
  timing_protection; /**<  dynamic variables needed to handle
                           the timing protection. Set to NULL if
                           the proc is not supervised by the mechanism    */
#endif               /* WITH_AUTOSAR_TIMING_PROTECTION */
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
struct TPL_PROC
{
  struct P2VAR(TPL_RESOURCE, TYPEDEF,
               OS_APPL_DATA) resources; /**< head of the ressources held */
#if WITH_OSAPPLICATION == YES
  VAR(tpl_trusted_count, TYPEDEF)
  trusted_counter; /**<  if > 0 the process is trusted       */
#endif             /* WITH_OSAPPLICATION */
  VAR(tpl_activate_counter, TYPEDEF)
  activate_count; /**< current activate count               */
  VAR(tpl_priority, TYPEDEF)
  priority; /**< current priority                     */
  VAR(tpl_proc_state, TYPEDEF)
  state; /**< state (READY, RUNNING, ...)*/
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
  P2CONST(tpl_proc_static, TYPEDEF, OS_CONST) s_running;
  P2CONST(tpl_proc_static, TYPEDEF, OS_CONST) s_elected;
  P2VAR(tpl_proc, TYPEDEF, OS_VAR) running;
  P2VAR(tpl_proc, TYPEDEF, OS_VAR) elected;
  VAR(sint32, TYPEDEF) running_id;
  VAR(sint32, TYPEDEF) elected_id;

  /**
   * 2 bits are used in this field.
   * bit 0 indicates a context switch is needed after calling a service,
   * bit 1 indicated the context of the processus that loses the cpu
   * should be saved.
   */
  VAR(uint8, TYPEDEF) need_switch;

  /**
   * Boolean used to notify a rescheduling should be done
   */
  VAR(tpl_bool, TYPEDEF) need_schedule;

#if WITH_MEMORY_PROTECTION == YES
  /**
   * This flag is set before running a hook or a (transitionnal) trusted
   * process to disable some checkings
   */
  VAR(uint8, TYPEDEF) running_trusted;
#endif /* WITH_MEMORY_PROTECTION */
} tpl_kern_state;

/**
 * @typedef tpl_heap_entry
 *
 * This type gather a key used to sort the heap and the identifier of
 * the process
 */
typedef struct
{
  VAR(tpl_priority, TYPEDEF) key;
  VAR(tpl_proc_id, TYPEDEF) id;
} tpl_heap_entry;

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#if NUMBER_OF_CORES == 1
extern VAR(tpl_kern_state, OS_VAR) tpl_kern;
#else
extern CONSTP2VAR(tpl_kern_state, OS_CONST, OS_VAR) tpl_kern[];
#endif

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

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*
 * @def INVALID_PROC_ID
 *
 * @see #INVALID_TASK
 *
 */
#define INVALID_PROC_ID -1

/**
 * @internal
 *
 * In monocore and multicore and function base context switch,
 * does the rescheduling and the context switch if needed
 * In multicore does the intercore interrupt if needed
 */
#if WITH_SYSTEM_CALL == NO
#define LOCAL_SWITCH_CONTEXT(a_core_id)                                        \
  if (TPL_KERN(a_core_id).need_switch != NO_NEED_SWITCH)                       \
  {                                                                            \
    TPL_KERN(a_core_id).need_switch = NO_NEED_SWITCH;                          \
    tpl_switch_context(tpl_run_elected(TRUE),                                  \
                       &(TPL_KERN(a_core_id).s_elected->context));             \
  }

#define LOCAL_SWITCH_CONTEXT_NOSAVE(a_core_id)                                 \
  if (TPL_KERN(a_core_id).need_switch != NO_NEED_SWITCH)                       \
  {                                                                            \
    TPL_KERN(a_core_id).need_switch = NO_NEED_SWITCH;                          \
    tpl_switch_context(tpl_run_elected(FALSE),                                 \
                       &(TPL_KERN(a_core_id).s_elected->context));             \
  }
#else
#define LOCAL_SWITCH_CONTEXT(a_core_id)
#define LOCAL_SWITCH_CONTEXT_NOSAVE(a_core_id)
#endif

#if NUMBER_OF_CORES == 1

#define REMOTE_SWITCH_CONTEXT()

#define SWITCH_CONTEXT(a_core_id) LOCAL_SWITCH_CONTEXT(0)
#define SWITCH_CONTEXT_NOSAVE(a_core_id) LOCAL_SWITCH_CONTEXT_NOSAVE(0)

#else
/* NUMBER_OF_CORES > 1, Multicore definitions */
#define REMOTE_SWITCH_CONTEXT(a_core_id)                                       \
  if (TPL_KERN(a_core_id).need_switch != NO_NEED_SWITCH)                       \
  {                                                                            \
    /* need_switch flag will be resetted by the remote core */                 \
    tpl_send_intercore_it(a_core_id);                                          \
  }

#if WITH_SYSTEM_CALL == NO

#define SWITCH_CONTEXT(a_core_id)                                              \
  if (a_core_id == tpl_get_core_id())                                          \
  {                                                                            \
    LOCAL_SWITCH_CONTEXT(a_core_id)                                            \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    REMOTE_SWITCH_CONTEXT(a_core_id);                                          \
  }

#define SWITCH_CONTEXT_NOSAVE(a_core_id)                                       \
  if (a_core_id == tpl_get_core_id())                                          \
  {                                                                            \
    LOCAL_SWITCH_CONTEXT(a_core_id)                                            \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    REMOTE_SWITCH_CONTEXT(a_core_id);                                          \
  }

#else
/* WITH_SYSTEM_CALL == YES */

#define SWITCH_CONTEXT(a_core_id)                                              \
  if (a_core_id != tpl_get_core_id())                                          \
  {                                                                            \
    tpl_send_intercore_it(a_core_id);                                          \
  }
#define SWITCH_CONTEXT_NOSAVE(a_core_id)                                       \
  if (a_core_id != tpl_get_core_id())                                          \
  {                                                                            \
    tpl_send_intercore_it(a_core_id);                                          \
  }

#endif

#endif

/**
 * @internal
 *
 * In monocore implementation tpl_ready_list is a heap with a size
 * automatically generated by goil from the application description. Each
 * entry is a key and a proc id. The key is used to sort the heap and is
 * the concatenation of the priority of the proc and its job rank of
 * activation.
 *
 * In multicore implementation, tpl_ready_list is an array of pointers to
 * a heap per core. tpl_ready_list is indexed by the core identifier.
 */

/*
 * MISRA RULE 27 VIOLATION: These 2 variables are used only in this file
 * but declared in the configuration file, this is why they do not need
 * to be declared as external in a header file
 */

#if NUMBER_OF_CORES > 1

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
extern CONSTP2VAR(tpl_heap_entry, OS_CONST, OS_VAR) tpl_ready_list[];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#else

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
extern VAR(tpl_heap_entry, OS_VAR) tpl_ready_list[];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#endif

/**
 * @internal
 *
 * In monocore implementation, tpl_tail_for_prio is a variable that stores
 * the last rank used to store a proc.
 *
 * In multicore implementation, tpl_tail_for_prio is an array of such
 * a variable.
 */
#if NUMBER_OF_CORES > 1

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

extern CONSTP2VAR(tpl_rank_count, OS_CONST,
                  OS_VAR) tpl_tail_for_prio[NUMBER_OF_CORES];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#else

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

extern VAR(tpl_rank_count, OS_VAR) tpl_tail_for_prio[];

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#endif

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/**
 * Arrays of all processes static and dynamic descriptors.
 *
 * Index in this array correspond to the #TaskType of the task.
 * The size of these tables are static and known at compile time
 * The last elements of these arrays are the idle task descriptor
 * (one Idle task per core).
 */
extern CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
    tpl_stat_proc_table[TASK_COUNT + ISR_COUNT + NUMBER_OF_CORES];

extern CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA)
    tpl_dyn_proc_table[TASK_COUNT + ISR_COUNT + NUMBER_OF_CORES];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * Kernel functions
 */
FUNC(void, OS_CODE) tpl_begin_alarm_callback(void);

FUNC(void, OS_CODE) tpl_end_alarm_callback(void);

FUNC(tpl_bool, OS_CODE) tpl_alarm_callback_running(void);

FUNC(tpl_os_state, OS_CODE) tpl_current_os_state(CORE_ID_OR_VOID(core_id));

FUNC(void, OS_CODE) tpl_schedule_from_running(CORE_ID_OR_VOID(core_id));

FUNC(void, OS_CODE) tpl_start_scheduling(CORE_ID_OR_VOID(core_id));

/**
 * @internal
 *
 * Starts a highest priority READY process
 */
FUNC(void, OS_CODE) tpl_start(CORE_ID_OR_VOID(core_id));

/**
 * @internal
 *
 * The elected task becomes the running task
 *
 * @return  the pointer to the static descriptor of the task
 *          that was running before the elected task replace it
 */
FUNC(P2CONST(tpl_context, AUTOMATIC, OS_CONST), OS_CODE)
tpl_run_elected(CONST(tpl_bool, AUTOMATIC) save);

/**
 * @internal
 *
 * Blocks the running process
 *
 */
FUNC(void, OS_CODE) tpl_block(void);

/**
 * @internal
 *
 * Release a task from the waiting state
 *
 */
FUNC(void, OS_CODE) tpl_release(CONST(tpl_task_id, AUTOMATIC) task_id);

/**
 * @internal
 *
 * Get the highest priority READY process from the queue
 */
FUNC(tpl_heap_entry, OS_CODE) tpl_front_proc(CORE_ID_OR_VOID(core_id));

/**
 * @internal
 *
 * Terminate the RUNNING process
 */
FUNC(void, OS_CODE) tpl_terminate(void);

FUNC(void, OS_CODE) tpl_init_proc(CONST(tpl_proc_id, AUTOMATIC) proc_id);

FUNC(void, OS_CODE)
tpl_put_preempted_proc(CONST(tpl_proc_id, AUTOMATIC) proc_id);

FUNC(void, OS_CODE) tpl_put_new_proc(CONST(tpl_proc_id, AUTOMATIC) proc_id);

FUNC(void, OS_CODE)
tpl_init_os(CONST(tpl_application_mode, AUTOMATIC) app_mode);

FUNC(void, OS_CODE)
tpl_get_internal_resource(CONST(tpl_proc_id, AUTOMATIC) task_id);

FUNC(void, OS_CODE)
tpl_release_internal_resource(CONST(tpl_proc_id, AUTOMATIC) task_id);

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
FUNC(void, OS_CODE) tpl_remove_proc(CONST(tpl_proc_id, AUTOMATIC) proc_id);
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
FUNC(tpl_status, OS_CODE)
tpl_activate_task(CONST(tpl_task_id, AUTOMATIC) task_id);

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
FUNC(tpl_status, OS_CODE)
tpl_set_event(CONST(tpl_task_id, AUTOMATIC) task_id,
              CONST(tpl_event_mask, AUTOMATIC) incoming_event);

#if NUMBER_OF_CORES > 1
/**
 * @internal
 *
 * tpl_multi_schedule does multiple rescheduling when many tasks could
 * have been activated on several cores (messages, alarms, schedule tables)
 */
FUNC(void, OS_CODE) tpl_multi_schedule(void);

/**
 * @internal
 *
 * tpl_dispatch_context_switch notify multiple context switch to other cores
 * It happens when many tasks could have been activated on several cores
 * (messages, alarms, schedule tables)
 */
FUNC(void, OS_CODE) tpl_dispatch_context_switch(void);

#endif /* NUMBER_OF_CORES > 1 */

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_KERNEL_H */

/* End of file tpl_os_kernel.h */
