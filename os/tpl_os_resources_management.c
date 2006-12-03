/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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

#include "tpl_os.h"
#include "tpl_os_kernel.h"
#include "tpl_os_error.h"

extern tpl_resource res_scheduler;

void tpl_get_task_lock(void);
void tpl_release_task_lock(void);

/*
 * Prototypes of external functions
 */
void tpl_schedule(int);


/*
 * Getting a resource.
 */
void tpl_get_resource(tpl_resource *res)
{
    /*  set the owner of the resource to the calling task       */
    res->owner = tpl_running_obj;
    /*  add the ressource at the beginning of the
        resource list stored in the task descriptor             */
    res->next_res = tpl_running_obj->resources;
    tpl_running_obj->resources = res;
    /*  save the current priority of the task in the resource   */
    res->owner_prev_priority = tpl_running_obj->priority;
   
    if (tpl_running_obj->priority < res->ceiling_priority) {
        /*  set the task priority at the ceiling priority of the resource
            if the ceiling priority is greater than the current priority of the task   */
        tpl_running_obj->priority = res->ceiling_priority;
    }
}

/*
 * Releasing a resource
 */
void tpl_release_resource(tpl_resource *res)
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

/*
 * OSEK/VDX API services
 */
StatusType GetResource(ResourceType res_id)
{
    /*  init the error to no error  */
    StatusType result = E_OK;

    tpl_resource *res;

    LOCK_WHEN_HOOK()
    
    STORE_SERVICE(OSServiceId_GetResource)
    STORE_RESOURCE_ID(res_id)
    
    CHECK_RESOURCE_ID_ERROR(res_id,result)

    IF_NO_EXTENDED_ERROR(result)
        if (res_id == -1) {
            res = &res_scheduler;
        }
        else {
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
        END_IF_NO_EXTENDED_ERROR()
        
        UNLOCK_WHEN_NO_HOOK()
    END_IF_NO_EXTENDED_ERROR()
    
    PROCESS_ERROR(result)
    
    UNLOCK_WHEN_HOOK()
    
    return result;
}

StatusType ReleaseResource(ResourceType res_id)
{
    /*  init the error to no error  */
    StatusType result = E_OK;
    
    tpl_resource *res;
    
    LOCK_WHEN_HOOK()
    
    STORE_SERVICE(OSServiceId_GetResource)
    STORE_RESOURCE_ID(res_id)
    
    CHECK_RESOURCE_ID_ERROR(res_id,result)
    
    IF_NO_EXTENDED_ERROR(result)
        if (res_id == -1) {
            res = &res_scheduler;
        }
        else {
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
        END_IF_NO_EXTENDED_ERROR()
    
        UNLOCK_WHEN_NO_HOOK()
    END_IF_NO_EXTENDED_ERROR()
    
    PROCESS_ERROR(result)
    
    UNLOCK_WHEN_HOOK()
    
    return result;
}
