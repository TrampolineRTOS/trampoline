#include "tpl_os_stm_internal_types.h"


/*
 * Transaction descriptors' table (indexed by core IDs)
 */ 
VAR(tpl_stm_tx_descriptor, OS_APPL_DATA) trans_table[NUMBER_OF_CORES] = {
    {
    	0, 				/* core id 		*/
    	0, 				/* status 		*/ 
    	{ 
    	{ 
    	0 				/* access_vector 	*/
    }
};

/*
 * Writers' table (indexed by object IDs)
 */
P2VAR(tpl_stm_tx_descriptor, AUTOMATIC, OS_APPL_DATA) writer_table[NUMBER_OF_OBJECTS] = {
	