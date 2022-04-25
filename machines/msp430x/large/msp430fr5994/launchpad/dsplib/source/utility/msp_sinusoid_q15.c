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

msp_status msp_sinusoid_q15(const msp_sinusoid_q15_params *params, _q15 *dst)
{
    msp_status status;
    msp_biquad_df1_q15_params df1Params;

#if defined(MSP_USE_LEA)
    /* Initialize LEA if it is not enabled. */
    if (!(LEAPMCTL & LEACMDEN)) {
        msp_lea_init();
    }

    /* Allocate coefficients in LEA memory and set parameters */
    df1Params.length = params->length;
    df1Params.coeffs = (msp_biquad_df1_q15_coeffs *)msp_lea_allocMemory(sizeof(msp_biquad_df1_q15_coeffs)/sizeof(uint32_t));
    df1Params.states = (msp_biquad_df1_q15_states *)msp_lea_allocMemory(sizeof(msp_biquad_df1_q15_coeffs)/sizeof(uint32_t));
#else //MSP_USE_LEA
    /* Allocate coefficients on stack */
    msp_biquad_df1_q15_coeffs coeffs;
    msp_biquad_df1_q15_states states;

    /* Set parameters */
    df1Params.coeffs = &coeffs;
    df1Params.states = &states;
    df1Params.length = params->length;
#endif //MSP_USE_LEA
    
#if defined(__MSP430_HAS_MPY32__)
    /* If MPY32 is available save control context and set to fractional mode. */
    uint16_t ui16MPYState = MPY32CTL0;
    MPY32CTL0 = MPYFRAC | MPYDLYWRTEN;
#endif //__MSP430_HAS_MPY32__

    /* Initialize coefficients */
    ((msp_biquad_df1_q15_coeffs *)df1Params.coeffs)->a1By2  = params->cosOmega;
    ((msp_biquad_df1_q15_coeffs *)df1Params.coeffs)->a2     = _Q15(-1.0);
    ((msp_biquad_df1_q15_coeffs *)df1Params.coeffs)->b0     = _Q15(0.0);
    ((msp_biquad_df1_q15_coeffs *)df1Params.coeffs)->b1By2  = _Q15(0.0);
    ((msp_biquad_df1_q15_coeffs *)df1Params.coeffs)->b2     = _Q15(0.0);

    /* Initialize states */
    df1Params.states->x1 = _Q15(0.0);
    df1Params.states->x2 = _Q15(0.0);
    df1Params.states->y1 = -__q15mpy(params->amplitude, params->sinOmega);
    df1Params.states->y2 =  __q15mpy(df1Params.states->y1, params->cosOmega) << 1;
    
#if defined(__MSP430_HAS_MPY32__)
    /* Restore MPY32 control context. */
    MPY32CTL0 = ui16MPYState;
#endif //__MSP430_HAS_MPY32__

    /* Call DF1 biquad to generate sinusoid */
    status = msp_biquad_df1_q15(&df1Params, dst, dst);
    
#if defined(MSP_USE_LEA)
    /* Free coefficients and states from LEA memory */
    msp_lea_freeMemory(sizeof(msp_biquad_df1_q15_coeffs)/sizeof(uint32_t));
    msp_lea_freeMemory(sizeof(msp_biquad_df1_q15_states)/sizeof(uint32_t));
#endif //MSP_USE_LEA

    return status;
}

