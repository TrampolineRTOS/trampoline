//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  Lexique introspection                                                                                              *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2016, ..., 2016 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#pragma once

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "strings/C_String.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (* Type_appendKeywordListNames) (TC_UniqueArray <C_String> & ioList) ;

typedef void (* Type_getKeywordsForIdentifier) (const C_String & inIdentifier,
                                                bool & ioFound,
                                                TC_UniqueArray <C_String> & ioList) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cLexiqueIntrospection {
//--- Constructor
  public : cLexiqueIntrospection (Type_appendKeywordListNames appendKeywordListNames,
                                  Type_getKeywordsForIdentifier getKeywordsForIdentifier) ;

//--- Accessors
  public : static void getKeywordListNames (TC_UniqueArray <C_String> & outList) ;
  public : static void getKeywordListForIdentifier (const C_String & inIdentifier,
                                                    bool & outFound,
                                                    TC_UniqueArray <C_String> & outList) ;

  public : static void handleGetKeywordListOption (class C_Compiler * inCompiler) ;

//--- No copy
  private : cLexiqueIntrospection (const cLexiqueIntrospection &) ;
  private : cLexiqueIntrospection & operator = (const cLexiqueIntrospection &) ;

//--- Private member
  private : cLexiqueIntrospection * mNext ;
  private : Type_appendKeywordListNames mAppendKeywordListNames ;
  private : Type_getKeywordsForIdentifier mGetKeywordsForIdentifier ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
