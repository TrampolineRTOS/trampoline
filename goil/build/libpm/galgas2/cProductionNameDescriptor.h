//--------------------------------------------------------------------------------------------------
//
//  'Lexique' : an abstract lexique class ;                                                    
//  Galgas generated scanner classes inherit from this class.                                    
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1996, ..., 2023 Pierre Molinaro.
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

#include "M_machine.h"

//--------------------------------------------------------------------------------------------------
//
//  P R O D U C T I O N    N A M E    D E S C R I P T O R                                        
//
//--------------------------------------------------------------------------------------------------

class cProductionNameDescriptor final {
  public: const char * mName ;
  public: const char * mFileName ;
  public: const uint32_t mLineNumber ;
} ;

//--------------------------------------------------------------------------------------------------
