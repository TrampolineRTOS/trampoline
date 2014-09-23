//-----------------------------------------------------------------------------*
//                                                                             *
//  Collection of macros for determining a location in a source file.          *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 1997 Pierre Molinaro.                                        *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
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

#ifndef SOURCE_LOCATION_MACROS_DEFINED
#define SOURCE_LOCATION_MACROS_DEFINED

//-----------------------------------------------------------------------------*

#include "utilities/M_machine.h"

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define HERE __FILE__, __LINE__
  #define COMMA_HERE , HERE
  #define THERE IN_SOURCE_FILE, IN_SOURCE_LINE
  #define COMMA_THERE , THERE
  #define LOCATION_ARGS const char * IN_SOURCE_FILE, const int32_t IN_SOURCE_LINE
  #define UNUSED_LOCATION_ARGS const char *, const int32_t
  #define COMMA_LOCATION_ARGS , LOCATION_ARGS
  #define COMMA_UNUSED_LOCATION_ARGS , UNUSED_LOCATION_ARGS
#else
  #define HERE
  #define COMMA_HERE
  #define THERE
  #define COMMA_THERE
  #define LOCATION_ARGS void
  #define UNUSED_LOCATION_ARGS void
  #define COMMA_LOCATION_ARGS
  #define COMMA_UNUSED_LOCATION_ARGS
#endif

//-----------------------------------------------------------------------------*

#endif
