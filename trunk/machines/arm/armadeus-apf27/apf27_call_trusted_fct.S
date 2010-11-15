/**
 * @file apf27_call_trusted_fct.S
 *
 * @section descr File description
 *
 * Management of trusted functions
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
 *
 * @section infos File informations
 *
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */

#include "../tpl_asm_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

.global tpl_call_trusted_function_service
tpl_call_trusted_function_service:
	/* FIXME: to be done */
	mov pc, lr

.global tpl_exit_trusted_function_service
tpl_exit_trusted_function_service:
	/* FIXME: to be done */
	mov pc, lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

