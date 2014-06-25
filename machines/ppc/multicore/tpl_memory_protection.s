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
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
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
#include "tpl_registers.h"


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
 * Readable region access right
 * Here, the region is r in User mode
 * and rxw in supervisor mode
 */
#define const_rgn_access  0x00000004

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
TPL_EXTERN  __SEG_START_API_CODE_RGN
TPL_EXTERN  __SEG_END_API_CODE_RGN
TPL_EXTERN  __SEG_START_API_CONST_RGN
TPL_EXTERN  __SEG_END_API_CONST_RGN



  .global tpl_kernel_mp
  .global tpl_user_mp
  .global tpl_set_process_mp
  .global tpl_init_mp

  .text
  .section .osCode CODE_ACCESS_RIGHT

/**
 * tpl_init_mp programs the MP descriptor 0-3 to allow
 * - Descriptor 0: no access for user, all access for supervisor
 * - Descriptor 1: code of shared library and Os API, RX by any OS Application. So the access is RX
 * - Descriptor 2: const Os API, RX by any OS Application. So the access is R
 * - Descriptor 3: code of an OS Application. So the access is RX
 * - Descriptor 4: const of an OS Application. So the access is R
 * - Descriptor 5: private data region of a process. So the access is RW
 * - Descriptor 6: stack of a process. So the access is RW
 * - Descriptor 7: data of an OS Application. So the access is RW
 */
tpl_init_mp:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)

  e_lis   r12,TPL_HIG(MPUBase)
  e_or2i  r12,TPL_LOW(MPUBase)

  /*
   * Descriptor 0 is used for no access for user to the whole
   * memory space and all access for supervisor
   */
  e_li    r11,0
  e_stw   r11,MPU_RGD0_start(r12)
  e_subi  r11,r11,1
  e_stw   r11,MPU_RGD0_end(r12)
  /*
   * Load the noall access right in r11
   */
  e_lis   r11,TPL_HIG(noall_rgn_access)
  e_or2i  r11,TPL_LOW(noall_rgn_access)
  /*
   * Store it in the access register or region 0
   */
  e_stw   r11,MPU_RGD0_access(r12)

  /*
   * Validate the descriptor
   */
  e_li    r11,1
  e_stw   r11,MPU_RGD0_pid(r12)



  /*
   * Descriptor 1 is used for execution access for user and supervisor
   * on API code section
   */
  e_lis   r11,TPL_HIG(__SEG_START_API_CODE_RGN)
  e_or2i  r11,TPL_LOW(__SEG_START_API_CODE_RGN)
  e_stw   r11,MPU_RGD1_start(r12)
  e_lis   r11,TPL_HIG(__SEG_END_API_CODE_RGN)
  e_or2i  r11,TPL_LOW(__SEG_END_API_CODE_RGN)
  e_stw   r11,MPU_RGD1_end(r12)
  /*
   * Load the noall access right in r11
   */
  e_lis   r11,TPL_HIG(exe_rgn_access)
  e_or2i  r11,TPL_LOW(exe_rgn_access)
  /*
   * Store it in the access register or region 0
   */
  e_stw   r11,MPU_RGD1_access(r12)

  /*
   * Validate the descriptor
   */
  e_li    r11,1
  e_stw   r11,MPU_RGD1_pid(r12)



  /*
   * Descriptor 2 is used for read access for user and supervisor
   * on API const section
   */
  e_lis   r11,TPL_HIG(__SEG_START_API_CONST_RGN)
  e_or2i  r11,TPL_LOW(__SEG_START_API_CONST_RGN)
  e_stw   r11,MPU_RGD2_start(r12)
  e_lis   r11,TPL_HIG(__SEG_END_API_CONST_RGN)
  e_or2i  r11,TPL_LOW(__SEG_END_API_CONST_RGN)
  e_stw   r11,MPU_RGD2_end(r12)
  /*
   * Load the noall access right in r11
   */
  e_lis   r11,TPL_HIG(const_rgn_access)
  e_or2i  r11,TPL_LOW(const_rgn_access)
  /*
   * Store it in the access register or region 0
   */
  e_stw   r11,MPU_RGD2_access(r12)

  /*
   * Validate the descriptor
   */
  e_li    r11,1
  e_stw   r11,MPU_RGD2_pid(r12)





  se_blr

/* ------------ NO VLE ------------------------------------------------------*/
#else
  /*
   * Load the address of MPU
   */
  lis   r12,TPL_HIG(MPUBase)
  ori   r12,r12,TPL_LOW(MPUBase)


  /*
   * Descriptor 0 is used for no access for user to the whole
   * memory space and all access for supervisor
   */
  li  r11,0
  stw   r11,MPU_RGD0_start(r12)
  subi  r11,r11,1
  stw   r11,MPU_RGD0_end(r12)
  /*
   * Load the noall access right in r11
   */
  lis   r11,TPL_HIG(noall_rgn_access)
  ori   r11,r11,TPL_LOW(noall_rgn_access)
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
   * Descriptor 1 is used for execution access for user and supervisor
   * on API code section
   */
  lis   r11,TPL_HIG(__SEG_START_API_CODE_RGN)
  ori   r11,r11,TPL_LOW(__SEG_START_API_CODE_RGN)
  stw   r11,MPU_RGD1_start(r12)
  lis   r11,TPL_HIG(__SEG_END_API_CODE_RGN)
  ori   r11,r11,TPL_LOW(__SEG_END_API_CODE_RGN)
  stw   r11,MPU_RGD1_end(r12)

  /*
   * Load the exe access right in r11
   */
  lis   r11,TPL_HIG(exe_rgn_access)
  ori   r11,r11,TPL_LOW(exe_rgn_access)
  /*
   * Store it in the access register or region 0
   */
  stw   r11,MPU_RGD1_access(r12)

  /*
   * Validate the descriptor
   */
  li    r11,1
  stw   r11,MPU_RGD1_pid(r12)



  /*
   * Descriptor 2 is used for read access for user and supervisor
   * on API const section
   */
  lis   r11,TPL_HIG(__SEG_START_API_CONST_RGN)
  ori   r11,r11,TPL_LOW(__SEG_START_API_CONST_RGN)
  stw   r11,MPU_RGD2_start(r12)
  lis   r11,TPL_HIG(__SEG_END_API_CONST_RGN)
  ori   r11,r11,TPL_LOW(__SEG_END_API_CONST_RGN)
  stw   r11,MPU_RGD2_end(r12)

  /*
   * Load the exe access right in r11
   */
  lis   r11,TPL_HIG(const_rgn_access)
  ori   r11,r11,TPL_LOW(const_rgn_access)
  /*
   * Store it in the access register or region 0
   */
  stw   r11,MPU_RGD2_access(r12)

  /*
   * Validate the descriptor
   */
  li    r11,1
  stw   r11,MPU_RGD2_pid(r12)




  blr

#endif
  FUNCTION(tpl_init_mp)
  .type tpl_init_mp,@function
  .size tpl_init_mp,$-tpl_init_mp

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
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  /*
   * Load the kernel mode value
   */
  e_lis   r11,TPL_HIG(kernel_mode)
  e_or2i  r11,TPL_LOW(kernel_mode)
  /*
   * Load the address of the control register
   */
  e_lis   r12,TPL_HIG(MPUBase)
  e_or2i  r12,TPL_LOW(MPUBase)
  /*
   * Disable memory protection
   */
  e_stw   r11,MPU_CESR(r12)
  /*
   * That's all
   */
  se_blr

/* ------------ NO VLE ------------------------------------------------------*/
#else
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

#endif
  FUNCTION(tpl_kernel_mp)
  .type tpl_kernel_mp,@function
  .size tpl_kernel_mp,$-tpl_kernel_mp
  
  
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
 * no parameter and no return value
 *
 * Uses r11 only
 */
tpl_user_mp:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  /*
   * First check the reentrancy counter
   * Do not switch to user memory protection
   * if the reentrancy counter is greater than 0
   */
  e_lis     r11,TPL_HIG(tpl_reentrancy_counter)
  e_or2i    r11,TPL_LOW(tpl_reentrancy_counter)
  e_lwz     r12,0(r11)    /*  get the value of the counter */
  e_cmp16i  r12,0
  se_bne    trusted_proc  /* returns if not zero */

  /*
   * get the running process dynamic descriptor
   * pointer from the kernel stack.
   */
  e_lis     r11,TPL_HIG(tpl_kern)
  e_or2i    r11,TPL_LOW(tpl_kern)
  e_lwz     r12,12(r11)
  /* Get the trusted counter */
  e_lwz     r11,4(r12)
  e_cmp16i  r11,0
  se_bgt    trusted_proc
  /*
   *  Load the user mode value
   */
  e_lis     r11,TPL_HIG(user_mode)
  e_or2i    r11,TPL_LOW(user_mode)
  /*
   * Load the address of the control register
   */
  e_lis     r12,TPL_HIG(MPUBase)
  e_or2i    r12,TPL_LOW(MPUBase)
  /*
   * Enable memory protection
   */
  e_stw     r11,MPU_CESR(r12)
  /*
   * That's all
   */
trusted_proc:
  se_blr

/* ------------ NO VLE ------------------------------------------------------*/
#else
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

#endif
  FUNCTION(tpl_user_mp)
  .type tpl_user_mp,@function
  .size tpl_user_mp,$-tpl_user_mp
  
  
/**
 * Set the memory protection for a process
 *
 * @param   r3    the id of the process
 */
tpl_set_process_mp:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  /*  Load the address of the control register            */
  e_lis     r12,TPL_HIG(MPUBase)
  e_or2i    r12,TPL_LOW(MPUBase)
  /* get the tpl_mp_table pointer                         */
  e_lis     r11,TPL_HIG(tpl_mp_table)
  e_or2i    r11,TPL_LOW(tpl_mp_table)
  /* tranform the id to an offset                         */
  e_slwi    r3,r3,2
  /* get the pointer to the mp descriptor                 */
  lwzx      r11,r11,r3

  /*
   * If the pointer is NULL, no memory protection is
   * configured for the process. So it is a trusted
   * process and the corresponding field in the dynamic
   * process descriptor is greater than 0
   */
  e_cmp16i  r11,0
  e_beq     finished

  /*
   * Configuration for the private var access of the process
   */

  /* get the start address of private data region         */
  e_lwz     r3,0(r11)
  /* set the start address                                */
  e_stw     r3,MPU_RGD5_start(r12)
  /* get the end address                                  */
  e_lwz     r3,4(r11)
  /* set the end address                                  */
  e_stw     r3,MPU_RGD5_end(r12)
  /* set the access rights                                */
  e_lis     r3,TPL_HIG(var_rgn_access)
  e_or2i    r3,TPL_LOW(var_rgn_access)
  e_stw     r3,MPU_RGD5_access(r12)
  /* validate the descriptor                              */
  e_li      r3,1
  e_stw     r3,MPU_RGD5_pid(r12)

  /*
   * Configuration for the stack access of the process
   */
  /* get the start address of stack data region           */
  e_lwz     r3,8(r11)
  /* set the start address                                */
  e_stw     r3,MPU_RGD6_start(r12)
  /* get the end address                                  */
  e_lwz     r3,12(r11)
  /* set the end address                                  */
  e_stw     r3,MPU_RGD6_end(r12)
  /* set the access rights                                */
  e_lis     r3,TPL_HIG(stack_rgn_access)
  e_or2i    r3,TPL_LOW(stack_rgn_access)
  e_stw     r3,MPU_RGD6_access(r12)
  /* validate the descriptor                              */
  e_li      r3,1
  e_stw     r3,MPU_RGD6_pid(r12)

  /*
   * Configuration for the private var no init access of the process
   */

  /* get the start address of private data no init region         */
  e_lwz     r3,16(r11)
  /* set the start address                                */
  e_stw     r3,MPU_RGD8_start(r12)
  /* get the end address                                  */
  e_lwz     r3,20(r11)
  /* set the end address                                  */
  e_stw     r3,MPU_RGD8_end(r12)
  /* set the access rights                                */
  e_lis     r3,TPL_HIG(var_rgn_access)
  e_or2i    r3,TPL_LOW(var_rgn_access)
  e_stw     r3,MPU_RGD8_access(r12)
  /* validate the descriptor                              */
  e_li      r3,1
  e_stw     r3,MPU_RGD8_pid(r12)

#if WITH_OSAPPLICATION == YES
  /*
   * Configuration for the private var access of the OS Application
   */

  /* get the start address of OS Application data region  */
  e_lwz     r3,24(r11)
  /* set the start address                                */
  e_stw     r3,MPU_RGD7_start(r12)
  /* get the end address                                  */
  e_lwz     r3,28(r11)
  /* set the end address                                  */
  e_stw     r3,MPU_RGD7_end(r12)
  /* set the access rights                                */
  e_lis     r3,TPL_HIG(var_rgn_access)
  e_or2i    r3,TPL_LOW(var_rgn_access)
  e_stw     r3,MPU_RGD7_access(r12)
  /* validate the descriptor                              */
  e_li      r3,1
  e_stw     r3,MPU_RGD7_pid(r12)

  /*
   * Configuration for the private var no init access of the OS Application
   */

  /* get the start address of OS Application data no init region  */
  e_lwz     r3,32(r11)
  /* set the start address                                */
  e_stw     r3,MPU_RGD9_start(r12)
  /* get the end address                                  */
  e_lwz     r3,36(r11)
  /* set the end address                                  */
  e_stw     r3,MPU_RGD9_end(r12)
  /* set the access rights                                */
  e_lis     r3,TPL_HIG(var_rgn_access)
  e_or2i    r3,TPL_LOW(var_rgn_access)
  e_stw     r3,MPU_RGD9_access(r12)
  /* validate the descriptor                              */
  e_li      r3,1
  e_stw     r3,MPU_RGD9_pid(r12)

  /*
   * Configuration for the private code access of the OS Application
   */

  /* get the start address of OS Application code region  */
  e_lwz     r3,40(r11)
  /* set the start address                                */
  e_stw     r3,MPU_RGD3_start(r12)
  /* get the end address                                  */
  e_lwz     r3,44(r11)
  /* set the end address                                  */
  e_stw     r3,MPU_RGD3_end(r12)
  /* set the access rights                                */
  e_lis     r3,TPL_HIG(exe_rgn_access)
  e_or2i    r3,TPL_LOW(exe_rgn_access)
  e_stw     r3,MPU_RGD3_access(r12)
  /* validate the descriptor                              */
  e_li      r3,1
  e_stw     r3,MPU_RGD3_pid(r12)

  /*
   * Configuration for the private const access of the OS Application
   */

  /* get the start address of OS Application const region  */
  e_lwz     r3,48(r11)
  /* set the start address                                */
  e_stw     r3,MPU_RGD4_start(r12)
  /* get the end address                                  */
  e_lwz     r3,52(r11)
  /* set the end address                                  */
  e_stw     r3,MPU_RGD4_end(r12)
  /* set the access rights                                */
  e_lis     r3,TPL_HIG(const_rgn_access)
  e_or2i    r3,TPL_LOW(const_rgn_access)
  e_stw     r3,MPU_RGD4_access(r12)
  /* validate the descriptor                              */
  e_li      r3,1
  e_stw     r3,MPU_RGD4_pid(r12)

  /*
   * Configuration for the private const access of the OS Application
   */

  /* get the start address of OS Application config data region  */
  e_lwz     r3,56(r11)
  /* set the start address                                */
  e_stw     r3,MPU_RGD10_start(r12)
  /* get the end address                                  */
  e_lwz     r3,60(r11)
  /* set the end address                                  */
  e_stw     r3,MPU_RGD10_end(r12)
  /* set the access rights                                */
  e_lis     r3,TPL_HIG(const_rgn_access)
  e_or2i    r3,TPL_LOW(const_rgn_access)
  e_stw     r3,MPU_RGD10_access(r12)
  /* validate the descriptor                              */
  e_li      r3,1
  e_stw     r3,MPU_RGD10_pid(r12)

#endif

finished:
  se_blr

/* ------------ NO VLE ------------------------------------------------------*/
#else
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
  stw     r3,MPU_RGD5_start(r12)
  /* get the end address                                  */
  lwz     r3,4(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD5_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(var_rgn_access)
  ori     r3,r3,TPL_LOW(var_rgn_access)
  stw     r3,MPU_RGD5_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD5_pid(r12)

  /*
   * Configuration for the stack access of the process
   */
  /* get the start address of stack data region           */
  lwz     r3,8(r11)
  /* set the start address                                */
  stw     r3,MPU_RGD6_start(r12)
  /* get the end address                                  */
  lwz     r3,12(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD6_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(stack_rgn_access)
  ori     r3,r3,TPL_LOW(stack_rgn_access)
  stw     r3,MPU_RGD6_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD6_pid(r12)

  /*
   * Configuration for the stack access of the process
   */
  /* get the start address of stack data region           */
  lwz     r3,16(r11)
  /* set the start address                                */
  stw     r3,MPU_RGD8_start(r12)
  /* get the end address                                  */
  lwz     r3,20(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD8_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(stack_rgn_access)
  ori     r3,r3,TPL_LOW(stack_rgn_access)
  stw     r3,MPU_RGD8_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD8_pid(r12)

#if WITH_OSAPPLICATION == YES
  /*
   * Configuration for the private var access of the OS Application
   */

  /* get the start address of OS Application data region  */
  lwz     r3,24(r11)
  /* set the start address                                */
  stw     r3,MPU_RGD7_start(r12)
  /* get the end address                                  */
  lwz     r3,28(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD7_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(var_rgn_access)
  ori     r3,r3,TPL_LOW(var_rgn_access)
  stw     r3,MPU_RGD7_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD7_pid(r12)

  /*
   * Configuration for the private var no init access of the OS Application
   */

  /* get the start address of OS Application data no init region  */
  lwz     r3,32(r11)
  /* set the start address                                */
  stw     r3,MPU_RGD9_start(r12)
  /* get the end address                                  */
  lwz     r3,36(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD9_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(var_rgn_access)
  ori     r3,r3,TPL_LOW(var_rgn_access)
  stw     r3,MPU_RGD9_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD9_pid(r12)

  /*
   * Configuration for the private code access of the OS Application
   */

  /* get the start address of OS Application data region  */
  lwz     r3,40(r11)
  /* set the start address                                */
  stw     r3,MPU_RGD3_start(r12)
  /* get the end address                                  */
  lwz     r3,44(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD3_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(exe_rgn_access)
  ori     r3,r3,TPL_LOW(exe_rgn_access)
  stw     r3,MPU_RGD3_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD3_pid(r12)

  /*
   * Configuration for the private const access of the OS Application
   */

  /* get the start address of OS Application data region  */
  lwz     r3,48(r11)
  /* set the start address                                */
  stw     r3,MPU_RGD4_start(r12)
  /* get the end address                                  */
  lwz     r3,52(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD4_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(const_rgn_access)
  ori     r3,r3,TPL_LOW(const_rgn_access)
  stw     r3,MPU_RGD4_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD4_pid(r12)

  /*
   * Configuration for the private config data access of the OS Application
   */

  /* get the start address of OS Application config data region  */
  lwz     r3,56(r11)
  /* set the start address                                */
  stw     r3,MPU_RGD10_start(r12)
  /* get the end address                                  */
  lwz     r3,60(r11)
  /* set the end address                                  */
  stw     r3,MPU_RGD10_end(r12)
  /* set the access rights                                */
  lis     r3,TPL_HIG(const_rgn_access)
  ori     r3,r3,TPL_LOW(const_rgn_access)
  stw     r3,MPU_RGD10_access(r12)
  /* validate the descriptor                              */
  li      r3,1
  stw     r3,MPU_RGD10_pid(r12)
#endif

finished:
  blr

#endif
  FUNCTION(tpl_set_process_mp)
  .type tpl_set_process_mp,@function
  .size tpl_set_process_mp,$-tpl_set_process_mp
  

#endif

/* End of file tpl_memory_protection.s */
