#include "tpl_os_internal_types.h" //pour tpl_core_id

/**
 * @typedef tpl_stm_core_id
 *
 * Transaction core id
 */
typedef uint32 tpl_stm_core_id;

/**
 * @typedef tpl_stm_tx_id
 *
 * Transaction id
 */
typedef tpl_stm_core_id tpl_stm_tx_id;

/**
 * @typedef tpl_stm_data_id
 *
 * Object data id
 */
typedef uint32 tpl_stm_data_id;

/**
 * @typedef tpl_stm_data
 *
 * Object data
 */
typedef void* tpl_stm_data;

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
 * @typedef tpl_stm_access_vector
 *
 * Transaction access vector
 */
typedef uint32 tpl_stm_access_vector;

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
 * This is the internal object structure.
 */
struct TPL_STM_OBJECT {
  CONST(tpl_stm_data_id, TYPEDEF)
    dataId;     	/**<  Data id
                                		                       	*/
  VAR(tpl_stm_current_pos, TYPEDEF)
    current_pos;  	/**<  Current position of the concurrent data
								 	*/
  VAR(tpl_stm_data, OS_APPL_DATA) 
    tpl_stm_copy_table[NUMBER_OF_CORES+2];  /**<  Table gathering the  
                      copies of the concurrent data                  	*/
  VAR(tpl_stm_concurrency_vector, TYPEDEF)
    concurrency_vector; /**<  Concurrency vector of the object
								 	*/
};

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
struct TPL_STM_TX_DESCRIPTOR {
  CONST(tpl_stm_core_id, TYPEDEF)
    transaction_id;    	/**<  Core id to which the transaction belongs
                                		                       	*/
  VAR(tpl_stm_status, TYPEDEF)
    status;  		/**<  Status of the transaction
								 	*/
  P2VAR(tpl_stm_object, OS_APPL_DATA)
    read_set[NUMBER_OF_OBJECTS];          /**<  Set of objects accessed 
                               	in read-only mode                     	*/
  P2VAR(tpl_stm_object, OS_APPL_DATA)
    write_set[NUMBER_OF_OBJECTS];          /**<  Set of objects accessed
                                in write mode                          	*/
  VAR(tpl_stm_access_vector, TYPEDEF)
    access_vector; 	/**<  Access vector of the transaction
								 	*/
};

/**
 * @typedef tpl_stm_tx_descriptor
 *
 * This is an alias for the #TPL_STM_TX_DESCRIPTOR structure
 *
 * @see #TPL_STM_TX_DESCRIPTOR
 */
typedef struct TPL_STM_TX_DESCRIPTOR tpl_stm_tx_descriptor;
