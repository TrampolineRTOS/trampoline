//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  Generic String Command Line Interface Option                                                                       *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2017 Pierre Molinaro.                                                                     *
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

#include "command_line_interface/C_StringListCommandLineOption.h"
#include "utilities/C_PrologueEpilogue.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include <string.h>

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static C_StringListCommandLineOption * gFirstStringListOption ;
static C_StringListCommandLineOption * gLastStringListOption ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_StringListCommandLineOption::C_StringListCommandLineOption (const char * inDomainName,
                                                              const char * inIdentifier,
                                                              const char inChar,
                                                              const char * inString,
                                                              const char * inComment) :
C_CommandLineOption (inDomainName, inIdentifier, inChar, inString, inComment),
mNext (NULL),
mValue () {
  if (NULL == gFirstStringListOption) {
    gFirstStringListOption = this ;
  }else{
    gLastStringListOption->mNext = this ;
  }
  gLastStringListOption = this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_StringListCommandLineOption::setStringListOptionForCommandChar (const char * inCommandString,
                                                                       bool & outFound,
                                                                       bool & outCommandLineOptionStringIsValid) {
  outCommandLineOptionStringIsValid = (strlen (inCommandString) > 2) && (inCommandString [1] == '=') ;
  // printf ("[COMMAND STRING '%s', valid %d]\n", inCommandString, outCommandLineOptionStringIsValid) ;
  outFound = false ;
  if (outCommandLineOptionStringIsValid) {
    C_StringListCommandLineOption * p = gFirstStringListOption ;
    while ((p != NULL) && ! outFound) {
      outFound = inCommandString [0] == p->mCommandChar ;
      if (outFound) {
        p->mValue.appendObject (& inCommandString [2]) ;
      }
      p = p->mNext ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_StringListCommandLineOption::setStringListOptionForCommandString (const char * inCommandString,
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
    C_StringListCommandLineOption * p = gFirstStringListOption ;
    while ((p != NULL) && ! outFound) {
      outFound = (strlen (p->mCommandString) == equalSignIndex) && 
                 (strncmp (p->mCommandString, inCommandString, equalSignIndex) == 0) ;
      if (outFound) {
        p->mValue.appendObject (& inCommandString [strlen (p->mCommandString) + 1]) ;
      }
      p = p->mNext ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_StringListCommandLineOption::printUsageOfStringOptions (void) {
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  while (p != NULL) {
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_StringListCommandLineOption::printStringOptions (void) {
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  while (p != NULL) {
    if (p->mCommandChar != '\0') {
      for (uint32_t i=0 ; i<2 ; i++) {
        if (i != 0) {
          co << " " ;
        }
        co.setForeColor (kBlueForeColor) ;
        co.setTextAttribute (kBoldTextAttribute) ;
        co << "-" << cStringWithCharacter (p->mCommandChar) << "=string" ;
        co.setTextAttribute (kAllAttributesOff) ;
      }
      co << " ...\n" ;
    }
    if (p->mCommandString [0] != '\0') {
      for (uint32_t i=0 ; i<2 ; i++) {
        if (i != 0) {
          co << " " ;
        }
        co.setForeColor (kBlueForeColor) ;
        co.setTextAttribute (kBoldTextAttribute) ;
        co << "--" << p->mCommandString << "=string" ;
        co.setTextAttribute (kAllAttributesOff) ;
      }
      co << " ...\n" ;
    }
    co << "    " << p->mComment  << "\n" ;
    p = p->mNext ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_StringListCommandLineOption::releaseStrings (void) {
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  while (p != NULL) {
    p->mValue.free () ;
    p = p->mNext ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gReleaseStringList (NULL, C_StringListCommandLineOption::releaseStrings) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_StringListCommandLineOption::getStringOptionNameList (TC_UniqueArray <C_String> & outArray) {
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  while (p != NULL) {
    outArray.appendObject (p->mDomainName) ;
    outArray.appendObject (p->mIdentifier) ;
    p = p->mNext ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

utf32 C_StringListCommandLineOption::getStringOptionInvocationLetter (const C_String & inDomainName,
                                                                      const C_String & inIdentifier) {
  utf32 result = TO_UNICODE (0) ;
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = TO_UNICODE ((uint32_t) p->mCommandChar) ;
    p = p->mNext ;
}
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_StringListCommandLineOption::getStringOptionInvocationString (const C_String & inDomainName,
                                                                         const C_String & inIdentifier) {
  C_String result ;
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mCommandString ;
    p = p->mNext ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String C_StringListCommandLineOption::getStringOptionCommentString (const C_String & inDomainName,
                                                                      const C_String & inIdentifier) {
  C_String result ;
  C_StringListCommandLineOption * p = gFirstStringListOption ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) ;
    result = p->mComment ;
    p = p->mNext ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
