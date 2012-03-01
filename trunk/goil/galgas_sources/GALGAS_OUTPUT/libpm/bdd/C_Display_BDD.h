//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for displaying BDDs (use with the BDD package 'C_BDD.cpp')  *
//                                                                           *
//  This file is part of libpm Libary                                        *
//                                                                           *
//  Copyright (C) 2000, ..., 2005 Pierre Molinaro.                           *
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
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public      *
//  License for more details.                                                *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef CLASS_DISPLAY_BDD_DEFINED
#define CLASS_DISPLAY_BDD_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/M_machine.h"
#include "collections/TC_UniqueArray.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------*

class AC_OutputStream ;

//---------------------------------------------------------------------------*

class C_Display_BDD {
//--- Attributs
  protected : PMUInt16 aNombreChaines ;
  protected : TC_UniqueArray <C_String> aTab ;
  protected : PMUInt16 * aDimensions ;
  
//--- Constructeur et destructeur
  public : C_Display_BDD (const PMUInt16 nombreChaines) ;
  public : virtual ~C_Display_BDD (void) ;

//--- Allocation (efface les chaines existantes)
  public : void vider (void) ;

//--- Est vide ?
  public : inline bool isFalse (void) const { return aNombreChaines == 0 ; }

//--- Nombre de chaines entrees ?
  public : PMUInt16 nombreEntrees (void) const { return aNombreChaines ; }

//--- Allocation (efface les chaines existantes)
  public : void allouer (const PMUInt16 nombreChaines) ;

//--- Definir une chaine
  public : void defineVariableName (const PMUInt32 indice,
                                    const C_String & chaine,
                                    const PMUInt16 dimensions) ;

//--- Obtenir la longueur d'une chaine
  public : PMSInt32 longueur (const PMUInt16 indice) const ;

//--- Obtenir la dimension d'une variable
  public : PMUInt16 obtenirDimension (const PMUInt16 indice) const ;

//--- Ecrire une chaine
  public : void ecrire (const PMUInt16 indice,
                        AC_OutputStream & inStream) const ;

//--- Interdire la duplication
  private : C_Display_BDD (C_Display_BDD &) ;
  private : C_Display_BDD & operator = (C_Display_BDD &) ;
} ;

//---------------------------------------------------------------------------*

#endif
