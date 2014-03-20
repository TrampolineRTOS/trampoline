//-----------------------------------------------------------------------------*
//                                                                             *
//  unicode_character : an implementation of Unicode character                 *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2008, ..., 2009 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#ifndef UNICODE_CHARACTER_COCOA_ROUTINES_DEFINED
#define UNICODE_CHARACTER_COCOA_ROUTINES_DEFINED

//-----------------------------------------------------------------------------*

#import <Cocoa/Cocoa.h>
#import <limits.h>

#import "strings/string_encodings.h"

//-----------------------------------------------------------------------------*

typedef UInt32 utf32 ;
#define UNICODE_VALUE(n) (n)
#define TO_UNICODE(v) (v)

//-----------------------------------------------------------------------------*

typedef UInt8  PMUInt8  ;
typedef UInt16 PMUInt16 ;
typedef UInt32 PMUInt32 ;
typedef SInt32 PMSInt32 ;
typedef UInt64 PMUInt64 ;
typedef SInt64 PMSInt64 ;

//-----------------------------------------------------------------------------*
//                                                                             *
// D E F I N E    M I N    A N D    M A X     F O R    I N T    T Y P E S      *
//                                                                             *
//-----------------------------------------------------------------------------*

//--- Signed integer max
#define PMSINT8_MAX       0x7F
#define PMSINT16_MAX      0x7FFF
#define PMSINT32_MAX      0x7FFFFFFFL
#define PMSINT64_MAX      0x7FFFFFFFFFFFFFFFLL

//--- Signed integer min
#define PMSINT8_MIN       (~PMSINT8_MAX)
#define PMSINT16_MIN      (~PMSINT16_MAX)
#define PMSINT32_MIN      (~PMSINT32_MAX)
#define PMSINT64_MIN      (~PMSINT64_MAX)

//--- Unsigned integer max
#define PMUINT8_MAX       0xFFU
#define PMUINT16_MAX      0xFFFFU
#define PMUINT32_MAX      0xFFFFFFFFUL
#define PMUINT64_MAX      0xFFFFFFFFFFFFFFFFULL    

//-----------------------------------------------------------------------------*

#include "strings/unicode_character_base.h"

//-----------------------------------------------------------------------------*

#endif
