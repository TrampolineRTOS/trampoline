//-----------------------------------------------------------------------------*
//                                                                             *
//  Implementation of routines for handling dynamic allocation checking.       *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 1994, ..., 2010 Pierre Molinaro.                             *
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

#include "utilities/M_machine.h"
#include "utilities/MF_MemoryControl.h"
#include "utilities/cpp-allocation.h"
#include "utilities/basic-allocation.h"

//-----------------------------------------------------------------------------*

#include <stdio.h>

//-----------------------------------------------------------------------------*

//#define REGISTER_ALLOCATION_STATS
//#define REDEFINE_NEW_DELETE_OPERATORS

//-----------------------------------------------------------------------------*
// Include this header is required for safely compile allocation operators.

#include <new>

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #ifndef REGISTER_ALLOCATION_STATS
    #define REGISTER_ALLOCATION_STATS
  #endif
#endif

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #ifndef REDEFINE_NEW_DELETE_OPERATORS
    #define REDEFINE_NEW_DELETE_OPERATORS
  #endif
#endif

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static int32_t gAllocProloguePendings = 0 ;
#endif

//-----------------------------------------------------------------------------*

#ifdef REGISTER_ALLOCATION_STATS
  static uint32_t gBlockAllocatedWithoutUsingMacroMyNew = 0 ;
  static uint32_t gBlockAllocatedWithoutUsingMacroMyNewArray = 0 ;
  static int32_t gCurrentObjectCount = 0 ;
  static uint32_t gAllocatedObjectCount = 0 ;
  static int32_t gCurrentArrayCount = 0 ;
  static uint32_t gAllocatedArrayCount = 0 ;
#endif

//-----------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void prologueForNew (void) {
    gAllocProloguePendings ++ ;
  }
#endif

//-----------------------------------------------------------------------------*

#ifdef REDEFINE_NEW_DELETE_OPERATORS
void * operator new (size_t inSizeInBytes) throw (std::bad_alloc) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    if (gAllocProloguePendings <= 0) {
      gBlockAllocatedWithoutUsingMacroMyNew ++ ;
    }
    gAllocProloguePendings -- ;
  #endif
  void * result = NULL ;
  if (inSizeInBytes > 0) {
    result = ::myAllocRoutine (inSizeInBytes) ;
    if (NULL == result) {
      throw std::bad_alloc () ;
    }
    #ifdef REGISTER_ALLOCATION_STATS
      gCurrentObjectCount ++ ;
      gAllocatedObjectCount ++ ;
    #endif
  }
  return result ;
}
#endif

//-----------------------------------------------------------------------------*

#ifdef REDEFINE_NEW_DELETE_OPERATORS
void * operator new [] (size_t inSizeInBytes) throw (std::bad_alloc) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    if (gAllocProloguePendings <= 0) {
      gBlockAllocatedWithoutUsingMacroMyNewArray ++ ;
    }
    gAllocProloguePendings -- ;
  #endif
  void * result = NULL ;
  if (inSizeInBytes > 0) {
    result = ::myAllocRoutine (inSizeInBytes) ;
    if (NULL == result) {
      throw std::bad_alloc () ;
    }
    #ifdef REGISTER_ALLOCATION_STATS
      gCurrentArrayCount ++ ;
      gAllocatedArrayCount ++ ;
    #endif
  }
  return result ;
}
#endif

//-----------------------------------------------------------------------------*

#ifdef REDEFINE_NEW_DELETE_OPERATORS
void operator delete (void * inPointer) throw () {
  if (inPointer != NULL) {
    ::myFreeRoutine (inPointer) ;
    #ifdef REGISTER_ALLOCATION_STATS
      gCurrentObjectCount -- ;
    #endif
  } 
}
#endif

//-----------------------------------------------------------------------------*

#ifdef REDEFINE_NEW_DELETE_OPERATORS
void operator delete [] (void * inPointer) throw () {
  if (inPointer != NULL) {
    ::myFreeRoutine (inPointer) ;
    #ifdef REGISTER_ALLOCATION_STATS
      gCurrentArrayCount -- ;
    #endif
  } 
}
#endif

//-----------------------------------------------------------------------------*

void displayAllocationStats (void) {
  #ifdef REGISTER_ALLOCATION_STATS
    printf ("%u memory blocks, %u arraies have been used.\n", gAllocatedObjectCount, gAllocatedArrayCount) ;
    if (gCurrentObjectCount > 0) {
      printf ("*** Warning: %u blocks currently allocated (instead of 0).\n", gCurrentObjectCount) ;
    }
    if (gCurrentArrayCount > 0) {
      printf ("*** Warning: %u arraies currently allocated (instead of 0).\n", gCurrentArrayCount) ;
    }
    if (gBlockAllocatedWithoutUsingMacroMyNew > 0) {
      printf ("*** Warning: %u blocks allocated without using macroMyNew.\n", gBlockAllocatedWithoutUsingMacroMyNew) ;
    }
    if (gBlockAllocatedWithoutUsingMacroMyNewArray > 0) {
      printf ("*** Warning: %u blocks allocated without using macroMyNewArray.\n", gBlockAllocatedWithoutUsingMacroMyNewArray) ;
    }
  #endif
}

//-----------------------------------------------------------------------------*
