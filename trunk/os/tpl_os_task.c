/**
 * @file tpl_os_task.c
 *
 * @section desc File description
 *
 * Trampoline Task Management Calls
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Copyright IRISA - JF Deverge for libpcl port
 * Copyright Geensys for hcs12 port
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

#include "tpl_os_task.h"
#include "tpl_os_task_kernel.h"
#include "tpl_os_definitions.h"

#ifdef WITH_SYSTEM_CALL
#include "tpl_os_service_ids.h"
#include "tpl_dispatch.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * OSEK/VDX API services
 *
 * see header file documentation or refer to the OSEK/VDX 2.2.2 specification
 */
ASM FUNC(StatusType, OS_CODE) ActivateTask(
    CONST(TaskType, AUTOMATIC) task_id)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_ActivateTask)
#else
    return OSEK_STATUS_MASK & tpl_activate_task_service(task_id);
#endif
}


ASM FUNC(StatusType, OS_CODE) TerminateTask(void)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_TerminateTask)
#else
    return OSEK_STATUS_MASK & tpl_terminate_task_service();
#endif
}


ASM FUNC(StatusType, OS_CODE) ChainTask(
    CONST(TaskType, AUTOMATIC) task_id)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_ChainTask)
#else
    return OSEK_STATUS_MASK & tpl_chain_task_service(task_id);
#endif
}


ASM FUNC(StatusType, OS_CODE) Schedule(void)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_Schedule)
#else
    return OSEK_STATUS_MASK & tpl_schedule_service();
#endif
}


ASM FUNC(StatusType, OS_CODE) GetTaskID(
    VAR(TaskRefType, AUTOMATIC) task_id)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_GetTaskID)
#else
    return tpl_get_task_id_service(task_id);
#endif
}


ASM FUNC(StatusType, OS_CODE) GetTaskState(
    CONST(TaskType, AUTOMATIC)        task_id,
    VAR(TaskStateRefType, AUTOMATIC)  state)
{
#ifdef WITH_SYSTEM_CALL
    TPL_SYSCALL(OSServiceId_GetTaskState)
#else
    return tpl_get_task_state_service(task_id, state);
#endif
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_task.c */
