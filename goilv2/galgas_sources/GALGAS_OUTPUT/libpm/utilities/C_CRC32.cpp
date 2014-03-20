//---------------------------------------------------------------------------*
//                                                                           *
//  'C_CRC32' : a class for computing CRC32                                  *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1997 Pierre Molinaro.                                      *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes                                            *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include "C_CRC32.h"
#include <string.h>

//---------------------------------------------------------------------------*
//            Initialisation du tableau des sommes de controle               *
//---------------------------------------------------------------------------*

static PMUInt32 tableCRC [256] ;

//---------------------------------------------------------------------------*

class cInitTableCRC {
  public : cInitTableCRC (void) ;
} ;


//---------------------------------------------------------------------------*

cInitTableCRC::cInitTableCRC (void) {
  const PMUInt32 polynome_CRC32 = 0xEDB88320UL ;
  for (PMUInt16 i=0 ; i<256 ; i++) {
    PMUInt32 crc = i ;
    for (PMSInt16 j=8 ; j>0 ; j--) {
      if (crc & 1UL) {
        crc = (crc >> 1) ^ polynome_CRC32 ;
      }else{
        crc >>= 1 ;
      }
    }
    tableCRC [i] = crc ;
  }
}

//---------------------------------------------------------------------------*

void C_CRC32::addCharToChecksum (const char car, PMUInt32 & somme) {
  PMSInt32 valeurLong = car ;
  if (valeurLong < 0L) valeurLong += 256L ;
  addLongToChecksum (valeurLong, somme) ;
}

//---------------------------------------------------------------------------*

void C_CRC32::addShortToChecksum (const PMSInt16 valeur, PMUInt32 & somme) {
  const PMSInt32 valeurLong = valeur ;
  addLongToChecksum (valeurLong, somme) ;
}

//---------------------------------------------------------------------------*

void C_CRC32::addLongToChecksum (const PMSInt32 valeur, PMUInt32 & somme) {
  const PMUInt32 temp1 = (somme >> 8) & 0x00FFFFFFUL ;
  const PMUInt32 temp2 = tableCRC [(somme ^ valeur) & 255UL] ;
  somme = temp1 ^ temp2 ;
}

//---------------------------------------------------------------------------*

void C_CRC32::addUnsignedLongToChecksum (const PMUInt32 valeur, PMUInt32 & somme) {
  const PMUInt32 temp1 = (somme >> 8) & 0x00FFFFFFUL ;
  const PMUInt32 temp2 = tableCRC [(somme ^ valeur) & 255UL] ;
  somme = temp1 ^ temp2 ;
}

//---------------------------------------------------------------------------*

void C_CRC32::addStringToChecksum (const char * chaine, PMUInt32 & somme) {
  if (chaine == NULL) {
    addLongToChecksum (0L, somme) ;
  }else{
    const PMSInt32 longueurChaine = (PMSInt32) ::strlen (chaine) ;
    for (PMSInt32 i=0 ; i<longueurChaine ; i++) {
      addCharToChecksum (chaine [i], somme) ;
    }
  }
}

//---------------------------------------------------------------------------*
