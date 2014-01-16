//---------------------------------------------------------------------------*
//                                                                           *
//  'C_FileManager' : a class for handling files,                            *
//  independantly from platform                                              *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.                           *
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

#include "files/C_FileManager.h"
#include "files/C_TextFileWrite.h"
#include "files/C_BinaryFileWrite.h"
#include "strings/unicode_character_base.h"

//---------------------------------------------------------------------------*

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>

#ifdef __MINGW32__
  #include <sys/stat.h>
#endif

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Converting into Unix Path
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   Converting into Unix Path                                               *
//                                                                           *
//---------------------------------------------------------------------------*

//--- On Unix: do nothing
#ifdef UNIX_TOOL
  C_String C_FileManager::unixPathWithNativePath (const C_String & inFilePath) {
    return inFilePath ;
  }
#endif

//---------------------------------------------------------------------------*

//--- On Windows: translate
#ifdef COMPILE_FOR_WIN32
  C_String C_FileManager::unixPathWithNativePath (const C_String & inFilePath) {
    C_String result ;
    const PMSInt32 pathLength = inFilePath.length () ;
    PMSInt32 firstChar = 0 ;
    if ((pathLength > 3)
     && isalpha ((int) UNICODE_VALUE (inFilePath (0 COMMA_HERE)))
     && (UNICODE_VALUE (inFilePath (1 COMMA_HERE)) == ':')
     && (UNICODE_VALUE (inFilePath (2 COMMA_HERE)) == '\\')) {
      result << "/" ;
      result.appendUnicodeCharacter (inFilePath (0 COMMA_HERE) COMMA_HERE) ;
      result << "/" ;
      firstChar = 3 ;
    }
    for (PMSInt32 i=firstChar ; i<pathLength ; i++) {
      const utf32 c = inFilePath (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) == '\\') {
        result << "/" ;
      }else{
        result.appendUnicodeCharacter (c COMMA_HERE) ;
      }
    }
    return result ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Converting into Native Path
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   Converting into Native Path                                             *
//                                                                           *
//---------------------------------------------------------------------------*

//--- On Unix: do nothing
#ifdef UNIX_TOOL
  C_String C_FileManager::nativePathWithUnixPath (const C_String & inFilePath) {
    return inFilePath ;
  }
#endif

//---------------------------------------------------------------------------*

//--- On Windows: convert
#ifdef COMPILE_FOR_WIN32
  C_String C_FileManager::nativePathWithUnixPath (const C_String & inFilePath) {
    C_String winPath ;
      const PMSInt32 fileLength = inFilePath.length () ;
      PMSInt32 firstChar = 0 ;
      if ((fileLength > 3)
       && (UNICODE_VALUE (inFilePath (0 COMMA_HERE)) == '/')
       && isalpha ((int) UNICODE_VALUE (inFilePath (1 COMMA_HERE)))
       && (UNICODE_VALUE (inFilePath (2 COMMA_HERE)) == '/')) {
        winPath.appendUnicodeCharacter (inFilePath (1 COMMA_HERE) COMMA_HERE) ;
        winPath << ":\\" ;
        firstChar = 3 ;
      }
      for (PMSInt32 i=firstChar ; i<fileLength ; i++) {
        const utf32 c = inFilePath (i COMMA_HERE) ;
        winPath.appendUnicodeCharacter ((UNICODE_VALUE (c) == '/') ? TO_UNICODE ('\\') : c COMMA_HERE) ;
      }
    return winPath ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Open Text File
#endif

//---------------------------------------------------------------------------*

FILE * C_FileManager::openTextFileForReading (const C_String & inFilePath) {
  return ::fopen (nativePathWithUnixPath (inFilePath).cString (HERE), "rt") ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Open Binary File
#endif

//---------------------------------------------------------------------------*

FILE * C_FileManager::openBinaryFileForReading (const C_String & inFilePath) {
  return ::fopen (nativePathWithUnixPath (inFilePath).cString (HERE), "rb") ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Read binary file at once
#endif

//---------------------------------------------------------------------------*
  
bool C_FileManager::binaryDataWithContentOfFile (const C_String & inFilePath,
                                                 C_Data & outBinaryData) {
  outBinaryData.free () ;
//--- Open file for binary reading
  const C_String nativePath = nativePathWithUnixPath (inFilePath) ;
  FILE * inputFile = ::fopen (nativePath.cString (HERE), "rb") ;
  bool ok = inputFile != NULL ;
//--- Go to the end of the file
  if (ok) {
    ok = ::fseek (inputFile, 0, 2) == 0 ;
  }

//--- Get file size
  PMSInt32 fileSize = 0 ;
  if (ok) {
    fileSize = (PMSInt32) (ftell (inputFile) & PMUINT32_MAX) ;
    ok = fileSize != -1 ;
  }

//--- Rewind file
  if (ok) {
    ok = ::fseek (inputFile, 0L, 0) == 0 ;
  }

//--- Read file
  if (ok) {
    PMUInt8 * binaryData = NULL ;
    macroMyNewArray (binaryData, PMUInt8, fileSize) ;
    const PMSInt32 sizeRead = (PMSInt32) (fread (binaryData, 1, (PMUInt32) fileSize, inputFile) & PMUINT32_MAX) ;
    ok = sizeRead == fileSize ;
    if (ok) {
      outBinaryData.setDataFromPointer (binaryData, fileSize) ;
    }
  }
//--- Close file
  if (inputFile != NULL) {
    const PMSInt32 result = ::fclose (inputFile) ;
    inputFile = NULL ;
    if (ok) {
      ok = result == 0 ;
    }
  }
  return ok ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Read text file at once
#endif

//---------------------------------------------------------------------------*
  
static bool parseUTF32LE (const C_Data & inDataString,
                          const PMSInt32 inOffset,
                          C_String & outString) {
  bool ok = (inDataString.length () % 4) == 0 ;
  for (PMSInt32 i=inOffset ; (i<inDataString.length ()) && ok ; i+=4) {
    PMUInt32 n = inDataString (i+3 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i+2 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i+1 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i COMMA_HERE) ;
    ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) ;
    outString.appendUnicodeCharacter (TO_UNICODE (n) COMMA_HERE) ;
  }
  if (! ok) {
    outString.setLengthToZero () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
static bool parseUTF32BE (const C_Data & inDataString,
                          const PMSInt32 inOffset,
                          C_String & outString) {
  bool ok = (inDataString.length () % 4) == 0 ;
  for (PMSInt32 i=inOffset ; (i<inDataString.length ()) && ok ; i+=4) {
    PMUInt32 n = inDataString (i COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i+1 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i+2 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i+3 COMMA_HERE) ;
    ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) ;
    outString.appendUnicodeCharacter (TO_UNICODE (n) COMMA_HERE) ;
  }
  if (! ok) {
    outString.setLengthToZero () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*
// UTF-16 http://fr.wikipedia.org/wiki/UTF-16
//    
static bool parseUTF16LE (const C_Data & inDataString,
                          const PMSInt32 inOffset,
                          C_String & outString) {
  bool ok = (inDataString.length () % 2) == 0 ;
  // PMUInt32 utf16prefix =0 ;
  bool foundUTF16prefix = false ;
  for (PMSInt32 i=inOffset ; (i<inDataString.length ()) && ok ; i+=2) {
    PMUInt32 n = inDataString (i+1 COMMA_HERE) ;
    n <<= 8 ;
    n |= inDataString (i COMMA_HERE) ;
    if ((n & 0xDC00) == 0xD800) {
      ok = ! foundUTF16prefix ;
      foundUTF16prefix = true ;
      // utf16prefix = n & 0x3FF ;
      // utf16prefix += 64 ;
    }else if ((n & 0xDC00) == 0xDC00) {
      ok = foundUTF16prefix ;
      foundUTF16prefix = false ;
      // n &= 0x3FF ;
      // n |= utf16prefix << 6 ;
    }else{
      ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) && ! foundUTF16prefix ;
      outString.appendUnicodeCharacter (TO_UNICODE (n) COMMA_HERE) ;
    }
  }
  ok &= ! foundUTF16prefix ;
  if (! ok) {
    outString.setLengthToZero () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*

static bool parseUTF16BE (const C_Data & inDataString,
                          const PMSInt32 inOffset,
                          C_String & outString) {
  bool ok = (inDataString.length () % 2) == 0 ;
  // PMUInt32 utf16prefix =0 ;
  bool foundUTF16prefix = false ;
  for (PMSInt32 i=inOffset ; (i<inDataString.length ()) && ok ; i+=2) {
    PMUInt32 n = inDataString (i COMMA_HERE) ;
    i ++ ;
    n <<= 8 ;
    n |= inDataString (i COMMA_HERE) ;
    if ((n & 0xDC00) == 0xD800) {
      ok = ! foundUTF16prefix ;
      foundUTF16prefix = true ;
      // utf16prefix = n & 0x3FF ;
      // utf16prefix += 64 ;
    }else if ((n & 0xDC00) == 0xDC00) {
      ok = foundUTF16prefix ;
      foundUTF16prefix = false ;
      // n &= 0x3FF ;
      // n |= utf16prefix << 6 ;
    }else{
      ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) && ! foundUTF16prefix ;
      outString.appendUnicodeCharacter (TO_UNICODE (n) COMMA_HERE) ;
    }
  }
  ok &= ! foundUTF16prefix ;
  if (! ok) {
    outString.setLengthToZero () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
static bool searchBOMandParse (const C_Data & inDataString,
                               const PMSInt32 inLength,
                               PMTextFileEncoding & outTextFileEncoding,
                               C_String & outResultString) {
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
    ok = C_String::parseUTF8 (inDataString, 3, outResultString) ;
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

//---------------------------------------------------------------------------*
  
static bool sniffUTFEncodingAndParse (const C_Data & inDataString,
                                      PMTextFileEncoding & outTextFileEncoding,
                                      C_String & outResultString) {
//--- Try UTF-8
  bool ok = C_String::parseUTF8 (inDataString, 0, outResultString) ;
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

//---------------------------------------------------------------------------*
  
typedef struct {
  const char * mEncodingName ;
  const PMTextFileEncoding mTextFileEncoding ;
  const PMStringEncoding mStringEncoding ;
} encodingStruct ;

//---------------------------------------------------------------------------*
  
static const PMSInt32 kEncodingCount = 18 ;

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

//---------------------------------------------------------------------------*
  
static bool parseWithEncoding (const C_Data & inDataString,
                               const PMStringEncoding inTextFileEncoding,
                               C_String & outString) {
  bool foundCR = false ;
  bool ok = true ;
  PMSInt32 idx = 0 ;
  while ((idx < inDataString.length ()) && (inDataString (idx COMMA_HERE) != 0) && ok) {
    const PMUInt8 c = inDataString (idx COMMA_HERE) ;
    if (c == 0x0A) { // LF
      if (! foundCR) {
        outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
      }
      foundCR = false ;
    }else if (c == 0x0D) { // CR
      outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
      foundCR = true ;
    }else if ((c & 0x80) == 0) { // ASCII Character
      outString.appendUnicodeCharacter (TO_UNICODE (c) COMMA_HERE) ;
      foundCR = false ;
    }else{
      const utf32 uc = unicodeCharacterForSingleByteCharacter ((char) c, inTextFileEncoding) ;
      outString.appendUnicodeCharacter (uc COMMA_HERE) ;
      foundCR = false ;
    }
  }
  if (foundCR) {
    outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
static bool searchForEncodingTagAndParse (const C_Data & inDataString,
                                          PMTextFileEncoding & outTextFileEncoding,
                                          C_String & outResultString) {
//--- Copy first line
  char firstLine [1000] ;
  PMSInt32 index = 0 ;
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
  if (strstr (firstLine, "UTF-8") != NULL) {
    ok = C_String::parseUTF8 (inDataString, 0, outResultString) ;
    outTextFileEncoding = kUTF_8_FileEncoding ;
    tagFound = true ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-8 tag in first line **\n") ;
    #endif
  }
  for (PMSInt32 i=0 ; (i<kEncodingCount) && ! tagFound ; i++) {
    tagFound = strstr (firstLine, kEncodings [i].mEncodingName) != NULL ;
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

//---------------------------------------------------------------------------*
  
static void parseASCIIWithReplacementCharacter (const C_Data & inDataString,
                                                C_String & outString) {
  bool foundCR = false ;
  PMSInt32 index = 0 ;
  while (index < inDataString.length ()) {
    const PMUInt8 c = inDataString (index COMMA_HERE) ;
    index ++ ;
    if (c == 0x0A) { // LF
      if (! foundCR) {
        outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
      }
      foundCR = false ;
    }else if (c == 0x0D) { // CR
      outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
      foundCR = true ;
    }else if ((c != 0) && (c & 0x80) == 0) { // ASCII Character (not NUL)
      outString.appendUnicodeCharacter (TO_UNICODE (c) COMMA_HERE) ;
      foundCR = false ;
    }else{
      outString.appendUnicodeCharacter (UNICODE_REPLACEMENT_CHARACTER COMMA_HERE) ;
      foundCR = false ;
    }
  }
}

//---------------------------------------------------------------------------*
  
C_String C_FileManager::stringWithContentOfFile (const C_String & inFilePath,
                                                 PMTextFileEncoding & outTextFileEncoding,
                                                 bool & outOk) {
  #ifdef PRINT_SNIFF_ENCODING
    printf ("** SNIFF ENCODING for '%s': ", inFilePath.cString (HERE)) ;
  #endif
//--- Read file
  C_Data stringData ;
  outOk = binaryDataWithContentOfFile (inFilePath, stringData) ;
  const PMSInt32 length = stringData.length () ;
//--- Assign C string to C_String
  C_String result_string ;
  if (outOk) {
    result_string.setCapacity ((PMUInt32) (length + 2)) ;
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

//---------------------------------------------------------------------------*
  
C_String C_FileManager::stringWithContentOfFile (const C_String & inFilePath) {
  bool ok = false ;
  PMTextFileEncoding textFileEncoding ;
  C_String result_string = stringWithContentOfFile (inFilePath, textFileEncoding, ok) ;
//--- Assign C string to C_String
  if (! ok) {
    throw C_TextReadException (inFilePath.cString (HERE)) ;
  }
  return result_string ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Write to File
#endif

//---------------------------------------------------------------------------*

bool C_FileManager::writeStringToFile (const C_String & inString,
                                       const C_String & inFilePath) {
  C_FileManager::makeDirectoryIfDoesNotExist (inFilePath.stringByDeletingLastPathComponent ()) ;
  C_TextFileWrite file (inFilePath) ;
  bool success = file.isOpened () ;
  file << inString ;
  if (success) {
    success = file.close () ;
  }
  return success ;
}

//---------------------------------------------------------------------------*
  
bool C_FileManager::writeStringToExecutableFile (const C_String & inString,
                                                 const C_String & inFilePath) {
  makeDirectoryIfDoesNotExist (inFilePath.stringByDeletingLastPathComponent()) ;
  C_TextFileWrite file (inFilePath) ;
  file << inString ;
  bool success = file.isOpened () ;
  if (success) {
    success = file.close () ;
    #ifndef COMPILE_FOR_WIN32
      struct stat fileStat ;
      ::stat (inFilePath.cString (HERE), & fileStat) ;
      // printf ("FILE MODE 0x%X\n", fileStat.st_mode) ;
      ::chmod (inFilePath.cString (HERE), fileStat.st_mode | S_IXUSR | S_IXGRP | S_IXOTH) ;
    #endif
  }
  return success ;
}

//---------------------------------------------------------------------------*
  
bool C_FileManager::writeBinaryDataToFile (const C_Data & inBinaryData,
                                           const C_String & inFilePath) {
  makeDirectoryIfDoesNotExist (inFilePath.stringByDeletingLastPathComponent()) ;
//---
  C_BinaryFileWrite binaryFile (inFilePath) ;
  bool success = binaryFile.isOpened () ;
  binaryFile.appendData (inBinaryData) ;
//--- Close file
  if (success) {
    success = binaryFile.close () ;
  }
//---
  return success ;
}

//---------------------------------------------------------------------------*
  
bool C_FileManager::writeBinaryDataToExecutableFile (const C_Data & inBinaryData,
                                                     const C_String & inFilePath) {
  makeDirectoryIfDoesNotExist (inFilePath.stringByDeletingLastPathComponent()) ;
//---
  C_BinaryFileWrite binaryFile (inFilePath) ;
  bool success = binaryFile.isOpened () ;
  binaryFile.appendData (inBinaryData) ;
//--- Close file
  if (success) {
    success = binaryFile.close () ;
    #ifndef COMPILE_FOR_WIN32
      struct stat fileStat ;
      ::stat (inFilePath.cString (HERE), & fileStat) ;
      // printf ("FILE MODE 0x%X\n", fileStat.st_mode) ;
      ::chmod (inFilePath.cString (HERE), fileStat.st_mode | S_IXUSR | S_IXGRP | S_IXOTH) ;
    #endif
  }
//---
  return success ;
}

 //---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Make File Executable
#endif

//---------------------------------------------------------------------------*

bool C_FileManager::makeFileExecutable (const C_String & inFilePath) {
  const bool result = fileExistsAtPath (inFilePath) ;
  #ifndef COMPILE_FOR_WIN32
    if (result) {
      struct stat fileStat ;
      ::stat (inFilePath.cString (HERE), & fileStat) ;
      // printf ("FILE MODE 0x%X\n", fileStat.st_mode) ;
      ::chmod (inFilePath.cString (HERE), fileStat.st_mode | S_IXUSR | S_IXGRP | S_IXOTH) ;
    }
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Directory Handling
#endif

//---------------------------------------------------------------------------*

bool C_FileManager::directoryExists (const C_String & inDirectoryPath) {
  const C_String nativePath = nativePathWithUnixPath (inDirectoryPath) ;
//--- Get file properties
  bool exists = nativePath.length () > 0 ;
  if (exists) {
    struct stat fileProperties ;
    const int err = ::stat (nativePath.cString (HERE), & fileProperties) ;
    exists = (err == 0) && ((fileProperties.st_mode & S_IFDIR) != 0) ;
  }
 //--- Return result
  return exists ;
}

//---------------------------------------------------------------------------*

C_String C_FileManager::currentDirectory (void) {
  char * cwd = getcwd (NULL, 0) ;
  #ifdef COMPILE_FOR_WIN32
    const PMSInt32 fileLength = (PMSInt32) strlen (cwd) ;
    PMSInt32 firstChar = 0 ;
    if ((fileLength > 3)
     && isalpha (cwd [0])
     && (cwd [1] == ':')
     && (cwd [2] == '\\')) {
      cwd [1] = cwd [0] ;
      cwd [0] = '/' ;
      cwd [2] = '/' ;
      firstChar = 3 ;
    }
    for (PMSInt32 i=firstChar ; i<fileLength ; i++) {
      if (cwd [i] == '\\') {
        cwd [i] = '/' ;
      }
    }
  #endif
  const C_String result (cwd) ;
  ::free (cwd) ;
  return result ;
}

//---------------------------------------------------------------------------*

bool C_FileManager::makeDirectoryIfDoesNotExist (const C_String & inDirectoryPath) {
  const C_String s = inDirectoryPath.stringByStandardizingPath () ;
  bool ok = directoryExists (s) ;
  if (! ok) {
    ok = makeDirectoryIfDoesNotExist (s.stringByDeletingLastPathComponent ()) ;
    if (ok) {
      const C_String nativePath = nativePathWithUnixPath (inDirectoryPath) ;
    //--- Create directory (mkdir returns 0 if creation is ok)
      #ifdef COMPILE_FOR_WIN32
        const int result = ::mkdir (nativePath.cString (HERE)) ;
      #else
        const int result = ::mkdir (nativePath.cString (HERE), 0770) ;
      #endif
      ok = result == 0 ;
    }
  }
  return ok ;
}

//---------------------------------------------------------------------------*

C_String C_FileManager::removeDirectory (const C_String & inDirectoryPath) {
 C_String errorString ;
  const C_String nativePath = nativePathWithUnixPath (inDirectoryPath) ;
  const int result = rmdir (nativePath.cString (HERE)) ;
  if (result < 0) {
    errorString << ::strerror (errno) ;
  }
  return errorString ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Path Handling
#endif

//---------------------------------------------------------------------------*

bool C_FileManager::isAbsolutePath (const C_String & inPath) {
  return (inPath.length () > 0) && (UNICODE_VALUE (inPath (0 COMMA_HERE)) == '/') ;
}

//---------------------------------------------------------------------------*

C_String C_FileManager::absolutePathFromCurrentDirectory (const C_String & inPath) {
  const PMSInt32 stringLength = inPath.length () ;
  C_String result ;
  if ((stringLength > 0) && (UNICODE_VALUE (inPath (0 COMMA_HERE)) == '/')) {
    result = inPath ;
  }else{
    result = currentDirectory () + "/" + inPath ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//--- If receiver is an absolute path, returns it
//    Otherwise, prepend path argument
//    if path argument it self is relative, current directory is prepended

C_String C_FileManager::absolutePathFromPath (const C_String & inPath,
                                              const C_String & inFromPath) {
  const PMSInt32 pathLength = inPath.length () ;
  C_String result ;
  if ((pathLength > 0) && (UNICODE_VALUE (inPath (0 COMMA_HERE)) == '/')) {
    result = inPath ;
  }else{
    result = absolutePathFromCurrentDirectory (inFromPath) ;
    if (UNICODE_VALUE (result.lastCharacter (HERE)) != '/') {
      result.appendUnicodeCharacter (TO_UNICODE ('/') COMMA_HERE) ;
    }
    result.appendString (inPath) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_String C_FileManager::relativePathFromPath (const C_String & inPath,
                                              const C_String & inFromPath) {
  TC_UniqueArray <C_String> absoluteReferencePathComponents ;
  absolutePathFromCurrentDirectory (inFromPath.stringByStandardizingPath ()).componentsSeparatedByString("/", absoluteReferencePathComponents) ;
  TC_UniqueArray <C_String> absoluteReceiverPathComponents ;
  absolutePathFromCurrentDirectory (inPath.stringByStandardizingPath ()).componentsSeparatedByString("/", absoluteReceiverPathComponents) ;
  C_String result ;
  PMSInt32 idx = 0 ;
  while ((idx < absoluteReferencePathComponents.count ())
      && (idx < absoluteReceiverPathComponents.count ())
      && (absoluteReferencePathComponents (idx COMMA_HERE) == absoluteReceiverPathComponents (idx COMMA_HERE))) {
    idx ++ ;
  }
  for (PMSInt32 i=idx ; i<absoluteReferencePathComponents.count () ; i++) {
    result << "../" ;
  }
  for (PMSInt32 i=idx ; i<absoluteReceiverPathComponents.count () ; i++) {
    if (i > idx) {
      result << "/" ;
    }
    result << absoluteReceiverPathComponents (i COMMA_HERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Symbolic Link
#endif

//---------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  bool C_FileManager::makeSymbolicLinkWithPath (const C_String & /* inPath */,
                                                const C_String & /* inLinkPath */) {
    return true ; // Symbolic links are not supported on Windows
  }
#else
  bool C_FileManager::makeSymbolicLinkWithPath (const C_String & inPath,
                                                const C_String & inLinkPath) {
    const int r = symlink (inPath.cString (HERE), inLinkPath.cString (HERE)) ;
    return r >= 0 ;
  }
#endif

//---------------------------------------------------------------------------*

// See http://www.gnu.org/s/libc/manual/html_node/Symbolic-Links.html

//--- Symbolic links and Windows:
// See http://answers.google.com/answers/threadview/id/341355.html

//---------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  bool C_FileManager::isSymbolicLink (const C_String & /* inLinkPath */) {
    return false ; // Symbolic links are not supported on Windows
  }
#endif

//---------------------------------------------------------------------------*

#ifndef COMPILE_FOR_WIN32
  bool C_FileManager::isSymbolicLink (const C_String & inLinkPath) {
    char buffer [8] ; // Any value
    return readlink (inLinkPath.cString (HERE), buffer, 8) >= 0 ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  C_String C_FileManager::stringWithSymbolicLinkContents (const C_String & /* inLinkPath */,
                                                          bool & outOk) {
    outOk = false ; // Symbolic links are not supported on Windows
    return C_String () ;
  }
#endif

//---------------------------------------------------------------------------*

#ifndef COMPILE_FOR_WIN32
  C_String C_FileManager::stringWithSymbolicLinkContents (const C_String & inLinkPath,
                                                          bool & outOk) {
    C_String result ;
    bool loop = true ;
    outOk = true ;
    char * buffer = NULL ;
    size_t bufferSize = 128 ;
    while (loop) {
      macroMyReallocPODArray (buffer, char, bufferSize) ;
      const PMSInt64 r = readlink (inLinkPath.cString (HERE), buffer, bufferSize) ;
      if (r < 0) { // Error
        outOk = false ;
        loop = false ;
      }else if (r < (PMSInt64) bufferSize) { // ok
        buffer [r] = '\0' ;
        result << buffer ;
        loop = false ;
      }else{ // Buffer too small
        bufferSize *= 2 ;
      }
    }
    macroMyDeletePODArray (buffer) ;
    return result ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Delete File
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//  Delete file                                                              *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_FileManager::deleteFile (const C_String & inFilePath) {
  C_String returnValue ;
  const C_String nativePath = nativePathWithUnixPath (inFilePath) ;
  const int result = unlink (nativePath.cString (HERE)) ;
  if (result < 0) {
    returnValue << ::strerror (errno) ;
  }
  return returnValue ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Search a file in a directory
#endif

//---------------------------------------------------------------------------*

// #define DEBUG_recursiveSearchInDirectory

//---------------------------------------------------------------------------*

static C_String recursiveSearchInDirectory (const C_String & inStartSearchPath,
                                            const C_String & inFileName,
                                            const PMSInt32 inDirectoriesToExcludeCount,
                                            const TC_UniqueArray <C_String> & inDirectoriesToExclude) {
  C_String result ;
  const C_String nativeStartSearchPath = C_FileManager::nativePathWithUnixPath (inStartSearchPath) ;
  DIR * dir = ::opendir (nativeStartSearchPath.cString (HERE)) ;
  if (dir != NULL) {
    C_String fileName = inStartSearchPath ;
    fileName << "/" << inFileName ;
    if (C_FileManager::fileExistsAtPath (fileName)) {
      #ifdef DEBUG_recursiveSearchInDirectory
        co << "** FILE '" << fileName << "' EXISTS **\n" ;
      #endif
      result = fileName ;
    }else{
      struct dirent  * current = readdir (dir) ;
      while ((current != NULL) && (result.length () == 0)) {
        if (current->d_name [0] != '.') {
          C_String name = inStartSearchPath ;
          name.appendCString ("/") ;
          name.appendCString (current->d_name) ;
          if (C_FileManager::directoryExists (name)) {
            bool dirOk = true ;
            for (PMSInt32 i=0 ; (i<inDirectoriesToExcludeCount) && dirOk ; i++) {
              if (UNICODE_VALUE (inDirectoriesToExclude (i COMMA_HERE) (0 COMMA_HERE)) == '.') {
                const char * dotPtr = strrchr (current->d_name, '.') ;
                dirOk = (dotPtr == NULL) || (inDirectoriesToExclude (i COMMA_HERE).compare (dotPtr) != 0) ;
              }else{
                dirOk = inDirectoriesToExclude (i COMMA_HERE).compare (current->d_name) != 0 ;
              }
              #ifdef DEBUG_recursiveSearchInDirectory
                if (! dirOk) {
                  co << "** REJECTED DIR '" << name << "' **\n" ;
                }
              #endif
            }
            if (dirOk) {
              #ifdef DEBUG_recursiveSearchInDirectory
                co << "** SEARCH IN DIR '" << name << "' **\n" ;
              #endif
              result = recursiveSearchInDirectory (name, inFileName, inDirectoriesToExcludeCount, inDirectoriesToExclude) ;
            }
          }
        }
        current = readdir (dir) ;
      }
    }
    closedir (dir) ;
  }
  #ifdef DEBUG_recursiveSearchInDirectory
    co << "** RESULT IS '" << result << "' **\n" ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

C_String C_FileManager::findFileInDirectory (const C_String & inDirectoryPath,
                                             const C_String & inFileName,
                                             const TC_UniqueArray <C_String> & inDirectoriesToExclude) {
  const PMSInt32 directoriesToExcludeCount = inDirectoriesToExclude.count () ;
  #ifdef DEBUG_recursiveSearchInDirectory
    co << "************* Search in directory '" << *this << "'\n"
          "** File to search '" << inFileName << "'\n'" ;
    for (PMSInt32 i=0 ; i<directoriesToExcludeCount ; i++) {
      co << "** Exclude '" << inDirectoriesToExclude (i COMMA_HERE) << "'\n'" ;
    }
  #endif
  return recursiveSearchInDirectory (inDirectoryPath, inFileName, directoriesToExcludeCount, inDirectoriesToExclude) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Find all files in a directory
#endif

//---------------------------------------------------------------------------*

static void recursiveFindAllFilesInDirectory (const C_String & inStartSearchPath,
                                              const C_String & inExtension,
                                              TC_UniqueArray <C_String> & outFoundFilePathes) {
//--- Iterate throught directory
  const C_String nativeStartSearchPath = C_FileManager::nativePathWithUnixPath (inStartSearchPath) ;
  DIR * dir = ::opendir (nativeStartSearchPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if (current->d_name [0] != '.') {
        C_String name = inStartSearchPath ;
        name.appendCString ("/") ;
        name.appendCString (current->d_name) ;
        if (C_FileManager::directoryExists (name)) {
          recursiveFindAllFilesInDirectory (name, inExtension, outFoundFilePathes) ;
        }else if (C_FileManager::fileExistsAtPath (name) && (name.pathExtension () == inExtension)) {
          outFoundFilePathes.addObject (name) ;
        }
      }
      current = readdir (dir) ;
    }
    closedir (dir) ;
  }
}

//---------------------------------------------------------------------------*

void C_FileManager::findAllFilesInDirectoryFromExtension (const C_String & inDirectoryPath,
                                                          const C_String & inExtension,
                                                          TC_UniqueArray <C_String> & outFoundFilePathes) {
  if (directoryExists (inDirectoryPath)) {
    recursiveFindAllFilesInDirectory (inDirectoryPath, inExtension, outFoundFilePathes) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Files Modification Time
#endif

//---------------------------------------------------------------------------*

C_DateTime C_FileManager::fileModificationTime (const C_String & inFilePath) {
  const C_String nativePath = nativePathWithUnixPath (inFilePath) ;
//--- Get file properties
  time_t modificationTime = 0 ;
  if (nativePath.length () > 0) {
    struct stat fileProperties ;
    const int err = ::stat (nativePath.cString (HERE), & fileProperties) ;
    if ((err == 0) && ((fileProperties.st_mode & S_IFREG) != 0)) {
      modificationTime = fileProperties.st_mtime ;
    }
  }
//--- Return modification date
  return C_DateTime (modificationTime)  ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Files permissions
#endif

//---------------------------------------------------------------------------*

PMSInt32 C_FileManager::filePosixPermissions (const C_String & inFilePath) {
  const C_String nativePath = nativePathWithUnixPath (inFilePath) ;
//--- Get file properties
  PMSInt32 permissions = -1 ;
  struct stat fileProperties ;
  const int err = ::stat (nativePath.cString (HERE), & fileProperties) ;
  if (err == 0) {
    permissions = ((PMSInt32) fileProperties.st_mode) & 0xFFF ;
  }
 //--- Return result
  return permissions ;
}

//---------------------------------------------------------------------------*

PMSInt32 C_FileManager::setFilePosixPermissions (const C_String & inFilePath,
                                                 const PMSInt32 inNewFilePosixPermissions) {
  PMSInt32 newMode = -1 ; // Error Code
  if ((inNewFilePosixPermissions & 0xFFFFF000L) == 0) {
    const C_String nativePath = nativePathWithUnixPath (inFilePath) ;
    newMode = ::chmod (nativePath.cString (HERE), (PMUInt16) (inNewFilePosixPermissions & PMUINT16_MAX)) ;
  }
  return newMode ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Files exists at path
#endif

//---------------------------------------------------------------------------*

bool C_FileManager::fileExistsAtPath (const C_String & inFilePath) {
  const C_String nativePath = nativePathWithUnixPath (inFilePath) ;
//--- Get file properties
  bool exists = nativePath.length () > 0 ;
  if (exists) {
    struct stat fileProperties ;
    const int err = ::stat (nativePath.cString (HERE), & fileProperties) ;
    exists = (err == 0) && ((fileProperties.st_mode & S_IFREG) != 0) ;
  }
 //--- Return result
  return exists ;
}

//---------------------------------------------------------------------------*

