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

/*
 * GetAlarmBase
 *
 * See page 63 of the OSEK spec
 */
StatusType GetAlarmBase(
    const AlarmType     alarm_id,
    AlarmBaseRefType    info)
{
    StatusType result = E_OK;
    
#ifndef NO_ALARM
    tpl_alarm *alarm;
#endif

    STORE_SERVICE(OSServiceId_GetAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_ALARM_BASE_REF(info)
    
    CHECK_ALARM_ID_ERROR(alarm_id,result)
    
#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
        alarm = tpl_alarm_table[alarm_id];
        
        /*  NOT YET IMPLEMENTED FOR mincycle and maxallowedvalue    */
        info->ticksperbase = alarm->counter->ticks_per_base;
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
StatusType GetAlarm(
    const AlarmType alarm_id,
    TickRefType     tick)
{
    StatusType result = E_OK;
    
#ifndef NO_ALARM
    tpl_alarm *alarm;
#endif

    STORE_SERVICE(OSServiceId_GetAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_TICK_REF(tick)

    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
        alarm = tpl_alarm_table[alarm_id];
        
        /*  verify the alarm is active  */
        if (alarm->state == (tpl_alarm_state)ALARM_ACTIVE)
        {
            *tick = alarm->date - alarm->counter->current_date;
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
StatusType SetRelAlarm(
    const AlarmType alarm_id,
    const TickType  increment,
    const TickType  cycle)
{
    StatusType result = E_OK;
    
#ifndef NO_ALARM
    tpl_alarm *alarm;
#endif
    
    STORE_SERVICE(OSServiceId_SetRelAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_TICK_1(increment)
    STORE_TICK_2(cycle)

    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
        alarm = tpl_alarm_table[alarm_id];
    
        if (alarm->state == (tpl_alarm_state)ALARM_SLEEP)
        {
            /*  the alarm is not in use, proceed    */
            alarm->date = alarm->counter->current_date + increment;
            alarm->cycle = cycle;
            tpl_insert_alarm(alarm);
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
 * SetRelAlarm
 *
 * See page 64 of the OSEK spec
 */
StatusType SetAbsAlarm(
    const AlarmType alarm_id,
    const TickType  start,
    const TickType  cycle)
{
    StatusType result = E_OK;
    
#ifndef NO_ALARM
    tpl_alarm *alarm;
#endif
    
    STORE_SERVICE(OSServiceId_SetAbsAlarm)
    STORE_ALARM_ID(alarm_id)
    STORE_TICK_1(start)
    STORE_TICK_2(cycle)

    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
    alarm = tpl_alarm_table[alarm_id];
    
    if (alarm->state == (tpl_alarm_state)ALARM_SLEEP)
    {
        /*  the alarm is not in use, proceed    */
        alarm->date = start;
        alarm->cycle = cycle;
        tpl_insert_alarm(alarm);
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
StatusType CancelAlarm(const AlarmType alarm_id)
{
    StatusType result = E_OK;
    
#ifndef NO_ALARM
    tpl_alarm *alarm;
#endif

    STORE_SERVICE(OSServiceId_CancelAlarm)
    STORE_ALARM_ID(alarm_id)
    
    CHECK_ALARM_ID_ERROR(alarm_id,result)

#ifndef NO_ALARM
    IF_NO_EXTENDED_ERROR(result)
    alarm = tpl_alarm_table[alarm_id];

    if (alarm->state == (tpl_alarm_state)ALARM_ACTIVE)
    {
        tpl_remove_alarm(alarm);
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

/* End of file tpl_os_alarm.c */
