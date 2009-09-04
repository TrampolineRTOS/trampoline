/**
 * @file tpl_os_rez_kernel.h
 *
 * @section desc File description
 *
 * This header file provides internal function
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

#ifndef TPL_OS_REZ_KERNEL_H
#define TPL_OS_REZ_KERNEL_H

#include "tpl_os_internal_types.h"

#ifdef WITH_OSAPPLICATION
#include "tpl_as_app_kernel.h"
#endif /* WITH_OSAPPLICATION */

/**
 * @struct TPL_RESOURCE
 *
 * This structure describes all attributes of a resource
 */
struct TPL_RESOURCE {
  CONST(tpl_priority, TYPEDEF)
    ceiling_priority;       /**<  Ceiling priority as computed at system
                                  generation time.                            */
  VAR(tpl_priority, TYPEDEF)
    owner_prev_priority;    /**<  Priority of the owner before accessing to
                                  the resource. This field is used to restore
                                  the priority of the task when the resource
                                  is released                                 */
  VAR(tpl_proc_id, TYPEDEF)
    owner;                  /**<  Id of the owner of the resource or -1
                                  if the resource is not owned                */
#ifdef WITH_OSAPPLICATION
  CONST(tpl_app_id, TYPEDEF)
    app_id;                 /**<  Id of the OS Application which owns the
                                  resource.                                   */
#endif    
  struct P2VAR(TPL_RESOURCE, TYPEDEF, OS_APPL_DATA)
    next_res;               /**< Pointer to the next resource used to link
                                 them together when a task get more than one
                                 resource                                     */
};

/**
 * @typedef tpl_resource
 *
 * This type is an alias for the structure #TPL_RESOURCE.
 *
 * @see #TPL_RESOURCE
 */
typedef struct TPL_RESOURCE tpl_resource;

#ifndef NO_RESOURCE
/**
 * Array of all resources descriptors
 *
 * Index in this array correspond to the #ResourceType of the resource
 */
extern CONSTP2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA)
  tpl_resource_table[RESOURCE_COUNT];
#endif

/**
 * The scheduler resource descriptor
 *
 * @see #RES_SCHEDULER
 */
extern VAR(tpl_resource, OS_VAR) res_sched_rez_desc;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#ifdef WITH_AUTOSAR
FUNC(void, OS_CODE) tpl_release_all_resources(
  CONST(tpl_proc_id, AUTOMATIC) proc_id);
#endif

/*
 * Getting a resource.
 */
FUNC(tpl_status, OS_CODE) tpl_get_resource_service(
  CONST(tpl_resource_id, AUTOMATIC) res_id);


/*
 * Releasing a resource
 */
FUNC(tpl_status, OS_CODE) tpl_release_resource_service(
  CONST(tpl_resource_id, AUTOMATIC) res);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* tpl_os_rez_kernel.h */

/* End of file tpl_os_rez_kernel.h */
