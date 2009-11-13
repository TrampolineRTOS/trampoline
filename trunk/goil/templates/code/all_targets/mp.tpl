#include "tpl_os_mem_prot.h"

#ifdef WITH_AUTOSAR
/*
 * External linker symbols for OS Applications
 */
$LINKER_SYM$
#endif

/*
 * Memory descriptor for each process
 */
$REGION_DESC$

/*
 * Descriptor table indexed by the id of the task or ISR
 */
$DESC_TABLE$
