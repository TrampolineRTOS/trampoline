//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'C_Lexique' : an abstract lexique class ;                                *
//  Galgas generated scanner classes inherit from this class.                *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 1996, ..., 2010 Pierre Molinaro.                             *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef TEMPLATE_DELIMITER_CLASS_CLASS_DEFINED
#define TEMPLATE_DELIMITER_CLASS_CLASS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------------------------------------------------*

class C_Lexique ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  T E M P L A T E    D E L I M I T E R S     C L A S S                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cTemplateDelimiter {
  public : const utf32 * mStartString ;
  public : const int32_t mStartStringLength ;
  public : const utf32 * mEndString ;
  public : const int32_t mEndStringLength ;
  public : void (* mReplacementFunction) (C_Lexique & inLexique, const C_String & inElementString, C_String & ioTemplateString) ;
  public : const bool mDiscardStartString ;

//--- Constructor
  public : cTemplateDelimiter (const utf32 * inStartString,
                               const int32_t inStartStringLength,
                               const utf32 * inEndString,
                               const int32_t inEndStringLength,
                               void (* inReplacementFunction) (C_Lexique & inLexique, const C_String & inElementString, C_String & ioTemplateString),
                               const bool inDiscardStartString) ;

//--- Copy
  public : cTemplateDelimiter (const cTemplateDelimiter & inOperand) ;

//--- No assignment
  private : cTemplateDelimiter & operator = (const cTemplateDelimiter &) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
