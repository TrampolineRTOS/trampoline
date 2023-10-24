//----------------------------------------------------------------------------------------------------------------------
//
//  C_SharedObject : Base class for GALGAS object handling                                       
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2009, ..., 2014 Pierre Molinaro.
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
#include "utilities/MF_MemoryControl.h"

//----------------------------------------------------------------------------------------------------------------------

class C_SharedObject {
//--- Attributes for debug
  #ifndef DO_NOT_GENERATE_CHECKINGS
  //--- Creation location
    public: const char * const mCreationFile ;
    public: const int mCreationLine ;
  //--- Link between existing instances
    private: C_SharedObject * mPtrToPreviousObject ;
    private: C_SharedObject * mPtrToNextObject ;
  #endif

//--- Object index
  public: const uint32_t mObjectIndex ;

//--- Retain count
  private: mutable int32_t mRetainCount ;

  public: inline bool isUniquelyReferenced (void) { return mRetainCount == 1 ; }
  
  public: static void retain (const C_SharedObject * inObject COMMA_LOCATION_ARGS) ;

  public: static void release (const C_SharedObject * inObject COMMA_LOCATION_ARGS) ;

  public: static void retainRelease (const C_SharedObject * inObjectToRetain,
                                      const C_SharedObject * inObjectToRelease
                                      COMMA_LOCATION_ARGS) ;
  
//--- Default Constructor
  protected: C_SharedObject (LOCATION_ARGS) ;
  
//--- Virtual Destructor
  protected: virtual ~ C_SharedObject (void) ;
  
//--- No copy
  private: C_SharedObject (const C_SharedObject &) ;
  private: C_SharedObject & operator = (const C_SharedObject &) ;

//------------------------------------------------------------- Handling Pointer checking
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: static void checkAllObjectsHaveBeenReleased (void) ;
  #endif
} ;

//----------------------------------------------------------------------------------------------------------------------
//   macroValidSharedObject                                                                      
//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroValidSharedObject(OBJECT,TYPE) { \
    macroValidPointer (OBJECT) ; \
    if (dynamic_cast <const TYPE *> (OBJECT) == nullptr) { \
      MF_RunTimeError ("'"#OBJECT"' is not an instance of '"#TYPE" *'", 0, 0) ; \
    } \
  }
#else
  #define macroValidSharedObject(OBJECT,TYPE)
#endif

//----------------------------------------------------------------------------------------------------------------------
//   macroValidSharedObjectThere                                                                 
//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroValidSharedObjectThere(OBJECT,TYPE) { \
    macroValidPointerThere (OBJECT) ; \
    if (dynamic_cast <const TYPE *> (OBJECT) == nullptr) { \
      MF_RunTimeErrorThere ("'"#OBJECT"' is not an instance of '"#TYPE" *'", 0, 0) ; \
    } \
  }
#else
  #define macroValidSharedObjectThere(OBJECT,TYPE)
#endif

//----------------------------------------------------------------------------------------------------------------------
//   macroNullOrValidSharedObject                                                                
//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroNullOrValidSharedObject(OBJECT,TYPE) \
    if (nullptr != (OBJECT)) { \
      macroValidPointer (OBJECT) ; \
      MF_Assert (dynamic_cast <const TYPE *> (OBJECT) != nullptr, "'"#OBJECT"' is not an instance of '"#TYPE" *'", 0, 0) ; \
    }
#else
  #define macroNullOrValidSharedObject(OBJECT,TYPE)
#endif

//----------------------------------------------------------------------------------------------------------------------
//   macroNullOrValidSharedObjectThere                                                           
//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroNullOrValidSharedObjectThere(OBJECT,TYPE) \
    if (nullptr != (OBJECT)) { \
      macroValidPointerThere (OBJECT) ; \
      MF_AssertThere (dynamic_cast <const TYPE *> (OBJECT) != nullptr, "'"#OBJECT"' is not an instance of '"#TYPE" *'", 0, 0) ; \
    }
#else
  #define macroNullOrValidSharedObjectThere(OBJECT,TYPE)
#endif

//----------------------------------------------------------------------------------------------------------------------
//   macroAssignSharedObject                                                                     
//----------------------------------------------------------------------------------------------------------------------

#define macroAssignSharedObject(TARGET_PTR,SOURCE_PTR) \
  { C_SharedObject::retainRelease (SOURCE_PTR, TARGET_PTR COMMA_HERE) ; TARGET_PTR = SOURCE_PTR ; }

//----------------------------------------------------------------------------------------------------------------------
//   macroAssignSharedObjectThere                                                                
//----------------------------------------------------------------------------------------------------------------------

#define macroAssignSharedObjectThere(TARGET_PTR,SOURCE_PTR) \
  { C_SharedObject::retainRelease (SOURCE_PTR, TARGET_PTR COMMA_THERE) ; TARGET_PTR = SOURCE_PTR ; }

//----------------------------------------------------------------------------------------------------------------------
//   macroDetachSharedObject                                                                     
//----------------------------------------------------------------------------------------------------------------------

#define macroDetachSharedObject(PTR) \
  { C_SharedObject::release (PTR COMMA_HERE) ; PTR = nullptr ; }

//----------------------------------------------------------------------------------------------------------------------
//   macroDetachSharedObjectThere                                                                
//----------------------------------------------------------------------------------------------------------------------

#define macroDetachSharedObjectThere(PTR) \
  { C_SharedObject::release (PTR COMMA_THERE) ; PTR = nullptr ; }

//----------------------------------------------------------------------------------------------------------------------
//   macroUniqueSharedObject                                                                     
//----------------------------------------------------------------------------------------------------------------------

#define macroUniqueSharedObject(PTR) \
  { MF_Assert ((PTR)->isUniquelyReferenced (), "isUniquelyReferenced () is false", 0, 0) ; }

//----------------------------------------------------------------------------------------------------------------------
//   macroUniqueSharedObjectThere                                                                
//----------------------------------------------------------------------------------------------------------------------

#define macroUniqueSharedObjectThere(PTR) \
  { MF_AssertThere ((PTR)->isUniquelyReferenced (), "isUniquelyReferenced () is false", 0, 0) ; }

//----------------------------------------------------------------------------------------------------------------------
