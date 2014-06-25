/*
 * @file tpl_exceptions.S
 *
 * @section desc File description
 *
 * Trampoline default exception functions for MPC551x
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

#include "tpl_assembler.h"
#include "tpl_app_define.h"

#define TPL_EXCEPTION_CRITICAL_INPUT        0
#define TPL_EXCEPTION_MACHINE_CHECK         1
#define TPL_EXCEPTION_DATA_STORAGE          2
#define TPL_EXCEPTION_INSTRUCTION_STORAGE   3
#define TPL_EXCEPTION_ALIGNMENT             5
#define TPL_EXCEPTION_PROGRAM               6
#define TPL_EXCEPTION_FLOATING_POINT        7
#define TPL_EXCEPTION_FIXED_INTERVAL_TIMER  11
#define TPL_EXCEPTION_WATCHDOG_TIMER        12
#define TPL_EXCEPTION_DATA_TLB_ERROR        13
#define TPL_EXCEPTION_INSTRUCTION_TLB_ERROR 14

#if (WITH_EXCEPTION_HOOK == YES)
  .text
  .section .osCode CODE_ACCESS_RIGHT
tpl_exception_mngt:  
  /* prolog, save all volatile registers, r3 has already been saved */
  e_subi    r1,r1,44     
  e_stw     r0,0(r1)     
  se_mflr   r0           
  e_stw     r0,4(r1)          
  e_stw     r4,8(r1)    
  e_stw     r5,12(r1)    
  e_stw     r6,16(r1)    
  e_stw     r7,20(r1)    
  e_stw     r8,24(r1)    
  e_stw     r9,28(r1)    
  e_stw     r10,32(r1)   
  e_stw     r11,36(r1)   
  e_stw     r12,40(r1) 

  /* call ExceptionHook, parameter has already been set in r3 */
  e_bl      ExceptionHook   
  
  /* epilog */
  e_lwz     r12,40(r1)      
  e_lwz     r11,36(r1)      
  e_lwz     r10,32(r1)      
  e_lwz     r9 ,28(r1)       
  e_lwz     r8 ,24(r1)       
  e_lwz     r7 ,20(r1)       
  e_lwz     r6 ,16(r1)       
  e_lwz     r5 ,12(r1)       
  e_lwz     r4 , 8(r1)              
  e_lwz     r0 , 4(r1)        
  se_mtlr   r0              
  e_lwz     r0 ,0(r1)        
  e_addi    r1,r1,44
  se_lwz    r3 ,0(r1)  
  se_addi   r1,4
  se_rfi
  FUNCTION(tpl_exception_mngt)
  .type tpl_exception_mngt,@function
  .size tpl_exception_mngt,$-tpl_exception_mngt  
  
  .text
  .section .osCode CODE_ACCESS_RIGHT
tpl_exception_mngt_with_wrapper:  
  /* prolog, save all volatile registers, r3 has already been saved */
  e_subi    r1,r1,44     
  e_stw     r0,0(r1)     
  se_mflr   r0           
  e_stw     r0,4(r1)          
  e_stw     r4,8(r1)    
  e_stw     r5,12(r1)    
  e_stw     r6,16(r1)    
  e_stw     r7,20(r1)    
  e_stw     r8,24(r1)    
  e_stw     r9,28(r1)    
  e_stw     r10,32(r1)   
  e_stw     r11,36(r1)   
  e_stw     r12,40(r1) 

  /* call ExceptionHook, parameter has already been set in r3 */
  e_bl      tpl_protection_hook_wrapper
  e_bl      ExceptionHook   
  
  /* epilog */
  e_lwz     r12,40(r1)      
  e_lwz     r11,36(r1)      
  e_lwz     r10,32(r1)      
  e_lwz     r9 ,28(r1)       
  e_lwz     r8 ,24(r1)       
  e_lwz     r7 ,20(r1)       
  e_lwz     r6 ,16(r1)       
  e_lwz     r5 ,12(r1)       
  e_lwz     r4 , 8(r1)              
  e_lwz     r0 , 4(r1)        
  se_mtlr   r0              
  e_lwz     r0 ,0(r1)        
  e_addi    r1,r1,44
  se_lwz    r3 ,0(r1)  
  se_addi   r1,4
  se_rfi
  FUNCTION(tpl_exception_mngt_with_wrapper)
  .type tpl_exception_mngt_with_wrapper,@function
  .size tpl_exception_mngt_with_wrapper,$-tpl_exception_mngt_with_wrapper  
  
  .text
  .section .osCode CODE_ACCESS_RIGHT
tpl_exception_mngt_with_wrapper_mc:  
  /* prolog, save all volatile registers, r3 has already been saved */
  e_subi    r1,r1,44     
  e_stw     r0,0(r1)     
  se_mflr   r0           
  e_stw     r0,4(r1)          
  e_stw     r4,8(r1)    
  e_stw     r5,12(r1)    
  e_stw     r6,16(r1)    
  e_stw     r7,20(r1)    
  e_stw     r8,24(r1)    
  e_stw     r9,28(r1)    
  e_stw     r10,32(r1)   
  e_stw     r11,36(r1)   
  e_stw     r12,40(r1) 

  /* call ExceptionHook, parameter has already been set in r3 */
  e_bl      tpl_protection_hook_wrapper
  e_bl      ExceptionHook   
  
  /* epilog */
  e_lwz     r12,40(r1)      
  e_lwz     r11,36(r1)      
  e_lwz     r10,32(r1)      
  e_lwz     r9 ,28(r1)       
  e_lwz     r8 ,24(r1)       
  e_lwz     r7 ,20(r1)       
  e_lwz     r6 ,16(r1)       
  e_lwz     r5 ,12(r1)       
  e_lwz     r4 , 8(r1)              
  e_lwz     r0 , 4(r1)        
  se_mtlr   r0              
  e_lwz     r0 ,0(r1)        
  e_addi    r1,r1,44
  se_lwz    r3 ,0(r1)  
  se_addi   r1,4
  se_rfmci
  FUNCTION(tpl_exception_mngt_with_wrapper_mc)
  .type tpl_exception_mngt_with_wrapper_mc,@function
  .size tpl_exception_mngt_with_wrapper_mc,$-tpl_exception_mngt_with_wrapper_mc   
#endif
  
  
  
#if (WITH_EXCEPTION_HOOK == YES)
TPL_CALL_EXCEPTION_MNGT: .macro exception
  se_subi   r1,4 
  se_stw    r3,0(r1)      
  se_li     r3,exception  
  e_b       tpl_exception_mngt
  .endm

TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER: .macro exception
  se_subi   r1,4 
  se_stw    r3,0(r1)      
  se_li     r3,exception  
  e_b       tpl_exception_mngt_with_wrapper
  .endm 

TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER_MC: .macro exception
  se_subi   r1,4 
  se_stw    r3,0(r1)      
  se_li     r3,exception  
  e_b       tpl_exception_mngt_with_wrapper_mc
  .endm   
#else
TPL_CALL_EXCEPTION_MNGT: .macro exception
  .endm
  
TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER: .macro exception
  e_bl      tpl_protection_hook_wrapper
  .endm 
  
TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER_MC: .macro exception
  e_bl      tpl_protection_hook_wrapper
  .endm 
#endif 
  
  
#if (WITH_EXCEPTION_HOOK == YES)
  TPL_EXTERN ExceptionHook
#endif
  TPL_EXTERN tpl_protection_hook_wrapper

  .text

  .section .exCriticalInput CODE_ACCESS_RIGHT
  .global tpl_critical_input
tpl_critical_input:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_CRITICAL_INPUT
  e_b tpl_critical_input
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b   tpl_critical_input
#endif
  FUNCTION(tpl_critical_input)
  .type tpl_critical_input,@function
  .size tpl_critical_input,$-tpl_critical_input





  .section .exMachineCheck CODE_ACCESS_RIGHT
  .global tpl_machine_check
tpl_machine_check:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER_MC TPL_EXCEPTION_MACHINE_CHECK
  e_b tpl_machine_check
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_protection_hook_wrapper
#endif
  FUNCTION(tpl_machine_check)
  .type tpl_machine_check,@function
  .size tpl_machine_check,$-tpl_machine_check





/*
 * tpl_data_storage and tpl_instruction_storage exception handler
 * are called when a memory protection exception occurs
 */
  .section .exDataStorage CODE_ACCESS_RIGHT
  .global tpl_data_storage
tpl_data_storage:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER TPL_EXCEPTION_DATA_STORAGE
  e_b tpl_data_storage
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_protection_hook_wrapper
#endif
  FUNCTION(tpl_data_storage)
  .type tpl_data_storage,@function
  .size tpl_data_storage,$-tpl_data_storage





  .section .exInstructionStorage CODE_ACCESS_RIGHT
  .global tpl_instruction_storage
tpl_instruction_storage:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT_WITH_WRAPPER TPL_EXCEPTION_INSTRUCTION_STORAGE
  e_b tpl_instruction_storage
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_protection_hook_wrapper
#endif
  FUNCTION(tpl_instruction_storage)
  .type tpl_instruction_storage,@function
  .size tpl_instruction_storage,$-tpl_instruction_storage





  .section .exAlignment CODE_ACCESS_RIGHT
  .global tpl_alignment
tpl_alignment:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_ALIGNMENT
  e_b tpl_alignment
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_alignment
#endif
  FUNCTION(tpl_alignment)
  .type tpl_alignment,@function
  .size tpl_alignment,$-tpl_alignment





  .section .exProgram CODE_ACCESS_RIGHT
  .global tpl_program
tpl_program:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_PROGRAM
  /*e_b tpl_program*/
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_program
#endif
  FUNCTION(tpl_program)
  .type tpl_program,@function
  .size tpl_program,$-tpl_program





  .section .exFloatingPointUnavailable CODE_ACCESS_RIGHT
  .global tpl_floating_point_unavalaible
tpl_floating_point_unavalaible:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_FLOATING_POINT
  e_b tpl_floating_point_unavalaible
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_floating_point_unavalaible
#endif
  FUNCTION(tpl_floating_point_unavalaible)
  .type tpl_floating_point_unavalaible,@function
  .size tpl_floating_point_unavalaible,$-tpl_floating_point_unavalaible





  .section .exFixedIntervalTimer CODE_ACCESS_RIGHT
  .global tpl_fi_timer
tpl_fi_timer:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_FIXED_INTERVAL_TIMER
  e_b tpl_fi_timer
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_fi_timer
#endif
  FUNCTION(tpl_fi_timer)
  .type tpl_fi_timer,@function
  .size tpl_fi_timer,$-tpl_fi_timer





  .section .exWatchdogTimer CODE_ACCESS_RIGHT
  .global tpl_wdg_timer
tpl_wdg_timer:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_WATCHDOG_TIMER 
  e_b tpl_wdg_timer
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_wdg_timer
#endif
  FUNCTION(tpl_wdg_timer)
  .type tpl_wdg_timer,@function
  .size tpl_wdg_timer,$-tpl_wdg_timer




  .section .exDataTLBError CODE_ACCESS_RIGHT
  .global tpl_data_tlb
tpl_data_tlb:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_DATA_TLB_ERROR
  e_b tpl_data_tlb
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_data_tlb
#endif
  FUNCTION(tpl_data_tlb)
  .type tpl_data_tlb,@function
  .size tpl_data_tlb,$-tpl_data_tlb




  .section .exInstructionTLBError CODE_ACCESS_RIGHT
  .global tpl_inst_tlb
tpl_inst_tlb:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  TPL_CALL_EXCEPTION_MNGT TPL_EXCEPTION_INSTRUCTION_TLB_ERROR
  e_b tpl_inst_tlb
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_inst_tlb
#endif
  FUNCTION(tpl_inst_tlb)
  .type tpl_inst_tlb,@function
  .size tpl_inst_tlb,$-tpl_inst_tlb




