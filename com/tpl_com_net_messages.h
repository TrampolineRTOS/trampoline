/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Network Messages data structures
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_COM_NET_MESSAGES_H
#define TPL_COM_NET_MESSAGES_H

struct TPL_SENDING_NETWORK_MESSAGE {
  tpl_message_size  size;
  tpl_com_data      *buffer;
};

typedef struct TPL_SENDING_NETWORK_MESSAGE tpl_sending_network_message;

#endif  /* TPL_COM_NET_MESSAGES_H */
/* End of file tpl_com_net_messages.h */
