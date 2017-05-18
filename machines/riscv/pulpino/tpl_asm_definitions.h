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

/*
 * tpl_kern data structure offsets (for use into assembler sources)
 */
#define TPL_KERN_OFFSET_S_RUNNING 0
#define TPL_KERN_OFFSET_S_ELECTED 4
#define TPL_KERN_OFFSET_RUNNING 8
#define TPL_KERN_OFFSET_ELECTED 12
#define TPL_KERN_OFFSET_RUNNING_ID 16
#define TPL_KERN_OFFSET_ELECTED_ID 20
#define TPL_KERN_OFFSET_NEED_SWITCH 24
#define TPL_KERN_OFFSET_NEED_SCHEDULE 25

#endif
/* TPL_ASM_DEFINITIONS_H */

/* Enf of file tpl_asm_definitions.h */
