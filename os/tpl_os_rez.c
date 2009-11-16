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

#ifndef WITH_SYSTEM_CALL

#include "tpl_os_rez.h"
#include "tpl_os_rez_kernel.h"
#include "tpl_os_definitions.h"

#ifdef WITH_AUTOSAR
#include "tpl_as_isr.h"
#endif

#define API_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * OSEK/VDX API services
 */
FUNC(StatusType, OS_CODE) GetResource(
    CONST(ResourceType, AUTOMATIC) res_id)
{
    return tpl_get_resource_service(res_id);
}

FUNC(StatusType, OS_CODE) ReleaseResource(
    CONST(ResourceType, AUTOMATIC) res_id)
{
    return OSEK_STATUS_MASK & tpl_release_resource_service(res_id);
}

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

#else
#error "This file should not be part of your project since WITH_SYSTEM_CALL is defined"
#endif /* WITH_SYSTEM_CALL */

/* End of file tpl_os_rez.c */
