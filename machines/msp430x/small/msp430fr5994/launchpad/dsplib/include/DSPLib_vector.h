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
#ifndef __DSPLIB_VECTOR_H__
#define __DSPLIB_VECTOR_H__

//******************************************************************************
//
//! \addtogroup dsplib_vector_api Vector
//! @{
//!
//! Functions for performing real and complex vector operations.
//!
//! \defgroup dsplib_vector_real Real Vectors
//! Functions for performing vector operations on real data.
//!
//! \defgroup dsplib_vector_complex Complex Vectors
//! Functions for performing vector operations on complex data.
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
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 vector add functions.
//
//******************************************************************************
typedef struct msp_add_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_add_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 vector add functions.
//
//******************************************************************************
typedef struct msp_add_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_add_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 vector subtract functions.
//
//******************************************************************************
typedef struct msp_sub_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_sub_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 vector subtract functions.
//
//******************************************************************************
typedef struct msp_sub_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_sub_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 vector multiply functions.
//
//******************************************************************************
typedef struct msp_mpy_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_mpy_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 vector multiply functions.
//
//******************************************************************************
typedef struct msp_mpy_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_mpy_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 vector multiply and accumulate function.
//
//******************************************************************************
typedef struct msp_mac_q15_params {
    //! Length of source data, must be a multiple of two.
    uint16_t length;
} msp_mac_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 vector multiply and accumulate function.
//
//******************************************************************************
typedef struct msp_mac_iq31_params {
    //! Length of source data, must be a multiple of two.
    uint16_t length;
} msp_mac_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 vector negate function.
//
//******************************************************************************
typedef struct msp_neg_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_neg_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 vector negate function.
//
//******************************************************************************
typedef struct msp_neg_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_neg_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 vector absolute value function.
//
//******************************************************************************
typedef struct msp_abs_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_abs_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 vector absolute value function.
//
//******************************************************************************
typedef struct msp_abs_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_abs_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 vector offset function.
//
//******************************************************************************
typedef struct msp_offset_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
    //! Offset to add to each vector element.
    _q15 offset;
} msp_offset_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the vector offset function.
//
//******************************************************************************
typedef struct msp_offset_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
    //! Offset to add to each vector element.
    _iq31 offset;
} msp_offset_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 vector scale function.
//
//******************************************************************************
typedef struct msp_scale_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
    //! Q15 fractional value scale to multiply each vector element by.
    _q15 scale;
    //! Unsigned integer value to shift each vector result left by.
    uint8_t shift;
} msp_scale_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 vector scale function.
//
//******************************************************************************
typedef struct msp_scale_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
    //! q31 fractional value scale to multiply each vector element by.
    _iq31 scale;
    //! Unsigned integer value to shift each vector result left by.
    uint8_t shift;
} msp_scale_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 vector shift function.
//
//******************************************************************************
typedef struct msp_shift_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
    //! Integer value to shift each vector element by. Positive values will
    //! shift to the left and negative values will shift to the right.
    int8_t shift;
} msp_shift_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 vector shift function.
//
//******************************************************************************
typedef struct msp_shift_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
    //! Integer value to shift each vector element by. Positive values will
    //! shift to the left and negative values will shift to the right.
    int8_t shift;
} msp_shift_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 signed vector maximum function.
//
//******************************************************************************
typedef struct msp_max_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_max_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 signed vector maximum function.
//
//******************************************************************************
typedef struct msp_max_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_max_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 unsigned vector maximum function.
//
//******************************************************************************
typedef struct msp_max_uq15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_max_uq15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 unsigned vector maximum function.
//
//******************************************************************************
typedef struct msp_max_uq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_max_uq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 signed vector minimum function.
//
//******************************************************************************
typedef struct msp_min_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_min_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 signed vector minimum function.
//
//******************************************************************************
typedef struct msp_min_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_min_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the Q15 unsigned vector minimum function.
//
//******************************************************************************
typedef struct msp_min_uq15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_min_uq15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Parameter structure for the IQ31 unsigned vector minimum function.
//
//******************************************************************************
typedef struct msp_min_uq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_min_uq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the Q15 complex vector add functions.
//
//******************************************************************************
typedef struct msp_cmplx_add_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_add_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the IQ31 complex vector add functions.
//
//******************************************************************************
typedef struct msp_cmplx_add_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_add_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the Q15 complex vector subtract functions.
//
//******************************************************************************
typedef struct msp_cmplx_sub_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_sub_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the IQ31 complex vector subtract functions.
//
//******************************************************************************
typedef struct msp_cmplx_sub_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_sub_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the Q15 complex vector multiply functions.
//
//******************************************************************************
typedef struct msp_cmplx_mpy_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_mpy_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the IQ31 complex vector multiply functions.
//
//******************************************************************************
typedef struct msp_cmplx_mpy_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_mpy_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the Q15 complex vector multiply by real
//!        functions.
//
//******************************************************************************
typedef struct msp_cmplx_mpy_real_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_mpy_real_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the IQ31 complex vector multiply by real
//!        functions.
//
//******************************************************************************
typedef struct msp_cmplx_mpy_real_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_mpy_real_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the Q15 complex vector multiply and
//!        accumulate function.
//
//******************************************************************************
typedef struct msp_cmplx_mac_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_mac_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the IQ31 complex vector multiply and
//!        accumulate function.
//
//******************************************************************************
typedef struct msp_cmplx_mac_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_mac_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the Q15 complex vector conjugate function.
//
//******************************************************************************
typedef struct msp_cmplx_conj_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_conj_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the IQ31 complex vector conjugate function.
//
//******************************************************************************
typedef struct msp_cmplx_conj_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
} msp_cmplx_conj_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the Q15 complex vector scale by real
//!        function.
//
//******************************************************************************
typedef struct msp_cmplx_scale_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
    //! Q15 real fractional scale to multiply each complex vector element by.
    _q15 scale;
    //! Unsigned integer value to shift each complex vector result left by.
    uint8_t shift;
} msp_cmplx_scale_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the IQ31 complex vector scale by real
//!        function.
//
//******************************************************************************
typedef struct msp_cmplx_scale_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
    //! q31 real fractional scale to multiply each complex vector element by.
    _iq31 scale;
    //! Unsigned integer value to shift each complex vector result left by.
    uint8_t shift;
} msp_cmplx_scale_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the Q15 complex vector shift function.
//
//******************************************************************************
typedef struct msp_cmplx_shift_q15_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
    //! Integer value to shift each vector element by. Positive values will
    //! shift to the left and negative values will shift to the right.
    int8_t shift;
    //! Return complex conjugate result.
    bool conjugate;
} msp_cmplx_shift_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Parameter structure for the IQ31 complex vector shift function.
//
//******************************************************************************
typedef struct msp_cmplx_shift_iq31_params {
    //! Length of source and destination data, must be a multiple of two.
    uint16_t length;
    //! Integer value to shift each vector element by. Positive values will
    //! shift to the left and negative values will shift to the right.
    int8_t shift;
    //! Take complex conjugate of the result.
    bool conjugate;
} msp_cmplx_shift_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Addition of two real source vectors.
//!
//! \par Details
//! Element-wise Q15 addition of two real vectors with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = srcA + srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector add parameter structure.
//! \param srcA Pointer to the first source data vector.
//! \param srcB Pointer to the second source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_add_q15(const msp_add_q15_params *params,
                              const _q15 *srcA,
                              const _q15 *srcB,
                              _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Addition of two real source vectors.
//!
//! \par Details
//! Element-wise IQ31 addition of two real vectors with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = srcA + srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector add parameter structure.
//! \param srcA Pointer to the first source data vector.
//! \param srcB Pointer to the second source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_add_iq31(const msp_add_iq31_params *params,
                               const _iq31 *srcA,
                               const _iq31 *srcB,
                               _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Subtraction of two real source vectors.
//!
//! \par Details
//! Element-wise Q15 subtraction of two real vectors with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = srcA - srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector add parameter structure.
//! \param srcA Pointer to the first source data vector.
//! \param srcB Pointer to the second source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_sub_q15(const msp_sub_q15_params *params,
                              const _q15 *srcA,
                              const _q15 *srcB,
                              _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Subtraction of two real source vectors.
//!
//! \par Details
//! Element-wise IQ31 subtraction of two real vectors with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = srcA - srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector add parameter structure.
//! \param srcA Pointer to the first source data vector.
//! \param srcB Pointer to the second source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_sub_iq31(const msp_sub_iq31_params *params,
                               const _iq31 *srcA,
                               const _iq31 *srcB,
                               _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Multiplication of two real source vectors.
//!
//! \par Details
//! Element-wise Q15 multiplication of two real source vectors without
//! saturation. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = srcA .* srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector multiply parameter structure.
//! \param srcA Pointer to the first source data vector.
//! \param srcB Pointer to the second source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_mpy_q15(const msp_mpy_q15_params *params,
                              const _q15 *srcA,
                              const _q15 *srcB,
                              _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Multiplication of two real source vectors.
//!
//! \par Details
//! Element-wise IQ31 multiplication of two real source vectors without
//! saturation. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = srcA .* srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector multiply parameter structure.
//! \param srcA Pointer to the first source data vector.
//! \param srcB Pointer to the second source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_mpy_iq31(const msp_mpy_iq31_params *params,
                               const _iq31 *srcA,
                               const _iq31 *srcB,
                               _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Multiply and accumulate of real source vectors.
//!
//! \par Details
//! Element-wise Q15 multiplication of two real source vectors with accumulated
//! IQ31 result (dot product).
//!
//! \par Pseudo code
//! `result = sum(srcA .* srcB)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector multiply and accumulate parameter
//!               structure.
//! \param srcA Pointer to the first source data vector.
//! \param srcB Pointer to the second source data vector.
//! \param result Pointer to the 32-bit result data.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_mac_q15(const msp_mac_q15_params *params,
                              const _q15 *srcA,
                              const _q15 *srcB,
                              _iq31 *result);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Multiply and accumulate of real source vectors.
//!
//! \par Details
//! Element-wise IQ31 multiplication of two real source vectors with accumulated
//! IQ31 result (dot product).
//!
//! \par Pseudo code
//! `result = sum(srcA .* srcB)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector multiply and accumulate parameter
//!               structure.
//! \param srcA Pointer to the first source data vector.
//! \param srcB Pointer to the second source data vector.
//! \param result Pointer to the 32-bit result data.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_mac_iq31(const msp_mac_iq31_params *params,
                               const _iq31 *srcA,
                               const _iq31 *srcB,
                               _iq31 *result);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Negation of a source vector.
//!
//! \par Details
//! Element-wise Q15 multiplication by negative one with a real source vector. 
//! This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = -1 * src`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector negate parameter structure.
//! \param src Pointer to the source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_neg_q15(const msp_neg_q15_params *params,
                              const _q15 *src,
                              _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Negation of a source vector.
//!
//! \par Details
//! Element-wise IQ31 multiplication by negative one with a real source vector. 
//! This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = -1 * src`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector negate parameter structure.
//! \param src Pointer to the source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_neg_iq31(const msp_neg_iq31_params *params,
                               const _iq31 *src,
                               _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Absolute value of a real source vector.
//!
//! \par Details
//! Element-wise absolute value of a single source vector.
//!
//! \par Pseudo code
//! `dst = |src|`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the vector absolute value parameter structure.
//! \param src Pointer to the source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_abs_q15(const msp_abs_q15_params *params,
                              const _q15 *src,
                              _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Absolute value of a real source vector.
//!
//! \par Details
//! Element-wise absolute value of a single source vector.
//!
//! \par Pseudo code
//! `dst = |src|`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the vector absolute value parameter structure.
//! \param src Pointer to the source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_abs_iq31(const msp_abs_iq31_params *params,
                               const _iq31 *src,
                               _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Constant offset of a real source vector.
//!
//! \par Details
//! Element-wise Q15 addition with saturation of a single source vector with a
//! Q15 constant. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src + offset`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector offset parameter structure.
//! \param src Pointer to the source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_offset_q15(const msp_offset_q15_params *params,
                                 const _q15 *src,
                                 _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Constant offset of a real source vector.
//!
//! \par Details
//! Element-wise IQ31 addition with saturation of a single source vector with a
//! IQ31 constant. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src + offset`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector offset parameter structure.
//! \param src Pointer to the source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_offset_iq31(const msp_offset_iq31_params *params,
                                  const _iq31 *src,
                                  _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Scale a real source vector.
//!
//! \par Details
//! Element-wise scaling of a real vector. Source data is multiplied by a IQ31
//! constant and then shifted left. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src * 2^SHIFT * SCALE`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the vector scale structure. The bitwise shift
//!               value must be >=0.
//! \param src Pointer to the source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_scale_q15(const msp_scale_q15_params *params,
                                const _q15 *src,
                                _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Scale a real source vector.
//!
//! \par Details
//! Element-wise scaling of a real vector. Source data is multiplied by a IQ31
//! constant and then shifted left. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src * 2^SHIFT * SCALE`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the vector scale structure. The bitwise shift value
//!               must be >=0.
//! \param src Pointer to the source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_scale_iq31(const msp_scale_iq31_params *params,
                                 const _iq31 *src,
                                 _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Bitwise shift of a real source vector.
//!
//! \par Details
//! Element-wise bitwise shift of a real vector to the left or right by a signed
//! integer value. This function does not saturate and supports in-place
//! operation.
//!
//! \par Pseudo code
//! `dst = src * 2^SHIFT`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector shift parameter structure.
//! \param src Pointer to the source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_shift_q15(const msp_shift_q15_params *params,
                                const _q15 *src,
                                _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Bitwise shift of a real source vector.
//!
//! \par Details
//! Element-wise bitwise shift of a real vector to the left or right by a signed
//! integer value. This function does not saturate and supports in-place
//! operation.
//!
//! \par Pseudo code
//! `dst = src * 2^SHIFT`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector shift parameter structure.
//! \param src Pointer to the source data vector.
//! \param dst Pointer to the destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_shift_iq31(const msp_shift_iq31_params *params,
                                 const _iq31 *src,
                                 _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Signed maximum of a source vector.
//!
//! \par Details
//! This function returns the 16-bit signed maximum value and corresponding 
//! index of a single source vector.
//!
//! \par Pseudo code
//! `dst = MAX(src)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the signed vector maximum parameter structure.
//! \param src Pointer to the source data vector.
//! \param max Pointer to the maximum result vector of size one.
//! \param index Pointer to the index result vector of size one.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_max_q15(const msp_max_q15_params *params,
                              const _q15 *src,
                              _q15 *max,
                              uint16_t *index);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Signed maximum of a source vector.
//!
//! \par Details
//! This function returns the 32-bit signed maximum value and corresponding 
//! index of a single source vector.
//!
//! \par Pseudo code
//! `dst = MAX(src)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the signed vector maximum parameter structure.
//! \param src Pointer to the source data vector.
//! \param max Pointer to the maximum result vector of size one.
//! \param index Pointer to the index result vector of size one.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_max_iq31(const msp_max_iq31_params *params,
                               const _iq31 *src,
                               _iq31 *max,
                               uint16_t *index);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Unsigned maximum of a source vector.
//!
//! \par Details
//! This function returns the 16-bit unsigned maximum value and corresponding 
//! index of a single source vector.
//!
//! \par Pseudo code
//! `dst = MAX(src)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the unsigned vector maximum parameter structure.
//! \param src Pointer to the source data vector.
//! \param max Pointer to the maximum result vector of size one.
//! \param index Pointer to the index result vector of size one.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_max_uq15(const msp_max_uq15_params *params,
                               const _uq15 *src,
                               _uq15 *max,
                               uint16_t *index);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Unsigned maximum of a source vector.
//!
//! \par Details
//! This function returns the 32-bit unsigned maximum value and corresponding 
//! index of a single source vector.
//!
//! \par Pseudo code
//! `dst = MAX(src)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the unsigned vector maximum parameter structure.
//! \param src Pointer to the source data vector.
//! \param max Pointer to the maximum result vector of size one.
//! \param index Pointer to the index result vector of size one.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_max_uq31(const msp_max_uq31_params *params,
                               const _uq31 *src,
                               _uq31 *max,
                               uint16_t *index);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Signed minimum of a source vector.
//!
//! \par Details
//! This function returns the 16-bit signed minimum value and corresponding 
//! index of a single source vector.
//!
//! \par Pseudo code
//! `dst = MIN(src)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the signed vector minimum parameter structure.
//! \param src Pointer to the source data vector.
//! \param min Pointer to the minimum result vector of size one.
//! \param index Pointer to the index result vector of size one.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_min_q15(const msp_min_q15_params *params,
                              const _q15 *src,
                              _q15 *min,
                              uint16_t *index);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Signed minimum of a source vector.
//!
//! \par Details
//! This function returns the 32-bit signed minimum value and corresponding 
//! index of a single source vector.
//!
//! \par Pseudo code
//! `dst = MIN(src)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the signed vector minimum parameter structure.
//! \param src Pointer to the source data vector.
//! \param min Pointer to the minimum result vector of size one.
//! \param index Pointer to the index result vector of size one.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_min_iq31(const msp_min_iq31_params *params,
                               const _iq31 *src,
                               _iq31 *min,
                               uint16_t *index);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Unsigned minimum of a source vector.
//!
//! \par Details
//! This function returns the 16-bit unsigned minimum value and corresponding 
//! index of a single source vector.
//!
//! \par Pseudo code
//! `dst = MIN(src)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the unsigned vector minimum parameter structure.
//! \param src Pointer to the source data vector.
//! \param min Pointer to the minimum result vector of size one.
//! \param index Pointer to the index result vector of size one.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_min_uq15(const msp_min_uq15_params *params,
                               const _uq15 *src,
                               _uq15 *min,
                               uint16_t *index);

//******************************************************************************
//
//! \ingroup dsplib_vector_real
//!
//! \brief Unsigned minimum of a source vector.
//!
//! \par Details
//! This function returns the 32-bit unsigned minimum value and corresponding 
//! index of a single source vector.
//!
//! \par Pseudo code
//! `dst = MIN(src)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the unsigned vector minimum parameter structure.
//! \param src Pointer to the source data vector.
//! \param min Pointer to the minimum result vector of size one.
//! \param index Pointer to the index result vector of size one.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_min_uq31(const msp_min_uq31_params *params,
                               const _uq31 *src,
                               _uq31 *min,
                               uint16_t *index);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Addition of two complex source vectors.
//!
//! \par Details
//! Element-wise Q15 addition of two complex vectors with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = complex(srcA) + complex(srcB)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex vector add parameter structure.
//! \param srcA Pointer to the first complex source data vector.
//! \param srcB Pointer to the second complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_add_q15(const msp_cmplx_add_q15_params *params,
                                    const _q15 *srcA,
                                    const _q15 *srcB,
                                    _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Addition of two complex source vectors.
//!
//! \par Details
//! Element-wise IQ31 addition of two complex vectors with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = complex(srcA) + complex(srcB)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex vector add parameter structure.
//! \param srcA Pointer to the first complex source data vector.
//! \param srcB Pointer to the second complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_add_iq31(const msp_cmplx_add_iq31_params *params,
                                     const _iq31 *srcA,
                                     const _iq31 *srcB,
                                     _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Subtraction of two complex source vectors.
//!
//! \par Details
//! Element-wise Q15 subtraction of two complex vectors with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = complex(srcA) - complex(srcB)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex vector subtraction parameter structure.
//! \param srcA Pointer to the first complex source data vector.
//! \param srcB Pointer to the second complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_sub_q15(const msp_cmplx_sub_q15_params *params,
                                    const _q15 *srcA,
                                    const _q15 *srcB,
                                    _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Subtraction of two complex source vectors.
//!
//! \par Details
//! Element-wise IQ31 subtraction of two complex vectors with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = complex(srcA) - complex(srcB)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex vector subtraction parameter structure.
//! \param srcA Pointer to the first complex source data vector.
//! \param srcB Pointer to the second complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_sub_iq31(const msp_cmplx_sub_iq31_params *params,
                                     const _iq31 *srcA,
                                     const _iq31 *srcB,
                                     _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Multiplication of two complex source vectors.
//!
//! \par Details
//! Element-wise Q15 multiply of two complex vectors without saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = complex(srcA) .* complex(srcB)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex vector multiply parameter structure.
//! \param srcA Pointer to the first complex source data vector.
//! \param srcB Pointer to the second complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_mpy_q15(const msp_cmplx_mpy_q15_params *params,
                                    const _q15 *srcA,
                                    const _q15 *srcB,
                                    _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Multiplication of complex source vectors.
//!
//! \par Details
//! Element-wise IQ31 multiply of two complex vectors without saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = complex(srcA) .* complex(srcB)`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the complex vector multiply parameter structure.
//! \param srcA Pointer to the first complex source data vector.
//! \param srcB Pointer to the second complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_mpy_iq31(const msp_cmplx_mpy_iq31_params *params,
                                     const _iq31 *srcA,
                                     const _iq31 *srcB,
                                     _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Multiplication of complex source vector by real source vector.
//!
//! \par Details
//! Element-wise Q15 multiply of a complex vector by real vector without
//! saturation. The length of complex and real vectors should be equal, that is 
//! the complex source vector contains twice the allocated bytes for data 
//! storage. This function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = real(srcA) .* real(srcB) + imag(srcB)`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the complex vector multiply parameter structure.
//! \param srcCmplx Pointer to the complex source data vector.
//! \param srcReal Pointer to the real source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_mpy_real_q15(
                                const msp_cmplx_mpy_real_q15_params *params,
                                const _q15 *srcCmplx,
                                const _q15 *srcReal,
                                _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Multiplication of complex source vector by real source vector.
//!
//! \par Details
//! Element-wise IQ31 multiply of a complex vector by real vector without
//! saturation. The length of complex and real vectors should be equal, that is 
//! the complex source vector contains twice the allocated bytes for data 
//! storage. This function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = real(srcA) .* real(srcB) + imag(srcB)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex vector multiply parameter structure.
//! \param srcCmplx Pointer to the complex source data vector.
//! \param srcReal Pointer to the real source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_mpy_real_iq31(
                                const msp_cmplx_mpy_real_iq31_params *params,
                                const _iq31 *srcCmplx,
                                const _iq31 *srcReal,
                                _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Multiply and accumulate of complex source vectors.
//!
//! \par Details
//! Element-wise Q15 multiplication of two complex source vectors with
//! accumulated result (dot product).
//!
//! \par Pseudo code
//! `result = sum(complex(srcA) .* complex(srcB))`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex vector multiply and accumulate
//!               parameter structure.
//! \param srcA Pointer to the first complex source data vector.
//! \param srcB Pointer to the second complex source data vector.
//! \param result Pointer to the 32-bit result data.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_mac_q15(const msp_cmplx_mac_q15_params *params,
                                    const _q15 *srcA,
                                    const _q15 *srcB,
                                    _iq31 *result);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Multiply and accumulate of complex source vectors.
//!
//! \par Details
//! Element-wise IQ31 multiplication of two complex source vectors with
//! accumulated result (dot product).
//!
//! \par Pseudo code
//! `result = sum(complex(srcA) .* complex(srcB))`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the complex vector multiply and accumulate
//!               parameter structure.
//! \param srcA Pointer to the first complex source data vector.
//! \param srcB Pointer to the second complex source data vector.
//! \param result Pointer to the 32-bit result data.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_mac_iq31(const msp_cmplx_mac_iq31_params *params,
                                     const _iq31 *srcA,
                                     const _iq31 *srcB,
                                     _iq31 *result);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Conjugation of a source vector.
//!
//! \par Details
//! Conjugation of each element in a complex vector. This function supports 
//! in-place operations.
//!
//! \par Pseudo code
//! `dst = conj(src)`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the complex vector conjugate parameter structure.
//! \param src Pointer to the complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_conj_q15(const msp_cmplx_conj_q15_params *params,
                                     const _q15 *src,
                                     _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Conjugation of a source vector.
//!
//! \par Details
//! Conjugation of each element in a complex vector. This function supports 
//! in-place operations.
//!
//! \par Pseudo code
//! `dst = conj(src)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex vector conjugate parameter structure.
//! \param src Pointer to the complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_conj_iq31(const msp_cmplx_conj_iq31_params *params,
                                      const _iq31 *src,
                                      _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Scale a complex source vector.
//!
//! \par Details
//! Element-wise scaling of both imaginary and real values of a complex vector.
//! Source data is multiplied by a IQ31 constant and then shifted left. This 
//! function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src * 2^SHIFT * SCALE`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the complex vector scale structure.
//! \param src Pointer to the complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_scale_q15(const msp_cmplx_scale_q15_params *params,
                                      const _q15 *src,
                                      _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Scale a complex source vector.
//!
//! \par Details
//! Element-wise scaling of both imaginary and real values of a complex vector.
//! Source data is multiplied by a IQ31 constant and then shifted left. This 
//! function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src * 2^SHIFT * SCALE`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the complex vector scale structure.
//! \param src Pointer to the complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_scale_iq31(const msp_cmplx_scale_iq31_params *params,
                                       const _iq31 *src,
                                       _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Bitwise shift of a complex source vector.
//!
//! \par Details
//! Element-wise bitwise shift of both imaginary and real elements of a complex 
//! vector to the left or right by a signed integer value. This function does
//! not saturate and supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src * 2^SHIFT`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex vector shift parameter structure.
//! \param src Pointer to the complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_shift_q15(const msp_cmplx_shift_q15_params *params,
                                      const _q15 *src,
                                      _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_vector_complex
//!
//! \brief Bitwise shift of a complex source vector.
//!
//! \par Details
//! Element-wise bitwise shift of both imaginary and real elements of a complex 
//! vector to the left or right by a signed int. This function does not saturate
//! and supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src * 2^SHIFT`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex vector shift parameter structure.
//! \param src Pointer to the complex source data vector.
//! \param dst Pointer to the complex destination data vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_shift_iq31(const msp_cmplx_shift_iq31_params *params,
                                       const _iq31 *src,
                                       _iq31 *dst);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //__DSPLIB_VECTOR_H__
