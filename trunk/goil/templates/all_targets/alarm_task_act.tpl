/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
tpl_task_activation_action task_act_of_$ALARM_NAME$ = {
    {
        /* action function  */  tpl_action_activate_task
    },
    /* task descriptor ptr  */  &$TASK$
};

tpl_alarm $ALARM$ = {
    /* State of the alarm   */  $ALARM_STATE$,
    /* action of the alarm  */  (tpl_action *)&task_act_of_$ALARM_NAME$,
    /* pointer to counter   */  &$COUNTER$,
    /* cycle                */  $ALARM_CYCLE$,
    /* date                 */  $ALARM_DATE$,
    /* next alarm           */  NULL,
    /* prev alarm           */  NULL
};
