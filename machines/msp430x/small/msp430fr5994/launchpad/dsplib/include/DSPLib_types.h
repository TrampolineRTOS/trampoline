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
#ifndef __DSPLIB_TYPES_H__
#define __DSPLIB_TYPES_H__

//******************************************************************************
//
//! \addtogroup dsplib_types Types
//! @{
//!
//! Definitions of types used in DSPLib.
//!
//! @}
//
//******************************************************************************

//******************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//******************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//******************************************************************************
//
//! \ingroup dsplib_types
//!
//! \brief Define C std macros not available in C++ (for Energia).
//
//******************************************************************************
#ifndef INT16_MIN
#define INT16_MIN   0x8000
#endif

//******************************************************************************
//
//! \ingroup dsplib_types
//!
//! \brief Define C std macros not available in C++ (for Energia).
//
//******************************************************************************
#ifndef INT16_MAX
#define INT16_MAX   0x7fff
#endif

//******************************************************************************
//
//! \ingroup dsplib_types
//!
//! \brief Define C std macros not available in C++ (for Energia).
//
//******************************************************************************
#ifndef INT32_MIN
#define INT32_MIN   0x80000000
#endif

//******************************************************************************
//
//! \ingroup dsplib_types
//!
//! \brief Define C std macros not available in C++ (for Energia).
//
//******************************************************************************
#ifndef INT32_MAX
#define INT32_MAX   0x7fffffff
#endif

//******************************************************************************
//
//! \ingroup dsplib_types
//!
//! \brief Signed fixed point data type with 1 integer bit and 15 fractional
//!        bits.
//
//******************************************************************************
#ifndef __QMATHLIB_H__ // Define _q15 if not defined by QmathLib header.
typedef int16_t _q15;
#endif  //__QMATHLIB_H__

//******************************************************************************
//
//! \ingroup dsplib_types
//!
//! \brief Unsigned fixed point data type with 0 integer bit and 16 fractional
//!        bits.
//
//******************************************************************************
typedef uint16_t _uq15;

//******************************************************************************
//
//! \ingroup dsplib_types
//!
//! \brief Signed fixed point data type with 1 integer bit and 31 fractional
//!        bits.
//
//******************************************************************************
typedef int32_t _iq31;

//******************************************************************************
//
//! \ingroup dsplib_types
//!
//! \brief Unsigned fixed point data type with 0 integer bits and 32 fractional
//!        bits.
//
//******************************************************************************
typedef uint32_t _uq31;

//******************************************************************************
//
//! \ingroup dsplib_types
//!
//! \brief Enumerated type to return the status of an operation.
//
//******************************************************************************
typedef enum {
    //! Successful operation.
    MSP_SUCCESS = 0,
    //! Invalid size, see API for restrictions.
    MSP_SIZE_ERROR = 1,
    //! Invalid shift size, see API for restrictions.
    MSP_SHIFT_SIZE_ERROR = 2,
    //! Invalid table size, see API for restrictions.
    MSP_TABLE_SIZE_ERROR = 3,
    //! LEA is busy and cannot be invoked.
    MSP_LEA_BUSY = 4,
    //! Address is not within LEA RAM section.
    MSP_LEA_INVALID_ADDRESS = 5,
    //! Command resulted in out of range memory access.
    MSP_LEA_OUT_OF_RANGE = 6,
    //! LEA scalar data inconsistency error.
    MSP_LEA_SCALAR_INCONSISTENCY = 7,
    //! LEA command overflow error.
    MSP_LEA_COMMAND_OVERFLOW = 8,
    //! LEA incorrect revision.
    MSP_LEA_INCORRECT_REVISION = 9
} msp_status;

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //__DSPLIB_TYPES_H__
