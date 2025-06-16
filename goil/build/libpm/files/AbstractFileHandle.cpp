//--------------------------------------------------------------------------------------------------
//
//  'AbstractFileHandle' : an abstract class for handling files handles                               
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2012, ..., 2023 Pierre Molinaro.
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

#include "AbstractFileHandle.h"

//--------------------------------------------------------------------------------------------------

AbstractFileHandle::AbstractFileHandle (const String & inFilePath,
                                        const char * inMode) :
mFilePtr ((inFilePath.length () == 0)
  ? nullptr :
  ::fopen (FileManager::nativePathWithUnixPath (inFilePath).cString (), inMode)
),
mFilePath (inFilePath) {
}

//--------------------------------------------------------------------------------------------------

AbstractFileHandle::~AbstractFileHandle (void) {
  if (nullptr != mFilePtr) {
    fclose (mFilePtr) ;
    mFilePtr = nullptr ;
  }
}

//--------------------------------------------------------------------------------------------------
//                                Flush
//--------------------------------------------------------------------------------------------------

void AbstractFileHandle::flush (void) {
  if (nullptr != mFilePtr) {
    ::fflush (mFilePtr) ;
  }
}

//--------------------------------------------------------------------------------------------------
//                                Close
//--------------------------------------------------------------------------------------------------

bool AbstractFileHandle::close (void) {
  flush () ;
  bool ok = true ;
  if (mFilePtr != nullptr) {
    ok = ::fclose (mFilePtr) == 0 ; // Flushes the file, then closes it
    mFilePtr = nullptr ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------
//   appendBinaryData
//--------------------------------------------------------------------------------------------------

void AbstractFileHandle::appendBinaryData (const size_t inByteCount,
                                           const uint8_t * inByteArray) {
  if ((mFilePtr != nullptr) && (inByteCount > 0)) {
    macroCheckPointerIsNotNull (inByteArray) ;
    ::fwrite (inByteArray, sizeof (uint8_t), inByteCount, mFilePtr) ;
  }
}

//--------------------------------------------------------------------------------------------------
//   appendUTF8String
//--------------------------------------------------------------------------------------------------

void AbstractFileHandle::appendUTF8String (const int inByteCount, const char * inByteArray) {
  if ((mFilePtr != nullptr) && (inByteCount > 0)) {
    macroCheckPointerIsNotNull (inByteArray) ;
    ::fprintf (mFilePtr, "%.*s", inByteCount, inByteArray) ;
  }
}

//--------------------------------------------------------------------------------------------------
