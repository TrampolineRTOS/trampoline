/*
 * Task $EXEC_NAME$ function prototype
 */
void $EXEC_FUNCTION$(void);

/*
 * Static descriptor of task $EXEC_NAME$
 */
tpl_exec_static $EXEC_STATIC$ = {
    /* context                  */ $EXEC_CONTEXT$,
    /* stack                    */ $EXEC_STACK$,
    /* entry point (function)   */ $EXEC_FUNCTION$,
    /* internal ressource       */ $RESOURCE_PTR$,
    /* task id                  */ $TASK_ID$,
    /* task base priority       */ (tpl_priority)$TASK_PRIORITY$,
    /* max activation count     */ $TASK_MAX_ACT_COUNT$,
    /* task type                */ $TASK_TYPE$
};

/*
 * Dynamic descriptor of task $EXEC_NAME$
 */
tpl_task $TASK$ = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &$EXEC_STATIC$,
    /* resources            */  NULL,
    /* activate count       */  0,
    /* task priority        */  (tpl_priority)$TASK_PRIORITY$,
    /* task state           */  $TASK_STATE$,
    },    /* end of exec_desc part */
    /* event mask           */  0,
    /* event wait           */  0
};

