/**
 * @file tpl_as_service_ids.h
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
 * $Author: fp$
 * $URL$
 */

#ifndef TPL_AS_SERVICE_IDS_H
#define TPL_AS_SERVICE_IDS_H

/************************
 * Services identifiers *
 ************************/

/**
 * @def OSServiceId_GetApplicationID
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetApplicationID
 */
#define OSServiceId_GetApplicationID   64

/**
 * @def OSServiceId_GetISRID
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetISRID
 */
#define OSServiceId_GetISRID   65

/**
 * @def OSServiceId_CallTrustedFunction
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #CallTrustedFunction
 */
#define OSServiceId_CallTrustedFunction   66

/**
 * @def OSServiceId_CheckISRMemoryAccess
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #CheckISRMemoryAccess
 */
#define OSServiceId_CheckISRMemoryAccess   67

/**
 * @def OSServiceId_CheckTaskMemoryAccess
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #CheckTaskMemoryAccess
 */
#define OSServiceId_CheckTaskMemoryAccess   68

/**
 * @def OSServiceId_CheckObjectAccess
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #CheckObjectAccess
 */
#define OSServiceId_CheckObjectAccess   69

/**
 * @def OSServiceId_CheckObjectOwnership
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #CheckObjectOwnership
 */
#define OSServiceId_CheckObjectOwnership   70

/**
 * @def OSServiceId_StartScheduleTableRel
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartScheduleTableRel
 */
#define OSServiceId_StartScheduleTableRel   71

/**
 * @def OSServiceId_StartScheduleTableAbs
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartScheduleTableAbs
 */
#define OSServiceId_StartScheduleTableAbs   72

/**
 * @def OSServiceId_StopScheduleTable
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StopScheduleTable
 */
#define OSServiceId_StopScheduleTable       73

/**
 * @def OSServiceId_NextScheduleTable
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #NextScheduleTable
 */
#define OSServiceId_NextScheduleTable       74

/**
 * @def OSServiceId_StartScheduleTableSynchron
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #StartScheduleTableSynchron
 */
#define OSServiceId_StartScheduleTableSynchron  75

/**
 * @def OSServiceId_SyncScheduleTable
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SyncScheduleTable
 */
#define OSServiceId_SyncScheduleTable           76

/**
 * @def OSServiceId_GetScheduleTableStatus
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetScheduleTableStatus
 */
#define OSServiceId_GetScheduleTableStatus  77

/**
 * @def OSServiceId_SetScheduleTableAsync
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #SetScheduleTableAsync
 */
#define OSServiceId_SetScheduleTableAsync   78

/**
 * @def OSServiceId_IncrementCounter
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #IncrementCounter
 */
#define OSServiceId_IncrementCounter        79

/**
 * @def OSServiceId_GetCounterValue
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetCounterValue
 */
#define OSServiceId_GetCounterValue         80

/**
 * @def OSServiceId_GetElapsedCounterValue
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #GetElapsedCounterValue
 */
#define OSServiceId_GetElapsedCounterValue  81

/**
 * @def OSServiceId_TerminateApplication
 *
 * @see #SERVICE_CALL_DESCRIPTOR
 * @see #TerminateApplication
 */
#define OSServiceId_TerminateApplication  82

/* TPL_AS_SERVICE_IDS_H */
#endif
/* End of file tpl_as_service_ids.h */


