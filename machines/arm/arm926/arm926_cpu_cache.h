/**
 * @file arm926_cpu_cache.h
 *
 * @section descr File description
 *
 * Driver for memory management unit of ARM926EJ-S CPU
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
#ifndef ARM926_CPU_CACHE_H
#define ARM926_CPU_CACHE_H

#include "tpl_os_definitions.h"
#include "apf27_config.h"

/**
 * Enables the data cache and the instruction cache
 */
extern FUNC (void, OS_CODE) arm926_cache_on ();

/**
 * Disables the data cache and the instruction cache
 */
extern FUNC (void, OS_CODE) arm926_cache_off ();

/**
 * Invalidate both data and instruction caches
 */
extern FUNC (void, OS_CODE) arm926_cache_invalidate ();

#endif /* ARM926_CPU_CACHE_H */
