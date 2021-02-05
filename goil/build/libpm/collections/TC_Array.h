//----------------------------------------------------------------------------------------------------------------------
//
//   G E N E R I C     A R R A Y                                                                 
//
//  This file is part of libpm library                                                           
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
#include "collections/TC_UniqueArray.h"

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

template <typename TYPE> class cSharedArray : public C_SharedObject, public TC_UniqueArray<TYPE> {
//--- Default Constructor
  public : cSharedArray (void) :
  C_SharedObject (HERE),
  TC_UniqueArray<TYPE> () {
  }
  
//--- Destructor
  public : virtual ~ cSharedArray (void) {
  }
  
//--- Allocation Constructor (empty array)
  public : cSharedArray (const int inCapacity COMMA_LOCATION_ARGS) :
  C_SharedObject (THERE),
  TC_UniqueArray<TYPE> (inCapacity COMMA_THERE) {
  }
  
//--- Allocation Constructor (array initialized with inValue)
  public : cSharedArray (const int inCount,
                         const TYPE & inValue COMMA_LOCATION_ARGS) :
  C_SharedObject (THERE),
  TC_UniqueArray<TYPE> (inCount, inValue COMMA_THERE) {
  }
  
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//   Template class declaration                                                                  
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class TC_Array {
//--- Default Constructor
  public : TC_Array (void) ;
  
//--- Destructor
  public : virtual ~ TC_Array (void) ;
  
//--- Allocation Constructor (empty array)
  public : TC_Array (const int inCapacity COMMA_LOCATION_ARGS) ;
  
//--- Allocation Constructor (array initialized with inValue)
  public : TC_Array (const int inCount,
                     const TYPE & inValue COMMA_LOCATION_ARGS) ;
  
//--- Handle Copy
  public : TC_Array (const TC_Array <TYPE> &) ;
  public : TC_Array <TYPE> & operator = (const TC_Array <TYPE> &) ;
  private : void insulate (void) ;

//--- swap
  friend void swap <TYPE> (TC_Array <TYPE> & ioOperand1,
                           TC_Array <TYPE> & ioOperand2) ;

//--- Methods for setting capacity
  public : void setCapacity (const int32_t inNewCapacity) ;

//--- Get Count
  public : inline int32_t count (void) const ;

//--- Array Pointer
  public : const TYPE * unsafeArrayPointer (void) const ;

//--- Add objects at the end of the array
  public : void appendObject (const TYPE & inValue) ; // inValue is copied

//--- Set Count To zero
  public : void setCountToZero (void) ;

//--- Remove all objects and deallocate
  public : void free (void) ;

//--- Call operators
  public : TYPE & operator () (const int32_t inIndex COMMA_LOCATION_ARGS) ;
//  public : const TYPE & operator () (const int32_t inIndex COMMA_LOCATION_ARGS) const ;
  public : const TYPE operator () (const int32_t inIndex COMMA_LOCATION_ARGS) const ;

//--- Element access (with index checking)
  public : const TYPE lastObject (LOCATION_ARGS) const ;
//  public : TYPE & lastObject (LOCATION_ARGS) ;

  public : void setObjectAtIndex (const TYPE & inObject,
                                  const int32_t inIndex
                                  COMMA_LOCATION_ARGS) ;

//--- Insert object at index (0 <= index <= count)
  public : void insertObjectAtIndex (const TYPE & inValue,
                                     const int32_t inIndex
                                     COMMA_LOCATION_ARGS) ; // inValue is copied

//------------------------------------ Sorted array operations
//--- Remove an object, suppose the array is ordered
  public : void removeObjectFromOrderedArray (const TYPE & inKey) ;

// Test is based on 'compare' method, and inValue is copied, object is added if not already in array
  public : void appendUniqueObjectInOrderedArray (const TYPE & inKey) ;

//--- Return -1 if not found
  public : int32_t indexOfObjectInOrderedArray (const TYPE & inKey) const ;

//--- Intersection
  public : void intersectionOfOrderedArraies (const TC_Array<TYPE> & inOperand,
                                              TC_Array<TYPE> & outResult) const ;

//--- Union
  public : void unionOfOrderedArraies (const TC_Array<TYPE> & inOperand,
                                       TC_Array<TYPE> & outResult) const ;

//--- substract
  public : void substractOfOrderedArraies (const TC_Array<TYPE> & inSubstractedSet,
                                           TC_Array<TYPE> & outResult) const ;

//------------------------------------

//--- Remove last object(s)
  public : void removeLastObject (LOCATION_ARGS) ;
  public : void removeLastObjects (const int32_t inCount COMMA_LOCATION_ARGS) ;

//--- Comparisons (based on == operator on objects)
  public : bool operator == (const TC_Array <TYPE> & inOperand) const ;

  public : inline bool operator != (const TC_Array <TYPE> & inOperand) const {
    return ! ((*this) == inOperand) ;
  }

//--- Allocation with provided data
  public : void setDataFromPointer (TYPE * & ioDataPtr,
                                    const int32_t inDataLength) ;

//--- Append data
  public : void appendDataFromPointer (const TYPE * inDataPtr,
                                       const int32_t inDataLength) ;
  
//--- Remove objects at index (0 <= index < count)
  public : void removeObjectAtIndex (const int32_t inIndex
                                     COMMA_LOCATION_ARGS) ;
  public : void removeObjectsAtIndex (const int32_t inCount,
                                      const int32_t inStartingIndex
                                      COMMA_LOCATION_ARGS) ;

//--- Shared Array
  private : cSharedArray <TYPE> * mSharedArray ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//   Default Constructor                                                                         
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array <TYPE>::TC_Array (void) :
mSharedArray (NULL) {
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
mSharedArray (NULL) {
  macroMyNew (mSharedArray, cSharedArray <TYPE> (inCapacity COMMA_THERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Allocation Constructor                                                                      
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array <TYPE>:: TC_Array (const int inCount, const TYPE & inValue COMMA_LOCATION_ARGS) :
mSharedArray (NULL) {
  macroMyNew (mSharedArray, cSharedArray <TYPE> (inCount, inValue COMMA_THERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Copy Constructor                                                                            
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array <TYPE>::TC_Array (const TC_Array <TYPE> & inOperand) :
mSharedArray (NULL) {
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
  if (NULL != mSharedArray) {
    result = mSharedArray->count () ;
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
  if (NULL != mSharedArray) {
    result = mSharedArray->unsafeArrayPointer () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   insulate                                                                                    
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::insulate (void) {
  if ((NULL != mSharedArray) && !mSharedArray->isUniquelyReferenced ()) {
    cSharedArray <TYPE> * p = NULL ;
    macroMyNew (p, cSharedArray <TYPE> ()) ;
    mSharedArray->copyTo (*p) ;
    macroAssignSharedObject (mSharedArray, p) ;
    macroDetachSharedObject (p) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   appendObject (inValue is copied)                                                               
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::appendObject (const TYPE & inValue) {
  if (NULL == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
  }else{
    insulate () ;
  }
  mSharedArray->appendObject (inValue) ;
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
  if (NULL == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
  }else{
    insulate () ;
  }
  macroValidPointer (mSharedArray) ;
  return mSharedArray->operator () (inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

//template <typename TYPE> const TYPE & TC_Array <TYPE>::operator () (const int32_t inIndex COMMA_LOCATION_ARGS) const {
//  macroValidPointer (mSharedArray) ;
//  return mSharedArray->operator () (inIndex COMMA_THERE) ;
//}    

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> const TYPE TC_Array <TYPE>::operator () (const int32_t inIndex COMMA_LOCATION_ARGS) const {
  macroValidPointer (mSharedArray) ;
  return mSharedArray->operator () (inIndex COMMA_THERE) ;
}    

//----------------------------------------------------------------------------------------------------------------------
//
//   Last object access (with index checking)                                                    
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> const TYPE TC_Array <TYPE>::lastObject (LOCATION_ARGS) const {
  macroValidPointer (mSharedArray) ;
  return mSharedArray->lastObject (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

//template <typename TYPE> TYPE & TC_Array <TYPE>::lastObject (LOCATION_ARGS) {
//  macroValidPointer (mSharedArray) ;
//  return mSharedArray->lastObject (THERE) ;
//}    

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove last object                                                                          
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::removeLastObject (LOCATION_ARGS) {
  insulate () ;
  macroValidPointer (mSharedArray) ;
  mSharedArray->removeLastObject (THERE) ;
}    

//----------------------------------------------------------------------------------------------------------------------
//
//   Remove last objects                                                                         
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::removeLastObjects (const int32_t inCount COMMA_LOCATION_ARGS) {
  insulate () ;
  macroValidPointer (mSharedArray) ;
  mSharedArray->removeLastObjects (inCount COMMA_THERE) ;
}    

//----------------------------------------------------------------------------------------------------------------------
//
//   Set Count To zero                                                                           
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::setCountToZero (void) {
  if (NULL != mSharedArray) {
    insulate () ;
    mSharedArray->setCountToZero () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   ==                                                                                          
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> bool TC_Array <TYPE>::operator == (const TC_Array <TYPE> & inOperand) const {
  bool result = mSharedArray == inOperand.mSharedArray ;
  if (!result && (mSharedArray != NULL) && (inOperand.mSharedArray != NULL)) {
    result = (*mSharedArray) == *(inOperand.mSharedArray) ;
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
  if (NULL != mSharedArray) {
    macroDetachSharedObject (mSharedArray) ;
  }
  macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
  mSharedArray->setDataFromPointer (ioDataPtr, inDataLength) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   appendDataFromPointer                                                                       
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::appendDataFromPointer (const TYPE * inDataPtr,
                                                                      const int32_t inDataLength) {
  if (NULL == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE> ()) ;
  }else{
    insulate () ;
  }
  mSharedArray->appendDataFromPointer (inDataPtr, inDataLength) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   setCapacity                                                                                 
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::setCapacity (const int32_t inNewCapacity) {
  if (NULL == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE> (inNewCapacity COMMA_HERE)) ;
  }else{
    insulate () ;
    mSharedArray->setCapacity (inNewCapacity) ;
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
  mSharedArray->removeObjectAtIndex (inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::removeObjectsAtIndex (const int32_t inCount,
                                                                     const int32_t inStartingIndex
                                                                     COMMA_LOCATION_ARGS) {
  insulate () ;
  macroUniqueSharedObject (mSharedArray) ;
  mSharedArray->removeObjectsAtIndex (inCount, inStartingIndex COMMA_THERE) ;
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
  mSharedArray->setObjectAtIndex (inObject, inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   insertObjectAtIndex                                                                         
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::insertObjectAtIndex (const TYPE & inObject,
                                                                    const int32_t inIndex  // inValue is copied
                                                                    COMMA_LOCATION_ARGS) {
  if (NULL == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE>) ;
  }else{
    insulate () ;
  }
  macroUniqueSharedObject (mSharedArray) ;
  mSharedArray->setObjectAtIndex (inObject, inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   appendUniqueObjectInOrderedArray                                                               
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::appendUniqueObjectInOrderedArray (const TYPE & inKey) {
  if (NULL == mSharedArray) {
    macroMyNew (mSharedArray, cSharedArray <TYPE>) ;
  }else{
    insulate () ;
  }
  macroUniqueSharedObject (mSharedArray) ;
  mSharedArray->appendUniqueObjectInOrderedArray (inKey) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   removeObjectFromOrderedArray                                                                
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::removeObjectFromOrderedArray (const TYPE & inKey) {
  if (NULL != mSharedArray) {
    insulate () ;
    macroUniqueSharedObject (mSharedArray) ;
    mSharedArray->removeObjectFromOrderedArray (inKey) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   indexOfObjectInOrderedArray                                                                 
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> int32_t TC_Array <TYPE>::indexOfObjectInOrderedArray (const TYPE & inKey) const {
  int32_t result = -1 ; // Not found
  if (NULL != mSharedArray) {
    macroValidPointer (mSharedArray) ;
    result = mSharedArray->indexOfObjectInOrderedArray (inKey) ;
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
  outResult.setCountToZero () ;
  if ((count () > 0) && (inOperand.count () > 0)) {
    if (NULL == outResult.mSharedArray) {
      macroMyNew (outResult.mSharedArray, cSharedArray <TYPE>) ;
    }else{
      outResult.insulate () ;
    }
    macroUniqueSharedObject (outResult.mSharedArray) ;
    macroValidPointer (mSharedArray) ;
    macroValidPointer (inOperand.mSharedArray) ;
    mSharedArray->intersectionOfOrderedArraies (* (inOperand.mSharedArray), * (outResult.mSharedArray)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   unionOfOrderedArraies                                                                       
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::unionOfOrderedArraies (const TC_Array<TYPE> & inOperand,
                                                                      TC_Array<TYPE> & outResult) const {
  outResult.setCountToZero () ;
  if ((count () > 0) && (inOperand.count () == 0)) {
    outResult = *this ;
  }else if ((count () == 0) && (inOperand.count () > 0)) {
    outResult = inOperand ;
  }else if ((count () > 0) && (inOperand.count () > 0)) {
    if (NULL == outResult.mSharedArray) {
      macroMyNew (outResult.mSharedArray, cSharedArray <TYPE>) ;
    }else{
      outResult.insulate () ;
    }
    macroUniqueSharedObject (outResult.mSharedArray) ;
    macroValidPointer (mSharedArray) ;
    macroValidPointer (inOperand.mSharedArray) ;
    mSharedArray->unionOfOrderedArraies (* (inOperand.mSharedArray), * (outResult.mSharedArray)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   substractOfOrderedArraies                                                                   
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array <TYPE>::substractOfOrderedArraies (const TC_Array<TYPE> & inSubstractedSet,
                                                                          TC_Array<TYPE> & outResult) const {
  outResult.setCountToZero () ;
  if (count () > 0) {
    if (inSubstractedSet.count () == 0) {
      outResult = *this ;
    }else{
      if (NULL == outResult.mSharedArray) {
        macroMyNew (outResult.mSharedArray, cSharedArray <TYPE>) ;
      }else{
        outResult.insulate () ;
      }
      macroUniqueSharedObject (outResult.mSharedArray) ;
      macroValidPointer (mSharedArray) ;
      macroValidPointer (inSubstractedSet.mSharedArray) ;
      mSharedArray->substractOfOrderedArraies (* (inSubstractedSet.mSharedArray), * (outResult.mSharedArray)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
