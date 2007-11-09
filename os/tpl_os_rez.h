/**
 * @file tpl_os_rez.h
 *
 * @section desc File description
 *
 * Trampoline Resource Management header file
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

#ifndef TPL_OS_REZ_H
#define TPL_OS_REZ_H

#include "tpl_os_types.h"
#include "tpl_os_application_def.h"

#ifdef WITH_AUTOSAR
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
#define DeclareResource(resource_id)


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * System services
 * see paragraph 13.4.3,
 * pages 58+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Get the resource
 *
 * @param ResID identifier of the resource
 *
 * @retval E_OK no error
 * @retval E_OS_ID ResID is invalid
 *
 * see paragraph 13.4.3.1 page 58 of OSEK/VDX 2.2.2 spec
 */
FUNC(StatusType, OS_CODE) GetResource(
    CONST(ResourceType, AUTOMATIC) res_id);


/**
 * Releases the resource
 *
 * @param ResID identifier of the resource
 *
 * @retval E_OK no error
 * @retval (extended error only) E_OS_ID ResID is invalid
 * @retval (extended error only) E_OS_NOFUNC the resource is not occupied or
 * another resource shall be released before
 * @retval (extended error only) E_OS_ACCESS the resource has a lower ceiling
 * priority than the static priority of the caller
 *
 * see paragraph 13.4.3.2 page 59 of OSEK/VDX 2.2.2 spec
 */
FUNC(StatusType, OS_CODE) ReleaseResource(
    CONST(ResourceType, AUTOMATIC) res_id);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * This special resource is used to deny preemption.
 *
 * @note It can be used by a task but is not stored
 * in the general resource table.
 *
 * see paragraph 13.4.4 page 59 of OSEK/VDX 2.2.2 spec
 */
extern VAR(ResourceType, OS_VAR) RES_SCHEDULER;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#endif /* TPL_OS_REZ_H */

/* End of file tpl_os_rez.h */
