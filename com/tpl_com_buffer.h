/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Communication bufffer type header
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_COM_BUFFER_H
#define TPL_COM_BUFFER_H

#include "tpl_com_private_types.h"

struct TPL_COM_BUFFER {
    /*! pointer to the buffer       */
    tpl_com_data        *buffer;
    /*! size of the buffer          */
    tpl_message_size    size;
};

typedef struct TPL_COM_BUFFER tpl_com_buffer;

#endif
