//-----------------------------------------------------------------------------*
//                                                                             *
//            Template routines for managing AVL trees                       *
//                                                                             *
//  References :                                                             *
//  Niklaus Wirth, "Algorithms + Data Structures = Programs",                *
//  Prentice-Hall Eds, Series in Automatic Computations,                     *
//  1976, pages 215-225                                                      *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2001 Pierre Molinaro.                                      *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
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

#ifndef AVLTREE_TEMPLATE_ROUTINES_DEFINED
#define AVLTREE_TEMPLATE_ROUTINES_DEFINED

//-----------------------------------------------------------------------------*
//                                                                             *
//      An ELEMENT class must have the following members :                   *
//        INFO mInfo                                                         *
//        ELEMENT * mPtrToInf                                                *
//        ELEMENT * mPtrToSup                                                *
//        PMSInt8 mBalance  (can also be declared as PMSInt16 or PMSInt32)         *
//                                                                             *
//     An ELEMENT class must have the following constructor :                *
//        ELEMENT (const INFO & inInfo) ;                                    *
//                                                                             *
//     An INFO class must have the following method :                        *
//        PMSInt32 compare (const INFO & inInfo) ;                             *
//                                                                             *
//-----------------------------------------------------------------------------*

#include <stdlib.h>
#include <stdio.h>
#include "utilities/M_machine.h"

//-----------------------------------------------------------------------------*
//                                                                             *
//       Rotate left                                                         *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class ELEMENT>
inline void rotateLeft (ELEMENT * & ioPtr) {
//--- Rotate 
  ELEMENT * ptr = ioPtr->mPtrToSup ;
  ioPtr->mPtrToSup = ptr->mPtrToInf ;
  ptr->mPtrToInf = ioPtr ;
//--- Update balance 
  if (ptr->mBalance < 0) {
    ioPtr->mBalance -= ptr->mBalance ;
  }
  ioPtr->mBalance ++ ;
  if (ioPtr->mBalance > 0) {
    ptr->mBalance += ioPtr->mBalance ;
  }
  ptr->mBalance ++ ;
  ioPtr = ptr ;
} 

//-----------------------------------------------------------------------------*
//                                                                             *
//       Rotate right                                                        *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class ELEMENT>
inline void rotateRight (ELEMENT * & ioPtr) {
//--- Rotate 
  ELEMENT * ptr = ioPtr->mPtrToInf ;
  ioPtr->mPtrToInf = ptr->mPtrToSup ;
  ptr->mPtrToSup = ioPtr ;
 //--- Update balance 
  if (ptr->mBalance > 0) {
    ioPtr->mBalance -= ptr->mBalance ;
  }
  ioPtr->mBalance -- ;
  if (ioPtr->mBalance < 0) {
    ptr->mBalance += ioPtr->mBalance ;
  }
  ptr->mBalance-- ;
  ioPtr = ptr ;
}
 
//-----------------------------------------------------------------------------*
//                                                                             *
//       Recursive search and insert                                         *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class ELEMENT, class INFO>
INFO * TF_avltree_search (ELEMENT * ioRootPointer,
                          const INFO & inInfo) {
  INFO * result = (INFO *) NULL ;
  if (ioRootPointer == NULL) {
    result = (INFO *) NULL ;
  }else{
    const PMSInt32 comp = ioRootPointer->mInfo.compare (inInfo) ;
    if (comp > 0) {
      result = TF_avltree_search (ioRootPointer->mPtrToSup, inInfo) ;
    }else if (comp < 0) {
      result = TF_avltree_search (ioRootPointer->mPtrToInf, inInfo) ;
    }else{ // Found
      result = & (ioRootPointer->mInfo) ;
    }
  }
  return result ;
}
 
//-----------------------------------------------------------------------------*
//                                                                             *
//       Recursive search and insert                                         *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class ELEMENT, class INFO>
INFO * recursiveSearchOrInsert (ELEMENT * & ioRootPointer,
                                const INFO & inInfo,
                                bool & outExtension,
                                bool & outInsertionPerformed) {
  INFO * result ;
  if (ioRootPointer == NULL) {
    ioRootPointer = new ELEMENT (inInfo) ;
    result = & (ioRootPointer->mInfo) ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    outInsertionPerformed = false ;
    const PMSInt32 comp = ioRootPointer->mInfo.compare (inInfo) ;
    if (comp > 0) {
      result = recursiveSearchOrInsert (ioRootPointer->mPtrToSup, inInfo, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            ::rotateRight (ioRootPointer->mPtrToSup) ;
          }
          ::rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      result = recursiveSearchOrInsert (ioRootPointer->mPtrToInf, inInfo, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            ::rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          ::rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      result = & (ioRootPointer->mInfo) ;
      outExtension = false;
    }
  }
  return result ;
}
 
//-----------------------------------------------------------------------------*

template <class ELEMENT, class ARG1, class ARG2, class ARG3>
ELEMENT * recursiveSearchOrInsert3 (ELEMENT * & ioRootPointer,
                                    const ARG1 inOperand1,
                                    const ARG2 inOperand2,
                                    const ARG3 inOperand3,
                                    bool & outExtension,
                                    bool & outInsertionPerformed) {
  ELEMENT * result ;
  if (ioRootPointer == NULL) {
    ioRootPointer = new ELEMENT (inOperand1, inOperand2, inOperand3) ;
    result = ioRootPointer ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    outInsertionPerformed = false ;
    const PMSInt32 comp = ioRootPointer->compare (inOperand1, inOperand2, inOperand3) ;
    if (comp > 0) {
      result = recursiveSearchOrInsert3 <ELEMENT, ARG1, ARG2, ARG3>
                 (ioRootPointer->mPtrToSup, inOperand1, inOperand2, inOperand3, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            ::rotateRight (ioRootPointer->mPtrToSup) ;
          }
          ::rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      result = recursiveSearchOrInsert3 <ELEMENT, ARG1, ARG2, ARG3>
                 (ioRootPointer->mPtrToInf, inOperand1, inOperand2, inOperand3, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            ::rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          ::rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      result = ioRootPointer ;
      outExtension = false;
    }
  }
  return result ;
}
 
//-----------------------------------------------------------------------------*

template <class ELEMENT, class INFO, class ARG1, class ARG2, class ARG3>
INFO * recursiveSearchOrInsertInfo3 (ELEMENT * & ioRootPointer,
                                const ARG1 inOperand1,
                                const ARG2 inOperand2,
                                const ARG3 inOperand3,
                                bool & outExtension,
                                bool & outInsertionPerformed) {
  INFO * result ;
  if (ioRootPointer == NULL) {
    ioRootPointer = new ELEMENT (inOperand1, inOperand2, inOperand3) ;
    result = & (ioRootPointer->mInfo) ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    outInsertionPerformed = false ;
    const PMSInt32 comp = ioRootPointer->mInfo.compare (inOperand1, inOperand2, inOperand3) ;
    if (comp > 0) {
      result = recursiveSearchOrInsertInfo3 <ELEMENT, INFO, ARG1, ARG2, ARG3>
                 (ioRootPointer->mPtrToSup, inOperand1, inOperand2, inOperand3, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            ::rotateRight (ioRootPointer->mPtrToSup) ;
          }
          ::rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      result = recursiveSearchOrInsertInfo3 <ELEMENT, INFO, ARG1, ARG2, ARG3>
                 (ioRootPointer->mPtrToInf, inOperand1, inOperand2, inOperand3, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            ::rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          ::rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      result = & (ioRootPointer->mInfo) ;
      outExtension = false;
    }
  }
  return result ;
}
 
//-----------------------------------------------------------------------------*
//                                                                             *
//       Recursive search and insert                                         *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class ELEMENT>
void recursiveInsertElementWithInfo (ELEMENT * & ioRootPointer,
                                     ELEMENT * inElementPointer,
                                     bool & outExtension,
                                     bool & outInsertionPerformed) {
  if (ioRootPointer == NULL) {
    ioRootPointer = inElementPointer ;
    inElementPointer->mPtrToInf = (ELEMENT *) NULL ;
    inElementPointer->mPtrToSup = (ELEMENT *) NULL ;
    inElementPointer->mBalance = 0 ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    const PMSInt32 comp = ioRootPointer->mInfo.compare (inElementPointer->mInfo) ;
    if (comp > 0) {
      recursiveInsertElementWithInfo (ioRootPointer->mPtrToSup, inElementPointer, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            ::rotateRight (ioRootPointer->mPtrToSup) ;
          }
          ::rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      recursiveInsertElementWithInfo (ioRootPointer->mPtrToInf, inElementPointer, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            ::rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          ::rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      outInsertionPerformed = false ;
      outExtension = false;
    }
  }
}

//-----------------------------------------------------------------------------*

template <class ELEMENT>
void recursiveInsertElement (ELEMENT * & ioRootPointer,
                             ELEMENT * const inElementPointer,
                             bool & outExtension,
                             bool & outInsertionPerformed) {
  if (ioRootPointer == NULL) {
    ioRootPointer = inElementPointer ;
    inElementPointer->mPtrToInf = (ELEMENT *) NULL ;
    inElementPointer->mPtrToSup = (ELEMENT *) NULL ;
    inElementPointer->mBalance = 0 ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    const PMSInt32 comp = ioRootPointer->compare (* inElementPointer) ;
    if (comp > 0) {
      recursiveInsertElement (ioRootPointer->mPtrToSup, inElementPointer, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            ::rotateRight (ioRootPointer->mPtrToSup) ;
          }
          ::rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      recursiveInsertElement (ioRootPointer->mPtrToInf, inElementPointer, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            ::rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          ::rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      outInsertionPerformed = false ;
      outExtension = false;
    }
  }
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Verify an AVL tree                                                  *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class ELEMENT, class INFO>
bool recursiveVerifyAVLtree (const ELEMENT * inPointer,
                             const INFO * inInfPointer,
                             const INFO * inSupPointer,
                             const PMSInt32 inMaxLevelToExplore,
                             const PMSInt32 inCurrentLevel,
                             PMSInt32 & outMaxLevels,
                             FILE * inOutputFile) ;

template <class ELEMENT, class INFO>
bool recursiveVerifyAVLtree (const ELEMENT * const inPointer,
                             const INFO * const inInfPointer,
                             const INFO * const inSupPointer,
                             const PMSInt32 inMaxLevelToExplore,
                             const PMSInt32 inCurrentLevel,
                             PMSInt32 & outMaxLevels,
                             FILE * inOutputFile) {
  bool ok = true ;
  if (inPointer == NULL) {
    outMaxLevels = 0 ;
  }else if (inCurrentLevel >= inMaxLevelToExplore) {
    ::fprintf (inOutputFile, "Max level reached.\n") ;
    ok = false ;
  }else{
    if ((inPointer->mBalance < -1) || (inPointer->mBalance > 1)) {
      ::fprintf (inOutputFile, "Balance error (%ld).\n", inPointer->mBalance) ;
       ok = false ;
    }
    if ((inInfPointer != NULL) && (inInfPointer->compare (inPointer->mInfo) <= 0)) {
      ::fprintf (inOutputFile, "inf error.\n") ;
      ok = false ;
    }
    if ((inSupPointer != NULL) && (inSupPointer->compare (inPointer->mInfo) >= 0)) {
      ::fprintf (inOutputFile, "inf error.\n") ;
      ok = false ;
    }
    PMSInt32 max1, max2 ;
    const bool ok1 = recursiveVerifyAVLtree (inPointer->mPtrToInf,
                                             inInfPointer,
                                             & inPointer->mInfo,
                                             inMaxLevelToExplore,
                                             inCurrentLevel ,
                                             max1,
                                             inOutputFile) ;
    const bool ok2 = recursiveVerifyAVLtree (inPointer->mPtrToSup,
                                             & inPointer->mInfo,
                                             inSupPointer,
                                             inMaxLevelToExplore,
                                             inCurrentLevel + 1,
                                             max2,
                                             inOutputFile) ;
    ok = ok && ok1 && ok2 ;
    const PMSInt32 balance = max1 - max2 ;
    if (balance != inPointer->mBalance) {
      ::fprintf (inOutputFile, "Check balance error (inPointer->mBalance:%ld, balance:%ld).\n",
                inPointer->mBalance, balance) ;
      ok = false ;
    }
    outMaxLevels = ((max1 < max2) ? max2 : max1) + 1 ;
  }
  return ok ;
}

//-----------------------------------------------------------------------------*

template <class ELEMENT, class INFO>
bool verifyAVLtree (const ELEMENT * inRootPointer,
                    const PMSInt32 inMaxLevelsToExplore,
                    PMSInt32 & outMaxLevels,
                    FILE * inOutputFile) {
  return recursiveVerifyAVLtree (inRootPointer,
                                 (INFO *) NULL,
                                 (INFO *) NULL,
                                 inMaxLevelsToExplore,
                                 0, // Current level
                                 outMaxLevels,
                                 inOutputFile) ;
}

//-----------------------------------------------------------------------------*

#endif
