/* Byte FIFO queue implementation.
 *
 * Implements a simple byte FIFO on top of a data buffer, that lets
 * you enqueue and dequeue single bytes.
 */

#include "byte_fifo.h"

/* Empty the given byte fifo.
 *
 * Args:
 *   f: The byte fifo structure to clear.
 */
void
byte_fifo_clear(struct byte_fifo *f)
{
  f->tail = f->head = f->buffer;
  f->holding = 0;
}


/* Initialize the given byte fifo structure.
 *
 * The given buffer space will be assigned to the byte fifo, and
 * should not be manipulated directly after the initialization of the
 * fifo.
 *
 * Args:
 *   f: The byte fifo structure to initialize.
 *   buffer: A pointer to the buffer the fifo should use.
 *   buffer_size: The length of the buffer in bytes.
 */
void
byte_fifo_init(struct byte_fifo *f, U8 *buffer, U32 buffer_size)
{
  f->buffer = buffer;
  f->buffer_size = buffer_size;
  f->buffer_end = buffer + buffer_size;
  byte_fifo_clear(f);
}


/* Enqueue a byte in the given byte fifo.
 *
 * If the byte fifo is full, the operation will fail. If force is
 * specified, then the oldest data in the fifo will be overwritten.
 *
 * Note that the fifo is not thread-safe when write force is used. If
 * you force overwrite, the same task should do both writes and reads,
 * or the fifo should be accessed with interrupts disabled.
 *
 * Args:
 *   f: The byte fifo that is to receive the byte.
 *   force: 0 if the operation should fail if the fifo is full,
 *          non-zero if it should overwrite the oldest data in the
 *          fifo.
 *   b: The byte that the fifo is to enqueue.
 *
 * Returns: 0 if the fifo was full and could not receive the byte, 1
 *          otherwise.
 */
int
byte_fifo_put(struct byte_fifo *f, U32 force, U8 b)
{
  /* If the fifo is full, only proceed if the operation was
   * forced. Otherwise, fail now.
   */
  if (f->holding >= f->buffer_size && !force)
    return 0;

  /* Enqueue the byte and advance the fifo head. */
  *(f->head) = b;
  f->holding++;
  f->head++;
  if (f->head >= f->buffer_end)
    f->head = f->buffer;

  /* If the operation was forced and overwrote old data, the tail
   * needs to be moved as well.
   */
  if (f->tail == f->head) {
    f->holding--;
    f->tail++;
    if (f->tail >= f->buffer_end)
      f->tail = f->buffer;
  }

  return 1;
}


/* Dequeue a byte from the given byte fifo.
 *
 * Args:
 *   f: The byte fifo that is to receive the byte.
 *   b: A pointer to the memory location where the dequeued byte
 *   should be stored.
 *
 * Returns: 0 if the fifo was empty and no byte could be dequeued, 1
 *          otherwise.
 */
int
byte_fifo_get(struct byte_fifo *f, U8 *b)
{
  /* Fail if the fifo is empty. */
  if (!f->holding)
    return 0;

  /* Dequeue a byte and advance the tail. */
  *b = *(f->tail);
  f->holding--;
  f->tail++;
  if (f->tail >= f->buffer_end)
    f->tail = f->buffer;

  return 1;
}
