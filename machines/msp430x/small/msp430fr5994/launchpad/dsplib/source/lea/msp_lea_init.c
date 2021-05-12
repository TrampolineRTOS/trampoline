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

#if defined(MSP_DISABLE_LPM0)
#warning "DSPLib: LPM0 is disabled, undefine MSP_DISABLE_LPM0 to enable LPM0.
#elif ((MSP_LEA_REVISION==MSP_LEA_REVISION_A) && !defined(MSP_ENABLE_LPM0))
#warning "DSPLib: Building for revision A of LEA, LPM0 is disabled to work \
around LEA1 errata. See the LEA chapter of API User's Guide and device errata \
sheet for more details."
#endif

void msp_lea_init(void)
{
    /* Initialize DSPLib flags. */
    msp_lea_ifg = 0;
    msp_lea_locked = 0;

    /* Initialize LEA registers. */
    LEACNF0 = LEALPR | LEAILPM;
    LEACNF1 = 0;
    LEACNF2 = LEAMT >> 2;
    LEAPMS1 = 0;
    LEAPMS0 = 0;
    LEAPMDST = 0;
    LEAPMCTL |= LEACMDEN;
    LEAIE |= LEAPMCMDIE;
    LEACMCTL = 0;

#if (MSP_LEA_REVISION == MSP_LEA_REVISION_A)
    msp_lea_initCommandTable();
#endif

    return;
}

#endif
