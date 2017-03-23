#ifndef TPL_OS_TIME_MODEL
#define TPL_OS_TIME_MODEL

#include "tpl_compiler.h"

typedef uint8  tpl_te_model_state;
typedef uint32 tpl_te_earliest_firing_time;

typedef struct {
  CONST(uint8, TYPEDEF)                       service_id;
  CONST(tpl_te_model_state, TYPEDEF)          target_state;
  CONST(tpl_te_earliest_firing_time, TYPEDEF) eft;
} tpl_te_transition;

typedef struct {
  CONST(uint8, TYPEDEF)                       count;
  CONSTP2CONST(tpl_te_transition, TYPEDEF, OS_CONST)    transitions;
} tpl_te_outgoings;

extern CONSTP2CONST(tpl_te_outgoings, OS_CONST, OS_APPL_CONST) tpl_state_table[];
extern VAR(tpl_te_model_state, OS_APPL_DATA) tpl_te_current_state[];

#endif
