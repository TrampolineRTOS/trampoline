/**
 *  @file tpl_as_application.c
 *  
 *  @section desc File description
 *
 *  Implementation of Autosar OS Application API
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

#include "tpl_as_application.h"
#include "tpl_as_app_kernel.h"

/**
 *  Get the application ID to which the current process belongs to
 *
 *  @retval   the application ID (OS261) or INVALID_OSAPPLICATION (OS262)
 */
FUNC(ApplicationType, OS_CODE) GetApplicationID(void)
{
#ifdef WITH_SYSTEM_CALL
#else
  return tpl_get_application_id_service();
#endif
}

/**
 *  Get the application ID to which the object belongs to
 *
 *  @param    obj_type  the type of object. @see #ObjectTypeType
 *  @param    obj_id    the id of the object. @see #tpl_generic_id
 *
 *  @retval   the application ID (OS273) or INVALID_OSAPPLICATION (OS274, OS319)
 */
FUNC(ApplicationType, OS_CODE) CheckObjectOwnership(
  ObjectTypeType  obj_type,
  tpl_generic_id  obj_id)
{
#ifdef WITH_SYSTEM_CALL
#else
  return tpl_check_object_ownership_service(obj_type, obj_id);
#endif  
}

/**
 *  Check an Application may access an object
 *
 *  @param    app_id    the id of the application
 *  @param    obj_type  the type of object. @see #ObjectTypeType
 *  @param    obj_id    the id of the object. @see #tpl_generic_id
 *
 *  @retval   the application ID (OS273) or INVALID_OSAPPLICATION (OS274, OS319)
 */
FUNC(ObjectAccessType, OS_CODE) CheckObjectAccess(
  ApplicationType app_id, 
  ObjectTypeType  obj_type,
  tpl_generic_id  obj_id)
{
#ifdef WITH_SYSTEM_CALL
#else
  return tpl_check_object_access_service(app_id, obj_type, obj_id);
#endif
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
FUNC(StatusType, OS_CODE) TerminateApplication(RestartType restart_opt)
{
#ifdef WITH_SYSTEM_CALL
#else
  return tpl_terminate_application_service(restart_opt);
#endif
}

/*  End of file tpl_as_application.c  */
