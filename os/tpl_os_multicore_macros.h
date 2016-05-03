/**
 * @file tpl_os_multicore_macros.h
 *
 * @section desc File description
 *
 * Trampoline kernel macro to adapt to mono or multicore
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
 * $Date: 2013-01-15 18:00:20 +0100 (Mar, 15 jan 2013) $
 * $Rev: 1442 $
 * $Author: jlb $
 * $URL: https://trampoline.rts-software.org/svn/trunk/os/tpl_os_kernel.h $
 */

#ifndef TPL_OS_MULTICORE_MACROS_H
#define TPL_OS_MULTICORE_MACROS_H

/*
 * Macros used to adapt the kernel code to a multicore or a monocore
 * kernel
 */
#if NUMBER_OF_CORES > 1
/*
 * Multicore macros
 */

/*
 * GET_PROC_CORE_ID initializes the constant core_id with the core_id of
 * the proc passed as argument.
 */
#define GET_PROC_CORE_ID(a_proc_id, a_core_id) \
  CONST(uint16, AUTOMATIC) a_core_id = tpl_stat_proc_table[a_proc_id]->core_id;
/*
 * GET_CURRENT_CORE_ID initializes the constant core_id
 * with the current core_id
 */
#define GET_CURRENT_CORE_ID(a_core_id) \
  CONST(uint16, AUTOMATIC) a_core_id = tpl_get_core_id();
/*
 * GET_CORE_READY_LIST initializes the constant ready_list
 * with the ready list belonging to core core_id
 */
#define GET_CORE_READY_LIST(a_core_id, a_ready_list) \
  CONSTP2VAR(tpl_heap_entry, AUTOMATIC, OS_VAR) a_ready_list = tpl_ready_list[a_core_id];
/*
 * GET_TAIL_FOR_PRIO initializes the constant tail_for_prio
 * with the rank table of core core_id
 */
#define GET_TAIL_FOR_PRIO(a_core_id, a_tail_for_prio) \
  CONSTP2VAR(tpl_rank_count, AUTOMATIC, OS_VAR) a_tail_for_prio = \
    tpl_tail_for_prio[a_core_id];
/*
 * CORE_ID_OR_VOID is defined as CONST(uint16, AUTOMATIC) core_id in multicore
 * kernel. it is used as an argument to the tpl_current_os_state function
 */
#define CORE_ID_OR_VOID(a_core_id) \
  CONST(uint16, AUTOMATIC) a_core_id

/*
 * CORE_ID_OR_NOTHING is defined as core_id in multicore
 * kernel. it is used to pass the core_id as argument
 */
#define CORE_ID_OR_NOTHING(a_core_id) \
  a_core_id

/*
 * GET_TPL_KERN_FOR_CORE_ID instantiate a constant pointer pointing to the
 * tpl_kern of core_id
 */
#define GET_TPL_KERN_FOR_CORE_ID(a_core_id, a_kern) \
  CONSTP2VAR(tpl_kern_state, AUTOMATIC, OS_VAR) a_kern = \
    tpl_kern[a_core_id];
/*
 * TPL_KERN_REF dereference tpl_kern_for_core_id in multicore.
 */
#define TPL_KERN_REF(a_kern) \
  (*a_kern)

/*
 * TPL_KERN return the dereferenced table item in multicore.
 */
#define TPL_KERN(a_core_id) \
  (*(tpl_kern[a_core_id]))

/*
 * READY_LIST expands to the ready_list constant
 */
#define READY_LIST(a_ready_list)  a_ready_list
/*
 * TAIL_FOR_PRIO expands to the tail_for_prio constant
 */
#define TAIL_FOR_PRIO(a_tail_for_prio)     a_tail_for_prio
/*
 * TAIL_FOR_PRIO_ARG_DECL expands to the declaration of a tail_for_prio
 * table argument. It is used in multicore as additional argument to the
 * tpl_compare_entries function.
 */
#define TAIL_FOR_PRIO_ARG_DECL(a_tail_for_prio) \
  , CONSTP2CONST(tpl_rank_count, AUTOMATIC, OS_VAR) a_tail_for_prio
/*
 * TAIL_FOR_PRIO_ARG is in multicore the corresponding additional argument
 * passed to the tpl_compare_entries function.
 */
#define TAIL_FOR_PRIO_ARG(a_tail_for_prio) \
  , a_tail_for_prio

/*
 * GET_LOCK_CNT_FOR_CORE expands to the corresponding array in multicore.
 * It is used to retrieve all lock counters (e.g. tpl_locking_depth)
 */
#define GET_LOCK_CNT_FOR_CORE(a_lock_cnt, a_core_id)  a_lock_cnt[a_core_id]

#else
/*
 * Monocore macros
 */

#define GET_PROC_CORE_ID(a_proc_id, a_core_id)
#define GET_CURRENT_CORE_ID(a_core_id)
#define GET_CORE_READY_LIST(a_core_id, a_ready_list)
#define GET_TAIL_FOR_PRIO(a_core_id, a_tail_for_prio)

/*
 * CORE_ID_OR_VOID is defined as void in monocore kernel since
 * tpl_current_os_state function has no argument.
 */
#define CORE_ID_OR_VOID(a_core_id) \
  void
#define CORE_ID_OR_NOTHING(a_core_id)
#define GET_TPL_KERN_FOR_CORE_ID(a_core_id, a_kern)

/*
 * TPL_KERN_REF is equal to tpl_kern in monocore.
 */
#define TPL_KERN_REF(a_kern) \
  tpl_kern

/*
 * TPL_KERN is equal to tpl_kern in monocore.
 */
#define TPL_KERN(a_core_id) \
  tpl_kern

#define READY_LIST(a_ready_list) tpl_ready_list
#define TAIL_FOR_PRIO(a_tail_for_prio)  tpl_tail_for_prio
#define TAIL_FOR_PRIO_ARG_DECL(a_tail_for_prio)
#define TAIL_FOR_PRIO_ARG(a_tail_for_prio)

/*
 * GET_LOCK_CNT_FOR_CORE expands to the corresponding array in multicore.
 * It is used to retrieve all lock counters (e.g. tpl_locking_depth)
 */
#define GET_LOCK_CNT_FOR_CORE(a_lock_cnt, a_core_id)  a_lock_cnt
#endif

/**
 * @internal
 *
 * Macro to compute a dynamic priority
 */
#define DYNAMIC_PRIO(a_prio, a_tail_for_prio)                \
  (((a_prio) << PRIORITY_SHIFT) |                            \
   (--TAIL_FOR_PRIO(a_tail_for_prio)[a_prio] & RANK_MASK))

/**
 * @internal
 *
 * Macro to compute the actual priority
 */
#define ACTUAL_PRIO(prio) \
  (prio >> PRIORITY_SHIFT)


#endif
/* TPL_OS_MULTICORE_MACROS_H */
