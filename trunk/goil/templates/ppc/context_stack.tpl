/*
 * Task $TASK_NAME$ stack
 */
tpl_stack_word $STACK_ZONE$[$STACK_SIZE$/sizeof(tpl_stack_word)];

#define $TASK_STACK$ { &$STACK_ZONE$, $STACK_SIZE$ }

/*
 * Task $TASK_NAME$ context
 */
ppc_integer_context $TASK_INTEGER_CONTEXT$;

#define $TASK_USE_FLOAT$ $FLAG_USE_FLOAT$

#if $TASK_USE_FLOAT$ == 1

ppc_float_context $TASK_FLOAT_CONTEXT$ ;
#define $TASK_CONTEXT$ { &$TASK_INTEGER_CONTEXT$, &$TASK_FLOAT_CONTEXT$ }

#else

#define $TASK_CONTEXT$ { &$TASK_INTEGER_CONTEXT$, NULL }

#endif

