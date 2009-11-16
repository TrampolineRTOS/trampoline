#include "tpl_os_mem_prot.h"

#ifdef WITH_AUTOSAR
/*
 * External linker symbols for OS Applications
 */
$LINKER_SYM$
#endif

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Memory descriptor for each process
 */
$REGION_DESC$

/*
 * Descriptor table indexed by the id of the task or ISR
 */
$DESC_TABLE$
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
