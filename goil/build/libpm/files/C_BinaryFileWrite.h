//----------------------------------------------------------------------------------------------------------------------
//
//  'C_BinaryFileWrite' : a class for stream writing binary files                                
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.
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

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "strings/C_String.h"
#include "files/AC_FileHandleForWriting.h"

//----------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

//----------------------------------------------------------------------------------------------------------------------

class C_BinaryFileWrite : public AC_FileHandleForWriting {
//--- Constructor : if inFileName is the empty string, no file is opened.
//    Otherwise, it tries to open the file for writing;
//    outSuccessfullyOpened is returned true is inFileName is empty or if file is successfully opened
//    outSuccessfullyOpened is returned false is inFileName is not empty and file cannot be successfully opened
//    The destructor will close the file (is successfully opened)
  public: C_BinaryFileWrite (const C_String & inFilePath) ;

//--- Destructor closes the file
  public: virtual ~ C_BinaryFileWrite (void) ;

//--- No copy
  private: C_BinaryFileWrite (C_BinaryFileWrite &) ;
  private: C_BinaryFileWrite & operator = (C_BinaryFileWrite &) ;
  
//--- 
  public: void appendData (const C_Data & inData) ;

//--- Flush print
  public: virtual void flush (void) ;

//--- Close file (does nothing is file is not open)
  public: virtual bool close (void) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
