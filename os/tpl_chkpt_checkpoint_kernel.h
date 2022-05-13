/**
 * @file tpl_os_checkpoint_kernel.h
 *
 * @section descr File description
 *
 * Trampoline checkpointing os services header.
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
 *
 */

#ifndef TPL_OS_CHECKPOINT_H
#define TPL_OS_CHECKPOINT_H

#include "tpl_os_kernel.h"

// extern void tpl_save_checkpoint(const uint16 buffer);
// extern void tpl_load_checkpoint(const uint16 buffer);

extern void tpl_save_checkpoint(void);
extern void tpl_load_checkpoint(void);
extern void tpl_save_checkpoint_dma(void);
extern void tpl_load_checkpoint_dma(void);

#define OS_START_SEC_CONST_16BIT
#include "tpl_memmap.h"
static CONST (sint16,OS_CONST) NO_CHECKPOINT = -1;
#define OS_STOP_SEC_CONST_16BIT
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_NON_VOLATILE_16BIT
#include "tpl_memmap.h"
extern VAR (sint16,OS_VAR) tpl_checkpoint_buffer;
#define OS_STOP_SEC_VAR_NON_VOLATILE_16BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_hibernate_os_service(void);

FUNC(void, OS_CODE) tpl_restart_os_service(void);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_OS_CHECKPOINT_H */
#endif
/* End of file tpl_os_checkpoint_kernel.h */
