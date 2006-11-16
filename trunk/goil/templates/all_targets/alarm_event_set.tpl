/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
extern $TASK$;
extern $COUNTER$;

tpl_alarm $ALARM$ = {
    /* State of the alarm   */  $ALARM_STATE$,
    /* kind of the alarm    */  ALARM_EVENT_SETTING,
                                {
    /* action of the alarm  */      {
                                        (tpl_callback_func)&$TASK$
                                    },
    /* event if necessary   */      $EVENT$
                                },
    /* pointer to counter   */  &$COUNTER$,
    /* cycle                */  $ALARM_CYCLE$,
    /* date                 */  $ALARM_DATE$,
    /* next alarm           */  NULL,
    /* prev alarm           */  NULL
};
