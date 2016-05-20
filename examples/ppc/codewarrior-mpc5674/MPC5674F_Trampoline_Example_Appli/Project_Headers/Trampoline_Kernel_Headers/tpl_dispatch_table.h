/*
 *  @file tpl_dispatch_table.h
 *
 * @section desc File description
 *
 * Trampoline dispatch table header for system call version
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date: 2010-04-14 02:41:19 -0500 (mer. 14 avril 2010) $
 * $Rev: 1133 $
 * $Author: jlb $
 * $URL: https://trampoline.rts-software.org/svn/trunk/os/tpl_dispatch_table.h $
 */

#ifndef TPL_DISPATCH_TABLE_H
#define TPL_DISPATCH_TABLE_H

#include "tpl_service_ids.h"
#include "tpl_compiler.h"

typedef void (* tpl_system_call)(void);

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
extern CONST(tpl_system_call, OS_CONST) tpl_dispatch_table[SYSCALL_COUNT];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/* TPL_DISPATCH_TABLE_H */
#endif
/* End of file tpl_dispatch_table.h */
