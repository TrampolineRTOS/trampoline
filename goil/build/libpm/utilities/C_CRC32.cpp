//----------------------------------------------------------------------------------------------------------------------
//
//  'C_CRC32' : a class for computing CRC32                                                      
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1997 Pierre Molinaro.                                                          
//  e-mail : pierre@pcmolinaro.name
//  This library is free software; you can redistribute it and/or modify it                      
//  under the terms of the GNU Lesser General Public License as published                        
//  by the Free Software Foundation; either version 2 of the License, or                         
//  (at your option) any later version.                                                          
//
//  This program is distributed in the hope it will be useful, but WITHOUT                       
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                        
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                     
//  more details.
//
//----------------------------------------------------------------------------------------------------------------------

#include "C_CRC32.h"
#include <string.h>

//----------------------------------------------------------------------------------------------------------------------
//            Initialisation du tableau des sommes de controle                                   
//----------------------------------------------------------------------------------------------------------------------

static uint32_t tableCRC [256] ;

//----------------------------------------------------------------------------------------------------------------------

class cInitTableCRC {
  public : cInitTableCRC (void) ;
} ;


//----------------------------------------------------------------------------------------------------------------------

cInitTableCRC::cInitTableCRC (void) {
  const uint32_t polynome_CRC32 = 0xEDB88320UL ;
  for (uint32_t i=0 ; i<256 ; i++) {
    uint32_t crc = i ;
    for (int32_t j=8 ; j>0 ; j--) {
      if (crc & 1UL) {
        crc = (crc >> 1) ^ polynome_CRC32 ;
      }else{
        crc >>= 1 ;
      }
    }
    tableCRC [i] = crc ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_CRC32::addCharToChecksum (const char car, uint32_t & somme) {
  int32_t valeurLong = car ;
  if (valeurLong < 0) valeurLong += 256L ;
  addLongToChecksum (valeurLong, somme) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_CRC32::addShortToChecksum (const int16_t valeur, uint32_t & somme) {
  const int32_t valeurLong = valeur ;
  addLongToChecksum (valeurLong, somme) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_CRC32::addLongToChecksum (const int32_t valeur, uint32_t & somme) {
  const uint32_t temp1 = (somme >> 8) & 0x00FFFFFFUL ;
  const uint32_t temp2 = tableCRC [(somme ^ (uint32_t) valeur) & 255] ;
  somme = temp1 ^ temp2 ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_CRC32::addUnsignedLongToChecksum (const uint32_t valeur, uint32_t & somme) {
  const uint32_t temp1 = (somme >> 8) & 0x00FFFFFFUL ;
  const uint32_t temp2 = tableCRC [(somme ^ valeur) & 255UL] ;
  somme = temp1 ^ temp2 ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_CRC32::addStringToChecksum (const char * chaine, uint32_t & somme) {
  if (chaine == NULL) {
    addLongToChecksum (0, somme) ;
  }else{
    const int32_t longueurChaine = (int32_t) ::strlen (chaine) ;
    for (int32_t i=0 ; i<longueurChaine ; i++) {
      addCharToChecksum (chaine [i], somme) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
