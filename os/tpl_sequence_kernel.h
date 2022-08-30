/**
 * @file tpl_sequence_kernel.h
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

#ifndef TPL_OS_SEQUENCE_H
#define TPL_OS_SEQUENCE_H

#include "tpl_compiler.h"
#include "tpl_os_internal_types.h"

struct TPL_SEQUENCE{
    CONST(uint32, TYPEDEF) energy;
    CONST(uint8, TYPEDEF) next_state;
    CONST(uint8, TYPEDEF) current_state; 
    CONST(uint8, TYPEDEF) trace[];
};

typedef struct TPL_SEQUENCE tpl_sequence;

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

extern CONSTP2VAR(tpl_sequence, AUTOMATIC, OS_APPL_DATA)
    tpl_sequence_table[2];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_start_os_sequence_service(CONST(tpl_application_mode, AUTOMATIC) mode);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* TPL_OS_SEQUENCE_H */
#endif
/* End of file tpl_sequence_kernel.h */