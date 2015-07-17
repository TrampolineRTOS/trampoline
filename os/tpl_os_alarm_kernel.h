/**
 * @file tpl_os_alarm_kernel.h
 *
 * @section desc File description
 *
 * Trampoline Alarm Kernel header file
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
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

#ifndef TPL_OS_ALARM_KERNEL_H
#define TPL_OS_ALARM_KERNEL_H

#include "tpl_os_timeobj_kernel.h"
#include "tpl_os_action.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#if ALARM_COUNT > 0
/**
 * Array of all alarms descriptors
 *
 * Index in this array correspond to the #AlarmType of the alarm
 */
extern CONSTP2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) tpl_alarm_table[ALARM_COUNT];
#endif

/**
 * @struct TPL_ALARM_STATIC
 *
 * This is the data structure used to describe the static part of an alarm.
 * It extends the #TPL_TIME_OBJ_STATIC structure by adding an action to be done
 * when the alarm expires.
 *
 * @see #TPL_TIME_OBJ_STATIC
 */
struct TPL_ALARM_STATIC {
  VAR(tpl_time_obj_static, TYPEDEF)         b_desc;   /**< common part of all objects that
                                                             derive from tpl_time_obj.          */
  P2VAR(tpl_action, TYPEDEF, OS_APPL_DATA)  action;   /**< action to be done when the alarm
                                                             expires                            */
};

/**
 * @typedef tpl_alarm_static
 *
 * This is an alias for the structure #TPL_ALARM_STATIC
 *
 * @see #TPL_ALARM_STATIC
 */
typedef struct TPL_ALARM_STATIC tpl_alarm_static;

/**
 * @internal
 *
 * tpl_raise_alarm is called by tpl_counter_tick
 * when an alarm time object is raised.
 *
 * @param time_obj  The alarm to raise.
 */
FUNC(void, OS_CODE) tpl_raise_alarm(
    P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) time_obj);

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
FUNC(tpl_status, OS_CODE) tpl_get_alarm_base_service(
    CONST(tpl_alarm_id, AUTOMATIC)                  alarm_id,
    P2VAR(tpl_alarm_base, AUTOMATIC, OS_APPL_DATA)  info);


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
FUNC(tpl_status, OS_CODE) tpl_get_alarm_service(
    CONST(tpl_alarm_id, AUTOMATIC)              alarm_id,
    P2VAR(tpl_tick, AUTOMATIC, OS_APPL_DATA)    tick);


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
FUNC(tpl_status, OS_CODE) tpl_set_rel_alarm_service(
    CONST(tpl_alarm_id, AUTOMATIC)  alarm_id,
    CONST(tpl_tick, AUTOMATIC)      increment,
    CONST(tpl_tick, AUTOMATIC)      cycle);


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
FUNC(tpl_status, OS_CODE) tpl_set_abs_alarm_service(
    CONST(tpl_alarm_id, AUTOMATIC)  alarm_id,
    CONST(tpl_tick, AUTOMATIC)      start,
    CONST(tpl_tick, AUTOMATIC)      cycle);


/**
 * Cancels the alarm
 *
 * @param alarm_id identifier of the alarm
 *
 * @retval E_OK no error
 * @retval E_OS_NOFUNC alarm is not in use
 * @retval E_OS_ID (extended error only) alarm_id is invalid
 */
FUNC(tpl_status, OS_CODE) tpl_cancel_alarm_service(
    CONST(tpl_alarm_id, AUTOMATIC) alarm_id);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_ALARM_KERNEL_H */

/* End of file tpl_os_alarm_kernel.h */
