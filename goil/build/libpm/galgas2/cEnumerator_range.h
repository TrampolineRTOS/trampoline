//----------------------------------------------------------------------------------------------------------------------
//
//  'cEnumerator_range' : galgas range enumerator                                                
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
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/cGenericAbstractEnumerator.h"

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_range ;
class GALGAS_uint ;

//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_range final {
//--- Constructor
  public: cEnumerator_range (const GALGAS_range & inEnumeratedRange,
                             const typeEnumerationOrder inOrder) ;

//--- Virtual destructor
  public: ~ cEnumerator_range (void) ;

//--- No copy
  private: cEnumerator_range (const cEnumerator_range &) ;
  private: cEnumerator_range & operator = (const cEnumerator_range &) ;

//--- 
  public: bool hasCurrentObject (void) const ;
  public: bool hasNextObject (void) const ;
  public: void gotoNextObject (void) ;

//--- Current element access
  public: GALGAS_uint current (LOCATION_ARGS) const ;

//---- Attributes
  private: const bool mIsValid ;
  private: const bool mAscending ;
  private: const int64_t mStart ;
  private: const int64_t mLength ;
  private: int64_t mCurrent ;
} ;

//----------------------------------------------------------------------------------------------------------------------
