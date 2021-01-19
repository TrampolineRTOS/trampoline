/**
 * @file core_cm_func_mk20dx256.h
 *
 * @section descr File description
 *
 * Trampoline macros and functions for low level processor access.
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

#include "tpl_os_std_types.h"

#ifndef CORE_CM_FUNC_MK20DX256_H
#define CORE_CM_FUNC_MK20DX256_H

#if   defined ( __CC_ARM )
  #define __ASM            __asm     /*!< asm keyword for ARM Compiler          */
  #define __INLINE         __inline  /*!< inline keyword for ARM Compiler       */
  #define __STATIC_INLINE  static __inline

#elif defined ( __GNUC__ )
  #define __ASM            __asm     /*!< asm keyword for GNU Compiler          */
  #define __INLINE         inline    /*!< inline keyword for GNU Compiler       */
  #define __STATIC_INLINE  static inline

#elif defined ( __ICCARM__ )
  #define __ASM            __asm     /*!< asm keyword for IAR Compiler            */
  #define __INLINE         inline    /*!< inline keyword for IAR Compiler.        */
                                     /* Only available in High optimization mode! */
  #define __STATIC_INLINE  static inline

#elif defined ( __TMS470__ )
  #define __ASM            __asm     /*!< asm keyword for TI CCS Compiler       */
  #define __STATIC_INLINE  static inline

#elif defined ( __TASKING__ )
  #define __ASM            __asm     /*!< asm keyword for TASKING Compiler      */
  #define __INLINE         inline    /*!< inline keyword for TASKING Compiler   */
  #define __STATIC_INLINE  static inline

#elif defined ( __CSMC__ )
  #define __packed
  #define __ASM            _asm      /*!< asm keyword for COSMIC Compiler      */
  #define __INLINE         inline    /* use -pc99 on compile line !< inline    */
                                     /* keyword for COSMIC Compiler            */
  #define __STATIC_INLINE  static inline

#endif


__attribute__( ( always_inline ) ) __STATIC_INLINE void __set_MSP(uint32 topOfMainStack)
{
  __ASM volatile ("MSR msp, %0\n" : : "r" (topOfMainStack) : "sp");
}

__attribute__( ( always_inline ) ) __STATIC_INLINE void __set_CONTROL(uint32 control)
{
  __ASM volatile ("MSR control, %0" : : "r" (control) : "memory");
}

__attribute__( ( always_inline ) ) __STATIC_INLINE void __ISB(void)
{
  __ASM volatile ("isb");
}

#endif
