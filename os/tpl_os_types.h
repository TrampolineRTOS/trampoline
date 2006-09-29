/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline general types definitions. This file is included
 * by the communication library
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_OS_TYPES_H__
#define __TPL_OS_TYPES_H__

/*
 * standard bool declaration
 */
typedef unsigned char bool;

/*
 * tpl_status_type is used for return
 * status of services (ie one of the result
 * codes specified below).
 */
typedef unsigned char tpl_status;

/*
 * tpl_callback_func is used for various
 * callback function type in the os
 */
typedef void (*tpl_callback_func)(void);

#endif
