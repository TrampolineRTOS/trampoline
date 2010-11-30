/**
 * @file apf27_irq.c
 *
 * @section descr File description
 *
 * APF27 specific IRQ management
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
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */
#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_os_definitions.h"
#include "tpl_os_application_def.h"
#include "tpl_os_kernel.h"
#include "apf27_aitc.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_arm_subarch_irq_handler ()
{
#if ISR_COUNT > 0
  VAR(u32, AUTOMATIC) interrupt_source;
  VAR(tpl_it_handler, AUTOMATIC) isr_vector;

  interrupt_source = (u32)apf27_aitc_get_source_int ();
  isr_vector = tpl_it_vector[interrupt_source].func;
  isr_vector(tpl_it_vector[interrupt_source].args);
#endif /* ISR_COUNT > 0 */
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

