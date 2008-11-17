/*
 * Task activation notification $NOTIFICATION_NAME$
 */

tpl_setevent_action $NOTIFICATION$ = {
    {
    /*  notification function       */  tpl_action_setevent
    },
    /*  task descriptor pointer     */  $TASK$,
    /*  event mask                  */  $EVENT$
};
