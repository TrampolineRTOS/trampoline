/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
extern $TASK_NAME$ ;
extern $COUNTER_NAME$ ;

tpl_alarm $ALARM_NAME$ = {
    /* State of the alarm   */  $ALARM_STATE$,
    /* kind of the alarm    */  ALARM_TASK_ACTIVATION,
                                {
    /* action of the alarm  */      {
                                        (tpl_callback_func)&$TASK_NAME$
                                    },
    /* event if necessary   */      0
                                },
    /* pointer to counter   */  &$COUNTER_NAME$,
    /* cycle                */  $ALARM_CYCLE$,
    /* date                 */  $ALARM_DATE$,
    /* next alarm           */  NULL,
    /* prev alarm           */  NULL
};
