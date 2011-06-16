/*
 * Static internal sending message object $MESSAGE_NAME$
 */

tpl_internal_sending_mo $MESSAGE$ = {
    {   /* base message object      */
    /* sending function             */ tpl_send_static_internal_message
    },
    /* pointer to the receiving mo  */ (tpl_base_receiving_mo *)&$TARGET$
};
