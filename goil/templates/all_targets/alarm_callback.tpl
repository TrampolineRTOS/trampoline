/*
 * Alarm descriptor of alarm $ALARM_NAME$
 */
extern void $ALARM_CALLBACK$(void);

tpl_callback_action callback_action_of_$ALARM_NAME$ = {
  {
    /* action function  */    tpl_action_callback
  },
  /* callback function    */  $ALARM_CALLBACK$
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
  /* action of the alarm  */  (tpl_action *)&callback_action_of_$ALARM_NAME$
};

tpl_time_obj $ALARM$ = {
  /* pointer to the static part   */  (tpl_time_obj_static *)&stat_$ALARM$,
  /* next alarm                   */  NULL_PTR,
  /* prev alarm                   */  NULL_PTR,
  /* cycle                        */  $ALARM_CYCLE$,
  /* date                         */  $ALARM_DATE$,
  /* State of the alarm           */  $ALARM_STATE$
};
