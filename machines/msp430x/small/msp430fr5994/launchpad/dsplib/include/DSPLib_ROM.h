/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
#ifndef __DSPLIB_ROM_H__
#define __DSPLIB_ROM_H__

//******************************************************************************
//
//! \addtogroup dsplib_support Support
//! @{
//!
//! \defgroup dsplib_support_rom ROM
//! Definitions required to support the use of DSPLib functions in ROM.
//!
//! @}
//
//******************************************************************************

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#if (defined(__MSP430FR2355__) || defined(__MSP430FR2353__) || \
     defined(__MSP430FR2155__) || defined(__MSP430FR2153__)) && !defined(MSP_DISABLE_ROM)

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Use DSPLib functions located in ROM. The default is to use ROM 
//! functions when available, to disable use of ROM functions define
//! MSP_DISABLE_ROM in the compiler settings.
//!
//! It is always recommended to use ROM functions for lowest power and best
//! performance. Disabling ROM functions is only recommended for debugging.
//
//******************************************************************************
#define MSP_USE_ROM                 1

// Check for compatible code model
#if (defined(__TI_COMPILER_VERSION__) && !defined(__LARGE_CODE_MODEL__)) || \
    (defined(__IAR_SYSTEMS_ICC__) && (__CODE_MODEL__!=__CODE_MODEL_LARGE__))
#error "Incompatible code model selected, switch to large code model or \
disable ROM functions by defining MSP_DISABLE_ROM in compiler settings."
#endif

// Check for compatible data model
#if (defined(__TI_COMPILER_VERSION__) && !defined(__LARGE_DATA_MODEL__)) || \
    (defined(__IAR_SYSTEMS_ICC__) && (__DATA_MODEL__!=__DATA_MODEL_LARGE__))
#error "Incompatible data model selected, switch to large code model or \
disable ROM functions by defining MSP_DISABLE_ROM in compiler settings."
#endif

// Check CCS compiler version for ROM compatability
#if defined(__TI_COMPILER_VERSION__)
#if __TI_COMPILER_VERSION__ >= 18001001
#define __cc_rom __attribute__((call_conv("cc_rom")))   
#else
#error "The cc_rom attribute requires MSP TI COMPILER 18.1.1.LTS or newer, \
please upgrade your compiler to use this version of DSPLib with ROM funcitons."
#endif
#endif

// Check IAR register model
#if defined(__IAR_SYSTEMS_ICC__)
#if __REGISTER_R4__ != __REGISTER_FREE__
#error "Incorrect setting for R4, expected it to be free."
#endif
#if __REGISTER_R5__ != __REGISTER_FREE__
#error "Incorrect setting for R5, expected it to be free."
#endif
#endif

// Suppress CCS type conversion warning
#if defined (__TI_COMPILER_VERSION__)
#pragma diag_suppress 173
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief DSPLib API table for functions located in ROM.
//
//******************************************************************************
#define ROM_DSPLIB_TABLE        ((uint32_t *)(((uint32_t *)ROMLIB_START)[1]))

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for ROM msp_fft_auto_q15() function.
//
//******************************************************************************
#define ROM_msp_fft_auto_q15                                                   \
    ((msp_status (__cc_rom *)                                                  \
    (const msp_fft_q15_params *params, int16_t *src, uint16_t *shift))         \
    ROM_DSPLIB_TABLE[0])

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for ROM msp_fft_fixed_q15() function.
//
//******************************************************************************
#define ROM_msp_fft_fixed_q15                                                   \
    ((msp_status (__cc_rom *)                                                  \
    (const msp_fft_q15_params *params, int16_t *src))                          \
    ROM_DSPLIB_TABLE[1])

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for ROM msp_fft_iq31() function.
//
//******************************************************************************
#define ROM_msp_fft_iq31                                                       \
    ((msp_status (__cc_rom *)                                                  \
    (const msp_fft_iq31_params *params, int32_t *src))                         \
    ROM_DSPLIB_TABLE[2])

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for ROM msp_cmplx_fft_auto_q15() function.
//
//******************************************************************************
#define ROM_msp_cmplx_fft_auto_q15                                               \
    ((msp_status (__cc_rom *)                                                  \
    (const msp_cmplx_fft_q15_params *params, int16_t *src, uint16_t *shift))   \
    ROM_DSPLIB_TABLE[3])

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for ROM msp_cmplx_fft_fixed_q15() function.
//
//******************************************************************************
#define ROM_msp_cmplx_fft_fixed_q15                                               \
    ((msp_status (__cc_rom *)                                                  \
    (const msp_cmplx_fft_q15_params *params, int16_t *src))                    \
    ROM_DSPLIB_TABLE[4])

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for ROM msp_cmplx_fft_iq31() function.
//
//******************************************************************************
#define ROM_msp_cmplx_fft_iq31                                                   \
    ((msp_status (__cc_rom *)                                                  \
    (const msp_cmplx_fft_iq31_params *params, int32_t *src))                   \
    ROM_DSPLIB_TABLE[5])

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for ROM twiddle table.
//
//******************************************************************************
#define ROM_msp_cmplx_twiddle_table_2048_q15                                   \
    ((_q15 *)ROM_DSPLIB_TABLE[6])

#endif

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for MAP msp_fft_auto_q15() function.
//
//******************************************************************************
#ifdef ROM_msp_fft_auto_q15
#define MAP_msp_fft_auto_q15                                                   \
        ROM_msp_fft_auto_q15
#else
#define MAP_msp_fft_auto_q15                                                   \
        msp_fft_auto_q15
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for MAP msp_fft_fixed_q15() function.
//
//******************************************************************************
#ifdef ROM_msp_fft_fixed_q15
#define MAP_msp_fft_fixed_q15                                                  \
        ROM_msp_fft_fixed_q15
#else
#define MAP_msp_fft_fixed_q15                                                  \
        msp_fft_fixed_q15
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for MAP msp_fft_iq31() function.
//
//******************************************************************************
#ifdef ROM_msp_fft_iq31
#define MAP_msp_fft_iq31                                                       \
        ROM_msp_fft_iq31
#else
#define MAP_msp_fft_iq31                                                       \
        msp_fft_iq31
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for MAP msp_cmplx_fft_auto_q15() function.
//
//******************************************************************************
#ifdef ROM_msp_cmplx_fft_auto_q15
#define MAP_msp_cmplx_fft_auto_q15                                             \
        ROM_msp_cmplx_fft_auto_q15
#else
#define MAP_msp_cmplx_fft_auto_q15                                             \
        msp_cmplx_fft_auto_q15
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for MAP msp_cmplx_fft_fixed_q15() function.
//
//******************************************************************************
#ifdef ROM_msp_cmplx_fft_fixed_q15
#define MAP_msp_cmplx_fft_fixed_q15                                            \
        ROM_msp_cmplx_fft_fixed_q15
#else
#define MAP_msp_cmplx_fft_fixed_q15                                            \
        msp_cmplx_fft_fixed_q15
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//!
//! \brief Definition for MAP msp_cmplx_fft_iq31() function.
//
//******************************************************************************
#ifdef ROM_msp_cmplx_fft_iq31
#define MAP_msp_cmplx_fft_iq31                                                 \
        ROM_msp_cmplx_fft_iq31
#else
#define MAP_msp_cmplx_fft_iq31                                                 \
        msp_cmplx_fft_iq31
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_rom
//
//! \brief Definition for MAP twiddle table.
//
//******************************************************************************
#ifdef ROM_msp_cmplx_twiddle_table_2048_q15
#define MAP_msp_cmplx_twiddle_table_2048_q15                                   \
        ROM_msp_cmplx_twiddle_table_2048_q15
#else
#define MAP_msp_cmplx_twiddle_table_2048_q15                                   \
        msp_cmplx_twiddle_table_2048_q15
#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //__DSPLIB_ROM_H__
