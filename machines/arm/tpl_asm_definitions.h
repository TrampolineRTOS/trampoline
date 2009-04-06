/**
 * @file tpl_asm_definitions.h
 *
 * @section descr File description
 *
 * Common definitions for ARM assembler source files
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
#ifndef TPL_ASM_DEFINITIONS_H
#define TPL_ASM_DEFINITIONS_H

#include "tpl_os_definitions.h"
#include "tpl_os_service_ids.h"

#define CPSR_USR_MODE 0b10000
#define CPSR_FIQ_MODE 0b10001
#define CPSR_IRQ_MODE 0b10010
#define CPSR_SVC_MODE 0b10011
#define CPSR_ABT_MODE 0b10111
#define CPSR_UND_MODE 0b11011
#define CPSR_SYS_MODE 0b11111

#define CPSR_IRQ_LOCKED 0b10000000
#define CPSR_FIQ_LOCKED 0b01000000

#endif /* TPL_ASM_DEFINITIONS_H */
