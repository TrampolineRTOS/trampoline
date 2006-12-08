/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline external communication functions
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_com_internal_private_types.h"

/*
 * tpl_send_static_external_message sends a message from an external only
 * sending message object to an IPDU.
 * This function is attached to the sending message object.
 */
void tpl_send_static_external_message(tpl_base_sending_mo *smo, tpl_com_data *data)
{
    /*  filter the message                                                      */
    if (tpl_filtering(smo, data)) {
        /*  cast the base mo to the correct typo of mo                          */
        tpl_external_sending_mo *esmo = (tpl_external_sending_mo *)smo;
        /*  get the target ipdu                                                 */
        tpl_sending_ipdu *ipdu = esmo->external_target;
    }
}
