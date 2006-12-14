/*
 * Task activation notification $NOTIFICATION_NAME$
 */

tpl_task_activation_notification $NOTIFICATION$ = {
    {
    /*  notification function       */  tpl_notify_activate_task
    },
    /*  task descriptor pointer     */  &$TASK$
};
