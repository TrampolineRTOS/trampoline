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

static inline uint32 cp15_read_irq_id(void)
{
    uint32 irq_id;
    __asm__ volatile
    (
        "mrc p15, 0, %[result], c12, c8, 0;"
        :[result] "=r" (irq_id)::"memory"
    );

    return irq_id;
}


void tpl_arm_subarch_irq_handler ()
{
  VAR(uint32, AUTOMATIC) isr_id_dec;
  VAR(tpl_it_handler, AUTOMATIC) isr_vector;

  /*
   * get interrupt id
   */
  isr_id_dec = cp15_read_irq_id();

  /* launch interrupt fonction */
  isr_vector = tpl_it_vector[isr_id_dec].func;
  isr_vector(tpl_it_vector[isr_id_dec].args);
}
