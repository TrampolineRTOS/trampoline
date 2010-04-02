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

  TPL_EXTERN tpl_protection_hook_wrapper

  .text
  
  .section .exCriticalInput CODE_ACCESS_RIGHT
  .global tpl_critical_input
tpl_critical_input:
  b tpl_critical_input
  
  .type tpl_critical_input,@function
  .size tpl_critical_input,$-tpl_critical_input

  .section .exMachineCheck CODE_ACCESS_RIGHT
  .global tpl_machine_check
tpl_machine_check:
  b tpl_machine_check
  
  .type tpl_machine_check,@function
  .size tpl_machine_check,$-tpl_machine_check


/*
 * tpl_data_storage and tpl_instruction_storage exception handler
 * are called when a memory protection exception occurs
 */
  .section .exDataStorage CODE_ACCESS_RIGHT
  .global tpl_data_storage
tpl_data_storage:
  b tpl_protection_hook_wrapper
  
  .type tpl_data_storage,@function
  .size tpl_data_storage,$-tpl_data_storage

  .section .exInstructionStorage CODE_ACCESS_RIGHT
  .global tpl_instruction_storage
tpl_instruction_storage:
  b tpl_protection_hook_wrapper
  
  .type tpl_instruction_storage,@function
  .size tpl_instruction_storage,$-tpl_instruction_storage

  .section .exAlignment CODE_ACCESS_RIGHT
  .global tpl_alignment
tpl_alignment:
  b tpl_alignment
  
  .type tpl_alignment,@function
  .size tpl_alignment,$-tpl_alignment

  .section .exProgram CODE_ACCESS_RIGHT
  .global tpl_program
tpl_program:
  b tpl_program
  
  .type tpl_program,@function
  .size tpl_program,$-tpl_program

  .section .exFloatingPointUnavailable CODE_ACCESS_RIGHT
  .global tpl_floating_point_unavalaible
tpl_floating_point_unavalaible:
  b tpl_floating_point_unavalaible
  
  .type tpl_floating_point_unavalaible,@function
  .size tpl_floating_point_unavalaible,$-tpl_floating_point_unavalaible


