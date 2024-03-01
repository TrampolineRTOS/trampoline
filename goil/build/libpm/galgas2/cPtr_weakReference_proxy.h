//--------------------------------------------------------------------------------------------------
//
//  cPtr_weakReference_proxy : Base class for reference class class
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
//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#include "acPtr_class.h"

//--------------------------------------------------------------------------------------------------

class acStrongPtr_class ;

//--------------------------------------------------------------------------------------------------

class cPtr_weakReference_proxy final : public acPtr_class {
//--- Public default constructor
  public: cPtr_weakReference_proxy (LOCATION_ARGS) ;

//--- Destructor
  public: virtual ~ cPtr_weakReference_proxy (void) ;

//--- Private property
  private: acStrongPtr_class * mStrongObjectPtr ;
  public: acStrongPtr_class * strongObject (void) const { return mStrongObjectPtr ; }

//--- Virtual methods from acPtr_class
  public: virtual void description (String &, const int32_t) const {} // Never invoked

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class *) const { // Never invoked
    return typeComparisonResult::kOperandNotValid ;
  }

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- No Copy
  private: cPtr_weakReference_proxy (const cPtr_weakReference_proxy &) = delete ;
  private: cPtr_weakReference_proxy & operator = (const cPtr_weakReference_proxy &) = delete ;

//--- Friend
  friend class acStrongPtr_class ;
} ;

//--------------------------------------------------------------------------------------------------
