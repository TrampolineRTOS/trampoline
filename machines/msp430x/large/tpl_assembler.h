#ifndef TPL_ASSEMBLER_H
#define TPL_ASSEMBLER_H

#define TPL_EXTERN .extern

#define PC r0
#define SP r1
#define SR r2
#define CG r3
#define R4 r4
#define R5 r5
#define R6 r6
#define R7 r7
#define R8 r8
#define R9 r9
#define R10 r10
#define R11 r11
//R12 behavior depends on the ABI flavor
#define R13 r13
#define R14 r14
//R15 behavior depends on the ABI flavor

#if __GXX_ABI_VERSION == 1002
	/* MSPGCC ABI */
    #define MSPGCC_ABI
    #define REG_SID r12
    #define REG_RETARG r15

#elif __GXX_ABI_VERSION == 1011
    /* GCC compiler for MSP ABI */
    #define GCCFORMSP_ABI
    #define REG_RETARG r12
    #define REG_SID r15
#else
    #error "Unsupported ABI"
#endif

#endif
