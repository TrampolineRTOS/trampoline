/**
 *  @file tpl_as_app_kernel.h
 *  
 *  @section desc File description
 *
 *  Header of Autosar OS Application Kernel
 *
 *  @section copyright Copyright
 *
 *  Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2007
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007
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

#ifndef TPL_AS_APP_KERNEL_H
#define TPL_AS_APP_KERNEL_H

#include "tpl_os_internal_types.h"

/**
 *  @def INVALID_OSAPPLICATION_ID
 *
 *  No OS Application is running
 *
 *  @see  #tpl_app_id
 */
#define INVALID_OSAPPLICATION_ID   APP_COUNT

/**
 * @typedef tpl_application_hook
 *
 * This type is used for application startup and shutdown hooks
 */
typedef P2FUNC(void, OS_APPL_CODE, tpl_application_hook)(void);

/**
 *  @struct TPL_APP_ACCESS
 *
 *  Data structure used to store the access vector of an OS Application
 *  each element of the access vector table is a pointer to an array
 *  that store a bit vector where each bit flags the ownership of access
 *  right of the OS Application
 *  access_vec[0] is the ownership/right for processes (tasks and ISRs)
 *  access_vec[1] is the ownership/right for alarms
 *  access_vec[2] is the ownership/right for resources
 *  access_vec[3] is the ownership/right for counters
 *  access_vec[4] is the ownership/right for schedule tables
 */
struct TPL_APP_ACCESS {
  CONST(tpl_application_hook, TYPEDEF)                    startup_hook;
  CONST(tpl_application_hook, TYPEDEF)                    shutdown_hook;
  CONSTP2CONST(u8, TYPEDEF, OS_APPL_CONST)                access_vec[5];
  CONSTP2CONST(tpl_proc_id, TYPEDEF, OS_APPL_CONST)       procs;
  CONSTP2CONST(tpl_alarm_id, TYPEDEF, OS_APPL_CONST)      alarms;
  CONSTP2CONST(tpl_resource_id, TYPEDEF, OS_APPL_CONST)   rezs;
  CONSTP2CONST(tpl_schedtable_id, TYPEDEF, OS_APPL_CONST) sts;
  CONSTP2CONST(tpl_counter_id, TYPEDEF, OS_APPL_CONST)    cnts;
  CONST(tpl_proc_id, TYPEDEF)                             proc_count;
  CONST(tpl_alarm_id, TYPEDEF)                            alarm_count;
  CONST(tpl_resource_id, TYPEDEF)                         rez_count;
  CONST(tpl_schedtable_id, TYPEDEF)                       st_count;
  CONST(tpl_counter_id, TYPEDEF)                          cnt_count;
  CONST(tpl_proc_id, TYPEDEF)                             restart;
};

/**
 *  @typedef  tpl_app_access
 *
 *  alias
 *  @see  #TPL_APP_ACCESS
 */
typedef struct TPL_APP_ACCESS tpl_app_access;

/**
 *  Get the application ID to which the current process belongs to
 *
 *  @retval   the application ID (OS261) or INVALID_OSAPPLICATION (OS262)
 */
FUNC(tpl_app_id, OS_CODE) tpl_get_application_id_service(void);

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
  tpl_generic_id  obj_id);

/**
 *  Check an Application may access an object
 *
 *  @param    app_id    the id of the application
 *  @param    obj_type  the type of object. @see #ObjectTypeType
 *  @param    obj_id    the id of the object. @see #tpl_generic_id
 *
 *  @retval   the application ID (OS273) or INVALID_OSAPPLICATION (OS274, OS319)
 */
FUNC(u8, OS_CODE) tpl_check_object_access_service(
  tpl_app_id      app_id, 
  u8              obj_type,
  tpl_generic_id  obj_id);

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
FUNC(tpl_status, OS_CODE) tpl_terminate_application_service(u8 opt);

/**
 *  Calls the StartupHook of all OS Applications
 *
 */
FUNC(void, OS_CODE) tpl_osapp_startup_hooks(void);

/**
 *  Calls the ShutdownHook of all OS Applications
 *
 */
FUNC(void, OS_CODE) tpl_call_application_shutdownhooks(void);

/*  TPL_AS_APP_KERNEL_H  */
#endif
/*  End of file tpl_as_app_kernel.h  */
