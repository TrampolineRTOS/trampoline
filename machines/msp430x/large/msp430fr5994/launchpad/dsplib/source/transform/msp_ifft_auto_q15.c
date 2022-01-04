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
 * Perform an in-place real inverse DFT of the complex input signal using a
 * split operation and a complex DFT of size N/2 and to obtain a real output
 * with length N. Automatic scaling is performed such that this is the direct
 * inverse of the forward FFT with auto scaling.
 */
msp_status msp_ifft_auto_q15(const msp_fft_q15_params *params, int16_t *src, uint16_t shift)
{
    uint16_t length;                            // src length
    uint16_t resultShift;                       // complex fft result shift
    msp_status status;                          // Status of the operations
    msp_split_q15_params paramsSplit;           // Split operation params
    msp_cmplx_conj_q15_params conjParams;       // Complex conjugate params
    msp_cmplx_fft_q15_params paramsCmplxFFT;    // Complex FFT params
    msp_cmplx_shift_q15_params paramsShift;     // Complex shift params
    
    /* Initialize complex conjugate params structure. */
    conjParams.length = params->length/2;
    
    /* Take the complex conjugate of the input. */
    status = msp_cmplx_conj_q15(&conjParams, src, src);
    if (status !=  MSP_SUCCESS) {
        return status;
    }
    
    /* Initialize split operation params structure. */
    paramsSplit.length = params->length;
    paramsSplit.twiddleTable = params->twiddleTable;
    
    /* Perform the last stage split operation to obtain N/2 complex FFT results. */
    status = msp_split_q15(&paramsSplit, src);
    if (status !=  MSP_SUCCESS) {
        return status;
    }
    
    /* Initialize complex FFT params structure. */
    paramsCmplxFFT.length = params->length >> 1;
    paramsCmplxFFT.bitReverse = params->bitReverse;
    paramsCmplxFFT.twiddleTable = params->twiddleTable;
    
    /* Perform N/2 complex FFT on real source with scaling. */
    status = MAP_msp_cmplx_fft_auto_q15(&paramsCmplxFFT, src, &resultShift);
    if (status !=  MSP_SUCCESS) {
        return status;
    }
    
    /* Calculate necessary shift to complete the operation. */
    shift += resultShift;
    length = params->length;
    while (length > 2) {
        shift--;
        length >>= 1;
    }
    
    /* Initialize complex shift parameters with conjugate enabled. */
    paramsShift.length = params->length >> 1;
    paramsShift.shift = (int8_t)shift;
    paramsShift.conjugate = true;
    return msp_cmplx_shift_q15(&paramsShift, src, src);
}
