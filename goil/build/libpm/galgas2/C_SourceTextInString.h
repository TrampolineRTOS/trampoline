//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'C_SourceTextInString'                                                                                             *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1996, ..., 2010 Pierre Molinaro.                                                                     *
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

#ifndef GALGAS_SOURCE_TEXT_IN_STRING_CLASS_DEFINED
#define GALGAS_SOURCE_TEXT_IN_STRING_CLASS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "strings/C_String.h"
#include "utilities/C_SharedObject.h"

//---------------------------------------------------------------------------------------------------------------------*

class C_LocationInSource ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                 Classes for handling source text                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class C_SourceTextInString : public C_SharedObject {
//--- Constructor
  public : C_SourceTextInString (const C_String & inSourceString,
                                 const C_String & inFilePath,
                                 const bool inShowSourceOnDetailledErrorMessage
                                 COMMA_LOCATION_ARGS) ;

//--- Source file Name
  private : const C_String mFilePath ;

  public : inline C_String sourceFilePath (void) const {
    return mFilePath ;
  }
//--- Source text
  public : const C_String mSourceString ;
  private : const bool mShowSourceOnDetailledErrorMessage ;

  public : int32_t sourceLength (void) const ;
  public : utf32 readCharOrNul (const int32_t inIndex COMMA_LOCATION_ARGS) const ;
  public : const utf32 * temporaryUTF32StringAtIndex (const int32_t inIndex, const int32_t inRequiredLength COMMA_LOCATION_ARGS) const ;
  public : C_String getLineForLocation (const C_LocationInSource & inLocation) const ;
  public : void appendSourceContents (C_String & ioMessage) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
