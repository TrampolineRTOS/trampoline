//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  acPtr_class : Base class for GALGAS class                                                                          *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2010 Pierre Molinaro.                                                                     *
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
//----------------------------------------------------------------------------------------------------------------------

#ifndef C_PTR_OBJECT_DEFINED
#define C_PTR_OBJECT_DEFINED

//----------------------------------------------------------------------------------------------------------------------

#include "utilities/C_SharedObject.h"

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_type ;
class AC_GALGAS_root ;

//----------------------------------------------------------------------------------------------------------------------

class cPtr_object : public C_SharedObject {
//--- Default Constructor
  public : cPtr_object (LOCATION_ARGS) ;

//--- Constructor with embedded object
  public : cPtr_object (AC_GALGAS_root * inObjectPointer
                        COMMA_LOCATION_ARGS) ;

//--- Destructor
  public : virtual ~cPtr_object (void) ;

//--- No Copy
  private : cPtr_object (const cPtr_object &) ;
  private : cPtr_object & operator = (const cPtr_object &) ;

//--- Private attribute
  private : AC_GALGAS_root * mEmbeddedObjectPtr ;
  public : const AC_GALGAS_root * embeddedObjectPtr (void) const { return mEmbeddedObjectPtr ; }

//--- Accessing embedded object types
  public : GALGAS_type objectStaticType (void) const ;
  public : GALGAS_type objectDynamicType (void) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

#endif
