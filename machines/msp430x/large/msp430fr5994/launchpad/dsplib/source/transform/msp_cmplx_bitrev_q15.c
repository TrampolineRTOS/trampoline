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

msp_status msp_cmplx_bitrev_q15(const msp_cmplx_bitrev_q15_params *params, _q15 *src)
{
    uint16_t cmdId;
    msp_status status;
    uint16_t length;
    uint16_t sqrtLength;
    MSP_LEA_BITREVERSECOMPLEX_PARAMS *leaParams;
    
    /* Save input length to local. */
    length = params->length;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that the length is a power of two. */
    if ((length & (length-1))) {
        return MSP_SIZE_ERROR;
    }
    
    /* Check that the data arrays are aligned and in a valid memory segment. */
    if (!(MSP_LEA_VALID_ADDRESS(src, 4))) {
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
    
    /* Check vector size to determine which bit reverse function to use. */
    sqrtLength = 1;
    while (length > 2) {
        sqrtLength <<= 1;
        length >>= 2;
    }
        
    /* Allocate MSP_LEA_BITREVERSECOMPLEX_PARAMS structure. */
    leaParams = (MSP_LEA_BITREVERSECOMPLEX_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_BITREVERSECOMPLEX_PARAMS)/sizeof(uint32_t));
    
    /* Initialize MSP_LEA_BITREVERSECOMPLEX_PARAMS structure. */
    leaParams->sqrtVectorSize = sqrtLength;
    LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(src);
    LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);
    
    /* Check if remainder is even or odd to determine which LEA function to use. */
    if (length == 2) {
        /* Invoke the LEACMD__BITREVERSECOMPLEXODD command. */
        cmdId = LEACMD__BITREVERSECOMPLEXODD;
    }
    else {
        /* Invoke the LEACMD__BITREVERSECOMPLEXEVEN command. */
        cmdId = LEACMD__BITREVERSECOMPLEXEVEN;
    }
    
    /* Invoke the command. */
    msp_lea_invokeCommand(cmdId);

    /* Free MSP_LEA_BITREVERSECOMPLEX_PARAMS structure. */
    msp_lea_freeMemory(sizeof(MSP_LEA_BITREVERSECOMPLEX_PARAMS)/sizeof(uint32_t));
    
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
 * Perform an in-place bit reversal of the complex input array using a lookup
 * table.
 */
msp_status msp_cmplx_bitrev_q15(const msp_cmplx_bitrev_q15_params *params, _q15 *src)
{
    uint16_t i;                     // loop counter
    uint16_t index;                 // left justified index
    uint16_t indexInc;              // index increment
    uint16_t length;                // src length
    uint16_t indexBitRev;           // index bit reversal
    uint32_t temp;                  // Temporary storage
    uint32_t *srcPtr;               // Treat complex data pairs as 32-bit data
    
    /* Initialize source pointer and length. */
    srcPtr = (uint32_t *)src;
    length = params->length;
    index = 0;
    indexInc = 2;
    
    /* Calculate index increment for left justified index. */
    while (length < 0x8000) {
        indexInc <<= 1;
        length <<= 1;
    }
        
#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that the length is a power of two. */
    if (length != 0x8000) {
        return MSP_SIZE_ERROR;
    }
#endif //MSP_DISABLE_DIAGNOSTICS
    
    /* In-place bit-reversal using fixed table length. */
    length = params->length;
    for (i = 0; i < length; i++, index += indexInc) {
        /* Calculate bit reversed index. */
        indexBitRev = ((uint16_t)msp_cmplx_bitrev_table_ui8[index & 0xff] << 8)
            + ((uint16_t)msp_cmplx_bitrev_table_ui8[(index >> 8) & 0xff]);
        
        if (i < indexBitRev) {
            /* Swap inputs. */
            temp = srcPtr[i];
            srcPtr[i] = srcPtr[indexBitRev];
            srcPtr[indexBitRev] = temp;
        }
    }
    
    return MSP_SUCCESS;
}

#endif //MSP_USE_LEA
