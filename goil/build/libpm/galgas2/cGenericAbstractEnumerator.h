//----------------------------------------------------------------------------------------------------------------------
//
//  cGenericAbstractEnumerator: base class for enumerating GALGAS enumerable objects             
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2010, ..., 2010 Pierre Molinaro.
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

#include "galgas2/capCollectionElementArray.h"

//----------------------------------------------------------------------------------------------------------------------

class cGenericAbstractEnumerator {
//--- Private data members
  protected: capCollectionElementArray mEnumerationArray ;
  private: uint32_t mIndex ;
  public: const typeEnumerationOrder mOrder ;

//--- Constructor
  protected: inline cGenericAbstractEnumerator (const typeEnumerationOrder inOrder) :
  mEnumerationArray (),
  mIndex (0),
  mOrder (inOrder) {
  }

//--- Virtual destructor
  protected: virtual ~ cGenericAbstractEnumerator (void) ;

//--- No copy
  private: cGenericAbstractEnumerator (const cGenericAbstractEnumerator &) ;
  private: cGenericAbstractEnumerator & operator = (const cGenericAbstractEnumerator &) ;

//--- 
  public: inline bool hasCurrentObject (void) const { return mIndex < mEnumerationArray.count () ; }
  public: inline bool hasNextObject (void) const { return (mIndex + 1) < mEnumerationArray.count () ; }
  public: inline void gotoNextObject (void) { mIndex ++ ; }
  public: inline void rewind (void) { mIndex = 0 ; }
  public: inline uint32_t index (void) const { return mIndex ; } // For Sara compatibility
  public: inline void gotoIndex (const uint32_t inIndex) { mIndex = inIndex ; } // For Sara compatibility
  protected: const cCollectionElement * currentObjectPtr (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
