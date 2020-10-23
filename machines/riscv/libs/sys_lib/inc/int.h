// Copyright 2016 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the “License”); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an “AS IS” BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

/**
 * @file
 * @brief Interrupt library for PULPino.
 *
 * Contains various interrupt manipulating functions.
 *
 * @author Florian Zaruba
 *
 * @version 1.0
 *
 * @date 11/9/2015
 *
 */

#ifndef _INT_H_
#define _INT_H_

#ifndef __riscv__
#include "spr-defs.h"
#endif
#include "tpl_compiler.h"

/* Number of interrupt handlers - really depends on PIC width in OR1200*/
#define MAX_INT_HANDLERS  32


/**
 * \brief Disables interrupts globally.
 * \param void
 * \return void
 *
 * By writing 1 to the ie (interruptenable) bit
 * interrupts are globally disabled.
 */
static inline void int_disable(void) {
#ifdef __riscv__
  asm("csrci 0x7c0, 1" : : );
#else
  mtspr(SPR_SR, mfspr(SPR_SR) & (~SPR_SR_IEE));
#endif
}



/**
 * \brief Enables interrupts globally.
 * \param void
 * \return void
 *
 * By writing 1 to the ie (interruptenable) bit
 * interrupts are globally enabled.
 */
static inline void int_enable(void) {
#ifdef __riscv__
  asm("csrsi 0x7c0, 1" : : );
#else
  mtspr(SPR_SR, mfspr(SPR_SR) | (SPR_SR_IEE));
#endif
}



//declearing all interrupt handlers
//these functions can be redefined by users

FUNC(void, OS_CODE)ISR_I2C (P2CONST(void, OS_APPL_DATA, AUTOMATIC));	// 23: i2c
FUNC(void, OS_CODE)ISR_UART (P2CONST(void, OS_APPL_DATA, AUTOMATIC));	// 23: i2c
FUNC(void, OS_CODE)ISR_GPIO (P2CONST(void, OS_APPL_DATA, AUTOMATIC)); 	// 25: gpio
FUNC(void, OS_CODE)ISR_SPIM0 (P2CONST(void, OS_APPL_DATA, AUTOMATIC));  // 26: spim end of transmission
FUNC(void, OS_CODE)ISR_SPIM1 (P2CONST(void, OS_APPL_DATA, AUTOMATIC));  // 27: spim R/T finished
FUNC(void, OS_CODE)ISR_TA_OVF (P2CONST(void, OS_APPL_DATA, AUTOMATIC)); // 28: timer A overflow
FUNC(void, OS_CODE)ISR_TA_CMP (P2CONST(void, OS_APPL_DATA, AUTOMATIC)); // 29: timer A compare
FUNC(void, OS_CODE)ISR_TB_OVF (P2CONST(void, OS_APPL_DATA, AUTOMATIC)); // 30: timer B overflow
FUNC(void, OS_CODE)ISR_TB_CMP (P2CONST(void, OS_APPL_DATA, AUTOMATIC)); // 31: timer B compare



#endif // _INT_H_
