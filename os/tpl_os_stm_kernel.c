/**
 * @file tpl_os_stm_kernel.c
 *
 * @section desc File description
 *
 * Trampoline Event Management implementation file
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
#include <string.h>

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

 /* a compléter */

 UNLOCK_KERNEL()
#else
 LOCK_KERNEL()

 /* a compléter */

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
 /* a compléter */
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
FUNC(StatusType, OS_CODE) read_obj(CONST(tpl_stm_core_id, OS_APPL_DATA) coreid_tx1, CONST(tpl_stm_core_id, OS_APPL_DATA) coreid_tx2, CONST(ObjectType, AUTOMATIC) object_id, CONST(uint32, AUTOMATIC) instance){

  char loc_current_pos;
  char read_copy_index;

  if ((STATUS(trans_table[coreid_tx2].status) == TXS_IN_RETRY) && (INSTANCE(trans_table[coreid_tx2].status) == instance))
 	object_table[object_id].concurrency_vector = SET_FAIL_VECTOR(object_table[object_id].concurrency_vector, coreid_tx2);

  do
  {
	SET_READ_VECTOR(object_table[object_id].concurrency_vector, coreid_tx2);
	loc_current_pos = CURRENT_OBJECT_POS(object_table[object_id].concurrency_vector);
	read_copy_index = 2 + coreid_tx2;
	printf("data dans la structure object_table à current_pos = %d\n", *(int*)object_table[object_id].copy_table[object_table[object_id].current_pos]);
	object_table[object_id].copy_table[read_copy_index] = object_table[object_id].copy_table[loc_current_pos];
	printf("data dans la structure object_table à read_copy_index = %d\n",  *(int*)object_table[object_id].copy_table[read_copy_index]);
	if (READ_VECTOR_BIT(object_table[object_id].concurrency_vector, coreid_tx2))
		break;

  }
  while(1);


  if ((INSTANCE(trans_table[coreid_tx2].status) == instance) && (STATUS(trans_table[coreid_tx2].status) < TXS_INACTIVE))
  {
	/* ATOMIC */
	if (trans_table[coreid_tx1].read_set[object_id] == &object_table[object_id])
		trans_table[coreid_tx1].read_set[object_id] = object_table[object_id].copy_table[read_copy_index];
  }
  printf("data dans la structure trans_table = %d\n", *(int*)trans_table[coreid_tx1].read_set[object_id]);
};


/*
 * tpl_stm_open_read_object_service
 *
 * A read-set transaction opens for reading a given object
 *
 * object_id:  Object identifier
 *
 * data:  Data
 *
 * data_size:  Data size
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 *
 */
FUNC(StatusType, OS_CODE) tpl_stm_open_read_object_service(CONST(ObjectType, AUTOMATIC) object_id, P2VAR(tpl_stm_data, AUTOMATIC, OS_APPL_DATA) data){

uint32 instance;

#if NUMBER_OF_CORES > 1
 GET_CURRENT_CORE_ID(core_id)
#else
 uint32 core_id = 0;
#endif

  LOCK_KERNEL()

  printf("DEBUT : data pointée = %d, adresse pointée par data=%p\n", *(int*)data, data);

  if ((STATUS(trans_table[core_id].status) != TXS_IN_RETRY) && (UPDATE_FLAG(object_table[object_id].concurrency_vector)==1))
  {
	printf("Statut de la transaction différent de TXS_RETRY et update flag de l'objet à 1...\n");
	update(writer_table[object_id], object_id);
  }

  /* ATOMIC(&trans_table[core_id].read_set[object_id], NULL, &object_table[object_id]);  // inutile car déjà initialisé ainsi dans le template STM-HRT */
  instance = INSTANCE(trans_table[core_id].status);
  read_obj(core_id, core_id, object_id, instance);
  SET_ACCESS_VECTOR(trans_table[core_id].access_vector, object_id);
  printf("Data size = %zd\n", object_table[object_id].size);
  memcpy(data, trans_table[core_id].read_set[object_id], object_table[object_id].size);

  printf("FIN : data pointée = %d, adresse pointée par data=%p\n", *(int*)data, data);

  UNLOCK_KERNEL()

};

/*
 * tpl_stm_open_write_object_service
 *
 * A write-set transaction opens for writing a given object
 *
 * object_id:  Object identifier
 *
 * data:  Data
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 *
 */
FUNC(StatusType, OS_CODE) tpl_stm_open_write_object_service(CONST(ObjectType, AUTOMATIC) object_id, P2VAR(tpl_stm_data, AUTOMATIC, OS_APPL_DATA) data){

#if NUMBER_OF_CORES > 1
 GET_CURRENT_CORE_ID(core_id)
#else
 uint32 core_id = 0;
#endif

  LOCK_KERNEL()

  memcpy(trans_table[core_id].write_set[object_id], data, object_table[object_id].size);
  SET_UPDATE_FLAG(object_table[object_id].concurrency_vector);
  SET_ACCESS_VECTOR(trans_table[core_id].access_vector, object_id);

  printf("Valeur data dans copy_table = %d\n", *(int*)trans_table[core_id].write_set[object_id]);

  UNLOCK_KERNEL()

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

