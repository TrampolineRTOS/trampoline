/*
 * isr2 $EXEC_NAME$ stacks
 *
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_stack_word $STACK_ZONE$[$STACK_SIZE$/sizeof(tpl_stack_word)];

#define $EXEC_STACK$ { $STACK_ZONE$, $STACK_SIZE$ }

/*
 * isr2 $EXEC_NAME$ context
 */
hcs12_context $EXEC_INTEGER_CONTEXT$;

#define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$ }

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
