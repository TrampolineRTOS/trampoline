//-----------------------------------------------------------------------------*
//                                                                             *
//  unicode_string_routines: this file implements uint32_t * string routines,  *
//  that are in direct correspondance with char * C string routines of C       *
//  library.                                                                   *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2008, ..., 2008 Pierre Molinaro.                             *
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

#ifndef UNICODE_STRING_ROUTINES_DEFINED
#define UNICODE_STRING_ROUTINES_DEFINED

//-----------------------------------------------------------------------------*

#include "utilities/M_machine.h"

//-----------------------------------------------------------------------------*

int32_t utf32_strcmp (const utf32 * inString1, const utf32 * inString2) ;

int32_t utf32_char_strncmp (const utf32 * inString1, const char * inString2, const int32_t inLength) ;

int32_t utf32_strncmp (const utf32 * inString1, const utf32 * inString2, const int32_t inLength) ;

int32_t utf32_strlen (const utf32 * inString) ;

int32_t utf32_char_strcmp (const utf32 * inString1, const char * inString2) ;

const utf32 * utf32_strstr (const utf32 * haystack, const utf32 * needle) ;

//-----------------------------------------------------------------------------*

#endif
