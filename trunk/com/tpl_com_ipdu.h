/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline IPDU header
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_IPDU_H__
#define __TPL_COM_IPDU_H__

struct TPL_IDPU_LOCATION {
    /*  offset in bytes from the start of the IPDU. Since an IPDU is limited
        to 8 bytes in the current implementation, 3 bits are used for the
        offset  */
    unsigned int byte_offset:3;
    /*  offset in bits from the start of the first byte, 3 bits too */
    unsigned int bit_offset:3;
    /*  length in bits of the message   */
    unsigned int bit_length:6;
};

typedef struct TPL_IDPU_LOCATION tpl_ipdu_location;

struct TPL_SENDING_IPDU {
    
};

typedef struct TPL_SENDING_IPDU tpl_sending_ipdu;

/*  __TPL_COM_IPDU_H__  */
#endif