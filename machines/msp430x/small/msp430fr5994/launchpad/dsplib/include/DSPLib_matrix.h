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
#ifndef __DSPLIB_MATRIX_H__
#define __DSPLIB_MATRIX_H__

//******************************************************************************
//
//! \addtogroup dsplib_matrix_api Matrix
//! @{
//!
//! Functions for performing matrix operations on real data.
//!
//! \defgroup dsplib_matrix_real Real Matrix
//! Functions for performing matrix operations on real data.
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
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the matrix add function.
//
//******************************************************************************
typedef struct msp_matrix_add_q15_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
} msp_matrix_add_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the matrix add function.
//
//******************************************************************************
typedef struct msp_matrix_add_iq31_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
} msp_matrix_add_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the matrix subtract function.
//
//******************************************************************************
typedef struct msp_matrix_sub_q15_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
} msp_matrix_sub_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the matrix subtract function.
//
//******************************************************************************
typedef struct msp_matrix_sub_iq31_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
} msp_matrix_sub_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the matrix transpose function.
//
//******************************************************************************
typedef struct msp_matrix_trans_q15_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
} msp_matrix_trans_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the matrix transpose function.
//
//******************************************************************************
typedef struct msp_matrix_trans_iq31_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
} msp_matrix_trans_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix multiply function.
//
//******************************************************************************
typedef struct msp_matrix_mpy_q15_params {
    //! Number of rows in source A matrix, must be a multiple of two.
    uint16_t srcARows;
    //! Number of columns in source A matrix, must be a multiple of two.
    uint16_t srcACols;
    //! Number of rows in source B matrix, must be a multiple of two.
    uint16_t srcBRows;
    //! Number of columns in source B matrix, must be a multiple of two.
    uint16_t srcBCols;
} msp_matrix_mpy_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix multiply function.
//
//******************************************************************************
typedef struct msp_matrix_mpy_iq31_params {
    //! Number of rows in source A matrix, must be a multiple of two.
    uint16_t srcARows;
    //! Number of columns in source A matrix, must be a multiple of two.
    uint16_t srcACols;
    //! Number of rows in source B matrix, must be a multiple of two.
    uint16_t srcBRows;
    //! Number of columns in source B matrix, must be a multiple of two.
    uint16_t srcBCols;
} msp_matrix_mpy_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix negate function.
//
//******************************************************************************
typedef struct msp_matrix_neg_q15_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
} msp_matrix_neg_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix negate function.
//
//******************************************************************************
typedef struct msp_matrix_neg_iq31_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
} msp_matrix_neg_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix absolute value function.
//
//******************************************************************************
typedef struct msp_matrix_abs_q15_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
} msp_matrix_abs_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix absolute value function.
//
//******************************************************************************
typedef struct msp_matrix_abs_iq31_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
} msp_matrix_abs_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix offset function.
//
//******************************************************************************
typedef struct msp_matrix_offset_q15_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
    //! Q15 constant to add to the source matrix.
    int16_t offset;
} msp_matrix_offset_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix offset function.
//
//******************************************************************************
typedef struct msp_matrix_offset_iq31_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
    //! IQ31 constant to add to the source matrix.
    int32_t offset;
} msp_matrix_offset_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix scale function.
//
//******************************************************************************
typedef struct msp_matrix_scale_q15_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
    //! Integer amount to shift result matrix by, must be positive.
    uint8_t shift;
    //! Q15 constant multiplied with the source matrix.
    _q15 scale;
} msp_matrix_scale_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix scale function.
//
//******************************************************************************
typedef struct msp_matrix_scale_iq31_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
    //! Integer amount to shift result matrix by, must be positive.
    uint8_t shift;
    //! IQ31 constant multiplied with the source matrix.
    _iq31 scale;
} msp_matrix_scale_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix shift function.
//
//******************************************************************************
typedef struct msp_matrix_shift_q15_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
    //! Integer value to shift each matrix element by. Positive values will
    //! shift to the left and negative values will shift to the right.
    int8_t shift;
} msp_matrix_shift_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Parameter structure for the real matrix shift function.
//
//******************************************************************************
typedef struct msp_matrix_shift_iq31_params {
    //! Number of rows in the source matrices, must be a multiple of two.
    uint16_t rows;
    //! Number of columns in the source matrices, must be a multiple of two.
    uint16_t cols;
    //! Integer value to shift each matrix element by. Positive values will
    //! shift to the left and negative values will shift to the right.
    int8_t shift;
} msp_matrix_shift_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Addition of two real source matrices.
//!
//! \par Details
//! Element-wise Q15 addition of two real matrices with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = srcA + srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the matrix add parameter structure.
//! \param srcA Pointer to the first source data matrix.
//! \param srcB Pointer to the second source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_add_q15(const msp_matrix_add_q15_params *params,
                                     const _q15 *srcA,
                                     const _q15 *srcB,
                                     _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Addition of two real source matrices.
//!
//! \par Details
//! Element-wise IQ31 addition of two real matrices with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = srcA + srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the matrix add parameter structure.
//! \param srcA Pointer to the first source data matrix.
//! \param srcB Pointer to the second source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_add_iq31(const msp_matrix_add_iq31_params *params,
                                      const _iq31 *srcA,
                                      const _iq31 *srcB,
                                      _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Subtraction of two real source matrices.
//!
//! \par Details
//! Element-wise Q15 subtraction of two real matrices with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = srcA - srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the matrix subtraction parameter structure.
//! \param srcA Pointer to the first source data matrix.
//! \param srcB Pointer to the second source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_sub_q15(const msp_matrix_sub_q15_params *params,
                                     const _q15 *srcA,
                                     const _q15 *srcB,
                                     _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Subtraction of two real source matrices.
//!
//! \par Details
//! Element-wise IQ31 subtraction of two real matrices with saturation. This
//! function supports in-place operations.
//!
//! \par Pseudo code
//! `dst = srcA - srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the matrix subtraction parameter structure.
//! \param srcA Pointer to the first source data matrix.
//! \param srcB Pointer to the second source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_sub_iq31(const msp_matrix_sub_iq31_params *params,
                                      const _iq31 *srcA,
                                      const _iq31 *srcB,
                                      _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Multiplication of two real source matrices.
//!
//! \par Details
//! Element-wise Q15 multiplication of two real source matrices without
//! saturation. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = srcA * srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the matrix multiply parameter structure.
//! \param srcA Pointer to the first source data matrix.
//! \param srcB Pointer to the second source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_mpy_q15(const msp_matrix_mpy_q15_params *params,
                                     const _q15 *srcA,
                                     const _q15 *srcB,
                                     _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Multiplication of two real source matrices.
//!
//! \par Details
//! Element-wise IQ31 multiplication of two real source matrices without
//! saturation. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = srcA * srcB`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the matrix multiply parameter structure.
//! \param srcA Pointer to the first source data matrix.
//! \param srcB Pointer to the second source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_mpy_iq31(const msp_matrix_mpy_iq31_params *params,
                                      const _iq31 *srcA,
                                      const _iq31 *srcB,
                                      _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Transposition of a source matrix.
//!
//! \par Details
//! Transposition of the source matrix. The resulting matrix
//! will have same number of rows as the source does columns and
//! the same number of columns as the source has rows. This function
//! does not support in-place operations.
//!
//! \par Pseudo code
//! `dst = src'`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the matrix transpose parameter structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_trans_q15(const msp_matrix_trans_q15_params *params,
                                       const _q15 *src,
                                       _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Transposition of a source matrix.
//!
//! \par Details
//! Transposition of the source matrix. The resulting matrix
//! will have same number of rows as the source does columns and
//! the same number of columns as the source has rows. This function
//! does not support in-place operations.
//!
//! \par Pseudo code
//! `dst = src'`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the matrix transpose parameter structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_trans_iq31(const msp_matrix_trans_iq31_params *params,
                                        const _iq31 *src,
                                        _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Negation of a source matrix.
//!
//! \par Details
//! Element-wise Q15 multiplication by negative one with a real source matrix. 
//! This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = -src`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the matrix negate parameter structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_neg_q15(const msp_matrix_neg_q15_params *params,
                                     const _q15 *src,
                                     _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Negation of a source matrix.
//!
//! \par Details
//! Element-wise IQ31 multiplication by negative one with a real source matrix. 
//! This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = -src`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the matrix negate parameter structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_neg_iq31(const msp_matrix_neg_iq31_params *params,
                                      const _iq31 *src,
                                      _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Absolute value of a real source matrix.
//!
//! \par Details
//! Element-wise absolute value of a single source matrix.
//!
//! \par Pseudo code
//! `dst = |src|`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the matrix absolute value structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_abs_q15(const msp_matrix_abs_q15_params *params,
                                     const _q15 *src,
                                     _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Absolute value of a real source matrix.
//!
//! \par Details
//! Element-wise absolute value of a single source matrix.
//!
//! \par Pseudo code
//! `dst = |src|`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the matrix absolute value structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_abs_iq31(const msp_matrix_abs_iq31_params *params,
                                      const _iq31 *src,
                                      _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Constant offset of a real source matrix.
//!
//! \par Details
//! Element-wise Q15 addition with saturation of a single source matrix with a
//! Q15 constant. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src + offset`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the matrix offset structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_offset_q15(
                                    const msp_matrix_offset_q15_params *params,
                                    const _q15 *src,
                                    _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Constant offset of a real source matrix.
//!
//! \par Details
//! Element-wise IQ31 addition with saturation of a single source matrix with a
//! IQ31 constant. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src + offset`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the matrix offset structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_offset_iq31(
                                    const msp_matrix_offset_iq31_params *params,
                                    const _iq31 *src,
                                    _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Scale a real source matrix.
//!
//! \par Details
//! Element-wise scaling of a real matrix. Source data is multiplied by a IQ31
//! constant and then shifted left. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src * 2^SHIFT * SCALE`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the matrix scale structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_scale_q15(
                                    const msp_matrix_scale_q15_params *params,
                                    const _q15 *src,
                                    _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Scale a real source matrix.
//!
//! \par Details
//! Element-wise scaling of a real matrix. Source data is multiplied by a IQ31
//! constant and then shifted left. This function supports in-place operation.
//!
//! \par Pseudo code
//! `dst = src * 2^SHIFT * SCALE`
//!
//! \par LEA Support
//! This function is not currently supported by LEA.
//!
//! \param params Pointer to the matrix scale structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_scale_iq31(
                                    const msp_matrix_scale_iq31_params *params,
                                    const _iq31 *src,
                                    _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Bitwise shift of a real source matrix.
//!
//! \par Details
//! Element-wise bitwise shift of a real matrix to the left or right by a signed
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
//! \param params Pointer to the matrix shift structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_shift_q15(
                                    const msp_matrix_shift_q15_params *params,
                                    const _q15 *src,
                                    _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_matrix_real
//!
//! \brief Bitwise shift of a real source matrix.
//!
//! \par Details
//! Element-wise bitwise shift of a real matrix to the left or right by a signed
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
//! \param params Pointer to the matrix shift structure.
//! \param src Pointer to the source data matrix.
//! \param dst Pointer to the destination data matrix.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_matrix_shift_iq31(
                                    const msp_matrix_shift_iq31_params *params,
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

#endif //__DSPLIB_MATRIX_H__
