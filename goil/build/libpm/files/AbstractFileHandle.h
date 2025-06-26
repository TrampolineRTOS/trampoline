//--------------------------------------------------------------------------------------------------
//
//  'AbstractFileHandle' : an abstract class for handling files handles
//
//  This file is part of libpm library
//
//  Copyright (C) 2012, ..., 2024 Pierre Molinaro.
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

#pragma once

//--------------------------------------------------------------------------------------------------

#include "FileManager.h"

//--------------------------------------------------------------------------------------------------

class AbstractFileHandle {
//--- Private attribute
  private: FILE * mFilePtr ;
  private: String mFilePath ;

//--- Protected constructor
  protected: AbstractFileHandle (const String & inFilePath,
                                 const char * inMode) ;

//--- No copy
  private: AbstractFileHandle (const AbstractFileHandle &) = delete ;
  private: AbstractFileHandle & operator = (const AbstractFileHandle &) = delete ;

//--- Virtual destructor
  public: virtual ~ AbstractFileHandle (void) ;

  public: virtual bool close (void) ;
  public: virtual void flush (void) ;

//---
  public: inline bool isOpened (void) const { return nullptr != mFilePtr ; }
  public: inline String filePath (void) const { return mFilePath ; }

//---
  public: void appendBinaryData (const size_t inByteCount, const uint8_t * inByteArray) ;
  public: void appendUTF8String (const int inByteCount, const char * inByteArray) ;
} ;


//--------------------------------------------------------------------------------------------------
