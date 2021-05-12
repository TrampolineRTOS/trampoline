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
 * Optimized helper function for shift right with complex conjugate, used for
 * inverse FFT functions.
 */    
static inline msp_status msp_cmplx_shift_right_conj_iq31(const _iq31 *src, _iq31 *dst, uint16_t length, uint8_t shift);

/*
 * Perform element wise left or right shift of a single complex source vector.
 */
msp_status msp_cmplx_shift_iq31(const msp_cmplx_shift_iq31_params *params, const _iq31 *src, _iq31 *dst)
{
    int8_t shift;
    uint16_t length;
    msp_shift_iq31_params shiftParams;
    msp_cmplx_conj_iq31_params conjParams;
    
    /* Initialize the loop counter and shift variables. */
    length = params->length;
    shift = params->shift;

    /* If conjugate is not enabled use real version. */
    if (!params->conjugate) {
        shiftParams.shift = params->shift;
        shiftParams.length = params->length << 1;
        return msp_shift_iq31(&shiftParams, src, dst);
    }
    else {
#ifndef MSP_DISABLE_DIAGNOSTICS
        /* Verify the shift parameter. */
        if ((shift > 31) || (shift < -31)) {
            return MSP_SHIFT_SIZE_ERROR;
        }
#endif //MSP_DISABLE_DIAGNOSTICS

        /* Shift src array left for a positive shift parameter. */
        if (shift > 0) {
            /* Loop through all vector elements. */
            while (length--) {
                /* Shift src left by the shift parameter and store to dst. */
                *dst++ = *src++ << shift;
                *dst++ = -(*src++ << shift);
            }
            return MSP_SUCCESS;
        }
        /* Shift src array right for a negative shift parameter. */
        else if (shift < 0) {
            /* Use optimized helper function. */
            return msp_cmplx_shift_right_conj_iq31(src, dst, length, -shift);
        }
        else {
            /* No shift, just return conjugate. */
            conjParams.length = length;
            return msp_cmplx_conj_iq31(&conjParams, src, dst);
        }
    }
}

#if defined(MSP_USE_LEA)

/* Shift factor lookup table. */
extern const uint32_t msp_shift_right_factor_iq31[32];
    
static inline msp_status msp_cmplx_shift_right_conj_iq31(const _iq31 *src, _iq31 *dst, uint16_t length, uint8_t shift)
{
    uint16_t cmdId;
    int32_t shiftValue;
    int32_t *shiftVector;
    uint32_t leaFlags;
    msp_status status;
    MSP_LEA_MPYLONGMATRIX_PARAMS *leaParams;
    
    /* Lookup the fractional shift value. */
    shiftValue = msp_shift_right_factor_iq31[shift & 0x1f];

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that the data arrays are aligned and in a valid memory segment. */
    if (!(MSP_LEA_VALID_ADDRESS(src, 4) && MSP_LEA_VALID_ADDRESS(dst, 4))) {
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
        
    /* Allocate shift vector of length one. */
    shiftVector = (int32_t *)msp_lea_allocMemory(sizeof(int32_t)/sizeof(uint32_t));
    shiftVector[0] = shiftValue;

    /* Set MSP_LEA_MPYLONGMATRIX_PARAMS structure. */
    leaParams->input2 = MSP_LEA_CONVERT_ADDRESS(shiftVector);
    leaParams->output = MSP_LEA_CONVERT_ADDRESS(&CMPLX_REAL(dst));
    leaParams->vectorSize = length;
    leaParams->input1Offset = 2;
    leaParams->input2Offset = 0;
    leaParams->outputOffset = 2;

    /* Load source arguments to LEA. */
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(&CMPLX_REAL(src));
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
    
    /* Save flags status before invoking the next command. */
    leaFlags = msp_lea_ifg;
    
    /* Rerun the shift operation for imaginary components. */
    shiftVector[0] = -shiftValue;
    leaParams->output = MSP_LEA_CONVERT_ADDRESS(&CMPLX_IMAG(dst));
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(&CMPLX_IMAG(src));
    LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);

    /* Invoke the command. */
    msp_lea_invokeCommand(cmdId);

    /* Free MSP_LEA_MPYLONGMATRIX_PARAMS structure and shift vector. */
    msp_lea_freeMemory(sizeof(int32_t)/sizeof(uint32_t));
    msp_lea_freeMemory(sizeof(MSP_LEA_MPYLONGMATRIX_PARAMS)/sizeof(uint32_t));
    
    /* Add flags to result. */
    leaFlags |= msp_lea_ifg;
    
    /* Set status flag. */
    status = MSP_SUCCESS;
    
#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check LEA interrupt flags for any errors. */
    if (leaFlags & LEACOVLIFG) {
        status = MSP_LEA_COMMAND_OVERFLOW;
    }
    else if (leaFlags & LEAOORIFG) {
        status = MSP_LEA_OUT_OF_RANGE;
    }
    else if (leaFlags & LEASDIIFG) {
        status = MSP_LEA_SCALAR_INCONSISTENCY;
    }
#endif

    /* Free lock for LEA module and return status. */
    msp_lea_freeLock();
    return status;
}

#else //MSP_USE_LEA
    
static inline msp_status msp_cmplx_shift_right_conj_iq31(const _iq31 *src, _iq31 *dst, uint16_t length, uint8_t shift)
{    
    /* Loop through all vector elements. */
    while (length--) {
        /* Shift src right by the negated shift parameter and store to dst. */
        *dst++ = *src++ >> shift;
        *dst++ = -(*src++ >> shift);
    }

    return MSP_SUCCESS;
}

#endif //MSP_USE_LEA
