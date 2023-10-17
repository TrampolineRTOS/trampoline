/**
 * @file tpl_os_error.h
 *
 * @section descr File description
 *
 * Trampoline Errors macros, functions and datatypes header
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS,
 * University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
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

#ifndef TPL_OS_ERROR_H
#define TPL_OS_ERROR_H

#include "tpl_os_types.h"

#if WITH_USEGETSERVICEID == YES
#include "tpl_service_ids.h"
#endif

#if WITH_AUTOSAR == YES
#include "tpl_as_application.h"
#include "tpl_os_timeobj_kernel.h"
#endif

#if WITH_ORTI == YES

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#if NUMBER_OF_CORES > 1
extern VAR(tpl_status, OS_VAR) tpl_last_error[NUMBER_OF_CORES];
#define TPL_LAST_ERROR(core) tpl_last_error[core]
#else
extern VAR(tpl_status, OS_VAR) tpl_last_error;
#define TPL_LAST_ERROR(core) tpl_last_error
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
extern FUNC(tpl_bool, OS_CODE) tpl_get_interrupt_lock_status(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/*
 * Remember (see "The design of Trampoline") :
 * WITH_OS_EXTENDED == YES means extended error checking is done
 * WITH_ERROR_HOOK == YES means an error hook routine is called when
 * an error occurs.
 */

#if WITH_ERROR_HOOK == YES

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
extern FUNC(void, OS_CODE)
    tpl_call_error_hook(CONST(tpl_status, AUTOMATIC) error);
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
union ID_PARAM_BLOCK
{
  VAR(tpl_task_id, TYPEDEF)
  task_id;                                            /**< used by
                                                          #ActivateTask,
                                                          #ChainTask,
                                                          #GetTaskState,
                                                          #SetEvent,
                                                          #GetEvent
                                                       */
  P2VAR(tpl_task_id, AUTOMATIC, TYPEDEF) task_id_ref; /**< used by #GetTaskID */
  VAR(tpl_resource_id, TYPEDEF)
  res_id; /**< used by #GetResource,
               #ReleaseResource
           */
  VAR(tpl_alarm_id, TYPEDEF)
  alarm_id; /**< used by #SetRelAlarm, #SetAbsAlarm,
                 #CancelAlarm, #GetAlarm and
                 #GetAlarmBase
             */
  VAR(tpl_application_mode, TYPEDEF) mode; /**< used by StartOS */

#if WITH_AUTOSAR == YES
  VAR(tpl_schedtable_id, TYPEDEF) schedtable_id; /**< @todo document this */
  VAR(tpl_counter_id, TYPEDEF) counter_id;       /**< @todo document this */
  VAR(tpl_app_id, TYPEDEF) application_id;       /**< @todo document this */
#endif
#if WITH_IOC == YES
  VAR(tpl_ioc_id, TYPEDEF)
  ioc_id; /**< used by
                                           #IOC_Send
                                           #IOC_Receive
                                           #IOC_Write
                                           #IOC_Read
                                           */
#endif
#if NUMBER_OF_CORES > 1
  VAR(tpl_core_id, TYPEDEF)
  core_id;                                   /**< used by StartCore and
                                                  StartNonAutosarCore   */
  VAR(tpl_spinlock_id, TYPEDEF) spinlock_id; /**< @todo document this */
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
union PARAM_PARAM_BLOCK
{
  P2VAR(tpl_proc_state, AUTOMATIC, TYPEDEF)
  state;                       /**< used by #GetTaskState
                                */
  VAR(tpl_tick, TYPEDEF) tick; /**< used by #SetRelAlarm, #SetAbsAlarm */
  P2VAR(tpl_tick, AUTOMATIC, TYPEDEF) tick_ref; /**< used by #GetAlarm */
  P2VAR(tpl_alarm_base, AUTOMATIC, TYPEDEF)
  alarm_base_ref; /**< used by
                       #GetAlarmBase
                   */
  VAR(tpl_event_mask, TYPEDEF)
  mask;                                               /**< used by #SetEvent,
                                                           #ClearEvent,
                                                           #WaitEvent
                                                       */
  P2VAR(tpl_event_mask, AUTOMATIC, TYPEDEF) mask_ref; /**< used by #GetEvent */
#if WITH_AUTOSAR == YES
  VAR(tpl_schedtable_id, TYPEDEF) next_st_id; /**< @todo document this */
  P2VAR(tpl_time_obj_state, AUTOMATIC, TYPEDEF)
  st_stat;                                  /**< @todo document
                                                 this
                                             */
  VAR(ObjectTypeType, TYPEDEF) object_type; /**< @todo document this */
  VAR(uint8, TYPEDEF) opt_termapp;          /**< @todo document this */
#endif
};

union PARAM_PARAM_BLOCK_2
{
  VAR(tpl_tick, TYPEDEF) tick; /**< used by #SetRelAlarm, #SetAbsAlarm */
  P2VAR(tpl_tick, AUTOMATIC, TYPEDEF)
  tick_ref; /**< used by
                 #GetElapsedCounterValue
             */
#if WITH_AUTOSAR == YES
  VAR(tpl_generic_id, TYPEDEF) object_id; /**< @todo document this  */
#endif
};

/**
 * @struct PARAM_BLOCK
 *
 * This structure gathers all parameters for an error hook
 */
struct PARAM_BLOCK
{
  union ID_PARAM_BLOCK id;          /**< identifies the OS element
                                         concerned by the error */
  union PARAM_PARAM_BLOCK param;    /**< gives more information about the
                                         reason of the error    */
  union PARAM_PARAM_BLOCK_2 param2; /**< more informations      */
};

/**
 * @struct SERVICE_CALL_DESCRIPTOR
 *
 * This structure gathers the os service identifier and its parameters
 */
struct SERVICE_CALL_DESCRIPTOR
{
  struct PARAM_BLOCK parameters; /**< information about conditions seen
                                      when error has been detected */
  VAR(uint8, TYPEDEF)
  service_id; /**< identifier of the service which
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
 * - #OSError_StartOS_Mode
 *
 * Within OS services, these macros should be used to modify this variable :
 * - #STORE_SERVICE
 * - #STORE_TASK_ID
 * - #STORE_TASK_ID_REF
 * - #STORE_TASK_STATE_REF
 * - #STORE_RESOURCE_ID
 * - #STORE_ALARM_ID
 * - #STORE_ALARM_BASE_REF
 * - #STORE_TICK_REF_1
 * - #STORE_TICK_REF_2
 * - #STORE_TICK_1
 * - #STORE_TICK_2
 * - #STORE_EVENT_MASK
 * - #STORE_EVENT_MASK_REF
 * - #STORE_MODE
 */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

extern VAR(tpl_service_call_desc, OS_VAR) tpl_service;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

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
#if WITH_USEGETSERVICEID == YES
#define OSErrorGetServiceId() (tpl_service.service_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_ActivateTask_TaskID() (tpl_service.parameters.id.task_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_ChainTask_TaskID() (tpl_service.parameters.id.task_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetTaskID_TaskID() (tpl_service.parameters.id.task_id_ref)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetTaskState_TaskID() (tpl_service.parameters.id.task_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetTaskState_State() (tpl_service.parameters.param.state)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetResource_ResID() (tpl_service.parameters.id.res_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_ReleaseResource_ResID() (tpl_service.parameters.id.res_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SetEvent_TaskID() (tpl_service.parameters.id.task_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SetEvent_Mask() (tpl_service.parameters.param.mask)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_ClearEvent_Mask() (tpl_service.parameters.param.mask)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetEvent_TaskID() (tpl_service.parameters.id.task_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetEvent_Event() (tpl_service.parameters.param.mask)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_WaitEvent_Mask() (tpl_service.parameters.param.mask)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetAlarmBase_AlarmID() (tpl_service.parameters.id.alarm_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetAlarmBase_Info()                                            \
  (tpl_service.parameters.param.alarm_base_ref)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetAlarm_AlarmID() (tpl_service.parameters.id.alarm_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetAlarm_Tick() (tpl_service.parameters.param.tick_ref)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SetRelAlarm_AlarmID() (tpl_service.parameters.id.alarm_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SetRelAlarm_increment() (tpl_service.parameters.param.tick)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SetRelAlarm_cycle() (tpl_service.parameters.param2.tick)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SetAbsAlarm_AlarmID() (tpl_service.parameters.id.alarm_id)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SetAbsAlarm_start() (tpl_service.parameters.param.tick)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SetAbsAlarm_cycle() (tpl_service.parameters.param2.tick)
#endif

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
#if WITH_USEPARAMETERACCESS == YES
#define OSError_CancelAlarm_AlarmID() (tpl_service.parameters.id.alarm_id)
#endif

/**
 * @def OSError_StartOS_Mode
 *
 * StartOS service error parameter
 *
 * Returns the identifier (#AppModeType) of the application mode
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_StartOS_Mode() (tpl_service.parameters.id.mode)
#endif

#if WITH_IOC == YES
/**
 * @def OSError_IOC_Send_IocID
 *
 * IOC_Send service error parameter
 *
 * Returns the identifier (#tpl_ioc_id) of the ioc which caused error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_IOC_Send_IocID() (tpl_service.parameters.id.ioc_id)
#endif

/**
 * @def OSError_IOC_Send_IocID
 *
 * IOC_Send service error parameter
 *
 * Returns the identifier (#tpl_ioc_id) of the ioc which caused error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_IOC_Receive_IocID() (tpl_service.parameters.id.ioc_id)
#endif

/**
 * @def OSError_IOC_Send_IocID
 *
 * IOC_Send service error parameter
 *
 * Returns the identifier (#tpl_ioc_id) of the ioc which caused error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_IOC_Write_IocID() (tpl_service.parameters.id.ioc_id)
#endif

/**
 * @def OSError_IOC_Send_IocID
 *
 * IOC_Send service error parameter
 *
 * Returns the identifier (#tpl_ioc_id) of the ioc which caused error
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_IOC_Read_IocID() (tpl_service.parameters.id.ioc_id)
#endif
#endif /* WITH_IOC == YES */

#endif /* defined WITH_ERROR_HOOK  */

/**
 * @def STORE_SERVICE
 *
 * Stores the service identifier into service error variable
 *
 * @see #OSErrorGetServiceId
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEGETSERVICEID == YES)
#define STORE_SERVICE(service) tpl_service.service_id = (service);
#else
#define STORE_SERVICE(service)
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
 * @see #OSError_GetTaskState_TaskID
 * @see #OSError_SetEvent_TaskID
 * @see #OSError_GetEvent_TaskID
 *
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_TASK_ID(taskid) tpl_service.parameters.id.task_id = (taskid);
#else
#define STORE_TASK_ID(taskid)
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
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_TASK_ID_REF(taskidref)                                           \
  tpl_service.parameters.id.task_id_ref = (taskidref);
#else
#define STORE_TASK_ID_REF(taskidref)
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
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_TASK_STATE_REF(state)                                            \
  tpl_service.parameters.param.state = (state);
#else
#define STORE_TASK_STATE_REF(state)
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
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_RESOURCE_ID(res_id) tpl_service.parameters.id.res_id = (res_id);
#else
#define STORE_RESOURCE_ID(res_id)
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
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_ALARM_ID(alarm_id)                                               \
  tpl_service.parameters.id.alarm_id = (alarm_id);
#else
#define STORE_ALARM_ID(alarm_id)
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
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_ALARM_BASE_REF(ref)                                              \
  tpl_service.parameters.param.alarm_base_ref = (ref);
#else
#define STORE_ALARM_BASE_REF(ref)
#endif

/**
 * @def STORE_TICK_REF_1
 *
 * Stores a tick reference into service error variable
 *
 * @param ref type is #TickRefType
 *
 * @see #OSError_GetAlarm_Tick
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_TICK_REF_1(ref) tpl_service.parameters.param.tick_ref = (ref);
#else
#define STORE_TICK_REF_1(ref)
#endif

/**
 * @def STORE_TICK_REF_2
 *
 * Stores a tick reference into service error variable
 *
 * @param ref type is #TickRefType
 *
 * @see #OSError_GetAlarm_Tick
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_TICK_REF_2(ref) tpl_service.parameters.param2.tick_ref = (ref);
#else
#define STORE_TICK_REF_2(ref)
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
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_TICK_1(t) tpl_service.parameters.param.tick = (t);
#else
#define STORE_TICK_1(t)
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
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_TICK_2(t) tpl_service.parameters.param2.tick = (t);
#else
#define STORE_TICK_2(t)
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
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_EVENT_MASK(m) tpl_service.parameters.param.mask = (m);
#else
#define STORE_EVENT_MASK(m)
#endif

/**
 * @def STORE_EVENT_MASK_REF
 *
 * Stores an event mask into service error variable
 *
 * @param ref type is #EventMaskRefType
 *
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_EVENT_MASK_REF(ref) tpl_service.parameters.param.mask_ref = (ref);
#else
#define STORE_EVENT_MASK_REF(ref)
#endif

/**
 * @def STORE_IOC_ID
 *
 * Stores an ioc identifier into service error variable
 *
 * @param ioc_id type is #tpl_ioc_id
 *
 * @see #OSError_IOC_Send_IocID
 * @see #OSError_IOC_Receive_IocID
 * @see #OSError_IOC_Write_IocID
 * @see #OSError_IOC_Read_IocID
 *
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES) &&            \
    (WITH_IOC == YES)
#define STORE_IOC_ID(iocid) tpl_service.parameters.id.ioc_id = (iocid);
#else
#define STORE_IOC_ID(iocid)
#endif

/**
 * @def STORE_MODE
 *
 * Stores an application mode into service error variable
 *
 * @param mode type is #AppModeType
 *
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#define STORE_MODE(mode) tpl_service.parameters.id.mode = (mode);
#else
#define STORE_MODE(mode)
#endif

/**
 * @def STORE_CORE_ID
 *
 * Stores a core identifier
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES) &&            \
    (NUMBER_OF_CORES > 1)
#define STORE_CORE_ID(core_id) tpl_service.parameters.id.core_id = (core_id);
#else
#define STORE_CORE_ID(core_id)
#endif

/**
 * @def STORE_SPINLOCK_ID
 *
 * Stores a spinlock identifier into service error variable
 *
 * @param spinlock_id type is #tpl_spinlock_id
 *
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES) &&            \
    (WITH_SPINLOCK == YES)
#define STORE_SPINLOCK_ID(spinlockid)                                          \
  tpl_service.parameters.id.spinlock_id = (spinlockid);
#else
#define STORE_SPINLOCK_ID(spinlockid)
#endif

/**
 * @def PROCESS_ERROR
 *
 * This maccro generates the code to call the error hook, when
 * an error occured, if the #WITH_ERROR_HOOK flag is defined.
 *
 * It sets the "last_error" variable if the WITH_ORTI flag is defined
 *
 * @param error the error code variable to check
 */
#if WITH_ERROR_HOOK == YES
#define PROCESS_ERROR_ERRHOOK(error) tpl_call_error_hook(error);
#else
#define PROCESS_ERROR_ERRHOOK(error)
#endif

#if WITH_ORTI == YES
#define PROCESS_ERROR_ORTI(error)                                              \
  {                                                                            \
    GET_CURRENT_CORE_ID(core_id)                                               \
    TPL_LAST_ERROR(core_id) = error;                                           \
  }
#else
#define PROCESS_ERROR_ORTI(error)
#endif

#if (WITH_ERROR_HOOK == YES) || (WITH_ORTI == YES)
#define PROCESS_ERROR(error)                                                   \
  if ((error) != E_OK)                                                         \
  {                                                                            \
    PROCESS_ERROR_ERRHOOK(error)                                               \
    PROCESS_ERROR_ORTI(error)                                                  \
  }
#else
#define PROCESS_ERROR(error)
#endif

/**
 * @def LOCK_KERNEL
 *
 * This macro locks the kernel when WITH_SYSTEM_CALL is not
 * defined. If WITH_SYSTEM_CALL is defined it does nothing
 */
#if WITH_SYSTEM_CALL == YES
#define LOCK_KERNEL()
#else
#define LOCK_KERNEL() tpl_get_task_lock();
#endif

/**
 * @def UNLOCK_KERNEL
 *
 * This macro unlocks the kernel when WITH_SYSTEM_CALL is not
 * defined. If WITH_SYSTEM_CALL is defined it does nothing
 */
#if WITH_SYSTEM_CALL == YES
#define UNLOCK_KERNEL()
#else
#define UNLOCK_KERNEL() tpl_release_task_lock();
#endif

/**
 * @def IF_NO_EXTENDED_ERROR
 *
 * In conjonction with #END_IF_NO_EXTENDED_ERROR, this macro
 * can be used to enclose a section which should not be executed
 * while there is both :
 * - WITH_OS_EXTENDED == YES
 * - an error occurred
 *
 * @param result the error code variable to check
 *
 * @see #END_IF_NO_EXTENDED_ERROR
 */
#if WITH_OS_EXTENDED == YES
#define IF_NO_EXTENDED_ERROR(result) if ((result) == E_OK)
#else
#define IF_NO_EXTENDED_ERROR(result)
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
 * @note this checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no
 * previous error
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if WITH_OS_EXTENDED == NO
/* Does not check the task_id in this case */
#define CHECK_TASK_ID_ERROR(task_id, result)
#endif

/* No Task and extended error checking (WITH_OS_EXTENDED == YES)        */
#if (TASK_COUNT == 0) && (WITH_OS_EXTENDED == YES)
/* E_OS_ID is returned in this case  */
#define CHECK_TASK_ID_ERROR(task_id, result)                                   \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = (tpl_status)E_OS_ID;                                              \
  }
#endif

/* Any Task and extended error checking (WITH_OS_EXTENDED == YES)   */
#if (TASK_COUNT > 0) && (WITH_OS_EXTENDED == YES)
/* E_OK or E_OS_LIMIT   */
#define CHECK_TASK_ID_ERROR(task_id, result)                                   \
  if ((result == (tpl_status)E_OK) &&                                          \
      (((task_id) >= (tpl_task_id)TASK_COUNT) || ((task_id) < 0)))             \
  {                                                                            \
    result = (tpl_status)E_OS_ID;                                              \
  }
#endif

/**
 * @def CHECK_TASK_CALL_LEVEL_ERROR
 *
 * This macro checks for inappropriate call level errors.
 *
 * @param result error code variable to set (#StatusType)
 *
 * @note checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no previous error
 *
 * @see #tpl_os_state
 */

/*  No Task and extended error checking (WITH_OS_EXTENDED == YES).
    Since there is no task, there is no task level calling  */
#if (TASK_COUNT == 0) && (WITH_OS_EXTENDED == YES)
#define CHECK_TASK_CALL_LEVEL_ERROR(a_core_id, result)                         \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = (tpl_status)E_OS_CALLEVEL;                                        \
  }
#endif

/*  Any Task and extended error checking (WITH_OS_EXTENDED == YES). */
#if (TASK_COUNT > 0) && (WITH_OS_EXTENDED == YES)
#define CHECK_TASK_CALL_LEVEL_ERROR(a_core_id, result)                         \
  if ((result == (tpl_status)E_OK) &&                                          \
      (tpl_current_os_state(CORE_ID_OR_NOTHING(a_core_id)) !=                  \
       (tpl_os_state)OS_TASK))                                                 \
  {                                                                            \
    result = (tpl_status)E_OS_CALLEVEL;                                        \
  }
#endif

/*  no extended error checking (WITH_OS_EXTENDED == NO).    */
#if WITH_OS_EXTENDED == NO
#define CHECK_TASK_CALL_LEVEL_ERROR(a_core_id, result)
#endif

/**
 * @def CHECK_ISR2_CALL_LEVEL_ERROR
 *
 * This macro checks for inappropriate call level errors.
 *
 * @param result error code variable to set (#StatusType)
 *
 * @note checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no previous error
 *
 * @see #tpl_os_state
 */

/*  No ISR and extended error checking (WITH_OS_EXTENDED == YES).
    Since there is no ISR2, there is no ISR2 level calling  */
#if (ISR_COUNT == 0) && (WITH_OS_EXTENDED == YES)
#define CHECK_ISR2_CALL_LEVEL_ERROR(result, core_id)                           \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = (tpl_status)E_OS_CALLEVEL;                                        \
  }
#endif

/*  Any ISR and extended error checking (WITH_OS_EXTENDED == YES). */
#if (ISR_COUNT > 0) && (WITH_OS_EXTENDED == YES)
#define CHECK_ISR2_CALL_LEVEL_ERROR(result, core_id)                           \
  if ((result == (tpl_status)E_OK) &&                                          \
      (tpl_current_os_state(CORE_ID_OR_NOTHING(core_id)) !=                    \
       (tpl_os_state)OS_ISR2))                                                 \
  {                                                                            \
    result = (tpl_status)E_OS_CALLEVEL;                                        \
  }
#endif

/*  no extended error checking (WITH_OS_EXTENDED == NO).    */
#if WITH_OS_EXTENDED == NO
#define CHECK_ISR2_CALL_LEVEL_ERROR(result, core_id)
#endif

/**
 * @def CHECK_CALLBACK_CALL_LEVEL_ERROR
 *
 * This macro checks for alarm callback call level errors.
 *
 * @param result error code variable to set (#StatusType)
 *
 * @note checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no previous error
 *
 * @see #tpl_os_state
 */
#if WITH_OS_EXTENDED == YES
#define CHECK_CALLBACK_CALL_LEVEL_ERROR(result, core_id)                       \
  if ((result == (tpl_status)E_OK) && tpl_alarm_callback_running())            \
  {                                                                            \
    result = (tpl_status)E_OS_CALLEVEL;                                        \
  }
#endif

/*  no extended error checking (WITH_OS_EXTENDED == NO).    */
#if WITH_OS_EXTENDED == NO
#define CHECK_CALLBACK_CALL_LEVEL_ERROR(result, core_id)
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
 * @note error code is not set if it does not equal E_OK
 * @note checking is disabled when WITH_OS_EXTENDED == NO
 */
#if WITH_OS_EXTENDED == YES
#define CHECK_NOT_EXTENDED_TASK_ERROR(task_id, result)                         \
  if ((result == (tpl_status)E_OK) &&                                          \
      (tpl_stat_proc_table[task_id]->type != (tpl_proc_type)TASK_EXTENDED))    \
  {                                                                            \
    result = (tpl_status)E_OS_ACCESS;                                          \
  }
#else
#define CHECK_NOT_EXTENDED_TASK_ERROR(task_id, result)
#endif

/**
 * @def CHECK_NOT_EXTENDED_RUNNING_ERROR
 *
 * Does the same checking as #CHECK_NOT_EXTENDED_TASK_ERROR but for the
 * running task.
 *
 * @param result error code to set if check fails (#StatusType)
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disabled when WITH_OS_EXTENDED == NO
 */
#if WITH_OS_EXTENDED == YES
#define CHECK_NOT_EXTENDED_RUNNING_ERROR(a_core_id, result)                    \
  if ((result == (tpl_status)E_OK) &&                                          \
      (TPL_KERN(a_core_id).running_id >= EXTENDED_TASK_COUNT))                 \
  {                                                                            \
    result = (tpl_status)E_OS_ACCESS;                                          \
  }
#else
#define CHECK_NOT_EXTENDED_RUNNING_ERROR(a_core_id, result)
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
 * @note error code is not set if it does not equal E_OK
 * @note checking is disabled when WITH_OS_EXTENDED == NO
 */
#if WITH_OS_EXTENDED == YES
#define CHECK_SUSPENDED_TASK_ERROR(task_id, result)                            \
  if ((result == (tpl_status)E_OK) &&                                          \
      (tpl_dyn_proc_table[task_id]->state == (tpl_proc_state)SUSPENDED))       \
  {                                                                            \
    result = (tpl_status)E_OS_STATE;                                           \
  }
#else
#define CHECK_SUSPENDED_TASK_ERROR(task_id, result)
#endif

/**
 * @def CHECK_RUNNING_OWNS_REZ_ERROR
 *
 * Checks if the running task owns a resource, if not, sets an error.
 *
 * @param result error code (#StatusType) to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disabled when WITH_OS_EXTENDED == NO
 */

/*  If no Task, this error cannot happen    */
#if TASK_COUNT == 0
#define CHECK_RUNNING_OWNS_REZ_ERROR(a_core_id, result)
#endif

/*  If any Task and not extended error checking (WITH_OS_EXTENDED == NO)
    the occurence is not tested                                 */
#if (TASK_COUNT > 0) && (WITH_OS_EXTENDED == NO)
#define CHECK_RUNNING_OWNS_REZ_ERROR(a_core_id, result)
#endif

/*  If any Task and extended error checking (WITH_OS_EXTENDED == YES) */
#if (TASK_COUNT > 0) && (WITH_OS_EXTENDED == YES)
#define CHECK_RUNNING_OWNS_REZ_ERROR(a_core_id, result)                        \
  if ((result == (tpl_status)E_OK) &&                                          \
      ((TPL_KERN(a_core_id).running->resources) != NULL))                      \
  {                                                                            \
    result = (tpl_status)E_OS_RESOURCE;                                        \
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
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
/* Does not check the task_id in this case */
#define CHECK_ALARM_ID_ERROR(alarm_id, result)
#endif

/* No Alarm and extended error checking (WITH_OS_EXTENDED == YES)   */
#if (ALARM_COUNT == 0) && (WITH_OS_EXTENDED == YES)
/* E_OS_ID is returned in this case  */
#define CHECK_ALARM_ID_ERROR(alarm_id, result)                                 \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = (tpl_status)E_OS_ID;                                              \
  }
#endif

/* Any Alarm and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (ALARM_COUNT > 0) && (WITH_OS_EXTENDED == YES)
/* E_OK or E_OS_LIMIT   */
#define CHECK_ALARM_ID_ERROR(alarm_id, result)                                 \
  if ((result == (tpl_status)E_OK) &&                                          \
      ((alarm_id) >= (tpl_alarm_id)ALARM_COUNT))                               \
  {                                                                            \
    result = (tpl_status)E_OS_ID;                                              \
  }
#endif

/**
 * @def CHECK_ALARM_INCREMENT_ERROR
 *
 * Checks if increment is within the range of the maximum
 * allowed value for the counter used by the alarm
 *
 * @param increment #TickType to check
 * @param result    error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
/* Does not check the task_id in this case                  */
#define CHECK_ALARM_INCREMENT_ERROR(alarm_id, increment, result)
#endif

/* No Alarm and extended error checking (WITH_OS_EXTENDED == YES) */
#if (ALARM_COUNT == 0) && (WITH_OS_EXTENDED == YES)
/* E_OS_ID is returned in this case  */
#define CHECK_ALARM_INCREMENT_ERROR(alarm_id, increment, result)
#endif

/*
 * Any Alarm and extended error checking (WITH_OS_EXTENDED == YES) and
 * AUTOSAR (WITH_AUTOSAR == YES)
 */
#if (ALARM_COUNT > 0) && (WITH_OS_EXTENDED == YES) && (WITH_AUTOSAR == YES)
/* E_OK or E_OS_VALUE   */
#define CHECK_ALARM_INCREMENT_ERROR(alarm_id, increment, result)               \
  if ((result == (tpl_status)E_OK) &&                                          \
      (((increment) >                                                          \
        tpl_alarm_table[(alarm_id)]->stat_part->counter->max_allowed_value) || \
       ((increment) == 0)))                                                    \
  {                                                                            \
    result = (tpl_status)E_OS_VALUE;                                           \
  }
#endif

/*
 * Any Alarm and extended error checking (WITH_OS_EXTENDED == YES) and
 * no AUTOSAR (WITH_AUTOSAR == NO)
 */
#if (ALARM_COUNT > 0) && (WITH_OS_EXTENDED == YES) && (WITH_AUTOSAR == NO)
/* E_OK or E_OS_VALUE   */
#define CHECK_ALARM_INCREMENT_ERROR(alarm_id, increment, result)               \
  if ((result == (tpl_status)E_OK) &&                                          \
      (((increment) >                                                          \
        tpl_alarm_table[(alarm_id)]->stat_part->counter->max_allowed_value)))  \
  {                                                                            \
    result = (tpl_status)E_OS_VALUE;                                           \
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)          */
#if (WITH_OS_EXTENDED == NO)
/* Does not check the task_id in this case                  */
#define CHECK_ALARM_MIN_CYCLE_ERROR(alarm_id, cycle, result)
#endif

/* No Alarm and extended error checking (WITH_OS_EXTENDED == YES) */
#if (ALARM_COUNT == 0) && (WITH_OS_EXTENDED == YES)
/* E_OS_ID is returned in this case  */
#define CHECK_ALARM_MIN_CYCLE_ERROR(alarm_id, cycle, result)
#endif

/* Any Alarm and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (ALARM_COUNT > 0) && (WITH_OS_EXTENDED == YES)
/* E_OK or E_OS_LIMIT   */
#define CHECK_ALARM_MIN_CYCLE_ERROR(alarm_id, cycle, result)                   \
  if ((result == (tpl_status)E_OK) && ((cycle) != 0) &&                        \
      (((cycle) >                                                              \
        tpl_alarm_table[(alarm_id)]->stat_part->counter->max_allowed_value) || \
       ((cycle) <                                                              \
        tpl_alarm_table[(alarm_id)]->stat_part->counter->min_cycle)))          \
  {                                                                            \
    result = (tpl_status)E_OS_VALUE;                                           \
  }
#endif

/**
 * @def CHECK_OS_NOT_STARTED
 *
 * Checks if the operating system is not started already.
 *
 * @param result error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 */
#if (WITH_OS_EXTENDED == YES)
#define CHECK_OS_NOT_STARTED(a_core_id, result)                                \
  if ((result == (tpl_status)E_OK) &&                                          \
      (tpl_current_os_state(CORE_ID_OR_NOTHING(a_core_id)) != OS_INIT))        \
  {                                                                            \
    result = (tpl_status)E_OS_STATE;                                           \
  }
#else
#define CHECK_OS_NOT_STARTED(core_id, result)
#endif

/**
 * @def CHECK_STARTCORE_OS_NOT_STARTED
 *
 * Checks if the operating system is not started already.
 *
 * @param result error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 */
#if (WITH_OS_EXTENDED == YES)
#define CHECK_STARTCORE_OS_NOT_STARTED(a_core_id, result)                      \
  if ((result == (tpl_status)E_OK) &&                                          \
      (tpl_current_os_state(CORE_ID_OR_NOTHING(a_core_id)) != OS_INIT))        \
  {                                                                            \
    result = (tpl_status)E_OS_ACCESS;                                          \
  }
#else
#define CHECK_STARTCORE_OS_NOT_STARTED(core_id, result)
#endif

/**
 * @def CHECK_RESOURCE_ID_ERROR
 *
 * Checks if the resouce identifier (#ResourceType) is valid.
 *
 * @param res_id #ResourceType to check
 * @param result error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
/* Does not check the task_id in this case */
#define CHECK_RESOURCE_ID_ERROR(res_id, result)
#endif

/* No Resource and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (RESOURCE_COUNT == 0) && (WITH_OS_EXTENDED == YES)
/* E_OS_ID is returned in this case  */
#define CHECK_RESOURCE_ID_ERROR(res_id, result)                                \
  if ((result == (tpl_status)E_OK) &&                                          \
      ((res_id) != (tpl_resource_id)RES_SCHEDULER))                            \
  {                                                                            \
    result = (tpl_status)E_OS_ID;                                              \
  }
#endif

/* Any Resource and extended error checking (WITH_OS_EXTENDED == YES) */
#if (RESOURCE_COUNT > 0) && (WITH_OS_EXTENDED == YES)
/* E_OK or E_OS_LIMIT   */
#define CHECK_RESOURCE_ID_ERROR(res_id, result)                                \
  if ((result == (tpl_status)E_OK) &&                                          \
      ((res_id) >= ((tpl_resource_id)RESOURCE_COUNT)))                         \
  {                                                                            \
    result = (tpl_status)E_OS_ID;                                              \
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
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

#if WITH_OS_EXTENDED == YES
#define CHECK_RESOURCE_PRIO_ERROR_ON_GET(core_id, res, result)                 \
  if ((result == (tpl_status)E_OK) &&                                          \
      (((res)->owner != INVALID_TASK) ||                                       \
       (TPL_KERN(core_id).s_running->base_priority > res->ceiling_priority)))  \
  {                                                                            \
    result = (tpl_status)E_OS_ACCESS;                                          \
  }
#else
#define CHECK_RESOURCE_PRIO_ERROR_ON_GET(core_id, res, result)
#endif

/**
 * @def CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE
 *
 * Checks if the running task or interrupt can release the resource.
 *
 * @param res the resource (#ResourceType) the task releases
 * @param result error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

#if WITH_OS_EXTENDED == YES
#define CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(a_core_id, res, result)           \
  if ((result == (tpl_status)E_OK) &&                                          \
      (TPL_KERN(a_core_id).s_running->base_priority >                          \
       (res)->ceiling_priority))                                               \
  {                                                                            \
    result = (tpl_status)E_OS_ACCESS;                                          \
  }
#else
#define CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(a_core_id, res, result)
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
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

#if WITH_OS_EXTENDED == YES
#define CHECK_RESOURCE_ORDER_ON_RELEASE(a_core_id, res, result)                \
  if ((result == (tpl_status)E_OK) &&                                          \
      (TPL_KERN(a_core_id).running->resources != (res)))                       \
  {                                                                            \
    result = (tpl_status)E_OS_NOFUNC;                                          \
  }
#else
#define CHECK_RESOURCE_ORDER_ON_RELEASE(a_core_id, res, result)
#endif

/**
 * @def CHECK_INTERRUPT_LOCK
 *
 * Checks if the interrutps are not disabled by user
 * when calling an api, and release the locking if needed
 *
 * @param result: error code returned
 */

#define CHECK_INTERRUPT_LOCK(result)                                           \
  if (FALSE != tpl_get_interrupt_lock_status())                                \
  {                                                                            \
    result = E_OS_DISABLEDINT;                                                 \
  }

/**
 * @def CHECK_ACCESS_RIGHTS_TASK_ID
 *
 * This macro checks if running task is allowed to access to
 * the task identifier in parameter
 *
 * This macro is a little different than the service call CheckObjectAccess.
 * bit_shift because the first bit (bit_shift) is set if the object
 * belongs to the OS application and we want to know if the actual
 * task has access right to the application, which is indicates by
 * the second bit bit_shift.
 *
 * @param obj_id #ObjectID to check
 * @param result error code variable to set (StatusType)
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

#if (WITH_OS_EXTENDED == NO) || (WITH_OSAPPLICATION == NO)
#define CHECK_ACCESS_RIGHTS_TASK_ID(a_core_id, obj_id, result)
#elif (APP_COUNT == 0)
#define CHECK_ACCESS_RIGHTS_TASK_ID(a_core_id, obj_id, result)                 \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = E_OS_ACCESS;                                                      \
  }
#else
#define CHECK_ACCESS_RIGHTS_TASK_ID(a_core_id, obj_id, result)                 \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    CONST(uint8, AUTOMATIC) bit_shift = (obj_id & 0x7);                        \
    CONST(uint8, AUTOMATIC) byte_idx = obj_id >> 3;                            \
    extern CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)              \
        tpl_app_table[APP_COUNT];                                              \
    CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)                     \
    app_access =                                                               \
        tpl_app_table[tpl_stat_proc_table[TPL_KERN(a_core_id).running_id]      \
                          ->app_id];                                           \
    if ((((app_access->access_vec[OBJECT_TASK][byte_idx]) >> bit_shift) &      \
         0x1) == NO_ACCESS)                                                    \
    {                                                                          \
      result = E_OS_ACCESS;                                                    \
    }                                                                          \
  }
#endif

/**
 * @def CHECK_ACCESS_RIGHTS_ALARM_ID
 *
 * This macro checks if running task is allowed to access to
 * the alarm identifier in parameter
 *
 * This macro is a little different than the service call CheckObjectAccess.
 * bit_shift because the first bit (bit_shift) is set if th object
 * belongs to the OS application and we want to know if the actual
 * task has access right to the application, which is indicates by
 * the second bit bit_shift.
 *
 * @param obj_id #ObjectID to check
 * @param result error code variable to set (StatusType)
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

#if (WITH_OS_EXTENDED == NO) || (WITH_OSAPPLICATION == NO) || (ALARM_COUNT == 0)
#define CHECK_ACCESS_RIGHTS_ALARM_ID(a_core_id, obj_id, result)
#elif (APP_COUNT == 0)
#define CHECK_ACCESS_RIGHTS_ALARM_ID(a_core_id, obj_id, result)                \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = E_OS_ACCESS;                                                      \
  }
#else
#define CHECK_ACCESS_RIGHTS_ALARM_ID(a_core_id, obj_id, result)                \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    CONST(uint8, AUTOMATIC) bit_shift = (obj_id & 0x7);                        \
    CONST(uint8, AUTOMATIC) byte_idx = obj_id >> 3;                            \
    extern CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)              \
        tpl_app_table[APP_COUNT];                                              \
    CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)                     \
    app_access =                                                               \
        tpl_app_table[tpl_stat_proc_table[TPL_KERN(a_core_id).running_id]      \
                          ->app_id];                                           \
    if ((((app_access->access_vec[OBJECT_ALARM][byte_idx]) >> bit_shift) &     \
         0x1) == NO_ACCESS)                                                    \
    {                                                                          \
      result = E_OS_ACCESS;                                                    \
    }                                                                          \
  }
#endif

/**
 * @def CHECK_ACCESS_RIGHTS_RESOURCE_ID
 *
 * This macro checks if running task is allowed to access to
 * the resource identifier in parameter
 *
 * This macro is a little different than the service call CheckObjectAccess.
 * bit_shift because the first bit (bit_shift) is set if th object
 * belongs to the OS application and we want to know if the actual
 * task has access right to the application, which is indicates by
 * the second bit bit_shift.
 *
 * @param obj_id #ObjectID to check
 * @param result error code variable to set (StatusType)
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

#if ((WITH_OS_EXTENDED == NO)) || (WITH_OSAPPLICATION == NO)
#define CHECK_ACCESS_RIGHTS_RESOURCE_ID(a_core_id, obj_id, result)
#elif (APP_COUNT == 0)
#define CHECK_ACCESS_RIGHTS_RESOURCE_ID(a_core_id, obj_id, result)             \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = E_OS_ACCESS;                                                      \
  }
#else
#define CHECK_ACCESS_RIGHTS_RESOURCE_ID(a_core_id, obj_id, result)             \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    CONST(uint8, AUTOMATIC) bit_shift = (obj_id & 0x7);                        \
    CONST(uint8, AUTOMATIC) byte_idx = obj_id >> 3;                            \
    extern CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)              \
        tpl_app_table[APP_COUNT];                                              \
    CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)                     \
    app_access =                                                               \
        tpl_app_table[tpl_stat_proc_table[TPL_KERN(a_core_id).running_id]      \
                          ->app_id];                                           \
    if ((((app_access->access_vec[OBJECT_RESOURCE][byte_idx]) >> bit_shift) &  \
         0x1) == NO_ACCESS)                                                    \
    {                                                                          \
      result = E_OS_ACCESS;                                                    \
    }                                                                          \
  }
#endif

/**
 * @def CHECK_ACCESS_RIGHTS_COUNTER_ID
 *
 * This macro checks if running task is allowed to access to
 * the counter identifier in parameter
 *
 * This macro is a little different than the service call CheckObjectAccess.
 * bit_shift because the first bit (bit_shift) is set if th object
 * belongs to the OS application and we want to know if the actual
 * task has access right to the application, which is indicates by
 * the second bit bit_shift.
 *
 * @param obj_id #ObjectID to check
 * @param result error code variable to set (StatusType)
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

#if ((WITH_OS_EXTENDED == NO)) || (WITH_OSAPPLICATION == NO) ||                \
    (COUNTER_COUNT == 0)
#define CHECK_ACCESS_RIGHTS_COUNTER_ID(a_core_id, obj_id, result)
#elif (APP_COUNT == 0)
#define CHECK_ACCESS_RIGHTS_COUNTER_ID(a_core_id, obj_id, result)              \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = E_OS_ACCESS;                                                      \
  }
#else
#define CHECK_ACCESS_RIGHTS_COUNTER_ID(a_core_id, obj_id, result)              \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    CONST(uint8, AUTOMATIC) bit_shift = (obj_id & 0x7);                        \
    CONST(uint8, AUTOMATIC) byte_idx = obj_id >> 3;                            \
    extern CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)              \
        tpl_app_table[APP_COUNT];                                              \
    CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)                     \
    app_access =                                                               \
        tpl_app_table[tpl_stat_proc_table[TPL_KERN(a_core_id).running_id]      \
                          ->app_id];                                           \
    if ((((app_access->access_vec[OBJECT_COUNTER][byte_idx]) >> bit_shift) &   \
         0x1) == NO_ACCESS)                                                    \
    {                                                                          \
      result = E_OS_ACCESS;                                                    \
    }                                                                          \
  }
#endif

/**
 * @def CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID
 *
 * This macro checks if running task is allowed to access to
 * the schedule table identifier in parameter
 *
 * This macro is a little different than the service call CheckObjectAccess.
 * bit_shift because the first bit (bit_shift) is set if th object
 * belongs to the OS application and we want to know if the actual
 * task has access right to the application, which is indicates by
 * the second bit bit_shift.
 *
 * @param obj_id #ObjectID to check
 * @param result error code variable to set (StatusType)
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

#if (WITH_OS_EXTENDED == NO) || (WITH_OSAPPLICATION == NO) ||                  \
    (SCHEDTABLE_COUNT == 0)
#define CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(a_core_id, obj_id, result)
#elif (APP_COUNT == 0)
#define CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(a_core_id, obj_id, result)        \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = E_OS_ACCESS;                                                      \
  }
#else
#define CHECK_ACCESS_RIGHTS_SCHEDULETABLE_ID(a_core_id, obj_id, result)        \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    CONST(uint8, AUTOMATIC) bit_shift = (obj_id & 0x7);                        \
    CONST(uint8, AUTOMATIC) byte_idx = obj_id >> 3;                            \
    extern CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)              \
        tpl_app_table[APP_COUNT];                                              \
    CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)                     \
    app_access =                                                               \
        tpl_app_table[tpl_stat_proc_table[TPL_KERN(a_core_id).running_id]      \
                          ->app_id];                                           \
    if ((((app_access->access_vec[OBJECT_SCHEDULETABLE][byte_idx]) >>          \
          bit_shift) &                                                         \
         0x1) == NO_ACCESS)                                                    \
    {                                                                          \
      result = E_OS_ACCESS;                                                    \
    }                                                                          \
  }
#endif

/**
 * @def CHECK_ACCESS_RIGHTS_SPINLOCK_ID
 *
 * This macro checks if running task is allowed to access to
 * the spinlock identifier in parameter
 *
 * This macro is a little different than the service call CheckObjectAccess.
 * bit_shift because the first bit (bit_shift) is set if the object
 * belongs to the OS application and we want to know if the actual
 * task has access right to the application, which is indicates by
 * the second bit bit_shift.
 *
 * @param obj_id #ObjectID to check
 * @param result error code variable to set (StatusType)
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

#if (WITH_OS_EXTENDED == NO) || (WITH_OSAPPLICATION == NO)
#define CHECK_ACCESS_RIGHTS_SPINLOCK_ID(a_core_id, obj_id, result)
#elif (APP_COUNT == 0)
#define CHECK_ACCESS_RIGHTS_SPINLOCK_ID(a_core_id, obj_id, result)             \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = E_OS_ACCESS;                                                      \
  }
#else
#define CHECK_ACCESS_RIGHTS_SPINLOCK_ID(a_core_id, obj_id, result)             \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    CONST(uint8, AUTOMATIC) bit_shift = (obj_id & 0x7);                        \
    CONST(uint8, AUTOMATIC) byte_idx = obj_id >> 3;                            \
    extern CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)              \
        tpl_app_table[APP_COUNT];                                              \
    CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)                     \
    app_access =                                                               \
        tpl_app_table[tpl_stat_proc_table[TPL_KERN(a_core_id).running_id]      \
                          ->app_id];                                           \
    if ((((app_access->access_vec[OBJECT_SPINLOCK][byte_idx]) >> bit_shift) &  \
         0x1) == NO_ACCESS)                                                    \
    {                                                                          \
      result = E_OS_ACCESS;                                                    \
    }                                                                          \
  }
#endif

/**
 * @def LOCATION_WITHIN
 *
 * This macro expands to 1 if the location (start pointer + size of the
 * location lays within the memory descriptor
 *
 * @param mem_region  the memory region struct
 * @param loc_ptr     the start address of the location
 * @param loc_size    the size of the location
 */
#define LOCATION_WITHIN(mem_region, loc_ptr)                                   \
  (((void *)(loc_ptr) < mem_region.start) ||                                   \
   ((void *)((loc_ptr) + (1)) > mem_region.end))
/**
 * @def CHECK_DATA_LOCATION
 *
 * This macro checks a data pointer passed to a service is within
 * the allowed data range (ie within the stack of the process or
 * within the private data of the process or within the shared data
 * of the OS Application.
 *
 * @param data_ptr  the pointer to be tested
 * @param result error code variable to set (StatusType)
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disabled when WITH_MEMORY_PROTECTION == NO
 */
#if (WITH_MEMORY_PROTECTION == NO)
#define CHECK_DATA_LOCATION(a_core_id, data_ptr, result)
#elif (WITH_MEMORY_PROTECTION == YES) && (WITH_AUTOSAR == NO)
#define CHECK_DATA_LOCATION(a_core_id, data_ptr, result)                       \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    CONSTP2CONST(tpl_mem_prot_desc, AUTOMATIC, OS_CONST)                       \
    mp_desc = tpl_mp_table[TPL_KERN(a_core_id).running_id];                    \
    if (TPL_KERN(a_core_id).running_trusted == 0)                              \
    {                                                                          \
      if (LOCATION_WITHIN(mp_desc->proc_var, data_ptr) &&                      \
          LOCATION_WITHIN(mp_desc->proc_stack, data_ptr))                      \
      {                                                                        \
        result = E_OS_PROTECTION_MEMORY;                                       \
      }                                                                        \
    }                                                                          \
  }
#elif (WITH_MEMORY_PROTECTION == YES) && (WITH_AUTOSAR == YES)
#define CHECK_DATA_LOCATION(a_core_id, data_ptr, result)                       \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    CONSTP2CONST(tpl_mem_prot_desc, AUTOMATIC, OS_CONST)                       \
    mp_desc = tpl_mp_table[TPL_KERN(a_core_id).running_id];                    \
    if (TPL_KERN(a_core_id).running_trusted == 0)                              \
    {                                                                          \
      if (LOCATION_WITHIN(mp_desc->proc_var, data_ptr) &&                      \
          LOCATION_WITHIN(mp_desc->proc_stack, data_ptr) &&                    \
          LOCATION_WITHIN(mp_desc->osap_var, data_ptr))                        \
      {                                                                        \
        result = E_OS_PROTECTION_MEMORY;                                       \
      }                                                                        \
    }                                                                          \
  }
#endif

#if WITH_IOC == YES
/**
 * @def CHECK_IOC_ID_ERROR
 *
 * This macro checks for out of range ioc_id error. It
 * is used in os services which uses ioc_id as parameter.
 *
 * @param ioc_id #tpl_ioc_id (so called ioc_id) to check
 * @param result error code variable to set (StatusType)
 *
 * @note this checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no
 * previous error
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if WITH_OS_EXTENDED == NO
/* Does not check the task_id in this case */
#define CHECK_IOC_ID_ERROR(ioc_id, result)
#endif

/* No Task and extended error checking (WITH_OS_EXTENDED == YES)        */
#if (IOC_COUNT == 0) && (WITH_OS_EXTENDED == YES)
/* E_OS_ID is returned in this case  */
#define CHECK_IOC_ID_ERROR(ioc_id, result)                                     \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    result = (tpl_status)E_OS_ID;                                              \
  }
#endif

/* Any Ioc and extended error checking (WITH_OS_EXTENDED == YES)   */
#if (IOC_COUNT > 0) && (WITH_OS_EXTENDED == YES)
/* E_OK or E_OS_LIMIT   */
#define CHECK_IOC_ID_ERROR(ioc_id, result)                                     \
  if ((result == (tpl_status)E_OK) && (ioc_id >= (tpl_ioc_id)IOC_COUNT))       \
  {                                                                            \
    result = (tpl_status)E_OS_ID;                                              \
  }
#endif

/**
 * @def CHECK_ACCESS_WRITE_IOC_ID
 *
 * This macro checks if running task is allowed to write to
 * the ioc identifier in parameter
 *
 *
 * @param obj_id #ObjectID to check
 * @param result error code variable to set (StatusType)
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */
#if (WITH_OS_EXTENDED == NO) || (WITH_IOC == NO)
#define CHECK_ACCESS_WRITE_IOC_ID(a_core_id, obj_id, result)
#elif (APP_COUNT == 0)
#define CHECK_ACCESS_WRITE_IOC_ID(a_core_id, obj_id, result)                   \
  if (result == IOC_E_OK)                                                      \
  {                                                                            \
    result = E_OS_ACCESS;                                                      \
  }
#else
#define CHECK_ACCESS_WRITE_IOC_ID(a_core_id, obj_id, result)                   \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    CONST(uint8, AUTOMATIC) bit_shift = (obj_id & 0x7);                        \
    CONST(uint8, AUTOMATIC) byte_idx = obj_id >> 3;                            \
    extern CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)              \
        tpl_app_table[APP_COUNT];                                              \
    CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)                     \
    app_access =                                                               \
        tpl_app_table[tpl_stat_proc_table[TPL_KERN(a_core_id).running_id]      \
                          ->app_id];                                           \
    if ((((app_access->access_vec[OBJECT_IOC_SENDER][byte_idx]) >>             \
          bit_shift) &                                                         \
         0x1) == NO_ACCESS)                                                    \
    {                                                                          \
      result = E_OS_ACCESS;                                                    \
    }                                                                          \
  }
#endif

/**
 * @def CHECK_ACCESS_READ_IOC_ID
 *
 * This macro checks if running task is allowed to read rfom
 * the ioc identifier in parameter
 *
 *
 * @param obj_id #ObjectID to check
 * @param result error code variable to set (StatusType)
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */
#if (WITH_OS_EXTENDED == NO) || (WITH_IOC == NO)
#define CHECK_ACCESS_READ_IOC_ID(a_core_id, obj_id, result)
#elif (APP_COUNT == 0)
#define CHECK_ACCESS_READ_IOC_ID(a_core_id, obj_id, result)                    \
  if (result == IOC_E_OK)                                                      \
  {                                                                            \
    result = E_OS_ACCESS;                                                      \
  }
#else
#define CHECK_ACCESS_READ_IOC_ID(a_core_id, obj_id, result)                    \
  if (result == (tpl_status)E_OK)                                              \
  {                                                                            \
    CONST(uint8, AUTOMATIC) bit_shift = (obj_id & 0x7);                        \
    CONST(uint8, AUTOMATIC) byte_idx = obj_id >> 3;                            \
    extern CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)              \
        tpl_app_table[APP_COUNT];                                              \
    CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)                     \
    app_access =                                                               \
        tpl_app_table[tpl_stat_proc_table[TPL_KERN(a_core_id).running_id]      \
                          ->app_id];                                           \
    if ((((app_access->access_vec[OBJECT_IOC_RECEIVER][byte_idx]) >>           \
          bit_shift) &                                                         \
         0x1) == NO_ACCESS)                                                    \
    {                                                                          \
      result = E_OS_ACCESS;                                                    \
    }                                                                          \
  }
#endif

#endif /* WITH_IOC == YES */

/**
 * CHECK_SCHEDULE_WHILE_OCCUPED_SPINLOCK
 *
 * This macro checks if the calling TASK is attempting a scheduling while
 * having an occupied lock
 */
#if (WITH_OS_EXTENDED == YES) && (WITH_AUTOSAR == YES) && (SPINLOCK_COUNT > 0)
#define CHECK_SCHEDULE_WHILE_OCCUPED_SPINLOCK(a_core_id, a_result)             \
  if (((a_result) == E_OK) && (HAS_SPINLOCK(a_core_id)))                       \
  {                                                                            \
    result = E_OS_SPINLOCK;                                                    \
  }
#else
#define CHECK_SCHEDULE_WHILE_OCCUPED_SPINLOCK(a_core_id, a_result)
#endif

/**
 * CHECK_CORE_ID_ERROR
 *
 * This macro checks the core_id is within 0 .. NUMBER_OF_CORES - 1
 */
#if (WITH_OS_EXTENDED == YES) && (NUMBER_OF_CORES > 1)
#define CHECK_CORE_ID_ERROR(a_core_id, a_result)                               \
  if (((a_result) == E_OK) && ((a_core_id) >= NUMBER_OF_CORES))                \
  {                                                                            \
    result = E_OS_ID;                                                          \
  }
#else
#define CHECK_CORE_ID_ERROR(a_core_id, a_result)
#endif

/**
 * CHECK_START_CORE_ERROR
 *
 * This macro checks the core is not already started
 */
#if (WITH_OS_EXTENDED == YES) && (NUMBER_OF_CORES > 1)
#define CHECK_START_CORE_ERROR(a_core_id, a_result)                            \
  if (((a_result) == E_OK) && (tpl_core_status[a_core_id] != STOPPED_CORE))    \
  {                                                                            \
    result = E_OS_STATE;                                                       \
  }
#else
#define CHECK_START_CORE_ERROR(a_core_id, a_result)
#endif

/**
 * CHECK_START_OS_ERROR
 *
 * This macro checks the os is not already started
 */

#endif /*TPL_OS_ERROR_H */

/* End of file tpl_os_error.h */
