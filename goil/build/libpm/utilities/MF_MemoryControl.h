//--------------------------------------------------------------------------------------------------
//
//  Declaration of macros and routines for handling dynamic allocation checking.
//
//  This file is part of libpm library
//
//  Copyright (C) 1994, ..., 2024 Pierre Molinaro.
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

#include "macroAssert.h"
#include "cpp-allocation.h"

//--------------------------------------------------------------------------------------------------

#include <stdlib.h>

//--------------------------------------------------------------------------------------------------
//
//         User macros for allocation
//
//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyNew(inPointer,instanciation) { \
    macroCheckPointerIsNull (inPointer) ; \
    prologueForNew () ; \
    inPointer = new instanciation ; \
    registerPointer (inPointer COMMA_HERE) ; \
  }
#else
  #define macroMyNew(inPointer,instanciation) { inPointer = new instanciation ; }
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyNewArray(inPointer,type,size) { \
    macroCheckPointerIsNull (inPointer) ; \
    prologueForNew () ; \
    inPointer = new type [size] ; \
    registerArray (inPointer COMMA_HERE) ; \
  }
#else
  #define macroMyNewArray(inPointer,type,size) { inPointer = new type [size] ; }
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyNewPODArray(inPointer,type,size) { \
    macroCheckPointerIsNull (inPointer) ; \
    inPointer = (type *) allocAndRegisterPODArray ((size) * sizeof (type) COMMA_HERE) ; \
  }
#else
  #define macroMyNewPODArray(inPointer,type,size) { inPointer = (type *) malloc ((size) * sizeof (type)) ; }
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyReallocPODArray(inPointer,type,size) { \
    macroValidPointer (inPointer) ; \
    inPointer = (type *) reallocAndRegisterPODArray (inPointer, (size) * sizeof (type) COMMA_HERE) ; \
  }
#else
  #define macroMyReallocPODArray(inPointer,type,size) { \
    inPointer = (type *) realloc (inPointer, (size) * sizeof (type)) ; \
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyNewThere(inPointer,instanciation) { \
    macroCheckPointerIsNullThere (inPointer) ; \
    prologueForNew () ; \
    inPointer = new instanciation ; \
    registerPointer (inPointer COMMA_THERE) ; \
  }
#else
  #define macroMyNewThere(inPointer,instanciation) { inPointer = new instanciation ; }
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyNewPODArrayThere(inPointer,type,size) { \
    macroValidPointerThere (inPointer) ; \
    inPointer = (type *) allocAndRegisterPODArray ((size) * sizeof (type) COMMA_THERE) ; \
  }
#else
  #define macroMyNewPODArrayThere(inPointer,type,size) { \
    inPointer = (type *) malloc ((size) * sizeof (type)) ; \
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyReallocPODArrayThere(inPointer,type,size) { \
    inPointer = (type *) reallocAndRegisterPODArray (inPointer, (size) * sizeof (type) COMMA_THERE) ; \
  }
#else
  #define macroMyReallocPODArrayThere(inPointer,type,size) { \
    inPointer = (type *) realloc (inPointer, (size) * sizeof (type)) ; \
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyNewArrayThere(inPointer,type,size) { \
    macroCheckPointerIsNullThere (inPointer) ; \
    prologueForNew () ; \
    inPointer = new type [size] ; \
    registerArray (inPointer COMMA_THERE) ; \
  }
#else
  #define macroMyNewArrayThere(inPointer,type,size) { \
    inPointer = new type [size] ; \
  }
#endif

//--------------------------------------------------------------------------------------------------
//
//         User macros for deallocation
//
//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyDelete(inPointer) { \
    routineFreePointer (inPointer COMMA_HERE) ; \
    delete (inPointer) ; inPointer = nullptr ; \
  }
#else
  #define macroMyDelete(inPointer) { \
    delete (inPointer) ; inPointer = nullptr ; \
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyDeletePODArray(inPointer) { \
    routineFreePODArrayPointer (inPointer COMMA_HERE) ; inPointer = nullptr ; \
  }
#else
  #define macroMyDeletePODArray(inPointer) { \
    free (inPointer) ; inPointer = nullptr ; \
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyDeleteArray(inPointer) { \
    routineFreeArrayPointer (inPointer COMMA_HERE) ; \
    delete [] (inPointer) ; inPointer = nullptr ; \
  }
#else
  #define macroMyDeleteArray(inPointer) { \
    delete [] (inPointer) ; inPointer = nullptr ; \
  }
#endif

//--------------------------------------------------------------------------------------------------
//
//         Assertion macros for checking pointers
//
//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroValidPointer(inPointer) routineValidPointer (inPointer COMMA_HERE)
#else
  #define macroValidPointer(inPointer)
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroValidPointerThere(inPointer) routineValidPointer (inPointer COMMA_THERE)
#else
  #define macroValidPointerThere(inPointer)
#endif

//--------------------------------------------------------------------------------------------------
//         Assertion for checking if a pointer is NULL
//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroCheckPointerIsNull(inPointer) routineCheckPointerIsNull (inPointer COMMA_HERE)
#else
  #define macroCheckPointerIsNull(inPointer)
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroCheckPointerIsNullThere(inPointer) routineCheckPointerIsNull (inPointer COMMA_THERE)
#else
  #define macroCheckPointerIsNullThere(inPointer)
#endif

//--------------------------------------------------------------------------------------------------
//         Assertion for checking if a pointer is not NULL
//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroCheckPointerIsNotNull(inPointer) routineCheckPointerIsNotNull (inPointer COMMA_HERE)
#else
  #define macroCheckPointerIsNotNull(inPointer)
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroCheckPointerIsNotNullThere(inPointer) routineCheckPointerIsNotNull (inPointer COMMA_THERE)
#else
  #define macroCheckPointerIsNotNullThere(inPointer)
#endif

//--------------------------------------------------------------------------------------------------
//
//         Routine to call for displaying currently allocated pointers
//
//--------------------------------------------------------------------------------------------------

void displayAllocatedBlocksInfo (void) ;

//--------------------------------------------------------------------------------------------------
//
//         Internal routines (do not call them directly)
//
//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void registerPointer (const void * inPointer COMMA_LOCATION_ARGS) ;
  void * allocAndRegisterPODArray (const size_t inSize COMMA_LOCATION_ARGS) ;
  void registerArray (const void * inPointer COMMA_LOCATION_ARGS) ;
  void routineValidPointer (const void * inPointer COMMA_LOCATION_ARGS) ;
  void routineCheckPointerIsNull (const void * inPointer COMMA_LOCATION_ARGS) ;
  void routineCheckPointerIsNotNull (const void * inPointer COMMA_LOCATION_ARGS) ;
  void routineFreePointer (const void * inPointer COMMA_LOCATION_ARGS) ;
  void routineFreePODArrayPointer (void * inPointer COMMA_LOCATION_ARGS) ;
  void routineFreeArrayPointer (const void * inPointer COMMA_LOCATION_ARGS) ;
  void * reallocAndRegisterPODArray (void * inPointer,
                                     const size_t inSize
                                     COMMA_LOCATION_ARGS) ;
#endif

//--------------------------------------------------------------------------------------------------
