//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  C_HTMLString : generating HTML text                                                                                *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2014, ..., 2014 Pierre Molinaro.                                                                     *
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
//----------------------------------------------------------------------------------------------------------------------

#ifndef CLASS_HTML_STRING_DEFINED
#define CLASS_HTML_STRING_DEFINED

//----------------------------------------------------------------------------------------------------------------------

#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//      Fully dynamic character string : C_String                                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class C_HTMLString : public C_String {
//--- Constructors
  public : C_HTMLString (void) ;
  
//--- Handling copy
//  public : C_HTMLString (const C_HTMLString & inSource) ;
//  public : C_HTMLString & operator = (const C_HTMLString & inString) ;

//--- Output data, without HTML formatting
  public : void outputRawData (const char * in_Cstring) ;

//--- General stream methods
  protected : virtual void performActualCharArrayOutput (const char * inCharArray,
                                                         const int32_t inArrayCount) ;

  protected : virtual void performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                                            const int32_t inArrayCount) ;

//--- Method for writing a HTML table
  public : void appendCppTitleComment (const C_String & inCommentString,
                                       const C_String & inTableStyleClass) ;

//--- Write start code
  public : void writeStartCode (const C_String & inWindowTitle,
                                const C_String & inCSSFileName,
                                const C_String & inCSSContents) ;

//--- Write end code
  public : void writeEndCode (void) ;

//--- Private attributes
  private : typedef C_String inherited ;
} ;

//----------------------------------------------------------------------------------------------------------------------

#endif
