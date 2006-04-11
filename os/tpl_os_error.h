/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Errors macros, functions and datatypes header
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#ifndef __TPL_OS_ERROR_H__
#define __TPL_OS_ERROR_H__

#include "tpl_os.h"

/*
 * NO_TASK means there is no task defined in the system
 * OS_EXTENDED means extended error checking is done
 * WITH_ERROR_HOOK means an error hook routine is called when
 * an error occurs.
 */

#ifdef WITH_ERROR_HOOK

union ID_PARAM_BLOCK {
        TaskType        task_id;        /* ActivateTask, ChainTask, GetTaskState, SetEvent, GetEvent    */
        TaskRefType     task_id_ref;    /* GetTaskID    */
        ResourceType    res_id;         /* GetResource, ReleaseResource */
        AlarmType       alarm_id;
};

union PARAM_PARAM_BLOCK {
        TaskStateRefType    state;          /* GetTaskState                     */
        TickType            tick;           /* SetRelAlarm, SetAbsAlarm         */
        TickRefType         tick_ref;       /* GetAlarm                         */
        AlarmBaseRefType    alarm_base_ref; /* GetAlarmBase                     */
        EventMaskType       mask;           /* SetEvent, ClearEvent, WaitEvent  */
        EventMaskRefType    mask_ref;       /* GetEvent                         */
};

/* union of parameters for error hook */
struct PARAM_BLOCK {
    union ID_PARAM_BLOCK    id;
    union PARAM_PARAM_BLOCK param;
    TickType                cycle;
};

/*
 * struct that gather the os service id and its parameters
 */
struct SERVICE_CALL_DESCRIPTOR {
    struct PARAM_BLOCK  parameters;
    unsigned char       service_id;
};

typedef struct SERVICE_CALL_DESCRIPTOR tpl_service_call_desc;

/*
 * the global where parameters are stored before calling the error hook routine
 */
extern tpl_service_call_desc tpl_service;

/*
 * the function that calls error_hook
 */
void tpl_call_error_hook(tpl_status);

/*
 * Services ids
 */
#define OSServiceId_ActivateTask                1
#define OSServiceId_TerminateTask               2
#define OSServiceId_ChainTask                   3
#define OSServiceId_Schedule                    4
#define OSServiceId_GetTaskID                   5
#define OSServiceId_GetTaskState                6

#define OSServiceId_EnableAllInterrupts         7
#define OSServiceId_DisableAllInterrupts        8
#define OSServiceId_ResumeAllInterrupts         9
#define OSServiceId_SuspendAllInterrupts        10
#define OSServiceId_ResumeOSInterrupts          11
#define OSServiceId_SuspendOSInterrupts         12

#define OSServiceId_GetResource                 13
#define OSServiceId_ReleaseResource             14

#define OSServiceId_SetEvent                    15
#define OSServiceId_ClearEvent                  16
#define OSServiceId_GetEvent                    17
#define OSServiceId_WaitEvent                   18

#define OSServiceId_GetAlarmBase                19
#define OSServiceId_GetAlarm                    20
#define OSServiceId_SetRelAlarm                 21
#define OSServiceId_SetAbsAlarm                 22
#define OSServiceId_CancelAlarm                 23

#define OSServiceId_GetActiveApplicationMode    24
#define OSServiceId_StartOS                     25
#define OSServiceId_ShutdownOS                  26

/*
 * macros to access the service id and its parameters from hook routine
 */
#define OSErrorGetServiceId()   (tpl_service.service_id)

/*  ActivateTask parameter  */
#define OSError_ActivateTask_TaskID()   \
    (tpl_service.parameters.id.task_id)
    
/*  ChainTask parameter */
#define OSError_ChainTask_TaskID()      \
    (tpl_service.parameters.id.task_id)
    
/*  GetTaskID parameter */
#define OSError_GetTaskID_TaskID()             \
    (tpl_service.parameters.id.task_id_ref)
    
/*  GetTaskState parameters */
#define OSError_GetTaskState_TaskID()   \
    (tpl_service.parameters.id.task_id)
#define OSError_GetTaskState_State()    \
    (tpl_service.parameters.param.state)

/*  GetResource parameter   */
#define OSError_GetResource_ResID()     \
    (tpl_service.parameters.id.res_id)

/*  ReleaseResource parameter   */
#define OSError_ReleaseResource_ResID() \
    (tpl_service.parameters.id.res_id)

/*  SetEvent parameters */
#define OSError_SetEvent_TaskID()       \
    (tpl_service.parameters.id.task_id)
#define OSError_SetEvent_Mask()         \
    (tpl_service.parameters.param.mask)

/*  ClearEvent parameter    */
#define OSError_ClearEvent_Mask()       \
    (tpl_service.parameters.param.mask)
    
/*  GetEvent parameters */
#define OSError_GetEvent_TaskID()       \
    (tpl_service.parameters.id.task_id)
#define OSError_GetEvent_Event()        \
    (tpl_service.parameters.param.mask)
    
/*  WaitEvent parameter */
#define OSError_WaitEvent_Mask()        \
    (tpl_service.parameters.param.mask)

/*  GetAlarmBase parameters */
#define OSError_GetAlarmBase_AlarmID()  \
    (tpl_service.parameters.id.alarm_id)
#define OSError_GetAlarmBase_Info()     \
    (tpl_service.parameters.param.alarm_base_ref)
    
/*  GetAlarm parameters  */
#define OSError_GetAlarm_AlarmID()      \
    (tpl_service.parameters.id.alarm_id)
#define OSError_GetAlarm_Tick()         \
    (tpl_service.parameters.param.tick_ref)

/*  SetRelAlarm parameters  */
#define OSError_SetRelAlarm_AlarmID()   \
    (tpl_service.parameters.id.alarm_id)
#define OSError_SetRelAlarm_increment() \
    (tpl_service.parameters.param.tick)
#define OSError_SetRelAlarm_cycle()     \
    (tpl_service.parameters.cycle)

/*  SetAbsAlarm parameters  */
#define OSError_SetAbsAlarm_AlarmID()   \
    (tpl_service.parameters.id.alarm_id)
#define OSError_SetAbsAlarm_start()     \
    (tpl_service.parameters.param.tick)
#define OSError_SetAbsAlarm_cycle()     \
    (tpl_service.parameters.cycle)

/*  CancelAlarm parameter   */
#define OSError_CancelAlarm_AlarmID()   \
    (tpl_service.parameters.id.alarm_id)

#endif
/* of WITH_ERROR_HOOK  */

/*
 *  STORE_SERVICE
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_SERVICE(service)   \
    tpl_service.service_id = (service);
#else
#   define STORE_SERVICE(service)
#endif

/*
 * STORE_TASK_ID
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TASK_ID(task_id)   \
    tpl_service.parameters.id.task_id = (task_id);
#else
#   define STORE_TASK_ID(task_id)
#endif 

/*
 * STORE_TASK_ID_REF
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TASK_ID_REF(task_id_ref)  \
    tpl_service.parameters.id.task_id_ref;
#else
#   define STORE_TASK_ID_REF(task_id_ref)
#endif

/*
 * STORE_TASK_STATE_REF
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TASK_STATE_REF(state)  \
    tpl_service.parameters.param.state = state;
#else
#   define STORE_TASK_STATE_REF(state)
#endif

/*
 * STORE_RESOURCE_ID
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_RESOURCE_ID(res_id)    \
    tpl_service.parameters.id.res_id = res_id;
#else
#   define STORE_RESOURCE_ID(res_id)
#endif

/*
 * STORE_ALARM_ID
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_ALARM_ID(alarm_id)     \
    tpl_service.parameters.id.alarm_id = alarm_id;
#else
#   define STORE_ALARM_ID(alarm_id)
#endif

/*
 * STORE_ALARM_BASE_REF
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_ALARM_BASE_REF(ref)     \
    tpl_service.parameters.param.alarm_base_ref = ref;
#else
#   define STORE_ALARM_BASE_REF(ref)
#endif

/*
 * STORE_TICK_REF
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TICK_REF(ref)     \
    tpl_service.parameters.param.tick_ref = ref;
#else
#   define STORE_TICK_REF(tick_ref)
#endif

/*
 * STORE_TICK_1
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TICK_1(t)     \
    tpl_service.parameters.param.tick = t;
#else
#   define STORE_TICK_1(t)
#endif

/*
 * STORE_TICK_2
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_TICK_2(t)     \
    tpl_service.parameters.cycle = t;
#else
#   define STORE_TICK_2(t)
#endif

/*
 * STORE_EVENT_MASK
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_EVENT_MASK(m)     \
    tpl_service.parameters.param.mask = m;
#else
#   define STORE_EVENT_MASK(m)
#endif

/*
 * STORE_EVENT_MASK_REF
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_EVENT_MASK_REF(ref)     \
    tpl_service.parameters.param.mask_ref = ref;
#else
#   define STORE_EVENT_MASK_REF(ref)
#endif

/*-----------------------------------------------------------------------------
 * PROCESS_ERROR
 * This maccro generates the code to call the error hook, when
 * an error occured, if the WITH_ERROR_HOOK flag is on and no
 * code at all if the flag is off.
 */
#ifdef WITH_ERROR_HOOK
#define PROCESS_ERROR(error)        \
    if (error != E_OK) {            \
        tpl_call_error_hook(error); \
    }                               
#else
#define PROCESS_ERROR(error)
#endif

/*-----------------------------------------------------------------------------
 * IF_NO_EXTENDED_ERROR
 * This macro generate a if (result == E_OK) {
 * when OS_EXTENDED is on and no code at all if it is off
 */
#ifdef OS_EXTENDED
#   define IF_NO_EXTENDED_ERROR(result) \
    if (result == E_OK) {
#else
#   define IF_NO_EXTENDED_ERROR(result)
#endif

/*-----------------------------------------------------------------------------
 * END_IF_NO_EXTENDED_ERROR
 * See above
 */
#ifdef OS_EXTENDED
#   define END_IF_NO_EXTENDED_ERROR() \
    }
#else
#   define END_IF_NO_EXTENDED_ERROR()
#endif

/*-----------------------------------------------------------------------------
 * LOCK_WHEN_HOOK
 * Lock when WITH_ERROR_HOOK is defined. Used for some services
 * that does not require locking in standard mode since they do not
 * access globals
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

/*-----------------------------------------------------------------------------
 * LOCK_WHEN_NO_HOOK
 * Lock when WITH_ERROR_HOOK is not defined. Used for some services
 * that require a different locking scheme according to hook use
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

/*-----------------------------------------------------------------------------
 * LOCK_WHEN_TASK
 * Lock when NO_TASK is not defined. Used for task services
 * that does not require locking in standard mode since there is no
 * task to operate on
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

/*-----------------------------------------------------------------------------
 * LOCK_WHEN_RESOURCE
 * Lock when NO_RESOURCE is not defined. Used for resource services
 * that does not require locking in standard mode since there is no
 * resource to operate on
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

/*-----------------------------------------------------------------------------
 * CHECK_TASK_ID_ERROR macro definition
 * This macro defines the appropriate error program
 * for out of range task_id. It is used in os services
 * that use task_id as parameter.
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the task_id in this case */
#   define CHECK_TASK_ID_ERROR(task_id,result)
#endif

/* NO_TASK and extended error checking (OS_EXTENDED)        */
#if defined(NO_TASK) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_TASK_ID_ERROR(task_id,result) \
    if (result == E_OK) {                      \
        result = E_OS_ID;                      \
    }
#endif

/* !NO_TASK and extended error checking (OS_EXTENDED)   */
#if !defined(NO_TASK) && defined(OS_EXTENDED)
    /* E_OK or E_OS_LIMIT   */
#   define CHECK_TASK_ID_ERROR(task_id,result)      \
    if (result == E_OK && task_id >= TASK_COUNT) {  \
        result = E_OS_ID;                           \
    }
#endif

/*-----------------------------------------------------------------------------
 * CHECK_TASK_CALL_LEVEL_ERROR macro definition
 * This macro defines the appropriate error program
 * that check for call level
 */

/*  NO_TASK and extended error checking (OS_EXTENDED).
    Since there is no task, there is no task level calling  */
#if defined(NO_TASK) && defined(OS_EXTENDED)
#   define CHECK_TASK_CALL_LEVEL_ERROR(result)      \
    if (result == E_OK) {                           \
        result = E_OS_CALLEVEL;                     \
    }
#endif

/*  !NO_TASK and extended error checking (OS_EXTENDED). */
#if !defined(NO_TASK) && defined(OS_EXTENDED)
#   define CHECK_TASK_CALL_LEVEL_ERROR(result)          \
    if (result == E_OK && tpl_os_state != OS_TASK) {    \
        result = E_OS_CALLEVEL;                         \
    }
#endif
    
/*  no extended error checking !(OS_EXTENDED).    */
#if !defined(OS_EXTENDED)
#   define CHECK_TASK_CALL_LEVEL_ERROR(result)
#endif

/*-----------------------------------------------------------------------------
 * CHECK_NOT_EXTENDED_TASK_ERROR macro definition
 * This macro defines the appropriate error program
 * that check the task is an extended one
 */
#ifdef OS_EXTENDED
#   define CHECK_NOT_EXTENDED_TASK_ERROR(task_id,result)                            \
    if (tpl_task_table[task_id]->exec_desc.static_desc->type != EXTENDED_TASK) {    \
        result = E_OS_ACCESS;                                                       \
    }
#else
#   define CHECK_NOT_EXTENDED_TASK_ERROR(task_id,result)
#endif

/*-----------------------------------------------------------------------------
 * CHECK_NOT_EXTENDED_RUNNING_ERROR macro definition
 * This macro defines the appropriate error program
 * that check the running task is an extended one
 */
#ifdef OS_EXTENDED
#   define CHECK_NOT_EXTENDED_RUNNING_ERROR(result)                                     \
    if (((tpl_task *)tpl_running_obj)->exec_desc.static_desc->type != EXTENDED_TASK) {  \
        result = E_OS_ACCESS;                                                           \
    }
#else
#   define CHECK_NOT_EXTENDED_RUNNING_ERROR(result)
#endif

/*-----------------------------------------------------------------------------
 * CHECK_SUSPENDED_TASK_ERROR macro definition
 * This macro defines the appropriate error program
 * that check the task is not in the suspended state
 */
#ifdef OS_EXTENDED
#   define CHECK_SUSPENDED_TASK_ERROR(task_id,result)                      \
    if (tpl_task_table[task_id]->exec_desc.state == SUSPENDED) {    \
        result = E_OS_STATE;                                        \
    }
#else
#   define CHECK_SUSPENDED_TASK_ERROR(task_id,result)
#endif


/*--------------------------------------------------------------------------------
 * CHECK_RUNNING_OWNS_REZ_ERROR macro definition
 * This macro defines the appropriate error program
 * that check for the running object owning a resource
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
#   define CHECK_RUNNING_OWNS_REZ_ERROR(result)       \
    if (result == E_OK && tpl_running_obj->resources != NULL) {   \
        result = E_OS_RESOURCE;                 \
    }
#endif

/*-----------------------------------------------------------------------------
 * CHECK_ALARM_ID_ERROR macro definition
 * This macro defines the appropriate error program
 * for out of range alarm_id. It is used in os services
 * that use task_id as parameter.
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the task_id in this case */
#   define CHECK_ALARM_ID_ERROR(alarm_id,result)
#endif

/* NO_ALARM and extended error checking (OS_EXTENDED)        */
#if defined(NO_ALARM) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_ALARM_ID_ERROR(alarm_id,result) \
    if (result == E_OK) {                      \
        result = E_OS_ID;                      \
    }
#endif

/* !NO_ALARM and extended error checking (OS_EXTENDED)   */
#if !defined(NO_ALARM) && defined(OS_EXTENDED)
    /* E_OK or E_OS_LIMIT   */
#   define CHECK_ALARM_ID_ERROR(alarm_id,result)      \
    if (result == E_OK && alarm_id >= ALARM_COUNT) {  \
        result = E_OS_ID;                           \
    }
#endif

/*-----------------------------------------------------------------------------
 * CHECK_RESOURCE_ID_ERROR macro definition
 * This macro defines the appropriate error program
 * for out of range res_id. It is used in os services
 * that use res_id as parameter.
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the task_id in this case */
#   define CHECK_RESOURCE_ID_ERROR(res_id,result)
#endif

/* NO_TASK and extended error checking (OS_EXTENDED)        */
#if defined(NO_RESOURCE) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_RESOURCE_ID_ERROR(res_id,result)   \
    if (result == E_OK && res_id != -1) {           \
        result = E_OS_ID;                           \
    }
#endif

/* !NO_TASK and extended error checking (OS_EXTENDED)   */
#if !defined(NO_RESOURCE) && defined(OS_EXTENDED)
    /* E_OK or E_OS_LIMIT   */
#   define CHECK_RESOURCE_ID_ERROR(res_id,result)                   \
    if (result == E_OK && (res_id >= RES_COUNT || res_id < -1)) {   \
        result = E_OS_ID;                                           \
    }
#endif

/*-----------------------------------------------------------------------------
 * CHECK_RESOURCE_PRIO_ERROR_ON_GET macro definition
 * This macro defines the appropriate error program
 * for a resource that has a lower priority than the task that
 * attempt to get it. It is used in GetResource.
 */

#ifdef OS_EXTENDED
#   define CHECK_RESOURCE_PRIO_ERROR_ON_GET(res,result)                                                 \
    if (result == E_OK &&                                                                               \
        (res->owner != NULL || tpl_running_obj->static_desc->base_priority > res->ceiling_priority)) {  \
        result = E_OS_ACCESS;                                                                           \
    }
#else
#   define CHECK_RESOURCE_PRIO_ERROR_ON_GET(res,result)
#endif

/*-----------------------------------------------------------------------------
 * CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE macro definition
 * This macro defines the appropriate error program
 * for a resource that has a higher priority than the task that
 * attempt to release it. It is used in ReleaseResource.
 */

#ifdef OS_EXTENDED
#   define CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(res,result)                         \
    if (result == E_OK &&                                                           \
        tpl_running_obj->static_desc->base_priority > res->ceiling_priority) {      \
        result = E_OS_ACCESS;                                                       \
    }
#else
#   define CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(res,result)
#endif

/*-----------------------------------------------------------------------------
 * CHECK_RESOURCE_ORDER_ON_RELEASE macro definition
 * This macro defines the appropriate error program
 * for a resource that is not released in the correct order.
 * It is used in ReleaseResource.
 */

#ifdef OS_EXTENDED
#   define CHECK_RESOURCE_ORDER_ON_RELEASE(res,result)                                  \
    if (result == E_OK && (res->owner == NULL || tpl_running_obj->resources != res)) {  \
        result = E_OS_NOFUNC;                                                           \
    }
#else
#   define CHECK_RESOURCE_ORDER_ON_RELEASE(res,result)
#endif

#endif
