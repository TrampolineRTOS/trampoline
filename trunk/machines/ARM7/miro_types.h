/**
 * @file miro_types.h
 *
 * @brief Ce module contient toutes les définitions communes à tous les programmes de MIRO
 *
 * Note : comme les types de base définis ci-après sont fréquemment utilisés, la concision
 * a précédé la clareté dans le choix des noms de types.
 * 
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 0.9
 * $Revision: 1.1.1.1 $
 */
#if !defined __MIRO_TYPES_H
#define __MIRO_TYPES_H

/**
 * Entier non signé sur 8 bits
 */
typedef unsigned char UInt8;

/**
 * Entier signé sur 8 bits
 */
typedef signed char SInt8;

/**
 * Entier non-signé sur 16 bits
 */
typedef unsigned short UInt16;

/**
 * Entier signé sur 16 bits
 */
typedef signed short SInt16;

/**
 * Entier non-signé sur 32 bits
 */
typedef unsigned int UInt32;

/**
 * Entier signé sur 32 bits
 */
typedef signed int SInt32;

#endif /* __MIRO_TYPES_H */
/*
 * Historique des modifications :
 * ------------------------------
 * $Log: miro_types.h,v $
 * Revision 1.1.1.1  2008/01/17 08:47:20  LaurentMenard
 * creation du module CVS trampoline porte sur ARM7
 *
 * Revision 1.4  2007/05/07 11:55:32  benoit
 * Maj des commentaires et du Doxygen
 *
 * Revision 1.1.1.1  2005/03/21 15:46:44  jilias
 * premier import sur le dépôt CVS
 *
 */
