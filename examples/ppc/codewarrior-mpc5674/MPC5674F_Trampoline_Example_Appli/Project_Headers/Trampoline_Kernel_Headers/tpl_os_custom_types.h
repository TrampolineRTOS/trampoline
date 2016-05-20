/**
 * @file tpl_os_custom_types.h
 *
 * @section File description
 *
 * This file gathers all data types which can be changed by user for the
 * needs of its application. Please refer to comment of each type for more
 * details.
 *
 * @section Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section File informations
 *
 * $Date: 2013-12-09 10:59:56 -0600 (lun. 09 déc. 2013) $
 * $Rev: 1500 $
 * $Author: jlb $
 * $URL: https://trampoline.rts-software.org/svn/trunk/os/tpl_os_custom_types.h $
 */

#ifndef TPL_OS_CUSTOM_TYPES_H
#define TPL_OS_CUSTOM_TYPES_H

#include "tpl_os_application_def.h"
#include "tpl_app_custom_types.h"

/**
 * tpl_tick is used for relative and absolute dates.
 * tpl_tick should be an unsigned datatype.
 *
 * Default aliased type is "unsigned long int"
 */
typedef uint32 tpl_tick;

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
