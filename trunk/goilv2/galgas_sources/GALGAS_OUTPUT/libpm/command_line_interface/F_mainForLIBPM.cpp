//-----------------------------------------------------------------------------*
//                                                                             *
//  Routine 'main' (call user supplied 'mainForLIBPM' routine).              *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2002, ..., 2012 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#include "bdd/C_BDD.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "utilities/MF_MemoryControl.h"
#include "utilities/F_DisplayException.h"
#include "streams/C_ConsoleOut.h"
#include "time/C_DateTime.h"
#include "utilities/C_SharedObject.h"
#include "utilities/cpp-allocation.h"
#include "utilities/basic-allocation.h"
#include "utilities/C_PrologueEpilogue.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"

//-----------------------------------------------------------------------------*

#include <stdio.h>

//-----------------------------------------------------------------------------*

static const char * gArgv0 ;

//-----------------------------------------------------------------------------*

static void
checkDataTypesSize (int & ioReturnCode) {
  if (sizeof (PMSInt8) != 1) {
    co << "** INTERNAL ERROR : sizeof (PMSInt8) == " ;
    co.appendUnsigned (sizeof (PMSInt8)) ;
    co << ", instead of 1 **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (PMUInt8) != 1) {
    co << "** INTERNAL ERROR : sizeof (PMUInt8) == " ;
    co.appendUnsigned (sizeof (PMUInt8)) ;
    co << ", instead of 1 **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (PMSInt16) != 2) {
    co << "** INTERNAL ERROR : sizeof (PMSInt16) == " ;
    co.appendUnsigned (sizeof (PMSInt16)) ;
    co << ", instead of 2 **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (PMUInt16) != 2) {
    co << "** INTERNAL ERROR : sizeof (PMUInt16) == " ;
    co.appendUnsigned (sizeof (PMUInt16)) ;
    co << ", instead of 2 **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (PMSInt32) != 4) {
    co << "** INTERNAL ERROR : sizeof (PMSInt32) == " ;
    co.appendUnsigned (sizeof (PMSInt32)) ;
    co << ", instead of 4 **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (PMUInt32) != 4) {
    co << "** INTERNAL ERROR : sizeof (PMUInt32) == " ;
    co.appendUnsigned (sizeof (PMUInt32)) ;
    co << ", instead of 4 **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (PMSInt64) != 8) {
    co << "** INTERNAL ERROR : sizeof (PMSInt64) == " ;
    co.appendUnsigned (sizeof (PMSInt64)) ;
    co << ", instead of 8 **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (PMUInt64) != 8) {
    co << "** INTERNAL ERROR : sizeof (PMUInt64) == " ;
    co.appendUnsigned (sizeof (PMUInt64)) ;
    co << ", instead of 8 **\n" ;
    ioReturnCode = 2 ;
  }
  #ifdef __LP64__
    const PMUInt32 kPointerSize = 8 ;
  #else
    const PMUInt32 kPointerSize = 4 ;
  #endif
  if (sizeof (void *) != kPointerSize) {
    co << "** INTERNAL ERROR : sizeof (void *) == " ;
    co.appendUnsigned (sizeof (void *)) ;
    co << ", instead of " ;
    co.appendUnsigned (kPointerSize) ;
    co << " **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (ptrdiff_t) != kPointerSize) {
    co << "** INTERNAL ERROR : sizeof (ptrdiff_t) == " ;
    co.appendUnsigned (sizeof (ptrdiff_t)) ;
    co << ", instead of " ;
    co.appendUnsigned (kPointerSize) ;
    co << " **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (size_t) != kPointerSize) {
    co << "** INTERNAL ERROR : sizeof (size_t) == " ;
    co.appendUnsigned (sizeof (size_t)) ;
    co << ", instead of " ;
    co.appendUnsigned (kPointerSize) ;
    co << " **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (PMSInt) != kPointerSize) {
    co << "** INTERNAL ERROR : sizeof (PMSInt) == " ;
    co.appendUnsigned (sizeof (PMSInt)) ;
    co << ", instead of " ;
    co.appendUnsigned (kPointerSize) ;
    co << " **\n" ;
    ioReturnCode = 2 ;
  }
  if (sizeof (PMUInt) != kPointerSize) {
    co << "** INTERNAL ERROR : sizeof (PMUInt) == " ;
    co.appendUnsigned (sizeof (PMUInt)) ;
    co << ", instead of " ;
    co.appendUnsigned (kPointerSize) ;
    co << " **\n" ;
    ioReturnCode = 2 ;
  }
}

//-----------------------------------------------------------------------------*

// #include "PMUInt128.h"
// #include "C_DirectedGraph.h"

//-----------------------------------------------------------------------------*

int main (int argc, const char * argv []) {
  // PMUInt128::example () ;
  // C_DirectedGraph::example () ;
  gArgv0 = argv [0] ;
  C_DateTime::enterCurrentToolModificationTime (argv [0]) ;
  int returnCode = 0 ; // No error
//--- Print options
  /* printf ("Command line options:\n") ;
  for (int i=1 ; i<argc ; i++) {
    printf ("  - '%s'\n", argv [i]) ;
  } */
//--- Check Data type size
  checkDataTypesSize (returnCode) ;
//---
  if (returnCode == 0) {
    try{
      C_PrologueEpilogue::runPrologueActions () ;
      returnCode = mainForLIBPM (argc, argv) ;
      C_PrologueEpilogue::runEpilogueActions () ;
      C_BDD::freeBDDStataStructures () ;
      #ifndef DO_NOT_GENERATE_CHECKINGS
        C_SharedObject::checkAllObjectsHaveBeenReleased () ;
        displayAllocationStats () ;
        displayAllocatedBlockSizeStats () ;
        displayAllocatedBlocksInfo () ;
      #endif
    }catch (const M_STD_NAMESPACE exception & e) {
      F_default_display_exception (e) ;
      #ifndef DO_NOT_GENERATE_CHECKINGS
        C_SharedObject::checkAllObjectsHaveBeenReleased () ;
      #endif
      returnCode = 1 ; // Error code
    }catch (char * inExceptionString) {
      printf ("*** Exception: '%s' ***\n", inExceptionString) ;
      #ifndef DO_NOT_GENERATE_CHECKINGS
        C_SharedObject::checkAllObjectsHaveBeenReleased () ;
      #endif
      returnCode = 1 ; // Error code
    }catch (...) {
      F_default_display_unknown_exception () ;
      #ifndef DO_NOT_GENERATE_CHECKINGS
        C_SharedObject::checkAllObjectsHaveBeenReleased () ;
      #endif
      returnCode = 2 ; // Error code
    }
  }
  return returnCode ;
}

//-----------------------------------------------------------------------------*

const char * mainFirstArgument (void) {
  return gArgv0 ;
}

//-----------------------------------------------------------------------------*
