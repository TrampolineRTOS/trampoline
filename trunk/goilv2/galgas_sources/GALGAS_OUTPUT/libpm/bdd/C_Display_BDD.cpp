//-----------------------------------------------------------------------------*
//                                                                             *
//     C++ class for displaying BDDs (use with the BDD package 'C_BDD.cpp')  *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2000, ..., 2005 Pierre Molinaro.                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
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

#include "bdd/C_Display_BDD.h"
#include "streams/AC_OutputStream.h"
#include "utilities/MF_MemoryControl.h"

//---------------------------------------------------------------------*

#include <string.h>

//---------------------------------------------------------------------*

C_Display_BDD::C_Display_BDD (const PMUInt32 nombreChaines) :
aNombreChaines (0),
aTab (),
aDimensions (NULL) {
  allouer (nombreChaines) ;
}

//---------------------------------------------------------------------*

C_Display_BDD::~C_Display_BDD (void) {
  vider () ;
}

//---------------------------------------------------------------------*

void C_Display_BDD::vider (void) {
  aTab.free () ;
  macroMyDeleteArray (aDimensions) ;
  aNombreChaines = 0 ;
}

//---------------------------------------------------------------------*

void C_Display_BDD::allouer (const PMUInt32 nombreChaines) {
  vider () ;
  aTab.makeRoom ((PMSInt32) nombreChaines) ;
  macroMyDeleteArray (aDimensions) ;
  macroMyNewArray (aDimensions, PMUInt32, nombreChaines) ;
  if (aDimensions != NULL) {
    aNombreChaines = nombreChaines ;
  }else{
    aTab.free () ;
    macroMyDeleteArray (aDimensions) ;
  }
}

//---------------------------------------------------------------------*

void C_Display_BDD::defineVariableName (const PMUInt32 indice,
                                        const C_String & chaine,
                                        const PMUInt32 dimensions) {
  if (indice < aNombreChaines) {
    aDimensions [indice] = dimensions ;
  //  aTab ((PMSInt32) indice COMMA_HERE) = chaine ;
    aTab.addObject (chaine) ;
  }
}

//---------------------------------------------------------------------*

PMSInt32 C_Display_BDD::longueur (const PMUInt32 indice) const  {
  return aTab ((PMSInt32) indice COMMA_HERE).length () ;
}

//---------------------------------------------------------------------*

PMUInt32 C_Display_BDD::
obtenirDimension (const PMUInt32 indice) const {
  PMUInt32 dim = 1 ;
  if (indice < aNombreChaines) {
    dim = aDimensions [indice] ;
  }
  return dim ;
}

//---------------------------------------------------------------------*

void C_Display_BDD::ecrire (const PMUInt32 indice,
                            AC_OutputStream & inStream) const {
  inStream << aTab ((PMSInt32) indice COMMA_HERE) ;
}

//---------------------------------------------------------------------*
