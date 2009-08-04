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
 
#ifndef TPL_AS_ERROR_H
#define TPL_AS_ERROR_H

#include "tpl_os_error.h"
#include "tpl_as_service_ids.h"

/**
 * @def OSServiceId_StartScheduleTableRel_ScheduleTableID
 *
 * StartScheduleTableRel service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_StartScheduleTableRel_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)

/**
 * @def OSServiceId_StartScheduleTableRel_value
 *
 * StartScheduleTableRel service error parameter
 *
 * Returns the value (#TickType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_StartScheduleTableRel_offset()   \
	(tpl_service.parameters.param.tick)

/**
 * @def OSServiceId_StartScheduleTableAbs_ScheduleTableID
 *
 * StartScheduleTableAbs service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_StartScheduleTableAbs_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)

/**
 * @def OSServiceId_StartScheduleTableAbs_value
 *
 * StartScheduleTableAbs service error parameter
 *
 * Returns the value (#TickType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_StartScheduleTableAbs_value()   \
	(tpl_service.parameters.param.tick)

/**
 * @def OSServiceId_StopScheduleTable_ScheduleTableID
 *
 * StopScheduleTable service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_StopScheduleTable_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)

/**
 * @def OSServiceId_NextScheduleTable_ScheduleTableID
 *
 * NextScheduleTable service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_NextScheduleTable_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)

/**
 * @def OSServiceId_NextScheduleTable_ScheduleTableID2
 *
 * NextScheduleTable service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_NextScheduleTable_ScheduleTableID2()   \
	(tpl_service.parameters.param.next_st_id)

/**
 * @def OSServiceId_NextScheduleTable_ScheduleTableID2
 *
 * NextScheduleTable service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_NextScheduleTable_ScheduleTableID2()   \
(tpl_service.parameters.param.next_st_id)

/**
 * @def OSServiceId_IncrementCounter_CounterID
 *
 * IncrementCounter service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_IncrementCounter_CounterID()   \
	(tpl_service.parameters.id.counter_id)

/**
 * @def OSServiceId_GetCounterValue_CounterID
 *
 * GetCounterValue service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_GetCounterValue_CounterID()   \
	(tpl_service.parameters.id.counter_id)

/**
 * @def OSServiceId_GetCounterValue_value
 *
 * GetCounterValue service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_GetCounterValue_value()   \
	(tpl_service.parameters.param.tick_ref)

/**
 * @def OSServiceId_GetElapsedCounterValue_CounterID
 *
 * GetElapsedCounterValue service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_GetElapsedCounterValue_CounterID()   \
	(tpl_service.parameters.id.counter_id)

/**
 * @def OSServiceId_GetElapsedCounterValue_previous_value
 *
 * GetElapsedCounterValue service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_GetElapsedCounterValue_previous_value()   \
	(tpl_service.parameters.param.tick_ref)

/**
 * @def OSServiceId_GetElapsedCounterValue_value
 *
 * GetElapsedCounterValue service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_GetElapsedCounterValue_value()   \
	(tpl_service.parameters.param2.tick_ref)

/**
 * @def OSServiceId_GetScheduleTableStatus_ScheduleTableID
 *
 * GetScheduleTableStatus service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_GetScheduleTableStatus_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)

/**
 * @def OSServiceId_GetScheduleTableStatus_status
 *
 * GetScheduleTableStatus service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_GetScheduleTableStatus_status()   \
	(tpl_service.parameters.param.st_stat)

/**
 * @def OSServiceId_SetScheduleTableAsync_ScheduleTableID
 *
 * SetScheduleTableAsync service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_SetScheduleTableAsync_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)

/**
 * @def OSServiceId_StartScheduleTableSynchron_ScheduleTableID
 *
 * StartScheduleTableSynchron service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_StartScheduleTableSynchron_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)

/**
 * @def OSServiceId_SyncScheduleTable_ScheduleTableID
 *
 * SyncScheduleTable service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_SyncScheduleTable_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)

/**
 * @def OSServiceId_SyncScheduleTable_value
 *
 * SyncScheduleTable service error parameter
 *
 * Returns the value (#TickType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#define OSServiceId_SyncScheduleTable_value()   \
	(tpl_service.parameters.param.tick)

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
        ((sched_table_id) >= (tpl_schedtable_id)SCHEDTABLE_COUNT))  \
    {                                                               \
        result = (tpl_status)E_OS_ID;                               \
    }
#endif

/**
 * @def CHECK_SCHEDTABLE_TO_STOPPED
 *
 * Checks if schedule table (to)'s state is stopped.
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
#   define CHECK_SCHEDTABLE_TO_STOPPED(sched_table_id,result)
#elif !defined(NO_SCHEDTABLE)
#   define CHECK_SCHEDTABLE_TO_STOPPED(sched_table_id,result)			\
	if ((result == (tpl_status)E_OK) &&                                 \
	(tpl_schedtable_table[sched_table_id]->b_desc.state !=				\
	SCHEDULETABLE_STOPPED) )											\
	{                                                                   \
		result = (tpl_status)E_OS_STATE;                                \
	}
#else
#   define CHECK_SCHEDTABLE_TO_STOPPED(sched_table_id,result)			\
	if (result == (tpl_status)E_OK)                                     \
	{                                                                   \
		result = (tpl_status)E_OS_ID;                                   \
	}
#endif

/**
 * @def CHECK_SCHEDTABLE_DIFF_STOPPED_AND_NEXT
 *
 * Checks if schedule table (to)'s state is neither stopped nor 'nexted'.
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
#   define CHECK_SCHEDTABLE_DIFF_STOPPED_AND_NEXT(sched_table_id,result)
#elif !defined(NO_SCHEDTABLE)
#   define CHECK_SCHEDTABLE_DIFF_STOPPED_AND_NEXT(sched_table_id,result)	\
	if ((result == (tpl_status)E_OK) &&										\
		( (tpl_schedtable_table[sched_table_id]->b_desc.state ==			\
		SCHEDULETABLE_STOPPED) ||											\
		(tpl_schedtable_table[sched_table_id]->b_desc.state ==				\
		SCHEDULETABLE_NEXT) ) )												\
	{																		\
		result = (tpl_status)E_OS_STATE;									\
	}
#else
#   define CHECK_SCHEDTABLE_DIFF_STOPPED_AND_NEXT(sched_table_id,result)	\
	if (result == (tpl_status)E_OK)											\
	{																		\
		result = (tpl_status)E_OS_ID;										\
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
         (tpl_schedtable_table[sched_table_id]->                        \
         b_desc.stat_part->counter->max_allowed_value -					\
		 (((P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))((tpl_schedtable_table[sched_table_id])->b_desc.stat_part))->expiry[0])->offset) ) \
		 || (offset == (TickType)0)))                                      \
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
 * @def CHECK_SCHEDTABLE_VALUE
 *
 * Checks if the value <= DURATION of the schedule
 * table sched_table_id belongs to.
 *
 * @param sched_table_id #ScheduleTableType
 * @param value #TickType to check
 * @param result error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when OS_EXTENDED is not defined
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
#   define CHECK_SCHEDTABLE_VALUE(sched_table_id,value,result)
#elif !defined(NO_SCHEDTABLE)
#   define CHECK_SCHEDTABLE_VALUE(sched_table_id,value,result)      \
	if ( (result == (tpl_status)E_OK) &&                                 \
		(value >                                                        \
		(((tpl_schedtable_static *)(tpl_schedtable_table[sched_table_id]-> \
		b_desc.stat_part))->length)) )                \
	{                                                                   \
		result = (tpl_status)E_OS_VALUE;                                \
	}
#else
#   define CHECK_SCHEDTABLE_VALUE(sched_table_id,value,result)      \
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
 * @def CHECK_SCHEDTABLE_SYNC_STRATEGY_EQUAL_ERROR
 *
 * Checks
 *
 * @param schedtable #ScheduleTableType
 * @param result error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when OS_EXTENDED is not defined
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
#   define CHECK_SCHEDTABLE_SYNC_STRATEGY_EQUAL_ERROR(st_id,sync,result)
#elif !defined(NO_SCHEDTABLE)
#   define CHECK_SCHEDTABLE_SYNC_STRATEGY_EQUAL_ERROR(st_id,sync,result)        \
    if ( (result == (tpl_status)E_OK) &&										\
	((((tpl_schedtable_static *)(tpl_schedtable_table[st_id]->					\
	b_desc.stat_part))->sync_strat) == sync))									\
    {																			\
        result = (tpl_status)E_OS_ID;											\
    }
#else
#   define CHECK_SCHEDTABLE_SYNC_STRATEGY_EQUAL_ERROR(st_id,sync,result)      \
	if (result == (tpl_status)E_OK)                                     \
	{                                                                   \
		result = (tpl_status)E_OS_ID;                                   \
	}
#endif

/**
 * @def CHECK_SCHEDTABLE_SYNC_STRATEGY_DIFF_ERROR
 *
 * Checks
 *
 * @param schedtable #ScheduleTableType
 * @param result error code to set if check fails
 *
 * @note error code is not set if it does not equal E_OK
 * @note checking is disable when OS_EXTENDED is not defined
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (! OS_EXTENDED)  */
#if !defined(OS_EXTENDED)
#   define CHECK_SCHEDTABLE_SYNC_STRATEGY_DIFF_ERROR(st_id,sync,result)
#elif !defined(NO_SCHEDTABLE)
#   define CHECK_SCHEDTABLE_SYNC_STRATEGY_DIFF_ERROR(st_id,sync,result)            \
	if ( (result == (tpl_status)E_OK) &&                                      \
		((((tpl_schedtable_static *)(tpl_schedtable_table[st_id]-> \
		b_desc.stat_part))->sync_strat) != sync))                \
	{                                                                         \
		result = (tpl_status)E_OS_ID;                                         \
}
#else
#   define CHECK_SCHEDTABLE_SYNC_STRATEGY_DIFF_ERROR(st_id,sync,result)      \
	if (result == (tpl_status)E_OK)                                     \
	{                                                                   \
		result = (tpl_status)E_OS_ID;                                   \
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
        (((isr_id) >= (tpl_isr_id)(ISR_COUNT+TASK_COUNT)) ||        \
        ((isr_id) < TASK_COUNT)))                                   \
    {                                                               \
        result = (tpl_status)E_OS_ID;                               \
    }
#endif


/* TPL_AS_ERROR_H */
#endif

/* End of file tpl_as_error.h */
