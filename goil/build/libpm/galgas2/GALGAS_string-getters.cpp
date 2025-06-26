//--------------------------------------------------------------------------------------------------
//
//  'GALGAS_string' : class of galgas string
//
//  This file is part of libpm library
//
//  Copyright (C) 1996, ..., 2023 Pierre Molinaro.
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
#include "C_galgas_CLI_Options.h"
#include "Compiler.h"
#include "F_mainForLIBPM.h"
#include "F_Analyze_CLI_Options.h"
#include "unicode_character_cpp.h"
#include "C_galgas_io.h"
#include "FileManager.h"
#include "BinaryFileWrite.h"
#include "F_verbose_output.h"

//--------------------------------------------------------------------------------------------------

#include <math.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Getters
#endif

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_HTMLRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.HTMLRepresentation ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_string::getter_nowhere (LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (isValid ()) {
    result.mProperty_string = * this ;
    result.mProperty_location = GALGAS_location::class_func_nowhere (THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_string::getter_here (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (isValid ()) {
    result.mProperty_string = * this ;
    result.mProperty_location = GALGAS_location::class_func_here (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_fileExists (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (FileManager::fileExistsAtPath (mString)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_directoryExists (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (FileManager::directoryExists (mString)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_string::getter_count (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint ((uint32_t) mString.length ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_range GALGAS_string::getter_range (UNUSED_LOCATION_ARGS) const {
  GALGAS_range result ;
  if (isValid ()) {
    result = GALGAS_range (GALGAS_uint (0), GALGAS_uint ((uint32_t) mString.length ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_md_35_ (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.md5 ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_sha_32__35__36_ (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.sha256 ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_utf_33__32_Representation (const GALGAS_bool & inAppendZeroTerminator
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inAppendZeroTerminator.isValid ()) {
    String s ;
    s.appendUTF32LiteralStringConstant (mString, inAppendZeroTerminator.boolValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_utf_38_RepresentationEscapingQuestionMark (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    const bool escapeQuestionMark = true ;
    const String s = mString.utf8RepresentationEnclosedWithin ('"', escapeQuestionMark) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_utf_38_Representation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    const bool escapeQuestionMark = false ;
    const String s = mString.utf8RepresentationEnclosedWithin ('"', escapeQuestionMark) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_cStringRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    const bool escapeQuestionMark = true ;
    const String s = mString.utf8RepresentationEnclosedWithin ('"', escapeQuestionMark) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_utf_38_RepresentationEnclosedWithin (const GALGAS_char & inCharacter COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inCharacter.isValid ()) {
    const bool escapeQuestionMark = true ;
    const String s = mString.utf8RepresentationEnclosedWithin (inCharacter.charValue (), escapeQuestionMark) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_string::getter_utf_38_Length (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    U8Data data ;
    data.appendString (mString) ;
    result = GALGAS_uint (uint32_t (data.count ())) ;
  }
  return result ;
}


//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_utf_38_RepresentationWithoutDelimiters (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    String s ;
    s.appendStringAsCLiteralStringConstantWithoutDelimiters (mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_utf_38_RepresentationWithUnicodeEscaping (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.utf8RepresentationWithUnicodeEscaping ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_identifierRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.identifierRepresentation ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_nameRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.nameRepresentation ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_fileNameRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.fileNameRepresentation ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_assemblerRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mString.assemblerRepresentation ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_decodedStringFromRepresentation (Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    bool ok = true ;
    const String r = mString.decodedStringFromRepresentation (ok) ;
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

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_subStringFromIndex (const GALGAS_uint & inStartIndex
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inStartIndex.isValid ()) {
    result = GALGAS_string (mString.subStringFromIndex ((int32_t) inStartIndex.uintValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_rightSubString (const GALGAS_uint & inLength
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inLength.isValid ()) {
    result = GALGAS_string (mString.rightSubString ((int32_t) inLength.uintValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_leftSubString (const GALGAS_uint & inLength
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inLength.isValid ()) {
    result = GALGAS_string (mString.leftSubString ((int32_t) inLength.uintValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_absolutePathFromPath (const GALGAS_string & inBasePath
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inBasePath.isValid ()) {
    const String path = mString ;
    const int32_t stringLength = path.length () ;
    String r ;
    if ((stringLength > 0) && (UNICODE_VALUE (path.charAtIndex (0 COMMA_HERE)) == '/')) {
      r = path ;
    }else{
      r = inBasePath.mString ;
      r.appendChar (TO_UNICODE ('/')) ;
      r.appendString (path) ;
    }
    result = GALGAS_string (r.stringByStandardizingPath ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_relativePathFromPath (const GALGAS_string & inReferencePath
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inReferencePath.isValid ()) {
    result = GALGAS_string (FileManager::relativePathFromPath (mString, inReferencePath.mString)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_char GALGAS_string::getter_lastCharacter (Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_char result ;
  if (isValid ()) {
    if (mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError (
        "@string lastCharacter getter called on empty string"
        COMMA_THERE
      ) ;
    }else{
      result = GALGAS_char (mString.lastChar (THERE)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_stringByStandardizingPath (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByStandardizingPath ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_pathExtension (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.pathExtension ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_char GALGAS_string::getter_firstCharacterOrNul (UNUSED_LOCATION_ARGS) const {
  return GALGAS_char (mString.readCharOrNul (0 COMMA_HERE)) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_stringByDeletingPathExtension (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByDeletingPathExtension ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_stringByDeletingLastPathComponent (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByDeletingLastPathComponent ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_stringByCapitalizingFirstCharacter (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByCapitalizingFirstCharacter ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_uppercaseString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.uppercaseString ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_lowercaseString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.lowercaseString ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_reversedString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.reversedString ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_stringByTrimmingWhiteSpaces (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.stringByTrimmingSeparators ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_string::getter_currentColumn (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mString.currentColumn ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_stringByLeftPadding (const GALGAS_uint & inPaddedStringLength,
                                                         const GALGAS_char & inPaddingChar
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inPaddedStringLength.isValid ()) && (inPaddingChar.isValid ())) {
    const utf32 paddingChar = inPaddingChar.charValue () ;
    const int32_t paddedStringLength = (int32_t) inPaddedStringLength.uintValue () ;
    const int32_t paddingLength = paddedStringLength - mString.length () ;
    String s ; s.setCapacity (paddedStringLength) ;
    for (int32_t i=0 ; i<paddingLength ; i++) {
      s.appendChar (paddingChar) ;
    }
    s.appendString (mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_stringByRightPadding (const GALGAS_uint & inPaddedStringLength,
                                                          const GALGAS_char & inPaddingChar
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inPaddedStringLength.isValid ()) && (inPaddingChar.isValid ())) {
    const utf32 paddingChar = inPaddingChar.charValue () ;
    const int32_t paddedStringLength = (int32_t) inPaddedStringLength.uintValue () ;
    const int32_t paddingLength = paddedStringLength - mString.length () ;
    String s ; s.setCapacity (paddedStringLength) ;
    s.appendString (mString) ;
    for (int32_t i=0 ; i<paddingLength ; i++) {
      s.appendChar (paddingChar) ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_stringByLeftAndRightPadding (const GALGAS_uint & inPaddedStringLength,
                                                                 const GALGAS_char & inPaddingChar
                                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inPaddedStringLength.isValid ()) && (inPaddingChar.isValid ())) {
    const utf32 paddingChar = inPaddingChar.charValue () ;
    const int32_t paddedStringLength = (int32_t) inPaddedStringLength.uintValue () ;
    const int32_t paddingLength = paddedStringLength - mString.length () ;
    String s ; s.setCapacity (paddedStringLength) ;
    for (int32_t i=0 ; i<(paddingLength / 2) ; i++) {
      s.appendChar (paddingChar) ;
    }
    s.appendString (mString) ;
    for (int32_t i=paddingLength / 2 ; i<paddingLength ; i++) {
      s.appendChar (paddingChar) ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_lastPathComponent (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mString.lastPathComponent ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_stringByReplacingStringByString (const GALGAS_string & inSearchedString,
                                                                     const GALGAS_string & inReplacementString,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if ((inSearchedString.isValid ()) && (inReplacementString.isValid ())) {
    if (inSearchedString.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError (
        "@string stringByReplacingStringByString getter called with empty searched string"
        COMMA_THERE
      ) ;
    }else{
      uint32_t replacementCount = 0 ;
      const String s = mString.stringByReplacingStringByString (inSearchedString.mString, inReplacementString.mString, replacementCount) ;
      result = GALGAS_string (s) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_stringByRemovingCharacterAtIndex (const GALGAS_uint & inIndex,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (inIndex.isValid ()) {
    if (inIndex.uintValue () < (uint32_t) mString.length ()) {
      String s = mString ;
      s.removeCountFromIndex (1, int32_t (inIndex.uintValue ()) COMMA_THERE) ;
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

//--------------------------------------------------------------------------------------------------

GALGAS_char GALGAS_string::getter_characterAtIndex (const GALGAS_uint & inIndex,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_char result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t idx = (int32_t) inIndex.uintValue () ;
    const int32_t stringLength = mString.length () ;
    if (idx >= stringLength) {
      String message = "string index (" ;
      message.appendSigned (idx) ;
      message.appendCString (") too large (string length: ") ;
      message.appendSigned (stringLength) ;
      message.appendCString (")") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = GALGAS_char (mString.charAtIndex (idx COMMA_HERE)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_containsCharacter (const GALGAS_char & inCharacter
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inCharacter.isValid ()) {
    result = GALGAS_bool (mString.containsChar (inCharacter.charValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_containsCharacterInRange (const GALGAS_char & inFirstCharacter,
                                                            const GALGAS_char & inLastCharacter
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inFirstCharacter.isValid () && inLastCharacter.isValid ()) {
    result = GALGAS_bool (mString.containsCharInRange (inFirstCharacter.charValue (), inLastCharacter.charValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_unixPathWithNativePath (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (FileManager::unixPathWithNativePath (mString)) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_nativePathWithUnixPath (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (FileManager::nativePathWithUnixPath (mString)) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_string::getter_componentsSeparatedByString (const GALGAS_string & inSeparator
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inSeparator.isValid ()) {
    result = GALGAS_stringlist::class_func_emptyList (THERE) ;
    TC_UniqueArray <String> components ;
    mString.componentsSeparatedByString (inSeparator.mString, components) ;
    for (int32_t i=0 ; i<components.count () ; i++) {
      result.addAssign_operation (GALGAS_string (components (i COMMA_HERE)) COMMA_HERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_string::getter_system (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid ()) {
    result = GALGAS_sint (::system (mString.cString ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_string::getter_commandWithArguments (const GALGAS_stringlist & inArguments,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inArguments.isValid ()) {
    String command = String ("'") + mString + "'" ;
    for (uint32_t i=0 ; i<inArguments.count () ; i++) {
      command.appendCString (" '") ;
      command.appendString (inArguments.getter_mValueAtIndex (GALGAS_uint (i), inCompiler COMMA_THERE).stringValue ()) ;
      command.appendCString ("'") ;
    }
    result = GALGAS_sint (::system (command.cString ())) ;
  }
  return result ;
}

 //--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::getter_hiddenCommandWithArguments (const GALGAS_stringlist & inArguments,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inArguments.isValid ()) {
    String command = String ("'") + mString + "'" ;
    for (uint32_t i=0 ; i<inArguments.count () ; i++) {
      command.appendCString (" '") ;
      command.appendString (inArguments.getter_mValueAtIndex (GALGAS_uint (i), inCompiler COMMA_THERE).stringValue ()) ;
      command.appendCString ("'") ;
    }
    result = GALGAS_string (command).getter_popen (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

static void recursiveSearchForRegularFiles (const String & inUnixStartPath,
                                            const bool inRecursiveSearch,
                                            const String & inRelativePath,
                                            GALGAS_stringlist & ioResult) {
  const String nativeStartPath = FileManager::nativePathWithUnixPath (inUnixStartPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString ()) ;
  if (dir != nullptr) {
    struct dirent  * current = readdir (dir) ;
    while (current != nullptr) {
      if (current->d_name [0] != '.') {
        String name = nativeStartPath ;
        name.appendCString ("/") ;
        name.appendString (current->d_name) ;
        if (FileManager::directoryExistsWithNativePath (name)) {
          if (inRecursiveSearch) {
            recursiveSearchForRegularFiles (name,
                                            inRecursiveSearch,
                                            inRelativePath + current->d_name + "/",
                                            ioResult) ;
          }
        }else if (FileManager::fileExistsAtPath (name)) {
          const String relativePath = inRelativePath + current->d_name ;
          ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
        }
      }
      current = readdir (dir) ;
    }
    closedir (dir) ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_string::getter_regularFiles (const GALGAS_bool & inRecursiveSearch
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inRecursiveSearch.isValid ()) {
    result = GALGAS_stringlist::class_func_emptyList (THERE) ;
    recursiveSearchForRegularFiles (mString,
                                    inRecursiveSearch.boolValue (),
                                    "",
                                    result) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

static void recursiveSearchForHiddenFiles (const String & inUnixStartPath,
                                           const bool inRecursiveSearch,
                                           const String & inRelativePath,
                                           GALGAS_stringlist & ioResult) {
  const String nativeStartPath = FileManager::nativePathWithUnixPath (inUnixStartPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString ()) ;
  if (dir != nullptr) {
    struct dirent  * current = readdir (dir) ;
    while (current != nullptr) {
      if ((strlen (current->d_name) > 1) && (current->d_name [0] == '.') && (strcmp (current->d_name, "..") != 0)) {
        String name = nativeStartPath ;
        name.appendCString ("/") ;
        name.appendString (current->d_name) ;
        if (FileManager::directoryExistsWithNativePath (name)) {
          if (inRecursiveSearch) {
            recursiveSearchForHiddenFiles (name,
                                           inRecursiveSearch,
                                           inRelativePath + current->d_name + "/",
                                           ioResult) ;
          }
        }else if (FileManager::fileExistsAtPath (name)) {
          const String relativePath = inRelativePath + current->d_name ;
          ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
        }
      }
      current = readdir (dir) ;
    }
    closedir (dir) ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_string::getter_hiddenFiles (const GALGAS_bool & inRecursiveSearch
                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inRecursiveSearch.isValid ()) {
    result = GALGAS_stringlist::class_func_emptyList (THERE) ;
    recursiveSearchForHiddenFiles (mString,
                                   inRecursiveSearch.boolValue (),
                                   "",
                                   result) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

static void recursiveSearchForDirectories (const String & inUnixStartPath,
                                           const bool inRecursiveSearch,
                                           const String & inRelativePath,
                                           GALGAS_stringlist & ioResult) {
  const String nativeStartPath = FileManager::nativePathWithUnixPath (inUnixStartPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString ()) ;
  if (dir != nullptr) {
    struct dirent  * current = readdir (dir) ;
    while (current != nullptr) {
      if (current->d_name [0] != '.') {
        String name = nativeStartPath ;
        name.appendCString ("/") ;
        name.appendString (current->d_name) ;
        if (FileManager::directoryExistsWithNativePath (name)) {
          const String relativePath = inRelativePath + current->d_name ;
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
    closedir (dir) ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_string::getter_directories (const GALGAS_bool & inRecursiveSearch
                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inRecursiveSearch.isValid ()) {
    result = GALGAS_stringlist::class_func_emptyList (THERE) ;
    if (FileManager::directoryExists (mString)) {
      recursiveSearchForDirectories (mString,
                                     inRecursiveSearch.boolValue (),
                                     "",
                                     result) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

static void recursiveSearchForRegularFiles (const String & inUnixStartPath,
                                            GALGAS_stringlist inExtensionList,
                                            const bool inRecursiveSearch,
                                            const String & inRelativePath,
                                            GALGAS_stringlist & ioResult) {
  const String nativeStartPath = FileManager::nativePathWithUnixPath (inUnixStartPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString ()) ;
  if (dir != nullptr) {
    struct dirent  * current = readdir (dir) ;
    while (current != nullptr) {
      if (current->d_name [0] != '.') {
        String name = nativeStartPath ;
        name.appendCString ("/") ;
        name.appendString (current->d_name) ;
        if (FileManager::directoryExistsWithNativePath (name)) {
          if (inRecursiveSearch) {
            recursiveSearchForRegularFiles (name,
                                            inExtensionList,
                                            inRecursiveSearch,
                                            inRelativePath + current->d_name + "/",
                                            ioResult) ;
          }
        }else if (FileManager::fileExistsAtPath (name)) {
          const String extension = name.pathExtension () ;
          bool extensionFound = false ;
          cEnumerator_stringlist currentExtension (inExtensionList, kENUMERATION_UP) ;
          while (currentExtension.hasCurrentObject () && ! extensionFound) {
            extensionFound = currentExtension.current_mValue (HERE).stringValue () == extension ;
            currentExtension.gotoNextObject () ;
          }
          if (extensionFound) {
            const String relativePath = inRelativePath + current->d_name ;
            ioResult.addAssign_operation (GALGAS_string (relativePath) COMMA_HERE) ;
          }
        }
      }
      current = readdir (dir) ;
    }
    closedir (dir) ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_string::getter_regularFilesWithExtensions (const GALGAS_bool & inRecursiveSearch,
                                                                    const GALGAS_stringlist & inExtensionList
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if ((inRecursiveSearch.isValid ()) && (inExtensionList.isValid ())) {
    result = GALGAS_stringlist::class_func_emptyList (THERE) ;
    if (FileManager::directoryExists (mString)) {
      recursiveSearchForRegularFiles (mString,
                                      inExtensionList,
                                      inRecursiveSearch.boolValue (),
                                      "",
                                      result) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

static void recursiveSearchForDirectories (const String & inUnixStartPath,
                                           GALGAS_stringlist inExtensionList,
                                           const bool inRecursiveSearch,
                                           const String & inRelativePath,
                                           GALGAS_stringlist & ioResult) {
  const String nativeStartPath = FileManager::nativePathWithUnixPath (inUnixStartPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString ()) ;
  if (dir != nullptr) {
    struct dirent  * current = readdir (dir) ;
    while (current != nullptr) {
      if (current->d_name [0] != '.') {
        String name = nativeStartPath ;
        name.appendCString ("/") ;
        name.appendString (current->d_name) ;
        if (FileManager::directoryExistsWithNativePath (name)) {
        //--- Look for extension
          const String extension = name.pathExtension () ;
          bool extensionFound = false ;
          cEnumerator_stringlist currentExtension (inExtensionList, kENUMERATION_UP) ;
          while (currentExtension.hasCurrentObject () && ! extensionFound) {
            extensionFound = currentExtension.current_mValue (HERE).stringValue () == extension ;
            currentExtension.gotoNextObject () ;
          }
          if (extensionFound) {
            const String relativePath = inRelativePath + current->d_name ;
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
    closedir (dir) ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_string::getter_directoriesWithExtensions (const GALGAS_bool & inRecursiveSearch,
                                                                   const GALGAS_stringlist & inExtensionList
                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (isValid () && inRecursiveSearch.isValid () && inExtensionList.isValid ()) {
    result = GALGAS_stringlist::class_func_emptyList (THERE) ;
    if (FileManager::directoryExists (mString)) {
      recursiveSearchForDirectories (mString,
                                     inExtensionList,
                                     inRecursiveSearch.boolValue (),
                                     "",
                                     result) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_doesEnvironmentVariableExist (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (::getenv (mString.cString ()) != nullptr) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_string::getter_capacity (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint ((uint32_t) mString.capacity ())  ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_isDecimalUnsignedNumber (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    uint32_t r = 0 ;
    bool ok = false ;
    mString.convertToUInt32 (r, ok) ;
    result = GALGAS_bool (ok) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_string::getter_decimalUnsignedNumber (Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    uint32_t r = 0 ;
    bool ok = false ;
    mString.convertToUInt32 (r, ok) ;
    if (ok) {
      result = GALGAS_uint (r) ;
    }else{
      inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal @uint number" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_isDecimalUnsigned_36__34_Number (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    uint64_t r = 0 ;
    bool ok = false ;
    mString.convertToUInt64 (r, ok) ;
    result = GALGAS_bool (ok) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_string::getter_decimalUnsigned_36__34_Number (Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid ()) {
    uint64_t r = 0 ;
    bool ok = false ;
    mString.convertToUInt64 (r, ok) ;
    if (ok) {
      result = GALGAS_uint_36__34_ (r) ;
    }else{
      inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal @uint64 number" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_isDecimalSignedNumber (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    int32_t r = 0 ;
    bool ok = false ;
    mString.convertToSInt32 (r, ok) ;
    result = GALGAS_bool (ok) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_string::getter_decimalSignedNumber (Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid ()) {
    int32_t r = 0 ;
    bool ok = false ;
    mString.convertToSInt32 (r, ok) ;
    if (ok) {
      result = GALGAS_sint (r) ;
    }else{
      inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal @sint number" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_isDecimalSigned_36__34_Number (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    int64_t r = 0 ;
    bool ok = false ;
    mString.convertToSInt64 (r, ok) ;
    result = GALGAS_bool (ok) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_string::getter_decimalSigned_36__34_Number (Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid ()) {
    int64_t r = 0 ;
    bool ok = false ;
    mString.convertToSInt64 (r, ok) ;
    if (ok) {
      result = GALGAS_sint_36__34_ (r) ;
    }else{
      inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal @sint64 number" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_isDecimalSignedBigInt (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    bool ok = mString.length () > 0 ;
  //--- Sign
    int32_t idx = 0 ;
    if (ok) {
      const utf32 c = mString.charAtIndex (0 COMMA_HERE) ;
      if ((UNICODE_VALUE (c) == '+') || (UNICODE_VALUE (c) == '-')) {
        idx = 1 ;
      }
    }
    while ((idx < mString.length ()) && ok) {
      const utf32 c = mString.charAtIndex (idx COMMA_HERE) ;
      idx += 1 ;
      ok = (UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9') ;
    }
    result = GALGAS_bool (ok) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bigint GALGAS_string::getter_decimalSignedBigInt (Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (isValid ()) {
    bool ok = false ;
    BigSigned bigint (mString.cString (), BigUnsignedBase::ten, ok) ;
    if (ok) {
      result = GALGAS_bigint (bigint) ;
    }else{
      inCompiler->onTheFlyRunTimeError ("cannot convert a string to a decimal @bigint number" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_string::getter_doubleNumber (Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    double doubleValue = 0.0 ;
    bool ok = true ;
    mString.convertToDouble (doubleValue, ok) ;
    if (ok) {
      result = GALGAS_double (doubleValue) ;
    }else{
      inCompiler->onTheFlyRunTimeError ("cannot convert a string to a double number: it contains invalid character" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_isDoubleNumber (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    double doubleValue = 0.0 ;
    bool ok = true ;
    mString.convertToDouble (doubleValue, ok) ;
    result = GALGAS_bool (ok) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_string::getter_isSymbolicLink (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (FileManager::isSymbolicLink (mString)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Getter popen
#endif

//--------------------------------------------------------------------------------------------------
// http://msdn.microsoft.com/en-us/library/ms682499%28VS.85%29.aspx

#if (COMPILE_FOR_WINDOWS == 1) || defined(__CYGWIN__)
  #include <windows.h>
  #include <iostream>

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
       nullptr,          // process security attributes
       nullptr,          // primary thread security attributes
       TRUE,          // handles are inherited
       0,             // creation flags
       nullptr,          // use parent's environment
       nullptr,          // use parent's current directory
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
       std::cout << "'CreateProcess' error: " << error << std::endl ;
     }
   //---
     return bSuccess ;
  }

  GALGAS_string GALGAS_string::getter_popen (Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
    GALGAS_string result ;
    if (isValid ()) {
    // Create a pipe for the child process's STDIN.
      HANDLE g_hChildStd_OUT_Wr = nullptr ;
      HANDLE g_hChildStd_OUT_Rd = nullptr ;
      HANDLE g_hChildStd_IN_Wr = nullptr ;
      HANDLE g_hChildStd_IN_Rd = nullptr ;
      SECURITY_ATTRIBUTES saAttr ;
      saAttr.nLength = sizeof (SECURITY_ATTRIBUTES) ;
      saAttr.bInheritHandle = TRUE ;
      saAttr.lpSecurityDescriptor = nullptr ;
      String errorMessage ;
      bool ok = 0 != CreatePipe (& g_hChildStd_OUT_Rd, & g_hChildStd_OUT_Wr, & saAttr, 0) ;
      if (! ok) {
        errorMessage.appendCString ("@string popen: 'CreatePipe' error") ;
      }else{
        ok = SetHandleInformation (g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0) ;
        if (! ok) {
          errorMessage.appendCString ("@string popen: 'SetHandleInformation' error") ;
        }
      }
      if (ok) {
        ok = CreatePipe (& g_hChildStd_IN_Rd, & g_hChildStd_IN_Wr, & saAttr, 0) ;
        if (! ok) {
          errorMessage.appendCString ("@string popen: 'CreatePipe (2)' error") ;
        }
      }
      if (ok) {
        ok = SetHandleInformation (g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0) ;
        if (! ok) {
          errorMessage.appendCString ("@string popen: 'SetHandleInformation (2)' error") ;
        }
      }
      if (ok) {
        ok = CreateChildProcess (g_hChildStd_OUT_Wr, g_hChildStd_IN_Rd, mString.cString ()) ;
        if (! ok) {
          errorMessage.appendCString ("@string popen: 'CreateChildProcess' error") ;
        }
      }
      if (! ok) {
        inCompiler->onTheFlyRunTimeError (errorMessage COMMA_THERE) ;
      }else{
        U8Data response ;
        bool loop = true ;
        while (loop) {
          const size_t kBufferSize = 1000 ;
          uint8_t buffer [kBufferSize] ;
          DWORD readLength = 0 ;
          loop = ReadFile (g_hChildStd_OUT_Rd, buffer, kBufferSize, & readLength, nullptr) ;
          loop = readLength > 0 ;
          response.appendDataFromPointer (buffer, readLength) ;
        }
        String s ;
        String::parseUTF8 (response, 0, s) ;
        result = GALGAS_string (s) ;
      }
      CloseHandle (g_hChildStd_IN_Wr) ;
      CloseHandle (g_hChildStd_IN_Rd) ;
      CloseHandle (g_hChildStd_OUT_Wr) ;
      CloseHandle (g_hChildStd_OUT_Rd) ;
    }
    return result ;
  }

#else

  GALGAS_string GALGAS_string::getter_popen (Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
    GALGAS_string result ;
    if (isValid ()) {
      FILE * f = popen (mString.cString (), "r") ;
      U8Data response ;
      bool loop = true ;
      while (loop) {
        const size_t kBufferSize = 1000 ;
        uint8_t buffer [kBufferSize] ;
        const size_t readLength = fread (buffer, 1, kBufferSize, f) ;
        loop = readLength > 0 ;
        response.appendDataFromPointer (buffer, (int32_t) readLength) ;
      }
      pclose (f) ;
      String s ;
      response.appendByte ('\0') ;
      String::parseUTF8 (response, 0, s) ;
      result = GALGAS_string (s) ;
    }
    return result ;
  }
#endif

//--------------------------------------------------------------------------------------------------
