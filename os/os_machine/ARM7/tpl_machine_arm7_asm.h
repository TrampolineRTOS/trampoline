/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline ARM7 specifics
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL: http://localhost:8888/Trampoline/svn/tpl_machine/ARM7/tpl_machine_ARM7.h $
 */
 
#include "tpl_os_internal_types.h"

#ifndef __TPL_MACHINE_ARM7_ASM_H__
#define __TPL_MACHINE_ARM7_ASM_H__
extern void tpl_shutdown(void);
extern void tpl_switch_context(tpl_context *old_context, tpl_context *new_context);
extern void tpl_switch_context_from_it(tpl_context * old_context, tpl_context * new_context);
extern void tpl_get_task_lock(void);
extern void tpl_release_task_lock(void);
#endif