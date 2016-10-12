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
#include "tpl_os_resource.h"

#if NUMBER_OF_CORES > 1

/**
 * @typedef tpl_lock_method
 *
 * [ECUC_Os_01038]
 * Lock method which is used when a spinlock is taken.
 */
#define LOCK_NOTHING                0
#define LOCK_WITH_RES_SCHEDULER     1
#define LOCK_CAT2_INTERRUPTS        2
#define LOCK_ALL_INTERRUPTS         3
typedef uint8 tpl_lock_method;

/**
 * @struct TPL_SPINLOCK
 *
 * This structure describes all attributes of a spinlock
 */
struct TPL_SPINLOCK {
    VAR(tpl_lock, TYPEDEF) state; /**< Lock state. Can be either UNLOCKED_LOCK
                                       or LOCKED_LOCK                         */
    CONST(tpl_lock_method, TYPEDEF) method;
#if WITH_OS_EXTENDED == YES
    CONSTP2CONST(tpl_spinlock_successor_bitfield, TYPEDEF, OS_CONST)
        successors;                 /**< Array of bitfields indexed by a
                                         spinlock_id describing which spinlock
                                         can be taken after this one. */
#endif
};

/**
 * @typedef tpl_spinlock
 *
 * This type is an alias for the structure #TPL_SPINLOCK.
 *
 * @see #TPL_SPINLOCK
 */
typedef struct TPL_SPINLOCK tpl_spinlock;

#if SPINLOCK_COUNT > 0
extern CONSTP2VAR(tpl_spinlock, OS_CONST, OS_VAR) tpl_spinlock_table[SPINLOCK_COUNT];
extern VAR(tpl_spinlock_id, OS_VAR) tpl_taken_spinlocks[NUMBER_OF_CORES][MAX_POSSESSED_SPINLOCKS];
extern VAR(tpl_spinlock_id, OS_VAR) tpl_taken_spinlock_counter[NUMBER_OF_CORES];
/*
 * SPINLOCK_IS_SUCCESSOR returns 1 if a_spinlock_id is a successor of
 * a_last_spinlock_id
 */
#define SPINLOCK_IS_SUCCESSOR(last_spinlock_id, spinlock_id)                  \
 (((tpl_spinlock_table[last_spinlock_id]->successors[spinlock_id >> SPINLOCK_SUCCESSOR_BITFIELD_SHIFT]) >> (spinlock_id & SPINLOCK_SUCCESSOR_BITFIELD_MASK)) & 0x1)

/*
 * HAS_SPINLOCK returns 1 if the core core_id holds at least one spinlock
 */
#define HAS_SPINLOCK(core_id)            \
    (tpl_taken_spinlock_counter[core_id] > 0)

/*
 * GET_LAST_TAKEN_SPINLOCK returns the last taken spinlock of the core core_id
 */
#define GET_LAST_TAKEN_SPINLOCK(core_id) \
    (tpl_taken_spinlocks[core_id][tpl_taken_spinlock_counter[core_id]-1])

/*
 * SET_LAST_TAKEN_SPINLOCK add a spinlock to the core_id's spinlock list
 */
#define SET_LAST_TAKEN_SPINLOCK(core_id, spinlock_id)                         \
    tpl_taken_spinlocks[core_id][tpl_taken_spinlock_counter[core_id]] = spinlock_id; \
    tpl_taken_spinlock_counter[core_id]++;                                    \

/*
 * REMOVE_LAST_TAKEN_SPINLOCK remove the last core_id's spinlock from its list
 */
#define REMOVE_LAST_TAKEN_SPINLOCK(core_id)  \
    if(HAS_SPINLOCK(core_id)) {              \
      tpl_taken_spinlock_counter[core_id]--; \
    }

#define RELEASE_ALL_SPINLOCKS(core_id)                                        \
    {                                                                         \
      VAR(sint32, AUTOMATIC) tmp;                                             \
      for(tmp = 0; tmp < tpl_taken_spinlock_counter[core_id]; tmp++)          \
      {                                                                       \
        P2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock;                              \
        lock = &(tpl_spinlock_table[tmp]->state);                             \
        tpl_release_lock(lock);                                               \
      }                                                                       \
      tpl_taken_spinlock_counter[core_id] = 0;                                \
    }

#define GET_TAKEN_SPINLOCK(core_id, position)   \
    tpl_taken_spinlocks[core_id][position]

#define GET_TAKEN_SPINLOCK_COUNTER(core_id) \
    tpl_taken_spinlock_counter[core_id]

/**
 *  SPINLOCK_SUSPEND_INTERRUPTS calls the specific command to suspend
 *  interrupts following the lock method of the given spinlock.
 */
/* FIXME : It would be preferable to have an architecture dependant function
 *         that takes a lock power level as an argument. This would simplify
 *         this call here and interrupt-relative service calls.
 */
#define SPINLOCK_SUSPEND_INTERRUPTS(core_id, spinlock_id)                     \
    switch(tpl_spinlock_table[spinlock_id]->method) {                         \
        case LOCK_ALL_INTERRUPTS :                                            \
            tpl_suspend_all_interrupts_service();                             \
            break;                                                            \
        case LOCK_CAT2_INTERRUPTS :                                           \
            tpl_suspend_os_interrupts_service();                              \
            break;                                                            \
        default :                                                             \
            break;                                                            \
    }

/**
 *  SPINLOCK_GET_RESSCHEDULER gets the RES_SCHEDULER resource if the spinlock
 *  has the associated lock method.
 */
#define SPINLOCK_GET_RESSCHEDULER(core_id, spinlock_id)                       \
    if(tpl_spinlock_table[spinlock_id]->method == LOCK_WITH_RES_SCHEDULER) {  \
            tpl_get_resource_service(RES_SCHEDULER);                          \
            tpl_spinlock_resscheduler_taken[core_id] = TRUE;                  \
    }

/**
 *  SPINLOCK_RESUME_INTERRUPTS calls the specific command to resume interrupts
 *  following the lock method of the last taken spinlock.
 */
/* FIXME : We have to set the interrupt tolerance level to the one of the last
 *         spinlock in taken_spinlocks list. However, we MUST NOT enable THEN
 *         disable interrupts. We actually lack a way to just drop off a level
 *         of interrupt tolerance, so we're enabling all interrupts only when
 *         all the spinlocks are released.
 */
#define SPINLOCK_RESUME_INTERRUPTS(core_id)                                   \
    if (!HAS_SPINLOCK(core_id)) {                                             \
        tpl_reset_interrupt_lock_status();                                    \
        tpl_enable_interrupts();                                              \
        if (tpl_spinlock_resscheduler_taken[core_id]) {                       \
          tpl_spinlock_resscheduler_taken[core_id] = FALSE;                   \
          tpl_release_resource_service(RES_SCHEDULER);                        \
        }                                                                     \
    }


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

#endif /* NUMBER_OF_CORES > 1 */
#endif /* SPINLOCK_COUNT > 0  */

/* TPL_AS_SPINLOCK_KERNEL_H */
#endif

/* End of file tpl_as_spinlock_kernel.h */
