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
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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

#include "tpl_assembler.h"
#include "tpl_app_define.h"


  TPL_EXTERN tpl_protection_hook_wrapper

  .text

  .section .exCriticalInput CODE_ACCESS_RIGHT
  .global tpl_critical_input
tpl_critical_input:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b tpl_critical_input
/* ------------ NO VLE ------------------------------------------------------*/
#else
  e_b tpl_critical_input
#endif

  .type tpl_critical_input,@function
  .size tpl_critical_input,$-tpl_critical_input

  .section .exMachineCheck CODE_ACCESS_RIGHT
  .global tpl_machine_check
tpl_machine_check:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b tpl_protection_hook_wrapper
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_protection_hook_wrapper
#endif

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
  e_b tpl_protection_hook_wrapper
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_protection_hook_wrapper
#endif

  .type tpl_data_storage,@function
  .size tpl_data_storage,$-tpl_data_storage

  .section .exInstructionStorage CODE_ACCESS_RIGHT
  .global tpl_instruction_storage
tpl_instruction_storage:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b tpl_protection_hook_wrapper
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_protection_hook_wrapper
#endif

  .type tpl_instruction_storage,@function
  .size tpl_instruction_storage,$-tpl_instruction_storage

  .section .exAlignment CODE_ACCESS_RIGHT
  .global tpl_alignment
tpl_alignment:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b tpl_alignment
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_alignment
#endif

  .type tpl_alignment,@function
  .size tpl_alignment,$-tpl_alignment

  .section .exProgram CODE_ACCESS_RIGHT
  .global tpl_program
tpl_program:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b tpl_program
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_program
#endif

  .type tpl_program,@function
  .size tpl_program,$-tpl_program

  .section .exFloatingPointUnavailable CODE_ACCESS_RIGHT
  .global tpl_floating_point_unavalaible
tpl_floating_point_unavalaible:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b tpl_floating_point_unavalaible
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_floating_point_unavalaible
#endif

  .type tpl_floating_point_unavalaible,@function
  .size tpl_floating_point_unavalaible,$-tpl_floating_point_unavalaible


  .section .exFixedIntervalTimer CODE_ACCESS_RIGHT
  .global tpl_fi_timer
tpl_fi_timer:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b tpl_fi_timer
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_fi_timer
#endif

  .type tpl_fi_timer,@function
  .size tpl_fi_timer,$-tpl_fi_timer


  .section .exWatchdogTimer CODE_ACCESS_RIGHT
  .global tpl_wdg_timer
tpl_wdg_timer:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b tpl_wdg_timer
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_wdg_timer
#endif

  .type tpl_wdg_timer,@function
  .size tpl_wdg_timer,$-tpl_wdg_timer


    .section .exDataTLBError CODE_ACCESS_RIGHT
    .global tpl_data_tlb
  tpl_data_tlb:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b tpl_data_tlb
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_data_tlb
#endif

  .type tpl_data_tlb,@function
  .size tpl_data_tlb,$-tpl_data_tlb


    .section .exInstructionTLBError CODE_ACCESS_RIGHT
    .global tpl_inst_tlb
  tpl_inst_tlb:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b tpl_inst_tlb
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b tpl_inst_tlb
#endif

  .type tpl_inst_tlb,@function
  .size tpl_inst_tlb,$-tpl_inst_tlb




