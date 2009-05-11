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
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
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

#ifndef TPL_MEMORY_PROTECTION_H
#define TPL_MEMORY_PROTECTION_H

#include "tpl_os_std_types.h"

/**
 * @typedef
 *
 * start of a memory protection region of MPC565. See section 11.8.4 of
 * the MPC565 Reference Manual (page 11-14). Actually, it takes 20 bits
 */
typedef u32 tpl_mp_region_start;

/**
 * @typedef
 *
 * end of a memory protection region of MPC565. See section 11.8.5 of
 * the MPC565 Reference Manual (page 11-15). This is converted to a size
 * by the function that set the register of the MPU.
 */
typedef u32 tpl_mp_region_end;

/* TPL_MEMORY_PROTECTION_H */
#endif
/* End of file tpl_memory_protection.h */
