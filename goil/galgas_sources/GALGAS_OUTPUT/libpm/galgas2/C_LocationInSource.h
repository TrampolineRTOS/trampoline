//---------------------------------------------------------------------------*
//                                                                           *
//  'C_LocationInSource'                                                     *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1996, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
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

#ifndef GALGAS_LOCATION_IN_SOURCE_CLASS_DEFINED
#define GALGAS_LOCATION_IN_SOURCE_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/M_machine.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                 Class for referencing a location in source text           *
//                                                                           *
//---------------------------------------------------------------------------*

class C_LocationInSource {
  public : PMSInt32 mIndex ;
  public : PMSInt32 mLineNumber ;
  public : PMSInt32 mColumnNumber ;
  
  public : C_LocationInSource (void) ;
  public : C_LocationInSource (const PMSInt32 inIndex, const PMSInt32 inLine, const PMSInt32 inColumn) ;
} ;

//---------------------------------------------------------------------------*

#endif
