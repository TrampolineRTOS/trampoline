//-----------------------------------------------------------------------------*
//                                                                             *
//  GALGAS_enumerable : Base class for GALGAS enumerable object                *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2010, ..., 2010 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#ifndef C_SORTEDLIST_ELEMENT_CLASS_DEFINED
#define C_SORTEDLIST_ELEMENT_CLASS_DEFINED

//-----------------------------------------------------------------------------*

#include "galgas2/cCollectionElement.h"

//-----------------------------------------------------------------------------*

class cSortedListElement : public cCollectionElement {
//--- Default constructor
  public : cSortedListElement (LOCATION_ARGS) ;

//--- No copy
  private : cSortedListElement (const cSortedListElement &) ;
  private : cSortedListElement & operator = (const cSortedListElement &) ;

//--- Virtual method that comparing element for sorting
  public : virtual typeComparisonResult compareForSorting (const cSortedListElement * inOperand) const = 0 ;
} ;

//-----------------------------------------------------------------------------*

#endif
