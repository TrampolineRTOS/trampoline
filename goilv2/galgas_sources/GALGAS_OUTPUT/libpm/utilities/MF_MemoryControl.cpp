//---------------------------------------------------------------------------*
//                                                                           *
//  Implementation of routines for handling dynamic allocation checking.     *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1994, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include "utilities/M_machine.h"
#include "utilities/MF_MemoryControl.h"
#include "utilities/basic-allocation.h"

//---------------------------------------------------------------------------*

#include <stdlib.h>
#include <stdio.h>

//---------------------------------------------------------------------------*

macroDeclareMutex (gAllocationMutex) ;

//---------------------------------------------------------------------------*
//                                                                           *
//         Enum for describing a pointer                                     *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  typedef enum {
    kAllocatedByMacroMyNew,
    kAllocatedByMacroMyNewArray,
    kAllocatedByMacroMyNewPODArray,
    kUnknownAllocation
  } enumAllocation ;
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static PMUInt32 gAllocatedPODArrayCount = 0 ;
  static PMUInt32 gReallocatedPODArrayCount = 0 ;
  static PMUInt32 gPointerChangedOnPODArrayReallocationCount = 0 ;
  static PMSInt32 gExistingPODArrayCount = 0 ;
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void
  supprimerPointeur (const void * PointeurAretirer,
                     const enumAllocation natureAllocation COMMA_LOCATION_ARGS) ;

  static void performRegistering (const void * p,
                                  const enumAllocation inAllocation
                                  COMMA_LOCATION_ARGS) ;
  static void
  display_pointer (const void * adresse,
                   const PMSInt32 numeroCreation, 
                   const enumAllocation natureObjet, 
                   const PMSInt32 numeroLigneSource, 
                   const char * inSourceFileName) ;
#endif

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark -
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void * allocAndRegisterPODArray (const size_t inSize COMMA_LOCATION_ARGS) {
    void * ptr = myAllocRoutine (inSize) ;
    performRegistering (ptr, kAllocatedByMacroMyNewPODArray COMMA_THERE) ;
    gAllocatedPODArrayCount ++ ;
    gExistingPODArrayCount ++ ;
    return ptr ;
  }
#endif


//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void * reallocAndRegisterPODArray (void * inPointer,
                                     const size_t inSize
                                     COMMA_LOCATION_ARGS) {
    if (inPointer != NULL) {
      macroValidPointerThere (inPointer) ;
    }
    void * ptr = realloc (inPointer, inSize) ;
    gReallocatedPODArrayCount ++ ;
    if (ptr != inPointer) {
      if (inPointer == NULL) {
        gAllocatedPODArrayCount ++ ;
        gExistingPODArrayCount ++ ;
      }else{
        gPointerChangedOnPODArrayReallocationCount ++ ;
        supprimerPointeur (inPointer, kAllocatedByMacroMyNewPODArray COMMA_THERE) ;
      }
      performRegistering (ptr, kAllocatedByMacroMyNewPODArray COMMA_THERE) ;
    }
    return ptr ;
  }
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void routineFreePODArrayPointer (void * inPointer COMMA_LOCATION_ARGS) {
    if (inPointer != NULL) {
      gExistingPODArrayCount -- ;
      myFreeRoutine (inPointer) ;
      supprimerPointeur (inPointer, kAllocatedByMacroMyNewPODArray COMMA_THERE) ;
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

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark -
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//          Localisation de l'appel du deallocateur 'delete'                 *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void routineFreePointer (const void * inPointer COMMA_LOCATION_ARGS) {
    if (inPointer != NULL) {
      supprimerPointeur (inPointer, kAllocatedByMacroMyNew COMMA_THERE) ;
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

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void routineFreeArrayPointer (const void * inPointer COMMA_LOCATION_ARGS) {
    if (inPointer != NULL) {
      supprimerPointeur (inPointer, kAllocatedByMacroMyNewArray COMMA_THERE) ;
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

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark -
#endif

//-----------------------------------------------------------------*
//                                                                 *
//            Specification des types de donnees                   *
//               pour l'ioRoot binaire equilibre                    *
//                                                                 *
//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  class CelementArbreBinaireEquilibrePointeur {
    public : const void * champPtr ;
 // pour construire une liste sequentielle des pointeurs
    public : CelementArbreBinaireEquilibrePointeur * champSuivantDeListeLineaire ;
    public : void enregistrerDansListeLineaire (CelementArbreBinaireEquilibrePointeur * & racine) ;
  //-- champs pour la table binaire equilibree permettant de retrouver le pointeur par son adresse
    public : CelementArbreBinaireEquilibrePointeur * mInfPtr ;
    public : CelementArbreBinaireEquilibrePointeur * mSupPtr ;
    public : const char * mSourceFileName ; // nom du fichier source dans lequel le pointeur a ete cree
    public : PMSInt32 champNumeroCreation ; // numero d'ordre unique
    public : int champNumeroLigneSource ; // ligne source
    public : PMSInt16 mBalance ;    
    public : enumAllocation champNatureObjet ; // indique si le pointeur designe un tableau (new ... [...])
    public : void affichageRecursif (void) const ;
   } ; 
#endif

//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static const PMSInt32 TAILLE_TABLE_RACINES = 262145 ;
  static CelementArbreBinaireEquilibrePointeur * gPointersTreeRoot [TAILLE_TABLE_RACINES] ;
  static PMSInt32 gCreatedPointersCount = 0 ;
  static PMSInt32 gPointersCurrentCount = 0 ;
  static bool gRootInited = false ;
#endif 

//-----------------------------------------------------------------*
//                                                                 *
//                Comparaison de deux clefs                        *
//                                                                 *
//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
   enum enumResultatComparaison {ClefGaucheSup, ClefsEgales, ClefDroiteSup} ; 
#endif

//-----------------------------------------------------------------*
//                     Prototypes                                  *
//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static enumResultatComparaison comparerPointeurs (const void * Pgauche,
                                                    const void * Pdroit) ;
  static void rotationGauche (CelementArbreBinaireEquilibrePointeur * & A) ;
  static void rotationDroite (CelementArbreBinaireEquilibrePointeur * & A) ;
  static void diminutionBrancheSup (CelementArbreBinaireEquilibrePointeur *&A, bool &h) ;
  static void infBranchDecreased (CelementArbreBinaireEquilibrePointeur *&A, bool &h) ;
  static void obtenirElementPrecedent (CelementArbreBinaireEquilibrePointeur *&arbreEquilibre,
         CelementArbreBinaireEquilibrePointeur *&E,
         bool &h) ;
  static void suppressionRecursiveDansArbreBinaireEquilibre (CelementArbreBinaireEquilibrePointeur *&arbreEquilibre,
         const void * PointeurAretirer,
         CelementArbreBinaireEquilibrePointeur *&PointeurElementSupprime,
         bool &h) ;
  static void executerInsertionRecursiveDansArbreEquilibre (
         CelementArbreBinaireEquilibrePointeur *&Arbre,
         const void * NouvelleClef,
         bool & existeDeja,
         CelementArbreBinaireEquilibrePointeur *&pointeurNouvelElement,
         bool & ioExtension) ;
#endif

//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static enumResultatComparaison comparerPointeurs (const void * Pgauche,
                                                    const void * Pdroit) {
    if ((PMSInt) Pgauche > (PMSInt) Pdroit) {
      return ClefGaucheSup ;
    }else if ((PMSInt) Pgauche < (PMSInt) Pdroit) {
      return ClefDroiteSup ;
    }else{
      return ClefsEgales ;
    }
  }
#endif 

//-----------------------------------------------------------------*
//     Rotations elementaires de reequilibrage d'un ioRoot binaire  *
//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void rotationGauche (CelementArbreBinaireEquilibrePointeur * & a) {
  //--- faire la rotation 
    CelementArbreBinaireEquilibrePointeur * b = a->mSupPtr;
    a->mSupPtr = b->mInfPtr;
    b->mInfPtr = a;
  //--- recalculer l'equilibrage 
    if (b->mBalance >= 0) {
      a->mBalance ++ ;
    }else{
      a->mBalance = (PMSInt16) (a->mBalance + 1 - b->mBalance) ;
    }
    if (a->mBalance > 0) {
      b->mBalance = (PMSInt16) (b->mBalance + a->mBalance + 1) ;
    }else{
      b->mBalance ++ ;
    }
    a = b ;
  } 
#endif

//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void rotationDroite (CelementArbreBinaireEquilibrePointeur * & a) {
  //-- faire la rotation 
    CelementArbreBinaireEquilibrePointeur * b = a->mInfPtr;
    a->mInfPtr = b->mSupPtr;
    b->mSupPtr = a;
   //--- recalculer l'equilibrage 
    if (b->mBalance > 0) {
      a->mBalance = (PMSInt16) (a->mBalance - b->mBalance - 1) ;
    }else{
      a->mBalance -- ;
    }
    if (a->mBalance >= 0) {
      b->mBalance -- ;
    }else{
      b->mBalance = (PMSInt16) (b->mBalance + a->mBalance - 1) ;
    }
    a = b ;
  }
#endif
 
//-----------------------------------------------------------------*
//    Suppression d'un element dans un ioRoot binaire equilibre     *
//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void diminutionBrancheSup (CelementArbreBinaireEquilibrePointeur * & a, bool & h) {
    a->mBalance ++ ;
    switch (a->mBalance) {
    case 0:
      break;
    case 1:
      h = false;
      break;
    case 2:
      switch (a->mInfPtr->mBalance) {
      case -1:
        rotationGauche (a->mInfPtr) ;
        rotationDroite (a) ;
        break;
      case 0:
        rotationDroite (a) ;
        h = false;
        break;
      case 1:
        rotationDroite (a) ;
        break;
      }
      break;
    }
  }
#endif
 
//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void infBranchDecreased (CelementArbreBinaireEquilibrePointeur * & a, bool & h) {
    a->mBalance -- ;
    switch (a->mBalance) {
    case 0:
      break;
    case -1:
      h = false;
      break;
    case -2:
      switch (a->mSupPtr->mBalance) {
      case 1:
        rotationDroite (a->mSupPtr) ;
        rotationGauche (a) ;
        break;
      case 0:
        rotationGauche (a) ;
        h = false;
        break;
      case -1:
        rotationGauche (a) ;
        break;
      }
      break;
    }
  }
#endif

//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void obtenirElementPrecedent (CelementArbreBinaireEquilibrePointeur * & arbreEquilibre,
                                       CelementArbreBinaireEquilibrePointeur * & e,
                                       bool & h) {
    if (arbreEquilibre->mSupPtr == NULL) {
      e = arbreEquilibre;
      arbreEquilibre = arbreEquilibre->mInfPtr ;
      h = true;
    }else{
      obtenirElementPrecedent (arbreEquilibre->mSupPtr, e, h) ;
      if (h) {
        diminutionBrancheSup (arbreEquilibre, h);
      }
    }
  }
#endif

//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void suppressionRecursiveDansArbreBinaireEquilibre
                          (CelementArbreBinaireEquilibrePointeur * & arbreEquilibre,
                           const void * pointeurAretirer,
                           CelementArbreBinaireEquilibrePointeur * & pointeurElementSupprime,
                           bool & h) {
    if (arbreEquilibre == NULL) {
      pointeurElementSupprime = (CelementArbreBinaireEquilibrePointeur *) NULL;
    }else{
      switch (comparerPointeurs(pointeurAretirer, arbreEquilibre->champPtr)) {
      case ClefGaucheSup:
        suppressionRecursiveDansArbreBinaireEquilibre (arbreEquilibre->mSupPtr,
                                                       pointeurAretirer, pointeurElementSupprime, h);
        if (h) {
          diminutionBrancheSup (arbreEquilibre, h) ;
        }
        break;
      case ClefDroiteSup:
        suppressionRecursiveDansArbreBinaireEquilibre (arbreEquilibre->mInfPtr,
                                                       pointeurAretirer, pointeurElementSupprime, h);
        if (h) {
          infBranchDecreased (arbreEquilibre, h);
        }
        break;
      case ClefsEgales:
        pointeurElementSupprime = arbreEquilibre;
        if (pointeurElementSupprime->mInfPtr == NULL) {
          arbreEquilibre = pointeurElementSupprime->mSupPtr;
          pointeurElementSupprime->mSupPtr = (CelementArbreBinaireEquilibrePointeur *) NULL;
          h = true;
        }else if (pointeurElementSupprime->mSupPtr == NULL) {
          arbreEquilibre = pointeurElementSupprime->mInfPtr;
          pointeurElementSupprime->mInfPtr = (CelementArbreBinaireEquilibrePointeur *) NULL;
          h = true;
        }else{
          obtenirElementPrecedent (pointeurElementSupprime->mInfPtr,
                                   arbreEquilibre, h);
          arbreEquilibre->mSupPtr = pointeurElementSupprime->mSupPtr;
          pointeurElementSupprime->mSupPtr = (CelementArbreBinaireEquilibrePointeur *) NULL;
          arbreEquilibre->mInfPtr = pointeurElementSupprime->mInfPtr;
          pointeurElementSupprime->mInfPtr = (CelementArbreBinaireEquilibrePointeur *) NULL;
          arbreEquilibre->mBalance = pointeurElementSupprime->mBalance;
          pointeurElementSupprime->mBalance = 0;
          if (h) {
            infBranchDecreased (arbreEquilibre, h);
          }
        }
        break;
      }
    }
  }
#endif

//-----------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void executerInsertionRecursiveDansArbreEquilibre (
                            CelementArbreBinaireEquilibrePointeur *& ioRoot,
                            const void * nouvelleClef,
                            bool & existeDeja,
                            CelementArbreBinaireEquilibrePointeur * & pointeurNouvelElement,
                            bool & ioExtension) {
    if (ioRoot == NULL) {
      pointeurNouvelElement = (CelementArbreBinaireEquilibrePointeur *) myAllocRoutine (sizeof (CelementArbreBinaireEquilibrePointeur)) ;
      if (pointeurNouvelElement != NULL) {
        pointeurNouvelElement->mInfPtr = (CelementArbreBinaireEquilibrePointeur *) NULL;
        pointeurNouvelElement->mSupPtr = (CelementArbreBinaireEquilibrePointeur *) NULL;
        pointeurNouvelElement->mBalance = 0;
        pointeurNouvelElement->champPtr = nouvelleClef;
        pointeurNouvelElement->champNumeroCreation = gCreatedPointersCount;
        pointeurNouvelElement->mSourceFileName = (char *) NULL ;
        pointeurNouvelElement->champNumeroLigneSource = -1 ;
        ioRoot = pointeurNouvelElement;
        existeDeja = false;
        ioExtension = true;
      }
    }else{
      const enumResultatComparaison ResultatComparaison = comparerPointeurs(nouvelleClef, ioRoot->champPtr);
      switch (ResultatComparaison) {
      case ClefGaucheSup:
        executerInsertionRecursiveDansArbreEquilibre (ioRoot->mSupPtr, nouvelleClef,
                                                      existeDeja, pointeurNouvelElement, ioExtension);
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
              rotationDroite (ioRoot->mSupPtr) ;
            }
            rotationGauche (ioRoot) ;
            ioExtension = false;
            break;
          }
        }
        break;
      case ClefsEgales:
        pointeurNouvelElement = ioRoot;
        existeDeja = true;
        ioExtension = false;
        break;
      case ClefDroiteSup:
        executerInsertionRecursiveDansArbreEquilibre (ioRoot->mInfPtr, nouvelleClef,
                                                      existeDeja, pointeurNouvelElement, ioExtension);
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
              rotationGauche (ioRoot->mInfPtr) ;
            }
            rotationDroite (ioRoot) ;
            ioExtension = false;
            break;
          }
        }
        break;
      }
    }
  } //fin executerInsertionRecursiveDansArbreEquilibre 
#endif
 
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static PMUInt32 HashCode (const void * Ptr) {
    const PMUInt v = (PMUInt) Ptr ;
    return (PMUInt32) ((v % TAILLE_TABLE_RACINES) & PMUINT32_MAX) ;
  }
#endif

//---------------------------------------------------------------------------*

//#include <stdio.h>

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void performRegistering (const void * inPointer,
                                  const enumAllocation inAllocation
                                  COMMA_LOCATION_ARGS) {
    // printf ("*** registering pointer %p\n", p) ;
    if (NULL != inPointer) {
      if (! gRootInited) {
        for (PMSInt32 i=0 ; i<TAILLE_TABLE_RACINES ; i ++) {
          gPointersTreeRoot [i] = (CelementArbreBinaireEquilibrePointeur *) NULL ;
        }
        gRootInited = true ;
      }
      bool existeDeja = false ;
      bool ioExtension = false ;
      CelementArbreBinaireEquilibrePointeur * pointeurNouvelElement = NULL ;
      gPointersCurrentCount ++ ;
      gCreatedPointersCount ++ ;
  //    MF_Assert (gCreatedPointersCount != 69068, "gCreatedPointersCount == %lld", gCreatedPointersCount, 0) ;
      executerInsertionRecursiveDansArbreEquilibre (gPointersTreeRoot[HashCode(inPointer)], inPointer, existeDeja, pointeurNouvelElement, ioExtension);
      if (existeDeja) {
        runtime_error_routine ("(detectee par " __FILE__ ") Le pointeur existe deja", 0, 0, IN_SOURCE_FILE, IN_SOURCE_LINE) ;
      }
      if (NULL != pointeurNouvelElement) {
        pointeurNouvelElement->mSourceFileName = IN_SOURCE_FILE ;
        pointeurNouvelElement->champNumeroLigneSource = IN_SOURCE_LINE ;
        pointeurNouvelElement->champNatureObjet = inAllocation ;
      }
    }
  }
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void registerPointer (const void * p COMMA_LOCATION_ARGS) {
    performRegistering (p, kAllocatedByMacroMyNew COMMA_THERE) ;
  }
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void registerArray (const void * p COMMA_LOCATION_ARGS) {
    performRegistering (p, kAllocatedByMacroMyNewArray COMMA_THERE) ;
  }
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static CelementArbreBinaireEquilibrePointeur * rechercherPointeur (const void * inPointer) {
    CelementArbreBinaireEquilibrePointeur * p = (CelementArbreBinaireEquilibrePointeur *) NULL ;
    if (inPointer != NULL) {
      p = gPointersTreeRoot[HashCode(inPointer)];
      bool PasTrouve = true;
      while (PasTrouve && p != NULL) {
        switch (comparerPointeurs (p->champPtr, inPointer)) {
        case ClefGaucheSup: 
          p = p->mInfPtr;
          break ;
        case ClefsEgales: 
          PasTrouve = false;
          break ;
        case ClefDroiteSup: 
          p = p->mSupPtr;
          break ;
        } //switch
      } //while
    }
    return p ;
  }
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void supprimerPointeur (const void * inPointer,
                          const enumAllocation natureAllocation COMMA_LOCATION_ARGS) {
    bool h = false ;
    CelementArbreBinaireEquilibrePointeur * pointerToDelete = (CelementArbreBinaireEquilibrePointeur *) NULL ;
    suppressionRecursiveDansArbreBinaireEquilibre (gPointersTreeRoot [HashCode (inPointer)],
                                                   inPointer, pointerToDelete, h);
    if (pointerToDelete == NULL) {
      runtime_error_routine ("(" __FILE__ ") Pointer (0x%X) is unknown", (PMSInt) inPointer, 0 COMMA_THERE) ;
    }
    if (NULL != pointerToDelete) {
      const PMSInt32 numeroLigneSource = pointerToDelete->champNumeroLigneSource ;
      const char * nomFichierSource = pointerToDelete->mSourceFileName ;
      // printf ("------- %p %d\n", pointerToDelete, pointerToDelete->champNatureObjet) ;
      switch (natureAllocation) {
      case kAllocatedByMacroMyNew :
        if (pointerToDelete->champNatureObjet != kAllocatedByMacroMyNew) {
          runtime_error_routine ("(" __FILE__ ") Appel de 'macroMyDelete' sur un pointeur declare dans '%s' ligne %d qui n'a pas ete alloue par 'macroMyNew'", 
                                 (PMSInt) nomFichierSource, numeroLigneSource, IN_SOURCE_FILE, IN_SOURCE_LINE) ; 
        }
        break ;
      case kAllocatedByMacroMyNewArray :
        if (pointerToDelete->champNatureObjet != kAllocatedByMacroMyNewArray) {
          runtime_error_routine ("(" __FILE__ ") Appel de 'macroMyDeleteArray' sur un pointeur declare dans '%s' ligne %d qui n'a pas ete alloue par 'macroMyNewArray'", 
                                 (PMSInt) nomFichierSource, numeroLigneSource, IN_SOURCE_FILE, IN_SOURCE_LINE) ;
        }
        break ;
      case kAllocatedByMacroMyNewPODArray :
        if (pointerToDelete->champNatureObjet != kAllocatedByMacroMyNewPODArray) {
          runtime_error_routine ("(" __FILE__ ") Appel de 'macroMyDeletePODArray' sur un pointeur declare dans '%s' ligne %d qui n'a pas ete alloue par 'macroMyNewPODArray'", 
                                 (PMSInt) nomFichierSource, numeroLigneSource, IN_SOURCE_FILE, IN_SOURCE_LINE) ;
        }
        break ;
      default : // Alloue hors macro
        break ;
      }
      myFreeRoutine (pointerToDelete) ;
      gPointersCurrentCount -- ;
    }
  }
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//             Routine garantissant la nullite d'un pointeur                 *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void routineVoidPointer (const void * inPointer COMMA_LOCATION_ARGS) {
    if (inPointer != NULL) {
      runtime_error_routine ("pointer (%p) not NULL", (PMSInt) inPointer, 0 COMMA_THERE) ;
    }
  }
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//            Routine garantissant la validite d'un pointeur                 *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void routineValidPointer (const void * inPointer COMMA_LOCATION_ARGS) {
    if (inPointer == NULL) {
      runtime_error_routine ("(detected by " __FILE__ ") NULL pointer", 0, 0 COMMA_THERE) ;
    }
    CelementArbreBinaireEquilibrePointeur * p = rechercherPointeur (inPointer) ;
    if (p == NULL) {
      runtime_error_routine ("(detected by " __FILE__ ") unknown (%p) pointer", (PMSInt) inPointer, 0 COMMA_THERE) ;
    }
  }
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void CelementArbreBinaireEquilibrePointeur::affichageRecursif (void) const {
  //--- Branche inf
    if (mInfPtr != NULL) {
      mInfPtr->affichageRecursif () ;
    }
  //--- Affichage
    display_pointer (champPtr, champNumeroCreation, champNatureObjet,
                     champNumeroLigneSource, mSourceFileName) ;
  //--- Branche sup
    if (mSupPtr != NULL) {
      mSupPtr->affichageRecursif () ;
    }
  }
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void CelementArbreBinaireEquilibrePointeur::
  enregistrerDansListeLineaire (CelementArbreBinaireEquilibrePointeur * & racine) {
  //--- Branche inf
    if (mInfPtr != NULL) {
      mInfPtr->enregistrerDansListeLineaire (racine) ;
    }
  //--- Insertion
    champSuivantDeListeLineaire = racine ;
    racine = this ;
  //--- Branche sup
    if (mSupPtr != NULL) {
      mSupPtr->enregistrerDansListeLineaire (racine) ;
    }
  }
#endif

//---------------------------------------------------------------------------*
 
#ifndef DO_NOT_GENERATE_CHECKINGS 
  static void
  display_pointer (const void * adresse,
                   const PMSInt32 numeroCreation, 
                   const enumAllocation natureObjet, 
                   const PMSInt32 numeroLigneSource, 
                   const char * inSourceFileName) {
    printf ("%10p | %10u |", adresse, numeroCreation) ;
    switch (natureObjet) {
    case kAllocatedByMacroMyNew :
      printf ("    class") ;
      break ;
    case kAllocatedByMacroMyNewArray :
      printf ("       []") ;
      break ;
    case kAllocatedByMacroMyNewPODArray :
      printf ("POD array") ;
      break ;
    default :
      break ;
    }
    printf (" | %11u | %s\n", numeroLigneSource, inSourceFileName) ;
  }
#endif

//---------------------------------------------------------------------------*

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
    for (PMSInt32 i=0 ; i<TAILLE_TABLE_RACINES ; i++) {
      if (gPointersTreeRoot [i] != NULL) {
        gPointersTreeRoot [i]->affichageRecursif () ;
      }
    }
  #endif
}

//---------------------------------------------------------------------------*


