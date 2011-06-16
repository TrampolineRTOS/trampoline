/*
 * Increment counter notification $NOTIFICATION_NAME$
 */

tpl_increment_counter_action $NOTIFICATION$ = {
    {
    /*  notification function       */  tpl_action_increment_counter
    },
    /*  counter descriptor pointer     */  &$COUNTER$,
};
