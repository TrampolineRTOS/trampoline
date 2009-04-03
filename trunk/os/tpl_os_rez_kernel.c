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

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * This special resource is used to deny preemption.
 *
 * @note    It can be used by a task but is not stored
 *          in the general resource table.
 *
 * see paragraph 13.4.4 page 59 of OSEK/VDX 2.2.2 spec
 */
CONST(tpl_resource_id, OS_CONST) RES_SCHEDULER = RESOURCE_COUNT - 1;

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * The scheduler resource descriptor
 *
 * @see #RES_SCHEDULER
 */
VAR(tpl_resource, OS_VAR) res_sched_rez_desc = {
  RES_SCHEDULER_PRIORITY, /*  ceiling priority                            */
  0,                      /*  owner_prev_priority                         */
  INVALID_TASK,           /*  owner                                       */
#ifdef WITH_OSAPPLICATION
  INVALID_OSAPPLICATION,  /*  OS Application id                           */
#endif    
  NULL                    /*  next_res                                    */
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"


#ifdef WITH_OSAPPLICATION
/**
 * @internal
 *
 * tpl_release_all_resources releases all the resources got by a process
 * Since this function is called when the proccess is killed, the priority
 * of the process is not changed by this function.
 * No rescheduling is done.
 */
FUNC(void, OS_CODE) tpl_release_all_resources(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  /*  Get the resource pointer of the process */
  P2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA) res =
  tpl_dyn_proc_table[proc_id]->resources;
  
  if (res != NULL)
  {
    tpl_dyn_proc_table[proc_id]->resources = NULL;
    
    do
    {
      CONSTP2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA) next_res =
      res->next_res;
      res->owner = INVALID_TASK;
      res->next_res = NULL;
      res = next_res;
    } while (res != NULL);
  }
}
#endif

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
  
  LOCK_KERNEL()
  
  STORE_SERVICE(OSServiceId_GetResource)
  STORE_RESOURCE_ID(res_id)
  
  CHECK_RESOURCE_ID_ERROR(res_id,result)
  
  IF_NO_EXTENDED_ERROR(result)
#ifndef NO_RESOURCE
  res = tpl_resource_table[res_id];
#else
  res = NULL; /* error */
#endif

  /*  Return an error if the task that attempt to get
      the resource has a higher priority than the resource
      or the resource is already owned by another task
      By using PCP, this situation should no occur.         */
  CHECK_RESOURCE_PRIO_ERROR_ON_GET(res,result)
  
  IF_NO_EXTENDED_ERROR(result)
    /*  set the owner of the resource to the calling task     */
    res->owner = tpl_kern.running_id;
    /*  add the ressource at the beginning of the
        resource list stored in the task descriptor              */
    res->next_res = tpl_kern.running->resources;
    tpl_kern.running->resources = res;
    /*  save the current priority of the task in the resource */
    res->owner_prev_priority = tpl_kern.running->priority;
  
    if (tpl_kern.running->priority < res->ceiling_priority)
    {
      /*  set the task priority at the ceiling priority of the resource
          if the ceiling priority is greater than the current priority of
          the task  */
      tpl_kern.running->priority = res->ceiling_priority;
    }
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_start_resource_monitor(tpl_kern.running_id, res_id);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
  IF_NO_EXTENDED_ERROR_END()
  
  IF_NO_EXTENDED_ERROR_END()
  
  PROCESS_ERROR(result)
  
  UNLOCK_KERNEL()
  
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

  LOCK_KERNEL()

  STORE_SERVICE(OSServiceId_ReleaseResource)
  STORE_RESOURCE_ID(res_id)

  CHECK_RESOURCE_ID_ERROR(res_id,result)

  IF_NO_EXTENDED_ERROR(result)
  #ifndef NO_RESOURCE
    res = tpl_resource_table[res_id];
  #else
    res = NULL; /* error */
  #endif
  
    /*  the spec requires resources to be released in
        the reverse order of the getting. if the resource
        is not owned or not release in the good order.
        This test has to be done before CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE
        because CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE assumes the
        resource is gotten
    */
    CHECK_RESOURCE_ORDER_ON_RELEASE(res,result)
  
    /*  Return an error if the task that attempt to get
        the resource has a higher priority than the resource    */
    CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(res,result)

    IF_NO_EXTENDED_ERROR(result)
        /*  get the saved priority  */
      tpl_kern.running->priority = res->owner_prev_priority;
      /*  remove the resource from the resource list  */
      tpl_kern.running->resources = res->next_res;
      res->next_res = NULL;
      /*  remove the owner    */
      res->owner = INVALID_TASK;

      tpl_schedule_from_running();
# ifdef WITH_AUTOSAR_TIMING_PROTECTION
      tpl_stop_resource_monitor(tpl_kern.running_id, res_id);
# endif /* WITH_AUTOSAR_TIMING_PROTECTION */
# ifndef WITH_SYSTEM_CALL
      if (tpl_kern.need_switch != NO_NEED_SWITCH)
      {
        tpl_switch_context(
          &(tpl_kern.s_old->context),
          &(tpl_kern.s_running->context)
        );
      }
# endif
    IF_NO_EXTENDED_ERROR_END()

  IF_NO_EXTENDED_ERROR_END()

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_rez_kernel.c */
