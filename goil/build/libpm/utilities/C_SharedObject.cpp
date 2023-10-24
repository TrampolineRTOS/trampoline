//----------------------------------------------------------------------------------------------------------------------
//
//  C_SharedObject : Base class for GALGAS object handling                                       
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2009, ..., 2021 Pierre Molinaro.
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

#include "utilities/C_SharedObject.h"
#include "utilities/MF_MemoryControl.h"
#include "streams/C_ConsoleOut.h"
#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Validity Checking (only in Debug Mode)
#endif

//----------------------------------------------------------------------------------------------------------------------

static uint32_t gCreationIndex ;
static uint32_t gObjectCurrentCount ;

//--- List of existing objects
#ifndef DO_NOT_GENERATE_CHECKINGS
  static C_SharedObject * gFirstObject ;
  static C_SharedObject * gLastObject ;
#endif

//----------------------------------------------------------------------------------------------------------------------

C_SharedObject::C_SharedObject (LOCATION_ARGS) :
#ifndef DO_NOT_GENERATE_CHECKINGS
  mCreationFile (IN_SOURCE_FILE),
  mCreationLine (IN_SOURCE_LINE),
  mPtrToPreviousObject (nullptr),
  mPtrToNextObject (nullptr),
#endif
mObjectIndex (gCreationIndex),
mRetainCount (1) {
  gCreationIndex ++ ;
  gObjectCurrentCount ++ ;
//--- Enter current object in instance list
  #ifndef DO_NOT_GENERATE_CHECKINGS
    mPtrToNextObject = nullptr ;
    if (gLastObject == nullptr) {
      gFirstObject = this ;
      mPtrToPreviousObject = nullptr ;
    }else{
      gLastObject->mPtrToNextObject = this ;
      mPtrToPreviousObject = gLastObject ;
    }
    gLastObject = this ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------

C_SharedObject::~ C_SharedObject (void) {
//--- Remove object from instance list
  #ifndef DO_NOT_GENERATE_CHECKINGS
    C_SharedObject * previousObject = mPtrToPreviousObject ;
    C_SharedObject * nextObject = mPtrToNextObject ;
    if (previousObject == nullptr) {
      gFirstObject = nextObject ;
    }else{
      previousObject->mPtrToNextObject = nextObject ;
    }
    if (nextObject == nullptr) {
      gLastObject = previousObject ;
    }else{
      nextObject->mPtrToPreviousObject = previousObject ;
    }
  #endif
//--- Decrement object count
  gObjectCurrentCount -- ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_SharedObject::retain (const C_SharedObject * inObject COMMA_LOCATION_ARGS) {
  if (inObject != nullptr) {
    macroValidSharedObjectThere (inObject, C_SharedObject) ;
    inObject->mRetainCount ++ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_SharedObject::release (const C_SharedObject * inObject COMMA_LOCATION_ARGS) {
  if (inObject != nullptr) {
    macroValidSharedObjectThere (inObject, C_SharedObject) ;
    MF_AssertThere (inObject->mRetainCount > 0, "mRetainCount should be > 0)", 0, 0) ;
    inObject->mRetainCount -- ;
    if (inObject->mRetainCount == 0) {
      macroMyDelete (inObject) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_SharedObject::retainRelease (const C_SharedObject * inObjectToRetain,
                                    const C_SharedObject * inObjectToRelease
                                    COMMA_LOCATION_ARGS) {
  retain (inObjectToRetain COMMA_THERE) ;
  release (inObjectToRelease COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Collect unused Objects
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void C_SharedObject::checkAllObjectsHaveBeenReleased (void) {
    if (gObjectCurrentCount != 0) {
      co << "Warning: "
         << cStringWithUnsigned (gObjectCurrentCount)
         << " object"
         << ((gObjectCurrentCount > 1) ? "s have" : " has")
         << " not been released:\n";
      C_SharedObject * p = gFirstObject ;
      while (p != nullptr) {
        co << "- object declared in '"
           << p->mCreationFile
           << "', line "
           << cStringWithSigned (p->mCreationLine)
           << " (retain count: "
           << cStringWithSigned (p->mRetainCount)
           << ")\n" ;
        p = p->mPtrToNextObject ;
      }
    }
  }
#endif

//----------------------------------------------------------------------------------------------------------------------
