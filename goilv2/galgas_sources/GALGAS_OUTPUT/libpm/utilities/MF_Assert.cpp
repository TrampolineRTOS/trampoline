//-----------------------------------------------------------------------------*
//                                                                             *
//  Definition of 'MF_Assert' and related routines                             *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 1997, ..., 2014 Pierre Molinaro.                             *
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

#include "utilities/MF_Assert.h"
#include "utilities/M_machine.h"

//-----------------------------------------------------------------------------*

#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------*

#ifndef MACHINE_IS_DEFINED
  #error "Undefined machine"
#endif

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static const PMUInt32 K_EXCEPTION_STRING_SIZE = 2000 ;
#endif

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void runtime_error_routine (const char * const inMessage,
                              const PMSInt64 inParameter1,
                              const PMSInt64 inParameter2
                              COMMA_LOCATION_ARGS) {
    char exceptionMessage [K_EXCEPTION_STRING_SIZE] ;
    snprintf (exceptionMessage, K_EXCEPTION_STRING_SIZE - 1, inMessage, inParameter1, inParameter2) ;
    printf ("*** Assertion failed at line %d of file '%s': %s\n", IN_SOURCE_LINE, IN_SOURCE_FILE, exceptionMessage) ;
    exit (1) ;
  }
#endif

//-----------------------------------------------------------------------------*
