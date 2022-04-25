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

#include "../../include/DSPLib.h"

/*
 * Perform an in-place complex inverse DFT of the input signal using complex
 * conjugate, the complex DFT and complex scaling. Fixed scaling is performed
 * such that this is the direct inverse of the forward FFT.
 */
msp_status msp_ifft_iq31(const msp_fft_iq31_params *params, int32_t *src)
{
    uint16_t index;                             // min/max index
    uint16_t length;                            // vector length
    int16_t preShift;                           // pre-complex fft shift
    int16_t postShift;                          // post-complex fft shift
    int32_t maximum;                            // vector maximum
    int32_t minimum;                            // vector minimum
    msp_status status;                          // Status of the operations
    msp_max_iq31_params paramsMax;              // Maximum params
    msp_min_iq31_params paramsMin;              // Minimum params
    msp_split_iq31_params paramsSplit;          // Split operation params
    msp_cmplx_fft_iq31_params paramsCmplxFFT;   // Complex FFT params
    msp_cmplx_shift_iq31_params paramsShift;    // Complex shift params
    
    /* Calculate the necessary result scale based on length. */
    preShift = -2;
    length = params->length;
    while (length > 2) {
        preShift--;
        length >>= 1;
    }
    
    /* Find maximum input to determine scaling order. */
    paramsMax.length = params->length;
    status = msp_max_iq31(&paramsMax, src, &maximum, &index);
    if (status !=  MSP_SUCCESS) {
        return status;
    }
    
    /* Find minimum input to determine scaling order. */
    paramsMin.length = params->length;
    status = msp_min_iq31(&paramsMin, src, &minimum, &index);
    if (status !=  MSP_SUCCESS) {
        return status;
    }
    
    /* Determine scaling order based on min/max results. */
    postShift = 0;
    minimum = minimum < -maximum ? minimum : -maximum;
    while (minimum > (INT32_MIN/2)) {
        minimum <<= 1;
        preShift++;
        postShift--;
    }
    
    /* Prescale the complex fft input with complex conjugate. */
    paramsShift.length = params->length >> 1;
    paramsShift.shift = preShift;
    paramsShift.conjugate = true;
    status = msp_cmplx_shift_iq31(&paramsShift, src, src);
    if (status !=  MSP_SUCCESS) {
        return status;
    }
    
    /* Initialize split operation params structure. */
    paramsSplit.length = params->length;
    paramsSplit.twiddleTable = params->twiddleTable;
    
    /* Perform the last stage split operation to obtain N/2 complex FFT results. */
    status = msp_split_iq31(&paramsSplit, src);
    if (status !=  MSP_SUCCESS) {
        return status;
    }

    /* Initialize complex FFT params structure. */
    paramsCmplxFFT.length = params->length >> 1;
    paramsCmplxFFT.bitReverse = params->bitReverse;
    paramsCmplxFFT.twiddleTable = params->twiddleTable;
    
    /* Perform N/2 complex FFT on real source. */
    status = MAP_msp_cmplx_fft_iq31(&paramsCmplxFFT, src);
    if (status !=  MSP_SUCCESS) {
        return status;
    }
    
    /* Initialize complex shift parameters with conjugate enabled. */
    paramsShift.length = params->length >> 1;
    paramsShift.shift = postShift;
    paramsShift.conjugate = true;
    return msp_cmplx_shift_iq31(&paramsShift, src, src);
}
