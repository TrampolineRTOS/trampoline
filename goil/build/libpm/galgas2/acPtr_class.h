//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  acPtr_class : Base class for GALGAS class                                                                          *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2011 Pierre Molinaro.                                                                     *
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
class C_galgas_type_descriptor ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class acPtr_class : public C_SharedObject {
  public : acPtr_class (LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const = 0 ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
