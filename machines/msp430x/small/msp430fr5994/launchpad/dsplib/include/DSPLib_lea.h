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
#ifndef __DSPLIB_LEA_H__
#define __DSPLIB_LEA_H__

//******************************************************************************
//
//! \addtogroup dsplib_support Support
//! @{
//!
//! \defgroup dsplib_support_lea LEA
//! Definitions required to support the use of LEA.
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

#if defined(__MSP430_HAS_LEA__) && !defined(MSP_DISABLE_LEA)

#if __MSP430_HEADER_VERSION__ < 1192
#error "DSPLib: Device header file is out of date, please upgrade to the \
latest support package to use this version of DSPLib with LEA."
#endif

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Enable the LEA accelerator for DSPLib functions. The default is
//! to use LEA when available, to disable LEA define MSP_DISABLE_LEA in
//! the compiler settings.
//!
//! It is always recommended to use LEA for lowest power and best performance.
//! Disabling LEA is only intended to be used for benchmarking LEA
//! performance against the CPU and hardware multiplier or by users who would
//! like to dedicate the LEA peripheral to a specific function and run the
//! remainder on the CPU.
//
//******************************************************************************
#define MSP_USE_LEA                 1

// LEA revision A.
#define MSP_LEA_REVISION_A          0

// LEA revision B.
#define MSP_LEA_REVISION_B          1

// LEA revision B.
#define MSP_LEA_REVISION_C          2

// Unknown revision of LEA.
#define MSP_LEA_REVISION_UNKNOWN    255

#if !defined(MSP_LEA_REVISION)

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief If a LEA revision is not specified default to revision B.
//
//******************************************************************************
#define MSP_LEA_REVISION            MSP_LEA_REVISION_B

#endif //MSP_LEA_REVISION

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Convert MSP430 address to internal LEA address mapping.
//
//******************************************************************************
#define MSP_LEA_CONVERT_ADDRESS(x)  ((uint16_t)(((uintptr_t)(x) >> 2) & 0xffff))

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Convert LEA address to MSP430 address mapping.
//
//******************************************************************************
#define MSP_LEA_REVERT_ADDRESS(x)   ((uintptr_t)(((uint32_t)(x) << 2)))

// Cast read-only registers to const to avoid compiler warnings.
#define MSP_LEA_BOTTOM              (*((const uint16_t *)(&LEAMB)))
#define MSP_LEA_TOP                 (*((const uint16_t *)(&LEAMT)))

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Check that the address is aligned correctly.
//
//******************************************************************************
#define MSP_LEA_RANGE(x)            (((uintptr_t)(x) >= MSP_LEA_BOTTOM) \
                                        && ((uintptr_t)(x) < MSP_LEA_TOP))

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Check that the address is within the LEA RAM.
//
//******************************************************************************
#define MSP_LEA_ALIGNED(x,n)        (!((uint32_t)(x) & ((n)-1)))

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Check that the address aligment is valid and within the LEA RAM.
//
//******************************************************************************
#define MSP_LEA_VALID_ADDRESS(x,n)  (MSP_LEA_RANGE(x) & MSP_LEA_ALIGNED(x,n))

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA constant memory address for 0x0000 coefficients.
//
//******************************************************************************
#define MSP_LEA_CONST_ZERO          0xA000

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA constant memory address for 0x7fff coefficients.
//
//******************************************************************************
#define MSP_LEA_CONST_ONE           0xAC00

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA constant memory address for 0x8000 coefficients.
//
//******************************************************************************
#define MSP_LEA_Q15_CONST_NEG_ONE   0xB000

 //******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA constant memory address for 0x80000000 coefficients.
//
//******************************************************************************
#define MSP_LEA_IQ31_CONST_NEG_ONE  0xE000

 //******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA command ID for interleave even even command.
//
//******************************************************************************
#define LEACMD__INTERLEAVEEVENEVEN  (0x0000f000)

 //******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA command ID for interleave even odd command.
//
//******************************************************************************
#define LEACMD__INTERLEAVEEVENODD   (0x0000f001)

 //******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA command ID for interleave odd even command.
//
//******************************************************************************
#define LEACMD__INTERLEAVEODDEVEN   (0x0000f002)

 //******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA command ID for interleave odd odd command.
//
//******************************************************************************
#define LEACMD__INTERLEAVEODDODD    (0x0000f003)

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__ADDMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Input data vector 2.
    uint16_t input2;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector 1.
    uint16_t input1Offset;
    //! Offset of input vector 2.
    uint16_t input2Offset;
    //! Offset of output vector.
    uint16_t outputOffset;
} MSP_LEA_ADDMATRIX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEAMD__ADDLONGMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! Input data vector 2.
    uint16_t input2;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector 1.
    uint16_t input1Offset;
    //! Offset of input vector 2.
    uint16_t input2Offset;
    //! Offset of output vector.
    uint16_t outputOffset;
} MSP_LEA_ADDLONGMATRIX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__SUBMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Input data vector 2.
    uint16_t input2;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector 1.
    uint16_t input1Offset;
    //! Offset of input vector 2.
    uint16_t input2Offset;
    //! Offset of output vector.
    uint16_t outputOffset;
} MSP_LEA_SUBMATRIX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__SUBLONGMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! Input data vector 2.
    uint16_t input2;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector 1.
    uint16_t input1Offset;
    //! Offset of input vector 2.
    uint16_t input2Offset;
    //! Offset of output vector.
    uint16_t outputOffset;
} MSP_LEA_SUBLONGMATRIX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MPYMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Input data vector 2.
    uint16_t input2;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector 1.
    uint16_t input1Offset;
    //! Offset of input vector 2.
    uint16_t input2Offset;
    //! Offset of output vector.
    uint16_t outputOffset;
} MSP_LEA_MPYMATRIX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MPYLONGMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! Input data vector 2.
    uint16_t input2;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector 1.
    uint16_t input1Offset;
    //! Offset of input vector 2.
    uint16_t input2Offset;
    //! Offset of output vector.
    uint16_t outputOffset;
} MSP_LEA_MPYLONGMATRIX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MAC command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Input data vector 2.
    uint16_t input2;
    //! Output data vector.
    uint16_t output;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_MAC_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MACLONGMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! Input data vector 2.
    uint16_t input2;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector 1.
    uint16_t input1Offset;
    //! Offset of input vector 2.
    uint16_t input2Offset;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_MACLONG_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__POLYNOMIAL command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Output data vector.
    uint16_t output;
    //! Polynomial coefficient vector.
    uint16_t coeff;
    //! Polynomial coefficient order.
    uint16_t order;
    //! Scale factor.
    int32_t scaleFactor;
} MSP_LEA_POLY_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MAX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Output data vector.
    uint16_t output;
} MSP_LEA_MAX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MAXLONGMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector.
    uint16_t inputOffset;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_MAXLONG_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MAXUNSIGNED command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Output data vector.
    uint16_t output;
} MSP_LEA_MAXUNSIGNED_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MAXUNSIGNEDMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector.
    uint16_t inputOffset;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_MAXLONGUNSIGNED_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MIN command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Output data vector.
    uint16_t output;
} MSP_LEA_MIN_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MINLONGMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector.
    uint16_t inputOffset;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_MINLONG_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MINUNSIGNEDMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector.
    uint16_t inputOffset;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_MINUNSIGNED_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MINLONGUNSIGNED command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector.
    uint16_t inputOffset;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_MINLONGUNSIGNED_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MPYCOMPLEXMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Input data vector 2.
    uint16_t input2;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector 1.
    uint16_t input1Offset;
    //! Offset of input vector 2.
    uint16_t input2Offset;
    //! Offset of output vector.
    uint16_t outputOffset;
} MSP_LEA_MPYCOMPLEXMATRIX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MACCOMPLEXMATRIX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Input data vector 2.
    uint16_t input2;
    //! Output data vector.
    uint16_t output;
    //! Offset of input vector 1.
    uint16_t input1Offset;
    //! Offset of input vector 2.
    uint16_t input2Offset;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_MACCOMPLEXMATRIX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__MPYMATRIXROW command.
//
//******************************************************************************
typedef struct {
    //! Input row size.
    uint16_t rowSize;
    //! Input column size.
    uint16_t colSize;
    //! Input column vector.
    uint16_t colVector;
    //! Output data vector.
    uint16_t output;
} MSP_LEA_MPYMATRIXROW_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__FIR command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! FIR coefficient vector.
    uint16_t coeffs;
    //! Output data vector.
    uint16_t output;
    //! Length of FIR coefficient vector.
    uint16_t tapLength;
    //! Input buffer increment mask.
    uint16_t bufferMask;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_FIR_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__FIRLONG command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! FIR coefficient vector.
    uint16_t coeffs;
    //! Output data vector.
    uint16_t output;
    //! Length of FIR coefficient vector.
    uint16_t tapLength;
    //! Input buffer increment mask.
    uint16_t bufferMask;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_FIRLONG_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__FIRCOMPLEX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! FIR coefficient vector.
    uint16_t coeffs;
    //! Output data vector.
    uint16_t output;
    //! Length of FIR coefficient vector.
    uint16_t tapLength;
    //! Input buffer increment mask.
    uint16_t bufferMask;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_FIRCOMPLEX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__FIRLONGCOMPLEX command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! FIR coefficient vector.
    uint16_t coeffs;
    //! Output data vector.
    uint16_t output;
    //! Length of FIR coefficient vector.
    uint16_t tapLength;
    //! Input buffer increment mask.
    uint16_t bufferMask;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_FIRLONGCOMPLEX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__IIRBQ1 command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector divided by two.
    uint16_t vectorSizeBy2;
    //! Output data vector.
    uint16_t output;
    //! Biquad state structure.
    uint16_t state;
    //! Biquad coefficient structure.
    uint16_t coeffs;
    //! Input increment direction.
    uint16_t direction;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_IIRBQ1_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__IIRBQ2 and LEACMD__IIRBQ2EXTENDED
//! commands.
//
//******************************************************************************
typedef struct {
    //! Length of data vector divided by two.
    uint16_t vectorSizeBy2;
    //! Output data vector.
    uint16_t output;
    //! Biquad state structure.
    uint16_t state;
    //! Biquad coefficient structure.
    uint16_t coeffs;
} MSP_LEA_IIRBQ2_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__BITREVERSECOMPLEXEVEN or 
//! LEACMD__BITREVERSECOMPLEXODD commands.
//
//******************************************************************************
typedef struct {
    //! Square root of data vector length.
    uint16_t sqrtVectorSize;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_BITREVERSECOMPLEX_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__BITREVERSECOMPLEXLONGEVEN or 
//! LEACMD__BITREVERSECOMPLEXLONGODD commands.
//
//******************************************************************************
typedef struct {
    //! Square root of data vector length.
    uint16_t sqrtVectorSize;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_BITREVERSECOMPLEXLONG_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__FFTCOMPLEXAUTOSCALING command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector divided by two, must be a power of two.
    uint16_t vectorSizeBy2;
    //! Log base 2 of 2*vectorSizeBy2 parameter.
    uint16_t log2Size;
} MSP_LEA_FFTCOMPLEXAUTOSCALING_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__FFTCOMPLEXFIXEDSCALING command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector divided by two, must be a power of two.
    uint16_t vectorSizeBy2;
    //! Log base 2 of 2*vectorSizeBy2 parameter.
    uint16_t log2Size;
} MSP_LEA_FFTCOMPLEXFIXEDSCALING_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__FFTCOMPLEXLONG command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a power of two.
    uint16_t vectorSize;
    //! Log base 2 of vectorSize parameter.
    uint16_t log2Size;
} MSP_LEA_FFTCOMPLEXLONG_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__FFT command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a power of two.
    uint16_t vectorSize;
    //! Log base 2 of vectorSize parameter.
    uint16_t log2Size;
} MSP_LEA_FFT_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__FFTLONG command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector,must be a power of two.
    uint16_t vectorSize;
    //! Log base 2 of vectorSize parameter.
    uint16_t log2Size;
} MSP_LEA_FFTLONG_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__INTERLEAVEEVENEVEN,
//! LEACMD__INTERLEAVEEVENODD, LEACMD__INTERLEAVEODDEVEN and
//! LEACMD__INTERLEAVEODDODD commands.
//
//******************************************************************************
typedef struct {
    //! Output data vector.
    uint16_t output;
    //! Channel to insert vector into.
    uint16_t channel;
    //! Number of destination channels.
    uint16_t numChannels;
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
} MSP_LEA_INTERLEAVE_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__DEINTERLEAVEEVENEVEN,
//! LEACMD__DEINTERLEAVEEVENODD, LEACMD__DEINTERLEAVEODDEVEN and
//! LEACMD__DEINTERLEAVEODDODD commands.
//
//******************************************************************************
typedef struct {
    //! Length of data vector, must be a multiple of two.
    uint16_t vectorSize;
    //! Depth of interleave operation.
    uint16_t interleaveDepth;
    //! Output data vector.
    uint16_t output;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_DEINTERLEAVE_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Parameter structure for LEACMD__DEINTERLEAVELONG command.
//
//******************************************************************************
typedef struct {
    //! Length of data vector.
    uint16_t vectorSize;
    //! Depth of interleave operation.
    uint16_t interleaveDepth;
    //! Output data vector.
    uint16_t output;
    //! Reserved padding.
    uint16_t reserved;
} MSP_LEA_DEINTERLEAVELONG_PARAMS;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__MIN command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_MIN[23];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__MINUNSIGNED command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_MINUNSIGNED[23];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__MINLONGMATRIX command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_MINLONGMATRIX[20];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__MINUNSIGNEDLONGMATRIX command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_MINUNSIGNEDLONGMATRIX[20];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__MAX command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_MAX[23];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__MAXUNSIGNED command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_MAXUNSIGNED[23];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__MAXLONGMATRIX command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_MAXLONGMATRIX[20];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__MAXUNSIGNEDLONGMATRIX command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_MAXUNSIGNEDLONGMATRIX[20];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__MACLONGMATRIX command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_MACLONGMATRIX[18];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEACMD__FFTCOMPLEXAUTOSCALING command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_FFTCOMPLEXAUTOSCALING[58];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__FFTCOMPLEXLONG command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_FFTCOMPLEXLONG[64];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__MPYLONGMATRIX command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_MPYLONGMATRIX[17];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__IIRBQ1 command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_IIRBQ1[31];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__IIRBQ2 command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_IIRBQ2[32];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__IIRBQ2EXTENDED command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_IIRBQ2EXTENDED[47];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__FIRLONG command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_FIRLONG[30];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA patch for the LEA__FIRCOMPLEXLONG command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_FIRCOMPLEXLONG[43];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA function for the LEACMD__INTERLEAVEEVENEVEN command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_INTERLEAVEEVENEVEN[22];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA function for the LEACMD__INTERLEAVEEVENODD command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_INTERLEAVEEVENODD[24];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA function for the LEACMD__INTERLEAVEODDEVEN command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_INTERLEAVEODDEVEN[22];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief LEA function for the LEACMD__INTERLEAVEODDODD command.
//
//******************************************************************************
extern const uint32_t MSP_LEA_INTERLEAVEODDODD[24];

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief DSPLib interrupt flags.
//
//******************************************************************************
extern volatile uint16_t msp_lea_ifg;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief DSPLib LEA-SC locked flag.
//
//******************************************************************************
extern volatile uint16_t msp_lea_locked;

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief DSPLib initialization routine for LEA.
//!
//! \return none
//
//******************************************************************************
extern void msp_lea_init(void);

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Invoke a command with interrupts enabled and enter low-power mode or
//! poll the interrupt flag.
//!
//! \return none
//
//******************************************************************************
static inline void msp_lea_invokeCommand(uint16_t cmdId)
{
    /* Save interrupt state and disable interrupts. */
    uint16_t interruptState = __get_interrupt_state();
    __disable_interrupt();

    /* Clear interrupt flag and invoke the command. */
    msp_lea_ifg = 0;
    LEAPMCB = cmdId | LEAITFLG1;
    
#if defined(MSP_DISABLE_LPM0)
#warning "DSPLib: LPM0 is disabled, undefine MSP_DISABLE_LPM0 to enable LPM0."
    /* Do not enter LPM0, poll interrupt flags for command completion. */
    __bis_SR_register(GIE);
    while(!msp_lea_ifg);
#elif ((MSP_LEA_REVISION==MSP_LEA_REVISION_A) && !defined(MSP_ENABLE_LPM0))
    /* Do not enter LPM0, poll interrupt flags for command completion. */
    __bis_SR_register(GIE);
    while(!msp_lea_ifg);
#else
    /* Enter LPM0 and wait for command complete interrupt to wake the device. */
    __bis_SR_register(GIE+LPM0_bits);
#endif

    /* Restore original interrupt state. */
    __set_interrupt_state(interruptState);
}

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Allocate LEA-SC memory from stack.
//!
//! \param length Length of memory to allocate in 32-bit words.
//!
//! \return Pointer to allocated memory.
//
//******************************************************************************
static inline void *msp_lea_allocMemory(uint16_t length)
{
    LEACNF2 -= length;
    return (void *)MSP_LEA_REVERT_ADDRESS(LEACNF2);
}

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Free LEA-SC memory from stack.
//!
//! \param length Length of memory to allocate in 32-bit words.
//!
//! \return none
//
//******************************************************************************
static inline void msp_lea_freeMemory(uint16_t length)
{
    LEACNF2 += length;
}

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Acquire LEA-SC module if available.
//!
//! \return Status of the operation, true means lock was acquired.
//
//******************************************************************************
static inline bool msp_lea_acquireLock(void)
{
#ifndef MSP_DISABLE_DIAGNOSTICS
    bool status;

    /* Save interrupt state and disable interrupts. */
    uint16_t interruptState = __get_interrupt_state();
    __disable_interrupt();

    /* Check LEA-SC busy flag and DSPLib lock flags. */
    if ((LEACNF1 & LEABUSY) || msp_lea_locked) {
        status = false;
    }
    else {
        status = true;
        msp_lea_locked = true;
    }

    /* Restore interrupt state and return status. */
    __set_interrupt_state(interruptState);
    return status;
#endif //MSP_DISABLE_DIAGNOSTICS
}

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Free LEA-SC module.
//!
//! \return none
//
//******************************************************************************
static inline void msp_lea_freeLock(void)
{
#ifndef MSP_DISABLE_DIAGNOSTICS
    msp_lea_locked = false;
#endif //MSP_DISABLE_DIAGNOSTICS
}

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Initialize the table used for loading commands.
//!
//! \return none
//
//******************************************************************************
extern void msp_lea_initCommandTable(void);

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Return the revision of LEA code ROM.
//!
//! \return LEA revision.
//
//******************************************************************************
extern uint16_t msp_lea_getRevision(void);

//******************************************************************************
//
//! \ingroup dsplib_support_lea
//!
//! \brief Load a LEA command into code memory.
//!
//! \return LEA command ID for loaded command.
//
//******************************************************************************
extern uint16_t msp_lea_loadCommand(
                    uint16_t commandId, const void *command, uint16_t length);

#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DSPLIB_LEA_H__
