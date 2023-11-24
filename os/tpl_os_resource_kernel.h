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

#ifndef TPL_OS_REZ_KERNEL_H
#define TPL_OS_REZ_KERNEL_H

#include "tpl_os_internal_types.h"

#if WITH_OSAPPLICATION == YES
#include "tpl_as_app_kernel.h"
#endif /* WITH_OSAPPLICATION */

/**
 * @struct TPL_RESOURCE
 *
 * This structure describes all attributes of a resource
 */
struct TPL_RESOURCE
{
  CONST(tpl_priority, TYPEDEF)
  ceiling_priority; /**<  Ceiling priority as computed at system
                          generation time.                            */
  VAR(tpl_priority, TYPEDEF)
  owner_prev_priority; /**<  Priority of the owner before accessing to
                             the resource. This field is used to restore
                             the priority of the task when the resource
                             is released                                 */
  VAR(tpl_proc_id, TYPEDEF)
  owner; /**<  Id of the owner of the resource or -1
               if the resource is not owned                */
#if RESOURCE_BELONGS_TO_OS_APP == YES
  CONST(tpl_app_id, TYPEDEF)
  app_id; /**<  Id of the OS Application which owns the
                resource.                                   */
#endif
#if WITH_ID == YES
  CONST(tpl_resource_id, TYPEDEF)
  res_id; /**< Index of the resource in the resource table */
#endif
  struct P2VAR(TPL_RESOURCE, TYPEDEF,
               OS_APPL_DATA) next_res; /**< Pointer to the next resource used to
                                          link them together when a task get
                                          more than one resource */
};

/**
 * @typedef tpl_resource
 *
 * This type is an alias for the structure #TPL_RESOURCE.
 *
 * @see #TPL_RESOURCE
 */
typedef struct TPL_RESOURCE tpl_resource;

#if RESOURCE_COUNT > 0
#if NUMBER_OF_CORES == 1
/**
 * Array of all resources descriptors
 *
 * Index in this array correspond to the #ResourceType of the resource
 */
extern CONSTP2VAR(tpl_resource, AUTOMATIC,
                  OS_APPL_DATA) tpl_resource_table[RESOURCE_COUNT];
#define TPL_RESOURCE_TABLE(a_core_id) tpl_resource_table
#else
/**
 * Array of all resources descriptors
 *
 * In multicore, tpl_ressource_table is an array indexed by a core id
 * containing the addresses of the core's tpl_ressource_table.
 */
extern CONSTP2CONST(tpl_resource *, AUTOMATIC,
                    OS_CONST) tpl_resource_table[NUMBER_OF_CORES];
#define TPL_RESOURCE_TABLE(a_core_id) (tpl_resource_table[a_core_id])
#endif

#endif /* RESOURCE_COUNT */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * Release all resources of a process (Task/ISR2)
 *
 * @param proc_id process's id
 */
FUNC(void, OS_CODE)
tpl_release_all_resources(CONST(tpl_proc_id, AUTOMATIC) proc_id);

/**
 * Getting a resource.
 *
 * see #GetResource
 */
FUNC(tpl_status, OS_CODE)
tpl_get_resource_service(CONST(tpl_resource_id, AUTOMATIC) res_id);

/**
 * Releasing a resource
 *
 * see #ReleaseResource
 */
FUNC(tpl_status, OS_CODE)
tpl_release_resource_service(CONST(tpl_resource_id, AUTOMATIC) res);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* tpl_os_rez_kernel.h */

/* End of file tpl_os_rez_kernel.h */
