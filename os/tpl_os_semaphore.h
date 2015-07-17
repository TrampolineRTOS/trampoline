/**
 * @file tpl_os_semaphore.h
 *
 * @section desc File description
 *
 * Trampoline semaphore types header file
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

#ifndef TPL_OS_SEMAPHORE_H
#define TPL_OS_SEMAPHORE_H

#include "tpl_os_std_types.h"

typedef uint8 SemType;

#define DeclareSemaphore(sem_id) extern CONST(SemType, AUTOMATIC) sem_id;

#endif
