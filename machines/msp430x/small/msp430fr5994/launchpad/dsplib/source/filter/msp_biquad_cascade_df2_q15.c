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

msp_status msp_biquad_cascade_df2_q15(const msp_biquad_cascade_df2_q15_params *params, const _q15 *src, _q15 *dst)
{
    uint16_t i;
    uint16_t stages;
    const _q15 *srcPtr;
    msp_status status;
    msp_biquad_df2_q15_params df2Params;
    
    /* Load the number of stages from the parameters. */
    stages = params->stages;
    
    /* Set initial source pointer. */
    srcPtr = src;

    /* Run the input through all stages of the cascaded biquad. */
    for (i = 0; i < stages; i++) {
        /* Initialize the DF2 biquad parameter structure. */
        df2Params.length = params->length;
        df2Params.coeffs = &params->coeffs[i];
        df2Params.states = &params->states[i];
    
        /* Invoke the msp_biquad_df2_q15 function and check status flag. */
        status = msp_biquad_df2_q15(&df2Params, srcPtr, dst);
        if (status != MSP_SUCCESS) {
            /* Something went wrong, return the status of the operation. */
            return status;
        }
        
        /* Set source pointer to destination for next stage. */
        srcPtr = dst;
    }
    
    /* Return the status of the operation. */
    return status;
}
