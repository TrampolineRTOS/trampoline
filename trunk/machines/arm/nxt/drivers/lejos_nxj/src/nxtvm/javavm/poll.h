/**
 * poll.h
 * Contains conterparts of special classes as C structs.
 */
 
#ifndef _POLL_H
#define _POLL_H

#include "constants.h"
#include "classes.h"

/**
 * Poll class native structure
 */
typedef struct S_Poll
{
  Object _super;	     // Superclass object storage
  JSHORT changed;            // Mask of inputs that have changed
} Poll;

extern void set_poller(Poll*);
extern void poll_inputs();

extern Poll *poller;
extern byte throttle;
extern byte throttle_count;

static inline void init_poller()
{
  poller = (Poll *)null;
  throttle = 1;
  throttle_count = 1;
}

#endif // _POLL_H
