//----------------------------------------------------------------------------------------------------------------------
//
//  Generic String Command Line Interface Option
//
//  This file is part of libpm library
//
//  Copyright (C) 2009, ..., 2023 Pierre Molinaro.
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

#include "command_line_interface/C_StringCommandLineOption.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include <string.h>

//----------------------------------------------------------------------------------------------------------------------

static C_StringCommandLineOption * gFirstStringOption ;
static C_StringCommandLineOption * gLastStringOption ;

//----------------------------------------------------------------------------------------------------------------------

C_StringCommandLineOption::C_StringCommandLineOption (const char * inDomainName,
                                                      const char * inIdentifier,
                                                      const char inChar,
                                                      const char * inString,
                                                      const char * inComment,
                                                      const char * inDefaultValue) :
C_CommandLineOption (inDomainName, inIdentifier, inChar, inString, inComment),
mNext (nullptr),
mValue (inDefaultValue),
mDefaultValue (inDefaultValue) {
  if (nullptr == gFirstStringOption) {
    gFirstStringOption = this ;
  }else{
    gLastStringOption->mNext = this ;
  }
  gLastStringOption = this ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::setStringOptionForCommandChar (const char * inCommandString,
                                                               bool & outFound,
                                                               bool & outCommandLineOptionStringIsValid) {
  outCommandLineOptionStringIsValid = (strlen (inCommandString) > 2) && (inCommandString [1] == '=') ;
  outFound = false ;
  if (outCommandLineOptionStringIsValid) {
    C_StringCommandLineOption * p = gFirstStringOption ;
    while ((p != nullptr) && ! outFound) {
      outFound = inCommandString [0] == p->mCommandChar ;
      if (outFound) {
        p->mValue.setLengthToZero () ;
        p->mValue << & inCommandString [2] ;
      }
      p = p->mNext ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::setStringOptionForCommandString (const char * inCommandString,
                                                                 bool & outFound,
                                                                 bool & outCommandLineOptionStringIsValid) {
  const uint32_t optionLength = (uint32_t) (strlen (inCommandString) & UINT32_MAX) ;
  outCommandLineOptionStringIsValid = optionLength > 4 ;
//--- Find '=' character
  uint32_t equalSignIndex = 0 ;
  if (outCommandLineOptionStringIsValid) {
    outFound = false ;
    while ((equalSignIndex < optionLength) && outCommandLineOptionStringIsValid && ! outFound) {
      outFound = inCommandString [equalSignIndex] == '=' ;
      if (! outFound) {
        equalSignIndex ++ ;
      }
    }
    outCommandLineOptionStringIsValid = outFound && (equalSignIndex > 0) && (equalSignIndex < (optionLength - 1)) ;
  }
//--- Search option
  outFound = false ;
  if (outCommandLineOptionStringIsValid) {
    C_StringCommandLineOption * p = gFirstStringOption ;
    while ((p != nullptr) && ! outFound) {
      outFound = (strlen (p->mCommandString) == equalSignIndex) &&
                 (strncmp (p->mCommandString, inCommandString, equalSignIndex) == 0) ;
      if (outFound) {
        p->mValue.setLengthToZero () ;
        p->mValue << & inCommandString [strlen (p->mCommandString) + 1] ;
      }
      p = p->mNext ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::printUsageOfStringOptions (void) {
  C_StringCommandLineOption * p = gFirstStringOption ;
  while (p != nullptr) {
    const char c = p->mCommandChar ;
    if (c != '\0') {
      printf (" [-%c=string]", c) ;
    }
    const char * s = p->mCommandString ;
    if (s [0] != 0) {
      printf (" [--%s=string]", s) ;
    }
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::printStringOptions (void) {
  C_StringCommandLineOption * p = gFirstStringOption ;
  while (p != nullptr) {
    if (p->mCommandChar != '\0') {
      co.setForeColor (kBlueForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << "-" << cStringWithCharacter (p->mCommandChar) << "=string" ;
      co.setTextAttribute (kAllAttributesOff) ;
      co << "\n" ;
    }
    if (p->mCommandString [0] != '\0') {
      co.setForeColor (kBlueForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << "--" << p->mCommandString << "=string" ;
      co.setTextAttribute (kAllAttributesOff) ;
      co << "\n" ;
    }
    co << "    " << p->mComment  << " (default value: '"
       << p->mDefaultValue
       << "')\n" ;
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::releaseStrings (void) {
  C_StringCommandLineOption * p = gFirstStringOption ;
  while (p != nullptr) {
    p->mValue.releaseString () ;
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gReleaseString (nullptr, C_StringCommandLineOption::releaseStrings) ;

//----------------------------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::getStringOptionNameList (TC_UniqueArray <C_String> & outArray) {
  C_StringCommandLineOption * p = gFirstStringOption ;
  while (p != nullptr) {
    outArray.appendObject (p->mDomainName) ;
    outArray.appendObject (p->mIdentifier) ;
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

utf32 C_StringCommandLineOption::getStringOptionInvocationLetter (const C_String & inDomainName,
                                                                  const C_String & inIdentifier) {
  utf32 result = TO_UNICODE (0) ;
  C_StringCommandLineOption * p = gFirstStringOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = TO_UNICODE ((uint32_t) p->mCommandChar) ;
    p = p->mNext ;
}
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_StringCommandLineOption::getStringOptionInvocationString (const C_String & inDomainName,
                                                                     const C_String & inIdentifier) {
  C_String result ;
  C_StringCommandLineOption * p = gFirstStringOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mCommandString ;
    p = p->mNext ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_StringCommandLineOption::getStringOptionCommentString (const C_String & inDomainName,
                                                                  const C_String & inIdentifier) {
  C_String result ;
  C_StringCommandLineOption * p = gFirstStringOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mComment ;
    p = p->mNext ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_StringCommandLineOption::getStringOptionValue (const C_String & inDomainName,
                                                          const C_String & inIdentifier) {
  C_String result ;
  C_StringCommandLineOption * p = gFirstStringOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mValue ;
    p = p->mNext ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::setStringOptionValue (const C_String & inDomainName,
                                                      const C_String & inIdentifier,
                                                      const C_String & inValue) {
  C_StringCommandLineOption * p = gFirstStringOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    if (found) {
      p->mValue = inValue ;
    }
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
