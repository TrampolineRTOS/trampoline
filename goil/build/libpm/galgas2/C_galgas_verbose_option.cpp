//----------------------------------------------------------------------------------------
//
//  Built-in GALGAS Command Line Interface Options
//
//  This file is part of libpm library
//
//  Copyright (C) 2015, ..., 2023 Pierre Molinaro.
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
//----------------------------------------------------------------------------------------

#include "C_galgas_verbose_option.h"
#include "F_verbose_output.h"

//----------------------------------------------------------------------------------------

C_BoolCommandLineOption gOption_galgas_5F_builtin_5F_options_verbose_5F_output ("galgas_builtin_options",
                                                                                "verbose_output",
                                                                                'v',
                                                                                "verbose",
                                                                                "Verbose Output",
                                                                                false) ; // Not visible in GALGAS

//----------------------------------------------------------------------------------------

bool verboseOutput (void) {
  return gOption_galgas_5F_builtin_5F_options_verbose_5F_output.readProperty_value () ;
}

//----------------------------------------------------------------------------------------
