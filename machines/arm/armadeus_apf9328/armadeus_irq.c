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

//64 interrupt sources in apf9328
extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[64]; 

#define NIVECSR (unsigned int *)0x00223040

void tpl_arm_subarch_irq_handler ()
{
	VAR(tpl_it_handler, AUTOMATIC) isr_vector;
	VAR(u32, AUTOMATIC) source;
	
	/* get interrupt id */
	source =  (*NIVECSR) >>16;

	/* launch interrupt fonction (ISR2, timer...) */
	isr_vector = tpl_it_vector[source].func;
	isr_vector(tpl_it_vector[source].args);
}

/* End of file armadeus_irq.c */
