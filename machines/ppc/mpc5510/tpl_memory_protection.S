/**
 * @file tpl_memory_protection.s
 *
 * @section descr File description
 *
 * Trampoline processor dependant memory protection for MPC551x mpu.
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

/* #include "tpl_memory_protection.h" */
#include "tpl_app_define.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_assembler.h"

/* Base address of the MPU */
#define MPUBase 0xFFF14000

/* MPU control/error status register */
#define MPU_CESR  0x00

/* MPU error address register, slave port 0 */
#define MPU_EAR0  0x10

/* MPU error detail register, slave port 0 */
#define MPU_EDR0  0x14

/* MPU error address register, slave port 1 */
#define MPU_EAR1  0x18

/* MPU error detail register, slave port 1 */
#define MPU_EDR1  0x1C

/* MPU error address register, slave port 2 */
#define MPU_EAR2  0x20

/* MPU error detail register, slave port 2 */
#define MPU_EDR2  0x24

/*
 * MPU Region descriptor 0
 */
#define MPU_RGD0_start  0x400
#define MPU_RGD0_end    0x404
#define MPU_RGD0_access 0x408
#define MPU_RGD0_pid    0x40C
/*
 * MPU Region descriptor 1
 */
#define MPU_RGD1_start  0x410
#define MPU_RGD1_end    0x414
#define MPU_RGD1_access 0x418
#define MPU_RGD1_pid    0x41C
/*
 * MPU Region descriptor 2
 */
#define MPU_RGD2_start  0x420
#define MPU_RGD2_end    0x424
#define MPU_RGD2_access 0x428
#define MPU_RGD2_pid    0x42C
/*
 * MPU Region descriptor 3
 */
#define MPU_RGD3_start  0x430
#define MPU_RGD3_end    0x434
#define MPU_RGD3_access 0x438
#define MPU_RGD3_pid    0x43C

/*
 * MPU Region descriptor 4
 */
#define MPU_RGD4_start  0x440
#define MPU_RGD4_end    0x444
#define MPU_RGD4_access 0x448
#define MPU_RGD4_pid    0x44C

/*
 * MPU_CESR value to init/disable memory protection
 * ie: all errors are cleared and the MPU is disabled
 * This is done by writing a 1 on all bits of the MPERR field
 * to clear all previous errors and a 0 in the VLD bit
 */
#define kernel_mode     0xE0000000

/*
 * MPU_CESR value to init/enable memory protection
 * ie: all errors are cleared and the MPU is enabled
 * This is done by writing a 1 on all bits of the MPERR field
 * to clear all previous errors and a 1 in the VLD bit
 */
#define user_mode       0xE0000001

/*
 * VAR region access right
 */
#define var_rgn_access  0x0000001E
  
/*
 * STACK region access right
 */
#define stack_rgn_access  0x0000001E

/*
 * Executable region access right
 * Here, the region is rx in User mode
 * and rxw in supervisor mode
 */
/* #define exe_rgn_access  0x0000001D */
#define exe_rgn_access  0x00000005

/*
 * noall access right
 * Here, the region is inaccessible in User mode
 * and rxw in supervisor mode
 */
#define noall_rgn_access  0x00000000

#if WITH_MEMORY_PROTECTION == YES

TPL_EXTERN tpl_mp_table
TPL_EXTERN tpl_kern
TPL_EXTERN tpl_reentrancy_counter

TPL_EXTERN  __PROGCONST_SECTION_START
TPL_EXTERN  __PROGCONST_SECTION_STOP

  .global tpl_kernel_mp
  .global tpl_user_mp
  .global tpl_set_process_mp
  .global tpl_init_mp
  
  .text
  .section .osCode CODE_ACCESS_RIGHT

/**
 * tpl_init_mp programs the MP descriptor 0-3 to allow
 * - Descriptor 0: code and constants. So the access is RX
 * - Descriptor 1: private data region of a process. So the access is RW
 * - Descriptor 2: stack of a process. So the access is RW
 * - Descriptor 3: data of an OS Application. So the access is RW
 */
tpl_init_mp:
  /*
   * Load the address of MPU
   */
  lis   r12,TPL_HIG(MPUBase)
  ori   r12,r12,TPL_LOW(MPUBase)
  
  /*
   * Set the start address to __PROGCONST_SECTION_START
   * and the end address to __PROGCONST_SECTION_STOP
   */
  lis   r11,TPL_HIG(__PROGCONST_SECTION_START)
  ori   r11,r11,TPL_LOW(__PROGCONST_SECTION_START)
  stw   r11,MPU_RGD0_start(r12)
  lis   r11,TPL_HIG(__PROGCONST_SECTION_STOP)
  ori   r11,r11,TPL_LOW(__PROGCONST_SECTION_STOP)
  stw   r11,MPU_RGD0_end(r12)

  /*
   * Load the exe access right in r11
   */
  lis   r11,TPL_HIG(exe_rgn_access)
  ori   r11,r11,TPL_LOW(exe_rgn_access)
  /*
   * Store it in the access register or region 0
   */
  stw   r11,MPU_RGD0_access(r12)
  
  /*
   * Validate the descriptor
   */
  li    r11,1
  stw   r11,MPU_RGD0_pid(r12)
  
  /*
   * Descriptor 4 is used for no access for user to the whole
   * memory space and all access for supervisor
   */
  li	r11,0
  stw   r11,MPU_RGD4_start(r12)
  subi  r11,r11,1
  stw   r11,MPU_RGD4_end(r12)
  /*
   * Load the noall access right in r11
   */
  lis   r11,TPL_HIG(noall_rgn_access)
  ori   r11,r11,TPL_LOW(noall_rgn_access)
  /*
   * Store it in the access register or region 0
   */
  stw   r11,MPU_RGD4_access(r12)
  
  /*
   * Validate the descriptor
   */
  li    r11,1
  stw   r11,MPU_RGD4_pid(r12)
  
  
  blr
  
/**
 * Disable memory protection. This function is called when
 * entering in kernel mode (typically at the start of the it
 * handler and at the start of the system call).
 *
 * no parameter and no return value
 *
 * Uses r11 and r12
 */
tpl_kernel_mp:
  /*
   * Load the kernel mode value
   */
  lis   r11,TPL_HIG(kernel_mode)
  ori   r11,r11,TPL_LOW(kernel_mode)
  /*
   * Load the address of the control register
   */
  lis   r12,TPL_HIG(MPUBase)
  ori   r12,r12,TPL_LOW(MPUBase)
  /*
   * Disable memory protection
   */
  stw   r11,MPU_CESR(r12)
  /*
   * That's all
   */
  blr

/**
 * Enable memory protection. This function is called when
 * returning to user mode (typically at the end of the it
 * handler and at the end of the system call).
 * However, if the current process is a trusted one
 * this is known by checking the trusted_counter field
 * in the process dynamic descriptor. If is is > 0
 * the the process is trusted. In this case, the memory
 * protection stay disabled.
 *
 * This is done only if WITH_OSAPPLICATION is YES
 * because a call to a trusted function may only occur when
 * a trusted OS Application that declares trusted function(s)
 * is available
 *
 * no parameter and no return value
 *
 * Uses r11 only
 */
tpl_user_mp:
  /*
   * First check the reentrancy counter
   * Do not switch to user memory protection
   * if the reentrancy counter is greater than 0
   */
  lis   r11,TPL_HIG(tpl_reentrancy_counter)
  ori   r11,r11,TPL_LOW(tpl_reentrancy_counter)
  lwz   r12,0(r11)    /*  get the value of the counter */
  cmpwi r12,0
  bnelr /* returns if not zero */
  
  /*
   * get the running process dynamic descriptor
   * pointer from the kernel stack.
   */
  lis   r11,TPL_HIG(tpl_kern)
  ori   r11,r11,TPL_LOW(tpl_kern)
  lwz   r12,12(r11)
  
#if WITH_OSAPPLICATION == YES
  /* Get the trusted counter */
  lwz   r11,4(r12)
  cmpwi r11,0
  bgt   trusted_proc
#endif

  /*
   *  Load the user mode value
   */
  lis   r11,TPL_HIG(user_mode)
  ori   r11,r11,TPL_LOW(user_mode)
  /*
   * Load the address of the control register
   */
  lis   r12,TPL_HIG(MPUBase)
  ori   r12,r12,TPL_LOW(MPUBase)
  /*
   * Enable memory protection
   */
  stw   r11,MPU_CESR(r12)
  /*
   * That's all
   */
trusted_proc:
    blr

/**
 * Set the memory protection for a process
 *
 * @param   r3    the id of the process
 */
tpl_set_process_mp:
  /*  Load the address of the control register            */
  lis   r12,TPL_HIG(MPUBase)
  ori   r12,r12,TPL_LOW(MPUBase)
  /* get the tpl_mp_table pointer                         */
  lis     r11,TPL_HIG(tpl_mp_table)
  ori     r11,r11,TPL_LOW(tpl_mp_table)
  /* tranform the id to an offset                         */
  slwi    r3,r3,2
  /* get the pointer to the mp descriptor                 */
  lwzx    r11,r11,r3
  
  /*
   * If the pointer is NULL, no memory protection is
   * configured for the process. So it is a trusted
   * process and the corresponding field in the dynamic
   * process descriptor is greater than 0
   */
  cmpwi   r11,0
  beq     finished
  
  /*
   * Configuration for the private var access of the process
   */

  /* get the start address of private data region         */
  lwz     r3,0(r11)
  /* set the start address                                */
  stw     r3,MPU_RGD1_start(r12)
  /* get the end address                                  */
  lwz     r3,4(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD1_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(var_rgn_access)
  ori     r3,r3,TPL_LOW(var_rgn_access)
  stw     r3,MPU_RGD1_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD1_pid(r12)
  
  /*
   * Configuration for the stack access of the process
   */
  /* get the start address of stack data region           */
  lwz     r3,8(r11)
  /* set the start address                                */
  stw     r3,MPU_RGD2_start(r12)
  /* get the end address                                  */
  lwz     r3,12(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD2_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(stack_rgn_access)
  ori     r3,r3,TPL_LOW(stack_rgn_access)
  stw     r3,MPU_RGD2_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD2_pid(r12)
  
#if WITH_OSAPPLICATION == YES
  /*
   * Configuration for the private var access of the OS Application
   */

  /* get the start address of OS Application data region  */
  lwz     r3,16(r11)
  /* set the start address                                */
  stw     r3,MPU_RGD3_start(r12)
  /* get the end address                                  */
  lwz     r3,20(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD3_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(var_rgn_access)
  ori     r3,r3,TPL_LOW(var_rgn_access)
  stw     r3,MPU_RGD3_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD3_pid(r12)    
#endif

finished:
  blr

#endif

/* End of file tpl_memory_protection.s */
