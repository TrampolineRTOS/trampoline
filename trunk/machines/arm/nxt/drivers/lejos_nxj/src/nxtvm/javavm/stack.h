
#include "configure.h"
#include "threads.h"
#include "interpreter.h"
#include "memory.h"
#include "language.h"

#ifndef _STACK_H
#define _STACK_H

#define get_local_word(IDX_)       (localsBase[(IDX_)])
#define get_local_ref(IDX_)        (localsBase[(IDX_)])
#define inc_local_word(IDX_,NUM_)  (localsBase[(IDX_)] += (NUM_))
#define just_set_top_word(WRD_)    (stackTop[0] = (WRD_))
#define get_top_word()             (stackTop[0])
#define get_top_ref()              (stackTop[0])
#define get_word_at(DOWN_)         (*(stackTop-(DOWN_)))
#define get_ref_at(DOWN_)          *(stackTop-(DOWN_))
#define get_stack_ptr()            (stackTop)
#define get_stack_ptr_at(DOWN_)    (stackTop-(DOWN_))

// Note: The following locals should only be accessed
// in this header file.

extern STACKWORD *localsBase;
extern STACKWORD *stackTop;

/**
 * Clears the operand stack for the given stack frame.
 */
static inline void init_sp (StackFrame *stackFrame, MethodRecord *methodRecord)
{
  stackTop = stackFrame->localsBase + methodRecord->numLocals - 1;
}

/**
 * Clears/initializes the operand stack at the bottom-most stack frame,
 * and pushes a void (unitialized) element, which should be overriden
 * immediately with set_top_word or set_top_ref.
 */
static inline void init_sp_pv (void)
{
  stackTop = stack_array();
}

/**
 * With stack cleared, checks for stack overflow in given method.
 */
static inline boolean is_stack_overflow (MethodRecord *methodRecord)
{
  return (stackTop + methodRecord->maxOperands) >= (stack_array() + get_array_length((Object *) word2ptr (currentThread->stackArray)));
}

extern void update_stack_frame (StackFrame *stackFrame);

extern void update_registers (StackFrame *stackFrame);

/**--**/

static inline void update_constant_registers (StackFrame *stackFrame)
{
  localsBase = stackFrame->localsBase;
}

static inline void push_word (const STACKWORD word)
{
  *(++stackTop) = word;
}

static inline void push_ref (const REFERENCE word)
{
  *(++stackTop) = word;
}

static inline STACKWORD pop_word (void)
{
  return *stackTop--;
}

static inline REFERENCE pop_ref (void)
{
  return *stackTop--;
}

static inline JINT pop_jint (void)
{
  return word2jint(*stackTop--);
}

static inline STACKWORD pop_word_or_ref()
{
  return *stackTop--;
}

static inline void pop_jlong (JLONG *lword)
{
  lword->lo = *stackTop--;
  lword->hi = *stackTop--;
}

static inline void pop_words (byte aNum)
{
  stackTop -= aNum;
}

static inline void just_pop_word (void)
{
  --stackTop;
}

static inline void just_pop_ref (void)
{
  --stackTop;
}

static inline void push_void (void)
{
  ++stackTop;
}

static inline void set_top_ref (REFERENCE aRef)
{
  *stackTop = aRef;
}

static inline void set_top_word (STACKWORD aWord)
{
  *stackTop = aWord;
}

static inline void dup (void)
{
  stackTop++;
  *stackTop = *(stackTop-1);
}

static inline void dup2 (void)
{
  *(stackTop+1) = *(stackTop-1);
  *(stackTop+2) = *stackTop;
  stackTop += 2;
}

static inline void dup_x1 (void)
{
  stackTop++;
  *stackTop = *(stackTop-1);
  *(stackTop-1) = *(stackTop-2);
  *(stackTop-2) = *stackTop;
}

static inline void dup2_x1 (void)
{
  stackTop += 2;
  *stackTop = *(stackTop-2);
  *(stackTop-1) = *(stackTop-3);
  *(stackTop-2) = *(stackTop-4);
  *(stackTop-3) = *stackTop;
  *(stackTop-4) = *(stackTop-1);
}

static inline void dup_x2 (void)
{
  stackTop++;
  *stackTop = *(stackTop-1);
  *(stackTop-1) = *(stackTop-2);
  *(stackTop-2) = *(stackTop-3);
  *(stackTop-3) = *stackTop;
}

static inline void dup2_x2 (void)
{
  stackTop += 2;
  *stackTop = *(stackTop-2);
  *(stackTop-1) = *(stackTop-3);
  *(stackTop-2) = *(stackTop-4);
  *(stackTop-3) = *(stackTop-5);
  *(stackTop-4) = *stackTop;
  *(stackTop-5) = *(stackTop-1);
}

static inline void swap (void)
{
  tempStackWord = *stackTop;
  *stackTop = *(stackTop-1);
  *(stackTop-1) = tempStackWord;
}

static inline void set_local_word (byte aIndex, STACKWORD aWord)
{
  localsBase[aIndex] = aWord;
}

static inline void set_local_ref (byte aIndex, REFERENCE aWord)
{
  localsBase[aIndex] = aWord;
}

#endif

