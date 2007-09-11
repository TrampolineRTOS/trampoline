/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Resource Management
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#include "tpl_machine_interface.h"
#include "tpl_os_kernel.h"
#include "tpl_os_rez_kernel.h"
#include "tpl_os_error.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * OSEK/VDX API services
 */
StatusType GetResource(const ResourceType res_id)
{
    /*  init the error to no error  */
    StatusType result = E_OK;

    tpl_resource *res;

    LOCK_WHEN_HOOK()
    
    STORE_SERVICE(OSServiceId_GetResource)
    STORE_RESOURCE_ID(res_id)
    
    CHECK_RESOURCE_ID_ERROR(res_id,result)

    IF_NO_EXTENDED_ERROR(result)
        if (res_id == RES_SCHEDULER)
        {
            res = &res_sched;
        }
        else
        {
			#ifndef NO_RESOURCE
            	res = tpl_resource_table[res_id];
			#else
				res = NULL; /* error */
			#endif
        }
        
        LOCK_WHEN_NO_HOOK()
        
        /*  Return an error if the task that attempt to get
            the resource has a higher priority than the resource
            or the resource is already owned by another task
            By using PCP, this situation should no occur.           */
        CHECK_RESOURCE_PRIO_ERROR_ON_GET(res,result)
            
        IF_NO_EXTENDED_ERROR(result)
            tpl_get_resource(res);
        #ifdef AUTOSAR
        tpl_start_resource_monitor (tpl_running_obj, res_id);
        #endif
        IF_NO_EXTENDED_ERROR_END()
        
        UNLOCK_WHEN_NO_HOOK()
    IF_NO_EXTENDED_ERROR_END()
    
    PROCESS_ERROR(result)
    
    UNLOCK_WHEN_HOOK()
    
    return result;
}

StatusType ReleaseResource(const ResourceType res_id)
{
    /*  init the error to no error  */
    StatusType result = E_OK;
    
    tpl_resource *res;
    
    LOCK_WHEN_HOOK()
    
    STORE_SERVICE(OSServiceId_GetResource)
    STORE_RESOURCE_ID(res_id)
    
    CHECK_RESOURCE_ID_ERROR(res_id,result)
    
    IF_NO_EXTENDED_ERROR(result)
        if (res_id == RES_SCHEDULER)
        {
            res = &res_sched;
        }
        else
        {
			#ifndef NO_RESOURCE
            	res = tpl_resource_table[res_id];
			#else
				res = NULL; /* error */
			#endif
        }
        
        LOCK_WHEN_NO_HOOK()
    
        /*  Return an error if the task that attempt to get
            the resource has a higher priority than the resource    */
        CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(res,result)
        
        /*  the spec requires resources to be released in
            the reverse order of the getting. if the resource
            is not owned or not release in the good order       */
        CHECK_RESOURCE_ORDER_ON_RELEASE(res,result)
        
        IF_NO_EXTENDED_ERROR(result)
            tpl_release_resource(res);
        #ifdef WITH_AUTOSAR_TIMING_PROTECTION
        tpl_disable_resource_monitor (tpl_running_obj, res_id);
        #endif /* WITH_AUTOSAR_TIMING_PROTECTION */
        IF_NO_EXTENDED_ERROR_END()
    
        UNLOCK_WHEN_NO_HOOK()
    IF_NO_EXTENDED_ERROR_END()
    
    PROCESS_ERROR(result)
    
    UNLOCK_WHEN_HOOK()
    
    return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_rez.c */
