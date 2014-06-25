/**
 * @file tpl_memory_protection.h
 *
 * @section descr File description
 *
 * Trampoline datatypes for memory protection descriptors for MPC565 MPU.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_MEMORY_PROTECTION_H
#define TPL_MEMORY_PROTECTION_H

#include "tpl_os_std_types.h"

/**
 * @typedef
 *
 * start of a memory protection region of MPC565. See section 11.8.4 of
 * the MPC565 Reference Manual (page 11-14). Actually, it takes 20 bits
 */
typedef uint32 tpl_mp_region_start;

/**
 * @typedef
 *
 * end of a memory protection region of MPC565. See section 11.8.5 of
 * the MPC565 Reference Manual (page 11-15). This is converted to a size
 * by the function that set the register of the MPU.
 */
typedef uint32 tpl_mp_region_end;

/* TPL_MEMORY_PROTECTION_H */
#endif
/* End of file tpl_memory_protection.h */
