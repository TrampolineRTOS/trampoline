//--------------------------------------------------------------------------------------------------
//
//  'C_ConsoleOut' : a class for console output                                                  
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2002, ..., 2023 Pierre Molinaro.
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

#include "C_ColoredConsole.h"

//--------------------------------------------------------------------------------------------------

class C_ConsoleOut final : public C_ColoredConsole {
//--- Constructor
  public: C_ConsoleOut (void) ;

//--- Flush output
  public: virtual void flush (void) ;
  
//--- General stream method
  protected: virtual void handleAppendUTF8Array (const char * inCharArray,
                                                 const int32_t inArrayCount) ;

  protected: virtual void handleAppendCharacter (const utf32 inCharacter) ;
} ;

//--------------------------------------------------------------------------------------------------
//
//  C O N S O L E    O U T    G L O B A L   V A R I A B L E                                      
//
//--------------------------------------------------------------------------------------------------

extern C_ConsoleOut gCout ;

//--------------------------------------------------------------------------------------------------
