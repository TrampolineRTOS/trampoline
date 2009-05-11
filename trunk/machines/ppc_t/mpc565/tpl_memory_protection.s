/**
 * @file tpl_memory_protection.s
 *
 * @section descr File description
 *
 * Trampoline processor dependant memory protection for MPC565 mpu.
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

#include "tpl_app_objects.h"

#define Global_Region_Attribute_Register    536
#define Kernel_mode_DMPU                    0x00000400
#define User_mode_DMPU                      0xF0000400

#define User_RW 0x0C00
#define User_RO 0x0800

#define DRBA0   792
#define DRBA1   793
#define DRBA2   794
#define DRBA3   795

#define DRA0    824
#define DRA1    825
#define DRA2    826
#define DRA3    827

.text
.globl tpl_kernel_mp
.globl tpl_user_mp
.globl tpl_set_process_mp
.globl tpl_set_app_mp

/**
 * Disable memory protection. This function is called when
 * entering in kernel mode (typically at the start of the it
 * handler and at thestart of the system call).
 *
 * no parameter and no return value
 *
 * Uses r11 only
 */
tpl_kernel_mp:

    /*  Load the control word                       */
    li      r11,Kernel_mode_DMPU
    /*  Get the Global Region Attribute Register    */
    mtspr   Global_Region_Attribute_Register,r11
    /*  That's all                                  */
    blr

/**
 * Enable memory protection. This function is called when
 * returning to user mode (typically at the end of the it
 * handler and at the start of the system call).
 *
 * no parameter and no return value
 *
 * Uses r11 only
 */
tpl_user_mp:

    /*  Load the control word                       */
    lis     r11,hi16(User_mode_DMPU)
    ori     r11,r11,lo16(User_mode_DMPU)
    /*  Get the Global Region Attribute Register    */
    mtspr   Global_Region_Attribute_Register,r11
    /*  That's all                                  */
    blr
    
/**
 * Set the memory protection for a process
 *
 * @param   r11 a pointer to the memory protection descriptor
 */
tpl_set_process_mp:

    /* get the start of private data region of the process              */

    lwz     r12,0(r11)
    slwi    r12,r12,12  /* shift it to put the bits at the good place   */
    mtspr   DRBA0,r12   /* put it in the register                       */
    
    /* get the end                                                      */

    lwz     r0,8(r11)
    sub     r12,r12,r0  /* compute the size                             */
    clrrwi  r12,r12,12  /* normalize it                                 */

    /* set the permissions                                              */

    ori     r12,r12,User_RW
    mtspr   DRA0,r12    /* put it in the register                       */
    
    /* get the start of private const region of the process             */

    lwz     r12,4(r11)
    slwi    r12,r12,12  /* shift it to put the bits at the good place   */
    mtspr   DRBA1,r12   /* put it in the register                       */

    /* get the end                                                      */

    lwz     r0,12(r11)
    sub     r12,r12,r0  /* compute the size                             */
    clrrwi  r12,r12,12  /* normalize it                                 */

    /* set the permissions                                              */

    ori     r12,r12,User_RO
    mtspr   DRA1,r12    /* put it in the register                       */
    
    blr
    
#ifdef WITH_AUTOSAR
/**
 * Set the memory protection for an application
 *
 * @param   r11 a pointer to the memory protection descriptor
 */
tpl_set_app_mp:

    /* get the start of private data region of the os application       */

    lwz     r12,16(r11)
    slwi    r12,r12,12  /* shift it to put the bits at the good place   */
    mtspr   DRBA2,r12   /* put it in the register                       */

    /* get the end                                                      */
    lwz     r0,24(r11)
    sub     r12,r12,r0  /* compute the size                             */
    clrrwi  r12,r12,12  /* normalize it                                 */

    /* set the permissions                                              */

    ori     r12,r12,User_RW
    mtspr   DRA2,r12    /* put it in the register                       */
    
    /* get the start of private const region of the os application      */

    lwz     r12,20(r11)
    slwi    r12,r12,12  /* shift it to put the bits at the good place   */
    mtspr   DRBA3,r12   /* put it in the register                       */

    /* get the end                                                      */

    lwz     r0,28(r11)
    sub     r12,r12,r0  /* compute the size                             */
    clrrwi  r12,r12,12  /* normalize it                                 */

    /* set the permissions                                              */

    ori     r12,r12,User_RO
    mtspr   DRA3,r12    /* put it in the register                       */
    
    blr
#endif
    
/* End of file tpl_memory_protection.s */
