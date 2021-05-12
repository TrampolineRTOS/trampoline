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
#ifndef __DSPLIB_FILTER_H__
#define __DSPLIB_FILTER_H__

//******************************************************************************
//
//! \addtogroup dsplib_filter_api Filter
//! @{
//!
//! Functions for common digital filters such as Finite Impulse Response (FIR)
//! and Infinite Impulse Response (IIR). The filter functions support real and
//! complex inputs as well as 16-bit and 32-bit data types.
//!
//! \defgroup dsplib_filter_real_fir Real FIR
//! Functions for performing real Finite Impulse Response (FIR) filters.
//!
//! \defgroup dsplib_filter_complex_fir Complex FIR
//! Functions for performing complex Finite Impulse Response (FIR) filters.
//!
//! \defgroup dsplib_filter_real_iir Real IIR
//! Functions for performing real Infinite Impulse Response (IIR) filters.
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
//! \ingroup dsplib_filter_real_fir
//!
//! \brief Calculate the alignment for a 16-bit real FIR filter from length
//! parameter.
//
//******************************************************************************
#define MSP_ALIGN_FIR_Q15(n)        (n*4)

//******************************************************************************
//
//! \ingroup dsplib_filter_real_fir
//!
//! \brief Calculate the alignment for a 32-bit real FIR filter from length
//! parameter.
//
//******************************************************************************
#define MSP_ALIGN_FIR_IQ31(n)        (n*8)

//******************************************************************************
//
//! \ingroup dsplib_filter_complex_fir
//!
//! \brief Calculate the alignment for a 16-bit complex FIR filter from length
//! parameter.
//
//******************************************************************************
#define MSP_ALIGN_CMPLX_FIR_Q15(n)  (n*8)

//******************************************************************************
//
//! \ingroup dsplib_filter_complex_fir
//!
//! \brief Calculate the alignment for a 32-bit complex FIR filter from length
//! parameter.
//
//******************************************************************************
#define MSP_ALIGN_CMPLX_FIR_IQ31(n) (n*16)

//******************************************************************************
//
//! \ingroup dsplib_filter_real_fir
//!
//! \brief Parameter structure for FIR filter.
//
//******************************************************************************
typedef struct msp_fir_q15_params {
    //! \details
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
    //! \details
    //! Length of FIR coefficients, must be a multiple of two.
    uint16_t tapLength;
    //! \details
    //! Pointer to real FIR filter coefficients.
    const _q15 *coeffs;
    //! \details
    //! Enable circular buffer.
    bool enableCircularBuffer;
} msp_fir_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_fir
//!
//! \brief Parameter structure for FIR filter.
//
//******************************************************************************
typedef struct msp_fir_iq31_params {
    //! \details
    //! Length of the output, must be a multiple of two.
    uint16_t length;
    //! \details
    //! Length of FIR coefficients, must be a multiple of two.
    uint16_t tapLength;
    //! \details
    //! Pointer to real FIR filter coefficients.
    const _iq31 *coeffs;
    //! \details
    //! Enable circular buffer.
    bool enableCircularBuffer;
} msp_fir_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_filter_complex_fir
//!
//! \brief Parameter structure for complex FIR filter.
//
//******************************************************************************
typedef struct msp_cmplx_fir_q15_params{
    //! \details
    //! Length of the output, must be a multiple of two.
    uint16_t length;
    //! \details
    //! Length of FIR coefficients, must be a multiple of two.
    uint16_t tapLength;
    //! \details
    //! Pointer to complex FIR filter coefficients.
    const _q15 *coeffs;
    //! \details
    //! Enable circular buffer.
    bool enableCircularBuffer;
} msp_cmplx_fir_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_filter_complex_fir
//!
//! \brief Parameter structure for complex FIR filter.
//
//******************************************************************************
typedef struct msp_cmplx_fir_iq31_params{
    //! \details
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
    //! \details
    //! Length of FIR coefficients, must be a multiple of two.
    uint16_t tapLength;
    //! \details
    //! Pointer to complex FIR filter coefficients.
    const _iq31 *coeffs;
    //! \details
    //! Enable circular buffer.
    bool enableCircularBuffer;
} msp_cmplx_fir_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Coefficients for direct form 1 biquad filter.
//
//******************************************************************************
typedef struct msp_biquad_df1_q15_coeffs {
    //! \details
    //! Coefficient b2
    _q15 b2;
    //! \details
    //! Coefficient b1 divided by two
    _q15 b1By2;
    //! \details
    //! Coefficient b0
    _q15 b0;
    //! \details
    //! Reserved, do not remove
    uint16_t reserved1;
    //! \details
    //! Coefficient a2
    _q15 a2;
    //! \details
    //! Coefficient a1 divided by two
    _q15 a1By2;
} msp_biquad_df1_q15_coeffs;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief States for direct form 1 biquad filter.
//
//******************************************************************************
typedef struct msp_biquad_df1_q15_states {
    //! \details
    //! Input x[n-2]
    _q15 x2;
    //! \details
    //! Input x[n-1]
    _q15 x1;
    //! \details
    //! Output y[n-2]
    _q15 y2;
    //! \details
    //! Output y[n-1]
    _q15 y1;
} msp_biquad_df1_q15_states;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Parameter structure for direct form 1 biquad filter.
//
//******************************************************************************
typedef struct msp_biquad_df1_q15_params {
    //! \details
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
    //! \details
    //! Pointer to DF1 filter coefficients. This data block must be allocated in
    //! shared RAM when using LEA.
    const msp_biquad_df1_q15_coeffs *coeffs;
    //! \details
    //! Pointer to an array of length four used to store the state of the
    //! operation. When continuous operation is desired the previous state
    //! needs to be passed to the next biquad operation. This data block must be
    //! allocated in shared RAM when using LEA.
    msp_biquad_df1_q15_states *states;
} msp_biquad_df1_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Parameter structure for cascaded direct form 1 biquad filter.
//
//******************************************************************************
typedef struct msp_biquad_cascade_df1_q15_params {
    //! \details
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
    //! \details
    //! Number of cascaded biquad filters, typically the filter order divided by
    //! two.
    uint16_t stages;
    //! \details
    //! Pointer to an array of DF1 filter coefficients of length stages. This
    //! data block must be allocated in shared RAM when using LEA.
    const msp_biquad_df1_q15_coeffs *coeffs;
    //! \details
    //! Pointer to an array of DF1 filter states of length stages. When
    //! continuous operation is desired the previous states must be passed to
    //! the next cascaded biquad operation. This data block must be allocated in
    //! shared RAM when using LEA.
    msp_biquad_df1_q15_states *states;
} msp_biquad_cascade_df1_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Coefficients for direct form 2 biquad filter. When using LEA these
//! coefficients must be placed into shared RAM.
//
//******************************************************************************
typedef struct msp_biquad_df2_q15_coeffs {
    //! \details
    //! Reserved, do not remove
    uint16_t reserved1;
    //! \details
    //! Coefficient a2
    _q15 a2;
    //! \details
    //! Coefficient a1 divided by two
    _q15 a1By2;
    //! \details
    //! Coefficient a0
    _q15 a0;
    //! \details
    //! Coefficient b0
    _q15 b0;
    //! \details
    //! Coefficient b1 divided by two
    _q15 b1By2;
    //! \details
    //! Coefficient b2
    _q15 b2;
    //! \details
    //! Reserved, do not remove
    uint16_t reserved2;
} msp_biquad_df2_q15_coeffs;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief States for direct form 2 biquad filter.
//
//******************************************************************************
typedef struct msp_biquad_df2_q15_states {
    //! \details
    //! State Q1
    _q15 q1;
    //! \details
    //! State Q2
    _q15 q2;
} msp_biquad_df2_q15_states;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Parameter structure for direct form 2 biquad filter.
//
//******************************************************************************
typedef struct msp_biquad_df2_q15_params {
    //! \details
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
    //! \details
    //! Pointer to DF2 filter coefficients. This data block must be allocated in
    //! shared RAM when using LEA.
    const msp_biquad_df2_q15_coeffs *coeffs;
    //! \details
    //! Pointer to an array of length two used to store the state of the
    //! operation. When continuous operation is desired the previous state
    //! needs to be passed to the next biquad operation. This data block must be
    //! allocated in shared RAM when using LEA.
    msp_biquad_df2_q15_states *states;
} msp_biquad_df2_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Parameter structure for cascaded direct form 2 biquad filter.
//
//******************************************************************************
typedef struct msp_biquad_cascade_df2_q15_params {
    //! \details
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
    //! \details
    //! Number of cascaded biquad filters, typically the filter order divided by
    //! two.
    uint16_t stages;
    //! \details
    //! Pointer to an array of DF2 filter coefficients of length stages. This
    //! data block must be allocated in shared RAM when using LEA.
    const msp_biquad_df2_q15_coeffs *coeffs;
    //! \details
    //! Pointer to an array of DF2 filter states of length stages. When
    //! continuous operation is desired the previous states must be passed to
    //! the next cascaded biquad operation. This data block must be allocated in
    //! shared RAM when using LEA.
    msp_biquad_df2_q15_states *states;
} msp_biquad_cascade_df2_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Coefficients for extended direct form 2 biquad filter. When using
//! LEA these coefficients must be placed into shared RAM.
//
//******************************************************************************
typedef struct msp_biquad_df2_ext_q15_coeffs {
    //! \details
    //! Constant bias added to input.
    _iq31 bias;
    //! \details
    //! Reserved, do not remove
    uint16_t reserved1;
    //! \details
    //! Coefficient a2
    _q15 a2;
    //! \details
    //! Coefficient a1 divided by two
    _q15 a1By2;
    //! \details
    //! Coefficient a0
    _q15 a0;
    //! \details
    //! Coefficient b0
    _q15 b0;
    //! \details
    //! Coefficient b1 divided by two
    _q15 b1By2;
    //! \details
    //! Coefficient b2
    _q15 b2;
    //! \details
    //! Reserved, do not remove
    uint16_t reserved2;
} msp_biquad_df2_ext_q15_coeffs;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief States for extended direct form 2 biquad filter.
//
//******************************************************************************
typedef struct msp_biquad_df2_ext_q15_states {
    //! \details
    //! State Q1
    _q15 q1;
    //! \details
    //! State Q2
    _q15 q2;
    //! \details
    //! Minimum of even states
    _q15 minEven;
    //! \details
    //! Minimum of odd states
    _q15 minOdd;
    //! \details
    //! Maximum of even states
    _q15 maxEven;
    //! \details
    //! Maximum of odd states
    _q15 maxOdd;
    //! \details
    //! Minimum intermediate state
    _q15 min;
    //! \details
    //! Maximum intermediate state
    _q15 max;
} msp_biquad_df2_ext_q15_states;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Parameter structure for extended direct form 2 biquad filter.
//
//******************************************************************************
typedef struct msp_biquad_df2_ext_q15_params {
    //! \details
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
    //! \details
    //! Pointer to extended DF2 filter coefficients. This data block must be
    //! allocated in shared RAM when using LEA.
    const msp_biquad_df2_ext_q15_coeffs *coeffs;
    //! \details
    //! Pointer to an array of length eight used to store the state of the
    //! operation. When continuous operation is desired the previous state
    //! needs to be passed to the next biquad operation. This data block must be
    //! allocated in shared RAM when using LEA.
    msp_biquad_df2_ext_q15_states *states;
} msp_biquad_df2_ext_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Parameter structure for cascaded extended direct form 2 biquad
//! filter.
//
//******************************************************************************
typedef struct msp_biquad_cascade_df2_ext_q15_params {
    //! \details
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
    //! \details
    //! Number of cascaded biquad filters, typically the filter order divided by
    //! two.
    uint16_t stages;
    //! \details
    //! Pointer to an array of DF2 filter coefficients of length stages. This
    //! data block must be allocated in shared RAM when using LEA.
    const msp_biquad_df2_ext_q15_coeffs *coeffs;
    //! \details
    //! Pointer to an array of DF2 filter states of length stages. When
    //! continuous operation is desired the previous states must be passed to
    //! the next cascaded biquad operation. This data block must be allocated in
    //! shared RAM when using LEA.
    msp_biquad_df2_ext_q15_states *states;
} msp_biquad_cascade_df2_ext_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_filter_real_fir
//!
//! \brief Discrete-time convolution of a source vector with real coefficients
//!        to apply an FIR filter.
//!
//! \par Details
//! FIR filter implementation utilizing discrete-time convolution. Q15
//! multiplication is performed with a 32-bit accumulator to avoid intermediate
//! overflow.
//!
//! \par Pseudo code
//! `dst = conv([stateBuffer, src], taps)(0:1:length)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment when circular buffer is disabled or
//! aligned to four times the FIR data length if circular buffer is enabled 
//! (e.g. a 64-sample FIR with 128-sample circular buffer must be aligned to a 
//! 256-byte address). When allocating data the MSP\_ALIGN\_FIR\_Q15 macro can
//! be used to calculate the correct alignment.
//!
//! \param params Pointer to the FIR parameter structure.
//! \param src Pointer to the source vector to filter.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_fir_q15(
                        const msp_fir_q15_params *params,
                        const _q15 *src,
                        _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_filter_real_fir
//!
//! \brief Discrete-time convolution of a source vector with real coefficients
//!        to apply an FIR filter.
//!
//! \par Details
//! FIR filter implementation utilizing discrete-time convolution. IQ31
//! multiplication is performed with a 32-bit accumulator to avoid intermediate
//! overflow.
//!
//! \par Pseudo code
//! `dst = conv([stateBuffer, src], taps)(0:1:length)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment when circular buffer is disabled or
//! aligned to eight times the FIR data length if circular buffer is enabled 
//! (e.g. a 64-sample FIR with 128-sample circular buffer must be aligned to a 
//! 512-byte address). When allocating data the MSP\_ALIGN\_FIR\_IQ31 macro can
//! be used to calculate the correct alignment.
//!
//! \param params Pointer to the FIR parameter structure.
//! \param src Pointer to the source vector to filter.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_fir_iq31(
                        const msp_fir_iq31_params *params,
                        const _iq31 *src,
                        _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_filter_complex_fir
//!
//! \brief Discrete-time convolution of a complex source vector with complex
//!        coefficients to apply an FIR filter.
//!
//! \par Details
//! FIR filter implementation utilizing discrete-time convolution. Complex Q15
//! multiplication is performed with a 32-bit accumulator to avoid intermediate
//! overflow.
//!
//! \par Pseudo code
//! `dst = conv([stateBuffer, src], taps)(0:1:length)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment when circular buffer is disabled or
//! aligned to eight times the FIR data length if circular buffer is enabled 
//! (e.g. a 64-sample FIR with 128-sample circular buffer must be aligned to a 
//! 512-byte address). When allocating data the MSP\_ALIGN\_CMPLX\_FIR\_Q15 
//! macro can be used to calculate the correct alignment.
//!
//! \param params Pointer to the complex FIR parameter structure.
//! \param src Pointer to the source vector to filter.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_fir_q15(
                        const msp_cmplx_fir_q15_params *params,
                        const _q15 *src,
                        _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_filter_complex_fir
//!
//! \brief Discrete-time convolution of a complex source vector with complex
//!        coefficients to apply an FIR filter.
//!
//! \par Details
//! FIR filter implementation utilizing discrete-time convolution. Complex IQ31
//! multiplication is performed with a 32-bit accumulator to avoid intermediate
//! overflow.
//!
//! \par Pseudo code
//! `dst = conv([stateBuffer, src], taps)(0:1:length)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment when circular buffer is disabled or
//! aligned to sixteen times the FIR data length if circular buffer is enabled 
//! (e.g. a 64-sample FIR with 128-sample circular buffer must be aligned to a 
//! 1024-byte address). When allocating data the MSP\_ALIGN\_CMPLX\_FIR\_IQ31 
//! macro can be used to calculate the correct alignment.
//!
//! \param params Pointer to the complex FIR parameter structure.
//! \param src Pointer to the source vector to filter.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_fir_iq31(
                        const msp_cmplx_fir_iq31_params *params,
                        const _iq31 *src,
                        _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Second-order direct form 1 biquad filter.
//!
//! \par Details
//! Second-order biquad filter with direct form 1 implementation. Q15
//! multiplication is performed with a 32-bit accumulator to avoid intermediate
//! overflow with saturation to Q15 when storing the result.
//!
//! ![Biquad DF1 structure](images/biquad_df1.svg)
//!
//! \par Pseudo code
//! `y[n] = b0 * x[n] + b1 * x[n-1] + b2 * x[n-2] +  a1 * y[n-1] + a2 * y[n-2]`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the biquad direct form 1 parameter structure.
//! \param src Pointer to the source data to filter.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_biquad_df1_q15(
                        const msp_biquad_df1_q15_params *params,
                        const _q15 *src,
                        _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Cascaded direct form 1 biquad filter.
//!
//! \par Details
//! Cascaded biquad filter with direct form 1 implementation. The coefficients
//! are passed as an array of second-order sections (SOS matrix) and each
//! section is passed to msp_biquad_df1_q15 to filter the input.
//!
//! ![Example filter with three DF1 stages](images/biquad_cascade_df1.svg)
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the cascaded biquad direct form 1 parameter
//!                    structure.
//! \param src Pointer to the source data to filter.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_biquad_cascade_df1_q15(
                        const msp_biquad_cascade_df1_q15_params *params,
                        const _q15 *src,
                        _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Second-order direct form 2 biquad filter.
//!
//! \par Details
//! Second-order direct form 2 biquad filter. Q15 multiplication is performed
//! with a 32-bit accumulator to avoid intermediate overflow with saturation to
//! Q15 when storing the result.
//!
//! ![Biquad DF2 structure](images/biquad_df2.svg)
//!
//! \par Pseudo code
//! `y[n] = b0 * w[n] + b1 * w[n-1] + b2 * w[n-2]` \n
//! `w[n] = a0 * x[n] + a1 * x[n-1] + a2 * x[n-2]`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the biquad direct form 2 parameter structure.
//! \param src Pointer to the source data to filter.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_biquad_df2_q15(
                        const msp_biquad_df2_q15_params *params,
                        const _q15 *src,
                        _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Cascaded direct form 2 biquad filter.
//!
//! \par Details
//! Cascaded biquad filter with direct form 2 implementation. The coefficients
//! are passed as an array of second-order sections (SOS matrix) and each
//! section is passed to msp_biquad_df1_q15 to filter the input.
//!
//! ![Example filter with three DF2 stages](images/biquad_cascade_df2.svg)
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the cascaded biquad direct form 2 parameter
//!                    structure.
//! \param src Pointer to the source data to filter.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_biquad_cascade_df2_q15(
                        const msp_biquad_cascade_df2_q15_params *params,
                        const _q15 *src,
                        _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Second-order direct form 2 biquad filter extended with DC bias and
//! minimum and maximum tracking.
//!
//! \par Details
//! Second-order direct form 2 biquad filter extended to include bias and
//! minimum and maximum state tracking. Q15 multiplication is performed with a
//! 32-bit accumulator to avoid intermediate overflow with saturation to Q15
//! when storing the result. The maximum and minimum of the intermediate states
//! are stored in the state structure.
//!
//! ![Biquad DF2 structure (extended)](images/biquad_df2_ext.svg)
//!
//! \par Pseudo code
//! `y[n] = b0 * w[n] + b1 * w[n-1] + b2 * w[n-2]` \n
//! `w[n] = a0 * x[n] + a1 * x[n-1] + a2 * x[n-2]`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the biquad direct form 2 parameter structure.
//! \param src Pointer to the source data to filter.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_biquad_df2_ext_q15(
                        const msp_biquad_df2_ext_q15_params *params,
                        const _q15 *src,
                        _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_filter_real_iir
//!
//! \brief Cascaded direct form 2 biquad filter extended with DC bias and
//! minimum and maximum tracking.
//!
//! \par Details
//! Cascaded biquad filter with direct form 2 implementation extended to include
//! bias and minimum and maximum state tracking. The coefficients are passed
//! as an array of second-order sections (SOS matrix) and each section is passed
//! to msp_biquad_df2_ext_q15 to filter the input.
//!
//! ![Example filter with three DF2 stages](images/biquad_cascade_df2_ext.svg)
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the cascaded biquad direct form 2 parameter
//!                    structure.
//! \param src Pointer to the source data to filter.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_biquad_cascade_df2_ext_q15(
                        const msp_biquad_cascade_df2_ext_q15_params *params,
                        const _q15 *src,
                        _q15 *dst);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //__DSPLIB_FILTER_H__
