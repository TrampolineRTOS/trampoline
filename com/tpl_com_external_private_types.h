/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline External Communication Type
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_EXTERNAL_PRIVATE_TYPES_H__
#define __TPL_COM_EXTERNAL_PRIVATE_TYPES_H__

/*
 * tpl_external_sending_mo is external only sending message object
 */
struct TPL_EXTERNAL_SENDING_MO {
    /*  common to all sending mo            */
    tpl_base_sending_mo     base_mo;
    /*  function pointer to the filter      */
    tpl_filter_desc         filter;
    /*  pointer to the buffer               */
    tpl_com_data            *buffer;
    /*  pointer to the IPDU                 */
    tpl_sending_ipdu        *external_target;
    /*  location of the message in the IPDU */
    tpl_ipdu_location       message_location;
};

typedef struct TPL_EXTERNAL_SENDING_MO tpl_external_sending_mo;

/*
 * tpl_internal_external_sending_mo is internal AND external
 * sending message object
 */
struct TPL_INTERNAL_EXTERNAL_SENDING_MO {
    /*  common to all sending mo                            */
    tpl_base_sending_mo             base_mo;
    /*  function pointer to the filter                      */
    tpl_filter                      filter;
    /*  pointer to the buffer                               */
    tpl_com_data                    *buffer;
    /*  pointer to the internal receiving message object    */
    struct TPL_BASE_RECEIVING_MO    *internal_target;
    /*  pointer to the IPDU                                 */
    struct TPL_SENDING_IPDU         *external_target;
};

typedef struct TPL_INTERNAL_EXTERNAL_SENDING_MO
tpl_internal_external_sending_mo;

#endif
