/**
 * @file tpl_as_counter_kernel.h
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
#ifndef TPL_AS_SPINLOCK_KERNEL_H
#define TPL_AS_SPINLOCK_KERNEL_H

#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_timeobj_kernel.h"


typedef enum
{
  TRYTOGETSPINLOCK_NOSUCCESS,
  TRYTOGETSPINLOCK_SUCCESS
} tpl_try_to_get_spinlock_type;

typedef VAR(uint8, TYPEDEF) tpl_spinlock_id;


#if SPINLOCK_COUNT > 0
/*  MISRA RULE 27 VIOLATION: This object is not declared as external
 in a header file because it is only used in this file but declared
 in the configuration file
 */
extern VAR(tpl_lock, OS_VAR) tpl_spinlock_table[SPINLOCK_COUNT];
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"


extern FUNC(void, OS_CODE) tpl_try_to_get_lock(
  CONSTP2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock,
  P2VAR(tpl_try_to_get_spinlock_type, AUTOMATIC, OS_VAR) success);

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
extern FUNC(tpl_status, OS_CODE) tpl_get_spinlock_service(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id
);


/**
 * Release a Spinlock
 *
 * @param SpinLockId                    identifier of the spinlock to release
 *
 * @retval  E_OK                        no error
 * @retval  E_OS_ID                     SpinLockId is not valid (EXTENDED status only)
 * @retval  E_OS_STATE                  the spinlock is not occupied by this task
 * @retval  E_OS_NOFUNC                 attempt to release a spinlock while another spinlock must be released before
 * @retval  E_OS_ACCESS                 spinlock cannot be accessed by this task
 *  
 */
extern FUNC(tpl_status, OS_CODE) tpl_release_spinlock_service(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id
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
extern FUNC(tpl_status, OS_CODE) tpl_try_to_get_spinlock_service(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id,
    P2VAR(tpl_try_to_get_spinlock_type, AUTOMATIC, OS_VAR) success
);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_AS_SPINLOCK_KERNEL_H */
#endif

/* End of file tpl_as_spinlock_kernel.h */
