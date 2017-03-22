#ifndef TPL_OS_TIME_MODEL
#define TPL_OS_TIME_MODEL

#include "tpl_compiler.h"

typedef uint8  tpl_te_model_state;
typedef uint32 tpl_te_earliest_firing_time;

typedef struct {
  CONST(tpl_te_model_state, TYPEDEF) target_state;
  CONST(tpl_te_earliest_firing_time, TYPEDEF) eft;
} tpl_te_transition;

#endif
