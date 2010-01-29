
#include "types.h"
#include "constants.h"
#include "classes.h"

#ifndef _INTERPRETER_H
#define _INTERPRETER_H

#define REQUEST_TICK          0
#define REQUEST_SWITCH_THREAD 1
#define REQUEST_EXIT          2

extern volatile boolean gMakeRequest;
extern byte    gRequestCode;

extern byte *pc;
extern STACKWORD *stackTop;
extern STACKWORD *localsBase;

// Temp globals:

extern byte tempByte;
extern STACKWORD tempStackWord;

extern void engine();

static inline void schedule_request (const byte aCode)
{
  gMakeRequest = true;
  gRequestCode = aCode;
}

#endif /* _INTERPRETER_H */





