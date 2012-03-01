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

#ifndef C_OBJECT_ARRAY_CLASS_DEFINED
#define C_OBJECT_ARRAY_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/C_SharedObject.h"

//---------------------------------------------------------------------------*

class GALGAS_object ;
class GALGAS_objectlist ;
class C_Compiler ;

//---------------------------------------------------------------------------*

class cObjectArray {
//--- Default constructor
  public : cObjectArray (const GALGAS_objectlist & inObjectList,
                         C_Compiler * inCompiler
                         COMMA_LOCATION_ARGS) ;

//--- Virtual destructor
  public : virtual ~ cObjectArray (void) ;

//--- No copy
  private : cObjectArray (const cObjectArray & inSource) ;
  private : cObjectArray & operator = (const cObjectArray & inSource) ;

//--- Object count
  public : inline PMUInt32 count (void) const { return mCount ; }

//--- Object at index
  public : GALGAS_object objectAtIndex (const PMUInt32 inIndex COMMA_LOCATION_ARGS) const ;

//--- Attributes
  private : GALGAS_object * mArray ;
  private : PMUInt32 mCount ;
} ;

//---------------------------------------------------------------------------*

#endif
