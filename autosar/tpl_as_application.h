/**
 *  @file tpl_as_application.h
 *  
 *  @section desc File description
 *
 *  Header of Autosar OS Application API
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

#ifndef TPL_AS_APPLICATION_H
#define TPL_AS_APPLICATION_H

#include "tpl_os_custom_types.h"
#include "tpl_os_types.h"

/**
 *  @typedef  ObjectTypeType
 *
 *  type of object. It can be one of the following
 *
 *  @see  #OBJECT_TASK
 *  @see  #OBJECT_ISR
 *  @see  #OBJECT_ALARM
 *  @see  #OBJECT_RESOURCE
 *  @see  #OBJECT_COUNTER
 *  @see  #OBJECT_SCHEDULETABLE 
 */
typedef uint8  ObjectTypeType;

/**
 *  @typedef  ApplicationType
 *
 *  Id of an OS Application
 */
typedef tpl_app_id  ApplicationType;

/**
 *  @typedef ObjectAccessType
 *
 *  Return type used by CheckObjectAccess. @see #CheckObjectAccess
 */
typedef uint8  ObjectAccessType;

/**
 *  @typedef RestartType
 *
 *  Type used to specifies how TerminateApplication should behave
 */
typedef uint8  RestartType;

/**
 *  @typedef ObjectType
 *
 *  Type used as a generic identifier of objects
 */
typedef tpl_generic_id ObjectType;

/**
 *  @typedef ApplicationStateType
 *  
 *  Type used to identify the state of an OsApplication
 */
typedef uint8 ApplicationStateType;

/**
 *  @typedef ApplicationStateRefType
 *  
 *  Type used to return an ApplicationStateType
 */
typedef P2VAR(uint8, TYPEDEF, OS_VAR) ApplicationStateRefType;

/**
 * @def DeclareApplication
 *
 * Defines an application
 *
 * @param app_id application's C identifier
 *
 */
#define DeclareApplication(app_id)  \
	extern CONST(ApplicationType, OS_APPL_CONST) app_id

/*  TPL_AS_APPLICATION_H  */
#endif
/*  End of file tpl_as_application.h  */
