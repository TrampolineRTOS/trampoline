/**
 * @file tpl_afh_ready_list.h
 *
 * @section descr File description
 *
 * Header for Trampoline array of fifo indexed by priority and highest
 * priority stored in a heap hybrid system.
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

#ifndef __TPL_AFH_READY_LIST_H__
#define __TPL_AFH_READY_LIST_H__

/**
 * @typedef tpl_proc_list
 * This type implements a FIFO list of tpl_proc_id
 */
typedef struct {
  VAR(tpl_index, TYPEDEF) front_index;
  VAR(tpl_index, TYPEDEF) actual_size;
  CONST(tpl_index, TYPEDEF) full_size;
  CONSTP2VAR(tpl_proc_id, TYPEDEF, OS_VAR) buffer;
} tpl_proc_fifo;

/**
 * @typedef tpl_list
 * This type implements the ready list.
 */
typedef struct {
  CONSTP2VAR(tpl_proc_fifo, TYPEDEF, OS_VAR) fifos;
  CONSTP2VAR(tpl_priority, TYPEDEF, OS_VAR) heap;
} tpl_list;

#endif
