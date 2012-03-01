//---------------------------------------------------------------------------*
//                                                                           *
//  Definition of 'MF_Assert' and related routine prototypes                 *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1997, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
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

#ifndef ASSERT_MACRO_DEFINED
#define ASSERT_MACRO_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/M_machine.h"
#include "utilities/M_SourceLocation.h"

//---------------------------------------------------------------------------*
//                                                                           *
//            Macro 'MF_Assert'  definition                                  *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void assert_routine (const bool inExpression,
                       const char * const inMessage,
                       const PMSInt64 inParameter1,
                       const PMSInt64 inParameter2 COMMA_LOCATION_ARGS) ;
  #define MF_Assert(exp,message,par1,par2) { assert_routine (exp, message, par1, par2 COMMA_HERE) ; }
  #define MF_AssertThere(exp,message,par1,par2) { assert_routine (exp, message, par1, par2 COMMA_THERE) ; }
#else
  #define MF_Assert(exp,message,par1,par2) {}
  #define MF_AssertThere(exp,message,par1,par2) {}
#endif

//---------------------------------------------------------------------------*

#endif

