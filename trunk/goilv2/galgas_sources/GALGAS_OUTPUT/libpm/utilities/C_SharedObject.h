//---------------------------------------------------------------------------*
//                                                                           *
//  C_SharedObject : Base class for GALGAS object handling                   *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef C_OBJECT_CLASS_DEFINED
#define C_OBJECT_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/MF_Assert.h"

//---------------------------------------------------------------------------*

class C_SharedObject {
//--- Attributes for debug
  #ifndef DO_NOT_GENERATE_CHECKINGS
  //--- Creation location
    public : const char * const mCreationFile ;
    public : const int mCreationLine ;
  #endif

//--- Object index
  public : const PMUInt32 mObjectIndex ;

//--- Link between existing instances
  private : C_SharedObject * mPtrToPreviousObject ;
  private : C_SharedObject * mPtrToNextObject ;

//--- Retain count
  private : mutable PMSInt32 mRetainCount ;

  public : inline PMSInt32 retainCount (void) const { return mRetainCount ; }

  public : static void retain (const C_SharedObject * inObject COMMA_LOCATION_ARGS) ;

  public : static void release (const C_SharedObject * inObject COMMA_LOCATION_ARGS) ;

  public : static void retainRelease (const C_SharedObject * inObjectToRetain,
                                      const C_SharedObject * inObjectToRelease
                                      COMMA_LOCATION_ARGS) ;
  
//--- Default Constructor
  protected : C_SharedObject (LOCATION_ARGS) ;
  
//--- Virtual Destructor
  protected : virtual ~ C_SharedObject (void) ;
  
//--- No copy
  private : C_SharedObject (const C_SharedObject &) ;
  private : C_SharedObject & operator = (const C_SharedObject &) ;

//------------------------------------------------------------- Handling Pointer checking
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : static void checkAllObjectsHaveBeenReleased (void) ;
  #endif
} ;

//---------------------------------------------------------------------------*
//   macroValidSharedObject                                                  *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroValidSharedObject(OBJECT,TYPE) { \
    macroValidPointer (OBJECT) ; \
    if (dynamic_cast <TYPE *> (OBJECT) == NULL) { \
      MF_RunTimeError ("'"#OBJECT"' is not an instance of '"#TYPE" *'", 0, 0) ; \
    } \
  }
#else
  #define macroValidSharedObject(OBJECT,TYPE)
#endif

//---------------------------------------------------------------------------*
//   macroValidSharedObjectThere                                             *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroValidSharedObjectThere(OBJECT,TYPE) { \
    macroValidPointerThere (OBJECT) ; \
    if (dynamic_cast <TYPE *> (OBJECT) == NULL) { \
      MF_RunTimeErrorThere ("'"#OBJECT"' is not an instance of '"#TYPE" *'", 0, 0) ; \
    } \
  }
#else
  #define macroValidSharedObjectThere(OBJECT,TYPE)
#endif

//---------------------------------------------------------------------------*
//   macroNullOrValidSharedObject                                            *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroNullOrValidSharedObject(OBJECT,TYPE) \
    if (NULL != (OBJECT)) { \
      macroValidPointer (OBJECT) ; \
      MF_Assert (dynamic_cast <TYPE *> (OBJECT) != NULL, "'"#OBJECT"' is not an instance of '"#TYPE" *'", 0, 0) ; \
    }
#else
  #define macroNullOrValidSharedObject(OBJECT,TYPE)
#endif

//---------------------------------------------------------------------------*
//   macroNullOrValidSharedObjectThere                                       *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroNullOrValidSharedObjectThere(OBJECT,TYPE) \
    if (NULL != (OBJECT)) { \
      macroValidPointerThere (OBJECT) ; \
      MF_AssertThere (dynamic_cast <TYPE *> (OBJECT) != NULL, "'"#OBJECT"' is not an instance of '"#TYPE" *'", 0, 0) ; \
    }
#else
  #define macroNullOrValidSharedObjectThere(OBJECT,TYPE)
#endif

//---------------------------------------------------------------------------*
//   macroAssignSharedObject                                                 *
//---------------------------------------------------------------------------*

#define macroAssignSharedObject(TARGET_PTR,SOURCE_PTR) \
  { C_SharedObject::retainRelease (SOURCE_PTR, TARGET_PTR COMMA_HERE) ; TARGET_PTR = SOURCE_PTR ; }

//---------------------------------------------------------------------------*
//   macroAssignSharedObjectThere                                            *
//---------------------------------------------------------------------------*

#define macroAssignSharedObjectThere(TARGET_PTR,SOURCE_PTR) \
  { C_SharedObject::retainRelease (SOURCE_PTR, TARGET_PTR COMMA_THERE) ; TARGET_PTR = SOURCE_PTR ; }

//---------------------------------------------------------------------------*
//   macroDetachSharedObject                                                 *
//---------------------------------------------------------------------------*

#define macroDetachSharedObject(PTR) \
  { C_SharedObject::release (PTR COMMA_HERE) ; PTR = NULL ; }

//---------------------------------------------------------------------------*
//   macroDetachSharedObjectThere                                            *
//---------------------------------------------------------------------------*

#define macroDetachSharedObjectThere(PTR) \
  { C_SharedObject::release (PTR COMMA_THERE) ; PTR = NULL ; }

//---------------------------------------------------------------------------*
//   macroUniqueSharedObject                                                 *
//---------------------------------------------------------------------------*

#define macroUniqueSharedObject(PTR) \
  { MF_Assert ((PTR)->retainCount () == 1, "retainCount () == %ld != 1", (PTR)->retainCount (), 0) ; }

//---------------------------------------------------------------------------*
//   macroUniqueSharedObjectThere                                            *
//---------------------------------------------------------------------------*

#define macroUniqueSharedObjectThere(PTR) \
  { MF_AssertThere ((PTR)->retainCount () == 1, "retainCount () == %ld != 1", (PTR)->retainCount (), 0) ; }

//---------------------------------------------------------------------------*

#endif
