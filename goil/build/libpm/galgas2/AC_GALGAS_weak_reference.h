//--------------------------------------------------------------------------------------------------
//
//  AC_GALGAS_weak_reference : base class for reference class objects
//
//  This file is part of libpm library
//
//  Copyright (C) 2021, ..., 2021 Pierre Molinaro.
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
//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#include "AC_GALGAS_root.h"

//--------------------------------------------------------------------------------------------------

class String ;
class C_galgas_type_descriptor ;
class AC_GALGAS_reference_class ;
class cPtr_weakReference_proxy ;
class acStrongPtr_class ;

//--------------------------------------------------------------------------------------------------

class AC_GALGAS_weak_reference : public AC_GALGAS_root { // AC_GALGAS_weak_reference est une classe abstraite
//--- Properties
  protected: cPtr_weakReference_proxy * mProxyPtr ;
  public: acStrongPtr_class * ptr (void) const ;

//--- Default constructor
  protected: AC_GALGAS_weak_reference (void) ;

//--- Handle copy
  protected: AC_GALGAS_weak_reference (const AC_GALGAS_weak_reference & inSource) ;
  protected: AC_GALGAS_weak_reference & operator = (const AC_GALGAS_weak_reference & inSource) ;

//--- Constructor from strong reference
  protected: AC_GALGAS_weak_reference (const AC_GALGAS_reference_class & inSource) ;
  private: AC_GALGAS_weak_reference & operator = (const AC_GALGAS_reference_class &) = delete ;

//--- Destructor
  protected: virtual ~ AC_GALGAS_weak_reference (void) ;

//--- Is valid
  public: virtual bool isValid (void) const { return nullptr != mProxyPtr ; }

//--- Drop
  public: virtual void drop (void) ;

//--- Dynamic Type Descriptor
  public: virtual const C_galgas_type_descriptor * dynamicTypeDescriptor (void) const ;

  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
