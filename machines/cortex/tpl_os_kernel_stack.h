/*
 * @file tpl_os_kernel_stack.h
 *
 * @section desc File description
 *
 * Trampoline kernel stack structure for Cortex port
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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

#ifndef TPL_OS_KERNEL_STACK_H
#define TPL_OS_KERNEL_STACK_H

/*
 * The kernel stack frame takes 20 bytes and is as follow:
 *
 *          |                                 |
 *          +---------------------------------+
 *  SP-> +0 |         sp of the caller        | KS_PROCESS_SP
 *          +---------------------------------+
 *       +4 |                lr               | KS_LR
 *          +---------------------------------+
 *       +8 | pointer to the tpl_kern struct  | KS_KERN_PTR
 *          +---------------------------------+
 *      +12 |           r4 save area          | KS_R4
 *          +---------------------------------+
 *      +16 |           r5 save area          | KS_R5
 *          +---------------------------------+
 */

#define KS_FOOTPRINT		20

#define KS_PROCESS_SP		0
#define KS_LR				4
#define KS_KERN_PTR			8
#define KS_R4				12
#define KS_R5				16

/* TPL_OS_KERNEL_STACK_H */
#endif
