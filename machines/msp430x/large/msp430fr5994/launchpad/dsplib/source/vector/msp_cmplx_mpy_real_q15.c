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
 * Perform element wise Q15 multiplication of a complex source vector with a real source vector.
 */
msp_status msp_cmplx_mpy_real_q15(const msp_cmplx_mpy_real_q15_params *params, const _q15 *srcCmplx, const _q15 *srcReal, _q15 *dst)
{
    uint16_t length;
    
    /* Initialize the loop counter with the vector length. */
    length = params->length;
    
#if defined(__MSP430_HAS_MPY32__)
    /* If MPY32 is available save control context and set to fractional mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN;
    
    /* Loop through all vector elements. */
    while (length--) {
        /* Multiply srcCmplx and srcReal and store to dst. */
        MPYS = *srcReal++;
        OP2  = *srcCmplx++;
        *dst++ = RESHI;
        OP2  = *srcCmplx++;
        *dst++ = RESHI;
    }
    
    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#else //__MSP430_HAS_MPY32__
    /* Loop through all vector elements. */
    while (length--) {
        /* Multiply srcCmplx and srcReal and store to dst. */
        *dst++ = __q15mpy(*srcCmplx++, *srcReal);       // real
        *dst++ = __q15mpy(*srcCmplx++, *srcReal++);     // imaginary
    }
#endif //__MSP430_HAS_MPY32__

    return MSP_SUCCESS;
}
