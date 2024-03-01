//
//  print.cpp
//  galgas-developer-v3
//
//  Created by Pierre Molinaro on 14/09/2023.
//
//--------------------------------------------------------------------------------------------------

#include "print.h"
#include <iostream>

//--------------------------------------------------------------------------------------------------

void routine_println_3F_ (const GALGAS_string inString,
                          Compiler * /* inCompiler */
                          COMMA_UNUSED_LOCATION_ARGS) {
  if (inString.isValid ()) {
    gCout.appendString (inString.stringValue ()) ;
    gCout.appendNewLine () ;
  }
}

//--------------------------------------------------------------------------------------------------

void routine_print_3F_ (const GALGAS_string inString,
                        Compiler * /* inCompiler */
                        COMMA_UNUSED_LOCATION_ARGS) {
  if (inString.isValid ()) {
    gCout.appendString (inString.stringValue ()) ;
  }
}

//--------------------------------------------------------------------------------------------------
