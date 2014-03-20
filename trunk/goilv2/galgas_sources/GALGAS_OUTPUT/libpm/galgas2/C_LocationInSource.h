//-----------------------------------------------------------------------------*
//                                                                             *
//  'C_LocationInSource'                                                     *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 1996, ..., 2011 Pierre Molinaro.                             *
//                                                                             *
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

#ifndef GALGAS_LOCATION_IN_SOURCE_CLASS_DEFINED
#define GALGAS_LOCATION_IN_SOURCE_CLASS_DEFINED

//-----------------------------------------------------------------------------*

#include "utilities/M_machine.h"

//-----------------------------------------------------------------------------*

class C_SourceTextInString ;
class C_String ;

//-----------------------------------------------------------------------------*
//                                                                             *
//                 Class for referencing a location in source text           *
//                                                                             *
//-----------------------------------------------------------------------------*

class C_LocationInSource {
  private : PMSInt32 mIndex ;
  private : PMSInt32 mLineNumber ;
  private : PMSInt32 mColumnNumber ;
  private : const C_SourceTextInString * mSourceText ;

//---  
  public : C_LocationInSource (void) ;
  public : virtual ~C_LocationInSource (void) ;

  public : C_LocationInSource (const C_LocationInSource & inObject) ;

  public : C_LocationInSource & operator = (const C_LocationInSource & inObject) ;

  public : C_LocationInSource (const C_SourceTextInString * inSourceText,
                               const PMSInt32 inIndex,
                               const PMSInt32 inLine,
                               const PMSInt32 inColumn) ;

  public : void gotoNextLocation (const bool inPreviousCharWasEndOfLine) ;

  public : void resetLocation (void) ;

  public : void resetWithSourceText (const C_SourceTextInString * inSourceText) ;

  public : inline PMSInt32 index (void) const { return mIndex ; }

  public : inline PMSInt32 lineNumber (void) const { return mLineNumber ; }

  public : inline PMSInt32 columnNumber (void) const { return mColumnNumber ; }

  public : C_String sourceFilePath (void) const ;
} ;

//-----------------------------------------------------------------------------*

#endif
