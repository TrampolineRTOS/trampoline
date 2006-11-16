/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
extern $TASK$ ;
extern $COUNTER$ ;

tpl_alarm $ALARM_NAME$ = {
    /* State of the alarm   */  $ALARM_STATE$,
    /* kind of the alarm    */  ALARM_TASK_ACTIVATION,
                                {
    /* action of the alarm  */      {
                                        (tpl_callback_func)&$TASK$
                                    },
    /* event if necessary   */      0
                                },
    /* pointer to counter   */  &$COUNTER$,
    /* cycle                */  $ALARM_CYCLE$,
    /* date                 */  $ALARM_DATE$,
    /* next alarm           */  NULL,
    /* prev alarm           */  NULL
};
