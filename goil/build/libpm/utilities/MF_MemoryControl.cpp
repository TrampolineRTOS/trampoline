//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Implementation of routines for handling dynamic allocation checking.                                               *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1994, ..., 2016 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/M_machine.h"
#include "utilities/MF_MemoryControl.h"
#include "utilities/basic-allocation.h"

//---------------------------------------------------------------------------------------------------------------------*

#include <stdlib.h>
#include <stdio.h>

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//         Enum for describing a pointer                                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  typedef enum {
    kAllocatedByMacroMyNew,
    kAllocatedByMacroMyNewArray,
    kAllocatedByMacroMyNewPODArray
  } enumAllocationKind ;
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static uint32_t gAllocatedPODArrayCount = 0 ;
  static uint32_t gReallocatedPODArrayCount = 0 ;
  static uint32_t gPointerChangedOnPODArrayReallocationCount = 0 ;
  static int32_t gExistingPODArrayCount = 0 ;
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void unregisterPointer (const void * inPointerToUnregister,
                                 const enumAllocationKind inAllocationKind COMMA_LOCATION_ARGS) ;

  static void registerPointerDescriptor (const void * inPointerToRegister,
                                         const enumAllocationKind inAllocationKind
                                         COMMA_LOCATION_ARGS) ;
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark -
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void * allocAndRegisterPODArray (const size_t inSize COMMA_LOCATION_ARGS) {
    void * ptr = myAllocRoutine (inSize) ;
    registerPointerDescriptor (ptr, kAllocatedByMacroMyNewPODArray COMMA_THERE) ;
    gAllocatedPODArrayCount ++ ;
    gExistingPODArrayCount ++ ;
    return ptr ;
  }
#endif


//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void * reallocAndRegisterPODArray (void * inPointer,
                                     const size_t inSize
                                     COMMA_LOCATION_ARGS) {
    if (inPointer != NULL) {
      macroValidPointerThere (inPointer) ;
      unregisterPointer (inPointer, kAllocatedByMacroMyNewPODArray COMMA_THERE) ;
    }
    void * ptr = realloc (inPointer, inSize) ;
    registerPointerDescriptor (ptr, kAllocatedByMacroMyNewPODArray COMMA_THERE) ;
    gReallocatedPODArrayCount ++ ;
    if (ptr != inPointer) {
      if (inPointer == NULL) {
        gAllocatedPODArrayCount ++ ;
        gExistingPODArrayCount ++ ;
      }else{
        gPointerChangedOnPODArrayReallocationCount ++ ;
      }
    }
    return ptr ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void routineFreePODArrayPointer (void * inPointer COMMA_LOCATION_ARGS) {
    if (inPointer != NULL) {
      gExistingPODArrayCount -- ;
      myFreeRoutine (inPointer) ;
      unregisterPointer (inPointer, kAllocatedByMacroMyNewPODArray COMMA_THERE) ;
      #ifdef TRACE_DELETE
        co << "macroMyDeleteStructC -> "
           << inPointer
           << " at line "
           << IN_SOURCE_LINE
           << " of file '"
           << IN_SOURCE_FILE
           << "')\n" ;
      #endif
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark -
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//          Localisation de l'appel du deallocateur 'delete'                                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void routineFreePointer (const void * inPointer COMMA_LOCATION_ARGS) {
    if (inPointer != NULL) {
      unregisterPointer (inPointer, kAllocatedByMacroMyNew COMMA_THERE) ;
      #ifdef TRACE_DELETE
        co << "macroMyDelete -> "
           << inPointer
           << " at line "
           << IN_SOURCE_LINE
           << " of file '"
           << IN_SOURCE_FILE
           << "')\n" ;
      #endif
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void routineFreeArrayPointer (const void * inPointer COMMA_LOCATION_ARGS) {
    if (inPointer != NULL) {
      unregisterPointer (inPointer, kAllocatedByMacroMyNewArray COMMA_THERE) ;
      #ifdef TRACE_DELETE
        co << "macroMyDeleteArray -> "
           << inPointer
           << " at line "
           << IN_SOURCE_LINE
           << " of file '"
           << IN_SOURCE_FILE
           << "')\n" ;
      #endif
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark -
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  typedef struct cPointerDescriptor {
    const void * mPointer ;
    struct cPointerDescriptor * mInfPtr ;
    struct cPointerDescriptor * mSupPtr ;
    const char * mSourceFileName ;
    int mSourceLine ;
    int32_t mUniquePointerID ;
    int32_t mBalance ;
    enumAllocationKind mAllocationKind ;
  } cPointerDescriptor ;
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static const uint32_t ROOT_TABLE_SIZE = 33554467 ;
  static cPointerDescriptor * gPointerDescriptorTreeRoot [ROOT_TABLE_SIZE] ; // Initialized to array of NULL
  static int32_t gCreatedPointersCount = 0 ;
  static int32_t gPointersCurrentCount = 0 ;
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                Comparaison de deux clefs                                                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  typedef enum {kLeftKeyGreater, kEqualKeys, kRightKeyGreater} enumCompareResult ;
#endif

//---------------------------------------------------------------------------------------------------------------------*
//   Prototypes                                                                                                        *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static enumCompareResult comparePointers (const void * inLeftPointer,
                                            const void * inRightPointer) ;

  static void rotateLeft (cPointerDescriptor * & ioPtr) ;
  static void rotateRight (cPointerDescriptor * & ioPtr) ;
  static void supBranchDecreased (cPointerDescriptor *& ioPtr, bool &h) ;
  static void infBranchDecreased (cPointerDescriptor *& ioPtr, bool &h) ;
  static void getPreviousElement (cPointerDescriptor *&ioRoot,
                                  cPointerDescriptor *&E,
                                  bool &h) ;
  static void recursiveDeleteInBalancedBinaryTree (cPointerDescriptor * & ioRoot,
                                                   const void * inPointerToUnregister,
                                                   cPointerDescriptor * & outDeletedElementPtr,
                                                   bool & h) ;
  static void insertInBalancedBinaryTree (cPointerDescriptor *& ioRoot,
                                          const void * inNewKey,
                                          bool & ioAlreadyExists,
                                          cPointerDescriptor *& ioPointerNewElement,
                                          bool & ioExtension) ;
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static enumCompareResult comparePointers (const void * inLeftPointer, const void * inRightPointer) {
    enumCompareResult result = kEqualKeys ;
    if ((intptr_t) inLeftPointer > (intptr_t) inRightPointer) {
      result = kLeftKeyGreater ;
    }else if ((intptr_t) inLeftPointer < (intptr_t) inRightPointer) {
      result = kRightKeyGreater ;
    }
    return result ;
  }
#endif 

//---------------------------------------------------------------------------------------------------------------------*
//     Rotations elementaires de reequilibrage d'un ioRoot binaire                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void rotateLeft (cPointerDescriptor * & ioPtr) {
  //--- faire la rotation 
    cPointerDescriptor * b = ioPtr->mSupPtr;
    ioPtr->mSupPtr = b->mInfPtr;
    b->mInfPtr = ioPtr;
  //--- recalculer l'equilibrage 
    if (b->mBalance >= 0) {
      ioPtr->mBalance ++ ;
    }else{
      ioPtr->mBalance += 1 - b->mBalance ;
    }
    if (ioPtr->mBalance > 0) {
      b->mBalance += ioPtr->mBalance + 1 ;
    }else{
      b->mBalance ++ ;
    }
    ioPtr = b ;
  } 
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void rotateRight (cPointerDescriptor * & ioPtr) {
  //-- faire la rotation 
    cPointerDescriptor * b = ioPtr->mInfPtr;
    ioPtr->mInfPtr = b->mSupPtr;
    b->mSupPtr = ioPtr;
   //--- recalculer l'equilibrage 
    if (b->mBalance > 0) {
      ioPtr->mBalance -= 1 + b->mBalance ;
    }else{
      ioPtr->mBalance -- ;
    }
    if (ioPtr->mBalance >= 0) {
      b->mBalance -- ;
    }else{
      b->mBalance += ioPtr->mBalance - 1 ;
    }
    ioPtr = b ;
  }
#endif
 
//---------------------------------------------------------------------------------------------------------------------*
//    Suppression d'un element dans un ioRoot binaire equilibre                                                        *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void supBranchDecreased (cPointerDescriptor * & ioPtr, bool & h) {
    ioPtr->mBalance ++ ;
    switch (ioPtr->mBalance) {
    case 0:
      break;
    case 1:
      h = false;
      break ;
    case 2:
      switch (ioPtr->mInfPtr->mBalance) {
      case -1:
        rotateLeft (ioPtr->mInfPtr) ;
        rotateRight (ioPtr) ;
        break ;
      case 0:
        rotateRight (ioPtr) ;
        h = false ;
        break ;
      case 1:
        rotateRight (ioPtr) ;
        break ;
      }
      break;
    }
  }
#endif
 
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void infBranchDecreased (cPointerDescriptor * & ioPtr, bool & h) {
    ioPtr->mBalance -- ;
    switch (ioPtr->mBalance) {
    case 0:
      break;
    case -1:
      h = false;
      break;
    case -2:
      switch (ioPtr->mSupPtr->mBalance) {
      case 1:
        rotateRight (ioPtr->mSupPtr) ;
        rotateLeft (ioPtr) ;
        break;
      case 0:
        rotateLeft (ioPtr) ;
        h = false;
        break;
      case -1:
        rotateLeft (ioPtr) ;
        break;
      }
      break;
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void getPreviousElement (cPointerDescriptor * & ioRoot,
                                  cPointerDescriptor * & e,
                                  bool & h) {
    if (ioRoot->mSupPtr == NULL) {
      e = ioRoot;
      ioRoot = ioRoot->mInfPtr ;
      h = true;
    }else{
      getPreviousElement (ioRoot->mSupPtr, e, h) ;
      if (h) {
        supBranchDecreased (ioRoot, h);
      }
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void recursiveDeleteInBalancedBinaryTree (cPointerDescriptor * & ioRoot,
                                                   const void * inPointerToUnregister,
                                                   cPointerDescriptor * & outDeletedElementPtr,
                                                   bool & h) {
    if (ioRoot == NULL) {
      outDeletedElementPtr = NULL;
    }else{
      switch (comparePointers (inPointerToUnregister, ioRoot->mPointer)) {
      case kLeftKeyGreater:
        recursiveDeleteInBalancedBinaryTree (ioRoot->mSupPtr, inPointerToUnregister, outDeletedElementPtr, h);
        if (h) {
          supBranchDecreased (ioRoot, h) ;
        }
        break;
      case kRightKeyGreater:
        recursiveDeleteInBalancedBinaryTree (ioRoot->mInfPtr, inPointerToUnregister, outDeletedElementPtr, h);
        if (h) {
          infBranchDecreased (ioRoot, h) ;
        }
        break;
      case kEqualKeys:
        outDeletedElementPtr = ioRoot ;
        if (outDeletedElementPtr->mInfPtr == NULL) {
          ioRoot = outDeletedElementPtr->mSupPtr ;
          outDeletedElementPtr->mSupPtr = NULL ;
          h = true;
        }else if (outDeletedElementPtr->mSupPtr == NULL) {
          ioRoot = outDeletedElementPtr->mInfPtr ;
          outDeletedElementPtr->mInfPtr = NULL ;
          h = true;
        }else{
          getPreviousElement (outDeletedElementPtr->mInfPtr, ioRoot, h) ;
          ioRoot->mSupPtr = outDeletedElementPtr->mSupPtr ;
          outDeletedElementPtr->mSupPtr = NULL ;
          ioRoot->mInfPtr = outDeletedElementPtr->mInfPtr ;
          outDeletedElementPtr->mInfPtr = NULL ;
          ioRoot->mBalance = outDeletedElementPtr->mBalance ;
          outDeletedElementPtr->mBalance = 0;
          if (h) {
            infBranchDecreased (ioRoot, h) ;
          }
        }
        break;
      }
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void insertInBalancedBinaryTree (cPointerDescriptor *& ioRoot,
                                          const void * inNewKey,
                                          bool & ioAlreadyExists,
                                          cPointerDescriptor * & ioPointerNewElement,
                                          bool & ioExtension) {
    if (ioRoot == NULL) {
      ioPointerNewElement = (cPointerDescriptor *) myAllocRoutine (sizeof (cPointerDescriptor)) ;
      if (ioPointerNewElement != NULL) {
        ioPointerNewElement->mInfPtr = NULL ;
        ioPointerNewElement->mSupPtr = NULL ;
        ioPointerNewElement->mBalance = 0 ;
        ioPointerNewElement->mPointer = inNewKey ;
        ioPointerNewElement->mUniquePointerID = gCreatedPointersCount ;
        ioPointerNewElement->mSourceFileName = NULL ;
        ioPointerNewElement->mSourceLine = -1 ;
        ioRoot = ioPointerNewElement;
        ioAlreadyExists = false;
        ioExtension = true;
      }
    }else{
      switch (comparePointers (inNewKey, ioRoot->mPointer)) {
      case kLeftKeyGreater:
        insertInBalancedBinaryTree (ioRoot->mSupPtr, inNewKey, ioAlreadyExists, ioPointerNewElement, ioExtension);
        if (ioExtension) {
          ioRoot->mBalance -- ;
          switch (ioRoot->mBalance) {
          case 0:
            ioExtension = false;
            break;
          case -1:
            break;
          case -2:
            if (ioRoot->mSupPtr->mBalance == 1) {
              rotateRight (ioRoot->mSupPtr) ;
            }
            rotateLeft (ioRoot) ;
            ioExtension = false;
            break;
          }
        }
        break;
      case kEqualKeys:
        ioPointerNewElement = ioRoot;
        ioAlreadyExists = true;
        ioExtension = false;
        break;
      case kRightKeyGreater:
        insertInBalancedBinaryTree (ioRoot->mInfPtr, inNewKey, ioAlreadyExists, ioPointerNewElement, ioExtension);
        if (ioExtension) {
          ioRoot->mBalance++;
          switch (ioRoot->mBalance) {
          case 0:
            ioExtension = false;
            break;
          case 1:
            break;
          case 2:
            if (ioRoot->mInfPtr->mBalance == -1) {
              rotateLeft (ioRoot->mInfPtr) ;
            }
            rotateRight (ioRoot) ;
            ioExtension = false;
            break;
          }
        }
        break;
      }
    }
  }
#endif
 
//---------------------------------------------------------------------------------------------------------------------*
//   http://stackoverflow.com/questions/3442639/hashing-of-pointer-values
//   https://gist.github.com/badboy/6267743

#ifndef DO_NOT_GENERATE_CHECKINGS
  static uint32_t hashCodeForPointer (const void * inPointer) {
    const uint64_t v = (uint64_t) inPointer ;
    return (uint32_t) (v % ROOT_TABLE_SIZE) ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void registerPointerDescriptor (const void * inPointerToRegister,
                                         const enumAllocationKind inAllocation
                                         COMMA_LOCATION_ARGS) {
    // printf ("*** registering pointer %p\n", p) ;
    if (NULL != inPointerToRegister) {
      bool ioAlreadyExists = false ;
      bool ioExtension = false ;
      cPointerDescriptor * ioPointerNewElement = NULL ;
      gPointersCurrentCount ++ ;
      gCreatedPointersCount ++ ;
      insertInBalancedBinaryTree (gPointerDescriptorTreeRoot [hashCodeForPointer(inPointerToRegister)], inPointerToRegister, ioAlreadyExists, ioPointerNewElement, ioExtension);
      if (ioAlreadyExists) {
        runtime_error_routine ("(detectee par " __FILE__ ") Le pointeur existe deja", 0, 0, IN_SOURCE_FILE, IN_SOURCE_LINE) ;
      }
      if (NULL != ioPointerNewElement) {
        ioPointerNewElement->mSourceFileName = IN_SOURCE_FILE ;
        ioPointerNewElement->mSourceLine = IN_SOURCE_LINE ;
        ioPointerNewElement->mAllocationKind = inAllocation ;
      }
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void registerPointer (const void * inPointer COMMA_LOCATION_ARGS) {
    registerPointerDescriptor (inPointer, kAllocatedByMacroMyNew COMMA_THERE) ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void registerArray (const void * inPointer COMMA_LOCATION_ARGS) {
    registerPointerDescriptor (inPointer, kAllocatedByMacroMyNewArray COMMA_THERE) ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static cPointerDescriptor * searchPointerDescriptor (const void * inPointer) {
    cPointerDescriptor * p = NULL ;
    if (inPointer != NULL) {
      p = gPointerDescriptorTreeRoot[hashCodeForPointer(inPointer)];
      bool notFound = true;
      while (notFound && (p != NULL)) {
        switch (comparePointers (p->mPointer, inPointer)) {
        case kLeftKeyGreater:
          p = p->mInfPtr;
          break ;
        case kEqualKeys:
          notFound = false;
          break ;
        case kRightKeyGreater:
          p = p->mSupPtr;
          break ;
        } //switch
      } //while
    }
    return p ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void unregisterPointer (const void * inPointer,
                          const enumAllocationKind inAllocationKind
                          COMMA_LOCATION_ARGS) {
    bool h = false ;
    cPointerDescriptor * pointerToDelete = NULL ;
    recursiveDeleteInBalancedBinaryTree (gPointerDescriptorTreeRoot [hashCodeForPointer (inPointer)],
                                         inPointer, pointerToDelete, h);
    if (pointerToDelete == NULL) {
      runtime_error_routine ("(" __FILE__ ") Pointer (0x%X) is unknown", (intptr_t) inPointer, 0 COMMA_THERE) ;
    }
    if (NULL != pointerToDelete) {
      const int32_t inSourceFileLine = pointerToDelete->mSourceLine ;
      const char * nomFichierSource = pointerToDelete->mSourceFileName ;
      // printf ("------- %p %d\n", pointerToDelete, pointerToDelete->mAllocationKind) ;
      switch (inAllocationKind) {
      case kAllocatedByMacroMyNew :
        if (pointerToDelete->mAllocationKind != kAllocatedByMacroMyNew) {
          runtime_error_routine ("(" __FILE__ ") Appel de 'macroMyDelete' sur un pointeur declare dans '%s' ligne %d qui n'a pas ete alloue par 'macroMyNew'", 
                                 (intptr_t) nomFichierSource, inSourceFileLine, IN_SOURCE_FILE, IN_SOURCE_LINE) ;
        }
        break ;
      case kAllocatedByMacroMyNewArray :
        if (pointerToDelete->mAllocationKind != kAllocatedByMacroMyNewArray) {
          runtime_error_routine ("(" __FILE__ ") Appel de 'macroMyDeleteArray' sur un pointeur declare dans '%s' ligne %d qui n'a pas ete alloue par 'macroMyNewArray'", 
                                 (intptr_t) nomFichierSource, inSourceFileLine, IN_SOURCE_FILE, IN_SOURCE_LINE) ;
        }
        break ;
      case kAllocatedByMacroMyNewPODArray :
        if (pointerToDelete->mAllocationKind != kAllocatedByMacroMyNewPODArray) {
          runtime_error_routine ("(" __FILE__ ") Appel de 'macroMyDeletePODArray' sur un pointeur declare dans '%s' ligne %d qui n'a pas ete alloue par 'macroMyNewPODArray'", 
                                 (intptr_t) nomFichierSource, inSourceFileLine, IN_SOURCE_FILE, IN_SOURCE_LINE) ;
        }
        break ;
      }
      myFreeRoutine (pointerToDelete) ;
      gPointersCurrentCount -- ;
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//             Routine garantissant la nullite d'un pointeur                                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void routineVoidPointer (const void * inPointer COMMA_LOCATION_ARGS) {
    if (inPointer != NULL) {
      runtime_error_routine ("pointer (%p) not NULL", (intptr_t) inPointer, 0 COMMA_THERE) ;
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//            Routine garantissant la validite d'un pointeur                                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void routineValidPointer (const void * inPointer COMMA_LOCATION_ARGS) {
    if (inPointer == NULL) {
      runtime_error_routine ("(detected by " __FILE__ ") NULL pointer", 0, 0 COMMA_THERE) ;
    }
    cPointerDescriptor * p = searchPointerDescriptor (inPointer) ;
    if (p == NULL) {
      runtime_error_routine ("(detected by " __FILE__ ") unknown (%p) pointer", (intptr_t) inPointer, 0 COMMA_THERE) ;
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void recursiveDisplay (const cPointerDescriptor * inRoot) {
    if (NULL != inRoot) {
      recursiveDisplay (inRoot->mInfPtr) ;
    //---
      switch (inRoot->mAllocationKind) {
      case kAllocatedByMacroMyNew :
        printf ("    class") ;
        break ;
      case kAllocatedByMacroMyNewArray :
        printf ("       []") ;
        break ;
      case kAllocatedByMacroMyNewPODArray :
        printf ("POD array") ;
        break ;
      }
      printf (" | %11u | %s\n", inRoot->mSourceLine, inRoot->mSourceFileName) ;
    //---
      recursiveDisplay (inRoot->mSupPtr) ;
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

void displayAllocatedBlocksInfo (void) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    printf ("%u POD arraies have been used, %u have been reallocated (%u with pointer change).\n",
            gAllocatedPODArrayCount, gReallocatedPODArrayCount, gPointerChangedOnPODArrayReallocationCount) ;
    if (gExistingPODArrayCount != 0) {
      printf ("*** Warning: %u POD arraies are still allocated (instead of 0).\n", gExistingPODArrayCount) ;
    }
    if (gPointersCurrentCount != 0) {
      printf ("*** Warning: %d block information datas (instead of 0):\n", gPointersCurrentCount) ;
      printf ("  address  |   number   |     kind | source line | source file\n") ;  
    }
    for (uint32_t i=0 ; i<ROOT_TABLE_SIZE ; i++) {
      recursiveDisplay (gPointerDescriptorTreeRoot [i]) ;
    }
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*
