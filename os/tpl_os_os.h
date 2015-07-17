/**
 * @file tpl_os_os.h
 *
 * @section descr File description
 *
 * Trampoline OS types definitions and StartOS prototype.
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

#ifndef TPL_OS_OS_H
#define TPL_OS_OS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "tpl_app_custom_types.h"
#include "tpl_os_internal_types.h"

/**
 * @typedef StatusType
 *
 * Status information for many services. Values names are usually prefixed by
 * E_OS_*. Each API service provides more informations about error codes.
 *
 * See paragraph 13.1, page 48 of OSEK/VDX 2.2.2 spec
 */
#ifndef STATUSTYPE_DEFINED
#define STATUSTYPE_DEFINED
typedef tpl_status      StatusType;
#endif

/**
 * @typedef AppModeType
 *
 * Application execution mode
 *
 * see paragraph 13.7.1 page 66 of OSEK/VDX 2.2.2 spec
 */
typedef tpl_application_mode AppModeType;

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Declaration of the OSDEFAULTAPPMODE constant
 */
extern CONST(tpl_application_mode, OS_CONST) OSDEFAULTAPPMODE;

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*
 * System services
 * see paragraph 13.7.2,
 * pages 66+ of OSEK/VDX 2.2.2 spec
 */

/**
 * Declare an application mode
 *
 * This macro declares an application mode exists.
 *
 * @param appmode_id the application mode identifier
 *                   (provide a C identifier here)
 */
#define DeclareApplicationMode(appmode_id) \
  extern CONST(AppModeType, OS_CONST) appmode_id

/**
 * Starts Trampoline
 *
 * @param mode chosen application mode
 *
 * see paragraph 13.7.2.2 page 66 of OSEK/VDX 2.2.2 spec
 */
extern FUNC(void, OS_CODE) StartOS(
  CONST(AppModeType, AUTOMATIC) mode);

#ifdef __cplusplus
}
#endif

/* TPL_OS_OS_H */
#endif

/* End of file tpl_os_os.h */
