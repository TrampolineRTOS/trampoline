/*
 * $EXEC_NAME$ stack
 */
tpl_stack_word $STACK_ZONE$[$STACK_SIZE$/sizeof(tpl_stack_word)];
struct TPL_STACK $STACK$ = {$STACK_ZONE$, $STACK_SIZE$};

#define $EXEC_STACK$ &$STACK$

/*
 * $EXEC_NAME$ context
 */
struct TPL_CONTEXT $EXEC_ALL_CONTEXT$ = { {0} };

#define $EXEC_CONTEXT$ &$EXEC_ALL_CONTEXT$
