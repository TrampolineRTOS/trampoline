//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  GALGAS_enumerable : Base class for GALGAS enumerable object                                                        *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2010, ..., 2010 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#pragma once

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "utilities/C_SharedObject.h"
#include "galgas2/typeComparisonResult.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class C_String ;
class cCollectionElement ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class capCollectionElement {
//--- Private pointer
  private : cCollectionElement * mPtr ;

//--- Default constructor
  public : capCollectionElement (void) ;

//--- Destructor
  public : ~ capCollectionElement (void) ;

//--- Handle copy
  public : capCollectionElement (const capCollectionElement & inSource) ;
  public : capCollectionElement & operator = (const capCollectionElement & inSource) ;

//--- set pointer
  public : void setPointer (cCollectionElement * inObjectPointer) ;

//--- Method that checks that all attributes are valid
  public : bool isValid (void) const ;

//--- Method that ensures that pointer object is unique
  public : void insulate (void) ;

//--- Method that release object
  public : void drop (void) ;

//--- Get pointer (for temporary use)
  public : inline cCollectionElement * ptr (void) { return mPtr ; }
  public : inline const cCollectionElement * ptr (void) const { return mPtr ; }

//--- Method for comparing elements
  public : typeComparisonResult compare (const capCollectionElement & inOperand) const ;

//--- Method that returns a copy of current object
  public : capCollectionElement copy (void) ;

//--- Description
 public : void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
