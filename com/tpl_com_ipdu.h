/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
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

typedef u8  tpl_ipdu_mode;

#define IPDU_PERIODIC 1
#define IPDU_DIRECT   2
#define IPDU_MIXED    ((IPDU_PERIODIC) | (IPDU_DIRECT))

typedef u32 tpl_ipdu_id;

/*
 * A tpl_sending_ipdu gathers :
 * - An id
 * - A mode
 * - A 8 bytes buffer pointer
 */ 
struct TPL_SENDING_IPDU {
  CONST(tpl_ipdu_id, TYPEDEF)      id;
  CONST(tpl_ipdu_mode, TYPEDEF)    mode;
  CONSTP2VAR(u8, TYPEDEF, COM_VAR) buffer;
};

typedef struct TPL_SENDING_IPDU tpl_sending_ipdu;

/*  __TPL_COM_IPDU_H__  */
#endif