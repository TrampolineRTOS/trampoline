/**
 * @file tpl_config_def.h
 *
 * @section descr File description
 *
 * Here are defined macros used to control the configuration of Trampoline.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
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

#ifndef TPL_CONFIG_DEF_H
#define TPL_CONFIG_DEF_H

/**
 * @def NO
 *
 * Used by configuration flags.
 */
#define NO    0

/**
 * @def YES
 *
 * Used by configuration flags.
 */
#define YES   1

/**
 * @def ARCH_POSIX
 */
#define ARCH_POSIX      0

/**
 * @def ARCH_LIBPCL
 */
#define ARCH_LIBPCL     1

/**
 * @def ARCH_PPC
 */
#define ARCH_PPC        2

/**
 * @def ARCH_C166
 */
#define ARCH_C166       3

/**
 * @def ARCH_ARM
 */
#define ARCH_ARM        4

/**
 * @def ARCH_V850E
 */
#define ARCH_V850E      5

/**
 * @def ARCH_HCS12
 */
#define ARCH_HCS12      6

/**
 * @def ARCH_H8300H
 */
#define ARCH_H8300H     7

/**
 * @def ARCH_AVR
 */
#define ARCH_AVR        8

/**
 * @def MPC5516
 */
#define MPC5516 ((ARCH_PPC << 16) | 1)

/**
 * @def MPC5604
 */
#define MPC5604 ((ARCH_PPC << 16) | 2)

/**
 * @def MPC5668
 */
#define MPC5668 ((ARCH_PPC << 16) | 3)

/**
 * @def MPC5643
 */
#define MPC5643 ((ARCH_PPC << 16) | 4)

#endif
/* End of file tpl_config_def.h */
