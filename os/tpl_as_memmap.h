/**
 * @file tpl_as_memmap.h
 *
 * @section desc File description
 *
 * Trampoline wrapper to memory mapping platform specific header
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c)
 * CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date:$
 * $Rev:$
 * $Author:$
 * $URL:$
 */

#include "tpl_app_define.h"

#if WITH_MEMMAP != YES && WITH_MEMMAP != NO
  #error "Wrong configuration of the OS, WITH_MEMMAP should be YES or NO"
#endif

#if WITH_MEMMAP == YES
  #include "AsMemMap.h"
#endif

/* End of file tpl_as_memmap.h */
