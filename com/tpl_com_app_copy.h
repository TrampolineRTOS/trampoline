/*
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS,
 * University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * Trampoline application receiving functions header
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_APP_COPY_H__
#define __TPL_COM_APP_COPY_H__

#include "tpl_com_base_mo.h"
#include "tpl_os_types.h"

FUNC(tpl_status, OS_CODE)
tpl_copy_from_unqueued(P2VAR(tpl_com_data, AUTOMATIC, OS_APPL_DATA) data,
                       CONSTP2CONST(void, AUTOMATIC, OS_CONST) rmo);

tpl_status tpl_copy_from_queued(P2VAR(tpl_com_data, AUTOMATIC, OS_APPL_DATA)
                                    data,
                                CONSTP2CONST(void, AUTOMATIC, OS_CONST) rmo);

#endif
/*  __TPL_COM_APP_COPY_H__   */
