//----------------------------------------------------------------------------------------------------------------------
//
//  'C_TextFileWrite' : a class for stream writing text files                                    
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1999, ..., 2011 Pierre Molinaro.
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
//----------------------------------------------------------------------------------------------------------------------

#include "files/C_TextFileWrite.h"
#include "time/C_DateTime.h"
#include "strings/unicode_character_cpp.h"
#include "files/C_FileManager.h"

//----------------------------------------------------------------------------------------------------------------------

#include <string.h>

//----------------------------------------------------------------------------------------------------------------------

C_TextFileWrite::C_TextFileWrite (const C_String & inFileName) :
AC_FileHandleForWriting (inFileName, "wt"),
mBufferLength (0) {
}

//----------------------------------------------------------------------------------------------------------------------
//                                Close                                                          
//----------------------------------------------------------------------------------------------------------------------

bool C_TextFileWrite::close (void) {
  bool ok = true ;
  if (mFilePtr != NULL) {
    if (mBufferLength > 0) {
      ::fprintf (mFilePtr, "%.*s", (int) mBufferLength, mBuffer) ;
      mBufferLength = 0 ;
    }
    ok = ::fclose (mFilePtr) == 0 ; // Flushes the file, then closes it
    mFilePtr = NULL ;
  }
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------
//                             Destructor                                                        
// Cannot call the virtual 'close' method in destructor                                          
//----------------------------------------------------------------------------------------------------------------------

C_TextFileWrite::~C_TextFileWrite (void) {
  if ((mFilePtr != NULL) && (mBufferLength > 0)) {
    ::fprintf (mFilePtr, "%.*s", (int) mBufferLength, mBuffer) ;
    mBufferLength = 0 ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//                  Write a character string into the file                                       
//----------------------------------------------------------------------------------------------------------------------

void C_TextFileWrite::performActualCharArrayOutput (const char * inCharArray,
                                                    const int32_t inArrayCount) {
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

//----------------------------------------------------------------------------------------------------------------------

void C_TextFileWrite::performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                                       const int32_t inArrayCount) {
  if ((mFilePtr != NULL) && (inArrayCount > 0)) {
    for (int32_t i=0 ; i<inArrayCount ; i++) {
      char buffer [5] ;
      const int32_t length = UTF8StringFromUTF32Character (inCharArray [i], buffer) ;
      if ((mBufferLength + length) > kFileBufferSize) {
        ::fprintf (mFilePtr, "%.*s", (int) mBufferLength, mBuffer) ;
        mBufferLength = 0 ;
      }
      ::memcpy (& mBuffer [mBufferLength], buffer, (size_t) length) ;
      mBufferLength += length ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
//                   Flush print                                                                 
//----------------------------------------------------------------------------------------------------------------------

void C_TextFileWrite::flush (void) {
  if (mFilePtr != NULL) {
    if (mBufferLength > 0) {
      ::fprintf (mFilePtr, "%.*s", (int) mBufferLength, mBuffer) ;
      mBufferLength = 0 ;
    }
    ::fflush (mFilePtr) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
