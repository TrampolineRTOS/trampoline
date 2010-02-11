/**
 * @file nxt_irq.c
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

#include "AT91SAM7.h"
#include "tpl_os_it_kernel.h"
#include "buttons.h" //check_buttons_status()

extern void tpl_tick_it_timer1(void); //extern void systick_isr_C(void);
extern void nxt_motor_isr_C(void);
extern void spi_isr_C(void);
extern void uart_isr_C_0(void);
extern void uart_isr_C_1(void);
extern void sound_isr_C(void);
extern void twi_isr_C(void);
extern void systick_low_priority_C(void);
extern void udp_isr_C(void);
extern void i2c_timer_isr_C(void);

extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[31];

#define OS_START_SEC_VAR_8BIT
#include "tpl_memmap.h"
u8 check_buttons_period = 0;
#define OS_STOP_SEC_VAR_8BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC (void, OS_CODE) tpl_arm_subarch_irq_handler (void)
{
    /* When the processor reads AIC_IVR (Interrupt Vector Register),
      the value written into AIC_SVR corresponding to the current
     interrupt is returned. */
    VAR(u16, AUTOMATIC) isr_id = *AT91C_AIC_IVR;
    
    /* Find Interrupt Peripheral ID */
    *AT91C_AIC_IVR = 0xFFFFF100;
    isr_id = *AT91C_AIC_ISR;
    
    /* Launch action (timer, ISR2...) */
    /* TODO : Isn't better to insert those functions in tpl_it_vector ? */
    switch (isr_id)
    {
        case 1:
        {
            tpl_tick_it_timer1();
            check_buttons_period++;
            if (check_buttons_period == 10)
            {
                /* Call check_buttons_status() (via interrupts)
                 * which will check if buttons are pressed or not. */
                *AT91C_AIC_ISCR = (1 << AT91C_PERIPHERAL_ID_IRQ0);
                check_buttons_period = 0;
            }
            break;
        }
        case 2:
        {
            nxt_motor_isr_C();
            break;
        }
        case 5:
        {
            spi_isr_C();
            break;
        }
        case 6:
        {
            uart_isr_C_0();
            break;
        }
        case 7:
        {
            uart_isr_C_1();
            break;
        }
        case 8:
        {
            sound_isr_C();
            break;
        }
        case 9:
        {
            twi_isr_C();
            break;
        }
        case 10:
        {
            systick_low_priority_C();
            break;
        }
        case 11:
        {
            udp_isr_C();
            break;
        }
        case 12:
        {
            i2c_timer_isr_C();
            break;
        }
        case 30:
        {
            check_buttons_status();
            break;
        }
        default:
        {
            /* TODO : launch VECADDR */
            VAR(tpl_it_handler, AUTOMATIC) isr_vector;
            isr_vector = tpl_it_vector[isr_id].func;
            isr_vector(tpl_it_vector[isr_id].args);
            break;
        }
    }
    
    /* Acknowledge interrupt */
    *AT91C_AIC_EOICR = 0xFFFFF130;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file nxt_irq.c */
