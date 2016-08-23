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

/**
 * @def OSError_CheckObjectAccess_ApplicationID
 *
 * CheckObjectAccess service error parameter
 *
 * Returns the identifier (#ApplicationType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_CheckObjectAccess_ApplicationID()   \
		(tpl_service.parameters.id.application_id)
#endif

/**
 * @def OSError_CheckObjectAccess_ObjectType
 *
 * CheckObjectAccess service error parameter
 *
 * Returns the identifier (#ObjectTypeType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_CheckObjectAccess_ObjectType()   \
		(tpl_service.parameters.param.object_type)
#endif

/**
 * @def OSError_CheckObjectAccess_ObjectID
 *
 * CheckObjectAccess service error parameter
 *
 * Returns the identifier (#ObjectID) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_CheckObjectAccess_ObjectID()   \
		(tpl_service.parameters.param2.object_id)
#endif

/**
 * @def OSError_CheckObjectOwnership_ObjectType
 *
 * CheckObjectOwnership service error parameter
 *
 * Returns the identifier (#ObjectTypeType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_CheckObjectOwnership_ObjectType()   \
		(tpl_service.parameters.param.object_type)
#endif

/**
 * @def OSError_CheckObjectOwnership_ObjectID
 *
 * CheckObjectOwnership service error parameter
 *
 * Returns the identifier (#ObjectID) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_CheckObjectOwnership_ObjectID()   \
		(tpl_service.parameters.param2.object_id)
#endif

/**
 * @def OSError_StartScheduleTableRel_ScheduleTableID
 *
 * StartScheduleTableRel service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_StartScheduleTableRel_ScheduleTableID()   \
		(tpl_service.parameters.id.schedtable_id)
#endif

/**
 * @def OSError_StartScheduleTableRel_value
 *
 * StartScheduleTableRel service error parameter
 *
 * Returns the value (#TickType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_StartScheduleTableRel_offset()   \
	(tpl_service.parameters.param.tick)
#endif

/**
 * @def OSError_StartScheduleTableAbs_ScheduleTableID
 *
 * StartScheduleTableAbs service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_StartScheduleTableAbs_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)
#endif

/**
 * @def OSError_StartScheduleTableAbs_value
 *
 * StartScheduleTableAbs service error parameter
 *
 * Returns the value (#TickType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_StartScheduleTableAbs_value()   \
	(tpl_service.parameters.param.tick)
#endif

/**
 * @def OSError_StopScheduleTable_ScheduleTableID
 *
 * StopScheduleTable service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_StopScheduleTable_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)
#endif

/**
 * @def OSError_NextScheduleTable_ScheduleTableID
 *
 * NextScheduleTable service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_NextScheduleTable_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)
#endif

/**
 * @def OSError_NextScheduleTable_ScheduleTableID2
 *
 * NextScheduleTable service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_NextScheduleTable_ScheduleTableID2()   \
	(tpl_service.parameters.param.next_st_id)
#endif

/**
 * @def OSError_IncrementCounter_CounterID
 *
 * IncrementCounter service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_IncrementCounter_CounterID()   \
	(tpl_service.parameters.id.counter_id)
#endif

/**
 * @def OSError_GetCounterValue_CounterID
 *
 * GetCounterValue service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetCounterValue_CounterID()   \
	(tpl_service.parameters.id.counter_id)
#endif

/**
 * @def OSError_GetCounterValue_value
 *
 * GetCounterValue service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetCounterValue_value()   \
	(tpl_service.parameters.param.tick_ref)
#endif

/**
 * @def OSError_GetElapsedCounterValue_CounterID
 *
 * GetElapsedCounterValue service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetElapsedCounterValue_CounterID()   \
	(tpl_service.parameters.id.counter_id)
#endif

/**
 * @def OSError_GetElapsedCounterValue_previous_value
 *
 * GetElapsedCounterValue service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetElapsedCounterValue_previous_value()   \
	(tpl_service.parameters.param.tick_ref)
#endif

/**
 * @def OSError_GetElapsedCounterValue_value
 *
 * GetElapsedCounterValue service error parameter
 *
 * Returns the identifier (#CounterType) of the counter which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetElapsedCounterValue_value()   \
	(tpl_service.parameters.param2.tick_ref)
#endif

/**
 * @def OSError_GetScheduleTableStatus_ScheduleTableID
 *
 * GetScheduleTableStatus service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetScheduleTableStatus_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)
#endif

/**
 * @def OSError_GetScheduleTableStatus_status
 *
 * GetScheduleTableStatus service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_GetScheduleTableStatus_status()   \
	(tpl_service.parameters.param.st_stat)
#endif

/**
 * @def OSError_SetScheduleTableAsync_ScheduleTableID
 *
 * SetScheduleTableAsync service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SetScheduleTableAsync_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)
#endif

/**
 * @def OSError_StartScheduleTableSynchron_ScheduleTableID
 *
 * StartScheduleTableSynchron service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_StartScheduleTableSynchron_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)
#endif

/**
 * @def OSError_SyncScheduleTable_ScheduleTableID
 *
 * SyncScheduleTable service error parameter
 *
 * Returns the identifier (#ScheduleTableType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SyncScheduleTable_ScheduleTableID()   \
	(tpl_service.parameters.id.schedtable_id)
#endif

/**
 * @def OSError_SyncScheduleTable_value
 *
 * SyncScheduleTable service error parameter
 *
 * Returns the value (#TickType) of the schedule table which
 * caused the error.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_SyncScheduleTable_value()   \
	(tpl_service.parameters.param.tick)
#endif

/**
 * @def OSError_TerminateApplication_opt
 *
 * TerminateApplication service error parameter
 *
 * Returns the value (#uint8) of the option.
 *
 * @warning this macro does only make sense when used within #ErrorHook
 * function
 */
#if WITH_USEPARAMETERACCESS == YES
#define OSError_TerminateApplication_opt()   \
	(tpl_service.parameters.param.opt_termapp)
#endif

/**
 * @def STORE_APPLICATION_ID
 *
 * Stores the id of an application
 *
 * @param counter_id type is #ApplicationID
 *
 * @see #OSError_CheckObjectAccess_ApplicationID
 * 
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#   define STORE_APPLICATION_ID(app_id)   \
	tpl_service.parameters.id.application_id = (app_id);
#else
#   define STORE_APPLICATION_ID(app_id)
#endif 

/**
 * @def STORE_OBJECT_TYPE
 *
 * Stores the type of an object
 *
 * @param counter_id type is #ObjectTypeType
 *
 * @see #OSError_CheckObjectAccess_ObjectType
 * @see #OSError_CheckObjectOwnership_ObjectType
 * 
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#   define STORE_OBJECT_TYPE(obj_typ)   \
	tpl_service.parameters.param.object_type = (obj_typ);
#else
#   define STORE_OBJECT_TYPE(obj_typ)
#endif 

/**
 * @def STORE_OBJECT_ID
 *
 * Stores the id of an object
 *
 * @param counter_id type is #ObjectID
 *
 * @see #OSError_CheckObjectAccess_ObjectID
 * @see #OSError_CheckObjectOwnership_ObjectID
 * 
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#   define STORE_OBJECT_ID(obj_id)   \
		tpl_service.parameters.param2.object_id = (obj_id);
#else
#   define STORE_OBJECT_ID(obj_id)
#endif 

/**
 * @def STORE_SCHEDTABLE_ID
 *
 * Stores a schedule table identifier into service error variable
 *
 * @param sched_table_id type is #ScheduleTableType
 *
 * @see #OSError_StartScheduleTableRel_ScheduleTableID
 * @see #OSError_StartScheduleTableAbs_ScheduleTableID
 * @see #OSError_StopScheduleTable_ScheduleTableID
 * @see #OSError_NextScheduleTable_ScheduleTableID
 * @see #OSError_StartScheduleTableSynchron_ScheduleTableID
 * @see #OSError_SyncScheduleTable_ScheduleTableID
 * @see #OSError_GetScheduleTableStatus_ScheduleTableID
 * @see #OSError_SetScheduleTableAsync_ScheduleTableID
 * 
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
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
 * @see #OSError_NextScheduleTable_ScheduleTableID
 * 
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
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
 * @see #OSError_GetCounterValue_CounterID
 * @see #OSError_GetElapsedCounterValue_CounterID
 * 
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
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
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#   define STORE_ST_STATUS_REF(status)   \
    tpl_service.parameters.param.st_stat = (status);
#else
#   define STORE_ST_STATUS_REF(status)
#endif 

/**
 * @def STORE_TERMAPP_OPT
 *
 * Stores the option when terminating an applicaiton
 *
 * @param opt type is #uint8
 *
 * @see #OSError_TerminateApplication_opt
 * 
 */
#if (WITH_ERROR_HOOK == YES) && (WITH_USEPARAMETERACCESS == YES)
#   define STORE_TERMAPP_OPT(opt)   \
	tpl_service.parameters.param.opt_termapp = (opt);
#else
#   define STORE_TERMAPP_OPT(opt)
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the sched_table_id in this case */
#   define CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)
#endif

/* No scheduletable and extended error checking (WITH_OS_EXTENDED == YES) */
#if (SCHEDTABLE_COUNT == 0) && (WITH_OS_EXTENDED == YES)
    /* E_OS_ID is returned in this case  */
#   define CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)     \
    if (result == (tpl_status)E_OK)                             \
    {                                                           \
        result = (tpl_status)E_OS_ID;                           \
    }
#endif

/* Any scheduletable and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (SCHEDTABLE_COUNT > 0) && (WITH_OS_EXTENDED == YES)
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
#   define CHECK_SCHEDTABLE_TO_STOPPED(sched_table_id,result)
#elif (SCHEDTABLE_COUNT > 0)
#   define CHECK_SCHEDTABLE_TO_STOPPED(sched_table_id,result)			\
	if ((result == (tpl_status)E_OK) &&                             \
	    (tpl_schedtable_table[sched_table_id]->b_desc.state !=      \
	     SCHEDULETABLE_STOPPED) )                                   \
	{                                                               \
		result = (tpl_status)E_OS_STATE;                              \
	}
#else
#   define CHECK_SCHEDTABLE_TO_STOPPED(sched_table_id,result)			\
	if (result == (tpl_status)E_OK)                                 \
	{                                                               \
		result = (tpl_status)E_OS_ID;                                 \
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
#   define CHECK_SCHEDTABLE_DIFF_STOPPED_AND_NEXT(sched_table_id,result)
#elif (SCHEDTABLE_COUNT > 0)
#   define CHECK_SCHEDTABLE_DIFF_STOPPED_AND_NEXT(sched_table_id,result)	\
	if ((result == (tpl_status)E_OK) &&                                     \
		  ((tpl_schedtable_table[sched_table_id]->b_desc.state ==             \
                SCHEDULETABLE_STOPPED) ||                                 \
      (tpl_schedtable_table[sched_table_id]->b_desc.state ==              \
                SCHEDULETABLE_NEXT) ) )                                   \
	{                                                                       \
		result = (tpl_status)E_OS_STATE;                                      \
	}
#else
#   define CHECK_SCHEDTABLE_DIFF_STOPPED_AND_NEXT(sched_table_id,result)	\
	if (result == (tpl_status)E_OK)                                         \
	{                                                                       \
		result = (tpl_status)E_OS_ID;                                         \
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
#   define CHECK_SCHEDTABLE_OFFSET_VALUE(sched_table_id,offset,result)
#elif (SCHEDTABLE_COUNT > 0)
#   define CHECK_SCHEDTABLE_OFFSET_VALUE(sched_table_id,offset,result)  \
    if ((result == (tpl_status)E_OK) &&                                 \
        ((offset >                                                      \
         (tpl_schedtable_table[sched_table_id]->                        \
         b_desc.stat_part->counter->max_allowed_value -                 \
		 (((P2VAR(tpl_schedtable_static, AUTOMATIC, OS_APPL_DATA))((tpl_schedtable_table[sched_table_id])->b_desc.stat_part))->expiry[0])->offset) )     \
		 || (offset == (TickType)0)))                                       \
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
#   define CHECK_SCHEDTABLE_TICK_VALUE(sched_table_id,tick,result)
#elif (SCHEDTABLE_COUNT > 0)
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
#   define CHECK_SCHEDTABLE_VALUE(sched_table_id,value,result)
#elif (SCHEDTABLE_COUNT > 0)
#   define CHECK_SCHEDTABLE_VALUE(sched_table_id,value,result)          \
	if ( (result == (tpl_status)E_OK) &&                                  \
      (value >                                                          \
		(((tpl_schedtable_static *)(tpl_schedtable_table[sched_table_id]->  \
		b_desc.stat_part))->length)) )                                      \
	{                                                                     \
		result = (tpl_status)E_OS_VALUE;                                    \
	}
#else
#   define CHECK_SCHEDTABLE_VALUE(sched_table_id,value,result)          \
	if (result == (tpl_status)E_OK)                                       \
	{                                                                     \
		result = (tpl_status)E_OS_ID;                                     \
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 * @note sched_table_id should be checked before doing this check
 */
 
/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the schedule table sync in this case  */
#   define CHECK_SCHEDTABLE_SYNC(sched_table_id, result)
#endif

/* No scheduletable and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (SCHEDTABLE_COUNT == 0) && (WITH_OS_EXTENDED == YES)
    /* E_OS_ID is returned in this case  */
#   define CHECK_SCHEDTABLE_SYNC(sched_table_id, result)    \
    if (result == (tpl_status)E_OK)                         \
    {                                                       \
        result = (tpl_status)E_OS_ID;                       \
    }
#endif

/* Any scheduletable and extended error checking (WITH_OS_EXTENDED == YES) */
#if (SCHEDTABLE_COUNT > 0) && (WITH_OS_EXTENDED == YES)
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the schedule table counters in this case */
#   define CHECK_SCHEDTABLE_COUNTERS(current_st, next_st, result)
#endif

/* No schedule table and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (SCHEDTABLE_COUNT == 0) && (WITH_OS_EXTENDED == YES)
    /* E_OS_ID is returned in this case  */
#   define CHECK_SCHEDTABLE_COUNTERS(current_st, next_st, result)   \
    if (result == (tpl_status)E_OK)                                 \
    {                                                               \
        result = (tpl_status)E_OS_ID;                               \
    }
#endif

/* Any scheduletable and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (SCHEDTABLE_COUNT > 0) && (WITH_OS_EXTENDED == YES)
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
#   define CHECK_SCHEDTABLE_SYNC_STRATEGY_EQUAL_ERROR(st_id,sync,result)
#elif (SCHEDTABLE_COUNT > 0)
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 * @note sched_table_id should be checked before doing this check
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
#   define CHECK_SCHEDTABLE_SYNC_STRATEGY_DIFF_ERROR(st_id,sync,result)
#elif (SCHEDTABLE_COUNT > 0)
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 *
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the sched_table_id in this case */
#   define CHECK_COUNTER_ID_ERROR(cnt_id,result)
#endif

/* No Counter and extended error checking (WITH_OS_EXTENDED == YES)   */
#if (COUNTER_COUNT == 0) && (WITH_OS_EXTENDED == YES)
    /* E_OS_ID is returned in this case  */
#   define CHECK_COUNTER_ID_ERROR(cnt_id,result)    \
    if (result == (tpl_status)E_OK)                 \
    {                                               \
        result = (tpl_status)E_OS_ID;               \
    }
#endif

/* Any Counter and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (COUNTER_COUNT > 0) && (WITH_OS_EXTENDED == YES)
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 *
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the sched_table_id in this case */
#   define CHECK_COUNTER_KIND_ERROR(cnt_id,result)
#endif

/* No Counter and extended error checking (WITH_OS_EXTENDED == YES)   */
#if (COUNTER_COUNT == 0) && (WITH_OS_EXTENDED == YES)
    /* E_OS_ID is returned in this case  */
#   define CHECK_COUNTER_KIND_ERROR(cnt_id,result)  \
    if (result == (tpl_status)E_OK)                 \
    {                                               \
        result = (tpl_status)E_OS_ID;               \
    }
#endif

/* Any Counter and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (COUNTER_COUNT > 0) && (WITH_OS_EXTENDED == YES)
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
 * @note checking is disable when WITH_OS_EXTENDED == NO
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)          */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the task_id in this case                  */
#   define CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR(counter_id,value,result)
#endif

/* No Counter and extended error checking (WITH_OS_EXTENDED == YES)   */
#if (COUNTER_COUNT == 0) && (WITH_OS_EXTENDED == YES)
    /* E_OS_ID is returned in this case  */
#   define CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR(counter_id,value,result)
#endif

/* Any Counter and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (COUNTER_COUNT > 0) && (WITH_OS_EXTENDED == YES)
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
 * @note this checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no previous error
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the isr_id in this case */
#   define CHECK_ISR_ID_ERROR(isr_id,result)
#endif

/* No ISR and extended error checking (WITH_OS_EXTENDED == YES)   */
#if (ISR_COUNT == 0) && (WITH_OS_EXTENDED == YES)
    /* E_OS_ID is returned in this case  */
#   define CHECK_ISR_ID_ERROR(isr_id,result)    \
    if (result == (tpl_status)E_OK)             \
    {                                           \
        result = (tpl_status)E_OS_ID;           \
    }
#endif

/* Any ISR and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (ISR_COUNT > 0) && (WITH_OS_EXTENDED == YES)
    /* E_OK or E_OS_ID   */
#   define CHECK_ISR_ID_ERROR(isr_id,result)                        \
    if  ((result == (tpl_status)E_OK) &&                            \
        (((isr_id) >= (tpl_isr_id)(ISR_COUNT+TASK_COUNT)) ||        \
        ((isr_id) < TASK_COUNT)))                                   \
    {                                                               \
        result = (tpl_status)E_OS_ID;                               \
    }
#endif



/**
 * @def CHECK_SPINLOCK_ID_ERROR
 *
 * This macro checks for out of range spinlock_id error. It
 * is used in os services which uses spinlock_id as parameter.
 *
 * @param spinlock_id #SpinlockIdType (so called spinlock_id) to check
 * @param result error code variable to set (StatusType)
 *
 * @note this checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no previous error
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the isr_id in this case */
#   define CHECK_SPINLOCK_ID_ERROR(spinlock_id,result)
#endif

/* No SPINLOCK and extended error checking (WITH_OS_EXTENDED == YES)   */
#if (SPINLOCK_COUNT == 0) && (WITH_OS_EXTENDED == YES)
    /* E_OS_ID is returned in this case  */
#   define CHECK_SPINLOCK_ID_ERROR(spinlock_id,result)    \
    if (result == (tpl_status)E_OK)                       \
    {                                                     \
        result = (tpl_status)E_OS_ID;                     \
    }
#endif

/* Any SPINLOCK and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (SPINLOCK_COUNT > 0) && (WITH_OS_EXTENDED == YES)
    /* E_OK or E_OS_ID   */
#   define CHECK_SPINLOCK_ID_ERROR(spinlock_id,result)              \
    if  ((result == (tpl_status)E_OK) &&                            \
         ((spinlock_id) >= (tpl_spinlock_id)(SPINLOCK_COUNT)))             \
    {                                                               \
        result = (tpl_status)E_OS_ID;                               \
    }
#endif

/**
 * @def CHECK_SPINLOCK_NESTING_ORDER_ERROR
 *
 * This macro checks is a spinlock is taken is the right nesting order
 *
 * @param spinlock_id #SpinlockIdType (so called spinlock_id) to check
 * @param result error code variable to set (StatusType)
 *
 * @note this checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no previous error
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the isr_id in this case */
#   define CHECK_SPINLOCK_NESTING_ORDER_ERROR(core_id,spinlock_id,result)
#endif

/* Any SPINLOCK and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (SPINLOCK_COUNT > 0) && (WITH_OS_EXTENDED == YES)
# define CHECK_SPINLOCK_NESTING_ORDER_ERROR(core_id, spinlock_id, result)      \
  if ((result == (tpl_status)E_OK)                                             \
   && (HAS_SPINLOCK(core_id))                                                  \
   && (!SPINLOCK_IS_SUCCESSOR(GET_LAST_TAKEN_SPINLOCK(core_id), spinlock_id))) \
  {                                                                            \
    result = (tpl_status)E_OS_NESTING_DEADLOCK;                                \
  }
#endif

/**
 * @def CHECK_SPINLOCK_UNNESTING_ORDER_ERROR
 *
 * This macro checks is a spinlock is released is the right nesting order
 *
 * @param core_id
 * @param spinlock_id #SpinlockIdType (so called spinlock_id) to check
 * @param result error code variable to set (StatusType)
 *
 * @note this checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no previous error
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the isr_id in this case */
#   define CHECK_SPINLOCK_UNNESTING_ORDER_ERROR(core_id,spinlock_id,result)
#endif

/* Any SPINLOCK and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (SPINLOCK_COUNT > 0) && (WITH_OS_EXTENDED == YES)
    /* E_OK or E_OS_ID   */
#   define CHECK_SPINLOCK_UNNESTING_ORDER_ERROR(core_id,spinlock_id,result) \
    if  (   (result == (tpl_status)E_OK)                                    \
         && (GET_LAST_TAKEN_SPINLOCK(core_id) != spinlock_id))              \
    {                                                                       \
        result = (tpl_status)E_OS_NOFUNC;                                   \
    }
#endif

/**
 * @def CHECK_SPINLOCK_INTERFERENCE_DEADLOCK
 *
 * This macro checks if the spinlock is already occupied by a TASK/ISR2 on the
 * same core
 *
 * @param core_id
 * @param spinlock_id #SpinlockIdType (so called spinlock_id) to check
 * @param result error code variable to set (StatusType)
 *
 * @note this checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no previous error
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the isr_id in this case */
#   define CHECK_SPINLOCK_INTERFERENCE_DEADLOCK_ERROR(core_id,spinlock_id,result)
#endif

/* Any SPINLOCK and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (SPINLOCK_COUNT > 0) && (WITH_OS_EXTENDED == YES)
    /* E_OK or E_OS_ID   */
#   define CHECK_SPINLOCK_INTERFERENCE_DEADLOCK_ERROR(core_id,spinlock_id,result) \
    if  (result == (tpl_status)E_OK)                                        \
    {                                                                       \
        VAR(tpl_spinlock_id, AUTOMATIC) temp;                               \
        for(temp = 0; temp < GET_TAKEN_SPINLOCK_COUNTER(core_id); temp++)   \
        {                                                                   \
          if(GET_TAKEN_SPINLOCK(core_id, temp) == spinlock_id)              \
          {                                                                 \
            result = (tpl_status)E_OS_INTERFERENCE_DEADLOCK;                \
            break;                                                          \
          }                                                                 \
        }                                                                   \
    }
#endif

/**
 * @def CHECK_SPINLOCK_NOT_TAKEN_ERROR
 *
 * This macro checks if the spinlock is not occupied by the calling TASK
 *
 * @param core_id
 * @param spinlock_id #SpinlockIdType (so called spinlock_id) to check
 * @param result error code variable to set (StatusType)
 *
 * @note this checking is disabled if WITH_OS_EXTENDED == NO
 * @note the error code is set only if there was no previous error
 */

/* No extended error checking (WITH_OS_EXTENDED == NO)  */
#if (WITH_OS_EXTENDED == NO)
    /* Does not check the isr_id in this case */
#   define CHECK_SPINLOCK_NOT_TAKEN_ERROR(core_id,spinlock_id,result)
#endif

/* Any SPINLOCK and extended error checking (WITH_OS_EXTENDED == YES)  */
#if (SPINLOCK_COUNT > 0) && (WITH_OS_EXTENDED == YES)
    /* E_OK or E_OS_ID   */
#   define CHECK_SPINLOCK_NOT_TAKEN_ERROR(core_id,spinlock_id,result)         \
    if  (result == (tpl_status)E_OK)                                          \
    {                                                                         \
        VAR(sint32, AUTOMATIC) tmp;                                           \
        result = (tpl_status)E_OS_STATE;                                      \
        for(tmp = GET_TAKEN_SPINLOCK_COUNTER(core_id) - 1; tmp >= 0; tmp--)   \
        {                                                                     \
          if(GET_TAKEN_SPINLOCK(core_id, tmp) == spinlock_id)                 \
          {                                                                   \
            result = (tpl_status) E_OK;                                       \
            break;                                                            \
          }                                                                   \
        }                                                                     \
    }
#endif

/* TPL_AS_ERROR_H */
#endif

/* End of file tpl_as_error.h */
