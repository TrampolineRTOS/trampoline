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

msp_status msp_matrix_mpy_iq31(const msp_matrix_mpy_iq31_params *params, const _iq31 *srcA, const _iq31 *srcB, _iq31 *dst)
{
    uint16_t i;
    uint16_t j;
    uint16_t cmdId;
    uint16_t srcARows;
    uint16_t srcACols;
    uint16_t srcBRows;
    uint16_t srcBCols;
    msp_status status;
    MSP_LEA_MACLONG_PARAMS *leaParams;

    /* Initialize the row and column sizes. */
    srcARows = params->srcARows;
    srcACols = params->srcACols;
    srcBRows = params->srcBRows;
    srcBCols = params->srcBCols;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that column of A equals rows of B */
    if (srcACols != srcBRows) {
        return MSP_SIZE_ERROR;
    }
    
    /* Check that the data arrays are aligned and in a valid memory segment. */
    if (!(MSP_LEA_VALID_ADDRESS(srcA, 4) &
          MSP_LEA_VALID_ADDRESS(srcB, 4) &
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
        
    /* Allocate MSP_LEA_MACLONG_PARAMS structure. */
    leaParams = (MSP_LEA_MACLONG_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_MACLONG_PARAMS)/sizeof(uint32_t));

    /* Initialize MSP_LEA_MACLONG_PARAMS structure. */
    leaParams->vectorSize = srcACols;
    leaParams->input1Offset = 1;
    leaParams->input2Offset = srcBCols;

#if (MSP_LEA_REVISION < MSP_LEA_REVISION_B)
    /* Load function into code memory */
    cmdId = msp_lea_loadCommand(LEACMD__MACLONGMATRIX, MSP_LEA_MACLONGMATRIX,
            sizeof(MSP_LEA_MACLONGMATRIX)/sizeof(MSP_LEA_MACLONGMATRIX[0]));
#else //MSP_LEA_REVISION
    /* Invoke the LEACMD__MACLONGMATRIX command. */
    cmdId = LEACMD__MACLONGMATRIX;
#endif //MSP_LEA_REVISION

    /* Multiply srcA row by srcB column and accumulate. */
    for (i = 0; i < srcARows*srcACols; i += srcACols) {
        for (j = 0; j < srcBCols; j++) {
            /* Set MSP_LEA_MACLONG_PARAMS for row by column MAC. */
            leaParams->input2 = MSP_LEA_CONVERT_ADDRESS(&srcB[j]);
            leaParams->output = MSP_LEA_CONVERT_ADDRESS(dst++);

            /* Load source arguments to LEA. */
            LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(&srcA[i]);
            LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);
    
            /* Invoke the command. */
            msp_lea_invokeCommand(cmdId);
            
            /* Set status flag. */
            status = MSP_SUCCESS;
                
#ifndef MSP_DISABLE_DIAGNOSTICS
            /* Check LEA interrupt flags for any errors. */
            if (msp_lea_ifg & LEACOVLIFG) {
                status = MSP_LEA_COMMAND_OVERFLOW;
                break;
            }
            else if (msp_lea_ifg & LEAOORIFG) {
                status = MSP_LEA_OUT_OF_RANGE;
                break;
            }
            else if (msp_lea_ifg & LEASDIIFG) {
                status = MSP_LEA_SCALAR_INCONSISTENCY;
                break;
            }
#endif //MSP_DISABLE_DIAGNOSTICS
        }
#ifndef MSP_DISABLE_DIAGNOSTICS
        if (status != MSP_SUCCESS) {
            break;
        }
#endif //MSP_DISABLE_DIAGNOSTICS
    }

    /* Free MSP_LEA_MACLONG_PARAMS structure. */
    msp_lea_freeMemory(sizeof(MSP_LEA_MACLONG_PARAMS)/sizeof(uint32_t));

    /* Free lock for LEA module and return status. */
    msp_lea_freeLock();
    return status;
}

#else //MSP_USE_LEA    

/*
 * Perform matrix multiplication of two source matrices.
 */
msp_status msp_matrix_mpy_iq31(const msp_matrix_mpy_iq31_params *params, const _iq31 *srcA, const _iq31 *srcB, _iq31 *dst)
{
    uint16_t cntr;
    uint16_t dst_row;
    uint16_t dst_col;
    uint16_t srcARows;
    uint16_t srcACols;
    uint16_t srcBRows;
    uint16_t srcBCols;
    uint16_t row_offset;
    uint16_t col_offset;
    uint16_t dst_row_offset;

    /* Initialize the row and column sizes. */
    srcARows = params->srcARows;
    srcACols = params->srcACols;
    srcBRows = params->srcBRows;
    srcBCols = params->srcBCols;

#ifndef MSP_DISABLE_DIAGNOSTICS
    /* Check that column of A equals rows of B */
    if (srcACols != srcBRows) {
        return MSP_SIZE_ERROR;
    }
#endif //MSP_DISABLE_DIAGNOSTICS

    /* In initialize loop counters. */
    cntr = 0;
    dst_row = 0;
    dst_col = 0;
    row_offset = 0;
    col_offset = 0;
    dst_row_offset = 0;

#if defined(__MSP430_HAS_MPY32__)
    int32_t result;

    /* If MPY32 is available save control context, set to fractional mode, set saturation mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN | MPYSAT;

    /* Loop through all srcA rows. */
    while(srcARows--) {
        /* Loop through all srcB columns. */
        while (dst_col < srcBCols) {
            /* Reset result registers */
            MPY32CTL0 &= ~MPYC;
            RES3 = 0; RES2 = 0; RES1 = 0; RES0 = 0;

            /* Multiply and accumulate inputs. */
            while(cntr < srcACols) {
                MACS32L = srcA[row_offset + cntr] & 0xffff;
                MACS32H = srcA[row_offset + cntr] >> 16;
                OP2L = srcB[col_offset + dst_col] & 0xffff;
                OP2H = srcB[col_offset + dst_col] >> 16;
                col_offset += srcBCols;
                cntr++;
            }

            /* Store accumulated result. */
            result  = RES2;
            result |= ((uint32_t)RES3 << 16);
            dst[dst_row_offset + dst_col] = result;

            /* Update pointers. */
            dst_col++;
            cntr = 0;
            col_offset = 0;
        }

        /* Update pointers. */
        dst_row++;
        dst_col = 0;
        row_offset += srcACols;
        dst_row_offset += srcBCols;
    }

    /* Restore MPY32 control context, previous saturation state. */
    MPY32CTL0 = ui16MPYState;

#else //__MSP430_HAS_MPY32__
    int64_t result;

    /* Loop through all srcA rows. */
    while(srcARows--) {
        /* Loop through all srcB columns. */
        while (dst_col < srcBCols) {
            /* Initialize accumulator. */
            result = 0;

            /* Loop through all elements in srcA column and srcB row. */
            while(cntr < srcACols) {
                result += (int64_t)srcA[row_offset+cntr] * (int64_t)srcB[col_offset+dst_col];
                col_offset += srcBCols;
                cntr++;
            }

            /* Scale and saturate accumulator and store to destination. */
            dst[dst_row_offset+dst_col] = (_iq31)__saturate((result >> 31), INT32_MIN, INT32_MAX);

            /* Update pointers. */
            dst_col++;
            cntr = 0;
            col_offset = 0;
        }

        /* Update pointers. */
        dst_row++;
        dst_col = 0;
        row_offset += srcACols;
        dst_row_offset += srcBCols;
    }
#endif //__MSP430_HAS_MPY32__

    return MSP_SUCCESS;
}

#endif //MSP_USE_LEA    
