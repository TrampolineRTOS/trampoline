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

/*
 * tpl_receive_static_internal_unqueued_message
 */
tpl_status tpl_receive_static_external_unqueued_message(
  void          *rmo,
  tpl_com_data  *data)
{
  /*  cast the base receiving mo to the correct type of mo                */
  tpl_external_receiving_unqueued_mo *rum = rmo;
  /*  get the destination buffer                                          */
  tpl_com_data *mo_buf = rum->buffer.buffer;
  /*  get the size of the buffer                                          */
  int size = rum->buffer.size;
  
  /*  reception filtering                                                 */
  if (tpl_filtering(mo_buf, data, size, rum->base_mo.filter)) {
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
tpl_status tpl_send_static_external_message(
  void            *smo,
  tpl_com_data    *data)
{
  /*  cast the base mo to the correct typo of mo      */
  tpl_external_sending_static_mo *esmo = smo;

  tpl_com_data *buf = esmo->net_mess->buffer;
  tpl_message_size size = esmo->net_mess->size;
  
  while (size--)
  {
    *buf++ = *data++;
  }
  
  /*  Sending of message to the network should occur here */
  
}
