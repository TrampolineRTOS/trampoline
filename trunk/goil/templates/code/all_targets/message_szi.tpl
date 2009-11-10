/*
 * Static internal sending zero length message object $MESSAGE_NAME$
 */

tpl_internal_sending_zero_mo $MESSAGE$ = {
    {   /* base message object      */
    /* sending function             */ tpl_send_zero_internal_message
    },
    /* pointer to the receiving mo  */ (tpl_base_receiving_mo *)&$TARGET$
};
