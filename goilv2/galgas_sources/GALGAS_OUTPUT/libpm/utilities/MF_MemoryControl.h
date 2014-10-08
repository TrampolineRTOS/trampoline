//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Declaration of macros and routines for handling dynamic allocation checking.                                       *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1994, ..., 2012 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybern��tique de Nantes                                         *
//  ECN, �cole Centrale de Nantes (France)                                                                             *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it                                            *
//  under the terms of the GNU Lesser General Public License as published                                              *
//  by the Free Software Foundation; either version 2 of the License, or                                               *
//  (at your option) any later version.                                                                                *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT                                             *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                              *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                                           *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef MEMORY_CONTROL_MACROS_AND_ROUTINES_DEFINED
#define MEMORY_CONTROL_MACROS_AND_ROUTINES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_Assert.h"
#include "utilities/M_Threads.h"

//---------------------------------------------------------------------------------------------------------------------*

#include <stdlib.h>

//---------------------------------------------------------------------------------------------------------------------*

macroDeclareExternMutex (gAllocationMutex)

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//         User macros for allocation                                                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS 
  #define macroMyNew(inPointer,instanciation) { \
    macroMutexLock (gAllocationMutex) ; \
    macroVoidPointer (inPointer) ; \
    prologueForNew () ; \
    inPointer = new instanciation ; \
    registerPointer (inPointer COMMA_HERE) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyNew(inPointer,instanciation) { \
    macroMutexLock (gAllocationMutex) ; \
    inPointer = new instanciation ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS 
  #define macroMyNewArray(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    macroVoidPointer (inPointer) ; \
    prologueForNew () ; \
    inPointer = new type [size] ; \
    registerArray (inPointer COMMA_HERE) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyNewPODArray(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    inPointer = (type *) malloc ((size) * sizeof (type)) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS 
  #define macroMyNewPODArray(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    macroVoidPointer (inPointer) ; \
    inPointer = (type *) allocAndRegisterPODArray ((size) * sizeof (type) COMMA_HERE) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyReallocPODArray(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    inPointer = (type *) realloc (inPointer, (size) * sizeof (type)) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS 
  #define macroMyReallocPODArray(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    inPointer = (type *) reallocAndRegisterPODArray (inPointer, (size) * sizeof (type) COMMA_HERE) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyNewArray(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    inPointer = new type [size] ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS 
  #define macroMyNewThere(inPointer,instanciation) { \
    macroMutexLock (gAllocationMutex) ; \
    macroVoidPointerThere (inPointer) ; \
    prologueForNew () ; \
    inPointer = new instanciation ; \
    registerPointer (inPointer COMMA_THERE) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyNewThere(inPointer,instanciation) { \
    macroMutexLock (gAllocationMutex) ; \
    inPointer = new instanciation ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS 
  #define macroMyNewPODArrayThere(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    macroValidPointerThere (inPointer) ; \
    inPointer = (type *) allocAndRegisterPODArray ((size) * sizeof (type) COMMA_THERE) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyNewPODArrayThere(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    inPointer = (type *) malloc ((size) * sizeof (type)) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS 
  #define macroMyReallocPODArrayThere(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    inPointer = (type *) reallocAndRegisterPODArray (inPointer, (size) * sizeof (type) COMMA_THERE) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyReallocPODArrayThere(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    inPointer = (type *) realloc (inPointer, (size) * sizeof (type)) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS 
  #define macroMyNewArrayThere(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    macroVoidPointerThere (inPointer) ; \
    prologueForNew () ; \
    inPointer = new type [size] ; \
    registerArray (inPointer COMMA_THERE) ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyNewArrayThere(inPointer,type,size) { \
    macroMutexLock (gAllocationMutex) ; \
    inPointer = new type [size] ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//         User macros for deallocation                                                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyDelete(inPointer) { \
    macroMutexLock (gAllocationMutex) ; \
    routineFreePointer (inPointer COMMA_HERE) ; \
    delete (inPointer) ; inPointer = NULL ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyDelete(inPointer) { \
    macroMutexLock (gAllocationMutex) ; \
    delete (inPointer) ; inPointer = NULL ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyDeletePODArray(inPointer) { \
    macroMutexLock (gAllocationMutex) ; \
    routineFreePODArrayPointer (inPointer COMMA_HERE) ; inPointer = NULL ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyDeletePODArray(inPointer) { \
    macroMutexLock (gAllocationMutex) ; \
    free (inPointer) ; inPointer = NULL ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroMyDeleteArray(inPointer) { \
    routineFreeArrayPointer (inPointer COMMA_HERE) ; \
    delete [] (inPointer) ; inPointer = NULL ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#else
  #define macroMyDeleteArray(inPointer) { \
    macroMutexLock (gAllocationMutex) ; \
    delete [] (inPointer) ; inPointer = NULL ; \
    macroMutexUnlock (gAllocationMutex) ; \
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//         Assertion macros for checking pointers                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroValidPointer(inPointer) routineValidPointer (inPointer COMMA_HERE)
#else
  #define macroValidPointer(inPointer)
#endif 

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroValidPointerThere(inPointer) routineValidPointer (inPointer COMMA_THERE)
#else
  #define macroValidPointerThere(inPointer)
#endif 

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//         Assertion for checking if a pointer is void                                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroVoidPointer(inPointer) routineVoidPointer (inPointer COMMA_HERE)
#else
  #define macroVoidPointer(inPointer)
#endif 

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define macroVoidPointerThere(inPointer) routineVoidPointer (inPointer COMMA_THERE)
#else
  #define macroVoidPointerThere(inPointer)
#endif 

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//         Routine to call for displaying currently allocated pointers                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void displayAllocatedBlocksInfo (void) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//         Internal routines (do not call them directly)                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS 
  void prologueForNew () ;
  void registerPointer (const void * inPointer COMMA_LOCATION_ARGS) ;
  void * allocAndRegisterPODArray (const size_t inSize COMMA_LOCATION_ARGS) ;
  void registerArray (const void * inPointer COMMA_LOCATION_ARGS) ;
  void routineValidPointer (const void * inPointer COMMA_LOCATION_ARGS) ;
  void routineVoidPointer (const void * inPointer COMMA_LOCATION_ARGS) ;
  void routineFreePointer (const void * inPointer COMMA_LOCATION_ARGS) ;
  void routineFreePODArrayPointer (void * inPointer COMMA_LOCATION_ARGS) ;
  void routineFreeArrayPointer (const void * inPointer COMMA_LOCATION_ARGS) ;
  void displayAllocatedBlockSizeStats (void) ;
  void * reallocAndRegisterPODArray (void * inPointer,
                                     const size_t inSize
                                     COMMA_LOCATION_ARGS) ;
#endif

//---------------------------------------------------------------------------------------------------------------------*

#endif

