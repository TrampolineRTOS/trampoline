/**
 *  @file tpl_as_app_kernel.c
 *  
 *  @section desc File description
 *
 *  Implementation of Autosar OS Application Kernel
 *
 *  @section copyright Copyright
 *
 *  Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2008
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2008
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2
 *  2 - The BSD Licence
 *
 *  @section infos File informations
 *
 *  $Date$
 *  $Rev$
 *  $Author$
 *  $URL$
 */

#include "tpl_as_app_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_task_kernel.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_rez_kernel.h"
#include "tpl_as_counter_kernel.h"
#include "tpl_as_st_kernel.h"
#include "tpl_as_definitions.h"

extern CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)
  tpl_app_table[APP_COUNT];

static CONST(tpl_generic_id, AUTOMATIC) tpl_obj_count_table[5] = {
  TASK_COUNT+ISR_COUNT,
  ALARM_COUNT,
  RESOURCE_COUNT,
  COUNTER_COUNT,
  SCHEDTABLE_COUNT
};

/**
 *  Get the application ID to which the current process belongs to
 *
 *  @retval   the application ID (OS261) or INVALID_OSAPPLICATION (OS262)
 */
FUNC(tpl_app_id, OS_CODE) tpl_get_application_id_service(void)
{
  return tpl_running_app_id;
}

/**
 *  Get the application ID to which the object belongs to
 *
 *  @param    obj_type  the type of object. @see #ObjectTypeType
 *  @param    obj_id    the id of the object. @see #tpl_generic_id
 *
 *  @retval   the application ID (OS273) or INVALID_OSAPPLICATION (OS274, OS319)
 */
FUNC(tpl_app_id, OS_CODE) tpl_check_object_ownership_service(
  u8              obj_type,
  tpl_generic_id  obj_id)
{
  VAR(tpl_app_id, AUTOMATIC) result = INVALID_OSAPPLICATION;
  
  switch (obj_type) {
      
    case OBJECT_TASK: /*  Same as OBJECT_ISR  */
#if !defined(NO_TASK) && !defined(NO_ISR)
      if (obj_id < (TASK_COUNT+ISR_COUNT))
      {
        result = tpl_stat_proc_table[obj_id]->app_id;
      }
#endif
      break;
      
    case OBJECT_ALARM:
#ifndef NO_ALARM
      if (obj_id < ALARM_COUNT)
      {
        P2CONST(tpl_time_obj_static, AUTOMATIC, OS_CONST) alr =
          tpl_alarm_table[obj_id]->stat_part;
        result = alr->app_id;
      }
#endif
      break;
      
    case OBJECT_RESOURCE:
#ifndef NO_RESOURCE
      /* RES_SCHEDULER id is equal to RESOURCE_COUNT - 1  */
      if (obj_id < (RESOURCE_COUNT - 1))
      {
        result = tpl_resource_table[obj_id]->app_id;
      }
#endif
      break;
      
    case OBJECT_COUNTER:
#ifndef NO_COUNTER
      if (obj_id < COUNTER_COUNT)
      {
        result = tpl_counter_table[obj_id]->app_id;
      }
#endif
      break;
      
    case OBJECT_SCHEDULETABLE:
#ifndef NO_SCHEDTABLE
      if (obj_id < SCHEDTABLE_COUNT)
      {
        P2CONST(tpl_time_obj_static, AUTOMATIC, OS_CONST) st =
          tpl_schedtable_table[obj_id]->b_desc.stat_part;
        result = st->app_id;
      }
#endif      
      break;
      
    default:
      result = INVALID_OSAPPLICATION;
      
  }
  
  return result;
}

/**
 *  Check an Application may access an object
 *
 *  @param    app_id    the id of the application
 *  @param    obj_type  the type of object. @see #ObjectTypeType
 *  @param    obj_id    the id of the object. @see #tpl_generic_id
 *
 *  @retval   ACCESS (OS271)    if the application has access to the object
 *                              or if the object is Res_scheduler 
 *  @retval   NO_ACCESS (OS272) if the application has no access to the object
 *                              or one of the parameters is invalid
 */
FUNC(u8, OS_CODE) tpl_check_object_access_service(
  tpl_app_id      app_id, 
  u8              obj_type,
  tpl_generic_id  obj_id)
{
  VAR(u8, AUTOMATIC) result = NO_ACCESS;

  if ((app_id < APP_COUNT) &&
      (obj_type < OBJECT_TYPE_COUNT) &&
      (obj_id < tpl_obj_count_table[obj_type]))
  {
    /*  Get the access vector of the corresponding application  */
    CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST) app_access =
      tpl_app_table[app_id];
    CONST(u8, AUTOMATIC) bit_shift = ((obj_id << 1) & 0x7);
    CONST(u8, AUTOMATIC) byte_idx = obj_id >> 2;
    
    result = ((app_access->access_vec[obj_type][byte_idx]) &
                    (1 << bit_shift)) >> bit_shift;
  }
  
  return result;
}

/**
 *  Terminate an OS Application. All running processes/alarms/schedule tables
 *  are killed
 *
 *  @param    restart_opt   indicates if the OS Application should be restarted.
 *                          @see #RestartType
 *
 *  @retval   E_OK          called from allowed context (OS287).
 *  @retval   E_OS_CALLEVEL wrong context (OS288)
 *  @retval   E_OS_VALUE    invalid restart_opt (OS459)
 */
FUNC(tpl_status, OS_CODE) tpl_terminate_application_service(u8 opt)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;

  if (tpl_running_app_id < APP_COUNT)
  {
    /*  First, remove all alarms belonging
        to the OS application from the queue            */
    {
      P2CONST(tpl_alarm_id, AUTOMATIC, OS_APPL_CONST) alarms =
        tpl_app_table[tpl_running_app_id]->alarms;
      CONST(tpl_alarm_id, AUTOMATIC) alarm_count =
        tpl_app_table[tpl_running_app_id]->alarm_count;
      VAR(tpl_alarm_id, AUTOMATIC) i;
      for (i = 0; i < alarm_count; i++)
      {
        CONST(tpl_alarm_id, AUTOMATIC) alarm_id = alarms[i];
        P2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) alarm =
          tpl_alarm_table[alarm_id];
        if (alarm->state == ALARM_ACTIVE)
        {
          tpl_remove_time_obj(alarm);
          alarm->state = ALARM_SLEEP;
        }
      }
    }
    /*  Then remove all the schedule tables belonging
        to the OS application from the queue            */
    {
      P2CONST(tpl_schedtable_id, AUTOMATIC, OS_APPL_CONST) schedtables =
        tpl_app_table[tpl_running_app_id]->sts;
      CONST(tpl_schedtable_id, AUTOMATIC) schedtable_count =
        tpl_app_table[tpl_running_app_id]->st_count;
      VAR(tpl_schedtable_id, AUTOMATIC) i;
      for (i = 0; i < schedtable_count; i++)
      {
        CONST(tpl_schedtable_id, AUTOMATIC) schedtable_id = schedtables[i];
        P2VAR(tpl_schedule_table, AUTOMATIC, OS_APPL_DATA) schedtable =
          tpl_schedtable_table[schedtable_id];
        if (schedtable->b_desc.state != SCHEDULETABLE_STOPPED)
        {
          tpl_remove_time_obj(&(schedtable->b_desc));
          schedtable->b_desc.state = SCHEDULETABLE_STOPPED;
          schedtable->index = 0;
        }
      }
    }
    /*  Then remove all processes belonging to the OS
        application in the ready list and in the waiting
        state (the running process called this service)   */
    {
      P2CONST(tpl_proc_id, AUTOMATIC, OS_APPL_CONST) procs =
        tpl_app_table[tpl_running_app_id]->procs;
      CONST(tpl_proc_id, AUTOMATIC) proc_count =
        tpl_app_table[tpl_running_app_id]->proc_count;
      VAR(tpl_proc_id, AUTOMATIC) i;
      for (i = 0; i < proc_count; i++)
      {
        CONST(tpl_proc_id, AUTOMATIC) proc_id = procs[i];
        /*  remove the process from the ready queue       */
        tpl_remove_proc(proc_id);
        /*  release the resources, both external
            and internal, that could be held              */
        tpl_release_all_resources(proc_id);
        tpl_release_internal_resource(proc_id);
        /*  reset the task descriptor                     */
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
        tpl_stop_budget_monitor(proc_id);
        tpl_stop_all_resource_monitor(proc_id);
        tpl_dyn_proc_table[proc_id]->activation_allowed = TRUE;
#endif
        tpl_dyn_proc_table[proc_id]->state = SUSPENDED;
        tpl_dyn_proc_table[proc_id]->activate_count = 0;
        tpl_dyn_proc_table[proc_id]->priority =
          tpl_stat_proc_table[proc_id]->base_priority;
      }
    }
  }
  else
  {
    result = E_OS_CALLEVEL;
  }
  return result;
}


/*  End of file tpl_as_app_kernel.c  */
