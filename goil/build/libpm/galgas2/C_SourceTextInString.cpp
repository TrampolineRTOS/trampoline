//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  'C_SourceTextInString'                                                                                             *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1996, ..., 2010 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes                                          *
//  ECN, École Centrale de Nantes (France)                                                                             *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it                                            *
//  under the terms of the GNU Lesser General Public License as published                                              *
//  by the Free Software Foundation; either version 2 of the License, or                                               *
//  (at your option) any later version.                                                                                *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT                                             *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                              *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                                           *
//  more details.                                                                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/C_SourceTextInString.h"
#include "galgas2/C_LocationInSource.h"

//----------------------------------------------------------------------------------------------------------------------

C_SourceTextInString::
C_SourceTextInString (const C_String & inSourceString,
                      const C_String & inFilePath,
                      const bool inShowSourceOnDetailledErrorMessage
                      COMMA_LOCATION_ARGS) :
C_SharedObject (THERE),
mFilePath (inFilePath),
mSourceString (inSourceString),
mShowSourceOnDetailledErrorMessage (inShowSourceOnDetailledErrorMessage) {
}

//----------------------------------------------------------------------------------------------------------------------

int32_t C_SourceTextInString::sourceLength (void) const {
  return mSourceString.length () ;
}

//----------------------------------------------------------------------------------------------------------------------

utf32 C_SourceTextInString::readCharOrNul (const int32_t inIndex COMMA_LOCATION_ARGS) const {
  return mSourceString.readCharOrNul (inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const utf32 * C_SourceTextInString::
temporaryUTF32StringAtIndex (const int32_t inIndex,
                             const int32_t /* inRequiredLength */
                             COMMA_LOCATION_ARGS) const {
  return & (mSourceString.utf32String (THERE)) [inIndex] ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_SourceTextInString::
getLineForLocation (const C_LocationInSource & inLocation) const {
  const int32_t sourceTextLength = mSourceString.length () ;
  int32_t index = 0 ;
  int32_t currentLine = 1 ;
  if (sourceTextLength > 0) {
    while (currentLine < inLocation.lineNumber ()) {
      if (UNICODE_VALUE (mSourceString.readCharOrNul (index COMMA_HERE)) == '\n') {
        currentLine ++ ;
      }
      index ++ ;
    }
  }
//--- Get error line text
  C_String errorLine ;
  for (int32_t i=index ; (i<sourceTextLength) && (UNICODE_VALUE (mSourceString.readCharOrNul (i COMMA_HERE)) != '\n') ; i++) {
    const utf32 character = mSourceString (i COMMA_HERE) ;
    errorLine.appendUnicodeCharacter (character COMMA_HERE) ;
  }
  return errorLine ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_SourceTextInString::
appendSourceContents (C_String & ioMessage) const {
  if (mShowSourceOnDetailledErrorMessage) {
    const bool insertCarriageReturn = (mSourceString.length () > 0) && (UNICODE_VALUE (mSourceString.lastCharacter (HERE)) != '\n')  ;
    ioMessage << "-- SOURCE STRING (--verbose option) --\n"
              << mSourceString
              << (insertCarriageReturn ? "\n" : "")
              << "-------------------------------------------------------\n" ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
