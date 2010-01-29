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

#include "tpl_os_kernel.h"
#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#endif /* WITH_AUTOSAR */

void tpl_arm_subarch_irq_handler ()
{
    /* TODO */ 
     
    /* acknoledge interrupt
    */
}

/* End of file olimex_irq.c */
