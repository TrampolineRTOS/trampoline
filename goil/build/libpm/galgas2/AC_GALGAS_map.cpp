//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  AC_GALGAS_map : Base class for GALGAS map                                                                          *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2014 Pierre Molinaro.                                                                     *
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

#include "galgas2/predefined-types.h"
#include "galgas2/capCollectionElement.h"
#include "galgas2/C_galgas_type_descriptor.h"
#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_Compiler.h"
#include "strings/unicode_string_routines.h"
#include "galgas2/C_galgas_CLI_Options.h"

//---------------------------------------------------------------------------------------------------------------------*

class cMapNode ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  c S h a r e d M a p R o o t                                                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cSharedMapRoot : public C_SharedObject {
//--------------------------------- Attributes
  private : cMapNode * mRoot ;
  private : uint32_t mCount ;
  protected : cSharedMapRoot * mOverridenMap ;

//--------------------------------- Accessors
  public : inline const cMapNode * root (void) const { return mRoot ; }
  public : inline uint32_t count (void) const { return mCount ; }

//--------------------------------- Constructor
  protected : cSharedMapRoot (LOCATION_ARGS) ;

//--------------------------------- Virtual destructor
  public : virtual ~ cSharedMapRoot (void) ;

//--------------------------------- No copy
  private : cSharedMapRoot (const cSharedMapRoot &) ;
  private : cSharedMapRoot & operator = (const cSharedMapRoot &) ;

//--------------------------------- Copy a map
  protected : VIRTUAL_IN_DEBUG void copyFrom (const cSharedMapRoot * inSource) ;

//--------------------------------- Attribute read access
  private : VIRTUAL_IN_DEBUG const cMapNode * findNodeForKeyInMapOrInOverridenMaps (const GALGAS_string & inKey,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- Insert or Replace
  protected : VIRTUAL_IN_DEBUG void performInsertOrReplace (const capCollectionElement & inAttributes) ;

//--------------------------------- Insert
  protected : VIRTUAL_IN_DEBUG cMapNode * performInsert (const capCollectionElement & inAttributes,
                                                         C_Compiler * inCompiler,
                                                         const char * inInsertErrorMessage,
                                                         const char * inShadowErrorMessage
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Search
  private : VIRTUAL_IN_DEBUG cMapNode * findEntryInMap (const C_String & inKey,
                                                        const cSharedMapRoot * inFirstMap) const ;

  private : VIRTUAL_IN_DEBUG cMapNode * findEntryInMapAtLevel (const C_String & inKey,
                                                               const uint32_t inLevel,
                                                               const cSharedMapRoot * inFirstMap) const ;

  public : VIRTUAL_IN_DEBUG void findNearestKey (const C_String & inKey,
                                                 TC_UniqueArray <C_String> & ioNearestKeyArray) const ;

  protected : VIRTUAL_IN_DEBUG cMapNode * performSearch (const GALGAS_lstring & inKey,
                                                         C_Compiler * inCompiler,
                                                         const char * inSearchErrorMessage
                                                         COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG const cMapElement * searchForReadingAttribute (const GALGAS_string & inKey,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG cMapElement * searchForReadWriteAttribute (const GALGAS_string & inKey,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG cMapElement * searchForReadWriteAttribute (const GALGAS_lstring & inKey,
                                                                          C_Compiler * inCompiler,
                                                                          const char * inSearchErrorMessage
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Remove
  protected : VIRTUAL_IN_DEBUG void performRemove (GALGAS_lstring & inKey,
                                                   capCollectionElement & outResult,
                                                   C_Compiler * inCompiler,
                                                   const char * inRemoveErrorMessage
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Readers
  protected : VIRTUAL_IN_DEBUG GALGAS_bool hasKey (const GALGAS_string & inKey
                                                   COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG GALGAS_uint levels (UNUSED_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_bool hasKeyAtLevel (const GALGAS_string & inKey,
                                                       const GALGAS_uint & inLevel
                                                       COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG GALGAS_location locationForKey (const GALGAS_string & inKey,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG GALGAS_stringset keySet (LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG GALGAS_lstringlist keyList (LOCATION_ARGS) const ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation,
                                              const uint32_t inLevel) const ;

//--------------------------------- Internal method for enumeration
  protected : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & ioEnumerationArray,
                                                              const typeEnumerationOrder inEnumerationOrder) const ;

//--------------------------------- Comparison
  public : VIRTUAL_IN_DEBUG typeComparisonResult mapCompare (const cSharedMapRoot * inOperand) const ;


//--------------------------------- Check Map
  #ifndef DO_NOT_GENERATE_CHECKINGS
    private : VIRTUAL_IN_DEBUG void checkMap (LOCATION_ARGS) const ;
  #endif

//--------------------------------- Friend
  friend class AC_GALGAS_map ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  c M a p N o d e                                                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapNode {
  public : cMapNode * mInfPtr ;
  public : cMapNode * mSupPtr ;
  public : int32_t mBalance ;
  public : const C_String mKey ;
  public : capCollectionElement mAttributes ;

//--- Constructors
  public : cMapNode (const C_String & inKey,
                     const capCollectionElement & inAttributes) ;

  public : cMapNode (cMapNode * inNode) ;

//--- Destructor
  public : ~ cMapNode (void) ;

//--- No copy
  private : cMapNode (const cMapNode &) ;
  private : cMapNode & operator = (const cMapNode &) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cSharedMapRoot::cSharedMapRoot (LOCATION_ARGS) :
C_SharedObject (THERE),
mRoot (NULL),
mCount (0),
mOverridenMap (NULL) {
}

//---------------------------------------------------------------------------------------------------------------------*

cSharedMapRoot::~ cSharedMapRoot (void) {
  macroMyDelete (mRoot) ;
  macroDetachSharedObject (mOverridenMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapNode::cMapNode (const C_String & inKey,
                    const capCollectionElement & inAttributes) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mKey (inKey),
mAttributes (inAttributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

cMapNode::~cMapNode (void) {
  macroMyDelete (mInfPtr) ;
  macroMyDelete (mSupPtr) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Check Map
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void checkNode (const cMapNode * inNode,
                         uint32_t & ioCount) {
    if (NULL != inNode) {
     checkNode (inNode->mInfPtr, ioCount) ;
     if (inNode->mAttributes.ptr () != NULL) {
       ioCount ++ ;
     }
     checkNode (inNode->mSupPtr, ioCount) ;
    }
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cSharedMapRoot::checkMap (LOCATION_ARGS) const {
    uint32_t n = 0 ;
    checkNode (mRoot, n) ;
    MF_AssertThere (n == mCount, "n (%lld) != mCount (%lld)", n, mCount) ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructor, destructor and copy
#endif

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_map::AC_GALGAS_map (void) :
AC_GALGAS_root (),
mSharedMap (NULL) {
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_map::AC_GALGAS_map (const AC_GALGAS_map & inSource) :
AC_GALGAS_root (),
mSharedMap (NULL) {
  macroAssignSharedObject (mSharedMap, inSource.mSharedMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_map & AC_GALGAS_map::operator = (const AC_GALGAS_map & inSource) {
  macroAssignSharedObject (mSharedMap, inSource.mSharedMap) ;
  return *this ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_map::~AC_GALGAS_map (void) {
  macroDetachSharedObject (mSharedMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_map::drop (void) {
  macroDetachSharedObject (mSharedMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_map::makeNewEmptyMap (LOCATION_ARGS) {
  macroMyNew (mSharedMap, cSharedMapRoot (THERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_map::makeNewEmptyMapWithMapToOverride (const AC_GALGAS_map & inMapToOverride
                                                      COMMA_LOCATION_ARGS) {
  if (inMapToOverride.isValid ()) {
    macroMyNew (mSharedMap, cSharedMapRoot (THERE)) ;
    macroAssignSharedObject (mSharedMap->mOverridenMap, inMapToOverride.mSharedMap) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Description, log
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void internalDescription (cMapNode * inNode,
                                 C_String & ioString,
                                 const int32_t inIndentation,
                                 uint32_t & ioIdx) {
  if (NULL != inNode) {
    internalDescription (inNode->mInfPtr, ioString, inIndentation, ioIdx) ;
    ioString << "\n" ;
    ioString.writeStringMultiple ("| ", inIndentation) ;
    ioString << "|-at " << cStringWithUnsigned (ioIdx)
             << ": key '" << inNode->mKey << "' " ;
    inNode->mAttributes.description (ioString, inIndentation + 2) ;
    ioIdx ++ ;
    internalDescription (inNode->mSupPtr, ioString, inIndentation, ioIdx) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedMapRoot::description (C_String & ioString,
                                  const int32_t inIndentation,
                                  const uint32_t inLevel) const {
  if (inLevel > 0) {
    ioString << "\n" ;
    ioString.writeStringMultiple ("| ", inIndentation + 1) ;
    ioString << "override #" << cStringWithUnsigned (inLevel) ;
  }
  ioString << " ("
           << cStringWithUnsigned (count ())
           << " object" << ((count () > 1) ? "s" : "")
           << "): " ;
  uint32_t idx = 0 ;
  internalDescription (mRoot, ioString, inIndentation, idx) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_map::description (C_String & ioString,
                                 const int32_t inIndentation) const {
  ioString << "<map @"
           << staticTypeDescriptor ()->mGalgasTypeName ;
  if (isValid ()) {
    const cSharedMapRoot * currentMap = mSharedMap ;
    uint32_t level = 0 ;
    while (NULL != currentMap) {
      currentMap->description (ioString, inIndentation, level) ;
      level ++ ;
      currentMap = currentMap->mOverridenMap ;
    }
  }else{
    ioString << " not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Search in map and overridden maps
#endif

//---------------------------------------------------------------------------------------------------------------------*

cMapNode * cSharedMapRoot::findEntryInMapAtLevel (const C_String & inKey,
                                                  const uint32_t inLevel,
                                                  const cSharedMapRoot * inFirstMap) const {
  cMapNode * result = NULL ;
  const cSharedMapRoot * currentMap = inFirstMap ;
  uint32_t level = 0 ;
  while ((NULL != currentMap) && (NULL == result)) {
    if (inLevel == level) {
      cMapNode * currentNode = currentMap->mRoot ;
      while ((currentNode != NULL) && (NULL == result)) {
        macroValidPointer (currentNode) ;
        const int32_t comparaison = currentNode->mKey.compare (inKey) ;
        if (comparaison > 0) {
          currentNode = currentNode->mInfPtr ;
        }else if (comparaison < 0) {
          currentNode = currentNode->mSupPtr ;
        }else{ // Found
          result = currentNode ;
        }
      }
    }
    level ++ ;
    currentMap = currentMap->mOverridenMap ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapNode * cSharedMapRoot::findEntryInMap (const C_String & inKey,
                                           const cSharedMapRoot * inFirstMap) const {
  cMapNode * result = NULL ;
  const cSharedMapRoot * currentMap = inFirstMap ;
  while ((NULL != currentMap) && (NULL == result)) {
    cMapNode * currentNode = currentMap->mRoot ;
    while ((currentNode != NULL) && (NULL == result)) {
      macroValidPointer (currentNode) ;
      const int32_t comparaison = currentNode->mKey.compare (inKey) ;
      if (comparaison > 0) {
        currentNode = currentNode->mInfPtr ;
      }else if (comparaison < 0) {
        currentNode = currentNode->mSupPtr ;
      }else{ // Found
        result = currentNode ;
      }
    }
    currentMap = currentMap->mOverridenMap ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

const cMapNode * cSharedMapRoot::findNodeForKeyInMapOrInOverridenMaps (const GALGAS_string & inKey,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  const cMapNode * result = NULL ;
  if (inKey.isValid ()) {
    const C_String key = inKey.stringValue () ;
    result = findEntryInMap (key, this) ;
    if (NULL == result) {
      C_String errorMessage ;
      errorMessage << "the '" << key << "' key is not defined in map" ;
      inCompiler->onTheFlyRunTimeError (errorMessage COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapNode * AC_GALGAS_map::searchEntryInMap (const C_String & inKey) const {
  cMapNode * result = NULL ;
  if (isValid ()) {
    result = mSharedMap->findEntryInMap (inKey, mSharedMap) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Search for "with instruction" read only access
#endif

//---------------------------------------------------------------------------------------------------------------------*

const cCollectionElement * AC_GALGAS_map::readAccessForWithInstruction (const GALGAS_string & inKey) const {
  const cCollectionElement * result = NULL ;
  if (isValid () && inKey.isValid ()) {
    cMapNode * node = mSharedMap->findEntryInMap (inKey.stringValue (), mSharedMap) ;
    if (NULL != node) {
      result = node->mAttributes.ptr () ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * AC_GALGAS_map::readWriteAccessForWithInstructionWithErrorMessage (C_Compiler * inCompiler,
                                                                                       const GALGAS_lstring & inKey,
                                                                                       const char * inSearchErrorMessage
                                                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * result = NULL ;
  if (isValid () && inKey.isValid ()) {
    insulate (HERE) ;
    const C_String key = inKey.mAttribute_string.stringValue () ;
    cMapNode * node = mSharedMap->findEntryInMap (key, mSharedMap) ;
    if (NULL == node) {
      TC_UniqueArray <C_String> nearestKeyArray ;
      mSharedMap->findNearestKey (key, nearestKeyArray) ;
      inCompiler->semanticErrorWith_K_message (inKey, nearestKeyArray, inSearchErrorMessage COMMA_THERE) ;
    }else{
      result = node->mAttributes.ptr () ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Insert Or Replace
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void rotateLeft (cMapNode * & ioRootPtr) {
  cMapNode * b = ioRootPtr->mSupPtr ;
  ioRootPtr->mSupPtr = b->mInfPtr ;
  b->mInfPtr = ioRootPtr;

  if (b->mBalance >= 0) {
    ioRootPtr->mBalance++ ;
  }else{
    ioRootPtr->mBalance += 1 - b->mBalance ;
  }

  if (ioRootPtr->mBalance > 0) {
    b->mBalance += ioRootPtr->mBalance + 1 ;
  }else{
    b->mBalance++ ;
  }
  ioRootPtr = b ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void rotateRight (cMapNode * & ioRootPtr) {
  cMapNode * b = ioRootPtr->mInfPtr ;
  ioRootPtr->mInfPtr = b->mSupPtr ;
  b->mSupPtr = ioRootPtr ;
 
  if (b->mBalance > 0) {
    ioRootPtr->mBalance += -b->mBalance - 1 ;
  }else{
    ioRootPtr->mBalance-- ;
  }
  if (ioRootPtr->mBalance >= 0) {
    b->mBalance-- ;
  }else{
    b->mBalance += ioRootPtr->mBalance - 1 ;
  }
  ioRootPtr = b ;
}

//---------------------------------------------------------------------------------------------------------------------*

static bool internalInsertOrReplace (cMapNode * & ioRootPtr,
                                     const C_String & inKey,
                                     const capCollectionElement & ioAttributeArray,
                                     bool & ioExtension) {
  bool anObjectHasBeenAdded = false ;
  if (ioRootPtr == NULL) {
    macroMyNew (ioRootPtr, cMapNode (inKey, ioAttributeArray)) ;
    ioExtension = true ;
    anObjectHasBeenAdded = true ;
  }else{
    macroValidPointer (ioRootPtr) ;
    const int32_t comparaison = ioRootPtr->mKey.compare (inKey) ;
    if (comparaison > 0) {
      anObjectHasBeenAdded = internalInsertOrReplace (ioRootPtr->mInfPtr, inKey, ioAttributeArray, ioExtension) ;
      if (ioExtension) {
        ioRootPtr->mBalance++;
        if (ioRootPtr->mBalance == 0) {
          ioExtension = false;
        }else if (ioRootPtr->mBalance == 2) {
          if (ioRootPtr->mInfPtr->mBalance == -1) {
            rotateLeft (ioRootPtr->mInfPtr) ;
          }
          rotateRight (ioRootPtr) ;
          ioExtension = false;
        }
      }
    }else if (comparaison < 0) {
      anObjectHasBeenAdded = internalInsertOrReplace (ioRootPtr->mSupPtr, inKey, ioAttributeArray, ioExtension) ;
      if (ioExtension) {
        ioRootPtr->mBalance-- ;
        if (ioRootPtr->mBalance == 0) {
          ioExtension = false ;
        }else if (ioRootPtr->mBalance == -2) {
          if (ioRootPtr->mSupPtr->mBalance == 1) {
            rotateRight (ioRootPtr->mSupPtr) ;
          }
          rotateLeft (ioRootPtr) ;
          ioExtension = false;
        }
      }
    }else{
      ioExtension = false ; // Found : perform replacement
      ioRootPtr->mAttributes = ioAttributeArray ;
    }
  }
  return anObjectHasBeenAdded ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedMapRoot::performInsertOrReplace (const capCollectionElement & inAttributes) {
  macroUniqueSharedObject (this) ;
//--- If all attributes are built, perform insertion
  if (inAttributes.isValid ()) {
    const cMapElement * p = (cMapElement *) inAttributes.ptr () ;
    macroValidSharedObject (p, cMapElement) ;
    const GALGAS_string string_key = p->mAttribute_lkey.mAttribute_string ;
    const C_String key = string_key.stringValue () ;
  //--- Insert or replace
    bool extension ; // Unused here
    const bool anObjectHasBeenAdded = internalInsertOrReplace (mRoot, key, inAttributes, extension) ;
    if (anObjectHasBeenAdded) {
      mCount ++ ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkMap (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_map::performInsertOrReplace (const capCollectionElement & inAttributes) {
  if (isValid ()) {
    insulate (HERE) ;
    if (NULL != mSharedMap) {
      mSharedMap->performInsertOrReplace (inAttributes) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Insulate
#endif

//---------------------------------------------------------------------------------------------------------------------*

cMapNode::cMapNode (cMapNode * inNode) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (inNode->mBalance),
mKey (inNode->mKey),
mAttributes (inNode->mAttributes) {
  if (inNode->mInfPtr != NULL) {
    macroMyNew (mInfPtr, cMapNode (inNode->mInfPtr)) ;
  }
  if (inNode->mSupPtr != NULL) {
    macroMyNew (mSupPtr, cMapNode (inNode->mSupPtr)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedMapRoot::copyFrom (const cSharedMapRoot * inSource) {
  macroUniqueSharedObject (this) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    inSource->checkMap (HERE) ;
  #endif
  macroValidSharedObject (inSource, cSharedMapRoot) ;
  mCount = inSource->mCount ;
  if (NULL != inSource->mRoot) {
    macroMyNew (mRoot, cMapNode (inSource->mRoot)) ;
  }
  macroAssignSharedObject (mOverridenMap, inSource->mOverridenMap) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkMap (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_map::insulate (LOCATION_ARGS) {
  if ((NULL != mSharedMap) && (mSharedMap->retainCount () > 1)) {
    cSharedMapRoot * p = NULL ;
    macroMyNew (p, cSharedMapRoot (THERE)) ;
    p->copyFrom (mSharedMap) ;
    macroAssignSharedObject (mSharedMap, p) ;
    macroDetachSharedObject (p) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Insert
#endif

//---------------------------------------------------------------------------------------------------------------------*

static cMapNode * internalInsert (cMapNode * & ioRootPtr,
                                  const C_String & inKey,
                                  const capCollectionElement & inAttributes,
                                  bool & outEntryAlreadyExists,
                                  bool & ioExtension) {
  cMapNode * matchingEntry = NULL ;
  if (ioRootPtr == NULL) {
    macroMyNew (ioRootPtr, cMapNode (inKey, inAttributes)) ;
    ioExtension = true ;
    matchingEntry = ioRootPtr ;
  }else{
    macroValidPointer (ioRootPtr) ;
    const int32_t comparaison = ioRootPtr->mKey.compare (inKey) ;
    if (comparaison > 0) {
      matchingEntry = internalInsert (ioRootPtr->mInfPtr, inKey, inAttributes, outEntryAlreadyExists, ioExtension) ;
      if (ioExtension) {
        ioRootPtr->mBalance ++ ;
        if (ioRootPtr->mBalance == 0) {
          ioExtension = false;
        }else if (ioRootPtr->mBalance == 2) {
          if (ioRootPtr->mInfPtr->mBalance == -1) {
            rotateLeft (ioRootPtr->mInfPtr) ;
          }
          rotateRight (ioRootPtr) ;
          ioExtension = false;
        }
      }
    }else if (comparaison < 0) {
      matchingEntry = internalInsert (ioRootPtr->mSupPtr, inKey, inAttributes, outEntryAlreadyExists, ioExtension) ;
      if (ioExtension) {
        ioRootPtr->mBalance-- ;
        if (ioRootPtr->mBalance == 0) {
          ioExtension = false ;
        }else if (ioRootPtr->mBalance == -2) {
          if (ioRootPtr->mSupPtr->mBalance == 1) {
            rotateRight (ioRootPtr->mSupPtr) ;
          }
          rotateLeft (ioRootPtr) ;
          ioExtension = false;
        }
      }
    }else{ // Error, entry already exists
      matchingEntry = ioRootPtr ;
      ioExtension = false ;
      outEntryAlreadyExists = NULL != matchingEntry->mAttributes.ptr () ;
      if (! outEntryAlreadyExists) {
        matchingEntry->mAttributes = inAttributes ;
      }
    }
  }
  return matchingEntry ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapNode * cSharedMapRoot::performInsert (const capCollectionElement & inAttributes,
                                          C_Compiler * inCompiler,
                                          const char * inInsertErrorMessage,
                                          const char * inShadowErrorMessage
                                          COMMA_LOCATION_ARGS) {
  cMapNode * result = NULL ;
  macroUniqueSharedObject (this) ;
//--- If all attributes are built, perform insertion
  if (inAttributes.isValid ()) {
    cMapElement * p = (cMapElement *) inAttributes.ptr () ;
    macroValidSharedObject (p, cMapElement) ;
    const C_String key = p->mAttribute_lkey.mAttribute_string.stringValue () ;
  //--- Insert or replace
    bool extension = false ; // Unused here
    bool entryAlreadyExists = false ;
    cMapNode * matchingEntry = internalInsert (mRoot, key, inAttributes, entryAlreadyExists, extension) ;
    if (! entryAlreadyExists) {
      result = matchingEntry ;
      mCount ++ ;
      const C_String shadowErrorMessage (inShadowErrorMessage) ;
      const int32_t shadowErrorMessageLength = shadowErrorMessage.length () ;
      if (shadowErrorMessageLength > 0) {
        matchingEntry = findEntryInMap (key, mOverridenMap) ;
        if (NULL != matchingEntry) {
        //--- Existing key
          cMapElement * me = (cMapElement *) matchingEntry->mAttributes.ptr () ;
          macroValidSharedObject (me, cMapElement) ;
          const GALGAS_location lstring_existingKey_location = me->mAttribute_lkey.mAttribute_location ;
        //--- Emit error message
          inCompiler->semanticErrorWith_K_L_message (p->mAttribute_lkey, inShadowErrorMessage, lstring_existingKey_location COMMA_THERE) ;
        }
      }
    }else{ // Error, entry already exists
    //--- Existing key
      cMapElement * me = (cMapElement *) matchingEntry->mAttributes.ptr () ;
      macroValidSharedObject (me, cMapElement) ;
      const GALGAS_location lstring_existingKey_location = me->mAttribute_lkey.mAttribute_location ;
    //--- Emit error message
      inCompiler->semanticErrorWith_K_L_message (p->mAttribute_lkey, inInsertErrorMessage, lstring_existingKey_location COMMA_THERE) ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkMap (HERE) ;
  #endif
//---
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_map::performInsert (const capCollectionElement & inAttributes,
                                   C_Compiler * inCompiler,
                                   const char * inInsertErrorMessage,
                                   const char * inShadowErrorMessage
                                   COMMA_LOCATION_ARGS) {
//--- If all attributes are built, perform insertion
  if (isValid ()) {
    insulate (HERE) ;
    if (NULL != mSharedMap) {
      mSharedMap->performInsert (inAttributes, inCompiler, inInsertErrorMessage, inShadowErrorMessage COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader count
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint AC_GALGAS_map::reader_count (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mSharedMap->count ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t AC_GALGAS_map::count (void) const {
  uint32_t result = 0 ;
  if (isValid ()) {
    result = mSharedMap->count () ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader "keySet"
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void enterKeyInStringSet (const cMapNode * inNode,
                                 GALGAS_stringset & ioResult) {
  if (inNode != NULL) {
    enterKeyInStringSet (inNode->mInfPtr, ioResult) ;
    GALGAS_string object (inNode->mKey) ;
    ioResult.addAssign_operation (object COMMA_HERE) ;
    enterKeyInStringSet (inNode->mSupPtr, ioResult) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset cSharedMapRoot::keySet (LOCATION_ARGS) const {
  GALGAS_stringset result = GALGAS_stringset::constructor_emptySet (THERE) ;
  enterKeyInStringSet (mRoot, result) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset AC_GALGAS_map::reader_keySet (LOCATION_ARGS) const {
  GALGAS_stringset result ;
  if (isValid ()) {
    result = mSharedMap->keySet (THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader "keyList"
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void enterKeyInLStringList (cMapNode * inNode,
                                   GALGAS_lstringlist & ioResult) {
  if (inNode != NULL) {
    enterKeyInLStringList (inNode->mInfPtr, ioResult) ;
    cMapElement * p = (cMapElement *) inNode->mAttributes.ptr () ;
    if (NULL != p) {
      macroValidSharedObject (p, cMapElement) ;
      ioResult.addAssign_operation (p->mAttribute_lkey COMMA_HERE) ;
    }
    enterKeyInLStringList (inNode->mSupPtr, ioResult) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cSharedMapRoot::keyList (LOCATION_ARGS) const {
  GALGAS_lstringlist result = GALGAS_lstringlist::constructor_emptyList (THERE) ;
  enterKeyInLStringList (mRoot, result) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist AC_GALGAS_map::reader_keyList (LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (isValid ()) {
    result = mSharedMap->keyList (THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader locationForKey
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cSharedMapRoot::locationForKey (const GALGAS_string & inKey,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (inKey.isValid ()) {
    const C_String key = inKey.stringValue () ;
    cMapNode * node = findEntryInMap (key, this) ;
    if (NULL == node) {
      C_String message ;
      message << "'locationForKey' map reader run-time error: the '" << key << "' does not exist in map" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      cMapElement * p = (cMapElement *) node->mAttributes.ptr () ;
      macroValidSharedObject (p, cMapElement) ;
      result = p->mAttribute_lkey.mAttribute_location ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location AC_GALGAS_map::reader_locationForKey (const GALGAS_string & inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (isValid ()) {
    result = mSharedMap->locationForKey (inKey, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader levels
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cSharedMapRoot::levels (UNUSED_LOCATION_ARGS) const {
  uint32_t levelCount = 0 ;
  const cSharedMapRoot * currentMap = this ;
  while (NULL != currentMap) {
    currentMap = currentMap->mOverridenMap ;
    levelCount ++ ;
  }
  return GALGAS_uint (levelCount) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint AC_GALGAS_map::reader_levels (LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = mSharedMap->levels (THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader hasKeyAtLevel
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cSharedMapRoot::hasKeyAtLevel (const GALGAS_string & inKey,
                                           const GALGAS_uint & inLevel
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (inKey.isValid () && inLevel.isValid ()) {
    const C_String key = inKey.stringValue () ;
    const cMapNode * node = findEntryInMapAtLevel (key, inLevel.uintValue (), this) ;
    result = GALGAS_bool (NULL != node) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool AC_GALGAS_map::reader_hasKeyAtLevel (const GALGAS_string & inKey,
                                                 const GALGAS_uint & inLevel
                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = mSharedMap->hasKeyAtLevel (inKey, inLevel COMMA_THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader hasKey
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cSharedMapRoot::hasKey (const GALGAS_string & inKey
                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (inKey.isValid ()) {
    const C_String key = inKey.stringValue () ;
    const cMapNode * node = findEntryInMap (key, this) ;
    result = GALGAS_bool (NULL != node) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool AC_GALGAS_map::reader_hasKey (const GALGAS_string & inKey
                                          COMMA_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = mSharedMap->hasKey (inKey COMMA_THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Search
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void findNearestKeyForNode (const C_String & inKey,
                                   const cMapNode * inCurrentNode,
                                   uint32_t & ioBestDistance,
                                   TC_UniqueArray <C_String> & ioNearestKeyArray) {
  if (NULL != inCurrentNode) {
    macroValidPointer (inCurrentNode) ;
    const uint32_t distance = inCurrentNode->mKey.LevenshteinDistanceFromString (inKey) ;
    // printf ("inCurrentNode->mKey '%s', distance %u\n", inCurrentNode->mKey.cString (HERE), distance) ;
    if (ioBestDistance > distance) {
      ioBestDistance = distance ;
      ioNearestKeyArray.setCountToZero () ;
      ioNearestKeyArray.addObject (inCurrentNode->mKey) ;
    }else if (ioBestDistance == distance) {
      ioNearestKeyArray.addObject (inCurrentNode->mKey) ;
    }
    findNearestKeyForNode (inKey, inCurrentNode->mInfPtr, ioBestDistance, ioNearestKeyArray) ;
    findNearestKeyForNode (inKey, inCurrentNode->mSupPtr, ioBestDistance, ioNearestKeyArray) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedMapRoot::findNearestKey (const C_String & inKey,
                                     TC_UniqueArray <C_String> & ioNearestKeyArray) const {
  ioNearestKeyArray.setCountToZero () ;
  uint32_t bestDistance = UINT32_MAX ;
  const cSharedMapRoot * currentMap = this ;
  while (NULL != currentMap) {
    findNearestKeyForNode (inKey, currentMap->mRoot, bestDistance, ioNearestKeyArray) ;
    currentMap = currentMap->mOverridenMap ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapNode * cSharedMapRoot::performSearch (const GALGAS_lstring & inKey,
                                          C_Compiler * inCompiler,
                                          const char * inSearchErrorMessage
                                          COMMA_LOCATION_ARGS) const {
  cMapNode * result = NULL ;
  if (inKey.isValid ()) {
    const C_String key = inKey.mAttribute_string.stringValue () ;
    result = findEntryInMap (key, this) ;
    if (NULL == result) {
      TC_UniqueArray <C_String> nearestKeyArray ;
      findNearestKey (key, nearestKeyArray) ;
      inCompiler->semanticErrorWith_K_message (inKey, nearestKeyArray, inSearchErrorMessage COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

const cCollectionElement * AC_GALGAS_map::performSearch (const GALGAS_lstring & inKey,
                                                         C_Compiler * inCompiler,
                                                         const char * inSearchErrorMessage
                                                         COMMA_LOCATION_ARGS) const {
  const cCollectionElement * result = NULL ;
  if (isValid () && inKey.isValid ()) {
    const cMapNode * node = mSharedMap->performSearch (inKey, inCompiler, inSearchErrorMessage COMMA_THERE) ;
    if (NULL != node) {
      result = node->mAttributes.ptr () ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark searchForReadingAttribute
#endif

//---------------------------------------------------------------------------------------------------------------------*

const cMapElement * cSharedMapRoot::searchForReadingAttribute (const GALGAS_string & inKey,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  const cMapElement * result = NULL ;
  if (inKey.isValid ()) {
    const C_String key = inKey.stringValue () ;
    cMapNode * node = findEntryInMap (key, this) ;
    if (NULL != node) {
      result = (const cMapElement *) node->mAttributes.ptr () ;
      macroValidSharedObject (result, cMapElement) ;
    }else{
    //--- Build error message
      C_String message ;
      message << "cannot read attribute in map: the '" << key << "' key does not exist" ;
    //--- Emit error message
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

const cMapElement * AC_GALGAS_map::searchForReadingAttribute (const GALGAS_string & inKey,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  const cMapElement * result = NULL ;
  if (isValid ()) {
    result = mSharedMap->searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark searchForReadWriteAttribute (string)
#endif

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cSharedMapRoot::searchForReadWriteAttribute (const GALGAS_string & inKey,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  cMapElement * result = NULL ;
  if (inKey.isValid ()) {
    const C_String key = inKey.stringValue () ;
    cMapNode * node = findEntryInMap (key, this) ;
    if (NULL != node) {
      node->mAttributes.insulate () ;
      result = (cMapElement *) node->mAttributes.ptr () ;
      macroValidSharedObject (result, cMapElement) ;
      macroUniqueSharedObject (result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * AC_GALGAS_map::searchForReadWriteAttribute (const GALGAS_string & inKey,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cMapElement * result = NULL ;
  if (isValid ()) {
    insulate (THERE) ;
    if (NULL != mSharedMap) {
      result = (cMapElement *) mSharedMap->searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark searchForReadWriteAttribute (lstring)
#endif

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cSharedMapRoot::searchForReadWriteAttribute (const GALGAS_lstring & inKey,
                                                           C_Compiler * inCompiler,
                                                           const char * inSearchErrorMessage
                                                           COMMA_LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  cMapElement * result = NULL ;
  if (inKey.isValid ()) {
    const C_String key = inKey.mAttribute_string.stringValue () ;
    cMapNode * node = findEntryInMap (key, this) ;
    if (NULL != node) {
      node->mAttributes.insulate () ;
      result = (cMapElement *) node->mAttributes.ptr () ;
      macroValidSharedObject (result, cMapElement) ;
      macroUniqueSharedObject (result) ;
    }else{
      TC_UniqueArray <C_String> nearestKeyArray ;
      findNearestKey (key, nearestKeyArray) ;
      inCompiler->semanticErrorWith_K_message (inKey, nearestKeyArray, inSearchErrorMessage COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * AC_GALGAS_map::searchForReadWriteAttribute (const GALGAS_lstring & inKey,
                                                          C_Compiler * inCompiler,
                                                          const char * inSearchErrorMessage
                                                          COMMA_LOCATION_ARGS) {
  cMapElement * result = NULL ;
  if (isValid ()) {
    insulate (THERE) ;
    if (NULL != mSharedMap) {
      result = mSharedMap->searchForReadWriteAttribute (inKey, inCompiler, inSearchErrorMessage COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Remove
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void supBranchDecreased (cMapNode * & ioRoot,
                                bool & ioBranchHasBeenRemoved) {
  ioRoot->mBalance ++ ;
  switch (ioRoot->mBalance) {
  case 0:
    break;
  case 1:
    ioBranchHasBeenRemoved = false;
    break;
  case 2:
    switch (ioRoot->mInfPtr->mBalance) {
    case -1:
      rotateLeft (ioRoot->mInfPtr) ;
      rotateRight (ioRoot) ;
      break;
    case 0:
      rotateRight (ioRoot) ;
      ioBranchHasBeenRemoved = false;
      break;
    case 1:
      rotateRight (ioRoot) ;
      break;
    }
    break;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void infBranchDecreased (cMapNode * & ioRoot,
                                bool & ioBranchHasBeenRemoved) {
  ioRoot->mBalance -- ;
  switch (ioRoot->mBalance) {
  case 0:
    break;
  case -1:
    ioBranchHasBeenRemoved = false;
    break;
  case -2:
    switch (ioRoot->mSupPtr->mBalance) {
    case 1:
      rotateRight (ioRoot->mSupPtr) ;
      rotateLeft (ioRoot) ;
      break;
    case 0:
      rotateLeft (ioRoot) ;
      ioBranchHasBeenRemoved = false;
      break;
    case -1:
      rotateLeft (ioRoot) ;
      break;
    }
    break;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void getPreviousElement (cMapNode * & ioRoot,
                                cMapNode * & ioElement,
                                bool & ioBranchHasBeenRemoved) {
  if (ioRoot->mSupPtr == NULL) {
    ioElement = ioRoot ;
    ioRoot = ioRoot->mInfPtr ;
    ioBranchHasBeenRemoved = true ;
  }else{
    getPreviousElement (ioRoot->mSupPtr, ioElement, ioBranchHasBeenRemoved) ;
    if (ioBranchHasBeenRemoved) {
      supBranchDecreased (ioRoot, ioBranchHasBeenRemoved) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static cMapNode * internalRemoveEntry (const C_String & inKeyToRemove,
                                       cMapNode * & ioRoot,
                                       bool & ioBranchHasBeenRemoved) {
  cMapNode * removedNode = NULL ;
  if (ioRoot != NULL) {
    const int32_t comparaison = ioRoot->mKey.compare (inKeyToRemove) ;
    if (comparaison > 0) {
      removedNode = internalRemoveEntry (inKeyToRemove, ioRoot->mInfPtr, ioBranchHasBeenRemoved);
      if (ioBranchHasBeenRemoved) {
        infBranchDecreased (ioRoot, ioBranchHasBeenRemoved) ;
      }
    }else if (comparaison < 0) {
      removedNode = internalRemoveEntry (inKeyToRemove, ioRoot->mSupPtr, ioBranchHasBeenRemoved);
      if (ioBranchHasBeenRemoved) {
        supBranchDecreased (ioRoot, ioBranchHasBeenRemoved);
      }
    }else{ // Found
      removedNode = ioRoot ;
      cMapNode * p = ioRoot ;
      if (p->mInfPtr == NULL) {
        ioRoot = p->mSupPtr;
        p->mSupPtr = NULL;
        ioBranchHasBeenRemoved = true;
      }else if (p->mSupPtr == NULL) {
        ioRoot = p->mInfPtr;
        p->mInfPtr = NULL;
        ioBranchHasBeenRemoved = true;
      }else{
        getPreviousElement (p->mInfPtr, ioRoot, ioBranchHasBeenRemoved) ;
        ioRoot->mSupPtr = p->mSupPtr;
        p->mSupPtr = NULL;
        ioRoot->mInfPtr = p->mInfPtr;
        p->mInfPtr = NULL;
        ioRoot->mBalance = p->mBalance;
        p->mBalance = 0;
        if (ioBranchHasBeenRemoved) {
          infBranchDecreased (ioRoot, ioBranchHasBeenRemoved) ;
        }
      }
    }
  }
  return removedNode ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedMapRoot::performRemove (GALGAS_lstring & inKey,
                                    capCollectionElement & outResult,
                                    C_Compiler * inCompiler,
                                    const char * inRemoveErrorMessage
                                    COMMA_LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  if (inKey.isValid ()) {
    const C_String key = inKey.mAttribute_string.stringValue () ;
    bool branchHasBeenRemoved = false ;
    cMapNode * node = internalRemoveEntry (key, mRoot, branchHasBeenRemoved) ;
    if (NULL == node) {
    //--- Build error message
      C_String message ;
      bool perCentFound = false ;
      const C_String removeErrorMessage (inRemoveErrorMessage) ;
      const int32_t errorMessageLength = removeErrorMessage.length () ;
      for (int32_t i=0 ; i<errorMessageLength ; i++) {
        const utf32 c = removeErrorMessage (i COMMA_HERE) ;
        if (perCentFound) {
          if (UNICODE_VALUE (c) == 'K') {
            message << key ;
          }
          perCentFound = false ;
        }else if (UNICODE_VALUE (c) == '%') {
          perCentFound = true ;
        }else{
          message.appendUnicodeCharacter (c COMMA_HERE) ;
        }
      }
    //--- Emit error message
      const GALGAS_location key_location = inKey.mAttribute_location ;
      inCompiler->semanticErrorAtLocation (key_location, message COMMA_THERE) ;
    }else{ // Ok, found
      outResult = node->mAttributes ;
      macroMyDelete (node) ;
      mCount -- ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkMap (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_map::performRemove (GALGAS_lstring & inKey,
                                   capCollectionElement & outResult,
                                   C_Compiler * inCompiler,
                                   const char * inRemoveErrorMessage
                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    insulate (THERE) ;
    if (NULL != mSharedMap) {
      mSharedMap->performRemove (inKey, outResult, inCompiler, inRemoveErrorMessage COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Object Compare
#endif

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSharedMapRoot::mapCompare (const cSharedMapRoot * inOperand) const {
  typeComparisonResult r = kOperandEqual ;
  if (count () < inOperand->count ()) {
    r = kFirstOperandLowerThanSecond ;
  }else if (count () > inOperand->count ()) {
    r = kFirstOperandGreaterThanSecond ;
  }else{
    capCollectionElementArray array ; populateEnumerationArray (array, kEnumeration_up) ;
    capCollectionElementArray operandArray ; inOperand->populateEnumerationArray (operandArray, kEnumeration_up) ;
    for (uint32_t i=0 ; (i<array.count ()) && (kOperandEqual == r) ; i++) {
      r = array.objectAtIndex (i COMMA_HERE).compare (operandArray.objectAtIndex (i COMMA_HERE)) ;
    }
    if (kOperandEqual == r) {
      const int32_t n1 = (NULL == mOverridenMap) ? 0 : (int32_t) mOverridenMap->count () ;
      const int32_t n2 = (NULL == inOperand->mOverridenMap) ? 0 : (int32_t) inOperand->mOverridenMap->count () ;
      if (n1 < n2) {
        r = kFirstOperandLowerThanSecond ;
      }else if (n1 > n2) {
        r = kFirstOperandGreaterThanSecond ;
      }else if ((NULL != mOverridenMap) && (NULL != inOperand->mOverridenMap)) {
        r = mOverridenMap->mapCompare (inOperand->mOverridenMap) ;
      }
    }
  }
  return r ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult AC_GALGAS_map::objectCompare (const AC_GALGAS_map & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    result = mSharedMap->mapCompare (inOperand.mSharedMap) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark map overriden map
#endif

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_map::getOverridenMap (AC_GALGAS_map & outMap,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  outMap.drop () ;
  if (isValid ()) {
    if (NULL == mSharedMap->mOverridenMap) {
 //     outMap.makeNewEmptyMap (HERE) ;
      inCompiler->onTheFlySemanticError ("reader 'overriddenMap': no overriden map" COMMA_THERE) ;
    }else{
      macroAssignSharedObject (outMap.mSharedMap, mSharedMap->mOverridenMap) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark map cEnumerator
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void enterAscendingEnumeration (cMapNode * inNode,
                                       capCollectionElementArray & ioEnumerationArray) {
  if (inNode != NULL) {
    enterAscendingEnumeration (inNode->mInfPtr, ioEnumerationArray) ;
    if (NULL != inNode->mAttributes.ptr ()) {
      ioEnumerationArray.addObject (inNode->mAttributes) ;
    }
    enterAscendingEnumeration (inNode->mSupPtr, ioEnumerationArray) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void enterDescendingEnumeration (cMapNode * inNode,
                                        capCollectionElementArray & ioEnumerationArray) {
  if (inNode != NULL) {
    enterDescendingEnumeration (inNode->mSupPtr, ioEnumerationArray) ;
    if (NULL != inNode->mAttributes.ptr ()) {
      ioEnumerationArray.addObject (inNode->mAttributes) ;
    }
    enterDescendingEnumeration (inNode->mInfPtr, ioEnumerationArray) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedMapRoot::populateEnumerationArray (capCollectionElementArray & ioEnumerationArray,
                                               const typeEnumerationOrder inEnumerationOrder) const {
  // printf ("MAP COUNT %u\n", count ()) ;
  ioEnumerationArray.setCapacity (mCount) ;
  switch (enumerationOrderValue (inEnumerationOrder)) {
  case kENUMERATION_UP  :
    enterAscendingEnumeration (mRoot, ioEnumerationArray) ;
    break ;
  case kENUMERATION_DOWN :
    enterDescendingEnumeration (mRoot, ioEnumerationArray) ;
    break ;
  case kENUMERATION_ENTER_ORDER :
  case kENUMERATION_REVERSE_ENTER_ORDER :
    MF_RunTimeError ("invalid inEnumerationOrder %lld", enumerationOrderValue (inEnumerationOrder), 0) ;
//    break ;
  }
  MF_Assert (mCount == ioEnumerationArray.count (), "mCount (%lld) != ioEnumerationArray.count () (%lld)", mCount, ioEnumerationArray.count ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_map::populateEnumerationArray (capCollectionElementArray & ioEnumerationArray,
                                              const typeEnumerationOrder inEnumerationOrder) const {
  // printf ("MAP COUNT %u\n", count ()) ;
  if (isValid ()) {
    mSharedMap->populateEnumerationArray (ioEnumerationArray, inEnumerationOrder) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

