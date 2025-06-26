//--------------------------------------------------------------------------------------------------
//
//  'LocationInSource'                                                                         
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
//--------------------------------------------------------------------------------------------------

#include "LocationInSource.h"
#include "SourceTextInString.h"
#include "String-class.h"

//--------------------------------------------------------------------------------------------------

LocationInSource::LocationInSource (void) :
mIndex (0),
mLineNumber (1),
mColumnNumber (1),
mSourceText () {
}

//--------------------------------------------------------------------------------------------------

void LocationInSource::gotoNextLocation (void) {
  if (mIndex < mSourceText.sourceString ().length ()) {
    const utf32 currentChar = mSourceText.sourceString ().charAtIndex (mIndex COMMA_HERE) ;
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

//--------------------------------------------------------------------------------------------------

void LocationInSource::goForward (const uint32_t inCount) {
  uint32_t count = inCount ;
  while (count > 0) {
    gotoNextLocation () ;
    count -= 1 ;
  }
}

//--------------------------------------------------------------------------------------------------

void LocationInSource::resetLocation (void) {
  mIndex = 0 ;
  mLineNumber = 1 ;
  mColumnNumber = 1 ;
}

//--------------------------------------------------------------------------------------------------

void LocationInSource::resetWithSourceText (const SourceTextInString & inSourceText) {
  mIndex = 0 ;
  mLineNumber = 1 ;
  mColumnNumber = 1 ;
  mSourceText = inSourceText ;
}

//--------------------------------------------------------------------------------------------------

String LocationInSource::sourceFilePath (void) const {
  return mSourceText.sourceFilePath () ;
}

//--------------------------------------------------------------------------------------------------

int32_t LocationInSource::lineNumber (void) const {
  return mLineNumber ;
}

//--------------------------------------------------------------------------------------------------

int32_t LocationInSource::columnNumber (void) const {
  return mColumnNumber ;
}

//--------------------------------------------------------------------------------------------------
