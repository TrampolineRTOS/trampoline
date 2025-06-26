//--------------------------------------------------------------------------------------------------
//
//  acPtr_class : Base class for GALGAS class
//
//  This file is part of libpm library
//
//  Copyright (C) 2008, ..., 2010 Pierre Molinaro.
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

#include "cPtr_object.h"
#include "all-predefined-types.h"
#include "MF_MemoryControl.h"

//--------------------------------------------------------------------------------------------------

cPtr_object::cPtr_object (LOCATION_ARGS) :
SharedObject (THERE),
mEmbeddedObjectPtr (nullptr) {
}

//--------------------------------------------------------------------------------------------------

cPtr_object::cPtr_object (AC_GALGAS_root * inObjectPointer
                          COMMA_LOCATION_ARGS) :
SharedObject (THERE),
mEmbeddedObjectPtr (nullptr) {
  mEmbeddedObjectPtr = inObjectPointer ;
}

//--------------------------------------------------------------------------------------------------

cPtr_object::~cPtr_object (void) {
  macroMyDelete (mEmbeddedObjectPtr) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_object::objectStaticType (void) const {
  GALGAS_type result ;
  if (nullptr != mEmbeddedObjectPtr) {
    result = mEmbeddedObjectPtr->getter_staticType (HERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_object::objectDynamicType (void) const {
  GALGAS_type result ;
  if (nullptr != mEmbeddedObjectPtr) {
    result = mEmbeddedObjectPtr->getter_dynamicType (HERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
