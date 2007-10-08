/**
 * @file tpl_machine_ppc.c
 *
 * @section descr File description
 *
 * Trampoline machine dependant C implementation stuff for the PowerPC port.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_it.h"
/*#include "tpl_os_generated_configuration.h"*/

extern tpl_exec_common *tpl_running_obj;

#define EE_BIT      0x8000

#define INT_CONTEXT 0
#define FP_CONTEXT  4

/*
 * Mapping in the context structures
 */
#define GPR0    0
#define GPR1    4
#define GPR2    8
#define GPR3    12
#define GPR4    16
#define GPR5    20
#define GPR6    24
#define GPR7    28
#define GPR8    32
#define GPR9    36
#define GPR10   40
#define GPR11   44
#define GPR12   48
#define GPR13   52
#define GPR14   56
#define GPR15   60
#define GPR16   64
#define GPR17   68
#define GPR18   72
#define GPR19   76
#define GPR20   80
#define GPR21   84
#define GPR22   88
#define GPR23   92
#define GPR24   96
#define GPR25   100
#define GPR26   104
#define GPR27   108
#define GPR28   112
#define GPR29   116
#define GPR30   120
#define GPR31   124
#define CR      128
#define XER     132
#define LR      136
#define CTR     140
#define SRR0    144
#define SRR1    148

#define FPR0    0
#define FPR1    8
#define FPR2    16
#define FPR3    24
#define FPR4    32
#define FPR5    40
#define FPR6    48
#define FPR7    56
#define FPR8    64
#define FPR9    72
#define FPR10   80
#define FPR11   88
#define FPR12   96
#define FPR13   104
#define FPR14   112
#define FPR15   120
#define FPR16   128
#define FPR17   136
#define FPR18   144
#define FPR19   152
#define FPR20   160
#define FPR21   168
#define FPR22   176
#define FPR23   184
#define FPR24   192
#define FPR25   200
#define FPR26   208
#define FPR27   216
#define FPR28   224
#define FPR29   232
#define FPR30   240
#define FPR31   248
#define FPSCR   256

#define spr_SRR0    spr26
#define spr_SRR1    spr27

#define F_GET_TASK_LOCK         0
#define F_RELEASE_TASK_LOCK     1

void tpl_sleep(void)
{
    while (1) {}
}

void tpl_shutdown(void)
{
    /* sleep forever */
    while (1) {}
}

typedef void (* tpl_system_call)(void);

/*
 * forward declaration
 */
void tpl_sc_suspend_all_interrupts(void);
void tpl_sc_resume_all_interrupts(void);
void tpl_sc_disable_all_interrupts(void);
void tpl_sc_enable_all_interrupts(void);
void tpl_sc_switch_context(void);

/*
 * System calls table
 */
tpl_system_call tpl_sc[5] = {
    tpl_sc_suspend_all_interrupts,
    tpl_sc_resume_all_interrupts,
    tpl_sc_disable_all_interrupts,
    tpl_sc_enable_all_interrupts,
    tpl_sc_switch_context
};

#define SC_SUSPEND_ALL_INTERRUPTS       0
#define SC_RESUME_ALL_INTERRUPTS        4
#define SC_DISABLE_ALL_INTERRUPTS       8
#define SC_ENABLE_ALL_INTERRUPTS        12
#define SC_SWITCH_CONTEXT               16

/*
 * tpl_locking_depth is used to track how many recursive
 * locks have been done
 */
volatile static u32 tpl_locking_depth = 0;

/*
 * tpl_sc_handler is called as interrupt routine when a sc is executed
 * r3 contains the system call (actually the offset in the sc table).
 *
 * tpl_sc_handler saves r2, cr and lr to use them but does not reuse
 * them after the program return from the system call. So r2 can be
 * used without saving it.
 *
 * stack is like that before the system call
 *
 * +------+
 * |  cr  |
 * +------+
 * |  lr  |
 * +------+
 * |  r2  |
 * +------+
 * |  r3  |
 * +------+
 */
asm void tpl_sc_handler(void)
{
            nofralloc
/*  save r2 and lr on the stack                             */
            subi    r1,r1,12
            stw     r2,8(r1)
            mflr    r2
            stw     r2,4(r1)
            mfcr    r2
            stw     r2,0(r1)
/*  get the system call function                            */
            lis     r2,hi16(tpl_sc)
            li      r2,lo16(tpl_sc)
            lwzx    r2,r2,r3
            mtlr    r2
/*  call it                                                 */
            blrl
/*  restore r2 and lr from the stack                        */
            lwz     r2,0(r1)
            mtcr    r2
            lwz     r2,4(r1)
            mtlr    r2
            lwz     r2,8(r1)
            addi    r1,r1,12
/*  return to the caller                                    */
            rfi
}

/*
 * System calls
 * All the system calls are called from tpl_sc_handler.
 *
 * tpl_sc_suspend_all_interrupts disables external interrupts and increment
 * the locking depth.
 * r2 is used to get a copy of SRR1 to work on and to increment
 * the locking depth.
 * r3 is used to store the mask to change the state of bit EE and
 * to store the adresse of tpl_locking_depth.
 */
asm void tpl_sc_suspend_all_interrupts(void)
{
            nofralloc
/*  copy SRR1 into r2                                       */
            mfspr   r2,spr_SRR1
/*  set r3 to EE_BIT constant                               */
            li      r3,0
            ori     r3,r3,EE_BIT
/*  clear the EE_BIT in SRR1 copy                           */
            andc    r2,r2,r3
/*  put back r2 in SRR1                                     */
            mtspr   spr_SRR1,r2
/*  increment the locking depth                             */
            lis     r3,ha16(tpl_locking_depth)
            lwz     r2,lo16(tpl_locking_depth)(r3)
            addi    r2,r2,1
            stw     r2,lo16(tpl_locking_depth)(r3)
            blr
}

/*
 * tpl_sc_resume_all_interrupts decrements the locking depth and
 * if it reaches 0, enable external interrupts.
 * r2 is used to get a copy of SRR1 to work on and to decrement
 * the locking depth
 * r3 is used to store the mask to change the state of bit EE and
 * to store the adresse of tpl_locking_depth
 */
asm void tpl_sc_resume_all_interrupts(void)
{
            nofralloc
/*  decrement the locking depth                             */
            lis     r3,ha16(tpl_locking_depth)
            lwz     r2,lo16(tpl_locking_depth)(r3)
            subi    r2,r2,1
            stw     r2,lo16(tpl_locking_depth)(r3)
/*  check whether the interrupts should be enabled          */
            cmpwi   r2,0
            bne     no_enable
/*  copy SRR1 into r2                                       */
            mfspr   r2,spr_SRR1
/*  set r3 to EE_BIT constant                               */
            li      r3,0
            ori     r3,r3,EE_BIT
/*  set the EE_BIT in SRR1 copy                           */
            or      r2,r2,r3
/*  put back r2 in SRR1                                     */
            mtspr   spr_SRR1,r2
no_enable:  blr
}

/*
 * tpl_sc_disable_all_interrupts disables external interrupts.
 * r2 is used to get a copy of SRR1 to work on.
 * r3 is used to store the mask to change the state of bit EE.
 */
asm void tpl_sc_disable_all_interrupts(void)
{
            nofralloc
/*  copy SRR1 into r2                                       */
            mfspr   r2,spr_SRR1
/*  set r3 to EE_BIT constant                               */
            li      r3,0
            ori     r3,r3,EE_BIT
/*  clear the EE_BIT in SRR1 copy                           */
            andc    r2,r2,r3
/*  put back r2 in SRR1                                     */
            mtspr   spr_SRR1,r2
            blr
}

/*
 * tpl_sc_enable_all_interrupts decrements the locking depth and
 * if it reaches 0, enable external interrupts.
 * r2 is used to get a copy of SRR1 to work on and to decrement
 * the locking depth
 * r3 is used to store the mask to change the state of bit EE and
 * to store the adresse of tpl_locking_depth
 */
asm void tpl_sc_enable_all_interrupts(void)
{
            nofralloc
/*  copy SRR1 into r2                                       */
            mfspr   r2,spr_SRR1
/*  set r3 to EE_BIT constant                               */
            li      r3,0
            ori     r3,r3,EE_BIT
/*  set the EE_BIT in SRR1 copy                           */
            or      r2,r2,r3
/*  put back r2 in SRR1                                     */
            mtspr   spr_SRR1,r2
            blr
}

/*
 * tpl_get_task_lock is used to lock a critical section 
 * around the task management in the os.
 */
asm void tpl_get_task_lock(void)
{
            nofralloc
/*  save r3 on the stack                                    */
            subi    r1,r1,4
            stw     r3,0(r1)
/*  call the SC_SUSPEND_ALL_INTERRUPTS system service       */
            li      r3,SC_SUSPEND_ALL_INTERRUPTS
            sc
/*  restore r3 and the stack                                */
            lwz     r3,0(r1)
            addi    r1,r1,4
            blr
}

/*
 * tpl_release_task_lock is used to unlock a critical section
 * around the task management in the os.
 */
asm void tpl_release_task_lock(void)
{
            nofralloc
/*  save r3 on the stack                                    */
            subi    r1,r1,4
            stw     r3,0(r1)
/*  call the SC_RESUME_ALL_INTERRUPTS system service        */
            li      r3,SC_RESUME_ALL_INTERRUPTS
            sc
/*  restore r3 and the stack                                */
            lwz     r3,0(r1)
            addi    r1,r1,4
            blr
}

asm void tpl_switch_context(
    register tpl_context *old_context, /* r3 */
    register tpl_context *new_context  /* r4 */
)
{
            nofralloc
/*  save r3 on the stack                                    */
            subi    r1,r1,4
            stw     r3,0(r1)
/*  call the SC_SWITCH_CONTEXT system service        */
            li      r3,SC_SWITCH_CONTEXT
            sc
/*  restore r3 and the stack                                */
            lwz     r3,0(r1)
            addi    r1,r1,4
            blr
}

asm void tpl_sc_switch_context(void)
{
            nofralloc
/*  r3 has been save on the stack by tpl_switch_context
    r2 and lr have been saved on the stack by tpl_sc_handler.
    the saved r3 contains the pointer to the context to be
    saved so we have to get it back                             */
            lwz     r3,12(r1)
/*  Check the old context pointer.
    If NULL, the old context is not saved                       */
            cmpwi   r3,0
            beq     no_save
/*  Get the pointer to the integer context in r2
    r2 is a volatile register and can be used freely
    in the cooperative context switching                        */
            lwz     r2,INT_CONTEXT(r3)
/*  Save the GPRs                                               */
            stw     r0,GPR0(r2)
            stw     r1,GPR1(r2)
/*  Get back from the stack the saved r2                        */
            lwz     r0,8(r1)
            stw     r0,GPR2(r2)
            stw     r3,GPR3(r2)
            stw     r4,GPR4(r2)
            stw     r5,GPR5(r2)
            stw     r6,GPR6(r2)
            stw     r7,GPR7(r2)
            stw     r8,GPR8(r2)
            stw     r9,GPR9(r2)
            stw     r10,GPR10(r2)
            stw     r11,GPR11(r2)
            stw     r12,GPR12(r2)
            stw     r13,GPR13(r2)
            stw     r14,GPR14(r2)
            stw     r15,GPR15(r2)
            stw     r16,GPR16(r2)
            stw     r17,GPR17(r2)
            stw     r18,GPR18(r2)
            stw     r19,GPR19(r2)
            stw     r20,GPR20(r2)
            stw     r21,GPR21(r2)
            stw     r22,GPR22(r2)
            stw     r23,GPR23(r2)
            stw     r24,GPR24(r2)
            stw     r25,GPR25(r2)
            stw     r26,GPR26(r2)
            stw     r27,GPR27(r2)
            stw     r28,GPR28(r2)
            stw     r29,GPR29(r2)
            stw     r30,GPR30(r2)
            stw     r31,GPR31(r2)
/*  Save the CR got from the stack                  */
            lwz     r0,0(r1)
            stw     r0,CR(r2)
/*  Save the XER                                    */
            mfxer   r0
            stw     r0,XER(r2)
/*  Save the LR got from the stack                  */
            lwz     r0,4(r1)
            stw     r0,LR(r2)
/*  Save the CTR                                    */
            mfctr   r0
            stw     r0,CTR(r2)
/*  Save SRR0 and SRR1                              */
            mfspr   r0,spr_SRR0
            stw     r0,SRR0(r2)
            mfspr   r0,spr_SRR1
            stw     r0,SRR1(r2)
/*  Check if the task has a floating point context  */
            lwz     r2,FP_CONTEXT(r3)
            cmpwi   r2,0
            beq     no_old_fp
/*  Store non volatile floating point registers     */
            stfd    f14,FPR14(r2)
            stfd    f15,FPR15(r2)
            stfd    f16,FPR16(r2)
            stfd    f17,FPR17(r2)
            stfd    f18,FPR18(r2)
            stfd    f19,FPR19(r2)
            stfd    f20,FPR20(r2)
            stfd    f21,FPR21(r2)
            stfd    f22,FPR22(r2)
            stfd    f23,FPR23(r2)
            stfd    f24,FPR24(r2)
            stfd    f25,FPR25(r2)
            stfd    f26,FPR26(r2)
            stfd    f27,FPR27(r2)
            stfd    f28,FPR28(r2)
            stfd    f29,FPR29(r2)
            stfd    f30,FPR30(r2)
            stfd    f31,FPR31(r2)
/*  Store the floating point condition register     */
            mffs    f14
            stfd    f14,FPSCR(r2)
no_old_fp:
no_save:
/*  Check if the task has a floating point context  */
            lwz     r2,FP_CONTEXT(r4)
            cmpwi   r2,0
            beq     no_new_fp
/*  Get back the floating point condition register  */
            lfd     f14,FPSCR(r2)
            mtfsf   0xff,f14
/*  Get back the floating point registers           */
            lfd     f1,FPR1(r2)
            lfd     f2,FPR2(r2)
            lfd     f3,FPR3(r2)
            lfd     f4,FPR4(r2)
            lfd     f5,FPR5(r2)
            lfd     f6,FPR6(r2)
            lfd     f7,FPR7(r2)
            lfd     f8,FPR8(r2)
            lfd     f9,FPR9(r2)
            lfd     f10,FPR10(r2)
            lfd     f11,FPR11(r2)
            lfd     f12,FPR12(r2)
            lfd     f13,FPR13(r2)
            lfd     f14,FPR14(r2)
            lfd     f15,FPR15(r2)
            lfd     f16,FPR16(r2)
            lfd     f17,FPR17(r2)
            lfd     f18,FPR18(r2)
            lfd     f19,FPR19(r2)
            lfd     f20,FPR20(r2)
            lfd     f21,FPR21(r2)
            lfd     f22,FPR22(r2)
            lfd     f23,FPR23(r2)
            lfd     f24,FPR24(r2)
            lfd     f25,FPR25(r2)
            lfd     f26,FPR26(r2)
            lfd     f27,FPR27(r2)
            lfd     f28,FPR28(r2)
            lfd     f29,FPR29(r2)
            lfd     f30,FPR30(r2)
            lfd     f31,FPR31(r2)
no_new_fp:
/*  Get the integer context pointer                 */
            lwz     r2,INT_CONTEXT(r4)
/*  Get back the CTR                                */
            lwz     r0,CTR(r2)
            mtctr   r0
/*  Get back the LR to the stack                    */
            lwz     r0,LR(r2)
            stw     r0,4(r1)
/*  Get back the XER                                */
            lwz     r0,XER(r2)
            mtxer   r0
/*  Get back the CR to the stack                    */
            lwz     r0,CR(r2)
            stw     r0,0(r1)
/*  Get bask SRR0 and SRR1                          */
            lwz     r0,SRR0(r2)
            mtspr   spr_SRR0,r0
            lwz     r0,SRR1(r2)
            mtspr   spr_SRR1,r0
/*  Get back the integer registers                  */
            lwz     r31,GPR31(r2)
            lwz     r30,GPR30(r2)
            lwz     r29,GPR29(r2)
            lwz     r28,GPR28(r2)
            lwz     r27,GPR27(r2)
            lwz     r26,GPR26(r2)
            lwz     r25,GPR25(r2)
            lwz     r24,GPR24(r2)
            lwz     r23,GPR23(r2)
            lwz     r22,GPR22(r2)
            lwz     r21,GPR21(r2)
            lwz     r20,GPR20(r2)
            lwz     r19,GPR19(r2)
            lwz     r18,GPR18(r2)
            lwz     r17,GPR17(r2)
            lwz     r16,GPR16(r2)
            lwz     r15,GPR15(r2)
            lwz     r14,GPR14(r2)
            lwz     r13,GPR13(r2)
            lwz     r12,GPR12(r2)
            lwz     r11,GPR11(r2)
            lwz     r10,GPR10(r2)
            lwz     r9,GPR9(r2)
            lwz     r8,GPR8(r2)
            lwz     r7,GPR7(r2)
            lwz     r6,GPR6(r2)
            lwz     r5,GPR5(r2)
            lwz     r4,GPR4(r2)
            lwz     r3,GPR3(r2)
            lwz     r1,GPR1(r2)
            lwz     r0,GPR0(r2)
            lwz     r2,GPR2(r2)
/*  Restore the stack as wanted for a cooperative context switching */
            stw     r3,12(r1)
            stw     r2,8(r1)
            
/*  Return                                          */
            blr
}

/*
 * tpl_interrupt_handler_wrapper saves the integer registers
 * to the context of the currently running object, then it
 * calls tpl_central_interrupt_handler, restores the context
 * of the currently running object (that could have changed
 * since tpl_central_interrupt_handler may switch the context
 * and returns from interrupt. a jump (not a call) to 
 * tpl_interrupt_handler_wrapper should be done in the interrupt
 * vector.
 * 
 * When entering tpl_interrupt_handler_wrapper, r3 should contain
 * the id of the ISR2 that is passed to tpl_central_interrupt_handler.
 * The interrupt vector entry code should save r3 on the stack, load
 * it with the corresponding ISR id and jump to tpl_interrupt_handler_wrapper
 *
 * subi r1,r1,4
 * stw  r3,0(r1)
 * li   r3,isr_id
 * bl   tpl_interrupt_handler_wrapper
 *
 * tpl_interrupt_handler_wrapper restore r3 from the stack before
 * returning from interrupt.
 */
asm void tpl_interrupt_handler_wrapper(void)
{
            nofralloc
/*  Save working register                           */
            subi    r1,r1,8
            stw     r2,0(r1)
            stw     r3,4(r1)
/*  Get a pointer to the tpl_running_object         */
            lis     r3,ha16(tpl_running_obj)
            lwz     r3,lo16(tpl_running_obj)(r3)
/*  Get the static descriptor pointer
    Since the context is in the first place of the
    static descriptor struct, it is also the
    context pointer                                 */
            lwz     r3,0(r3)
/*  Get the pointer to the integer context in r2    */
            lwz     r2,INT_CONTEXT(r3)
/*  Save the registers in the context               */
/*  Save the GPRs                                   */
            stw     r0,GPR0(r2)
            stw     r1,GPR1(r2)
/*  Get back r2                                     */
            lwz     r0,0(r1)
            stw     r0,GPR2(r2)
/*  Get back r3 (the real one that was saved by the
    interrupt vector wrapper                        */
            lwz     r0,8(r1)
            stw     r0,GPR3(r2)
            stw     r4,GPR4(r2)
            stw     r5,GPR5(r2)
            stw     r6,GPR6(r2)
            stw     r7,GPR7(r2)
            stw     r8,GPR8(r2)
            stw     r9,GPR9(r2)
            stw     r10,GPR10(r2)
            stw     r11,GPR11(r2)
            stw     r12,GPR12(r2)
            stw     r13,GPR13(r2)
            stw     r14,GPR14(r2)
            stw     r15,GPR15(r2)
            stw     r16,GPR16(r2)
            stw     r17,GPR17(r2)
            stw     r18,GPR18(r2)
            stw     r19,GPR19(r2)
            stw     r20,GPR20(r2)
            stw     r21,GPR21(r2)
            stw     r22,GPR22(r2)
            stw     r23,GPR23(r2)
            stw     r24,GPR24(r2)
            stw     r25,GPR25(r2)
            stw     r26,GPR26(r2)
            stw     r27,GPR27(r2)
            stw     r28,GPR28(r2)
            stw     r29,GPR29(r2)
            stw     r30,GPR30(r2)
            stw     r31,GPR31(r2)
/*  Save the CR                                     */
            mfcr    r0
            stw     r0,CR(r2)
/*  Save the XER                                    */
            mfxer   r0
            stw     r0,XER(r2)
/*  Save the LR                                     */
            mflr    r0
            stw     r0,LR(r2)
/*  Save the CTR                                    */
            mfctr   r0
            stw     r0,CTR(r2)
/*  Save SRR0 and SRR1                              */
            mfspr   r0,spr_SRR0
            stw     r0,SRR0(r2)
            mfspr   r0,spr_SRR1
            stw     r0,SRR1(r2)
            
            
/*  Get back the r3 that was
    set to the id of the ISR2                       */
            lwz     r3,4(r1)
/*  Call tpl_central_interrupt_handler              */
            bl      tpl_central_interrupt_handler


/*  Restore the registers from the context.
    This has to be redone since the context may
    be changed by tpl_central_interrupt_handler.
    Get a pointer to the tpl_running_object         */
            lis     r3,ha16(tpl_running_obj)
            lwz     r3,lo16(tpl_running_obj)(r3)
/*  Get the static descriptor pointer
    Since the context is in the first place of the
    static descriptor struct, it is also the
    context pointer                                 */
            lwz     r3,0(r3)
/*  Get the pointer to the integer context in r2    */
            lwz     r2,INT_CONTEXT(r3)
/*  Get back the registers of the context           */
            lwz     r31,GPR31(r2)
            lwz     r30,GPR30(r2)
            lwz     r29,GPR29(r2)
            lwz     r28,GPR28(r2)
            lwz     r27,GPR27(r2)
            lwz     r26,GPR26(r2)
            lwz     r25,GPR25(r2)
            lwz     r24,GPR24(r2)
            lwz     r23,GPR23(r2)
            lwz     r22,GPR22(r2)
            lwz     r21,GPR21(r2)
            lwz     r20,GPR20(r2)
            lwz     r19,GPR19(r2)
            lwz     r18,GPR18(r2)
            lwz     r17,GPR17(r2)
            lwz     r16,GPR16(r2)
            lwz     r15,GPR15(r2)
            lwz     r14,GPR14(r2)
            lwz     r13,GPR13(r2)
            lwz     r12,GPR12(r2)
            lwz     r11,GPR11(r2)
            lwz     r10,GPR10(r2)
            lwz     r9,GPR9(r2)
            lwz     r8,GPR8(r2)
            lwz     r7,GPR7(r2)
            lwz     r6,GPR6(r2)
            lwz     r5,GPR5(r2)
            lwz     r4,GPR4(r2)
            lwz     r1,GPR1(r2)
            lwz     r0,GPR0(r2)
            lwz     r2,GPR2(r2)
/*  Restore working register
    This part restore the r3 that was saved by the
    interrupt vector entry wrapper                  */
            lwz     r2,0(r1)
            lwz     r3,8(r1)
            addi    r1,r1,12
            rfi
}

/*
 * tpl_switch_context_from_it
 *
 * Since the integer context is saved at the start of
 * the interrupt handling, tpl_switch_context_from_it manages
 * the floating point context only. 
 */
asm void tpl_switch_context_from_it(
    register tpl_context *old_context /* aka r3 */,
    register tpl_context *new_context /* aka r4 */)
{
            nofralloc
/*  Get the FP context of the old_context   */
/*  Check if the task has a floating point context  */
            lwz     r2,FP_CONTEXT(old_context)
            cmpwi   r2,0
            beq     no_old
/*  Store non volatile floating point registers     */
            stfd    f1,FPR1(r2)
            stfd    f2,FPR2(r2)
            stfd    f3,FPR3(r2)
            stfd    f4,FPR4(r2)
            stfd    f5,FPR5(r2)
            stfd    f6,FPR6(r2)
            stfd    f7,FPR7(r2)
            stfd    f8,FPR8(r2)
            stfd    f9,FPR9(r2)
            stfd    f10,FPR10(r2)
            stfd    f11,FPR11(r2)
            stfd    f12,FPR12(r2)
            stfd    f13,FPR13(r2)
            stfd    f14,FPR14(r2)
            stfd    f15,FPR15(r2)
            stfd    f16,FPR16(r2)
            stfd    f17,FPR17(r2)
            stfd    f18,FPR18(r2)
            stfd    f19,FPR19(r2)
            stfd    f20,FPR20(r2)
            stfd    f21,FPR21(r2)
            stfd    f22,FPR22(r2)
            stfd    f23,FPR23(r2)
            stfd    f24,FPR24(r2)
            stfd    f25,FPR25(r2)
            stfd    f26,FPR26(r2)
            stfd    f27,FPR27(r2)
            stfd    f28,FPR28(r2)
            stfd    f29,FPR29(r2)
            stfd    f30,FPR30(r2)
            stfd    f31,FPR31(r2)
/*  Store the floating point condition register     */
            mffs    f14
            stfd    f14,FPSCR(r2)
no_old:
/*  Check if the task has a floating point context  */
            lwz     r2,FP_CONTEXT(r4)
            cmpwi   r2,0
            beq     no_new
/*  Get back the floating point condition register  */
            lfd     f14,FPSCR(r2)
            mtfsf   0xff,f14
/*  Get back the floating point registers           */
            lfd     f1,FPR1(r2)
            lfd     f2,FPR2(r2)
            lfd     f3,FPR3(r2)
            lfd     f4,FPR4(r2)
            lfd     f5,FPR5(r2)
            lfd     f6,FPR6(r2)
            lfd     f7,FPR7(r2)
            lfd     f8,FPR8(r2)
            lfd     f9,FPR9(r2)
            lfd     f10,FPR10(r2)
            lfd     f11,FPR11(r2)
            lfd     f12,FPR12(r2)
            lfd     f13,FPR13(r2)
            lfd     f14,FPR14(r2)
            lfd     f15,FPR15(r2)
            lfd     f16,FPR16(r2)
            lfd     f17,FPR17(r2)
            lfd     f18,FPR18(r2)
            lfd     f19,FPR19(r2)
            lfd     f20,FPR20(r2)
            lfd     f21,FPR21(r2)
            lfd     f22,FPR22(r2)
            lfd     f23,FPR23(r2)
            lfd     f24,FPR24(r2)
            lfd     f25,FPR25(r2)
            lfd     f26,FPR26(r2)
            lfd     f27,FPR27(r2)
            lfd     f28,FPR28(r2)
            lfd     f29,FPR29(r2)
            lfd     f30,FPR30(r2)
            lfd     f31,FPR31(r2)
no_new:
            blr
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and lr and init the other registers to 0
 */
void tpl_init_context(tpl_exec_common *exec_obj)
{
	int i;
	ppc_integer_context *ic = exec_obj->static_desc->context.ic;
	
	for (i = 0; i < 32; i++ ) {
        ic->gpr[i] = 0;
	}
	
	ic->cr = 0;
	ic->xer = 0;
	ic->ctr = 0;
	
	ic->lr = (unsigned long)exec_obj->static_desc->entry;
	ic->gpr[1] = ((unsigned long)exec_obj->static_desc->stack.stack_zone)
	               + exec_obj->static_desc->stack.stack_size;
	/*  Size of the linkage area used to store (among others)
        the link register if the task calls a function          */
}

/*
 * tpl_init_machine init the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{
}
