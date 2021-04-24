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
#ifndef __DSPLIB_SUPPORT_H__
#define __DSPLIB_SUPPORT_H__

//******************************************************************************
//
//! \addtogroup dsplib_support Support
//! @{
//!
//! Definitions and abstraction for MSP devices.
//!
//! \defgroup dsplib_support_device Common
//! This file provides common definitions, useful conversion macros and 
//! abstracted functions to support the core DSPLib functions. While not all
//! macros and functions in this file are useful outside of DSPLib the main
//! application can use any of them as needed.
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
//! \ingroup dsplib_support_device
//!
//! \brief Offset used to store table size.
//
//******************************************************************************
#define DSPLIB_TABLE_OFFSET     2

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Increment size for complex data.
//
//******************************************************************************
#define CMPLX_INCREMENT         (2)

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Access the real portion of complex data.
//
//******************************************************************************
#define CMPLX_REAL(ptr)         ((ptr)[0])

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Access the imaginary portion of complex data.
//
//******************************************************************************
#define CMPLX_IMAG(ptr)         ((ptr)[1])

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Convert number to Q15 fixed point.
//
//******************************************************************************
#ifndef __QMATHLIB_H__ // Define _Q15 if not defined by QmathLib header.
#define _Q15(A)                 ((_q15)((((uint32_t)1 << 15) * \
                                __saturate(A,-1.0,32767.0/32768.0))))
#endif  //__QMATHLIB_H__

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Convert number to IQ31 fixed point.
//
//******************************************************************************
#define _IQ31(A)                ((_iq31)((((uint32_t)1 << 31) * \
                                __saturate(A,-1.0,2147483647.0/2147483648.0))))

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Convert number to IQ31 fixed point.
//
//******************************************************************************
#define _Q31(A)                 (_IQ31(A))

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Saturate input to minimum or maximum value and return value.
//
//******************************************************************************
#define __saturate(x, min, max) (((x)>(max))?(max):(((x)<(min))?(min):(x)))

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Add Q15 arguments with saturation.
//
//******************************************************************************
#if (defined(__TI_COMPILER_VERSION__) && (__TI_COMPILER_VERSION__ >= 15012001)) || \
    (defined(__IAR_SYSTEMS_ICC__) && (__VER__ >= 650))
#define __saturated_add_q15     __saturated_add_signed_short
#else
static inline _q15 __saturated_add_q15(_q15 x, _q15 y)
{
    return (_q15)__saturate((int32_t)x + (int32_t)y, INT16_MIN, INT16_MAX);
}
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Subtract Q15 arguments with saturation.
//
//******************************************************************************
#if (defined(__TI_COMPILER_VERSION__) && (__TI_COMPILER_VERSION__ >= 15012001)) || \
    (defined(__IAR_SYSTEMS_ICC__) && (__VER__ >= 650))
#define __saturated_sub_q15     __saturated_sub_signed_short
#else
static inline _q15 __saturated_sub_q15(_q15 x, _q15 y)
{
    return (_q15)__saturate((int32_t)x - (int32_t)y, INT16_MIN, INT16_MAX);
}
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Add IQ31 arguments with saturation.
//
//******************************************************************************
#if (defined(__TI_COMPILER_VERSION__) && (__TI_COMPILER_VERSION__ >= 15012001)) || \
    (defined(__IAR_SYSTEMS_ICC__) && (__VER__ >= 650))
#define __saturated_add_iq31    __saturated_add_signed_long
#else
static inline _iq31 __saturated_add_iq31(_iq31 x, _iq31 y)
{
    return (_iq31)__saturate((int64_t)x + (int64_t)y, INT32_MIN, INT32_MAX);
}
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Subtract IQ31 arguments with saturation.
//
//******************************************************************************
#if (defined(__TI_COMPILER_VERSION__) && (__TI_COMPILER_VERSION__ >= 15012001)) || \
    (defined(__IAR_SYSTEMS_ICC__) && (__VER__ >= 650))
#define __saturated_sub_iq31    __saturated_sub_signed_long
#else
static inline _iq31 __saturated_sub_iq31(_iq31 x, _iq31 y)
{
    return (_iq31)__saturate((int64_t)x - (int64_t)y, INT32_MIN, INT32_MAX);
}
#endif

//******************************************************************************
//
//! \brief  Circular buffer mask of a pointer.
//!
//! \param  ptr     Pointer to mask
//! \param  mask    Circular buffer mask
//! \return         Pointer after applying circular buffer mask
//
//******************************************************************************
static inline const void *__circular_mask(const void *ptr, uintptr_t mask)
{
    return (void *)((uintptr_t)ptr & ~mask);
}

//******************************************************************************
//
//! \brief  Circular buffer increment of a pointer.
//!
//! \param  ptr     Pointer to increment
//! \param  incr    Increment size
//! \param  mask    Circular buffer mask
//! \return         Pointer after incrementing and applying circular buffer
//!                 mask
//
//******************************************************************************
static inline const void *__circular_increment( const void *ptr,
                                                int16_t incr,
                                                uintptr_t mask)
{
    uintptr_t base = (uintptr_t)__circular_mask(ptr, mask);
    uintptr_t addr = base;
    addr += (uintptr_t)__circular_mask(
                            (const void *)((uintptr_t)ptr + (uintptr_t)incr),
                            ~mask);
    return (const void *)addr;
}

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Place data with alignment, when LEA is used data is placed into the
//!        shared RAM section.
//
//******************************************************************************
#if defined(__TI_COMPILER_VERSION__)
#define _PRAGMA(x) _Pragma (#x)
#if defined(MSP_USE_LEA)
#define DSPLIB_DATA(var,align)  _PRAGMA(DATA_SECTION(var,".leaRAM"))\
                                _PRAGMA(DATA_ALIGN(var,(align)))
#else
#define DSPLIB_DATA(var,align)  _PRAGMA(DATA_ALIGN(var,(align)))
#endif
#elif defined(__IAR_SYSTEMS_ICC__)
#define _PRAGMA(x) _Pragma (#x)
#if defined(MSP_USE_LEA)
#define DSPLIB_DATA(var,align)  _PRAGMA(location="LEARAM")\
                                _PRAGMA(data_alignment=align)\
                                _PRAGMA(object_attribute=__no_init)
#else
#define DSPLIB_DATA(var,align)  _PRAGMA(data_alignment=align)
#endif
#elif defined(__GNUC__)
#if defined(MSP_USE_LEA)
#define DSPLIB_DATA(var,align)  __attribute__((section(".leaRAM")))\
                                __attribute__((aligned(align)))
#else
#define DSPLIB_DATA(var,align)  __attribute__((aligned(align)))
#endif
#else
#define DSPLIB_DATA(var,align)
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Check status flag and loop forever if not MSP_SUCCESS.
//!
//! \param status Status of the operation.
//!
//! \return None
//
//******************************************************************************
static inline void msp_checkStatus(msp_status status)
{
#ifndef MSP_DISABLE_DIAGNOSTICS
    switch (status) {
    case MSP_SUCCESS:
        break;
    case MSP_SIZE_ERROR:
        /* Invalid size error, loop forever. */
         while(true) __no_operation();
    case MSP_SHIFT_SIZE_ERROR:
        /* Invalid shift size error, loop forever. */
         while(true) __no_operation();
    case MSP_TABLE_SIZE_ERROR:
        /* Invalid table size error, loop forever. */
         while(true) __no_operation();
    case MSP_LEA_BUSY:
        /* LEA is busy and cannot be invoked, loop forever. */
         while(true) __no_operation();
    case MSP_LEA_INVALID_ADDRESS:
        /* Address is not within LEA RAM section, loop forever. */
         while(true) __no_operation();
    case MSP_LEA_OUT_OF_RANGE:
        /* Command resulted in out of range memory access, loop forever. */
         while(true) __no_operation();
    case MSP_LEA_SCALAR_INCONSISTENCY:
        /* LEA scalar data inconsistency error, loop forever. */
         while(true) __no_operation();
    case MSP_LEA_COMMAND_OVERFLOW:
        /* LEA command overflow error, loop forever. */
         while(true) __no_operation();
    case MSP_LEA_INCORRECT_REVISION:
        /* LEA incorrect revision, loop forever. */
         while(true) __no_operation();
    default:
        /* Unknown error, loop forever. */
        while(true) __no_operation();
    }
#endif //MSP_DISABLE_DIAGNOSTICS
}

// Benchmark register support
#define HWREG16(x)          (*((volatile uint16_t *)((uint16_t)x)))
#define BENCHMARK_TAxR      (0x0010)
#define BENCHMARK_TAxEX0    (0x0020)

// Define default benchmark timer base address for examples
#if defined(TA0_BASE)
#define MSP_BENCHMARK_BASE  TA0_BASE
#elif defined(TB0_BASE)
#define MSP_BENCHMARK_BASE  TB0_BASE
#else
#define MSP_BENCHMARK_BASE  TIMER_A0_BASE
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Start benchmark using Timer_A or Timer_B with SMCLK as the clock
//!        source.
//!
//! \param baseAddress Base address of timer peripheral to use.
//! \param res Resolution of the benchmark, valid values are:
//!                   - 1 (16-bit result)
//!                   - 2 (17-bit result)
//!                   - 4 (18-bit result)
//!                   - 8 (19-bit result)
//!                   - 16 (20-bit result)
//!                   - 32 (21-bit result)
//!                   - 64 (22-bit result)
//!
//! \return None
//
//******************************************************************************
static inline void msp_benchmarkStart(uint16_t baseAddress, uint8_t res)
{
    static const uint8_t TAx_ID[8] = {
        0x00, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0xC0
    };
    HWREG16(baseAddress) = 0x0004;
    HWREG16(baseAddress+BENCHMARK_TAxEX0) = res < 7 ? 0 : ((0x07&(res >> 3))-1);
    HWREG16(baseAddress) = 0x0220 + TAx_ID[res > 7 ? 7 : ((res-1)&7)];
}

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Stop timer benchmark and return cycle counts.
//!
//! \param baseAddress Base address of timer peripheral to use.
//!
//! \return Benchmark cycle counts.
//
//******************************************************************************
static inline uint32_t msp_benchmarkStop(uint16_t baseAddress)
{
    static const uint8_t TAx_IDEX_SCALE[8] = {
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
    };
    uint16_t cycles = HWREG16(baseAddress+BENCHMARK_TAxR);
    uint16_t shift = (HWREG16(baseAddress) & 0x00C0) >> 6;
    uint16_t scale = TAx_IDEX_SCALE[HWREG16(baseAddress+BENCHMARK_TAxEX0) & 7];
    HWREG16(baseAddress) = 0;
    return (scale*((uint32_t)cycles << shift));
}

#if defined(__MSP430_HAS_MPY32__)

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Real Q15 multiply with result returned.
//!
//! \param a First Q15 input
//! \param b Second Q15 input
//!
//! \return Q15 result
//
//******************************************************************************
static inline int16_t __q15mpy(int16_t a, int16_t b) 
{
    MPYS = a;
    OP2  = b;
    return RESHI;
}

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Real Q15 multiply with 32-bit result returned.
//!
//! \param a First Q15 input
//! \param b Second Q15 input
//!
//! \return IQ31 result
//
//******************************************************************************
static inline int32_t __q15mpyl(int16_t a, int16_t b)
{
    uint32_t result;
    MPYS = a;
    OP2  = b;
    result  = RESLO;
    result |= ((uint32_t)RESHI << 16);
    return (int32_t)result;
}

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Real Q31 multiply with result returned.
//!
//! \param a First Q31 input
//! \param b Second Q31 input
//!
//! \return Q31 result
//
//******************************************************************************
static inline int32_t __q31mpy(int32_t a, int32_t b) 
{
    uint32_t result;
    MPYS32L = a & 0xFFFF;
    MPYS32H = a >> 16;
    OP2L    = b & 0xFFFF;
    OP2H    = b >> 16;
    result  = RES2;
    result |= ((uint32_t)RES3 << 16);
    return (int32_t)result;
}

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Complex Q15 multiply with result stored back to a.
//!
//! \param aR First real Q15 input
//! \param aI First imaginary Q15 input
//! \param bR Second real Q15 input
//! \param bI Second imaginary Q15 input
//!
//! \return Q15 result
//
//******************************************************************************
static inline void __q15cmpy(int16_t *aR,
                             int16_t *aI,
                             const int16_t *bR,
                             const int16_t *bI)
{
    MPYS = *aI;
    OP2  = *bR;
    MACS = *aR;
    OP2  = *bI;
    MPYS = -*aI;
    *aI  = RESHI;
    OP2  = *bI;
    MACS = *aR;
    OP2  = *bR;
    *aR  = RESHI;
}

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Complex IQ31 by IQ31 multiply with result stored back to a.
//!
//! \param aR First real IQ31 input
//! \param aI First imaginary IQ31 input
//! \param bR Second real IQ31 input
//! \param bI Second imaginary IQ31 input
//!
//! \return IQ31 result
//
//******************************************************************************
static inline void __q15iq31cmpy(int32_t *aR,
                                 int32_t *aI,
                                 const int32_t *bR,
                                 const int32_t *bI)
{
    MPYS = *aI;
    OP2L = (uint16_t)*bR;
    OP2H = (uint16_t)(*bR >> 16);
    MACS = *aR;
    OP2L = (uint16_t)*bI;
    OP2H = (uint16_t)(*bI >> 16);
    MPYS = -*aI;
    *aI  = RES1;
    *aI |= ((uint32_t)RES2 << 16);
    OP2L = (uint16_t)*bI;
    OP2H = (uint16_t)(*bI >> 16);
    MACS = *aR;
    OP2L = (uint16_t)*bR;
    OP2H = (uint16_t)(*bR >> 16);
    *aR  = RES1;
    *aR |= ((uint32_t)RES2 << 16);
}

#else //__MSP430_HAS_MPY32__

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Real Q15 multiply with result returned.
//
//******************************************************************************
#define __q15mpy(A, B)  ((int16_t)(((int32_t)(A) * (int32_t)(B)) >> 15))

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Real Q15 multiply with 32-bit result returned.
//
//******************************************************************************
#define __q15mpyl(A, B)  ((int32_t)(((int32_t)(A) * (int32_t)(B)) << 1))

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Real IQ31 multiply with result returned.
//
//******************************************************************************
#define __q31mpy(A, B)  ((int32_t)(((int64_t)(A) * (int64_t)(B)) >> 31))

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Real Q15 by IQ31 multiply with result returned
//
//******************************************************************************
#define __q15iq31mpy(A, B)  ((int32_t)(((int64_t)(A) * (int64_t)(B)) >> 15))

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Complex Q15 multiply with result stored back to a.
//!
//! \param aR First real Q15 input
//! \param aI First imaginary Q15 input
//! \param bR Second real Q15 input
//! \param bI Second imaginary Q15 input
//!
//! \return Q15 result
//
//******************************************************************************
static inline void __q15cmpy(int16_t *aR,
                             int16_t *aI,
                             const int16_t *bR,
                             const int16_t *bI)
{
    int16_t resR =  __q15mpy(*aR, *bR) - __q15mpy(*aI, *bI);
    int16_t resI =  __q15mpy(*aR, *bI) + __q15mpy(*aI, *bR);
    *aR = resR;
    *aI = resI;
}

//******************************************************************************
//
//! \ingroup dsplib_support_device
//!
//! \brief Complex IQ31 by IQ31 multiply with result stored back to a.
//!
//! \param aR First real IQ31 input
//! \param aI First imaginary IQ31 input
//! \param bR Second real IQ31 input
//! \param bI Second imaginary IQ31 input
//!
//! \return IQ31 result
//
//******************************************************************************
static inline void __q15iq31cmpy(int32_t *aR,
                                 int32_t *aI,
                                 const int32_t *bR,
                                 const int32_t *bI)
{
    int32_t resR =  __q15iq31mpy(*aR, *bR) - __q15iq31mpy(*aI, *bI);
    int32_t resI =  __q15iq31mpy(*aR, *bI) + __q15iq31mpy(*aI, *bR);
    *aR = resR;
    *aI = resI;
}

#endif //__MSP430_HAS_MPY32__

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //__DSPLIB_SUPPORT_H__
