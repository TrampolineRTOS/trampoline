/*
 * @file tpl_assembler.h
 *
 * @section desc File description
 *
 * Cooking to have a portable assembly source
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

#ifndef TPL_ASSEMBLER_H
#define TPL_ASSEMBLER_H

/*
 * According to the assembler used (currently, Metrowerks and Green Hills are
 * supported, whe define some macro that correspond to keywords that are
 * not portable
 */
#ifdef __MWERKS__
#  define TPL_HIG(sym)  hi16(sym)
#  define TPL_LOW(sym)  lo16(sym)
#  define TPL_EXTERN    .reference
#else
#  ifdef __ghs_asm
#    define TPL_HIG(sym)  %hi(sym)
#    define TPL_LOW(sym)  %lo(sym)
#    define TPL_EXTERN    .extern
#  endif
#endif

/*
 * register number for special purpose registers
 */
#define spr_SRR0    26
#define spr_SRR1    27

/*
 * External interrupt bit mask in MSR
 */
#define EE_BIT      0x8000

#endif /*  TPL_ASSEMBLER_H  */

/* End of file tpl_assembler.h */
