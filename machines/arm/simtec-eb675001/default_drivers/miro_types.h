/**
 * @file miro_types.h
 *
 * @brief Ce module contient toutes les définitions communes à tous les programmes de MIRO
 *
 * Note : comme les types de base définis ci-après sont fréquemment utilisés, la concision
 * a précédé la clareté dans le choix des noms de types.
 * 
 * $Author$
 * $Date$
 *
 * @version 0.9
 * $Revision$
 */
#if !defined __MIRO_TYPES_H
#define __MIRO_TYPES_H

#include "../tpl_os_std_types.h"

/**
 * Entier non signé sur 8 bits
 */
typedef u8 UInt8;

/**
 * Entier signé sur 8 bits
 */
typedef s8 SInt8;

/**
 * Entier non-signé sur 16 bits
 */
typedef u16 UInt16;

/**
 * Entier signé sur 16 bits
 */
typedef s16 SInt16;

/**
 * Entier non-signé sur 32 bits
 */
typedef u32 UInt32;

/**
 * Entier signé sur 32 bits
 */
typedef s32 SInt32;

#endif /* __MIRO_TYPES_H */

