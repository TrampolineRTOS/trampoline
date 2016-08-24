//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'GALGAS_string' : class of galgas string                                                                           *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1996, ..., 2016 Pierre Molinaro.                                                                     *
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
//---------------------------------------------------------------------------------------------------------------------*

#include "all-predefined-types.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/C_Compiler.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "strings/unicode_character_cpp.h"
#include "galgas2/C_galgas_io.h"
#include "files/C_FileManager.h"
#include "galgas2/F_verbose_output.h"

//---------------------------------------------------------------------------------------------------------------------*

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

//---------------------------------------------------------------------------------------------------------------------*

#ifndef COMPILE_FOR_WINDOWS
  #error COMPILE_FOR_WINDOWS is undefined
#endif

#if COMPILE_FOR_WINDOWS == 0
  #include <pwd.h>
#endif

#if COMPILE_FOR_WINDOWS == 1
  #include <Shlobj.h>
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     C++ Management                                                                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark C++ Management
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string::GALGAS_string (void) :
mIsValid (false),
mString () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string::GALGAS_string (const C_String & inString) :
mIsValid (true),
mString (inString) {
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::drop (void) {
  mIsValid = false ;
  mString.releaseString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::makeEmptyString (void) {
  GALGAS_string result ;
  result.mIsValid = true ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_string::objectCompare (const GALGAS_string & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mString.compare (inOperand.mString) ;
    if (r < 0) {
      result = kFirstOperandLowerThanSecond ;
    }else if (r > 0) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}


//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::description (C_String & ioString,
                                 const int32_t /* inIndentation */) const {
  ioString << "<@string:" ;
  if (isValid ()) {
    ioString << "\"" << mString << "\"" ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const GALGAS_string & inString) {
  inStream << inString.stringValue () ;
  return inStream ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const GALGAS_lstring & inString) {
  inStream << inString.mAttribute_string.stringValue () ;
  return inStream ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     Constructors                                                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_newWithStdIn (UNUSED_LOCATION_ARGS) {
  return GALGAS_string (C_String::newWithStdIn ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_CppChar (const GALGAS_char & inCharacter
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inCharacter.isValid ()) {
    C_String s ;
    s.appendCLiteralCharConstant (inCharacter.charValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_CppLineComment (UNUSED_LOCATION_ARGS) {
  C_String s ; s.appendCppHyphenLineComment () ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_CppTitleComment (const GALGAS_string & inTitle
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inTitle.isValid ()) {
    C_String s ;
    s.appendCppTitleComment (inTitle.mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_CppSpaceComment (UNUSED_LOCATION_ARGS) {
  C_String s ; s.appendCppSpaceLineComment () ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_CppString (const GALGAS_string & inString
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inString.isValid ()) {
    C_String s ;
    s.appendCLiteralStringConstant (inString.mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#if COMPILE_FOR_WINDOWS == 0
  GALGAS_string GALGAS_string::constructor_homeDirectory (UNUSED_LOCATION_ARGS) {
    return GALGAS_string (getpwuid (getuid ())->pw_dir) ;
  }
#endif

#if COMPILE_FOR_WINDOWS == 1
  GALGAS_string GALGAS_string::constructor_homeDirectory (UNUSED_LOCATION_ARGS) {
    char path [MAX_PATH] ;
    SHGetFolderPath (NULL, CSIDL_PROFILE, NULL, 0, path) ;
    return GALGAS_string (path).getter_unixPathWithNativePath (HERE) ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_string ("") ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithSequenceOfCharacters (const GALGAS_char & inCharacter,
                                                                         const GALGAS_uint & inCount
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if ((inCount.isValid ()) && (inCharacter.isValid ())) {
    const utf32 character = inCharacter.charValue () ;
    C_String s ;
    for (uint32_t i=0 ; i<inCount.uintValue () ; i++) {
      s.appendUnicodeCharacter (character COMMA_HERE) ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithSourceFilePath (C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  return GALGAS_string (inCompiler->sourceFilePath ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithContentsOfFile (const GALGAS_string & inFilePath,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inFilePath.isValid ()) {
    inCompiler->logFileRead (inFilePath.mString) ;
    if (C_FileManager::fileExistsAtPath (inFilePath.mString)) {
      result = GALGAS_string (C_FileManager::stringWithContentOfFile (inFilePath.mString)) ;
    }else{
      C_String message ;
      message << "cannot read '" << inFilePath.mString << "' file (does not exist)" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithCurrentDirectory (UNUSED_LOCATION_ARGS) {
  return GALGAS_string (C_FileManager::currentDirectory ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithEnvironmentVariable (const GALGAS_string & inEnvironmentVariableName,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inEnvironmentVariableName.isValid ()) {
    const char * value = ::getenv (inEnvironmentVariableName.mString.cString (HERE)) ;
    if (value == NULL) {
      C_String message ;
      message << "the '" << inEnvironmentVariableName.mString << "' environment variable does not exist" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = GALGAS_string (value) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (const GALGAS_string & inEnvironmentVariableName
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inEnvironmentVariableName.isValid ()) {
    const char * value = ::getenv (inEnvironmentVariableName.mString.cString (HERE)) ;
    result = GALGAS_string (value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_componentsJoinedByString (const GALGAS_stringlist & inComponents,
                                                                   const GALGAS_string & inSeparator
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if ((inComponents.isValid ()) && (inSeparator.isValid ())) {
    bool first = true ;
    C_String s ;
    cEnumerator_stringlist current (inComponents, kEnumeration_up) ;
    while (current.hasCurrentObject ()) {
      if (first) {
        first = false ;
      }else{
        s << inSeparator.mString ;
      }
      s << current.current_mValue (HERE).mString ;
      current.gotoNextObject () ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithCurrentDateTime (UNUSED_LOCATION_ARGS) {
  const time_t currentTime = ::time (NULL) ;
  char * timeString = NULL ;
  bool ok = currentTime >= 0 ;
  if (ok) {
    timeString = ::ctime (& currentTime) ;
    ok = timeString != NULL ;
    if (ok) {
      const size_t length = ::strlen (timeString) ;
      ok = length > 0 ;
      if (ok) {
        timeString [length - 1] = '\0' ; // Suppress trailing '\n'
      }
    }
  }
  return GALGAS_string (ok ? timeString : "") ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_retrieveAndResetTemplateString (C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  return inCompiler->retrieveAndResetTemplateString () ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::constructor_stringWithSymbolicLinkContents (const GALGAS_string & inSymbolicLink,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inSymbolicLink.isValid ()) {
    bool ok = false ;
    const C_String r = C_FileManager::stringWithSymbolicLinkContents (inSymbolicLink.mString, ok) ;
    if (ok) {
      result = GALGAS_string (r) ;
    }else{
      C_String s ;
      s << "'@string stringWithSymbolicLinkContents' error; receiver's value '" << inSymbolicLink.mString << "' is not a symbolic link" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     Operators                                                                                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Operators
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::add_operation (const GALGAS_string & inOperand2,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_string (mString + inOperand2.mString) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::plusAssign_operation (GALGAS_string inOperand,
                                          C_Compiler *
                                          COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    mString << inOperand.mString ;
  }else{
    drop () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     Getters                                                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Getters
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_HTMLRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.HTMLRepresentation ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_string::getter_nowhere (LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (isValid ()) {
    result.mAttribute_string = * this ;
    result.mAttribute_location = GALGAS_location::constructor_nowhere (THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_string::getter_here (C_Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (isValid ()) {
    result.mAttribute_string = * this ;
    result.mAttribute_location = GALGAS_location::constructor_here (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::getter_fileExists (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (C_FileManager::fileExistsAtPath (mString)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::getter_directoryExists (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (C_FileManager::directoryExists (mString)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_string::getter_length (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint ((uint32_t) mString.length ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_range GALGAS_string::getter_range (UNUSED_LOCATION_ARGS) const {
  GALGAS_range result ;
  if (isValid ()) {
    result = GALGAS_range (GALGAS_uint (0), GALGAS_uint ((uint32_t) mString.length ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_md_35_ (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.md5 ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_utf_33__32_Representation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    C_String s ;
    s.appendUTF32LiteralStringConstant (mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_utf_38_Representation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    C_String s ;
    s.appendCLiteralStringConstant (mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_utf_38_RepresentationWithoutDelimiters (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    C_String s ;
    s.appendCLiteralStringConstantWithoutDelimiters (mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_identifierRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.identifierRepresentation ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_nameRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.nameRepresentation ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_assemblerRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.assemblerRepresentation ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_decodedStringFromRepresentation (C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    bool ok = true ;
    const C_String r = mString.decodedStringFromRepresentation (ok) ;
    if (ok) {
      result = GALGAS_string (r) ;
    }else{
      inCompiler->onTheFlyRunTimeError (
        "@string decodedStringFromRepresentation getter called with a string that is not a valid string representation"
        COMMA_THERE
      ) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_subStringFromIndex (const GALGAS_uint & inStartIndex
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inStartIndex.isValid ()) {
    result = GALGAS_string (mString.subStringFromIndex ((int32_t) inStartIndex.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_rightSubString (const GALGAS_uint & inLength
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inLength.isValid ()) {
    result = GALGAS_string (mString.rightSubString ((int32_t) inLength.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_leftSubString (const GALGAS_uint & inLength
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inLength.isValid ()) {
    result = GALGAS_string (mString.leftSubString ((int32_t) inLength.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_subString (const GALGAS_uint & inStart,
                                               const GALGAS_uint & inLength
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inStart.isValid ()) && (inLength.isValid ())) {
    const int32_t start = (int32_t) inStart.uintValue () ;
    const int32_t aLength = (int32_t) inLength.uintValue () ;
    result = GALGAS_string (mString.subString (start, aLength)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_absolutePathFromPath (const GALGAS_string & inBasePath
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inBasePath.isValid ()) {
    const C_String path = mString ;
    const int32_t stringLength = path.length () ;
    C_String r ;
    if ((stringLength > 0) && (UNICODE_VALUE (path (0 COMMA_HERE)) == '/')) {
      r = path ;
    }else{
      r = inBasePath.mString ;
      r.appendUnicodeCharacter (TO_UNICODE ('/') COMMA_HERE) ;
      r.appendString (path) ;
    }
    result = GALGAS_string (r.stringByStandardizingPath ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_relativePathFromPath (const GALGAS_string & inReferencePath
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inReferencePath.isValid ()) {
    result = GALGAS_string (C_FileManager::relativePathFromPath (mString, inReferencePath.mString)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_char GALGAS_string::getter_lastCharacter (C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_char result ;
  if (isValid ()) {
    if (mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError (
        "@string lastCharacter getter called on empty string"
        COMMA_THERE
      ) ;
    }else{
      result = GALGAS_char (mString.lastCharacter (THERE)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_stringByStandardizingPath (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByStandardizingPath ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_pathExtension (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.pathExtension ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_char GALGAS_string::getter_firstCharacterOrNul (UNUSED_LOCATION_ARGS) const {
  return GALGAS_char (mString.readCharOrNul (0 COMMA_HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_stringByDeletingPathExtension (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByDeletingPathExtension ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_stringByDeletingLastPathComponent (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByDeletingLastPathComponent ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_stringByCapitalizingFirstCharacter (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByCapitalizingFirstCharacter ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_uppercaseString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.uppercaseString ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_lowercaseString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.lowercaseString ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_reversedString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.reversedString ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_stringByTrimmingWhiteSpaces (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByTrimmingSeparators ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_string::getter_currentColumn (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mString.currentColumn ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_stringByLeftPadding (const GALGAS_uint & inPaddedStringLength,
                                                         const GALGAS_char & inPaddingChar
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inPaddedStringLength.isValid ()) && (inPaddingChar.isValid ())) {
    const utf32 paddingChar = inPaddingChar.charValue () ;
    const int32_t paddedStringLength = (int32_t) inPaddedStringLength.uintValue () ;
    const int32_t paddingLength = paddedStringLength - mString.length () ;
    C_String s ; s.setCapacity ((uint32_t) paddedStringLength) ;
    for (int32_t i=0 ; i<paddingLength ; i++) {
      s.appendUnicodeCharacter (paddingChar COMMA_HERE) ;
    }
    s << mString ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_stringByRightPadding (const GALGAS_uint & inPaddedStringLength,
                                                          const GALGAS_char & inPaddingChar
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inPaddedStringLength.isValid ()) && (inPaddingChar.isValid ())) {
    const utf32 paddingChar = inPaddingChar.charValue () ;
    const int32_t paddedStringLength = (int32_t) inPaddedStringLength.uintValue () ;
    const int32_t paddingLength = paddedStringLength - mString.length () ;
    C_String s ; s.setCapacity ((uint32_t) paddedStringLength) ;
    s << mString ;
    for (int32_t i=0 ; i<paddingLength ; i++) {
      s.appendUnicodeCharacter (paddingChar COMMA_HERE) ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_stringByLeftAndRightPadding (const GALGAS_uint & inPaddedStringLength,
                                                                 const GALGAS_char & inPaddingChar
                                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inPaddedStringLength.isValid ()) && (inPaddingChar.isValid ())) {
    const utf32 paddingChar = inPaddingChar.charValue () ;
    const int32_t paddedStringLength = (int32_t) inPaddedStringLength.uintValue () ;
    const int32_t paddingLength = paddedStringLength - mString.length () ;
    C_String s ; s.setCapacity ((uint32_t) paddedStringLength) ;
    for (int32_t i=0 ; i<(paddingLength / 2) ; i++) {
      s.appendUnicodeCharacter (paddingChar COMMA_HERE) ;
    }
    s << mString ;
    for (int32_t i=paddingLength / 2 ; i<paddingLength ; i++) {
      s.appendUnicodeCharacter (paddingChar COMMA_HERE) ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_lastPathComponent (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.lastPathComponent ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_stringByReplacingStringByString (const GALGAS_string & inSearchedString,
                                                                     const GALGAS_string & inReplacementString,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inSearchedString.isValid ()) && (inReplacementString.isValid ())) {
    if (inSearchedString.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError (
        "@string stringByReplacingStringByString getter called with empty searched string"
        COMMA_THERE
      ) ;
    }else{
      bool ok = false ;
      uint32_t replacementCount = 0 ;
      const C_String s = mString.stringByReplacingStringByString (inSearchedString.mString, inReplacementString.mString, replacementCount, ok) ;
      result = GALGAS_string (s) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_stringByRemovingCharacterAtIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inIndex.isValid ()) {
    if (inIndex.uintValue () < (uint32_t) mString.length ()) {
      C_String s = mString ;
      s.suppress ((int32_t) inIndex.uintValue (), 1 COMMA_THERE) ;
      result = GALGAS_string (s) ;
    }else{
      inCompiler->onTheFlyRunTimeError (
        "@string stringByRemovingCharacterAtIndex getter called with index greater or equal to length"
        COMMA_THERE
      ) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_char GALGAS_string::getter_characterAtIndex (const GALGAS_uint & inIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_char result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t idx = (int32_t) inIndex.uintValue () ;
    const int32_t stringLength = mString.length () ;
    if (idx >= stringLength) {
      C_String message ;
      message << "string index (" << cStringWithSigned (idx) << ") too large (string length: " << cStringWithSigned (stringLength) << ")" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = GALGAS_char (mString (idx COMMA_HERE)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::getter_containsCharacter (const GALGAS_char & inCharacter
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inCharacter.isValid ()) {
    result = GALGAS_bool (mString.containsCharacter (inCharacter.charValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::getter_containsCharacterInRange (const GALGAS_char & inFirstCharacter,
                                                            const GALGAS_char & inLastCharacter
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inFirstCharacter.isValid () && inLastCharacter.isValid ()) {
    result = GALGAS_bool (mString.containsCharacterInRange (inFirstCharacter.charValue (), inLastCharacter.charValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_unixPathWithNativePath (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (C_FileManager::unixPathWithNativePath (mString)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_string::getter_nativePathWithUnixPath (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (C_FileManager::nativePathWithUnixPath (mString)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::getter_componentsSeparatedByString (const GALGAS_string & inSeparator
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inSeparator.isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    TC_UniqueArray <C_String> components ;
    mString.componentsSeparatedByString (inSeparator.mString, components) ;
    for (int32_t i=0 ; i<components.count () ; i++) {
      result.addAssign_operation (GALGAS_string (components (i COMMA_HERE)) COMMA_HERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_string::getter_system (UNUSED_LOCATION_ARGS) const {
  return GALGAS_sint (::system (mString.cString (HERE))) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void recursiveSearchForRegularFiles (const C_String & inUnixStartPath,
                                            const bool inRecursiveSearch,
                                            const C_String & inRelativePath,
                                            GALGAS_stringlist & ioResult) {
  const C_String nativeStartPath = C_FileManager::nativePathWithUnixPath (inUnixStartPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if (current->d_name [0] != '.') {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (C_FileManager::directoryExists (name)) {
          if (inRecursiveSearch) {
            recursiveSearchForRegularFiles (name,
                                            inRecursiveSearch,
                                            inRelativePath + current->d_name + "/",
                                            ioResult) ;
          }
        }else if (C_FileManager::fileExistsAtPath (name)) {
          const C_String relativePath = inRelativePath + current->d_name ;
          ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::getter_regularFiles (const GALGAS_bool & inRecursiveSearch
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inRecursiveSearch.isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    recursiveSearchForRegularFiles (mString,
                                    inRecursiveSearch.boolValue (),
                                    "",
                                    result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void recursiveSearchForHiddenFiles (const C_String & inUnixStartPath,
                                           const bool inRecursiveSearch,
                                           const C_String & inRelativePath,
                                           GALGAS_stringlist & ioResult) {
  const C_String nativeStartPath = C_FileManager::nativePathWithUnixPath (inUnixStartPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if ((strlen (current->d_name) > 1) && (current->d_name [0] == '.') && (strcmp (current->d_name, "..") != 0)) {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (C_FileManager::directoryExists (name)) {
          if (inRecursiveSearch) {
            recursiveSearchForHiddenFiles (name,
                                           inRecursiveSearch,
                                           inRelativePath + current->d_name + "/",
                                           ioResult) ;
          }
        }else if (C_FileManager::fileExistsAtPath (name)) {
          const C_String relativePath = inRelativePath + current->d_name ;
          ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::getter_hiddenFiles (const GALGAS_bool & inRecursiveSearch
                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inRecursiveSearch.isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    recursiveSearchForHiddenFiles (mString,
                                   inRecursiveSearch.boolValue (),
                                   "",
                                   result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void recursiveSearchForDirectories (const C_String & inUnixStartPath,
                                           const bool inRecursiveSearch,
                                           const C_String & inRelativePath,
                                           GALGAS_stringlist & ioResult) {
  const C_String nativeStartPath = C_FileManager::nativePathWithUnixPath (inUnixStartPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if (current->d_name [0] != '.') {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (C_FileManager::directoryExists (name)) {
          const C_String relativePath = inRelativePath + current->d_name ;
          ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
          if (inRecursiveSearch) {
            recursiveSearchForDirectories (name,
                                           inRecursiveSearch,
                                           inRelativePath + current->d_name + "/",
                                           ioResult) ;
          }
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::getter_directories (const GALGAS_bool & inRecursiveSearch
                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inRecursiveSearch.isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    if (C_FileManager::directoryExists (mString)) {
      recursiveSearchForDirectories (mString,
                                     inRecursiveSearch.boolValue (),
                                     "",
                                     result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void recursiveSearchForRegularFiles (const C_String & inUnixStartPath,
                                            GALGAS_stringlist inExtensionList,
                                            const bool inRecursiveSearch,
                                            const C_String & inRelativePath,
                                            GALGAS_stringlist & ioResult) {
  const C_String nativeStartPath = C_FileManager::nativePathWithUnixPath (inUnixStartPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if (current->d_name [0] != '.') {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (C_FileManager::directoryExists (name)) {
          if (inRecursiveSearch) {
            recursiveSearchForRegularFiles (name,
                                            inExtensionList,
                                            inRecursiveSearch,
                                            inRelativePath + current->d_name + "/",
                                            ioResult) ;
          }
        }else if (C_FileManager::fileExistsAtPath (name)) {
          const C_String extension = name.pathExtension () ;
          bool extensionFound = false ;
          cEnumerator_stringlist currentExtension (inExtensionList, kEnumeration_up) ;
          while (currentExtension.hasCurrentObject () && ! extensionFound) {
            extensionFound = currentExtension.current_mValue (HERE).stringValue () == extension ;
            currentExtension.gotoNextObject () ;
          }
          if (extensionFound) {
            const C_String relativePath = inRelativePath + current->d_name ;
            ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
          }
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::getter_regularFilesWithExtensions (const GALGAS_bool & inRecursiveSearch,
                                                                      const GALGAS_stringlist & inExtensionList
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if ((inRecursiveSearch.isValid ()) && (inExtensionList.isValid ())) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    if (C_FileManager::directoryExists (mString)) {
      recursiveSearchForRegularFiles (mString,
                                      inExtensionList,
                                      inRecursiveSearch.boolValue (),
                                      "",
                                      result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void recursiveSearchForDirectories (const C_String & inUnixStartPath,
                                           GALGAS_stringlist inExtensionList,
                                           const bool inRecursiveSearch,
                                           const C_String & inRelativePath,
                                           GALGAS_stringlist & ioResult) {
  const C_String nativeStartPath = C_FileManager::nativePathWithUnixPath (inUnixStartPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if (current->d_name [0] != '.') {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (C_FileManager::directoryExists (name)) {
        //--- Look for extension
          const C_String extension = name.pathExtension () ;
          bool extensionFound = false ;
          cEnumerator_stringlist currentExtension (inExtensionList, kEnumeration_up) ;
          while (currentExtension.hasCurrentObject () && ! extensionFound) {
            extensionFound = currentExtension.current_mValue (HERE).stringValue () == extension ;
            currentExtension.gotoNextObject () ;
          }
          if (extensionFound) {
            const C_String relativePath = inRelativePath + current->d_name ;
            ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
          }
        //--- Recursive Search ?
          if (inRecursiveSearch) {
            recursiveSearchForDirectories (name,
                                           inExtensionList,
                                           inRecursiveSearch,
                                           inRelativePath + current->d_name + "/",
                                           ioResult) ;
          }
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_string::getter_directoriesWithExtensions (const GALGAS_bool & inRecursiveSearch,
                                                                   const GALGAS_stringlist & inExtensionList
                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if ((inRecursiveSearch.isValid ()) && (inExtensionList.isValid ())) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    if (C_FileManager::directoryExists (mString)) {
      recursiveSearchForDirectories (mString,
                                     inExtensionList,
                                     inRecursiveSearch.boolValue (),
                                     "",
                                     result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::getter_doesEnvironmentVariableExist (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (::getenv (mString.cString (HERE)) != NULL) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_string::getter_capacity (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint ((uint32_t) mString.capacity ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::getter_isDecimalUnsignedNumber (UNUSED_LOCATION_ARGS) const {
  bool isDecimalUnsignedNumber = true ;
  for (int32_t i=0 ; (i<mString.length ()) && isDecimalUnsignedNumber ; i++) {
    const utf32 c = mString (i COMMA_HERE) ;
    isDecimalUnsignedNumber = (UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9') ;
  }
  return GALGAS_bool (isDecimalUnsignedNumber) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_string::getter_decimalUnsignedNumber (C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  bool ok = true ;
  const uint32_t max = UINT32_MAX / 10 ;
  uint32_t decimalUnsignedValue = 0 ;
  for (int32_t i=0 ; (i<mString.length ()) && ok ; i++) {
    const utf32 c = mString (i COMMA_HERE) ;
    if ((UNICODE_VALUE (c) < '0') || (UNICODE_VALUE (c) > '9')) {
      inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal number: it contains a non-digit character" COMMA_THERE) ;
      ok = false ;
    }else{
      const uint32_t digit = UNICODE_VALUE (c) - '0' ;
      if (decimalUnsignedValue > max) {
        inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal number: number is > 2**32 - 1" COMMA_THERE) ;
        ok = false ;
      }else if ((decimalUnsignedValue == max) && (digit > (UINT32_MAX % 10))) {
        inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal number: number is > 2**32 - 1" COMMA_THERE) ;
        ok = false ;
      }else{
        decimalUnsignedValue = decimalUnsignedValue * 10 + digit ;
      }
    }
  }
  GALGAS_uint result ;
  if (ok) {
    result = GALGAS_uint (decimalUnsignedValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_string::getter_isSymbolicLink (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (C_FileManager::isSymbolicLink (mString)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Getter popen
#endif

//---------------------------------------------------------------------------------------------------------------------*

// http://msdn.microsoft.com/en-us/library/ms682499%28VS.85%29.aspx

#if COMPILE_FOR_WINDOWS == 1
  #include <windows.h>
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if COMPILE_FOR_WINDOWS == 1
  static bool CreateChildProcess (HANDLE g_hChildStd_OUT_Wr,
                                  HANDLE g_hChildStd_IN_Rd,
                                  const char * /* inCommandLine */) {
  //--- Create a child process that uses the previously created pipes for STDIN and STDOUT.
     TCHAR szCmdline [] = TEXT ("dir") ;
     TCHAR application [] = TEXT ("c:\\windows\\system32\\command.com") ;
  //--- Set up members of the PROCESS_INFORMATION structure. 
     PROCESS_INFORMATION piProcInfo ; 
     ZeroMemory (& piProcInfo, sizeof (PROCESS_INFORMATION)) ;
  //--- Set up members of the STARTUPINFO structure. 
     STARTUPINFO siStartInfo ;
     ZeroMemory (& siStartInfo, sizeof (STARTUPINFO)) ;
     siStartInfo.cb = sizeof (STARTUPINFO) ; 
     siStartInfo.hStdError = g_hChildStd_OUT_Wr ;
     siStartInfo.hStdOutput = g_hChildStd_OUT_Wr ;
     siStartInfo.hStdInput = g_hChildStd_IN_Rd ;
     siStartInfo.dwFlags |= STARTF_USESTDHANDLES ;
  //-- Create the child process. 
     const bool bSuccess = 0 != CreateProcess (
       application,   // Application 
       szCmdline,     // command line 
       NULL,          // process security attributes 
       NULL,          // primary thread security attributes 
       TRUE,          // handles are inherited 
       0,             // creation flags 
       NULL,          // use parent's environment 
       NULL,          // use parent's current directory 
       & siStartInfo, // STARTUPINFO pointer 
       & piProcInfo   // receives PROCESS_INFORMATION 
     ) ;
     if (bSuccess) {
     // Close handles to the child process and its primary thread.
     // Some applications might keep these handles to monitor the status
     // of the child process, for example. 
       CloseHandle (piProcInfo.hProcess) ;
       CloseHandle (piProcInfo.hThread) ;
     }else{ // CreateProcess Error
       DWORD error = GetLastError () ;
       printf ("'CreateProcess' error: %ld\n", error) ;
     }
   //---
     return bSuccess ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if COMPILE_FOR_WINDOWS == 1
  GALGAS_string GALGAS_string::getter_popen (C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
    GALGAS_string result ;
    if (isValid ()) {
    // Create a pipe for the child process's STDIN. 
      HANDLE g_hChildStd_OUT_Wr = NULL ;
      HANDLE g_hChildStd_OUT_Rd = NULL ;
      HANDLE g_hChildStd_IN_Wr = NULL ;
      HANDLE g_hChildStd_IN_Rd = NULL ;
      SECURITY_ATTRIBUTES saAttr ;
      saAttr.nLength = sizeof (SECURITY_ATTRIBUTES) ; 
      saAttr.bInheritHandle = TRUE ; 
      saAttr.lpSecurityDescriptor = NULL ; 
      C_String errorMessage ; 
      bool ok = 0 != CreatePipe (& g_hChildStd_OUT_Rd, & g_hChildStd_OUT_Wr, & saAttr, 0) ;
      if (! ok) {
        errorMessage << "@string popen: 'CreatePipe' error" ;
      }else{
        ok = SetHandleInformation (g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0) ;
        if (! ok) {
          errorMessage << "@string popen: 'SetHandleInformation' error" ;
        }      
      }
      if (ok) {
        ok = CreatePipe (& g_hChildStd_IN_Rd, & g_hChildStd_IN_Wr, & saAttr, 0) ;
        if (! ok) {
          errorMessage << "@string popen: 'CreatePipe (2)' error" ;
        }      
      }
      if (ok) {
        ok = SetHandleInformation (g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0) ;
        if (! ok) {
          errorMessage << "@string popen: 'SetHandleInformation (2)' error" ;
        }      
      }
      if (ok) {
        ok = CreateChildProcess (g_hChildStd_OUT_Wr, g_hChildStd_IN_Rd, mString.cString (HERE)) ;
        if (! ok) {
          errorMessage << "@string popen: 'CreateChildProcess' error" ;
        }      
      }
      if (! ok) {
        inCompiler->onTheFlyRunTimeError (errorMessage COMMA_THERE) ;
      }else{
        C_Data response ;
        bool loop = true ;
        while (loop) {
          const size_t kBufferSize = 1000 ;
          uint8_t buffer [kBufferSize] ;
          DWORD readLength = 0 ;
          loop = ReadFile (g_hChildStd_OUT_Rd, buffer, kBufferSize, & readLength, NULL) ;
          loop = readLength > 0 ;
          response.appendDataFromPointer (buffer, readLength) ;
        }
        C_String s ;
        C_String::parseUTF8 (response, 0, s) ;
        result = GALGAS_string (s) ;
      }
      CloseHandle (g_hChildStd_IN_Wr) ;
      CloseHandle (g_hChildStd_IN_Rd) ;
      CloseHandle (g_hChildStd_OUT_Wr) ;
      CloseHandle (g_hChildStd_OUT_Rd) ;
    }
    return result ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if COMPILE_FOR_WINDOWS == 0
  GALGAS_string GALGAS_string::getter_popen (C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
    GALGAS_string result ;
    if (isValid ()) {
      FILE * f = popen (mString.cString (HERE), "r") ;
      C_Data response ;
      bool loop = true ;
      while (loop) {
        const size_t kBufferSize = 1000 ;
        uint8_t buffer [kBufferSize] ;
        const size_t readLength = fread (buffer, 1, kBufferSize, f) ;
        loop = readLength > 0 ;
        response.appendDataFromPointer (buffer, (int32_t) readLength) ;
      }
      pclose (f) ;
      C_String s ;
      response.appendByte ('\0') ;
      C_String::parseUTF8 (response, 0, s) ;
      result = GALGAS_string (s) ;
    }
    return result ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     Methods                                                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Methods
#endif

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::method_makeDirectory (C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const bool ok = C_FileManager::makeDirectoryIfDoesNotExist (mString) ;
  if (! ok) {
    C_String message ;
    message << "cannot create '" << mString << "' directory" ;
    inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::method_makeDirectoryAndWriteToFile (GALGAS_string inFilePath,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
  //--- Make directory
    const C_String directory = inFilePath.mString.stringByDeletingLastPathComponent () ;
    bool ok = C_FileManager::makeDirectoryIfDoesNotExist (directory) ;
    if (! ok) {
      C_String message ;
      message << "cannot create '" << directory << "' directory" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      method_writeToFile (inFilePath, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::method_makeDirectoryAndWriteToExecutableFile (GALGAS_string inFilePath,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
  //--- Make directory
    const C_String directory = inFilePath.mString.stringByDeletingLastPathComponent () ;
    bool ok = C_FileManager::makeDirectoryIfDoesNotExist (directory) ;
    if (! ok) {
      C_String message ;
      message << "cannot create '" << directory << "' directory" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      method_writeToExecutableFile (inFilePath, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::method_writeToFile (GALGAS_string inFilePath,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
    if (C_Compiler::performGeneration ()) {
      const bool fileAlreadyExists = C_FileManager::fileExistsAtPath (inFilePath.mString) ;
      const bool verboseOptionOn = verboseOutput () ;
      const bool ok = C_FileManager::writeStringToFile (mString, inFilePath.mString) ;
      if (ok && verboseOptionOn && fileAlreadyExists) {
        ggs_printFileOperationSuccess (C_String ("Replaced '") + inFilePath.mString + "'.\n") ;
      }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
        ggs_printFileCreationSuccess (C_String ("Created '") + inFilePath.mString + "'.\n") ;
      }else if (! ok) {
        C_String message ;
        message << "cannot write '" << inFilePath.mString << "' file" ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }else{
      ggs_printWarning (NULL, C_IssueWithFixIt (), C_String ("Need to write '") + inFilePath.mString + "'.\n" COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::method_writeToFileWhenDifferentContents (GALGAS_string inFilePath,
                                                             GALGAS_bool & outFileWritten,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
    bool needToWrite = true ;
    const bool fileAlreadyExists = C_FileManager::fileExistsAtPath (inFilePath.mString) ;
    if (fileAlreadyExists) {
      inCompiler->logFileRead (inFilePath.mString) ;
      const C_String readContents = C_FileManager::stringWithContentOfFile (inFilePath.mString) ;
      needToWrite = mString.compare (readContents) != 0 ;
    }
    outFileWritten = GALGAS_bool (needToWrite) ;
    if (needToWrite) {
      if (C_Compiler::performGeneration ()) {
        const bool verboseOptionOn = verboseOutput () ;
        bool ok = C_FileManager::makeDirectoryIfDoesNotExist (inFilePath.mString.stringByDeletingLastPathComponent ()) ;
        if (! ok) {
          C_String message ;
          message << "cannot create '" << inFilePath.mString << "' directory" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
          outFileWritten.drop () ;
        }else{
          ok = C_FileManager::writeStringToFile (mString, inFilePath.mString) ;
          if (ok && verboseOptionOn && fileAlreadyExists) {
            ggs_printFileOperationSuccess (C_String ("Replaced '") + inFilePath.mString + "'.\n") ;
          }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
            ggs_printFileCreationSuccess (C_String ("Created '") + inFilePath.mString + "'.\n") ;
          }else if (! ok) {
            C_String message ;
            message << "cannot write '" << inFilePath.mString << "' file" ;
            inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
            outFileWritten.drop () ;
          }
        }
      }else{
        ggs_printWarning (NULL, C_IssueWithFixIt (), C_String ("Need to write '") + inFilePath.mString + "'.\n" COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::method_writeToExecutableFile (GALGAS_string inFilePath,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
 //   inCompiler->addDependancyOutputFilePath (inFilePath.mString) ;
    const bool fileAlreadyExists = C_FileManager::fileExistsAtPath (inFilePath.mString) ;
    if (C_Compiler::performGeneration ()) {
      const bool verboseOptionOn = verboseOutput () ;
      const bool ok = C_FileManager::writeStringToExecutableFile (mString, inFilePath.mString) ;
      if (ok && verboseOptionOn && fileAlreadyExists) {
        ggs_printFileOperationSuccess (C_String ("Replaced '") + inFilePath.mString + "'.\n") ;
      }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
        ggs_printFileCreationSuccess (C_String ("Created '") + inFilePath.mString + "'.\n") ;
      }else if (! ok) {
        C_String message ;
        message << "cannot write '" << inFilePath.mString << "' file" ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }else{
      ggs_printWarning (NULL, C_IssueWithFixIt (), C_String ("Need to write '") + inFilePath.mString + "'.\n" COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::method_writeToExecutableFileWhenDifferentContents (GALGAS_string inFilePath,
                                                                       GALGAS_bool & outFileWritten,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
    bool needToWrite = true ;
    const bool fileAlreadyExists = C_FileManager::fileExistsAtPath (inFilePath.mString) ;
    if (fileAlreadyExists) {
      inCompiler->logFileRead (inFilePath.mString) ;
      const C_String readContents = C_FileManager::stringWithContentOfFile (inFilePath.mString) ;
      needToWrite = mString.compare (readContents) != 0 ;
    }
    outFileWritten = GALGAS_bool (needToWrite) ;
    if (needToWrite) {
      if (C_Compiler::performGeneration ()) {
        const bool verboseOptionOn = verboseOutput () ;
        bool ok = C_FileManager::makeDirectoryIfDoesNotExist (inFilePath.mString.stringByDeletingLastPathComponent ()) ;
        if (! ok) {
          C_String message ;
          message << "cannot create '" << inFilePath.mString << "' directory" ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
          outFileWritten.drop () ;
        }else{
          ok = C_FileManager::writeStringToExecutableFile (mString, inFilePath.mString) ;
          if (ok && verboseOptionOn && fileAlreadyExists) {
            ggs_printFileOperationSuccess (C_String ("Replaced '") + inFilePath.mString + "'.\n") ;
          }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
            ggs_printFileCreationSuccess (C_String ("Created '") + inFilePath.mString + "'.\n") ;
          }else if (! ok) {
            C_String message ;
            message << "cannot write '" << inFilePath.mString << "' file" ;
            inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
            outFileWritten.drop () ;
          }
        }
      }else{
        ggs_printWarning (NULL, C_IssueWithFixIt (), C_String ("Need to write '") + inFilePath.mString + "'.\n" COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::method_makeSymbolicLinkWithPath (GALGAS_string inPath,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  if (isValid () && inPath.isValid ()) {
    const bool ok = C_FileManager::makeSymbolicLinkWithPath (inPath.mString, mString) ;
    if (! ok) {
        C_String s ;
        s << "'@string makeSymbolicLinkWithPath' error; cannot make a symbolic link with receiver's value '"
          << mString
          << "' and path given '" << inPath << "' by argument's value" ;
        inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     Setters                                                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Setters
#endif

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::setter_appendSpacesUntilColumn (GALGAS_uint inColumnIndex,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inColumnIndex.isValid ()) {
    mString.appendSpacesUntilColumn (inColumnIndex.uintValue ()) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::setter_setCapacity (GALGAS_uint inNewCapacity,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (inNewCapacity.isValid ()) {
    if (inNewCapacity.uintValue () <= ((uint32_t) INT32_MAX)) {
      mString.setCapacity (inNewCapacity.uintValue ()) ; 
    }else{
      C_String message ;
      message << "setCapacity argument value (" ;
      message.appendUnsigned (inNewCapacity.uintValue ()) ;
      message << ") too large (should be <= 2**31-1)" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    } 
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::setter_incIndentation (GALGAS_uint inIndentation,
                                           C_Compiler * /* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) {
  if (inIndentation.isValid ()) {
    mString.incIndentation ((int32_t) inIndentation.uintValue ()) ; 
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::setter_decIndentation (GALGAS_uint inIndentation,
                                           C_Compiler * /* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) {
  if (inIndentation.isValid ()) {
    mString.incIndentation (- ((int32_t) inIndentation.uintValue ())) ; 
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::setter_setCharacterAtIndex (GALGAS_char inCharacter,
                                                GALGAS_uint inIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if ((inCharacter.isValid ()) && (inIndex.isValid ())) {
    const int32_t idx = (int32_t) inIndex.uintValue () ;
    const int32_t stringLength = mString.length () ;
    if (idx >= stringLength) {
      C_String message ;
      message << "string index (" << cStringWithSigned (idx) << ") too large (string length: " << cStringWithSigned (stringLength) << ")" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      mString.setUnicodeCharacterAtIndex (inCharacter.charValue (), idx COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     Type methods                                                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Type methods
#endif


//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::class_method_deleteFile (GALGAS_string inFilePath,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    if (! C_Compiler::performGeneration ()) {
      ggs_printWarning (NULL, C_IssueWithFixIt (), C_String ("Need to delete '") + inFilePath.mString + "'.\n" COMMA_THERE) ;
    }else if (inFilePath.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("cannot perform file delete: file name is an empty string" COMMA_THERE) ;
    }else{
      const C_String errorMessage = C_FileManager::deleteFile (inFilePath.mString) ;
      if (errorMessage.length () == 0) {
        ggs_printFileOperationSuccess (C_String ("Deleted '") + inFilePath.mString + "'.\n") ;
      }else{
        C_String message ;
        message << "cannot perform delete '" << inFilePath.mString << "' file: " << errorMessage ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::class_method_deleteFileIfExists (GALGAS_string inFilePath,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if ((inFilePath.isValid ()) && C_FileManager::fileExistsAtPath (inFilePath.mString)) {
    class_method_deleteFile (inFilePath, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::class_method_removeEmptyDirectory (GALGAS_string inDirectoryPath,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  if (inDirectoryPath.isValid ()) {
    if (! C_Compiler::performGeneration ()) {
      ggs_printWarning (NULL, C_IssueWithFixIt (), C_String ("Need to remove directory '") + inDirectoryPath.mString + "'.\n" COMMA_THERE) ;
    }else if (inDirectoryPath.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("cannot perform directory removing: directory path is an empty string" COMMA_THERE) ;
    }else{
      const C_String errorMessage = C_FileManager::removeDirectory (inDirectoryPath.mString) ;
      if (errorMessage.length () > 0) {
        C_String message ;
        message << "cannot perform directory removing: " << errorMessage ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static C_String recursiveRemoveDirectory (const C_String & inUnixDirectoryPath) {
  C_String result ;
  const C_String nativeStartPath = C_FileManager::nativePathWithUnixPath (inUnixDirectoryPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while ((current != NULL) && (result.length () == 0)) {
      if ((strcmp (current->d_name, ".") != 0) && (strcmp (current->d_name, "..") != 0)) {
        C_String name = nativeStartPath ;
        name << "/" << current->d_name ;
        if (C_FileManager::directoryExists (name)) {
          recursiveRemoveDirectory (name) ;
        }else if (C_FileManager::fileExistsAtPath (name)) {
          result = C_FileManager::deleteFile (name) ;
        }
      }
      current = readdir (dir) ;
    }
  }
  closedir (dir) ;
  if (result.length () == 0) {
    result = C_FileManager::removeDirectory (inUnixDirectoryPath) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::class_method_removeDirectoryRecursively (GALGAS_string inDirectoryPath,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (inDirectoryPath.isValid ()) {
    if (! C_Compiler::performGeneration ()) {
      ggs_printWarning (NULL, C_IssueWithFixIt (), C_String ("Need to remove directory '") + inDirectoryPath.mString + "'.\n" COMMA_THERE) ;
    }else if (inDirectoryPath.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("cannot perform directory removing: directory path is an empty string" COMMA_THERE) ;
    }else{
      C_String errorMessage = recursiveRemoveDirectory (inDirectoryPath.mString) ;
      if (errorMessage.length () > 0) {
        C_String message ;
        message << "cannot perform directory removing: " << errorMessage ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::class_method_generateFile (GALGAS_string inStartPath,
                                               GALGAS_string inFileName,
                                               GALGAS_string inContents,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const bool built = (inStartPath.isValid ())
    && (inFileName.isValid ())
    && (inContents.isValid ())
  ;
  if (built) {
    TC_UniqueArray <C_String> directoriesToExclude ;
    inCompiler->generateFileFromPathes (inStartPath.mString,
                                        directoriesToExclude,
                                        inFileName.mString,
                                        inContents.mString) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_string::class_method_generateFileWithPattern (GALGAS_string inStartPath,
                                                          GALGAS_string inFileName,
                                                          GALGAS_string inLineCommentPrefix,
                                                          GALGAS_string inHeader,
                                                          GALGAS_string inDefaultUserZone1,
                                                          GALGAS_string inGeneratedZone2,
                                                          GALGAS_string inDefaultUserZone2,
                                                          GALGAS_string inGeneratedZone3,
                                                          GALGAS_bool inMakeExecutable,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const bool built = (inStartPath.isValid ())
    && (inFileName.isValid ())
    && (inLineCommentPrefix.isValid ())
    && (inDefaultUserZone1.isValid ())
    && (inHeader.isValid ())
    && (inDefaultUserZone2.isValid ())
    && (inDefaultUserZone2.isValid ())
    && (inGeneratedZone3.isValid ())
    && (inMakeExecutable.isValid ())
  ;
  if (built) {
    TC_UniqueArray <C_String> directoriesToExclude ;
    inCompiler->generateFileWithPatternFromPathes (
      inStartPath.mString,
      directoriesToExclude,
      inLineCommentPrefix.mString,
      inFileName.mString,
      inHeader.mString,
      inDefaultUserZone1.mString,
      inGeneratedZone2.mString,
      inDefaultUserZone2.mString,
      inGeneratedZone3.mString,
      inMakeExecutable.boolValue ()
    ) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
