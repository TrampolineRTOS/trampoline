/*
 * Callback function call notification $NOTIFICATION_NAME$
 */
extern void $CALLBACK$(void);

tpl_callback_action $NOTIFICATION$ = {
    {
    /*  notification function       */  tpl_action_callback
    },
    /* Callback function pointer    */  $CALLBACK$
};
