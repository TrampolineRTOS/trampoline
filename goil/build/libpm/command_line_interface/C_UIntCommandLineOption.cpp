//--------------------------------------------------------------------------------------------------
//
//  Generic Unsigned Command Line Interface Option
//
//  This file is part of libpm library
//
//  Copyright (C) 2009, ..., 2018 Pierre Molinaro.
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

#include "C_UIntCommandLineOption.h"
#include "String-class.h"

//--------------------------------------------------------------------------------------------------

#include <string.h>

//--------------------------------------------------------------------------------------------------

static C_UIntCommandLineOption * gFirstIntOption ;
static C_UIntCommandLineOption * gLastIntOption ;

//--------------------------------------------------------------------------------------------------

C_UIntCommandLineOption::C_UIntCommandLineOption (const char * inDomainName,
                                                  const char * inIdentifier,
                                                  const char inChar,
                                                  const char * inString,
                                                  const char * inComment,
                                                  const uint32_t inDefaultValue) :
C_CommandLineOption (inDomainName, inIdentifier, inChar, inString, inComment),
mNext (nullptr),
mValue (inDefaultValue),
mDefaultValue (inDefaultValue) {
  if (nullptr == gFirstIntOption) {
    gFirstIntOption = this ;
  }else{
    gLastIntOption->mNext = this ;
  }
  gLastIntOption = this ;
}

//--------------------------------------------------------------------------------------------------

void C_UIntCommandLineOption::
setUIntOptionForCommandChar (const String & inCommandCommandLineOptionString,
                             bool & outFound,
                             bool & outCommandLineOptionStringIsValid) {
  const int32_t optionLength = inCommandCommandLineOptionString.length () ;
  outCommandLineOptionStringIsValid = (optionLength > 2) && (inCommandCommandLineOptionString.charAtIndex (1 COMMA_HERE) == '=') ;
  uint32_t optionValue = 0 ;
  for (int32_t i=2 ; (i<optionLength) && outCommandLineOptionStringIsValid ; i++) {
    const uint32_t c = UNICODE_VALUE (inCommandCommandLineOptionString.charAtIndex (i COMMA_HERE)) ;
    outCommandLineOptionStringIsValid = (c >= '0') && (c <= '9') ;
    optionValue *= 10 ;
    optionValue += c - '0' ;
  }
  outFound = false ;
  C_UIntCommandLineOption * p = gFirstIntOption ;
  if (outCommandLineOptionStringIsValid) {
    while ((p != nullptr) && ! outFound) {
      outFound = UNICODE_VALUE (inCommandCommandLineOptionString.charAtIndex (0 COMMA_HERE)) == uint32_t (p->mCommandChar) ;
      if (outFound) {
        p->mValue = optionValue ;
      }
      p = p->mNext ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_UIntCommandLineOption::
setUIntOptionForCommandString (const String & inCommandCommandLineOptionString,
                               bool & outFound,
                               bool & outCommandLineOptionStringIsValid) {
  const int32_t optionLength = inCommandCommandLineOptionString.length () ;
  outCommandLineOptionStringIsValid = optionLength > 2 ;
//--- Find '=' character
  int32_t equalSignIndex = 0 ;
  if (outCommandLineOptionStringIsValid) {
    bool found = false ;
    while ((equalSignIndex < optionLength) && outCommandLineOptionStringIsValid && !found) {
      found = inCommandCommandLineOptionString.charAtIndex (equalSignIndex COMMA_HERE) == '=' ;
      if (! found) {
        equalSignIndex ++ ;
      }
    }
    outCommandLineOptionStringIsValid = found && (equalSignIndex > 0) && (equalSignIndex < (optionLength - 1)) ;
  }
//--- Compute option value
  uint32_t optionValue = 0 ;
  for (int32_t i=equalSignIndex+1 ; (i<optionLength) && outCommandLineOptionStringIsValid ; i++) {
    const uint32_t c = UNICODE_VALUE (inCommandCommandLineOptionString.charAtIndex (i COMMA_HERE)) ;
    outCommandLineOptionStringIsValid = (c >= '0') && (c <= '9') ;
    optionValue *= 10 ;
    optionValue += uint32_t (c - '0') ;
  }
//--- Search option
  outFound = false ;
  const String command = inCommandCommandLineOptionString.leftSubString (equalSignIndex) ;
  if (outCommandLineOptionStringIsValid) {
    C_UIntCommandLineOption * p = gFirstIntOption ;
    while ((p != nullptr) && ! outFound) {
      outFound = command == p->mCommandString ;
      if (outFound) {
        p->mValue = optionValue ;
      }
      p = p->mNext ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_UIntCommandLineOption::printUsageOfUIntOptions (void) {
  C_UIntCommandLineOption * p = gFirstIntOption ;
  while (p != nullptr) {
    const char c = p->mCommandChar ;
    if (c != '\0') {
      printf (" [-%c=number]", c) ;
    }
    if (p->mCommandString [0] != '\0') {
      printf (" [--%s=number]", p->mCommandString) ;
    }
    p = p->mNext ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_UIntCommandLineOption::printUIntOptions (void) {
  C_UIntCommandLineOption * p = gFirstIntOption ;
  while (p != nullptr) {
    if (p->mCommandChar != '\0') {
      gCout.setForeColor (kBlueForeColor) ;
      gCout.setTextAttribute (kBoldTextAttribute) ;
      gCout.appendCString ("-") ;
      gCout.appendASCIIChar (p->mCommandChar) ;
      gCout.appendCString ("=number") ;
      gCout.setTextAttribute (kAllAttributesOff) ;
      gCout.appendNewLine () ;
    }
    if (p->mCommandString [0] != '\0') {
      gCout.setForeColor (kBlueForeColor) ;
      gCout.setTextAttribute (kBoldTextAttribute) ;
      gCout.appendCString ("--") ;
      gCout.appendString (p->mCommandString) ;
      gCout.appendCString ("=number") ;
      gCout.setTextAttribute (kAllAttributesOff) ;
      gCout.appendNewLine () ;
    }
    gCout.appendCString ("    ") ;
    gCout.appendString (p->mComment) ;
    gCout.appendCString (" (default value: ") ;
    gCout.appendUnsigned (p->mDefaultValue) ;
    gCout.appendCString (")\n") ;
    p = p->mNext ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_UIntCommandLineOption::getUIntOptionNameList (TC_UniqueArray <String> & outArray) {
  C_UIntCommandLineOption * p = gFirstIntOption ;
  while (p != nullptr) {
    outArray.appendObject (p->mDomainName) ;
    outArray.appendObject (p->mIdentifier) ;
    p = p->mNext ;
  }
}

//--------------------------------------------------------------------------------------------------

utf32 C_UIntCommandLineOption::getUIntOptionInvocationLetter (const String & inDomainName,
                                                       const String & inIdentifier) {
  utf32 result = TO_UNICODE (0) ;
  C_UIntCommandLineOption * p = gFirstIntOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = TO_UNICODE ((uint32_t) p->mCommandChar) ;
    p = p->mNext ;
}
  return result ;
}

//--------------------------------------------------------------------------------------------------

String C_UIntCommandLineOption::getUIntOptionInvocationString (const String & inDomainName,
                                                       const String & inIdentifier) {
  String result ;
  C_UIntCommandLineOption * p = gFirstIntOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mCommandString ;
    p = p->mNext ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String C_UIntCommandLineOption::getUIntOptionCommentString (const String & inDomainName,
                                                       const String & inIdentifier) {
  String result ;
  C_UIntCommandLineOption * p = gFirstIntOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mComment ;
    p = p->mNext ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

uint32_t C_UIntCommandLineOption::getUIntOptionValue (const String & inDomainName,
                                                      const String & inIdentifier) {
  uint32_t result = 0 ;
  C_UIntCommandLineOption * p = gFirstIntOption ;
  bool found = false ;
  while ((p != nullptr) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mValue ;
    p = p->mNext ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void C_UIntCommandLineOption::setUIntOptionValue (const String & inDomainName,
                                                  const String & inIdentifier,
                                                  const uint32_t inValue) {
  C_UIntCommandLineOption * p = gFirstIntOption ;
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
