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

msp_status msp_split_iq31(const msp_split_iq31_params *params, int32_t *src)
{
    uint16_t i;
    uint16_t log2Size;
    uint16_t length;
    msp_status status;
    MSP_LEA_FFTLONG_PARAMS *leaParams;
    
    /* Get vector length parameter. */
    length = params->length;
    
    /* Calculate log2Size parameter. */
    i = length;
    log2Size = 0;
    while (i > 1) {
        log2Size++;
        i >>= 1;
    }

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that the length is a power of two. */
    if ((length & (length-1))) {
        return MSP_SIZE_ERROR;
    }
    
    /* Check that the data arrays are aligned and in a valid memory segment. */
    if (!(MSP_LEA_VALID_ADDRESS(src, length))) {
        return MSP_LEA_INVALID_ADDRESS;
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
        
    /* Allocate MSP_LEA_FFTLONG_PARAMS structure. */
    leaParams = (MSP_LEA_FFTLONG_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_FFTLONG_PARAMS)/sizeof(uint32_t));

    /* Set MSP_LEA_FFTLONG_PARAMS structure. */
    leaParams->vectorSize = length;
    leaParams->log2Size = log2Size;
    
    /* Load source arguments to LEA. */
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(src);
    LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);

    /* Invoke the LEACMD__FFTLONG command. */
    msp_lea_invokeCommand(LEACMD__FFTLONG);

    /* Free MSP_LEA_FFTLONG_PARAMS structure. */
    msp_lea_freeMemory(sizeof(MSP_LEA_FFTLONG_PARAMS)/sizeof(uint32_t));
    
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

/*
 * This function performs the last stage of a real FFT of size M in place.
 * Before this step is performed, a size M/2 complex FFT must be performed
 * on the input data with bit reversal. This algorithm has been optimized
 * to use a single coefficient lookup table and a reduced number of multiply
 * operations. The complex result G(k) where k = 0,1,2...N-1 and N = M/2 is
 * calculated as follows:
 *
 *     G(k) = 0.5*(X(k) + X*(N-k)) - 0.5*j*(e^-j2*pi*k/2N)*(X(k) - X*(N-k))
 *
 * This can be optimized by calculating G(N-k) in parallel using the following
 * simplification:
 *
 *     G(N-k) = 0.5*(X(N-k) + X*(N-(N-k))) - 0.5*j*(e^-j2*pi*(N-k)/2N)*(X(N-k) - X*(N-(N-k)))
 *     G(N-k) = 0.5*(X(N-k) + X*(k)) - 0.5*j*(e^-j2*pi*(N-k)/2N)*(X(N-k) - X*(k))
 *     G(N-k) = 0.5*(X(N-k) + X*(k)) - 0.5*j*-(e^-j2*pi*(N-k)/2N)*(X*(k) - X(N-k))
 *     G(N-k) = 0.5*(X(k) + X*(N-k))* - 0.5*j*((e^-j2*pi*k/2N)*(X(k) - X*(N-k)))*
 *
 * The common components of G(k) and G(N-k) can be calculated once as local
 * variables A and B:
 *
 *     A(k) = 0.5*(X(k) + X*(N-k))
 *     B(k) = 0.5*(e^-j2*pi*k/2N)*(X(k) - X*(N-k))
 *
 * Finally, performing substitutions to the G(k) and G(N-k) equations yields
 * the following optimized equations:
 * 
 *     G(k) = A(k) - j*B(k)
 *     G(N-k) = A*(k) - j*B*(k)
 * 
 * Reference: http://www.ti.com/lit/an/spra291/spra291.pdf
 */
msp_status msp_split_iq31(const msp_split_iq31_params *params, int32_t *src)
{
    uint16_t length;            // src length
    uint16_t tableLength;       // Coefficient table length
    uint16_t coeffOffset;       // Coefficient table increment
    int32_t aR;                 // Temp variable
    int32_t aI;                 // Temp variable
    int32_t bR;                 // Temp variable
    int32_t bI;                 // Temp variable
    int32_t cR;                 // Temp variable
    int32_t cI;                 // Temp variable
    int32_t *srcPtrK;           // Source pointer to X(k)
    int32_t *srcPtrNK;          // Source pointer to X(N-k)
    const int16_t *coeffPtr;    // Coefficient pointer
    
    /* Save input length to local. */
    length = params->length;
    
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
    
    /* 
     * Calculate the first result bin (DC component).
     *
     *     X(N) = X(0)
     *     G(0) = 0.5*(X(0) + X*(0)) - j*0.5*(e^-j*0)*(X(0) - X*(0))
     *     G(0) = Xr(0) + Xi(0)
     */
    CMPLX_REAL(src) = (CMPLX_REAL(src) + CMPLX_IMAG(src)) << 1;
    CMPLX_IMAG(src) = 0;
    
    /* Initialize Src(k) and Src(N/2-k) pointers when k=1. */
    srcPtrK = src + CMPLX_INCREMENT;
    srcPtrNK = src + length - CMPLX_INCREMENT;
    
    /* Calculate coefficient table offset. */
    coeffOffset = 2;
    tableLength = *(uint16_t *)params->twiddleTable;
    while (length < tableLength) {
        coeffOffset *= 2;
        length *= 2;
    }
    
    /* Initialize coefficient pointer to index k=1. */
    coeffPtr = &params->twiddleTable[DSPLIB_TABLE_OFFSET] + coeffOffset;
    
    /*
     * Initialize length of split operations to perform. G(k) and G(N/2-k) are
     * calculated in the same loop iteration so only half of the N/2 iterations
     * are required, N/4. The last iteration where k = N/2-k will be calculated
     * separately.
     */
    length = (params->length >> 2) - 1;
    
    /* If MPY32 is available save control context and set to fractional mode. */
#if defined(__MSP430_HAS_MPY32__)
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN;
#endif
    
    /* Loop through and perform all of the split operations. */
    while(length--) {
        /* Calculate X(k) - X*(N-k) to local temporary variables. */
        bR = CMPLX_REAL(srcPtrK) - CMPLX_REAL(srcPtrNK);
        bI = CMPLX_IMAG(srcPtrK) + CMPLX_IMAG(srcPtrNK);
        
        /* B(k) = 0.5*(e^-j2*pi*k/2N)*(X(k) - X(N-k)) */
        cR = CMPLX_REAL(coeffPtr);
        cI = CMPLX_IMAG(coeffPtr);
        __q15iq31cmpy(&cR, &cI, &bR, &bI);
        bR = cR; bI = cI;
        
        /*
         * Ar(k) = 0.5*(Xr(k) + Xr(N-k))
         * Ai(k) = 0.5*(Xi(k) - Xi(N-k))
         */
        aR = (CMPLX_REAL(srcPtrK) + CMPLX_REAL(srcPtrNK));
        aI = (CMPLX_IMAG(srcPtrK) - CMPLX_IMAG(srcPtrNK));
        
        /*
         * Gr(k) = Ar(k) + Bi(k)
         * Gi(k) = Ai(k) - Br(k)
         * Gr(N-k) = Ar(k) - Bi(k)
         * Gi(N-k) = -(Ai(k) + Br(k))
         */
        CMPLX_REAL(srcPtrK) = aR + bI;
        CMPLX_IMAG(srcPtrK) = aI - bR;
        CMPLX_REAL(srcPtrNK) = aR - bI;
        CMPLX_IMAG(srcPtrNK) = -(aI + bR);
        
        /* Update pointers. */
        srcPtrK += CMPLX_INCREMENT;
        srcPtrNK -= CMPLX_INCREMENT;
        coeffPtr += coeffOffset;
    }
    
    /* Restore MPY32 control context. */
#if defined(__MSP430_HAS_MPY32__)
    MPY32CTL0 = ui16MPYState;
#endif
    
    /* 
     * Calculate the last result bin where k = N/2-k.
     *
     *     X(k) = X(N-k)
     *     G(k) = 0.5*(X(k) + X*(k)) - j*0.5*(e^-j*pi/2)*(X(k) - X*(k))
     *     G(k) = 0.5(2*Xr(k)) - j*0.5*(-j)*(2*j*Xi(k))
     *     G(k) = Xr(k) - j*Xi(k)
     */
    CMPLX_REAL(srcPtrK) = CMPLX_REAL(srcPtrK) << 1;
    CMPLX_IMAG(srcPtrK) = -(CMPLX_IMAG(srcPtrK) << 1);
    
    return MSP_SUCCESS;
}

#endif //MSP_USE_LEA
