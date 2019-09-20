/**
 * @file tpl_os_custom_types.h
 *
 * @section File description
 *
 * This file gathers all data types which can be changed by user for the
 * needs of its application. Please refer to comment of each type for more
 * details.
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
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_CUSTOM_TYPES_H
#define TPL_OS_CUSTOM_TYPES_H

#include "tpl_os_application_def.h"
#include "tpl_app_custom_types.h"

/**
 * tpl_buffer is a pointer to a chunk of data in memory
 */
typedef P2VAR(uint8, TYPEDEF, OS_APPL_DATA) tpl_buffer;

/**
 * Time data (duration or date) used in timing protection. The unit is system
 * dependant (see #tpl_get_local_current_date)).
 *
 * @see #tpl_get_local_current_date
 */
typedef uint32 tpl_time;

#endif /* TPL_OS_CUSTOM_TYPES_H */

/* End of file tpl_os_custom_types.h */
