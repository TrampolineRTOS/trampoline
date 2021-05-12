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

msp_status msp_matrix_mpy_q15(const msp_matrix_mpy_q15_params *params, const _q15 *srcA, const _q15 *srcB, _q15 *dst)
{
    uint16_t srcARows;
    uint16_t srcACols;
    uint16_t srcBRows;
    uint16_t srcBCols;
    msp_status status;
    MSP_LEA_MPYMATRIXROW_PARAMS *leaParams;

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

    /* Acquire lock for LEA module. */
    if (!msp_lea_acquireLock()) {
        return MSP_LEA_BUSY;
    }
#endif //MSP_DISABLE_DIAGNOSTICS

    /* Initialize LEA if it is not enabled. */
    if (!(LEAPMCTL & LEACMDEN)) {
        msp_lea_init();
    }

    /* Allocate MSP_LEA_MPYMATRIXROW_PARAMS structure. */
    leaParams = (MSP_LEA_MPYMATRIXROW_PARAMS *)msp_lea_allocMemory(sizeof(MSP_LEA_MPYMATRIXROW_PARAMS)/sizeof(uint32_t));

    /* Set status flag. */
    status = MSP_SUCCESS;

    /* Iterate through each row of srcA */
    while (srcARows--) {
        /* Set MSP_LEA_MPYMATRIXROW_PARAMS structure. */
        leaParams->rowSize = srcBRows;
        leaParams->colSize = srcBCols;
        leaParams->colVector = MSP_LEA_CONVERT_ADDRESS(srcB);
        leaParams->output = MSP_LEA_CONVERT_ADDRESS(dst);

        /* Load source arguments to LEA. */
        LEAPMS0 = MSP_LEA_CONVERT_ADDRESS(srcA);
        LEAPMS1 = MSP_LEA_CONVERT_ADDRESS(leaParams);

        /* Invoke the LEACMD__MPYMATRIXROW command. */
        msp_lea_invokeCommand(LEACMD__MPYMATRIXROW);

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

        /* Increment srcA and dst pointers. */
        srcA += srcACols;
        dst += srcBCols;
    }

    /* Free MSP_LEA_MPYMATRIXROW_PARAMS structure. */
    msp_lea_freeMemory(sizeof(MSP_LEA_MPYMATRIXROW_PARAMS)/sizeof(uint32_t));

    /* Free lock for LEA module and return status. */
    msp_lea_freeLock();
    return status;
}

#else //MSP_USE_LEA

msp_status msp_matrix_mpy_q15(const msp_matrix_mpy_q15_params *params, const _q15 *srcA, const _q15 *srcB, _q15 *dst)
{
    uint16_t cntr;
    uint16_t srcARows;
    uint16_t srcACols;
    uint16_t srcBRows;
    uint16_t srcBCols;
    uint16_t dst_row;
    uint16_t dst_col;
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
    /* If MPY32 is available save control context, set to fractional mode, set saturation mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN | MPYSAT;

    /* Loop through all srcA rows. */
    while(srcARows--) {
        /* Loop through all srcB columns. */
        while (dst_col < srcBCols) {
            /* Reset result accumulator. */
            MPY32CTL0 &= ~MPYC;
            RESLO = 0; RESHI = 0;
            
            /* Loop through all elements in srcA column and srcB row. */
            while(cntr < srcACols) {
                MACS = srcA[row_offset + cntr];
                OP2 = srcB[col_offset + dst_col];
                col_offset += srcBCols;
                cntr++;
            }
            
            /* Store the result */
            dst[dst_row_offset + dst_col] = RESHI;

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
    _iq31 result;

    /* Loop through all srcA rows. */
    while(srcARows--) {
        /* Loop through all srcB columns. */
        while (dst_col < srcBCols) {
            /* Initialize accumulator. */
            result = 0;
            
            /* Loop through all elements in srcA column and srcB row. */
            while(cntr < srcACols) {
                result += (_iq31)srcA[row_offset + cntr] * (_iq31)srcB[col_offset + dst_col];
                col_offset += srcBCols;
                cntr++;
            }

            /* Saturate and store the result */
            dst[dst_row_offset + dst_col] = (_q15)__saturate(result >> 15, INT16_MIN, INT16_MAX);

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
