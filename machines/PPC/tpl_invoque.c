/**
 * @file tpl_invoque.c
 *
 * @section desc File description
 *
 * Trampoline user level invoque API.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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
#include "tpl_os_application_def.h"
#include "tpl_os_service_ids.h"

#ifdef WITH_SYSTEM_CALL

ASM FUNC(StatusType, OS_CODE) GetAlarmBase(
    CONST(AlarmType, AUTOMATIC)       alarm_id,
    VAR(AlarmBaseRefType, AUTOMATIC)  info
)
{
    TPL_SYSCALL(OSServiceId_GetAlarmBase)
}

ASM FUNC(StatusType, OS_CODE) GetAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    VAR(TickRefType, AUTOMATIC) tick)
{
    TPL_SYSCALL(OSServiceId_GetAlarm)
}

ASM FUNC(StatusType, OS_CODE) SetRelAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    CONST(TickType, AUTOMATIC)  increment,
    CONST(TickType, AUTOMATIC)  cycle
)
{
    TPL_SYSCALL(OSServiceId_SetRelAlarm)
}

ASM FUNC(StatusType, OS_CODE) SetAbsAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id,
    CONST(TickType, AUTOMATIC)  start,
    CONST(TickType, AUTOMATIC)  cycle
)
{
    TPL_SYSCALL(OSServiceId_SetAbsAlarm)
}

ASM FUNC(StatusType, OS_CODE) CancelAlarm(
    CONST(AlarmType, AUTOMATIC) alarm_id
)
{
    TPL_SYSCALL(OSServiceId_CancelAlarm)
}

ASM FUNC(AppModeType, OS_CODE) GetActiveApplicationMode(void)
{
    TPL_SYSCALL(OSServiceId_GetActiveApplicationMode)
}

ASM FUNC(void, OS_CODE) StartOS(
    CONST(AppModeType, AUTOMATIC) mode)
{
    TPL_SYSCALL(OSServiceId_StartOS)
}

ASM FUNC(void, OS_CODE) ShutdownOS(
    CONST(StatusType, AUTOMATIC) error  /*@unused@*/
)
{
    TPL_SYSCALL(OSServiceId_ShutdownOS)
}

ASM FUNC(StatusType, OS_CODE) SetEvent(
    CONST(TaskType, AUTOMATIC)      task_id,
    CONST(EventMaskType, AUTOMATIC) event)
{
    TPL_SYSCALL(OSServiceId_SetEvent)
}

ASM FUNC(StatusType, OS_CODE) ClearEvent(
    CONST(EventMaskType, AUTOMATIC) event)
{
    TPL_SYSCALL(OSServiceId_ClearEvent)
}

ASM FUNC(StatusType, OS_CODE) GetEvent(
    CONST(TaskType, AUTOMATIC)          task_id,
    CONST(EventMaskRefType, AUTOMATIC)  event)
{
    TPL_SYSCALL(OSServiceId_GetEvent)
}

ASM FUNC(StatusType, OS_CODE) WaitEvent(
    CONST(EventMaskType, AUTOMATIC) event)
{
    TPL_SYSCALL(OSServiceId_WaitEvent)
}

ASM FUNC(StatusType, OS_CODE) TerminateISR2(void)
{
    TPL_SYSCALL(OSServiceId_TerminateISR)
}

ASM FUNC(void, OS_CODE) EnableAllInterrupts(void)
{
    TPL_SYSCALL(OSServiceId_EnableAllInterrupts)
}

ASM FUNC(void, OS_CODE) DisableAllInterrupts(void)
{
    TPL_SYSCALL(OSServiceId_DisableAllInterrupts)
}

ASM FUNC(void, OS_CODE) ResumeAllInterrupts(void)
{
    TPL_SYSCALL(OSServiceId_ResumeAllInterrupts)
}

ASM FUNC(void, OS_CODE) SuspendAllInterrupts(void)
{
    TPL_SYSCALL(OSServiceId_SuspendAllInterrupts)
}

ASM FUNC(void, OS_CODE) ResumeOSInterrupts(void)
{
    TPL_SYSCALL(OSServiceId_ResumeOSInterrupts)
}

ASM FUNC(void, OS_CODE) SuspendOSInterrupts(void)
{
    TPL_SYSCALL(OSServiceId_SuspendOSInterrupts)
}

ASM FUNC(StatusType, OS_CODE) GetResource(
    CONST(ResourceType, AUTOMATIC) res_id)
{
    TPL_SYSCALL(OSServiceId_GetResource)
}

ASM FUNC(StatusType, OS_CODE) ReleaseResource(
    CONST(ResourceType, AUTOMATIC) res_id)
{
    TPL_SYSCALL(OSServiceId_ReleaseResource)
}

ASM FUNC(StatusType, OS_CODE) ActivateTask(
    CONST(TaskType, AUTOMATIC) task_id)
{
    TPL_SYSCALL(OSServiceId_ActivateTask)
}

ASM FUNC(StatusType, OS_CODE) TerminateTask(void)
{
    TPL_SYSCALL(OSServiceId_TerminateTask)
}

ASM FUNC(StatusType, OS_CODE) ChainTask(
    CONST(TaskType, AUTOMATIC) task_id)
{
    TPL_SYSCALL(OSServiceId_ChainTask)
}

ASM FUNC(StatusType, OS_CODE) Schedule(void)
{
    TPL_SYSCALL(OSServiceId_Schedule)
}

ASM FUNC(StatusType, OS_CODE) GetTaskID(
    VAR(TaskRefType, AUTOMATIC) task_id)
{
    TPL_SYSCALL(OSServiceId_GetTaskID)
}

ASM FUNC(StatusType, OS_CODE) GetTaskState(
    CONST(TaskType, AUTOMATIC)        task_id,
    VAR(TaskStateRefType, AUTOMATIC)  state)
{
    TPL_SYSCALL(OSServiceId_GetTaskState)
}

#endif /* defined WITH_SYSTEM_CALL */

