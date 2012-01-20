//---------------------------------------------------------------------------*
//                                                                           *
//  'C_TextFileWrite' : a class for stream writing text files                *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1999, ..., 2010 Pierre Molinaro.                           *
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

#include "files/C_TextFileWrite.h"
#include "time/C_DateTime.h"
#include "strings/unicode_character_cpp.h"

//---------------------------------------------------------------------------*

#include <string.h>
#include <ctype.h>

#ifdef TARGET_API_MAC_CARBON
  #include <unix.h>
#endif

//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  static C_String unixPath2macOSpath (const C_String & inPath) {
    C_String macOSpath ;
    const PMSInt32 length = inPath.length () ;
    if (length > 0) {
    //--- Replace '/' by ':'
      for (PMSInt32 i=0 ; i<length ; i++) {
        const utf32 c = inPath (i COMMA_HERE) ;
        macOSpath.appendUnicodeCharacter ((UNICODE_VALUE (c) == '/') ? TO_UNICODE (':') : c COMMA_HERE) ;
      }
    //--- if first character is ':', following char must be 'Volumes:' : suppress them
      if ((UNICODE_VALUE (macOSpath (0 COMMA_HERE)) == ':') && (macOSpath.length () > 9)) {
        macOSpath.suppress (0, 9 COMMA_HERE) ;
      }
    }
    return macOSpath ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  static C_String unixPath2winPath (const C_String & inWinFileName) {
    C_String winFileName ;
      const PMSInt32 fileLength = inWinFileName.length () ;
      PMSInt32 firstChar = 0 ;
      if ((fileLength > 3)
       && (UNICODE_VALUE (inWinFileName (0 COMMA_HERE)) == '/')
       && isalpha ((int) UNICODE_VALUE (inWinFileName (1 COMMA_HERE)))
       && (UNICODE_VALUE (inWinFileName (2 COMMA_HERE)) == '/')) {
        winFileName.appendUnicodeCharacter (inWinFileName (1 COMMA_HERE) COMMA_HERE) ;
        winFileName << ":\\" ;
        firstChar = 3 ;
      }
      for (PMSInt32 i=firstChar ; i<fileLength ; i++) {
        const utf32 c = (UNICODE_VALUE (inWinFileName (i COMMA_HERE)) == '/')
          ? TO_UNICODE ('\\')
          : inWinFileName (i COMMA_HERE) ;
        winFileName.appendUnicodeCharacter (c COMMA_HERE) ;
      }
    return winFileName ;
  }
#endif

//---------------------------------------------------------------------------*

C_TextFileWrite::C_TextFileWrite (const C_String & inFileName
                                  COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT,
                                  bool & outOk) :
mFileName (inFileName),
mFilePtr((FILE *) NULL),
mBufferLength (0) {
  outOk = true ;
//--- If 'inFileName' is the empty string, do not create the file
//    so that 'mFilePtr' remains equal to NULL
  if (inFileName.length () > 0) {
  //--- Open file in "wt" mode
  //--- Mac OS : fix creator and type
    #ifdef TARGET_API_MAC_CARBON
      _fcreator = MAC_OS_CREATOR_FORMAL_ARGUMENT_NAME ;
      _ftype = 'TEXT' ;
      mFilePtr = ::fopen (unixPath2macOSpath (inFileName).cString (HERE), "wt") ;
    #elif defined (COMPILE_FOR_WIN32)
      mFilePtr = ::fopen (unixPath2winPath (inFileName).cString (HERE), "wt") ;
    #else
      mFilePtr = ::fopen (inFileName.cString (HERE), "wt") ;
    #endif
  //--- Open Ok ?
    outOk = mFilePtr != NULL;
  }
}

//---------------------------------------------------------------------------*
//                                Close                                      *
//---------------------------------------------------------------------------*

bool C_TextFileWrite::close (void) {
  bool ok = true ;
  if (mFilePtr != NULL) {
    if (mBufferLength > 0) {
      ::fprintf (mFilePtr, "%.*s", (int) mBufferLength, mBuffer) ;
      mBufferLength = 0 ;
    }
    ok = ::fclose (mFilePtr) == 0 ; // Flushes the file, then closes it
    mFilePtr = (FILE *) NULL ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*
//                             Destructor                                    *
// Cannot call the virtual 'close' method in destructor                      *
//---------------------------------------------------------------------------*

C_TextFileWrite::~C_TextFileWrite (void) {
  if (mFilePtr != NULL) {
    if (mBufferLength > 0) {
      ::fprintf (mFilePtr, "%.*s", (int) mBufferLength, mBuffer) ;
      mBufferLength = 0 ;
    }
    ::fclose (mFilePtr) ; // Flushes the file, then closes it
    mFilePtr = (FILE *) NULL ;
  }
}

//---------------------------------------------------------------------------*
//                  Write a character string into the file                   *
//---------------------------------------------------------------------------*

void C_TextFileWrite::
performActualCharArrayOutput (const char * inCharArray,
                              const PMSInt32 inArrayCount) {
  if ((mFilePtr != NULL) && (inArrayCount > 0)) {
    if ((mBufferLength + inArrayCount) < kFileBufferSize) {
      ::memcpy (& mBuffer [mBufferLength], inCharArray, (size_t) inArrayCount) ;
      mBufferLength += inArrayCount ;
    }else{
      if (mBufferLength > 0) {
        ::fprintf (mFilePtr, "%.*s", (int) mBufferLength, mBuffer) ;
        mBufferLength = 0 ;
      }
      ::fprintf (mFilePtr, "%.*s", (int) inArrayCount, inCharArray) ;
    }
  }
}

//---------------------------------------------------------------------------*

void C_TextFileWrite::
performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                 const PMSInt32 inArrayCount) {
  if ((mFilePtr != NULL) && (inArrayCount > 0)) {
    for (PMSInt32 i=0 ; i<inArrayCount ; i++) {
      char buffer [5] ;
      const PMSInt32 length = UTF8StringFromUTF32Character (inCharArray [i], buffer) ;
      if ((mBufferLength + length) > kFileBufferSize) {
        ::fprintf (mFilePtr, "%.*s", (int) mBufferLength, mBuffer) ;
        mBufferLength = 0 ;
      }
      ::memcpy (& mBuffer [mBufferLength], buffer, (size_t) length) ;
      mBufferLength += length ;
    }
  }
}

//---------------------------------------------------------------------------*
//                   Flush print                                             *
//---------------------------------------------------------------------------*

void C_TextFileWrite::flush (void) {
  if (mFilePtr != NULL) {
    if (mBufferLength > 0) {
      ::fprintf (mFilePtr, "%.*s", (int) mBufferLength, mBuffer) ;
      mBufferLength = 0 ;
    }
    ::fflush (mFilePtr) ;
  }
}

//---------------------------------------------------------------------------*
