define(`task_context',`dnl
tpl_context task_$1_context;
')

define(`task_context_ref',`dnl
&task_$1_context')

define(`AD_task_def',`dnl
/*
 * Task $1 stack
 */

tpl_stack_word task_$1_stack_zone[$5/sizeof(tpl_stack_word)];')

define(`stack_ref',`dnl
{task_$1_stack_zone`,' $5}')

define(`AD_Global',`')

define(`AD_isr_def',`dnl
/*
 * ISR2 $1 stack
 */

tpl_stack_word isr2_$1_stack_zone[$5/sizeof(tpl_stack_word)];')

define(`isr_context',`dnl
tpl_context isr2_$1_context;')

define(`isr_stack_ref',`dnl
{isr2_$1_stack_zone`,'$5}')

define(`isr_context_ref',`dnl
&isr2_$1_context')

define(`AD_sig',`dnl
define(`sig_b',eval(index(`$1',`/*%')+3))dnl
define(`sig_l',eval(index(`$1',`%*/')-sig_b))dnl
substr(`$1',sig_b,sig_l)')dnl
define(`AD_isr_assoc_list',`
    ifelse($#,`1',`AD_sig($1)',`AD_sig($1)`,'AD_isr_assoc_list(shift($@))')
')dnl

define(`AD_isr_addon',`dnl
/*
 * Signal / handler id association
 */

#include <signal.h>

int signal_for_id[ISR_COUNT] =  {dnl
AD_isr_assoc_list($@)
};dnl
')
