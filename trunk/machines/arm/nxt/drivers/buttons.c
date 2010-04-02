/**
 * @file buttons.c
 *
 * @section descr File description
 *
 * NXT platform. Check buttons status.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
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
#include "tpl_os_it_kernel.h" //tpl_central_interrupt_handler_2

#include "AT91SAM7.h"
#include "ecrobot_interface.h" //ecrobot_status_monitor
#include "ecrobot_private.h" //ecrobot_get_button_state, ecrobot_poll_nxtstate, ENTER_PRESSED...

#include "buttons.h"

extern void tpl_primary_irq_handler(void);

/**
 * InitButtons
 *
 * Initialize interrupt AT91C_PERIPHERAL_ID_IRQ0 which will check
 * buttons status each 10ms (see tpl_arm_subarch_irq_handler())
 * See tpl_init_machine()
 *
 */
void InitButtons(void)
{
    int i_state = interrupts_get_and_disable();
    
    aic_mask_off(AT91C_PERIPHERAL_ID_IRQ0);
    aic_set_vector(AT91C_PERIPHERAL_ID_IRQ0, (1 << 5) /* positive internal edge */ |
                   AIC_INT_LEVEL_NORMAL, (U32) tpl_primary_irq_handler);
    aic_mask_on(AT91C_PERIPHERAL_ID_IRQ0); 
    
    if (i_state)
        interrupts_enable();
}

/**
 * check_buttons_status
 * 
 * check buttons status every 10ms
 * See nxt_irq.c
 */
ISR(check_buttons_status)
{
    
    /* Read status to confirm interrupt */
    //status = *AT91C_AIC_IVR;
    
    u8 buttons_state = 0;
    /* check buttons status */
    ecrobot_poll_nxtstate();
    buttons_state = ecrobot_get_button_state();
    
    /* for debug disp = dectohex((char)(buttons_state & 0x0F)); */
    
    /* launch interrupts */
    VAR(tpl_it_handler, AUTOMATIC) isr_vector;
    extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[31];
    
    if ((buttons_state & ENTER_PRESSED) == ENTER_PRESSED)
    {
        isr_vector = tpl_it_vector[15].func;
        isr_vector(tpl_it_vector[15].args);
    }
    else if ((buttons_state & STOP_PRESSED) == STOP_PRESSED)
    {
        isr_vector = tpl_it_vector[16].func;
        isr_vector(tpl_it_vector[16].args);    
    }
    else if ((buttons_state & RUN_PRESSED) == RUN_PRESSED)
    {
        isr_vector = tpl_it_vector[17].func;
        isr_vector(tpl_it_vector[17].args);            
    }
    else if ((buttons_state & EXIT_PRESSED) == EXIT_PRESSED)
    {
        isr_vector = tpl_it_vector[18].func;
        isr_vector(tpl_it_vector[18].args);          
    }
    
}

/* End of file buttons.c */
