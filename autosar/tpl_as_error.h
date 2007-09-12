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
 * @def CHECK_SCHEDTABLE_ID_ERROR
 *
 * Checks if sched_table_id is a valid alarm identifier.
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
#   define CHECK_SCHEDTABLE_ID_ERROR(sched_table_id,result)     \
    if ((result == (tpl_status)E_OK) &&                         \
        ((sched_table_id) >= (sched_table_id)SCHEDTABLE_COUNT)) \
    {                                                           \
        result = (tpl_status)E_OS_ID;                           \
    }
#endif

#define CHECK_SCHEDTABLE_COUNTERS(current_st, next_st, result)
#define CHECK_SCHEDTABLE_NEXT(next_st, result)

/* TPL_AS_ERROR_H */
#endif
