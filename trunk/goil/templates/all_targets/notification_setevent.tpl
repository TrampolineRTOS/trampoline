/*
 * Task activation notification $NOTIFICATION_NAME$
 */

tpl_setevent_notification $NOTIFICATION$ = {
    {
    /*  notification function       */  tpl_notify_setevent
    },
    /*  task descriptor pointer     */  &$TASK$,
    /*  event mask                  */  $EVENT$
};
