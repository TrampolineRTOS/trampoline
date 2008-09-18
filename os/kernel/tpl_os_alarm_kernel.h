/**
 * @file tpl_os_alarm_kernel.h
 *
 * @section desc File description
 *
 * Trampoline Alarm Kernel header file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
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

#ifndef TPL_OS_ALARM_KERNEL_H
#define TPL_OS_ALARM_KERNEL_H

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * tpl_raise_alarm is called by tpl_counter_tick
 * when an alarm time object is raised.
 *
 * @param time_obj  The alarm to raise.
 */
FUNC(tpl_status, OS_CODE) tpl_raise_alarm(
    P2CONST(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) time_obj);

/**
 * @internal
 *
 * Get informations about alarm base
 *
 * @param alarm_id identifier of the alarm
 * @param info #AlarmBaseType variable where will be stored requested
 * informations
 *
 * @retval E_OK no error
 * @retval E_OS_ID (extended error only) alarm_id is invalid
 */
FUNC(StatusType, OS_CODE) tpl_get_alarm_base_service(
    CONST(AlarmType, AUTOMATIC)       alarm_id,
    VAR(AlarmBaseRefType, AUTOMATIC)  info);


/**
 * @internal
 * 
 * Get relative ticks count before alarm exprires
 *
 * @param alarm_id identifier of the alarm
 * @param tick reference to the variable where ticks will be stored
 *
 * @retval E_OK no error
 * @retval E_OS_NOFUNC alarm_id is not used
 * @retval E_OS_ID (extended error only) alarm_id is invalid
 */
FUNC(StatusType, OS_CODE) tpl_get_alarm_service(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    VAR(TickRefType, AUTOMATIC) tick);


/**
 * @internal
 * 
 * Changes the alarm trigger relative to the current counter
 *
 * @param alarm_id identifier of the alarm
 * @param increment relative ticks to set
 * @param cycle number of cycles after next expiration (0 if unused)
 *
 * @retval E_OK no error
 * @retval E_OS_STATE alarm is already in use
 * @retval E_OS_ID (extended error only) alarm_id is invalid
 * @retval E_OS_VALUE (extended error only) increment or cycle is outside of
 * limits
 */
FUNC(StatusType, OS_CODE) tpl_set_rel_alarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    CONST(TickType, AUTOMATIC)  increment,
    CONST(TickType, AUTOMATIC)  cycle);


/**
 * @internal
 * 
 * Changes the alarm trigger relative to the current counter
 *
 * @param alarm_id identifier of the alarm
 * @param start the number of tick when the alarm will raise
 * @param cycle the number of tick when the alarm will raise after the first
 * expiry
 *
 * @retval E_OK no error
 * @retval E_OS_STATE alarm is already in use
 * @retval E_OS_ID (extended error only) alarm_id is invalid
 * @retval E_OS_VALUE (extended error only) start or cycle is outside of
 * limits
 */
FUNC(StatusType, OS_CODE) tpl_set_abs_alarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    CONST(TickType, AUTOMATIC)  start,
    CONST(TickType, AUTOMATIC)  cycle);


/**
 * Cancels the alarm
 *
 * @param alarm_id identifier of the alarm
 *
 * @retval E_OK no error
 * @retval E_OS_NOFUNC alarm is not in use
 * @retval E_OS_ID (extended error only) alarm_id is invalid
 */
FUNC(StatusType, OS_CODE) tpl_cancel_alarm_service(
  CONST(AlarmType, AUTOMATIC) alarm_id);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_ALARM_KERNEL_H */

/* End of file tpl_os_alarm_kernel.h */
