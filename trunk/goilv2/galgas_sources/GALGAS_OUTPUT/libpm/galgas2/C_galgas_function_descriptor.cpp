//---------------------------------------------------------------------------*
//                                                                           *
//  GALGAS introspection classes                                             *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.                           *
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

#include "galgas2/C_galgas_function_descriptor.h"

//---------------------------------------------------------------------------*
//                                                                           *
//  GALGAS function descriptor (for function introspection)                  *
//                                                                           *
//---------------------------------------------------------------------------*

static C_galgas_function_descriptor * gGalgasFunctionListRoot = NULL ;

//---------------------------------------------------------------------------*

C_galgas_function_descriptor::
C_galgas_function_descriptor (const char * inFunctionName,
                              const functionPrototypeForIntrospection inFunctionPointer,
                              const C_galgas_type_descriptor * inResultType,
                              const PMUInt32 inParameterCount,
                              const C_galgas_type_descriptor * * inParameterTypeList) :
mNextFunction (gGalgasFunctionListRoot),
mFunctionName (inFunctionName),
mFunctionPointer (inFunctionPointer),
mResultType (inResultType),
mParameterCount (inParameterCount),
mFormalParameterTypeList (inParameterTypeList) {
  gGalgasFunctionListRoot = this ;
}

//---------------------------------------------------------------------------*

C_galgas_function_descriptor * C_galgas_function_descriptor::functionListRoot (void) {
  return gGalgasFunctionListRoot ;
} 

//---------------------------------------------------------------------------*
