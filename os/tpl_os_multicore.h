/**
 * @file tpl_os_multicore.h
 *
 * @section descr File description
 *
 * Trampoline multicore types.
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
 *
 */

#ifndef TPL_OS_MULTICORE_H
#define TPL_OS_MULTICORE_H

#include "tpl_os_internal_types.h"

/**
 * @typedef CoreIdType
 *
 * A core identifier
 */
typedef uint16 CoreIdType;

/**
 * @typedef CoreStatusType
 *
 * The status of a core
 */
typedef uint8 CoreStatusType;

/**
 * @def STOPPED_CORE
 *
 * The stopped core status.
 */
#define STOPPED_CORE              0

/**
 * @def STARTED_CORE_AUTOSAR
 *
 * The started in AUTOSAR core status.
 */
#define STARTED_CORE_AUTOSAR      1

/**
 * @def STARTED_CORE_NON_AUTOSAR
 *
 * The started in non AUTOSAR core status.
 */
#define STARTED_CORE_NON_AUTOSAR  2

#endif
/* TPL_OS_MULTICORE_H */

/* end of file tpl_os_multicore.h */
