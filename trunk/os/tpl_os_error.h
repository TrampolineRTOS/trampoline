/**
 * @file tpl_os_error.h
 *
 * @section descr File description
 *
 * Trampoline Errors macros, functions and datatypes header
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
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

#ifndef TPL_OS_ERROR_H
#define TPL_OS_ERROR_H

#include "tpl_os.h"

/*
 * Remember (see "The design of Trampoline") :
 * NO_TASK means there is no task defined in the system
 * OS_EXTENDED means extended error checking is done
 * WITH_ERROR_HOOK means an error hook routine is called when
 * an error occurs.
 */

#ifdef WITH_ERROR_HOOK

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * The function corresponding to this prototype should be provided
 * by the application
 */
extern FUNC(void, OS_CODE) ErrorHook(
    VAR(StatusType, AUTOMATIC) error);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/**
 * @union ID_PARAM_BLOCK
 *
 * This union is used in error hook parameter (#PARAM_BLOCK) to specify
 * the related OS element's identifier. An OS element can be either a task
 * or a resource or an alarm.
 *
 * Of course, it is an union because the kinds of identifier are mutually
 * exclusive.
 *
 * @see #PARAM_BLOCK
 * @see #tpl_service
 */
union ID_PARAM_BLOCK {
    VAR(TaskType, AUTOMATIC)            task_id;        /**< used by
                                                             #ActivateTask,
                                                             #ChainTask,
                                                             #GetTaskState,
                                                             #SetEvent,
                                                             #GetEvent                  */
    VAR(TaskRefType, AUTOMATIC)         task_id_ref;    /**< used by #GetTaskID         */
    VAR(ResourceType, AUTOMATIC)        res_id;         /**< used by #GetResource,
                                                             #ReleaseResource           */
    VAR(AlarmType, AUTOMATIC)           alarm_id;       /**< @todo document this        */
#ifdef WITH_AUTOSAR
    VAR(ScheduleTableType, AUTOMATIC)   schedtable_id;  /**< @todo document this        */
    VAR(CounterType, AUTOMATIC)         counter_id;     /**< @todo document this        */
#endif
};

/**
 * @union PARAM_PARAM_BLOCK
 *
 * This union describes the parameter of the param block (#PARAM_BLOCK).
 *
 * @see #PARAM_BLOCK
 * @see #tpl_service
 */
union PARAM_PARAM_BLOCK {
    VAR(TaskStateRefType, AUTOMATIC)            state;          /**< used by #GetTaskState  */
    VAR(TickType, AUTOMATIC)                    tick;           /**< used by #SetRelAlarm,
                                                                     #SetAbsAlarm       */
    VAR(TickRefType, AUTOMATIC)                 tick_ref;       /**< used by #GetAlarm      */
    VAR(AlarmBaseRefType, AUTOMATIC)            alarm_base_ref; /**< used by #GetAlarmBase  */
    VAR(EventMaskType, AUTOMATIC)               mask;           /**< used by #SetEvent,
                                                                     #ClearEvent,
                                                                     #WaitEvent             */
    VAR(EventMaskRefType, AUTOMATIC)            mask_ref;       /**< used by #GetEvent      */
#ifdef WITH_AUTOSAR
    VAR(ScheduleTableType, AUTOMATIC)           next_st_id;     /**< @todo document this    */
    VAR(ScheduleTableStatusRefType, AUTOMATIC)  st_stat;        /**< @todo document this    */
#endif
};

/**
 * @struct PARAM_BLOCK
 *
 * This structure gathers all parameters for an error hook
 */
struct PARAM_BLOCK {
    union ID_PARAM_BLOCK      id;     /**< identifies the OS element
                                            concerned by the error */
    union PARAM_PARAM_BLOCK   param;  /**< gives more information about the
                                            reason of the error */
    VAR(TickType, AUTOMATIC)  cycle;  /**< cycle set for a relative alarm */
};

/**
 * @struct SERVICE_CALL_DESCRIPTOR
 *
 * This structure gathers the os service identifier and its parameters
 */
struct SERVICE_CALL_DESCRIPTOR {
    struct PARAM_BLOCK  parameters; /**< information about conditions seen
                                         when error has been detected */
    VAR(u8, AUTOMATIC)  service_id; /**< identifier of the service which
                                         raised the error */
};

/**
 * @typedef tpl_service_call_desc
 *
 * This is an alias for the structure #SERVICE_CALL_DESCRIPTOR
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 */
typedef struct SERVICE_CALL_DESCRIPTOR tpl_service_call_desc;

/**
 * This global variable is where all informations about the error are store.
 *
 * This global variable must not be accessed directly, neither by application
 * nor by OS services.
 *
 * Application (via ErrorHook function) should use some of these macros :
 * - #OSError_ActivateTask_TaskID
 * - #OSError_ChainTask_TaskID
 * - #OSError_GetTaskID_TaskID
 * - #OSError_GetTaskState_TaskID
 * - #OSError_GetTaskState_State
 * - #OSError_GetResource_ResID
 * - #OSError_ReleaseResource_ResID
 * - #OSError_SetEvent_TaskID
 * - #OSError_SetEvent_Mask
 * - #OSError_ClearEvent_Mask
 * - #OSError_GetEvent_TaskID
 * - #OSError_GetEvent_Event
 * - #OSError_WaitEvent_Mask
 * - #OSError_GetAlarmBase_AlarmID
 * - #OSError_GetAlarmBase_Info
 * - #OSError_GetAlarm_AlarmID
 * - #OSError_GetAlarm_Tick
 * - #OSError_SetRelAlarm_AlarmID
 * - #OSError_SetRelAlarm_increment
 * - #OSError_SetRelAlarm_cycle
 * - #OSError_SetAbsAlarm_AlarmID
 * - #OSError_SetAbsAlarm_start
 * - #OSError_SetAbsAlarm_cycle
 * - #OSError_CancelAlarm_AlarmID
 *
 * Within OS services, these macros should be used to modify this variable :
 * - #STORE_SERVICE
 * - #STORE_TASK_ID
 * - #STORE_TASK_ID_REF
 * - #STORE_TASK_STATE_REF
 * - #STORE_RESOURCE_ID
 * - #STORE_ALARM_ID
 * - #STORE_ALARM_BASE_REF
 * - #STORE_TICK_REF
 * - #STORE_TICK_1
 * - #STORE_TICK_2
 * - #STORE_EVENT_MASK
 * - #STORE_EVENT_MASK_REF
 */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

extern VAR(tpl_service_call_desc, OS_VAR) tpl_service;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * this function is used to call the ErrorHook callback
 *
 * @param tpl_status The error code which causes the call back
 */
FUNC(void, OS_CODE) tpl_call_error_hook(
    CONST(tpl_status, AUTOMATIC) error);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/************************
 * Services identifiers *
 ************************/

/**
 * @def OSServiceId_ActivateTask
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ActivateTask
 */
#define OSServiceId_ActivateTask                1

/**
 * @def OSServiceId_TerminateTask
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #TerminateTask
 */
#define OSServiceId_TerminateTask               2

/**
 * @def OSServiceId_ChainTask
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ChainTask
 */
#define OSServiceId_ChainTask                   3

/**
 * @def OSServiceId_Schedule
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #Schedule
 */
#define OSServiceId_Schedule                    4

/**
 * @def OSServiceId_GetTaskID
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetTaskID
 */
#define OSServiceId_GetTaskID                   5

/**
 * @def OSServiceId_GetTaskState
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetTaskState
 */
#define OSServiceId_GetTaskState                6

/**
 * @def OSServiceId_EnableAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #EnableAllInterrupts
 */
#define OSServiceId_EnableAllInterrupts         7

/**
 * @def OSServiceId_DisableAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #DisableAllInterrupts
 */
#define OSServiceId_DisableAllInterrupts        8

/**
 * @def OSServiceId_ResumeAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ResumeAllInterrupts
 */
#define OSServiceId_ResumeAllInterrupts         9

/**
 * @def OSServiceId_SuspendAllInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SuspendAllInterrupts
 */
#define OSServiceId_SuspendAllInterrupts        10

/**
 * @def OSServiceId_ResumeOSInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ResumeOSInterrupts
 */
#define OSServiceId_ResumeOSInterrupts          11

/**
 * @def OSServiceId_SuspendOSInterrupts
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SuspendOSInterrupts
 */
#define OSServiceId_SuspendOSInterrupts         12


/**
 * @def OSServiceId_GetResource
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetResource
 */
#define OSServiceId_GetResource                 13

/**
 * @def OSServiceId_ReleaseResource
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ReleaseResource
 */
#define OSServiceId_ReleaseResource             14

/**
 * @def OSServiceId_SetEvent
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SetEvent
 */
#define OSServiceId_SetEvent                    15

/**
 * @def OSServiceId_ClearEvent
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ClearEvent
 */
#define OSServiceId_ClearEvent                  16

/**
 * @def OSServiceId_GetEvent
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetEvent
 */
#define OSServiceId_GetEvent                    17

/**
 * @def OSServiceId_WaitEvent
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #WaitEvent
 */
#define OSServiceId_WaitEvent                   18

/**
 * @def OSServiceId_GetAlarmBase
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetAlarmBase
 */
#define OSServiceId_GetAlarmBase                19

/**
 * @def OSServiceId_GetAlarm
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetAlarm
 */
#define OSServiceId_GetAlarm                    20

/**
 * @def OSServiceId_SetRelAlarm
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SetRelAlarm
 */
#define OSServiceId_SetRelAlarm                 21

/**
 * @def OSServiceId_SetAbsAlarm
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SetAbsAlarm
 */
#define OSServiceId_SetAbsAlarm                 22

/**
 * @def OSServiceId_CancelAlarm
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #CancelAlarm
 */
#define OSServiceId_CancelAlarm                 23

/**
 * @def OSServiceId_GetActiveApplicationMode
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetActiveApplicationMode
 */
#define OSServiceId_GetActiveApplicationMode    24

/**
 * @def OSServiceId_StartOS
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartOS
 */
#define OSServiceId_StartOS                     25

/**
 * @def OSServiceId_ShutdownOS
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #ShutdownOS
 */
#define OSServiceId_ShutdownOS                  26

/**
 * @def OSServiceId_TerminateISR
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #TerminateISR
 */
#define OSServiceId_TerminateISR                32

/************************************************************************
 * macros to access the service id and its parameters from hook routine *
 ************************************************************************/

/**
 * @def OSErrorGetServiceId
 *
 * Gives identifier of the OS service which raised the error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSErrorGetServiceId()   (tpl_service.service_id)

/**
 * @def OSError_ActivateTask_TaskID
 *
 * ActivateTask service error parameter
 *
 * Returns the identifier (#TaskType) of the task which caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSError_ActivateTask_TaskID()   \
    (tpl_service.parameters.id.task_id)

/**
 * @def OSError_ChainTask_TaskID
 *
 * ChainTask service error parameter
 *
 * Returns the identifier (#TaskType) of the task which caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSError_ChainTask_TaskID()      \
    (tpl_service.parameters.id.task_id)

/**
 * @def OSError_GetTaskID_TaskID
 *
 * GetTaskID service error parameter
 *
 * Returns the identifier (#TaskType) of the task which caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSError_GetTaskID_TaskID()             \
    (tpl_service.parameters.id.task_id_ref)

/**
 * @def OSError_GetTaskState_TaskID
 *
 * One of GetTaskState service error parameters
 *
 * Returns the identifier (#TaskType) of the task which caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see #OSError_GetTaskState_State
 */
#define OSError_GetTaskState_TaskID()   \
    (tpl_service.parameters.id.task_id)

/**
 * @def OSError_GetTaskState_State
 *
 * One of GetTaskState service error parameters
 *
 * Returns the state (#TaskStateRefType) of the task when the error occured.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see #OSError_GetTaskState_TaskID
 */
#define OSError_GetTaskState_State()    \
    (tpl_service.parameters.param.state)

/**
 * @def OSError_GetResource_ResID
 *
 * GetResource service error parameter
 *
 * Returns the identifier (#ResourceType) of the resource which caused the
 * error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSError_GetResource_ResID()     \
    (tpl_service.parameters.id.res_id)

/**
 * @def OSError_ReleaseResource_ResID
 *
 * ReleaseResource service error parameter
 *
 * Returns the identifier (#ResourceType) of the resource which caused the
 * error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSError_ReleaseResource_ResID() \
    (tpl_service.parameters.id.res_id)

/**
 * @def OSError_SetEvent_TaskID
 *
 * One of the SetEvent service error parameters
 *
 * Returns the identifier (#TaskType) of the task which caused the error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see #OSError_SetEvent_Mask
 */
#define OSError_SetEvent_TaskID()       \
    (tpl_service.parameters.id.task_id)

/**
 * @def OSError_SetEvent_Mask
 *
 * One of the SetEvent service error parameters
 *
 * Returns the mask (#EventMaskType) of the event when error occurred
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see #OSError_SetEvent_TaskID
 */
#define OSError_SetEvent_Mask()         \
    (tpl_service.parameters.param.mask)

/**
 * @def OSError_ClearEvent_Mask
 *
 * ClearEvent service error parameter
 *
 * Returns the mask (#EventMaskType) of the event when error occurred
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSError_ClearEvent_Mask()       \
    (tpl_service.parameters.param.mask)

/**
 * @def OSError_GetEvent_TaskID
 *
 * One of GetEvent service error parameters
 *
 * Returns the identifier (#TaskType) of the task which caused the error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see #OSError_GetEvent_Event
 */
#define OSError_GetEvent_TaskID()       \
    (tpl_service.parameters.id.task_id)

/**
 * @def OSError_GetEvent_Event
 *
 * One of GetEvent service error parameters
 *
 * Returns the mask (#EventMaskType) of the event when error occurred
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see #OSError_GetEvent_TaskID
 */
#define OSError_GetEvent_Event()        \
    (tpl_service.parameters.param.mask)

/**
 * @def OSError_WaitEvent_Mask
 *
 * WaitEvent service error parameter
 *
 * Returns the mask (#EventMaskType) of the event when error occurred
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSError_WaitEvent_Mask()        \
    (tpl_service.parameters.param.mask)

/**
 * @def OSError_GetAlarmBase_AlarmID
 *
 * One of GetAlarmBase service error parameters
 *
 * Returns the identifier (#AlarmType) of the alarm which caused error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see #OSError_GetAlarmBase_Info
 */
#define OSError_GetAlarmBase_AlarmID()  \
    (tpl_service.parameters.id.alarm_id)

/**
 * @def OSError_GetAlarmBase_Info
 *
 * One of GetAlarmBase service error parameters
 *
 * Returns the basic characteristics (#AlarmBaseRefType) of the alarm which
 * caused the error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see #AlarmBaseType
 * @see #AlarmBaseRefType
 * @see #OSError_GetAlarmBase_AlarmID
 */
#define OSError_GetAlarmBase_Info()     \
    (tpl_service.parameters.param.alarm_base_ref)

/**
 * @def OSError_GetAlarm_AlarmID
 *
 * One of GetAlarm service error parameters
 *
 * Returns the identifier (#AlarmType) of the alarm which caused error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see OSError_GetAlarm_Tick
 */
#define OSError_GetAlarm_AlarmID()      \
    (tpl_service.parameters.id.alarm_id)

/**
 * @def OSError_GetAlarm_Tick
 *
 * One of GetAlarm service error parameters
 *
 * Returns the number of ticks (#TickRefType) on which the alarm which caused
 * error should trigger
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see OSError_GetAlarm_AlarmID
 */
#define OSError_GetAlarm_Tick()         \
    (tpl_service.parameters.param.tick_ref)

/**
 * @def OSError_SetRelAlarm_AlarmID
 *
 * One of SetRelAlarm service error parameters
 *
 * Returns the identifier (#AlarmType) of the alarm which caused the error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see #OSError_SetRelAlarm_increment
 * @see #OSError_SetRelAlarm_cycle
 */
#define OSError_SetRelAlarm_AlarmID()   \
    (tpl_service.parameters.id.alarm_id)

/**
 * @def OSError_SetRelAlarm_increment
 *
 * One of SetRelAlarm service error parameters
 *
 * Returns the number of ticks (#TickType) on which the alarm which caused
 * error should trigger
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see OSError_SetRelAlarm_AlarmID
 * @see OSError_SetRelAlarm_cycle
 */
#define OSError_SetRelAlarm_increment() \
    (tpl_service.parameters.param.tick)

/**
 * @def OSError_SetRelAlarm_cycle
 *
 * One of SetRelAlarm service error parameters
 *
 * Returns the cycle in ticks (#TickType) of the alarm which caused error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see OSError_SetRelAlarm_AlarmID
 * @see #OSError_SetRelAlarm_increment
 */
#define OSError_SetRelAlarm_cycle()     \
    (tpl_service.parameters.cycle)

/**
 * @def OSError_SetAbsAlarm_AlarmID
 *
 * One of SetAbsAlarm service error parameters
 *
 * Returns the identifier (#AlarmType) of the alarm which caused the error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see OSError_SetAbsAlarm_start
 * @see OSError_SetAbsAlarm_cycle
 */
#define OSError_SetAbsAlarm_AlarmID()   \
    (tpl_service.parameters.id.alarm_id)

/**
 * @def OSError_SetAbsAlarm_start
 *
 * One of SetAbsAlarm service error parameters
 *
 * Returns the ticks (#TickType) of the alarm which caused the error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see OSError_SetAbsAlarm_AlarmID
 * @see OSError_SetAbsAlarm_cycle
 */
#define OSError_SetAbsAlarm_start()     \
    (tpl_service.parameters.param.tick)

/**
 * @def OSError_SetAbsAlarm_cycle
 *
 * One of SetAbsAlarm service error parameters
 *
 * Returns the cycle (#TickType) of the alarm which caused the error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 *
 * @see OSError_SetAbsAlarm_AlarmID
 * @see OSError_SetAbsAlarm_start
 */
#define OSError_SetAbsAlarm_cycle()     \
    (tpl_service.parameters.cycle)

/**
 * @def OSError_CancelAlarm_AlarmID
 *
 * CancelAlarm service error parameter
 *
 * Returns the identifier (#AlarmType) of the alarm which caused error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSError_CancelAlarm_AlarmID()   \
    (tpl_service.parameters.id.alarm_id)

#endif /* defined WITH_ERROR_HOOK  */

/**
 * @def STORE_SERVICE
 *
 * Stores the service identifier into service error variable
 *
 * @see #OSErrorGetServiceId
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_SERVICE(service)   \
    tpl_service.service_id = (service);
#else
#   define STORE_SERVICE(service)
#endif

/**
 * @def STORE_TASK_ID
 *
 * Stores a task identifier into service error variable
 *
 * @param task_id type is #TaskType
 *
 * @see #OSError_ActivateTask_TaskID
 * @see #OSError_ChainTask_TaskID
 * @see #OSError_GetTaskID_TaskID
 * @see #OSError_GetTaskState_TaskID
 * @see #OSError_SetEvent_TaskID
 * @see #OSError_GetEvent_TaskID
 *
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TASK_ID(task_id)   \
    tpl_service.parameters.id.task_id = (task_id);
#else
#   define STORE_TASK_ID(task_id)
#endif

/**
 * @def STORE_TASK_ID_REF
 *
 * Stores a task identifier reference into service error variable
 *
 * @param task_id_ref type is #TaskRefType
 *
 * @see #OSError_GetTaskID_TaskID
 * @see #
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TASK_ID_REF(task_id_ref)  \
    tpl_service.parameters.id.task_id_ref = (task_id_ref);
#else
#   define STORE_TASK_ID_REF(task_id_ref)
#endif

/**
 * @def STORE_TASK_STATE_REF
 *
 * Stores a task state into service error variable
 *
 * @param state type is #TaslStateRefType
 *
 * @see #OSError_GetTaskState_State
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TASK_STATE_REF(state)  \
    tpl_service.parameters.param.state = (state);
#else
#   define STORE_TASK_STATE_REF(state)
#endif

/**
 * @def STORE_RESOURCE_ID
 *
 * Stores a resource identifier into service error variable
 *
 * @param res_id type is #ResourceType
 *
 * @see #OSError_GetResource_ResID
 * @see #OSError_ReleaseResource_ResID
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_RESOURCE_ID(res_id)    \
    tpl_service.parameters.id.res_id = (res_id);
#else
#   define STORE_RESOURCE_ID(res_id)
#endif

/**
 * @def STORE_ALARM_ID
 OSError_GetTaskState_State
 * Stores an alarm identifier into service error variable
 *
 * @param alarm_id type is #AlarmType
 *
 * @see #OSError_GetAlarmBase_AlarmID
 * @see #OSError_GetAlarm_AlarmID
 * @see #OSError_SetRelAlarm_AlarmID
 * @see #OSError_SetAbsAlarm_AlarmID
 * @see #OSError_CancelAlarm_AlarmID
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_ALARM_ID(alarm_id)     \
    tpl_service.parameters.id.alarm_id = (alarm_id);
#else
#   define STORE_ALARM_ID(alarm_id)
#endif

/**
 * @def STORE_ALARM_BASE_REF
 *
 * Stores an alarm base tick into service error variable
 *
 * @param ref type is #AlarmBaseRefType
 *
 * @see #OSError_GetAlarmBase_Info
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_ALARM_BASE_REF(ref)     \
    tpl_service.parameters.param.alarm_base_ref = (ref);
#else
#   define STORE_ALARM_BASE_REF(ref)
#endif

/**
 * @def STORE_TICK_REF
 *
 * Stores a tick reference into service error variable
 *
 * @param ref type is #TickRefType
 *
 * @see #OSError_GetAlarm_Tick
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TICK_REF(ref)     \
    tpl_service.parameters.param.tick_ref = (ref);
#else
#   define STORE_TICK_REF(tick_ref)
#endif

/**
 * @def STORE_TICK_1
 *
 * Stores a tick into service error variable
 *
 * @param t type is #TickType
 *
 * @see OSError_SetRelAlarm_increment
 * @see OSError_SetAbsAlarm_start
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TICK_1(t)     \
    tpl_service.parameters.param.tick = (t);
#else
#   define STORE_TICK_1(t)
#endif

/**
 * @def STORE_TICK_2
 *
 * Stores a cycle into service error variable
 *
 * @param t type is #TickType
 *
 * @see #OSError_SetRelAlarm_cycle
 * @see #OSError_SetAbsAlarm_cycle
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TICK_2(t)     \
    tpl_service.parameters.cycle = (t);
#else
#   define STORE_TICK_2(t)
#endif

/**
 * @def STORE_EVENT_MASK
 *
 * Stores an event mask into service error variable
 *
 * @param m type is #EventMaskType
 *
 * @see #OSError_SetEvent_Mask
 * @see #OSError_ClearEvent_Mask
 * @see #OSError_GetEvent_Event
 * @see #OSError_WaitEvent_Mask
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_EVENT_MASK(m)     \
    tpl_service.parameters.param.mask = (m);
#else
#   define STORE_EVENT_MASK(m)
#endif

/**
 * @def STORE_EVENT_MASK_REF
 *
 * Stores an event mask into service error variable
 *
 * @param ref type is #EventMaskRefType
 *
 * @todo Is this really useful ?
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_EVENT_MASK_REF(ref)     \
    tpl_service.parameters.param.mask_ref = (ref);
#else
#   define STORE_EVENT_MASK_REF(ref)
#endif

/**
 * @def PROCESS_ERROR
 *
 * This maccro generates the code to call the error hook, when
 * an error occured, if the #WITH_ERROR_HOOK flag is defined.
 *
 * @param error the error code variable to check
 */
#ifdef WITH_ERROR_HOOK
#define PROCESS_ERROR(error)        \
    if (error != E_OK) {            \
        tpl_call_error_hook(error); \
    }
#else
#define PROCESS_ERROR(error)
#endif

/**
 * @def IF_NO_EXTENDED_ERROR
 *
 * In conjonction with #END_IF_NO_EXTENDED_ERROR, this macro
 * can be used to enclose a section which should not be executed
 * while there is both :
 * - OS_EXTENDED defined
 * - an error occurred
 *
 * @param result the error code variable to check
 *
 * @see #END_IF_NO_EXTENDED_ERROR
 */
#ifdef OS_EXTENDED
#   define IF_NO_EXTENDED_ERROR(result) \
    if ((result) == E_OK) {
#else
#   define IF_NO_EXTENDED_ERROR(result)
#endif

/**
 * @def END_IF_NO_EXTENDED_ERROR
 *
 * Closes a #IF_NO_EXTENDED_ERROR opened section
 *
 * @see #IF_NO_EXTENDED_ERROR
 */
#ifdef OS_EXTENDED
#   define IF_NO_EXTENDED_ERROR_END() \
    }
#else
#   define IF_NO_EXTENDED_ERROR_END()
#endif

/**
 * @def LOCK_WHEN_HOOK
 *
 * Locks preemption only when #WITH_ERROR_HOOK is defined.
 *
 * Used for some services that does not require locking when
 * #WITH_ERROR_HOOK is not defined while it is needed when
 * #WITH_ERROR_HOOK is defined.
 *
 * @see #UNLOCK_WHEN_HOOK
 * @see #LOCK_WHEN_NO_HOOK
 */
#ifdef WITH_ERROR_HOOK
#   define LOCK_WHEN_HOOK()     \
    tpl_get_task_lock();
#   define UNLOCK_WHEN_HOOK()   \
    tpl_release_task_lock();
#else
#   define LOCK_WHEN_HOOK()
#   define UNLOCK_WHEN_HOOK()
#endif

/**
 * @def LOCK_WHEN_NO_HOOK
 *
 * Locks preemption only if #WITH_ERROR_HOOK is not defined. This is
 * the opposite of #LOCK_WHEN_HOOK.
 *
 * Used for some services that require different locking scheme
 * according to hook use.
 *
 * @see #UNLOCK_WHEN_NO_HOOK
 * @see #LOCK_WHEN_HOOK
 */
#ifdef WITH_ERROR_HOOK
#   define LOCK_WHEN_NO_HOOK()
#   define UNLOCK_WHEN_NO_HOOK()
#else
#   define LOCK_WHEN_NO_HOOK()     \
    tpl_get_task_lock();
#   define UNLOCK_WHEN_NO_HOOK()   \
    tpl_release_task_lock();
#endif

/**
 * @def LOCK_WHEN_TASK
 *
 * Locks only when NO_TASK is not defined.
 *
 * @see #UNLOCK_WHEN_TASK
 */
#ifdef NO_TASK
#   define LOCK_WHEN_TASK()
#   define UNLOCK_WHEN_TASK()
#else
#   define LOCK_WHEN_TASK()     \
    tpl_get_task_lock();
#   define UNLOCK_WHEN_TASK()   \
    tpl_release_task_lock();
#endif

/**
 * @def LOCK_WHEN_ISR
 *
 * Locks only when NO_ISR is not defined.
 *
 * @see #UNLOCK_WHEN_ISR
 */
#ifdef NO_ISR
#   define LOCK_WHEN_ISR()
#   define UNLOCK_WHEN_ISR()
#else
#   define LOCK_WHEN_ISR()     \
    tpl_get_task_lock();
#   define UNLOCK_WHEN_ISR()   \
    tpl_release_task_lock();
#endif

/**
 * @def LOCK_WHEN_TASK_OR_ISR
 *
 * Locks only when NO_TASK or NO_ISR is not defined.
 *
 * @see #UNLOCK_WHEN_TASK_OR_ISR
 */
#if defined(NO_ISR) && defined(NO_TASK)
#   define LOCK_WHEN_TASK_OR_ISR()
#   define UNLOCK_WHEN_TASK_OR_ISR()
#else
#   define LOCK_WHEN_TASK_OR_ISR()     \
    tpl_get_task_lock();
#   define UNLOCK_WHEN_TASK_OR_ISR()   \
    tpl_release_task_lock();
#endif

/**
 * @def LOCK_WHEN_RESOURCE
 *
 * Locks only when NO_RESOURCE is not defined.
 *
 * @see #UNLOCK_WHEN_RESOURCE
 */
#ifdef NO_RESOURCE
#   define LOCK_WHEN_RESOURCE()
#   define UNLOCK_WHEN_RESOURCE()
#else
#   define LOCK_WHEN_RESOURCE()     \
    tpl_get_task_lock();
#   define UNLOCK_WHEN_RESOURCE()   \
    tpl_release_task_lock();
#endif

/**
 * @def CHECK_TASK_ID_ERROR
 *
 * This macro checks for out of range task_id error. It
 * is used in os services which uses task_id as parameter.
 *
 * @param task_id #TaskType (so called task_id) to check
 * @param result error code variable to set (StatusType)
 *
 * @note this checking is disabled if OS_EXTENDED is not set
 *
 * @note the error code is set only if there was no
 * previous error
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the task_id in this case */
#   define CHECK_TASK_ID_ERROR(task_id,result)
#endif

/* NO_TASK and extended error checking (OS_EXTENDED)        */
#if defined(NO_TASK) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_TASK_ID_ERROR(task_id,result)                  \
    if (result == (tpl_status)E_OK)                                         \
    {                                                           \
        result = (tpl_status)E_OS_ID;                                       \
    }
#endif

/* !NO_TASK and extended error checking (OS_EXTENDED)   */
#if !defined(NO_TASK) && defined(OS_EXTENDED)
    /* E_OK or E_OS_LIMIT   */
#   define CHECK_TASK_ID_ERROR(task_id,result)                          \
    if  ((result == (tpl_status)E_OK) &&                                \
        (((task_id) >= (tpl_task_id)TASK_COUNT) || ((task_id) < 0)))    \
    {                                                                   \
        result = (tpl_status)E_OS_ID;                                   \
    }
#endif

/**
 * @def CHECK_TASK_CALL_LEVEL_ERROR
 *
 * This macro checks for inappropriate call level errors.
 *
 * @param result error code variable to set (#StatusType)
 *
 * @note checking is disabled if OS_EXTENDED is not defined
 *
 * @note the error code is set only if there was no previous error
 *
 * @see #tpl_os_state
 */

/*  NO_TASK and extended error checking (OS_EXTENDED).
    Since there is no task, there is no task level calling  */
#if defined(NO_TASK) && defined(OS_EXTENDED)
#   define CHECK_TASK_CALL_LEVEL_ERROR(result)                          \
    if (result == (tpl_status)E_OK)                                     \
    {                                                                   \
        result = (tpl_status)E_OS_CALLEVEL;                             \
    }
#endif

/*  !NO_TASK and extended error checking (OS_EXTENDED). */
#if !defined(NO_TASK) && defined(OS_EXTENDED)
#   define CHECK_TASK_CALL_LEVEL_ERROR(result)                          \
    if ((result == (tpl_status)E_OK) && (tpl_os_state != (u8)OS_TASK))  \
    {                                                                   \
        result = (tpl_status)E_OS_CALLEVEL;                             \
    }
#endif

/*  no extended error checking !(OS_EXTENDED).    */
#if !defined(OS_EXTENDED)
#   define CHECK_TASK_CALL_LEVEL_ERROR(result)
#endif

/**
 * @def CHECK_ISR2_CALL_LEVEL_ERROR
 *
 * This macro checks for inappropriate call level errors.
 *
 * @param result error code variable to set (#StatusType)
 *
 * @note checking is disabled if OS_EXTENDED is not defined
 *
 * @note the error code is set only if there was no previous error
 *
 * @see #tpl_os_state
 */

/*  NO_ISR and extended error checking (OS_EXTENDED).
    Since there is no ISR2, there is no ISR2 level calling  */
#if defined(NO_ISR) && defined(OS_EXTENDED)
#   define CHECK_ISR2_CALL_LEVEL_ERROR(result)                          \
    if (result == (tpl_status)E_OK)                                     \
    {                                                                   \
        result = (tpl_status)E_OS_CALLEVEL;                             \
    }
#endif

/*  !NO_ISR and extended error checking (OS_EXTENDED). */
#if !defined(NO_ISR) && defined(OS_EXTENDED)
#   define CHECK_ISR2_CALL_LEVEL_ERROR(result)                          \
    if ((result == (tpl_status)E_OK) && (tpl_os_state != (u8)OS_ISR2))  \
    {                                                                   \
        result = (tpl_status)E_OS_CALLEVEL;                             \
    }
#endif

/*  no extended error checking !(OS_EXTENDED).    */
#if !defined(OS_EXTENDED)
#   define CHECK_ISR2_CALL_LEVEL_ERROR(result)
#endif

/**
 * @def CHECK_NOT_EXTENDED_TASK_ERROR
 *
 * This macro checks if specified task is extended. If it is not, it
 * sets an error
 *
 * @param task_id task identifier (#TaskType) of the task to check
 * @param result error code to set if check fails (#StatusType)
 *
 * @note checking is disabled when OS_EXTENDED is not defined
 */
#ifdef OS_EXTENDED
#   define CHECK_NOT_EXTENDED_TASK_ERROR(task_id,result)            \
    if ((result == (tpl_status)E_OK) &&                             \
        (tpl_task_table[task_id]->exec_desc.static_desc->type !=    \
        (tpl_exec_obj_type)TASK_EXTENDED))                          \
    {                                                               \
        result = (tpl_status)E_OS_ACCESS;                           \
    }
#else
#   define CHECK_NOT_EXTENDED_TASK_ERROR(task_id,result)
#endif

/**
 * @def CHECK_NOT_EXTENDED_RUNNING_ERROR
 *
 * Does the same checking as #CHECK_NOT_EXTENDED_TASK_ERROR but for the
 * running task.
 *
 * @param result error code to set if check fails (#StatusType)
 *
 * @note checking is disabled when OS_EXTENDED is not defined
 */
#ifdef OS_EXTENDED
#   define CHECK_NOT_EXTENDED_RUNNING_ERROR(result)                     \
    if ((result == (tpl_status)E_OK) &&                                 \
        (((tpl_task *)tpl_running_obj)->exec_desc.static_desc->type !=  \
        (tpl_exec_obj_type)TASK_EXTENDED)) {                            \
        result = (tpl_status)E_OS_ACCESS;                               \
    }
#else
#   define CHECK_NOT_EXTENDED_RUNNING_ERROR(result)
#endif

/**
 * @def CHECK_SUSPENDED_TASK_ERROR
 *
 * Checks if task is not suspended (check fails if task is suspended) and
 * sets the error code
 *
 * @param task_id task (#TaskType) to check
 * @param result error code to set if check fails (#StatusType)
 *
 * @note checking is disabled when OS_EXTENDED is not defined
 */
#ifdef OS_EXTENDED
#   define CHECK_SUSPENDED_TASK_ERROR(task_id,result)                   \
    if ((result == (tpl_status)E_OK) &&                                 \
        (tpl_task_table[task_id]->exec_desc.state ==                    \
        (tpl_exec_state)SUSPENDED))                                     \
    {                                                                   \
        result = (tpl_status)E_OS_STATE;                                \
    }
#else
#   define CHECK_SUSPENDED_TASK_ERROR(task_id,result)
#endif


/**
 * @def CHECK_RUNNING_OWNS_REZ_ERROR
 *
 * Checks if the running task owns a resource, if not, sets an error.
 *
 * @param result error code (#StatusType) to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 */

/*  If NO_TASK, this error cannot happen    */
#if defined(NO_TASK)
#   define CHECK_RUNNING_OWNS_REZ_ERROR(result)
#endif

/*  If !NO_TASK and not extended error checking !(OS_EXTENDED)
    the occurence is not tested                                 */
#if !defined(NO_TASK) && !defined(OS_EXTENDED)
#   define CHECK_RUNNING_OWNS_REZ_ERROR(result)
#endif

/*  If !NO_TASK and extended error checking (OS_EXTENTED)   */
#if !defined(NO_TASK) && defined(OS_EXTENDED)
#   define CHECK_RUNNING_OWNS_REZ_ERROR(result)                 \
    if ((result == (tpl_status)E_OK) &&                         \
        ((tpl_running_obj->resources) != NULL))                 \
    {                                                           \
        result = (tpl_status)E_OS_RESOURCE;                     \
    }
#endif

/**
 * @def CHECK_ALARM_ID_ERROR
 *
 * Checks if alarm_id is a valid alarm identifier.
 *
 * @param alarm_id #AlarmType to check
 * @param result error code to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the task_id in this case */
#   define CHECK_ALARM_ID_ERROR(alarm_id,result)
#endif

/* NO_ALARM and extended error checking (OS_EXTENDED)        */
#if defined(NO_ALARM) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_ALARM_ID_ERROR(alarm_id,result)                \
    if (result == (tpl_status)E_OK)                             \
    {                                                           \
        result = (tpl_status)E_OS_ID;                           \
    }
#endif

/* !NO_ALARM and extended error checking (OS_EXTENDED)   */
#if !defined(NO_ALARM) && defined(OS_EXTENDED)
    /* E_OK or E_OS_LIMIT   */
#   define CHECK_ALARM_ID_ERROR(alarm_id,result)                \
    if ((result == (tpl_status)E_OK) &&                         \
        ((alarm_id) >= (tpl_alarm_id)ALARM_COUNT))              \
    {                                                           \
        result = (tpl_status)E_OS_ID;                           \
    }
#endif

/**
 * @def CHECK_ALARM_MAX_ALLOWED_VALUE_ERROR
 *
 * Checks if increment is within the range of the maximum
 * allowed value for the counter used by the alarm
 *
 * @param increment #TickType to check
 * @param result    error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 */

/* No extended error checking (! OS_EXTENDED)                   */
#if !defined(OS_EXTENDED)
    /* Does not check the task_id in this case                  */
#   define CHECK_ALARM_MAX_ALLOWED_VALUE_ERROR(alarm_id,increment,result)
#endif

/* NO_ALARM and extended error checking (OS_EXTENDED)           */
#if defined(NO_ALARM) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_ALARM_MAX_ALLOWED_VALUE_ERROR(alarm_id,increment,result)
#endif

/* !NO_ALARM and extended error checking (OS_EXTENDED)          */
#if !defined(NO_ALARM) && defined(OS_EXTENDED)
    /* E_OK or E_OS_VALUE   */
#   define CHECK_ALARM_MAX_ALLOWED_VALUE_ERROR(alarm_id,increment,result)     \
    if ((result == (tpl_status)E_OK) &&                                       \
        ((increment) >                                                        \
         tpl_alarm_table[(alarm_id)]->stat_part->counter->max_allowed_value)) \
    {                                                                         \
        result = (tpl_status)E_OS_VALUE;                                      \
    }
#endif

/**
 * @def CHECK_ALARM_MIN_CYCLE_VALUE_ERROR
 *
 * Checks if cycle is within the range of minimum cycle time and
 * the maximum allowed value for the counter used by the alarm
 *
 * @param cycle     #TickType to check
 * @param result    error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 */

/* No extended error checking (! OS_EXTENDED)                   */
#if !defined(OS_EXTENDED)
    /* Does not check the task_id in this case                  */
#   define CHECK_ALARM_MIN_CYCLE_ERROR(alarm_id,cycle,result)
#endif

/* NO_ALARM and extended error checking (OS_EXTENDED)           */
#if defined(NO_ALARM) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_ALARM_MIN_CYCLE_ERROR(alarm_id,cycle,result)
#endif

/* !NO_ALARM and extended error checking (OS_EXTENDED)          */
#if !defined(NO_ALARM) && defined(OS_EXTENDED)
    /* E_OK or E_OS_LIMIT   */
#   define CHECK_ALARM_MIN_CYCLE_ERROR(alarm_id,cycle,result)                 \
    if ((result == (tpl_status)E_OK) && ((cycle) != 0) &&                     \
        (((cycle) >                                                           \
         tpl_alarm_table[(alarm_id)]->stat_part->counter->max_allowed_value)  \
         ||                                                                   \
         ((cycle) <                                                           \
         tpl_alarm_table[(alarm_id)]->stat_part->counter->min_cycle)))        \
    {                                                                         \
        result = (tpl_status)E_OS_VALUE;                                      \
    }
#endif

/**
 * @def CHECK_RESOURCE_ID_ERROR
 *
 * Checks if the resouce identifier (#ResourceType) is valid.
 *
 * @param res_id #ResourceType to check
 * @param result error code to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the task_id in this case */
#   define CHECK_RESOURCE_ID_ERROR(res_id,result)
#endif

/* NO_RESOURCE and extended error checking (OS_EXTENDED)    */
#if defined(NO_RESOURCE) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_RESOURCE_ID_ERROR(res_id,result)               \
    if ((result == (tpl_status)E_OK) &&                         \
        ((res_id) != (tpl_resource_id)RES_SCHEDULER))           \
    {                                                           \
        result = (tpl_status)E_OS_ID;                           \
    }
#endif

/* !NO_TASK and extended error checking (OS_EXTENDED)   */
#if !defined(NO_RESOURCE) && defined(OS_EXTENDED)
    /* E_OK or E_OS_LIMIT   */
#   define CHECK_RESOURCE_ID_ERROR(res_id,result)               \
    if ((result == (tpl_status)E_OK) &&                         \
        (((res_id) >= ((tpl_resource_id)RESOURCE_COUNT+1)) ||   \
         ((res_id) < 0)))                     \
    {                                                           \
        result = (tpl_status)E_OS_ID;                           \
    }
#endif

/**
 * @def CHECK_RESOURCE_PRIO_ERROR_ON_GET
 *
 * Checks if the running task or interrupt can get the resource.
 * Especially, it checks that :
 * - the task does not have an higher priority than
 *   the ceiling priority of the resource it gets.
 * - the resource is not owned by another task
 *
 * @param res the resource (#ResourceType) the task get
 * @param result error code to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 */

#ifdef OS_EXTENDED
#   define CHECK_RESOURCE_PRIO_ERROR_ON_GET(res,result)         \
    if ((result == (tpl_status)E_OK) &&                         \
        (((res)->owner != NULL) ||                              \
         (tpl_running_obj->static_desc->base_priority >         \
          res->ceiling_priority)))                              \
    {                                                           \
        result = (tpl_status)E_OS_ACCESS;                       \
    }
#else
#   define CHECK_RESOURCE_PRIO_ERROR_ON_GET(res,result)
#endif

/**
 * @def CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE
 *
 * Checks if the running task or interrupt can release the resource.
 *
 * @param res the resource (#ResourceType) the task releases
 * @param result error code to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 */

#ifdef OS_EXTENDED
#   define CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(res,result)     \
    if ((result == (tpl_status)E_OK) &&                         \
        (tpl_running_obj->static_desc->base_priority >          \
         (res)->ceiling_priority))                              \
    {                                                           \
        result = (tpl_status)E_OS_ACCESS;                       \
    }
#else
#   define CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(res,result)
#endif

/**
 * @def CHECK_RESOURCE_ORDER_ON_RELEASE
 *
 * Checks if a resource is released by the running task or interrupt in the
 * right order
 *
 * @param res #ResourceType to check
 * @param result error code to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 */

#ifdef OS_EXTENDED
#   define CHECK_RESOURCE_ORDER_ON_RELEASE(res,result)          \
    if ((result == (tpl_status)E_OK) &&                         \
        (((res)->owner == NULL) ||                              \
         (tpl_running_obj->resources != (res))))                \
    {                                                           \
        result = (tpl_status)E_OS_NOFUNC;                       \
    }
#else
#   define CHECK_RESOURCE_ORDER_ON_RELEASE(res,result)
#endif

#endif /*TPL_OS_ERROR_H */

/* End of file tpl_os_error.h */
