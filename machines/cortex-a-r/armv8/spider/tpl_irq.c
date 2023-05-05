/**
 * @section descr File description
 *
 * Spider platform irq handling
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
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

#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h"
#include "emblib.h"

extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[31];


void tpl_arm_subarch_irq_handler ()
{
  VAR(uint32, AUTOMATIC) isr_id_dec;
  VAR(tpl_it_handler, AUTOMATIC) isr_vector;

  /*
   * Get group0 interrupt id
   * Use 'cp15_read32(0, 12, 8, 0, isr_id_dec);' for group1
   */
   cp15_read32(0, 12, 12, 0, isr_id_dec);

  /*
   * Launch interrupt function
   */
  isr_vector = tpl_it_vector[isr_id_dec].func;
  isr_vector(tpl_it_vector[isr_id_dec].args);

  /*
   * Clear interrupt
   */
  cp15_write32(0, 12, 12, 1, isr_id_dec);
}
