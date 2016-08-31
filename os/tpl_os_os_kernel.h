/**
 * @file tpl_os_os_kernel.h
 *
 * @section descr File description
 *
 * Trampoline os services header.
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

#ifndef TPL_OS_OS_KERNEL_H
#define TPL_OS_OS_KERNEL_H

#include "tpl_os_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(tpl_application_mode, OS_CODE) tpl_get_active_application_mode_service(
  void);

FUNC(void, OS_CODE) tpl_start_os_service(
  CONST(tpl_application_mode, AUTOMATIC) mode);

FUNC(void, OS_CODE) tpl_call_shutdown_os(
    CONST(tpl_status, AUTOMATIC) error);

FUNC(void, OS_CODE) tpl_shutdown_os_service(
    CONST(tpl_status, AUTOMATIC) error);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_OS_OS_KERNEL_H */
#endif
/* End of file tpl_os_os_kernel.h */
