/*
 * @file tpl_os_stm.h
 *
 * @section desc File description
 *
 * Trampoline STM header file
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
 * $Date: 2015-03-02 16:00:39 +0100 (lun., 02 mars 2015) $
 * $Rev: 0 $
 * $Author: audrey $
 * $URL: http://trampoline.rts-software.org/svn/trunk/os/tpl_os_stm.h $
 */
#include "tpl_compiler.h"
#include "tpl_os_types.h"
#include "tpl_os_task_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"


/*-----------------------------------------------------------------------------
 * Number of objects in the system
 */
#define NUMBER_OF_OBJECTS         0

/**
 * @typedef tpl_stm_core_id
 *
 * Transaction core id
 */
typedef uint32 tpl_stm_core_id;

/**
 * @typedef tpl_stm_data_id
 *
 * Object data id
 */
typedef uint32 tpl_stm_data_id;

/**
 * @typedef tpl_stm_current_pos
 *
 * Current position of concurrent data in copy_table
 */
typedef int tpl_stm_current_pos;

/**
 * @typedef tpl_stm_concurrency_vector
 *
 * Object concurrency vector
 */
typedef uint32 tpl_stm_concurrency_vector;

/**
 * @typedef tpl_stm_status
 *
 * Transaction status : 
 * - #TXS_IN_PROGRESS means the transaction is active
 * - #TXS_IN_RETRY means the transaction is in retry
 * - #TXS_FAILED means the transaction has failed
 * - #TXS_INACTIVE means the transaction is inactive
 */
typedef uint32 tpl_stm_status;

/**
 * @def TXS_IN_PROGRESS
 *
 * The transaction is active
 *
 */
#define TXS_IN_PROGRESS	0

/**
 * @def TXS_IN_RETRY
 *
 * The transaction is in retry
 *
 */
#define TXS_IN_RETRY	1

/**
 * @def TXS_FAILED
 *
 * The transaction has failed
 *
 */
#define TXS_FAILED	2

/**
 * @def TXS_INACTIVE
 *
 * The transaction is inactive
 *
 */
#define TXS_INACTIVE	3


/**
 * @typedef tpl_stm_access_vector
 *
 * Transaction access vector
 */
typedef uint32 tpl_stm_access_vector;


/**
 * @typedef tpl_stm_object
 *
 * This is is the internal object structure.
 */
struct {
  CONST(tpl_stm_data_id, TYPEDEF)
    dataId;     	/**<  Data id
                                		                       	*/
  VAR(tpl_stm_current_pos, TYPEDEF)
    current_pos;  	/**<  Current position of the concurrent data
								 	*/
  VAR(tpl_stm_data_id, OS_APPL_DATA) 
    tpl_stm_copy_table[NUMBER_OF_CORES+2];  /**<  Table gathering the  
                      copies of the concurrent data                  	*/
  VAR(tpl_stm_concurrency_vector, TYPEDEF)
    concurrency_vector; /**<  Concurrency vector of the object
								 	*/
} TPL_STM_OBJECT;

/**
 * @typedef tpl_stm_object
 *
 * This is an alias for the #TPL_STM_OBJECT structure
 *
 * @see #TPL_STM_TX_DESCRIPTOR
 */
typedef struct TPL_STM_OBJECT tpl_stm_object;


/**
 * @typedef TPL_STM_TX_DESCRIPTOR
 *
 * This is is the internal transaction descriptor structure.
 */
struct {
  CONST(tpl_stm_core_id, TYPEDEF)
    core_id;     	/**<  Core id to which the transaction belongs
                                		                       	*/
  VAR(tpl_stm_status, TYPEDEF)
    status;  		/**<  Status of the transaction
								 	*/

  //VAR(tpl_stm_object, OS_APPL_DATA)
   // read_set[NUMBER_OF_OBJECTS];          /**<  Set of objects accessed 
     //                          	in read-only mode                     	*/
  //VAR(tpl_stm_object, OS_APPL_DATA)
   // write_set[NUMBER_OF_OBJECTS];          /**<  Set of objects accessed
         //                       in write mode                          	*/
  VAR(tpl_stm_concurrency_vector, TYPEDEF)
    access_vector; 	/**<  Access vector of the transaction
								 	*/
} TPL_STM_TX_DESCRIPTOR;

/**
 * @typedef tpl_stm_tx_descriptor
 *
 * This is an alias for the #TPL_STM_TX_DESCRIPTOR structure
 *
 * @see #TPL_STM_TX_DESCRIPTOR
 */
typedef struct TPL_STM_TX_DESCRIPTOR tpl_stm_tx_descriptor;


//VAR(tpl_stm_tx_descriptor, OS_APPL_DATA) trans_table[NUMBER_OF_CORES];
//VAR(tpl_stm_object, OS_APPL_DATA) object_table[NUMBER_OF_OBJECTS];
//VAR(tpl_stm_tx_descriptor, OS_APPL_DATA) writer_table[NUMBER_OF_OBJECTS];

/**
 * @internal
 *
 * Displays on screen the message given as an argument
 *
 * @param   msg     message to display
 *
 * @retval  E_OK        no error
 *
 */
FUNC(StatusType, OS_CODE) tpl_screen_display_service(
  P2CONST(char, AUTOMATIC, OS_APPL_DATA) msg);

/*
 * tpl_stm_begin_read_tx_service
 *
 * Initializes a read-set transaction on the core given as an argument
 *
 * tx:  Transaction descriptor
 *
 * coreId:  Core on which the read-set transaction begins
 *
 * Return value:
 * E_OK:    No error (Standard & Extended)
 * 
 */
FUNC(StatusType, OS_CODE) tpl_stm_begin_read_tx_service(
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) tx,
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) coreId);

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
FUNC(StatusType, OS_CODE) tpl_stm_begin_write_tx_service(
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) tx,
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) coreId);

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
FUNC(StatusType, OS_CODE) tpl_stm_end_read_tx_service(
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) tx);

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
FUNC(StatusType, OS_CODE) tpl_stm_end_write_tx_service(
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) tx);

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
FUNC(StatusType, OS_CODE) tpl_stm_open_read_object_service(
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) tx,
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) coreId,
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) dataId);

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
FUNC(StatusType, OS_CODE) tpl_stm_open_write_object_service(
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) tx,
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) coreId,
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) dataId);

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
FUNC(StatusType, OS_CODE) tpl_stm_commit_read_tx_service(
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) tx,
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) instance);

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
FUNC(StatusType, OS_CODE) tpl_stm_commit_write_tx_service(
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) tx);


