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
} gpio_channel;

/*
 * So GPIO channels are accessed with GPIO_CHANNEL[n]
 * where n is is the range 0:4
 * Alternatively, one can use GPIO_PORTA to GPIO_PORTE
*/
#define GPIO_CHANNEL  ((volatile pit_channel *)0x400FF000)

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4

static CONST(uint32, OS_CONST) clockEnableBitForGPIOChannel[5] = {
  SIM_SCGC5_PORTA,
  SIM_SCGC5_PORTB,
  SIM_SCGC5_PORTC,
  SIM_SCGC5_PORTD,
  SIM_SCGC5_PORTE
};

/**
 * Enable clock gating for a GPIO port.
 *
 * This is done by setting bit SIM_SCGC5_PORTA, SIM_SCGC5_PORTB, SIM_SCGC5_PORTC
 * SIM_SCGC5_PORTD or SIM_SCGC5_PORTE in the SIM_SCGC5 register.
 * See page 254 and 255 of the mk20dx256 manual.
 *
 * @param channel The channel number in range 0:4.
 *                Alternatively GPIO_PORTA to GPIO_PORTE can be used
 *
 * @return E_OK       channel is in range 0:4
 * @return E_OS_VALUE channel is out of range
 *
 * AT RESET the GPIO module clock gating is disabled
 */
INLINE_FUNC(void, OS_CODE) GPIOEnableClockForPort(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 4) return E_OS_VALUE;
  SIM_SCGC5 |= clockEnableBitForGPIOChannel[channel];
  return E_OK;
}

/**
 * Disable clock gating for a GPIO port.
 *
 * This is done by clearing bit SIM_SCGC5_PORTA, SIM_SCGC5_PORTB, SIM_SCGC5_PORTC
 * SIM_SCGC5_PORTD or SIM_SCGC5_PORTE in the SIM_SCGC5 register.
 * See page 254 and 255 of the mk20dx256 manual.
 *
 * @param channel The channel number in range 0:4.
 *                Alternatively GPIO_PORTA to GPIO_PORTE can be used
 *
 * @return E_OK       channel is in range 0:4
 * @return E_OS_VALUE channel is out of range
 *
 * AT RESET the GPIO module clock gating is disabled
 */
INLINE_FUNC(void, OS_CODE) GPIODisableClockForPort(
  CONST(uint32, AUTOMATIC) channel)
{
  if (channel > 4) return E_OS_VALUE;
  SIM_SCGC5 &= ~clockEnableBitForGPIOChannel[channel];
  return E_OK;
}

#endif

/* end of file gpio_mk20dx256.h */
