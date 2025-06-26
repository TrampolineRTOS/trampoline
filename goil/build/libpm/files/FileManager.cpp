//--------------------------------------------------------------------------------------------------
//
//  'FileManager' : a class for handling files, independantly from platform
//
//  This file is part of libpm library
//
//  Copyright (C) 2012, ..., 2018 Pierre Molinaro.
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

#include "FileManager.h"
#include "TextFileWrite.h"
#include "BinaryFileWrite.h"
#include "unicode_character_base.h"

//--------------------------------------------------------------------------------------------------

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

//--------------------------------------------------------------------------------------------------

#ifndef COMPILE_FOR_WINDOWS
  #error COMPILE_FOR_WINDOWS is undefined
#endif

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  #include <sys/stat.h>
#endif

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Converting into Unix Path
#endif

//--------------------------------------------------------------------------------------------------
//
//   Converting into Unix Path
//
//--------------------------------------------------------------------------------------------------

//--- On Unix: do nothing
#if COMPILE_FOR_WINDOWS == 0
  String FileManager::unixPathWithNativePath (const String & inFilePath) {
    return inFilePath ;
  }
#endif

//--------------------------------------------------------------------------------------------------

//--- On Windows: translate
#if COMPILE_FOR_WINDOWS == 1
  String FileManager::unixPathWithNativePath (const String & inFilePath) {
    String result ;
    const int32_t pathLength = inFilePath.length () ;
    int32_t firstChar = 0 ;
    if ((pathLength > 3)
     && isalpha ((int) UNICODE_VALUE (inFilePath.charAtIndex (0 COMMA_HERE)))
     && (UNICODE_VALUE (inFilePath.charAtIndex (1 COMMA_HERE)) == ':')
     && (UNICODE_VALUE (inFilePath.charAtIndex (2 COMMA_HERE)) == '\\')) {
      result.appendCString ("/") ;
      result.appendChar (inFilePath.charAtIndex (0 COMMA_HERE)) ;
      result.appendCString ("/") ;
      firstChar = 3 ;
    }
    for (int32_t i=firstChar ; i<pathLength ; i++) {
      const utf32 c = inFilePath.charAtIndex (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) == '\\') {
        result.appendCString ("/") ;
      }else{
        result.appendChar (c) ;
      }
    }
    return result ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Converting into Native Path
#endif

//--------------------------------------------------------------------------------------------------
//
//   Converting into Native Path
//
//--------------------------------------------------------------------------------------------------

//--- On Unix: do nothing
#if COMPILE_FOR_WINDOWS == 0
  String FileManager::nativePathWithUnixPath (const String & inFilePath) {
    return inFilePath ;
  }
#endif

//--------------------------------------------------------------------------------------------------

//--- On Windows: convert
#if COMPILE_FOR_WINDOWS == 1
  String FileManager::nativePathWithUnixPath (const String & inFilePath) {
    String winPath ;
      const int32_t fileLength = inFilePath.length () ;
      int32_t firstChar = 0 ;
      if ((fileLength > 3)
       && (UNICODE_VALUE (inFilePath.charAtIndex (0 COMMA_HERE)) == '/')
       && isalpha ((int) UNICODE_VALUE (inFilePath.charAtIndex (1 COMMA_HERE)))
       && (UNICODE_VALUE (inFilePath.charAtIndex (2 COMMA_HERE)) == '/')) {
        winPath.appendChar (inFilePath.charAtIndex (1 COMMA_HERE)) ;
        winPath.appendCString (":\\") ;
        firstChar = 3 ;
      }
      for (int32_t i=firstChar ; i<fileLength ; i++) {
        const utf32 c = inFilePath.charAtIndex (i COMMA_HERE) ;
        winPath.appendChar ((UNICODE_VALUE (c) == '/') ? TO_UNICODE ('\\') : c) ;
      }
    return winPath ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Open Text File
#endif

//--------------------------------------------------------------------------------------------------

FILE * FileManager::openTextFileForReading (const String & inFilePath) {
  return ::fopen (nativePathWithUnixPath (inFilePath).cString (), "rt") ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Open Binary File
#endif

//--------------------------------------------------------------------------------------------------

FILE * FileManager::openBinaryFileForReading (const String & inFilePath) {
  return ::fopen (nativePathWithUnixPath (inFilePath).cString (), "rb") ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Read binary file at once
#endif

//--------------------------------------------------------------------------------------------------

bool FileManager::binaryDataWithContentOfFile (const String & inFilePath,
                                               U8Data & outBinaryData) {
  outBinaryData.free () ;
//--- Open file for binary reading
  const String nativePath = nativePathWithUnixPath (inFilePath) ;
  FILE * inputFile = ::fopen (nativePath.cString (), "rb") ;
  bool ok = inputFile != nullptr ;
//--- Go to the end of the file
  if (ok) {
    ok = ::fseek (inputFile, 0, 2) == 0 ;
  }

//--- Get file size
  int32_t fileSize = 0 ;
  if (ok) {
    fileSize = (int32_t) (ftell (inputFile) & INT32_MAX) ;
    ok = fileSize != -1 ;
  }

//--- Rewind file
  if (ok) {
    ok = ::fseek (inputFile, 0, 0) == 0 ;
  }

//--- Read file
  if (ok) {
    uint8_t * binaryData = nullptr ;
    macroMyNewArray (binaryData, uint8_t, uint32_t (fileSize)) ;
    const int32_t sizeRead = (int32_t) (fread (binaryData, 1, (uint32_t) fileSize, inputFile) & UINT32_MAX) ;
    ok = sizeRead == fileSize ;
    if (ok) {
      outBinaryData.setDataFromPointer (binaryData, fileSize) ;
    }
  }
//--- Close file
  if (inputFile != nullptr) {
    const int32_t result = ::fclose (inputFile) ;
    inputFile = nullptr ;
    if (ok) {
      ok = result == 0 ;
    }
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Read text file at once
#endif

//--------------------------------------------------------------------------------------------------

static bool parseUTF32LE (const U8Data & inDataString,
                          const int32_t inOffset,
                          String & outString) {
  bool ok = (inDataString.count () % 4) == 0 ;
  for (int32_t i=inOffset ; (i<inDataString.count ()) && ok ; i+=4) {
    uint32_t n = inDataString (i+3 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i+2 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i+1 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i COMMA_HERE) ;
    ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) ;
    outString.appendChar (TO_UNICODE (n)) ;
  }
  if (! ok) {
    outString.removeAllKeepingCapacity () ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

static bool parseUTF32BE (const U8Data & inDataString,
                          const int32_t inOffset,
                          String & outString) {
  bool ok = (inDataString.count () % 4) == 0 ;
  for (int32_t i=inOffset ; (i<inDataString.count ()) && ok ; i+=4) {
    uint32_t n = inDataString (i COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i+1 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i+2 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i+3 COMMA_HERE) ;
    ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) ;
    outString.appendChar (TO_UNICODE (n)) ;
  }
  if (! ok) {
    outString.removeAllKeepingCapacity () ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------
// UTF-16 http://fr.wikipedia.org/wiki/UTF-16

static bool parseUTF16LE (const U8Data & inDataString,
                          const int32_t inOffset,
                          String & outString) {
  bool ok = (inDataString.count () % 2) == 0 ;
  bool foundUTF16prefix = false ;
  for (int32_t i=inOffset ; (i<inDataString.count ()) && ok ; i+=2) {
    uint32_t n = inDataString (i+1 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i COMMA_HERE) ;
    if ((n & 0xDC00) == 0xD800) {
      ok = ! foundUTF16prefix ;
      foundUTF16prefix = true ;
    }else if ((n & 0xDC00) == 0xDC00) {
      ok = foundUTF16prefix ;
      foundUTF16prefix = false ;
    }else{
      ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) && ! foundUTF16prefix ;
      outString.appendChar (TO_UNICODE (n)) ;
    }
  }
  ok &= ! foundUTF16prefix ;
  if (! ok) {
    outString.removeAllKeepingCapacity () ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

static bool parseUTF16BE (const U8Data & inDataString,
                          const int32_t inOffset,
                          String & outString) {
  bool ok = (inDataString.count () % 2) == 0 ;
  bool foundUTF16prefix = false ;
  for (int32_t i=inOffset ; (i<inDataString.count ()) && ok ; i+=2) {
    uint32_t n = inDataString (i COMMA_HERE) ;
    i ++ ;
    n <<= 8 ;
    n |= inDataString (i COMMA_HERE) ;
    if ((n & 0xDC00) == 0xD800) {
      ok = ! foundUTF16prefix ;
      foundUTF16prefix = true ;
    }else if ((n & 0xDC00) == 0xDC00) {
      ok = foundUTF16prefix ;
      foundUTF16prefix = false ;
    }else{
      ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) && ! foundUTF16prefix ;
      outString.appendChar (TO_UNICODE (n)) ;
    }
  }
  ok &= ! foundUTF16prefix ;
  if (! ok) {
    outString.removeAllKeepingCapacity () ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

static bool searchBOMandParse (const U8Data & inDataString,
                               const int32_t inLength,
                               PMTextFileEncoding & outTextFileEncoding,
                               String & outResultString) {
  bool ok = false ;
//--- UTF-32BE BOM ?
  if ((inLength >= 4) && (inDataString (0 COMMA_HERE) == 0) && (inDataString (1 COMMA_HERE) == 0) && (inDataString (2 COMMA_HERE) == 0xFE) && (inDataString (3 COMMA_HERE) == 0xFF)) {
    ok = parseUTF32BE (inDataString, 4, outResultString) ;
    outTextFileEncoding = kUTF_32BE_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-32BE BOM **\n") ;
    #endif
//--- UTF-32LE BOM ?
  }else if ((inLength >= 4) && (inDataString (0 COMMA_HERE) == 0xFF) && (inDataString (1 COMMA_HERE) == 0xFE) && (inDataString (2 COMMA_HERE) == 0) && (inDataString (3 COMMA_HERE) == 0)) {
    ok = parseUTF32LE (inDataString, 4, outResultString) ;
    outTextFileEncoding = kUTF_32LE_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-32LE BOM **\n") ;
    #endif
//--- UTF-8 BOM ?
  }else if ((inLength >= 3) && (inDataString (0 COMMA_HERE) == 0xEF) && (inDataString (1 COMMA_HERE) == 0xBB) && (inDataString (2 COMMA_HERE) == 0x3F)) {
    ok = String::parseUTF8 (inDataString, 3, outResultString) ;
    outTextFileEncoding = kUTF_8_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-8 BOM **\n") ;
    #endif
//--- UTF-16LE BOM ?
  }else if ((inLength >= 2) && (inDataString (0 COMMA_HERE) == 0xFF) && (inDataString (1 COMMA_HERE) == 0xFE)) {
    ok = parseUTF16LE (inDataString, 2, outResultString) ;
    outTextFileEncoding = kUTF_16LE_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-16LE BOM **\n") ;
    #endif
//--- UTF-16BE BOM ?
  }else if ((inLength >= 2) && (inDataString (0 COMMA_HERE) == 0xFE) && (inDataString (1 COMMA_HERE) == 0xFF)) {
    ok = parseUTF16BE (inDataString, 2, outResultString) ;
    outTextFileEncoding = kUTF_16BE_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-16BE BOM **\n") ;
    #endif
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

static bool sniffUTFEncodingAndParse (const U8Data & inDataString,
                                      PMTextFileEncoding & outTextFileEncoding,
                                      String & outResultString) {
//--- Try UTF-8
  bool ok = String::parseUTF8 (inDataString, 0, outResultString) ;
  if (ok) {
    outTextFileEncoding = kUTF_8_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("sniffed UTF-8 encoding **\n") ;
    #endif
  }
//--- Try UTF-32BE
  if (! ok) {
    ok = parseUTF32BE (inDataString, 0, outResultString) ;
    if (ok) {
      outTextFileEncoding = kUTF_32BE_FileEncoding ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("sniffed UTF-32BE encoding **\n") ;
      #endif
    }
  }
//--- Try UTF-32LE
  if (! ok) {
    ok = parseUTF32LE (inDataString, 0, outResultString) ;
    if (ok) {
      outTextFileEncoding = kUTF_32LE_FileEncoding ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("sniffed UTF-32LE encoding **\n") ;
      #endif
    }
  }
//--- Try UTF-16LE
  if (! ok) {
    ok = parseUTF16LE (inDataString, 0, outResultString) ;
    if (ok) {
      outTextFileEncoding = kUTF_16LE_FileEncoding ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("sniffed UTF-16LE encoding **\n") ;
      #endif
    }
  }
//--- Try UTF-16BE
  if (! ok) {
    ok = parseUTF16BE (inDataString, 0, outResultString) ;
    if (ok) {
      outTextFileEncoding = kUTF_16BE_FileEncoding ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("sniffed UTF-16BE encoding **\n") ;
      #endif
    }
  }
//---
  return ok ;
}

//--------------------------------------------------------------------------------------------------

class encodingStruct {
  public: const char * mEncodingName ;
  public: const PMTextFileEncoding mTextFileEncoding ;
  public: const PMStringEncoding mStringEncoding ;
}  ;

//--------------------------------------------------------------------------------------------------

static const int32_t kEncodingCount = 18 ;

static const encodingStruct kEncodings [kEncodingCount] = {
 {"ISO-8859-1", kISO_8859_1_FileEncoding, k8859_1_encoding},
 {"ISO-8859-2", kISO_8859_2_FileEncoding, k8859_2_encoding},
 {"ISO-8859-3", kISO_8859_3_FileEncoding, k8859_3_encoding},
 {"ISO-8859-4", kISO_8859_4_FileEncoding, k8859_4_encoding},
 {"ISO-8859-5", kISO_8859_5_FileEncoding, k8859_5_encoding},
 {"ISO-8859-6", kISO_8859_6_FileEncoding, k8859_6_encoding},
 {"ISO-8859-7", kISO_8859_7_FileEncoding, k8859_7_encoding},
 {"ISO-8859-8", kISO_8859_8_FileEncoding, k8859_8_encoding},
 {"ISO-8859-9", kISO_8859_9_FileEncoding, k8859_9_encoding},
 {"ISO-8859-10", kISO_8859_10_FileEncoding, k8859_10_encoding},
 {"ISO-8859-11", kISO_8859_11_FileEncoding, k8859_11_encoding},
 {"ISO-8859-13", kISO_8859_13_FileEncoding, k8859_13_encoding},
 {"ISO-8859-14", kISO_8859_14_FileEncoding, k8859_14_encoding},
 {"ISO-8859-15", kISO_8859_15_FileEncoding, k8859_15_encoding},
 {"ISO-8859-16", kISO_8859_16_FileEncoding, k8859_16_encoding},
 {"CP-1252", kCP1252_FileEncoding, kCP1252_encoding},
 {"CP-437", kCP437_DOS_FileEncoding, kCP437_DOS_encoding},
 {"MacRoman", kMacRoman_FileEncoding, kMacRoman_encoding}
} ;

//--------------------------------------------------------------------------------------------------

static bool parseWithEncoding (const U8Data & inDataString,
                               const PMStringEncoding inTextFileEncoding,
                               String & outString) {
  bool foundCR = false ;
  bool ok = true ;
  int32_t idx = 0 ;
  while ((idx < inDataString.count ()) && (inDataString (idx COMMA_HERE) != 0) && ok) {
    const uint8_t c = inDataString (idx COMMA_HERE) ;
    if (c == 0x0A) { // LF
      if (! foundCR) {
        outString.appendChar (TO_UNICODE ('\n')) ;
      }
      foundCR = false ;
    }else if (c == 0x0D) { // CR
      outString.appendChar (TO_UNICODE ('\n')) ;
      foundCR = true ;
    }else if ((c & 0x80) == 0) { // ASCII Character
      outString.appendChar (TO_UNICODE (c)) ;
      foundCR = false ;
    }else{
      const utf32 uc = unicodeCharacterForSingleByteCharacter ((char) c, inTextFileEncoding) ;
      outString.appendChar (uc) ;
      foundCR = false ;
    }
  }
  if (foundCR) {
    outString.appendChar (TO_UNICODE ('\n')) ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

static bool searchForEncodingTagAndParse (const U8Data & inDataString,
                                          PMTextFileEncoding & outTextFileEncoding,
                                          String & outResultString) {
//--- Copy first line
  char firstLine [1000] ;
  int32_t index = 0 ;
  bool eol = false ;
  while ((index < 999) && ! eol) {
    if ((inDataString (index COMMA_HERE) == 0x0A) || (inDataString (index COMMA_HERE) == 0x0D)) {
      firstLine [index] = '\0' ;
      eol = true ;
    }else{
      firstLine [index] = (char) inDataString (index COMMA_HERE) ;
    }
    index ++ ;
  }
  if (! eol) {
    firstLine [index] = '\0' ;
  }
  bool ok = false ;
//--- Search for Tag
  bool tagFound = false ;
  if (strstr (firstLine, "UTF-8") != nullptr) {
    ok = String::parseUTF8 (inDataString, 0, outResultString) ;
    outTextFileEncoding = kUTF_8_FileEncoding ;
    tagFound = true ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-8 tag in first line **\n") ;
    #endif
  }
  for (int32_t i=0 ; (i<kEncodingCount) && ! tagFound ; i++) {
    tagFound = strstr (firstLine, kEncodings [i].mEncodingName) != nullptr ;
    if (tagFound) {
      ok = parseWithEncoding (inDataString, kEncodings [i].mStringEncoding, outResultString) ;
      outTextFileEncoding = kEncodings [i].mTextFileEncoding ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("found '%s' tag in first line **\n", kEncodings [i].mEncodingName) ;
      #endif
    }
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

static void parseASCIIWithReplacementCharacter (const U8Data & inDataString,
                                                String & outString) {
  bool foundCR = false ;
  int32_t index = 0 ;
  while (index < inDataString.count ()) {
    const uint8_t c = inDataString (index COMMA_HERE) ;
    index ++ ;
    if (c == 0x0A) { // LF
      if (! foundCR) {
        outString.appendChar (TO_UNICODE ('\n')) ;
      }
      foundCR = false ;
    }else if (c == 0x0D) { // CR
      outString.appendChar (TO_UNICODE ('\n')) ;
      foundCR = true ;
    }else if ((c != 0) && (c & 0x80) == 0) { // ASCII Character (not NUL)
      outString.appendChar (TO_UNICODE (c)) ;
      foundCR = false ;
    }else{
      outString.appendChar (UNICODE_REPLACEMENT_CHARACTER) ;
      foundCR = false ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

String FileManager::stringWithContentOfFile (const String & inFilePath,
                                             PMTextFileEncoding & outTextFileEncoding,
                                             bool & outOk) {
  #ifdef PRINT_SNIFF_ENCODING
    printf ("** SNIFF ENCODING for '%s': ", inFilePath.cString ()) ;
  #endif
//--- Read file
  U8Data stringData ;
  outOk = binaryDataWithContentOfFile (inFilePath, stringData) ;
  const int32_t length = stringData.count () ;
//--- Assign C string to String
  String result_string ;
  if (outOk) {
    result_string.setCapacity (length + 2) ;
  //------------ 1- Search for BOM
    outOk = searchBOMandParse (stringData, length, outTextFileEncoding, result_string) ;
  //------------ 2- Try UTF-32BE, UTF-32LE, UTF-16BE, UTF-16LE, UTF-8 encodings
    if (! outOk) {
      outOk = sniffUTFEncodingAndParse (stringData, outTextFileEncoding, result_string) ;
    }
  //------------ 3- Search for encoding name in the first line
    if (! outOk) {
      outOk = searchForEncodingTagAndParse (stringData, outTextFileEncoding, result_string) ;
    }
  //------------ 4- ASCII read
    if (! outOk) {
      parseASCIIWithReplacementCharacter (stringData, result_string) ;
      outTextFileEncoding = kUTF_8_FileEncoding ;
      outOk = true ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("default ASCII read **\n") ;
      #endif
    }
  }
  return result_string ;
}

//--------------------------------------------------------------------------------------------------

String FileManager::stringWithContentOfFile (const String & inFilePath) {
  bool ok = false ;
  PMTextFileEncoding textFileEncoding ;
  String result_string = stringWithContentOfFile (inFilePath, textFileEncoding, ok) ;
//--- Assign C string to String
  if (! ok) {
    throw C_TextReadException (inFilePath.cString ()) ;
  }
  return result_string ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Write to File
#endif

//--------------------------------------------------------------------------------------------------

bool FileManager::writeStringToFile (const String & inString,
                                       const String & inFilePath) {
  makeDirectoryIfDoesNotExist (inFilePath.stringByDeletingLastPathComponent ()) ;
  TextFileWrite file (inFilePath) ;
  bool success = file.isOpened () ;
  file.appendString (inString) ;
  if (success) {
    success = file.close () ;
  }
  return success ;
}

//--------------------------------------------------------------------------------------------------

bool FileManager::writeStringToExecutableFile (const String & inString,
                                                 const String & inFilePath) {
  makeDirectoryIfDoesNotExist (inFilePath.stringByDeletingLastPathComponent()) ;
  TextFileWrite file (inFilePath) ;
  file.appendString (inString) ;
  bool success = file.isOpened () ;
  if (success) {
    success = file.close () ;
    #if COMPILE_FOR_WINDOWS == 0
      struct stat fileStat ;
      ::stat (inFilePath.cString (), & fileStat) ;
      ::chmod (inFilePath.cString (), fileStat.st_mode | S_IXUSR | S_IXGRP | S_IXOTH) ;
    #endif
  }
  return success ;
}

//--------------------------------------------------------------------------------------------------

bool FileManager::writeBinaryDataToFile (const U8Data & inBinaryData,
                                           const String & inFilePath) {
  makeDirectoryIfDoesNotExist (inFilePath.stringByDeletingLastPathComponent()) ;
//---
  BinaryFileWrite binaryFile (inFilePath) ;
  bool success = binaryFile.isOpened () ;
  binaryFile.appendData (inBinaryData) ;
//--- Close file
  if (success) {
    success = binaryFile.close () ;
  }
//---
  return success ;
}

//--------------------------------------------------------------------------------------------------

bool FileManager::writeBinaryDataToExecutableFile (const U8Data & inBinaryData,
                                                     const String & inFilePath) {
  makeDirectoryIfDoesNotExist (inFilePath.stringByDeletingLastPathComponent()) ;
//---
  BinaryFileWrite binaryFile (inFilePath) ;
  bool success = binaryFile.isOpened () ;
  binaryFile.appendData (inBinaryData) ;
//--- Close file
  if (success) {
    success = binaryFile.close () ;
    #if COMPILE_FOR_WINDOWS == 0
      struct stat fileStat ;
      ::stat (inFilePath.cString (), & fileStat) ;
      ::chmod (inFilePath.cString (), fileStat.st_mode | S_IXUSR | S_IXGRP | S_IXOTH) ;
    #endif
  }
//---
  return success ;
}

 //--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Make File Executable
#endif

//--------------------------------------------------------------------------------------------------

bool FileManager::makeFileExecutable (const String & inFilePath) {
  const bool result = fileExistsAtPath (inFilePath) ;
  #if COMPILE_FOR_WINDOWS == 0
    if (result) {
      struct stat fileStat ;
      ::stat (inFilePath.cString (), & fileStat) ;
      ::chmod (inFilePath.cString (), fileStat.st_mode | S_IXUSR | S_IXGRP | S_IXOTH) ;
    }
  #endif
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Directory Handling
#endif

//--------------------------------------------------------------------------------------------------

bool FileManager::directoryExists (const String & inDirectoryPath) {
  return directoryExistsWithNativePath (nativePathWithUnixPath (inDirectoryPath)) ;
}

//--------------------------------------------------------------------------------------------------

bool FileManager::directoryExistsWithNativePath (const String & inDirectoryNativePath) {
  #if COMPILE_FOR_WINDOWS == 1
    const char dirSep = '\\' ;
  #else
    const char dirSep = '/' ;
  #endif
  String directoryNativePath = inDirectoryNativePath ;
  while ((directoryNativePath.length () > 0) && (directoryNativePath.lastChar(HERE) == dirSep)) {
    directoryNativePath = directoryNativePath.subString (0, directoryNativePath.length () - 1) ;
  }
//--- Get file properties
  bool exists = directoryNativePath.length () > 0 ;
  if (exists) {
    struct stat fileProperties ;
    const int err = ::stat (directoryNativePath.cString (), & fileProperties) ;
    exists = (err == 0) && ((fileProperties.st_mode & S_IFDIR) != 0) ;
  }
 //--- Return result
  return exists ;
}

//--------------------------------------------------------------------------------------------------

String FileManager::currentDirectory (void) {
  char * cwd = getcwd (nullptr, 0) ;
  #if COMPILE_FOR_WINDOWS == 1
    const int32_t fileLength = (int32_t) strlen (cwd) ;
    int32_t firstChar = 0 ;
    if ((fileLength > 3) && isalpha (cwd [0]) && (cwd [1] == ':') && (cwd [2] == '\\')) {
      cwd [1] = cwd [0] ;
      cwd [0] = '/' ;
      cwd [2] = '/' ;
      firstChar = 3 ;
    }
    for (int32_t i=firstChar ; i<fileLength ; i++) {
      if (cwd [i] == '\\') {
        cwd [i] = '/' ;
      }
    }
  #endif
  const String result (cwd) ;
  ::free (cwd) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool FileManager::makeDirectoryIfDoesNotExist (const String & inDirectoryPath) {
  const String directoryPath = absolutePathFromCurrentDirectory (inDirectoryPath) ;
  bool ok = directoryExists (directoryPath) ;
  if (! ok) {
    ok = makeDirectoryIfDoesNotExist (directoryPath.stringByDeletingLastPathComponent ()) ;
    if (ok && !directoryExists (directoryPath)) { // Special case when the path contains ../
      const String nativePath = nativePathWithUnixPath (directoryPath) ;
    //--- Create directory (mkdir returns 0 if creation is ok)
      #if COMPILE_FOR_WINDOWS == 1
        const int result = ::mkdir (nativePath.cString ()) ;
      #else
        const int result = ::mkdir (nativePath.cString (), 0770) ;
      #endif
      ok = result == 0 ;
    }
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

String FileManager::removeDirectory (const String & inDirectoryPath) {
 String errorString ;
  const String nativePath = nativePathWithUnixPath (inDirectoryPath) ;
  const int result = rmdir (nativePath.cString ()) ;
  if (result < 0) {
    errorString.appendString (::strerror (errno)) ;
  }
  return errorString ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Path Handling
#endif

//--------------------------------------------------------------------------------------------------

bool FileManager::isAbsolutePath (const String & inPath) {
  return (inPath.length () > 0) && (UNICODE_VALUE (inPath.charAtIndex (0 COMMA_HERE)) == '/') ;
}

//--------------------------------------------------------------------------------------------------

String FileManager::absolutePathFromCurrentDirectory (const String & inPath) {
  const int32_t stringLength = inPath.length () ;
  String result ;
  if ((stringLength > 0) && (UNICODE_VALUE (inPath.charAtIndex (0 COMMA_HERE)) == '/')) {
    result = inPath ;
  }else{
    result = currentDirectory () + "/" + inPath ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//--- If receiver is an absolute path, returns it
//    Otherwise, prepend path argument
//    if path argument it self is relative, current directory is prepended

String FileManager::absolutePathFromPath (const String & inPath,
                                          const String & inFromPath) {
  const int32_t pathLength = inPath.length () ;
  String result ;
  if ((pathLength > 0) && (UNICODE_VALUE (inPath.charAtIndex (0 COMMA_HERE)) == '/')) {
    result = inPath ;
  }else{
    result = absolutePathFromCurrentDirectory (inFromPath) ;
    if (UNICODE_VALUE (result.lastChar (HERE)) != '/') {
      result.appendChar (TO_UNICODE ('/')) ;
    }
    result.appendString (inPath) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String FileManager::relativePathFromPath (const String & inPath,
                                              const String & inFromPath) {
  TC_UniqueArray <String> absoluteReferencePathComponents ;
  absolutePathFromCurrentDirectory (inFromPath.stringByStandardizingPath ()).componentsSeparatedByString("/", absoluteReferencePathComponents) ;
  TC_UniqueArray <String> absoluteReceiverPathComponents ;
  absolutePathFromCurrentDirectory (inPath.stringByStandardizingPath ()).componentsSeparatedByString("/", absoluteReceiverPathComponents) ;
  String result ;
  int32_t idx = 0 ;
  while ((idx < absoluteReferencePathComponents.count ())
      && (idx < absoluteReceiverPathComponents.count ())
      && (absoluteReferencePathComponents (idx COMMA_HERE) == absoluteReceiverPathComponents (idx COMMA_HERE))) {
    idx ++ ;
  }
  for (int32_t i=idx ; i<absoluteReferencePathComponents.count () ; i++) {
    result.appendCString ("../") ;
  }
  for (int32_t i=idx ; i<absoluteReceiverPathComponents.count () ; i++) {
    if (i > idx) {
      result.appendCString ("/") ;
    }
    result.appendString (absoluteReceiverPathComponents (i COMMA_HERE)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Symbolic Link
#endif

//--------------------------------------------------------------------------------------------------

#if (COMPILE_FOR_WINDOWS == 1) || defined (__CYGWIN__)
  bool FileManager::makeSymbolicLinkWithPath (const String & /* inPath */,
                                                const String & /* inLinkPath */) {
    return true ; // Symbolic links are not supported on Windows
  }
#else
  bool FileManager::makeSymbolicLinkWithPath (const String & inPath,
                                                const String & inLinkPath) {
    const int r = symlink (inPath.cString (), inLinkPath.cString ()) ;
    return r >= 0 ;
  }
#endif

//--------------------------------------------------------------------------------------------------

// See http://www.gnu.org/s/libc/manual/html_node/Symbolic-Links.html

//--- Symbolic links and Windows:
// See http://answers.google.com/answers/threadview/id/341355.html

//--------------------------------------------------------------------------------------------------

#if (COMPILE_FOR_WINDOWS == 1) || defined (__CYGWIN__)
  bool FileManager::isSymbolicLink (const String & /* inLinkPath */) {
    return false ; // Symbolic links are not supported on Windows
  }
#else
  bool FileManager::isSymbolicLink (const String & inLinkPath) {
    char buffer [8] ; // Any value
    return readlink (inLinkPath.cString (), buffer, 8) >= 0 ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#if (COMPILE_FOR_WINDOWS == 1) || defined (__CYGWIN__)
  String FileManager::stringWithSymbolicLinkContents (const String & /* inLinkPath */,
                                                          bool & outOk) {
    outOk = false ; // Symbolic links are not supported on Windows
    return String () ;
  }
#else
  String FileManager::stringWithSymbolicLinkContents (const String & inLinkPath,
                                                          bool & outOk) {
    String result ;
    bool loop = true ;
    outOk = true ;
    char * buffer = nullptr ;
    size_t bufferSize = 128 ;
    while (loop) {
      macroMyReallocPODArray (buffer, char, bufferSize) ;
      const int64_t r = readlink (inLinkPath.cString (), buffer, bufferSize) ;
      if (r < 0) { // Error
        outOk = false ;
        loop = false ;
      }else if (r < (int64_t) bufferSize) { // ok
        buffer [r] = '\0' ;
        result.appendString (buffer) ;
        loop = false ;
      }else{ // Buffer too small
        bufferSize *= 2 ;
      }
    }
    macroMyDeletePODArray (buffer) ;
    return result ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Delete File
#endif

//--------------------------------------------------------------------------------------------------
//
//  Delete file
//
//--------------------------------------------------------------------------------------------------

String FileManager::deleteFile (const String & inFilePath) {
  String returnValue ;
  const String nativePath = nativePathWithUnixPath (inFilePath) ;
  const int result = unlink (nativePath.cString ()) ;
  if (result < 0) {
    returnValue.appendString (::strerror (errno)) ;
  }
  return returnValue ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Search a file in a directory
#endif

//--------------------------------------------------------------------------------------------------

static String recursiveSearchInDirectory (const String & inStartSearchPath,
                                            const String & inFileName,
                                            const int32_t inDirectoriesToExcludeCount,
                                            const TC_UniqueArray <String> & inDirectoriesToExclude) {
  String result ;
  const String nativeStartSearchPath = FileManager::nativePathWithUnixPath (inStartSearchPath) ;
  DIR * dir = ::opendir (nativeStartSearchPath.cString ()) ;
  if (dir != nullptr) {
    String fileName = inStartSearchPath ;
    fileName.appendCString ("/") ;
    fileName.appendString (inFileName) ;
    if (FileManager::fileExistsAtPath (fileName)) {
      result = fileName ;
    }else{
      struct dirent  * current = readdir (dir) ;
      while ((current != nullptr) && (result.length () == 0)) {
        if (current->d_name [0] != '.') {
          String name = inStartSearchPath ;
          name.appendCString ("/") ;
          name.appendString (current->d_name) ;
          if (FileManager::directoryExistsWithNativePath (name)) {
            bool dirOk = true ;
            for (int32_t i=0 ; (i<inDirectoriesToExcludeCount) && dirOk ; i++) {
              if (UNICODE_VALUE (inDirectoriesToExclude (i COMMA_HERE).charAtIndex (0 COMMA_HERE)) == '.') {
                const char * dotPtr = strrchr (current->d_name, '.') ;
                dirOk = (dotPtr == nullptr) || (inDirectoriesToExclude (i COMMA_HERE).compare (dotPtr) != 0) ;
              }else{
                dirOk = inDirectoriesToExclude (i COMMA_HERE).compare (current->d_name) != 0 ;
              }
            }
            if (dirOk) {
              result = recursiveSearchInDirectory (name, inFileName, inDirectoriesToExcludeCount, inDirectoriesToExclude) ;
            }
          }
        }
        current = readdir (dir) ;
      }
    }
    closedir (dir) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String FileManager::findFileInDirectory (const String & inDirectoryPath,
                                             const String & inFileName,
                                             const TC_UniqueArray <String> & inDirectoriesToExclude) {
  const int32_t directoriesToExcludeCount = inDirectoriesToExclude.count () ;
  return recursiveSearchInDirectory (inDirectoryPath, inFileName, directoriesToExcludeCount, inDirectoriesToExclude) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Find all files in a directory
#endif

//--------------------------------------------------------------------------------------------------

static void recursiveFindAllFilesInDirectory (const String & inStartSearchPath,
                                              const String & inExtension,
                                              TC_UniqueArray <String> & outFoundFilePathes) {
//--- Iterate throught directory
  const String nativeStartSearchPath = FileManager::nativePathWithUnixPath (inStartSearchPath) ;
  DIR * dir = ::opendir (nativeStartSearchPath.cString ()) ;
  if (dir != nullptr) {
    struct dirent  * current = readdir (dir) ;
    while (current != nullptr) {
      if (current->d_name [0] != '.') {
        String name = inStartSearchPath ;
        name.appendCString ("/") ;
        name.appendString (current->d_name) ;
        if (FileManager::directoryExistsWithNativePath (name)) {
          recursiveFindAllFilesInDirectory (name, inExtension, outFoundFilePathes) ;
        }else if (FileManager::fileExistsAtPath (name) && (name.pathExtension () == inExtension)) {
          outFoundFilePathes.appendObject (name) ;
        }
      }
      current = readdir (dir) ;
    }
    closedir (dir) ;
  }
}

//--------------------------------------------------------------------------------------------------

void FileManager::findAllFilesInDirectoryFromExtension (const String & inDirectoryPath,
                                                          const String & inExtension,
                                                          TC_UniqueArray <String> & outFoundFilePathes) {
  if (directoryExists (inDirectoryPath)) {
    recursiveFindAllFilesInDirectory (inDirectoryPath, inExtension, outFoundFilePathes) ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Files Modification Time
#endif

//--------------------------------------------------------------------------------------------------

DateTime FileManager::fileModificationTime (const String & inFilePath) {
  const String nativePath = nativePathWithUnixPath (inFilePath) ;
//--- Get file properties
  time_t modificationTime = 0 ;
  if (nativePath.length () > 0) {
    struct stat fileProperties ;
    const int err = ::stat (nativePath.cString (), & fileProperties) ;
    if ((err == 0) && ((fileProperties.st_mode & S_IFREG) != 0)) {
      modificationTime = fileProperties.st_mtime ;
    }
  }
//--- Return modification date
  return DateTime (modificationTime)  ;
}


//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Files Modification Time
#endif

//--------------------------------------------------------------------------------------------------

uint64_t FileManager::fileSize (const String & inFilePath) {
  uint64_t result = 0 ;
  const String nativePath = nativePathWithUnixPath (inFilePath) ;
  if (nativePath.length () > 0) {
    struct stat fileProperties ;
    const int err = ::stat (nativePath.cString (), & fileProperties) ;
    if ((err == 0) && ((fileProperties.st_mode & S_IFREG) != 0)) {
      result = (uint64_t) fileProperties.st_size ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Files permissions
#endif

//--------------------------------------------------------------------------------------------------

int32_t FileManager::filePosixPermissions (const String & inFilePath) {
  const String nativePath = nativePathWithUnixPath (inFilePath) ;
//--- Get file properties
  int32_t permissions = -1 ;
  struct stat fileProperties ;
  const int err = ::stat (nativePath.cString (), & fileProperties) ;
  if (err == 0) {
    permissions = ((int32_t) fileProperties.st_mode) & 0xFFF ;
  }
 //--- Return result
  return permissions ;
}

//--------------------------------------------------------------------------------------------------

int32_t FileManager::setFilePosixPermissions (const String & inFilePath,
                                                const int32_t inNewFilePosixPermissions) {
  int32_t newMode = -1 ; // Error Code
  const int32_t v = inNewFilePosixPermissions & (int32_t) 0xFFFFF000 ;
  if (v == 0) {
    const String nativePath = nativePathWithUnixPath (inFilePath) ;
    newMode = ::chmod (nativePath.cString (), (uint16_t) (inNewFilePosixPermissions & UINT16_MAX)) ;
  }
  return newMode ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Files exists at path
#endif

//--------------------------------------------------------------------------------------------------

bool FileManager::fileExistsAtPath (const String & inFilePath) {
  const String nativePath = nativePathWithUnixPath (inFilePath) ;
//--- Get file properties
  bool exists = nativePath.length () > 0 ;
  if (exists) {
    struct stat fileProperties ;
    const int err = ::stat (nativePath.cString (), & fileProperties) ;
    exists = (err == 0) && ((fileProperties.st_mode & S_IFREG) != 0) ;
  }
 //--- Return result
  return exists ;
}

//--------------------------------------------------------------------------------------------------

