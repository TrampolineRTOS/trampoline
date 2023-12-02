//----------------------------------------------------------------------------------------------------------------------
//
//   G E N E R I C     A R R A Y
//
//  This file is part of libpm library
//
//  Copyright (C) 1997, ..., 2023 Pierre Molinaro.
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
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "utilities/C_SharedObject.h"
#include "utilities/M_SourceLocation.h"
#include "utilities/TF_Swap.h"
#include "utilities/MF_MemoryControl.h"
#include "utilities/cpp-allocation.h"
#include "generic-arraies/TC_UniqueArray.h"

//----------------------------------------------------------------------------------------------------------------------
//
//   Template class predeclaration
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class TC_Array ;

//----------------------------------------------------------------------------------------------------------------------
//
//   swap function for TC_Array <TYPE> classes
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void swap (TC_Array <TYPE> & ioOperand1,
                                    TC_Array <TYPE> & ioOperand2) ;

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class cSharedArray final : public C_SharedObject {
//--- Default Constructor
  public: cSharedArray (void) :
  C_SharedObject (HERE),
  mUniqueArray () {
  }

//--- Destructor
  public: ~ cSharedArray (void) {
  }

//--- Allocation Constructor (empty array)
  public: cSharedArray (const int inCapacity COMMA_LOCATION_ARGS) :
  C_SharedObject (THERE),
  mUniqueArray (inCapacity COMMA_THERE) {
  }

//--- Allocation Constructor (array initialized with inValue)
  public: cSharedArray (const int inCount,
                        const TYPE & inValue COMMA_LOCATION_ARGS) :
  C_SharedObject (THERE),
  mUniqueArray (inCount, inValue COMMA_THERE) {
  }

//--- Property
  public: TC_UniqueArray <TYPE> mUniqueArray ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//   Template class declaration
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class TC_Array final {
//--- Default Constructor
  public: TC_Array (void) ;

//--- Destructor
  public: ~ TC_Array (void) ;

//--- Allocation Constructor (empty array)
  public: TC_Array (const int inCapacity COMMA_LOCATION_ARGS) ;

//--- Allocation Constructor (array initialized with inValue)
  public: TC_Array (const int inCount,
                    const TYPE & inValue COMMA_LOCATION_ARGS) ;

//--- Handle Copy
  public: TC_Array (const TC_Array <TYPE> &) ;
  public: TC_Array <TYPE> & operator = (const TC_Array <TYPE> &) ;
  private: void insulate (void) ;

//--- swap
  friend void swap <TYPE> (TC_Array <TYPE> & ioOperand1,
                           TC_Array <TYPE> & ioOperand2) ;

//--- Methods for setting capacity
  public: void setCapacity (const int32_t inNewCapacity) ;

//--- Get Count
  public: inline int32_t count (void) const ;

//--- Array Pointer
  public: const TYPE * unsafeArrayPointer (void) const ;

//--- Add objects at the end of the array
  public: void appendObject (const TYPE & inValue) ; // inValue is copied
  public: void appendObjects (const int32_t inCount, const TYPE & inValue) ; // inValue is copied

//--- Insert
  public: void insertObjectsAtIndex (const int32_t inCount,
                                     const TYPE & inValue,
                                     const int32_t inStartingIndex
                                     COMMA_LOCATION_ARGS) ; // inValue is copied

//--- Remove all, keeping capacity
  public: void removeAllKeepingCapacity (void) ;

//--- Remove all objects and deallocate
  public: void free (void) ;

//--- Call operators
  public: TYPE & operator () (const int32_t inIndex COMMA_LOCATION_ARGS) ;
  public: TYPE operator () (const int32_t inIndex COMMA_LOCATION_ARGS) const ;

//--- Element access (with index checking)
  public: TYPE lastObject (LOCATION_ARGS) const ;
  public: TYPE & lastObject (LOCATION_ARGS) ;

  public: void setObjectAtIndex (const TYPE & inObject,
                                  const int32_t inIndex
                                  COMMA_LOCATION_ARGS) ;

//--- Insert object at index (0 <= index <= count)
  public: void insertObjectAtIndex (const TYPE & inValue,
                                    const int32_t inIndex
                                    COMMA_LOCATION_ARGS) ; // inValue is copied

//------------------------------------ Sorted array operations
//--- Remove an object, suppose the array is ordered
  public: void removeObjectFromOrderedArray (const TYPE & inKey) ;

// Test is based on 'compare' method, and inValue is copied, object is added if not already in array
  public: void appendUniqueObjectInOrderedArray (const TYPE & inKey) ;

//--- Return -1 if not found
  public: int32_t indexOfObjectInOrderedArray (const TYPE & inKey) const ;

//--- Intersection
  public: void intersectionOfOrderedArraies (const TC_Array<TYPE> & inOperand,
                                             TC_Array<TYPE> & outResult) const ;

//--- Union
  public: void unionOfOrderedArraies (const TC_Array<TYPE> & inOperand,
                                      TC_Array<TYPE> & outResult) const ;

//--- subtract
  public: void subtractOfOrderedArraies (const TC_Array<TYPE> & inSubtractedSet,
                                         TC_Array<TYPE> & outResult) const ;

//--- Remove last object(s)
  public: void removeLastObject (LOCATION_ARGS) ;
  public: void removeLastObjects (const int32_t inCount COMMA_LOCATION_ARGS) ;

//--- Comparisons (based on == operator on objects)
  public: bool operator == (const TC_Array <TYPE> & inOperand) const ;

  public: inline bool operator != (const TC_Array <TYPE> & inOperand) const {
    return ! ((*this) == inOperand) ;
  }

//--- Allocation with provided data
  public: void setDataFromPointer (TYPE * & ioDataPtr,
                                   const int32_t inDataLength) ;

//--- Append data
  public: void appendDataFromPointer (const TYPE * inDataPtr,
                                      const int32_t inDataLength) ;

//--- Remove objects at index (0 <= index < count)
  public: void removeObjectAtIndex (const int32_t inIndex
                                    COMMA_LOCATION_ARGS) ;

  public: void removeObjectsAtIndex (const int32_t inCount,
                                     const int32_t inStartingIndex
                                     COMMA_LOCATION_ARGS) ;

//--- Shared Array
  private: cSharedArray <TYPE> * mSharedArray ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//   Default Constructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array <TYPE>::TC_Array (void) :
mSharedArray (nullptr) {
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Destructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array <TYPE>::~ TC_Array (void) {
  macroDetachSharedObject (mSharedArray) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Allocation Constructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array <TYPE>::TC_Array (const int inCapacity COMMA_LOCATION_ARGS) :
mSharedArray (nullptr) {
  macroMyNew (mSharedArray, cSharedArray <TYPE> (inCapacity COMMA_THERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Allocation Constructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array <TYPE>:: TC_Array (const int inCount, const TYPE & inValue COMMA_LOCATION_ARGS) :
mSharedArray (nullptr) {
  macroMyNew (mSharedArray, cSharedArray <TYPE> (inCount, inValue COMMA_THERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Copy Constructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array <TYPE>::TC_Array (const TC_Array <TYPE> & inOperand) :
mSharedArray (nullptr) {
  macroAssignSharedObject (mSharedArray, inOperand.mSharedArray) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Assignment Operator
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array <TYPE> & TC_Array <TYPE>::operator = (const TC_Array <TYPE> & inOperand) {
  if (mSharedArray != inOperand.mSharedArray) {
    macroAssignSharedObject (mSharedArray, inOperand.mSharedArray) ;
  }
  return *this ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   swap function for TC_Array <TYPE> classes
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void swap (TC_Array <TYPE> & ioOperand1,
                                    TC_Array <TYPE> & ioOperand2) {
  swap (ioOperand1.mSharedArray, ioOperand2.mSharedArray) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Count
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> int32_t TC_Array <TYPE>::count (void) const {
  int32_t result = 0 ;
  if (nullptr != mSharedArray) {
    result = mSharedArray->mUniqueArray.count () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   unsafeArrayPointer
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> const TYPE * TC_Array <TYPE>::unsafeArrayPointer (void) const {
  const TYPE * result = 0 ;
  if (nullptr != mSharedArray) {
    result = mSharedArray->mUniqueArray.unsafeArrayPointer () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   insulate
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::insulate (void) {
  if ((nullptr != mSharedArray) && !mSharedArray->isUniquelyReferenced ()) {
    cSharedArray <TYPE> * p = nullptr ;
    macroMyNew (p, cSharedArray <TYPE> ()) ;
    mSharedArray->mUniqueArray.copyTo (p->mUniqueArray) ;
    macroAssignSharedObject (mSharedArray, p) ;
    macroDetachSharedObject (p) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//   appendObject (inValue is copied)
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::appendObject (const TYPE & inValue) {
  if (nullptr == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
  }else{
    insulate () ;
  }
  mSharedArray->mUniqueArray.appendObject (inValue) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::appendObjects (const int32_t inCount,
                                                              const TYPE & inValue) { // inValue is copied
  if (inCount > 0) {
    if (nullptr == mSharedArray) {
      macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
    }else{
      insulate () ;
    }
    mSharedArray->mUniqueArray.appendObjects (inCount, inValue) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::insertObjectsAtIndex (const int32_t inCount,
                                                                     const TYPE & inValue,
                                                                     const int32_t inStartingIndex
                                                                     COMMA_LOCATION_ARGS) { // inValue is copied
  if (inCount > 0) {
    if (nullptr == mSharedArray) {
      macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
    }else{
      insulate () ;
    }
    mSharedArray->mUniqueArray.insertObjectsAtIndex (inCount, inValue, inStartingIndex COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   free (remove all objects and deallocate)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::free (void) {
  macroDetachSharedObject (mSharedArray) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   CALL operators
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TYPE & TC_Array <TYPE>::operator () (const int32_t inIndex COMMA_LOCATION_ARGS) {
  if (nullptr == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
  }else{
    insulate () ;
  }
  macroValidPointer (mSharedArray) ;
  return mSharedArray->mUniqueArray (inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TYPE TC_Array <TYPE>::operator () (const int32_t inIndex COMMA_LOCATION_ARGS) const {
  macroValidPointer (mSharedArray) ;
  return mSharedArray->mUniqueArray (inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Last object access (with index checking)
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TYPE TC_Array <TYPE>::lastObject (LOCATION_ARGS) const {
  macroValidPointer (mSharedArray) ;
  return mSharedArray->mUniqueArray.lastObject (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TYPE & TC_Array <TYPE>::lastObject (LOCATION_ARGS) {
  if (nullptr == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
  }else{
    insulate () ;
  }
  macroValidPointer (mSharedArray) ;
  return mSharedArray->mUniqueArray.lastObject (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove last object
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::removeLastObject (LOCATION_ARGS) {
  insulate () ;
  macroValidPointer (mSharedArray) ;
  mSharedArray->mUniqueArray.removeLastObject (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove last objects
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::removeLastObjects (const int32_t inCount COMMA_LOCATION_ARGS) {
  insulate () ;
  macroValidPointer (mSharedArray) ;
  mSharedArray->mUniqueArray.removeLastObjects (inCount COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Set Count To zero
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::removeAllKeepingCapacity (void) {
  if (nullptr != mSharedArray) {
    insulate () ;
    mSharedArray->mUniqueArray.removeAllKeepingCapacity () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   ==
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> bool TC_Array <TYPE>::operator == (const TC_Array <TYPE> & inOperand) const {
  bool result = mSharedArray == inOperand.mSharedArray ;
  if (!result && (mSharedArray != nullptr) && (inOperand.mSharedArray != nullptr)) {
    result = mSharedArray->mUniqueArray == inOperand.mSharedArray->mUniqueArray ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   setDataFromPointer
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::setDataFromPointer (TYPE * & ioDataPtr,
                                                                   const int32_t inDataLength) {
  if (nullptr != mSharedArray) {
    macroDetachSharedObject (mSharedArray) ;
  }
  macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
  mSharedArray->mUniqueArray.setDataFromPointer (ioDataPtr, inDataLength) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   appendDataFromPointer
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::appendDataFromPointer (const TYPE * inDataPtr,
                                                                      const int32_t inDataLength) {
  if (nullptr == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
  }else{
    insulate () ;
  }
  mSharedArray->mUniqueArray.appendDataFromPointer (inDataPtr, inDataLength) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   setCapacity
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::setCapacity (const int32_t inNewCapacity) {
  if (nullptr == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE> (inNewCapacity COMMA_HERE)) ;
  }else{
    insulate () ;
    mSharedArray->mUniqueArray.setCapacity (inNewCapacity) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove objects at index (0 <= index < count)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::removeObjectAtIndex (const int32_t inIndex
                                                                    COMMA_LOCATION_ARGS) {
  insulate () ;
  macroUniqueSharedObject (mSharedArray) ;
  mSharedArray->mUniqueArray.removeObjectAtIndex (inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::removeObjectsAtIndex (const int32_t inCount,
                                                                     const int32_t inStartingIndex
                                                                     COMMA_LOCATION_ARGS) {
  insulate () ;
  macroUniqueSharedObject (mSharedArray) ;
  mSharedArray->mUniqueArray.removeObjectsAtIndex (inCount, inStartingIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   setObjectAtIndex
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::setObjectAtIndex (const TYPE & inObject,
                                                                 const int32_t inIndex
                                                                 COMMA_LOCATION_ARGS) {
  insulate () ;
  macroUniqueSharedObject (mSharedArray) ;
  mSharedArray->mUniqueArray.setObjectAtIndex (inObject, inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   insertObjectAtIndex
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::insertObjectAtIndex (const TYPE & inObject,
                                                                    const int32_t inIndex  // inValue is copied
                                                                    COMMA_LOCATION_ARGS) {
  if (nullptr == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE>) ;
  }else{
    insulate () ;
  }
  macroUniqueSharedObject (mSharedArray) ;
  mSharedArray->mUniqueArray.insertObjectAtIndex (inObject, inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   appendUniqueObjectInOrderedArray
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::appendUniqueObjectInOrderedArray (const TYPE & inKey) {
  if (nullptr == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE>) ;
  }else{
    insulate () ;
  }
  macroUniqueSharedObject (mSharedArray) ;
  mSharedArray->mUniqueArray.appendUniqueObjectInOrderedArray (inKey) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   removeObjectFromOrderedArray
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::removeObjectFromOrderedArray (const TYPE & inKey) {
  if (nullptr != mSharedArray) {
    insulate () ;
    macroUniqueSharedObject (mSharedArray) ;
    mSharedArray->mUniqueArray.removeObjectFromOrderedArray (inKey) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   indexOfObjectInOrderedArray
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> int32_t TC_Array <TYPE>::indexOfObjectInOrderedArray (const TYPE & inKey) const {
  int32_t result = -1 ; // Not found
  if (nullptr != mSharedArray) {
    macroValidPointer (mSharedArray) ;
    result = mSharedArray->mUniqueArray.indexOfObjectInOrderedArray (inKey) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   intersectionOfOrderedArraies
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::intersectionOfOrderedArraies (const TC_Array<TYPE> & inOperand,
                                                                             TC_Array<TYPE> & outResult) const {
  outResult.removeAllKeepingCapacity () ;
  if ((count () > 0) && (inOperand.count () > 0)) {
    if (nullptr == outResult.mSharedArray) {
      macroMyNew (outResult.mSharedArray, cSharedArray <TYPE>) ;
    }else{
      outResult.insulate () ;
    }
    macroUniqueSharedObject (outResult.mSharedArray) ;
    macroValidPointer (mSharedArray) ;
    macroValidPointer (inOperand.mSharedArray) ;
    mSharedArray->mUniqueArray.intersectionOfOrderedArraies (inOperand.mSharedArray->mUniqueArray, outResult.mSharedArray->mUniqueArray) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   unionOfOrderedArraies
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::unionOfOrderedArraies (const TC_Array<TYPE> & inOperand,
                                                                      TC_Array<TYPE> & outResult) const {
  outResult.removeAllKeepingCapacity () ;
  if ((count () > 0) && (inOperand.count () == 0)) {
    outResult = *this ;
  }else if ((count () == 0) && (inOperand.count () > 0)) {
    outResult = inOperand ;
  }else if ((count () > 0) && (inOperand.count () > 0)) {
    if (nullptr == outResult.mSharedArray) {
      macroMyNew (outResult.mSharedArray, cSharedArray <TYPE>) ;
    }else{
      outResult.insulate () ;
    }
    macroUniqueSharedObject (outResult.mSharedArray) ;
    macroValidPointer (mSharedArray) ;
    macroValidPointer (inOperand.mSharedArray) ;
    mSharedArray->mUniqueArray.unionOfOrderedArraies (inOperand.mSharedArray->mUniqueArray, outResult.mSharedArray->mUniqueArray) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   substractOfOrderedArraies
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::subtractOfOrderedArraies (const TC_Array<TYPE> & inSubstractedSet,
                                                                         TC_Array<TYPE> & outResult) const {
  outResult.removeAllKeepingCapacity () ;
  if (count () > 0) {
    if (inSubstractedSet.count () == 0) {
      outResult = *this ;
    }else{
      if (nullptr == outResult.mSharedArray) {
        macroMyNew (outResult.mSharedArray, cSharedArray <TYPE>) ;
      }else{
        outResult.insulate () ;
      }
      macroUniqueSharedObject (outResult.mSharedArray) ;
      macroValidPointer (mSharedArray) ;
      macroValidPointer (inSubstractedSet.mSharedArray) ;
      mSharedArray->mUniqueArray.substractOfOrderedArraies (inSubstractedSet.mSharedArray->mUniqueArray, outResult.mSharedArray->mUniqueArray) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
