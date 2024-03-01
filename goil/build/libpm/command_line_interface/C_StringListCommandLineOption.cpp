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

#include "C_StringListCommandLineOption.h"
#include "PrologueEpilogue.h"

//--------------------------------------------------------------------------------------------------

#include <string.h>

//--------------------------------------------------------------------------------------------------

static C_StringListCommandLineOption * gFirstStringListOption ;
static C_StringListCommandLineOption * gLastStringListOption ;

//--------------------------------------------------------------------------------------------------

C_StringListCommandLineOption::C_StringListCommandLineOption (const String & inDomainName,
                                                              const String & inIdentifier,
                                                              const char inChar,
                                                              const String & inString,
                                                              const String & inComment) :
C_CommandLineOption (inDomainName, inIdentifier, inChar, inString, inComment),
mNext (nullptr),
mValue () {
  if (nullptr == gFirstStringListOption) {
    gFirstStringListOption = this ;
  }else{
    gLastStringListOption->mNext = this ;
  }
  gLastStringListOption = this ;
}

//--------------------------------------------------------------------------------------------------

void C_StringListCommandLineOption::setStringListOptionForCommandChar (const String & inCommandString,
                                                                       bool & outFound,
                                                                       bool & outCommandLineOptionStringIsValid) {
  outCommandLineOptionStringIsValid = (inCommandString.length () > 2) && (inCommandString.charAtIndex (1 COMMA_HERE) == '=') ;
  outFound = false ;
  if (outCommandLineOptionStringIsValid) {
    C_StringListCommandLineOption * p = gFirstStringListOption ;
    while ((p != nullptr) && ! outFound) {
      outFound = UNICODE_VALUE (inCommandString.charAtIndex (0 COMMA_HERE)) == uint32_t (p->mCommandChar) ;
      if (outFound) {
        p->mValue.appendObject (inCommandString.subStringFromIndex (2)) ;
      }
      p = p->mNext ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_StringListCommandLineOption::setStringListOptionForCommandString (const String & inCommandString,
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
    C_StringListCommandLineOption * p = gFirstStringListOption ;
    while ((p != nullptr) && ! outFound) {
      outFound = p->mCommandString == command ;
      if (outFound) {
  //      p->mValue.appendObject (String (& inCommandString [p->mCommandString.length () + 1])) ;
        p->mValue.appendObject (inCommandString.subStringFromIndex (p->mCommandString.length () + 1)) ;
      }
      p = p->mNext ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_StringListCommandLineOption::printUsageOfStringOptions (void) {
  C_StringListCommandLineOption * p = gFirstStringListOption ;
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

void C_StringListCommandLineOption::printStringOptions (void) {
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  while (p != nullptr) {
    if (p->mCommandChar != '\0') {
      for (uint32_t i=0 ; i<2 ; i++) {
        if (i != 0) {
          gCout.appendCString (" ") ;
        }
        gCout.setForeColor (kBlueForeColor) ;
        gCout.setTextAttribute (kBoldTextAttribute) ;
        gCout.appendCString ("-") ;
        gCout.appendASCIIChar (p->mCommandChar) ;
        gCout.appendCString ("=string") ;
        gCout.setTextAttribute (kAllAttributesOff) ;
      }
      gCout.appendCString (" ...\n") ;
    }
    if (p->mCommandString.length () > 0) {
      for (uint32_t i=0 ; i<2 ; i++) {
        if (i != 0) {
          gCout.appendCString (" ") ;
        }
        gCout.setForeColor (kBlueForeColor) ;
        gCout.setTextAttribute (kBoldTextAttribute) ;
        gCout.appendCString ("--") ;
        gCout.appendString (p->mCommandString) ;
        gCout.appendCString ("=string") ;
        gCout.setTextAttribute (kAllAttributesOff) ;
      }
      gCout.appendCString (" ...\n") ;
    }
    gCout.appendCString ("    ") ;
    gCout.appendString (p->mComment) ;
    gCout.appendNewLine () ;
    p = p->mNext ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_StringListCommandLineOption::releaseStrings (void) {
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  while (p != nullptr) {
    p->mValue.free () ;
    p = p->mNext ;
  }
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gReleaseStringList (nullptr, C_StringListCommandLineOption::releaseStrings) ;

//--------------------------------------------------------------------------------------------------

void C_StringListCommandLineOption::getStringOptionNameList (TC_UniqueArray <String> & outArray) {
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  while (p != nullptr) {
    outArray.appendObject (p->mDomainName) ;
    outArray.appendObject (p->mIdentifier) ;
    p = p->mNext ;
  }
}

//--------------------------------------------------------------------------------------------------

utf32 C_StringListCommandLineOption::getStringOptionInvocationLetter (const String & inDomainName,
                                                                      const String & inIdentifier) {
  utf32 result = TO_UNICODE (0) ;
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == String (p->mDomainName)) && (inIdentifier == String (p->mIdentifier)) ;
    result = TO_UNICODE ((uint32_t) p->mCommandChar) ;
    p = p->mNext ;
}
  return result ;
}

//--------------------------------------------------------------------------------------------------

String C_StringListCommandLineOption::getStringOptionInvocationString (const String & inDomainName,
                                                                       const String & inIdentifier) {
  String result ;
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == String (p->mDomainName)) && (inIdentifier == String (p->mIdentifier)) ;
    result = p->mCommandString ;
    p = p->mNext ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String C_StringListCommandLineOption::getStringOptionCommentString (const String & inDomainName,
                                                                      const String & inIdentifier) {
  String result ;
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == String (p->mDomainName)) && (inIdentifier == String (p->mIdentifier)) ;
    result = p->mComment ;
    p = p->mNext ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
