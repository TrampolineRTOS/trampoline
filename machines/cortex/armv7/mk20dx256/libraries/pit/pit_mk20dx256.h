/**
 * @file pit_mk20dx256.h
 *
 * @section descr File description
 *
 * mk20dx256 fonctions to toy with the PIT: Periodic Interrupt Timer Module
 * Check page 257 and chapter 37, pages 901 to 910 of the mk20dx256 manual
 * PIT is on the bus clock = F_CPU / 2
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef PIT_MK20DX256_H
#define PIT_MK20DX256_H

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_os_definitions.h"

#include "mk20dx256.h"

/* PIT Module Freeze in debug flag */
#define PIT_MCR_FRZ   0x00000001
/* PIT Module Disable flag */
#define PIT_MCR_MDIS  0x00000002

/* PIT Timer Enable flag */
#define PIT_TCTRLn_TEN  0x00000001
/* PIT Timer Interrupt Enable flag */
#define PIT_TCTRLn_TIE  0x00000002
/* PIT Timer Chain Flag */
#define PIT_TCTRLn_CHN  0x00000004

/* PIT Timer Interrupt Flag */
#define PIT_TFLGn_TIF 0x00000001

typedef struct {
  VAR(uint32, TYPEDEF) PIT_LDVAL; /**< Channel load value       */
  VAR(uint32, TYPEDEF) PIT_CVAL;  /**< Channel current value    */
  VAR(uint32, TYPEDEF) PIT_TCTRL; /**< Channel control register */
  VAR(uint32, TYPEDEF) PIT_TFLG;  /**< Channel interrupt flag   */
} pit_channel;

#define PIT_CHANNEL  ((volatile pit_channel *)0x40037100)

/**
 * Enable clock gating for the PIT.
 *
 * This is done by setting bit SIM_SCGC6_PIT to 1 in the SIM_SCGC6 register
 * See page 257 of the mk20dx256 manual.
 *
 * AT RESET the pit module clock gating is disabled
 */
INLINE_FUNC(void, OS_CODE) PITEnableClock()
{
  SIM_SCGC6 |= SIM_SCGC6_PIT;
}

/**
 * Disable clock gating for the PIT.
 *
 * This is done by setting bit SIM_SCGC6_PIT to 0 in the SIM_SCGC6 register
 * See page 257 of the mk20dx256 manual.
 */
INLINE_FUNC(void, OS_CODE) PITDisableClock()
{
  SIM_SCGC6 &= ~SIM_SCGC6_PIT;
}

/**
 *
 * Enable access to the PIT registers on AIPS0 peripheral bridge in
 * unprivileged thread mode
 *
 * This is done by setting bits SP, WP et TP to 0 in corresponding PACR
 * register (PACRG of AIPS0) slot. IE slot 7.
 * See pages 147 and 345-361.
 */
INLINE_FUNC(void, OS_CODE) PITEnableUserAccess()
{
  AIPS0_PACRG &= ~(AIPS_PACR_SP(7) | AIPS_PACR_WP(7) | AIPS_PACR_TP(7));
}

/**
 * Enable the PIT module.
 *
 * This is done by setting bit MDIS to 0 in the PIT_MCR register
 * See page 904 of the mk20dx256 manual.
 *
 * This function should be called before any other setup (functions below)
 * is done.
 */
INLINE_FUNC(void, OS_CODE) PITEnableModule()
{
  PIT_MCR &= ~PIT_MCR_MDIS;
}

/**
 * Disable the PIT module.
 *
 * This is done by setting bit MDIS to 1 in the PIT_MCR register
 * See page 904 of the mk20dx256 manual.
 * 
 * At reset the pit module is disabled
 */
INLINE_FUNC(void, OS_CODE) PITDisableModule()
{
  PIT_MCR |= PIT_MCR_MDIS;
}

/**
 * Freeze the PIT module when in debug mode.
 *
 * This is done by setting bit FRZ to 1 in the PIT_MCR register
 * See page 904 of the mk20dx256 manual.
 */
INLINE_FUNC(void, OS_CODE) PITFreezeInDebug()
{
  PIT_MCR |= PIT_MCR_FRZ;
}

/**
 * Do not freeze the PIT module when in debug mode.
 *
 * This is done by setting bit FRZ to 0 in the PIT_MCR register
 * See page 904 of the mk20dx256 manual.
 *
 * AT RESET the pit module does not freeze in debug mode
 */
INLINE_FUNC(void, OS_CODE) PITNoFreezeInDebug()
{
  PIT_MCR &= ~PIT_MCR_FRZ;
}

/**
 * Enable the PIT timer n.
 *
 * @param channel The channel number in range 0:3
 *
 * @return E_OK       channel is in range 0:3
 * @return E_OS_VALUE channel is out of range
 *
 * The tile starts to count down.
 *
 * This is done by setting bit TEN to 1 in the PIT_TCTRLn register
 * See page 905-906 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) PITEnableTimer(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 3) return E_OS_VALUE;
  PIT_CHANNEL[channel].PIT_TCTRL |= PIT_TCTRLn_TEN;
  return E_OK;
}

/**
 * Disable the PIT timer n.
 *
 * @param channel The channel number in range 0:3
 *
 * @return E_OK       channel is in range 0:3
 * @return E_OS_VALUE channel is out of range
 *
 * The timer stops.
 *
 * This is done by setting bit TEN to 0 in the PIT_TCTRLn register
 * See page 905-906 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) PITDisableTimer(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 3) return E_OS_VALUE;
  PIT_CHANNEL[channel].PIT_TCTRL &= ~PIT_TCTRLn_TEN;
  return E_OK;
}

/**
 * Enable the PIT timer n interrupt.
 *
 * @param channel The channel number in range 0:3
 *
 * @return E_OK       channel is in range 0:3
 * @return E_OS_VALUE channel is out of range
 *
 * This is done by setting bit TIE to 1 in the PIT_TCTRLn register
 * See page 905-906 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) PITEnableTimerInterrupt(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 3) return E_OS_VALUE;
  PIT_CHANNEL[channel].PIT_TCTRL |= PIT_TCTRLn_TIE;
  return E_OK;
}

/**
 * Disable the PIT timer n interrupt.
 *
 * @param channel The channel number in range 0:3
 *
 * @return E_OK       channel is in range 0:3
 * @return E_OS_VALUE channel is out of range
 *
 * This is done by setting bit TIE to 0 in the PIT_TCTRLn register
 * See page 905-906 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) PITDisableTimerInterrupt(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 3) return E_OS_VALUE;
  PIT_CHANNEL[channel].PIT_TCTRL &= ~PIT_TCTRLn_TIE;
  return E_OK;
}

/**
 * Acknowledge the PIT timer n interrupt.
 *
 * @param channel The channel number in range 0:3
 *
 * @return E_OK       channel is in range 0:3
 * @return E_OS_VALUE channel is out of range
 *
 * This is done by writing a 1 in bit TIF in the PIT_TFLGn register
 * See page 905-906 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) PITAcknowledgeTimerInterrupt(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 3) return E_OS_VALUE;
  PIT_CHANNEL[channel].PIT_TFLG = PIT_TFLGn_TIF;
  return E_OK;
}

/**
 * Chain the PIT timer n.
 *
 * @param channel The channel number in range 1:3
 *
 * @return E_OK       channel is in range 1:3
 * @return E_OS_VALUE channel is out of range
 *
 * Timer n is chained to timer n-1. So timer n-1 acts as a prescaler
 * for timer n.
 *
 * This is done by setting bit CHN to 1 in the PIT_TCTRLn register
 * See page 905-906 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) PITChainTimer(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 3 || channel < 1) return E_OS_VALUE;
  PIT_CHANNEL[channel].PIT_TCTRL |= PIT_TCTRLn_CHN;
  return E_OK;
}

/**
 * Unchain the PIT timer n.
 *
 * @param channel The channel number in range 1:3
 *
 * @return E_OK       channel is in range 1:3
 * @return E_OS_VALUE channel is out of range
 *
 * This is done by setting bit CHN to 0 in the PIT_TCTRLn register
 * See page 905-906 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) PITUnchainTimer(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 3 || channel < 1) return E_OS_VALUE;
  PIT_CHANNEL[channel].PIT_TCTRL &= ~PIT_TCTRLn_CHN;
  return E_OK;
}

/**
 * Set the load value of timer n.
 *
 * @param channel The channel number in range 0:3
 * @param reload  The reload value
 *
 * @return E_OK       channel is in range 0:3
 * @return E_OS_VALUE channel is out of range
 *
 * The reload value is set. The current timer operation is not modified
 * The new value will be used to reload the timer when the timer will
 * reach 0.
 *
 * See page 904 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) PITSetTimerLoad(
  CONST(uint32, AUTOMATIC) channel,
  CONST(uint32, AUTOMATIC) reload)
{
  if (channel > 3) return E_OS_VALUE;
  PIT_CHANNEL[channel].PIT_LDVAL = reload;
  return E_OK;
}

/**
 * Get the load value of timer n.
 *
 * @param channel The channel number in range 0:3
 * @param reload  A pointer where the reload value is stored
 *
 * @return E_OK       channel is in range 0:3
 * @return E_OS_VALUE channel is out of range
 *
 * Put the reload value in the variable pointed by reload.
 *
 * See page 904 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) PITGetTimerLoad(
  CONST(uint32, AUTOMATIC) channel,
  CONSTP2VAR(uint32, AUTOMATIC, OS_APPL_DATA) reload)
{
  if (channel > 3) return E_OS_VALUE;
  *reload = PIT_CHANNEL[channel].PIT_LDVAL;
  return E_OK;
}

/**
 * Returns the load value of timer n.
 *
 * @param channel The channel number in range 0:3
 *
 * @return        The load value
 *
 * Return the load value of the timer. If the channel is
 * out of range, 0 is returned
 *
 * See page 904 of the mk20dx256 manual.
 */
INLINE_FUNC(uint32, OS_CODE) PITTimerLoad(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 3) return 0;
  return PIT_CHANNEL[channel].PIT_LDVAL;
}

/**
 * Get the current value of timer n.
 *
 * @param channel       The channel number in range 0:3
 * @param currentValue  A pointer where the current value is stored
 *
 * @return E_OK       channel is in range 0:3
 * @return E_OS_VALUE channel is out of range
 *
 * Put the current value in the variable pointed by currentValue.
 *
 * See page 904 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) PITGetTimerValue(
  CONST(uint32, AUTOMATIC) channel,
  CONSTP2VAR(uint32, AUTOMATIC, OS_APPL_DATA) currentValue)
{
  if (channel > 3) return E_OS_VALUE;
  *currentValue = PIT_CHANNEL[channel].PIT_CVAL;
  return E_OK;
}

/**
 * Returns the current value of timer n.
 *
 * @param channel The channel number in range 0:3
 *
 * @return        The current value
 *
 * Return the current value of the timer. If the channel is
 * out of range, 0 is returned
 *
 * See page 904 of the mk20dx256 manual.
 */
INLINE_FUNC(uint32, OS_CODE) PITTimerValue(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 3) return 0;
  return PIT_CHANNEL[channel].PIT_CVAL;
}


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Acknowledge the PIT timer 0, 1, 2 and 3 interrupts.
 *
 * Functions to be used by the handlers generated by goil
 *
 * This is done by writing a 1 in bit TIF in the PIT_TFLG0, PIT_TFLG1,
 * PIT_TFLG2 or PIT_TFLG3 register
 * See page 905-906 of the mk20dx256 manual.
 */
FUNC(void, OS_CODE) PIT0_IRQ_ClearFlag();
FUNC(void, OS_CODE) PIT1_IRQ_ClearFlag();
FUNC(void, OS_CODE) PIT2_IRQ_ClearFlag();
FUNC(void, OS_CODE) PIT3_IRQ_ClearFlag();

#ifdef __cplusplus
}
#endif

#endif

/* end of file pit_mk20dx256.h */
