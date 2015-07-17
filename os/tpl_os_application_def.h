/**
 * @file tpl_os_application_def.h
 *
 * @section File description
 *
 * This file wraps user application configuration header. This wrapped file is
 * typically generated from an OIL source.
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
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_APPLICATION_DEF_H
#define TPL_OS_APPLICATION_DEF_H

#include "tpl_app_define.h"

/**
 * @def ASM
 *
 * When using system calls, API functions are written in assembly code
 * ASM expands in the appropriate keyword for the target platform or
 * to an empty string
 */
#if WITH_SYSTEM_CALL == YES
#define ASM TC_ASM
#else
#define ASM
#endif

#if WITH_AUTOSAR == YES

/**
 * @def WITH_OSAPPLICATION
 *
 * @internal
 *
 * This compilation is set if WITH_AUTOSAR is defined and AUTOSAR_SC is
 * equal to 3 or 4. But if WITH_NO_OSAPPLICATION is set, it is unset.
 */
#if APP_COUNT > 0
#if (AUTOSAR_SC == 3) || (AUTOSAR_SC == 4)
#if WITH_OSAPPLICATION == NO
#undef WITH_OSAPPLICATION
#define WITH_OSAPPLICATION YES
#endif
#endif
#endif

#endif /* defined WITH_AUTOSAR */

#endif /* TPL_OS_APPLICATION_DEF_H */

/* End of file tpl_os_application_def.h */
