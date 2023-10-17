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
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de
 * Nantes Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_resource_kernel.h"
#include "tpl_dow.h"
#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_os_errorhook.h"
#include "tpl_os_kernel.h"
#include "tpl_trace.h"

#if WITH_AUTOSAR == YES
#include "tpl_as_protec_hook.h"
#endif

#include "tpl_os_multicore_macros.h"

#ifdef WITH_DOW
#include <stdio.h>

extern CONSTP2CONST(char, AUTOMATIC, OS_APPL_DATA) proc_name_table[];
#endif

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

extern CONST(tpl_proc_id, AUTOMATIC) INVALID_TASK;

/**
 * This special resource is used to deny preemption.
 *
 * @note    It can be used by a task but is not stored
 *          in the general resource table.
 *
 * see paragraph 13.4.4 page 59 of OSEK/VDX 2.2.2 spec
 */
CONST(tpl_resource_id, OS_CONST) RES_SCHEDULER = RESOURCE_COUNT - 1;

/**
 * @def INVALID_RESOURCE
 *
 * This value is used to specify an invalid resource
 */
CONST(tpl_resource_id, AUTOMATIC) INVALID_RESOURCE = (tpl_resource_id)(-1);

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * tpl_release_all_resources releases all the resources got by a process
 * Since this function is called when the proccess is killed, the priority
 * of the process is not changed by this function.
 * No rescheduling is done.
 */
FUNC(void, OS_CODE)
tpl_release_all_resources(CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  /*  Get the resource pointer of the process */
  P2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA)
  res = tpl_dyn_proc_table[proc_id]->resources;
#if WITH_TRACE == YES
  GET_CURRENT_CORE_ID(core_id)
#endif /* WITH_TRACE */

  if (res != NULL)
  {
    tpl_dyn_proc_table[proc_id]->resources = NULL;

    do
    {
      CONSTP2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA)
      next_res = res->next_res;
      res->owner = INVALID_TASK;
      res->next_res = NULL;

      /* find the id of the resource for the trace */
#if WITH_TRACE == YES
      TRACE_RES_CHANGE_STATE(res->res_id,
                             (tpl_trace_resource_state)RESOURCE_FREE)
#endif /* WITH_TRACE */

      res = next_res;
    } while (res != NULL);
  }
}

/*
 * Getting a resource.
 *
 * Change:jlb:2008-09-25
 *  The ressource RES_SCHEDULER is now put in the tpl_resource_table array
 *  as the last item. This simplify tpl_get_resource_service.
 */
FUNC(tpl_status, OS_CODE)
tpl_get_resource_service(CONST(tpl_resource_id, AUTOMATIC) res_id)
{
  GET_CURRENT_CORE_ID(core_id)
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)

  /*  init the error to no error  */
  VAR(tpl_status, AUTOMATIC) result = E_OK;

#if RESOURCE_COUNT > 0
  P2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA) res;
#endif

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_GetResource)
  STORE_RESOURCE_ID(res_id)

  /* Check call level error */
  CHECK_CALLBACK_CALL_LEVEL_ERROR(result, core_id)

  CHECK_RESOURCE_ID_ERROR(res_id, result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_RESOURCE_ID(core_id, res_id, result)

  IF_NO_EXTENDED_ERROR(result)
  {
#if RESOURCE_COUNT > 0
    res = TPL_RESOURCE_TABLE(core_id)[res_id];
#else
    res = NULL; /* error */
#endif

    /*  Return an error if the task that attempt to get
        the resource has a higher priority than the resource
        or the resource is already owned by another task
        By using PCP, this situation should no occur.         */
    CHECK_RESOURCE_PRIO_ERROR_ON_GET(core_id, res, result)

    IF_NO_EXTENDED_ERROR(result)
    {
      /*  set the owner of the resource to the calling task     */
      res->owner = (tpl_proc_id)TPL_KERN_REF(kern).running_id;
      TRACE_RES_CHANGE_STATE(res_id, (tpl_trace_resource_state)RESOURCE_TAKEN)
      /*  add the ressource at the beginning of the
          resource list stored in the task descriptor              */
      res->next_res = TPL_KERN_REF(kern).running->resources;
      TPL_KERN_REF(kern).running->resources = res;
      /*  save the current priority of the task in the resource */
      res->owner_prev_priority = TPL_KERN_REF(kern).running->priority;

      DOW_DO(printf("*** GetResource: task %s stores priority %d\n",
                    proc_name_table[TPL_KERN_REF(kern).running_id],
                    TPL_KERN_REF(kern).running->priority));

      if (ACTUAL_PRIO(TPL_KERN_REF(kern).running->priority) <
          res->ceiling_priority)
      {
        GET_TAIL_FOR_PRIO(core_id, tail_for_prio)
        /*  set the task priority at the ceiling priority of the resource
            if the ceiling priority is greater than the current priority of
            the task  */
        TPL_KERN_REF(kern).running->priority =
            DYNAMIC_PRIO(res->ceiling_priority, tail_for_prio);
      }
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
/*    tpl_start_resource_monitor((tpl_proc_id)TPL_KERN_REF(kern).running_id,
 * res_id); */
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
    }
  }

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
FUNC(tpl_status, OS_CODE)
tpl_release_resource_service(CONST(tpl_resource_id, AUTOMATIC) res_id)
{
  GET_CURRENT_CORE_ID(core_id)
  /*  init the error to no error  */
  VAR(tpl_status, AUTOMATIC) result = E_OK;

  P2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA) res;

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_ReleaseResource)
  STORE_RESOURCE_ID(res_id)

  /* Check call level error */
  CHECK_CALLBACK_CALL_LEVEL_ERROR(result, core_id)

  CHECK_RESOURCE_ID_ERROR(res_id, result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_RESOURCE_ID(core_id, res_id, result)

  IF_NO_EXTENDED_ERROR(result)
  {
#if RESOURCE_COUNT > 0
    res = TPL_RESOURCE_TABLE(core_id)[res_id];
#else
    res = NULL; /* error */
#endif

    /* Return an error if the task that attempt to release
           the resource has a higher priority than the resource    */
    CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(core_id, res, result)

    /* the spec requires resources to be released in
       the reverse order of the getting. if the resource
       is not owned or not release in the good order.
       This test has to be done before CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE
       because CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE assumes the
       resource is got
    */
    CHECK_RESOURCE_ORDER_ON_RELEASE(core_id, res, result)

    IF_NO_EXTENDED_ERROR(result)
    {
      /*  get the saved priority  */
      TPL_KERN(core_id).running->priority = res->owner_prev_priority;

      DOW_DO(printf("*** ReleaseResource:task %s takes back priority %d\n",
                    proc_name_table[TPL_KERN(core_id).running_id],
                    TPL_KERN(core_id).running->priority));

      /*  remove the resource from the resource list  */
      TPL_KERN(core_id).running->resources = res->next_res;
      res->next_res = NULL;
      /*  remove the owner    */
      res->owner = INVALID_TASK;
      TRACE_RES_CHANGE_STATE(res_id, (tpl_trace_resource_state)RESOURCE_FREE)
      tpl_schedule_from_running(CORE_ID_OR_NOTHING(core_id));
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
/*    tpl_stop_resource_monitor((tpl_proc_id)TPL_KERN(core_id).running_id,
 * res_id); */
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

      LOCAL_SWITCH_CONTEXT(core_id)
    }
  }

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_rez_kernel.c */
