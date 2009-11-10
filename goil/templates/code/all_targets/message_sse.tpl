/*
 * Static external sending message object $MESSAGE_NAME$
 */

$CTYPE$ $BUFFER$$INITIALVALUE$;

tpl_external_sending_static_mo $MESSAGE$ = {
  {   /* base message object      */
  /* sending function             */ tpl_send_static_external_message
  },
  /* network message              */ &$NETWORKMESSAGE$
};
