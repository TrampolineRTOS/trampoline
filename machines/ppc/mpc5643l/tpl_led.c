/*
 * @file tpl_led.c
 *
 * @section desc File description
 *
 * Trampoline led control functions for mpc5643l with XPC56XX motherboard
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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

#include "tpl_os_std_types.h"
#include "tpl_registers.h"
#include "Compiler.h"

#define LED_COUNT  4

/*
 * LED0 => GPIO52
 * LED1 => GPIO53
 * LED2 => GPIO54
 * LED3 => GPIO55
 */
#define LED1    52
#define LED2    53
#define LED3    54
#define LED4    55 /* XXX : Used by Nexus Port */

#define BUTTONS_COUNT  4

/*
 * BUT0 => GPIO48
 * BUT1 => GPIO49
 * BUT2 => GPIO50
 * BUT3 => GPIO51
 */
#define BUT1    48
#define BUT2    49
#define BUT3    50
#define BUT4    51

#if (((defined DEBUG_OS_MCU_IN_SUPERVISOR_MODE) \
       || (WITH_MEMORY_PROTECTION == NO))       \
    && (WITH_DEBUG == YES))

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
STATIC CONST(uint8, OS_CONST) led_tab[LED_COUNT] = {LED1, LED2, LED3, LED4};
STATIC CONST(uint8, OS_CONST) button_tab[LED_COUNT] = {BUT1, BUT2, BUT3, BUT4};
#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define API_START_SEC_CODE
#include "tpl_memmap.h"

void initLed()
{
    int i;
    for(i = 0; i < LED_COUNT; i++)
    {
        int led_id = led_tab[i];
        SIUL.PCR[led_id] = 0x204;  // set outputs
        SIUL.GPDO[led_id] = 1;     // Light off
    }
}

void initButton()
{
    int i;
    for(i = 0; i < BUTTONS_COUNT; i++)
    {
        int but_id = button_tab[i];
        SIUL.PCR[but_id] = 0x104;  // set inputs
    }
}

void setLed(unsigned int id, unsigned int state)
{
    int led_id = led_tab[id % LED_COUNT];
    SIUL.GPDO[led_id] = state ? 0 : 1;
}

int readButton(unsigned int id)
{
    int but_id = button_tab[id % BUTTONS_COUNT];
    return SIUL.GPDI[but_id];
}

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_DEBUG */

