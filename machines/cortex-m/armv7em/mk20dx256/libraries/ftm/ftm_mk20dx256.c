/**
 * @file ftm_mk20dx256.c
 *
 * @section descr File description
 *
 * mk20dx256 fonctions to acknowledge the interrupt
 * flag of the FTM: FlexTimer Module
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

#include "ftm_mk20dx256.h"

/*
 * Acknowledge FTM0 interrupt
 */
FUNC(void, OS_CODE) FTM0_IRQ_ClearFlag()
{
  FTMAcknowledgeTimerInterrupt(0);
}

/*
 * Acknowledge FTM1 interrupt
 */
FUNC(void, OS_CODE) FTM1_IRQ_ClearFlag()
{
  FTMAcknowledgeTimerInterrupt(1);
}

/*
 * Acknowledge FTM2 interrupt
 */
FUNC(void, OS_CODE) FTM2_IRQ_ClearFlag()
{
  FTMAcknowledgeTimerInterrupt(2);
}

/* End of file ftm_mk20dx256.c */
