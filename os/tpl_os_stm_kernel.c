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

#include <stdio.h>

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

 // a compléter
 
 UNLOCK_KERNEL()
#else
 LOCK_KERNEL()

 // a compléter

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
 * update
 *
 * A write-set transaction is ready to update an object
 *
 * tx:  Transaction descriptor
 *
 * object_id:  Object identifier
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) update(P2VAR(tpl_stm_tx_descriptor, AUTOMATIC, OS_APPL_DATA) tx, CONST(ObjectType, AUTOMATIC) object_id){
 // a compléter
};

/*
 * read_obj
 *
 * A write-set transaction is ready to update an object
 *
 * tx:  Transaction descriptor
 *
 * object_id:  Object identifier
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) read_obj(P2VAR(tpl_stm_tx_descriptor, AUTOMATIC, OS_APPL_DATA) tx1, P2VAR(tpl_stm_tx_descriptor, AUTOMATIC, OS_APPL_DATA) tx2, CONST(ObjectType, AUTOMATIC) object_id, CONST(uint32, AUTOMATIC) instance){
 // a compléter
};


/*
 * tpl_stm_open_read_object_service
 *
 * A read-set transaction opens for reading a given object
 *
 * object_id:  Object identifier
 *
 * data_type:  Data type
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) tpl_stm_open_read_object_service(CONST(ObjectType, AUTOMATIC) object_id, P2VAR(void, AUTOMATIC, OS_APPL_DATA) data){
uint32 s=0x4FFFA5F2;

//printf("\n---------------------\nVoici l'object ID : %d qui pointe sur la donnée %d\n---------------------\n", object_id, data);
//printf("\n---------------------\nVoici l'object ID : %d qui pointe sur la donnée de type %s\n---------------------\n", object_table[object_id].object_id, object_table[object_id].type);

//printf("\n---------------------s=%04X\n", s);
//printf("---------------------status=%hu\n", STATUS(s));
//printf("---------------------instance=%04X\n", INSTANCE_S(s));

uint32 instance;
VAR(ObjectType, AUTOMATIC) loc_object_id;


#if NUMBER_OF_CORES > 1	
 GET_CURRENT_CORE_ID(core_id)

 LOCK_KERNEL()

 // a compléter
 
  UNLOCK_KERNEL()
#else
  LOCK_KERNEL()
 
  //printf("-----------s=%04X\n", s);
  //printf("-----------POW2_NUMBER_OF_CORES=%u\n", POW2_NUMBER_OF_CORES);
  //printf("-----------FAIL_VECTOR(s)=%04X\n", FAIL_VECTOR(s));

  if ((STATUS(trans_table[0].status) != TXS_IN_RETRY) && (UPDATE_FLAG(object_table[object_id].concurrency_vector)==1))
  {
	printf("Statut de la transaction différent de TXS_RETRY et update flag de l'objet à 1...\n");
	update(writer_table[object_id], object_id);
  }
  loc_object_id = object_id;
  //ATOMIC(&trans_table[0].read_set[loc_object_id], NULL, object_table[object_id]);
  instance = INSTANCE(trans_table[0].status);
  read_obj(&trans_table[0], &trans_table[0], loc_object_id, instance);
  SET_ACCESS_VECTOR(trans_table[0].access_vector, loc_object_id);
  data=&trans_table[0].read_set[loc_object_id];

  UNLOCK_KERNEL()
#endif

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

