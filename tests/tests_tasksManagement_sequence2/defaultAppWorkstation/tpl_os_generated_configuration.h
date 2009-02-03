#ifndef APP_HEADER_H
#define APP_HEADER_H

#include "tpl_app_objects.h"

#if !defined(NO_TASK) || !defined(NO_ISR)
extern char *proc_name_table[TASK_COUNT + ISR_COUNT];
#endif


/*=============================================================================
 * Declaration of Counters macros
 */


/*=============================================================================
 * Declaration of flags macros
 */
 

#endif

/* End of file tpl_os_generated_configuration.h */
