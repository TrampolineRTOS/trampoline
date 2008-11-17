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

#include "tpl_os_alarm.h"
#include "tpl_os_alarm_kernel.h"

#ifdef WITH_SYSTEM_CALL
#include "tpl_os_service_ids.h"
#include "tpl_dispatch.h"
#endif

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
ASM FUNC(StatusType, OS_CODE) GetAlarmBase(
    CONST(AlarmType, AUTOMATIC)       alarm_id,
    VAR(AlarmBaseRefType, AUTOMATIC)  info
)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_GetAlarmBase)
#else
    return tpl_get_alarm_base_service(alarm_id, info);
#endif
}

/*
 * GetAlarm
 *
 * See page 63 of the OSEK spec
 */
ASM FUNC(StatusType, OS_CODE) GetAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    VAR(TickRefType, AUTOMATIC) tick)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_GetAlarm)
#else
    return tpl_get_alarm_service(alarm_id, tick);
#endif
}

/*
 * SetRelAlarm
 *
 * See page 63 of the OSEK spec
 */
ASM FUNC(StatusType, OS_CODE) SetRelAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    CONST(TickType, AUTOMATIC)  increment,
    CONST(TickType, AUTOMATIC)  cycle
)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_SetRelAlarm)
#else
    return tpl_set_rel_alarm_service(alarm_id, increment, cycle);
#endif
}

/*
 * SetAbsAlarm
 *
 * See page 64 of the OSEK spec
 */
ASM FUNC(StatusType, OS_CODE) SetAbsAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    CONST(TickType, AUTOMATIC)  start,
    CONST(TickType, AUTOMATIC)  cycle
)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_SetAbsAlarm)
#else
    return tpl_set_abs_alarm_service(alarm_id, start, cycle);
#endif
}

/*
 * CancelAlarm
 *
 * See page 65 of the OSEK spec
 */
ASM FUNC(StatusType, OS_CODE) CancelAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id
)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_CancelAlarm)
#else
    return tpl_cancel_alarm_service(alarm_id);
#endif
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_alarm.c */
