/**
 * @file tpl_os_alarm.h
 *
 * @section desc File description
 *
 * Trampoline Alarm Management Services header file
 * See paragraph 13.6,
 * pages 62+ of OSEK/VDX 2.2.2 spec
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

#ifndef TPL_OS_ALARM_H
#define TPL_OS_ALARM_H

#include "tpl_os_custom_types.h"
#include "tpl_os_types.h"

/*
 * Alarms
 * see paragraph 13.6,
 * pages 62+ of OSEK/VDX 2.2.2 spec
 */

/**
 * @typedef TickType
 *
 * Represents a count value in ticks
 *
 * see paragraph 13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_tick            TickType;

/**
 * @typedef TickRefType
 *
 * References a #TickType
 *
 * see paragraph 13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 */
typedef P2VAR(tpl_tick, OS_APPL_DATA, AUTOMATIC)  TickRefType;

/**
 * @typedef AlarmBaseType
 *
 * see paragraph 13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 *
 * @see #tpl_alarm_base
 */
typedef tpl_alarm_base      AlarmBaseType;

/**
 * @typedef AlarmBaseRefType
 *
 * References an #AlarmBaseType
 *
 * See paragraph 13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 */
typedef P2VAR(tpl_alarm_base, OS_APPL_DATA, AUTOMATIC)  AlarmBaseRefType;

/**
 * @typedef AlarmType
 *
 * alarm identifier
 *
 * See paragraph 13.6.1 page 62 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_alarm_id        AlarmType;

/**
 * @def DeclareAlarm
 *
 * Defines an alarm
 *
 * @param alarm_id alarm C-identifier
 *
 * see paragraph 13.6.2.1 page 62 of OSEK/VDX 2.2.2 spec
 */
#define DeclareAlarm(alarm_id)


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * System services
 * see paragraph 13.6.3,
 * pages 63+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Get informations about alarm base
 *
 * @param alarm_id identifier of the alarm
 * @param info #AlarmBaseType variable where will be stored requested
 * informations
 *
 * @retval E_OK no error
 * @retval E_OS_ID (extended error only) alarm_id is invalid
 *
 * see paragraph 13.6.3.1 page 63 of OSEK/VDX 2.2.2 spec
 */
FUNC(StatusType, OS_CODE) GetAlarmBase(
    CONST(AlarmType, AUTOMATIC)       alarm_id,
    VAR(AlarmBaseRefType, AUTOMATIC)  info);


/**
 * Get relative ticks count before alarm exprires
 *
 * @param alarm_id identifier of the alarm
 * @param tick reference to the variable where ticks will be stored
 *
 * @retval E_OK no error
 * @retval E_OS_NOFUNC alarm_id is not used
 * @retval E_OS_ID (extended error only) alarm_id is invalid
 *
 * see paragraph 13.6.3.2 page 63 of OSEK/VDX 2.2.2 spec
 */
FUNC(StatusType, OS_CODE) GetAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    VAR(TickRefType, AUTOMATIC) tick);


/**
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
 *
 * see paragraph 13.6.3.3 page 63 of OSEK/VDX 2.2.2 spec
 */
FUNC(StatusType, OS_CODE) SetRelAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    CONST(TickType, AUTOMATIC)  increment,
    CONST(TickType, AUTOMATIC)  cycle);


/**
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
 *
 * see paragraph 13.6.3.3 page 63 of OSEK/VDX 2.2.2 spec
 */
FUNC(StatusType, OS_CODE) SetAbsAlarm(
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
 *
 * see paragraph 13.6.3.3 page 63 of OSEK/VDX 2.2.2 spec
 */
FUNC(StatusType, OS_CODE) CancelAlarm(
  CONST(AlarmType, AUTOMATIC) alarm_id);


/*
 * Operating system execution control
 * see paragraph 13.7,
 * pages 66+ of OSEK/VDX 2.2.2 spec
 */

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_ALARM_H */

/* End of file tpl_os_alarm.h */
