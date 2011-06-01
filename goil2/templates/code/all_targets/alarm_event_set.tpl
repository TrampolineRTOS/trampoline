/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
 
tpl_setevent_action set_event_of_$ALARM_NAME$ = {
  {
    /* action function  */    tpl_action_setevent
  },
  /* task id              */  $TASK$,
  /* event mask           */  $EVENT$
};

tpl_alarm_static stat_$ALARM$ = {
  {
    /* pointer to counter           */  &$COUNTER$,
    /* pointer to the expiration    */  tpl_raise_alarm
#if (WITH_TRACE == YES)
    /* id of the alarm for tracing  */  , $ALARM_NAME$_id
#endif
#ifdef WITH_OSAPPLICATION
    /* OS application id            */  , $APP_ID$
#endif
  },
  /* action of the alarm  */  (tpl_action *)&set_event_of_$ALARM_NAME$
};

tpl_time_obj $ALARM$ = {
  /* pointer to the static part   */  (tpl_time_obj_static *)&stat_$ALARM$,
  /* next alarm                   */  NULL,
  /* prev alarm                   */  NULL,
  /* cycle                        */  $ALARM_CYCLE$,
  /* date                         */  $ALARM_DATE$,
  /* State of the alarm           */  $ALARM_STATE$
};
