/*
 * $EXEC_NAME$ stack
 */
tpl_stack_word $STACK_ZONE$[$STACK_SIZE$/sizeof(tpl_stack_word)];

#define $EXEC_STACK$ { $STACK_ZONE$, $STACK_SIZE$ }

/*
 * $EXEC_NAME$ context
 */
couroutine_t $EXEC_ALL_CONTEXT$;

#define $EXEC_CONTEXT$ &$EXEC_ALL_CONTEXT$
