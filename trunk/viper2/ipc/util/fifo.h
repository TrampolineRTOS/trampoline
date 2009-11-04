#ifndef __FIFO_H__
#define __FIFO_H__

#include <stdbool.h> /* bool */

#include "../consts.h"

/**
 * Structure,
 *  Fifo of the shared memory
 */
typedef struct st_fifo
{
  modified_reg_t cell[FIFO_SIZE];

  unsigned int size;
  unsigned int end; /* Index to the last cell */
  unsigned int begin; /* Index to the first cell */
}fifo_t;

/**
 * Create and initialize a fifo container
 *  Should be freed
 */
fifo_t *create_fifo();

/**
 * Init fifo container
 */
void fifo_init(fifo_t *fifo);

/**
 * Add a cell to a fifo. Fifo should not be full.
 * @param modified_reg modified_reg_t structure to add in FIFO
 */
void fifo_push(fifo_t *fifo, modified_reg_t *modified_reg);

/**
 * Delete and return a cell from a fifo
 * @return cell in copy mode because value can be overlap just after (process)
 */
modified_reg_t fifo_pop(fifo_t *fifo);

/**
 * @return true when fifo container is full
 */
bool is_full(fifo_t *fifo);

#endif /* __FIFO_H__ */
