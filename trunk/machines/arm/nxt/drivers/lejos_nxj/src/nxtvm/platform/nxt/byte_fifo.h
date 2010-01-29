/* Byte FIFO queue implementation.
 *
 * Implements a simple byte FIFO on top of a data buffer, that lets
 * you enqueue and dequeue single bytes.
 */

#ifndef __BFIFO_H__
#  define __BFIFO_H__

#  include "mytypes.h"

/* The byte fifo control structure. */
struct byte_fifo {
  /* The buffer containing the fifo. */
  U8 *buffer;
  /* Pointer to the end of the buffer. */
  U8 *buffer_end;
  /* Size in bytes of the buffer. */
  U32 buffer_size;

  /* Current head (freshest data) of the fifo in the buffer. */
  U8 *head;
  /* Current tail (oldest data) of the fifo in the buffer. */
  U8 *tail;
  /* Number of bytes currently enqueued in the fifo. */
  U32 holding;
};

void byte_fifo_clear(struct byte_fifo *f);
void byte_fifo_init(struct byte_fifo *f, U8 *buffer, U32 buff_size);
int byte_fifo_put(struct byte_fifo *f, U32 force, U8 b);
int byte_fifo_get(struct byte_fifo *f, U8 *b);

#endif
