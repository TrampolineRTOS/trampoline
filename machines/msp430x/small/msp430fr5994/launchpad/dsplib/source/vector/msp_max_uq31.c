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

msp_status msp_max_uq31(const msp_max_uq31_params *params, const _uq31 *src, _uq31 *max, uint16_t *index)
{
    uint16_t cmdId;
    uint16_t length;
    uint32_t *output;
    msp_status status;
    MSP_LEA_MAXLONGUNSIGNED_PARAMS *leaParams;
    
    /* Initialize the loop counter with the vector length. */
    length = params->length;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that the data arrays are aligned and in a valid memory segment. */
    if (!(MSP_LEA_VALID_ADDRESS(src, 4))) {
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
        
    /* Allocate MSP_LEA_MAXLONGUNSIGNED_PARAMS structure. */
    leaParams = (MSP_LEA_MAXLONGUNSIGNED_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_MAXLONGUNSIGNED_PARAMS)/sizeof(uint32_t));

    /* Allocate output vector of length two. */
    output = (uint32_t *)msp_lea_allocMemory(2*sizeof(uint32_t)/sizeof(uint32_t));

    /* Set MSP_LEA_MAXLONGUNSIGNED_PARAMS structure. */
    leaParams->vectorSize = length;
    leaParams->output = MSP_LEA_CONVERT_ADDRESS(output);
    leaParams->inputOffset = 1;

    /* Load source arguments to LEA. */
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(src);
    LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);

#if (MSP_LEA_REVISION < MSP_LEA_REVISION_B)
    /* Load function into code memory */
    cmdId = msp_lea_loadCommand(LEACMD__MAXUNSIGNEDLONGMATRIX, MSP_LEA_MAXUNSIGNEDLONGMATRIX,
            sizeof(MSP_LEA_MAXUNSIGNEDLONGMATRIX)/sizeof(MSP_LEA_MAXUNSIGNEDLONGMATRIX[0]));
#else //MSP_LEA_REVISION
    /* Invoke the LEACMD__MAXUNSIGNEDLONGMATRIX command. */
    cmdId = LEACMD__MAXUNSIGNEDLONGMATRIX;
#endif //MSP_LEA_REVISION

    /* Invoke the command. */
    msp_lea_invokeCommand(cmdId);
    
    /* Write results. */
    *max = output[0];
    *index = output[1];

    /* Free MSP_LEA_MAXLONGUNSIGNED_PARAMS structure and output vector. */
    msp_lea_freeMemory(2*sizeof(uint32_t)/sizeof(uint32_t));
    msp_lea_freeMemory(sizeof(MSP_LEA_MAXLONGUNSIGNED_PARAMS)/sizeof(uint32_t));
    
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

msp_status msp_max_uq31(const msp_max_uq31_params *params, const _uq31 *src, _uq31 *max, uint16_t *index)
{
    uint16_t i;
    _uq31 temp;
    _uq31 maximum;
    uint16_t length;
    
    /* Initialize the loop counter with the vector length. */
    length = params->length;
    
    /* Initialize the maximum value and index. */
    maximum = 0;
    i = 0;
    
    /* Loop through all vector elements. */
    while (length--) {
        /* Store vector element to local variable. */
        temp = *src++;
        
        /* Compare vector element with current maximum value. */
        if (temp >= maximum) {
            /* Update maximum value and index. */
            maximum = temp;
            i = length;
        }
    }
    
    /* Save local maximum and index to output arguments. */
    *max = maximum;
    *index = params->length - (i + 1);

    return MSP_SUCCESS;
}

#endif //MSP_USE_LEA
