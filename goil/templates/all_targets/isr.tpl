/*
 * ISR $EXEC_NAME$ function prototype
 */
void $EXEC_FUNCTION$(void);

/*
 * Static descriptor of ISR $EXEC_NAME$
 */
tpl_exec_static $EXEC_STATIC$ = {
    /* context                  */ $EXEC_CONTEXT$,
    /* stack                    */ $EXEC_STACK$,
    /* entry point (function)   */ $EXEC_FUNCTION$,
    /* internal ressource       */ NULL,
    /* isr id                   */ 0,
    /* isr base priority        */ (tpl_priority)$ISR_PRIORITY$,
    /* max activation count     */ $ISR_MAX_ACT_COUNT$,
    /* isr type                 */ IS_ROUTINE
};

tpl_isr_static $ISR_HELPER$ = {
	/* helper */ NULL,
	/* next */   NULL
};

/*
 * Dynamic descriptor of ISR $EXEC_NAME$
 */
tpl_isr $ISR$ = {
    {       /* beginning of exec_desc part */
    /* static descriptor    */  &$EXEC_STATIC$,
    /* resources            */  NULL,
    /* next exec for READY  */  NULL,
    /* next set for READY   */  NULL,
    /* activate count       */  0,
    /* isr priority         */  (tpl_priority)$ISR_PRIORITY$,
    /* isr state            */  SUSPENDED,
    },    /* end of exec_desc part */
    /* more static desc     */  &$ISR_HELPER$
};

