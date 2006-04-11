/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Macros for system construction
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */
changecom(`/*',`*/')dnl
define(`default_stack_size',`dnl
ifdef(`header',`',`dnl
`#'define DEFAULT_STACK_SIZE  $1')')
define(`C_',`dnl')dnl
define(`objectlist',`ifelse($#,`1',`$1',`$1`'objectlist(shift($@))')')dnl
define(`objectname',`dnl
define(`begin',eval(index(`$2',`/*=')+3))dnl
define(`length',eval(index(`$2',`=*/')-begin))dnl
$1`'substr(`$2',begin,length)')dnl
define(`objectnamelist',`
    ifelse($#,`2',objectname($1,`$2'),`objectname($1,`$2')`,'objectnamelist($1,shift(shift($@)))')`'dnl
')

define(`currenttask',`0')dnl
define(`task',`
/*=$1=*/
ifdef(`header',`dnl
/* define the symbol for use with OS services */
`#'define $1  currenttask
',`

AD_task_def($@)

/*
 * Task $1 context
 */
task_context($@)

/*
 * Task $1 function prototype
 * the function have to be defined elsewhere in your project
 * with the TASK macro.
 */
void task_$1_function(void);

/*
 * Task $1 static descriptor
 */
tpl_exec_static task_static_descriptor_of_$1 = {
    /* context                  */ task_context_ref($@)`,'
    /* stack                    */ stack_ref($@)`,'
    /* entry point (function)   */ task_$1_function`,'
    /* internal ressource       */ NULL`,'
    /* task id                  */ $1`,'
    /* task base priority       */ (tpl_priority)$2`,'
    /* max activation count     */ $4`,'
    /* task type                */ BASIC_TASK
};

/*
 * Task $1 dynamic descriptor
 */
tpl_task task_descriptor_of_$1 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &task_static_descriptor_of_$1`,'
    /* resources            */  NULL`,'
    /* next task for READY  */  NULL`,'
    /* next set for READY   */  NULL`,'
    /* activate count       */  0`,'
    /* task priority        */  (tpl_priority)$2`,'
    /* task state           */  $3
    }`,'    /* end of exec_desc part */
    /* event mask           */  0`,'
    /* event wait           */  0
};
')
define(`currenttask',incr(currenttask))
')
define(`tasks_list',`dnl
ifdef(`header',`',`dnl
#ifndef DEFAULT_STACK_SIZE
#define DEFAULT_STACK_SIZE  1024
#endif
')
objectlist($@)
ifdef(`header',`/*
 * number of tasks
 */
#define TASK_COUNT  currenttask
',`
/*
 * task table
 */
tpl_task *tpl_task_table[TASK_COUNT] = {dnl
objectnamelist(`&task_descriptor_of_',$@)
};dnl
')
')

define(`currentisr',`0')dnl
define(`isr',`
/*=$1=*/
/*%$4%*/
ifdef(`header',`dnl
/* define the symbol for use with OS services */
`#'define $1            currentisr
`#'define $1_isr_level  $2
',`

AD_isr_def($@)

/*
 * ISR2 $1 context
 */

isr_context($@)

/*
 * ISR2 $1 function prototype
 * the function have to be defined elsewhere in your project
 * with the ISR2 macro.
 */
void isr2_$1_function(void);

/*
 * ISR2 $1 static descriptor
 */
tpl_exec_static isr2_static_descriptor_of_$1 = {
    /* context                  */ isr_context_ref($@)`,'
    /* stack                    */ isr_stack_ref($@)`,'
    /* entry point (function)   */ isr2_$1_function`,'
    /* internal resource        */ NULL`,'
    /* task id                  */ ($1 + TASK_COUNT)`,'
    /* task base priority       */ (tpl_priority)$2`,'
    /* max activation count     */ $3`,'
    /* task type                */ IS_ROUTINE
};


tpl_isr_static tis_$1 = {
	/* helper */ NULL`,'
	/* next */ NULL
};

/*
 * ISR2 $1 dynamic descriptor
 */
tpl_isr isr2_descriptor_of_$1 = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &isr2_static_descriptor_of_$1`,'
    /* resources            */  NULL`,'
    /* next task for READY  */  NULL`,'
    /* next set for READY   */  NULL`,'
    /* activate count       */  0`,'
    /* isr priority        */  (tpl_priority)$2`,'
    /* isr state           */  SUSPENDED
    }`,'    /* end of exec_desc part */
    &tis_$1
};')
define(`currentisr',incr(currentisr))
')
define(`isr_list',`dnl
ifdef(`header',`',`dnl
')
objectlist($@)
ifdef(`header',`/*
 * number of isr2
 */
#define ISR_COUNT  currentisr
',`
/*
 * ISR2 table
 */
tpl_isr *tpl_isr_table[ISR_COUNT] = {dnl
objectnamelist(`&isr2_descriptor_of_',$@)
};

AD_isr_addon($@)
')
')

define(`currentresource',`0')dnl
define(`resource',`dnl
/*=$1=*/
ifdef(`header',`dnl
/* define the symbol to use with OS services */
`#'define $1  currentresource
',`
/*
 * Resource descriptor of resource $1
 */
tpl_resource resource_descriptor_of_$1 = {
    /* ceiling priority of the resource */  (tpl_priority)$2`,'
    /* owner previous priority          */  (tpl_priority)-1`,'
    /* owner of the resource            */  NULL`,'
    /* next resource in the list        */  NULL
};
')
define(`currentresource',incr(currentresource))
')
define(`resources_list',`dnl
objectlist($@)
ifdef(`header',`/*
 * number of resources
 */
#define RES_COUNT  currentresource
',`
/*
 * resource table
 */
tpl_resource *tpl_resource_table[RES_COUNT] = {dnl
objectnamelist(`&resource_descriptor_of_',$@)
};
')
')
define(`counter',`dnl

/*
 * Counter descriptor of counter $1
 */
tpl_counter counter_descriptor_of_$1 = {
    /* ticks per base       */  $2`,'
    /* current tick         */  0`,'
    /* current date         */  0`,'
    /* first alarm          */  NULL`,'
    /* next alarm to raise  */  NULL
};
')
define(`counter_list',`dnl
ifdef(`header',`',`objectlist($@)')
')
define(`currentalarm',`0')dnl
define(`alarm',`dnl
/*=$1=*/
ifdef(`header',`dnl
/* define the symbol to use with OS services */
`#'define $1  currentalarm',`
ifelse($3,`alarm_callback',ifdef(`callback_function_$4',`',`void $4`('`)';define(`callback_function_$4')'))
/*
 * Alarm descriptor of alarm $1
 */
tpl_alarm alarm_descriptor_of_$1 = {
    /* State of the alarm   */  ALARM_SLEEP`,'
    /* kind of the alarm    */  ifelse($3,`activate_task',`ALARM_TASK_ACTIVATION',$3,`set_event',`ALARM_EVENT_SETTING',$3,`alarm_callback',`ALARM_CALLBACK')`,'
                                {
    /* action of the alarm  */      {
                                        ifelse($3,`activate_task',`(tpl_callback_func)&task_descriptor_of_$4',$3,`set_event',`(tpl_callback_func)&task_descriptor_of_$4',$3,`alarm_callback',`$4')
                                    }`,'
    /* event if necessary   */      ifelse($3,`activate_task',`0',$3,`set_event',`$5',$3,`alarm_callback',`0')
                                }`,'
    /* pointer to counter   */  &counter_descriptor_of_$2``,''
    /* cycle                */  0`,'
    /* date                 */  0`,'
    /* next alarm           */  NULL`,'
    /* prev alarm           */  NULL
};
')
define(`currentalarm',incr(currentalarm))
')
define(`alarm_list',`dnl
objectlist($@)
ifdef(`header',`/*
 * number or alarm
 */
#define ALARM_COUNT  $#
',`
/*
 * alarm table
 */
tpl_alarm *tpl_alarm_table[ALARM_COUNT] = {dnl
objectnamelist(`&alarm_descriptor_of_',$@)
};
')
')
define(`begin_system',`dnl
ifdef(`header',`
ifdef(`filename',``#'ifndef __translit(filename)_H__
`#'define __translit(filename)_H__',``#'ifndef __TPL_OS_GENERATED_CONFIG_H__
`#'define __TPL_OS_GENERATED_CONFIG_H__')
',`dnl
`#'include "tpl_os_internal_types.h"
`#'include "tpl_os_definitions.h"
`#'include "tpl_machine.h"
`#'include "tpl_os_interrupts.h"
ifdef(`filename',``#'include "filename.h"',``#'include "tpl_os_generated_configuration.h"')
')dnl
')
define(`end_system',`dnl
AD_Global 
ifdef(`header',`
`#'endif
') 
')
