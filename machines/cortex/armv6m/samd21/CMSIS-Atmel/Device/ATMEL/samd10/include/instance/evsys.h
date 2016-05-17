/**
 * \file
 *
 * \brief Instance description for EVSYS
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

#ifndef _SAMD10_EVSYS_INSTANCE_
#define _SAMD10_EVSYS_INSTANCE_

/* ========== Register definition for EVSYS peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_EVSYS_CTRL             (0x42000400U) /**< \brief (EVSYS) Control */
#define REG_EVSYS_CHANNEL          (0x42000404U) /**< \brief (EVSYS) Channel */
#define REG_EVSYS_USER             (0x42000408U) /**< \brief (EVSYS) User Multiplexer */
#define REG_EVSYS_CHSTATUS         (0x4200040CU) /**< \brief (EVSYS) Channel Status */
#define REG_EVSYS_INTENCLR         (0x42000410U) /**< \brief (EVSYS) Interrupt Enable Clear */
#define REG_EVSYS_INTENSET         (0x42000414U) /**< \brief (EVSYS) Interrupt Enable Set */
#define REG_EVSYS_INTFLAG          (0x42000418U) /**< \brief (EVSYS) Interrupt Flag Status and Clear */
#else
#define REG_EVSYS_CTRL             (*(WoReg8 *)0x42000400U) /**< \brief (EVSYS) Control */
#define REG_EVSYS_CHANNEL          (*(RwReg  *)0x42000404U) /**< \brief (EVSYS) Channel */
#define REG_EVSYS_USER             (*(RwReg16*)0x42000408U) /**< \brief (EVSYS) User Multiplexer */
#define REG_EVSYS_CHSTATUS         (*(RoReg  *)0x4200040CU) /**< \brief (EVSYS) Channel Status */
#define REG_EVSYS_INTENCLR         (*(RwReg  *)0x42000410U) /**< \brief (EVSYS) Interrupt Enable Clear */
#define REG_EVSYS_INTENSET         (*(RwReg  *)0x42000414U) /**< \brief (EVSYS) Interrupt Enable Set */
#define REG_EVSYS_INTFLAG          (*(RwReg  *)0x42000418U) /**< \brief (EVSYS) Interrupt Flag Status and Clear */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for EVSYS peripheral ========== */
#define EVSYS_CHANNELS              6        // Number of Channels
#define EVSYS_CHANNELS_BITS         3        // Number of bits to select Channel
#define EVSYS_CHANNELS_MSB          5        // Number of Channels - 1
#define EVSYS_EXTEVT_NUM            0        // Number of External Event Generators
#define EVSYS_GCLK_ID_0             7
#define EVSYS_GCLK_ID_1             8
#define EVSYS_GCLK_ID_2             9
#define EVSYS_GCLK_ID_3             10
#define EVSYS_GCLK_ID_4             11
#define EVSYS_GCLK_ID_5             12
#define EVSYS_GCLK_ID_LSB           7
#define EVSYS_GCLK_ID_MSB           12
#define EVSYS_GCLK_ID_SIZE          6
#define EVSYS_GENERATORS            44       // Total Number of Event Generators
#define EVSYS_GENERATORS_BITS       6        // Number of bits to select Event Generator
#define EVSYS_USERS                 18       // Total Number of Event Users
#define EVSYS_USERS_BITS            5        // Number of bits to select Event User

// GENERATORS
#define EVSYS_ID_GEN_RTC_CMP_0      1
#define EVSYS_ID_GEN_RTC_CMP_1      2
#define EVSYS_ID_GEN_RTC_OVF        3
#define EVSYS_ID_GEN_RTC_PER_0      4
#define EVSYS_ID_GEN_RTC_PER_1      5
#define EVSYS_ID_GEN_RTC_PER_2      6
#define EVSYS_ID_GEN_RTC_PER_3      7
#define EVSYS_ID_GEN_RTC_PER_4      8
#define EVSYS_ID_GEN_RTC_PER_5      9
#define EVSYS_ID_GEN_RTC_PER_6      10
#define EVSYS_ID_GEN_RTC_PER_7      11
#define EVSYS_ID_GEN_EIC_EXTINT_0   12
#define EVSYS_ID_GEN_EIC_EXTINT_1   13
#define EVSYS_ID_GEN_EIC_EXTINT_2   14
#define EVSYS_ID_GEN_EIC_EXTINT_3   15
#define EVSYS_ID_GEN_EIC_EXTINT_4   16
#define EVSYS_ID_GEN_EIC_EXTINT_5   17
#define EVSYS_ID_GEN_EIC_EXTINT_6   18
#define EVSYS_ID_GEN_EIC_EXTINT_7   19
#define EVSYS_ID_GEN_DMAC_CH_0      20
#define EVSYS_ID_GEN_DMAC_CH_1      21
#define EVSYS_ID_GEN_DMAC_CH_2      22
#define EVSYS_ID_GEN_DMAC_CH_3      23
#define EVSYS_ID_GEN_TCC0_OVF       24
#define EVSYS_ID_GEN_TCC0_TRG       25
#define EVSYS_ID_GEN_TCC0_CNT       26
#define EVSYS_ID_GEN_TCC0_MCX_0     27
#define EVSYS_ID_GEN_TCC0_MCX_1     28
#define EVSYS_ID_GEN_TCC0_MCX_2     29
#define EVSYS_ID_GEN_TCC0_MCX_3     30
#define EVSYS_ID_GEN_TC1_OVF        31
#define EVSYS_ID_GEN_TC1_MCX_0      32
#define EVSYS_ID_GEN_TC1_MCX_1      33
#define EVSYS_ID_GEN_TC2_OVF        34
#define EVSYS_ID_GEN_TC2_MCX_0      35
#define EVSYS_ID_GEN_TC2_MCX_1      36
#define EVSYS_ID_GEN_ADC_RESRDY     37
#define EVSYS_ID_GEN_ADC_WINMON     38
#define EVSYS_ID_GEN_AC_COMP_0      39
#define EVSYS_ID_GEN_AC_COMP_1      40
#define EVSYS_ID_GEN_AC_WIN_0       41
#define EVSYS_ID_GEN_DAC_EMPTY      42
#define EVSYS_ID_GEN_PTC_EOC        43
#define EVSYS_ID_GEN_PTC_WCOMP      44

// USERS
#define EVSYS_ID_USER_DMAC_CH_0     0
#define EVSYS_ID_USER_DMAC_CH_1     1
#define EVSYS_ID_USER_DMAC_CH_2     2
#define EVSYS_ID_USER_DMAC_CH_3     3
#define EVSYS_ID_USER_TCC0_EV_0     4
#define EVSYS_ID_USER_TCC0_EV_1     5
#define EVSYS_ID_USER_TCC0_MC_0     6
#define EVSYS_ID_USER_TCC0_MC_1     7
#define EVSYS_ID_USER_TCC0_MC_2     8
#define EVSYS_ID_USER_TCC0_MC_3     9
#define EVSYS_ID_USER_TC1_EVU       10
#define EVSYS_ID_USER_TC2_EVU       11
#define EVSYS_ID_USER_ADC_START     12
#define EVSYS_ID_USER_ADC_SYNC      13
#define EVSYS_ID_USER_AC_SOC_0      14
#define EVSYS_ID_USER_AC_SOC_1      15
#define EVSYS_ID_USER_DAC_START     16
#define EVSYS_ID_USER_PTC_STCONV    17

#endif /* _SAMD10_EVSYS_INSTANCE_ */
