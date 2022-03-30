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

msp_status msp_biquad_df1_q15(const msp_biquad_df1_q15_params *params, const _q15 *src, _q15 *dst)
{
    uint16_t cmdId;
    uint16_t length;
    msp_status status;
    MSP_LEA_IIRBQ1_PARAMS *leaParams;
    
    /* Initialize local length variable. */
    length = params->length;
    
#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that length parameter is a multiple of two. */
    if (length & 1) {
        return MSP_SIZE_ERROR;
    }
    
    /* Check that the data arrays are aligned and in a valid memory segment. */
    if (!(MSP_LEA_VALID_ADDRESS(src, 4) &
          MSP_LEA_VALID_ADDRESS(dst, 4) &
          MSP_LEA_VALID_ADDRESS(params->states, 4) &
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

    /* Initialize LEA if it is not enabled. */
    if (!(LEAPMCTL & LEACMDEN)) {
        msp_lea_init();
    }
        
    /* Allocate MSP_LEA_IIRBQ1_PARAMS structure. */
    leaParams = (MSP_LEA_IIRBQ1_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_IIRBQ1_PARAMS)/sizeof(uint32_t));
    
    /* Set MSP_LEA_IIR_PARAMS structure. */
    leaParams->vectorSizeBy2 = length >> 1;
    leaParams->output = MSP_LEA_CONVERT_ADDRESS(dst);
    leaParams->state = MSP_LEA_CONVERT_ADDRESS(params->states);
    leaParams->coeffs = MSP_LEA_CONVERT_ADDRESS(params->coeffs);
    leaParams->direction = 1;

    /* Load source arguments to LEA. */
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(src);
    LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);

#if (MSP_LEA_REVISION < MSP_LEA_REVISION_B)
    /* Load function into code memory */
    cmdId = msp_lea_loadCommand(LEACMD__IIRBQ1, MSP_LEA_IIRBQ1,
            sizeof(MSP_LEA_IIRBQ1)/sizeof(MSP_LEA_IIRBQ1[0]));
#else //MSP_LEA_REVISION
    /* Invoke the LEACMD__IIRBQ1 command. */
    cmdId = LEACMD__IIRBQ1;
#endif //MSP_LEA_REVISION
    
    /* Invoke the command. */
    msp_lea_invokeCommand(cmdId);

    /* Free MSP_LEA_IIRBQ1_PARAMS structure. */
    msp_lea_freeMemory(sizeof(MSP_LEA_IIRBQ1_PARAMS)/sizeof(uint32_t));
        
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

msp_status msp_biquad_df1_q15(const msp_biquad_df1_q15_params *params, const _q15 *src, _q15 *dst)
{
    uint16_t i;
    uint16_t length;
    int16_t x2, x1, y2, y1;
    const msp_biquad_df1_q15_coeffs *coeffs;

    /* Initialize local variables and pointers. */
    length = params->length;
    coeffs = params->coeffs;
    x2 = params->states->x2;
    x1 = params->states->x1;
    y2 = params->states->y2;
    y1 = params->states->y1;
    
#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that length parameter is a multiple of two. */
    if (length & 1) {
        return MSP_SIZE_ERROR;
    }
#endif //MSP_DISABLE_DIAGNOSTICS

#if defined(__MSP430_HAS_MPY32__)
    /* If MPY32 is available save control context and set to fractional mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN | MPYSAT;

    /* Calculate filtered output using direct form 1. */
    for (i = 0; i < length; i++) {
        /* Process and update input states. */
        MPYS = x2;      OP2  = coeffs->b2;
        MACS = x1;      OP2  = coeffs->b1By2;
                        OP2  = coeffs->b1By2;
        x2 = x1;        x1 = *src++;
        MACS = x1;      OP2  = coeffs->b0;

        /* Process and update output states and result. */
        MACS = y2;      OP2 =  coeffs->a2;
        MACS = y1;      OP2  = coeffs->a1By2;
                        OP2 =  coeffs->a1By2;
        y2 = y1;        y1 = RESHI;
        *dst++ = y1;
    }
        
    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#else
    int32_t temp;
    int32_t result;

    /* Calculate filtered output using direct form 1. */
    for (i = 0; i < length; i++) {
        /* Process and update input states. */
        result  = __q15mpy(x2, coeffs->b2);
        temp    = __q15mpy(x1, coeffs->b1By2);
        result += temp;     result += temp;
        x2 = x1;            x1 = *src++;
        result += __q15mpy(x1, coeffs->b0);

        /* Process and update output states and result. */
        result += __q15mpy(y2, coeffs->a2);
        temp    = __q15mpy(y1, coeffs->a1By2);
        result += temp;     result += temp;
        result = (_q15)__saturate(result, INT16_MIN, INT16_MAX);
        y2 = y1;            y1 = result;
        *dst++ = y1;
    }
#endif

    /* Store the states and return. */
    params->states->x2 = x2;
    params->states->x1 = x1;
    params->states->y2 = y2;
    params->states->y1 = y1;
    
    return MSP_SUCCESS;
}

#endif //MSP_USE_LEA
