//----------------------------------------------------------------------------------------------------------------------
//
//  acStrongPtr_class : Base class for reference class class
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
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/acPtr_class.h"

//----------------------------------------------------------------------------------------------------------------------

class cPtr_weakReference_proxy ;

//----------------------------------------------------------------------------------------------------------------------

class acStrongPtr_class : public acPtr_class {
//--- Default constructor
  public: acStrongPtr_class (LOCATION_ARGS) ;

//--- Destructor
  public: virtual ~ acStrongPtr_class (void) ;

//--- Private property
  private: cPtr_weakReference_proxy * mProxyPtr ;

//--- Get proxy
  public: cPtr_weakReference_proxy * getProxy (void) ;

//--- No Copy
  private: acStrongPtr_class (const acStrongPtr_class &) = delete ;
  private: acStrongPtr_class & operator = (const acStrongPtr_class &) = delete ;

//--- Friend
  friend class cPtr_weakReference_proxy ;
} ;

//----------------------------------------------------------------------------------------------------------------------
