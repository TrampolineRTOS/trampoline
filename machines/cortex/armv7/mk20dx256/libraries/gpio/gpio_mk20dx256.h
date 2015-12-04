/**
 * @file gpio_mk20dx256.h
 *
 * @section descr File description
 *
 * mk20dx256 fonctions to toy with the GPIO: General Purpose Input and Output Module
 * Check chapter 49, pages 1331 to 1338 of the mk20dx256 manual
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

#ifndef GPIO_MK20DX256_H
#define GPIO_MK20DX256_H

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_os_definitions.h"

#include "mk20dx256.h"

typedef struct {
  VAR(uint32, TYPEDEF) GPIO_PDOR; /**< Port Data Output Register    */
  VAR(uint32, TYPEDEF) GPIO_PSOR; /**< Port Set Output Register     */
  VAR(uint32, TYPEDEF) GPIO_PCOR; /**< Port Clear Output Register   */
  VAR(uint32, TYPEDEF) GPIO_PTOR; /**< Port Toggle Output Register  */
  VAR(uint32, TYPEDEF) GPIO_PDIR; /**< Port Data Input Register     */
  VAR(uint32, TYPEDEF) GPIO_PDDR; /**< Port Data Direction Register */
  VAR(uint32, TYPEDEF) garbage[10];
} gpio_port;

/*
 * So GPIO channels are accessed with GPIO_PORT[n]
 * where n is is the range 0:4
 * Alternatively, one can use GPIO_PORTA to GPIO_PORTE
*/
#define GPIO_PORT  ((volatile gpio_port *)0x400FF000)

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4


/**
 *
 * Enable access to the GPIO registers control on AIPS0 peripheral bridge in
 * unprivileged thread mode
 *
 * This is done by setting bits SP, WP et TP to 0 all the corresponding PACR
 * register (PACRJ of AIPS0) slot. IE slot 1 (PORTA) to 5 (PORTE).
 * See pages 147 and 345-361 of the mk20dx256 manual.
 *
 */
INLINE_FUNC(void, OS_CODE) GPIOEnableUserAccess()
{
  AIPS0_PACRJ &= ~(
    AIPS_PACR_SP(1) | AIPS_PACR_WP(1) | AIPS_PACR_TP(1) |
    AIPS_PACR_SP(2) | AIPS_PACR_WP(2) | AIPS_PACR_TP(2) |
    AIPS_PACR_SP(3) | AIPS_PACR_WP(3) | AIPS_PACR_TP(3) |
    AIPS_PACR_SP(4) | AIPS_PACR_WP(4) | AIPS_PACR_TP(4) |
    AIPS_PACR_SP(5) | AIPS_PACR_WP(5) | AIPS_PACR_TP(5)
  );
}

/**
 *
 * Disable access to the GPIO registers control on AIPS0 peripheral bridge in
 * unprivileged thread mode
 *
 * This is done by setting bits SP, WP et TP to 0 all the corresponding PACR
 * register (PACRJ of AIPS0) slot. IE slot 1 (PORTA) to 5 (PORTE).
 * See pages 147 and 345-361 of the mk20dx256 manual.
 *
 */
INLINE_FUNC(void, OS_CODE) GPIODisableUserAccess()
{
  AIPS0_PACRJ |=
    AIPS_PACR_SP(1) | AIPS_PACR_WP(1) | AIPS_PACR_TP(1) |
    AIPS_PACR_SP(2) | AIPS_PACR_WP(2) | AIPS_PACR_TP(2) |
    AIPS_PACR_SP(3) | AIPS_PACR_WP(3) | AIPS_PACR_TP(3) |
    AIPS_PACR_SP(4) | AIPS_PACR_WP(4) | AIPS_PACR_TP(4) |
    AIPS_PACR_SP(5) | AIPS_PACR_WP(5) | AIPS_PACR_TP(5);
}

/**
 *
 * Interrupt modes
 */
#define PIN_INT_DISABLED  0 /**< No interrupt allowed                   */
#define PIN_DMA_RISING    1 /**< DMA request on rising edge             */
#define PIN_DMA_FALLING   2 /**< DMA request on falling edge            */
#define PIN_DMA_CHANGE    3 /**< DMA request on falling or rising edge  */
#define PIN_INT_LOW       8 /**< IRQ on logic 0 state                   */
#define PIN_INT_RISING    9 /**< IRQ on rising edge                     */
#define PIN_INT_FALLING  10 /**< IRQ on falling edge                    */
#define PIN_INT_CHANGE   11 /**< IRQ on falling or rising edge          */
#define PIN_INT_HIGH     12 /**< IRQ on logic 1 state                   */

/**
 *
 * Enable Interrupt on a GPIO pin
 *
 * This is done by setting bit ISF (clear the flag)
 * and setting the interrupt mode.
 *
 * See pages 227 of the mk20dx256 manual.
 *
 * @param port    The channel number in range 0:4.
 *                Alternatively GPIO_PORTA to GPIO_PORTE can be used
 * @param pin     The pin in the range 0:31.
 * @param mode    The interrupt mode.
 *
 * @return E_OK         All params are OK
 * @return E_OS_VALUE   channel is out of range
 * @return E_OS_NOFUNC  pin is out of range
 * @return E_OS_STATE   mode is not ok
 */
INLINE_FUNC(void, OS_CODE) GPIOEnableInterruptOnPin(
  CONST(uint32, AUTOMATIC) port,
  CONST(uint32, AUTOMATIC) pin,
  CONST(uint32, AUTOMATIC) mode)
{
  if (channel > 4) return E_OS_VALUE;
  if (pin > 31) return E_OS_NOFUNC;
  if (mode > 12 || (mode < 8 && mode >3)) return E_OS_STATE;
  GPIO_CONTROL_PORT[port].GPIO_PORT_PCR[pin] |= 
    PORT_PCR_ISF | PORT_PCR_IRQC(mode);
  return E_OK;
}

/**
 *
 * Disable Interrupt on a GPIO pin
 *
 * This is done by setting bit ISF (clear the flag)
 * and clearing the interrupt mode.
 *
 * See pages 227 of the mk20dx256 manual.
 *
 * @param port    The channel number in range 0:4.
 *                Alternatively GPIO_PORTA to GPIO_PORTE can be used
 * @param pin     The pin in the range 0:31.
 *
 * @return E_OK         All params are OK
 * @return E_OS_VALUE   channel is out of range
 * @return E_OS_NOFUNC  pin is out of range
 */
INLINE_FUNC(void, OS_CODE) GPIODisableInterruptOnPin(
  CONST(uint32, AUTOMATIC) port,
  CONST(uint32, AUTOMATIC) pin)
{
  if (channel > 4) return E_OS_VALUE;
  if (pin > 31) return E_OS_NOFUNC;
  GPIO_CONTROL_PORT[port].GPIO_PORT_PCR[pin] =
    /* Reset the IRQC to Interrupt/DMA request disabled */
    (GPIO_CONTROL_PORT[port].GPIO_PORT_PCR[pin] & ~PORT_PCR_IRQC_MASK) |
    /* Reset the Interrupt flag ISF */
    PORT_PCR_ISF;
  return E_OK;
}

/**
 *
 * Lock a GPIO pin
 *
 * This is done by setting bit LK
 *
 * See pages 228 of the mk20dx256 manual.
 *
 * @param port    The channel number in range 0:4.
 *                Alternatively GPIO_PORTA to GPIO_PORTE can be used
 * @param pin     The pin in the range 0:31.
 *
 * @return E_OK         All params are OK
 * @return E_OS_VALUE   channel is out of range
 * @return E_OS_NOFUNC  pin is out of range
 */
INLINE_FUNC(void, OS_CODE) GPIOLockPin(
  CONST(uint32, AUTOMATIC) port,
  CONST(uint32, AUTOMATIC) pin)
{
  if (channel > 4) return E_OS_VALUE;
  if (pin > 31) return E_OS_NOFUNC;
  GPIO_CONTROL_PORT[port].GPIO_PORT_PCR[pin] |= PORT_PCR_LK;
  return E_OK;
}

#endif

/* end of file gpio_mk20dx256.h */
