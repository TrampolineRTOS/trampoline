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
 * This software is distributed under the Lesser GNU Public Licence
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
 *  @def APPLICATION_ACCESSIBLE
 *
 *  OS Application objects are accessible
 *
 *  @see  #tpl_app_state
 */
#define APPLICATION_ACCESSIBLE  0

/**
 *  @def APPLICATION_RESTARTING
 *
 *  OS Application is restarting and its objects are not accessible
 *
 *  @see  #tpl_app_state
 */
#define APPLICATION_RESTARTING  1

/**
 *  @def APPLICATION_TERMINATED
 *
 *  OS Application is terminated and will not restart. Its objects are not accessible
 *
 *  @see  #tpl_app_state
 */
#define APPLICATION_TERMINATED  2

/**
 * @typedef tpl_app_state
 *
 * This type is used for application state
 *
 * @see #APPLICATION_ACCESSIBLE
 * @see #APPLICATION_RESTARTING
 * @see #APPLICATION_TERMINATED
 */
typedef uint8 tpl_app_state;


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
 *  access_vec[3] is the ownership/right for schedule tables
 *  access_vec[4] is the ownership/right for counters
 *  access_vec[5] is the ownership/right for iocs receivers
 *  access_vec[6] is the ownership/right for iocs senders
 *  access_vec[7] is the ownership/right for spinlocks
 */
struct TPL_APP_ACCESS {
  CONST(tpl_application_hook, TYPEDEF)                    startup_hook;
  CONST(tpl_application_hook, TYPEDEF)                    shutdown_hook;
  CONSTP2CONST(uint8, TYPEDEF, OS_CONST)                  access_vec[8];
  CONSTP2CONST(tpl_proc_id, TYPEDEF, OS_CONST)            procs;
  CONSTP2CONST(tpl_alarm_id, TYPEDEF, OS_CONST)           alarms;
  CONSTP2CONST(tpl_resource_id, TYPEDEF, OS_CONST)        rezs;
  CONSTP2CONST(tpl_schedtable_id, TYPEDEF, OS_CONST)      sts;
  CONSTP2CONST(tpl_counter_id, TYPEDEF, OS_CONST)         cnts;
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
 *  @struct TPL_APP_DYN
 *
 *  Data structure used to store dynamic fields of an OsApplication
 */
struct TPL_APP_DYN {
  VAR(tpl_app_state, TYPEDEF)                             state;
};


/**
 *  @typedef  tpl_app_access
 *
 *  alias
 *  @see  #TPL_APP_ACCESS
 */
typedef struct TPL_APP_DYN tpl_app_dyn;


#if APP_COUNT > 0
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
extern CONSTP2CONST(tpl_app_access, OS_CONST, OS_CONST) tpl_app_table[APP_COUNT];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

# if NUMBER_OF_CORES > 1
# define OS_START_SEC_CONST_UNSPECIFIED
# include "tpl_memmap.h"
extern CONST(tpl_core_id, OS_CONST) tpl_core_id_for_app[APP_COUNT];
# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "tpl_memmap.h"
# endif

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
extern VAR(tpl_app_dyn, OS_VAR) tpl_app_dyn_table[APP_COUNT];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
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
  uint8              obj_type,
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
FUNC(uint8, OS_CODE) tpl_check_object_access_service(
  tpl_app_id      app_id,
  uint8              obj_type,
  tpl_generic_id  obj_id);

/**
 *  Terminate an OS Application. All running processes/alarms/schedule tables
 *  are killed
 *
 *  @param    app_id        the id of the application
 *  @param    restart_opt   indicates if the OS Application should be restarted.
 *                          @see #RestartType
 *
 *  @retval   E_OK          called from allowed context (OS287).
 *  @retval   E_OS_CALLEVEL wrong context (OS288)
 *  @retval   E_OS_VALUE    invalid restart_opt (OS459)
 */
FUNC(tpl_status, OS_CODE) tpl_terminate_application_service(
  tpl_app_id app_id,
  uint8 opt);

/**
 *  Allow other OsApplication to access an OsApplication after restarting
 *
 *  @retval   E_OK
 *  @retval   E_OS_STATE called from an OsApplication which state is not APPLICATION_RESTARTING
 */
FUNC(tpl_status, OS_CODE) tpl_allow_access_service(void);

/**
 *  Allow other OsApplication to access an OsApplication after restarting
 *
 *  @retval   E_OK
 *  @retval   E_OS_STATE called from an OsApplication which state is not APPLICATION_RESTARTING
 */
FUNC(tpl_status, OS_CODE) tpl_get_application_state_service(
  VAR(tpl_app_id, AUTOMATIC) app_id,
  P2VAR(tpl_app_state, AUTOMATIC, OS_VAR) app_state);

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


/*
 * Starts all OsApplications
 */
FUNC(void, OS_CODE) tpl_start_apps(void);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/*  TPL_AS_APP_KERNEL_H  */
#endif
/*  End of file tpl_as_app_kernel.h  */
