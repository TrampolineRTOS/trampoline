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

#include "tpl_os_rez_kernel.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"
#include "tpl_os_error.h"
#include "tpl_os_errorhook.h"
#include "tpl_machine_interface.h"

#ifdef WITH_AUTOSAR
#include "tpl_as_protec_hook.h"
#endif

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * The scheduler resource descriptor
 *
 * @see #RES_SCHEDULER
 */
VAR(tpl_resource, OS_VAR) descriptor_of_resource_res_sched = {
    RES_SCHEDULER_PRIORITY, /**< the ceiling priority is defined as the
                                 maximum priority of the tasks of the
                                 application                                */
    0,                      /*   owner_prev_priority                        */
    NULL,                   /*   owner                                      */
    NULL                    /*   next_res                                   */
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Getting a resource.
 *
 * Change:jlb:2008-09-25
 *  The ressource RES_SCHEDULER is now put in the tpl_resource_table array
 *  as the last item. This simplify tpl_get_resource_service.
 */
FUNC(tpl_status, OS_CODE) tpl_get_resource_service(
    CONST(tpl_resource_id, AUTOMATIC) res_id)
{
    /*  init the error to no error  */
    VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifndef NO_RESOURCE
    P2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA) res;
#endif

    /* check interrupts are not disabled by user    */
    CHECK_INTERRUPT_LOCK(result)

    LOCK_WHEN_HOOK()

    STORE_SERVICE(OSServiceId_GetResource)
    STORE_RESOURCE_ID(res_id)

    CHECK_RESOURCE_ID_ERROR(res_id,result)

    IF_NO_EXTENDED_ERROR(result)
    #ifndef NO_RESOURCE
        res = tpl_resource_table[res_id];
    #else
        res = NULL; /* error */
    #endif

        LOCK_WHEN_NO_HOOK()

        /*  Return an error if the task that attempt to get
            the resource has a higher priority than the resource
            or the resource is already owned by another task
            By using PCP, this situation should no occur.           */
        CHECK_RESOURCE_PRIO_ERROR_ON_GET(res,result)

        IF_NO_EXTENDED_ERROR(result)
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
        #ifdef WITH_AUTOSAR_TIMING_PROTECTION
            tpl_start_resource_monitor (tpl_running_obj, res_id);
        #endif /* WITH_AUTOSAR_TIMING_PROTECTION */
        IF_NO_EXTENDED_ERROR_END()

        UNLOCK_WHEN_NO_HOOK()
    IF_NO_EXTENDED_ERROR_END()

    PROCESS_ERROR(result)

    UNLOCK_WHEN_HOOK()

    return result;
}

/*
 * Releasing a resource
 *
 * Change:jlb:2008-09-25
 *  The ressource RES_SCHEDULER is now put in the tpl_resource_table array
 *  as the last item. This simplify tpl_get_resource_service.
 */
FUNC(tpl_status, OS_CODE) tpl_release_resource_service(
    CONST(tpl_resource_id, AUTOMATIC) res_id)
{
    /*  init the error to no error  */
    VAR(tpl_status, AUTOMATIC) result = E_OK;

    P2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA) res;

    /* check interrupts are not disabled by user    */
    CHECK_INTERRUPT_LOCK(result)

    LOCK_WHEN_HOOK()

    STORE_SERVICE(OSServiceId_GetResource)
    STORE_RESOURCE_ID(res_id)

    CHECK_RESOURCE_ID_ERROR(res_id,result)

    IF_NO_EXTENDED_ERROR(result)
    #ifndef NO_RESOURCE
        res = tpl_resource_table[res_id];
    #else
        res = NULL; /* error */
    #endif
    
        LOCK_WHEN_NO_HOOK()

        /*  Return an error if the task that attempt to get
            the resource has a higher priority than the resource    */
        CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(res,result)

        /*  the spec requires resources to be released in
            the reverse order of the getting. if the resource
            is not owned or not release in the good order       */
        CHECK_RESOURCE_ORDER_ON_RELEASE(res,result)

        IF_NO_EXTENDED_ERROR(result)
            /*  get the saved priority  */
            tpl_running_obj->priority = res->owner_prev_priority;
            /*  remove the resource from the resource list  */
            tpl_running_obj->resources = res->next_res;
            res->next_res = NULL;
            /*  remove the owner    */
            res->owner = NULL;

/* FIX */
            result |= tpl_schedule_from_running(FROM_TASK_LEVEL);
        #ifdef WITH_AUTOSAR_TIMING_PROTECTION
            tpl_stop_resource_monitor(tpl_running_obj, res_id);
        #endif /* WITH_AUTOSAR_TIMING_PROTECTION */
        IF_NO_EXTENDED_ERROR_END()

        if ((result & NEED_CONTEXT_SWITCH) == NEED_CONTEXT_SWITCH) {
            tpl_switch_context(
                (P2VAR(tpl_context, AUTOMATIC, OS_APPL_DATA))
                    &(tpl_old_running_obj->static_desc->context),
                (P2VAR(tpl_context, AUTOMATIC, OS_APPL_DATA))
                    &(tpl_running_obj->static_desc->context)
            );
        }

        UNLOCK_WHEN_NO_HOOK()
    IF_NO_EXTENDED_ERROR_END()

    PROCESS_ERROR(result)

    UNLOCK_WHEN_HOOK()

    return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_rez_kernel.c */
