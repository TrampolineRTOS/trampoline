/**
 * @file apf27_vectors.c
 *
 * @section descr File description
 *
 * ARMADEUS platform exception vectors
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
#define OS_START_SEC_CONST_UNSPECIFIED
570 #include "tpl_memmap.h"
*
 * @section infos File informations
 *
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */
#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_definitions.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

extern void primary_undefined_instruction_handler (void);
extern void tpl_primary_syscall_handler (void);
extern void primary_prefetch_abort_handler (void);
extern void primary_data_abort_handler (void);

/**
 * this exception vector table is copied by bootstrap
 * at startup to address 0xFFFFFF00
 */
CONST(func_ptr, OS_CONST) exception_table[4] = {
  (func_ptr)primary_undefined_instruction_handler,
  (func_ptr)tpl_primary_syscall_handler,
  (func_ptr)primary_prefetch_abort_handler,
  (func_ptr)primary_data_abort_handler
  };


#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

