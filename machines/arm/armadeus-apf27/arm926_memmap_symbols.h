/**
 * @file arm926_memmap_symbols.h
 *
 * @section descr File description
 *
 * Linker defined symbols to be used by MMU driver
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
#ifndef ARM926_MEMMAP_SYMBOLS_H
#define ARM926_MEMMAP_SYMBOLS_H

#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"

extern u8 kernel_zeroed_vars_begin;
extern u8 kernel_zeroed_vars_end;

extern u8 common_zeroed_vars_begin;
extern u8 common_zeroed_vars_end;

#if WITH_MEMORY_PROTECTION == YES 
/*
 * MMU is configured with fine page tables
 * for every page in this area.
 * 
 * This area shall include all data (code,
 * consts, vars, stacks, ...) of trampoline,
 * tasks, ISRs, OS applications, libraries,
 * GCC builtin functions, ...
 */
extern u8 MMU_start_custom_zone;
extern u8 MMU_end_custom_zone;

extern u8 __SEG_START_OS_PRIVATE;
extern u8 __SEG_END_OS_PRIVATE;

extern u8 __SEG_START_APP_CODE_CONST_RGN;
extern u8 __SEG_END_APP_CODE_CONST_RGN;

extern u8 __SEG_START_COMMON_VARS;
extern u8 __SEG_END_COMMON_VARS;

#endif /* WITH_MEMORY_PROTECTION == YES */

#endif /* ARM926_MEMMAP_SYMBOLS_H */
