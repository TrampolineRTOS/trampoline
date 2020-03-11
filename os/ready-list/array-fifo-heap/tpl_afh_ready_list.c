/**
 * @file tpl_afh_ready_list.c
 *
 * @section descr File description
 *
 * Trampoline structures and functions for ready list. The ready list maintains up
 * to date ordered lists of tasks to be executed by the kernel. These functions
 * are used internally by trampoline and should not be used directly.
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

#include "tpl_os_kernel.h"
#include "tpl_dow.h"
#include "tpl_os_multicore_macros.h"
#include "tpl_ready_list.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

#ifdef WITH_DOW
#include <stdio.h>

extern CONSTP2CONST(char, AUTOMATIC, OS_APPL_DATA) proc_name_table[];

#endif

/*
 * Jobs are stored in a heap. Each entry has a key (used to sort the heap)
 * and the id of the process. The size of the heap is computed by doing
 * the sum of the activations of a process (each activation of a process is
 * a job. The key is the concatenation of the priority of the job and the
 * rank of the job. The max value is a higher rank.
 *
 * The head of the queue contains the highest priority job and so the running
 * job.
 *
 * RANK_MASK is used to get the part of the key used to store the rank of
 * a job
 * PRIORITY_MASK is used to get the part of the key used to store
 * the priority of a job
 * PRIORITY_SHIFT is used to shift the part of the key used to store
 * the priority of a job
 */
FUNC(int, OS_CODE) tpl_compare_entries(
  CONSTP2CONST(tpl_heap_entry, AUTOMATIC, OS_VAR) first_entry,
  CONSTP2CONST(tpl_heap_entry, AUTOMATIC, OS_VAR) second_entry
  TAIL_FOR_PRIO_ARG_DECL(tail_for_prio))
{
  VAR(uint32, AUTOMATIC) first_key = first_entry->key & (PRIORITY_MASK | RANK_MASK);
  VAR(uint32, AUTOMATIC) second_key = second_entry->key & (PRIORITY_MASK | RANK_MASK);
  VAR(uint32, AUTOMATIC) first_tmp ;
  VAR(uint32, AUTOMATIC) second_tmp ;

  first_tmp = ((first_key & RANK_MASK) -
    TAIL_FOR_PRIO(tail_for_prio)[first_key >> PRIORITY_SHIFT]);
  first_tmp = first_tmp & RANK_MASK;
  first_key = (first_key & PRIORITY_MASK);
  first_key = first_key | first_tmp;

  second_tmp = ((second_key & RANK_MASK) -
    TAIL_FOR_PRIO(tail_for_prio)[second_key >> PRIORITY_SHIFT]);
  second_tmp = second_tmp & RANK_MASK;
  second_key = (second_key & PRIORITY_MASK);
  second_key = second_key | second_tmp;

  return (first_key < second_key);
}

/*
 * @internal
 *
 * tpl_bubble_up bubbles the entry at index place up in the heap
 *
 * @param  heap   the heap on which the operation is done
 * @param  index  the place of the item to bubble up
 *
 */
FUNC(void, OS_CODE) tpl_bubble_up(
  CONSTP2VAR(tpl_heap_entry, AUTOMATIC, OS_VAR) heap,
  VAR(uint32, AUTOMATIC)                        index
  TAIL_FOR_PRIO_ARG_DECL(tail_for_prio))
{
  VAR(uint32, AUTOMATIC) father = index >> 1;

  while ((index > 1) &&
    (tpl_compare_entries(heap + father,
                         heap + index
                         TAIL_FOR_PRIO_ARG(tail_for_prio))))
  {
    /*
     * if the father key is lower then the index key, swap them
     */
    VAR(tpl_heap_entry, AUTOMATIC) tmp = heap[index];
    heap[index] = heap[father];
    heap[father] = tmp;
    index = father;
    father >>= 1;
  }
}

/*
 * @internal
 *
 * tpl_bubble_down bubbles the entry at index place down in the heap
 *
 * @param  heap   the heap on which the operation is done
 * @param  index  the place of the item to bubble down
 *
 */
FUNC(void, OS_CODE) tpl_bubble_down(
  CONSTP2VAR(tpl_heap_entry, AUTOMATIC, OS_VAR) heap,
  VAR(uint32, AUTOMATIC)                        index
  TAIL_FOR_PRIO_ARG_DECL(tail_for_prio))
{
  CONST(uint32, AUTOMATIC) size = heap[0].key;
  VAR(uint32, AUTOMATIC) child;

  while ((child = index << 1) <= size) /* child = left */
  {
    CONST(uint32, AUTOMATIC) right = child + 1;
    if ((right <= size) &&
      tpl_compare_entries(heap + child,
                          heap + right
                          TAIL_FOR_PRIO_ARG(tail_for_prio)))
    {
      /* the right child exists and is greater */
      child = right;
    }
    if (tpl_compare_entries(heap + index,
                            heap + child
                            TAIL_FOR_PRIO_ARG(tail_for_prio)))
    {
      /* the father has a key <, swap */
      CONST(tpl_heap_entry, AUTOMATIC) tmp = heap[index];
      heap[index] = heap[child];
      heap[child] = tmp;
      /* go down */
      index = child;
    }
    else
    {
      /* went down to its place, stop the loop */
      break;
    }
  }
}

/**
 * @internal
 *
 * tpl_front_proc returns the proc_id of the highest priority proc in the
 * ready list on the current core
 */
FUNC(tpl_heap_entry, OS_CODE) tpl_front_proc(CORE_ID_OR_VOID(core_id))
{
  GET_CORE_READY_LIST(core_id, ready_list)

    return (READY_LIST(ready_list)[1]);
}

/*
 * @internal
 *
 * tpl_put_preempted_proc puts a preempted proc in a ready list.
 * In a multicore kernel it may be called from a core that does not own
 * the ready list (for a partitioned scheduler). So the core_id field
 * of the proc descriptor is used to get the corresponding ready list.
 */
FUNC(void, OS_CODE) tpl_put_preempted_proc(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  GET_PROC_CORE_ID(proc_id, core_id)
  GET_CORE_READY_LIST(core_id, ready_list)
  GET_TAIL_FOR_PRIO(core_id, tail_for_prio)


  VAR(uint32, AUTOMATIC) index = (uint32)(++(READY_LIST(ready_list)[0].key));

  CONST(tpl_priority, AUTOMATIC) dyn_prio =
    tpl_dyn_proc_table[proc_id]->priority;

  DOW_DO(printf("put preempted %s, %d\n",proc_name_table[proc_id],dyn_prio));
  /*
   * add the new entry at the end of the ready list
   */
  READY_LIST(ready_list)[index].key = dyn_prio;
  READY_LIST(ready_list)[index].id = proc_id;

  tpl_bubble_up(
    READY_LIST(ready_list),
    index
    TAIL_FOR_PRIO_ARG(tail_for_prio)
  );

  DOW_DO(printrl("put_preempted_proc"));
}

/*
 * @internal
 *
 * tpl_put_new_proc puts a new proc in a ready list. In a multicore kernel
 * it may be called from a core that does not own the ready list (for
 * a partitioned scheduler). So the core_id field of the proc descriptor
 * is used to get the corresponding ready list.
 */
FUNC(void, OS_CODE) tpl_put_new_proc(
  CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  GET_PROC_CORE_ID(proc_id, core_id)
  GET_CORE_READY_LIST(core_id, ready_list)
  GET_TAIL_FOR_PRIO(core_id, tail_for_prio)

  VAR(uint32, AUTOMATIC) index = (uint32)(++(READY_LIST(ready_list)[0].key));

  VAR(tpl_priority, AUTOMATIC) dyn_prio;
  CONST(tpl_priority, AUTOMATIC) prio =
    tpl_stat_proc_table[proc_id]->base_priority;
  /*
   * add the new entry at the end of the ready list
   */
  dyn_prio = (prio << PRIORITY_SHIFT) |
             (--TAIL_FOR_PRIO(tail_for_prio)[prio] & RANK_MASK);

  DOW_DO(printf("put new %s, %d\n",proc_name_table[proc_id],dyn_prio);)

  READY_LIST(ready_list)[index].key = dyn_prio;
  READY_LIST(ready_list)[index].id = proc_id;

  tpl_bubble_up(
    READY_LIST(ready_list),
    index
    TAIL_FOR_PRIO_ARG(tail_for_prio)
  );

  DOW_DO(printrl("put_new_proc");)
}

/*
 * @internal
 *
 * tpl_remove_front_proc removes the highest priority proc from the
 * ready list on the specified core and returns the heap_entry
 */
FUNC(tpl_heap_entry, OS_CODE) tpl_remove_front_proc(CORE_ID_OR_VOID(core_id))
{
  GET_CORE_READY_LIST(core_id, ready_list)
  GET_TAIL_FOR_PRIO(core_id, tail_for_prio)

  /*
   * Get the current size and update it (since the front element will be
   * removed)
   */
  CONST(uint32, AUTOMATIC) size = READY_LIST(ready_list)[0].key--;
  VAR(uint32, AUTOMATIC) index = 1;

  /*
   * Get the proc_id of the front proc
   */
  VAR(tpl_heap_entry, AUTOMATIC) proc = READY_LIST(ready_list)[1];

  /*
   * Put the last element in front
   */
  READY_LIST(ready_list)[index] = READY_LIST(ready_list)[size];

  /*
   * bubble down to the right place
   */
  tpl_bubble_down(
    READY_LIST(ready_list),
    index
    TAIL_FOR_PRIO_ARG(tail_for_prio)
  );

  return proc;
}

#if WITH_OSAPPLICATION == YES

/**
 * @internal
 *
 * tpl_remove_proc removes all the process instances in the ready queue
 */
FUNC(void, OS_CODE) tpl_remove_proc(CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  GET_PROC_CORE_ID(proc_id, core_id)
  GET_CORE_READY_LIST(core_id, ready_list)
  GET_TAIL_FOR_PRIO(core_id, tail_for_prio)

  VAR(uint32, AUTOMATIC) index;
  VAR(uint32, AUTOMATIC) size = (uint32)READY_LIST(ready_list)[0].key;

  DOW_DO(printf("\n**** remove proc %d ****\n",proc_id);)
  DOW_DO(printrl("tpl_remove_proc - before");)


  for (index = 1; index <= size; index++)
  {
    if (READY_LIST(ready_list)[index].id == proc_id)
    {
      READY_LIST(ready_list)[index] = READY_LIST(ready_list)[size--];
      tpl_bubble_down(
        READY_LIST(ready_list),
        index
        TAIL_FOR_PRIO_ARG(tail_for_prio)
      );
    }
  }

  READY_LIST(ready_list)[0].key = size;

  DOW_DO(printrl("tpl_remove_proc - after");)
}

#endif /* WITH_OSAPPLICATION */

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_afh_ready_list.c */
