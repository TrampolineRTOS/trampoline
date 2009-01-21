/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protege par la loi sur la propriete intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline external communication functions
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */
 
#ifndef TPL_COM_EXTERNAL_COM
#define TPL_COM_EXTERNAL_COM

#include "tpl_com_mo.h"

tpl_status tpl_receive_static_external_unqueued_message(
    void*         rmo,
    tpl_com_data* date);

tpl_status tpl_send_static_external_message(
    void            *smo,
    tpl_com_data    *data);

#endif
/* TPL_COM_EXTERNAL_COM */
