//--------------------------------------------------------------------------------------------------
//
//  GALGAS_enumerable : Base class for GALGAS enumerable object
//
//  This file is part of libpm library
//
//  Copyright (C) 2010, ..., 2013 Pierre Molinaro.
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

#include "capCollectionElement.h"
#include "cCollectionElement.h"
#include "String-class.h"

//--------------------------------------------------------------------------------------------------

capCollectionElement::capCollectionElement (void) :
mPtr (nullptr) {
}

//--------------------------------------------------------------------------------------------------

void capCollectionElement::setPointer (cCollectionElement * inObjectPointer) {
  macroAssignSharedObject (mPtr, inObjectPointer) ;
}

//--------------------------------------------------------------------------------------------------

capCollectionElement:: ~capCollectionElement (void) {
  macroDetachSharedObject (mPtr) ;
}

//--------------------------------------------------------------------------------------------------

capCollectionElement::capCollectionElement (const capCollectionElement & inSource) :
mPtr (nullptr) {
  macroAssignSharedObject (mPtr, inSource.mPtr) ;
}

//--------------------------------------------------------------------------------------------------

capCollectionElement & capCollectionElement::operator = (const capCollectionElement & inSource) {
  macroAssignSharedObject (mPtr, inSource.mPtr) ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

bool capCollectionElement::isValid (void) const {
  bool result = nullptr != mPtr ;
  if (result) {
    result = mPtr->isValid () ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

typeComparisonResult capCollectionElement::compare (const capCollectionElement & inOperand) const {
  macroValidSharedObject (mPtr, cCollectionElement) ;
  macroValidSharedObject (inOperand.mPtr, cCollectionElement) ;
  return mPtr->compare (inOperand.mPtr) ;
}

//--------------------------------------------------------------------------------------------------

capCollectionElement capCollectionElement::copy (void) {
  capCollectionElement result ;
  cCollectionElement * p = mPtr->copy () ;
  result.setPointer (p) ;
  macroDetachSharedObject (p) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void capCollectionElement::drop (void) {
  macroDetachSharedObject (mPtr) ;
}

//--------------------------------------------------------------------------------------------------

void capCollectionElement::insulate (void) {
  if ((nullptr != mPtr) && !mPtr->isUniquelyReferenced ()) {
    cCollectionElement * p = mPtr->copy () ;
    macroAssignSharedObject (mPtr, p) ;
    macroDetachSharedObject (p) ;
  }
}

//--------------------------------------------------------------------------------------------------

void capCollectionElement::description (String & ioString, const int32_t inIndentation) const {
  if (nullptr == mPtr) {
    ioString.appendCString ("NULL") ;
  }else{
    mPtr->description (ioString, inIndentation) ;
  }
}

//--------------------------------------------------------------------------------------------------
