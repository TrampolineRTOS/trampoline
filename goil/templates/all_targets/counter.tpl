/*
 * Counter descriptor of counter $COUNTER_NAME$
 */
tpl_counter $COUNTER$ = {
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

