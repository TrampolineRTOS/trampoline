/**
 * @file tpl_os_types.h
 *
 * @section descr File description
 *
 * Trampoline general types definitions. This file is included
 * by the communication library
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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

#ifndef __TPL_OS_TYPES_H__
#define __TPL_OS_TYPES_H__

/**
 * @typedef bool
 *
 * Standard bool declaration. Values can be #TRUE or #FALSE.
 */
typedef unsigned char bool;

/**
 * @typedef tpl_status
 *
 * This type is used for return
 * status of services (ie one of the result
 * codes specified below). 
 *
 * It is binary compatible with OSEK StatusType, provided
 * Trampoline specific codes are removed (via #OSEK_STATUS_MASK
 * AND-mask). 
 *
 * @see #OSEK_STATUS_MASK
 * @see #StatusType
 */
typedef unsigned char tpl_status;

/**
 * @typedef tpl_callback_func
 *
 * This type is used for various
 * callback function type in Trampoline.
 */
typedef void (*tpl_callback_func)(void);

#endif
