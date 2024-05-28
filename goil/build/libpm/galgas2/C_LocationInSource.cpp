//----------------------------------------------------------------------------------------------------------------------
//
//  'C_LocationInSource'                                                                         
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1996, ..., 2011 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/C_LocationInSource.h"
#include "galgas2/C_SourceTextInString.h"
#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

C_LocationInSource::C_LocationInSource (void) :
mIndex (0),
mLineNumber (1),
mColumnNumber (1),
mSourceText () {
}

//----------------------------------------------------------------------------------------------------------------------

void C_LocationInSource::gotoNextLocation (void) {
  if (mIndex < mSourceText.sourceString ().length ()) {
    const utf32 currentChar = mSourceText.sourceString () (mIndex COMMA_HERE) ;
    const bool previousCharWasEndOfLine = UNICODE_VALUE (currentChar) == '\n' ;
    if (previousCharWasEndOfLine) {
      mLineNumber ++ ;
      mColumnNumber = 1 ;
    }else{
      mColumnNumber ++ ;
    }
    mIndex ++ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_LocationInSource::goForward (const uint32_t inCount) {
  uint32_t count = inCount ;
  while (count > 0) {
    gotoNextLocation () ;
    count -= 1 ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_LocationInSource::resetLocation (void) {
  mIndex = 0 ;
  mLineNumber = 1 ;
  mColumnNumber = 1 ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_LocationInSource::resetWithSourceText (const C_SourceTextInString & inSourceText) {
  mIndex = 0 ;
  mLineNumber = 1 ;
  mColumnNumber = 1 ;
  mSourceText = inSourceText ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_LocationInSource::sourceFilePath (void) const {
  return mSourceText.sourceFilePath () ;
}

//----------------------------------------------------------------------------------------------------------------------

//LineColumnContents C_LocationInSource::lineColumnNumber (void) const {
//  return mSourceText.sourceString ().lineAndColumnFromIndex (mIndex) ;
//}

//----------------------------------------------------------------------------------------------------------------------
