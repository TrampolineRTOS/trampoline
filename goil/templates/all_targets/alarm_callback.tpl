/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
void $ALARM_CALLBACK$(void);
 
tpl_alarm $ALARM$ = {
    /* State of the alarm   */  $ALARM_STATE$,
    /* kind of the alarm    */  ALARM_CALLBACK,
                                {
    /* action of the alarm  */      {
                                        $ALARM_CALLBACK$
                                    },
    /* event if necessary   */      (tpl_event_mask)0
                                },
    /* pointer to counter   */  &$COUNTER$,
    /* cycle                */  $ALARM_CYCLE$,
    /* date                 */  $ALARM_DATE$,
    /* next alarm           */  NULL,
    /* prev alarm           */  NULL
};
