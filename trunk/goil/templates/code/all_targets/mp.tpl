#include "tpl_os_mem_prot.h"

/*
 * External linker symbols
 */
$LINKER_SYM$

/*
 * Memory descriptor for each process
 */
$REGION_DESC$

/*
 * Descriptor table indexed by the id of the task or ISR
 */
$DESC_TABLE$

/*
 * Initialization function since external const may not be used to init
 * variables
 */
FUNC(void, OS_CODE) tpl_init_mp_descriptors(void)
{
$INIT_CODE$
}
