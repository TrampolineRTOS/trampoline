define(`task_context',`dnl
ppc_integer_context task_$1_integer_context;
ifdef(`WITH_ALTIVEC',`dnl
ifelse(dnl
`$6',`FLOAT',`dnl
ppc_float_context   task_$1_float_context;',
`$6',`VECTOR',`dnl
ppc_vector_context  task_$1_vector_context;',
`$6',`FLOAT_VECTOR',`dnl
ppc_float_context   task_$1_float_context;
ppc_vector_context  task_$1_vector_context;')',`dnl
ifelse(dnl
`$6',`FLOAT',`dnl
ppc_float_context   task_$1_float_context;')')')

define(`task_context_ref',`dnl
{ &task_$1_integer_context`'ifdef(`WITH_ALTIVEC',`ifelse(dnl
`$6',`FLOAT',``,' &task_$1_float_context`,' NULL',
`$6',`VECTOR',``,' NULL`,' &task_$1_vector_context',
`$6',`FLOAT_VECTOR',``,' &task_$1_float_context`,' &task_$1_vector_context',
``,' NULL`,' NULL')',`ifelse(`$6',`FLOAT',``,' &task_$1_float_context',``,' NULL')') }')

define(`AD_task_def',`dnl
/*
 * Task $1 stack
 */

tpl_stack_word task_$1_stack_zone[$5/sizeof(tpl_stack_word)];')

define(`stack_ref',`dnl
{task_$1_stack_zone`,' $5}')

define(`AD_Global',`')
