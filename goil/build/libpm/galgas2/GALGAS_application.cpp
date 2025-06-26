//--------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2010, ..., 2023 Pierre Molinaro.
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

#include "all-predefined-types.h"
#include "Compiler.h"
#include "C_BoolCommandLineOption.h"
#include "C_UIntCommandLineOption.h"
#include "C_StringCommandLineOption.h"
#include "F_Analyze_CLI_Options.h"
#include "F_verbose_output.h"
#include "cLexiqueIntrospection.h"

//--------------------------------------------------------------------------------------------------
//                     'GALGAS_application' class
//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_application::class_func_verboseOutput (UNUSED_LOCATION_ARGS) {
  return GALGAS_bool (verboseOutput ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_system (UNUSED_LOCATION_ARGS) {
  #if COMPILE_FOR_WINDOWS == 1
    return GALGAS_string ("windows") ;
  #else
    return GALGAS_string ("unix") ;
  #endif
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_stringlist GALGAS_application::class_func_boolOptionNameList (LOCATION_ARGS) {
  GALGAS__32_stringlist result = GALGAS__32_stringlist::class_func_emptyList (THERE) ;
  TC_UniqueArray <String> array ;
  C_BoolCommandLineOption::getBoolOptionNameList (array) ;
  for (int32_t i=0 ; i<array.count () ; i+=2) {
    result.addAssign_operation (GALGAS_string (array (i COMMA_THERE)), GALGAS_string (array (i+1 COMMA_THERE)) COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_char GALGAS_application::class_func_boolOptionInvocationCharacter (const GALGAS_string & inDomainName,
                                                                           const GALGAS_string & inIdentifier
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_char result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const utf32 c = C_BoolCommandLineOption::getBoolOptionInvocationLetter (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_char (c) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_boolOptionInvocationString (const GALGAS_string & inDomainName,
                                                                          const GALGAS_string & inIdentifier
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const String s = C_BoolCommandLineOption::getBoolOptionInvocationString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_boolOptionCommentString (const GALGAS_string & inDomainName,
                                                                       const GALGAS_string & inIdentifier
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const String s = C_BoolCommandLineOption::getBoolOptionCommentString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_application::class_func_boolOptionValue (const GALGAS_string & inDomainName,
                                                             const GALGAS_string & inIdentifier
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const bool v = C_BoolCommandLineOption::getBoolOptionValue (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_bool (v) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_application::class_method_setBoolOptionValue (GALGAS_string inDomainName,
                                                          GALGAS_string inIdentifier,
                                                          GALGAS_bool inValue
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  if (inDomainName.isValid () && inIdentifier.isValid () && inValue.isValid ()) {
    C_BoolCommandLineOption::setBoolOptionValue (inDomainName.stringValue (),
                                                 inIdentifier.stringValue (),
                                                 inValue.boolValue ()) ;
  }
}

//--------------------------------------------------------------------------------------------------
//   @UINT options                                                                               
//--------------------------------------------------------------------------------------------------

GALGAS__32_stringlist GALGAS_application::class_func_uintOptionNameList (LOCATION_ARGS) {
  GALGAS__32_stringlist result = GALGAS__32_stringlist::class_func_emptyList (THERE) ;
  TC_UniqueArray <String> array ;
  C_UIntCommandLineOption::getUIntOptionNameList (array) ;
  for (int32_t i=0 ; i<array.count () ; i+=2) {
    result.addAssign_operation (GALGAS_string (array (i COMMA_THERE)), GALGAS_string (array (i+1 COMMA_THERE)) COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


GALGAS_char GALGAS_application::class_func_uintOptionInvocationCharacter (const GALGAS_string & inDomainName,
                                                                           const GALGAS_string & inIdentifier
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_char result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const utf32 c = C_UIntCommandLineOption::getUIntOptionInvocationLetter (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_char (c) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_uintOptionInvocationString (const GALGAS_string & inDomainName,
                                                                          const GALGAS_string & inIdentifier
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const String s = C_UIntCommandLineOption::getUIntOptionInvocationString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_uintOptionCommentString (const GALGAS_string & inDomainName,
                                                                       const GALGAS_string & inIdentifier
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const String s = C_UIntCommandLineOption::getUIntOptionCommentString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_application::class_func_uintOptionValue (const GALGAS_string & inDomainName,
                                                             const GALGAS_string & inIdentifier
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const uint32_t v = C_UIntCommandLineOption::getUIntOptionValue (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_uint (v) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_application::class_method_setUIntOptionValue (GALGAS_string inDomainName,
                                                          GALGAS_string inIdentifier,
                                                          GALGAS_uint inValue
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  if (inDomainName.isValid () && inIdentifier.isValid () && inValue.isValid ()) {
    C_UIntCommandLineOption::setUIntOptionValue (inDomainName.stringValue (),
                                                 inIdentifier.stringValue (),
                                                 inValue.uintValue ()) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_application::class_method_exit (GALGAS_uint inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  if (inValue.isValid ()) {
    exit (int (inValue.uintValue ())) ;
  }else{
    exit (1) ;
  }
}

//--------------------------------------------------------------------------------------------------
//   STRING OPTION                                                                               
//--------------------------------------------------------------------------------------------------

GALGAS__32_stringlist GALGAS_application::class_func_stringOptionNameList (LOCATION_ARGS) {
  GALGAS__32_stringlist result = GALGAS__32_stringlist::class_func_emptyList (THERE) ;
  TC_UniqueArray <String> array ;
  C_StringCommandLineOption::getStringOptionNameList (array) ;
  for (int32_t i=0 ; i<array.count () ; i+=2) {
    result.addAssign_operation (GALGAS_string (array (i COMMA_THERE)), GALGAS_string (array (i+1 COMMA_THERE)) COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_char GALGAS_application::class_func_stringOptionInvocationCharacter (const GALGAS_string & inDomainName,
                                                                             const GALGAS_string & inIdentifier
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_char result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const utf32 c = C_StringCommandLineOption::getStringOptionInvocationLetter (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_char (c) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_stringOptionInvocationString (const GALGAS_string & inDomainName,
                                                                            const GALGAS_string & inIdentifier
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const String s = C_StringCommandLineOption::getStringOptionInvocationString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_stringOptionCommentString (const GALGAS_string & inDomainName,
                                                                         const GALGAS_string & inIdentifier
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const String s = C_StringCommandLineOption::getStringOptionCommentString (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_stringOptionValue (const GALGAS_string & inDomainName,
                                                                 const GALGAS_string & inIdentifier
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inDomainName.isValid () && inIdentifier.isValid ()) {
    const String v = C_StringCommandLineOption::getStringOptionValue (inDomainName.stringValue (), inIdentifier.stringValue ()) ;
    result = GALGAS_string (v) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_application::class_method_setStringOptionValue (GALGAS_string inDomainName,
                                                            GALGAS_string inIdentifier,
                                                            GALGAS_string inValue
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  if (inDomainName.isValid () && inIdentifier.isValid () && inValue.isValid ()) {
    C_StringCommandLineOption::setStringOptionValue (inDomainName.stringValue (),
                                                     inIdentifier.stringValue (),
                                                     inValue.stringValue ()) ;
  }
}

//--------------------------------------------------------------------------------------------------
//  Version strings
//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_projectVersionString (UNUSED_LOCATION_ARGS) {
  return GALGAS_string (projectVersionString ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_galgasVersionString (UNUSED_LOCATION_ARGS) {
  return GALGAS_string (galgasVersionString ()) ;
}

//--------------------------------------------------------------------------------------------------
//  Command line arguments
//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_application::class_func_commandLineArgumentCount (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint (commandLineArgumentCount ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_application::class_func_commandLineArgumentAtIndex (const GALGAS_uint & inIndex,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < commandLineArgumentCount ()) {
      result = GALGAS_string (commandLineArgumentAtIndex (idx)) ;
    }else{
      String message ;
      message.appendCString ("@application.commandLineArgumentAtIndex: index ") ;
      message.appendUnsigned (idx) ;
      message.appendCString (" >= argument count = ") ;
      message.appendUnsigned (commandLineArgumentCount ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_application::class_func_keywordIdentifierSet (LOCATION_ARGS) {
  GALGAS_stringset result = GALGAS_stringset::class_func_emptySet (THERE) ;
  TC_UniqueArray <String> list ;
  cLexiqueIntrospection::getKeywordListNames (list) ;
  for (int32_t i=0 ; i < list.count () ; i++) {
    result.addAssign_operation (GALGAS_string (list (i COMMA_HERE)) COMMA_HERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_application::class_func_keywordListForIdentifier (const GALGAS_string & inIdentifier
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_stringlist result ;
  if (inIdentifier.isValid ()) {
    result = GALGAS_stringlist::class_func_emptyList (THERE) ;
    TC_UniqueArray <String> list ;
    bool found = false ;
    cLexiqueIntrospection::getKeywordListForIdentifier (inIdentifier.stringValue(), found, list) ;
    for (int32_t i=0 ; i < list.count () ; i++) {
      result.addAssign_operation (GALGAS_string (list (i COMMA_HERE)) COMMA_HERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
