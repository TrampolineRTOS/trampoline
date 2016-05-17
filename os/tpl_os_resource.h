/**
 * @file tpl_os_rez.h
 *
 * @section desc File description
 *
 * Trampoline Resource Management header file
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
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

#ifndef TPL_OS_REZ_H
#define TPL_OS_REZ_H

#include "tpl_os_types.h"
#include "tpl_os_application_def.h"

#if WITH_AUTOSAR == YES
#include "tpl_as_timing_protec.h"
#endif

/*
 * Resource Management
 * see paragraph 13.4,
 * pages 58+ of OSEK/VDX 2.2.2 spec
 */

/**
 * @typedef ResourceType
 *
 * identifies a resource
 *
 * see paragraph 13.4.1 page 58 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_resource_id ResourceType;

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
extern CONST(ResourceType, OS_CONST) RES_SCHEDULER;

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * @def DeclareResource
 *
 * Defines a resource
 *
 * @param resource_id resource's C identifier
 *
 * see "Constructional elements"
 * paragraph 13.4.2 page 58 of OSEK/VDX 2.2.2 spec
 */
#define DeclareResource(resource_id)  \
  extern CONST(ResourceType, AUTOMATIC) resource_id

#endif /* TPL_OS_REZ_H */

/* End of file tpl_os_rez.h */
