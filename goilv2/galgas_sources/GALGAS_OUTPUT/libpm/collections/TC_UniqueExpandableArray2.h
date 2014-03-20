//---------------------------------------------------------------------------*
//                                                                           *
//  Declaration and implementation of template class                         *
//                                                                           *
//  It implements a generic two dimensions expandable array.                 *
//                                                                           *
//  COPY OF ITS INSTANCES IS NOT ALLOWED.                                    *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2010, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                             *
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

#ifndef EXPANDABLE_ARRAY2_TEMPLATE_CLASS_DEFINED
#define EXPANDABLE_ARRAY2_TEMPLATE_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "collections/TC_UniqueArray2.h"

//---------------------------------------------------------------------------*

template <typename TYPE> class TC_UniqueExpandableArray2 : public TC_UniqueArray2 <TYPE> {
  protected : TYPE mDefaultValue ;

//--- Constructors
  public : TC_UniqueExpandableArray2 (const TYPE inDefaultValue) ;

//--- No copy
  private : TC_UniqueExpandableArray2 (TC_UniqueExpandableArray2 <TYPE> & inSource) ;
  private : TC_UniqueExpandableArray2 <TYPE> & operator = (TC_UniqueExpandableArray2 <TYPE> & inSource) ;

//--- Force entry
  public : void forceEntry (const PMSInt32 inRowIndex,
                            const PMSInt32 inColumnIndex,
                            const TYPE inValue
                            COMMA_LOCATION_ARGS) ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                         Implementation                                    *
//                                                                           *
//---------------------------------------------------------------------------*

template <typename TYPE>
TC_UniqueExpandableArray2 <TYPE>::TC_UniqueExpandableArray2 (const TYPE inDefaultValue) :
TC_UniqueArray2 <TYPE> (0, 0),
mDefaultValue (inDefaultValue) {
}

//---------------------------------------------------------------------------*

template <typename TYPE>
void TC_UniqueExpandableArray2 <TYPE>::forceEntry (const PMSInt32 inRowIndex,
                                                   const PMSInt32 inColumnIndex,
                                                   const TYPE inValue
                                                   COMMA_LOCATION_ARGS) {
  MF_AssertThere (inRowIndex >= 0, "row index (%ld) < 0", inRowIndex, 0) ;
  MF_AssertThere (inColumnIndex >= 0, "column index (%ld) < 0", inColumnIndex, 0) ;
  const bool resize = (inRowIndex >= this->mCurrentRowCount) || (inColumnIndex >= this->mCurrentColumnCount) ;
  if (resize) {
    const PMSInt32 newRowCount = (inRowIndex >= this->mCurrentRowCount) ? (inRowIndex + 1) : this->mCurrentRowCount ;
    const PMSInt32 newColumnCount = (inColumnIndex >= this->mCurrentColumnCount) ? (inColumnIndex + 1) : this->mCurrentColumnCount ;
    TYPE * newArray = NULL ;
    macroMyNewArray (newArray, TYPE, newRowCount * newColumnCount) ;
    for (PMSInt32 i=0 ; i<this->mCurrentRowCount ; i++) {
      for (PMSInt32 j=0 ; j<this->mCurrentColumnCount ; j++) {
        newArray [i * newColumnCount + j] = this->mArray [i * this->mCurrentColumnCount + j] ;
      }
      for (PMSInt32 j=this->mCurrentColumnCount ; j<newColumnCount ; j++) {
        newArray [i * newColumnCount + j] = this->mDefaultValue ;
      }
    }
    for (PMSInt32 i=this->mCurrentRowCount ; i<newRowCount ; i++) {
      for (PMSInt32 j=0 ; j<newColumnCount ; j++) {
        newArray [i * newColumnCount + j] = this->mDefaultValue ;
      }
    }
    macroMyDeleteArray (this->mArray) ;
    this->mArray = newArray ;
    this->mCurrentRowCount = newRowCount ;
    this->mCurrentColumnCount = newRowCount ;
  }
  this->mArray [inRowIndex * this->mCurrentColumnCount + inColumnIndex] = inValue ;
}

//---------------------------------------------------------------------------*

#endif
