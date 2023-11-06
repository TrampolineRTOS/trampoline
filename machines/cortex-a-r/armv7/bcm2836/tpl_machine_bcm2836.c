/**
 * @file tpl_machine_mk20dx256.c
 *
 * @section descr File description
 *
 * Trampoline processor dependant functions.
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

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "bcm2836.h"
#include "emblib.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_set_systick_timer(void) {
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
