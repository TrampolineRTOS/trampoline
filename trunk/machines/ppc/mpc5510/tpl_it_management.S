/*
 * @file tpl_it_management.S
 *
 * @section desc File description
 *
 * Trampoline interrupt id fonction for MPC551x
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_assembler.h"

  .equ INTC_IACKR_PRC0, 0xfff48010  /* MPC551x: P0 Interrupt Acknowledge @  */
  
  .text
  
tpl_it_id:
  lis   r3,TPL_HIG(INTC_IACKR_PRC0)
  lwz   r3,TPL_LOW(INTC_IACKR_PRC0)(r3)
  blr
  
  .type tpl_it_id,@function
  .size tpl_it_id,$-tpl_it_id
