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
 * such that this is the direct inverse of the forward FFT with fixed scaling.
 */
msp_status msp_cmplx_ifft_fixed_q15(const msp_cmplx_fft_q15_params *params, int16_t *src)
{
    uint16_t resultShift;                       // complex fft result shift
    msp_status status;                          // Status of the operations
    msp_cmplx_conj_q15_params conjParams;       // Complex conjugate params
    msp_cmplx_fft_q15_params paramsCmplxFFT;    // Complex FFT params
    msp_cmplx_shift_q15_params paramsShift;     // Complex shift params
    
    /* Initialize complex conjugate params structure. */
    conjParams.length = params->length;
    
    /* Take the complex conjugate of the input. */
    status = msp_cmplx_conj_q15(&conjParams, src, src);
    if (status !=  MSP_SUCCESS) {
        return status;
    }
    
    /* Initialize complex FFT params structure. */
    paramsCmplxFFT.length = params->length;
    paramsCmplxFFT.bitReverse = params->bitReverse;
    paramsCmplxFFT.twiddleTable = params->twiddleTable;
    
    /* Perform complex FFT on real source with scaling. */
    status = MAP_msp_cmplx_fft_auto_q15(&paramsCmplxFFT, src, &resultShift);
    if (status !=  MSP_SUCCESS) {
        return status;
    }
    
    /* Initialize complex shift parameters with conjugate enabled. */
    paramsShift.length = params->length;
    paramsShift.shift = (int8_t)resultShift;
    paramsShift.conjugate = true;
    return msp_cmplx_shift_q15(&paramsShift, src, src);
}
