//----------------------------------------------------------------------------------------------------------------------
//
//  cPtr_weakReference_proxy : Base class for reference class class
//
//  This file is part of libpm library
//
//  Copyright (C) 2021, ..., 2021 Pierre Molinaro.
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

#include "galgas2/cPtr_weakReference_proxy.h"
#include "galgas2/acStrongPtr_class.h"
#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

cPtr_weakReference_proxy::cPtr_weakReference_proxy (LOCATION_ARGS) :
acPtr_class (THERE),
mStrongObjectPtr (NULL) {
}

//----------------------------------------------------------------------------------------------------------------------

cPtr_weakReference_proxy::~ cPtr_weakReference_proxy (void) {
  if (mStrongObjectPtr != NULL) {
    mStrongObjectPtr->mProxyPtr = NULL ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_weakReference_proxy::classDescriptor (void) const {
  const C_galgas_type_descriptor * result = NULL ;
  if (mStrongObjectPtr != NULL) {
    result = mStrongObjectPtr->classDescriptor () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_weakReference_proxy::duplicate (UNUSED_LOCATION_ARGS) const {
  return NULL ;
}

//----------------------------------------------------------------------------------------------------------------------
