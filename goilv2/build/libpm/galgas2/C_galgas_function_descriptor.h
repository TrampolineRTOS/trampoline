//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS introspection classes                                                                                       *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef GALGAS_FUNCTION_DESCRIPTOR_CLASS_DEFINED
#define GALGAS_FUNCTION_DESCRIPTOR_CLASS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"

//---------------------------------------------------------------------------------------------------------------------*

class C_Compiler ;
class GALGAS_location ;
class GALGAS_object ;
class C_galgas_type_descriptor ;
class GALGAS_objectlist ;
class cObjectArray ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS function prototype (for function introspection)                                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef GALGAS_object (*functionPrototypeForIntrospection) (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & inErrorLocation
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS function descriptor (for function introspection)                                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class C_galgas_function_descriptor {
//--- Attributes
  public : const C_galgas_function_descriptor * mNextFunction ;
  public : const char * mFunctionName ;
  public : const functionPrototypeForIntrospection mFunctionPointer ;
  public : const C_galgas_type_descriptor * mResultType ;
  public : const uint32_t mParameterCount ;
  public : const C_galgas_type_descriptor * * mFormalParameterTypeList ;

//--- Constructor
  public : C_galgas_function_descriptor (const char * inFunctionName,
                                         const functionPrototypeForIntrospection inFunctionPointer,
                                         const C_galgas_type_descriptor * inResultType,
                                         const uint32_t inParameterCount,
                                         const C_galgas_type_descriptor * * inParameterTypeList) ;

//--- 
  public : static C_galgas_function_descriptor * functionListRoot (void) ;
  
//--- No copy
  private : C_galgas_function_descriptor (const C_galgas_function_descriptor &) ;
  private : C_galgas_function_descriptor & operator = (const C_galgas_function_descriptor &) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
