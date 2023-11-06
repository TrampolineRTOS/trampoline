/**
 * @file tpl_system_call.S
 *
 * @section descr File description
 *
 * Kernel stack frame.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c)
 * CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
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
 * The kernel stack frame takes 12 bytes when allocated from
 * the tpl_sc_handler and is as follow:
 *
 *          |                                 |
 *          +---------------------------------+
 *       +0 |                lr               | KS_LR <- MSP after allocation
 *          +---------------------------------+
 *       +4 |           r4 save area          | KS_R4
 *          +---------------------------------+
 *       +8 |           r5 save area          | KS_R5
 *          +---------------------------------+
 *          |                                 |       <- MSP before allocation
 *
 * When allocated from an interrupt handler, we do not need space to store
 * R4 and R5 because we have R0-R3 and R12 as working registers. We only have
 * to save LR to be able to call a function.
 *
 * it is as follow:
 *
 *          |                                 |
 *          +---------------------------------+
 *       +0 |                lr               | KS_LR <- MSP after allocation
 *          +---------------------------------+
 *          |                                 |       <- MSP before allocation
 */

#define KS_FOOTPRINT  12

#define KS_LR         0
#define KS_R4         4
#define KS_R5         8

/* TPL_OS_KERNEL_STACK_H */
#endif
