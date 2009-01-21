/*
 * network message $NAME$
 */

$CTYPE$ $NAME$_buffer$INITIALVALUE$;

tpl_sending_network_message $NAME$_net_message = {
  /* size of the datatype   */  sizeof($CTYPE$),
  /* pointer to the buffer  */  &$NAME$_buffer
};
