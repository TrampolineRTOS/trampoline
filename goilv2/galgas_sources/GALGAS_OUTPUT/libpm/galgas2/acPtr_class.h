//---------------------------------------------------------------------------*
//                                                                           *
//  acPtr_class : Base class for GALGAS class                                *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2008, ..., 2011 Pierre Molinaro.                           *
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

#ifndef C_PTR_CLASS_DEFINED
#define C_PTR_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/C_SharedObject.h"
#include "galgas2/typeComparisonResult.h"

//---------------------------------------------------------------------------*

class C_String ;
class C_galgas_type_descriptor ;

//---------------------------------------------------------------------------*

class acPtr_class : public C_SharedObject {
  public : acPtr_class (LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;
} ;

//---------------------------------------------------------------------------*

#endif
