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
 * Perform element wise Q31 multiplication of two complex source vectors.
 */
msp_status msp_cmplx_mpy_iq31(const msp_cmplx_mpy_iq31_params *params, const _iq31 *srcA, const _iq31 *srcB, _iq31 *dst)
{
    uint16_t length;
    
    /* Initialize the loop counter with the vector length. */
    length = params->length;

#if defined(__MSP430_HAS_MPY32__)
    uint16_t *dstPtr = (uint16_t *)dst;
    
    /* If MPY32 is available save control context and set to fractional mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN;
    
    /* Loop through all vector elements. */
     while (length--) {
        /* Complex multiply srcA and srcB and store to dst. */
        MPYS32L = (uint16_t)CMPLX_REAL(srcA);
        MPYS32H = (uint16_t)(CMPLX_REAL(srcA) >> 16);
        OP2L    = (uint16_t)CMPLX_REAL(srcB);
        OP2H    = (uint16_t)(CMPLX_REAL(srcB) >> 16);
        MACS32L = (uint16_t)(-CMPLX_IMAG(srcA));
        MACS32H = (uint16_t)(-CMPLX_IMAG(srcA) >> 16);
        OP2L    = (uint16_t)CMPLX_IMAG(srcB);
        OP2H    = (uint16_t)(CMPLX_IMAG(srcB) >> 16);
        *dstPtr++ = RES2;
        *dstPtr++ = RES3;
        MPYS32L = (uint16_t)CMPLX_REAL(srcA);
        MPYS32H = (uint16_t)(CMPLX_REAL(srcA) >> 16);
        OP2L    = (uint16_t)CMPLX_IMAG(srcB);
        OP2H    = (uint16_t)(CMPLX_IMAG(srcB) >> 16);
        MACS32L = (uint16_t)(CMPLX_IMAG(srcA));
        MACS32H = (uint16_t)(CMPLX_IMAG(srcA) >> 16);
        OP2L    = (uint16_t)CMPLX_REAL(srcB);
        OP2H    = (uint16_t)(CMPLX_REAL(srcB) >> 16);
        *dstPtr++ = RES2;
        *dstPtr++ = RES3;

        /* Increment pointers. */
        srcA += CMPLX_INCREMENT;
        srcB += CMPLX_INCREMENT;
    }

    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#else //__MSP430_HAS_MPY32__
    /* Loop through all vector elements. */
    while (length--) {
        /* Complex multiply srcA and srcB and store to dst. */
        *dst++ = (((int64_t)CMPLX_REAL(srcA) * (int64_t)CMPLX_REAL(srcB)) - ((int64_t)CMPLX_IMAG(srcA) * (int64_t)CMPLX_IMAG(srcB))) >> 31;
        *dst++ = (((int64_t)CMPLX_REAL(srcA) * (int64_t)CMPLX_IMAG(srcB)) + ((int64_t)CMPLX_IMAG(srcA) * (int64_t)CMPLX_REAL(srcB))) >> 31;
        
        /* Increment pointers. */
        srcA += CMPLX_INCREMENT;
        srcB += CMPLX_INCREMENT;
    }
#endif //__MSP430_HAS_MPY32__

    return MSP_SUCCESS;
}
