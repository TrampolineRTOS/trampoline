//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  Generic Unsigned Command Line Interface Option                                                                     *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2018 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "command_line_interface/C_UIntCommandLineOption.h"
#include "strings/C_String.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include <string.h>

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static C_UIntCommandLineOption * gFirstIntOption ;
static C_UIntCommandLineOption * gLastIntOption ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_UIntCommandLineOption::C_UIntCommandLineOption (const char * inDomainName,
                                                  const char * inIdentifier,
                                                  const char inChar,
                                                  const char * inString,
                                                  const char * inComment,
                                                  const uint32_t inDefaultValue) :
C_CommandLineOption (inDomainName, inIdentifier, inChar, inString, inComment),
mNext (NULL),
mValue (inDefaultValue),
mDefaultValue (inDefaultValue) {
  if (NULL == gFirstIntOption) {
    gFirstIntOption = this ;
  }else{
    gLastIntOption->mNext = this ;
  }
  gLastIntOption = this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_UIntCommandLineOption::
setUIntOptionForCommandChar (const char * inCommandCommandLineOptionString,
                             bool & outFound,
                             bool & outCommandLineOptionStringIsValid) {
  const uint32_t optionLength = (uint32_t) (strlen (inCommandCommandLineOptionString) & UINT32_MAX) ;
  outCommandLineOptionStringIsValid = (optionLength > 2) && (inCommandCommandLineOptionString [1] == '=') ;
  uint32_t optionValue = 0 ;
  for (uint32_t i=2 ; (i<optionLength) && outCommandLineOptionStringIsValid ; i++) {
    outCommandLineOptionStringIsValid = (inCommandCommandLineOptionString [i] >= '0') && (inCommandCommandLineOptionString [i] <= '9') ;
    optionValue *= 10 ;
    optionValue += (uint32_t) (inCommandCommandLineOptionString [i] - '0') ;
  }
  outFound = false ;
  C_UIntCommandLineOption * p = gFirstIntOption ;
  if (outCommandLineOptionStringIsValid) {
    while ((p != NULL) && ! outFound) {
      outFound = inCommandCommandLineOptionString [0] == p->mCommandChar ;
      if (outFound) {
        p->mValue = optionValue ;
      }
      p = p->mNext ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_UIntCommandLineOption::
setUIntOptionForCommandString (const char * inCommandCommandLineOptionString,
                               bool & outFound,
                               bool & outCommandLineOptionStringIsValid) {
  const uint32_t optionLength = (uint32_t) (strlen (inCommandCommandLineOptionString) & UINT32_MAX) ;
  outCommandLineOptionStringIsValid = optionLength > 2 ;
//--- Find '=' character
  uint32_t equalSignIndex = 0 ;
  if (outCommandLineOptionStringIsValid) {
    bool found = false ;
    while ((equalSignIndex < optionLength) && outCommandLineOptionStringIsValid && !found) {
      found = inCommandCommandLineOptionString [equalSignIndex] == '=' ;
      if (! found) {
        equalSignIndex ++ ;
      }
    }
    outCommandLineOptionStringIsValid = found && (equalSignIndex > 0) && (equalSignIndex < (optionLength - 1)) ;
  }
//--- Compute option value
  uint32_t optionValue = 0 ;
  for (uint32_t i=equalSignIndex+1 ; (i<optionLength) && outCommandLineOptionStringIsValid ; i++) {
    outCommandLineOptionStringIsValid = (inCommandCommandLineOptionString [i] >= '0') && (inCommandCommandLineOptionString [i] <= '9') ;
    optionValue *= 10 ;
    optionValue += (uint32_t) (inCommandCommandLineOptionString [i] - '0') ;
  }
//--- Search option
  outFound = false ;
  if (outCommandLineOptionStringIsValid) {
    C_UIntCommandLineOption * p = gFirstIntOption ;
    while ((p != NULL) && ! outFound) {
      outFound = (strlen (p->mCommandString) == equalSignIndex) && 
                  (strncmp (inCommandCommandLineOptionString, p->mCommandString, equalSignIndex) == 0) ;
      if (outFound) {
        p->mValue = optionValue ;
      }
      p = p->mNext ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_UIntCommandLineOption::printUsageOfUIntOptions (void) {
  C_UIntCommandLineOption * p = gFirstIntOption ;
  while (p != NULL) {
    const char c = p->mCommandChar ;
    if (c != '\0') {
      printf (" [-%c=number]", c) ;
    }
    const char * s = p->mCommandString ;
    if (s [0] != 0) {
      printf (" [--%s=number]", s) ;
    }
    p = p->mNext ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_UIntCommandLineOption::printUIntOptions (void) {
  C_UIntCommandLineOption * p = gFirstIntOption ;
  while (p != NULL) {
    if (p->mCommandChar != '\0') {
      co.setForeColor (kBlueForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << "-" << cStringWithCharacter (p->mCommandChar) << "=number" ;
      co.setTextAttribute (kAllAttributesOff) ;
      co << "\n" ;
    }
    if (p->mCommandString [0] != '\0') {
      co.setForeColor (kBlueForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << "--" << p->mCommandString << "=number" ;
      co.setTextAttribute (kAllAttributesOff) ;
      co << "\n" ;
    }
    co << "    " << p->mComment << " (default value: "
       << cStringWithUnsigned (p->mDefaultValue)
       << ")\n" ;
    p = p->mNext ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_UIntCommandLineOption::getUIntOptionNameList (TC_UniqueArray <C_String> & outArray) {
  C_UIntCommandLineOption * p = gFirstIntOption ;
  while (p != NULL) {
    outArray.appendObject (p->mDomainName) ;
    outArray.appendObject (p->mIdentifier) ;
    p = p->mNext ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

utf32 C_UIntCommandLineOption::getUIntOptionInvocationLetter (const C_String & inDomainName,
                                                       const C_String & inIdentifier) {
  utf32 result = TO_UNICODE (0) ;
  C_UIntCommandLineOption * p = gFirstIntOption ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = TO_UNICODE ((uint32_t) p->mCommandChar) ;
    p = p->mNext ;
}
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_UIntCommandLineOption::getUIntOptionInvocationString (const C_String & inDomainName,
                                                       const C_String & inIdentifier) {
  C_String result ;
  C_UIntCommandLineOption * p = gFirstIntOption ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mCommandString ;
    p = p->mNext ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_UIntCommandLineOption::getUIntOptionCommentString (const C_String & inDomainName,
                                                       const C_String & inIdentifier) {
  C_String result ;
  C_UIntCommandLineOption * p = gFirstIntOption ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mComment ;
    p = p->mNext ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

uint32_t C_UIntCommandLineOption::getUIntOptionValue (const C_String & inDomainName,
                                                      const C_String & inIdentifier) {
  uint32_t result = 0 ;
  C_UIntCommandLineOption * p = gFirstIntOption ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mValue ;
    p = p->mNext ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_UIntCommandLineOption::setUIntOptionValue (const C_String & inDomainName,
                                                  const C_String & inIdentifier,
                                                  const uint32_t inValue) {
  C_UIntCommandLineOption * p = gFirstIntOption ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    if (found) {
      p->mValue = inValue ;
    }
    p = p->mNext ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
