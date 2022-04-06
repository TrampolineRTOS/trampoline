/**
 * @file tpl_multicore_rp2040.c
 *
 * @section descr File description
 *
 * Multicore kernel functions for rp2040
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes,
 * Ecole Centrale de Nantes
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
 */

#include "hardware/structs/sio.h"

extern FUNC(int, OS_APPL_CODE) main(void)

    /**
     * @internal
     *
     * tpl_get_core_id is used to get the identifier of the core on which the
     * code is running
     */
    FUNC(uint32, OS_CODE) tpl_get_core_id()
{
  return sio_hw->cpuid;
}

/**
 * @internal
 *
 * This function starts the processing core given in the argument
 */
FUNC(void, OS_CODE) tpl_start_core(CONST(CoreIdType, AUTOMATIC) core_id)
{
  /*
   * Only CORE1 can be started because it is the only one that does not run when
   * the rp2040 starts.
   */
  if (core_id == OS_CORE_ID_1)
  {
    multicore_launch_core1_with_stack(main, tpl_core1_stack,
                                      tpl_core1_stack_size);
  }
}
