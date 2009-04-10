/**
 * @file tpl_os_alarm.c
 *
 * @section desc File description
 *
 * Trampoline Alarm Management Services implementation file
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
#ifndef WITH_SYSTEM_CALL

#include "tpl_os_alarm.h"
#include "tpl_os_alarm_kernel.h"

#ifdef WITH_AUTOSAR
#include "tpl_as_isr.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * GetAlarmBase
 *
 * See page 63 of the OSEK spec
 */
FUNC(StatusType, OS_CODE) GetAlarmBase(
    CONST(AlarmType, AUTOMATIC)       alarm_id,
    VAR(AlarmBaseRefType, AUTOMATIC)  info
)
{
    return tpl_get_alarm_base_service(alarm_id, info);
}


/*
 * GetAlarm
 *
 * See page 63 of the OSEK spec
 */
FUNC(StatusType, OS_CODE) GetAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    VAR(TickRefType, AUTOMATIC) tick)
{
    return tpl_get_alarm_service(alarm_id, tick);
}

/*
 * SetRelAlarm
 *
 * See page 63 of the OSEK spec
 */
FUNC(StatusType, OS_CODE) SetRelAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    CONST(TickType, AUTOMATIC)  increment,
    CONST(TickType, AUTOMATIC)  cycle
)
{
    return tpl_set_rel_alarm_service(alarm_id, increment, cycle);
}

/*
 * SetAbsAlarm
 *
 * See page 64 of the OSEK spec
 */
FUNC(StatusType, OS_CODE) SetAbsAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    CONST(TickType, AUTOMATIC)  start,
    CONST(TickType, AUTOMATIC)  cycle
)
{
    return tpl_set_abs_alarm_service(alarm_id, start, cycle);
}

/*
 * CancelAlarm
 *
 * See page 65 of the OSEK spec
 */
FUNC(StatusType, OS_CODE) CancelAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id
)
{
    return tpl_cancel_alarm_service(alarm_id);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#else
#error "This file should not be part of your project since WITH_SYSTEM_CALL is defined"
#endif /* WITH_SYSTEM_CALL */

/* End of file tpl_os_alarm.c */
