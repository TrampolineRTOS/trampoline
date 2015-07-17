/*
 *  @file tpl_dispatch_table.h
 *
 * @section desc File description
 *
 * Trampoline dispatch table header for system call version
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
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
