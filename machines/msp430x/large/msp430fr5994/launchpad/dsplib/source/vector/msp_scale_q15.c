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
 * Perform element wise Q15 multiplication of a single source vector with a Q15
 * scale value and shift left by shift.
 */
msp_status msp_scale_q15(const msp_scale_q15_params *params, const _q15 *src, _q15 *dst)
{
    uint16_t length;
    uint8_t shift;
    int32_t scale;
    
    /* Initialize the loop counter, scale and shift variables. */
    length = params->length;
    scale = params->scale;
    shift = params->shift;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that length parameter is a multiple of two. */
    if (length & 1) {
        return MSP_SIZE_ERROR;
    }
    
    /* Check for invalid shift size (maximum of 15). */
    if (shift > 15) {
        return MSP_SHIFT_SIZE_ERROR;
    }
#endif //MSP_DISABLE_DIAGNOSTICS

#if defined(__MSP430_HAS_MPY32__)
    /* If MPY32 is available save control context and set to fractional mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN;
    
    /* Combine the scale and shift parameters to a single 32-bit variable than can be reused. */
    while (shift--) {
        scale = scale << 1;
    }
    
    /* Load MPY32 registers for the first argument with the new scale value. */
    MPYS32L = (uint16_t)scale;
    MPYS32H = (uint16_t)(scale >> 16);
    
    /* Loop through all vector elements. */
    while (length--) {
        /* Multiply src and the combined scale and shift value. */
        OP2 = *src++;
        *dst++ = RESHI;
    }
    
    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#else //__MSP430_HAS_MPY32__
    /* Recalculate shift value to be a shift right offset by the default Q15 shift by 15. */
    shift = 15 - shift;
    
    /* Loop through all vector elements. */
    while (length--) {
        /* Multiply src by scale and shift result right by the offset shift value. */
        *dst++ = (_q15)(((int32_t)*src++ * (int32_t)scale) >> shift);
    }
#endif //__MSP430_HAS_MPY32__

    return MSP_SUCCESS;
}
