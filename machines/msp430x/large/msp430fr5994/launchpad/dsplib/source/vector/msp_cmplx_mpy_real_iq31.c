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

msp_status msp_cmplx_mpy_real_iq31(const msp_cmplx_mpy_real_iq31_params *params, const _iq31 *srcCmplx, const _iq31 *srcReal, _iq31 *dst)
{
    uint16_t cmdId;
    uint16_t length;
    msp_status status;
    MSP_LEA_MPYLONGMATRIX_PARAMS *leaParams;
    
    /* Initialize the loop counter with the vector length. */
    length = params->length;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that the data arrays are aligned and in a valid memory segment. */
    if (!(MSP_LEA_VALID_ADDRESS(srcCmplx, 4) &
          MSP_LEA_VALID_ADDRESS(srcReal, 4) &
          MSP_LEA_VALID_ADDRESS(dst, 4))) {
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
        
    /* Allocate MSP_LEA_MPYLONGMATRIX_PARAMS structure. */
    leaParams = (MSP_LEA_MPYLONGMATRIX_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_MPYLONGMATRIX_PARAMS)/sizeof(uint32_t));

    /* Set MSP_LEA_MPYLONGMATRIX_PARAMS structure. */
    leaParams->input2 = MSP_LEA_CONVERT_ADDRESS(srcReal);
    leaParams->output = MSP_LEA_CONVERT_ADDRESS(dst);
    leaParams->vectorSize = length;
    leaParams->input1Offset = 2;
    leaParams->input2Offset = 1;
    leaParams->outputOffset = 2;

    /* Load source arguments to LEA. */
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(srcCmplx);
    LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);

#if (MSP_LEA_REVISION < MSP_LEA_REVISION_B)
    /* Load function into code memory */
    cmdId = msp_lea_loadCommand(LEACMD__MPYLONGMATRIX, MSP_LEA_MPYLONGMATRIX,
            sizeof(MSP_LEA_MPYLONGMATRIX)/sizeof(MSP_LEA_MPYLONGMATRIX[0]));
#else //MSP_LEA_REVISION
    /* Invoke the LEACMD__MPYLONGMATRIX command. */
    cmdId = LEACMD__MPYLONGMATRIX;
#endif //MSP_LEA_REVISION

    /* Invoke the command. */
    msp_lea_invokeCommand(cmdId);

    /* Reset MSP_LEA_MPYLONGMATRIX_PARAMS source 2 and dst pointers. */
    leaParams->input2 = MSP_LEA_CONVERT_ADDRESS(srcReal);
    leaParams->output = MSP_LEA_CONVERT_ADDRESS(&dst[1]);

    /* Load first source argument to LEA. */
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(&srcCmplx[1]);

    /* Invoke the command. */
    msp_lea_invokeCommand(cmdId);

    /* Free MSP_LEA_MPYLONGMATRIX_PARAMS structure. */
    msp_lea_freeMemory(sizeof(MSP_LEA_MPYLONGMATRIX_PARAMS)/sizeof(uint32_t));
    
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
    
msp_status msp_cmplx_mpy_real_iq31(const msp_cmplx_mpy_real_iq31_params *params, const _iq31 *srcCmplx, const _iq31 *srcReal, _iq31 *dst)
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
        /* Multiply CMPLX_REAL(srcA) and CMPLX_REAL(srcB) */
        MPYS32L = (uint16_t)CMPLX_REAL(srcReal);
        MPYS32H = (uint16_t)(CMPLX_REAL(srcReal) >> 16);
        OP2L    = (uint16_t)CMPLX_REAL(srcCmplx);
        OP2H    = (uint16_t)(CMPLX_REAL(srcCmplx) >> 16);
        *dstPtr++ = RES2;
        *dstPtr++ = RES3;

        /* Multiply CMPLX_IMAG(srcA) and CMPLX_REAL(srcB) */
        OP2L = (uint16_t)CMPLX_IMAG(srcCmplx);
        OP2H = (uint16_t)(CMPLX_IMAG(srcCmplx) >> 16);
        *dstPtr++ = RES2;
        *dstPtr++ = RES3;
        
        /* Increment pointers. */
        srcReal++;
        srcCmplx += CMPLX_INCREMENT;
    }
    
    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#else //__MSP430_HAS_MPY32__
    /* Loop through all vector elements. */
    while (length--) {
        /* Multiply srcCmplx and srcReal and store to dst. */
        *dst++ = __q31mpy(*srcCmplx++, *srcReal);   // real
        *dst++ = __q31mpy(*srcCmplx++, *srcReal++); // imaginary
    }
#endif //__MSP430_HAS_MPY32__

    return MSP_SUCCESS;
}

#endif //MSP_USE_LEA
