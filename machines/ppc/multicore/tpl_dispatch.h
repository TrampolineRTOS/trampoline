/*
 *  @file tpl_dispatch.h
 *
 * @section desc File description
 *
 * Trampoline dispatch level
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_DISPATCH_H
#define TPL_DISPATCH_H

/**
 * @def TC_ASM
 *
 * TC_ASM expand to the appropriate keyword to qualify an assembly language
 * function. If the compiler uses this kind of construct, define it here
 * If it does not, define TC_ASM with no value and put the ad hoc keywords
 * in TPL_SYSCALL
 *
 * @see #ASM
 * @see #TPL_SYSCALL
 */
#define TC_ASM  asm

/**
 * @def TPL_SYSCALL
 *
 * Macro used by API to invoke OS services via
 * a system call (software interrupt).
 * The id of the os service is loaded in r0 (a volatile register)
 * and a system call is made.
 *
 * @see #tpl_sc_handler
 */
#define TPL_SYSCALL(os_service_id)  \
        li r0,(os_service_id);      \
        sc;

/* TPL_DISPATCH_H */
#endif

/* End of file tpl_dispatch.h */
