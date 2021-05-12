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
#ifndef __DSPLIB_UTILITY_H__
#define __DSPLIB_UTILITY_H__

//******************************************************************************
//
//! \addtogroup dsplib_utility_api Utility
//! @{
//!
//! This file provides utility functions for operations such as data copy,
//! array fill and deinterleaving of channel data.
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
//! \ingroup dsplib_utility_api
//!
//! \brief Parameters for Q15 to IQ31 conversion.
//
//******************************************************************************
typedef struct msp_q15_to_iq31_params {
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
} msp_q15_to_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Parameters for IQ31 to Q15 conversion.
//
//******************************************************************************
typedef struct msp_iq31_to_q15_params {
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
} msp_iq31_to_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Parameters for creating Q15 complex vector from real and imaginary
//! vectors.
//
//******************************************************************************
typedef struct msp_cmplx_q15_params {
    //! Length of the source data.
    uint16_t length;
} msp_cmplx_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Parameters for creating IQ31 complex vector from real and imaginary
//! vectors.
//
//******************************************************************************
typedef struct msp_cmplx_iq31_params {
    //! Length of the source data.
    uint16_t length;
} msp_cmplx_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Parameters for Q15 vector copy function.
//
//******************************************************************************
typedef struct msp_copy_q15_params {
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
} msp_copy_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Parameters for IQ31 vector copy function.
//
//******************************************************************************
typedef struct msp_copy_iq31_params {
    //! Length of the source data.
    uint16_t length;
} msp_copy_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//!  \brief Parameters for Q15 real vector fill
//
//******************************************************************************
typedef struct msp_fill_q15_params {
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
    //! Scalar constant to fill the destination vector with.
    _q15 value;
} msp_fill_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//!  \brief Parameters for IQ31 real vector fill
//
//******************************************************************************
typedef struct msp_fill_iq31_params {
    //! Length of the source data.
    uint16_t length;
    //! Scalar constant to fill the destination vector with.
    _iq31 value;
} msp_fill_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//!  \brief Parameters for Q15 complex vector fill
//
//******************************************************************************
typedef struct msp_cmplx_fill_q15_params {
    //! Length of the source data, must be a multiple of two.
    uint16_t length;
    //! Real constant value to fill real indices with.
    _q15 realValue;
    //! Imaginary constant value to fill imaginary indices with.
    _q15 imagValue;
} msp_cmplx_fill_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//!  \brief Parameters for IQ31 complex vector fill
//
//******************************************************************************
typedef struct msp_cmplx_fill_iq31_params {
    //! Length of the source data.
    uint16_t length;
    //! Real constant value to fill real indices with.
    _iq31 realValue;
    //! Imaginary constant value to fill imaginary indices with.
    _iq31 imagValue;
} msp_cmplx_fill_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//!  \brief Parameters for Q15 vector interleave
//
//******************************************************************************
typedef struct msp_interleave_q15_params {
    //! Length of each channel, must be a multiple of two.
    uint16_t length;
    //! Specific zero-indexed channel to insert source into.
    uint16_t channel;
    //! Number of channels in destination vector.
    uint16_t numChannels;
} msp_interleave_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//!  \brief Parameters for IQ31 vector interleave
//
//******************************************************************************
typedef struct msp_interleave_iq31_params {
    //! Length of each channel.
    uint16_t length;
    //! Specific zero-indexed channel to insert source into.
    uint16_t channel;
    //! Number of channels in destination vector.
    uint16_t numChannels;
} msp_interleave_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//!  \brief Parameters for Q15 vector deinterleave
//
//******************************************************************************
typedef struct msp_deinterleave_q15_params {
    //! Length of each channel, must be a multiple of two.
    uint16_t length;
    //! Specific zero-indexed channel to pull from source.
    uint16_t channel;
    //! Number of channels being separated.
    uint16_t numChannels;
} msp_deinterleave_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//!  \brief Parameters for IQ31 vector deinterleave
//
//******************************************************************************
typedef struct msp_deinterleave_iq31_params {
    //! Length of each channel.
    uint16_t length;
    //! Specific zero-indexed channel to pull from source.
    uint16_t channel;
    //! Number of channels being separated.
    uint16_t numChannels;
} msp_deinterleave_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//!  \brief Parameters for Q15 sinusoid generation
//
//******************************************************************************
typedef struct msp_sinusoid_q15_params {
    //! Length of the generated sinusoid, must be a multiple of two.
    uint16_t length;
    //! Amplitude of the generated sinusoid.
    _q15 amplitude;
    //! Q15 constant equal to cos(2*pi*frequency/fs) where fs is the sampling 
    //! frequency and freq is the desired sinusoid frequency. For example a 200 
    //! Hz sinusoid with sampling frequency of 8192 would have a cosOmega 
    //! constant equal to cos(2*pi*200/8192) = _Q15(0.988258) or 0x7E7F in 
    //! hexadecimal.
    _q15 cosOmega;
    //! Q15 constant equal to sin(2*pi*frequency/fs) where fs is the sampling
    //! frequency and freq is the desired sinusoid frequency. For example a 200
    //! Hz sinusoid with sampling frequency of 8192 would have a sinOmega
    //! constant equal to sin(2*pi*200/8192) = _Q15(0.152797) or 0x138F in
    //! hexadecimal.
    _q15 sinOmega;
} msp_sinusoid_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Convert Q15 vector to IQ31 format.
//!
//! \par Details
//! Convert a Q15 data vector to a IQ31 format data vector of the same length.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the parameter structure.
//! \param src Pointer to the Q15 source vector.
//! \param dst Pointer to the IQ31 destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_q15_to_iq31(const msp_q15_to_iq31_params *params,
                                   const _q15 *src,
                                   _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Convert IQ31 vector to Q15 format.
//!
//! \par Details
//! Convert a IQ31 data vector to a Q15 format data vector of the same length.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the parameter structure.
//! \param src Pointer to the IQ31 source vector.
//! \param dst Pointer to the Q15 destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_iq31_to_q15(const msp_iq31_to_q15_params *params,
                                   const _iq31 *src,
                                   _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Create Q15 complex vector from real and imaginary vectors.
//!
//! \par Details
//! Create Q15 complex vector from real and imaginary vectorsof the same length.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the parameter structure.
//! \param real Pointer to the Q15 real vector.
//! \param imag Pointer to the Q15 imaginary vector.
//! \param dst Pointer to the Q15 complex destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_q15(const msp_cmplx_q15_params *params,
                                   const _q15 *real,
                                   const _q15 *imag,
                                   _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Create IQ31 complex vector from real and imaginary vectors.
//!
//! \par Details
//! Create IQ31 complex vector from real and imaginary vectorsof the same
//! length.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the parameter structure.
//! \param real Pointer to the IQ31 real vector.
//! \param imag Pointer to the IQ31 imaginary vector.
//! \param dst Pointer to the IQ31 complex destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_iq31(const msp_cmplx_iq31_params *params,
                                   const _iq31 *real,
                                   const _iq31 *imag,
                                   _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Real Q15 vector copy.
//!
//! \par Details
//! Copy of real Q15 source vector to destination vector.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector copy parameter structure.
//! \param src Pointer to the source data to copy.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_copy_q15(const msp_copy_q15_params *params,
                               const _q15 *src,
                               _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Real IQ31 vector copy.
//!
//! \par Details
//! Copy of real IQ31 source vector to destination vector.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector copy parameter structure.
//! \param src Pointer to the source data to copy.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_copy_iq31(const msp_copy_iq31_params *params,
                                const _iq31 *src,
                                _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Real Q15 vector fill with constant.
//!
//! \par Details
//! Fill of real Q15 destination vector with constant.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector copy parameter structure.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_fill_q15(const msp_fill_q15_params *params, _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Real IQ31 vector fill with constant.
//!
//! \par Details
//! Fill of real IQ31 destination vector with constant.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the vector copy parameter structure.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_fill_iq31(const msp_fill_iq31_params *params, _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Complex Q15 vector fill with constant.
//!
//! \par Details
//! Fill of complex Q15 destination vector with constant real and imaginary
//! components.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex fill parameter structure.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_fill_q15(const msp_cmplx_fill_q15_params *params,
                                     _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Complex IQ31 vector fill with constant.
//!
//! \par Details
//! Fill of complex IQ31 destination vector with constant real and imaginary
//! components.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex fill parameter structure.
//! \param dst Pointer to the destination vector.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_fill_iq31(const msp_cmplx_fill_iq31_params *params,
                                      _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Insert a single channel into a multiple-channel destination.
//!
//! \par Details
//! A single Q15 vector is inserted into multiple interleaved vectors. For
//! example, a interleave operation to insert a source vector x[] into channel 
//! one of a four channel destination vector y[] will yield the following data
//! result:
//!
//!     y[0], x[0], y[2], y[3], y[4], x[1], y[6], y[7] ...
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the interleave parameter structure.
//! \param src Pointer to the source data to interleave.
//! \param dst Pointer to the destination data to interleave into.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_interleave_q15(const msp_interleave_q15_params *params,
                                     const _q15 *src,
                                     _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Insert a single channel into a multiple-channel destination.
//!
//! \par Details
//! A single IQ31 vector is inserted into multiple interleaved vectors. For
//! example, a interleave operation to insert a source vector x[] into channel 
//! one of a four channel destination vector y[] will yield the following data
//! result:
//!
//!     y[0], x[0], y[2], y[3], y[4], x[1], y[6], y[7] ...
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the interleave parameter structure.
//! \param src Pointer to the source data to interleave.
//! \param dst Pointer to the destination data to interleave into.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_interleave_iq31(const msp_interleave_iq31_params *params,
                                     const _iq31 *src,
                                     _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Extract a single channel from multiple-channel source.
//!
//! \par Details
//! A single Q15 vector is extracted from multiple interleaved vectors. For
//! example, a deinterleave operation to extract channel one from a four channel
//! source vector x[] with channel length 4 will extract the following data:
//!
//!     x[1], x[5], x[9], x[13]
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the deinterleave parameter structure.
//! \param src Pointer to the source data to deinterleave.
//! \param dst Pointer to the destination data to store results.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_deinterleave_q15(
                                    const msp_deinterleave_q15_params *params,
                                    const _q15 *src,
                                    _q15 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Extract a single channel from multiple-channel source.
//!
//! \par Details
//! A single IQ31 vector is extracted from multiple interleaved vectors. For
//! example, a deinterleave operation to extract channel one from a four channel
//! source vector x[] with channel length 4 will extract the following data:
//!
//!     x[1], x[5], x[9], x[13]
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the deinterleave parameter structure.
//! \param src Pointer to the source data to deinterleave.
//! \param dst Pointer to the destination data to store results.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_deinterleave_iq31(
                                    const msp_deinterleave_iq31_params *params,
                                    const _iq31 *src,
                                    _iq31 *dst);

//******************************************************************************
//
//! \ingroup dsplib_utility_api
//!
//! \brief Generate a sinusoid with specified amplitude and frequency. 
//!
//! \par Details
//! Generate a sinusoid waveform with configured amplitude and frequency
//! parameters using DF1 biquad functions.
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the sinusoid parameter structure.
//! \param dst Pointer to the destination to store generated sinusoid.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_sinusoid_q15(const msp_sinusoid_q15_params *params,
                                   _q15 *dst);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //__DSPLIB_UTILITY_H__
