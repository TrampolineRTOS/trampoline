//--------------------------------------------------------------------------------------------------
//
//  'GALGAS_string' : class of galgas string
//
//  This file is part of libpm library
//
//  Copyright (C) 1996, ..., 2024 Pierre Molinaro.
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

#ifndef COMPILE_FOR_WINDOWS
  #error COMPILE_FOR_WINDOWS is undefined
#endif

#if COMPILE_FOR_WINDOWS == 0
  #include <pwd.h>
#endif

#if COMPILE_FOR_WINDOWS == 1
  #include <Shlobj.h>
#endif

//--------------------------------------------------------------------------------------------------
//     C++ Management
//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark C++ Management
#endif

//--------------------------------------------------------------------------------------------------

GALGAS_string::GALGAS_string (void) :
AC_GALGAS_root (),
mIsValid (false),
mString () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_string::GALGAS_string (const String & inString) :
AC_GALGAS_root (),
mIsValid (true),
mString (inString) {
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::drop (void) {
  mIsValid = false ;
  mString.removeAll () ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::makeEmptyString (void) {
  GALGAS_string result ;
  result.mIsValid = true ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

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


//--------------------------------------------------------------------------------------------------

void GALGAS_string::description (String & ioString,
                                 const int32_t /* inIndentation */) const {
  ioString.appendCString ("<@string:") ;
  if (isValid ()) {
    ioString.appendCString ("\"") ;
    ioString.appendString (mString) ;
    ioString.appendCString ("\"") ;
  }else{
    ioString.appendCString ("not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     Constructors
//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors
#endif

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_stringByRepeatingString (const GALGAS_string & inString,
                                                                 const GALGAS_uint & inCount
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inString.isValid () && inCount.isValid ()) {
    String s ;
    for (uint32_t i=0 ; i<inCount.uintValue () ; i++) {
      s.appendString (inString.stringValue ()) ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_newWithStdIn (UNUSED_LOCATION_ARGS) {
  return GALGAS_string (String::newWithStdIn ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_CppChar (const GALGAS_char & inCharacter
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inCharacter.isValid ()) {
    String s ;
    s.appendStringAsCLiteralCharConstant (inCharacter.charValue ()) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_CppLineComment (UNUSED_LOCATION_ARGS) {
  String s ; s.appendCppHyphenLineComment () ;
  return GALGAS_string (s) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_CppTitleComment (const GALGAS_string & inTitle
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inTitle.isValid ()) {
    String s ;
    s.appendCppTitleComment (inTitle.mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_CppSpaceComment (UNUSED_LOCATION_ARGS) {
  String s ; s.appendCppSpaceLineComment () ;
  return GALGAS_string (s) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_CppString (const GALGAS_string & inString
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inString.isValid ()) {
    String s ;
    s.appendStringAsCLiteralStringConstant (inString.mString) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 0
  GALGAS_string GALGAS_string::class_func_homeDirectory (UNUSED_LOCATION_ARGS) {
    return GALGAS_string (getpwuid (getuid ())->pw_dir) ;
  }
#endif

#if COMPILE_FOR_WINDOWS == 1
  GALGAS_string GALGAS_string::class_func_homeDirectory (UNUSED_LOCATION_ARGS) {
    char path [MAX_PATH] ;
    SHGetFolderPath (nullptr, CSIDL_PROFILE, nullptr, 0, path) ;
    return GALGAS_string (path).getter_unixPathWithNativePath (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_stringWithSequenceOfCharacters (const GALGAS_char & inCharacter,
                                                                        const GALGAS_uint & inCount
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if ((inCount.isValid ()) && (inCharacter.isValid ())) {
    const utf32 character = inCharacter.charValue () ;
    String s ;
    for (uint32_t i=0 ; i<inCount.uintValue () ; i++) {
      s.appendChar (character) ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_stringWithSourceFilePath (Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  return GALGAS_string (inCompiler->sourceFilePath ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_stringWithContentsOfFile (const GALGAS_string & inFilePath,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inFilePath.isValid ()) {
    inCompiler->logFileRead (inFilePath.mString) ;
    if (FileManager::fileExistsAtPath (inFilePath.mString)) {
      result = GALGAS_string (FileManager::stringWithContentOfFile (inFilePath.mString)) ;
    }else{
      String message = "cannot read '" ;
      message.appendString (inFilePath.mString) ;
      message.appendCString ("' file (does not exist)") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_stringWithCurrentDirectory (UNUSED_LOCATION_ARGS) {
  return GALGAS_string (FileManager::currentDirectory ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_stringWithEnvironmentVariable (const GALGAS_string & inEnvironmentVariableName,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inEnvironmentVariableName.isValid ()) {
    const char * value = ::getenv (inEnvironmentVariableName.mString.cString ()) ;
    if (value == nullptr) {
      String message = "the '" ;
      message.appendString (inEnvironmentVariableName.mString) ;
      message.appendCString ("' environment variable does not exist") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = GALGAS_string (value) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_stringWithEnvironmentVariableOrEmpty (const GALGAS_string & inEnvironmentVariableName
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inEnvironmentVariableName.isValid ()) {
    const char * value = ::getenv (inEnvironmentVariableName.mString.cString ()) ;
    result = GALGAS_string (value) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_componentsJoinedByString (const GALGAS_stringlist & inComponents,
                                                                  const GALGAS_string & inSeparator
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result ;
  if ((inComponents.isValid ()) && (inSeparator.isValid ())) {
    bool first = true ;
    String s ;
    cEnumerator_stringlist current (inComponents, kENUMERATION_UP) ;
    while (current.hasCurrentObject ()) {
      if (first) {
        first = false ;
      }else{
        s.appendString (inSeparator.mString) ;
      }
      s.appendString (current.current_mValue (HERE).mString) ;
      current.gotoNextObject () ;
    }
    result = GALGAS_string (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_stringWithCurrentDateTime (UNUSED_LOCATION_ARGS) {
  time_t currentTime = ::time (nullptr) ;
  struct tm currentTimeTM ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&currentTime, &currentTimeTM) ; // Mac, Linux
  #else
   ::localtime_s (&currentTimeTM, &currentTime) ; // Windows
  #endif
  char timeString [128] ;
  bool ok = currentTime >= 0 ;
  if (ok) {
    ::strftime (timeString, sizeof (timeString), "Www Mmm dd hh:mm:ss yyyy", & currentTimeTM) ;
  }
  return GALGAS_string (ok ? timeString : "") ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_retrieveAndResetTemplateString (Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  return inCompiler->retrieveAndResetTemplateString () ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_separatorString (Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  return inCompiler->separatorString () ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::class_func_stringWithSymbolicLinkContents (const GALGAS_string & inSymbolicLink,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (inSymbolicLink.isValid ()) {
    bool ok = false ;
    const String r = FileManager::stringWithSymbolicLinkContents (inSymbolicLink.mString, ok) ;
    if (ok) {
      result = GALGAS_string (r) ;
    }else{
      String s = "'@string stringWithSymbolicLinkContents' error; receiver's value '" ;
      s.appendString (inSymbolicLink.mString) ;
      s.appendCString ("' is not a symbolic link") ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     Operators
//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Operators
#endif

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::add_operation (const GALGAS_string & inOperand,
                                            Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_string (mString + inOperand.mString) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::plusAssign_operation (GALGAS_string inOperand,
                                          Compiler * /* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    mString.appendString (inOperand.mString) ;
  }else{
    drop () ;
  }
}

//--------------------------------------------------------------------------------------------------
//     Methods
//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Methods
#endif

//--------------------------------------------------------------------------------------------------

void GALGAS_string::method_makeDirectory (Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const bool ok = FileManager::makeDirectoryIfDoesNotExist (mString) ;
  if (! ok) {
    String message = "cannot create '" ;
    message.appendString (mString) ;
    message.appendCString ("' directory") ;
    inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::method_makeDirectoryAndWriteToFile (GALGAS_string inFilePath,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
  //--- Make directory
    const String directory = inFilePath.mString.stringByDeletingLastPathComponent () ;
    bool ok = FileManager::makeDirectoryIfDoesNotExist (directory) ;
    if (! ok) {
      String message = "cannot create '" ;
      message.appendString (directory) ;
      message.appendCString ("' directory") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      method_writeToFile (inFilePath, inCompiler COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::method_makeDirectoryAndWriteToExecutableFile (GALGAS_string inFilePath,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
  //--- Make directory
    const String directory = inFilePath.mString.stringByDeletingLastPathComponent () ;
    bool ok = FileManager::makeDirectoryIfDoesNotExist (directory) ;
    if (! ok) {
      String message = "cannot create '" ;
      message.appendString (directory) ;
      message.appendCString ("' directory") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      method_writeToExecutableFile (inFilePath, inCompiler COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::method_writeToFile (GALGAS_string inFilePath,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
    if (Compiler::performGeneration ()) {
      const bool fileAlreadyExists = FileManager::fileExistsAtPath (inFilePath.mString) ;
      const bool verboseOptionOn = verboseOutput () ;
      const bool ok = FileManager::writeStringToFile (mString, inFilePath.mString) ;
      if (ok && verboseOptionOn && fileAlreadyExists) {
        ggs_printFileOperationSuccess (String ("Replaced '") + inFilePath.mString + "'.\n") ;
      }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
        ggs_printFileCreationSuccess (String ("Created '") + inFilePath.mString + "'.\n") ;
      }else if (! ok) {
        String message = "cannot write '" ;
        message.appendString (inFilePath.mString) ;
        message.appendCString ("' file") ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }else{
      ggs_printWarning (inCompiler, SourceTextInString (), C_IssueWithFixIt (), String ("Need to write '") + inFilePath.mString + "'." COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::method_writeToFileWhenDifferentContents (GALGAS_string inFilePath,
                                                             GALGAS_bool & outFileWritten,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
    bool needToWrite = true ;
    const bool fileAlreadyExists = FileManager::fileExistsAtPath (inFilePath.mString) ;
    if (fileAlreadyExists) {
      inCompiler->logFileRead (inFilePath.mString) ;
      const String readContents = FileManager::stringWithContentOfFile (inFilePath.mString) ;
      needToWrite = mString.compare (readContents) != 0 ;
    }
    outFileWritten = GALGAS_bool (needToWrite) ;
    if (needToWrite) {
      if (Compiler::performGeneration ()) {
        const bool verboseOptionOn = verboseOutput () ;
        bool ok = FileManager::makeDirectoryIfDoesNotExist (inFilePath.mString.stringByDeletingLastPathComponent ()) ;
        if (! ok) {
          String message = "cannot create '" ;
          message.appendString (inFilePath.mString) ;
          message.appendCString ("' directory") ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
          outFileWritten.drop () ;
        }else{
          ok = FileManager::writeStringToFile (mString, inFilePath.mString) ;
          if (ok && verboseOptionOn && fileAlreadyExists) {
            ggs_printFileOperationSuccess (String ("Replaced '") + inFilePath.mString + "'.\n") ;
          }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
            ggs_printFileCreationSuccess (String ("Created '") + inFilePath.mString + "'.\n") ;
          }else if (! ok) {
            String message = "cannot write '" ;
            message.appendString (inFilePath.mString) ;
            message.appendCString ("' file") ;
            inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
            outFileWritten.drop () ;
          }
        }
      }else{
        ggs_printWarning (inCompiler, SourceTextInString (), C_IssueWithFixIt (), String ("Need to write '") + inFilePath.mString + "'." COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::method_writeToExecutableFile (GALGAS_string inFilePath,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
    const bool fileAlreadyExists = FileManager::fileExistsAtPath (inFilePath.mString) ;
    if (Compiler::performGeneration ()) {
      const bool verboseOptionOn = verboseOutput () ;
      const bool ok = FileManager::writeStringToExecutableFile (mString, inFilePath.mString) ;
      if (ok && verboseOptionOn && fileAlreadyExists) {
        ggs_printFileOperationSuccess (String ("Replaced '") + inFilePath.mString + "'.\n") ;
      }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
        ggs_printFileCreationSuccess (String ("Created '") + inFilePath.mString + "'.\n") ;
      }else if (! ok) {
        String message = "cannot write '" ;
        message.appendString (inFilePath.mString) ;
        message.appendCString ("' file") ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }else{
      ggs_printWarning (inCompiler, SourceTextInString (), C_IssueWithFixIt (), String ("Need to write '") + inFilePath.mString + "'." COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::method_writeToExecutableFileWhenDifferentContents (GALGAS_string inFilePath,
                                                                       GALGAS_bool & outFileWritten,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  if (isValid () && inFilePath.isValid ()) {
    bool needToWrite = true ;
    const bool fileAlreadyExists = FileManager::fileExistsAtPath (inFilePath.mString) ;
    if (fileAlreadyExists) {
      inCompiler->logFileRead (inFilePath.mString) ;
      const String readContents = FileManager::stringWithContentOfFile (inFilePath.mString) ;
      needToWrite = mString.compare (readContents) != 0 ;
    }
    outFileWritten = GALGAS_bool (needToWrite) ;
    if (needToWrite) {
      if (Compiler::performGeneration ()) {
        const bool verboseOptionOn = verboseOutput () ;
        bool ok = FileManager::makeDirectoryIfDoesNotExist (inFilePath.mString.stringByDeletingLastPathComponent ()) ;
        if (! ok) {
          String message = "cannot create '" ;
          message.appendString (inFilePath.mString) ;
          message.appendCString ("' directory") ;
          inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
          outFileWritten.drop () ;
        }else{
          ok = FileManager::writeStringToExecutableFile (mString, inFilePath.mString) ;
          if (ok && verboseOptionOn && fileAlreadyExists) {
            ggs_printFileOperationSuccess (String ("Replaced '") + inFilePath.mString + "'.\n") ;
          }else if (ok && verboseOptionOn && ! fileAlreadyExists) {
            ggs_printFileCreationSuccess (String ("Created '") + inFilePath.mString + "'.\n") ;
          }else if (! ok) {
            String message = "cannot write '" ;
            message.appendString (inFilePath.mString) ;
            message.appendCString ("' file") ;
            inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
            outFileWritten.drop () ;
          }
        }
      }else{
        ggs_printWarning (inCompiler, SourceTextInString (), C_IssueWithFixIt (), String ("Need to write '") + inFilePath.mString + "'." COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::method_makeSymbolicLinkWithPath (GALGAS_string inPath,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  if (isValid () && inPath.isValid ()) {
    const bool ok = FileManager::makeSymbolicLinkWithPath (inPath.mString, mString) ;
    if (! ok) {
        String s = "'@string makeSymbolicLinkWithPath' error; cannot make a symbolic link with receiver's value '" ;
        s.appendString (mString) ;
        s.appendCString ("' and path given '") ;
        s.appendString (inPath.mString) ;
        s.appendCString ("' by argument's value") ;
        inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------
//     Setters
//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Setters
#endif

//--------------------------------------------------------------------------------------------------

void GALGAS_string::setter_appendSpacesUntilColumn (GALGAS_uint inColumnIndex,
                                                    Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inColumnIndex.isValid ()) {
    mString.appendSpacesUntilColumn (inColumnIndex.uintValue ()) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::setter_setCapacity (GALGAS_uint inNewCapacity,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inNewCapacity.isValid ()) {
    if (inNewCapacity.uintValue () <= ((uint32_t) INT32_MAX)) {
      mString.setCapacity (int32_t (inNewCapacity.uintValue ())) ;
    }else{
      String message = "setCapacity argument value (" ;
      message.appendUnsigned (inNewCapacity.uintValue ()) ;
      message.appendCString (") too large (should be <= 2**31-1)") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::setter_incIndentation (GALGAS_uint inIndentation,
                                           Compiler * /* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inIndentation.isValid ()) {
    mString.incIndentation ((int32_t) inIndentation.uintValue ()) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::setter_decIndentation (GALGAS_uint inIndentation,
                                           Compiler * /* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inIndentation.isValid ()) {
    mString.incIndentation (- ((int32_t) inIndentation.uintValue ())) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::setter_setCharacterAtIndex (GALGAS_char inCharacter,
                                                GALGAS_uint inIndex,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && (inCharacter.isValid ()) && (inIndex.isValid ())) {
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
      mString.setCharAtIndex (inCharacter.charValue (), idx COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::setter_insertCharacterAtIndex (GALGAS_char inCharacter,
                                                   GALGAS_uint inIndex,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && (inCharacter.isValid ()) && (inIndex.isValid ())) {
    const int32_t idx = int32_t (inIndex.uintValue ()) ;
    const int32_t stringLength = mString.length () ;
    if (idx > stringLength) {
      String message = "string index (" ;
      message.appendSigned (idx) ;
      message.appendCString (") too large (string length: ") ;
      message.appendSigned (stringLength) ;
      message.appendCString (")") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      mString.insertCharacterAtIndex (inCharacter.charValue (), idx COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::setter_removeCharacterAtIndex (GALGAS_char & outChar,
                                                   GALGAS_uint inIndex,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  outChar.drop () ;
  if (isValid () && (inIndex.isValid ())) {
    const int32_t idx = int32_t (inIndex.uintValue ()) ;
    const int32_t stringLength = mString.length () ;
    if (idx >= stringLength) {
      String message = "string index (" ;
      message.appendSigned (idx) ;
      message.appendCString (") too large (string length: ") ;
      message.appendSigned (stringLength) ;
      message.appendCString (")") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      outChar = GALGAS_char (mString.charAtIndex (idx COMMA_HERE)) ;
      mString.removeCountFromIndex (1, idx COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------
//     Type methods
//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Type methods
#endif


//--------------------------------------------------------------------------------------------------

void GALGAS_string::class_method_deleteFile (GALGAS_string inFilePath,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    if (! Compiler::performGeneration ()) {
      ggs_printWarning (inCompiler, SourceTextInString (), C_IssueWithFixIt (), String ("Need to delete '") + inFilePath.mString + "'.\n" COMMA_THERE) ;
    }else if (inFilePath.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("cannot perform file delete: file name is an empty string" COMMA_THERE) ;
    }else{
      const String errorMessage = FileManager::deleteFile (inFilePath.mString) ;
      if (errorMessage.length () == 0) {
        ggs_printFileOperationSuccess (String ("Deleted '") + inFilePath.mString + "'.\n") ;
      }else{
        String message = "cannot perform delete '" ;
        message.appendString (inFilePath.mString) ;
        message.appendCString ("' file: ") ;
        message.appendString (errorMessage) ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::class_method_deleteFileIfExists (GALGAS_string inFilePath,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if ((inFilePath.isValid ()) && FileManager::fileExistsAtPath (inFilePath.mString)) {
    class_method_deleteFile (inFilePath, inCompiler COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::class_method_removeEmptyDirectory (GALGAS_string inDirectoryPath,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  if (inDirectoryPath.isValid ()) {
    if (! Compiler::performGeneration ()) {
      ggs_printWarning (inCompiler, SourceTextInString (), C_IssueWithFixIt (), String ("Need to remove directory '") + inDirectoryPath.mString + "'.\n" COMMA_THERE) ;
    }else if (inDirectoryPath.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("cannot perform directory removing: directory path is an empty string" COMMA_THERE) ;
    }else{
      const String errorMessage = FileManager::removeDirectory (inDirectoryPath.mString) ;
      if (errorMessage.length () > 0) {
        String message = "cannot perform directory removing: " ;
        message.appendString (errorMessage) ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

static String recursiveRemoveDirectory (const String & inUnixDirectoryPath) {
  String result ;
  const String nativeStartPath = FileManager::nativePathWithUnixPath (inUnixDirectoryPath) ;
  DIR * dir = ::opendir (nativeStartPath.cString ()) ;
  if (dir != nullptr) {
    struct dirent  * current = readdir (dir) ;
    while ((current != nullptr) && (result.length () == 0)) {
      if ((strcmp (current->d_name, ".") != 0) && (strcmp (current->d_name, "..") != 0)) {
        String name = nativeStartPath ;
        name.appendCString ("/") ;
        name.appendString (current->d_name) ;
        if (FileManager::directoryExistsWithNativePath (name)) {
          recursiveRemoveDirectory (name) ;
        }else if (FileManager::fileExistsAtPath (name)) {
          result = FileManager::deleteFile (name) ;
        }
      }
      current = readdir (dir) ;
    }
    closedir (dir) ;
  }
  if (result.length () == 0) {
    result = FileManager::removeDirectory (inUnixDirectoryPath) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::class_method_removeDirectoryRecursively (GALGAS_string inDirectoryPath,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (inDirectoryPath.isValid ()) {
    if (! Compiler::performGeneration ()) {
      ggs_printWarning (inCompiler, SourceTextInString (), C_IssueWithFixIt (), String ("Need to remove directory '") + inDirectoryPath.mString + "'.\n" COMMA_THERE) ;
    }else if (inDirectoryPath.mString.length () == 0) {
      inCompiler->onTheFlyRunTimeError ("cannot perform directory removing: directory path is an empty string" COMMA_THERE) ;
    }else{
      String errorMessage = recursiveRemoveDirectory (inDirectoryPath.mString) ;
      if (errorMessage.length () > 0) {
        String message = "cannot perform directory removing: " ;
        message.appendString (errorMessage) ;
        inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

static bool writeFile (const String & inMessage,
                       const String & inFullPathName,
                       const U8Data & inCurrentData,
                       Compiler * inCompiler) {
  bool ok = true ;
  if (inCompiler->performGeneration ()) {
    const bool verboseOptionOn = verboseOutput () ;
    const String directory = inFullPathName.stringByDeletingLastPathComponent () ;
    FileManager::makeDirectoryIfDoesNotExist (directory) ;
    BinaryFileWrite binaryFile (inFullPathName) ;
    ok = binaryFile.isOpened () ;
    if (! ok) {
      String message = "Cannot open '" ;
      message.appendString (inFullPathName) ;
      message.appendCString ("' file in write mode.") ;
      inCompiler->onTheFlySemanticError (message COMMA_HERE) ;
    }
    binaryFile.appendData (inCurrentData) ;
  //--- Close file
    if (ok) {
      ok = binaryFile.close () ;
    }
    if (ok && verboseOptionOn) {
      ggs_printFileOperationSuccess (inMessage + " '" + inFullPathName + "'.\n") ;
    }
  }else{
    ggs_printWarning (inCompiler, SourceTextInString(), C_IssueWithFixIt (), String ("Need to write '") + inFullPathName + "'." COMMA_HERE) ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

static bool updateFile (const String & inFullPathName,
                        const String & inContents,
                        Compiler * inCompiler) {
  U8Data currentData ; currentData.appendString (inContents) ;
//--- Compare file length
  const uint64_t fileSize = FileManager::fileSize (inFullPathName) ;
  bool needsToWriteFile = fileSize != (uint64_t) currentData.count () ;
  bool ok = true ;
//--- Read file
  if (! needsToWriteFile) {
    U8Data fileData ;
    ok = FileManager::binaryDataWithContentOfFile (inFullPathName, fileData) ;
    if (ok) {
      needsToWriteFile = fileData != currentData ;
    }
  }
//--- File needs to be updated
  if (ok && needsToWriteFile) {
    ok = writeFile ("Updated", inFullPathName, currentData, inCompiler) ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

static void generateFile (const String & inStartPath,
                          const String & inFileName,
                          const String & inContents,
                          const bool inMakeExecutable,
                          Compiler * inCompiler) {
  bool ok = true ;
//--- File exists ?
  const TC_UniqueArray <String> directoriesToExclude ;
  const String fullPathName = FileManager::findFileInDirectory (inStartPath, inFileName, directoriesToExclude) ;
  if (fullPathName.length () == 0) { // No, does not exist
    U8Data currentData ; currentData.appendString (inContents) ;
    ok = writeFile ("Created", inStartPath + "/" + inFileName, currentData, inCompiler) ;
  }else{ //--- File exists: read it
    ok = updateFile (fullPathName, inContents, inCompiler) ;
  }
//--- Make file executable
  if (ok && inMakeExecutable) {
    #if COMPILE_FOR_WINDOWS == 0
      struct stat fileStat ;
      ::stat (fullPathName.cString (), & fileStat) ;
      ::chmod (fullPathName.cString (), fileStat.st_mode | S_IXUSR | S_IXGRP | S_IXOTH) ;
    #endif
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::class_method_generateFile (GALGAS_string inStartPath,
                                               GALGAS_string inFileName,
                                               GALGAS_string inContents,
                                               Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  if (inStartPath.isValid () && inFileName.isValid () && inContents.isValid ()) {
    generateFile (inStartPath.mString, inFileName.mString, inContents.mString, false, inCompiler) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_string::class_method_generateFileWithPattern (GALGAS_string inStartPath,
                                                          GALGAS_string inFileName,
                                                          GALGAS_string inLineCommentPrefix,
                                                          GALGAS_string inHeader,
                                                          GALGAS_string inDefaultUserZone1,
                                                          GALGAS_string inGeneratedZone2,
                                                          GALGAS_string inDefaultUserZone2,
                                                          GALGAS_string inGeneratedZone3,
                                                          GALGAS_bool inMakeExecutable,
                                                          Compiler * inCompiler
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
    TC_UniqueArray <String> directoriesToExclude ;
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

//--------------------------------------------------------------------------------------------------

bool GALGAS_string::optional_extractBigInt (GALGAS_bigint & outBigInt) const {
  bool extracted = false ;
  outBigInt.drop () ;
  if (isValid () && (mString.length () > 0)) {
    extracted = true ;
    const BigSigned bigint (mString.cString (), BigUnsignedBase::ten, extracted) ;
    if (extracted) {
      outBigInt = GALGAS_bigint (bigint) ;
    }
  }
  return extracted ;
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void GALGAS_string::printNonNullClassInstanceProperties (const char * inPropertyName) const {
    if (isValid ()) {
      gCout.appendCString ("    ") ;
      gCout.appendString (inPropertyName) ;
      gCout.appendCString (" : ") ;
      gCout.appendString (mString) ;
      gCout.appendNewLine () ; ;
    }
  }
#endif

//--------------------------------------------------------------------------------------------------
