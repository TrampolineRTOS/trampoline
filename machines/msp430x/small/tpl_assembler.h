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
#define R12 r12
#define R13 r13
#define R14 r14
#define R15 r15
#define pc r0
#define sp r1
#define sr r2

//R15 behavior depends on the ABI flavor

#if __GXX_ABI_VERSION == 1002
/* MSPGCC ABI, comes with Energia */
    #define MSPGCC_ABI
/* The register used to pass the id of the service is r12 */
    #define REG_SID r12
/* The register used to return a value from a function is r15 */
    #define REG_RETARG r15
/* The offset of this register once stored in the process stack */
    #define REG_RETARG_OFFSET 8
#elif __GXX_ABI_VERSION == 1011 || __GXX_ABI_VERSION == 1013
/* GCC compiler for MSP ABI, gcc compiler from TI */
    #define GCCFORMSP_ABI
/* The register used to pass the id of the service is r15 */
    #define REG_SID r15
/* The register used to return a value from a function is r12 */
    #define REG_RETARG r12
/* The offset of this register once stored in the process stack */
    #define REG_RETARG_OFFSET 2
#else
    #error "Unsupported ABI"
#endif

#endif
