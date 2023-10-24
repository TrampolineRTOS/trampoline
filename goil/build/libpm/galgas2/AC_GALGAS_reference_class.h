//----------------------------------------------------------------------------------------------------------------------
//
//  AC_GALGAS_reference_class : base class for reference class objects
//
//  This file is part of libpm library
//
//  Copyright (C) 2021, ..., 2023 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/AC_GALGAS_root.h"

//----------------------------------------------------------------------------------------------------------------------

class C_String ;
class C_galgas_type_descriptor ;
class acStrongPtr_class ;

//----------------------------------------------------------------------------------------------------------------------

class AC_GALGAS_reference_class : public AC_GALGAS_root { // AC_GALGAS_reference_class est une classe abstraite
//--- Properties
  protected: acStrongPtr_class * mObjectPtr ;
  public: inline const acStrongPtr_class * ptr (void) const { return mObjectPtr ; }

//--- Default constructor
  protected: AC_GALGAS_reference_class (void) ;
  
//--- Constructor from pointer
  protected: AC_GALGAS_reference_class (const acStrongPtr_class * inPointer) ;
  
//--- Destructor
  protected: virtual ~ AC_GALGAS_reference_class (void) ;

//--- Is valid
  public: virtual bool isValid (void) const { return NULL != mObjectPtr ; }
  
//--- Drop
  public: virtual void drop (void) ;
  
//--- Handle copy
  protected: AC_GALGAS_reference_class (const AC_GALGAS_reference_class & inSource) ;
  protected: AC_GALGAS_reference_class & operator = (const AC_GALGAS_reference_class & inSource) ;
  
//--- Dynamic Type Descriptor
  public: virtual const C_galgas_type_descriptor * dynamicTypeDescriptor (void) const ;

  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const ;

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (const char * inPropertyName) const ;
  #endif
} ;

//----------------------------------------------------------------------------------------------------------------------
