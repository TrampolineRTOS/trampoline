/**
 * @file tpl_memmap.h
 *
 * @section desc File description
 *
 * Trampoline wrapper to memory mapping platform specific header
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
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

#include "tpl_app_define.h"

#if WITH_MEMMAP != YES && WITH_MEMMAP != NO
  #error "Wrong configuration of the OS, WITH_MEMMAP should be YES or NO"
#endif

#if WITH_MEMMAP == YES
  #include "MemMap.h"
#endif

/* End of file tpl_memmap.h */
