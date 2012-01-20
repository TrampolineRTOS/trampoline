//---------------------------------------------------------------------------*
//                                                                           *
//  cGenericAbstractEnumerator: base class for enumerating GALGAS enumerable objects*
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

#ifndef AC_GALGAS_ENUMERATOR_CLASS_DEFINED
#define AC_GALGAS_ENUMERATOR_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "capCollectionElementArray.h"

//---------------------------------------------------------------------------*

class cGenericAbstractEnumerator {
//--- Private data members
  protected : capCollectionElementArray mEnumerationArray ;
  private : PMUInt32 mIndex ;

//--- Constructor
  protected : cGenericAbstractEnumerator (void) ;

//--- Virtual destructor
  protected : virtual ~ cGenericAbstractEnumerator (void) ;

//--- No copy
  private : cGenericAbstractEnumerator (const cGenericAbstractEnumerator &) ;
  private : cGenericAbstractEnumerator & operator = (const cGenericAbstractEnumerator &) ;

//--- 
  public : inline bool hasCurrentObject (void) const { return mIndex < mEnumerationArray.count () ; }
  public : inline bool hasNextObject (void) const { return (mIndex + 1) < mEnumerationArray.count () ; }
  public : inline void gotoNextObject (void) { mIndex ++ ; }
  public : inline void rewind (void) { mIndex = 0 ; }
  public : inline PMUInt32 index (void) const { return mIndex ; }
  public : inline void gotoIndex (const PMUInt32 inIndex) { mIndex = inIndex ; }
  protected : const cCollectionElement * currentObjectPtr (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*

#endif
