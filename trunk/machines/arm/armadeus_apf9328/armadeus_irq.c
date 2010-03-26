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
#include "tpl_os_it_kernel.h" //tpl_it_handler

extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[31];

void tpl_arm_subarch_irq_handler ()
{
       
}

/* End of file olimex_irq.c */
