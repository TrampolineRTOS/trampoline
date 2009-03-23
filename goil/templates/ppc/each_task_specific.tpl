/*
 * $EXEC_NAME$ stack
 */
tpl_stack_word $STACK_ZONE$[$STACK_SIZE$/sizeof(tpl_stack_word)];

#define $EXEC_STACK$ { $STACK_ZONE$, $STACK_SIZE$ }

/*
 * $EXEC_NAME$ context
 */
ppc_integer_context $EXEC_INTEGER_CONTEXT$;

#define $EXEC_USE_FLOAT$ $FLAG_USE_FLOAT$

#if defined(WITH_FLOAT) && $EXEC_USE_FLOAT$ == 1

ppc_float_context $EXEC_FLOAT_CONTEXT$ ;
#define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$, &$EXEC_FLOAT_CONTEXT$ }

#else
#ifdef WITH_FLOAT
#  define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$, NULL }
#else
#  define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$ }
#endif
#endif

