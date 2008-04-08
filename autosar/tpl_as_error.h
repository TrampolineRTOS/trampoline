/**
 * @file tpl_as_errors.h
 *
 * @section desc File description
 *
 * Trampoline autosar extension services ids and macros
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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
 
#ifndef TPL_AS_ERROR
#define TPL_AS_ERROR

#include "tpl_os_error.h"

/**
 * @def OSServiceId_StartScheduleTableRel
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartScheduleTableRel
 */
#define OSServiceId_StartScheduleTableRel   64

/**
 * @def OSServiceId_StartScheduleTableAbs
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartScheduleTableAbs
 */
#define OSServiceId_StartScheduleTableAbs   65

/**
 * @def OSServiceId_StopScheduleTable
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StopScheduleTable
 */
#define OSServiceId_StopScheduleTable       66

/**
 * @def OSServiceId_NextScheduleTable
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #NextScheduleTable
 */
#define OSServiceId_NextScheduleTable       67

/**
 * @def OSServiceId_IncrementCounter
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #IncrementCounter
 */
#define OSServiceId_IncrementCounter        68

/**
 * @def OSServiceId_GetCounterValue
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetCounterValue
 */
#define OSServiceId_GetCounterValue         69

/**
 * @def OSServiceId_GetElapsedCounterValue
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetElapsedCounterValue
 */
#define OSServiceId_GetElapsedCounterValue  70

/**
 * @def OSServiceId_GetScheduleTableStatus
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetScheduleTableStatus
 */
#define OSServiceId_GetScheduleTableStatus  71

/**
 * @def OSServiceId_SetScheduleTableAsync
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SetScheduleTableAsync
 */
#define OSServiceId_SetScheduleTableAsync   72

/**
 * @def OSServiceId_StartScheduleTableSynchron
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartScheduleTableSynchron
 */
#define OSServiceId_StartScheduleTableSynchron  73

/**
 * @def OSServiceId_SyncScheduleTable
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SyncScheduleTable
 */
#define OSServiceId_SyncScheduleTable           74

/**
 * @def STORE_SCHEDTABLE_ID
 *
 * Stores a schedule table identifier into service error variable
 *
 * @param sched_table_id type is #ScheduleTableType
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
#   define STORE_SCHEDTABLE_ID(sched_table_id)   \
    tpl_service.parameters.id.schedtable_id = (sched_table_id);
#else
#   define STORE_SCHEDTABLE_ID(sched_table_id)
#endif 

/**
 * @def STORE_SCHEDTABLE_ID2
 *
 * Stores the second schedule table identifier into service error variable
 *
 * @param schedtable_id type is #ScheduleTableType
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
#   define STORE_SCHEDTABLE_ID2(sched_table_id)   \
    tpl_service.parameters.param.next_st_id = (sched_table_id);
#else
#   define STORE_SCHEDTABLE_ID2(sched_table_id)
#endif 

/**
 * @def STORE_COUNTER_ID
 *
 * Stores the id of a counter
 *
 * @param counter_id type is #CounterType
 *
 * @see #OSError_IncrementCounter_CounterID
 * 
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_COUNTER_ID(cnt_id)   \
    tpl_service.parameters.id.counter_id = (cnt_id);
#else
#   define STORE_COUNTER_ID(cnt_id)
#endif 

/**
 * @def STORE_ST_STATUS_REF
 *
 * Stores the status reference of a schedule table
 *
 * @param status    type is #ScheduleTableStatusRefType
 *
 * @see #OSError_GetScheduleTableStatus_ScheduleStatus
 * 
 */
#ifdef WITH_ERROR_HOOK
#   define STORE_ST_STATUS_REF(status)   \
    tpl_service.parameters.param.st_stat = (status);
#else
#   define STORE_ST_STATUS_REF(status)
#endif 

/**
 * @def CHECK_SCHEDTABLE_ID_ERROR
 *
 * Checks if sched_table_id is a valid schedule table identifier.
 *
 * @param sched_table_id #ScheduleTableType to check
 * @param result error code to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the sched_table_id in this case */
#   define CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)
#endif

/* NO_SCHEDTABLE and extended error checking (OS_EXTENDED)      */
#if defined(NO_SCHEDTABLE) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)     \
    if (result == (tpl_status)E_OK)                             \
    {                                                           \
        result = (tpl_status)E_OS_ID;                           \
    }
#endif

/* !NO_SCHEDTABLE and extended error checking (OS_EXTENDED)     */
#if !defined(NO_SCHEDTABLE) && defined(OS_EXTENDED)
    /* E_OK or E_OS_LIMIT   */
#   define CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)         \
    if ((result == (tpl_status)E_OK) &&                             \
        ((sched_table_id) >= (ScheduleTableType)SCHEDTABLE_COUNT))  \
    {                                                               \
        result = (tpl_status)E_OS_ID;                               \
    }
#endif

/**
 * @def CHECK_SCHEDTABLE_OFFSET_VALUE
 *
 * Checks if the value is > 0 and <= MAXALLOWEDVALUE of the counter
 * the schedule sched_table_id belongs to.
 *
 * @param sched_table_id #ScheduleTableType
 * @param offset #TickType to check
 * @param result error code to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 * @note checking is disable when OS_EXTENDED is not defined
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
#   define CHECK_SCHEDTABLE_OFFSET_VALUE(sched_table_id,offset,result)
#elif !defined(NO_SCHEDTABLE)
#   define CHECK_SCHEDTABLE_OFFSET_VALUE(sched_table_id,offset,result)  \
    if ((result == (tpl_status)E_OK) &&                                 \
        ((offset >                                                      \
         tpl_schedtable_table[sched_table_id]->                         \
         b_desc.stat_part->counter->max_allowed_value) ||               \
         (offset == (TickType)0)))                                      \
    {                                                                   \
        result = (tpl_status)E_OS_VALUE;                                \
    }
#else
#   define CHECK_SCHEDTABLE_OFFSET_VALUE(sched_table_id,offset,result)  \
    if (result == (tpl_status)E_OK)                                     \
    {                                                                   \
        result = (tpl_status)E_OS_ID;                                   \
    }
#endif


/**
 * @def CHECK_SCHEDTABLE_TICK_VALUE
 *
 * Checks if the value <= MAXALLOWEDVALUE of the counter
 * the schedule sched_table_id belongs to.
 *
 * @param sched_table_id #ScheduleTableType
 * @param tick #TickType to check
 * @param result error code to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 * @note checking is disable when OS_EXTENDED is not defined
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
#   define CHECK_SCHEDTABLE_TICK_VALUE(sched_table_id,tick,result)
#elif !defined(NO_SCHEDTABLE)
#   define CHECK_SCHEDTABLE_TICK_VALUE(sched_table_id,tick,result)      \
    if ((result == (tpl_status)E_OK) &&                                 \
        ((tick >                                                        \
         tpl_schedtable_table[sched_table_id]->                         \
         b_desc.stat_part->counter->max_allowed_value)))                \
    {                                                                   \
        result = (tpl_status)E_OS_VALUE;                                \
    }
#else
#   define CHECK_SCHEDTABLE_TICK_VALUE(sched_table_id,tick,result)      \
    if (result == (tpl_status)E_OK)                                     \
    {                                                                   \
        result = (tpl_status)E_OS_ID;                                   \
    }
#endif

/**
 * @def CHECK_SCHEDTABLE_SYNC
 *
 * Checks a schedule table is synchronizable with global time. This is
 * used in StartScheduleTableSynchron service
 *
 * @param sched_table_id #ScheduleTableType the schedule table
 * @param result error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK at start
 * @note checking is disable when OS_EXTENDED is not defined
 * @note sched_table_id should be checked before doing this check
 */
 
/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the schedule table sync in this case  */
#   define CHECK_SCHEDTABLE_SYNC(sched_table_id, result)
#endif

/* NO_SCHEDTABLE and extended error checking (OS_EXTENDED)  */
#if defined(NO_SCHEDTABLE) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_SCHEDTABLE_SYNC(sched_table_id, result)    \
    if (result == (tpl_status)E_OK)                         \
    {                                                       \
        result = (tpl_status)E_OS_ID;                       \
    }
#endif

/* !NO_SCHEDTABLE and extended error checking (OS_EXTENDED)             */
#if !defined(NO_SCHEDTABLE) && defined(OS_EXTENDED)
    /* E_OK or E_OS_ID when the schedule table cannot be synchronized   */
#   define CHECK_SCHEDTABLE_SYNC(sched_table_id, result)                    \
    if ((result == (tpl_status)E_OK) &&                                     \
        ((((tpl_schedtable_static *)(tpl_schedtable_table[sched_table_id]-> \
            b_desc.stat_part))->sync_strat) == NULL))                       \
    {                                                                       \
        result = (tpl_status)E_OS_ID;                                       \
    }
#endif

/**
 * @def CHECK_SCHEDTABLE_COUNTERS
 *
 * Checks two schedule tables have the same counter. This is used
 * in NextScheduleTable service.
 *
 * @param current_st #ScheduleTableType the current schedule table
 * @param next_st #ScheduleTableType the next schedule table
 * @param result error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK at start
 * @note checking is disable when OS_EXTENDED is not defined
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the schedule table counters in this case */
#   define CHECK_SCHEDTABLE_COUNTERS(current_st, next_st, result)
#endif

/* NO_SCHEDTABLE and extended error checking (OS_EXTENDED)      */
#if defined(NO_SCHEDTABLE) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_SCHEDTABLE_COUNTERS(current_st, next_st, result)   \
    if (result == (tpl_status)E_OK)                                 \
    {                                                               \
        result = (tpl_status)E_OS_ID;                               \
    }
#endif

/* !NO_SCHEDTABLE and extended error checking (OS_EXTENDED)     */
#if !defined(NO_SCHEDTABLE) && defined(OS_EXTENDED)
    /* E_OK or E_OS_ID when counters are different  */
#   define CHECK_SCHEDTABLE_COUNTERS(current_st, next_st, result)   \
    if ((result == (tpl_status)E_OK) &&                             \
        ((current_st->b_desc.stat_part->counter) !=                 \
         (next_st->b_desc.stat_part->counter)))                     \
    {                                                               \
        result = (tpl_status)E_OS_ID;                               \
    }
#endif

/**
 * @def CHECK_COUNTER_ID_ERROR
 *
 * Checks if cnt_id is a valid counter identifier.
 *
 * @param cnt_id #CounterType to check
 * @param result error code to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 *
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the sched_table_id in this case */
#   define CHECK_COUNTER_ID_ERROR(cnt_id,result)
#endif

/* NO_COUNTER and extended error checking (OS_EXTENDED)      */
#if defined(NO_COUNTER) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_COUNTER_ID_ERROR(cnt_id,result)    \
    if (result == (tpl_status)E_OK)                 \
    {                                               \
        result = (tpl_status)E_OS_ID;               \
    }
#endif

/* !NO_COUNTER and extended error checking (OS_EXTENDED)     */
#if !defined(NO_COUNTER) && defined(OS_EXTENDED)
    /* E_OK or E_OS_LIMIT   */
#   define CHECK_COUNTER_ID_ERROR(cnt_id,result)        \
    if ((result == (tpl_status)E_OK) &&                 \
        ((cnt_id) >= (tpl_counter_id)COUNTER_COUNT))    \
    {                                                   \
        result = (tpl_status)E_OS_ID;                   \
    }
#endif

/**
 * @def CHECK_COUNTER_KIND_ERROR
 *
 * Checks if cnt_id the identifier of a software counter.
 *
 * @param cnt_id #CounterType to check
 * @param result error code to set if check fails
 *
 * @note error code is not set if it do not equals E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 *
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the sched_table_id in this case */
#   define CHECK_COUNTER_KIND_ERROR(cnt_id,result)
#endif

/* NO_COUNTER and extended error checking (OS_EXTENDED)      */
#if defined(NO_COUNTER) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_COUNTER_KIND_ERROR(cnt_id,result)  \
    if (result == (tpl_status)E_OK)                 \
    {                                               \
        result = (tpl_status)E_OS_ID;               \
    }
#endif

/* !NO_COUNTER and extended error checking (OS_EXTENDED)     */
#if !defined(NO_COUNTER) && defined(OS_EXTENDED)
    /* E_OK or E_OS_LIMIT   */
#   define CHECK_COUNTER_KIND_ERROR(cnt_id,result)                  \
    if ((result == (tpl_status)E_OK) &&                             \
        ((tpl_counter_table[cnt_id]->kind) != SOFTWARE_COUNTER))    \
    {                                                               \
        result = (tpl_status)E_OS_ID;                               \
    }
#endif

/**
 * @def CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR
 *
 * Checks if a vlue is within the range of the maximum
 * allowed value for a counter
 *
 * @param value     #TickType to check
 * @param result    error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 *
 * @note checking is disable when OS_EXTENDED is not defined
 */

/* No extended error checking (! OS_EXTENDED)                   */
#if !defined(OS_EXTENDED)
    /* Does not check the task_id in this case                  */
#   define CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR(counter_id,value,result)
#endif

/* NO_COUNTER and extended error checking (OS_EXTENDED)         */
#if defined(NO_COUNTER) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR(counter_id,value,result)
#endif

/* !NO_COUNTER and extended error checking (OS_EXTENDED)          */
#if !defined(NO_COUNTER) && defined(OS_EXTENDED)
    /* E_OK or E_OS_VALUE                                       */
#   define CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR(counter_id,value,result)   \
    if ((result == (tpl_status)E_OK) &&                                     \
        ((value) >                                                          \
         tpl_counter_table[(counter_id)]->max_allowed_value))               \
    {                                                                       \
        result = (tpl_status)E_OS_VALUE;                                    \
    }
#endif

/**
 * @def CHECK_ISR_ID_ERROR
 *
 * This macro checks for out of range isr_id error. It 
 * is used in os services which uses isr_id as parameter.
 *
 * @param isr_id #ISRType (so called isr_id) to check
 * @param result error code variable to set (StatusType)
 *
 * @note this checking is disabled if OS_EXTENDED is not set
 *
 * @note the error code is set only if there was no
 * previous error
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
    /* Does not check the isr_id in this case */
#   define CHECK_ISR_ID_ERROR(isr_id,result)
#endif

/* NO_ISR and extended error checking (OS_EXTENDED)        */
#if defined(NO_ISR) && defined(OS_EXTENDED)
    /* E_OS_ID is returned in this case  */
#   define CHECK_ISR_ID_ERROR(isr_id,result)    \
    if (result == (tpl_status)E_OK)             \
    {                                           \
        result = (tpl_status)E_OS_ID;           \
    }
#endif

/* !NO_ISR and extended error checking (OS_EXTENDED)   */
#if !defined(NO_ISR) && defined(OS_EXTENDED)
    /* E_OK or E_OS_ID   */
#   define CHECK_ISR_ID_ERROR(isr_id,result)                        \
    if  ((result == (tpl_status)E_OK) &&                            \
        (((isr_id) >= (tpl_isr_id)ISR_COUNT) || ((isr_id) < 0)))    \
    {                                                               \
        result = (tpl_status)E_OS_ID;                               \
    }
#endif


/* TPL_AS_ERROR_H */
#endif
