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

msp_status msp_cmplx_fft_auto_q15(const msp_cmplx_fft_q15_params *params, _q15 *src, uint16_t *shift)
{
    uint16_t cmdId;
    uint16_t log2Size;
    uint16_t length;
    msp_status status;
    MSP_LEA_FFTCOMPLEXAUTOSCALING_PARAMS *leaParams;
    
    /* Save input length to local. */
    length = params->length;
    
    /* Bit reverse the order of the inputs. */
    if(params->bitReverse) {
        /* Create and initialize a bit reversal params structure. */
        msp_cmplx_bitrev_q15_params paramsBitRev;
        paramsBitRev.length = params->length;
        
        /* Perform bit reversal on source data. */
        status = msp_cmplx_bitrev_q15(&paramsBitRev, src);
        
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
    if (!(MSP_LEA_VALID_ADDRESS(src, length*2))) {
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
        
    /* Allocate MSP_LEA_FFTCOMPLEXAUTOSCALING_PARAMS structure. */
    leaParams = (MSP_LEA_FFTCOMPLEXAUTOSCALING_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_FFTCOMPLEXAUTOSCALING_PARAMS)/sizeof(uint32_t));

    /* Set MSP_LEA_FFTCOMPLEXAUTOSCALING_PARAMS structure. */
    leaParams->vectorSizeBy2 = length >> 1;
    leaParams->log2Size = log2Size;
    
    /* Load source arguments to LEA. */
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(src);
    LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);

#if (MSP_LEA_REVISION < MSP_LEA_REVISION_B)
    /* Load function into code memory */
    cmdId = msp_lea_loadCommand(LEACMD__FFTCOMPLEXAUTOSCALING, MSP_LEA_FFTCOMPLEXAUTOSCALING,
            sizeof(MSP_LEA_FFTCOMPLEXAUTOSCALING)/sizeof(MSP_LEA_FFTCOMPLEXAUTOSCALING[0]));
#else //MSP_LEA_REVISION
    /* Invoke the LEACMD__FFTCOMPLEXAUTOSCALING command. */
    cmdId = LEACMD__FFTCOMPLEXAUTOSCALING;
#endif //MSP_LEA_REVISION.
    
    /* Invoke the command. */
    msp_lea_invokeCommand(cmdId);
    
    /* Get auto-scaling result */
    *shift = LEAPMDST;

    /* Free MSP_LEA_FFTCOMPLEXAUTOSCALING_PARAMS structure. */
    msp_lea_freeMemory(sizeof(MSP_LEA_FFTCOMPLEXAUTOSCALING_PARAMS)/sizeof(uint32_t));
    
    /* Set status flag. */
    status = MSP_SUCCESS;
        
#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check LEA interrupt flags for any errors. */
    if (msp_lea_ifg & LEACOVLIFG) {
        status = MSP_LEA_COMMAND_OVERFLOW;
    }
    else if (msp_lea_ifg & LEAOORIFG) {
        status = MSP_LEA_OUT_OF_RANGE;
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

static inline void msp_cmplx_overflow_q15(int16_t *src, bool *overflow);
static inline void msp_cmplx_btfly_auto_q15(int16_t *srcA, int16_t *srcB, const _q15 *coeff, bool *scale, bool *overflow);
static inline void msp_cmplx_btfly_c0_auto_q15(int16_t *srcA, int16_t *srcB, bool *scale, bool *overflow);
static inline void msp_cmplx_btfly_c1_auto_q15(int16_t *srcA, int16_t *srcB, bool *scale, bool *overflow);

/*
 * Perform in-place radix-2 DFT of the input signal using an algorithm optimized
 * for MSP430 with fixed scaling by two at each stage.
 */
msp_status msp_cmplx_fft_auto_q15(const msp_cmplx_fft_q15_params *params, int16_t *src, uint16_t *shift)
{
    bool scale;                         // scale flag
    bool overflow;                      // overflow flag
    int16_t i, j;                       // loop counters
    uint16_t step;                      // step size
    uint16_t length;                    // src length
    uint16_t twiddleIndex;              // twiddle table index
    uint16_t twiddleIncrement;          // twiddle table increment
    int16_t *srcPtr;                    // local source pointer
    const _q15 *twiddlePtr;             // twiddle table pointer
    msp_status status;                  // Status of the operation
    
    /* Save input length to local. */
    length = params->length;
    
    /* Bit reverse the order of the inputs. */
    if(params->bitReverse) {
        /* Create and initialize a bit reversal params structure. */
        msp_cmplx_bitrev_q15_params paramsBitRev;
        paramsBitRev.length = params->length;
        
        /* Perform bit reversal on source data. */
        status = msp_cmplx_bitrev_q15(&paramsBitRev, src);
        
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
    
    /* Initialize shift result. */
    *shift = 0;
    
    /* Check for initial overflow. */
    overflow = false;
    for (i = 0 ; i < length; i++) {
        msp_cmplx_overflow_q15(&src[i*2], &overflow);
    }

    /* Stage 1. */
    scale = overflow;
    overflow = false;
    *shift += scale ? 1 : 0;
    if (STAGE1_STEP <= length) {
        for (j = 0; j < length; j += STAGE1_STEP) {
            srcPtr = src + j*2;
            msp_cmplx_btfly_c0_auto_q15(&srcPtr[0], &srcPtr[0+STAGE1_STEP], &scale, &overflow);
        }
    }
    
    /* Stage 2. */
    scale = overflow;
    overflow = false;
    *shift += scale ? 1 : 0;
    if (STAGE2_STEP <= length) {
        for (j = 0; j < length; j += STAGE2_STEP) {
            srcPtr = src + j*2;
            msp_cmplx_btfly_c0_auto_q15(&srcPtr[0], &srcPtr[0+STAGE2_STEP], &scale, &overflow);
            msp_cmplx_btfly_c1_auto_q15(&srcPtr[2], &srcPtr[2+STAGE2_STEP], &scale, &overflow);
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
        
        /* Set scale and overflow flags. */
        scale = overflow;
        overflow = false;
        *shift += scale ? 1 : 0;
        
        for (i = 0; i < (step/2); i++) {            
            /* Perform butterfly operations on complex pairs. */
            for (j = i; j < length; j += step) {
                srcPtr = src + j*2;
                msp_cmplx_btfly_auto_q15(srcPtr, srcPtr + step, &twiddlePtr[twiddleIndex], &scale, &overflow);
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

#define MSP_OVERFLOW_MAX        (INT16_MAX >> 2)
#define MSP_OVERFLOW_MIN        (INT16_MIN >> 2)

/*
 * Abstracted helper function to check for overflow.
 */
static inline void msp_cmplx_overflow_q15(int16_t *src, bool *overflow)
{
    if ((CMPLX_REAL(src) > MSP_OVERFLOW_MAX) || (CMPLX_REAL(src) < MSP_OVERFLOW_MIN)) {
        *overflow = true;
    }
    if ((CMPLX_IMAG(src) > MSP_OVERFLOW_MAX) || (CMPLX_IMAG(src) < MSP_OVERFLOW_MIN)) {
        *overflow = true;
    }
}

/*
 * Abstracted helper functions for a radix-2 butterfly operation. The following
 * operation is performed at each stage:
 *     A = A + coeff*B
 *     B = A - coeff*B
 * 
 * If overflow is detected the result is scaled by two:
 *     A = A/2
 *     B = A/2
 */
static inline void msp_cmplx_btfly_auto_q15(int16_t *srcA, int16_t *srcB, const _q15 *coeff, bool *scale, bool *overflow)
{
    /* Load coefficients. */
    _q15 tempR = CMPLX_REAL(coeff);
    _q15 tempI = CMPLX_IMAG(coeff);
    
    /* Calculate real and imaginary parts of coeff*B. */
    __q15cmpy(&tempR, &tempI, &CMPLX_REAL(srcB), &CMPLX_IMAG(srcB));
    
    /* Scale result if necessary. */
    if (*scale) {
        /* B = (A - coeff*B)/2 */
        CMPLX_REAL(srcB) = (CMPLX_REAL(srcA) - tempR) >> 1;
        CMPLX_IMAG(srcB) = (CMPLX_IMAG(srcA) - tempI) >> 1;
        
        /* A = (A + coeff*B)/2 */
        CMPLX_REAL(srcA) = (CMPLX_REAL(srcA) + tempR) >> 1;
        CMPLX_IMAG(srcA) = (CMPLX_IMAG(srcA) + tempI) >> 1;
    }
    else {
        /* B = A - coeff*B */
        CMPLX_REAL(srcB) = CMPLX_REAL(srcA) - tempR;
        CMPLX_IMAG(srcB) = CMPLX_IMAG(srcA) - tempI;
        
        /* A = A + coeff*B */
        CMPLX_REAL(srcA) = CMPLX_REAL(srcA) + tempR;
        CMPLX_IMAG(srcA) = CMPLX_IMAG(srcA) + tempI;
    }
    
    /* Check for possibility of overflow. */
    if (!*overflow) {
        msp_cmplx_overflow_q15(srcA, overflow);
        msp_cmplx_overflow_q15(srcB, overflow);
    }
}

/*
 * Simplified radix-2 butterfly operation for e^(-2*pi*(0/4)). This abstracted
 * helper function takes advantage of the fact the the twiddle coefficients are
 * positive and negative one for a multiplication by e^(-2*pi*(0/4)). The
 * following operation is performed at each stage:
 *     A = A + (1+0j)*B
 *     B = A - (1+0j)*B
 * 
 * If overflow is detected the result is scaled by two:
 *     A = A/2
 *     B = A/2
 */
static inline void msp_cmplx_btfly_c0_auto_q15(int16_t *srcA, int16_t *srcB, bool *scale, bool *overflow)
{
    int16_t tempR = CMPLX_REAL(srcB);
    int16_t tempI = CMPLX_IMAG(srcB);
    
    /* Scale result if necessary. */
    if (*scale) {
        /* B = (A - (1+0j)*B)/2 */
        CMPLX_REAL(srcB) = (CMPLX_REAL(srcA) - tempR) >> 1;
        CMPLX_IMAG(srcB) = (CMPLX_IMAG(srcA) - tempI) >> 1;
        
        /* A = (A + (1+0j)*B)/2 */
        CMPLX_REAL(srcA) = (CMPLX_REAL(srcA) + tempR) >> 1;
        CMPLX_IMAG(srcA) = (CMPLX_IMAG(srcA) + tempI) >> 1;
    }
    else {
        /* B = A - coeff*B */
        CMPLX_REAL(srcB) = CMPLX_REAL(srcA) - tempR;
        CMPLX_IMAG(srcB) = CMPLX_IMAG(srcA) - tempI;
        
        /* A = A + coeff*B */
        CMPLX_REAL(srcA) = CMPLX_REAL(srcA) + tempR;
        CMPLX_IMAG(srcA) = CMPLX_IMAG(srcA) + tempI;
    }
    
    /* Check for possibility of overflow. */
    if (!*overflow) {
        msp_cmplx_overflow_q15(srcA, overflow);
        msp_cmplx_overflow_q15(srcB, overflow);
    }
}

/*
 * Simplified radix-2 butterfly operation for e^(-2*pi*(1/4)). This abstracted
 * helper function takes advantage of the fact the the twiddle coefficients are
 * positive and negative one for a multiplication by e^(-2*pi*(1/4)).  The
 * following operation is performed at each stage:
 *     A = A + (0-1j)*B
 *     B = A - (0-1j)*B
 * 
 * If overflow is detected the result is scaled by two:
 *     A = A/2
 *     B = A/2
 */
static inline void msp_cmplx_btfly_c1_auto_q15(int16_t *srcA, int16_t *srcB, bool *scale, bool *overflow)
{
    int16_t tempR = CMPLX_REAL(srcB);
    int16_t tempI = CMPLX_IMAG(srcB);
    
    /* Scale result if necessary. */
    if (*scale) {
        /* B = (A - (0-1j)*B)/2 */
        CMPLX_REAL(srcB) = (CMPLX_REAL(srcA) - tempI) >> 1;
        CMPLX_IMAG(srcB) = (CMPLX_IMAG(srcA) + tempR) >> 1;
        
        /* A = (A + (0-1j)*B)/2 */
        CMPLX_REAL(srcA) = (CMPLX_REAL(srcA) + tempI) >> 1;
        CMPLX_IMAG(srcA) = (CMPLX_IMAG(srcA) - tempR) >> 1;
    }
    else {
        /* B = A - coeff*B */
        CMPLX_REAL(srcB) = CMPLX_REAL(srcA) - tempI;
        CMPLX_IMAG(srcB) = CMPLX_IMAG(srcA) + tempR;
        
        /* A = A + coeff*B */
        CMPLX_REAL(srcA) = CMPLX_REAL(srcA) + tempI;
        CMPLX_IMAG(srcA) = CMPLX_IMAG(srcA) - tempR;
    }
    
    /* Check for possibility of overflow. */
    if (!*overflow) {
        msp_cmplx_overflow_q15(srcA, overflow);
        msp_cmplx_overflow_q15(srcB, overflow);
    }
}

#endif //MSP_USE_LEA
