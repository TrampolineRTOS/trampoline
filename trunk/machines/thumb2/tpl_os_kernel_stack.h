/*
 * @file tpl_os_kernel_stack.h
 *
 * @section desc File description
 *
 * Trampoline kernel stack structure for PowerPC port
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
 * The kernel stack is like that:
 *       
 *          |                                 |
 *          +---------------------------------+
 *  SP->    |         sp of the caller        |
 *          +---------------------------------+
 *       +4 |                lr               |
 *          +---------------------------------+
 *       +8 | return code of the service (r0) |
 *          +---------------------------------+
 *      +12 | pointer to the tpl_kern struct  |
 *          +---------------------------------+
 */

#define KERNEL_STACK_SIZE	300
#define KS_FOOTPRINT		24

#define KS_PROCESS_SP		0
#define KS_LR				4
#define KS_RETURN_CODE		8
#define KS_KERN_PTR			12
#define KS_R4				16
#define KS_R5				20

/* TPL_OS_KERNEL_STACK_H */
#endif 
