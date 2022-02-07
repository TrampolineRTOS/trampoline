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
#ifndef __DSPLIB_TRANSFORM_H__
#define __DSPLIB_TRANSFORM_H__

//******************************************************************************
//
//! \addtogroup dsplib_transform_api Transform
//! @{
//!
//! Functions for performing Discreet Fourier Transforms (DFT), commonly
//! referred to as Fast Fourier Transforms (FFT), on MSP embedded devices. 
//! Functions for both real and complex inputs, 16-bit and 32-bit data types as
//! well as forward and inverse transforms are included.
//!
//! \defgroup dsplib_transform_real Real FFT
//! Functions for performing forward and inverse FFT of real 16-bit and 32-bit
//! input data.
//!
//! \defgroup dsplib_transform_complex Complex FFT
//! Functions for performing forward and inverse FFT of complex 16-bit and 
//! 32-bit input data.
//!
//! \defgroup dsplib_transform_tables Tables
//! Constant lookup tables used for real and complex FFT functions. Pointers to
//! these tables must be set in the FFT parameter blocks with the exception of
//! when LEA is used to accelerate the FFT functions. The size of table used
//! depends on the maximum FFT size required by the application.
//!
//! \defgroup dsplib_transform_support Support
//! Support functions used for real and complex FFT functions. These functions
//! do not need to be called outside of DSPLib.
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
//! \ingroup dsplib_transform_support
//!
//! \brief Calculate the alignment for a 16-bit real FFT from length
//! parameter.
//
//******************************************************************************
#define MSP_ALIGN_FFT_Q15(n)        (n*2)

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Calculate the alignment for a 32-bit real FFT from length
//! parameter.
//
//******************************************************************************
#define MSP_ALIGN_FFT_IQ31(n)       (n*4)

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Calculate the alignment for a 16-bit complex FFT from length
//! parameter.
//
//******************************************************************************
#define MSP_ALIGN_CMPLX_FFT_Q15(n)  (n*4)

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Calculate the alignment for a 32-bit complex FFT from length
//! parameter.
//
//******************************************************************************
#define MSP_ALIGN_CMPLX_FFT_IQ31(n) (n*8)

#if defined(MSP_USE_LEA)

// Tables located in LEA ROM, define as null pointers
#define msp_cmplx_bitrev_table_ui8          0
#define msp_cmplx_twiddle_table_16_q15      0
#define msp_cmplx_twiddle_table_32_q15      0
#define msp_cmplx_twiddle_table_64_q15      0
#define msp_cmplx_twiddle_table_128_q15     0
#define msp_cmplx_twiddle_table_256_q15     0
#define msp_cmplx_twiddle_table_512_q15     0
#define msp_cmplx_twiddle_table_1024_q15    0
#define msp_cmplx_twiddle_table_2048_q15    0
#define msp_cmplx_twiddle_table_4096_q15    0

#else //MSP_USE_LEA

//******************************************************************************
//
//! \ingroup dsplib_transform_tables
//!
//! \brief Bit reversal lookup table.
//
//******************************************************************************
extern const uint8_t msp_cmplx_bitrev_table_ui8[256];

//******************************************************************************
//
//! \ingroup dsplib_transform_tables
//!
//! \brief Twiddle factor table for FFT of size 16.
//
//******************************************************************************
extern const _q15 msp_cmplx_twiddle_table_16_q15[DSPLIB_TABLE_OFFSET+16];

//******************************************************************************
//
//! \ingroup dsplib_transform_tables
//!
//! \brief Twiddle factor table for FFT of size 32.
//
//******************************************************************************
extern const _q15 msp_cmplx_twiddle_table_32_q15[DSPLIB_TABLE_OFFSET+32];

//******************************************************************************
//
//! \ingroup dsplib_transform_tables
//!
//! \brief Twiddle factor table for FFT of size 64.
//
//******************************************************************************
extern const _q15 msp_cmplx_twiddle_table_64_q15[DSPLIB_TABLE_OFFSET+64];

//******************************************************************************
//
//! \ingroup dsplib_transform_tables
//!
//! \brief Twiddle factor table for FFT of size 128.
//
//******************************************************************************
extern const _q15 msp_cmplx_twiddle_table_128_q15[DSPLIB_TABLE_OFFSET+128];

//******************************************************************************
//
//! \ingroup dsplib_transform_tables
//!
//! \brief Twiddle factor table for FFT of size 256.
//
//******************************************************************************
extern const _q15 msp_cmplx_twiddle_table_256_q15[DSPLIB_TABLE_OFFSET+256];

//******************************************************************************
//
//! \ingroup dsplib_transform_tables
//!
//! \brief Twiddle factor table for FFT of size 512.
//
//******************************************************************************
extern const _q15 msp_cmplx_twiddle_table_512_q15[DSPLIB_TABLE_OFFSET+512];

//******************************************************************************
//
//! \ingroup dsplib_transform_tables
//!
//! \brief Twiddle factor table for FFT of size 1024.
//
//******************************************************************************
extern const _q15 msp_cmplx_twiddle_table_1024_q15[DSPLIB_TABLE_OFFSET+1024];

//******************************************************************************
//
//! \ingroup dsplib_transform_tables
//!
//! \brief Twiddle factor table for FFT of size 2048.
//
//******************************************************************************
extern const _q15 msp_cmplx_twiddle_table_2048_q15[DSPLIB_TABLE_OFFSET+2048];

//******************************************************************************
//
//! \ingroup dsplib_transform_tables
//!
//! \brief Twiddle factor table for FFT of size 4096.
//
//******************************************************************************
extern const _q15 msp_cmplx_twiddle_table_4096_q15[DSPLIB_TABLE_OFFSET+4096];

#endif //MSP_USE_LEA

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Parameter structure for Q15 complex bit-reversal.
//
//******************************************************************************
typedef struct msp_cmplx_bitrev_q15_params {
    //! \details
    //! Length of the source data, must be a power of two.
    uint16_t length;
} msp_cmplx_bitrev_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Parameter structure for IQ31 complex bit-reversal.
//
//******************************************************************************
typedef struct msp_cmplx_bitrev_iq31_params {
    //! \details
    //! Length of the source data, must be a power of two.
    uint16_t length;
} msp_cmplx_bitrev_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Parameter structure for Q15 split operation.
//
//******************************************************************************
typedef struct msp_split_q15_params {
    //! \details
    //! Length of the source data, must be a power of two.
    uint16_t length;
    //! \details
    //! Pointer to the twiddle coefficient table with size greater than or equal
    //! to the source length. When using LEA this can be a NULL pointer.
    const _q15 *twiddleTable;
} msp_split_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Parameter structure for IQ31 split operation.
//
//******************************************************************************
typedef struct msp_split_iq31_params {
    //! \details
    //! Length of the source data, must be a power of two.
    uint16_t length;
    //! \details
    //! Pointer to the twiddle coefficient table with size greater than or equal
    //! to the source length. When using LEA this can be a NULL pointer.
    const _q15 *twiddleTable;
} msp_split_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_transform_real
//!
//! \brief Parameter structure for Q15 real FFT functions.
//
//******************************************************************************
typedef struct msp_fft_q15_params {
    //! \details
    //! Length of the source data, must be a power of two.
    uint16_t length;
    //! \details
    //! Perform bit-reversal of the input before transformation. This step is
    //! mandatory, this parameter only exists for applications that might handle
    //! bit reversal when storing the data samples to memory. If not this needs
    //! to be set to true.
    bool bitReverse;
    //! \details
    //! Pointer to the twiddle coefficient table with size greater than or equal
    //! to the source length. When using LEA this can be a NULL pointer.
    const _q15 *twiddleTable;
} msp_fft_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_transform_real
//!
//! \brief Parameter structure for IQ31 real FFT functions.
//
//******************************************************************************
typedef struct msp_fft_iq31_params {
    //! \details
    //! Length of the source data, must be a power of two.
    uint16_t length;
    //! \details
    //! Perform bit-reversal of the input before transformation. This step is
    //! mandatory, this parameter only exists for applications that might handle
    //! bit reversal when storing the data samples to memory. If not this needs
    //! to be set to true.
    bool bitReverse;
    //! \details
    //! Pointer to the twiddle coefficient table with size greater than or equal
    //! to the source length. When using LEA this can be a NULL pointer.
    const _q15 *twiddleTable;
} msp_fft_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_transform_complex
//!
//! \brief Parameter structure for Q15 complex FFT functions.
//
//******************************************************************************
typedef struct msp_cmplx_fft_q15_params {
    //! \details
    //! Length of the source data, must be a power of two.
    uint16_t length;
    //! \details
    //! Perform bit-reversal of the input before transformation. This step is
    //! mandatory, this parameter only exists for applications that might handle
    //! bit reversal when storing the data samples to memory. If not this needs
    //! to be set to true.
    bool bitReverse;
    //! \details
    //! Pointer to the twiddle coefficient table with size greater than or equal
    //! to the source length. When using LEA this can be a NULL pointer.
    const _q15 *twiddleTable;
} msp_cmplx_fft_q15_params;

//******************************************************************************
//
//! \ingroup dsplib_transform_complex
//!
//! \brief Parameter structure for IQ31 complex FFT functions.
//
//******************************************************************************
typedef struct msp_cmplx_fft_iq31_params {
    //! \details
    //! Length of the source data, must be a power of two.
    uint16_t length;
    //! \details
    //! Perform bit-reversal of the input before transformation. This step is
    //! mandatory, this parameter only exists for applications that might handle
    //! bit reversal when storing the data samples to memory. If not this needs
    //! to be set to true.
    bool bitReverse;
    //! \details
    //! Pointer to the twiddle coefficient table with size greater than or equal
    //! to the source length. When using LEA this can be a NULL pointer.
    const _q15 *twiddleTable;
} msp_cmplx_fft_iq31_params;

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Complex bit-reversal function.
//!
//! \par Details
//! Inputs to the real and complex fft functions need to be in bit reversed
//! order before the result can be computed. The DSPLib fft functions contain
//! a parameter to perform the bit reversal and this API does not need to be
//! invoked directly. Alternatively the application can store input in bit
//! reversed order and skip this step although it may be more efficient to
//! store in linear order using pointer increment or DMA copy and performing
//! the bit reversal all at once.
//!
//! \par Pseudo code
//! `y = bitrevorder(x)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex bit-reversal parameter structure.
//! \param src Pointer to the complex data array to perform the bit-reversal on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_bitrev_q15(
                                    const msp_cmplx_bitrev_q15_params *params,
                                    int16_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Complex bit-reversal function.
//!
//! \par Details
//! Inputs to the real and complex fft functions need to be in bit reversed
//! order before the result can be computed. The DSPLib fft functions contain
//! a parameter to perform the bit reversal and this API does not need to be
//! invoked directly. Alternatively the application can store input in bit
//! reversed order and skip this step although it may be more efficient to
//! store in linear order using pointer increment or DMA copy and performing
//! the bit reversal all at once.
//!
//! \par Pseudo code
//! `y = bitrevorder(x)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with 4-byte alignment.
//!
//! \param params Pointer to the complex bit-reversal parameter structure.
//! \param src Pointer to the complex data array to perform the bit-reversal on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_bitrev_iq31(
                                    const msp_cmplx_bitrev_iq31_params *params,
                                    int32_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Split operation for performing the final step of a real FFT.
//!
//! \par Details
//! Performs the final stage of a discreet Fourier transform (DFT) of real
//! inputs. First a complex FFT of size length/2 with must be performed before
//! this function can be called. The DSPLib real fft functions invoke this
//! function directly and this API does not need to be called directly from the
//! application.
//!
//! \par Pseudo code
//! `G(k) = 0.5*(X(k) + X*(N-k)) - 0.5*j*(e^-j2*pi*k/2N)*(X(k) - X*(N-k))`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to twice the data length (e.g.
//! a 256-point real FFT requires 512-byte alignment). When allocating data the
//! MSP\_ALIGN\_FFT\_Q15 macro can be used to calculate correct alignment. The
//! twiddle table pointer parameter is not used with LEA and can be null or
//! uninitialized.
//!
//! \param params Pointer to the split parameter structure.
//! \param src Pointer to the data array to perform the split operation on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_split_q15(const msp_split_q15_params *params,
                                int16_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_support
//!
//! \brief Split operation for performing the final step of a real FFT.
//!
//! \par Details
//! Performs the final stage of a discreet Fourier transform (DFT) of real
//! inputs. First a complex FFT of size length/2 with must be performed before
//! this function can be called. The DSPLib real fft functions invoke this
//! function directly and this API does not need to be called directly from the
//! application.
//!
//! \par Pseudo code
//! `G(k) = 0.5*(X(k) + X*(N-k)) - 0.5*j*(e^-j2*pi*k/2N)*(X(k) - X*(N-k))`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to four times the data length (e.g.
//! a 256-point real FFT requires 1024-byte alignment). When allocating data the
//! MSP\_ALIGN\_FFT\_IQ31 macro can be used to calculate correct alignment. The
//! twiddle table pointer parameter is not used with LEA and can be null or
//! uninitialized.
//!
//! \param params Pointer to the split parameter structure.
//! \param src Pointer to the data array to perform the split operation on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_split_iq31(const msp_split_iq31_params *params,
                                 int32_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_real
//!
//! \brief Real forward FFT function with auto-scaling.
//!
//! \par Details
//! Computes the forward discreet Fourier transform (DFT) of 16-bit real inputs.
//! If the inputs are not already in bit reversed order the bit reversal 
//! parameter must be set. The output is monitored for overflow and scaled by a 
//! factor of two when an overflow risk is detected. The shift parameter
//! contains the number of bit shifts that were applied to the output.
//!
//! \par
//! This functions requires half the data storage and consumes roughly half the
//! cycles and energy as running a complex FFT of the same length. When
//! transforming purely real inputs, such as samples from an ADC or analog
//! sensor, it is recommended to use the real FFT functions.
//!
//! \par Pseudo code
//! `y = fft(real(x)) * 2^-shift`
//!
//! \par Scaling
//! Scaling is applied as needed to prevent saturation of the output. The scale
//! factor that was applied to the output is returned in the shift parameter and
//! can be used to calculate the result by applying the following function.
//!
//! \par
//! `result = result * 2^shift`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to twice the data length (e.g.
//! a 256-point real FFT requires 512-byte alignment). When allocating data the
//! MSP\_ALIGN\_FFT\_Q15 macro can be used to calculate correct alignment. The
//! twiddle table pointer parameter is not used with LEA and can be null or
//! uninitialized.
//!
//! \param params Pointer to the real FFT parameter structure.
//! \param src Pointer to the real data array to perform the FFT on.
//! \param shift Auto-scaling shift that was applied to the output.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_fft_auto_q15(const msp_fft_q15_params *params,
                                   int16_t *src,
                                   uint16_t *shift);

//******************************************************************************
//
//! \ingroup dsplib_transform_real
//!
//! \brief Real forward FFT function with fixed scaling by two at each stage.
//!
//! \par Details
//! Computes the forward discreet Fourier transform (DFT) of 16-bit real inputs. 
//! If the inputs are not already in bit reversed order the bit reversal
//! parameter must be set. The output is scaled by a factor of two for each
//! stage of the DFT.
//! 
//! \par
//! This functions requires half the data storage and consumes roughly half the
//! cycles and energy as running a complex FFT of the same length. When
//! transforming purely real inputs, such as samples from an ADC or analog
//! sensor, it is recommended to use the real FFT functions.
//!
//! \par Pseudo code
//! `y = fft(real(x)) ./ (N/2)`
//!
//! \par Scaling
//! Each stage of the real FFT, with the exception of the final split stage,
//! scales the result by a factor of 0.5. The output format can either be
//! interpreted as the same type with (N/2) scaling or a different fixed point
//! data type. This can be helpful when using the IQmathLib to process the
//! results of the FFT, such as computing the magnitude or phase angle of the
//! complex result.
//! 
//! \par
//! <center>
//! | Length   | Input Type | Result Type |
//! | -------- |:----------:| :----------:|
//! | **16**   | _q15       | _q12        |
//! | **32**   | _q15       | _q11        |
//! | **64**   | _q15       | _q10        |
//! | **128**  | _q15       | _q9         |
//! | **256**  | _q15       | _q8         |
//! | **512**  | _q15       | _q7         |
//! | **1024** | _q15       | _q6         |
//! | **2048** | _q15       | _q5         |
//! | **4096** | _q15       | _q4         |
//! </center>
//!
//! \par
//! The following table lists the applied scaling factor and resulting data type
//! when the input is a 16-bit integer. 
//!
//! \par
//! <center>
//! | Length   | Input Type | Result Type              |
//! | -------- |:----------:| :-----------------------:|
//! | **16**   | int16_t    | (int16_t)(result / 8)    |
//! | **32**   | int16_t    | (int16_t)(result / 16)   |
//! | **64**   | int16_t    | (int16_t)(result / 32)   |
//! | **128**  | int16_t    | (int16_t)(result / 64)   |
//! | **256**  | int16_t    | (int16_t)(result / 128)  |
//! | **512**  | int16_t    | (int16_t)(result / 256)  |
//! | **1024** | int16_t    | (int16_t)(result / 512)  |
//! | **2048** | int16_t    | (int16_t)(result / 1024) |
//! | **4096** | int16_t    | (int16_t)(result / 2048) |
//! </center>
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to twice the data length (e.g.
//! a 256-point real FFT requires 512-byte alignment). When allocating data the
//! MSP\_ALIGN\_FFT\_Q15 macro can be used to calculate correct alignment. The
//! twiddle table pointer parameter is not used with LEA and can be null or
//! uninitialized.
//!
//! \param params Pointer to the real FFT parameter structure.
//! \param src Pointer to the real data array to perform the FFT on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_fft_fixed_q15(const msp_fft_q15_params *params,
                                    int16_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_real
//!
//! \brief Real forward FFT function without scaling.
//!
//! \par Details
//! Computes the forward discreet Fourier transform (DFT) of 32-bit real inputs. 
//! If the inputs are not already in bit reversed order the bit reversal
//! parameter must be set. The output is not scaled.
//!
//! \par
//! This functions requires half the data storage and consumes roughly half the
//! cycles and energy as running a complex FFT of the same length. When
//! transforming purely real inputs, such as samples from an ADC or analog
//! sensor, it is recommended to use the real FFT functions.
//!
//! \par Pseudo code
//! `y = fft(real(x))`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to four times the data length (e.g.
//! a 256-point real FFT requires 1024-byte alignment). When allocating data the
//! MSP\_ALIGN\_FFT\_IQ31 macro can be used to calculate correct alignment. The
//! twiddle table pointer parameter is not used with LEA and can be null or
//! uninitialized.
//!
//! \param params Pointer to the real FFT parameter structure.
//! \param src Pointer to the real data array to perform the FFT on.
//!
//! \return Status of the operation.
//
//******************************************************************************

extern msp_status msp_fft_iq31(const msp_fft_iq31_params *params,
                               int32_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_real
//!
//! \brief Real result inverse FFT function with auto-scaling.
//!
//! \par Details
//! Computes the inverse discreet Fourier transform (DFT) of 16-bit complex
//! inputs with real result. If the inputs are not already in bit reversed order
//! the bit reversal parameter must be set. Automatic scaling is performed such
//! that this is the direct inverse of the forward FFT with auto scaling.
//!
//! \par
//! This functions uses half the data storage and consumes roughly half the
//! cycles and energy as running a complex IFFT of the same length. When
//! transforming purely real inputs, such as samples from an ADC or analog
//! sensor, it is recommended to use the real FFT functions.
//!
//! \par Pseudo code
//! `y = (real(ifft(x)) * 2^shift) ./ (N/2)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to twice the data length (e.g.
//! a 256-point real FFT requires 512-byte alignment). When allocating data the
//! MSP\_ALIGN\_FFT\_Q15 macro can be used to calculate correct alignment. The
//! twiddle table pointer parameter is not used with LEA and can be null or
//! uninitialized.
//!
//! \param params Pointer to the real FFT parameter structure.
//! \param src Pointer to the real data array to perform the FFT on.
//! \param shift Auto-scaling shift that was applied to the forward FFT.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_ifft_auto_q15(const msp_fft_q15_params *params,
                                    int16_t *src,
                                    uint16_t shift);

//******************************************************************************
//
//! \ingroup dsplib_transform_real
//!
//! \brief Real result inverse FFT function with fixed scaling by two at each
//!        stage.
//!
//! \par Details
//! Computes the inverse discreet Fourier transform (DFT) of 16-bit complex
//! inputs with real result. If the inputs are not already in bit reversed order
//! the bit reversal parameter must be set. Fixed scaling is performed such
//! that this is the direct inverse of the forward FFT with fixed scaling.
//!
//! \par
//! This functions uses half the data storage and consumes roughly half the
//! cycles and energy as running a complex IFFT of the same length. When
//! transforming purely real inputs, such as samples from an ADC or analog
//! sensor, it is recommended to use the real FFT functions.
//!
//! \par Pseudo code
//! `y = real(ifft(x))`
//!
//! \par Scaling
//! This function is the direct inverse of the forward real FFT with fixed 
//! scaling. The following fixed point input types will all result in Q15
//! results.
//! 
//! \par
//! <center>
//! | Length   | Input Type | Result Type |
//! | -------- |:----------:| :----------:|
//! | **16**   | _q12       | _q15        |
//! | **32**   | _q11       | _q15        |
//! | **64**   | _q10       | _q15        |
//! | **128**  | _q9        | _q15        |
//! | **256**  | _q8        | _q15        |
//! | **512**  | _q7        | _q15        |
//! | **1024** | _q6        | _q15        |
//! | **2048** | _q5        | _q15        |
//! | **4096** | _q4        | _q15        |
//! </center>
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to twice the data length (e.g.
//! a 256-point real FFT requires 512-byte alignment). When allocating data the
//! MSP\_ALIGN\_FFT\_Q15 macro can be used to calculate correct alignment. The
//! twiddle table pointer parameter is not used with LEA and can be null or
//! uninitialized.
//!
//! \param params Pointer to the real FFT parameter structure.
//! \param src Pointer to the real data array to perform the FFT on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_ifft_fixed_q15(const msp_fft_q15_params *params,
                                     int16_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_real
//!
//! \brief Real result inverse FFT function without scaling.
//!
//! \par Details
//! Computes the inverse discreet Fourier transform (DFT) of 32-bit complex
//! inputs with real result. If the inputs are not already in bit reversed order
//! the bit reversal parameter must be set. Fixed scaling is performed such
//! that this is the direct inverse of the forward FFT without scaling.
//!
//! \par
//! This functions uses half the data storage and consumes roughly half the
//! cycles and energy as running a complex IFFT of the same length. When
//! transforming purely real inputs, such as samples from an ADC or analog
//! sensor, it is recommended to use the real FFT functions.
//!
//! \par Pseudo code
//! `y = real(ifft(x)) ./ N`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to four times the data length (e.g.
//! a 256-point real FFT requires 1024-byte alignment). When allocating data the
//! MSP\_ALIGN\_FFT\_IQ31 macro can be used to calculate correct alignment. The
//! twiddle table pointer parameter is not used with LEA and can be null or
//! uninitialized.
//!
//! \param params Pointer to the real FFT parameter structure.
//! \param src Pointer to the real data array to perform the FFT on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_ifft_iq31(const msp_fft_iq31_params *params,
                                int32_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_complex
//!
//! \brief Complex forward FFT function with auto-scaling.
//!
//! \par Details
//! Computes the forward discreet Fourier transform (DFT) of 16-bit complex 
//! inputs. If the inputs are not already in bit reversed order the bit reversal
//! parameter must be set. The output is monitored for overflow and scaled by a
//! factor of two when an overflow risk is detected. The shift parameter contains
//! the number of bit shifts that were applied to the output.
//!
//! \par Pseudo code
//! `y = fft(x) * 2^-shift`
//!
//! \par Scaling
//! Scaling is applied as needed to prevent saturation of the output. The scale
//! factor that was applied to the output is returned in the shift parameter and
//! can be used to calculate the result by applying the following function.
//!
//! \par
//! `result = result * 2^shift`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to four times the data length (e.g.
//! a 256-point complex FFT requires 1024-byte alignment). When allocating data
//! the MSP\_CMPLX\_ALIGN\_FFT\_Q15 macro can be used to calculate correct
//! alignment. The twiddle table pointer parameter is not used with LEA and 
//! can be null or uninitialized.
//!
//! \param params Pointer to the complex FFT parameter structure.
//! \param src Pointer to the complex data array to perform the FFT on.
//! \param shift Auto-scaling shift that was applied to the output.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_fft_auto_q15(const msp_cmplx_fft_q15_params *params,
                                         int16_t *src,
                                         uint16_t *shift);

//******************************************************************************
//
//! \ingroup dsplib_transform_complex
//!
//! \brief Complex forward FFT function with fixed scaling by two at each stage.
//!
//! \par Details
//! Computes the forward discreet Fourier transform (DFT) of 16-bit complex
//! inputs. If the inputs are not already in bit reversed order the bit
//! reversal parameter must be set. The output is scaled by a factor of two for
//! each stage of the DFT.
//!
//! \par Pseudo code
//! `y = fft(x) ./ N`
//!
//! \par Scaling
//! Each stage of the complex FFT scales the result by a factor of 0.5. The
//! output format can either be interpreted as the same type with (1/N) scaling
//! or a different fixed point data type. This can be helpful when using the
//! IQmathLib to process the results of the FFT, such as computing the magnitude
//! or phase angle of the complex result.
//! 
//! \par
//! <center>
//! | Length   | Input Type | Result Type |
//! | -------- |:----------:| :----------:|
//! | **16**   | _q15       | _q11        |
//! | **32**   | _q15       | _q10        |
//! | **64**   | _q15       | _q9        |
//! | **128**  | _q15       | _q8         |
//! | **256**  | _q15       | _q7         |
//! | **512**  | _q15       | _q6         |
//! | **1024** | _q15       | _q5         |
//! | **2048** | _q15       | _q4         |
//! | **4096** | _q15       | _q3         |
//! </center>
//!
//! \par
//! The following table lists the applied scaling factor and resulting data type
//! when the input is a 16-bit integer. 
//!
//! \par
//! <center>
//! | Length   | Input Type | Result Type              |
//! | -------- |:----------:| :-----------------------:|
//! | **16**   | int16_t    | (int16_t)(result / 16)   |
//! | **32**   | int16_t    | (int16_t)(result / 32)   |
//! | **64**   | int16_t    | (int16_t)(result / 64)   |
//! | **128**  | int16_t    | (int16_t)(result / 128)  |
//! | **256**  | int16_t    | (int16_t)(result / 256)  |
//! | **512**  | int16_t    | (int16_t)(result / 512)  |
//! | **1024** | int16_t    | (int16_t)(result / 1024) |
//! | **2048** | int16_t    | (int16_t)(result / 2048) |
//! | **4096** | int16_t    | (int16_t)(result / 4096) |
//! </center>
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to four times the data length (e.g.
//! a 256-point complex FFT requires 1024-byte alignment). When allocating data
//! the MSP\_CMPLX\_ALIGN\_FFT\_Q15 macro can be used to calculate correct
//! alignment. The twiddle table pointer parameter is not used with LEA and 
//! can be null or uninitialized.
//!
//! \param params Pointer to the complex FFT parameter structure.
//! \param src Pointer to the complex data array to perform the FFT on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_fft_fixed_q15(
                                        const msp_cmplx_fft_q15_params *params,
                                        int16_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_complex
//!
//! \brief Complex forward FFT function without scaling.
//!
//! \par Details
//! Computes the forward discreet Fourier transform (DFT) of 32-bit complex
//! inputs. If the inputs are not already in bit reversed order the bit
//! reversal parameter must be set. The output is not scaled.
//!
//! \par Pseudo code
//! `y = fft(x)`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to eight times the data length 
//! (e.g. a 256-point complex FFT requires 2048-byte alignment). When allocating
//! data the MSP\_CMPLX\_ALIGN\_FFT\_IQ31 macro can be used to calculate correct
//! alignment. The twiddle table pointer parameter is not used with LEA and 
//! can be null or uninitialized.
//!
//! \param params Pointer to the complex FFT parameter structure.
//! \param src Pointer to the complex data array to perform the FFT on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_fft_iq31(const msp_cmplx_fft_iq31_params *params,
int32_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_complex
//!
//! \brief Complex inverse FFT function with auto-scaling.
//!
//! \par Details
//! Computes the inverse discreet Fourier transform (DFT) of 16-bit complex 
//! inputs. If the inputs are not already in bit reversed order the bit reversal
//! parameter must be set. The output is monitored for overflow and scaled by a
//! factor of two when an overflow risk is detected. Automatic scaling is
//! performed such that this is the direct inverse of the forward FFT with auto
//! scaling.
//!
//! \par Pseudo code
//! `y = (ifft(x) * 2^shift) ./ N`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to four times the data length (e.g.
//! a 256-point complex FFT requires 1024-byte alignment). When allocating data
//! the MSP\_CMPLX\_ALIGN\_FFT\_Q15 macro can be used to calculate correct
//! alignment. The twiddle table pointer parameter is not used with LEA and 
//! can be null or uninitialized.
//!
//! \param params Pointer to the complex FFT parameter structure.
//! \param src Pointer to the complex data array to perform the FFT on.
//! \param shift Auto-scaling shift that was applied to the output.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_ifft_auto_q15(
                                        const msp_cmplx_fft_q15_params *params,
                                        int16_t *src,
                                        uint16_t shift);

//******************************************************************************
//
//! \ingroup dsplib_transform_complex
//!
//! \brief Complex inverse FFT function with fixed scaling by two at each stage.
//!
//! \par Details
//! Computes the inverse discreet Fourier transform (DFT) of 16-bit complex 
//! inputs. If the inputs are not already in bit reversed order the bit reversal
//! parameter must be set. Fixed scaling is performed such that this is the
//! direct inverse of the forward FFT with fixed scaling.
//!
//! \par Pseudo code
//! `y = ifft(x)`
//!
//! \par Scaling
//! This function is the direct inverse of the forward complex FFT with fixed
//! scaling. The following fixed point input types will all result in Q15
//! results.
//! 
//! \par
//! <center>
//! | Length   | Input Type | Result Type |
//! | -------- |:----------:| :----------:|
//! | **16**   | _q11       | _q15        |
//! | **32**   | _q10       | _q15        |
//! | **64**   | _q9       | _q15        |
//! | **128**  | _q8        | _q15        |
//! | **256**  | _q7        | _q15        |
//! | **512**  | _q6        | _q15        |
//! | **1024** | _q5        | _q15        |
//! | **2048** | _q4        | _q15        |
//! | **4096** | _q3        | _q15        |
//! </center>
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to four times the data length (e.g.
//! a 256-point complex FFT requires 1024-byte alignment). When allocating data
//! the MSP\_CMPLX\_ALIGN\_FFT\_Q15 macro can be used to calculate correct
//! alignment. The twiddle table pointer parameter is not used with LEA and 
//! can be null or uninitialized.
//!
//! \param params Pointer to the complex FFT parameter structure.
//! \param src Pointer to the complex data array to perform the FFT on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_ifft_fixed_q15(
                                        const msp_cmplx_fft_q15_params *params,
                                        int16_t *src);

//******************************************************************************
//
//! \ingroup dsplib_transform_complex
//!
//! \brief Complex inverse FFT function without scaling.
//!
//! \par Details
//! Computes the inverse discreet Fourier transform (DFT) of 32-bit complex
//! inputs. If the inputs are not already in bit reversed order the bit reversal
//! parameter must be set. Fixed scaling is performed such that this is the
//! direct inverse of the forward FFT without scaling.
//!
//! \par Pseudo code
//! `y = ifft(x) ./ N`
//!
//! \par LEA Support
//! This function is supported by LEA and requires data to be placed into
//! shared LEA memory with alignment equal to eight times the data length 
//! (e.g. a 256-point complex FFT requires 2048-byte alignment). When allocating
//! data the MSP\_CMPLX\_ALIGN\_FFT\_IQ31 macro can be used to calculate correct
//! alignment. The twiddle table pointer parameter is not used with LEA and 
//! can be null or uninitialized.
//!
//! \param params Pointer to the complex FFT parameter structure.
//! \param src Pointer to the complex data array to perform the FFT on.
//!
//! \return Status of the operation.
//
//******************************************************************************
extern msp_status msp_cmplx_ifft_iq31(const msp_cmplx_fft_iq31_params *params,
                                      int32_t *src);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //__DSPLIB_TRANSFORM_H__
