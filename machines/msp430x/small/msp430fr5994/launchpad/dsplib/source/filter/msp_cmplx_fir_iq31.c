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

msp_status msp_cmplx_fir_iq31(const msp_cmplx_fir_iq31_params *params, const _iq31 *src, _iq31 *dst)
{
    uint16_t cmdId;
    uint16_t tapLength;
    uint16_t bufferMask;
    uint16_t outputLength;
    bool enableCircBuf;
    msp_status status;
    MSP_LEA_FIRLONGCOMPLEX_PARAMS *leaParams;
  
    /* Save parameters to local variables. */
    tapLength = params->tapLength;
    outputLength = params->length;
    enableCircBuf = params->enableCircularBuffer;
    
#ifndef MSP_DISABLE_DIAGNOSTICS
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

    /* Check that the correct revision is defined. */
    if (MSP_LEA_REVISION != msp_lea_getRevision()) {
        return MSP_LEA_INCORRECT_REVISION;
    }

    /* Acquire lock for LEA module. */
    if (!msp_lea_acquireLock()) {
        return MSP_LEA_BUSY;
    }
#endif //MSP_DISABLE_DIAGNOSTICS

    /* Set buffer mask parameter. */
    if (enableCircBuf) {
        bufferMask = 4*outputLength - 1;
    }
    else {
        bufferMask = 0xffff;
    }

    /* Initialize LEA if it is not enabled. */
    if (!(LEAPMCTL & LEACMDEN)) {
        msp_lea_init();
    }
        
    /* Allocate MSP_LEA_FIRLONGCOMPLEX_PARAMS structure. */
    leaParams = (MSP_LEA_FIRLONGCOMPLEX_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_FIRLONGCOMPLEX_PARAMS)/sizeof(uint32_t));
    
    /* Set MSP_LEA_FIRLONGCOMPLEX_PARAMS structure. */
    leaParams->vectorSize = outputLength;
    leaParams->coeffs = MSP_LEA_CONVERT_ADDRESS(params->coeffs);
    leaParams->output = MSP_LEA_CONVERT_ADDRESS(dst);
    leaParams->tapLength = tapLength;
    leaParams->bufferMask = bufferMask;

    /* Load source arguments to LEA. */
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(src);
    LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);

#if (MSP_LEA_REVISION < MSP_LEA_REVISION_B)
    /* Load function into code memory */
    cmdId = msp_lea_loadCommand(LEACMD__FIRCOMPLEXLONG, MSP_LEA_FIRCOMPLEXLONG,
            sizeof(MSP_LEA_FIRCOMPLEXLONG)/sizeof(MSP_LEA_FIRCOMPLEXLONG[0]));
#else //MSP_LEA_REVISION
    /* Invoke the LEACMD__FIRCOMPLEXLONG command. */
    cmdId = LEACMD__FIRCOMPLEXLONG;
#endif //MSP_LEA_REVISION
    
    /* Invoke the command. */
    msp_lea_invokeCommand(cmdId);

    /* Free MSP_LEA_FIRLONGCOMPLEX_PARAMS structure. */
    msp_lea_freeMemory(sizeof(MSP_LEA_FIRLONGCOMPLEX_PARAMS)/sizeof(uint32_t));
        
    /* Set status flag. */
    status = MSP_SUCCESS;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check LEA interrupt flags for any errors. */
    if (msp_lea_ifg & LEACOVLIFG) {
        status = MSP_LEA_COMMAND_OVERFLOW;
    }
    else if (msp_lea_ifg & LEAOORIFG) {
        /* SW workaround for OOR interrupt when src is start of LEA memory. */
        if ((uintptr_t)src + (tapLength+outputLength)*(sizeof(int32_t)*2) > LEAMT) {
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

msp_status msp_cmplx_fir_iq31(const msp_cmplx_fir_iq31_params *params, const _iq31 *src, _iq31 *dst)
{
    uint16_t i;
    uint16_t j;
    uint16_t tapLength;
    uint16_t outputLength;
    bool enableCircBuf;
    const _iq31 *srcPtr;
    const _iq31 *coeffPtr;
    int64_t realRes;
    int64_t imagRes;
  
    /* Save parameters to local variables. */
    tapLength = params->tapLength << 1;
    outputLength = params->length << 1;
    enableCircBuf = params->enableCircularBuffer;
    
#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that the length is a power of two if circular buffer is enabled. */
    if (enableCircBuf && (outputLength & (outputLength-1))) {
        return MSP_SIZE_ERROR;
    }
#endif //MSP_DISABLE_DIAGNOSTICS

#if defined(__MSP430_HAS_MPY32__)
    /* If MPY32 is available save control context and set to fractional mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN | MPYSAT;
#endif

    /* Calculate filtered output using circular buffer. */
    if (enableCircBuf) {
        uintptr_t mask;
        const _iq31 *srcStartPtr;
        const _iq31 *srcEndPtr;

        /* Initialize circular buffer mask and set start pointer. */
        mask = (uintptr_t)(2*outputLength*sizeof(_iq31) - 1);
        srcStartPtr = (const _iq31 *)__circular_mask(src, mask);
        srcEndPtr = srcStartPtr + 2*outputLength;

        /* Calculate filtered output. */
        for (i = 0; i < outputLength; i += 2) {
            /* Reset data pointers and loop counters. */
            uint16_t j2;
            coeffPtr = &params->coeffs[tapLength - 2];
            srcPtr = (const _iq31 *)__circular_increment((const void *)src, i*sizeof(_iq31), mask);
            j = srcEndPtr - srcPtr;
            j = j > tapLength ? tapLength : j;
            j2 = tapLength - j;

            /* Reset accumulators. */
            realRes = 0;
            imagRes = 0;

            /* Multiply and accumulate inputs and coefficients. */
            while (j) {
                /* Accumulate real and complex. */
                realRes += __q31mpy(CMPLX_REAL(srcPtr), CMPLX_REAL(coeffPtr));
                realRes -= __q31mpy(CMPLX_IMAG(srcPtr), CMPLX_IMAG(coeffPtr));
                imagRes += __q31mpy(CMPLX_REAL(srcPtr), CMPLX_IMAG(coeffPtr));
                imagRes += __q31mpy(CMPLX_IMAG(srcPtr), CMPLX_REAL(coeffPtr));

                /* Update pointers */
                j -= 2;
                srcPtr += 2;
                coeffPtr-= 2;
            }

            /* Multiply and accumulate inputs and coefficients after circular buffer loop. */
            srcPtr = srcStartPtr;
            while (j2) {
                /* Accumulate real and complex. */
                realRes += __q31mpy(CMPLX_REAL(srcPtr), CMPLX_REAL(coeffPtr));
                realRes -= __q31mpy(CMPLX_IMAG(srcPtr), CMPLX_IMAG(coeffPtr));
                imagRes += __q31mpy(CMPLX_REAL(srcPtr), CMPLX_IMAG(coeffPtr));
                imagRes += __q31mpy(CMPLX_IMAG(srcPtr), CMPLX_REAL(coeffPtr));

                /* Update pointers */
                j2 -= 2;
                srcPtr += 2;
                coeffPtr-= 2;
            }
            
            /* Saturate accumulators and store result. */
            *dst++ = (_iq31)__saturate(realRes, INT32_MIN, INT32_MAX);
            *dst++ = (_iq31)__saturate(imagRes, INT32_MIN, INT32_MAX);
        }
    }
    /* Calculate filtered output without circular buffer. */
    else {
        for (i = 0; i < outputLength; i += 2) {
            /* Reset accumulators. */
            realRes = 0;
            imagRes = 0;

            /* Reset data pointers. */
            srcPtr = &src[i];
            coeffPtr = &params->coeffs[tapLength - 2];

            /* Multiply and accumulate inputs and coefficients. */
            j = tapLength;
            while (j) {
                /* Accumulate real and complex. */
                realRes += __q31mpy(CMPLX_REAL(srcPtr), CMPLX_REAL(coeffPtr));
                realRes -= __q31mpy(CMPLX_IMAG(srcPtr), CMPLX_IMAG(coeffPtr));
                imagRes += __q31mpy(CMPLX_REAL(srcPtr), CMPLX_IMAG(coeffPtr));
                imagRes += __q31mpy(CMPLX_IMAG(srcPtr), CMPLX_REAL(coeffPtr));

                /* Update pointers */
                j -= 2;
                srcPtr += 2;
                coeffPtr-= 2;
            }
            
            /* Saturate accumulators and store result. */
            *dst++ = (_iq31)__saturate(realRes, INT32_MIN, INT32_MAX);
            *dst++ = (_iq31)__saturate(imagRes, INT32_MIN, INT32_MAX);
        }
    }

#if defined(__MSP430_HAS_MPY32__)
    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#endif

#if defined(__MSP430_HAS_MPY32__)
    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#endif

    return MSP_SUCCESS;
}

#endif //MSP_USE_LEA
