//--------------------------------------------------------------------------------------------------
//
//  'TextFileWrite' : a class for stream writing text files                                    
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1999, ..., 2023 Pierre Molinaro.
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
#include "AbstractOutputStream.h"
#include "AbstractFileHandle.h"

//--------------------------------------------------------------------------------------------------

#include <stdio.h>

//--------------------------------------------------------------------------------------------------

class TextFileWrite : public AbstractOutputStream, public AbstractFileHandle {
//--- Constructor : if inFileName is the empty string, no file is opened.
//    Otherwise, it tries to open the file for writing;
//    The destructor will close the file (is successfully opened)
  public: TextFileWrite (const String & inFileName) ;

//--- No copy
  private: TextFileWrite (TextFileWrite &) = delete ;
  private: TextFileWrite & operator = (TextFileWrite &) = delete ;

//--- General stream methods
  protected: virtual void handleAppendUTF8Array (const char * inCharArray,
                                                        const int32_t inArrayCount) override ;

  protected: virtual void handleAppendCharacter (const utf32 inCharacter) override ;
} ;

//--------------------------------------------------------------------------------------------------
