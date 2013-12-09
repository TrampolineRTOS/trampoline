/**
 * @file tpl_os_multicore.h
 *
 * @section descr File description
 *
 * Trampoline multicore types.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2013
 * Part of Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
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

#include "tpl_os_std_types.h"

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
