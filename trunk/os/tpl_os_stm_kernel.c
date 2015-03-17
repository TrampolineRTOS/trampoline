/**
 * @file tpl_os_stm_kernel.c
 *
 * @section desc File description
 *
 * Trampoline Event Management implementation file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date: 2015-03-02 15:05:50 +0200 (lun., 02 mars 2015) $
 * $Rev: 0 $
 * $Author: audrey $
 * $URL: http://trampoline.rts-software.org/svn/trunk/os/tpl_os_stm_kernel.c $
 */

#include "tpl_os_definitions.h"
/*#include "tpl_os_errorhook.h"
#include "tpl_os_kernel.h"
#include "tpl_machine_interface.h"
#include "tpl_trace.h"

#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#include "tpl_as_protec_hook.h"
#endif

#if WITH_MEMORY_PROTECTION == YES
#include "tpl_os_mem_prot.h"
#endif*/
/*
#include "tpl_os_event_kernel.h"*/

#include "tpl_os_stm_kernel.h"

/*
 * tpl_screen_display_service.
 */

FUNC(StatusType, OS_CODE) tpl_screen_display_service(
  P2CONST(char, AUTOMATIC, OS_VAR) msg)
{
  VAR(StatusType, AUTOMATIC) result = E_OK;
	
  LOCK_KERNEL()
	
  /* Display the message    */
  
  printf("\n---------------------\nVoici le message : %s\n---------------------\n", msg);

  PROCESS_ERROR(result)
  
  UNLOCK_KERNEL()
  
  return result;
}

/*
 * tpl_stm_begin_read_tx_service
 *
 * Initializes a read-set transaction
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) tpl_stm_begin_read_tx_service()
{
 VAR(StatusType, AUTOMATIC) result = E_OK;

#if NUMBER_OF_CORES > 1	
 GET_CURRENT_CORE_ID(core_id)

 LOCK_KERNEL()

 trans_table[core_id].status=0;
 trans_table[core_id].access_vector=0;

 UNLOCK_KERNEL()
#else
 LOCK_KERNEL()

 trans_table[0].status=0;
 trans_table[0].access_vector=0;

 UNLOCK_KERNEL()
#endif
  
 return result;
};

/*
 * tpl_stm_begin_write_tx_service
 *
 * Initializes a write-set transaction on the core given as an argument
 *
 * tx:  Transaction descriptor
 *
 * coreId:  Core on which the write-set transaction begins
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) tpl_stm_begin_write_tx_service(){
};

/*
 * tpl_stm_end_read_tx_service
 *
 * Ends a read-set transaction 
 *
 * tx:  Transaction descriptor
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) tpl_stm_end_read_tx_service(){
};

/*
 * tpl_stm_end_write_tx_service
 *
 * Ends a write-set transaction
 *
 * tx:  Transaction descriptor
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) tpl_stm_end_write_tx_service(){
};

/*
 * tpl_stm_open_read_object_service
 *
 * A read-set transaction opens for reading a given object on a given core
 *
 * tx:  Transaction descriptor
 *
 * coreId:  Core on which the read-set transaction opens the object
 *
 * dataId:  Data identifier
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) tpl_stm_open_read_object_service(P2VAR(void, AUTOMATIC, OS_APPL_DATA) data){
};

/*
 * tpl_stm_open_write_object_service
 *
 * A write-set transaction opens for writing a given object on a given
 * core
 *
 * tx:  Transaction descriptor
 *
 * coreId:  Core on which the write-set transaction opens the object
 *
 * dataId:  Data identifier
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) tpl_stm_open_write_object_service(P2VAR(void, AUTOMATIC, OS_APPL_DATA) data){
};

/*
 * tpl_stm_commit_read_tx_service
 *
 * A read-set transaction tries to commit on a given core
 *
 * tx:  Transaction descriptor
 *
 * instance:  Transaction instance number
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) tpl_stm_commit_read_tx_service(){
};

/*
 * tpl_stm_commit_write_tx_service
 *
 * A write-set transaction tries to commit on a given core
 *
 * tx:  Transaction descriptor
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) tpl_stm_commit_write_tx_service(){
};

