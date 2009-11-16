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

#ifndef WITH_SYSTEM_CALL

#include "tpl_os_task.h"
#include "tpl_os_task_kernel.h"
#include "tpl_os_definitions.h"


#define API_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * OSEK/VDX API services
 *
 * see header file documentation or refer to the OSEK/VDX 2.2.2 specification
 */
FUNC(StatusType, OS_CODE) ActivateTask(
    CONST(TaskType, AUTOMATIC) task_id)
{
    return OSEK_STATUS_MASK & tpl_activate_task_service(task_id);
}


FUNC(StatusType, OS_CODE) TerminateTask(void)
{
    return OSEK_STATUS_MASK & tpl_terminate_task_service();
}


FUNC(StatusType, OS_CODE) ChainTask(
    CONST(TaskType, AUTOMATIC) task_id)
{
    return OSEK_STATUS_MASK & tpl_chain_task_service(task_id);
}


FUNC(StatusType, OS_CODE) Schedule(void)
{
    return OSEK_STATUS_MASK & tpl_schedule_service();
}


FUNC(StatusType, OS_CODE) GetTaskID(
    VAR(TaskRefType, AUTOMATIC) task_id)
{
    return tpl_get_task_id_service(task_id);
}


FUNC(StatusType, OS_CODE) GetTaskState(
    CONST(TaskType, AUTOMATIC)        task_id,
    VAR(TaskStateRefType, AUTOMATIC)  state)
{
    return tpl_get_task_state_service(task_id, state);
}

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

#else
#error "This file should not be part of your project since WITH_SYSTEM_CALL is defined"
#endif /* WITH_SYSTEM_CALL */

/* End of file tpl_os_task.c */
