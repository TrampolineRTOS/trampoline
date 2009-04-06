/**
 * @file tpl_asm_macros.h
 *
 * @section descr File description
 *
 * Macros to be used in preprocessed assembler source files.
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
 * $Rev $
 * $Author$
 * $URL$
 */
#ifndef TPL_ASM_MACROS_H
#define TPL_ASM_MACROS_H

/**
 * This instruction is used to load a tpl_proc_id typed variable
 */
#define LDR_PROC_ID ldr

/*
 * This instruction is used to store a tpl_proc_id typed variable
 */
#define STR_PROC_ID str

#endif /* TPL_ASM_MACROS_H */

