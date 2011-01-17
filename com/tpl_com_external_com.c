/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline external communication functions. These functions are
 * attached to the message object.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */


#include "tpl_com_external_com.h"
#include "tpl_os_definitions.h"
#include "tpl_com_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * tpl_receive_static_internal_unqueued_message
 */
FUNC(tpl_status, OS_CODE) tpl_receive_static_external_unqueued_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)   rmo,
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR)  data)
{
  /*  cast the base receiving mo to the correct type of mo                */
  CONSTP2CONST(tpl_external_receiving_unqueued_mo, AUTOMATIC, OS_CONST)
  rum = rmo;
  /*  get the destination buffer                                          */
  P2VAR(tpl_com_data, AUTOMATIC, OS_VAR)
  mo_buf = rum->buffer.buffer;
  /*  get the size of the buffer                                          */
  VAR(int, AUTOMATIC)
  size = rum->buffer.size;
  
  /*  reception filtering                                                 */
  if (tpl_filtering(mo_buf, data, rum->base_mo.filter)) {
    /*  copy the data from the source (data)
        to the message object buffer
    */
    while (size-- > 0) {
      *mo_buf++ = *data++;
    }
  }
  
  return E_OK;
}

/*
 * tpl_send_static_external_message sends a message from an external only
 * sending message object to an IPDU (not yet :)).
 * This function is attached to the sending message object.
 */
FUNC(tpl_status, OS_CODE) tpl_send_static_external_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)   smo,
  P2VAR(tpl_com_data, AUTOMATIC, OS_VAR)    data)
{
  /*  cast the base mo to the correct typo of mo      */
  CONSTP2CONST(tpl_external_sending_static_mo, AUTOMATIC, OS_CONST)
  esmo = smo;

  P2VAR(tpl_com_data, AUTOMATIC, OS_VAR)
  buf = esmo->net_mess->buffer;
  
  VAR(tpl_message_size, AUTOMATIC)
  size = esmo->net_mess->size;
  
  while (size--)
  {
    *buf++ = *data++;
  }
  
  /*  Sending of message to the network should occur here */
	return E_OK;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_com_external_com.c */
