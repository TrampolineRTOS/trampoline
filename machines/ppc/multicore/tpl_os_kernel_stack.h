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

#ifndef TPL_OS_KERNEL_STACK_H
#define TPL_OS_KERNEL_STACK_H

/*
 * The kernel stack is like that:
 *
 *          |                                 |
 *          +---------------------------------+
 *  SP->    |          linkage area           |  The linkage area is a zone
 *          +---------------------------------+  reserved for the callee when
 *       +4 |          linkage area           |  calling a C function
 *          +---------------------------------+
 *       +8 |        SP of the caller         |
 *          +---------------------------------+
 *      +12 |       SRR0 of the caller        |
 *          +---------------------------------+
 *      +16 |       SRR1 of the caller        |
 *          +---------------------------------+
 *      +20 | return code of the service (r3) |
 *          +---------------------------------+
 *      +24 | pointer to the tpl_kern struct  |
 *          +---------------------------------+
 *      +28 | LR when calling tpl_enter_kernel|
 *          +---------------------------------+
 */

#define KERNEL_STACK_SIZE 2000
#define KS_FOOTPRINT      32

#define KS_SP             8
#define KS_SRR0           12
#define KS_SRR1           16
#define KS_RETURN_CODE    20
#define KS_KERN_PTR       24
#define KS_LR             28

/* TPL_OS_KERNEL_STACK_H */
#endif
