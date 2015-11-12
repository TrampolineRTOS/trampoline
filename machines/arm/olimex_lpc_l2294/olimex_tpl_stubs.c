/**
 * @file olimex_tpl_stubs.c
 *
 * @section descr File description
 *
 * SIMTEC platform specific routines and variables
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
#include "tpl_machine.h"
#include "tpl_machine_arm.h"
#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"
#include "init.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

void tpl_init_machine()
{
    tpl_init_machine_generic ();
}

void tpl_shutdown ()
{
    /* FIXME: this is does not conform to AUTOSAR OS specifications, 
     * should return to main with initial context */
    DISABLE_FIQ ();
    DISABLE_IRQ ();
    
    /* TODO : fall into very low consumption mode : all
     * internal CPU clocks are disabled.
     */
    
    while (1);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file olimex_tpl_stubs.c */
