//---------------------------------------------------------------------------*
//                                                                           *
//  Definition of the general purpose inf template routine                   *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1997 Pierre Molinaro.                                      *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes                                            *
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

#ifndef TEMPLATE_INF_ROUTINE_DEFINED
#define TEMPLATE_INF_ROUTINE_DEFINED

//---------------------------------------------------------------------*

template <class T>
inline T TF_inf (const T inOperand1, const T inOperand2) {
  return (inOperand1 < inOperand2) ? inOperand1 : inOperand2 ;
}

//---------------------------------------------------------------------*

#endif
