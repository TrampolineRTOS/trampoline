//--------------------------------------------------------------------------------------------------
//
//  acStrongPtr_class : Base class for reference class class
//
//  This file is part of libpm library
//
//  Copyright (C) 2021, ..., 2023 Pierre Molinaro.
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

#include "acStrongPtr_class.h"
#include "cPtr_weakReference_proxy.h"
#include "cpp-allocation.h"

//--------------------------------------------------------------------------------------------------

#include <iostream>

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  static acStrongPtr_class * gFirstPtr = nullptr ;
  static acStrongPtr_class * gLastPtr = nullptr ;
#endif

//--------------------------------------------------------------------------------------------------

acStrongPtr_class::acStrongPtr_class (LOCATION_ARGS) :
acPtr_class (THERE),
#ifndef DO_NOT_GENERATE_CHECKINGS
  mPreviousPtr (nullptr),
  mNextPtr (nullptr),
#endif
mProxyPtr (nullptr) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    mPreviousPtr = gLastPtr ;
    if (nullptr == gLastPtr) {
      gFirstPtr = this ;
    }else{
      gLastPtr->mNextPtr = this ;
    }
    gLastPtr = this ;
  #endif
}

//--------------------------------------------------------------------------------------------------

acStrongPtr_class::~ acStrongPtr_class (void) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    if (nullptr == mNextPtr) { // Last descriptor ?
      gLastPtr = mPreviousPtr ;
    }else{
      mNextPtr->mPreviousPtr = mPreviousPtr ;
    }
    if (nullptr == mPreviousPtr) { // First descriptor ?
      gFirstPtr = mNextPtr ;
    }else{
      mPreviousPtr->mNextPtr = mNextPtr ;
    }
  #endif
  if (mProxyPtr != nullptr) {
    mProxyPtr->mStrongObjectPtr = nullptr ;
    macroDetachSharedObject (mProxyPtr) ;
  }
}

//--------------------------------------------------------------------------------------------------

cPtr_weakReference_proxy * acStrongPtr_class::getProxy (void) {
  if (mProxyPtr == nullptr) {
    macroMyNew (mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    mProxyPtr->mStrongObjectPtr = this ;
  }
  return mProxyPtr ;
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void acStrongPtr_class::printNonNullClassInstanceProperties (void) const {
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void acStrongPtr_class::printExistingClassInstances (void) {
    if (gFirstPtr != nullptr) {
      std::cout << "*** Unreleased class instances" << std::endl ;
    }
    acStrongPtr_class * ptr = gFirstPtr ;
    while (ptr != nullptr) {
      std::cout << "  Instance 0x" << std::hex << size_t (ptr) << std::dec << std::endl ;
      ptr->printNonNullClassInstanceProperties () ;
      ptr = ptr->mNextPtr ;
    }
  }
#endif

//--------------------------------------------------------------------------------------------------
