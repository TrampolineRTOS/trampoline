#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * ISR $EXEC_NAME$ function prototype
 */
void $EXEC_FUNCTION$(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
$TIMING_PROT_STRUCT$
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
#endif


#define OS_START_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Static descriptor of ISR $EXEC_NAME$
 */
CONST(tpl_exec_static, OS_CONST) $EXEC_STATIC$ = {
    /* context                  */ $EXEC_CONTEXT$,
    /* stack                    */ $EXEC_STACK$,
    /* entry point (function)   */ $EXEC_FUNCTION$,
    /* internal ressource       */ NULL_PTR,
    /* isr id                   */ 0,
    /* isr base priority        */ (tpl_priority)$ISR_PRIORITY$,
    /* max activation count     */ $ISR_MAX_ACT_COUNT$,
    /* isr type                 */ IS_ROUTINE,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  $TIMING_PROT_REF$
#endif
};

#define OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_isr_static $ISR_HELPER$ = {
  /* helper */ NULL_PTR,
  /* next */   NULL_PTR
};

/*
 * Dynamic descriptor of ISR $EXEC_NAME$
 */
tpl_isr $ISR$ = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &$EXEC_STATIC$,
    /* resources            */  NULL_PTR,
    /* activate count       */  0,
    /* isr priority         */  (tpl_priority)$ISR_PRIORITY$,
    /* isr state            */  SUSPENDED,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* start date           */  0,
    /* time left            */  0,
#endif
    },    /* end of exec_desc part */
    /* more static desc     */  &$ISR_HELPER$
#ifdef WITH_AUTOSAR
    ,
    /* enabled field        */  (tpl_isr2_enable_state)ENABLED
#endif
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"