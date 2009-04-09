/**
 * @file tpl_os_event.c
 *
 * @section desc File description
 *
 * Trampoline Event Management implementation file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Copyright ESEO for function and data structures documentation
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

#include "tpl_os_event.h"
#include "tpl_os_event_kernel.h"
#include "tpl_os_definitions.h"

#ifdef WITH_SYSTEM_CALL
#include "tpl_os_service_ids.h"
#include "tpl_dispatch.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * SetEvent
 */
#ifndef WITH_SYSTEM_CALL
FUNC(StatusType, OS_CODE) SetEvent(
    CONST(TaskType, AUTOMATIC)      task_id,
    CONST(EventMaskType, AUTOMATIC) event)
{
    StatusType result = tpl_set_event_service(task_id, event);
    return result & OSEK_STATUS_MASK;
}
#endif


/*
 * ClearEvent
 * see paragraph 13.5.3.2, page 61 of OSEK spec 2.2.2
 */
#ifndef WITH_SYSTEM_CALL
FUNC(StatusType, OS_CODE) ClearEvent(
    CONST(EventMaskType, AUTOMATIC) event)
{
    return tpl_clear_event_service(event);
}
#endif

/*
 * GetEvent
 * see paragraph 13.5.3.3, page 61 of OSEK spec 2.2.2
 */
#ifndef WITH_SYSTEM_CALL
FUNC(StatusType, OS_CODE) GetEvent(
    CONST(TaskType, AUTOMATIC)          task_id,
    CONST(EventMaskRefType, AUTOMATIC)  event)
{
    return tpl_get_event_service(task_id, event);
}
#endif

/*
 * WaitEvent
 * see $13.5.3.4, page 61-62 of OSEK spec 2.2.2
 */
#ifndef WITH_SYSTEM_CALL
FUNC(StatusType, OS_CODE) WaitEvent(
    CONST(EventMaskType, AUTOMATIC) event)
{
    StatusType result = tpl_wait_event_service(event);
    return result & OSEK_STATUS_MASK;
}
#endif

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_event.c */
