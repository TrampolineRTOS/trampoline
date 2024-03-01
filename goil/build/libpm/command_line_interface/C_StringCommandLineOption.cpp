//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------

#include "C_StringCommandLineOption.h"
#include "PrologueEpilogue.h"

//--------------------------------------------------------------------------------------------------

#include <string.h>

//--------------------------------------------------------------------------------------------------

static C_StringCommandLineOption * gFirstStringOption ;
static C_StringCommandLineOption * gLastStringOption ;

//--------------------------------------------------------------------------------------------------

C_StringCommandLineOption::C_StringCommandLineOption (const String & inDomainName,
                                                      const String & inIdentifier,
                                                      const char inChar,
                                                      const String & inString,
                                                      const String & inComment,
                                                      const String & inDefaultValue) :
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

//--------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::setStringOptionForCommandChar (const String & inCommandString,
                                                               bool & outFound,
                                                               bool & outCommandLineOptionStringIsValid) {
  outCommandLineOptionStringIsValid = (inCommandString.length () > 2) && (inCommandString.charAtIndex (1 COMMA_HERE) == '=') ;
  outFound = false ;
  if (outCommandLineOptionStringIsValid) {
    C_StringCommandLineOption * p = gFirstStringOption ;
    while ((p != nullptr) && ! outFound) {
      outFound = UNICODE_VALUE (inCommandString.charAtIndex (0 COMMA_HERE)) == uint32_t (p->mCommandChar) ;
      if (outFound) {
        p->mValue.removeAllKeepingCapacity () ;
        p->mValue.appendString (inCommandString.subStringFromIndex (2)) ;
      }
      p = p->mNext ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::setStringOptionForCommandString (const String & inCommandString,
                                                                 bool & outFound,
                                                                 bool & outCommandLineOptionStringIsValid) {
  const int32_t optionLength = inCommandString.length () ;
  outCommandLineOptionStringIsValid = optionLength > 4 ;
//--- Find '=' character
  int32_t equalSignIndex = 0 ;
  if (outCommandLineOptionStringIsValid) {
    outFound = false ;
    while ((equalSignIndex < optionLength) && outCommandLineOptionStringIsValid && ! outFound) {
      outFound = UNICODE_VALUE (inCommandString.charAtIndex (equalSignIndex COMMA_HERE)) == '=' ;
      if (! outFound) {
        equalSignIndex ++ ;
      }
    }
    outCommandLineOptionStringIsValid = outFound && (equalSignIndex > 0) && (equalSignIndex < (optionLength - 1)) ;
  }
//--- Search option
  const String command = inCommandString.leftSubString (equalSignIndex) ;
  outFound = false ;
  if (outCommandLineOptionStringIsValid) {
    C_StringCommandLineOption * p = gFirstStringOption ;
    while ((p != nullptr) && ! outFound) {
      outFound = p->mCommandString == command ;
      if (outFound) {
        p->mValue.removeAllKeepingCapacity () ;
        p->mValue.appendString (inCommandString.subStringFromIndex (p->mCommandString.length () + 1)) ;
      }
      p = p->mNext ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::printUsageOfStringOptions (void) {
  C_StringCommandLineOption * p = gFirstStringOption ;
  while (p != nullptr) {
    const char c = p->mCommandChar ;
    if (c != '\0') {
      printf (" [-%c=string]", c) ;
    }
    if (p->mCommandString.length () > 0) {
      printf (" [--%s=string]", p->mCommandString.cString ()) ;
    }
    p = p->mNext ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::printStringOptions (void) {
  C_StringCommandLineOption * p = gFirstStringOption ;
  while (p != nullptr) {
    if (p->mCommandChar != '\0') {
      gCout.setForeColor (kBlueForeColor) ;
      gCout.setTextAttribute (kBoldTextAttribute) ;
      gCout.appendCString ("-") ;
      gCout.appendASCIIChar (p->mCommandChar) ;
      gCout.appendCString ("=string") ;
      gCout.setTextAttribute (kAllAttributesOff) ;
      gCout.appendNewLine () ;
    }
    if (p->mCommandString.length () > 0) {
      gCout.setForeColor (kBlueForeColor) ;
      gCout.setTextAttribute (kBoldTextAttribute) ;
      gCout.appendCString ("--") ;
      gCout.appendString (p->mCommandString) ;
      gCout.appendCString ("=string") ;
      gCout.setTextAttribute (kAllAttributesOff) ;
      gCout.appendNewLine () ;
    }
    gCout.appendCString ("    ") ;
    gCout.appendString (p->mComment)  ;
    gCout.appendCString (" (default value: '") ;
    gCout.appendString (p->mDefaultValue) ;
    gCout.appendCString ("')\n") ;
    p = p->mNext ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::releaseStrings (void) {
  C_StringCommandLineOption * p = gFirstStringOption ;
  while (p != nullptr) {
    p->mValue.removeAll () ;
    p = p->mNext ;
  }
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gReleaseString (nullptr, C_StringCommandLineOption::releaseStrings) ;

//--------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::getStringOptionNameList (TC_UniqueArray <String> & outArray) {
  C_StringCommandLineOption * p = gFirstStringOption ;
  while (p != nullptr) {
    outArray.appendObject (p->mDomainName) ;
    outArray.appendObject (p->mIdentifier) ;
    p = p->mNext ;
  }
}

//--------------------------------------------------------------------------------------------------

utf32 C_StringCommandLineOption::getStringOptionInvocationLetter (const String & inDomainName,
                                                                  const String & inIdentifier) {
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

//--------------------------------------------------------------------------------------------------

String C_StringCommandLineOption::getStringOptionInvocationString (const String & inDomainName,
                                                                     const String & inIdentifier) {
  String result ;
  C_StringCommandLineOption * p = gFirstStringOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mCommandString ;
    p = p->mNext ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String C_StringCommandLineOption::getStringOptionCommentString (const String & inDomainName,
                                                                  const String & inIdentifier) {
  String result ;
  C_StringCommandLineOption * p = gFirstStringOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mComment ;
    p = p->mNext ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String C_StringCommandLineOption::getStringOptionValue (const String & inDomainName,
                                                          const String & inIdentifier) {
  String result ;
  C_StringCommandLineOption * p = gFirstStringOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mValue ;
    p = p->mNext ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void C_StringCommandLineOption::setStringOptionValue (const String & inDomainName,
                                                      const String & inIdentifier,
                                                      const String & inValue) {
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

//--------------------------------------------------------------------------------------------------
