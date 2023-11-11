//----------------------------------------------------------------------------------------------------------------------
//
//            Declaration and implementation of the template class 'TC_UniqueArray'
//
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR.                    *
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
//
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "utilities/MF_Assert.h"
#include "utilities/M_SourceLocation.h"
#include "utilities/TF_Swap.h"
#include "utilities/MF_MemoryControl.h"
#include "utilities/cpp-allocation.h"

//----------------------------------------------------------------------------------------------------------------------
//
//   Template class predeclaration
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class TC_UniqueArray ;

//----------------------------------------------------------------------------------------------------------------------
//
//   swap function for TC_UniqueArray <TYPE> classes
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void swap (TC_UniqueArray <TYPE> & ioOperand1, TC_UniqueArray <TYPE> & ioOperand2) ;

//----------------------------------------------------------------------------------------------------------------------
//
//   Template class declaration
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class TC_UniqueArray {
//--- Default Constructor
  public: TC_UniqueArray (void) ;

//--- Allocation Constructor (empty array)
  public: TC_UniqueArray (const int32_t inCapacity
                          COMMA_LOCATION_ARGS) ;

//--- Allocation Constructor (array initialized with inValue)
  public: TC_UniqueArray (const int32_t inCapacity,
                           const TYPE & inValue
                           COMMA_LOCATION_ARGS) ;

//--- Virtual Destructor
  public: virtual ~TC_UniqueArray (void) ;

//--- No copy
  private: TC_UniqueArray (const TC_UniqueArray <TYPE> &) ;
  private: TC_UniqueArray <TYPE> & operator = (const TC_UniqueArray <TYPE> &) ;

//--- Copy
  public: void copyTo (TC_UniqueArray <TYPE> & outArray) const ;

//--- Get Count
  public: inline int32_t count (void) const { return mCount ; }

//--- Set Count To zero
  public: void setCountToZero (void) ;

//--- Get allocated capacity
  public: inline int32_t capacity (void) const { return mCapacity ; }

//--- Methods for setting capacity
  public: void setCapacity (const int32_t inNewCapacity) ;
  public: void setCapacityUsingSwap (const int32_t inNewCapacity) ;

//--- Allocation with provided data (ioDataPtr is captured, and nullptr is returned)
  public: void setDataFromPointer (TYPE * & ioDataPtr,
                                    const int32_t inDataLength) ;

//--- Append data (inDataPtr is not released)
  public: void appendDataFromPointer (const TYPE * inDataPtr,
                                       const int32_t inDataLength) ;

//--- Get buffer pointer
  public: const TYPE * unsecureBufferPointer (void) const { return mArray ; }

//--- Comparisons (based on == operator on objects)
  public: bool operator == (const TC_UniqueArray <TYPE> & inOperand) const ;

  public: inline bool operator != (const TC_UniqueArray <TYPE> & inOperand) const {
    return ! ((*this) == inOperand) ;
  }

//-------- Sorted array operations
  #ifndef DO_NOT_GENERATE_CHECKINGS
    private: void checkOrdered (LOCATION_ARGS) const ;
  #endif

//--- Remove an object, suppose the array is ordered
  public: void removeObjectFromOrderedArray (const TYPE & inKey) ;

// Test is based on 'compare' method, and inValue is copied, object is added if not already in array
  public: void appendUniqueObjectInOrderedArray (const TYPE & inValue) ;

//--- Return -1 if not found
  public: int32_t indexOfObjectInOrderedArray (const TYPE & inValue) const ;

//--- Intersection
  public: void intersectionOfOrderedArraies (const TC_UniqueArray<TYPE> & inOperand,
                                              TC_UniqueArray<TYPE> & outResult) const ;

//--- Union
  public: void unionOfOrderedArraies (const TC_UniqueArray<TYPE> & inOperand,
                                       TC_UniqueArray<TYPE> & outResult) const ;

//--- substract
  public: void substractOfOrderedArraies (const TC_UniqueArray<TYPE> & inSubstractedSet,
                                           TC_UniqueArray<TYPE> & outResult) const ;


//--- Intersection (based on == operator)
//    Copies (using assignment operator) elements of current object that
//    also are in inOperand array.
  public: void intersectionWithArray (const TC_UniqueArray <TYPE> & inOperand,
                                       TC_UniqueArray <TYPE> & outResult) const ;

//--- Multi set intersection (based on == operator), perserves object count.
//    If an object appears x times in current object and y times in operand,
//    it appears min (x, y) times in result.
//    Copies (using assignment operator) elements of current object that also are in inOperand array.
  public: void multiSetIntersectionWithArray (const TC_UniqueArray <TYPE> & inOperand,
                                               TC_UniqueArray <TYPE> & outResult) const ;

//--- Union (based on == operator)
//    Copies (using assignment operator) elements of current object in result,
//    then adds elements of operand that are not yet in result.
  public: void unionWithArray (const TC_UniqueArray <TYPE> & inOperand,
                                TC_UniqueArray <TYPE> & outResult) const ;

//--- Remove all objects and deallocate
  public: void free (void) ;

//--- Increment, decrement
  public: void incrementAtIndex (const int32_t inIndex
                                  COMMA_LOCATION_ARGS) ; // ++ on object

  public: void decrementAtIndex (const int32_t inIndex
                                  COMMA_LOCATION_ARGS) ; // -- on object

//--- Append objects at the end of the array
  public: void appendObject (const TYPE & inValue) ; // inValue is copied
  public: void appendObjectIfUnique (const TYPE & inValue) ; // Test is based on == operator, and inValue is copied

  public: void appendObjectUsingSwap (TYPE & ioValue) ;
  public: void appendDefaultObjectUsingSwap (void) ;
  public: void appendObjects (const int32_t inCount, const TYPE & inValue) ; // inValue is copied
  public: void appendObjectsFromArray (const TC_UniqueArray <TYPE> &  inObjectArray) ; // New objects are copied

//--- Force entry
  public: void forceObjectAtIndex (const int32_t inIndex,
                                    const TYPE & inValue,
                                    const TYPE & inDefaultValue
                                    COMMA_LOCATION_ARGS) ;

//--- Insert objects at index (0 <= index <= count)
  public: void insertObjectAtIndex (const TYPE & inValue,
                                     const int32_t inIndex
                                     COMMA_LOCATION_ARGS) ; // inValue is copied

  public: void insertObjectsAtIndex (const int32_t inCount,
                                      const TYPE & inValue,
                                      const int32_t inStartingIndex
                                      COMMA_LOCATION_ARGS) ; // inValue is copied

  public: void insertObjectUsingSwap (TYPE & ioValue,
                                       const int32_t inIndex
                                       COMMA_LOCATION_ARGS) ;

  public: void insertObjectsUsingExchangeAndClear (const int32_t inObjectCount,
                                                    const int32_t inIndex
                                                    COMMA_LOCATION_ARGS) ;

//--- Find Object (uses == operator for comparing objects)
//    Returns -1 if not found
  public: int32_t indexOfFirstObjectEqualTo (const TYPE & inValue) const ;

//--- Remove last object(s)
  public: void removeLastObject (LOCATION_ARGS) ;
  public: void removeLastObjects (const int32_t inCount COMMA_LOCATION_ARGS) ;

//--- Exchange objects at indexes (0 <= index < count, use swap)
  public: void exchangeObjectAtIndexes (const int32_t inIndex1,
                                         const int32_t inIndex2
                                         COMMA_LOCATION_ARGS) ;

//--- Remove objects at index (0 <= index < count)
  public: void removeObjectAtIndex (const int32_t inIndex
                                     COMMA_LOCATION_ARGS) ;
  public: void removeObjectsAtIndex (const int32_t inCount,
                                      const int32_t inStartingIndex
                                      COMMA_LOCATION_ARGS) ;

//--- Remove objects from an other array (uses == operator for selecting objects to remove)
  public: void removeObjectsFromArray (const TC_UniqueArray <TYPE> & inArray) ; // Remaining objects are copied
  public: void removeObjectsFromArrayUsingSwapAndClear (const TC_UniqueArray <TYPE> & inArray) ; // Remaining objects are copied

//--- Remove identical objects (based on == operator)
  public: void removeIdenticalObjects (void) ;
  public: void removeIdenticalObjectsUsingSwapAndClear (void) ;

//--- Contains an objects equal to method actual argument value (based on == operator)
  public: bool containsObjectEqualTo (const TYPE & inObject) const ;

//--- Count objects equal to method actual argument value (based on == operator)
  public: int32_t countObjectsEqualTo (const TYPE & inObject) const ;

//--- Count objects that respond true to function
  public: int32_t countObjectsThatRespondsTrueToFunction (bool (inFunction) (const TYPE & inObject)) const ;

//--- Get a sub array: selection is done using a function. result array contains
//    objects for which inFunction returns true.
//    If inFunction is nullptr, result array is empty.
  public: void subArrayUsingFunction (bool (* inFunction) (const TYPE & inObject),
                                       TC_UniqueArray <TYPE> & outResult) const ;

//--- Sort and reverse sort array with <= and >= operators
//    these operators must be defined for TYPE class
  public: void sortArrayUsingComparisonOperators (void) ;
  public: void reverseSortArrayUsingComparisonOperators (void) ;

//--- Sort and reverse sort array with compare method of TYPE class
//  inOperand1.compare (inOperand2) < 0 means inOperand1 < inOperand2
  public: void sortArrayUsingCompareMethod (void) ;
  public: void reverseSortArrayUsingCompareMethod (void) ;

//--- Sort array with a sort function (does nothing if inSortFunction == nullptr)
//  inSortFunction (inOperand1, inOperand2) < 0 means inOperand1 < inOperand2
  public: void sortArrayUsingFunction (int32_t (* inSortFunction) (const TYPE & inOperand1, const TYPE & inOperand2)) ;

//--- Sort array with a sort function (does nothing if inSortFunction == nullptr)
//  inSortFunction (inOperand1, inOperand2) < 0 means inOperand1 < inOperand2
  public: void reverseSortArrayUsingFunction (int32_t (* inSortFunction) (const TYPE & inOperand1, const TYPE & inOperand2)) ;

//--- Element access (with index checking)
  public: TYPE lastObject (LOCATION_ARGS) const ;
  public: TYPE & lastObject (LOCATION_ARGS) ;

  public: void setObjectAtIndex (const TYPE & inObject,
                                  const int32_t inIndex
                                  COMMA_LOCATION_ARGS) ;

  public: TYPE & operator () (const int32_t inIndex COMMA_LOCATION_ARGS) ;

  public: TYPE & operator () (const int32_t inIndex COMMA_LOCATION_ARGS) const ;

//--- Private methods
  private: void internalSortArrayUsingOperators (const int32_t inFirst,
                                                  const int32_t inLast) ;

  private: void internalReverseSortArrayUsingOperators (const int32_t inFirst,
                                                         const int32_t inLast) ;

  private: void internalSortArrayUsingCompareMethod (const int32_t inFirst,
                                                      const int32_t inLast) ;

  private: void internalReverseSortArrayUsingCompareMethod (const int32_t inFirst,
                                                             const int32_t inLast) ;

  private: void internalSortArrayUsingFunction (const int32_t inFirst,
                                                 const int32_t inLast,
                                                 int32_t (* inSortFunction) (const TYPE & inOperand1,
                                                                              const TYPE & inOperand2)) ;

  private: void internalReverseSortArrayUsingFunction (const int32_t inFirst,
                                                        const int32_t inLast,
                                                        int32_t (* inSortFunction) (const TYPE & inOperand1,
                                                                                     const TYPE & inOperand2)) ;
//--- Index checking
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected: void checkIndex (const int32_t inIndex COMMA_LOCATION_ARGS) const ;
    protected: void checkIndexForInsertion (const int32_t inIndex COMMA_LOCATION_ARGS) const ;
  #endif

//--- Protected attributes
  protected: TYPE * mArray ;
  protected: int32_t mCount ;
  protected: int32_t mCapacity ;

//--- Array Pointer
  public: const TYPE * unsafeArrayPointer (void) const ;

//--- swap
  friend void swap <TYPE> (TC_UniqueArray <TYPE> & ioOperand1,
                           TC_UniqueArray <TYPE> & ioOperand2) ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//   Default Constructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_UniqueArray <TYPE>::TC_UniqueArray (void) :
mArray ((TYPE *) nullptr),
mCount (0),
mCapacity (0) {
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Allocation Constructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_UniqueArray <TYPE>::TC_UniqueArray (const int32_t inCapacity COMMA_LOCATION_ARGS) :
mArray (nullptr),
mCount (0),
mCapacity (0) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    MF_AssertThere (inCapacity >= 0, "inCapacity (%ld) < 0", inCapacity, 0) ;
  #endif
  if (inCapacity > 0) {
    macroMyNewArray (mArray, TYPE, uint32_t (inCapacity)) ;
    mCapacity = inCapacity ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Allocation Constructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_UniqueArray <TYPE>::TC_UniqueArray (const int32_t inCapacity,
                                                                const TYPE & inValue
                                                                COMMA_LOCATION_ARGS) :
mArray (nullptr),
mCount (0),
mCapacity (0) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    MF_AssertThere (inCapacity >= 0, "inCapacity (%ld) < 0", inCapacity, 0) ;
  #endif
  if (inCapacity > 0) {
    macroMyNewArray (mArray, TYPE, uint32_t (inCapacity)) ;
    mCapacity = inCapacity ;
    for (int32_t i=0 ; i<inCapacity ; i++) {
      mArray [i] = inValue ;
    }
    mCount = inCapacity ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Allocation Constructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::setDataFromPointer (TYPE * & ioDataPtr,
                                                                         const int32_t inDataLength) {
  macroMyDeleteArray (mArray) ;
  mArray = ioDataPtr ;
  mCount = inDataLength ;
  mCapacity = inDataLength ;
  ioDataPtr = nullptr ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::appendDataFromPointer (const TYPE * inDataPtr,
                                                                            const int32_t inDataLength) {
  for (int32_t i=0 ; i<inDataLength ; i++) {
    appendObject (inDataPtr [i]) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Destructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_UniqueArray <TYPE>::~TC_UniqueArray (void) {
  macroMyDeleteArray (mArray) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Destructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::setCountToZero (void) {
  mCount = 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Method for making room using copy
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::copyTo (TC_UniqueArray <TYPE> & outArray) const {
  outArray.setCountToZero () ;
  for (int32_t i=0 ; i<mCount ; i++) {
    outArray.appendObject (mArray [i]) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Method for making room using copy
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::setCapacity (const int32_t inNewCapacity) {
  if (mCapacity < inNewCapacity) {
    int32_t newCapacity = (mCapacity > 32) ? mCapacity : 32 ;
    while (newCapacity < inNewCapacity) {
      newCapacity <<= 1 ;
    }
    TYPE * newArray = nullptr ;
    macroMyNewArray (newArray, TYPE, uint32_t (newCapacity)) ;
    for (int32_t i=0 ; i<mCount ; i++) {
      newArray [i] = mArray [i] ;
    }
    macroMyDeleteArray (mArray) ; mArray = newArray ;
    mCapacity = newCapacity ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Method for making room using copy
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::forceObjectAtIndex (const int32_t inIndex,
                                                                         const TYPE & inValue,
                                                                         const TYPE & inDefaultValue
                                                                         COMMA_LOCATION_ARGS) {
  if (mCapacity <= inIndex) {
    int32_t newCapacity = (mCapacity > 32) ? mCapacity : 32 ;
    while (newCapacity <= inIndex) {
      newCapacity <<= 1 ;
    }
    TYPE * newArray = nullptr ;
    macroMyNewArrayThere (newArray, TYPE, uint32_t (newCapacity)) ;
    for (int32_t i=0 ; i<mCount ; i++) {
      newArray [i] = mArray [i] ;
    }
    macroMyDeleteArray (mArray) ; mArray = newArray ;
    mCapacity = newCapacity ;
  }
  if (mCount <= inIndex) {
    for (int32_t i=mCount ; i<inIndex ; i++) {
      mArray [i] = inDefaultValue ;
    }
    mCount = inIndex + 1 ;
  }
  mArray [inIndex] = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Method for setting capacity using swap function
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::setCapacityUsingSwap (const int32_t inNewCapacity) {
  if (mCapacity < inNewCapacity) {
    int32_t newCapacity = (mCapacity > 32) ? mCapacity : 32 ;
    while (newCapacity < inNewCapacity) {
      newCapacity <<= 1 ;
    }
    TYPE * newArray = nullptr ;
    macroMyNewArray (newArray, TYPE, uint32_t (newCapacity)) ;
    for (int32_t i=0 ; i<mCount ; i++) {
      swap (newArray [i], mArray [i]) ;
    }
    macroMyDeleteArray (mArray) ; mArray = newArray ;
    mCapacity = newCapacity ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove all objects and deallocate
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::free (void) {
  mCount = 0 ;
  macroMyDeleteArray (mArray) ;
  mCapacity = 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Add object at the end of the array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::appendObject (const TYPE & inValue) {
  if (mCount >= mCapacity) {
    setCapacity (mCount + 1 + mCount / 2) ;
  }
  mArray [mCount] = inValue ;
  mCount ++ ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Add object at the end of the array, if object is not already in array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::appendObjectIfUnique (const TYPE & inValue) {
  bool found = false ;
  for (int32_t i=0 ; (i<mCount) && ! found ; i++) {
    found = mArray [i] == inValue ;
  }
  if (! found) {
    setCapacity (mCount + 1 + mCount / 2) ;
    mArray [mCount] = inValue ;
    mCount ++ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Add objects at the end of the array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::appendObjects (const int32_t inCount, const TYPE & inValue) {
  if (inCount > 0) {
    const int32_t newCount = mCount + inCount ;
    setCapacity (newCount) ;
    for (int32_t i=mCount ; i<newCount ; i++) {
      mArray [i] = inValue ;
    }
    mCount = newCount ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Add object at the end of the array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::appendObjectUsingSwap (TYPE & ioValue) {
  setCapacityUsingSwap (mCount + 1) ;
  swap (mArray [mCount], ioValue) ;
  mCount ++ ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Add default object at the end of the array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::appendDefaultObjectUsingSwap (void) {
  setCapacityUsingSwap (mCount + 1) ;
  TYPE value ;
  swap (mArray [mCount], value) ;
  mCount ++ ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Add objects at the end of the array from an other array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::appendObjectsFromArray (const TC_UniqueArray <TYPE> &  inObjectArray) {
  if (inObjectArray.mCount > 0) {
    setCapacity (mCount + inObjectArray.mCount) ;
    for (int32_t i=0 ; i<inObjectArray.mCount ; i++) {
      mArray [mCount + i] = inObjectArray.mArray [i] ;
    }
    mCount += inObjectArray.mCount ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Check index before insertion
//
//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  template <typename TYPE> void TC_UniqueArray <TYPE>::checkIndexForInsertion (const int32_t inIndex COMMA_LOCATION_ARGS) const {
    MF_AssertThere (inIndex >= 0, "inIndex (%ld) < 0", inIndex, 0) ;
    MF_AssertThere (inIndex <= mCount, "inIndex (%d) > mCount (%ld)", inIndex, mCount) ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//   Insert object at index
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::insertObjectAtIndex (const TYPE & inValue,
                                                                          const int32_t inIndex
                                                                          COMMA_LOCATION_ARGS) { // inValue is copied
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndexForInsertion (inIndex COMMA_THERE) ;
  #endif
  setCapacity (mCount + 1) ;
  for (int32_t i=mCount ; i>inIndex ; i--) {
    mArray [i] = mArray [i-1] ;
  }
  mArray [inIndex] = inValue ;
  mCount ++ ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Insert objects at index
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::insertObjectsAtIndex (const int32_t inCount,
                                                                           const TYPE & inValue,
                                                                           const int32_t inStartingIndex
                                                                           COMMA_LOCATION_ARGS) { // inValue is copied
  if (inCount > 0) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkIndexForInsertion (inStartingIndex COMMA_THERE) ;
    #endif
    setCapacity (mCount + inCount) ;
    for (int32_t i=mCount+inCount-1 ; i>=(inStartingIndex + inCount) ; i--) {
      mArray [i] = mArray [i-inCount] ;
    }
    for (int32_t i=0 ; i<inCount ; i++) {
      mArray [inStartingIndex+i] = inValue ;
    }
    mCount += inCount ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Insert objects at index using swap
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::
insertObjectUsingSwap (TYPE & ioValue, const int32_t inIndex COMMA_LOCATION_ARGS) { // inValue is copied
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndexForInsertion (inIndex COMMA_THERE) ;
  #endif
  setCapacity (mCount + 1) ;
  for (int32_t i=mCount ; i>inIndex ; i--) {
    swap (mArray [i], mArray [i-1]) ;
  }
  swap (mArray [inIndex], ioValue) ;
  mCount ++ ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Insert objects at index using default constructor
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::
insertObjectsUsingExchangeAndClear (const int32_t inCount,
                                    const int32_t inStartingIndex COMMA_LOCATION_ARGS) { // inValue is copied
  if (inCount > 0) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkIndexForInsertion (inStartingIndex COMMA_THERE) ;
    #endif
    setCapacity (mCount + inCount) ;
    for (int32_t i=mCount+inCount-1 ; i>=(inStartingIndex + inCount) ; i--) {
      swap (mArray [i], mArray [i-inCount]) ;
    }
    for (int32_t i=0 ; i<inCount ; i++) {
      mArray [i+inStartingIndex].clear () ;
    }
    mCount += inCount ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   remove last object
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::removeLastObject (LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndex (mCount-1 COMMA_THERE) ;
  #endif
  mCount -- ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   remove last objects
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::removeLastObjects (const int32_t inCount COMMA_LOCATION_ARGS) {
  if (inCount > 0) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkIndex (mCount-inCount COMMA_THERE) ;
    #endif
    mCount -= inCount ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   remove object at index (0 <= index < count)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::exchangeObjectAtIndexes (const int32_t inIndex1,
                                                                              const int32_t inIndex2
                                                                              COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndex (inIndex1 COMMA_THERE) ;
    checkIndex (inIndex2 COMMA_THERE) ;
  #endif
  if (inIndex1 != inIndex2) {
    swap (mArray [inIndex1],  mArray [inIndex2]) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   remove object at index (0 <= index < count)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::removeObjectAtIndex (const int32_t inIndex COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndex (inIndex COMMA_THERE) ;
  #endif
  for (int32_t i=inIndex+1 ; i< mCount ; i++) {
    mArray [i-1] = mArray [i] ;
  }
  mCount -- ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   delete objects from index (0<=index<mCount), ((index+inCount)<=mCount)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::
removeObjectsAtIndex (const int32_t inCount, const int32_t inStartingIndex COMMA_LOCATION_ARGS) {
  if (inCount > 0) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkIndex (inStartingIndex COMMA_THERE) ;
      checkIndexForInsertion (inStartingIndex+inCount COMMA_THERE) ;
    #endif
    for (int32_t i=inStartingIndex+inCount ; i<mCount ; i++) {
      mArray [i-inCount] = mArray [i] ;
    }
    mCount -= inCount ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Search Objects
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> int32_t TC_UniqueArray <TYPE>::indexOfFirstObjectEqualTo (const TYPE & inValue) const {
  int32_t result = -1 ;
  for (int32_t i=0 ; (i<mCount) && (result < 0) ; i++) {
    if (mArray [i] == inValue) {
      result = i ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Array Access
//
//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  template <typename TYPE> void TC_UniqueArray <TYPE>::checkIndex (const int32_t inIndex COMMA_LOCATION_ARGS) const {
    MF_AssertThere (inIndex >= 0, "inIndex (%lld) < 0", inIndex, 0) ;
    MF_AssertThere (inIndex < mCount, "inIndex (%lld) >= mCount (%lld)", inIndex, mCount) ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::setObjectAtIndex (const TYPE & inObject,
                                                                       const int32_t inIndex
                                                                       COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndex (inIndex COMMA_THERE) ;
  #endif
  if (nullptr != mArray) {
    mArray [inIndex] = inObject ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::incrementAtIndex (const int32_t inIndex
                                                                       COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndex (inIndex COMMA_THERE) ;
  #endif
  mArray [inIndex] ++ ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::decrementAtIndex (const int32_t inIndex
                                                                       COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndex (inIndex COMMA_THERE) ;
  #endif
  mArray [inIndex] -- ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TYPE & TC_UniqueArray <TYPE>::operator () (const int32_t inIndex COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndex (inIndex COMMA_THERE) ;
  #endif
  return mArray [inIndex] ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TYPE & TC_UniqueArray <TYPE>::
operator () (const int32_t inIndex COMMA_LOCATION_ARGS) const {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndex (inIndex COMMA_THERE) ;
  #endif
  return mArray [inIndex] ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TYPE TC_UniqueArray <TYPE>::lastObject (LOCATION_ARGS) const {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndex (mCount-1 COMMA_THERE) ;
  #endif
  return mArray [mCount-1] ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TYPE & TC_UniqueArray <TYPE>::lastObject (LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkIndex (mCount-1 COMMA_THERE) ;
  #endif
  return mArray [mCount-1] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Extract sub array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::
subArrayUsingFunction (bool (* inFunction) (const TYPE & inObject),
                       TC_UniqueArray <TYPE> & outResult) const {
  outResult.clear () ;
  if (inFunction != nullptr) {
    outResult.setCapacity (mCount) ;
    for (int32_t i=0 ; i<mCount ; i++) {
      if (inFunction (mArray [i])) {
        outResult.appendObject (mArray [i]) ;
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Sort array using >= and <= operators
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray<TYPE>::internalSortArrayUsingOperators (const int32_t inFirst,
                                                                                     const int32_t inLast) {
//--- Sort using 'quick sort' algorithm
  if (inFirst < inLast) {
    int32_t i = inFirst ;
    int32_t j = inLast ;
    while (i < j) {
      while ((i < inLast) && (mArray [i] <= mArray [inFirst])) {
        i ++ ;
      }
      while ((j > inFirst) && (mArray [j] >= mArray [inFirst])) {
        j -- ;
      }
      if (i < j) {
        swap (mArray [i], mArray [j]) ;
      }
    }
    swap (mArray [j], mArray [inFirst]) ;
    internalSortArrayUsingOperators (inFirst, j-1) ;
    internalSortArrayUsingOperators (j+1, inLast) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray<TYPE>::sortArrayUsingComparisonOperators (void) {
  internalSortArrayUsingOperators (0, mCount - 1) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Reverse sort array using >= and <= operators
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray<TYPE>::internalReverseSortArrayUsingOperators (const int32_t inFirst,
                                                                                            const int32_t inLast) {
//--- Reverse sort using 'quick sort' algorithm
  if (inFirst < inLast) {
    int32_t i = inFirst ;
    int32_t j = inLast ;
    while (i < j) {
      while ((i < inLast) && (mArray [i] >= mArray [inFirst])) {
        i ++ ;
      }
      while ((j > inFirst) && (mArray [j] <= mArray [inFirst])) {
        j -- ;
      }
      if (i < j) {
        swap (mArray [i], mArray [j]) ;
      }
    }
    swap (mArray [j], mArray [inFirst]) ;
    internalReverseSortArrayUsingOperators (inFirst, j-1) ;
    internalReverseSortArrayUsingOperators (j+1, inLast) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray<TYPE>::reverseSortArrayUsingComparisonOperators (void) {
  internalReverseSortArrayUsingOperators (0, mCount - 1) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Sort array using comare method
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>void TC_UniqueArray<TYPE>::internalSortArrayUsingCompareMethod (const int32_t inFirst,
                                                                                        const int32_t inLast) {
//--- Sort using 'quick sort' algorithm
  if (inFirst < inLast) {
    int32_t i = inFirst ;
    int32_t j = inLast ;
    while (i < j) {
      while ((i < inLast) && (mArray [i].compare (mArray [inFirst]) <= 0)) {
        i ++ ;
      }
      while ((j > inFirst) && (mArray [j].compare (mArray [inFirst]) >= 0)) {
        j -- ;
      }
      if (i < j) {
        swap (mArray [i], mArray [j]) ;
      }
    }
    swap (mArray [j], mArray [inFirst]) ;
    internalSortArrayUsingCompareMethod (inFirst, j-1) ;
    internalSortArrayUsingCompareMethod (j+1, inLast) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray<TYPE>::sortArrayUsingCompareMethod (void) {
  internalSortArrayUsingCompareMethod (0, mCount - 1) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Reverse sort array using compare method
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray<TYPE>::
internalReverseSortArrayUsingCompareMethod (const int32_t inFirst,
                                            const int32_t inLast) {
//--- Reverse sort using 'quick sort' algorithm
  if (inFirst < inLast) {
    int32_t i = inFirst ;
    int32_t j = inLast ;
    while (i < j) {
      while ((i < inLast) && (mArray [i].compare (mArray [inFirst]) >= 0)) {
        i ++ ;
      }
      while ((j > inFirst) && (mArray [j].compare (mArray [inFirst]) <= 0)) {
        j -- ;
      }
      if (i < j) {
        swap (mArray [i], mArray [j]) ;
      }
    }
    swap (mArray [j], mArray [inFirst]) ;
    internalReverseSortArrayUsingCompareMethod (inFirst, j-1) ;
    internalReverseSortArrayUsingCompareMethod (j+1, inLast) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray<TYPE>::reverseSortArrayUsingCompareMethod (void) {
  internalReverseSortArrayUsingCompareMethod (0, mCount - 1) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Sort array using comparison function
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray<TYPE>::
internalSortArrayUsingFunction (const int32_t inFirst,
                                const int32_t inLast,
                                int32_t (* inSortFunction) (const TYPE & inOperand1, const TYPE & inOperand2)) {
//--- Sort using 'quick sort' algorithm
  if (inFirst < inLast) {
    int32_t i = inFirst ;
    int32_t j = inLast ;
    while (i < j) {
      while ((i < inLast) && (inSortFunction (mArray [i], mArray [inFirst]) <= 0)) {
        i ++ ;
      }
      while ((j > inFirst) && (inSortFunction (mArray [j], mArray [inFirst]) >= 0)) {
        j -- ;
      }
      if (i < j) {
        swap (mArray [i], mArray [j]) ;
      }
    }
    swap (mArray [j], mArray [inFirst]) ;
    internalSortArrayUsingFunction (inFirst, j-1, inSortFunction) ;
    internalSortArrayUsingFunction (j+1, inLast, inSortFunction) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray<TYPE>::
sortArrayUsingFunction (int32_t (* inSortFunction) (const TYPE & inOperand1, const TYPE & inOperand2)) {
  if (inSortFunction != nullptr) {
    internalSortArrayUsingFunction (0, mCount - 1, inSortFunction) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Reverse sort array using comparison function
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray<TYPE>::
internalReverseSortArrayUsingFunction (const int32_t inFirst,
                                       const int32_t inLast,
                                       int32_t (* inSortFunction) (const TYPE & inOperand1, const TYPE & inOperand2)) {
//--- Reverse sort using 'quick sort' algorithm
  if (inFirst < inLast) {
    int32_t i = inFirst ;
    int32_t j = inLast ;
    while (i < j) {
      while ((i < inLast) && (inSortFunction (mArray [i], mArray [inFirst]) >= 0)) {
        i ++ ;
      }
      while ((j > inFirst) && (inSortFunction (mArray [j], mArray [inFirst]) <= 0)) {
        j -- ;
      }
      if (i < j) {
        swap (mArray [i], mArray [j]) ;
      }
    }
    swap (mArray [j], mArray [inFirst]) ;
    internalReverseSortArrayUsingFunction (inFirst, j-1, inSortFunction) ;
    internalReverseSortArrayUsingFunction (j+1, inLast, inSortFunction) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::
reverseSortArrayUsingFunction (int32_t (* inSortFunction) (const TYPE & inOperand1, const TYPE & inOperand2)) {
  if (inSortFunction != nullptr) {
    internalReverseSortArrayUsingFunction (0, mCount - 1, inSortFunction) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Comparisons (based on == operator on objects)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> bool TC_UniqueArray<TYPE>::operator == (const TC_UniqueArray <TYPE> & inOperand) const {
  bool areEqual = mCount == inOperand.mCount ;
  for (int32_t i=0 ; (i<mCount) && areEqual ; i++) {
    areEqual = mArray [i] == inOperand.mArray [i] ;
  }
  return areEqual ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove from an other array (using assignment operator)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::removeObjectsFromArray (const TC_UniqueArray <TYPE> & inArray) {
  int32_t sourceIndex = 0 ;
  int32_t targetIndex = 0 ;
  while (sourceIndex < mCount) {
  //--- Serach for element
    bool found = false ;
    for (int32_t i=0 ; (i<inArray.count ()) && ! found ; i++) {
      found = inArray (i COMMA_HERE) == mArray [sourceIndex] ;
    }
    if (found) {
      sourceIndex ++ ;
    }else if (sourceIndex != targetIndex) {
      mArray [targetIndex] = mArray [sourceIndex] ;
      sourceIndex ++ ;
      targetIndex ++ ;
    }else{
      sourceIndex ++ ;
      targetIndex ++ ;
    }
  }
  mCount = targetIndex ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove from an other array (using swap function)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::
removeObjectsFromArrayUsingSwapAndClear (const TC_UniqueArray <TYPE> & inArray) {
  int32_t sourceIndex = 0 ;
  int32_t targetIndex = 0 ;
  while (sourceIndex < mCount) {
  //--- Serach for element
    bool found = false ;
    for (int32_t i=0 ; (i<inArray.count ()) && ! found ; i++) {
      found = inArray (i COMMA_HERE) == mArray [sourceIndex] ;
    }
    if (found) {
      sourceIndex ++ ;
    }else if (sourceIndex != targetIndex) {
      swap (mArray [targetIndex], mArray [sourceIndex]) ;
      sourceIndex ++ ;
      targetIndex ++ ;
    }else{
      sourceIndex ++ ;
      targetIndex ++ ;
    }
  }
  for (int32_t i=targetIndex ; i<sourceIndex ; i++) {
    mArray [i].clear () ;
  }
  mCount = targetIndex ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove identical objects (based on == operator)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::removeIdenticalObjects (void) {
  int32_t sourceIndex = 1 ;
  int32_t targetIndex = 1 ;
  while (sourceIndex < mCount) {
    bool found = false ;
    for (int32_t i=0 ; (i<targetIndex) && ! found ; i++) {
      found = mArray [sourceIndex] == mArray [i] ;
    }
    if (found) {
      sourceIndex ++ ;
    }else if (sourceIndex != targetIndex) {
      mArray [targetIndex] = mArray [sourceIndex] ;
      sourceIndex ++ ;
      targetIndex ++ ;
    }else{
      sourceIndex ++ ;
      targetIndex ++ ;
    }
  }
  mCount -= sourceIndex - targetIndex ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove identical objects (based on == operator)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::removeIdenticalObjectsUsingSwapAndClear (void) {
  int32_t sourceIndex = 1 ;
  int32_t targetIndex = 1 ;
  while (sourceIndex < mCount) {
    bool found = false ;
    for (int32_t i=0 ; (i<targetIndex) && ! found ; i++) {
      found = mArray [sourceIndex] == mArray [i] ;
    }
    if (found) {
      sourceIndex ++ ;
    }else if (sourceIndex != targetIndex) {
      swap (mArray [targetIndex], mArray [sourceIndex]) ;
      sourceIndex ++ ;
      targetIndex ++ ;
    }else{
      sourceIndex ++ ;
      targetIndex ++ ;
    }
  }
  for (int32_t i=targetIndex ; i<sourceIndex ; i++) {
    mArray [i].clear () ;
  }
  mCount -= sourceIndex - targetIndex ;
}

//----------------------------------------------------------------------------------------------------------------------
//
// Has objects equal to method actual argument value (based on == operator)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> bool TC_UniqueArray <TYPE>::containsObjectEqualTo (const TYPE & inObject) const {
  bool hasObject = false ;
  for (int32_t i=0 ; (i<mCount) && ! hasObject ; i++) {
    hasObject += mArray [i] == inObject ;
  }
  return hasObject ;
}

//----------------------------------------------------------------------------------------------------------------------
//
// Count objects equal to method actual argument value (based on == operator)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> int32_t TC_UniqueArray <TYPE>::countObjectsEqualTo (const TYPE & inObject) const {
  int32_t  matchCount = 0 ;
  for (int32_t i=0 ; i<mCount ; i++) {
    matchCount += mArray [i] == inObject ;
  }
  return matchCount ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//        Count objects that respond true to function
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> int32_t TC_UniqueArray <TYPE>::
countObjectsThatRespondsTrueToFunction (bool (inFunction) (const TYPE & inObject)) const {
  int32_t matchCount = 0 ;
  if (inFunction != nullptr) {
    for (int32_t i=0 ; i<mCount ; i++) {
      matchCount += inFunction (mArray [i]) ;
    }
  }
  return matchCount ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Intersection with an other array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::
intersectionWithArray (const TC_UniqueArray <TYPE> & inOperand,
                       TC_UniqueArray <TYPE> & outResult) const {
//--- Empty destination array
  outResult.clear () ;
  outResult.setCapacity (mCount) ;
//--- loop throught array
  for (int32_t i=0 ; i<mCount ; i++) {
    bool accept = true ;
    for (int32_t j=0 ; j<i; j++) {
      accept = ! (mArray [j] == mArray [i]) ;
    }
    if (accept) {
      bool found = false ;
      for (int32_t j=0 ; (j<inOperand.count ()) && ! found ; j++) {
        found = inOperand.mArray [j] == mArray [i] ;
      }
      if (found) {
        outResult.appendObject (mArray [i]) ;
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Multi Set Intersection with an other array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>void TC_UniqueArray <TYPE>::
multiSetIntersectionWithArray (const TC_UniqueArray <TYPE> & inOperand,
                               TC_UniqueArray <TYPE> & outResult) const {
//--- Empty destination array
  outResult.clear () ;
  outResult.setCapacity (mCount) ;
//--- Build counted set for current object
  TC_UniqueArray <TYPE> set (mCount COMMA_HERE) ;
  TC_UniqueArray <int32_t> setCount (mCount COMMA_HERE) ;
  for (int32_t i=0 ; i<mCount ; i++) {
    bool found = false ;
    for (int32_t j=0 ; (j<set.count ()) && ! found ; j++) {
      found = set.mArray [j] == mArray [i] ;
      if (found) {
        setCount.mArray [j] ++ ;
      }
    }
    if (! found) {
      set.appendObject (mArray [i]) ;
      setCount.appendObject (1) ;
    }
  }
//--- loop throught counted set
  for (int32_t i=0 ; i<set.mCount ; i++) {
    int32_t countInOperand = 0 ;
    for (int32_t j=0 ; j<inOperand.mCount; j++) {
      countInOperand += inOperand.mArray [j] == set.mArray [i] ;
    }
    const int32_t resultCount = countInOperand < setCount.mArray [i] ? countInOperand : setCount.mArray [i] ;
    for (int32_t j=0 ; j<resultCount ; j++) {
      outResult.appendObject (set.mArray [i]) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Union with an other array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::unionWithArray (const TC_UniqueArray <TYPE> & inOperand,
                                                                     TC_UniqueArray <TYPE> & outResult) const {
//--- Empty destination array
  outResult.clear () ;
  outResult.setCapacity (mCount + inOperand.mCount) ;
//--- Copy current object
  for (int32_t i=0 ; i<mCount ; i++) {
    outResult.appendObject (mArray [i]) ;
  }
//--- Remove duplicates
  outResult.removeIdenticalObjects () ;
//--- Add objects from operand array
  for (int32_t i=0 ; i<inOperand.mCount ; i++) {
    bool found = false ;
    for (int32_t j=0 ; (j<outResult.count ()) && ! found ; j++) {
      found = outResult.mArray [j] == inOperand.mArray [i] ;
    }
    if (! found) {
      outResult.appendObject (inOperand.mArray [i]) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Union with an other array
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> const TYPE * TC_UniqueArray <TYPE>::unsafeArrayPointer (void) const {
  return mArray ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   swap function for TC_UniqueArray <TYPE> classes
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void swap (TC_UniqueArray <TYPE> & ioOperand1,
           TC_UniqueArray <TYPE> & ioOperand2) {
  swap (ioOperand1.mCount, ioOperand2.mCount) ;
  swap (ioOperand1.mCapacity, ioOperand2.mCapacity) ;
  swap (ioOperand1.mArray, ioOperand2.mArray) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Add object in array, maintaining array sorted
//
//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  template <typename TYPE> void TC_UniqueArray <TYPE>::checkOrdered (LOCATION_ARGS) const {
    for (int32_t i=1 ; i<count () ; i++) {
      const int32_t r = mArray [i - 1].compare (mArray [i]) ;
      MF_AssertThere (r < 0, "Ordered Array Error for index %lld", i, 0) ;
    }
  }
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//   Add object in array, maintaining array sorted
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::appendUniqueObjectInOrderedArray (const TYPE & inKey) {
//--- Search
  bool found = false ;
  int32_t low = 0 ;
  int32_t high = mCount - 1 ;
  int32_t idx = 0 ;
  int32_t r = 0 ;
  while ((low <= high) && ! found) {
    idx = (low + high) / 2 ;
    r = mArray [idx].compare (inKey) ;
    if (r < 0) {
      low = idx + 1 ;
    }else if (r > 0) {
      high = idx - 1 ;
    }else{
      found = true ;
    }
  }
//--- Insert in not found
  if (! found) {
    setCapacity (mCount + 1) ;
    idx += r < 0 ;
    for (int32_t i=mCount ; i>idx ; i--) {
      mArray [i] = mArray [i - 1] ;
    }
    mArray [idx] = inKey ;
    mCount ++ ;
  }
//--- Check array is ordered
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkOrdered (HERE) ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------
//
//   indexOfObjectInOrderedArray
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> int32_t TC_UniqueArray <TYPE>::indexOfObjectInOrderedArray (const TYPE & inValue) const {
//--- Search
  bool found = false ;
  int32_t low = 0 ;
  int32_t high = mCount - 1 ;
  int32_t idx = 0 ;
  int32_t r = 0 ;
  while ((low <= high) && ! found) {
    idx = (low + high) / 2 ;
    r = mArray [idx].compare (inValue) ;
    if (r < 0) {
      low = idx + 1 ;
    }else if (r > 0) {
      high = idx - 1 ;
    }else{
      found = true ;
    }
  }
  return found ? idx : -1 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   intersectionOfOrderedArraies
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void TC_UniqueArray <TYPE>::intersectionOfOrderedArraies (const TC_UniqueArray<TYPE> & inOperand,
                                                          TC_UniqueArray<TYPE> & outResult) const {
  outResult.setCountToZero () ;
  int32_t leftIdx = 0 ;
  int32_t rightIdx = 0 ;
  while ((leftIdx < count ()) && (rightIdx < inOperand.count ())) {
    const int32_t r = (*this) (leftIdx COMMA_HERE).compare (inOperand (rightIdx COMMA_HERE)) ;
    if (r < 0) {
      leftIdx ++ ;
    }else if (r > 0) {
      rightIdx ++ ;
    }else{
      outResult.appendObject (inOperand (rightIdx COMMA_HERE)) ;
      leftIdx ++ ;
      rightIdx ++ ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    outResult.checkOrdered (HERE) ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------
//
//   unionOfOrderedArraies
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void TC_UniqueArray <TYPE>::unionOfOrderedArraies (const TC_UniqueArray<TYPE> & inOperand,
                                                   TC_UniqueArray<TYPE> & outResult) const {
  outResult.setCountToZero () ;
  int32_t leftIdx = 0 ;
  int32_t rightIdx = 0 ;
  while ((leftIdx < count ()) && (rightIdx < inOperand.count ())) {
    const int32_t r = (*this) (leftIdx COMMA_HERE).compare (inOperand (rightIdx COMMA_HERE)) ;
    if (r < 0) {
      outResult.appendObject ((*this) (leftIdx COMMA_HERE)) ;
      leftIdx ++ ;
    }else if (r > 0) {
      outResult.appendObject (inOperand (rightIdx COMMA_HERE)) ;
      rightIdx ++ ;
    }else{
      outResult.appendObject (inOperand (rightIdx COMMA_HERE)) ;
      leftIdx ++ ;
      rightIdx ++ ;
    }
  }
  while (leftIdx < count ()) {
    outResult.appendObject ((*this) (leftIdx COMMA_HERE)) ;
    leftIdx ++ ;
  }
  while (rightIdx < inOperand.count ()) {
    outResult.appendObject (inOperand (rightIdx COMMA_HERE)) ;
    rightIdx ++ ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    outResult.checkOrdered (HERE) ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------
//
//   substractOfOrderedArraies
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void TC_UniqueArray <TYPE>::substractOfOrderedArraies (const TC_UniqueArray<TYPE> & inSubstractedSet,
                                                       TC_UniqueArray<TYPE> & outResult) const {
  outResult.setCountToZero () ;
  int32_t leftIdx = 0 ;
  int32_t rightIdx = 0 ;
  while ((leftIdx < count ()) && (rightIdx < inSubstractedSet.count ())) {
    const int32_t r = (*this) (leftIdx COMMA_HERE).compare (inSubstractedSet (rightIdx COMMA_HERE)) ;
    if (r < 0) {
      outResult.appendObject ((*this) (leftIdx COMMA_HERE)) ;
      leftIdx ++ ;
    }else if (r > 0) {
      rightIdx ++ ;
    }else{
      leftIdx ++ ;
      rightIdx ++ ;
    }
  }
  while (leftIdx < count ()) {
    outResult.appendObject ((*this) (leftIdx COMMA_HERE)) ;
    leftIdx ++ ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    outResult.checkOrdered (HERE) ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove object in ordered array (based on < and > operators)
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_UniqueArray <TYPE>::removeObjectFromOrderedArray (const TYPE & inKey) {
  bool found = false ;
  int32_t low = 0 ;
  int32_t high = mCount - 1 ;
  while ((low <= high) && !found) {
    const int32_t mid = (low + high) / 2 ;
    const TYPE x = mArray [mid] ;
    const int32_t r = x.compare (inKey) ;
    if (r < 0) {
      low = mid + 1 ;
    }else if (r > 0) {
      high = mid - 1 ;
    }else{
      found = true ;
      removeObjectAtIndex (mid COMMA_HERE) ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkOrdered (HERE) ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------
