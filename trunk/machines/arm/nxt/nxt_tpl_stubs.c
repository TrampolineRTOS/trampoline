/**
 * @file nxt_tpl_stubs.c
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
#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"
#include "ecrobot_interface.h"

extern void tpl_init_machine_generic (void);

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

void tpl_init_machine(void)
{
    nxt_device_init();
    tpl_init_machine_generic();
    InitButtons();
	ecrobot_set_motor_rev(NXT_PORT_A, 0);
	ecrobot_set_motor_rev(NXT_PORT_B, 0);
	ecrobot_set_motor_rev(NXT_PORT_C, 0);
}

void tpl_shutdown(void)
{
    /* Enable interrupts because disabled bu ShutdownOS and we
     need them to shutdown the NXT */
    ENABLE_FIQ();
    ENABLE_IRQ();
    
    ecrobot_term_bt_connection(); /* shutdown bluetooth connection */
    display_clear(1);
    systick_wait_ms(10);
    nxt_lcd_power_down(); /* reset LCD hardware */
    systick_wait_ms(10);
    while(1)
    {
        nxt_avr_power_down();
    }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file nxt_tpl_stubs.c */
