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


#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Static descriptor of ISR $EXEC_NAME$
 */
CONST(tpl_proc_static, OS_CONST) $EXEC_STATIC$ = {
    /* context                  */ $EXEC_CONTEXT$,
    /* stack                    */ $EXEC_STACK$,
    /* entry point (function)   */ $EXEC_FUNCTION$,
    /* internal ressource       */ NULL,
    /* isr id                   */ $ISR_ID$,
#ifdef WITH_OSAPPLICATION
    /* OS application id        */  $APP_ID$,
#endif
    /* isr base priority        */ (tpl_priority)$ISR_PRIORITY$,
    /* max activation count     */ $ISR_MAX_ACT_COUNT$,
    /* isr type                 */ IS_ROUTINE,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  $TIMING_PROT_REF$
#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

tpl_isr_static $ISR_HELPER$ = {
  /* helper */ NULL,
  /* next */   NULL,
  /* id */     $ISR_ID$
};

/*
 * Dynamic descriptor of ISR $EXEC_NAME$
 */
VAR(tpl_proc, OS_VAR) $ISR$ = {
    /* resources            */            NULL,
#if WITH_MEMORY_PROTECTION == YES
    /* if > 0 the process is trusted  */  $TRUSTED_COUNT$,    
#endif /* WITH_MEMORY_PROTECTION */
    /* activate count       */            0,
    /* isr priority         */            (tpl_priority)$ISR_PRIORITY$,
    /* isr state            */            SUSPENDED
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* activation allowed   */            ,TRUE
#endif
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
