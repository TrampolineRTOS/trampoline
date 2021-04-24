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
 * Perform an in-place real DFT of the real input signal using a complex DFT of
 * size N/2 and a split operation to obtain a complex output with length N/2.
 * Fixed scaling by 2 is performed at each stage.
 */
msp_status msp_fft_fixed_q15(const msp_fft_q15_params *params, int16_t *src)
{
    msp_status status;                          // Status of the operations
    msp_split_q15_params paramsSplit;           // Split operation params
    msp_cmplx_fft_q15_params paramsCmplxFFT;    // Complex FFT params
    
    /* Initialize complex FFT params structure. */
    paramsCmplxFFT.length = params->length >> 1;
    paramsCmplxFFT.bitReverse = params->bitReverse;
    paramsCmplxFFT.twiddleTable = params->twiddleTable;
    
    /* Perform N/2 complex FFT on real source with scaling. */
    status = MAP_msp_cmplx_fft_fixed_q15(&paramsCmplxFFT, src);
    if (status !=  MSP_SUCCESS) {
        return status;
    }
    
    /* Initialize split operation params structure. */
    paramsSplit.length = params->length;
    paramsSplit.twiddleTable = params->twiddleTable;
    
    /* Perform the last stage split operation to obtain N/2 complex FFT results. */
    return msp_split_q15(&paramsSplit, src);
}
