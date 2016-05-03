/**
 * @file tpl_as_spinlock.c
 *
 * @internal
 *
 * @section desc File description
 *
 * Trampoline autosar extension software counters functions
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
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
 
#ifndef WITH_SYSTEM_CALL

#include "tpl_as_spinlock.h"
#include "tpl_as_spinlock_kernel.h"
#include "tpl_os_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 *
 */
//FUNC(StatusType, OS_CODE) GetSpinlock(
//    CONST(SpinlockIdType, AUTOMATIC) SpinlockId)
//{
//    return tpl_get_spinlock_service(SpinlockId);
//}
//
//
///**
// *
// */
//FUNC(StatusType, OS_CODE) ReleaseSpinlock(
//    CONST(SpinlockIdType, AUTOMATIC) SpinlockId)
//{
//  return tpl_release_spinlock_service(SpinlockId);
//}
//
//
///**
// *
// */
//FUNC(StatusType, OS_CODE) TryToGetSpinlock(
//    CONST(SpinlockIdType, AUTOMATIC) SpinlockId,
//    CONSTP2VAR(TryToGetSpinlockType, AUTOMATIC, OS_VAR) Success)
//{
//  return tpl_try_to_get_spinlock_service(SpinlockId, Success);
//}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#else
#error "This file should not be part of your project since WITH_SYSTEM_CALL is defined"
#endif /* WITH_SYSTEM_CALL */

/* End of file tpl_as_spinlock.c */
