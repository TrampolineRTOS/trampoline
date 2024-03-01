//--------------------------------------------------------------------------------------------------
//
//  'SourceTextInString'
//
//  This file is part of libpm library
//
//  Copyright (C) 1996, ..., 2016 Pierre Molinaro.
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

#include "SourceTextInString.h"
#include "LocationInSource.h"

//--------------------------------------------------------------------------------------------------

SourceTextInString::SourceTextInString (void) :
mObject (nullptr) {
}

//--------------------------------------------------------------------------------------------------

SourceTextInString::SourceTextInString (const String & inSourceString,
                                            const String & inFilePath,
                                            const bool inShowSourceOnDetailledErrorMessage) :
mObject (nullptr) {
  macroMyNew (mObject, cSourceTextInString (inSourceString, inFilePath, inShowSourceOnDetailledErrorMessage COMMA_HERE)) ;
}

//--------------------------------------------------------------------------------------------------

SourceTextInString::~ SourceTextInString (void) {
  macroDetachSharedObject (mObject) ;
}

//--------------------------------------------------------------------------------------------------

SourceTextInString::SourceTextInString (const SourceTextInString & inSource) :
mObject (nullptr) {
  macroAssignSharedObject (mObject, inSource.mObject) ;
}

//--------------------------------------------------------------------------------------------------

SourceTextInString & SourceTextInString::operator = (const SourceTextInString & inSource) {
  if (this != & inSource) {
    macroAssignSharedObject (mObject, inSource.mObject) ;
  }
  return *this ;
}

//--------------------------------------------------------------------------------------------------

String SourceTextInString::getLineForLocation (const LocationInSource & inLocation) const {
  String errorLine ;
  if (nullptr != mObject) {
    const int32_t sourceTextLength = mObject->mSourceString.length () ;
    int32_t index = 0 ;
    int32_t currentLine = 1 ;
    if (sourceTextLength > 0) {
      while (currentLine < inLocation.lineNumber ()) {
        if (UNICODE_VALUE (mObject->mSourceString.readCharOrNul (index COMMA_HERE)) == '\n') {
          currentLine ++ ;
        }
        index ++ ;
      }
    }
  //--- Get error line text
    for (int32_t i=index ; (i<sourceTextLength) && (UNICODE_VALUE (mObject->mSourceString.readCharOrNul (i COMMA_HERE)) != '\n') ; i++) {
      const utf32 character = mObject->mSourceString.charAtIndex (i COMMA_HERE) ;
      errorLine.appendChar (character) ;
    }
  }
  return errorLine ;
}

//--------------------------------------------------------------------------------------------------

void SourceTextInString::appendSourceContents (String & ioMessage) const {
  if ((nullptr != mObject) && mObject->mShowSourceOnDetailledErrorMessage) {
    const bool insertCarriageReturn = (mObject->mSourceString.length () > 0) && (UNICODE_VALUE (mObject->mSourceString.lastChar (HERE)) != '\n')  ;
    ioMessage.appendCString ("-- SOURCE STRING (--verbose option) --\n") ;
    ioMessage.appendString (mObject->mSourceString) ;
    ioMessage.appendString (insertCarriageReturn ? "\n" : "") ;
    ioMessage.appendCString ("-------------------------------------------------------\n") ;
  }
}

//--------------------------------------------------------------------------------------------------
