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

msp_status msp_cmplx_fft_iq31(const msp_cmplx_fft_iq31_params *params, int32_t *src)
{
    uint16_t cmdId;
    uint16_t log2Size;
    uint16_t length;
    msp_status status;
    MSP_LEA_FFTCOMPLEXLONG_PARAMS *leaParams;
    
    /* Save input length to local. */
    length = params->length;
    
    /* Bit reverse the order of the inputs. */
    if(params->bitReverse) {
        /* Create and initialize a bit reversal params structure. */
        msp_cmplx_bitrev_iq31_params paramsBitRev;
        paramsBitRev.length = params->length;
        
        /* Perform bit reversal on source data. */
        status = msp_cmplx_bitrev_iq31(&paramsBitRev, src);
        
        /* Check if the operation was not successful. */
        if (status !=  MSP_SUCCESS) {
            return status;
        }
    }

    /* Calculate log2Size parameter. */
    log2Size = 0;
    while (length > 1) {
        log2Size++;
        length >>= 1;
    }
    length = params->length;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that the length is a power of two. */
    if ((length & (length-1))) {
        return MSP_SIZE_ERROR;
    }
    
    /* Check that the data arrays are aligned and in a valid memory segment. */
    if (!(MSP_LEA_VALID_ADDRESS(src, length*8))) {
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

    /* Initialize LEA if it is not enabled. */
    if (!(LEAPMCTL & LEACMDEN)) {
        msp_lea_init();
    }
        
    /* Allocate MSP_LEA_FFTCOMPLEXLONG_PARAMS structure. */
    leaParams = (MSP_LEA_FFTCOMPLEXLONG_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_FFTCOMPLEXLONG_PARAMS)/sizeof(uint32_t));

    /* Set MSP_LEA_FFTCOMPLEXLONG_PARAMS structure. */
    leaParams->vectorSize = length;
    leaParams->log2Size = log2Size;
    
    /* Load source arguments to LEA. */
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(src);
    LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);

#if (MSP_LEA_REVISION < MSP_LEA_REVISION_B)
    /* Load function into code memory */
    cmdId = msp_lea_loadCommand(LEACMD__FFTCOMPLEXLONG, MSP_LEA_FFTCOMPLEXLONG,
            sizeof(MSP_LEA_FFTCOMPLEXLONG)/sizeof(MSP_LEA_FFTCOMPLEXLONG[0]));
#else //MSP_LEA_REVISION
    /* Invoke the LEACMD__FFTCOMPLEXLONG command. */
    cmdId = LEACMD__FFTCOMPLEXLONG;
#endif //MSP_LEA_REVISION
    
    /* Invoke the command. */
    msp_lea_invokeCommand(cmdId);

    /* Free MSP_LEA_FFTCOMPLEXLONG_PARAMS structure. */
    msp_lea_freeMemory(sizeof(MSP_LEA_FFTCOMPLEXLONG_PARAMS)/sizeof(uint32_t));
    
    /* Set status flag. */
    status = MSP_SUCCESS;
        
#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check LEA interrupt flags for any errors. */
    if (msp_lea_ifg & LEACOVLIFG) {
        status = MSP_LEA_COMMAND_OVERFLOW;
    }
    else if (msp_lea_ifg & LEAOORIFG) {
        /* SW workaround for OOR interrupt during normal operation. */
        if ((uintptr_t)src + length*(sizeof(int32_t)*2) > LEAMT) {
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

#define STAGE1_STEP             (2)
#define STAGE2_STEP             (STAGE1_STEP*2)
#define STAGE3_STEP             (STAGE2_STEP*2)
#define STAGE4_STEP             (STAGE3_STEP*2)

static inline void msp_cmplx_btfly_iq31(int32_t *srcA, int32_t *srcB, const _q15 *coeff);
static inline void msp_cmplx_btfly_c0_iq31(int32_t *srcA, int32_t *srcB);
static inline void msp_cmplx_btfly_c1_iq31(int32_t *srcA, int32_t *srcB);

/*
 * Perform in-place radix-2 DFT of the input signal using an algorithm optimized
 * for MSP430 with fixed scaling by two at each stage.
 */
msp_status msp_cmplx_fft_iq31(const msp_cmplx_fft_iq31_params *params, int32_t *src)
{
    int16_t i, j;                       // loop counters
    uint16_t step;                      // step size
    uint16_t length;                    // src length
    uint16_t twiddleIndex;              // twiddle table index
    uint16_t twiddleIncrement;          // twiddle table increment
    int32_t *srcPtr;                    // local source pointer
    const _q15 *twiddlePtr;             // twiddle table pointer
    msp_status status;                  // Status of the operation
    
    /* Save input length to local. */
    length = params->length;
    
    /* Bit reverse the order of the inputs. */
    if(params->bitReverse) {
        /* Create and initialize a bit reversal params structure. */
        msp_cmplx_bitrev_iq31_params paramsBitRev;
        paramsBitRev.length = params->length;
        
        /* Perform bit reversal on source data. */
        status = msp_cmplx_bitrev_iq31(&paramsBitRev, src);
        
        /* Check if the operation was not successful. */
        if (status !=  MSP_SUCCESS) {
            return status;
        }
    }

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that the length is a power of two. */
    if ((length & (length-1))) {
        return MSP_SIZE_ERROR;
    }
    
    /* Check that the provided table is the correct length. */
    if (*(uint16_t *)params->twiddleTable < length) {
        return MSP_TABLE_SIZE_ERROR;
    }
#endif //MSP_DISABLE_DIAGNOSTICS

    /* Stage 1. */
    if (STAGE1_STEP <= length) {
        for (j = 0; j < length; j += STAGE1_STEP) {
            srcPtr = src + j*2;
            msp_cmplx_btfly_c0_iq31(&srcPtr[0], &srcPtr[0+STAGE1_STEP]);
        }
    }
    
    /* Stage 2. */
    if (STAGE2_STEP <= length) {
        for (j = 0; j < length; j += STAGE2_STEP) {
            srcPtr = src + j*2;
            msp_cmplx_btfly_c0_iq31(&srcPtr[0], &srcPtr[0+STAGE2_STEP]);
            msp_cmplx_btfly_c1_iq31(&srcPtr[2], &srcPtr[2+STAGE2_STEP]);
        }
    }
    
    /* Initialize step size, twiddle angle increment and twiddle table pointer. */
    step = STAGE3_STEP;
    twiddleIncrement = 2*(*(uint16_t*)params->twiddleTable)/STAGE3_STEP;
    twiddlePtr = &params->twiddleTable[DSPLIB_TABLE_OFFSET];
    
    /* If MPY32 is available save control context and set to fractional mode. */
#if defined(__MSP430_HAS_MPY32__)
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN;
#endif
    
    /* Stage 3 -> log2(step). */
    while (step <= length) {
        /* Reset the twiddle angle index. */
        twiddleIndex = 0;
        
        for (i = 0; i < (step/2); i++) {            
            /* Perform butterfly operations on complex pairs. */
            for (j = i; j < length; j += step) {
                srcPtr = src + j*2;
                msp_cmplx_btfly_iq31(srcPtr, srcPtr + step, &twiddlePtr[twiddleIndex]);
            }
            
            /* Increment twiddle table index. */
            twiddleIndex += twiddleIncrement;
        }
        /* Double the step size and halve the increment factor. */
        step *= 2;
        twiddleIncrement = twiddleIncrement/2;
    }
    
    /* Restore MPY32 control context. */
#if defined(__MSP430_HAS_MPY32__)
    MPY32CTL0 = ui16MPYState;
#endif
    
    return MSP_SUCCESS;
}

/*
 * Abstracted helper functions for a radix-2 butterfly operation. The following
 * operation is performed with fixed scaling by two at each stage:
 *     A = A + coeff*B
 *     B = A - coeff*B
 */
static inline void msp_cmplx_btfly_iq31(int32_t *srcA, int32_t *srcB, const _q15 *coeff)
{
    /* Load coefficients. */
    _iq31 tempR = CMPLX_REAL(coeff);
    _iq31 tempI = CMPLX_IMAG(coeff);
    
    /* Calculate real and imaginary parts of coeff*B. */
    __q15iq31cmpy(&tempR, &tempI, &CMPLX_REAL(srcB), &CMPLX_IMAG(srcB));

    /* B = A - coeff*B */
    CMPLX_REAL(srcB) = CMPLX_REAL(srcA) - tempR;
    CMPLX_IMAG(srcB) = CMPLX_IMAG(srcA) - tempI;
    
    /* A = A + coeff*B */
    CMPLX_REAL(srcA) = CMPLX_REAL(srcA) + tempR;
    CMPLX_IMAG(srcA) = CMPLX_IMAG(srcA) + tempI;
}

/*
 * Simplified radix-2 butterfly operation for e^(-2*pi*(0/4)). This abstracted
 * helper function takes advantage of the fact the the twiddle coefficients are
 * positive and negative one for a multiplication by e^(-2*pi*(0/4)). The
 * following operation is performed with fixed scaling by two at each stage:
 *     A = A + (1+0j)*B
 *     B = A - (1+0j)*B
 */
static inline void msp_cmplx_btfly_c0_iq31(int32_t *srcA, int32_t *srcB)
{
    int32_t tempR = CMPLX_REAL(srcB);
    int32_t tempI = CMPLX_IMAG(srcB);
    
    /* B = A - (1+0j)*B */
    CMPLX_REAL(srcB) = CMPLX_REAL(srcA) - tempR;
    CMPLX_IMAG(srcB) = CMPLX_IMAG(srcA) - tempI;
    
    /* A = A + (1+0j)*B */
    CMPLX_REAL(srcA) = CMPLX_REAL(srcA) + tempR;
    CMPLX_IMAG(srcA) = CMPLX_IMAG(srcA) + tempI;
}

/*
 * Simplified radix-2 butterfly operation for e^(-2*pi*(1/4)). This abstracted
 * helper function takes advantage of the fact the the twiddle coefficients are
 * positive and negative one for a multiplication by e^(-2*pi*(1/4)). The
 * following operation is performed with fixed scaling by two at each stage:
 *     A = A + (0-1j)*B
 *     B = A - (0-1j)*B
 */
static inline void msp_cmplx_btfly_c1_iq31(int32_t *srcA, int32_t *srcB)
{
    int32_t tempR = CMPLX_REAL(srcB);
    int32_t tempI = CMPLX_IMAG(srcB);
    
    /* B = A - (0-1j)*B */
    CMPLX_REAL(srcB) = CMPLX_REAL(srcA) - tempI;
    CMPLX_IMAG(srcB) = CMPLX_IMAG(srcA) + tempR;
    
    /* A = A + (0-1j)*B */
    CMPLX_REAL(srcA) = CMPLX_REAL(srcA) + tempI;
    CMPLX_IMAG(srcA) = CMPLX_IMAG(srcA) - tempR;
}

#endif //MSP_USE_LEA
