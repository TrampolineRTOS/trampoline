//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  Generic Boolean Command Line Interface Option                                                                      *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2009 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

#include <string.h>
#include <stdio.h>

//----------------------------------------------------------------------------------------------------------------------

#include "command_line_interface/C_BoolCommandLineOption.h"
#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

static C_BoolCommandLineOption * gFirstBoolCommand ;
static C_BoolCommandLineOption * gLastBoolCommand ;

//----------------------------------------------------------------------------------------------------------------------

C_BoolCommandLineOption::C_BoolCommandLineOption (const char * inDomainName,
                                                  const char * inIdentifier,
                                                  const char inChar,
                                                  const char * inString,
                                                  const char * inComment,
                                                  const bool inVisibleInGalgas) :
C_CommandLineOption (inDomainName, inIdentifier, inChar, inString, inComment),
mNext (NULL),
mValue (false),
mVisibleInGalgas (inVisibleInGalgas) {
  if (NULL == gFirstBoolCommand) {
    gFirstBoolCommand = this ;
  }else{
    gLastBoolCommand->mNext = this ;
  }
  gLastBoolCommand = this ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BoolCommandLineOption::setBoolOptionForCommandChar (const char inCommandChar,
                                                           bool & outFound) {
  outFound = false ;
  C_BoolCommandLineOption * p = gFirstBoolCommand ;
  while ((p != NULL) && ! outFound) {
    if (p->mCommandChar == inCommandChar) {
      outFound = true ;
      p->mValue = true ;
    }
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_BoolCommandLineOption::setBoolOptionForCommandString (const char * inCommandString,
                                                             bool & outFound,
                                                             bool & outCocoaOutput) {
  outFound = strcmp (inCommandString, "cocoa") == 0 ;
  if (outFound) {
    outCocoaOutput = true ;
  }
  C_BoolCommandLineOption * p = gFirstBoolCommand ;
  while ((p != NULL) && ! outFound) {
    if (strcmp (p->mCommandString, inCommandString) == 0) {
      outFound = true ;
      p->mValue = true ;
    }
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_BoolCommandLineOption::printUsageOfBoolOptions (void) {
  C_BoolCommandLineOption * p = gFirstBoolCommand ;
  while (p != NULL) {
    const char c = p->mCommandChar ;
    if (c != '\0') {
      printf (" [-%c]", c) ;
    }
    const char * s = p->mCommandString ;
    if (s [0] != 0) {
      printf (" [--%s]", s) ;
    }
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_BoolCommandLineOption::printBoolOptions (const uint32_t inDisplayLength) {
  C_BoolCommandLineOption * p = gFirstBoolCommand ;
  while (p != NULL) {
    uint32_t charCount = 0 ;
    if (p->mCommandChar != '\0') {
      co.setForeColor (kBlueForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << "-" << cStringWithCharacter (p->mCommandChar) ;
      co.setTextAttribute (kAllAttributesOff) ;
      charCount += 2 ;
      if (p->mCommandString [0] != '\0') {
        co << ", " ;
        charCount += 2 ;
      }
    }
    if (p->mCommandString [0] != '\0') {
      co.setForeColor (kBlueForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << "--" << p->mCommandString ;
      co.setTextAttribute (kAllAttributesOff) ;
      charCount += 2 + (uint32_t) strlen (p->mCommandString) ;
    }
    if (charCount > inDisplayLength) {
      co << "\n" ;
      charCount = 0 ;
    }
    for (uint32_t i=charCount ; i<=inDisplayLength ; i++) {
      co << " " ;
    }
    co << p->mComment << "\n" ;
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_BoolCommandLineOption::getBoolOptionNameList (TC_UniqueArray <C_String> & outArray) {
  C_BoolCommandLineOption * p = gFirstBoolCommand ;
  while (p != NULL) {
    if (p->mVisibleInGalgas) {
      outArray.addObject (p->mDomainName) ;
      outArray.addObject (p->mIdentifier) ;
    }
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

utf32 C_BoolCommandLineOption::getBoolOptionInvocationLetter (const C_String & inDomainName,
                                                              const C_String & inIdentifier) {
  utf32 result = TO_UNICODE (0) ;
  C_BoolCommandLineOption * p = gFirstBoolCommand ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) && p->mVisibleInGalgas ;
    result = TO_UNICODE ((uint32_t) p->mCommandChar) ;
    p = p->mNext ;
}
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_BoolCommandLineOption::getBoolOptionInvocationString (const C_String & inDomainName,
                                                                 const C_String & inIdentifier) {
  C_String result ;
  C_BoolCommandLineOption * p = gFirstBoolCommand ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) && p->mVisibleInGalgas ;
    result = p->mCommandString ;
    p = p->mNext ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_BoolCommandLineOption::getBoolOptionCommentString (const C_String & inDomainName,
                                                              const C_String & inIdentifier) {
  C_String result ;
  C_BoolCommandLineOption * p = gFirstBoolCommand ;
  bool found = false ;
  while ((p != NULL) && not found) {
    found = (inDomainName == p->mDomainName) && (inIdentifier == p->mIdentifier) && p->mVisibleInGalgas ;
    result = p->mComment ;
    p = p->mNext ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
