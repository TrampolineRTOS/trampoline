/**
 * @file tpl_stacks_size.h
 *
 * @section descr File description
 *
 * Trampoline standard types. Here for MISRA rule 13 compliance
 * and for platform specific type definition
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

#ifndef TPL_OS_STACKS_SIZE_H
#define TPL_OS_STACKS_SIZE_H

#define IRQ_STACK_SIZE 256*4
#define FIQ_STACK_SIZE 256*4
#define SVC_STACK_SIZE 512*4
#define ABT_STACK_SIZE 256*4
#define UND_STACK_SIZE 256*4
#define USR_STACK_SIZE 256*4

#endif /* TPL_OS_STACKS_SIZE_H */

/* End of file tpl_stacks_size.h */

