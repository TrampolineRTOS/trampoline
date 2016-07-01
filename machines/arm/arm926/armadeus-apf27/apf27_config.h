/**
 * @file apf27_config.h
 *
 * @section descr File description
 *
 * APF27 port configuration
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
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef APF27_CONFIG_H
#define APF27_CONFIG_H

#include "tpl_config_def.h"

#define IRQ_STACK_SIZE (1024*4)
#define FIQ_STACK_SIZE (1024*4)
#define SVC_STACK_SIZE (4096*4)
#define ABT_STACK_SIZE (4096*4)
#define UND_STACK_SIZE (4096*4)
#define USR_STACK_SIZE (1024*4)

/**
 * Choose wether trampoline uses data and instruction cache or not.
 */
#define WITH_CPU_CACHE NO

#endif /* APF27_CONFIG_H */

