//---------------------------------------------------------------------------*
//                                                                           *
//  capCollectionElementArray                                                *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2010, ..., 2010 Pierre Molinaro.                           *
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

#ifndef CAP_COLLECTION_OBJECT_ARRAY_CLASS_DEFINED
#define CAP_COLLECTION_OBJECT_ARRAY_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "capCollectionElement.h"

//---------------------------------------------------------------------------*

class capCollectionElementArray {
//--- Default constructor
  public : capCollectionElementArray (void) ;

//--- Default constructor
  public : capCollectionElementArray (const PMUInt32 inCapacity) ;

//--- Virtual destructor
  public : virtual ~ capCollectionElementArray (void) ;

//--- Handle copy
  public : capCollectionElementArray (const capCollectionElementArray & inSource) ;
  public : capCollectionElementArray & operator = (const capCollectionElementArray & inSource) ;

//--- Set capacity
  public : void setCapacity (const PMUInt32 inNewCapacity) ;

//--- Add Object (at index mCount, the end of array)
//    Array should be allocated (with setCapacity)
//    Added object should not be NULL
  public : void addObject (const capCollectionElement & inObject) ;

//--- Replace Object
//    Argument object should not be NULL
  public : void replaceObjectAtIndex (const capCollectionElement & inObject,
                                      const PMUInt32 inIndex
                                      COMMA_LOCATION_ARGS) ;

//--- Get object
  #ifndef DO_NOT_GENERATE_CHECKINGS 
    public : capCollectionElement objectAtIndex (const PMUInt32 inIndex COMMA_LOCATION_ARGS) const ;
  #else
    public : inline capCollectionElement objectAtIndex (const PMUInt32 inIndex) const {
      return mArray [inIndex] ;
    }
  #endif

//--- Get object pointer for writing (perform implicitly an "insulate" action)
  public : cCollectionElement * pointerAtIndex (const PMUInt32 inIndex
                                                COMMA_LOCATION_ARGS) ;

//--- Get object pointer for reading
  public : const cCollectionElement * pointerAtIndexForReadAccess (const PMUInt32 inIndex
                                                                   COMMA_LOCATION_ARGS) const ;

//--- Get count
  public : inline PMUInt32 count (void) const { return mCount ; }

//--- Remove first objects (at index 0)
  public : void removeFirstObject (void) ;

//--- Remove last object (at index mCount - 1)
  public : void removeLastObject (void) ;

//--- Prepend object (insert them from index 0)
  public : void predendObject (const capCollectionElement & inObject) ;

//--- Remove all objects (without changing capacity)
  public : void removeAllObjects (void) ;

//--- Compare
  public : typeComparisonResult compareCollectionElementArray (const capCollectionElementArray & inOperand) const ;

//--- Attributes
  private : capCollectionElement * mArray ;
  private : PMUInt32 mCapacity ;
  private : PMUInt32 mCount ;
} ;

//---------------------------------------------------------------------------*

#endif
