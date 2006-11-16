/*
 * Task $TASK_NAME$ function prototype
 */
void $TASK_FUNCTION$(void);

/*
 * Static descriptor of task $TASK_NAME$
 */
tpl_exec_static $TASK_STATIC$ = {
    /* context                  */ $TASK_CONTEXT$,
    /* stack                    */ $TASK_STACK$,
    /* entry point (function)   */ $TASK_FUNCTION$,
    /* internal ressource       */ NULL,
    /* task id                  */ $TASK_ID$,
    /* task base priority       */ (tpl_priority)$TASK_PRIORITY$,
    /* max activation count     */ $TASK_MAX_ACT_COUNT$,
    /* task type                */ EXTENDED_TASK
};

/*
 * Dynamic descriptor of task $TASK_NAME$
 */
tpl_task $TASK$ = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &$TASK_STATIC$,
    /* resources            */  NULL,
    /* next task for READY  */  NULL,
    /* next set for READY   */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)$TASK_PRIORITY$,
    /* task state           */  $TASK_STATE$,
    },    /* end of exec_desc part */
    /* event mask           */  0,
    /* event wait           */  0
};

