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
VAR(ppc_integer_context, OS_VAR) $EXEC_INTEGER_CONTEXT$;
#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"

#define $EXEC_USE_FLOAT$ $FLAG_USE_FLOAT$

#if defined(WITH_FLOAT) && $EXEC_USE_FLOAT$ == 1

#define OS_START_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"
VAR(ppc_float_context, OS_VAR) $EXEC_FLOAT_CONTEXT$ ;
#define OS_STOP_SEC_VAR_NOINIT_32BIT
#include "tpl_memmap.h"

#define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$, &$EXEC_FLOAT_CONTEXT$ }

#else
#ifdef WITH_FLOAT
#  define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$, NULL }
#else
#  define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$ }
#endif
#endif

