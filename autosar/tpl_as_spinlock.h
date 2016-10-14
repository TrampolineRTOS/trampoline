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

/*
 * Trampoline extra
 * GetSpinlock_IE : GetSpinlock with Interrupts Enabled
 */
FUNC(tpl_status, OS_CODE) GetSpinlock_IE(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id);

/* TPL_AS_SPINLOCK_H */
#endif

/* End of file tpl_as_spinlock.h */
