#include "tpl_assembler.h"
#include "tpl_asm_definitions.h"
//#include "tpl_os_kernel_stack.h"
#include "tpl_service_ids.h"

.equ NO_NEED_SWITCH_NOR_SCHEDULE,   0
.equ NO_NEED_SWITCH,                0
.equ NEED_SWITCH,                   1
.equ NEED_SAVE,                     2

.extern tpl_reentrancy_counter

/*
    the tpl_sc_handler uses tpl_kern
*/

#define OS_START_SEC_VAR
#include "tpl_as_memmap.h"
.equ KERNEL_STACK_SIZE, 400
.extern tpl_kern
tpl_kernel_stack:
	.space KERNEL_STACK_SIZE-2
tpl_kernel_stack_bottom:
	.space 2

#define OS_STOP_SEC_VAR
#include "tpl_as_memmap.h"

/*
    the tpl_sc_handler uses the dispatch table
*/

#define OS_START_SEC_CONST
#include "tpl_as_memmap.h"

.extern tpl_dispatch_table

#define OS_STOP_SEC_CONST
#include "tpl_as_memmap.h"

/*
    the code starts here
*/

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

.global         tpl_sc_handler
.type           tpl_sc_handler, %function
tpl_sc_handler:
    cmp         #SYSCALL_COUNT, REG_SID
    jhs         tpl_sc_handler_invalid_service_id
    sub         #16, r1
    pushx.a     r11
    dint
    tst.b       &tpl_reentrancy_counter
    jnz         tpl_sc_handler_no_stack_switch
    mov         r1, r11
    mov         #tpl_kernel_stack_bottom, r1
    pushx       r11

tpl_sc_handler_no_stack_switch:
    inc.b       &tpl_reentrancy_counter
    mov         #tpl_kern, r11
    mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
    mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SCHEDULE(r11)
    rla         REG_SID
    call        tpl_dispatch_table(REG_SID)
    mov         r1, r13
    pop         r1
    movx.a      REG_RETARG, 16(r1)
    mov         #tpl_kern, r11
    tst.b       TPL_KERN_OFFSET_NEED_SWITCH(r11)
    jz          tpl_sc_handler_no_context_switch
    mov         #0, REG_RETARG
    bit.b       #NEED_SAVE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
    jz          tpl_sc_handler_no_save_running_context
    mov         22(r1), r14
    mov         20(r1), 22(r1)
    swpb        r14
    rlam.w      #4, r14
    bis         r2, r14
    mov         r14, 20(r1)
    pushm.a     #7, r10
    mov         &tpl_kern, r11
    mov         @r11, r11
    mov         r1, @r11
    mov         r13, r1
    mov         #1, REG_RETARG

tpl_sc_handler_no_save_running_context:
    add         #2, r1
    call        tpl_run_elected
    mov         &tpl_kern, r11
    mov         @r11, r11
    mov         @r11, r1
    popm.a      #7, r10
    mov         20(r1), r11
    mov         20(r1), 20(r1)
    and         #0x0FFF, r11
    mov         r11, r2
    mov         20(r1), r11
    and         #0x0FFF, r11
    swpb        r11
    rram.w      #4, r11
    mov         r11, 22(r1)
    /**/call    tpl_load_context

tpl_sc_handler_invalid_service_id:
    nop

tpl_sc_handler_no_context_switch:
    dec.b       &tpl_reentrancy_counter
    jnz         tpl_sc_handler_still_in_kernel
    eint

tpl_sc_handler_still_in_kernel:
    popx.a      r11
    add         #12, r1
    popx.a      REG_RETARG
    ret

//.global tpl_systick_handler
//.type   tpl_systick_handler, %function

//tpl_systick_handler:
//    pushx.a REG_RETARG
//#ifdef MSPGCC_ABI
//    pushm.a     #4, r14
//#endif
//#ifdef GCCFORMSP_ABI
//    pushm.a     #3, r15
//    pushx.a     r11
//#endif
//
//    mov         r1, r11
//    mov         #tpl_kern_stack_bottom, r1
//    push        r11
//
//    mov         #tpl_kern, r11
//    mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SWITCH(r11)
//    mov.b       #NO_NEED_SWITCH_NOR_SCHEDULE, TPL_KERN_OFFSET_NEED_SCHEDULE(r11)
//
//    call        tpl_counter_tick/*_SystemCounter*/
//
//    mov         r1, r13
//    pop         r1
//    mov         #tpl_kern, r11
//    tst.b       TPL_KERN_OFFSET_NEED_SWITCH(r11)
//    jz          tpl_systick_handler_no_context_switch
//
//    pushm.a     #7, r10
//
//    mov         &tpl_kern, r11
//    mov         @r11, r11
//    mov         r1, @r11
//
//    mov         r13, r1
//    mov         #1, REG_RETARG
//    add         #2, r1
//    call        tpl_run_elected
//
//    mov         &tpl_kern, r11
//    mov         @r11, r11
//    mov         @r11, r1
//
//    popm.a      #7, r10

//tpl_systick_handler_no_context_switch:
//#ifdef MSPGCC_ABI
//    popm.a      #4, r14
//#endif
//#ifdef GCCFORMSP_ABI
//    popx.a r11
//    popm.a #3, r15
//#endif
//    popx.a REG_RETARG
//    reti

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"
