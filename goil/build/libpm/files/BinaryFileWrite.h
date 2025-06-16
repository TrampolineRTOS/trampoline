//--------------------------------------------------------------------------------------------------
//
//  'BinaryFileWrite' : a class for stream writing binary files                                
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
//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#include "String-class.h"
#include "AbstractFileHandle.h"

//--------------------------------------------------------------------------------------------------

#include <stdio.h>

//--------------------------------------------------------------------------------------------------

class BinaryFileWrite final : public AbstractFileHandle {
//--- Constructor : if inFileName is the empty string, no file is opened.
//    Otherwise, it tries to open the file for writing;
//    The destructor will close the file (is successfully opened)
  public: BinaryFileWrite (const String & inFilePath) ;

//--- No copy
  private: BinaryFileWrite (BinaryFileWrite &) = delete ;
  private: BinaryFileWrite & operator = (BinaryFileWrite &) = delete ;
  
//--- 
  public: void appendData (const U8Data & inData) ;
} ;

//--------------------------------------------------------------------------------------------------
