/**
 * @file tpl_afh_ready_list.c
 *
 * @section descr File description
 *
 * Trampoline array of fifo indexed by priority and highest priority stored
 * in a heap hybrid system.
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

#include "tpl_ready_list.h"
#include "tpl_afh_ready_list.h"
#include "tpl_os_kernel.h"
#include "tpl_dow.h"

/**
 * @internal
 *
 * external declaration of the ready list which is instancied in
 * tpl_app_config.c generated file.
 */
#if NUMBER_OF_CORES > 1

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
extern VAR(tpl_array_fifo_heap, OS_VAR) tpl_ready_list[];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#else

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
extern VAR(tpl_array_fifo_heap, OS_VAR) tpl_ready_list;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#endif

#ifdef WITH_DOW

FUNC(void, OS_CODE) printrl(CONSTP2CONST(char, AUTOMATIC, OS_CONST) message)
{
  printf("from %s\n", message);
#if NUMBER_OF_CORES > 1
  VAR(int, AUTOMATIC) core;
  for (core = 0; core < NUMBER_OF_CORES; core++) {
    printf("core %d:\n", core);
    printf("  heap: (");
    VAR(tpl_priority_index, AUTOMATIC) pindex;
    for (pindex = 1; pindex <= tpl_ready_list[core].heap[0]; pindex++) {
      printf("%d ", tpl_ready_list[core].heap[pindex]);
    }
    printf(")\n");
    if (tpl_ready_list[core].heap[0]) > 0 {
      VAR(tpl_priority, AUTOMATIC) priority;
      for (priority = 0; priority <= tpl_ready_list[core].heap[1]; priority++) {
        CONSTP2VAR(tpl_proc_fifo, AUTOMATIC) fifo = &(tpl_ready_list[core].fifos[priority]);
        printf("  %d-[%d/%d,%d](", priority, fifo->actual_size, fifo->full_size, fifo->front_index);
        VAR(tpl_index, AUTOMATIC) proc_index = fifo->front_index;
        VAR(tpl_index, AUTOMATIC) proc_count;
        for (proc_count = 0; proc_count < fifo->actual_size; proc_count++) {
          printf("%d", fifo->buffer[proc_index++]);
          if (proc_index >= fifo->full_size) {
            proc_index = 0;
          }
        }
        prinf(")\n");
      }
    }
  }
#else
  printf("heap: (");
  VAR(tpl_priority_index, AUTOMATIC) pindex;
  for (pindex = 1; pindex <= tpl_ready_list.heap[0]; pindex++) {
    printf("%d ", tpl_ready_list.heap[pindex]);
  }
  printf(")\n");
  if (tpl_ready_list.heap[0] > 0) {
    VAR(tpl_priority, AUTOMATIC) priority;
    for (priority = 0; priority < NUMBER_OF_PRIORITY_LEVELS; priority++) {
      CONSTP2VAR(tpl_proc_fifo, AUTOMATIC, OS_VAR) fifo = &(tpl_ready_list.fifos[priority]);
      printf("%d-[%lu/%lu,%lu](", priority, fifo->actual_size, fifo->full_size, fifo->front_index);
      VAR(tpl_index, AUTOMATIC) proc_index = fifo->front_index;
      VAR(tpl_index, AUTOMATIC) proc_count;
      for (proc_count = 0; proc_count < fifo->actual_size; proc_count++) {
        printf("%d", fifo->buffer[proc_index++]);
        if (proc_index >= fifo->full_size) {
          proc_index = 0;
        }
      }
      printf(")\n");
    }
  }
#endif
}

#endif

/**
 * @internal
 *
 * tpl_add_prio adds a new priority to a priority heap
 */
FUNC(void, OS_CODE) tpl_add_prio(
  CONSTP2VAR(tpl_priority, AUTOMATIC, OS_VAR) heap,
  CONST(tpl_priority, AUTOMATIC) priority)
{
  /*
   * tpl_priority_index is always bigger or equal to tpl_priority datatype.
   * Both are unsigned.
   */
  VAR(tpl_priority_index, AUTOMATIC) child = (tpl_priority_index)(++heap[0]);
  VAR(tpl_priority_index, AUTOMATIC) father = child / 2;

  /* Add the new priority to the heap */
  heap[child] = priority;
  /* And bubble it up */
  while (child > 1) {
    if (heap[child] > heap[father]) {
      CONST(tpl_priority, AUTOMATIC) tmp = heap[child];
      heap[child] = heap[father];
      heap[father] = tmp;
      child = father;
      father /= 2;
    }
    else {
      break;
    }
  }
}

/**
 * @internal
 *
 * tpl_remove_priority removes the highest priority
 */
 FUNC(void, OS_CODE) tpl_remove_highest_prio(
   CONSTP2VAR(tpl_priority, AUTOMATIC, OS_VAR) heap)
{
  if (heap[0] > 0) {
    if (heap[0] > 1) {
      /* copy the last element of the heap into the first */
      heap[1] = heap[heap[0]];
      /* and bubble it down to its location */
      VAR(tpl_priority_index, AUTOMATIC) size = heap[0] - 1;
      VAR(tpl_priority_index, AUTOMATIC) father = 1;
      VAR(tpl_priority_index, AUTOMATIC) child = father * 2;
      while (child <= size) {
        VAR(tpl_priority_index, AUTOMATIC) right_child = child + 1;
        if (right_child <= size && heap[right_child] > heap[child]) {
          /* The right child exists and is greater, go in this branch */
          child = right_child;
        }
        if (heap[child] > heap[father]) {
          /* child has a higher priority, swap them */
          CONST(tpl_priority, AUTOMATIC) tmp = heap[father];
          heap[father] = heap[child];
          heap[child] = tmp;
          /* and go down */
        }
        else {
          break;
        }
      }
    }
    heap[0]--;
  }
}

/**
 * @internal
 *
 * tpl_highest_ready_prio returns the priority of the highest priority task
 * in the ready list
 */
FUNC(tpl_priority, OS_CODE) tpl_highest_ready_prio(CORE_ID_OR_VOID(core_id))
{
  /* Get a pointer to the ready list of the core */
  GET_CORE_READY_LIST(core_id, ready_list)

  if (ready_list->heap[0] > 0) {
    return ready_list->heap[1];
  }
  else {
    return -1;
  }
}

/**
 * @internal
 *
 * tpl_put_new_proc puts a new proc in a ready list. In a multicore kernel
 * it may be called from a core that does not own the ready list (for
 * a partitioned scheduler). So the core_id field of the proc descriptor
 * is used to get the corresponding ready list.
 */
FUNC(void, OS_CODE) tpl_put_new_proc(CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  /* Get the core_id to which the process belongs to */
  GET_PROC_CORE_ID(proc_id, core_id)
  /* Get a pointer to the ready list of the core */
  GET_CORE_READY_LIST(core_id, ready_list)
  /* Get the base priority of the process */
  CONST(tpl_priority, AUTOMATIC) priority =
    tpl_stat_proc_table[proc_id]->base_priority;
  /* Get the fifo corresponding to the priority */
  CONSTP2VAR(tpl_proc_fifo, AUTOMATIC, OS_VAR) fifo = &(ready_list->fifos[priority]);

  /* Check whether the slot of the process priority is empty */
  if (fifo->actual_size == 0) {
    /* to add the priority to the heap */
    tpl_add_prio(ready_list->heap, priority);
  }

  /* Add the new process to the end of the fifo */
  VAR(tpl_index, AUTOMATIC) index = fifo->front_index + fifo->actual_size;
  if (index > fifo->full_size) {
    index -= fifo->full_size;
  }
  fifo->buffer[index] = proc_id;
  fifo->actual_size++;

  DOW_DO(printrl("put_new_proc");)
}

/**
 * @internal
 *
 * tpl_put_prempted_proc puts a preempted proc in a ready list.
 * In a multicore kernel it may be called from a core that does not own the
 * ready list (for a partitioned scheduler). So the core_id field of the proc
 * descriptor is used to get the corresponding ready list.
 */
FUNC(void, OS_CODE) tpl_put_preempted_proc(CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  /* Get the core_id to which the process belongs to */
  GET_PROC_CORE_ID(proc_id, core_id)
  /* Get a pointer to the ready list of the core */
  GET_CORE_READY_LIST(core_id, ready_list)
  /* Get the base priority of the process */
  CONST(tpl_priority, AUTOMATIC) priority =
    tpl_dyn_proc_table[proc_id]->priority;
  /* Get the fifo corresponding to the priority */
  CONSTP2VAR(tpl_proc_fifo, AUTOMATIC, OS_VAR) fifo = &(ready_list->fifos[priority]);

  /* Check whether the slot of the process priority is empty */
  if (fifo->actual_size == 0) {
    /* to add the priority to the heap */
    tpl_add_prio(ready_list->heap, priority);
  }

  /* Add the new process to the front of the fifo */
  VAR(tpl_index, AUTOMATIC) index = fifo->front_index;
  if (index == 0) {
    index = fifo->full_size;
  }
  index--;
  fifo->front_index = index;
  fifo->actual_size++;
  fifo->buffer[index] = proc_id;

  DOW_DO(printrl("put_prempted_proc");)
}

/**
 * @internal
 *
 * tpl_front_proc returns the proc_id of the highest priority proc in the
 * ready list on the current core
 */
FUNC(tpl_proc_id, OS_CODE) tpl_front_proc(CORE_ID_OR_VOID(core_id))
{
  /* Get a pointer to the ready list of the core */
  GET_CORE_READY_LIST(core_id, ready_list)

  CONST(tpl_priority, AUTOMATIC) priority = ready_list->heap[1];
  CONSTP2VAR(tpl_proc_fifo, AUTOMATIC, OS_VAR) fifo = &(ready_list->fifos[priority]);

  if (fifo->actual_size > 0)
  {
    return fifo->buffer[fifo->front_index];
  }
  else {
    return INVALID_PROC_ID;
  }
}

/**
 * @internal
 *
 * tpl_remove_front_proc removes the highest priority proc from the
 * ready list of the specified core and returns proc_id
 */
FUNC(tpl_proc_id, OS_CODE) tpl_remove_front_proc(CORE_ID_OR_VOID(core_id))
{
  /* Get a pointer to the ready list of the core */
  GET_CORE_READY_LIST(core_id, ready_list)

  CONST(tpl_priority, AUTOMATIC) priority = ready_list->heap[1];
  CONSTP2VAR(tpl_proc_fifo, AUTOMATIC, OS_VAR) fifo = &(ready_list->fifos[priority]);

  if (fifo->actual_size > 0) {
    VAR(tpl_index, AUTOMATIC) index = fifo->front_index++;
    if (fifo->front_index == fifo->full_size) {
      fifo->front_index = 0;
    }
    if (--(fifo->actual_size) == 0) {
      DOW_DO(printf("Removing the highest prio from the heap\n"));
      tpl_remove_highest_prio(ready_list->heap);
    }
    DOW_DO(printrl("remove_front_proc");)
    return fifo->buffer[index];
  }
  else {
    DOW_DO(printrl("remove_front_proc");)
    return INVALID_PROC_ID;
  }
}

/**
 * @internal
 *
 * tpl_remove_proc removes all the jobs in the ready queue
 */
FUNC(void, OS_CODE) tpl_remove_proc(CONST(tpl_proc_id, AUTOMATIC) proc_id)
{
  /* Get the core_id to which the process belongs to */
  GET_PROC_CORE_ID(proc_id, core_id)
  /* Get a pointer to the ready list of the core */
  GET_CORE_READY_LIST(core_id, ready_list)
  if (ready_list->heap[0] > 0) {
    /* Get the highest priority */
    CONST(tpl_priority, AUTOMATIC) highest_prio = ready_list->heap[1];
    /* Empty the heap, il will be rebuilt */
    ready_list->heap[0] = 0;
    /*
     * loop through the fifos, priority 0 is ignored since it corresponds
     * to the idle task that is alone in its slot.
     */
    for (int priority = highest_prio; priority > 0; priority--) {
      CONSTP2VAR(tpl_proc_fifo, AUTOMATIC, OS_VAR) fifo = &(ready_list->fifos[priority]);
      /* Check if the fifo is empty */
      VAR(tpl_index, AUTOMATIC) size = fifo->actual_size;
      if (size > 0) {
        VAR(tpl_index, AUTOMATIC) r, w = 0, newsize = 0;
        for (r = 0; r < size; r++) {
          VAR(tpl_index, AUTOMATIC) read_index = fifo->front_index + r;
          if (read_index >= fifo->full_size) {
            read_index -= fifo->full_size;
          }
          if (fifo->buffer[read_index] != proc_id) {
            VAR(tpl_index, AUTOMATIC) write_index = fifo->front_index + w++;
            if (write_index >= ready_list->fifos[priority].full_size) {
              write_index -= fifo->full_size;
            }
            fifo->buffer[read_index] = fifo->buffer[write_index];
            newsize++;
          }
        }
        fifo->actual_size = newsize;
        if (newsize > 0) {
          tpl_add_prio(ready_list->heap, priority);
        }
      }
    }
  }
  DOW_DO(printrl("remove_proc");)
}
