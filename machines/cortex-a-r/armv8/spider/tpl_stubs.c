/**
 * @file tpl_stubs.c
 *
 * @section descr File description
 *
 * Spider platform specific routines and variables
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

#include "emblib.h"
extern unsigned int GETISR ( void );

// #include "init.h"
extern void enable_irq ( void );

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern uint32 vectors;

FUNC(void, OS_CODE) tpl_init_machine(void)
{
    cp15_write32(0, 12, 0, 0, &vectors);  // write VBAR

    tpl_init_machine_generic ();

    //enable_irq();
}

FUNC(void, OS_CODE) tpl_shutdown(void)
{
    /* FIXME: this is does not conform to AUTOSAR OS specifications,
     * should return to main with initial context */
    DISABLE_FIQ ();
    DISABLE_IRQ ();

    while (1);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
