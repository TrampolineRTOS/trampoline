//
//  C_RelationSingleType.cpp
//  galgas-developer
//
//  Created by Pierre Molinaro on 22/05/14.
//----------------------------------------------------------------------------------------------------------------------

#include "bdd/C_RelationSingleType.h"
#include "utilities/C_SharedObject.h"
#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

static uint32_t bitCountForCount (const uint32_t inCount) {
  uint32_t result = 0 ;
  uint32_t v = inCount - 1 ;
  while (v != 0) {
    result ++ ;
    v >>= 1 ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//  C_RelationSingleType::cType                                                                  
//----------------------------------------------------------------------------------------------------------------------

static C_RelationSingleType::cType * gFirstRelation ;
static C_RelationSingleType::cType * gLastRelation ;

//----------------------------------------------------------------------------------------------------------------------

class C_RelationSingleType::cType : public C_SharedObject {
//--- Constructor
  public: inline cType (const C_String & inTypeName,
                         const uint32_t inBDDBitCount
                         COMMA_LOCATION_ARGS) :
  C_SharedObject (THERE),
  mTypeName (inTypeName),
  mBDDBitCount (inBDDBitCount),
  mNextPtr (gFirstRelation),
  mPreviousPtr (NULL) {
    if (NULL != gFirstRelation) {
      gFirstRelation->mPreviousPtr = this ;
    }
    gFirstRelation = this ;
  }

//--- Desctructor
  public: inline virtual ~cType (void) {
    if (NULL == mNextPtr) {
      gLastRelation = mPreviousPtr ;
    }else{
      mNextPtr->mPreviousPtr = mPreviousPtr ;
    }
    if (NULL == mPreviousPtr) {
      gFirstRelation = mNextPtr ;
    }else{
      mPreviousPtr->mNextPtr = mNextPtr ;
    }
  }

//--- No copy
  private: cType (const cType &) ;
  private: cType & operator = (const cType &) ;

//--- Accessors
  public: virtual uint32_t constantCount (void) const = 0 ;
  public: virtual C_String nameForValue (const uint32_t inIndex
                                          COMMA_LOCATION_ARGS) const = 0 ;

//--- Attribute
  public: const C_String mTypeName ;
  public: const uint32_t mBDDBitCount ;
  public: cType * mNextPtr ;
  private: cType * mPreviousPtr ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//  C_EnumeratedTypeInRelation                                                                   
//----------------------------------------------------------------------------------------------------------------------

class C_EnumeratedTypeInRelation : public C_RelationSingleType::cType {
//--- Constructor
  public: C_EnumeratedTypeInRelation (const C_String & inTypeName,
                                       const TC_UniqueArray <C_String> & inConstantNameArray
                                       COMMA_LOCATION_ARGS) ;

//--- Accessors
  public: virtual uint32_t constantCount (void) const {
    return (uint32_t) mConstantNameArray.count () ;
  }

  public: virtual C_String nameForValue (const uint32_t inIndex
                                          COMMA_LOCATION_ARGS) const {
    return mConstantNameArray ((int32_t) inIndex COMMA_THERE) ;
  }

  public: inline bool isConstantArrayEqualTo (const TC_UniqueArray <C_String> & inConstantNameArray) const {
    return mConstantNameArray == inConstantNameArray ;
  }

//--- Attributes
  private: TC_UniqueArray <C_String> mConstantNameArray ;
} ;

//----------------------------------------------------------------------------------------------------------------------

C_EnumeratedTypeInRelation::
C_EnumeratedTypeInRelation (const C_String & inTypeName,
                            const TC_UniqueArray <C_String> & inConstantNameArray
                            COMMA_LOCATION_ARGS) :
cType (inTypeName, bitCountForCount ((uint32_t) inConstantNameArray.count ()) COMMA_THERE),
mConstantNameArray () {
  mConstantNameArray.appendObjectsFromArray (inConstantNameArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_RelationSingleType::
C_RelationSingleType (const C_String & inTypeName,
                      const TC_UniqueArray <C_String> & inConstantNameArray
                      COMMA_LOCATION_ARGS) :
mTypePtr (NULL) {
//--- Check type is unique
  cType * result = NULL ;
  cType * p = gFirstRelation ;
  while ((NULL == result) && (NULL != p)) {
    C_EnumeratedTypeInRelation * ptr = dynamic_cast <C_EnumeratedTypeInRelation *> (p) ;
    if ((NULL != ptr) && (ptr->mTypeName == inTypeName) && (ptr->isConstantArrayEqualTo (inConstantNameArray))) {
      result = ptr ;
    }
    p = p->mNextPtr ;
  }
//---
  if (NULL == result) {
    macroMyNew (mTypePtr, C_EnumeratedTypeInRelation (inTypeName, inConstantNameArray COMMA_THERE)) ;
  }else{
    macroAssignSharedObject (mTypePtr, result) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//  C_UnsignedTypeInRelation                                                                     
//----------------------------------------------------------------------------------------------------------------------

class C_UnsignedTypeInRelation : public C_RelationSingleType::cType {
//--- Constructor
  public: C_UnsignedTypeInRelation (const C_String & inTypeName,
                                     const uint32_t inValueCount
                                     COMMA_LOCATION_ARGS) ;

//--- Accessors
  public: virtual uint32_t constantCount (void) const {
    return mValueCount ;
  }

  public: virtual C_String nameForValue (const uint32_t inIndex
                                          COMMA_UNUSED_LOCATION_ARGS) const {
    return cStringWithUnsigned (inIndex) ;
  }

//--- Attributes
  private: const uint32_t mValueCount ;
} ;

//----------------------------------------------------------------------------------------------------------------------

C_UnsignedTypeInRelation::
C_UnsignedTypeInRelation (const C_String & inTypeName,
                          const uint32_t inValueCount
                          COMMA_LOCATION_ARGS) :
cType (inTypeName, bitCountForCount (inValueCount) COMMA_THERE),
mValueCount (inValueCount) {
}

//----------------------------------------------------------------------------------------------------------------------

C_RelationSingleType::
C_RelationSingleType (const C_String & inTypeName,
                      const uint32_t inValueCount
                      COMMA_LOCATION_ARGS) :
mTypePtr (NULL) {
//--- Check type is unique
  cType * result = NULL ;
  cType * p = gFirstRelation ;
  while ((NULL == result) && (NULL != p)) {
    C_UnsignedTypeInRelation * ptr = dynamic_cast <C_UnsignedTypeInRelation *> (p) ;
    if ((NULL != ptr) && (ptr->mTypeName == inTypeName) && (ptr->constantCount () == inValueCount)) {
      result = ptr ;
    }
    p = p->mNextPtr ;
  }
//---
  if (NULL == result) {
    macroMyNew (mTypePtr, C_UnsignedTypeInRelation (inTypeName, inValueCount COMMA_THERE)) ;
  }else{
    macroAssignSharedObject (mTypePtr, result) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//  Accessors                                            
//----------------------------------------------------------------------------------------------------------------------

C_String C_RelationSingleType::typeName (void) const {
  macroValidPointer (mTypePtr) ;
  return mTypePtr->mTypeName ;
}

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_RelationSingleType::BDDBitCount (void) const {
  macroValidPointer (mTypePtr) ;
  return mTypePtr->mBDDBitCount ;
}

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_RelationSingleType::constantCount (void) const {
  macroValidPointer (mTypePtr) ;
  return mTypePtr->constantCount () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_RelationSingleType::nameForValue (const uint32_t inIndex
                                             COMMA_LOCATION_ARGS) const {
  macroValidPointer (mTypePtr) ;
  return mTypePtr->nameForValue (inIndex COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//  Handling copy                                                                                
//----------------------------------------------------------------------------------------------------------------------

C_RelationSingleType::~C_RelationSingleType (void) {
  macroDetachSharedObject (mTypePtr) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_RelationSingleType::C_RelationSingleType (const C_RelationSingleType & inSource) :
mTypePtr (NULL) {
  macroAssignSharedObject (mTypePtr, inSource.mTypePtr) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_RelationSingleType & C_RelationSingleType::operator = (const C_RelationSingleType & inSource) {
  macroAssignSharedObject (mTypePtr, inSource.mTypePtr) ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------
