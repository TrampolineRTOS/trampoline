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

#include "tpl_os_error.h"
#include "tpl_os_kernel.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_alarm.h"

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
    VAR(StatusType, AUTOMATIC) result = E_OK;

#ifndef NO_ALARM
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC) alarm;
#endif

    STORE_SERVICE(OSServiceId_GetAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_ALARM_BASE_REF(info)

    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
        alarm = tpl_alarm_table[alarm_id];

        info->ticksperbase = alarm->stat_part->counter->ticks_per_base;
        info->maxallowedvalue = alarm->stat_part->counter->max_allowed_value;
        info->mincycle = alarm->stat_part->counter->min_cycle;
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    return result;
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
    VAR(StatusType, AUTOMATIC) result = E_OK;

#ifndef NO_ALARM
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC) alarm;
#endif

    STORE_SERVICE(OSServiceId_GetAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_TICK_REF(tick)

    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
        alarm = tpl_alarm_table[alarm_id];

        /*  verify the alarm is active  */
        if (alarm->state == (tpl_time_obj_state)ALARM_ACTIVE)
        {
            *tick = alarm->date - alarm->stat_part->counter->current_date;
        }
        else
        {
            result = E_OS_NOFUNC;
        }
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    return result;
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
    VAR(StatusType, AUTOMATIC) result = E_OK;

#ifndef NO_ALARM
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC) alarm;
#endif

    STORE_SERVICE(OSServiceId_SetRelAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_TICK_1(increment)
    STORE_TICK_2(cycle)

    CHECK_ALARM_ID_ERROR(alarm_id,result)
    CHECK_ALARM_MAX_ALLOWED_VALUE_ERROR(alarm_id,increment,result)
    CHECK_ALARM_MIN_CYCLE_ERROR(alarm_id,cycle,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
        alarm = tpl_alarm_table[alarm_id];

        if (alarm->state == (tpl_time_obj_state)ALARM_SLEEP)
        {
            tpl_counter *cnt = alarm->stat_part->counter;
            /*  the alarm is not in use, proceed    */
            tpl_tick date = cnt->current_date + increment;
            if (date > cnt->max_allowed_value)
            {
                date -= cnt->max_allowed_value;
            }
            alarm->date = date;
            alarm->cycle = cycle;
            alarm->state = ALARM_ACTIVE;
            tpl_insert_time_obj(alarm);
        }
        else
        {
            /*  the alarm is in use, return the proper error code   */
            result = E_OS_STATE;
        }
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    return result;
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
    VAR(StatusType, AUTOMATIC) result = E_OK;

#ifndef NO_ALARM
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC) alarm;
#endif

    STORE_SERVICE(OSServiceId_SetAbsAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_TICK_1(start)
    STORE_TICK_2(cycle)

    CHECK_ALARM_ID_ERROR(alarm_id,result)
    CHECK_ALARM_MAX_ALLOWED_VALUE_ERROR(alarm_id,start,result)
    CHECK_ALARM_MIN_CYCLE_ERROR(alarm_id,cycle,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
    alarm = tpl_alarm_table[alarm_id];

    if (alarm->state == (tpl_time_obj_state)ALARM_SLEEP)
    {
        /*  the alarm is not in use, proceed    */
        alarm->date = start;
        alarm->cycle = cycle;
        alarm->state = ALARM_ACTIVE;
        tpl_insert_time_obj(alarm);
    }
    else
    {
        /*  the alarm is in use, return the proper error code   */
        result = E_OS_STATE;
    }
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    return result;
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
    VAR(StatusType, AUTOMATIC) result = E_OK;

#ifndef NO_ALARM
    P2VAR(tpl_time_obj, OS_APPL_DATA, AUTOMATIC) alarm;
#endif

    STORE_SERVICE(OSServiceId_CancelAlarm)
    STORE_ALARM_ID(alarm_id)

    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
    alarm = tpl_alarm_table[alarm_id];

    if (alarm->state == (tpl_time_obj_state)ALARM_ACTIVE)
    {
        tpl_remove_time_obj(alarm);
        alarm->state = ALARM_SLEEP;
    }
    else
    {
        result = E_OS_NOFUNC;
    }
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_alarm.c */
