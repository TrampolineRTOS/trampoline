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
typedef tpl_tick            *TickRefType;

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
typedef tpl_alarm_base      *AlarmBaseRefType;

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

/*
 * System services
 * see paragraph 13.6.3,
 * pages 63+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Get informations about alarm base
 *
 * @param AlarmID identifier of the alarm
 * @param Info #AlarmBaseType variable where will be stored requested informations
 *
 * @retval E_OK no error
 * @retval E_OS_ID (extended error only) AlarmID is invalid
 *
 * see paragraph 13.6.3.1 page 63 of OSEK/VDX 2.2.2 spec
 */
StatusType GetAlarmBase(
    const AlarmType     AlarmID,
    AlarmBaseRefType    Info);

/**
 * Get relative ticks count before alarm exprires
 *
 * @param AlarmID identifier of the alarm
 * @param Tick reference to the variable where ticks will be stored
 *
 * @retval E_OK no error
 * @retval E_OS_NOFUNC AlarmID is not used
 * @retval E_OS_ID (extended error only) AlarmID is invalid
 *
 * see paragraph 13.6.3.2 page 63 of OSEK/VDX 2.2.2 spec
 */
StatusType GetAlarm(
    const AlarmType AlarmID,
    TickRefType Tick);

/**
 * Changes the alarm trigger relative to the current counter
 *
 * @param AlarmID identifier of the alarm
 * @param increment relative ticks to set
 * @param cycle number of cycles after next expiration (0 if unused)
 *
 * @retval E_OK no error
 * @retval E_OS_STATE alarm is already in use
 * @retval E_OS_ID (extended error only) AlarmID is invalid
 * @retval E_OS_VALUE (extended error only) increment or cycle is outside of limits
 *
 * see paragraph 13.6.3.3 page 63 of OSEK/VDX 2.2.2 spec
 */
StatusType SetRelAlarm(
    const AlarmType AlarmID,
    const TickType  increment,
    const TickType  cycle);

/**
 * Changes the alarm trigger relative to the current counter
 *
 * @param AlarmID identifier of the alarm
 * @param start the number of tick when the alarm will raise
 * @param cycle the number of tick when the alarm will raise after the first expiry
 *
 * @retval E_OK no error
 * @retval E_OS_STATE alarm is already in use
 * @retval E_OS_ID (extended error only) AlarmID is invalid
 * @retval E_OS_VALUE (extended error only) start or cycle is outside of limits
 *
 * see paragraph 13.6.3.3 page 63 of OSEK/VDX 2.2.2 spec
 */
StatusType SetAbsAlarm(
    const AlarmType AlarmID,
    const TickType  start,
    const TickType  cycle);

/**
 * Cancels the alarm
 * 
 * @param AlarmID identifier of the alarm
 *
 * @retval E_OK no error
 * @retval E_OS_NOFUNC alarm is not in use
 * @retval E_OS_ID (extended error only) AlarmID is invalid
 *
 * see paragraph 13.6.3.3 page 63 of OSEK/VDX 2.2.2 spec
 */
StatusType CancelAlarm(const AlarmType AlarmID);

/*
 * Operating system execution control
 * see paragraph 13.7,
 * pages 66+ of OSEK/VDX 2.2.2 spec
 */

#endif /* TPL_OS_ALARM_H */

/* End of file tpl_os_alarm.h */
