//---------------------------------------------------------------------------*
//                                                                           *
//  C_String : an implementation of fully dynamic character string           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1997, ..., 2011 Pierre Molinaro.                           *
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

#include "files/C_TextFileWrite.h"
#include "utilities/MF_MemoryControl.h"
#include "utilities/TF_sup.h"
#include "utilities/md5.h"
#include "utilities/C_SharedObject.h"
#include "strings/unicode_string_routines.h"
#include "strings/unicode_character_cpp.h"
#include "collections/TC_UniqueArray2.h"

//---------------------------------------------------------------------------*

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>

//---------------------------------------------------------------------------*

#ifdef __MINGW32__
  #include <sys/stat.h>
#endif

#ifdef __MWERKS__
  #include <unistd.h>
  #ifdef COMPILE_FOR_WIN32
    #include <unix.h>
  #endif
#endif

#ifdef UNIX_TOOL
  #include <unistd.h>
#endif

#ifdef TARGET_API_MAC_CARBON
  #include <stat.h>
#endif

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cEmbeddedString
#endif

//---------------------------------------------------------------------------*

static const utf32 kEmptyUTF32String [1] = {TO_UNICODE (0)} ;

//---------------------------------------------------------------------------*

class cEmbeddedString : public C_SharedObject {
  public : PMSInt32 mCapacity ; // Maximun allowed length of the following C string
  public : PMSInt32 mLength ; // Current length of the following C string
  public : char * mEncodedCString ;
  public : utf32 * mString ; // Zero terminated string

  public : cEmbeddedString (const PMSInt32 inCapacity COMMA_LOCATION_ARGS) ;

  public : cEmbeddedString (const cEmbeddedString * inEmbeddedString,
                            const PMSInt32 inCapacity
                            COMMA_LOCATION_ARGS) ;

  public : ~cEmbeddedString (void) ;

//--- No copy
  private : cEmbeddedString (const cEmbeddedString &) ;
  private : cEmbeddedString & operator = (const cEmbeddedString &) ;

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : void checkEmbeddedString (LOCATION_ARGS) const ;
  #endif

  public : void reallocEmbeddedString (const PMSInt32 inCapacity) ;
} ;

//---------------------------------------------------------------------------*

static PMSInt32 stringGoodSize (const PMSInt32 inCurrentCapacity,
                                const PMSInt32 inCapacity) {
  PMSInt32 newCapacity = (inCurrentCapacity < 128) ? 128 : inCurrentCapacity ;
  while (newCapacity < inCapacity) {
    newCapacity <<= 1 ;
  }
  return newCapacity ;
}

//---------------------------------------------------------------------------*

cEmbeddedString::cEmbeddedString (const PMSInt32 inCapacity COMMA_LOCATION_ARGS) :
C_SharedObject (THERE),
mCapacity (0),
mLength (0),
mEncodedCString (NULL),
mString (NULL) {
  const PMSInt32 newCapacity = stringGoodSize (0, inCapacity) ;
  macroMyNewPODArray (mString, utf32, newCapacity) ;
  mCapacity = newCapacity ;
  mString [0] = TO_UNICODE ('\0') ;
}

//---------------------------------------------------------------------------*

cEmbeddedString::cEmbeddedString (const cEmbeddedString * inEmbeddedString,
                                  const PMSInt32 inCapacity
                                  COMMA_LOCATION_ARGS) :
C_SharedObject (THERE),
mCapacity (0),
mLength (0),
mEncodedCString (NULL),
mString (NULL) {
  macroValidPointer (inEmbeddedString) ;
  macroValidPointer (inEmbeddedString->mString) ;
  MF_Assert (inCapacity > inEmbeddedString->mLength, "inCapacity (%lld) < inEmbeddedString->mLength (%lld)", inCapacity, inEmbeddedString->mLength) ;
  const PMSInt32 newCapacity = stringGoodSize (inEmbeddedString->mCapacity, inCapacity) ;
  macroMyNewPODArray (mString, utf32, newCapacity) ;
  mCapacity = newCapacity ;
  MF_Assert (inEmbeddedString->mLength < mCapacity, "inEmbeddedString->mLength (%lld) >= mCapacity (%lld)", inEmbeddedString->mLength, mCapacity) ;
  for (PMSInt32 i=0 ; i<=inEmbeddedString->mLength ; i++) {
    mString [i] = inEmbeddedString->mString [i] ;
  }
  mLength = inEmbeddedString->mLength ;
}

//---------------------------------------------------------------------------*

cEmbeddedString::~cEmbeddedString (void) {
  macroMyDeletePODArray (mEncodedCString) ;
  macroMyDeletePODArray (mString) ;
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cEmbeddedString::checkEmbeddedString (LOCATION_ARGS) const {
    MF_Assert (retainCount () >= 1, "retainCount () == %lld < 1", retainCount (), 0) ;
    if (mCapacity == 0) {
      assert_routine (UNICODE_VALUE (mString [0]) == '\0', "mString [0] (%lld) != '\\0'",
                      (PMSInt32) UNICODE_VALUE (mString [0]), '\0' COMMA_THERE) ;
      assert_routine (mLength == 0, "mLength (%ld) != 0", mLength, 0 COMMA_THERE) ;
    }else{
      assert_routine (mLength <= mCapacity, "mLength (%ld) > mCapacity (%ld)", mLength, mCapacity COMMA_THERE) ;
      assert_routine (UNICODE_VALUE (mString [mLength]) == '\0',
                      "mString [mLength] == %ld != '\\0'",
                      (PMSInt32) UNICODE_VALUE (mString [mLength]), '\0' COMMA_THERE) ;
      if (mEncodedCString != NULL) {
 //       macroValidPointer (mEncodedCString) ; §
        for (PMSInt32 i=0 ; i<= mLength ; i++) {
          assert_routine (UNICODE_VALUE (mString [i]) == (unsigned) mEncodedCString [i],
                          "mString [i] (%ld) != mEncodedCString [i] (%ld)",
                          UNICODE_VALUE (mString [i]), (unsigned) mEncodedCString [i] COMMA_THERE) ;
        }
      }
    }
  }
#endif

//---------------------------------------------------------------------------*

void cEmbeddedString::reallocEmbeddedString (const PMSInt32 inCapacity) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkEmbeddedString (HERE) ;
  #endif
  if (inCapacity > mCapacity) {
    const PMSInt32 newCapacity = stringGoodSize (mCapacity, inCapacity) ;
    macroMyReallocPODArray (mString, utf32, newCapacity) ;
    mCapacity = newCapacity ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkEmbeddedString (HERE) ;
    #endif
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors & destructor
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   C O N S T R U C T O R S                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

C_String::C_String (void) :
mEmbeddedString (NULL) {
}

//---------------------------------------------------------------------------*

C_String::C_String (const char * inCstring) :
mEmbeddedString (NULL) {
  if (inCstring != NULL) {
    genericCharArrayOutput (inCstring, (PMSInt32) (strlen (inCstring) & PMUINT32_MAX)) ;
  }
}

//---------------------------------------------------------------------------*

C_String::C_String (const utf32 * inUTF32String) :
mEmbeddedString (NULL) {
  if (inUTF32String != NULL) {
    genericUnicodeArrayOutput (inUTF32String, utf32_strlen (inUTF32String)) ;
  }
}

//---------------------------------------------------------------------------*

C_String::C_String (const C_String & inSource) : // Copy constructor
AC_OutputStream (inSource),
mEmbeddedString (NULL) {
  macroAssignSharedObject (mEmbeddedString, inSource.mEmbeddedString) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   D E S T R U C T O R                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

C_String::~C_String (void) {
  macroDetachSharedObject (mEmbeddedString) ;
}

//---------------------------------------------------------------------------*

PMSInt32 C_String::capacity (void) const {
  return (mEmbeddedString == NULL) ? 0 : mEmbeddedString->mCapacity ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   A S S I G N M E N T    O P E R A T O R S                                *
//                                                                           *
//---------------------------------------------------------------------------*

C_String & C_String::operator = (const C_String & inSource) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkString (HERE) ;
    inSource.checkString (HERE) ;
  #endif
  macroAssignSharedObject (mEmbeddedString, inSource.mEmbeddedString) ;
  return * this ;
}

//---------------------------------------------------------------------------*

void C_String::releaseString (void) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkString (HERE) ;
  #endif
  macroDetachSharedObject (mEmbeddedString) ;
  mEmbeddedString = NULL ;
}

//---------------------------------------------------------------------------*

PMUInt32 C_String::hash (void) const {
  PMUInt32 h = 0 ;
  if (mEmbeddedString != NULL) {
    for (PMSInt32 i=0 ; i<mEmbeddedString->mLength ; i++) {
      h <<= 3 ;
      h ^= UNICODE_VALUE (mEmbeddedString->mString [i]) ;
    }
  }
  return h ;
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void C_String::checkString (LOCATION_ARGS) const {
    if (mEmbeddedString != NULL) {
      macroValidSharedObject (mEmbeddedString, cEmbeddedString) ;
      mEmbeddedString->checkEmbeddedString (THERE) ;
    }
  }
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   G E T    M E T H O D S                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

utf32 C_String::operator () (const PMSInt32 inIndex COMMA_LOCATION_ARGS) const {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkString (THERE) ;
  #endif
  macroValidSharedObjectThere (mEmbeddedString, cEmbeddedString) ;
  MF_AssertThere (inIndex >= 0, "inIndex (%ld) < 0", inIndex, 0) ;
  MF_AssertThere (inIndex < mEmbeddedString->mLength,
                 "inIndex (%ld) >= string length (%ld)",
                 inIndex, mEmbeddedString->mLength) ;
  return mEmbeddedString->mString [inIndex] ;
}

//---------------------------------------------------------------------------*

utf32 C_String::readCharOrNul (const PMSInt32 inIndex COMMA_LOCATION_ARGS) const {
  MF_AssertThere (inIndex >= 0, "inIndex (%ld) < 0", inIndex, 0) ;
  return ((mEmbeddedString == NULL) || (inIndex >= mEmbeddedString->mLength))
    ? TO_UNICODE ('\0')
    : mEmbeddedString->mString [inIndex] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   lastCharacter                                                           *
//                                                                           *
//---------------------------------------------------------------------------*

utf32 C_String::lastCharacter (LOCATION_ARGS) const {
  const PMSInt32 stringLength = mEmbeddedString->mLength ;
  MF_AssertThere (stringLength > 0, "length == 0", 0, 0) ;
  return (stringLength == 0) ? TO_UNICODE ('\0') : mEmbeddedString->mString [stringLength - 1] ;
}

//---------------------------------------------------------------------------*

PMSInt32 C_String::length (void) const {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkString (HERE) ;
  #endif
  return (mEmbeddedString == NULL) ? 0 : mEmbeddedString->mLength ;
}

//---------------------------------------------------------------------------*

const char * C_String::cString (UNUSED_LOCATION_ARGS) const {
  const char * result = "" ;
  if (NULL != mEmbeddedString) {
    macroValidSharedObject (mEmbeddedString, cEmbeddedString) ;
    if (NULL == mEmbeddedString->mEncodedCString) {
      PMUInt32 allocatedSize = mEmbeddedString->mLength + 1 ;
      macroMyReallocPODArray (mEmbeddedString->mEncodedCString, char, allocatedSize) ;
      PMUInt32 idx = 0 ;
      for (PMSInt32 i=0 ; i<mEmbeddedString->mLength ; i++) {
        char buffer [5] ;
        const PMSInt32 n = UTF8StringFromUTF32Character (mEmbeddedString->mString [i], buffer) ;
        for (PMSInt32 j=0 ; j<n ; j++) {
          if (allocatedSize == idx) {
            allocatedSize *= 2 ;
            macroMyReallocPODArray (mEmbeddedString->mEncodedCString, char, allocatedSize) ;
          }
          mEmbeddedString->mEncodedCString [idx] = buffer [j] ;
          idx ++ ;
        }
      }
    //---
      if (allocatedSize == idx) {
        allocatedSize *= 2 ;
        macroMyReallocPODArray (mEmbeddedString->mEncodedCString, char, allocatedSize) ;
      }
      mEmbeddedString->mEncodedCString [idx] = '\0' ;
    }
    result = mEmbeddedString->mEncodedCString ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

const utf32 * C_String::utf32String (UNUSED_LOCATION_ARGS) const {
  const utf32 * result = kEmptyUTF32String ;
  if (NULL != mEmbeddedString) {
    result = mEmbeddedString->mString ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Methods that change string
#endif

//---------------------------------------------------------------------------*

void C_String::insulateEmbeddedString (const PMSInt32 inNewCapacity) {
  if (mEmbeddedString == NULL) {
    macroMyNew (mEmbeddedString, cEmbeddedString (inNewCapacity COMMA_HERE)) ;
  }else{
    macroValidSharedObject (mEmbeddedString, cEmbeddedString) ;
    if (mEmbeddedString->retainCount () == 1) {
      macroMyDeletePODArray (mEmbeddedString->mEncodedCString) ;
      mEmbeddedString->reallocEmbeddedString (inNewCapacity) ;
    }else{
      cEmbeddedString * p = NULL ;
      macroMyNew (p, cEmbeddedString (mEmbeddedString, inNewCapacity COMMA_HERE)) ;
      macroAssignSharedObject (mEmbeddedString, p) ;
      macroDetachSharedObject (p) ;
    }  
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkString (HERE) ;
    #endif
  }
  MF_Assert (capacity () >= inNewCapacity, "capacity (%lld) < inNewCapacity (%lld)", capacity (), inNewCapacity) ;
  macroValidSharedObject (mEmbeddedString, cEmbeddedString) ;
  macroUniqueSharedObject (mEmbeddedString) ;
}

//---------------------------------------------------------------------------*

void C_String::setLengthToZero (void) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkString (HERE) ;
  #endif
  if (mEmbeddedString != NULL) {
    if (mEmbeddedString->retainCount () == 1) {
      macroMyDeletePODArray (mEmbeddedString->mEncodedCString) ;
      mEmbeddedString->mLength = 0 ;
      mEmbeddedString->mString [0] = TO_UNICODE ('\0') ;
    }else{
      macroDetachSharedObject (mEmbeddedString) ;
      mEmbeddedString = NULL ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkString (HERE) ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//   S E T   F R O M    S T R I N G                                          *
//                                                                           *
//---------------------------------------------------------------------------*

void C_String::setFromString (const C_String & inString) {
  if (this != & inString) {
    macroAssignSharedObject (mEmbeddedString, inString.mEmbeddedString) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//   S E T    C A P A C I T Y                                                *
//                                                                           *
//---------------------------------------------------------------------------*

void C_String::setCapacity (const PMSInt32 inNewCapacity) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkString (HERE) ;
  #endif
  if (mEmbeddedString != NULL) {
    macroMyDeletePODArray (mEmbeddedString->mEncodedCString) ;
    if ((mEmbeddedString->mLength < inNewCapacity) && (mEmbeddedString->mCapacity < inNewCapacity)) {
      if (mEmbeddedString->retainCount () == 1) {
        macroMyDeletePODArray (mEmbeddedString->mEncodedCString) ;
        mEmbeddedString->reallocEmbeddedString (inNewCapacity) ;
      }else{
        cEmbeddedString * p = NULL ;
        macroMyNew (p, cEmbeddedString (mEmbeddedString, inNewCapacity COMMA_HERE)) ;
        macroAssignSharedObject (mEmbeddedString, p)  ;
        macroDetachSharedObject (p) ;
      }
      #ifndef DO_NOT_GENERATE_CHECKINGS
        checkString (HERE) ;
      #endif
    }
  }else if (inNewCapacity > 0) {
    macroMyNew (mEmbeddedString, cEmbeddedString (inNewCapacity COMMA_HERE)) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkString (HERE) ;
    #endif
  }
  MF_Assert (capacity () >= inNewCapacity, "capacity (%lld) < inNewCapacity (%lld)", capacity (), inNewCapacity) ;
  if (mEmbeddedString != NULL) {
    macroValidSharedObject (mEmbeddedString, cEmbeddedString) ;
    macroUniqueSharedObject (mEmbeddedString) ;
  }
}

//---------------------------------------------------------------------------*

void C_String::
performActualUnicodeArrayOutput (const utf32 * inUTF32CharArray,
                                 const PMSInt32 inArrayCount) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkString (HERE) ;
  #endif
  if (inArrayCount > 0) {
    const PMSInt32 kNewLength = length () + inArrayCount ;
    insulateEmbeddedString (kNewLength + 1) ;
    MF_Assert (mEmbeddedString->retainCount () == 1, "mEmbeddedString->retainCount () == (%lld) != 1", mEmbeddedString->retainCount () == 1, 0) ;
    for (PMSInt32 i=0 ; i<inArrayCount ; i++) {
      mEmbeddedString->mString [mEmbeddedString->mLength + i] = inUTF32CharArray [i] ;
    }
    mEmbeddedString->mLength = kNewLength ;
    mEmbeddedString->mString [kNewLength] = TO_UNICODE ('\0') ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkString (HERE) ;
    #endif
    MF_Assert (capacity () > kNewLength, "capacity (%lld) <= kNewLength (%lld)", capacity (), kNewLength) ;
    macroUniqueSharedObject (mEmbeddedString) ;
  }
}

//---------------------------------------------------------------------------*

void C_String::performActualCharArrayOutput (const char * inCharArray,
                                             const PMSInt32 inArrayCount) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkString (HERE) ;
  #endif
  if (inArrayCount != 0) {
    insulateEmbeddedString (length () + inArrayCount + 1) ;
    const PMUInt8 * p = (const PMUInt8 *) inCharArray ;
    const PMUInt8 * pMax = p + inArrayCount ;
    PMSInt32 newLength = mEmbeddedString->mLength ;
    while (p != pMax) {
      if ((* p) < 0x80) {
        mEmbeddedString->mString [newLength] = TO_UNICODE (* p) ;
        p ++ ;
        newLength ++ ;
      }else{
        bool ok = true ;
        const utf32 unicodeChar = utf32CharacterForPointer (p, pMax, ok) ;
        mEmbeddedString->mString [newLength] = unicodeChar ;
        newLength ++ ;
      }
    }
    mEmbeddedString->mLength = newLength ;
    mEmbeddedString->mString [newLength] = TO_UNICODE ('\0') ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkString (HERE) ;
    #endif
    MF_Assert (capacity () > newLength, "capacity (%lld) <= kNewLength (%lld)", capacity (), newLength) ;
    macroUniqueSharedObject (mEmbeddedString) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//   setCharacterAtIndex                                                     *
//                                                                           *
//---------------------------------------------------------------------------*


void C_String::
setUnicodeCharacterAtIndex (const utf32 inCharacter,
                            const PMSInt32 inIndex
                            COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkString (HERE) ;
  #endif
  macroValidPointerThere (mEmbeddedString) ;
  MF_AssertThere (inIndex >= 0, "inIndex (%ld) < 0", inIndex, 0) ;
  MF_AssertThere (inIndex < mEmbeddedString->mLength,
                  "inIndex (%ld) >= string length (%ld)",
                  inIndex, mEmbeddedString->mLength) ;
  insulateEmbeddedString (mEmbeddedString->mCapacity) ;
  mEmbeddedString->mString [inIndex] = inCharacter ;
  macroUniqueSharedObject (mEmbeddedString) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   S U P P R E S S    C H A R A C T E R S                                  *
//                                                                           *
//---------------------------------------------------------------------------*

void C_String::
suppress (const PMSInt32 inLocation,
          const PMSInt32 inLength COMMA_LOCATION_ARGS) {
  if (inLength > 0) {
    insulateEmbeddedString (mEmbeddedString->mCapacity) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkString (HERE) ;
    #endif
    macroValidPointerThere (mEmbeddedString) ;
    MF_AssertThere (inLocation >= 0, "inLocation (%ld) < 0", inLocation, 0) ;
    MF_AssertThere (inLocation <= mEmbeddedString->mLength,
                   "inLocation (%ld) > mLength (%ld)",
                    inLocation, mEmbeddedString->mLength) ;
    MF_AssertThere (inLength <= mEmbeddedString->mLength,
                   "inLength (%ld) > string length (%ld)",
                    inLength, mEmbeddedString->mLength) ;
    const PMSInt32 longueurAdeplacer = 1 + mEmbeddedString->mLength - inLength - inLocation ;
    if ((inLocation >= 0) && (longueurAdeplacer > 0)) {
      ::memmove (& mEmbeddedString->mString [inLocation],
                 & mEmbeddedString->mString [inLocation + inLength],
                 ((size_t) longueurAdeplacer) * sizeof (utf32)) ;
      MF_Assert (mEmbeddedString->mLength >= inLength,
               "mLength (%lld) < inLength (%lld)",
                mEmbeddedString->mLength, inLength) ;
      mEmbeddedString->mLength -= inLength ;
      #ifndef DO_NOT_GENERATE_CHECKINGS
        checkString (HERE) ;
      #endif
      macroUniqueSharedObject (mEmbeddedString) ;
    }
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark =============
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   G E T    L I N E S    A R R A Y                                         *
//                                                                           *
//---------------------------------------------------------------------------*

void C_String::getLinesArray (TC_UniqueArray <C_String> & outStringArray) const {
  const PMSInt32 currentStringLength = length () ;
  if (currentStringLength > 0) {
    PMSInt32 index = outStringArray.count () ;
    outStringArray.addObject (C_String ()) ;
    typedef enum {kAppendToCurrentLine, kGotCarriageReturn, kGotLineFeed} enumState ;
    enumState state = kAppendToCurrentLine ;
    for (PMSInt32 i=0 ; i<currentStringLength ; i++) {
      const utf32 c = mEmbeddedString->mString [i] ;
      switch (state) {
      case kAppendToCurrentLine :
        switch (UNICODE_VALUE (c)) {
        case '\n' : // LF
          state = kGotLineFeed ;
          break ;
        case '\r' : // CR
          state = kGotCarriageReturn ;
          break ;
        default: // Other character
          outStringArray (index COMMA_HERE).appendUnicodeCharacter (c COMMA_HERE) ;
        }
        break ;
      case kGotCarriageReturn :
        switch (UNICODE_VALUE (c)) {
        case '\n' : // LF
          state = kGotLineFeed ;
          break ;
        case '\r' : // CR
          outStringArray.addObject (C_String ()) ;
          index ++ ;
          break ;
        default: // Other character
          outStringArray.addObject (C_String ()) ;
          index ++ ;
          outStringArray (index COMMA_HERE).appendUnicodeCharacter (c COMMA_HERE) ;
          state = kAppendToCurrentLine ;
        }
        break ;
      case kGotLineFeed :
        switch (UNICODE_VALUE (c)) {
        case '\n' : // LF
          outStringArray.addObject (C_String ()) ;
          index ++ ;
          break ;
        case '\r' : // CR
          outStringArray.addObject (C_String ()) ;
          index ++ ;
          state = kGotCarriageReturn ;
          break ;
        default: // Other character
          outStringArray.addObject (C_String ()) ;
          index ++ ;
          outStringArray (index COMMA_HERE).appendUnicodeCharacter (c COMMA_HERE) ;
          state = kAppendToCurrentLine ;
        }
        break ;     
      }
    }  
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//   C O N T A I N S   S T R I N G                                           *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_String::containsString (const C_String & inSearchedString) const {
  const utf32 * source = utf32String (HERE) ;
  bool contains = source != NULL ;
  if (contains) {
    const utf32 * searchedString = inSearchedString.utf32String (HERE) ;
    contains = searchedString == NULL ;
    if (! contains) {
      contains = ::utf32_strstr (source, searchedString) != NULL ;
    }
  }
  return contains ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   componentsSeparatedByString                                             *
//                                                                           *
//---------------------------------------------------------------------------*

void C_String::
componentsSeparatedByString (const C_String & inSeparatorString,
                             TC_UniqueArray <C_String> & outResult) const {
  outResult.removeAllObjects () ;
  const utf32 * sourcePtr = utf32String (HERE) ;
  if (sourcePtr == NULL) {
    outResult.addObject (C_String ()) ;
  }else{
    const PMSInt32 splitStringLength = inSeparatorString.length () ;
    const utf32 * separator = inSeparatorString.utf32String (HERE) ;
    if (splitStringLength > 0) {
      const utf32 * p = ::utf32_strstr (sourcePtr, separator) ;
      while (p != NULL) {
        C_String s ;
        s.genericUnicodeArrayOutput (sourcePtr, (PMSInt32) ((p - sourcePtr) & PMUINT32_MAX)) ;
        outResult.addObject (s) ;
        sourcePtr = p + splitStringLength ;
        p = ::utf32_strstr (sourcePtr, separator) ;
      }
    }
    outResult.addObject (C_String (sourcePtr)) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//   componentsJoinedByString                                                *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::
componentsJoinedByString (const TC_UniqueArray <C_String> & inComponentArray,
                          const C_String & inSeparator) {
  C_String result ;
  if (inComponentArray.count () > 0) {
    result << (inComponentArray (0 COMMA_HERE)) ;
    for (PMSInt32 i=1 ; i<inComponentArray.count () ; i++) {
      result << (inSeparator) ;
      result << (inComponentArray (i COMMA_HERE)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   stringByDeletingTailFromString                                          *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::
stringByDeletingTailFromString (const C_String & inSearchedString) const {
  C_String result = * this ;
  const PMSInt32 searchedStringLength = inSearchedString.length () ;
  if (searchedStringLength > 0) {
    const utf32 * sourcePtr = utf32String (HERE) ;
    const utf32 * p = ::utf32_strstr (sourcePtr,
                                      inSearchedString.utf32String (HERE)) ;
    if (p != NULL) {
      result.setLengthToZero () ;
      result.genericUnicodeArrayOutput (sourcePtr, (PMSInt32) ((p - sourcePtr) & PMUINT32_MAX)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   S U B S T I T U T E    C H A R A C T E R    B Y    S T R I N G          *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Substitute 'inCharacter' by 'inString' ; if the character occurs twice, suppress one

C_String C_String::
stringByReplacingCharacterByString (const utf32 inCharacter,
                                    const C_String & inString) const {
  const PMSInt32 stringLength = length () ;
  C_String resultingString ;
  bool previousCharIsSubstituteChar = false ;
  for (PMSInt32 i=0 ; i<stringLength ; i++) {
    const utf32 c = ((*this).operator () (i COMMA_HERE)) ;
    if (previousCharIsSubstituteChar) {
      if (UNICODE_VALUE (c) == UNICODE_VALUE (inCharacter)) {
        resultingString.appendUnicodeCharacter (inCharacter COMMA_HERE) ;
      }else{
        resultingString << (inString) ;
        resultingString.appendUnicodeCharacter (c COMMA_HERE) ;
      }
      previousCharIsSubstituteChar = false ;    
    }else if (UNICODE_VALUE (c) == UNICODE_VALUE (inCharacter)) {
      previousCharIsSubstituteChar = true ;
    }else{
      resultingString.appendUnicodeCharacter (c COMMA_HERE) ;
    }
  }
  if (previousCharIsSubstituteChar) {
    resultingString << (inString) ;
  }
//--- Return
  return resultingString ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   S U B S T I T U T E    S T R I N G    B Y    S T R I N G                *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::
stringByReplacingStringByString (const C_String inSearchedString,
                                 const C_String & inReplacementString,
                                 PMUInt32 & outReplacementCount,
                                 bool & outOk
                                 COMMA_UNUSED_LOCATION_ARGS) const {
  C_String result ;
  outReplacementCount = 0 ;
  outOk = inSearchedString.length () != 0 ;
  if (outOk) {
    //printf ("SOURCE STRING: '%s' (length %d)\n", cString (HERE), length ()) ; 
    //printf ("SEARCHED STRING: '%s' (length %d)\n", inSearchedString.cString (HERE), inSearchedString.length (HERE)) ; 
    //printf ("REPLACEMENT STRING '%s'\n", inReplacementString.cString (HERE)) ; 
    const utf32 * sourceString = utf32String (HERE) ;
    const PMSInt32 sourceLength = length () ;
    const utf32 * searchedString = inSearchedString.utf32String (HERE) ;
    const PMSInt32 searchedStringLength = inSearchedString.length () ;
    PMSInt32 index = 0 ;
    while (index <= (sourceLength - searchedStringLength)) {
      const bool found = utf32_strncmp (& sourceString [index], searchedString, searchedStringLength) == 0 ;
      //printf ("AT INDEX %d, found: %d\n", index, found) ;
      if (found) {
        result << (inReplacementString) ;
        index += searchedStringLength ;
        outReplacementCount ++ ;
      }else{
        result.appendUnicodeCharacter (sourceString [index] COMMA_HERE) ;
        index ++ ;
      }
    }
    result.appendUTF32String (& sourceString [index]) ;
    //printf ("RESULT STRING: '%s'\n", result.cString (HERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   G E T    L A S T   O C C U R R E N C E   O F   A   C H A R              *
//                                                                           *
//---------------------------------------------------------------------------*

PMSInt32 C_String::
lastOccurrenceIndexOfChar (const utf32 inChar) const {
  PMSInt32 result = length () ;
  const utf32 * ptr = utf32String (HERE) ;
  bool notFound = true ;
  while ((result > 0) && notFound) {
    result -- ;
    notFound = UNICODE_VALUE (ptr [result]) != UNICODE_VALUE (inChar) ;
  }
  if (notFound) {
    result = -1 ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_String C_String::
subString (const PMSInt32 inStartIndex,
           const PMSInt32 inLength) const {
  C_String s ;
  if (inLength > 0) {
    PMSInt32 last = inStartIndex + inLength ;
    const PMSInt32 receiver_length = length () ;
    if (last > receiver_length) {
      last = receiver_length ;
    }
    const utf32 * ptr = utf32String (HERE) ;
    for (PMSInt32 i=inStartIndex ; i<last ; i++) {
      s.appendUnicodeCharacter (ptr [i] COMMA_HERE) ;
    }
  }
  return s ;
}

//---------------------------------------------------------------------------*

C_String C_String::
stringByCapitalizingFirstCharacter (void) const {
  C_String s ;
  const PMSInt32 receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  const utf32 * ptr = utf32String (HERE) ;
  if (receiver_length > 0) {
    s.appendUnicodeCharacter (unicodeToUpper (ptr [0]) COMMA_HERE) ;
    for (PMSInt32 i=1 ; i<receiver_length ; i++) {
      s.appendUnicodeCharacter (ptr [i] COMMA_HERE) ;
    }
  }
  return s ;
}

//---------------------------------------------------------------------------*

C_String C_String::
lowercaseString (void) const {
  C_String s ;
  const PMSInt32 receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  const utf32 * ptr = utf32String (HERE) ;
  for (PMSInt32 i=0 ; i<receiver_length ; i++) {
    s.appendUnicodeCharacter (unicodeToLower (ptr [i]) COMMA_HERE) ;
  }
  return s ;
}

//---------------------------------------------------------------------------*

C_String C_String::
stringByTrimmingWhiteSpaces (void) const {
  C_String s ;
  const PMSInt32 receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  const utf32 * ptr = utf32String (HERE) ;
//--- Trim left
  PMSInt32 idx = 0 ;
  while ((idx < receiver_length) && ((UNICODE_VALUE (ptr [idx]) == ' ') || (UNICODE_VALUE (ptr [idx]) == '\n'))) {
    idx ++ ;
  }
//--- Trim and replace
  bool isCurrentlyTrimming = false ;
  while (idx < receiver_length) {
    const utf32 c = ptr [idx] ;
    if ((UNICODE_VALUE (c) == ' ') || (UNICODE_VALUE (c) == '\n')) {
      isCurrentlyTrimming = true ;
    }else{
      if (isCurrentlyTrimming) {
        s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
        isCurrentlyTrimming = false ;
      }
      s.appendUnicodeCharacter (c COMMA_HERE) ;
    }
    idx ++ ;
  }
  return s ;
}

//---------------------------------------------------------------------------*

C_String C_String::
uppercaseString (void) const {
  C_String s ;
  const PMSInt32 receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  const utf32 * ptr = utf32String (HERE) ;
  for (PMSInt32 i=0 ; i<receiver_length ; i++) {
    s.appendUnicodeCharacter (unicodeToUpper (ptr [i]) COMMA_HERE) ;
  }
  return s ;
}

//---------------------------------------------------------------------------*

C_String C_String::
reversedString (void) const {
  C_String s ;
  const PMSInt32 receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  const utf32 * ptr = utf32String (HERE) ;
  for (PMSInt32 i=receiver_length-1 ; i>=0 ; i--) {
    s.appendUnicodeCharacter (ptr [i] COMMA_HERE) ;
  }
  return s ;
}

//---------------------------------------------------------------------------*

PMUInt32 C_String::currentColumn (void) const {
  PMUInt32 result = 0 ;
  bool found = false ;
  const PMSInt32 receiver_length = length () ;
  const utf32 * ptr = utf32String (HERE) ;
  for (PMSInt32 i=receiver_length-1 ; (i>=0) && ! found ; i--) {
    found = UNICODE_VALUE (ptr [i]) == '\n' ;
    if (! found) {
      result ++ ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

void C_String::appendSpacesUntilColumn (const PMUInt32 inColumn) {
  for (PMUInt32 i=currentColumn () ; i<inColumn ; i++) {
    appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
  }
}

//---------------------------------------------------------------------------*

C_String C_String::
stringWithRepeatedCharacter (const utf32 inRepeatedCharacter,
                             const PMUInt32 inCount) {
  C_String result ;
  for (PMUInt32 i=0 ; i<inCount ; i++) {
    result.appendUnicodeCharacter (inRepeatedCharacter COMMA_HERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_String C_String::
identifierRepresentation (void) const {
  C_String s ;
  const PMSInt32 receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  const utf32 * ptr = utf32String (HERE) ;
  for (PMSInt32 i=0 ; i<receiver_length ; i++) {
    const utf32 c = ptr [i] ;
    if (isalpha ((int) UNICODE_VALUE (c))) {
      s.appendUnicodeCharacter (c COMMA_HERE) ;
    }else{
      s.appendUnicodeCharacter (TO_UNICODE ('_') COMMA_HERE) ;
      s.appendUnsignedHex (UNICODE_VALUE (c)) ;
      s.appendUnicodeCharacter (TO_UNICODE ('_') COMMA_HERE) ;
    }
  }
  return s ;
}

//---------------------------------------------------------------------------*

C_String C_String::utf32Representation (void) const {
  C_String result ;
  result.appendUTF32LiteralStringConstant (*this) ;
  return result ;
}

//---------------------------------------------------------------------------*

C_String C_String::HTMLRepresentation (void) const {
  C_String result ;
  for (PMSInt32 i=0 ; i<length () ; i++) {
    const utf32 c = this->operator () (i COMMA_HERE) ;
    if (UNICODE_VALUE (c) == '&') {
      result << "&amp;" ;
    }else if (UNICODE_VALUE (c) == '"') {
      result << "&quot;" ;
    }else if (UNICODE_VALUE (c) == '<') {
      result << "&lt;" ;
    }else if (UNICODE_VALUE (c) == '>') {
      result << "&gt;" ;
    }else{
      result.appendUnicodeCharacter (c COMMA_HERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   S T R I N G    C O M P A R E                                            *
//                                                                           *
//---------------------------------------------------------------------------*

PMSInt32 C_String::compare (const char * const inCstring) const {
  PMSInt32 result = 0 ;
  const utf32 * myStringPtr = utf32String (HERE) ;
  if (inCstring == NULL) {
    result = 1 ;
  }else if (myStringPtr == NULL) {
    result = -1 ;
  }else{
    result = ::utf32_char_strcmp (myStringPtr, inCstring) ; // Never call strcmp with NULL pointer(s) !
  }
  return result ;
}

//---------------------------------------------------------------------------*

PMSInt32 C_String::compare (const C_String & inString) const {
  PMSInt32 result = 0 ;
  const utf32 * myStringPtr = utf32String (HERE) ;
  const utf32 * otherStringPtr = inString.utf32String (HERE) ;
  if (myStringPtr == NULL) {
    result = 1 ;
  }else if (otherStringPtr == NULL) {
    result = -1 ;
  }else{
    result = ::utf32_strcmp (myStringPtr, otherStringPtr) ; // Never call strcmp with NULL pointer(s) !
  }
  return result ;
}

//---------------------------------------------------------------------------*

PMSInt32 C_String::compareStringByLength (const C_String & inString) const {
  PMSInt32 result ;
  const utf32 * myStringPtr = utf32String (HERE) ;
  const utf32 * otherStringPtr = inString.utf32String (HERE) ;
  if (otherStringPtr == myStringPtr) {
    result = 0 ;
  }else if (otherStringPtr == NULL) {
    result = 1 ;
  }else if (otherStringPtr == NULL) {
    result = -1 ;
  }else{
    result = length () - inString.length () ;
    if (result == 0) {
      result = ::utf32_strcmp (myStringPtr, otherStringPtr) ; // Never call strcmp with NULL pointer(s) !
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

bool C_String::operator == (const C_String & inString) const {
  return compareStringByLength (inString) == 0 ;
}

//---------------------------------------------------------------------------*

bool C_String::operator != (const C_String & inString) const {
  return compareStringByLength (inString) != 0 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   +    O P E R A T O R                                                    *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::operator + (const C_String & inOperand) const {
  C_String s = *this ;
  s << inOperand ;
  return s ;
}

//---------------------------------------------------------------------------*

C_String C_String::operator + (const char * inOperand) const {
  C_String s = *this ;
  s.appendCString (inOperand) ;
  return s ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   pathExtension                                                           *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::
pathExtension (void) const {
  const utf32 * source = utf32String (HERE) ;
  C_String result ;
  PMSInt32 receiver_length = length ();
//--- Suppress training '/'
  while ((receiver_length > 1) && (UNICODE_VALUE (source [receiver_length - 1]) == '/')) {
    receiver_length -- ;
  }
//--- Search last '.'
  bool found = false ;
  PMSInt32 lastOccurrenceIndex = receiver_length ;
  while ((lastOccurrenceIndex > 0) && ! found) {
    lastOccurrenceIndex -- ;
    found = UNICODE_VALUE (source [lastOccurrenceIndex]) == '.' ;
  }
  if (found) {
    if (lastOccurrenceIndex < (receiver_length - 1)) {
      result.genericUnicodeArrayOutput (& source [lastOccurrenceIndex + 1], receiver_length - 1 - lastOccurrenceIndex) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   stringByDeletingPathExtension                                           *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::
stringByDeletingPathExtension (void) const {
  const utf32 * source = utf32String (HERE) ;
  C_String result ;
  PMSInt32 receiver_length = length ();
//--- Suppress training '/'
  while ((receiver_length > 1) && (UNICODE_VALUE (source [receiver_length - 1]) == '/')) {
    receiver_length -- ;
  }
//--- Search last '.'
  bool found = false ;
  PMSInt32 lastOccurrenceIndex = receiver_length ;
  while ((lastOccurrenceIndex > 0) && ! found) {
    lastOccurrenceIndex -- ;
    found = UNICODE_VALUE (source [lastOccurrenceIndex]) == '.' ;
  }
  if (found) {
    result.genericUnicodeArrayOutput (source, lastOccurrenceIndex) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   stringByDeletingLastPathComponent                                       *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::
stringByDeletingLastPathComponent (void) const {
  const utf32 * source = utf32String (HERE) ;
  C_String result ;
  PMSInt32 receiver_length = length ();
//--- Suppress training '/'
  while ((receiver_length > 1) && (UNICODE_VALUE (source [receiver_length - 1]) == '/')) {
    receiver_length -- ;
  }
//--- Search last '/'
  bool found = false ;
  PMSInt32 lastOccurrenceIndex = receiver_length ;
  while ((lastOccurrenceIndex > 0) && ! found) {
    lastOccurrenceIndex -- ;
    found = UNICODE_VALUE (source [lastOccurrenceIndex]) == '/' ;
  }
  if (found) {
    result.genericUnicodeArrayOutput (source, lastOccurrenceIndex) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   stringByAppendingPathComponent                                          *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::
stringByAppendingPathComponent (const C_String & inPathComponent) const {
  C_String result = *this ;
  if (result.length () == 0) {
    result = inPathComponent ;
  }else if (UNICODE_VALUE (result.lastCharacter (HERE)) != '/') {
    result.appendUnicodeCharacter (TO_UNICODE ('/') COMMA_HERE) ;
    result.appendString (inPathComponent) ;
  }else{
    result.appendString (inPathComponent) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   lastPathComponent                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::
lastPathComponent (void) const {
  const utf32 * source = utf32String (HERE) ;
  C_String result ;
  PMSInt32 receiver_length = length ();
//--- Suppress training '/'
  while ((receiver_length > 1) && (UNICODE_VALUE (source [receiver_length - 1]) == '/')) {
    receiver_length -- ;
  }
//--- Search last '/'
  bool found = false ;
  PMSInt32 lastOccurrenceIndex = receiver_length ;
  while ((lastOccurrenceIndex > 0) && ! found) {
    lastOccurrenceIndex -- ;
    found = UNICODE_VALUE (source [lastOccurrenceIndex]) == '/' ;
  }
  if (found) {
    result.genericUnicodeArrayOutput (& source [lastOccurrenceIndex + 1], receiver_length - lastOccurrenceIndex - 1) ;
  }else{
    result.genericUnicodeArrayOutput (source, receiver_length) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_String C_String::lastPathComponentWithoutExtension (void) const {
  const C_String fileNameWithExtension = lastPathComponent () ;
  return fileNameWithExtension.stringByDeletingPathExtension () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   M D 5                                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::md5 (void) const {
  C_String result ;
  unsigned char digest [16] ;
  ::md5 ((unsigned char *) cString (HERE), (PMUInt32) length (), digest);
  char s [10] ;
  for (PMUInt32 i=0 ; i<16 ; i++) {
    sprintf (s, "%02X", digest [i]) ;
    result << s ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   R I G H T    S U B    S T R I N G                                       *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::rightSubString (const PMSInt32 inLength) const  {
  C_String result ;
  if (length () <= inLength) {
    result = *this ;
  }else{
    result = subString (length () - inLength, inLength) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   L E F T    S U B    S T R I N G                                         *
//                                                                           *
//---------------------------------------------------------------------------*

C_String C_String::leftSubString (const PMSInt32 inLength) const  {
  C_String result ;
  if (length () <= inLength) {
    result = *this ;
  }else{
    result = subString (0, inLength) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   A S S I G N M E N T    O P E R A T O R S                                *
//                                                                           *
//---------------------------------------------------------------------------*

C_String & C_String::operator = (const char * inSource) {
  setLengthToZero () ;
  if (inSource != NULL) {
    genericCharArrayOutput (inSource, (PMSInt32) (strlen (inSource) & PMUINT32_MAX)) ;
  }
  return * this ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   S E T   F R O M    S T R I N G                                          *
//                                                                           *
//---------------------------------------------------------------------------*

void C_String::setFromCstring (const char * inCstring) {
  setLengthToZero () ;
  *this << inCstring ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   X M L    E S C A P E D    S T R I N G                                   *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Returns a string where ", ', <, > and & have been replaced by &quot;, &apos;, &lt;, &gt; and &amp;
C_String C_String::XMLEscapedString (void) const {
  C_String result ;
  for (PMSInt32 i=0 ; i<length () ; i++) {
    const utf32 c = this->operator () (i COMMA_HERE) ;
    switch (UNICODE_VALUE (c)) {
    case '"'  : result << "&quot;" ; break ;
    case '\'' : result << "&apos;" ; break ;
    case '<'  : result << "&lt;"   ; break ;
    case '>'  : result << "&gt;"   ; break ;
    case '&'  : result << "&amp;"  ; break ;
    case '\n' : result << "&#10;" ; break ;
    default   : result.appendUnicodeCharacter (c COMMA_HERE) ; break;
    }
  } 
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Converting into Unix Path
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   Converting into Unix Path                                               *
//                                                                           *
//---------------------------------------------------------------------------*

//--- On Unix: do nothing
#ifdef UNIX_TOOL
  C_String C_String::
  unixPathWithNativePath (void) const {
    return *this ;
  }
#endif

//---------------------------------------------------------------------------*

//--- On Carbon: translate (works only on full path names)
#ifdef TARGET_API_MAC_CARBON
  C_String C_String::
  unixPathWithNativePath (void) const {
    C_String result ("/Volumes/") ;
    for (PMSInt32 i=0 ; i<length () ; i++) {
      const utf32 c = this->operator () (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) == ':') {
        result << "/" ;
      }else{
        result.appendUnicodeCharacter (c COMMA_HERE) ;
      }
    }
    return result ;
  }
#endif

//---------------------------------------------------------------------------*

//--- On Windows: translate
#ifdef COMPILE_FOR_WIN32
  C_String C_String::
  unixPathWithNativePath (void) const {
    C_String result ;
    const PMSInt32 pathLength = length () ;
    PMSInt32 firstChar = 0 ;
    if ((pathLength > 3)
     && isalpha ((int) UNICODE_VALUE (this->operator () (0 COMMA_HERE)))
     && (UNICODE_VALUE (this->operator () (1 COMMA_HERE)) == ':')
     && (UNICODE_VALUE (this->operator () (2 COMMA_HERE)) == '\\')) {
      result << "/" ;
      result.appendUnicodeCharacter (this->operator () (0 COMMA_HERE) COMMA_HERE) ;
      result << "/" ;
      firstChar = 3 ;
    }
    for (PMSInt32 i=firstChar ; i<pathLength ; i++) {
      const utf32 c = this->operator () (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) == '\\') {
        result << "/" ;
      }else{
        result.appendUnicodeCharacter (c COMMA_HERE) ;
      }
    }
    return result ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Converting into Native Path
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   Converting into Native Path                                             *
//                                                                           *
//---------------------------------------------------------------------------*

//--- On Unix: do nothing
#ifdef UNIX_TOOL
  C_String C_String::
  nativePathWithUnixPath (void) const {
    return *this ;
  }
#endif

//---------------------------------------------------------------------------*

//--- On Carbon: convert (works only on full path names)
#ifdef TARGET_API_MAC_CARBON
  C_String C_String::
  nativePathWithUnixPath (void) const {
    C_String carbonPath ;
    const PMSInt32 pathLength = length () ;
    if (pathLength > 0) {
    //--- Replace '/' by ':'
      for (PMSInt32 i=0 ; i<pathLength ; i++) {
        const utf32 c = this->operator () (i COMMA_HERE) ;
        carbonPath.appendUnicodeCharacter ((UNICODE_VALUE (c) == '/') ? TO_UNICODE (':') : c COMMA_HERE) ;
      }
    //--- if first character is ':', following chars should be 'Volumes:' : suppress them
      if ((UNICODE_VALUE (carbonPath (0 COMMA_HERE)) == ':') && (carbonPath.length () > 9)) {
        carbonPath.suppress (0, 9 COMMA_HERE) ;
      }
    }
    return carbonPath ;
  }
#endif

//---------------------------------------------------------------------------*

//--- On Windows: convert
#ifdef COMPILE_FOR_WIN32
  C_String C_String::
  nativePathWithUnixPath (void) const {
    C_String winPath ;
      const PMSInt32 fileLength = length () ;
      PMSInt32 firstChar = 0 ;
      if ((fileLength > 3)
       && (UNICODE_VALUE (this->operator () (0 COMMA_HERE)) == '/')
       && isalpha ((int) UNICODE_VALUE (this->operator () (1 COMMA_HERE)))
       && (UNICODE_VALUE (this->operator () (2 COMMA_HERE)) == '/')) {
        winPath.appendUnicodeCharacter (this->operator () (1 COMMA_HERE) COMMA_HERE) ;
        winPath << ":\\" ;
        firstChar = 3 ;
      }
      for (PMSInt32 i=firstChar ; i<fileLength ; i++) {
        const utf32 c = this->operator () (i COMMA_HERE) ;
        winPath.appendUnicodeCharacter ((UNICODE_VALUE (c) == '/') ? TO_UNICODE ('\\') : c COMMA_HERE) ;
      }
    return winPath ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark File handling
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   M E T H O D S    F O R    F I L E    H A N D L I N G                    *
//                                                                           *
//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  C_String C_String::currentDirectory (void) {
    char * cwd = getcwd (NULL, 0) ;
    const PMUInt32 length = strlen (cwd) ;
    for (PMUInt32 i=0 ; i<length ; i++) {
      if (cwd [i] == ':') {
        cwd [i] = '/' ;
      }
    }
    C_String result ("/Volumes/") ;
    result << cwd ;
    ::free (cwd) ;
    return result ;
  }
#endif

//---------------------------------------------------------------------------*

#ifndef TARGET_API_MAC_CARBON
  C_String C_String::currentDirectory (void) {
    char * cwd = getcwd (NULL, 0) ;
    #ifdef COMPILE_FOR_WIN32
      const PMSInt32 fileLength = (PMSInt32) strlen (cwd) ;
      PMSInt32 firstChar = 0 ;
      if ((fileLength > 3)
       && isalpha (cwd [0])
       && (cwd [1] == ':')
       && (cwd [2] == '\\')) {
        cwd [1] = cwd [0] ;
        cwd [0] = '/' ;
        cwd [2] = '/' ;
        firstChar = 3 ;
      }
      for (PMSInt32 i=firstChar ; i<fileLength ; i++) {
        if (cwd [i] == '\\') {
          cwd [i] = '/' ;
        }
      }
    #endif
    const C_String result (cwd) ;
    ::free (cwd) ;
    return result ;
  }
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   isAbsolutePath                                                          *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_String::
isAbsolutePath (void) const {
  return (length () > 0) && (UNICODE_VALUE (this->operator () (0 COMMA_HERE)) == '/') ;
}

//---------------------------------------------------------------------------*

C_String C_String::
absolutePathFromCurrentDirectory (void) const {
  const PMSInt32 stringLength = length () ;
  C_String result ;
  if ((stringLength > 0) && (UNICODE_VALUE (this->operator () (0 COMMA_HERE)) == '/')) {
    result = *this ;
  }else{
    result = C_String::currentDirectory () + "/" + *this ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//--- If receiver is an absolute path, returns it
//    Otherwise, prepend path argument
//    if path argument it self is relative, current directory is prepended

C_String C_String::
absolutePathFromPath (const C_String & inPath) const {
  const PMSInt32 stringLength = length () ;
  C_String result ;
  if ((stringLength > 0) && (UNICODE_VALUE (this->operator () (0 COMMA_HERE)) == '/')) {
    result = *this ;
  }else{
    result = inPath.absolutePathFromCurrentDirectory () ;
    if (UNICODE_VALUE (result.lastCharacter (HERE)) != '/') {
      result.appendUnicodeCharacter (TO_UNICODE ('/') COMMA_HERE) ;
    }
    result.appendString (*this) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_String C_String::
relativePathFromPath (const C_String & inPath) const {
  TC_UniqueArray <C_String> absoluteReferencePathComponents ;
  inPath.stringByStandardizingPath ().absolutePathFromCurrentDirectory ().componentsSeparatedByString("/", absoluteReferencePathComponents) ;
  TC_UniqueArray <C_String> absoluteReceiverPathComponents ;
  stringByStandardizingPath ().absolutePathFromCurrentDirectory ().componentsSeparatedByString("/", absoluteReceiverPathComponents) ;
  C_String result ;
  PMSInt32 idx = 0 ;
  while ((idx < absoluteReferencePathComponents.count ())
      && (idx < absoluteReceiverPathComponents.count ())
      && (absoluteReferencePathComponents (idx COMMA_HERE) == absoluteReceiverPathComponents (idx COMMA_HERE))) {
    idx ++ ;
  }
  for (PMSInt32 i=idx ; i<absoluteReferencePathComponents.count () ; i++) {
    result << "../" ;
  }
  for (PMSInt32 i=idx ; i<absoluteReceiverPathComponents.count () ; i++) {
    if (i > idx) {
      result << "/" ;
    }
    result << absoluteReceiverPathComponents (i COMMA_HERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

bool C_String::makeDirectoryIfDoesNotExist (void) const {
  const C_String s = stringByStandardizingPath () ;
  bool ok = s.directoryExists () ;
  if (! ok) {
    ok = s.stringByDeletingLastPathComponent ().makeDirectoryIfDoesNotExist () ;
    if (ok) {
      const C_String nativePath = nativePathWithUnixPath () ;
    //--- Create directory (mkdir returns 0 if creation is ok)
      #ifdef COMPILE_FOR_WIN32
        const int result = ::mkdir (nativePath.cString (HERE)) ;
      #else
        const int result = ::mkdir (nativePath.cString (HERE), 0770) ;
      #endif
      ok = result == 0 ;
    }
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
bool C_String::binaryDataWithContentOfFile (TC_UniqueArray <unsigned char> & outBinaryData) const {
//--- Clear result
  outBinaryData.removeAllObjects () ;
//--- Open file for binary reading
  const C_String nativePath = nativePathWithUnixPath () ;
  FILE * inputFile = ::fopen (nativePath.cString (HERE), "rb") ;
  bool ok = inputFile != NULL ;
//--- Go to the end of the file
  if (ok) {
    ok = ::fseek (inputFile, 0, 2) == 0 ;
  }

//--- Get file size
  PMSInt32 fileSize = 0 ;
  if (ok) {
    fileSize = (PMSInt32) (ftell (inputFile) & PMUINT32_MAX) ;
    ok = fileSize != -1 ;
  }

//--- Rewind file
  if (ok) {
    ok = ::fseek (inputFile, 0L, 0) == 0 ;
  }

//--- Read file
  if (ok) {
  //--- Set allocated size for the result
    outBinaryData.makeRoom (fileSize) ;
  //--- Read file
    unsigned char * data = NULL ;
    macroMyNewPODArray (data, unsigned char, fileSize) ;
    const PMSInt32 sizeRead = (PMSInt32) (fread (data, 1, (PMUInt32) fileSize, inputFile) & PMUINT32_MAX) ;
    ok = sizeRead == fileSize ;
  //--- Enter in result
    if (ok) {
      for (PMSInt32 i=0 ; i<fileSize ; i++) {
        outBinaryData.addObject (data [i]) ;
      }
    }
    macroMyDeletePODArray (data) ;
  }
//--- Close file
  if (inputFile != NULL) {
    const PMSInt32 result = ::fclose (inputFile) ;
    if (ok) {
      ok = result == 0 ;
    }
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
bool C_String::writeToFile (const C_String & inFilePath
                            COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT
                            COMMA_UNUSED_LOCATION_ARGS) const {
  bool success = false ;
  inFilePath.stringByDeletingLastPathComponent().makeDirectoryIfDoesNotExist () ;
  C_TextFileWrite file (inFilePath COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT_NAME, success) ;
  file << *this ;
  if (success) {
    success = file.close () ;
  }
  return success ;
}

//---------------------------------------------------------------------------*

#ifdef TARGET_API_MAC_CARBON
  static C_String unixPath2macOSpath (const C_String & inPath) {
    C_String macOSpath ;
    const PMSInt32 length = inPath.length () ;
    if (length > 0) {
    //--- Replace '/' by ':'
      for (PMSInt32 i=0 ; i<length ; i++) {
        const utf32 c = inPath (i COMMA_HERE) ;
        macOSpath.appendUnicodeCharacter ((UNICODE_VALUE (c) == '/') ? TO_UNICODE (':') : c COMMA_HERE) ;
      }
    //--- if first character is ':', following char must be 'Volumes:' : suppress them
      if ((UNICODE_VALUE (macOSpath (0 COMMA_HERE)) == ':') && (macOSpath.length () > 9)) {
        macOSpath.suppress (0, 9 COMMA_HERE) ;
      }
    }
    return macOSpath ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  static C_String unixPath2winPath (const C_String & inWinFileName) {
    C_String winFileName ;
      const PMSInt32 fileLength = inWinFileName.length () ;
      PMSInt32 firstChar = 0 ;
      if ((fileLength > 3)
       && (UNICODE_VALUE (inWinFileName (0 COMMA_HERE)) == '/')
       && isalpha ((int) UNICODE_VALUE (inWinFileName (1 COMMA_HERE)))
       && (UNICODE_VALUE (inWinFileName (2 COMMA_HERE)) == '/')) {
        winFileName.appendUnicodeCharacter (inWinFileName (1 COMMA_HERE) COMMA_HERE) ;
        winFileName << ":\\" ;
        firstChar = 3 ;
      }
      for (PMSInt32 i=firstChar ; i<fileLength ; i++) {
        const utf32 c = (UNICODE_VALUE (inWinFileName (i COMMA_HERE)) == '/')
          ? TO_UNICODE ('\\')
          : inWinFileName (i COMMA_HERE) ;
        winFileName.appendUnicodeCharacter (c COMMA_HERE) ;
      }
    return winFileName ;
  }
#endif

//---------------------------------------------------------------------------*
  
bool C_String::writeBinaryData (const TC_UniqueArray <PMUInt8> & inBinaryData) const {
  stringByDeletingLastPathComponent().makeDirectoryIfDoesNotExist () ;
//---
  #ifdef TARGET_API_MAC_CARBON
    FILE * filePtr = ::fopen (unixPath2macOSpath (*this).cString (HERE), "wt") ;
  #elif defined (COMPILE_FOR_WIN32)
    FILE * filePtr = ::fopen (unixPath2winPath (*this).cString (HERE), "wt") ;
  #else
    FILE * filePtr = ::fopen (cString (HERE), "wt") ;
  #endif
//--- Open Ok ?
  bool success = filePtr != NULL ;
//--- Write binary data
  if (success) {
    const PMUInt8 * dataPtr = inBinaryData.arrayPointer () ;
    const PMUInt32 length = (PMUInt32) inBinaryData.count () ;
    const size_t writtenCount = (size_t) ::fwrite (dataPtr, 1, length, filePtr) ;
    success = writtenCount == length ;
  }
//--- Close file
  if (NULL != filePtr) {
    ::fclose (filePtr) ;
  }
//---
  return success ;
}

//---------------------------------------------------------------------------*
  
bool C_String::
writeToExecutableFile (const C_String & inFilePath
                       COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT
                       COMMA_UNUSED_LOCATION_ARGS) const {
  bool success = false ;
  inFilePath.stringByDeletingLastPathComponent().makeDirectoryIfDoesNotExist () ;
  C_TextFileWrite file (inFilePath COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT_NAME, success) ;
  file << *this ;
  if (success) {
    success = file.close () ;
    #ifndef COMPILE_FOR_WIN32
      struct stat fileStat ;
      ::stat (inFilePath.cString (HERE), & fileStat) ;
      // printf ("FILE MODE 0x%X\n", fileStat.st_mode) ;
      ::chmod (inFilePath.cString (HERE), fileStat.st_mode | S_IXUSR | S_IXGRP | S_IXOTH) ;
    #endif
  }
  return success ;
}

//---------------------------------------------------------------------------*

C_DateTime C_String::fileModificationTime (void) const {
  const C_String nativePath = nativePathWithUnixPath () ;
//--- Get file properties
  time_t modificationTime = 0 ;
  if (nativePath.length () > 0) {
    struct stat fileProperties ;
    const int err = ::stat (nativePath.cString (HERE), & fileProperties) ;
    if ((err == 0) && ((fileProperties.st_mode & S_IFREG) != 0)) {
      modificationTime = fileProperties.st_mtime ;
    }
  }
//--- Return modification date
  return C_DateTime (modificationTime)  ;
}

//---------------------------------------------------------------------------*

bool C_String::fileExists (void) const {
  const C_String nativePath = nativePathWithUnixPath () ;
//--- Get file properties
  bool exists = nativePath.length () > 0 ;
  if (exists) {
    struct stat fileProperties ;
    const int err = ::stat (nativePath.cString (HERE), & fileProperties) ;
    exists = (err == 0) && ((fileProperties.st_mode & S_IFREG) != 0) ;
  }
 //--- Return result
  return exists ;
}

//---------------------------------------------------------------------------*

bool C_String::directoryExists (void) const {
  const C_String nativePath = nativePathWithUnixPath () ;
//--- Get file properties
  bool exists = nativePath.length () > 0 ;
  if (exists) {
    struct stat fileProperties ;
    const int err = ::stat (nativePath.cString (HERE), & fileProperties) ;
    exists = (err == 0) && ((fileProperties.st_mode & S_IFDIR) != 0) ;
  }
 //--- Return result
  return exists ;
}

//---------------------------------------------------------------------------*

PMSInt32 C_String::
filePosixPermissions (void) const {
  const C_String nativePath = nativePathWithUnixPath () ;
//--- Get file properties
  PMSInt32 permissions = -1 ;
  struct stat fileProperties ;
  const int err = ::stat (nativePath.cString (HERE), & fileProperties) ;
  if (err == 0) {
    permissions = ((PMSInt32) fileProperties.st_mode) & 0xFFF ;
  }
 //--- Return result
  return permissions ;
}

//---------------------------------------------------------------------------*

PMSInt32 C_String::
setFilePosixPermissions (const PMSInt32 inNewFilePosixPermissions) const {
  PMSInt32 newMode = -1 ; // Error Code
  if ((inNewFilePosixPermissions & 0xFFFFF000) == 0) {
    const C_String nativePath = nativePathWithUnixPath () ;
    newMode = ::chmod (nativePath.cString (HERE), (PMUInt16) (inNewFilePosixPermissions & PMUINT16_MAX)) ;
  }
  return newMode ;
}

//---------------------------------------------------------------------------*

C_String C_String::
stringByStandardizingPath (void) const {
  #ifdef COMPILE_FOR_WIN32
    C_String path = stringByReplacingCharacterByString (TO_UNICODE ('\\'), "/") ;
  #else
    C_String path = * this ;
  #endif
  if (path.length () == 0) {
    path << "." ;
  }else{
  //#define TRACE_stringByStandardizingPath
  //--- Decompose path
    TC_UniqueArray <C_String> componentArray ;
    path.componentsSeparatedByString ("/", componentArray) ;
    #ifdef TRACE_stringByStandardizingPath
      printf ("----- Decomposition of '%s':\n", path.cString (HERE)) ;
      for (PMSInt32 i=0 ; i<componentArray.count () ; i++) {
        printf ("  '%s'\n", componentArray (i COMMA_HERE).cString (HERE)) ;
      }
    #endif
  //--- Remove empty components (but the first one)
    PMSInt32 componentIndex = 1 ;
    while (componentIndex < componentArray.count ()) {
      if (componentArray (componentIndex COMMA_HERE).length () == 0) {
        componentArray.removeObjectAtIndex (componentIndex COMMA_HERE) ;
      }else{
        componentIndex ++ ;
      }
    }
    #ifdef TRACE_stringByStandardizingPath
      printf ("-- After removing empty components:\n") ;
      for (PMSInt32 i=0 ; i<componentArray.count () ; i++) {
        printf ("  '%s'\n", componentArray (i COMMA_HERE).cString (HERE)) ;
      }
    #endif
  //--- Remove '.' components
    componentIndex = 0 ;
    while (componentIndex < componentArray.count ()) {
      if (componentArray (componentIndex COMMA_HERE) == ".") {
        componentArray.removeObjectAtIndex (componentIndex COMMA_HERE) ;
      }else{
        componentIndex ++ ;
      }
    }
    #ifdef TRACE_stringByStandardizingPath
      printf ("-- After removing '.' components:\n") ;
      for (PMSInt32 i=0 ; i<componentArray.count () ; i++) {
        printf ("  '%s'\n", componentArray (i COMMA_HERE).cString (HERE)) ;
      }
    #endif
  //--- Remove '..' components
    componentIndex = 1 ;
    while (componentIndex < componentArray.count ()) {
      if ((componentArray (componentIndex COMMA_HERE) == "..") && (componentArray (componentIndex-1 COMMA_HERE) != "..")) {
        componentArray.removeObjectAtIndex (componentIndex COMMA_HERE) ;
        componentIndex -- ;
        componentArray.removeObjectAtIndex (componentIndex COMMA_HERE) ;
        if (componentIndex == 0) {
          componentIndex = 1 ;
        }
      }else{
        componentIndex ++ ;
      }
    }
    #ifdef TRACE_stringByStandardizingPath
      printf ("-- After removing '..' components:\n") ;
      for (PMSInt32 i=0 ; i<componentArray.count () ; i++) {
        printf ("  '%s'\n", componentArray (i COMMA_HERE).cString (HERE)) ;
      }
    #endif
  //--- Recompose path
    path = componentsJoinedByString (componentArray, "/") ;
    #ifdef TRACE_stringByStandardizingPath
      printf ("-- Recomposed path: '%s'\n", path.cString (HERE)) ;
    #endif
  }
//---
  return path ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  Search a file in a directories                                           *
//                                                                           *
//---------------------------------------------------------------------------*

// #define DEBUG_recursiveSearchInDirectory

//---------------------------------------------------------------------------*

static C_String
recursiveSearchInDirectory (const C_String & inStartSearchPath,
                            const C_String & inFileName,
                            const PMSInt32 inDirectoriesToExcludeCount,
                            const TC_UniqueArray <C_String> & inDirectoriesToExclude) {
  C_String result ;
  const C_String nativeStartSearchPath = inStartSearchPath.nativePathWithUnixPath () ;
  DIR * dir = ::opendir (nativeStartSearchPath.cString (HERE)) ;
  if (dir != NULL) {
    C_String fileName = inStartSearchPath ;
    fileName << "/" << inFileName ;
    if (fileName.fileExists ()) {
      #ifdef DEBUG_recursiveSearchInDirectory
        co << "** FILE '" << fileName << "' EXISTS **\n" ;
      #endif
      result = fileName ;
    }else{
      struct dirent  * current = readdir (dir) ;
      while ((current != NULL) && (result.length () == 0)) {
        if (current->d_name [0] != '.') {
          C_String name = inStartSearchPath ;
          name.appendCString ("/") ;
          name.appendCString (current->d_name) ;
          if (name.directoryExists ()) {
            bool dirOk = true ;
            for (PMSInt32 i=0 ; (i<inDirectoriesToExcludeCount) && dirOk ; i++) {
              if (UNICODE_VALUE (inDirectoriesToExclude (i COMMA_HERE) (0 COMMA_HERE)) == '.') {
                const char * dotPtr = strrchr (current->d_name, '.') ;
                dirOk = (dotPtr == NULL) || (inDirectoriesToExclude (i COMMA_HERE).compare (dotPtr) != 0) ;
              }else{
                dirOk = inDirectoriesToExclude (i COMMA_HERE).compare (current->d_name) != 0 ;
              }
              #ifdef DEBUG_recursiveSearchInDirectory
                if (! dirOk) {
                  co << "** REJECTED DIR '" << name << "' **\n" ;
                }
              #endif
            }
            if (dirOk) {
              #ifdef DEBUG_recursiveSearchInDirectory
                co << "** SEARCH IN DIR '" << name << "' **\n" ;
              #endif
              result = recursiveSearchInDirectory (name, inFileName, inDirectoriesToExcludeCount, inDirectoriesToExclude) ;
            }
          }
        }
        current = readdir (dir) ;
      }
    }
    closedir (dir) ;
  }
  #ifdef DEBUG_recursiveSearchInDirectory
    co << "** RESULT IS '" << result << "' **\n" ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

C_String
C_String::findFileInDirectory (const C_String & inFileName,
                               const TC_UniqueArray <C_String> & inDirectoriesToExclude) const {
  const PMSInt32 directoriesToExcludeCount = inDirectoriesToExclude.count () ;
  #ifdef DEBUG_recursiveSearchInDirectory
    co << "************* Search in directory '" << *this << "'\n"
          "** File to search '" << inFileName << "'\n'" ;
    for (PMSInt32 i=0 ; i<directoriesToExcludeCount ; i++) {
      co << "** Exclude '" << inDirectoriesToExclude (i COMMA_HERE) << "'\n'" ;
    }
  #endif
  return recursiveSearchInDirectory (*this, inFileName, directoriesToExcludeCount, inDirectoriesToExclude) ;
}

//---------------------------------------------------------------------------*

static void
recursiveFindAllFilesInDirectory (const C_String & inStartSearchPath,
                                  const C_String & inExtension,
                                  TC_UniqueArray <C_String> & outFoundFilePathes) {
//--- Iterate throught directory
  const C_String nativeStartSearchPath = inStartSearchPath.nativePathWithUnixPath () ;
  DIR * dir = ::opendir (nativeStartSearchPath.cString (HERE)) ;
  if (dir != NULL) {
    struct dirent  * current = readdir (dir) ;
    while (current != NULL) {
      if (current->d_name [0] != '.') {
        C_String name = inStartSearchPath ;
        name.appendCString ("/") ;
        name.appendCString (current->d_name) ;
        if (name.directoryExists ()) {
          recursiveFindAllFilesInDirectory (name, inExtension, outFoundFilePathes) ;
        }else if (name.fileExists () && (name.pathExtension () == inExtension)) {
          outFoundFilePathes.addObject (name) ;
        }
      }
      current = readdir (dir) ;
    }
    closedir (dir) ;
  }
}

//---------------------------------------------------------------------------*

void C_String::
findAllFilesInDirectoryFromExtension (const C_String & inExtension,
                                      TC_UniqueArray <C_String> & outFoundFilePathes) const {
  if (directoryExists ()) {
    recursiveFindAllFilesInDirectory (*this, inExtension, outFoundFilePathes) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//  Delete file                                                              *
//                                                                           *
//---------------------------------------------------------------------------*

const char * C_String::deleteFile (void) const {
  const char * returnValue = NULL ;
  const C_String nativePath = nativePathWithUnixPath () ;
  const int result = unlink (nativePath.cString (HERE)) ;
  if (result < 0) {
    returnValue = ::strerror (errno) ;
  }
  return returnValue ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  Remove Directory                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

const char * C_String::removeDirectory (void) const {
  const char * returnValue = NULL ;
  const C_String nativePath = nativePathWithUnixPath () ;
  const int result = rmdir (nativePath.cString (HERE)) ;
  if (result < 0) {
    returnValue = ::strerror (errno) ;
  }
  return returnValue ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========== stringWithContentOfFile
#endif

//---------------------------------------------------------------------------*
  
//#define PRINT_SNIFF_ENCODING

//---------------------------------------------------------------------------*
  
static PMUInt8 * readFile (const C_String & inFilePath,
                           bool & outOk,
                           PMSInt32 & outFileSize) {
//--- Open file for reading
  const C_String nativePath = inFilePath.nativePathWithUnixPath () ;
  FILE * inputFile = ::fopen (nativePath.cString (HERE), "rb") ;
  outOk = inputFile != NULL ;
//  if (! outOk) {
//    printf ("inputFile == NULL, errno %d, strerror '%s'\n", errno, strerror (errno)) ;
//  }
//--- Go to the end of the file
  if (outOk) {
    outOk = ::fseek (inputFile, 0, 2) == 0 ;
//    if (! outOk) {
//      printf ("fseek\n") ;
//    }
  }

//--- Get file size
  outFileSize = 0 ;
  if (outOk) {
    outFileSize = (PMSInt32) (ftell (inputFile) & PMUINT32_MAX) ;
    outOk = outFileSize != -1 ;
//    if (! outOk) {
//      printf ("outFileSize == -1\n") ;
//    }
  }

//--- Rewind file
  if (outOk) {
    outOk = ::fseek (inputFile, 0, 0) == 0 ;
//    if (! outOk) {
//      printf ("fseek 2\n") ;
//    }
  }

//--- Create the dynamic char array that will get the text of the file
  PMUInt8 * cString = NULL ;
  if (outOk) {
    macroMyNewPODArray (cString, PMUInt8, outFileSize + 1) ; // One more byte for terminating '\0'
  }
//--- Read file
  if (outOk) {
    const PMSInt32 readCount = (PMSInt32) (fread (cString, sizeof (PMUInt8), (PMUInt32) outFileSize, inputFile) & PMUINT32_MAX) ;
    outOk = readCount == outFileSize ;
    cString [outFileSize] = '\0' ;
  }
//--- Close source file
  if (inputFile != NULL) {
    const PMSInt32 close_error = ::fclose (inputFile) ;
//    printf ("close_file\n") ;
    inputFile = NULL ;
    if (outOk && (close_error != 0)) {
      outOk = false ;
//      printf ("close_error\n") ;
    }
  }
  return cString ;
}

//---------------------------------------------------------------------------*
  
static bool parseWithEncoding (const PMUInt8 * inCString,
                               const PMSInt32 /* inLength */,
                               const PMStringEncoding inTextFileEncoding,
                               C_String & outString) {
  const PMUInt8 * sourcePointer = inCString ;
  bool foundCR = false ;
  bool ok = true ;
  while (((* sourcePointer) != 0) && ok) {
    const PMUInt8 c = * sourcePointer ;
    if (c == 0x0A) { // LF
      if (! foundCR) {
        outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
      }
      foundCR = false ;
      sourcePointer ++ ;
    }else if (c == 0x0D) { // CR
      outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
      foundCR = true ;
      sourcePointer ++ ;
    }else if ((c & 0x80) == 0) { // ASCII Character
      outString.appendUnicodeCharacter (TO_UNICODE (c) COMMA_HERE) ;
      foundCR = false ;
      sourcePointer ++ ;
    }else{
      const utf32 uc = unicodeCharacterForSingleByteCharacter ((char) c, inTextFileEncoding) ;
      outString.appendUnicodeCharacter (uc COMMA_HERE) ;
      foundCR = false ;
    }
  }
  if (foundCR) {
    outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
bool C_String::parseUTF8 (const PMUInt8 * inCString,
                          const PMSInt32 inLength,
                          C_String & outString) {
  bool ok = true ;
  if (inLength > 0) {
    const PMUInt8 * sourcePointer = inCString ;
    bool foundCR = false ;
    const PMUInt8 * endOfArrayPtr = inCString + inLength ;
    while (((* sourcePointer) != 0) && ok) {
      const PMUInt8 c = * sourcePointer ;
      if (c == 0x0A) { // LF
        if (! foundCR) {
          outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
        }
        foundCR = false ;
        sourcePointer ++ ;
      }else if (c == 0x0D) { // CR
        outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
        foundCR = true ;
        sourcePointer ++ ;
      }else if ((c & 0x80) == 0) { // ASCII Character
        outString.appendUnicodeCharacter (TO_UNICODE (c) COMMA_HERE) ;
        foundCR = false ;
        sourcePointer ++ ;
      }else{
        const utf32 uc = utf32CharacterForPointer (sourcePointer, endOfArrayPtr, ok) ;
        outString.appendUnicodeCharacter (uc COMMA_HERE) ;
        foundCR = false ;
      }
    }
    if (foundCR) {
      outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
    }
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
static void
parseASCIIWithReplacementCharacter (const PMUInt8 * inCString,
                                    const PMSInt32 inLength,
                                    C_String & outString) {
  const PMUInt8 * sourcePointer = inCString ;
  bool foundCR = false ;
  PMSInt32 index = 0 ;
  while (index < inLength) {
    const PMUInt8 c = * sourcePointer ;
    sourcePointer ++ ;
    index ++ ;
    if (c == 0x0A) { // LF
      if (! foundCR) {
        outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
      }
      foundCR = false ;
    }else if (c == 0x0D) { // CR
      outString.appendUnicodeCharacter (TO_UNICODE ('\n') COMMA_HERE) ;
      foundCR = true ;
    }else if ((c != 0) && (c & 0x80) == 0) { // ASCII Character (not NUL)
      outString.appendUnicodeCharacter (TO_UNICODE (c) COMMA_HERE) ;
      foundCR = false ;
    }else{
      outString.appendUnicodeCharacter (UNICODE_REPLACEMENT_CHARACTER COMMA_HERE) ;
      foundCR = false ;
    }
  }
}

//---------------------------------------------------------------------------*
  
static bool parseUTF32LE (const PMUInt8 * inCString,
                          const PMSInt32 inLength,
                          C_String & outString) {
  bool ok = (inLength % 4) == 0 ;
  const PMUInt8 * sourcePointer = inCString ;
  for (PMSInt32 i=0 ; (i<inLength) && ok ; i+=4) {
    PMUInt32 n = * (sourcePointer + 3) ;
    n <<= 8 ;
    n |= * (sourcePointer + 2) ;
    n <<= 8 ;
    n |= * (sourcePointer + 1) ;
    n <<= 8 ;
    n |= * sourcePointer ;
    sourcePointer += 4 ;
    ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) ;
    outString.appendUnicodeCharacter (TO_UNICODE (n) COMMA_HERE) ;
  }
  if (! ok) {
    outString.setLengthToZero () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
static bool parseUTF32BE (const PMUInt8 * inCString,
                          const PMSInt32 inLength,
                          C_String & outString) {
  bool ok = (inLength % 4) == 0 ;
  const PMUInt8 * sourcePointer = inCString ;
  for (PMSInt32 i=0 ; (i<inLength) && ok ; i+=4) {
    PMUInt32 n = * sourcePointer ;
    sourcePointer ++ ;
    n <<= 8 ;
    n |= * sourcePointer ;
    sourcePointer ++ ;
    n <<= 8 ;
    n |= * sourcePointer ;
    sourcePointer ++ ;
    n <<= 8 ;
    n |= * sourcePointer ;
    sourcePointer ++ ;
    ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) ;
    outString.appendUnicodeCharacter (TO_UNICODE (n) COMMA_HERE) ;
  }
  if (! ok) {
    outString.setLengthToZero () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*
// UTF-16 http://fr.wikipedia.org/wiki/UTF-16
//    
static bool parseUTF16LE (const PMUInt8 * inCString,
                          const PMSInt32 inLength,
                          C_String & outString) {
  bool ok = (inLength % 2) == 0 ;
  // PMUInt32 utf16prefix =0 ;
  bool foundUTF16prefix = false ;
  const PMUInt8 * sourcePointer = inCString ;
  for (PMSInt32 i=0 ; (i<inLength) && ok ; i+=2) {
    PMUInt32 n = * (sourcePointer + 1) ;
    n <<= 8 ;
    n |= * sourcePointer ;
    sourcePointer += 2 ;
    if ((n & 0xDC00) == 0xD800) {
      ok = ! foundUTF16prefix ;
      foundUTF16prefix = true ;
      // utf16prefix = n & 0x3FF ;
      // utf16prefix += 64 ;
    }else if ((n & 0xDC00) == 0xDC00) {
      ok = foundUTF16prefix ;
      foundUTF16prefix = false ;
      // n &= 0x3FF ;
      // n |= utf16prefix << 6 ;
    }else{
      ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) && ! foundUTF16prefix ;
      outString.appendUnicodeCharacter (TO_UNICODE (n) COMMA_HERE) ;
    }
  }
  ok &= ! foundUTF16prefix ;
  if (! ok) {
    outString.setLengthToZero () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*

static bool parseUTF16BE (const PMUInt8 * inCString,
                          const PMSInt32 inLength,
                          C_String & outString) {
  bool ok = (inLength % 2) == 0 ;
  // PMUInt32 utf16prefix =0 ;
  bool foundUTF16prefix = false ;
  const PMUInt8 * sourcePointer = inCString ;
  for (PMSInt32 i=0 ; (i<inLength) && ok ; i+=2) {
    PMUInt32 n = * sourcePointer ;
    sourcePointer ++ ;
    n <<= 8 ;
    n |= * sourcePointer ;
    sourcePointer ++ ;
    if ((n & 0xDC00) == 0xD800) {
      ok = ! foundUTF16prefix ;
      foundUTF16prefix = true ;
      // utf16prefix = n & 0x3FF ;
      // utf16prefix += 64 ;
    }else if ((n & 0xDC00) == 0xDC00) {
      ok = foundUTF16prefix ;
      foundUTF16prefix = false ;
      // n &= 0x3FF ;
      // n |= utf16prefix << 6 ;
    }else{
      ok = isUnicodeCharacterAssigned (TO_UNICODE (n)) && ! foundUTF16prefix ;
      outString.appendUnicodeCharacter (TO_UNICODE (n) COMMA_HERE) ;
    }
  }
  ok &= ! foundUTF16prefix ;
  if (! ok) {
    outString.setLengthToZero () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
static bool
searchBOMandParse (const PMUInt8 * inCString,
                   const PMSInt32 inLength,
                   PMTextFileEncoding & outTextFileEncoding,
                   C_String & outResultString) {
  bool ok = false ;
//--- UTF-32BE BOM ?
  if ((inLength >= 4) && (inCString [0] == 0) && (inCString [1] == 0) && (inCString [2] == 0xFE) && (inCString [3] == 0xFF)) {
    ok = parseUTF32BE (inCString + 4, inLength - 4, outResultString) ;
    outTextFileEncoding = kUTF_32BE_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-32BE BOM **\n") ;
    #endif
//--- UTF-32LE BOM ?
  }else if ((inLength >= 4) && (inCString [0] == 0xFF) && (inCString [1] == 0xFE) && (inCString [2] == 0) && (inCString [3] == 0)) {
    ok = parseUTF32LE (inCString + 4, inLength - 4, outResultString) ;
    outTextFileEncoding = kUTF_32LE_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-32LE BOM **\n") ;
    #endif
//--- UTF-8 BOM ?
  }else if ((inLength >= 3) && (inCString [0] == 0xEF) && (inCString [1] == 0xBB) && (inCString [2] == 0x3F)) {
    ok = C_String::parseUTF8 (inCString + 3, inLength - 3, outResultString) ;
    outTextFileEncoding = kUTF_8_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-8 BOM **\n") ;
    #endif
//--- UTF-16LE BOM ?
  }else if ((inLength >= 2) && (inCString [0] == 0xFF) && (inCString [1] == 0xFE)) {
    ok = parseUTF16LE (inCString + 2, inLength - 2, outResultString) ;
    outTextFileEncoding = kUTF_16LE_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-16LE BOM **\n") ;
    #endif
//--- UTF-16BE BOM ?
  }else if ((inLength >= 2) && (inCString [0] == 0xFE) && (inCString [1] == 0xFF)) {
    ok = parseUTF16BE (inCString + 2, inLength - 2, outResultString) ;
    outTextFileEncoding = kUTF_16BE_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-16BE BOM **\n") ;
    #endif
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
static bool
sniffUTFEncodingAndParse (const PMUInt8 * inCString,
                          const PMSInt32 inLength,
                          PMTextFileEncoding & outTextFileEncoding,
                          C_String & outResultString) {
//--- Try UTF-8
  bool ok = C_String::parseUTF8 (inCString, inLength, outResultString) ;
  if (ok) {
    outTextFileEncoding = kUTF_8_FileEncoding ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("sniffed UTF-8 encoding **\n") ;
    #endif
  }
//--- Try UTF-32BE
  if (! ok) {
    ok = parseUTF32BE (inCString, inLength, outResultString) ;
    if (ok) {
      outTextFileEncoding = kUTF_32BE_FileEncoding ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("sniffed UTF-32BE encoding **\n") ;
      #endif
    }
  }
//--- Try UTF-32LE
  if (! ok) {
    ok = parseUTF32LE (inCString, inLength, outResultString) ;
    if (ok) {
      outTextFileEncoding = kUTF_32LE_FileEncoding ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("sniffed UTF-32LE encoding **\n") ;
      #endif
    }
  }
//--- Try UTF-16LE
  if (! ok) {
    ok = parseUTF16LE (inCString, inLength, outResultString) ;
    if (ok) {
      outTextFileEncoding = kUTF_16LE_FileEncoding ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("sniffed UTF-16LE encoding **\n") ;
      #endif
    }
  }
//--- Try UTF-16BE
  if (! ok) {
    ok = parseUTF16BE (inCString, inLength, outResultString) ;
    if (ok) {
      outTextFileEncoding = kUTF_16BE_FileEncoding ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("sniffed UTF-16BE encoding **\n") ;
      #endif
    }
  }
//---
  return ok ;
}

//---------------------------------------------------------------------------*
  
typedef struct {
  const char * mEncodingName ;
  const PMTextFileEncoding mTextFileEncoding ;
  const PMStringEncoding mStringEncoding ;
} encodingStruct ;

//---------------------------------------------------------------------------*
  
static const PMSInt32 kEncodingCount = 18 ;

static const encodingStruct kEncodings [kEncodingCount] = {
 {"ISO-8859-1", kISO_8859_1_FileEncoding, k8859_1_encoding},
 {"ISO-8859-2", kISO_8859_2_FileEncoding, k8859_2_encoding},
 {"ISO-8859-3", kISO_8859_3_FileEncoding, k8859_3_encoding},
 {"ISO-8859-4", kISO_8859_4_FileEncoding, k8859_4_encoding},
 {"ISO-8859-5", kISO_8859_5_FileEncoding, k8859_5_encoding},
 {"ISO-8859-6", kISO_8859_6_FileEncoding, k8859_6_encoding},
 {"ISO-8859-7", kISO_8859_7_FileEncoding, k8859_7_encoding},
 {"ISO-8859-8", kISO_8859_8_FileEncoding, k8859_8_encoding},
 {"ISO-8859-9", kISO_8859_9_FileEncoding, k8859_9_encoding},
 {"ISO-8859-10", kISO_8859_10_FileEncoding, k8859_10_encoding},
 {"ISO-8859-11", kISO_8859_11_FileEncoding, k8859_11_encoding},
 {"ISO-8859-13", kISO_8859_13_FileEncoding, k8859_13_encoding},
 {"ISO-8859-14", kISO_8859_14_FileEncoding, k8859_14_encoding},
 {"ISO-8859-15", kISO_8859_15_FileEncoding, k8859_15_encoding},
 {"ISO-8859-16", kISO_8859_16_FileEncoding, k8859_16_encoding},
 {"CP-1252", kCP1252_FileEncoding, kCP1252_encoding},
 {"CP-437", kCP437_DOS_FileEncoding, kCP437_DOS_encoding},
 {"MacRoman", kMacRoman_FileEncoding, kMacRoman_encoding}
} ;

//---------------------------------------------------------------------------*
  
static bool
searchForEncodingTagAndParse (const PMUInt8 * inCString,
                              const PMSInt32 inLength,
                              PMTextFileEncoding & outTextFileEncoding,
                              C_String & outResultString) {
//--- Copy first line
  char firstLine [1000] ;
  PMSInt32 index = 0 ;
  bool eol = false ;
  while ((index < 999) && ! eol) {
    if ((inCString [index] == 0x0A) || (inCString [index] == 0x0D)) {
      firstLine [index] = '\0' ;
      eol = true ;
    }else{
      firstLine [index] = (char) inCString [index] ;
    }
    index ++ ;
  }
  if (! eol) {
    firstLine [index] = '\0' ;
  }
  bool ok = false ;
//--- Search for Tag
  bool tagFound = false ;
  if (strstr (firstLine, "UTF-8") != NULL) {
    ok = C_String::parseUTF8 (inCString, inLength, outResultString) ;
    outTextFileEncoding = kUTF_8_FileEncoding ;
    tagFound = true ;
    #ifdef PRINT_SNIFF_ENCODING
      printf ("found UTF-8 tag in first line **\n") ;
    #endif
  }
  for (PMSInt32 i=0 ; (i<kEncodingCount) && ! tagFound ; i++) {
    tagFound = strstr (firstLine, kEncodings [i].mEncodingName) != NULL ;
    if (tagFound) {
      ok = parseWithEncoding (inCString, inLength, kEncodings [i].mStringEncoding, outResultString) ;
      outTextFileEncoding = kEncodings [i].mTextFileEncoding ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("found '%s' tag in first line **\n", kEncodings [i].mEncodingName) ;
      #endif
    }
  }
  return ok ;
}

//---------------------------------------------------------------------------*
  
C_String C_String::
stringWithContentOfFile (const C_String & inFilePath,
                         PMTextFileEncoding & outTextFileEncoding,
                         bool & outOk) {
  #ifdef PRINT_SNIFF_ENCODING
    printf ("** SNIFF ENCODING for '%s': ", inFilePath.cString (HERE)) ;
  #endif
//--- Read file
  PMSInt32 length = 0 ;
  PMUInt8 * cString = readFile (inFilePath, outOk, length) ;
//--- Assign C string to C_String
  C_String result_string ;
  if (outOk) {
    result_string.setCapacity (length + 2) ;
  //------------ 1- Search for BOM
    outOk = searchBOMandParse (cString, length, outTextFileEncoding, result_string) ;
  //------------ 2- Try UTF-32BE, UTF-32LE, UTF-16BE, UTF-16LE, UTF-8 encodings
    if (! outOk) {
      outOk = sniffUTFEncodingAndParse (cString, length, outTextFileEncoding, result_string) ;
    }
  //------------ 3- Search for encoding name in the first line
    if (! outOk) {
      outOk = searchForEncodingTagAndParse (cString, length, outTextFileEncoding, result_string) ;
    }
  //------------ 4- ASCII read
    if (! outOk) {
      parseASCIIWithReplacementCharacter (cString, length, result_string) ;
      outTextFileEncoding = kUTF_8_FileEncoding ;
      outOk = true ;
      #ifdef PRINT_SNIFF_ENCODING
        printf ("default ASCII read **\n") ;
      #endif
    }
  }
  macroMyDeletePODArray (cString) ;
  return result_string ;
}

//---------------------------------------------------------------------------*
  
C_String C_String::stringWithContentOfFile (const C_String & inFilePath) {
  bool ok = false ;
  PMTextFileEncoding textFileEncoding ;
  C_String result_string = stringWithContentOfFile (inFilePath, textFileEncoding, ok) ;
//--- Assign C string to C_String
  if (! ok) {
    throw C_TextReadException (inFilePath.cString (HERE)) ;
  }
  return result_string ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========== C_TextReadException
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//  Exception generated by readTextFile method when a read error occurs      *
//                                                                           *
//---------------------------------------------------------------------------*

C_TextReadException::
C_TextReadException (const char * inFileName) {
  snprintf (mErrorMessage, kTextReadExceptionStringMaxLength, "cannot open file '%s' for reading", inFileName) ;
}

//---------------------------------------------------------------------------*

const char * C_TextReadException::what (void) const throw () {
  return mErrorMessage ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========== Symbolic links
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//    S Y M B O L I C    L I N K S                                           *
//                                                                           *
//---------------------------------------------------------------------------*

// See http://www.gnu.org/s/libc/manual/html_node/Symbolic-Links.html

//--- Symbolic links and Windows:
// See http://answers.google.com/answers/threadview/id/341355.html

//---------------------------------------------------------------------------*

bool C_String::isSymbolicLink (void) const {
  #ifdef COMPILE_FOR_WIN32
    return false ; // Symbolic links are not supported on Windows
  #elif defined TARGET_API_MAC_CARBON
    return false ; // Symbolic links are not supported on Carbon
  #else
    char buffer [8] ; // Any value
    return readlink (cString (HERE), buffer, 8) >= 0 ;
  #endif
}

//---------------------------------------------------------------------------*

C_String C_String::stringWithSymbolicLinkContents (bool & outOk) const {
  C_String result ;
  #ifdef COMPILE_FOR_WIN32
    outOk = false ; // Symbolic links are not supported on Windows
  #elif defined TARGET_API_MAC_CARBON
    outOk = false ; // Symbolic links are not supported on Carbon
  #else
    bool loop = true ;
    outOk = true ;
    char * buffer = NULL ;
    size_t bufferSize = 128 ;
    while (loop) {
      macroMyReallocPODArray (buffer, char, bufferSize) ;
      const PMSInt64 r = readlink (cString (HERE), buffer, bufferSize) ;
      if (r < 0) { // Error
        outOk = false ;
        loop = false ;
      }else if (r < (PMSInt64) bufferSize) { // ok
        buffer [r] = '\0' ;
        result << buffer ;
        loop = false ;
      }else{ // Buffer too small
        bufferSize *= 2 ;
      }
    }
    macroMyDeletePODArray (buffer) ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  bool C_String::makeSymbolicLinkWithPath (const C_String & /* inPath */) const {
    return true ; // Symbolic links are not supported on Windows
  }
#elif defined TARGET_API_MAC_CARBON
  bool C_String::makeSymbolicLinkWithPath (const C_String & /* inPath */) const {
    return true ; // Symbolic links are not supported on Carbon
  }
#else
  bool C_String::makeSymbolicLinkWithPath (const C_String & inPath) const {
    const int r = symlink (inPath.cString (HERE), cString (HERE)) ;
    return r >= 0 ;
  }
#endif

//---------------------------------------------------------------------------*

static inline PMUInt32 minimum (const PMUInt32 inA, const PMUInt32 inB) { return inA < inB ? inA : inB ; }

//---------------------------------------------------------------------------*

PMUInt32 C_String::LevenshteinDistanceFromString (const C_String & inOperand) const {

//char s[1..m], char t[1..n])
//{
  const PMSInt32 myLength = length () ;
  const PMSInt32 operandLength = inOperand.length () ;
  // for all i and j, d[i,j] will hold the Levenshtein distance between
  // the first i characters of s and the first j characters of t;
  // note that d has (m+1)x(n+1) values
  TC_UniqueArray2 <PMUInt32> distance (myLength + 1, operandLength + 1) ;

  for (PMSInt32 i=0 ; i<=myLength ; i++) {
    distance (i, 0 COMMA_HERE) = (PMUInt32) i ;
  }
 
  for (PMSInt32 j=0 ; j<=operandLength ; j++) {
    distance (0, j COMMA_HERE) = (PMUInt32) j ;
  }
 
  for (PMSInt32 j=1 ; j<=operandLength ; j++) {
    for (PMSInt32 i=1 ; i<=myLength ; i++) {
      if (UNICODE_VALUE (this->operator () (i-1 COMMA_HERE)) == UNICODE_VALUE (inOperand (j-1 COMMA_HERE))) {
        distance (i, j COMMA_HERE) = distance (i-1, j-1 COMMA_HERE) ;       // no operation required
      }else{
        distance (i, j COMMA_HERE) = minimum (minimum (
          distance (i-1, j COMMA_HERE) + 1,  // a deletion
          distance (i, j-1 COMMA_HERE) + 1),  // an insertion
          distance (i-1, j-1 COMMA_HERE) + 1 // a substitution
        ) ;
      }
    }
  }
  return distance (myLength, operandLength COMMA_HERE) ;
}

/* int LevenshteinDistance(char s[1..m], char t[1..n])
{
  // for all i and j, d[i,j] will hold the Levenshtein distance between
  // the first i characters of s and the first j characters of t;
  // note that d has (m+1)x(n+1) values
  declare int d[0..m, 0..n]

  for i from 0 to m
    d[i, 0] := i // the distance of any first string to an empty second string
  for j from 0 to n
    d[0, j] := j // the distance of any second string to an empty first string

  for j from 1 to n
  {
    for i from 1 to m
    {
      if s[i] = t[j] then  
        d[i, j] := d[i-1, j-1]       // no operation required
      else
        d[i, j] := minimum
                   (
                     d[i-1, j] + 1,  // a deletion
                     d[i, j-1] + 1,  // an insertion
                     d[i-1, j-1] + 1 // a substitution
                   )
    }
  }

  return d[m,n]
} */

//---------------------------------------------------------------------------*
