//
//  C_Relation.cpp
//  galgas-developer
//
//  Created by Pierre Molinaro on 22/05/14.
//  Copyright (c) 2014 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------------------------------------------------*

#include "bdd/C_Relation.h"
#include "utilities/C_SharedObject.h"

//---------------------------------------------------------------------------------------------------------------------*
//  cVariablesInRelationConfiguration                                          *
//---------------------------------------------------------------------------------------------------------------------*

class cVariablesInRelationConfiguration : public C_SharedObject {
//--- Constructor
  public : cVariablesInRelationConfiguration (LOCATION_ARGS) ;
  public : cVariablesInRelationConfiguration (cVariablesInRelationConfiguration * inPtr COMMA_LOCATION_ARGS) ;


  public : void addVariable (const C_String & inVariableName,
                             const C_RelationSingleType & inType) ;

//--- Accessors
  public : uint32_t bitCount (void) const ;

  public : C_String nameForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const ;

  public : C_RelationSingleType typeForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const ;

  public : uint32_t constantCountForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const ;

  public : void deleteVariableAtIndex (const int32_t inIndex COMMA_LOCATION_ARGS) ;

  public : void deleteLastVariable (LOCATION_ARGS) ;

  public : inline int32_t variableCount (void) const {
    return mBDDStartIndexArray.count () ;
  }

  public : inline uint32_t bddStartBitIndexForVariable (const int32_t inIndex
                                                        COMMA_LOCATION_ARGS) const {
    return mBDDStartIndexArray (inIndex COMMA_THERE) ;
  }

  public : inline uint32_t bddBitCountForVariable (const int32_t inIndex
                                                   COMMA_LOCATION_ARGS) const {
    return mVariableTypeArray (inIndex COMMA_THERE).BDDBitCount () ;
  }

  public : C_String constantNameForVariableAndValue (const int32_t inIndex,
                                                     const uint32_t inValue
                                                     COMMA_LOCATION_ARGS) const ;

//---
  public : void checkIdenticalTo (const cVariablesInRelationConfiguration * inVariables
                                  COMMA_LOCATION_ARGS) const ;

//--- Operations on 3 set configurations  
  public : void swap021 (LOCATION_ARGS) ;

  public : void swap102 (LOCATION_ARGS) ;

  public : void swap120 (LOCATION_ARGS) ;

  public : void swap201 (LOCATION_ARGS) ;

  public : void swap210 (LOCATION_ARGS) ;

  #ifndef DO_NOT_GENERATE_CHECKINGS
    private : void checkConfiguration (LOCATION_ARGS) const ;
  #endif

//--- Attributes
  private : TC_UniqueArray <uint32_t> mBDDStartIndexArray ;
  private : TC_UniqueArray <C_String> mVariableNameArray ;
  private : TC_UniqueArray <C_RelationSingleType> mVariableTypeArray ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cVariablesInRelationConfiguration::
cVariablesInRelationConfiguration (LOCATION_ARGS) :
C_SharedObject (THERE),
mBDDStartIndexArray (),
mVariableNameArray (),
mVariableTypeArray () {
}

//---------------------------------------------------------------------------------------------------------------------*

cVariablesInRelationConfiguration::
cVariablesInRelationConfiguration (cVariablesInRelationConfiguration * inPtr
                                   COMMA_LOCATION_ARGS) :
C_SharedObject (THERE),
mBDDStartIndexArray (),
mVariableNameArray (),
mVariableTypeArray () {
  macroValidSharedObjectThere (inPtr, cVariablesInRelationConfiguration) ;
  mBDDStartIndexArray.addObjectsFromArray (inPtr->mBDDStartIndexArray) ;
  mVariableNameArray.addObjectsFromArray (inPtr->mVariableNameArray) ;
  mVariableTypeArray.addObjectsFromArray (inPtr->mVariableTypeArray) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkConfiguration (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cVariablesInRelationConfiguration::checkConfiguration (LOCATION_ARGS) const {
    MF_AssertThere (mBDDStartIndexArray.count () == mVariableNameArray.count (),
                    "mBDDStartIndexArray.count () == %lld != mVariableNameArray.count () == %lld",
                    mBDDStartIndexArray.count (),
                    mVariableNameArray.count ()) ;
    MF_AssertThere (mBDDStartIndexArray.count () == mVariableTypeArray.count (),
                    "mBDDStartIndexArray.count () == %lld != mVariableTypeArray.count () == %lld",
                    mBDDStartIndexArray.count (),
                    mVariableTypeArray.count ()) ;
    uint32_t bddIndex = 0 ;
    for (int32_t i=0 ; i<mBDDStartIndexArray.count () ; i++) {
      MF_AssertThere (bddIndex == mBDDStartIndexArray (i COMMA_HERE),
                      "bddIndex == %lld != mBDDStartIndexArray (i COMMA_HERE) == %lld",
                      bddIndex,
                      mBDDStartIndexArray (i COMMA_HERE)) ;
      bddIndex += mVariableTypeArray (i COMMA_HERE).BDDBitCount() ;
    }  
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

void cVariablesInRelationConfiguration::addVariable (const C_String & inVariableName,
                                                     const C_RelationSingleType & inType) {
  if (mBDDStartIndexArray.count () == 0) {
    mBDDStartIndexArray.addObject (0) ;
  }else{
    mBDDStartIndexArray.addObject (bitCount ()) ;
  }
  mVariableNameArray.addObject (inVariableName) ;
  mVariableTypeArray.addObject (inType) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkConfiguration (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

void cVariablesInRelationConfiguration::checkIdenticalTo (const cVariablesInRelationConfiguration * inVariables
                                                          COMMA_LOCATION_ARGS) const {
  macroValidSharedObjectThere (inVariables, cVariablesInRelationConfiguration) ;
  bool same = mVariableTypeArray.count() == inVariables->mVariableTypeArray.count() ;
  for (int32_t i=0 ; (i<mVariableTypeArray.count()) && same ; i++) {
    same = mVariableTypeArray (i COMMA_HERE) == inVariables->mVariableTypeArray (i COMMA_HERE) ;
  }
  MF_AssertThere (same,
                  "cVariablesInRelationConfiguration::checkIdenticalTo failure",
                  0,
                  0) ;
  
  if (! same) {
    printf ("*** cVariablesInRelationConfiguration::checkIdenticalTo failure ***\n") ;
    exit (1) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cVariablesInRelationConfiguration::deleteVariableAtIndex (const int32_t inIndex COMMA_LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  uint32_t idx = mBDDStartIndexArray (inIndex COMMA_THERE) ;
  mBDDStartIndexArray.removeObjectAtIndex (inIndex COMMA_THERE) ;
  mVariableNameArray.removeObjectAtIndex (inIndex COMMA_THERE) ;
  mVariableTypeArray.removeObjectAtIndex (inIndex COMMA_THERE) ;
  for (int32_t i=inIndex ; i<mBDDStartIndexArray.count () ; i++) {
    mBDDStartIndexArray.setObjectAtIndex (idx, i COMMA_HERE) ;
    idx += mVariableTypeArray (i COMMA_HERE).BDDBitCount () ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkConfiguration (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

void cVariablesInRelationConfiguration::deleteLastVariable (LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  mBDDStartIndexArray.removeLastObject (THERE) ;
  mVariableNameArray.removeLastObject (THERE) ;
  mVariableTypeArray.removeLastObject (THERE) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkConfiguration (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t cVariablesInRelationConfiguration::constantCountForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const {
  return mVariableTypeArray (inIndex COMMA_THERE).constantCount () ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t cVariablesInRelationConfiguration::bitCount (void) const {
  return mBDDStartIndexArray.lastObject (HERE) + mVariableTypeArray.lastObject (HERE).BDDBitCount() ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String cVariablesInRelationConfiguration::constantNameForVariableAndValue (const int32_t inIndex,
                                                                             const uint32_t inValue
                                                                             COMMA_LOCATION_ARGS) const {
  return mVariableTypeArray (inIndex COMMA_THERE).nameForValue(inValue COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String cVariablesInRelationConfiguration::nameForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const {
  return mVariableNameArray (inIndex COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_RelationSingleType cVariablesInRelationConfiguration::typeForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const {
  return mVariableTypeArray (inIndex COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cVariablesInRelationConfiguration::swap021 (LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  mVariableNameArray.exchangeObjectAtIndexes (1, 2 COMMA_THERE) ;
  mVariableTypeArray.exchangeObjectAtIndexes (1, 2 COMMA_THERE) ;
  uint32_t bitIndex = mVariableTypeArray (0 COMMA_THERE).BDDBitCount() ;
  mBDDStartIndexArray.setObjectAtIndex (bitIndex, 1 COMMA_THERE) ;
  bitIndex += mVariableTypeArray (1 COMMA_THERE).BDDBitCount() ;
  mBDDStartIndexArray.setObjectAtIndex (bitIndex, 2 COMMA_THERE) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkConfiguration (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

void cVariablesInRelationConfiguration::swap102 (LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  mVariableNameArray.exchangeObjectAtIndexes (0, 1 COMMA_THERE) ;
  mVariableTypeArray.exchangeObjectAtIndexes (0, 1 COMMA_THERE) ;
  mBDDStartIndexArray.setObjectAtIndex (0, 0 COMMA_THERE) ;
  uint32_t bitIndex = mVariableTypeArray (0 COMMA_THERE).BDDBitCount() ;
  mBDDStartIndexArray.setObjectAtIndex (bitIndex, 1 COMMA_THERE) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkConfiguration (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

void cVariablesInRelationConfiguration::swap120 (LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  mVariableNameArray.exchangeObjectAtIndexes (0, 1 COMMA_THERE) ;
  mVariableTypeArray.exchangeObjectAtIndexes (0, 1 COMMA_THERE) ;
  mVariableNameArray.exchangeObjectAtIndexes (1, 2 COMMA_THERE) ;
  mVariableTypeArray.exchangeObjectAtIndexes (1, 2 COMMA_THERE) ;
  mBDDStartIndexArray.setObjectAtIndex (0, 0 COMMA_THERE) ;
  uint32_t bitIndex = mVariableTypeArray (0 COMMA_THERE).BDDBitCount() ;
  mBDDStartIndexArray.setObjectAtIndex (bitIndex, 1 COMMA_THERE) ;
  bitIndex += mVariableTypeArray (1 COMMA_THERE).BDDBitCount() ;
  mBDDStartIndexArray.setObjectAtIndex (bitIndex, 2 COMMA_THERE) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkConfiguration (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

void cVariablesInRelationConfiguration::swap201 (LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  mVariableNameArray.exchangeObjectAtIndexes (1, 2 COMMA_THERE) ;
  mVariableTypeArray.exchangeObjectAtIndexes (1, 2 COMMA_THERE) ;
  mVariableNameArray.exchangeObjectAtIndexes (0, 1 COMMA_THERE) ;
  mVariableTypeArray.exchangeObjectAtIndexes (0, 1 COMMA_THERE) ;
  mBDDStartIndexArray.setObjectAtIndex (0, 0 COMMA_THERE) ;
  uint32_t bitIndex = mVariableTypeArray (0 COMMA_THERE).BDDBitCount() ;
  mBDDStartIndexArray.setObjectAtIndex (bitIndex, 1 COMMA_THERE) ;
  bitIndex += mVariableTypeArray (1 COMMA_THERE).BDDBitCount() ;
  mBDDStartIndexArray.setObjectAtIndex (bitIndex, 2 COMMA_THERE) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkConfiguration (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

void cVariablesInRelationConfiguration::swap210 (LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  mVariableNameArray.exchangeObjectAtIndexes (0, 2 COMMA_THERE) ;
  mVariableTypeArray.exchangeObjectAtIndexes (0, 2 COMMA_THERE) ;
  mBDDStartIndexArray.setObjectAtIndex (0, 0 COMMA_THERE) ;
  uint32_t bitIndex = mVariableTypeArray (0 COMMA_THERE).BDDBitCount() ;
  mBDDStartIndexArray.setObjectAtIndex (bitIndex, 1 COMMA_THERE) ;
  bitIndex += mVariableTypeArray (1 COMMA_THERE).BDDBitCount() ;
  mBDDStartIndexArray.setObjectAtIndex (bitIndex, 2 COMMA_THERE) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkConfiguration (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*
//  C_RelationConfiguration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

C_RelationConfiguration::C_RelationConfiguration (void) :
mVariablesPtr (NULL) {
}

//---------------------------------------------------------------------------------------------------------------------*

C_RelationConfiguration::~C_RelationConfiguration (void) {
  macroDetachSharedObject (mVariablesPtr) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_RelationConfiguration::C_RelationConfiguration (const C_RelationConfiguration & inSource) :
mVariablesPtr (NULL) {
  macroAssignSharedObject (mVariablesPtr, inSource.mVariablesPtr) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_RelationConfiguration & C_RelationConfiguration::operator = (const C_RelationConfiguration & inSource) {
  if (this != & inSource) {
    macroAssignSharedObject (mVariablesPtr, inSource.mVariablesPtr) ;
  }
  return *this ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_RelationConfiguration::insulate (LOCATION_ARGS) {
  if (NULL == mVariablesPtr) {
    macroMyNew (mVariablesPtr, cVariablesInRelationConfiguration (THERE)) ;
  }else{
    macroValidSharedObjectThere (mVariablesPtr, cVariablesInRelationConfiguration) ;
    if (mVariablesPtr->retainCount () > 1) {
      cVariablesInRelationConfiguration * ptr = NULL ;
      macroMyNew (ptr, cVariablesInRelationConfiguration (mVariablesPtr COMMA_THERE)) ;
      macroAssignSharedObject (mVariablesPtr, ptr) ;
      macroDetachSharedObject (ptr) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_RelationConfiguration::addVariable (const C_String & inVariableName,
                                           const C_RelationSingleType & inType) {
  insulate (HERE) ;
  macroValidSharedObject (mVariablesPtr, cVariablesInRelationConfiguration) ;
  mVariablesPtr->addVariable (inVariableName, inType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_RelationConfiguration::appendConfiguration (const C_RelationConfiguration & inConfiguration) {
  insulate (HERE) ;
  for (int32_t i=0 ; i<inConfiguration.variableCount() ; i++) {
    const C_String variableName = inConfiguration.nameForVariable (i COMMA_HERE) ;
    const C_RelationSingleType type = inConfiguration.typeForVariable (i COMMA_HERE) ;
    mVariablesPtr->addVariable (variableName, type) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_RelationConfiguration::nameForVariable (const int32_t inIndex
                                                   COMMA_LOCATION_ARGS) const {
  macroValidSharedObjectThere (mVariablesPtr, cVariablesInRelationConfiguration) ;
  return mVariablesPtr->nameForVariable (inIndex COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_RelationSingleType C_RelationConfiguration::typeForVariable (const int32_t inIndex
                                                               COMMA_LOCATION_ARGS) const {
  macroValidSharedObjectThere (mVariablesPtr, cVariablesInRelationConfiguration) ;
  return mVariablesPtr->typeForVariable (inIndex COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_RelationConfiguration::bitCount (void) const {
  uint32_t result = 0 ;
  if (NULL != mVariablesPtr) {
    macroValidSharedObject (mVariablesPtr, cVariablesInRelationConfiguration) ;
    result = mVariablesPtr->bitCount () ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

int32_t C_RelationConfiguration::variableCount (void) const {
  int32_t result = 0 ;
  if (NULL != mVariablesPtr) {
    macroValidSharedObject (mVariablesPtr, cVariablesInRelationConfiguration) ;
    result = mVariablesPtr->variableCount () ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_RelationConfiguration::constantCountForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const {
  macroValidSharedObjectThere (mVariablesPtr, cVariablesInRelationConfiguration) ;
  return mVariablesPtr->constantCountForVariable (inIndex COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_RelationConfiguration::bddStartBitIndexForVariable (const int32_t inIndex
                                                               COMMA_LOCATION_ARGS) const {
  macroValidSharedObjectThere (mVariablesPtr, cVariablesInRelationConfiguration) ;
  return mVariablesPtr->bddStartBitIndexForVariable (inIndex COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_RelationConfiguration::bddBitCountForVariable (const int32_t inIndex
                                                          COMMA_LOCATION_ARGS) const {
  macroValidSharedObjectThere (mVariablesPtr, cVariablesInRelationConfiguration) ;
  return mVariablesPtr->bddBitCountForVariable (inIndex COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_RelationConfiguration::constantNameForVariableAndValue (const int32_t inIndex,
                                                                   const uint32_t inValue
                                                                   COMMA_LOCATION_ARGS) const {
  macroValidSharedObjectThere (mVariablesPtr, cVariablesInRelationConfiguration) ;
  return mVariablesPtr->constantNameForVariableAndValue (inIndex, inValue COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_RelationConfiguration::checkIdenticalTo (const C_RelationConfiguration & inConfiguration
                                                 COMMA_LOCATION_ARGS) const {
  bool same = mVariablesPtr == inConfiguration.mVariablesPtr ;
  if ((! same) && (NULL != mVariablesPtr) && (NULL != inConfiguration.mVariablesPtr)) {
    macroValidSharedObjectThere (mVariablesPtr, cVariablesInRelationConfiguration) ;
    mVariablesPtr->checkIdenticalTo (inConfiguration.mVariablesPtr COMMA_THERE) ;
  }else if (! same) {
    printf ("*** C_RelationConfiguration::checkIdenticalTo failure ***\n") ;
    exit (1) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_RelationConfiguration::deleteVariableAtIndex (const int32_t inIndex COMMA_LOCATION_ARGS) {
  insulate (THERE) ;
  macroValidSharedObjectThere (mVariablesPtr, cVariablesInRelationConfiguration) ;
  return mVariablesPtr->deleteVariableAtIndex (inIndex COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_RelationConfiguration::deleteLastVariable (LOCATION_ARGS) {
  insulate (THERE) ;
  macroValidSharedObjectThere (mVariablesPtr, cVariablesInRelationConfiguration) ;
  return mVariablesPtr->deleteLastVariable (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_RelationConfiguration C_RelationConfiguration::swap021 (LOCATION_ARGS) const {
  C_RelationConfiguration result = *this ;
  result.insulate (THERE) ;
  macroValidSharedObjectThere (result.mVariablesPtr, cVariablesInRelationConfiguration) ;
  result.mVariablesPtr->swap021 (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_RelationConfiguration C_RelationConfiguration::swap102 (LOCATION_ARGS) const {
  C_RelationConfiguration result = *this ;
  result.insulate (THERE) ;
  macroValidSharedObjectThere (result.mVariablesPtr, cVariablesInRelationConfiguration) ;
  result.mVariablesPtr->swap102 (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_RelationConfiguration C_RelationConfiguration::swap120 (LOCATION_ARGS) const {
  C_RelationConfiguration result = *this ;
  result.insulate (THERE) ;
  macroValidSharedObjectThere (result.mVariablesPtr, cVariablesInRelationConfiguration) ;
  result.mVariablesPtr->swap120 (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_RelationConfiguration C_RelationConfiguration::swap201 (LOCATION_ARGS) const {
  C_RelationConfiguration result = *this ;
  result.insulate (THERE) ;
  macroValidSharedObjectThere (result.mVariablesPtr, cVariablesInRelationConfiguration) ;
  result.mVariablesPtr->swap201 (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_RelationConfiguration C_RelationConfiguration::swap210 (LOCATION_ARGS) const {
  C_RelationConfiguration result = *this ;
  result.insulate (THERE) ;
  macroValidSharedObjectThere (result.mVariablesPtr, cVariablesInRelationConfiguration) ;
  result.mVariablesPtr->swap210 (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
