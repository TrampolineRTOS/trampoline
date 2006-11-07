/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
void $ALARM_CALLBACK$();
extern $COUNTER_NAME$;

tpl_alarm $ALARM_NAME$ = {
    /* State of the alarm   */  $ALARM_STATE$,
    /* kind of the alarm    */  ALARM_CALLBACK,
                                {
    /* action of the alarm  */      {
                                        $ALARM_CALLBACK$
                                    },
    /* event if necessary   */      0
                                },
    /* pointer to counter   */  &$COUNTER_NAME$,
    /* cycle                */  $ALARM_CYCLE$,
    /* date                 */  $ALARM_DATE$,
    /* next alarm           */  NULL,
    /* prev alarm           */  NULL
};
