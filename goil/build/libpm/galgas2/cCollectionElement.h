//----------------------------------------------------------------------------------------------------------------------
//
//  GALGAS_enumerable : Base class for GALGAS enumerable object                                  
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2010, ..., 2010 Pierre Molinaro.
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

#include "utilities/C_SharedObject.h"
#include "galgas2/typeComparisonResult.h"

//----------------------------------------------------------------------------------------------------------------------

class C_String ;

//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement : public C_SharedObject {
//--- Default constructor
  public: cCollectionElement (LOCATION_ARGS) ;

//--- No copy
  private: cCollectionElement (const cCollectionElement &) ;
  private: cCollectionElement & operator = (const cCollectionElement &) ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const = 0 ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const = 0 ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) = 0 ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const = 0 ;
} ;

//----------------------------------------------------------------------------------------------------------------------
