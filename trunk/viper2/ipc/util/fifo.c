#include "fifo.h"

#include <stdio.h>
#include <stdlib.h> /* malloc() NULL */

fifo_t *create_fifo()
{
  /* Variables */
  fifo_t *fifo = NULL;

  /* Instanciation */
  fifo = (fifo_t *)malloc(sizeof(fifo_t));
  if(fifo == NULL)
  {
    perror("malloc()");
    return NULL;
  }

  fifo_init(fifo);

  return fifo;
}

void fifo_init(fifo_t *fifo)
{
  /* Initialization */
  fifo->size = 0;
  fifo->end = -1; /* First cell will be in fifo->end + 1 */
  fifo->begin = 0;
}

void fifo_push(fifo_t *fifo, modified_reg_t *modified_reg)
{
  /* End on next cell */
  fifo->end++;
  if(fifo->end == FIFO_SIZE) /* End of array */
    fifo->end = 0;

  /* Push at the end */
  fifo->cell[fifo->end] = (*modified_reg); /* Copy because modified_reg isn't necessary in the shared memory */
  fifo->size++;
}

modified_reg_t fifo_pop(fifo_t *fifo)
{
  /* Get value */ 
  modified_reg_t *modified_reg = &fifo->cell[fifo->begin];

  /* New begin */
  fifo->begin++;
  if(fifo->begin == FIFO_SIZE) /* End of array */
    fifo->begin = 0;

  fifo->size--;

  return (*modified_reg); /* ( Copy mode because it could be overlaped just after */
}

bool is_full(fifo_t *fifo)
{
  return ! fifo->size < FIFO_SIZE;
}
