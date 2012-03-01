//---------------------------------------------------------------------------*
//                                                                           *
//  AC_GALGAS_root : root type for all GALGAS types (on debug mode only)     *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2010, ..., 2011 Pierre Molinaro.                           *
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

#ifndef GALGAS_ROOT_CLASS_DEFINED
#define GALGAS_ROOT_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/M_SourceLocation.h"

//---------------------------------------------------------------------------*

class GALGAS_object ;
class GALGAS_type ;
class GALGAS_string ;
class C_String ;
class C_galgas_type_descriptor ;

//---------------------------------------------------------------------------*
//   VIRTUAL_IN_DEBUG                                                        *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define VIRTUAL_IN_DEBUG virtual
#else
  #define VIRTUAL_IN_DEBUG
#endif

//---------------------------------------------------------------------------*
//   AC_GALGAS_root                                                          *
//---------------------------------------------------------------------------*

class AC_GALGAS_root {
//--- Default constructor
  public : inline AC_GALGAS_root (void) {}

//--- Destructor
  public : inline virtual ~ AC_GALGAS_root (void) {}
  
//--- Methods that every type should implement
  public : virtual bool isValid (void) const = 0 ;
  
  public : virtual void drop (void) = 0 ;

  public : virtual const C_galgas_type_descriptor * staticTypeDescriptor (void) const = 0 ;

  public : virtual const C_galgas_type_descriptor * dynamicTypeDescriptor (void) const ;

//--- Log instruction
  public : VIRTUAL_IN_DEBUG void log (const char * inMessage COMMA_LOCATION_ARGS) const ;

  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const = 0 ;

//--- Readers implemented in this class
  public : VIRTUAL_IN_DEBUG GALGAS_string reader_description (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_type reader_staticType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_type reader_dynamicType (LOCATION_ARGS) const ;

//--- "object" reader
  public : VIRTUAL_IN_DEBUG GALGAS_object reader_object (LOCATION_ARGS) const ;
  protected : virtual AC_GALGAS_root * clonedObject (void) const = 0 ;

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : virtual void checkIsValid (LOCATION_ARGS) const ;
  #endif
} ;

//---------------------------------------------------------------------------*

#endif
