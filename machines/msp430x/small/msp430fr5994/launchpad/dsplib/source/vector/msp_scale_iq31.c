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
 * Perform element wise Q31 multiplication of a single source vector with a Q31
 * scale value and shift left by scale. There is no risk of intermediate
 * saturation between steps however the result will overflow if the result is
 * outside the Q31 range of operation.
 */
msp_status msp_scale_iq31(const msp_scale_iq31_params *params, const _iq31 *src, _iq31 *dst)
{
    uint8_t shift;
    uint16_t length;
    int32_t scale;
    
    /* Initialize the loop counter, scale and shift variables. */
    length = params->length;
    scale = params->scale;
    shift = params->shift;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check for invalid shift size (maximum of 31). */
    if (shift > 31) {
        return MSP_SHIFT_SIZE_ERROR;
    }
#endif //MSP_DISABLE_DIAGNOSTICS
    
#if defined(__MSP430_HAS_MPY32__)
    int32_t result;
    
    /* If MPY32 is available save control context and set to fractional mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN;
    
    /* Load scale arguments once. */
    MPYS32L = (uint16_t)scale;
    MPYS32H = (uint16_t)(scale >> 16);

    /* Select 48-bit result registers based on shift count. */
    if (shift >= 16) {
        /* Decrement shift and use registers offset by 16-bits. */
        shift -= 16;
        
        /* Loop through all vector elements. */
        while (length--) {
            /* Multiply src and the combined scale and shift value. */
            OP2L = (uint16_t)*src;
            OP2H = (uint16_t)(*src++ >> 16);

            /* Combine the three registers comprising the result, with appropriate shifts */
            result = ((uint32_t)RES0 >> (16 - shift));
            result += ((uint32_t)RES1 << (shift));
            result += (int32_t)((uint32_t)RES2 << (shift + 16));
            *dst++ = result;
        }
    }
    else {
        /* Loop through all vector elements. */
        while (length--) {
            /* Multiply src and the combined scale and shift value. */
            OP2L = (uint16_t)*src;
            OP2H = (uint16_t)(*src++ >> 16);

            /* Combine the three registers comprising the result, with appropriate shifts */
            result = ((uint32_t)RES1 >> (16 - shift));
            result += ((uint32_t)RES2 << (shift));
            result += (int32_t)((uint32_t)RES3 << (shift + 16));
            *dst++ = result;
        }
    }

    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#else //__MSP430_HAS_MPY32__
    /* Recalculate shift value to be a shift right offset by the default Q15 shift by 15. */
    shift = 31 - shift;
    
    /* Loop through all vector elements. */
    while (length--) {
        /* Multiply src by scale and shift result right by the offset shift value. */
        *dst++ = (_iq31)(((int64_t)*src++ * (int64_t)scale) >> shift);
    }
#endif //__MSP430_HAS_MPY32__

    return MSP_SUCCESS;
}
