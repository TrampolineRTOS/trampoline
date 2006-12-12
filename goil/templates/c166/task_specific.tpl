/*
 * $EXEC_NAME$ stacks
 *
 * System stack
 */
tpl_stack_word idata $SYS_STACK_ZONE$[$SYS_STACK_SIZE$/sizeof(tpl_stack_word)];

/*
 * User stack
 */
tpl_stack_word $USR_STACK_ZONE$[$USR_STACK_SIZE$/sizeof(tpl_stack_word)];

#define $EXEC_STACK$ { $SYS_STACK_ZONE$, $SYS_STACK_SIZE$, $USR_STACK_ZONE$, $USR_STACK_SIZE$ }

/*
 * $EXEC_NAME$ context
 */
c166_context $EXEC_INTEGER_CONTEXT$;

#define $EXEC_CONTEXT$ { &$EXEC_INTEGER_CONTEXT$ }

