//---------------------------------------------------------------------------*
//                                                                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2010, ..., 2012 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"
#include "galgas2/C_Compiler.h"
#include "command_line_interface/C_BoolCommandLineOption.h"
#include "command_line_interface/C_UIntCommandLineOption.h"
#include "command_line_interface/C_StringCommandLineOption.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                     'GALGAS_application' class                            *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_application::GALGAS_application (void) :
AC_GALGAS_root () {
}

//---------------------------------------------------------------------------*

GALGAS_application::GALGAS_application (const GALGAS_application & inSource) :
AC_GALGAS_root (inSource) {
}

//---------------------------------------------------------------------------*

GALGAS_application::~GALGAS_application (void) {
}

//---------------------------------------------------------------------------*

GALGAS_application & GALGAS_application::operator = (const GALGAS_application & /* inSource */) {
  return *this ;
}

//---------------------------------------------------------------------------*

typeComparisonResult GALGAS_application::objectCompare (const GALGAS_application & /* inOperand */) const {
  return kOperandNotValid ;
}

//---------------------------------------------------------------------------*

void GALGAS_application::description (C_String & ioString,
                                      const PMSInt32 /* inIndentation */) const {
  ioString << "<@application:not built>" ;
}

//---------------------------------------------------------------------------*

GALGAS__32_stringlist GALGAS_application::constructor_boolOptionNameList (LOCATION_ARGS) {
  GALGAS__32_stringlist result = GALGAS__32_stringlist::constructor_emptyList (THERE) ;
  TC_UniqueArray <C_String> array ;
  C_BoolCommandLineOption::getBoolOptionNameList (array) ;
  for (PMSInt32 i=0 ; i<array.count () ; i+=2) {
    result.addAssign_operation (GALGAS_string (array (i COMMA_THERE)), GALGAS_string (array (i+1 COMMA_THERE)) COMMA_THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_char GALGAS_application::constructor_boolOptionInvocationLetter (const GALGAS_string & inDomainName,
                                                                        const GALGAS_string & inIdentifier
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_char result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const utf32 c = C_BoolCommandLineOption::getBoolOptionInvocationLetter (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_char (c) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_application::constructor_boolOptionInvocationString (const GALGAS_string & inDomainName,
                                                                          const GALGAS_string & inIdentifier
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const C_String s = C_BoolCommandLineOption::getBoolOptionInvocationString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_application::constructor_boolOptionCommentString (const GALGAS_string & inDomainName,
                                                                       const GALGAS_string & inIdentifier
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const C_String s = C_BoolCommandLineOption::getBoolOptionCommentString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS__32_stringlist GALGAS_application::constructor_uintOptionNameList (LOCATION_ARGS) {
  GALGAS__32_stringlist result = GALGAS__32_stringlist::constructor_emptyList (THERE) ;
  TC_UniqueArray <C_String> array ;
  C_UIntCommandLineOption::getUIntOptionNameList (array) ;
  for (PMSInt32 i=0 ; i<array.count () ; i+=2) {
    result.addAssign_operation (GALGAS_string (array (i COMMA_THERE)), GALGAS_string (array (i+1 COMMA_THERE)) COMMA_THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_char GALGAS_application::constructor_uintOptionInvocationLetter (const GALGAS_string & inDomainName,
                                                                        const GALGAS_string & inIdentifier
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_char result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const utf32 c = C_UIntCommandLineOption::getUIntOptionInvocationLetter (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_char (c) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_application::constructor_uintOptionInvocationString (const GALGAS_string & inDomainName,
                                                                          const GALGAS_string & inIdentifier
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const C_String s = C_UIntCommandLineOption::getUIntOptionInvocationString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_application::constructor_uintOptionCommentString (const GALGAS_string & inDomainName,
                                                                       const GALGAS_string & inIdentifier
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const C_String s = C_UIntCommandLineOption::getUIntOptionCommentString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS__32_stringlist GALGAS_application::constructor_stringOptionNameList (LOCATION_ARGS) {
  GALGAS__32_stringlist result = GALGAS__32_stringlist::constructor_emptyList (THERE) ;
  TC_UniqueArray <C_String> array ;
  C_StringCommandLineOption::getStringOptionNameList (array) ;
  for (PMSInt32 i=0 ; i<array.count () ; i+=2) {
    result.addAssign_operation (GALGAS_string (array (i COMMA_THERE)), GALGAS_string (array (i+1 COMMA_THERE)) COMMA_THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_char GALGAS_application::constructor_stringOptionInvocationLetter (const GALGAS_string & inDomainName,
                                                                          const GALGAS_string & inIdentifier
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_char result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const utf32 c = C_StringCommandLineOption::getStringOptionInvocationLetter (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_char (c) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_application::constructor_stringOptionInvocationString (const GALGAS_string & inDomainName,
                                                                            const GALGAS_string & inIdentifier
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const C_String s = C_StringCommandLineOption::getStringOptionInvocationString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_application::constructor_stringOptionCommentString (const GALGAS_string & inDomainName,
                                                                         const GALGAS_string & inIdentifier
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const C_String s = C_StringCommandLineOption::getStringOptionCommentString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
