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
typedef P2VAR(tpl_alarm_base, TYPEDEF, OS_APPL_DATA)  AlarmBaseRefType;

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
#define DeclareAlarm(alarm_id)  \
  extern CONST(AlarmType, AUTOMATIC) alarm_id

/**
 * @def OSMAXALLOWEDVALUE
 *
 * Maximum value of the System Counter in tick
 */
extern CONST(tpl_tick, OS_CONST) OSMAXALLOWEDVALUE;

/**
 * @def OSTICKSPERBASE
 *
 * number of timer tick for 1 counter tick
 */
extern CONST(tpl_tick, OS_CONST) OSTICKSPERBASE;

/**
 * @def OSMINCYCLE
 *
 * minimum tick value for a cyclic alarm
 */
extern CONST(tpl_tick, OS_CONST) OSMINCYCLE;

#endif /* TPL_OS_ALARM_H */

/* End of file tpl_os_alarm.h */
