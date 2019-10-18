/**
 * @file tpl_kern_stack.h
 *
 * @section desc File description
 *
 * Trampoline kernel stack size for MSP430x small memory model.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes and
 * Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 */

#ifndef __TPL_KERN_STACK_H__
#define __TPL_KERN_STACK_H__

#include "tpl_app_define.h"

#if WITH_ANY_HOOK == YES
#define TPL_KERNEL_STACK_SIZE   400
#else
#define TPL_KERNEL_STACK_SIZE   200
#endif

#endif
