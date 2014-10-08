//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS introspection classes                                               *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2009 Pierre Molinaro.                             *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes                                          *
//  ECN, École Centrale de Nantes (France)                                                                             *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it                                            *
//  under the terms of the GNU Lesser General Public License as published                                              *
//  by the Free Software Foundation; either version 2 of the License, or                                               *
//  (at your option) any later version.                                                                                *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT                                             *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                              *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                                           *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef GALGAS_CLASS_INSPECTOR_DEFINED
#define GALGAS_CLASS_INSPECTOR_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include <typeinfo>

//---------------------------------------------------------------------------------------------------------------------*

class C_galgas_class_inspector {
//--- Attributes
  public : const C_galgas_class_inspector * mNextClass ;
  public : const std::type_info * mClassID ;
  public : const std::type_info * mSuperClassID ;
  public : const char * mClassMessage ;

//--- Root of class list
  public : static C_galgas_class_inspector * root (void) ;

//--- Constructor
  public : C_galgas_class_inspector (const std::type_info * inClassID,
                                     const std::type_info * inSuperClassID,
                                     const char * inClassMessage) ;

//--- No copy
  private : C_galgas_class_inspector (const C_galgas_class_inspector &) ;
  private : C_galgas_class_inspector & operator = (const C_galgas_class_inspector &) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
