/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
 
tpl_setevent_action set_event_of_$ALARM_NAME$ = {
    {
        /* action function  */  tpl_action_setevent
    },
    /* task descriptor ptr  */  &$TASK$,
    /* event mask           */  $EVENT$
};

tpl_alarm $ALARM$ = {
    /* State of the alarm   */  $ALARM_STATE$,
    /* action of the alarm  */  (tpl_action *)&set_event_of_$ALARM_NAME$,
    /* pointer to counter   */  &$COUNTER$,
    /* cycle                */  $ALARM_CYCLE$,
    /* date                 */  $ALARM_DATE$,
    /* next alarm           */  NULL,
    /* prev alarm           */  NULL
};
