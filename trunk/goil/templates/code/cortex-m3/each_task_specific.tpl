/* ____________________________________________________________________
 * $EXEC_NAME$ stacks
 *
 * System stack
 */
tpl_stack_word $STACK_ZONE$[$STACK_SIZE$/sizeof(tpl_stack_word)];


#define $EXEC_STACK$ { $STACK_ZONE$, $STACK_SIZE$ }

/*
 * $EXEC_NAME$ context
 */
cm3_context $EXEC_INTEGER_CONTEXT$;

#define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$ }
