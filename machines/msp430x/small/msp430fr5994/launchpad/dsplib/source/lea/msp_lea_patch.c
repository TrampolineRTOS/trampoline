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

#define MSP_LEA_REV_A_CHECKSUM            0x7877D27F
#define MSP_LEA_REV_B_CHECKSUM            0xAE790580

#define MSP_LEA_COMMAND_TABLE_LENGTH      0x0008
#define MSP_LEA_COMMAND_TABLE_RESERVED    0x0002
#define MSP_LEA_COMMAND_TABLE_NULL        0xFFFF
#define MSP_LEA_COMMAND_ID_BASE           0x01e0
#define MSP_LEA_COMMAND_ID_INCR           0x0004
#define MSP_LEA_COMMAND_ADDRESS_BASE      0x3C00
#define MSP_LEA_COMMAND_ADDRESS_INCR      0x0080

static uint16_t commandTable[MSP_LEA_COMMAND_TABLE_LENGTH];

#if (MSP_LEA_REVISION == MSP_LEA_REVISION_A)
#warning "DSPLib: Building for revision A of LEA, commands will be patched \
with the latest revision of firmware."
#endif

void msp_lea_initCommandTable(void)
{
    uint16_t i;

    /* Initialize command table. */
    for (i = 0; i < MSP_LEA_COMMAND_TABLE_LENGTH; i++) {
        commandTable[i] = MSP_LEA_COMMAND_TABLE_NULL;
    }
}

uint16_t msp_lea_getRevision(void)
{
    uint32_t checksum;

    /* Read LEA code memory checksum */
    LEACMCTL = 0x2ffc0000 | LEAINC | LEACMAE;
    checksum = LEACMA;
    LEACMCTL = 0;

    /* Return LEA code ROM revision */
    switch (checksum) {
    case MSP_LEA_REV_A_CHECKSUM:
        return MSP_LEA_REVISION_A;
    case MSP_LEA_REV_B_CHECKSUM:
        return MSP_LEA_REVISION_B;
    default:
        return MSP_LEA_REVISION_UNKNOWN;
    }
}

uint16_t msp_lea_loadCommand(uint16_t commandId, const void *command, uint16_t length)
{
    uint16_t i;
    uint16_t j;
    uint16_t commandAddress;
    uint32_t *commandPtr = (uint32_t *)command;

    /* Return command ID if already loaded or find next open command entry. */
    for (i = 0; i < MSP_LEA_COMMAND_TABLE_LENGTH-MSP_LEA_COMMAND_TABLE_RESERVED; i++) {
        /* Check if command is loaded, calculate and return ID. */
        if (commandTable[i] == commandId) {
            return (MSP_LEA_COMMAND_ID_BASE + i*MSP_LEA_COMMAND_ID_INCR);
        }
        /* Check if table entry is NULL, break and load command */
        if (commandTable[i] == MSP_LEA_COMMAND_TABLE_NULL) {
            break;
        }
    }

    /* Calculate command address. */
    commandAddress = MSP_LEA_COMMAND_ADDRESS_BASE + i*MSP_LEA_COMMAND_ADDRESS_INCR;

    /* Load command to address. */
    LEACMCTL = LEACRACTION;
    while (LEACMCTL & LEACRACTION);
    LEACMCTL = ((uint32_t)commandAddress << 16) | LEAINC | LEACMAE;
    for (j = 0; j < length; j++) {
        LEACMA = commandPtr[j];
    }
    LEACMCTL = 0;

    /* Store command ID of the loaded function and return new ID. */
    commandTable[i] = commandId;
    if (length > 32) {
        commandTable[i+1] = commandId;
    }
    return (commandAddress >> 5);
}

const uint32_t MSP_LEA_MIN[23] = {
    0x7ffff254,0x400ff250,0x7ffff60a,0x7ffff685,
    0xa8000004,0x7ffff4a1,0x7ffff781,0x80000001,
    0x8006ffff,0x80880000,0x80807fff,0xb0000012,
    0x080fffff,0x7ffffb08,0x260ffe10,0x7ffff568,
    0x7ffffb18,0x260ffe90,0x080ff568,0x7ffff204,
    0x7fffffff,0x308fffff,0xb0800000
};

const uint32_t MSP_LEA_MINUNSIGNED[23] = {
    0x7ffff254,0x400ff250,0x7ffff60a,0x7ffff685,
    0xa8000004,0x7ffff4a1,0x7ffff781,0x80000001,
    0x8006ffff,0x80880000,0x8080ffff,0xb0000012,
    0x080fffff,0x7ffffb48,0x260ffe10,0x7ffff568,
    0x7ffffb58,0x260ffe90,0x080ff568,0x7ffff204,
    0x7fffffff,0x308fffff,0xb0800000
};

const uint32_t MSP_LEA_MINLONGMATRIX[20] = {
    0x7ffff256,0x80000001,0x010ff250,0x490ff003,
    0x8082ffff,0x7ffff611,0x7ffffc32,0x082ff782,
    0x7ffff685,0x80060000,0xb000000e,0x002ff462,
    0x261ffa08,0x002ff281,0x7ffff562,0x7ffff20d,
    0x7ffff114,0x388fffff,0x308fffff,0xb0800000
};

const uint32_t MSP_LEA_MINUNSIGNEDLONGMATRIX[20] = {
    0x7ffff256,0x80000001,0x010ff250,0x490ff003,
    0x8082ffff,0x7ffff611,0x7ffffc32,0x082ff782,
    0x7ffff685,0x80060000,0xb000000e,0x002ff462,
    0x261ffa48,0x002ff281,0x7ffff562,0x7ffff20d,
    0x7ffff114,0x388fffff,0x308fffff,0xb0800000
};

const uint32_t MSP_LEA_MAX[23] = {
    0x7ffff254,0x400ff250,0x7ffff60a,0x7ffff685,
    0xa8000004,0x7ffff4a1,0x7ffff781,0x80000001,
    0x8006ffff,0x80880000,0x80808000,0xb0000012,
    0x080fffff,0x7ffffb88,0x260ffe10,0x7ffff568,
    0x7ffffb98,0x260ffe90,0x080ff568,0x7ffff204,
    0x7fffffff,0x308fffff,0xb0800000
};

const uint32_t MSP_LEA_MAXUNSIGNED[23] = {
    0x7ffff254,0x400ff250,0x7ffff60a,0x7ffff685,
    0xa8000004,0x7ffff4a1,0x7ffff781,0x80000001,
    0x8006ffff,0x80880000,0x80800000,0xb0000012,
    0x080fffff,0x7ffffbc8,0x260ffe10,0x7ffff568,
    0x7ffffbd8,0x260ffe90,0x080ff568,0x7ffff204,
    0x7fffffff,0x308fffff,0xb0800000
};

const uint32_t MSP_LEA_MAXLONGMATRIX[20] = {
    0x7ffff256,0x80000001,0x010ff250,0x490ff003,
    0x8082ffff,0x7ffff611,0x7ffffc32,0x082ff782,
    0x7ffff685,0x80060000,0xb000000e,0x002ff462,
    0x261ffa88,0x002ff281,0x7ffff562,0x7ffff20d,
    0x7ffff114,0x388fffff,0x308fffff,0xb0800000
};

const uint32_t MSP_LEA_MAXUNSIGNEDLONGMATRIX[20] = {
    0x7ffff256,0x80000001,0x010ff250,0x490ff003,
    0x8082ffff,0x7ffff611,0x7ffffc32,0x082ff782,
    0x7ffff685,0x80060000,0xb000000e,0x002ff462,
    0x261ffac8,0x002ff281,0x7ffff562,0x7ffff20d,
    0x7ffff114,0x388fffff,0x308fffff,0xb0800000
};

const uint32_t MSP_LEA_MACLONGMATRIX[18] = {
    0x7ffff254,0x80000001,0x080ff251,0x000ff781,
    0x7ffff680,0x480ff694,0x188ff611,0x81040000,
    0xb000000e,0x102ff606,0x7ff99fff,0x7ff8ffff,
    0x102a6ed7,0x7fffefdf,0x188fe93c,0x7fffffff,
    0x310fffff,0xb0800000
};

const uint32_t MSP_LEA_FFTCOMPLEXAUTOSCALING[58] = {
    0x7ffff254,0x400ff250,0x7ffff780,0x80000001,
    0x80810000,0x100ff251,0xb000000b,0x180ff61c,
    0x100ff234,0x180ff23d,0x309fffff,0x389ff4c2,
    0x7ffff62d,0x7ffff61c,0x7ffff250,0x7ffff600,
    0x8005fffe,0x250ff459,0x80870001,0x7ffff788,
    0xa8000000,0x7ffff618,0x7ffff617,0x8003ffff,
    0x7ffff675,0x800a0800,0x800907ff,0xb0000035,
    0x230ff670,0x2547f671,0x27dfffff,0x7ffff450,
    0x12bff606,0x04bc1789,0x7ffdb61c,0x7ffcdfff,
    0x12b57fff,0x7ffc049b,0x7ffcc21d,0xb000002c,
    0x04bda01c,0x12b57fff,0x3b3c049b,0x353cc21d,
    0x04bda01c,0xa8000000,0x3b3d7407,0x353fe49b,
    0x7fffe21d,0x7fffe01c,0x3b3ff675,0x353ff4cf,
    0xa8000004,0x7ffff6fd,0x7ffff470,0x80880000,
    0x7ffff262,0xb0c00000
};

const uint32_t MSP_LEA_FFTCOMPLEXLONG[64] = {
    0x7ffff254,0x400ff250,0x7ffff60b,0x8005ffff,
    0x25bff45a,0x8005ffff,0xa8000006,0x25bff452,
    0xa000fffb,0x90820000,0x7ffff788,0x80820002,
    0x80050002,0x80010003,0x80080000,0x800a0800,
    0x80000001,0x800907ff,0xb000003d,0x908a0001,
    0x2547f450,0x108ff622,0x90030000,0x90820002,
    0x7ffa3783,0x7ff896a3,0x7ff8ee9c,0x12aa5606,
    0xb0000029,0x7ff8ced5,0x7ffa7fff,0x7ff88e98,
    0x7ffa2b04,0x008fee99,0x0ccfe94b,0x7fffea25,
    0x1087ea5d,0x39088824,0x3b2a285d,0x3108ce9c,
    0x12aa7fff,0x3d48ce9d,0x7ffa7fff,0x7ff88e98,
    0x7ffa2b04,0x008fee99,0x0ccfe94b,0x7fffea25,
    0x7fffea5d,0x390fe824,0x3b2fe85d,0x310fffff,
    0x3d4fffff,0x90020002,0x7ffff623,0x80010001,
    0xa8000002,0x213ff432,0x7ffff625,0xa8000004,
    0x80080000,0x900a0001,0xa0000005,0xb0800000
};

const uint32_t MSP_LEA_MPYLONGMATRIX[17] = {
    0x7ffff254,0x80000001,0x080ff251,0x000ff781,
    0x480ff694,0x7ffff681,0x7ffff612,0x10aff606,
    0x184fffff,0x7ff8ffff,0xb000000f,0x7ff99690,
    0x10aa6ed7,0x184fefdc,0x7ff99fff,0x3108ffff,
    0xb0800000
};

const uint32_t MSP_LEA_IIRBQ1[31] = {
    0x7ffff256,0x80000001,0x80020000,0x010ff250,
    0x090ff780,0x7ffff617,0x410ff686,0x118ff695,
    0x01cff601,0x188ff204,0x7ff8dfff,0xb000001b,
    0x7ff80890,0x50088810,0x18887211,0x31c80859,
    0x11c88810,0x1a8fe859,0x7ff80851,0x7ff8c810,
    0x7fffe810,0x7ff88816,0x7ff8c851,0x1a8fe851,
    0x188fe854,0x102ff0e4,0x7ff8d235,0x31080890,
    0x338fffff,0x398fffff,0xb0800000
};

const uint32_t MSP_LEA_IIRBQ2[32] = {
    0x7ffff256,0x80000001,0x010ff250,0x090ff780,
    0x7ffff617,0x80020000,0x11cff695,0x8001fffd,
    0x188ff686,0x7ff8dfff,0x18887210,0xb000001e,
    0x7ff81219,0x100fe810,0x7ff84810,0x7ff8e816,
    0x7ff8a859,0x7fffe859,0x7fffe859,0x188ff096,
    0x7ff8f235,0x7ff828d9,0x11c88859,0x18a85210,
    0x39c82810,0x7fffe85c,0x11c88810,0x188fe810,
    0x7ff8d084,0x18887210,0x31081219,0xb0800000
};

const uint32_t MSP_LEA_IIRBQ2EXTENDED[47] = {
    0x7ffff256,0x80000001,0x8001fffc,0x80020000,
    0x010ff250,0x090ff780,0x7ffff617,0x7ffff695,
    0x118ff686,0x088fffff,0x188fffff,0x7ff8dfff,
    0x18886850,0xb0000024,0x7ff80859,0x100fe810,
    0x7ff84810,0x7ff8e816,0x7ff8a859,0x7fffe859,
    0x7fffe859,0x7ffff096,0x018ff234,0x498ff235,
    0x7ffff90d,0x188ff984,0x3b88f235,0x338828d9,
    0x51888859,0x18a85210,0x39c82810,0x088fe85c,
    0x11888810,0x188fe810,0x7ff8d084,0x18886850,
    0x31080859,0x018fffff,0x098ffb10,0x7ffffe80,
    0x7ffff004,0x7ffffb99,0x7ffffe91,0x7ffff01c,
    0x7fffffff,0x31cfffff,0xb0800000
};

const uint32_t MSP_LEA_FIRLONG[30] = {
    0x7ffff255,0x7ffff250,0x7ffff444,0x7ffff450,
    0x80000001,0x008ff604,0x008ff780,0x488ff682,
    0x8001ffff,0x221ff605,0x7ffff420,0x7ffff613,
    0x81050000,0x7ffff601,0xb000001c,0x220ff420,
    0x480ff646,0x7ffff697,0x4d2ff780,0x198ff049,
    0x570ff22c,0xb000001a,0x7ff99fff,0x7ff8ffff,
    0x570a6ed2,0x198fee9a,0x7ff98914,0x210fffff,
    0x308ff094,0xb0800000
};

const uint32_t MSP_LEA_FIRCOMPLEXLONG[43] = {
    0x7ffff255,0x80020001,0x00cff250,0x08cff780,
    0x7ffff690,0x8001ffff,0x201ff084,0x408ff615,
    0x220ff603,0xa8000000,0x81050000,0x7ffff048,
    0x80010001,0xb0000029,0x201ff420,0x7ffff441,
    0x7ffff616,0x7ffff687,0x4d0ff780,0x8002ffff,
    0x19aff22c,0x572fffff,0xb0000025,0x7ff9b229,
    0x7ff8dfff,0x19ca4e9b,0x7ff8eed2,0x7ff98851,
    0x19aa6ed6,0x572fef9a,0x7ff98b14,0x7ff8ffff,
    0x19aa4ed3,0x7ff8eed2,0x7ff98914,0x572a6ed7,
    0x19afefda,0x7ff9a851,0x30aff20c,0x80020002,
    0x30afffff,0x202fffff,0xb0800000
};

const uint32_t  MSP_LEA_INTERLEAVEEVENEVEN[22] = {
    0x80000001,0x7ffff255,0x008ff250,0x488ff68a,
    0x7ffff605,0xa8000004,0x25aff61b,0x7ffff69a,
    0xa8000006,0xa8000004,0x7ffff4b2,0x7ffff4aa,
    0x7ffff621,0x000ff78a,0xb0000014,0x7ffff004,
    0x08aff085,0x0aaff09c,0x000ff09d,0x30afffff,
    0x38aff004,0xb0800000
};

const uint32_t  MSP_LEA_INTERLEAVEEVENODD[24] = {
    0x80000001,0x7ffff255,0x008ff250,0x488ff68a,
    0x7ffff605,0xa8000004,0x25aff61b,0x7ffff69a,
    0xa8000006,0xa8000004,0x7ffff4b2,0x7ffff4aa,
    0x7ffff622,0x7ffff621,0x220fffff,0x000ff78a,
    0xb0000016,0x7ffff004,0x08aff08d,0x0aaff09c,
    0x000ff015,0x30afffff,0x38cff004,0xb0800000
};

const uint32_t  MSP_LEA_INTERLEAVEODDEVEN[22] = {
    0x80000001,0x7ffff255,0x008ff250,0x488ff68a,
    0x7ffff605,0xa8000004,0x25aff61b,0x7ffff69a,
    0xa8000006,0xa8000004,0x7ffff4b2,0x7ffff4aa,
    0x7ffff621,0x000ff78a,0xb0000014,0x7ffff00c,
    0x08aff08d,0x0aaff014,0x000ff015,0x30afffff,
    0x38aff00c,0xb0800000
};

const uint32_t  MSP_LEA_INTERLEAVEODDODD[24] = {
    0x80000001,0x7ffff255,0x008ff250,0x488ff68a,
    0x7ffff605,0xa8000004,0x25aff61b,0x7ffff69a,
    0xa8000006,0xa8000004,0x7ffff4b2,0x7ffff4aa,
    0x7ffff621,0x7ffff622,0x210fffff,0x000ff78a,
    0xb0000016,0x7ffff00c,0x08aff085,0x0aaff014,
    0x000ff09d,0x30afffff,0x38cff00c,0xb0800000
};

#endif //MSP_USE_LEA
