/*
 * counter $COUNTER_NAME$ descriptor
 */

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONST(tpl_tick, OS_CONST) OSTICKSPERBASE$COUNTER_SUFF$ = $TICKS_PER_BASE$;
CONST(tpl_tick, OS_CONST) OSMAXALLOWEDVALUE$COUNTER_SUFF$ = $MAX_ALLOWED_VALUE$;
CONST(tpl_tick, OS_CONST) OSMINCYCLE$COUNTER_SUFF$ = $MIN_CYCLE$;
#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_counter, OS_VAR) $COUNTER$ = {
    /* ticks per base       */  $TICKS_PER_BASE$,
    /* max allowed value    */  $MAX_ALLOWED_VALUE$,
    /* minimum cycle        */  $MIN_CYCLE$,
    /* current tick         */  0,
    /* current date         */  0,
#ifdef WITH_AUTOSAR
    /* kind the counter     */  $COUNTER_KIND$,
#endif
#ifdef WITH_OSAPPLICATION
    /* OS application id    */  $APP_ID$,
#endif
    /* first alarm          */  NULL_PTR,
    /* next alarm to raise  */  NULL_PTR
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

