/**
 * @file tpl_sequence_kernel.c
 *
 * @section descr File description
 *
 * Trampoline sequence os services implementation.
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

#if WITH_SEQUENCING == YES

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_activate_sequence_os_service(void)
{
  /* init the error to no error */
  VAR(StatusType, AUTOMATIC) result = E_OK;

  PROCESS_ERROR(result)

}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif //WITH_SEQUENCING