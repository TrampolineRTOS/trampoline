/*******************************************************************************
 * (c) Copyright 2012-2015 Microsemi SoC Products Group.  All rights reserved.
 * 
 * @file startup_m2sxxx.S
 * @author Microsemi SoC Products Group
 * @brief SmartFusion2 vector table and startup code for CodeSourcery G++.
 *
 * SVN $Revision: 7683 $
 * SVN $Date: 2015-08-21 17:06:30 +0100 (Fri, 21 Aug 2015) $
 */

    .syntax unified
    .cpu cortex-m3
    .thumb
    
	.extern tpl_continue_reset_handler2
/*==============================================================================
 * Reset_Handler
 * Register r11 is used to keep track of whether we need to initialize RAMs
 * because ECC/ SECDED is enabled.
 */
    .global tpl_continue_reset_handler
    .section .after_vectors,"ax",%progbits            
    .type   tpl_continue_reset_handler, %function
tpl_continue_reset_handler:
/*------------------------------------------------------------------------------
 * Initialize stack RAM content to initialize the error detection and correction
 * (EDAC). This is done if EDAC is enabled for the eSRAM blocks or the
 * ECC/SECDED is enabled for the MDDR.
 * Register r11 is used to keep track of the RAM intialization decision outcome
 * for later use for heap RAM initialization at the end of the startup code.
 * Please note that the stack has to be located in eSRAM at this point and
 * cannot be located in MDDR since MDDR is not available at this point.
 * The bits of the content of register r11 have the following meaning:
 *  reg11[0]: eSRAM EDAC enabled
 *  reg11[1]: MDDR ECC/SECDED enabled
 */
    mov r11, #0
    ldr r0, SF2_MDDR_MODE_CR
    ldr r0, [r0]
    ldr r1, SF2_EDAC_CR
    ldr r1, [r1]
    and r1, r1, #3
    and r0, r0, #0x1C
    cmp r0, #0x14
    bne check_esram_edac
    orr r11, r11, #2
check_esram_edac:
    cmp r1, #0
    beq check_stack_init
    orr r11, r11, #1
check_stack_init:
    cmp r11, #0
    beq system_init
clear_stack:
//    ldr r0, = __stack_start__
//    ldr r1, =_estack
//    ldr r2, RAM_INIT_PATTERN
//    bl fill_memory                      /* ; fill_memory takes r0 - r2 as arguments uses r4, r5, r6, r7, r8, r9, and does not preserve contents */
    
///*------------------------------------------------------------------------------
// * Modify MDDR configuration if ECC/SECDED is enabled for MDDR.
// * Enable write combining on MDDR bridge, disable non-bufferable regions.
// */
//    and r10, r11, 0x2
//    cmp r10, #0
//    beq remap_memory
//    ldr r0, SF2_DDRB_NB_SIZE
//    ldr r1, SF2_DDRB_CR
//    ldr r2, [r0]
//    ldr r3, [r1]
//    push {r0, r1, r2, r3}
//    mov r2, #0
//    mov r3, #0xFF
//    str r2, [r0]
//    str r3, [r1]
    
	b tpl_continue_reset_handler2 // call the next step in C.

///*------------------------------------------------------------------------------
// * Initialize heap RAM content to initialize the error detection and correction
// * (EDAC). We use the decision made earlier in the startup code of whether or
// * not the stack RAM should be initialized. This decision is held in register
// * r11. A non-zero value indicates that the RAM content should be initialized.
// */
//clear_heap:
//    cmp r11, #0
//    beq call_glob_ctor
//    ldr r0, =__heap_start__
//    ldr r1, =_eheap
//    ldr r2, HEAP_INIT_PATTERN
//    bl fill_memory                      /* ; fill_memory takes r0 - r2 as arguments uses r4, r5, r6, r7, r8, r9, and does not preserve contents */
//
///*------------------------------------------------------------------------------
// * Restore MDDR configuration.
// */
//    and r10, r11, 0x2
//    cmp r10, #0
//    beq call_glob_ctor
//    pop {r0, r1, r2, r3}
//    str r2, [r0]
//    str r3, [r1]

/*==============================================================================
 * mscc_post_hw_cfg_init => called by CMSIS
 */
    .weak   mscc_post_hw_cfg_init
    .type   mscc_post_hw_cfg_init, %function
mscc_post_hw_cfg_init:
    BX LR

/*;------------------------------------------------------------------------------
; * fill_memory.
; * @brief Fills memory with Pattern contained in r2
; * This routine uses the stmne instruction to copy 4 words at a time which is very efficient
; * The instruction can only write to word aligned memory, hence the code at the start and end of this routine
; * to handle possible unaligned bytes at start and end.
; *
; * @param param1 r0: start address
; * @param param2 r1: end address
; * @param param3 r2: FILL PATTETN
; *
; * @note note: Most efficient if memory aligned. Linker ALIGN(4) command
; * should be used as per example linker scripts
; * Stack is not used in this routine
; * register contents r4, r5, r6, r7, r8, r9, will are used and will be returned undefined 
; * @return none - Used Registers are not preserved
; */

fill_memory:
    /* ;push {r4, r5, r6, r7, r8, r9, lr}    We will not use stack as may be not available */
    cmp r0, r1
    beq fill_memory_exit        /* ; Exit early if source and destination the same */
/* ; copy non-aligned bytes at the start */
    and.w  r6, r0, #3           /* ; see if non-alaigned bytes at the start     */
    cmp r6, #0
    beq fill_memory_end_start   /* ; no spare bytes at start, continue  */
    mov    r5, #4
    sub.w  r4, r5, r6           /* ; now have number of non-aligned bytes in r4 */
    mov  r7, #8
    mul  r8, r7, r6             /* ; calculate number of shifts required to initalise pattern for non-aligned bytes */
    mov  r9, r2                 /* ; copy pattern */
    ror  r9, r9, r8             /* ; Rotate right to keep pattern consistent */
fill_memory_spare_bytes_start:  /* ; From above, R0 contains source address, R1 contains destination address */
    cmp r4, #0                  /* ; no spare bytes at end- end now     */
    beq fill_memory_end_start
    strb r9, [r0]               /* ; fill byte */
    ror.w  r9, r9, r7           /* ; Rotate right by one byte for the next time, to keep pattern consistent */
    add r0, r0, #1              /* ; add one to address */
    subs r4, r4, #1             /* ; subtract one from byte count 1 */
    b fill_memory_spare_bytes_start
fill_memory_end_start:
    mov  r6, #0
    mov  r7, r1                  /* ; save end address */
    subs r1, r1, r0              /* ; Calculate number of bytes to fill */
    mov  r8,r1                   /* ; Save copy of byte count */
    asrs r1,r1, #4               /* ; Div by 16 to get number of chunks to move */
    mov  r9, r2                  /* ; copy pattern */
    mov  r4, r2                  /* ; copy pattern */
    mov  r5, r2                  /* ; copy pattern */
    cmp r1, r6                   /* ; compare to see if all chunks copied */
    beq fill_memory_spare_bytes_end
fill_memory_loop:
    it ne
    stmne r0!, {r2, r4, r5, r9}  /* ; copy pattern- note: stmne instruction must me word aligned (address in r0) */
    add.w r6, r6, #1             /* ; use Thumb2- make sure condition code reg. not updated */
    cmp r1, r6                   /* ; compare to see if all chunks copied */
    bne fill_memory_loop
fill_memory_spare_bytes_end:     /* ; copy spare bytes at the end if any */
    and.w r8, r8, #15            /* ; get spare bytes  --check can you do an ands?  */
fill_memory_spare_end_loop:      /* ; From above, R0 contains source address, R1 contains destination address */
    cmp r8, #0                   /* ; no spare bytes at end- end now    */
    beq fill_memory_exit
    strb r2, [r0]
    ror.w  r2, r2, #8            /* ; Rotate right by one byte for the next time, to keep pattern consistent */
    add r0, r0, #1               /* ; add one to address */
    subs r8, r8, #1              /* ; subtract one from byte count 1    */
    b fill_memory_spare_end_loop
fill_memory_exit:
    bx lr               /*; We will not use pop as stack may be not available */


/*==============================================================================
 * Constants:
 */
RAM_INIT_PATTERN:       .word   0x00000000
HEAP_INIT_PATTERN:      .word   0xA2A2A2A2
SF2_ESRAM_CR:           .word   0x40038000
SF2_DDR_CR:             .word   0x40038008
SF2_ENVM_REMAP_CR:      .word   0x40038010
SF2_DDRB_NB_SIZE:       .word   0x40038030
SF2_DDRB_CR:            .word   0x40038034
SF2_EDAC_CR:            .word   0x40038038
SF2_MDDR_MODE_CR:       .word   0x40020818
 
.end
