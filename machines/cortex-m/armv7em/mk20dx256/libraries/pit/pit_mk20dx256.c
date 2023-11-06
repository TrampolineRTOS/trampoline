/**
 * @file pit_mk20dx256.c
 *
 * @section descr File description
 *
 * mk20dx256 fonctions to acknowledge the interrupt flag
 *
 * @section copyright Copyright
 *
 * Trampoline OS
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
 */

#include "pit_mk20dx256.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) PIT0_IRQ_ClearFlag()
{
  PITAcknowledgeTimerInterrupt(0);
}

FUNC(void, OS_CODE) PIT1_IRQ_ClearFlag()
{
  PITAcknowledgeTimerInterrupt(1);
}

FUNC(void, OS_CODE) PIT2_IRQ_ClearFlag()
{
  PITAcknowledgeTimerInterrupt(2);
}

FUNC(void, OS_CODE) PIT3_IRQ_ClearFlag()
{
  PITAcknowledgeTimerInterrupt(3);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file pit_mk20dx256.c */
