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
#include "tpl_com_internal_com.h"
#include "tpl_os_definitions.h"
#include "tpl_com_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * tpl_send_static_external_message sends a message from a static external 
 * sending message object to an IPDU.
 * This function is attached to the sending message object.
 */
FUNC(tpl_status, OS_CODE) tpl_send_static_external_message(
  CONSTP2CONST(void, COM_CONST, AUTOMATIC)   smo,
  P2VAR(tpl_com_data, COM_VAR, AUTOMATIC)    data)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  /* cast the base mo to the correct type of mo */
  CONSTP2CONST(tpl_external_sending_mo, COM_CONST, AUTOMATIC) esmo = smo;
  /* get the pointer to the data buffer */
  CONSTP2VAR(tpl_com_data, COM_VAR, AUTOMATIC) mo_buf = esmo->buffer.buffer;

  /* filter the message */
  if (tpl_filtering(mo_buf, data, esmo->filter))
  {
#if WITH_CPU_ORDER_CALLOUT == YES
    /* call the CPU-order message callout */
    if (COM_TRUE == esmo->base_mo.cpu_callout())
#endif
    {
      /*
       * does the byte ordering of the message or not.
       * If cpu order and network order differs, the data are ordered and
       * copied from buffer.buffer to buffer.ordered_buffer. If cpu order
       * and network order are the same, the data are simply copied from
       * buffer.buffer to buffer.ordered_buffer.
       */
      esmo->order(&(esmo->buffer));

#if WITH_NET_ORDER_CALLOUT == YES
      /* call the Network-order message callout */
      if (COM_TRUE == esmo->base_mo.net_callout())
#endif
      {

        /* copy & pack the message object in the IPDU */
        esmo->copy_and_pack(esmo);
        /*
         * notify the IPDU. According to the message property and
         * the transfer property, this may trigger the sending of
         * the IPDU to the network.
         */
        tpl_notify_ipdu(esmo->base_mo.property);

      }
    }
  }
  /*
   * if at least an internal target exists,
   * the tpl_send_static_internal_message function is called
   */
  if (NULL != esmo->base_mo.internal.internal_target)
  {
    result = tpl_send_static_internal_message(smo, data);
  }
	return result;
}

/*
 * tpl_send_zero_external_message sends a zero size message from a zero 
 * external sending message object to an IPDU.
 * This function is attached to the sending message object.
 */
FUNC(tpl_status, OS_CODE) tpl_send_zero_external_message(
  CONSTP2CONST(void, AUTOMATIC, OS_CONST)   smo,
  P2VAR(tpl_com_data, AUTOMATIC, OS_VAR)    data)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  /* cast the base mo to the correct type of mo */
  CONSTP2CONST(tpl_external_sending_zero_mo, AUTOMATIC, OS_CONST) esmo = smo;

#if WITH_CPU_ORDER_CALLOUT == YES
    /* call the CPU-order message callout */
    if (COM_TRUE == esmo->cpu_callout())
#endif
    {
#if WITH_NET_ORDER_CALLOUT == YES
      /* call the Network-order message callout */
      if (COM_TRUE == esmo->net_callout())
#endif
      {
        /*
         * notify the IPDU. According to the message property and
         * the transfer property, this may trigger the sending of
         * the IPDU to the network.
         */
        tpl_notify_ipdu(esmo->property);
      }
    }
  /*
   * if at least an internal target exists, the tpl_send_zero_internal_message
   * function is called
   */
  if (NULL != esmo->internal.internal_target)
  {
    result = tpl_send_zero_internal_message(smo, data);
  }
	return result;
}

FUNC(void, COM_CODE) tpl_notify_ipdu(
  CONST(tpl_message_property, AUTOMATIC) property)
{
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_com_external_com.c */
