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

#if defined(MSP_USE_LEA)

msp_status msp_fir_q15(const msp_fir_q15_params *params, const _q15 *src, _q15 *dst)
{
    uint16_t tapLength;
    uint16_t bufferMask;
    uint16_t outputLength;
    bool enableCircBuf;
    msp_status status;
    MSP_LEA_FIR_PARAMS *leaParams;

    /* Save parameters to local variables. */
    tapLength = params->tapLength;
    outputLength = params->length;
    enableCircBuf = params->enableCircularBuffer;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that tap and output length are a multiple of two. */
    if ((tapLength & 1) || (outputLength & 1)) {
        return MSP_SIZE_ERROR;
    }
    
    /* Check that the length is a power of two if circular buffer is enabled. */
    if (enableCircBuf && (outputLength & (outputLength-1))) {
        return MSP_SIZE_ERROR;
    }

    /* Check that the data arrays are aligned and in a valid memory segment. */
    if (!(MSP_LEA_VALID_ADDRESS(src, 4) &
          MSP_LEA_VALID_ADDRESS(dst, 4) &
          MSP_LEA_VALID_ADDRESS(params->coeffs, 4))) {
        return MSP_LEA_INVALID_ADDRESS;
    }

    /* Acquire lock for LEA module. */
    if (!msp_lea_acquireLock()) {
        return MSP_LEA_BUSY;
    }
#endif //MSP_DISABLE_DIAGNOSTICS

    /* Set buffer mask parameter. */
    if (enableCircBuf) {
        bufferMask = outputLength - 1;
    }
    else {
        bufferMask = 0xffff;
    }

    /* Initialize LEA if it is not enabled. */
    if (!(LEAPMCTL & LEACMDEN)) {
        msp_lea_init();
    }

    /* Allocate MSP_LEA_FIR_PARAMS structure. */
    leaParams = (MSP_LEA_FIR_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_FIR_PARAMS)/sizeof(uint32_t));

    /* Set MSP_LEA_FIR_PARAMS structure. */
    leaParams->vectorSize = outputLength;
    leaParams->coeffs = MSP_LEA_CONVERT_ADDRESS(params->coeffs);
    leaParams->output = MSP_LEA_CONVERT_ADDRESS(dst);
    leaParams->tapLength = tapLength;
    leaParams->bufferMask = bufferMask;

    /* Load source arguments to LEA. */
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(src);
    LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);

    /* Invoke the LEACMD__FIR command. */
    msp_lea_invokeCommand(LEACMD__FIR);

    /* Free MSP_LEA_FIR_PARAMS structure. */
    msp_lea_freeMemory(sizeof(MSP_LEA_FIR_PARAMS)/sizeof(uint32_t));

    /* Set status flag. */
    status = MSP_SUCCESS;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check LEA interrupt flags for any errors. */
    if (msp_lea_ifg & LEACOVLIFG) {
        status = MSP_LEA_COMMAND_OVERFLOW;
    }
    else if (msp_lea_ifg & LEAOORIFG) {
        /* SW workaround for OOR interrupt when src is start of LEA memory. */
        if ((uintptr_t)src + (tapLength+outputLength)*(sizeof(int16_t)) > LEAMT) {
            status = MSP_LEA_OUT_OF_RANGE;
        }
    }
    else if (msp_lea_ifg & LEASDIIFG) {
        status = MSP_LEA_SCALAR_INCONSISTENCY;
    }
#endif

    /* Free lock for LEA module and return status. */
    msp_lea_freeLock();
    return status;
}

#else //MSP_USE_LEA

msp_status msp_fir_q15(const msp_fir_q15_params *params, const _q15 *src, _q15 *dst)
{
    uint16_t i;
    uint16_t j;
    uint16_t tapLength;
    uint16_t outputLength;
    bool enableCircBuf;
    const _q15 *srcPtr;
    const _q15 *coeffPtr;

    /* Save parameters to local variables. */
    tapLength = params->tapLength;
    outputLength = params->length;
    enableCircBuf = params->enableCircularBuffer;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that tap and output length are a multiple of two. */
    if ((tapLength & 1) || (outputLength & 1)) {
        return MSP_SIZE_ERROR;
    }

    /* Check that the length is a power of two if circular buffer is enabled. */
    if (enableCircBuf && (outputLength & (outputLength-1))) {
        return MSP_SIZE_ERROR;
    }
#endif //MSP_DISABLE_DIAGNOSTICS

#if defined(__MSP430_HAS_MPY32__)
    /* If MPY32 is available save control context and set to fractional mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN | MPYSAT;
#endif //__MSP430_HAS_MPY32__

    /* Calculate filtered output using circular buffer. */
    if (enableCircBuf) {
        uintptr_t mask;
        const _q15 *srcStartPtr;
        const _q15 *srcEndPtr;

        /* Initialize circular buffer mask and set start pointer. */
        mask = (uintptr_t)(2*outputLength*sizeof(_q15) - 1);
        srcStartPtr = (const _q15 *)__circular_mask(src, mask);
        srcEndPtr = srcStartPtr + 2*outputLength;

        /* Calculate filtered output. */
        for (i = 0; i < outputLength; i++) {
            /* Reset data pointers and loop counters. */
            uint16_t j2;
            coeffPtr = &params->coeffs[tapLength-1];
            srcPtr = (const _q15 *)__circular_increment((const void *)src, i*sizeof(_q15), mask);
            j = srcEndPtr - srcPtr;
            j = j > tapLength ? tapLength : j;
            j2 = tapLength - j;

#if defined(__MSP430_HAS_MPY32__)
            /* Reset multiplier context. */
            MPY32CTL0 &= ~MPYC;
            RESLO = 0; RESHI = 0;

            /* Multiply and accumulate inputs and coefficients. */
            while (j--) {
                MACS = *srcPtr++;
                OP2 =  *coeffPtr--;
            }

            /* Multiply and accumulate inputs and coefficients after circular buffer loop. */
            srcPtr = srcStartPtr;
            while (j2--) {
                MACS = *srcPtr++;
                OP2 =  *coeffPtr--;
            }

            /* Store accumulated result. */
            *dst++ = RESHI;
#else //__MSP430_HAS_MPY32__
            /* Reset accumulator. */
            _iq31 result = 0;

            /* Multiply and accumulate inputs and coefficients. */
            while (j--) {
                result += (_iq31)*srcPtr++ * (_iq31)*coeffPtr--;
            }

            /* Multiply and accumulate inputs and coefficients after circular buffer loop. */
            srcPtr = srcStartPtr;
            while (j2--) {
                result += (_iq31)*srcPtr++ * (_iq31)*coeffPtr--;
            }

            /* Saturate accumulator and store result. */
            *dst++ = __saturate(result >> 15, INT16_MIN, INT16_MAX);
#endif //__MSP430_HAS_MPY32__
        }
    }
    /* Calculate filtered output without circular buffer. */
    else {
        for (i = 0; i < outputLength; i++) {
            /* Reset data pointers and loop counters. */
            srcPtr = &src[i];
            coeffPtr = &params->coeffs[tapLength-1];
            j = tapLength;

#if defined(__MSP430_HAS_MPY32__)
            /* Reset multiplier context. */
            MPY32CTL0 &= ~MPYC;
            RESLO = 0; RESHI = 0;

            /* Multiply and accumulate inputs and coefficients. */
            while (j--) {
                MACS = *srcPtr++;
                OP2 =  *coeffPtr--;
            }

            /* Store accumulated result. */
            *dst++ = RESHI;
#else //__MSP430_HAS_MPY32__
            /* Reset accumulator. */
            _iq31 result = 0;

            /* Multiply and accumulate inputs and coefficients. */
            while (j--) {
                result += (_iq31)*srcPtr++ * (_iq31)*coeffPtr--;
            }

            /* Saturate accumulator and store result. */
            *dst++ = __saturate(result >> 15, INT16_MIN, INT16_MAX);
#endif //__MSP430_HAS_MPY32__
        }
    }
    
#if defined(_MSP430_HAS_MPY32_)
    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#endif

     return MSP_SUCCESS;
}

#endif //MSP_USE_LEA
