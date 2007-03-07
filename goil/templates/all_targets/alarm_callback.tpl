/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
extern void $ALARM_CALLBACK$(void);

tpl_callback_action callback_action_of_$ALARM_NAME$ = {
    {
        /* action function  */  tpl_action_callback
    },
    /* callback function    */  $ALARM_CALLBACK$
};

tpl_alarm $ALARM$ = {
    /* State of the alarm   */  $ALARM_STATE$,
    /* action of the alarm  */  (tpl_action *)&callback_action_of_$ALARM_NAME$,
    /* pointer to counter   */  &$COUNTER$,
    /* cycle                */  $ALARM_CYCLE$,
    /* date                 */  $ALARM_DATE$,
    /* next alarm           */  NULL,
    /* prev alarm           */  NULL
};
