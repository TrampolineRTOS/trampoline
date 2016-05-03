/**
 * @file tpl_as_counter.h
 *
 * @section desc File description
 *
 * Trampoline autosar extension software counters API
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
#ifndef TPL_AS_SPINLOCK_H
#define TPL_AS_SPINLOCK_H

#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_types.h"
#include "tpl_as_spinlock_kernel.h"


/**
 * @typedef CoreIDType
 *
 * A core identifier.
 *
 */
typedef tpl_spinlock_id  SpinlockIdType;

/**
 * @def DeclareSpinlock
 *
 * Defines a spinlock
 *
 * @param spinlock_id spinlock C-identifier
 *
 * see paragraph 7.0.29 page 109 of
 * Specification of Operating System AUTOSAR Release 4.2.2
 */
#define DeclareSpinlock(spinlock_id)  \
  extern CONST(SpinlockIdType, AUTOMATIC) spinlock_id


/**
 * @typedef CoreIDType
 *
 * A core identifier.
 *
 */
typedef tpl_try_to_get_spinlock_type  TryToGetSpinlockType;


#define OS_START_SEC_CODE
#include "tpl_memmap.h"


/**
 * Gets a Spinlock
 *
 * @param SpinLockId                    identifier of the spinlock to be taken
 *
 * @retval  E_OK                        no error
 * @retval  E_OS_ID                     SpinLockId is not valid (EXTENDED status only)
 * @retval  E_OS_INTERFERENCE_DEADLOCK  tries to occupy spinlock while the lock is already taken on the same core
 * @retval  E_OS_NESTING_DEADLOCK       tries to occupy a spinlock while a different spinlock has already been taken and could result in a deadlock
 * @retval  E_OS_ACCESS                 spinlock cannot be accessed by this task
 *  
 */
extern FUNC(StatusType, OS_CODE) GetSpinlock(
    CONST(SpinlockIdType, AUTOMATIC) SpinLockId
);


/**
 * Gets a Spinlock
 *
 * @param SpinLockId                    identifier of the spinlock to be taken
 *
 * @retval  E_OK                        no error
 * @retval  E_OS_ID                     SpinLockId is not valid (EXTENDED status only)
 * @retval  E_OS_STATE                  the spinlock is not occupied by this task
 * @retval  E_OS_NOFUNC                 attempt to release a spinlock while another spinlock must be released before
 * @retval  E_OS_ACCESS                 spinlock cannot be accessed by this task
 *  
 */
extern FUNC(StatusType, OS_CODE) ReleaseSpinlock(
    CONST(SpinlockIdType, AUTOMATIC) SpinLockId
);


/**
 * Test availability of a Spinlock
 *
 * @param SpinLockId                    identifier of the spinlock to be taken
 *
 * @retval  E_OK                        no error
 * @retval  E_OS_ID                     SpinLockId is not valid (EXTENDED status only)
 * @retval  E_OS_INTERFERENCE_DEADLOCK  tries to occupy spinlock while the lock is already taken on the same core
 * @retval  E_OS_NESTING_DEADLOCK       tries to occupy a spinlock while a different spinlock has already been taken and could result in a deadlock
 * @retval  E_OS_ACCESS                 spinlock cannot be accessed by this task
 *  
 */
extern FUNC(StatusType, OS_CODE) TryToGetSpinlock(
    CONST(SpinlockIdType, AUTOMATIC) SpinLockId,
    CONSTP2VAR(TryToGetSpinlockType, AUTOMATIC, OS_VAR) Success
);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_AS_SPINLOCK_H */
#endif

/* End of file tpl_as_spinlock.h */
