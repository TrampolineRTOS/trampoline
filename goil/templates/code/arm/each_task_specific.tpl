#define APP_Task_$EXEC_NAME$_START_SEC_STACK
#include "tpl_memmap.h"
/*
 * $EXEC_NAME$ stack
 */

VAR(tpl_stack_word, OS_APPL_DATA) $STACK_ZONE$[$STACK_SIZE$/sizeof(tpl_stack_word)];

#define APP_Task_$EXEC_NAME$_STOP_SEC_STACK
#include "tpl_memmap.h"

#define $EXEC_STACK$ { $STACK_ZONE$, $STACK_SIZE$ }

#define OS_START_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"
/*
 * $EXEC_NAME$ context
 */
 
VAR (arm_context, OS_VAR) $EXEC_INTEGER_CONTEXT$;

#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"

#define $EXEC_CONTEXT$ &$EXEC_INTEGER_CONTEXT$
