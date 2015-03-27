//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  unicode_character : an implementation of Unicode character                                                         *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2009 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef UNICODE_CHARACTER_COCOA_ROUTINES_DEFINED
#define UNICODE_CHARACTER_COCOA_ROUTINES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#import <Cocoa/Cocoa.h>
#import <limits.h>

#import "strings/string_encodings.h"

//---------------------------------------------------------------------------------------------------------------------*

typedef UInt32 utf32 ;
#define UNICODE_VALUE(n) (n)
#define TO_UNICODE(v) (v)

//---------------------------------------------------------------------------------------------------------------------*

/*typedef UInt8  uint8_t  ;
typedef UInt16 uint16_t ;
typedef UInt32 uint32_t ;
typedef SInt32 int32_t ;
typedef UInt64 uint64_t ;
typedef SInt64 int64_t ;
*/
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
// D E F I N E    M I N    A N D    M A X     F O R    I N T    T Y P E S      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//--- Signed integer max
// #define PMSINT8_MAX       0x7F
// #define PMSINT16_MAX      0x7FFF
// #define INT32_MAX      0x7FFFFFFFL
// #define INT64_MAX      0x7FFFFFFFFFFFFFFFLL

//--- Signed integer min
//#define PMSINT8_MIN       (~PMSINT8_MAX)
// #define PMSINT16_MIN      (~PMSINT16_MAX)
// #define INT32_MIN      (~INT32_MAX)
// #define INT64_MIN      (~INT64_MAX)

//--- Unsigned integer max
// #define UINT8_MAX       0xFFU
// #define UINT16_MAX      0xFFFFU
// #define UINT32_MAX      0xFFFFFFFFUL
// #define UINT64_MAX      0xFFFFFFFFFFFFFFFFULL    

//---------------------------------------------------------------------------------------------------------------------*

#include "strings/unicode_character_base.h"

//---------------------------------------------------------------------------------------------------------------------*

#endif
