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
//#include "tpl_os_generated_configuration.h"

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

void tpl_sleep(void)
{
    while (1) {}
}

void tpl_shutdown(void)
{
    /* sleep forever */
    while (1) {}
}

/*
 * This handler is called as interrupt routine when a sc is executed
 * r3 contains what to do. If it contains 0, it is a tpl_get_task_lock
 * and the interrupt bit (EE) that was saved in SRR1 (also known as SPR27)
 * as to be cleared. If it is 1, it is a tpl_release_task_lock and EE has
 * to be set.
 */
asm void tpl_sc_handler(void)
{
            nofralloc
            /*  copy SRR1 into r2                                       */
            mfspr   r4,27
            /*  compare r3 to 0                                         */
            cmpwi   r3,0
            /*  xor r3 and r4 and put the result in r4                  */
            bne     unlock
            /*  clear the EE bit                                        */
            
}

/*
 * tpl_get_task_lock is used to lock a critical section 
 * around the task management in the os.
 */
asm void tpl_get_task_lock(void)
{
            nofralloc							
            /*  Get the MSR.                                    */
            mfmsr   r0
            /*  Check the EE bit                                */
            andi.   r0,r0,EE_BIT
            /*  If 0, interrupt are already disabled, return    */
            beqlr
            
            mfmsr   r0
            /*  Turn the EE bit off                             */
            xori    r0,r0,EE_BIT
            /*  Update the MSR                                  */
            mtmsr   r0
            
            blr
}

/*
 * tpl_release_task_lock is used to unlock a critical section
 * around the task management in the os.
 */
asm void tpl_release_task_lock(void)
{
            nofralloc							
            /*  Get the MSR.                                    */
            mfmsr   r0
            /*  Check the EE bit                                */
            andi.   r0,r0,EE_BIT
            /*  If 1, interrupt are already enabled, return     */
            bnelr
            
            mfmsr   r0
            /*  Turn the EE bit off                             */
            xori    r0,r0,EE_BIT
            /*  Update the MSR                                  */
            mtmsr   r0
            
            blr
}

asm void tpl_switch_context(
    register tpl_context *old_context,
    register tpl_context *new_context
)
{
            nofralloc							
            /*  Check the old context pointer.
                If NULL, the old context is not saved           */
            cmpwi   old_context,0
            beq     no_save
            /*  Get the pointer to the integer context in r0
                r0 is a volatile register and can be used freely
                in the cooperative context switching            */
            lwz     r11,INT_CONTEXT(old_context)
            /*  Save the GPRs                                   */
            stmw    r0,GPR0(r11)
            /*  Save the CR                                     */
            mfcr    r0
            stw     r0,CR(r11)
            /*  Save the XER                                    */
            mfxer   r0
            stw     r0,XER(r11)
            /*  Save the LR                                     */
            mflr    r0
            stw     r0,LR(r11)
            /*  Save the CTR                                    */
            mfctr   r0
            stw     r0,CTR(r11)
            /*  Check if the task has a floating point context  */
            lwz     r11,FP_CONTEXT(old_context)
            cmpwi   r11,0
            beq     no_old_fp
            /*  Store non volatile floating point registers     */
            stfd    f14,FPR14(r11)
            stfd    f15,FPR15(r11)
            stfd    f16,FPR16(r11)
            stfd    f17,FPR17(r11)
            stfd    f18,FPR18(r11)
            stfd    f19,FPR19(r11)
            stfd    f20,FPR20(r11)
            stfd    f21,FPR21(r11)
            stfd    f22,FPR22(r11)
            stfd    f23,FPR23(r11)
            stfd    f24,FPR24(r11)
            stfd    f25,FPR25(r11)
            stfd    f26,FPR26(r11)
            stfd    f27,FPR27(r11)
            stfd    f28,FPR28(r11)
            stfd    f29,FPR29(r11)
            stfd    f30,FPR30(r11)
            stfd    f31,FPR31(r11)
            /*  Store the floating point condition register     */
            mffs    f14
            stfd    f14,FPSCR(r11)
no_old_fp:
no_save:
            /*  Check if the task has a floating point context  */
            lwz     r11,FP_CONTEXT(new_context)
            cmpwi   r11,0
            beq     no_new_fp
            /*  Get back the floating point condition register  */
            lfd     f14,FPSCR(r11)
            mtfsf   0xff,f14
            /*  Get back the floating point registers           */
            lfd     f1,FPR1(r11)
            lfd     f2,FPR2(r11)
            lfd     f3,FPR3(r11)
            lfd     f4,FPR4(r11)
            lfd     f5,FPR5(r11)
            lfd     f6,FPR6(r11)
            lfd     f7,FPR7(r11)
            lfd     f8,FPR8(r11)
            lfd     f9,FPR9(r11)
            lfd     f10,FPR10(r11)
            lfd     f11,FPR11(r11)
            lfd     f12,FPR12(r11)
            lfd     f13,FPR13(r11)
            lfd     f14,FPR14(r11)
            lfd     f15,FPR15(r11)
            lfd     f16,FPR16(r11)
            lfd     f17,FPR17(r11)
            lfd     f18,FPR18(r11)
            lfd     f19,FPR19(r11)
            lfd     f20,FPR20(r11)
            lfd     f21,FPR21(r11)
            lfd     f22,FPR22(r11)
            lfd     f23,FPR23(r11)
            lfd     f24,FPR24(r11)
            lfd     f25,FPR25(r11)
            lfd     f26,FPR26(r11)
            lfd     f27,FPR27(r11)
            lfd     f28,FPR28(r11)
            lfd     f29,FPR29(r11)
            lfd     f30,FPR30(r11)
            lfd     f31,FPR31(r11)
no_new_fp:
            /*  Get the integer context pointer                 */
            lwz     r3,INT_CONTEXT(new_context)
            /*  Get back the CTR                                */
            lwz     r0,CTR(r3)
            mtctr   r0
            /*  Get back the LR                                 */
            lwz     r0,LR(r3)
            mtlr    r0
            /*  Get back the XER                                */
            lwz     r0,XER(r3)
            mtxer   r0
            /*  Get back the CR                                 */
            lwz     r0,CR(r3)
            mtcr    r0
            /*  Get back integer registers from r4 to r31       */
            lmw     r4,GPR4(r3)
            /*  Get back the others                             */
            lwz     r0,GPR0(r3)
            lwz     r1,GPR1(r3)
            lwz     r2,GPR2(r3)
            lwz     r3,GPR3(r3)
            
            /*  Return                                          */
            blr
}

/*
 * tpl_switch_context_from_it
 */

asm void tpl_switch_context_from_it(
    register tpl_context *old_context /* aka r3 */,
    register tpl_context *new_context /* aka r4 */)
{
            nofralloc							

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
