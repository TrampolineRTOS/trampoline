/* Driver for the AT91SAM7's Advanced Interrupt Controller (AIC).
 *
 * The AIC is responsible for queuing interrupts from other
 * peripherals on the board. It then hands them one by one to the ARM
 * CPU core for handling, according to each peripheral's configured
 * priority.
 */

#include "AT91SAM7.h"

#include "mytypes.h"
#include "interrupts.h"

#include "aic.h"


/* Shorthand for addressing the System Controller structure defined in
 * the AT91 platform package, where the AIC's registers are defined.
 */
#define sysc ((volatile struct _AT91S_SYSC *)0xFFFFF000)


/* Default handlers for the three general kinds of interrupts that the
 * ARM core has to handle. These are defined in irq.s, and just freeze
 * the board in an infinite loop.
 */
/* modified by fp 100121
 extern void default_isr(void);
extern void default_fiq(void);
extern void spurious_isr(void);
*/
extern void tpl_primary_irq_handler(void);
extern void tpl_primary_fiq_handler(void);

/* Initialise the Advanced Interrupt Controller.
 *
 * Note that this function leaves interrupts disabled in the ARM core
 * when it returns, so that other board drivers may register interrupt
 * handlers safely.
 */
void
aic_initialise(void)
{
  int i;

  /* Prevent the ARM core from being interrupted while we set up the
   * AIC.
   */
  interrupts_get_and_disable();

  /* If we're coming from a warm boot, the AIC may be in a weird
   * state. Do some cleaning up to bring the AIC back into a known
   * state:
   *  - All interrupt lines disabled,
   *  - No interrupt lines handled by the FIQ handler,
   *  - No pending interrupts,
   *  - AIC idle, not handling an interrupt.
   */
  sysc->SYSC_AIC_IDCR = 0xFFFFFFFF;
  sysc->SYSC_AIC_FFDR = 0xFFFFFFFF;
  sysc->SYSC_AIC_ICCR = 0xFFFFFFFF;
  sysc->SYSC_AIC_EOICR = 1;

  /* Enable debug protection. This is necessary for JTAG debugging, so
   * that the hardware debugger can read AIC registers without
   * triggering side-effects.
   */
  sysc->SYSC_AIC_DCR = 1;

  /* Set default handlers for all interrupt lines. */
  for (i = 0; i < 32; i++) {
    sysc->SYSC_AIC_SMR[i] = 0;
    sysc->SYSC_AIC_SVR[i] = (U32) tpl_primary_irq_handler; //(U32) default_isr;
  }
  //by fp 100521
  sysc->SYSC_AIC_SMR[AT91C_PERIPHERAL_ID_FIQ] = 0;  
  sysc->SYSC_AIC_SVR[AT91C_PERIPHERAL_ID_FIQ] =  (U32) tpl_primary_fiq_handler; //(U32) default_fiq;
  sysc->SYSC_AIC_SPU =  (U32) tpl_primary_fiq_handler; //(U32) spurious_isr;
}

/* Register an interrupt service routine for an interrupt line.
 *
 * Note that while this function registers the routine in the AIC, it
 * does not enable or disable the interrupt line for that vector. Use
 * aic_mask_on and aic_mask_off to control actual activation of the
 * interrupt line.
 *
 * Args:
 *   vector: The peripheral ID to claim (see AT91SAM7.h for peripheral IDs)
 *   mode: The priority of this interrupt in relation to others. See aic.h
 *         for a list of defined values.
 *   isr: A pointer to the interrupt service routine function.
 */
void
aic_set_vector(U32 vector, U32 mode, U32 isr)
{
  if (vector < 32) {
    int i_state = interrupts_get_and_disable();

    sysc->SYSC_AIC_SMR[vector] = mode;
    sysc->SYSC_AIC_SVR[vector] = isr;
    if (i_state)
      interrupts_enable();
  }
}


/* Enable handling of an interrupt line in the AIC.
 *
 * Args:
 *   vector: The peripheral ID of the interrupt line to enable.
 */
void
aic_mask_on(U32 vector)
{
  int i_state = interrupts_get_and_disable();

  sysc->SYSC_AIC_IECR = (1 << vector);
  if (i_state)
    interrupts_enable();
}


/* Disable handling of an interrupt line in the AIC.
 *
 * Args:
 *   vector: The peripheral ID of the interrupt line to disable.
 */
void
aic_mask_off(U32 vector)
{
  int i_state = interrupts_get_and_disable();

  sysc->SYSC_AIC_IDCR = (1 << vector);
  if (i_state)
    interrupts_enable();
}


/* Clear an interrupt line in the AIC.
 *
 * Args:
 *   vector: The peripheral ID of the interrupt line to clear.
 */
void
aic_clear(U32 vector)
{
  int i_state = interrupts_get_and_disable();

  sysc->SYSC_AIC_ICCR = (1 << vector);
  if (i_state)
    interrupts_enable();
}
