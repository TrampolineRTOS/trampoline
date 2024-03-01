//--------------------------------------------------------------------------------------------------
//
//  AC_GALGAS_reference_class : base class for reference class objects
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
//--------------------------------------------------------------------------------------------------

#include "AC_GALGAS_reference_class.h"
#include "acStrongPtr_class.h"
#include "C_galgas_type_descriptor.h"
#include "String-class.h"

//--------------------------------------------------------------------------------------------------

#include <iostream>

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * AC_GALGAS_reference_class::dynamicTypeDescriptor (void) const {
  const C_galgas_type_descriptor * result = nullptr ;
  if (nullptr != mObjectPtr) {
    result = mObjectPtr->classDescriptor () ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_reference_class::AC_GALGAS_reference_class (void) :
AC_GALGAS_root (),
mObjectPtr (nullptr) {
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_reference_class::AC_GALGAS_reference_class (const acStrongPtr_class * inPointer) :
AC_GALGAS_root (),
mObjectPtr (nullptr) {
  macroAssignSharedObject (mObjectPtr, (acStrongPtr_class *) inPointer) ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_reference_class::~AC_GALGAS_reference_class (void) {
  macroDetachSharedObject (mObjectPtr) ;
}

//--------------------------------------------------------------------------------------------------

void AC_GALGAS_reference_class::drop (void) {
  macroDetachSharedObject (mObjectPtr) ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_reference_class::AC_GALGAS_reference_class (const AC_GALGAS_reference_class & inSource) :
AC_GALGAS_root (),
mObjectPtr (nullptr) {
  macroAssignSharedObject (mObjectPtr, inSource.mObjectPtr) ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_reference_class & AC_GALGAS_reference_class::operator = (const AC_GALGAS_reference_class & inSource) {
  macroAssignSharedObject (mObjectPtr, inSource.mObjectPtr) ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

void AC_GALGAS_reference_class::description (String & ioString,
                                             const int32_t inIndentation) const {
  ioString.appendCString ("<@") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (":") ;
  if (isValid ()) {
    mObjectPtr->description (ioString, inIndentation) ;
  }else{
    ioString.appendCString ("not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void AC_GALGAS_reference_class::printNonNullClassInstanceProperties (const char * inPropertyName) const {
    if (mObjectPtr != nullptr) {
      std::cout << "    " << inPropertyName << " : 0x" << std::hex << size_t (mObjectPtr) << std::dec << std::endl ;
    }
  }
#endif

//--------------------------------------------------------------------------------------------------
