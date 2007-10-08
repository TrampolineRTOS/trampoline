/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
tpl_increment_counter_action $ALARM_NAME$_counter_inc = {
    {
        /* action function      */  tpl_action_increment_counter
    },
    /* counter descriptor ptr   */  &$TARGET_COUNTER$
};

tpl_alarm_static stat_$ALARM$ = {
    {
        /* pointer to counter           */  &$COUNTER$,
        /* pointer to the expiration    */  tpl_raise_alarm
    },
    /* action of the alarm  */  (tpl_action *)&$ALARM_NAME$_counter_inc
};

tpl_time_obj $ALARM$ = {
    /* pointer to the static part   */  (tpl_time_obj_static *)&stat_$ALARM$,
    /* next alarm                   */  NULL,
    /* prev alarm                   */  NULL,
    /* cycle                        */  $ALARM_CYCLE$,
    /* date                         */  $ALARM_DATE$,
    /* State of the alarm           */  $ALARM_STATE$
};
