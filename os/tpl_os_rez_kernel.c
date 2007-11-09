/**
 * @file tpl_os_rez_kernel.c
 *
 * @section desc File description
 *
 * This implementation file provides internal function
 * for resource management.
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

#include "tpl_os_application_def.h"
#include "tpl_os_definitions.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_kernel.h"
#include "tpl_os_rez_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Getting a resource.
 */
FUNC(void, OS_CODE) tpl_get_resource(
    P2VAR(tpl_resource, OS_APPL_DATA, AUTOMATIC) res)
{
    /*  set the owner of the resource to the calling task       */
    res->owner = tpl_running_obj;
    /*  add the ressource at the beginning of the
        resource list stored in the task descriptor             */
    res->next_res = tpl_running_obj->resources;
    tpl_running_obj->resources = res;
    /*  save the current priority of the task in the resource   */
    res->owner_prev_priority = tpl_running_obj->priority;

    if (tpl_running_obj->priority < res->ceiling_priority)
    {
        /*  set the task priority at the ceiling priority of the resource
            if the ceiling priority is greater than the current priority of
            the task  */
        tpl_running_obj->priority = res->ceiling_priority;
    }
}

/*
 * Releasing a resource
 */
FUNC(void, OS_CODE) tpl_release_resource(
    P2VAR(tpl_resource, OS_APPL_DATA, AUTOMATIC) res)
{
    /*  get the saved priority  */
    tpl_running_obj->priority = res->owner_prev_priority;
    /*  remove the resource from the resource list  */
    tpl_running_obj->resources = res->next_res;
    res->next_res = NULL;
    /*  remove the owner    */
    res->owner = NULL;

    tpl_schedule(FROM_TASK_LEVEL);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_rez_kernel.c */
