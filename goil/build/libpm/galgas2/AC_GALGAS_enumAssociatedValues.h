//--------------------------------------------------------------------------------------------------
//
//  AC_GALGAS_enumAssociatedValues : class for enum associated values                            
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2014, ..., 2014 Pierre Molinaro.
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

#include "SharedObject.h"
#include "AC_GALGAS_root.h"
#include "typeComparisonResult.h"

//--------------------------------------------------------------------------------------------------

class cEnumAssociatedValues : public SharedObject {
  public: cEnumAssociatedValues (LOCATION_ARGS) ;

  public: virtual void description (class String & ioString,
                                     const int32_t inIndentation) const = 0 ;
  public: virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const = 0 ;
  
  public: virtual ~ cEnumAssociatedValues (void) {}
} ;

//--------------------------------------------------------------------------------------------------

class AC_GALGAS_enumAssociatedValues {
  private: const cEnumAssociatedValues * mSharedPtr ;

//--- Default constructor
  public: AC_GALGAS_enumAssociatedValues (void) ;

//---
  public: void setPointer (const cEnumAssociatedValues * inUniquePtr) ;

//--- Handle copy
  public: AC_GALGAS_enumAssociatedValues (const AC_GALGAS_enumAssociatedValues & inSource) ;
  public: AC_GALGAS_enumAssociatedValues & operator = (const AC_GALGAS_enumAssociatedValues & inSource) ;

//--- Destructor
  public: virtual ~ AC_GALGAS_enumAssociatedValues (void) ;

//---
  public: VIRTUAL_IN_DEBUG void description (String & ioString, const int32_t inIndentation) const ;


  public: VIRTUAL_IN_DEBUG typeComparisonResult objectCompare (const AC_GALGAS_enumAssociatedValues & inOperand) const ;

  public: VIRTUAL_IN_DEBUG const cEnumAssociatedValues * unsafePointer (void) const {
    return mSharedPtr ;
  }
} ;

//--------------------------------------------------------------------------------------------------
