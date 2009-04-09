/**
 * @file tpl_os_rez.c
 *
 * @section desc File description
 *
 * Trampoline Resource Management
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
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

#include "tpl_os_rez.h"
#include "tpl_os_rez_kernel.h"
#include "tpl_os_definitions.h"

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
 * OSEK/VDX API services
 */
#ifndef WITH_SYSTEM_CALL
FUNC(StatusType, OS_CODE) GetResource(
    CONST(ResourceType, AUTOMATIC) res_id)
{
    return tpl_get_resource_service(res_id);
}
#endif

#ifndef WITH_SYSTEM_CALL
FUNC(StatusType, OS_CODE) ReleaseResource(
    CONST(ResourceType, AUTOMATIC) res_id)
{
    return OSEK_STATUS_MASK & tpl_release_resource_service(res_id);
}
#endif

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_rez.c */
