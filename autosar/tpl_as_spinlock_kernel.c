/**
 * @file tpl_as_counter_kernel.c
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

#include "tpl_as_spinlock_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_os_errorhook.h"
#include "tpl_machine_interface.h"
#include "tpl_as_error.h"
#include "tpl_os_definitions.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_spinlock_id, OS_VAR) tpl_last_taken_spinlock=0;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 *
 */
FUNC(tpl_status, OS_CODE) tpl_get_spinlock_service(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC)  result = E_OK;

  P2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock = NULL_PTR;



  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetSpinlock)
  STORE_SPINLOCK_ID(spinlock_id)

  /*  check a spinlock_id error                   */
  CHECK_SPINLOCK_ID_ERROR(spinlock_id, result)
	
  /*  check spinlock nesting order error          */
  CHECK_SPINLOCK_NESTING_ORDER_ERROR(spinlock_id, result) 
	

  IF_NO_EXTENDED_ERROR(result)

    /*  get the lock descriptor                   */
    lock = &(tpl_spinlock_table[spinlock_id]);

    /* get the lock, this call is blocking        */
    tpl_get_lock(lock);
   
    /* store id of last taken spinlock, so we can check later the nesting order */
    tpl_last_taken_spinlock=spinlock_id;
    
  IF_NO_EXTENDED_ERROR_END()


  PROCESS_ERROR(result)

  return result;
}




/*
 *
 */
FUNC(tpl_status, OS_CODE) tpl_release_spinlock_service(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC)  result = E_OK;

  P2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock = NULL_PTR;



  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_ReleaseSpinlock)
  STORE_SPINLOCK_ID(spinlock_id)

  /*  check a counter_id error                    */
  CHECK_SPINLOCK_ID_ERROR(spinlock_id, result)
	
  /*  check spinlock nesting order error          */
  CHECK_SPINLOCK_UNNESTING_ORDER_ERROR(spinlock_id, result) 
	

  IF_NO_EXTENDED_ERROR(result)

    /*  get the lock descriptor                   */
    lock = &(tpl_spinlock_table[spinlock_id]);

    /* get the lock, this call is blocking        */
    tpl_release_lock(lock);
   
    /* store id of last released spinlock, so we can check later the nesting order */
    tpl_last_taken_spinlock=spinlock_id;
    
  IF_NO_EXTENDED_ERROR_END()


  PROCESS_ERROR(result)

  return result;
}



/*
 *
 */
FUNC(tpl_status, OS_CODE) tpl_try_to_get_spinlock_service(
    VAR(tpl_spinlock_id, AUTOMATIC) spinlock_id,
    P2VAR(tpl_try_to_get_spinlock_type, AUTOMATIC, OS_VAR) success)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC)  result = E_OK;

  P2VAR(tpl_lock, AUTOMATIC, OS_VAR) lock = NULL_PTR;



  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_TryToGetSpinlock)
  STORE_SPINLOCK_ID(spinlock_id)

  /*  check a counter_id error                    */
  CHECK_SPINLOCK_ID_ERROR(spinlock_id, result)
	
  /*  check spinlock nesting order error          */
  CHECK_SPINLOCK_NESTING_ORDER_ERROR(spinlock_id, result)   

  IF_NO_EXTENDED_ERROR(result)

    /*  get the lock descriptor                   */
    lock = &(tpl_spinlock_table[spinlock_id]);

    /* get the lock, this call is blocking        */
    tpl_try_to_get_lock(lock, success);
   
    /* store id of last taken spinlock, so we can check later the nesting order */
    tpl_last_taken_spinlock=spinlock_id;
    
  IF_NO_EXTENDED_ERROR_END()


  PROCESS_ERROR(result)

  return result;
}


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_counter_kernel.c */
