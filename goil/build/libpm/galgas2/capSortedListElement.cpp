//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------

#include "capSortedListElement.h"
#include "cSortedListElement.h"
#include "String-class.h"

//--------------------------------------------------------------------------------------------------

capSortedListElement::capSortedListElement (void) :
mPtr (nullptr) {
}

//--------------------------------------------------------------------------------------------------

void capSortedListElement::setPointer (cSortedListElement * inObjectPointer) {
  macroAssignSharedObject (mPtr, inObjectPointer) ;
}

//--------------------------------------------------------------------------------------------------

capSortedListElement::~ capSortedListElement (void) {
  macroDetachSharedObject (mPtr) ;
}

//--------------------------------------------------------------------------------------------------

capSortedListElement::capSortedListElement (const capSortedListElement & inSource) :
mPtr (nullptr) {
  macroAssignSharedObject (mPtr, inSource.mPtr) ;
}

//--------------------------------------------------------------------------------------------------

capSortedListElement & capSortedListElement::operator = (const capSortedListElement & inSource) {
  macroAssignSharedObject (mPtr, inSource.mPtr) ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

bool capSortedListElement::isValid (void) const {
  bool result = nullptr != mPtr ;
  if (result) {
    result = mPtr->isValid () ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

typeComparisonResult capSortedListElement::compare (capSortedListElement & inOperand) {
  macroValidSharedObject (mPtr, cSortedListElement) ;
  macroValidSharedObject (inOperand.mPtr, cSortedListElement) ;
  return mPtr->compare (inOperand.mPtr) ;
}

//--------------------------------------------------------------------------------------------------

capSortedListElement capSortedListElement::copy (void) {
  capSortedListElement result ;
  cSortedListElement * p = (cSortedListElement *) mPtr->copy () ;
  macroValidSharedObject (p, cSortedListElement) ;
  result.setPointer (p) ;
  macroDetachSharedObject (p) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void capSortedListElement::drop (void) {
  macroDetachSharedObject (mPtr) ;
}

//--------------------------------------------------------------------------------------------------

void capSortedListElement::insulate (void) {
  if ((nullptr != mPtr) && !mPtr->isUniquelyReferenced ()) {
    cSortedListElement * p = (cSortedListElement *) mPtr->copy () ;
    macroValidSharedObject (p, cSortedListElement) ;
    macroAssignSharedObject (mPtr, p) ;
    macroDetachSharedObject (p) ;
  }
}

//--------------------------------------------------------------------------------------------------

void capSortedListElement::description (String & ioString, const int32_t inIndentation) const {
  if (nullptr == mPtr) {
    ioString.appendCString ("NULL") ;
  }else{
    mPtr->description (ioString, inIndentation) ;
  }
}

//--------------------------------------------------------------------------------------------------

typeComparisonResult capSortedListElement::compareForSorting (const capSortedListElement & inOperand) {
  typeComparisonResult result = kOperandNotValid ;
  if ((nullptr != mPtr) && (nullptr != inOperand.mPtr)) {
    result = mPtr->compareForSorting (inOperand.mPtr) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
