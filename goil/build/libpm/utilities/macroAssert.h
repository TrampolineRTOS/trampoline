//--------------------------------------------------------------------------------------------------
//
//  Definition of 'macroAssert' and related routine prototypes                                     
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1997, ..., 2023 Pierre Molinaro.
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

#include "M_machine.h"
#include "M_SourceLocation.h"

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void runtime_error_routine (const char * const inMessage,
                              const int64_t inParameter1,
                              const int64_t inParameter2
                              COMMA_LOCATION_ARGS) __attribute__ ((__noreturn__)) ;
#endif

//--------------------------------------------------------------------------------------------------
//
//            Macro 'macroAssert'  definition                                                      
//
//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroAssert(exp,message,par1,par2) \
    if (! (exp)) { \
      runtime_error_routine (message, par1, par2 COMMA_HERE) ; \
    }
  #define macroAssertThere(exp,message,par1,par2) \
    if (! (exp)) { \
      runtime_error_routine (message, par1, par2 COMMA_THERE) ; \
    }
#else
  #define macroAssert(exp,message,par1,par2) {}
  #define macroAssertThere(exp,message,par1,par2) {}
#endif

//--------------------------------------------------------------------------------------------------
