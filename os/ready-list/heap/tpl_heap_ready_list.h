/**
 * @file tpl_heap_ready_list.h
 *
 * @section descr File description
 *
 * Header for Trampoline for heap ready list system.
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
 */

#ifndef __TPL_HEAP_READY_LIST_H__
#define __TPL_HEAP_READY_LIST_H__

#include "tpl_compiler.h"
#include "tpl_os_custom_types.h"

/**
 * @typedef tpl_heap_entry
 *
 * This type gather a key used to sort the heap and the identifier of
 * the process
 */
typedef struct {
  VAR(tpl_priority, TYPEDEF)  key;
  VAR(tpl_proc_id, TYPEDEF)   id;
} tpl_heap_entry;

#endif /* __TPL_HEAP_READY_LIST_H__ */

