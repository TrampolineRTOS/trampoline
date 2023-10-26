/**
 * \file
 *
 * \brief Instance description for TC1
 *
 * Copyright (c) 2014 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAMD11_TC1_INSTANCE_
#define _SAMD11_TC1_INSTANCE_

/* ========== Register definition for TC1 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_TC1_CTRLA              (0x42001800U) /**< \brief (TC1) Control A */
#define REG_TC1_READREQ            (0x42001802U) /**< \brief (TC1) Read Request */
#define REG_TC1_CTRLBCLR           (0x42001804U) /**< \brief (TC1) Control B Clear */
#define REG_TC1_CTRLBSET           (0x42001805U) /**< \brief (TC1) Control B Set */
#define REG_TC1_CTRLC              (0x42001806U) /**< \brief (TC1) Control C */
#define REG_TC1_DBGCTRL            (0x42001808U) /**< \brief (TC1) Debug Control */
#define REG_TC1_EVCTRL             (0x4200180AU) /**< \brief (TC1) Event Control */
#define REG_TC1_INTENCLR           (0x4200180CU) /**< \brief (TC1) Interrupt Enable Clear */
#define REG_TC1_INTENSET           (0x4200180DU) /**< \brief (TC1) Interrupt Enable Set */
#define REG_TC1_INTFLAG            (0x4200180EU) /**< \brief (TC1) Interrupt Flag Status and Clear */
#define REG_TC1_STATUS             (0x4200180FU) /**< \brief (TC1) Status */
#define REG_TC1_COUNT16_COUNT      (0x42001810U) /**< \brief (TC1) COUNT16 Counter Value */
#define REG_TC1_COUNT16_CC0        (0x42001818U) /**< \brief (TC1) COUNT16 Compare/Capture 0 */
#define REG_TC1_COUNT16_CC1        (0x4200181AU) /**< \brief (TC1) COUNT16 Compare/Capture 1 */
#define REG_TC1_COUNT32_COUNT      (0x42001810U) /**< \brief (TC1) COUNT32 Counter Value */
#define REG_TC1_COUNT32_CC0        (0x42001818U) /**< \brief (TC1) COUNT32 Compare/Capture 0 */
#define REG_TC1_COUNT32_CC1        (0x4200181CU) /**< \brief (TC1) COUNT32 Compare/Capture 1 */
#define REG_TC1_COUNT8_COUNT       (0x42001810U) /**< \brief (TC1) COUNT8 Counter Value */
#define REG_TC1_COUNT8_PER         (0x42001814U) /**< \brief (TC1) COUNT8 Period Value */
#define REG_TC1_COUNT8_CC0         (0x42001818U) /**< \brief (TC1) COUNT8 Compare/Capture 0 */
#define REG_TC1_COUNT8_CC1         (0x42001819U) /**< \brief (TC1) COUNT8 Compare/Capture 1 */
#else
#define REG_TC1_CTRLA              (*(RwReg16*)0x42001800U) /**< \brief (TC1) Control A */
#define REG_TC1_READREQ            (*(RwReg16*)0x42001802U) /**< \brief (TC1) Read Request */
#define REG_TC1_CTRLBCLR           (*(RwReg8 *)0x42001804U) /**< \brief (TC1) Control B Clear */
#define REG_TC1_CTRLBSET           (*(RwReg8 *)0x42001805U) /**< \brief (TC1) Control B Set */
#define REG_TC1_CTRLC              (*(RwReg8 *)0x42001806U) /**< \brief (TC1) Control C */
#define REG_TC1_DBGCTRL            (*(RwReg8 *)0x42001808U) /**< \brief (TC1) Debug Control */
#define REG_TC1_EVCTRL             (*(RwReg16*)0x4200180AU) /**< \brief (TC1) Event Control */
#define REG_TC1_INTENCLR           (*(RwReg8 *)0x4200180CU) /**< \brief (TC1) Interrupt Enable Clear */
#define REG_TC1_INTENSET           (*(RwReg8 *)0x4200180DU) /**< \brief (TC1) Interrupt Enable Set */
#define REG_TC1_INTFLAG            (*(RwReg8 *)0x4200180EU) /**< \brief (TC1) Interrupt Flag Status and Clear */
#define REG_TC1_STATUS             (*(RoReg8 *)0x4200180FU) /**< \brief (TC1) Status */
#define REG_TC1_COUNT16_COUNT      (*(RwReg16*)0x42001810U) /**< \brief (TC1) COUNT16 Counter Value */
#define REG_TC1_COUNT16_CC0        (*(RwReg16*)0x42001818U) /**< \brief (TC1) COUNT16 Compare/Capture 0 */
#define REG_TC1_COUNT16_CC1        (*(RwReg16*)0x4200181AU) /**< \brief (TC1) COUNT16 Compare/Capture 1 */
#define REG_TC1_COUNT32_COUNT      (*(RwReg  *)0x42001810U) /**< \brief (TC1) COUNT32 Counter Value */
#define REG_TC1_COUNT32_CC0        (*(RwReg  *)0x42001818U) /**< \brief (TC1) COUNT32 Compare/Capture 0 */
#define REG_TC1_COUNT32_CC1        (*(RwReg  *)0x4200181CU) /**< \brief (TC1) COUNT32 Compare/Capture 1 */
#define REG_TC1_COUNT8_COUNT       (*(RwReg8 *)0x42001810U) /**< \brief (TC1) COUNT8 Counter Value */
#define REG_TC1_COUNT8_PER         (*(RwReg8 *)0x42001814U) /**< \brief (TC1) COUNT8 Period Value */
#define REG_TC1_COUNT8_CC0         (*(RwReg8 *)0x42001818U) /**< \brief (TC1) COUNT8 Compare/Capture 0 */
#define REG_TC1_COUNT8_CC1         (*(RwReg8 *)0x42001819U) /**< \brief (TC1) COUNT8 Compare/Capture 1 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for TC1 peripheral ========== */
#define TC1_CC8_NUM                 2        // Number of 8-bit Counters
#define TC1_CC16_NUM                2        // Number of 16-bit Counters
#define TC1_CC32_NUM                2        // Number of 32-bit Counters
#define TC1_DITHERING_EXT           0        // Dithering feature implemented
#define TC1_DMAC_ID_MC_0            13
#define TC1_DMAC_ID_MC_1            14
#define TC1_DMAC_ID_MC_LSB          13
#define TC1_DMAC_ID_MC_MSB          14
#define TC1_DMAC_ID_MC_SIZE         2
#define TC1_DMAC_ID_OVF             12       // Indexes of DMA Overflow trigger
#define TC1_GCLK_ID                 18       // Index of Generic Clock
#define TC1_MASTER                  1       
#define TC1_OW_NUM                  2        // Number of Output Waveforms
#define TC1_PERIOD_EXT              0        // Period feature implemented
#define TC1_SHADOW_EXT              0        // Shadow feature implemented

#endif /* _SAMD11_TC1_INSTANCE_ */
