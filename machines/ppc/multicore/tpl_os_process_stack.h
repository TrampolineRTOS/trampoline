/*
 * @file tpl_os_process_stack.h
 *
 * @section desc File description
 *
 * Trampoline process stack structure for PowerPC port
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

#ifndef TPL_OS_PROCESS_STACK_H
#define TPL_OS_PROCESS_STACK_H

/*
 * The process stack top is like that:
 *
 *                  |              |
 *                  +--------------+
 * TRUSTED_SP -> +0 |   dummy r11  |
 *                  +--------------+
 *               +4 |   dummy r12  |
 *                  +--------------+
 *               +8 |   dummy lr   |
 *                  +--------------+
 *              +12 |   dummy cr   |
 *                  +--------------+
 *              +16 | linkage area |
 *                  +--------------+
 *              +20 | linkage area |
 *                  +--------------+
 *              +24 |    (SRR0)    |
 *                  +--------------+
 *              +28 |    (SRR1)    |
 *                  +--------------+
 * SP->          +0 |      r11     |
 *                  +--------------+
 *               +4 |      r12     |
 *                  +--------------+
 *               +8 |      lr      |
 *                  +--------------+
 *              +12 |      cr      |
 *                  +--------------+
 *              +16 |      r0      |
 *                  +--------------+
 *
 * r0 is saved by the API function or by the interrupt handler
 * cr, lr, r12 and r11 are saved when entering the kernel in tpl_sc_handler
 * or by the interrupt handler
 * SRR0 and SRR1 are optionally saved by the tpl_call_trusted_function
 * service that change the stack pointer.
 * the linkage area is reserved for the call of a trusted function
 */

#define PS_FOOTPRINT              20
#define PS_TRUSTED_FOOTPRINT  36

#define PS_SRR0                   28
#define PS_SRR1                   32
#define PS_R11                    0
#define PS_R12                    4
#define PS_LR                     8
#define PS_CR                     12
#define PS_R0                     16

/* TPL_OS_PROCESS_STACK_H */
#endif
