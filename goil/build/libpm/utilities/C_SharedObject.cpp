//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  C_SharedObject : Base class for GALGAS object handling                                                             *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/C_SharedObject.h"
#include "utilities/MF_MemoryControl.h"
#include "streams/C_ConsoleOut.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Validity Checking (only in Debug Mode)
#endif

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t gCreationIndex ;
static uint32_t gObjectCurrentCount ;

//--- List of existing objects
static C_SharedObject * gFirstObject ;
static C_SharedObject * gLastObject ;

//---------------------------------------------------------------------------------------------------------------------*

C_SharedObject::C_SharedObject (LOCATION_ARGS) :
#ifndef DO_NOT_GENERATE_CHECKINGS
  mCreationFile (IN_SOURCE_FILE),
  mCreationLine (IN_SOURCE_LINE),
#endif
mObjectIndex (gCreationIndex),
mPtrToPreviousObject (NULL),
mPtrToNextObject (NULL),
mRetainCount (1) {
  gCreationIndex ++ ;
//--- Enter current object in instance list
  mPtrToNextObject = NULL ;
  if (gLastObject == NULL) {
    gFirstObject = this ;
    mPtrToPreviousObject = NULL ;
  }else{
    gLastObject->mPtrToNextObject = this ;
    mPtrToPreviousObject = gLastObject ;
  }
  gLastObject = this ;
//--- Increment object count
  gObjectCurrentCount ++ ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_SharedObject::~ C_SharedObject (void) {
//--- Remove object from instance list
  C_SharedObject * previousObject = mPtrToPreviousObject ;
  C_SharedObject * nextObject = mPtrToNextObject ;
  if (previousObject == NULL) {
    gFirstObject = nextObject ;
  }else{
    previousObject->mPtrToNextObject = nextObject ;
  }
  if (nextObject == NULL) {
    gLastObject = previousObject ;
  }else{
    nextObject->mPtrToPreviousObject = previousObject ;
  }
//--- Decrement object count
  gObjectCurrentCount -- ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_SharedObject::retain (const C_SharedObject * inObject COMMA_LOCATION_ARGS) {
  if (inObject != NULL) {
    macroValidSharedObjectThere (inObject, C_SharedObject) ;
    inObject->mRetainCount ++ ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_SharedObject::release (const C_SharedObject * inObject COMMA_LOCATION_ARGS) {
  if (inObject != NULL) {
    macroValidSharedObjectThere (inObject, C_SharedObject) ;
    MF_AssertThere (inObject->mRetainCount > 0, "mRetainCount should be > 0)", 0, 0) ;
    inObject->mRetainCount -- ;
    if (inObject->mRetainCount == 0) {
      macroMyDelete (inObject) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_SharedObject::retainRelease (const C_SharedObject * inObjectToRetain,
                                    const C_SharedObject * inObjectToRelease
                                    COMMA_LOCATION_ARGS) {
  retain (inObjectToRetain COMMA_THERE) ;
  release (inObjectToRelease COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Collect unused Objects
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void C_SharedObject::checkAllObjectsHaveBeenReleased (void) {
    if (gObjectCurrentCount != 0) {
      co << "Warning: "
         << cStringWithUnsigned (gObjectCurrentCount)
         << " object"
         << ((gObjectCurrentCount > 1) ? "s have" : " has")
         << " not been released:\n";
      C_SharedObject * p = gFirstObject ;
      while (p != NULL) {
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

//---------------------------------------------------------------------------------------------------------------------*
