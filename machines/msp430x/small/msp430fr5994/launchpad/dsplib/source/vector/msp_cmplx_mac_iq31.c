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

msp_status msp_cmplx_mac_iq31(const msp_cmplx_mac_iq31_params *params, const _iq31 *srcA, const _iq31 *srcB, _iq31 *result)
{
    uint16_t length;
    
    /* Initialize the loop counter with the vector length. */
    length = params->length;
    
#if defined(__MSP430_HAS_MPY32__)
    uint16_t *resultPtr = (uint16_t *)result;
    
    /* If MPY32 is available save control context and set to fractional mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN;
    
    /* Initialize result registers. */
    RES0=0; RES1=0; RES2=0; RES3=0;

    /* Multiply and accumulate the real components of srcA and srcB. */
    while (length--) {
        MACS32L = (uint16_t)CMPLX_REAL(srcA);
        MACS32H = (uint16_t)(CMPLX_REAL(srcA) >> 16);
        OP2L    = (uint16_t)CMPLX_REAL(srcB);
        OP2H    = (uint16_t)(CMPLX_REAL(srcB) >> 16);
        MACS32L = (uint16_t)(-CMPLX_IMAG(srcA));
        MACS32H = (uint16_t)(-CMPLX_IMAG(srcA) >> 16);
        OP2L    = (uint16_t)CMPLX_IMAG(srcB);
        OP2H    = (uint16_t)(CMPLX_IMAG(srcB) >> 16);

        /* Increment pointers. */
        srcA += CMPLX_INCREMENT;
        srcB += CMPLX_INCREMENT;
    }
    
    /* Save real result. */
    *resultPtr++ = RES2;
    *resultPtr++ = RES3;
    
    /* Reset length to calculate imaginary value, reset result registers .*/
    length = params->length;
    RES3=0; RES2=0; RES1=0; RES0=0;
    srcA -= length*CMPLX_INCREMENT;
    srcB -= length*CMPLX_INCREMENT;

    while (length--) {
        MACS32L = (uint16_t)CMPLX_REAL(srcA);
        MACS32H = (uint16_t)(CMPLX_REAL(srcA) >> 16);
        OP2L    = (uint16_t)CMPLX_IMAG(srcB);
        OP2H    = (uint16_t)(CMPLX_IMAG(srcB) >> 16);
        MACS32L = (uint16_t)CMPLX_IMAG(srcA);
        MACS32H = (uint16_t)(CMPLX_IMAG(srcA) >> 16);
        OP2L    = (uint16_t)CMPLX_REAL(srcB);
        OP2H    = (uint16_t)(CMPLX_REAL(srcB) >> 16);

        /* Increment pointers. */
        srcA += CMPLX_INCREMENT;
        srcB += CMPLX_INCREMENT;
    }
    
    /* Save imaginary result. */
    *resultPtr++ = RES2;
    *resultPtr++ = RES3;

    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#else //__MSP430_HAS_MPY32__
    int64_t resultReal = 0;
    int64_t resultImag = 0;
    
    /* Loop through all vector elements. */
    while (length--) {
        /* Complex multiply srcA and srcB and accumulate to the result. */
        resultReal += ((int64_t)CMPLX_REAL(srcA) * (int64_t)CMPLX_REAL(srcB));
        resultReal -= ((int64_t)CMPLX_IMAG(srcA) * (int64_t)CMPLX_IMAG(srcB));
        resultImag += ((int64_t)CMPLX_REAL(srcA) * (int64_t)CMPLX_IMAG(srcB));
        resultImag += ((int64_t)CMPLX_IMAG(srcA) * (int64_t)CMPLX_REAL(srcB));
        
        /* Increment pointers. */
        srcA += CMPLX_INCREMENT;
        srcB += CMPLX_INCREMENT;
    }
    
    /* Scale result, saturate and save to result array. */
    CMPLX_REAL(result) = (_iq31)__saturate((resultReal >> 31), INT32_MIN, INT32_MAX);
    CMPLX_IMAG(result) = (_iq31)__saturate((resultImag >> 31), INT32_MIN, INT32_MAX);
#endif //__MSP430_HAS_MPY32__

    return MSP_SUCCESS;
}
