
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Task $EXEC_NAME$ function prototype
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
 * Static descriptor of task $EXEC_NAME$
 */
CONST(tpl_exec_static, OS_CONST) $EXEC_STATIC$ = {
    /* context                  */  $EXEC_CONTEXT$,
    /* stack                    */  $EXEC_STACK$,
    /* entry point (function)   */  $EXEC_FUNCTION$,
    /* internal ressource       */  $RESOURCE_PTR$,
    /* task id                  */  $TASK_ID$,
    /* task base priority       */  (tpl_priority)$TASK_PRIORITY$,
    /* max activation count     */  $TASK_MAX_ACT_COUNT$,
    /* task type                */  $TASK_TYPE$,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* pointer to the timing
       protection descriptor    */  $TIMING_PROT_REF$
#endif
};

#define OS_STOP_SEC_CONFIGDATA_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task $EXEC_NAME$
 */
tpl_task $TASK$ = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &$EXEC_STATIC$,
    /* resources            */  NULL_PTR,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)$TASK_PRIORITY$,
    /* task state           */  $TASK_STATE$,
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    /* activation allowed   */  TRUE,
#endif
    },    /* end of exec_desc part */
    /* event mask           */  0,
    /* event wait           */  0
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"