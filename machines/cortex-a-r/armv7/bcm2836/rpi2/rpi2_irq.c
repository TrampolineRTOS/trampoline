/**
 * @file olimex_irq.c
 *
 * @section descr File description
 *
 * OLIMEX platform specific routines and variables
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
#include "tpl_os_interrupt_kernel.h" //tpl_it_handler
#include "bcm2836.h"
#include "bcm2836_core.h"
#include "rpi2_uart.h"
#include "emblib.h"
#include "rpi2_trace.h"

extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[31];

void tpl_arm_subarch_irq_handler ()
{
  VAR(uint32, AUTOMATIC) isr_id_dec = 0;
  volatile VAR(uint32, AUTOMATIC) leading_zeros = 0;

  VAR(tpl_it_handler, AUTOMATIC) isr_vector;

  /* get interrupt id
   *
   * __CLZ counts the leading zero's in a value
   * ! BEWARE !
   * Following switch case is not finalized.
   * It shall be correct for interrupts raised from:
   * - ARM Timer
   * - Pending register 1
   * - Pending register 2
   * It must be completed for other intterupts sources.
   */
  leading_zeros = (uint32)31 - (uint32)__CLZ(readFromReg(IRQ_BASIC));
  switch (leading_zeros) {
    case 8:
      isr_id_dec = (uint32)31 - (uint32)__CLZ(readFromReg(IRQ_PEND1));
    break;
    case 9:
      isr_id_dec = (uint32)31 - (uint32)__CLZ(readFromReg(IRQ_PEND2));
    break;
    default:
      isr_id_dec = leading_zeros;
    break;
  }

  // trace_a_reg((const unsigned char*)"IRQ_BASIC", readFromReg(IRQ_BASIC));
  // trace_a_reg((const unsigned char*)"IRQ_PEND1", readFromReg(IRQ_PEND1));
  // trace_a_reg((const unsigned char*)"IRQ_PEND2", readFromReg(IRQ_PEND2));
  // trace_it(leading_zeros, isr_id_dec);
  /* launch interrupt fonction (ISR2, timer...) */
  isr_vector = tpl_it_vector[isr_id_dec].func;
  isr_vector(tpl_it_vector[isr_id_dec].args);
  // isr_vector = tpl_it_vector[0].func;
  // isr_vector(tpl_it_vector[0].args);
}

/* End of file olimex_irq.c */
