//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  AC_GALGAS_uniqueMap : Base class for GALGAS map                                                                    *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2016 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-predefined-types.h"
#include "galgas2/capCollectionElement.h"
#include "galgas2/C_galgas_type_descriptor.h"
#include "utilities/MF_Assert.h"
#include "galgas2/C_Compiler.h"
#include "strings/unicode_string_routines.h"
#include "collections/TC_UniqueArray.h"
#include "galgas2/C_galgas_CLI_Options.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cUniqueMapNode ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef struct {
  cUniqueMapNode * mSource ;
  cUniqueMapNode * mTarget ;
} structDependanceEdge ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static bool operator == (const structDependanceEdge & inOperand1,
                         const structDependanceEdge & inOperand2) {
  return
    (inOperand1.mSource == inOperand2.mSource)
  &&
    (inOperand1.mTarget == inOperand2.mTarget)
  ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  c S h a r e d M a p R o o t                                                                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cSharedUniqueMapRoot : public C_SharedObject {
//--------------------------------- Attributes
  private : cUniqueMapNode * mRoot ;
  private : uint32_t mNodeCount ;
  protected : cSharedUniqueMapRoot * mOverridenMap ;
  private : TC_UniqueArray <structDependanceEdge> mDependenceEdges ;

//--- For automaton and block overrides
  public : const cBranchOverrideTransformationDescriptor * mBranchBehaviourArray ;
  public : uint32_t mBranchBehaviourArraySize ;
  public : const cBranchOverrideCompatibilityDescriptor * mBranchCombinationArray ;
  public : uint32_t mBranchCombinationArraySize ;
  public : const char * mOverrideName ;
  public : uint32_t mBeginBranchCount ;
  public : uint32_t mEndBranchCount ;
  public : uint32_t mStateArrayLevel ;
  
//--------------------------------- Accessors
  public : inline const cUniqueMapNode * root (void) const { return mRoot ; }
  public : inline uint32_t count (void) const { return mNodeCount ; }

//--------------------------------- Constructor
  protected : cSharedUniqueMapRoot (LOCATION_ARGS) ;

//--------------------------------- Virtual destructor
  public : virtual ~ cSharedUniqueMapRoot (void) ;

//--------------------------------- No copy
  private : cSharedUniqueMapRoot (const cSharedUniqueMapRoot &) ;
  private : cSharedUniqueMapRoot & operator = (const cSharedUniqueMapRoot &) ;

//--------------------------------- EnterEdge
  public : void enterEdge (cUniqueMapNode * inSource,
                           cUniqueMapNode * inTarget) ;

//--------------------------------- Edge graphviz representation
  public : VIRTUAL_IN_DEBUG C_String edgeGraphvizRepresentation (void) const ;

//--------------------------------- internalTopologicalSort
  public : VIRTUAL_IN_DEBUG void internalTopologicalSort (GALGAS_lstringlist & outSortedNodeKeyList,
                                                          GALGAS_lstringlist & outUnsortedNodeKeyList) const ;

//--------------------------------- Unsolved Proxy Count
  public : VIRTUAL_IN_DEBUG uint32_t unsolvedProxyCount (void) const ;

//--------------------------------- Attribute read access
  private : VIRTUAL_IN_DEBUG const cUniqueMapNode * findNodeForKeyInMapOrInOverridenMaps (const GALGAS_string & inKey,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- Insert
  protected : VIRTUAL_IN_DEBUG cUniqueMapNode * performInsert (capCollectionElement & inAttributes,
                                                               C_Compiler * inCompiler,
                                                               const uint32_t inInitialState,
                                                               const char * inInsertErrorMessage,
                                                               const mapAutomatonIssueEnum inShadowBehaviour,
                                                               const C_String & inShadowErrorMessage
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Search
  private : VIRTUAL_IN_DEBUG cUniqueMapNode * findEntryInMap (const C_String & inKey,
                                                        const cSharedUniqueMapRoot * inFirstMap) const ;

  public : VIRTUAL_IN_DEBUG void findNearestKey (const C_String & inKey,
                                                 TC_UniqueArray <C_String> & ioNearestKeyArray) const ;

  protected : VIRTUAL_IN_DEBUG cUniqueMapNode * performSearch (const GALGAS_lstring & inKey,
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

//--------------------------------- Readers
  protected : VIRTUAL_IN_DEBUG GALGAS_bool getter_hasKey (const GALGAS_string & inKey
                                                          COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG GALGAS_location getter_locationForKey (const GALGAS_string & inKey,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG GALGAS_stringset getter_allKeys (LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG GALGAS_lstringlist getter_allKeyList (LOCATION_ARGS) const ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation,
                                              const uint32_t inLevel) const ;

//--------------------------------- Internal method for enumeration
  protected : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & ioEnumerationArray) const ;

//--------------------------------- Comparison
  public : VIRTUAL_IN_DEBUG typeComparisonResult mapCompare (const cSharedUniqueMapRoot * inOperand) const ;

//--------------------------------- Internal method for inserting proxy
  protected : VIRTUAL_IN_DEBUG cUniqueMapNode * performInsertProxy (const C_String & inKey,
                                                                    const GALGAS_location & inLocation) ;

  protected : VIRTUAL_IN_DEBUG void unsolvedProxyKeyList (GALGAS_lstringlist & ioList) const ;

//--------------------------------- Check Map Automatons state
  public : VIRTUAL_IN_DEBUG void checkAutomatonStates (const GALGAS_location & inErrorLocation,
                                                       const cMapAutomatonFinalIssue inAutomatonFinalIssueArray [],
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- Begin override for block
  public : VIRTUAL_IN_DEBUG void openOverride (const cBranchOverrideTransformationDescriptor inBranchBehaviourArray [],
                                               const uint32_t inBranchBehaviourSize,
                                               const cBranchOverrideCompatibilityDescriptor inBranchCombinationArray [],
                                               const uint32_t inBranchCombinationSize,
                                               const char * inBlockName,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- End override for block
  public : VIRTUAL_IN_DEBUG void closeOverride (const GALGAS_location & inErrorLocation,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Branch Handling
  public : VIRTUAL_IN_DEBUG void openBranch (C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void closeBranch (const GALGAS_location & inErrorLocation,
                                              const cMapAutomatonFinalIssue inAutomatonFinalIssueArray [],
                                              #ifndef DO_NOT_GENERATE_CHECKINGS
                                                const uint32_t inAutomatonStateCount,
                                              #endif
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Check Map
  #ifndef DO_NOT_GENERATE_CHECKINGS
    private : VIRTUAL_IN_DEBUG void checkMap (LOCATION_ARGS) const ;
  #endif

//--------------------------------- Friend
  friend class AC_GALGAS_uniqueMap ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//     c S h a r e d P r o x y                                                                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cSharedProxy : public C_SharedObject {
//--- Attribute
  public : cUniqueMapNode * mNode ;
  
//--- Constructor
  public : cSharedProxy (cUniqueMapNode * inNode COMMA_LOCATION_ARGS) ;
  
//--- Destructor
  protected : virtual ~ cSharedProxy (void) ;

//--- Detach proxy
  protected : void detachProxy (void) ;

//--- No copy
  private : cSharedProxy (const cSharedProxy &) ;
  private : cSharedProxy & operator = (const cSharedProxy &) ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  c M a p N o d e                                                                                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cUniqueMapNode {
  public : cUniqueMapNode * mInfPtr ;
  public : cUniqueMapNode * mSupPtr ;
  public : int32_t mBalance ;
  public : const C_String mKey ;
  public : GALGAS_location mDefinitionLocation ;
  public : capCollectionElement mAttributes ;
  private : cSharedProxy * mProxy ;
  public : TC_UniqueArray <GALGAS_location> mInvocationLocationArray ;
//--- For state
  public : uint32_t mCurrentState ;
  public : cOverrideStateDescriptor * mStateArray ;
  public : uint32_t mStateArraySize ;

//--- Constructor
  public : cUniqueMapNode (const C_String & inKey,
                           const uint32_t inInitialState,
                           capCollectionElement & inAttributes) ;

//--- Solved ?
  public : inline VIRTUAL_IN_DEBUG bool isSolved (void) const {
    return NULL != mAttributes.ptr () ;
  }

//--- Destructor
  public : virtual ~ cUniqueMapNode (void) ;

//--- No copy
  private : cUniqueMapNode (const cUniqueMapNode &) ;
  private : cUniqueMapNode & operator = (const cUniqueMapNode &) ;

//--- Friends
  friend class cSharedProxy ;
  friend class AC_GALGAS_uniqueMapProxy ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cSharedUniqueMapRoot::cSharedUniqueMapRoot (LOCATION_ARGS) :
C_SharedObject (THERE),
mRoot (NULL),
mNodeCount (0),
mOverridenMap (NULL),
mDependenceEdges (),
mBranchBehaviourArray (NULL),
mBranchBehaviourArraySize (0),
mBranchCombinationArray (NULL),
mBranchCombinationArraySize (0),
mOverrideName (NULL),
mBeginBranchCount (0),
mEndBranchCount (0),
mStateArrayLevel (0) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cSharedUniqueMapRoot::~ cSharedUniqueMapRoot (void) {
  macroMyDelete (mRoot) ;
  macroDetachSharedObject (mOverridenMap) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cUniqueMapNode::cUniqueMapNode (const C_String & inKey,
                                const uint32_t inInitialState,
                                capCollectionElement & inAttributes) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mKey (inKey),
mDefinitionLocation (),
mAttributes (inAttributes),
mProxy (NULL),
mInvocationLocationArray (),
mCurrentState (inInitialState),
mStateArray (NULL),
mStateArraySize (0) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cUniqueMapNode::~cUniqueMapNode (void) {
  macroMyDelete (mInfPtr) ;
  macroMyDelete (mSupPtr) ;
  macroMyDeletePODArray (mStateArray) ;
//--- Detach Proxy
  if (NULL != mProxy) {
    mProxy->mNode = NULL ;
    mProxy = NULL ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Check Map
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void checkNode (const cUniqueMapNode * inNode,
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cSharedUniqueMapRoot::checkMap (LOCATION_ARGS) const {
    uint32_t n = 0 ;
    checkNode (mRoot, n) ;
    MF_AssertThere (n == mNodeCount, "n (%lld) != mNodeCount (%lld)", n, mNodeCount) ;
  }
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructor, destructor and copy
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_uniqueMap::AC_GALGAS_uniqueMap (const mapAutomatonIssueEnum inShadowBehaviour,
                                          const C_String & inShadowMessage) :
AC_GALGAS_root (),
mSharedMap (NULL),
mShadowBehaviour (inShadowBehaviour),
mShadowMessage (inShadowMessage) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_uniqueMap::AC_GALGAS_uniqueMap (const AC_GALGAS_uniqueMap & inSource) :
AC_GALGAS_root (),
mSharedMap (NULL),
mShadowBehaviour (inSource.mShadowBehaviour),
mShadowMessage (inSource.mShadowMessage) {
  macroAssignSharedObject (mSharedMap, inSource.mSharedMap) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_uniqueMap & AC_GALGAS_uniqueMap::operator = (const AC_GALGAS_uniqueMap & inSource) {
  macroAssignSharedObject (mSharedMap, inSource.mSharedMap) ;
  return *this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_uniqueMap::~AC_GALGAS_uniqueMap (void) {
  macroDetachSharedObject (mSharedMap) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::drop (void) {
  macroDetachSharedObject (mSharedMap) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::makeNewEmptyMap (LOCATION_ARGS) {
  macroMyNew (mSharedMap, cSharedUniqueMapRoot (THERE)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Description, log
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void internalDescription (cUniqueMapNode * inNode,
                                 C_String & ioString,
                                 const int32_t inIndentation,
                                 uint32_t & ioIdx) {
  if (NULL != inNode) {
    internalDescription (inNode->mInfPtr, ioString, inIndentation, ioIdx) ;
    ioString << "\n" ;
    ioString.writeStringMultiple ("| ", inIndentation) ;
    ioString << "|-at " << cStringWithUnsigned (ioIdx)
             << ": key '" << inNode->mKey << "', state " << cStringWithUnsigned (inNode->mCurrentState) ;
    inNode->mAttributes.description (ioString, inIndentation + 1) ;
    ioIdx ++ ;
    internalDescription (inNode->mSupPtr, ioString, inIndentation, ioIdx) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::description (C_String & ioString,
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::description (C_String & ioString,
                                       const int32_t inIndentation) const {
  ioString << "<map @"
           << staticTypeDescriptor ()->mGalgasTypeName ;
  if (isValid ()) {
    const cSharedUniqueMapRoot * currentMap = mSharedMap ;
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Search in map and overridden maps
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cUniqueMapNode * cSharedUniqueMapRoot::findEntryInMap (const C_String & inKey,
                                                       const cSharedUniqueMapRoot * inFirstMap) const {
  cUniqueMapNode * result = NULL ;
  const cSharedUniqueMapRoot * currentMap = inFirstMap ;
  while ((NULL != currentMap) && (NULL == result)) {
    cUniqueMapNode * currentNode = currentMap->mRoot ;
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const cUniqueMapNode * cSharedUniqueMapRoot::findNodeForKeyInMapOrInOverridenMaps (const GALGAS_string & inKey,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const {
  const cUniqueMapNode * result = NULL ;
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Search for "with" read only access
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const cCollectionElement * AC_GALGAS_uniqueMap::readAccessForWithInstruction (const GALGAS_string & inKey) const {
  const cCollectionElement * result = NULL ;
  if (isValid () && inKey.isValid ()) {
    cUniqueMapNode * node = mSharedMap->findEntryInMap (inKey.stringValue (), mSharedMap) ;
    if (NULL != node) {
      result = node->mAttributes.ptr () ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Insert
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void rotateLeft (cUniqueMapNode * & ioRootPtr) {
  cUniqueMapNode * b = ioRootPtr->mSupPtr ;
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void rotateRight (cUniqueMapNode * & ioRootPtr) {
  cUniqueMapNode * b = ioRootPtr->mInfPtr ;
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static cUniqueMapNode * internalInsert (cUniqueMapNode * & ioRootPtr,
                                        const C_String & inKey,
                                        const uint32_t inInitialState,
                                        capCollectionElement & inAttributes,
                                        bool & outEntryAlreadyExists,
                                        bool & ioExtension) {
  cUniqueMapNode * matchingEntry = NULL ;
  if (ioRootPtr == NULL) {
    macroMyNew (ioRootPtr, cUniqueMapNode (inKey, inInitialState, inAttributes)) ;
    ioExtension = true ;
    matchingEntry = ioRootPtr ;
  }else{
    macroValidPointer (ioRootPtr) ;
    const int32_t comparaison = ioRootPtr->mKey.compare (inKey) ;
    if (comparaison > 0) {
      matchingEntry = internalInsert (ioRootPtr->mInfPtr, inKey, inInitialState, inAttributes, outEntryAlreadyExists, ioExtension) ;
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
      matchingEntry = internalInsert (ioRootPtr->mSupPtr, inKey, inInitialState, inAttributes, outEntryAlreadyExists, ioExtension) ;
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
      matchingEntry = ioRootPtr ;
      matchingEntry->mInvocationLocationArray.setCountToZero () ;
      ioExtension = false ;
      outEntryAlreadyExists = matchingEntry->isSolved () ;
      if (! outEntryAlreadyExists) {
        matchingEntry->mAttributes = inAttributes ;
      }
    }
  }
  return matchingEntry ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cUniqueMapNode * cSharedUniqueMapRoot::performInsert (capCollectionElement & inAttributes,
                                                      C_Compiler * inCompiler,
                                                      const uint32_t inInitialState,
                                                      const char * inInsertErrorMessage,
                                                      const mapAutomatonIssueEnum inShadowBehaviour,
                                                      const C_String & inShadowMessage
                                                      COMMA_LOCATION_ARGS) {
  cUniqueMapNode * result = NULL ;
//--- If all attributes are built, perform insertion
  if (inAttributes.isValid ()) {
    cMapElement * p = (cMapElement *) inAttributes.ptr () ;
    macroValidSharedObject (p, cMapElement) ;
    const C_String key = p->mProperty_lkey.mProperty_string.stringValue () ;
  //--- Insert or replace
    bool extension = false ; // Unused here
    bool entryAlreadyExists = false ;
    cUniqueMapNode * matchingEntry = internalInsert (mRoot, key, inInitialState, inAttributes, entryAlreadyExists, extension) ;
    if (! entryAlreadyExists) {
      result = matchingEntry ;
      matchingEntry->mDefinitionLocation = p->mProperty_lkey.mProperty_location ;
      mNodeCount ++ ;
      switch (inShadowBehaviour) {
      case kMapAutomatonNoIssue :
        break ;
      case kMapAutomatonIssueWarning :
        matchingEntry = findEntryInMap (key, mOverridenMap) ;
        if (NULL != matchingEntry) {
        //--- Existing key
          cMapElement * me = (cMapElement *) matchingEntry->mAttributes.ptr () ;
          macroValidSharedObject (me, cMapElement) ;
          const GALGAS_location lstring_existingKey_location = me->mProperty_lkey.mProperty_location ;
        //--- Emit error message
          inCompiler->semanticWarningWith_K_L_message (p->mProperty_lkey, inShadowMessage.cString (HERE), lstring_existingKey_location COMMA_THERE) ;
        }
        break ;
      case kMapAutomatonIssueError :
        matchingEntry = findEntryInMap (key, mOverridenMap) ;
        if (NULL != matchingEntry) {
        //--- Existing key
          cMapElement * me = (cMapElement *) matchingEntry->mAttributes.ptr () ;
          macroValidSharedObject (me, cMapElement) ;
          const GALGAS_location lstring_existingKey_location = me->mProperty_lkey.mProperty_location ;
        //--- Emit error message
          inCompiler->semanticErrorWith_K_L_message (p->mProperty_lkey, inShadowMessage.cString (HERE), lstring_existingKey_location COMMA_THERE) ;
        }
        break ;
      }
    }else{ // Error, entry already exists
    //--- Existing key
      cMapElement * me = (cMapElement *) matchingEntry->mAttributes.ptr () ;
      macroValidSharedObject (me, cMapElement) ;
      const GALGAS_location lstring_existingKey_location = me->mProperty_lkey.mProperty_location ;
    //--- Emit error message
      inCompiler->semanticErrorWith_K_L_message (p->mProperty_lkey, inInsertErrorMessage, lstring_existingKey_location COMMA_THERE) ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkMap (HERE) ;
  #endif
//---
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::insertInSharedMap (capCollectionElement & inAttributes,
                                             C_Compiler * inCompiler,
                                             const uint32_t inInitialState,
                                             const char * /* inInitialStateName */,
                                             const char * inInsertErrorMessage
                                             COMMA_LOCATION_ARGS) {
//--- If all attributes are built, perform insertion
  if (isValid ()) {
    /* cUniqueMapNode * node = */ mSharedMap->performInsert (inAttributes,
                                                             inCompiler,
                                                             inInitialState,
                                                             inInsertErrorMessage,
                                                             mShadowBehaviour,
                                                             mShadowMessage
                                                             COMMA_THERE) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Modifier enterEdge
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::enterEdge (cUniqueMapNode * inSource,
                                      cUniqueMapNode * inTarget) {
  const structDependanceEdge e = {inSource, inTarget} ;
  mDependenceEdges.appendObjectIfUnique (e) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::setter_enterEdge (const GALGAS_lstring & inSource,
                                              const GALGAS_lstring & inTarget
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inSource.isValid () && inTarget.isValid( )) {
    cUniqueMapNode * source = mSharedMap->performInsertProxy (inSource.getter_string (THERE).stringValue (), inSource.getter_location (THERE)) ;
    cUniqueMapNode * target = mSharedMap->performInsertProxy (inTarget.getter_string (THERE).stringValue (), inTarget.getter_location (THERE)) ;
    mSharedMap->enterEdge (source, target) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Modifier enterEdge
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cTopologicalSortElement {
  public : uint32_t mDependencyCount ;
  public : TC_Array <int32_t> mDependenceArray ; // Node indexes of nodes after current node
  public : int32_t mExplorationLink ;
  public : GALGAS_lstring mKey ;

//--- Constructor
  public : cTopologicalSortElement (void) ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cTopologicalSortElement::cTopologicalSortElement (void) :
mDependencyCount (0),
mDependenceArray (),
mExplorationLink (-1),
mKey () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void enterNodes (const cUniqueMapNode * inNode,
                        TC_UniqueArray <cTopologicalSortElement> & ioArray,
                        TC_UniqueArray <const cUniqueMapNode *> & ioNodeArray) {
  if (NULL != inNode) {
    enterNodes (inNode->mInfPtr, ioArray, ioNodeArray) ;
    ioNodeArray.appendObject (inNode) ;
    const int32_t idx = ioArray.count () ;
    ioArray.appendObject (cTopologicalSortElement ()) ;
    GALGAS_lstring lkey ;
    lkey.mProperty_string = inNode->mKey ;
    lkey.mProperty_location = inNode->mDefinitionLocation ;
    ioArray (idx COMMA_HERE).mKey = lkey ;
    enterNodes (inNode->mSupPtr, ioArray, ioNodeArray) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::internalTopologicalSort (GALGAS_lstringlist & outSortedNodeKeyList,
                                                    GALGAS_lstringlist & outUnsortedNodeKeyList) const {
//--- Enter nodes
  TC_UniqueArray <const cUniqueMapNode *> nodeArray ;
  TC_UniqueArray <cTopologicalSortElement> array ;
  enterNodes (mRoot, array, nodeArray) ;
//--- Enter arcs
  for (int32_t i=0 ; i<mDependenceEdges.count () ; i++) {
    const int32_t sourceNodeID = nodeArray.indexOfFirstObjectEqualTo (mDependenceEdges (i COMMA_HERE).mSource) ;
    const int32_t targetNodeID = nodeArray.indexOfFirstObjectEqualTo (mDependenceEdges (i COMMA_HERE).mTarget) ;
    cTopologicalSortElement & source = array (sourceNodeID COMMA_HERE) ;
    cTopologicalSortElement & target = array (targetNodeID COMMA_HERE) ;
    source.mDependencyCount ++ ;
    target.mDependenceArray.appendObject (sourceNodeID) ;
  }
//--- Make exploration link
  for (int32_t i=1 ; i<array.count () ; i++) {
    array (i-1 COMMA_HERE).mExplorationLink = i ;
  }
  int32_t theRoot = (mNodeCount > 0) ? 0 : -1 ;
//--- Display
 /*  printf ("*** Working array:\n") ;
    for (int32_t i=0 ; i<array.count () ; i++) {
      cTopologicalSortElement & entry = array (i COMMA_HERE) ;
      printf ("#%d '%s' dep %d :", i, entry.mKey.getter_string (HERE).stringValue ().cString (HERE), entry.mDependencyCount) ;
      for (int32_t j=0 ; j<entry.mDependenceArray.count () ; j++) {
        printf (" %d", entry.mDependenceArray (j COMMA_HERE)) ;
      }
      printf ("\n") ;
    } */
//--- Loop for accumulating sorted nodes
  outSortedNodeKeyList = GALGAS_lstringlist::constructor_emptyList (HERE) ;
  bool loop = true ;
  while (loop) {
    loop = false ;
    int32_t p = theRoot ;
    theRoot = -1 ;
    while (p >= 0) {
      cTopologicalSortElement & entry = array (p COMMA_HERE) ;
      const int32_t next = entry.mExplorationLink ;
      if (0 == entry.mDependencyCount) {
        loop = true ;
        for (int32_t i=0 ; i<entry.mDependenceArray.count () ; i++) {
          array (entry.mDependenceArray (i COMMA_HERE) COMMA_HERE).mDependencyCount -- ;
        }
        outSortedNodeKeyList.addAssign_operation (entry.mKey COMMA_HERE) ;
      }else{
        entry.mExplorationLink = theRoot ;
        theRoot = p ;
      }
      p = next ;
    }
  }
//--- Add unsorted nodes
  outUnsortedNodeKeyList = GALGAS_lstringlist::constructor_emptyList (HERE) ;
  int32_t p = theRoot ;
  while (p >= 0) {
    cTopologicalSortElement & entry = array (p COMMA_HERE) ;
    outUnsortedNodeKeyList.addAssign_operation (entry.mKey COMMA_HERE) ;
    p = entry.mExplorationLink ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::method_topologicalSort (GALGAS_lstringlist & outSortedKeys,
                                                  GALGAS_lstringlist & outUnsortedKeys,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  outSortedKeys.drop () ;
  outUnsortedKeys.drop () ;
  if (isValid ()) {
    uint32_t undefinedNodeCount = mSharedMap->unsolvedProxyCount () ;
    if (0 != undefinedNodeCount) {
      C_String s ;
      s << "Cannot apply graph topologicalSort: there " ;
      if (undefinedNodeCount > 1) {
        s << "are " << cStringWithUnsigned (undefinedNodeCount) << " undefined nodes" ;
      }else{
        s << "is 1 undefined node" ;
      }
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      mSharedMap->internalTopologicalSort (outSortedKeys, outUnsortedKeys) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader edgeGraphvizRepresentation
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String cSharedUniqueMapRoot::edgeGraphvizRepresentation (void) const {
  C_String s ;
  s << "digraph G {\n" ;
  for (int32_t i=0 ; i<mDependenceEdges.count () ; i++) {
    const structDependanceEdge edge = mDependenceEdges (i COMMA_HERE) ;
    s << "  \"" << edge.mSource->mKey
      << "\" -> \"" << edge.mTarget->mKey
      << "\" ;\n" ;
  }  
  s << "}\n" ;
  return s ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_string AC_GALGAS_uniqueMap::getter_edgeGraphvizRepresentation (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mSharedMap->edgeGraphvizRepresentation ()) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader count
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint AC_GALGAS_uniqueMap::getter_count (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mSharedMap->count ()) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

uint32_t AC_GALGAS_uniqueMap::count (void) const {
  uint32_t result = 0 ;
  if (isValid ()) {
    result = mSharedMap->count () ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader "allKeys"
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void enterKeyInStringSet (const cUniqueMapNode * inNode,
                                 GALGAS_stringset & ioResult) {
  if (inNode != NULL) {
    enterKeyInStringSet (inNode->mInfPtr, ioResult) ;
    GALGAS_string object (inNode->mKey) ;
    ioResult.addAssign_operation (object COMMA_HERE) ;
    enterKeyInStringSet (inNode->mSupPtr, ioResult) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_stringset cSharedUniqueMapRoot::getter_allKeys (LOCATION_ARGS) const {
  GALGAS_stringset result = GALGAS_stringset::constructor_emptySet (THERE) ;
  enterKeyInStringSet (mRoot, result) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_stringset AC_GALGAS_uniqueMap::getter_allKeys (LOCATION_ARGS) const {
  GALGAS_stringset result ;
  if (isValid ()) {
    result = mSharedMap->getter_allKeys (THERE) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader "allKeyList"
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void enterKeyInLStringList (cUniqueMapNode * inNode,
                                   GALGAS_lstringlist & ioResult) {
  if (inNode != NULL) {
    enterKeyInLStringList (inNode->mInfPtr, ioResult) ;
    cMapElement * p = (cMapElement *) inNode->mAttributes.ptr () ;
    if (NULL != p) {
      macroValidSharedObject (p, cMapElement) ;
      ioResult.addAssign_operation (p->mProperty_lkey COMMA_HERE) ;
    }
    enterKeyInLStringList (inNode->mSupPtr, ioResult) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstringlist cSharedUniqueMapRoot::getter_allKeyList (LOCATION_ARGS) const {
  GALGAS_lstringlist result = GALGAS_lstringlist::constructor_emptyList (THERE) ;
  enterKeyInLStringList (mRoot, result) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstringlist AC_GALGAS_uniqueMap::getter_allKeyList (LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (isValid ()) {
    result = mSharedMap->getter_allKeyList (THERE) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader unsolvedProxyCount
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static uint32_t unsolvedProxyCountForNode (const cUniqueMapNode * inNode) {
  uint32_t result = 0 ;
  if (NULL != inNode) {
    result = NULL == inNode->mAttributes.ptr () ;
    result += unsolvedProxyCountForNode (inNode->mInfPtr) ;
    result += unsolvedProxyCountForNode (inNode->mSupPtr) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

uint32_t cSharedUniqueMapRoot::unsolvedProxyCount (void) const {
  return unsolvedProxyCountForNode (mRoot) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint AC_GALGAS_uniqueMap::getter_unsolvedProxyCount (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mSharedMap->unsolvedProxyCount ()) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader "unsolvedProxyKeyList"
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void recursiveUnsolvedKeyList (cUniqueMapNode * inNode,
                                      GALGAS_lstringlist & ioResult) {
  if (inNode != NULL) {
    recursiveUnsolvedKeyList (inNode->mInfPtr, ioResult) ;
    if (! inNode->isSolved ()) {
      if (inNode->mInvocationLocationArray.count () == 0) {
        GALGAS_lstring s (inNode->mKey, GALGAS_location::constructor_nowhere (HERE)) ;
        ioResult.addAssign_operation (s COMMA_HERE) ;
      }else{
        for (int32_t i=0 ; i<inNode->mInvocationLocationArray.count () ; i++) {
          GALGAS_lstring s (inNode->mKey, inNode->mInvocationLocationArray (i COMMA_HERE)) ;
          ioResult.addAssign_operation (s COMMA_HERE) ;
        }
      }
    }
    recursiveUnsolvedKeyList (inNode->mSupPtr, ioResult) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::unsolvedProxyKeyList (GALGAS_lstringlist & ioList) const {
  ioList = GALGAS_lstringlist::constructor_emptyList (HERE) ;
  recursiveUnsolvedKeyList (mRoot, ioList) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstringlist AC_GALGAS_uniqueMap::getter_unsolvedProxyList (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (isValid ()) {
    mSharedMap->unsolvedProxyKeyList (result) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader locationForKey
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_location cSharedUniqueMapRoot::getter_locationForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (inKey.isValid ()) {
    const C_String key = inKey.stringValue () ;
    cUniqueMapNode * node = findEntryInMap (key, this) ;
    if (NULL == node) {
      C_String message ;
      message << "'locationForKey' map reader run-time error: the '" << key << "' does not exist in map" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      cMapElement * p = (cMapElement *) node->mAttributes.ptr () ;
      macroValidSharedObject (p, cMapElement) ;
      result = p->mProperty_lkey.mProperty_location ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_location AC_GALGAS_uniqueMap::getter_locationForKey (const GALGAS_string & inKey,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (isValid ()) {
    result = mSharedMap->getter_locationForKey (inKey, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Reader hasKey
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool cSharedUniqueMapRoot::getter_hasKey (const GALGAS_string & inKey
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (inKey.isValid ()) {
    const C_String key = inKey.stringValue () ;
    const cUniqueMapNode * node = findEntryInMap (key, this) ;
    result = GALGAS_bool (NULL != node) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool AC_GALGAS_uniqueMap::getter_hasKey (const GALGAS_string & inKey
                                                COMMA_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = mSharedMap->getter_hasKey (inKey COMMA_THERE) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Search
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void emitErrorMessageForKey (const GALGAS_lstring & inKey,
                                    C_Compiler * inCompiler,
                                    const char * inSearchErrorMessage
                                    COMMA_LOCATION_ARGS) {
  const C_String key = inKey.mProperty_string.stringValue () ;
//--- Build error message
  C_String message ;
  bool perCentFound = false ;
  const C_String searchErrorMessage (inSearchErrorMessage) ;
  const int32_t errorMessageLength = searchErrorMessage.length () ;
  for (int32_t i=0 ; i<errorMessageLength ; i++) {
    const utf32 c = searchErrorMessage (i COMMA_HERE) ;
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
  const GALGAS_location key_location = inKey.mProperty_location ;
  inCompiler->semanticErrorAtLocation (key_location, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static C_String buildIssueMessage (const char * inIssueMessage,
                                   const C_String & inKey) {
  C_String result ;
  const C_String issueMessage (inIssueMessage) ;
  bool gotPercent = false ;
  for (int32_t i=0 ; i<issueMessage.length () ; i++) {
    const utf32 c = issueMessage (i COMMA_HERE) ;
    if (gotPercent) {
      if (UNICODE_VALUE (c) == 'K') {
        result << inKey ;
      }else{
        result.appendUnicodeCharacter (c COMMA_HERE) ;
      }
      gotPercent = false ;
    }else if (UNICODE_VALUE (c) == '%') {
      gotPercent = true ;
    }else{
      result.appendUnicodeCharacter (c COMMA_HERE) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void findNearestKeyForNode (const C_String & inKey,
                                   const cUniqueMapNode * inCurrentNode,
                                   uint32_t & ioBestDistance,
                                   TC_UniqueArray <C_String> & ioNearestKeyArray) {
  if (NULL != inCurrentNode) {
    macroValidPointer (inCurrentNode) ;
    const uint32_t distance = inCurrentNode->mKey.LevenshteinDistanceFromString (inKey) ;
    // printf ("inCurrentNode->mKey '%s', distance %u\n", inCurrentNode->mKey.cString (HERE), distance) ;
    if (ioBestDistance > distance) {
      ioBestDistance = distance ;
      ioNearestKeyArray.setCountToZero () ;
      ioNearestKeyArray.appendObject (inCurrentNode->mKey) ;
    }else if (ioBestDistance == distance) {
      ioNearestKeyArray.appendObject (inCurrentNode->mKey) ;
    }
    findNearestKeyForNode (inKey, inCurrentNode->mInfPtr, ioBestDistance, ioNearestKeyArray) ;
    findNearestKeyForNode (inKey, inCurrentNode->mSupPtr, ioBestDistance, ioNearestKeyArray) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::findNearestKey (const C_String & inKey,
                                           TC_UniqueArray <C_String> & ioNearestKeyArray) const {
  uint32_t bestDistance = UINT32_MAX ;
  const cSharedUniqueMapRoot * currentMap = this ;
  while (NULL != currentMap) {
    findNearestKeyForNode (inKey, currentMap->mRoot, bestDistance, ioNearestKeyArray) ;
    currentMap = currentMap->mOverridenMap ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::findNearestKey (const C_String & inKey,
                                          TC_UniqueArray <C_String> & ioNearestKeyArray) const {
  if (isValid ()) {
    mSharedMap->findNearestKey (inKey, ioNearestKeyArray) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cUniqueMapNode * cSharedUniqueMapRoot::performSearch (const GALGAS_lstring & inKey,
                                                      C_Compiler * inCompiler,
                                                      const char * inSearchErrorMessage
                                                      COMMA_LOCATION_ARGS) const {
  cUniqueMapNode * result = NULL ;
  if (inKey.isValid ()) {
    const C_String key = inKey.mProperty_string.stringValue () ;
    result = findEntryInMap (key, this) ;
    if (NULL == result) {
      TC_UniqueArray <C_String> nearestKeyArray ;
      findNearestKey (key, nearestKeyArray) ;
      inCompiler->semanticErrorWith_K_message (inKey, nearestKeyArray, inSearchErrorMessage COMMA_THERE) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const cCollectionElement * AC_GALGAS_uniqueMap::performSearch (const GALGAS_lstring & inKey,
                                                               C_Compiler * inCompiler,
                                                               const char * inSearchErrorMessage
                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * result = NULL ;
  if (isValid () && inKey.isValid ()) {
    const cUniqueMapNode * node = mSharedMap->performSearch (inKey, inCompiler, inSearchErrorMessage COMMA_THERE) ;
    if (NULL != node) {
      result = node->mAttributes.ptr () ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const cCollectionElement * AC_GALGAS_uniqueMap::performSearch (const GALGAS_lstring & inKey,
                                                               C_Compiler * inCompiler,
                                                               const uint32_t inActionIndex,
                                                               const cMapAutomatonTransition inTransitionArray [],
                                                               const uint32_t inAutomatonActionCount,
                                                               #ifndef DO_NOT_GENERATE_CHECKINGS
                                                                 const uint32_t inAutomatonStateCount,
                                                               #endif
                                                               const char * inSearchErrorMessage
                                                               COMMA_LOCATION_ARGS) {
  const cCollectionElement * result = NULL ;
  if (isValid () && inKey.isValid ()) {
    cUniqueMapNode * node = mSharedMap->performSearch (inKey, inCompiler, inSearchErrorMessage COMMA_THERE) ;
    if (NULL != node) {
      result = node->mAttributes.ptr () ;
    //--- Perform transition
      MF_Assert (node->mCurrentState < inAutomatonStateCount, "node->mCurrentState (%lld) >= inAutomatonStateCount (%lld)", (int64_t) node->mCurrentState, (int64_t) inAutomatonStateCount) ;
      MF_Assert (inActionIndex < inAutomatonActionCount, "inActionIndex (%lld) >= inAutomatonActionCount (%lld)", (int64_t) inActionIndex, (int64_t) inAutomatonActionCount) ;
      const cMapAutomatonTransition & transition = inTransitionArray [node->mCurrentState * inAutomatonActionCount + inActionIndex] ;
      // printf ("NODE '%s' : %d -> %d\n", inKey.getter_string (HERE).stringValue ().cString (HERE), node->mCurrentState, transition.mTargetStateIndex) ;
      node->mCurrentState = transition.mTargetStateIndex ;
      MF_Assert (node->mCurrentState < inAutomatonStateCount, "node->mCurrentState (%lld) >= inAutomatonStateCount (%lld)", (int64_t) node->mCurrentState, (int64_t) inAutomatonStateCount) ;
    //--- Issue ?
      switch (transition.mIssue) {
      case kMapAutomatonNoIssue :
        break ;
      case kMapAutomatonIssueWarning : {
        macroValidSharedObject (node->mAttributes.ptr (), cMapElement) ;
        const GALGAS_location loc = inKey.mProperty_location ;
        const C_String warningMessage = buildIssueMessage (transition.mIssueMessage, inKey.mProperty_string.stringValue ()) ;
        inCompiler->semanticWarningAtLocation (loc, warningMessage COMMA_THERE) ;
        }
        break ;
      case kMapAutomatonIssueError : {
        macroValidSharedObject (node->mAttributes.ptr (), cMapElement) ;
        const GALGAS_location loc = inKey.mProperty_location ;
        const C_String errorMessage = buildIssueMessage (transition.mIssueMessage, inKey.mProperty_string.stringValue ()) ;
        inCompiler->semanticErrorAtLocation (loc, errorMessage, TC_Array <C_FixItDescription> () COMMA_THERE) ;
        result = NULL ; // All output arguments will not be built
        }
        break ;
      }
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark searchForReadingAttribute
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const cMapElement * cSharedUniqueMapRoot::searchForReadingAttribute (const GALGAS_string & inKey,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  cMapElement * result = NULL ;
  if (inKey.isValid ()) {
    const C_String key = inKey.stringValue () ;
    cUniqueMapNode * node = findEntryInMap (key, this) ;
    if (NULL != node) {
      result = (cMapElement *) node->mAttributes.ptr () ;
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const cMapElement * AC_GALGAS_uniqueMap::searchForReadingAttribute (const GALGAS_string & inKey,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  const cMapElement * result = NULL ;
  if (isValid ()) {
    result = mSharedMap->searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark searchForReadWriteAttribute (string)
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement * cSharedUniqueMapRoot::searchForReadWriteAttribute (const GALGAS_string & inKey,
                                                                 C_Compiler * /* inCompiler */
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  cMapElement * result = NULL ;
  if (inKey.isValid ()) {
    const C_String key = inKey.stringValue () ;
    cUniqueMapNode * node = findEntryInMap (key, this) ;
    if (NULL != node) {
      node->mAttributes.insulate () ;
      result = (cMapElement *) node->mAttributes.ptr () ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement * AC_GALGAS_uniqueMap::searchForReadWriteAttribute (const GALGAS_string & inKey,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  cMapElement * result = NULL ;
  if (isValid ()) {
    result = (cMapElement *) mSharedMap->searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark searchForReadWriteAttribute (lstring)
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement * cSharedUniqueMapRoot::searchForReadWriteAttribute (const GALGAS_lstring & inKey,
                                                                 C_Compiler * inCompiler,
                                                                 const char * inSearchErrorMessage
                                                                 COMMA_LOCATION_ARGS) {
  cMapElement * result = NULL ;
  if (inKey.isValid ()) {
    const C_String key = inKey.mProperty_string.stringValue () ;
    cUniqueMapNode * node = findEntryInMap (key, this) ;
    if (NULL != node) {
      node->mAttributes.insulate () ;
      result = (cMapElement *) node->mAttributes.ptr () ;
      macroUniqueSharedObject (result) ;
    }else{
      emitErrorMessageForKey (inKey, inCompiler, inSearchErrorMessage COMMA_THERE) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cMapElement * AC_GALGAS_uniqueMap::searchForReadWriteAttribute (const GALGAS_lstring & inKey,
                                                                C_Compiler * inCompiler,
                                                                const char * inSearchErrorMessage
                                                                COMMA_LOCATION_ARGS) {
  cMapElement * result = NULL ;
  if (isValid ()) {
    result = mSharedMap->searchForReadWriteAttribute (inKey, inCompiler, inSearchErrorMessage COMMA_THERE) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Object Compare
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cSharedUniqueMapRoot::mapCompare (const cSharedUniqueMapRoot * inOperand) const {
  typeComparisonResult result = kOperandEqual ;
  if (count () < inOperand->count ()) {
    result = kFirstOperandLowerThanSecond ;
  }else if (count () < inOperand->count ()) {
    result = kFirstOperandGreaterThanSecond ;
  }else{
    capCollectionElementArray array ; populateEnumerationArray (array) ;
    capCollectionElementArray operandArray ; inOperand->populateEnumerationArray (operandArray) ;
    for (uint32_t i=0 ; (i<array.count ()) && (kOperandEqual == result) ; i++) {
      result = array.objectAtIndex (i COMMA_HERE).compare (operandArray.objectAtIndex (i COMMA_HERE)) ;
    }
    if (kOperandEqual == result) {
      const int32_t n1 = (NULL == mOverridenMap) ? 0 : (int32_t) mOverridenMap->count () ;
      const int32_t n2 = (NULL == inOperand->mOverridenMap) ? 0 : (int32_t) inOperand->mOverridenMap->count () ;
      if (n1 < n2) {
        result = kFirstOperandLowerThanSecond ;
      }else if (n1 < n2) {
        result = kFirstOperandGreaterThanSecond ;
      }else if ((NULL != mOverridenMap) && (NULL != inOperand->mOverridenMap)) {
        result = mOverridenMap->mapCompare (inOperand->mOverridenMap) ;
      }
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult AC_GALGAS_uniqueMap::objectCompare (const AC_GALGAS_uniqueMap & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    result = mSharedMap->mapCompare (inOperand.mSharedMap) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Open Override
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void recursiveInitializeStateArray (cUniqueMapNode * inNode,
                                           const uint32_t inIndex) {
  if (NULL != inNode) {
    // printf ("node %p, inIndex %u, inNode->mStateArray %p, key '%s'\n", inNode, inIndex, inNode->mStateArray, inNode->mKey.cString (HERE)) ;
    recursiveInitializeStateArray (inNode->mInfPtr, inIndex) ;
    if (inNode->mStateArraySize <= inIndex) {
      inNode->mStateArraySize = inIndex + 1 ;
      macroMyReallocPODArray (inNode->mStateArray, cOverrideStateDescriptor, inNode->mStateArraySize) ;
    }
    inNode->mStateArray [inIndex].mInitialStateIndex = inNode->mCurrentState ;
    inNode->mStateArray [inIndex].mResultingStateIndex = inNode->mCurrentState ;
    recursiveInitializeStateArray (inNode->mSupPtr, inIndex) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::openOverride (const cBranchOverrideTransformationDescriptor inBranchBehaviourArray [],
                                         const uint32_t inBranchBehaviourArraySize,
                                         const cBranchOverrideCompatibilityDescriptor inBranchCombinationArray [],
                                         const uint32_t inBranchCombinationArraySize,
                                         const char * inOverrideName,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  // printf ("-------------------------- openOverride\n") ;
  if (NULL != mOverrideName) {
    C_String m ;
    m << "Illegal invocation of 'beginOverrideForMap"
      << C_String (inOverrideName).stringByCapitalizingFirstCharacter ()
      << "': the '"
      << mOverrideName
      << "' override is still running" ;
    inCompiler->onTheFlySemanticError (m COMMA_THERE) ;
  }
  mBranchBehaviourArray = inBranchBehaviourArray ;
  mBranchBehaviourArraySize = inBranchBehaviourArraySize ;
  mBranchCombinationArray = inBranchCombinationArray ;
  mBranchCombinationArraySize = inBranchCombinationArraySize ;
  mOverrideName = inOverrideName ;
  mBeginBranchCount = 0 ;
  mEndBranchCount = 0 ;
//--- Increment level of all overriden maps
  cSharedUniqueMapRoot * currentMap = this ;
  while (currentMap != NULL) {
    macroValidSharedObject (currentMap, cSharedUniqueMapRoot) ;
    recursiveInitializeStateArray (currentMap->mRoot, currentMap->mStateArrayLevel) ;
    currentMap->mStateArrayLevel ++ ;
    currentMap = currentMap->mOverridenMap ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkMap (HERE) ;
  #endif
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::openOverride (const cBranchOverrideTransformationDescriptor inBranchBehaviourArray [],
                                        const uint32_t inBranchBehaviourSize,
                                        const cBranchOverrideCompatibilityDescriptor inBranchCombinationArray [],
                                        const uint32_t inBranchCombinationSize,
                                        const char * inBlockName,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    mSharedMap->openOverride (inBranchBehaviourArray,
                              inBranchBehaviourSize,
                              inBranchCombinationArray,
                              inBranchCombinationSize,
                              inBlockName,
                              inCompiler
                              COMMA_THERE) ;
    cSharedUniqueMapRoot * newRoot = NULL ;
    macroMyNew (newRoot, cSharedUniqueMapRoot (THERE)) ;
    macroAssignSharedObject (newRoot->mOverridenMap, mSharedMap) ;
    macroAssignSharedObject (mSharedMap, newRoot) ;
    macroDetachSharedObject (newRoot) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      mSharedMap->checkMap (HERE) ;
    #endif
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark map Open Branch
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void recursiveRestoreInitialState (cUniqueMapNode * inNode,
                                          const uint32_t inIndex) {
  if (NULL != inNode) {
    recursiveRestoreInitialState (inNode->mInfPtr, inIndex) ;
    MF_Assert (inIndex < inNode->mStateArraySize, "inIndex %lld >= inNode->mStateArraySize %lld", inIndex, inNode->mStateArraySize) ;
    inNode->mCurrentState = inNode->mStateArray [inIndex].mInitialStateIndex ;
    // printf ("OPEN BRANCH '%s' -> current state %u\n", inNode->mKey.cString (HERE), inNode->mCurrentState) ;
    recursiveRestoreInitialState (inNode->mSupPtr, inIndex) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::openBranch (C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  // printf ("-------------------------- openBranch\n") ;
  if (NULL == mOverridenMap) {
    C_String m ;
    m << "Illegal invocation of 'openBranch' modifier: no override" ;
    inCompiler->onTheFlySemanticError (m COMMA_THERE) ;
  }else if (mOverridenMap->mBeginBranchCount != mOverridenMap->mEndBranchCount) {
    C_String m ;
    m << "Illegal invocation of 'openBranch' modifier: openBranch / closeBranch invocations should be balanced" ;
    inCompiler->onTheFlySemanticError (m COMMA_THERE) ;
  }else{
    macroValidPointer (mOverridenMap) ;
    mOverridenMap->mBeginBranchCount ++ ;
    if (mOverridenMap->mBeginBranchCount > 0) {
      cSharedUniqueMapRoot * currentMap = mOverridenMap ; // Start at first overriden map
      while (NULL != currentMap) {
        macroValidSharedObject (currentMap, cSharedUniqueMapRoot) ;
        recursiveRestoreInitialState (currentMap->mRoot, currentMap->mStateArrayLevel - 1) ;
        currentMap = currentMap->mOverridenMap ;
      }
    }
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkMap (HERE) ;
    #endif
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::setter_openBranch (C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    mSharedMap->openBranch (inCompiler COMMA_THERE) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark map End Branch
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void printIssueMessage (C_Compiler * inCompiler,
                               const C_String & inKey,
                               const mapAutomatonIssueEnum inIssue,
                               const char * inIssueMessage,
                               const GALGAS_location & inIssueLocation
                               COMMA_LOCATION_ARGS) {
  switch (inIssue) {
    case kMapAutomatonIssueWarning : {
      const C_String warningMessage = buildIssueMessage (inIssueMessage, inKey) ;
      inCompiler->semanticWarningAtLocation (inIssueLocation, warningMessage COMMA_THERE) ;
      }
      break ;
    case kMapAutomatonIssueError : {
      const C_String errorMessage = buildIssueMessage (inIssueMessage, inKey) ;
      inCompiler->semanticErrorAtLocation (inIssueLocation, errorMessage, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      break ;
    case kMapAutomatonNoIssue : break ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void recursiveCheckBranchTransition (C_Compiler * inCompiler,
                                            const GALGAS_location & inIssueLocation,
                                            cUniqueMapNode * inNode,
                                            const cBranchOverrideTransformationDescriptor inBranchBehaviourArray [],
                                            const uint32_t inBranchBehaviourArraySize,
                                            const cBranchOverrideCompatibilityDescriptor inBranchCombinationArray [],
                                            const uint32_t inBranchCombinationArraySize,
                                            #ifndef DO_NOT_GENERATE_CHECKINGS
                                              const uint32_t inAutomatonStateCount,
                                            #endif
                                            const uint32_t inIndex,
                                            const bool inCheckBranchCompatibility
                                            COMMA_LOCATION_ARGS) {
  if (NULL != inNode) {
    recursiveCheckBranchTransition (inCompiler, inIssueLocation, inNode->mInfPtr,
                                    inBranchBehaviourArray, inBranchBehaviourArraySize,
                                    inBranchCombinationArray, inBranchCombinationArraySize,
                                    #ifndef DO_NOT_GENERATE_CHECKINGS
                                      inAutomatonStateCount,
                                    #endif
                                    inIndex, inCheckBranchCompatibility COMMA_THERE) ;
    recursiveCheckBranchTransition (inCompiler, inIssueLocation, inNode->mSupPtr,
                                    inBranchBehaviourArray, inBranchBehaviourArraySize,
                                    inBranchCombinationArray, inBranchCombinationArraySize,
                                    #ifndef DO_NOT_GENERATE_CHECKINGS
                                      inAutomatonStateCount,
                                    #endif
                                    inIndex, inCheckBranchCompatibility COMMA_THERE) ;
    MF_Assert (inIndex < inNode->mStateArraySize, "inIndex %lld >= inNode->mStateArraySize %lld", inIndex, inNode->mStateArraySize) ;
    const uint32_t previousResultingState = inNode->mStateArray [inIndex].mResultingStateIndex ;
  //--- Check branch behaviour
    const uint32_t initialState = inNode->mStateArray [inIndex].mInitialStateIndex ;
    MF_Assert (initialState < inAutomatonStateCount, "initialState (%lld) >= inAutomatonStateCount (%lld)", (int64_t) initialState, (int64_t) inAutomatonStateCount) ;
    uint32_t resultingCandidateState = inNode->mCurrentState ;
    if (initialState != resultingCandidateState) {
      MF_Assert (resultingCandidateState < inAutomatonStateCount, "resultingCandidateState (%lld) >= inAutomatonStateCount (%lld)", (int64_t) resultingCandidateState, (int64_t) inAutomatonStateCount) ;
      inNode->mStateArray [inIndex].mResultingStateIndex = resultingCandidateState ;
      bool foundBehaviour = false ;
      uint32_t behaviourIndex = 0 ;
      while ((! foundBehaviour) && (behaviourIndex < inBranchBehaviourArraySize)) {
        foundBehaviour = (inBranchBehaviourArray [behaviourIndex].mFirstStateIndex == initialState)
                      && (inBranchBehaviourArray [behaviourIndex].mLastStateIndex == resultingCandidateState) ;
        if (foundBehaviour) {
          resultingCandidateState = inBranchBehaviourArray [behaviourIndex].mResultingStateIndex  ;
          //const uint32_t actualResultCandidateStateIndex = inBranchBehaviourArray [behaviourIndex].mResultingStateIndex  ;
 //         inNode->mStateArray [inIndex].mResultingStateIndex = actualResultCandidateStateIndex  ;
          // printf (" resulting state %u\n", actualResultCandidateStateIndex) ;
          //printf ("CLOSE BRANCH %d '%s': %u:%u -> %u (previous %u)\n", inCheckBranchCompatibility, inNode->mKey.cString (HERE), initialState, resultingCandidateState, actualResultCandidateStateIndex, previousResultingState) ;
          printIssueMessage (inCompiler, inNode->mKey,
                             inBranchBehaviourArray [behaviourIndex].mIssue, inBranchBehaviourArray [behaviourIndex].mIssueMessage,
                             inIssueLocation COMMA_THERE) ;
        }
        behaviourIndex ++ ;
      }
      MF_Assert (foundBehaviour, "inBranchBehaviourArray for %lld %lld not found", initialState, resultingCandidateState) ;
    }
  //---
    MF_Assert (previousResultingState < inAutomatonStateCount, "previousResultingState (%lld) >= inAutomatonStateCount (%lld)", (int64_t) previousResultingState, (int64_t) inAutomatonStateCount) ;
    // printf ("recursiveCheckBranchTransition '%s' : initialState %u, previousResultingState %u resultingCandidateState %u\n", inNode->mKey.cString (HERE), initialState, previousResultingState, resultingCandidateState) ;
    if (inCheckBranchCompatibility && (previousResultingState != resultingCandidateState)) {
       bool foundCompatibility = false ;
       uint32_t compatibilityIndex = 0 ;
       while ((! foundCompatibility) && (compatibilityIndex < inBranchCombinationArraySize)) {
         foundCompatibility = (inBranchCombinationArray [compatibilityIndex].mFirstCandidateStateIndex == previousResultingState)
                           && (inBranchCombinationArray [compatibilityIndex].mSecondCandidateStateIndex == resultingCandidateState) ;
         if (foundCompatibility) {
           // printf ("MERGE '%s': %u:%u ->%u\n", inNode->mKey.cString (HERE), previousResultingState, resultingCandidateState, inBranchCombinationArray [compatibilityIndex].mResultingStateIndex) ;
           inNode->mStateArray [inIndex].mResultingStateIndex = inBranchCombinationArray [compatibilityIndex].mResultingStateIndex ;
           printIssueMessage (inCompiler, inNode->mKey,
                              inBranchCombinationArray [compatibilityIndex].mIssue, inBranchCombinationArray [compatibilityIndex].mIssueMessage,
                              inIssueLocation COMMA_THERE) ;
         }
         compatibilityIndex ++ ;
       }
       MF_Assert (foundCompatibility, "inBranchBehaviourArray for %lld %lld not found", previousResultingState, resultingCandidateState) ;
     }
  //---
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::closeBranch (const GALGAS_location & inErrorLocation,
                                        const cMapAutomatonFinalIssue inAutomatonFinalIssueArray [],
                                        #ifndef DO_NOT_GENERATE_CHECKINGS
                                          const uint32_t inAutomatonStateCount,
                                        #endif
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  // printf ("-------------------------- closeBranch\n") ;
  if (NULL == mOverridenMap) {
    C_String m ;
    m << "Illegal invocation of 'closeBranch' modifier: no override" ;
    inCompiler->onTheFlySemanticError (m COMMA_THERE) ;
  }else{
    macroValidSharedObject (mOverridenMap, cSharedUniqueMapRoot) ;
    mOverridenMap->mEndBranchCount ++ ;
    if (mOverridenMap->mBeginBranchCount != mOverridenMap->mEndBranchCount) {
      C_String m ;
      m << "Illegal invocation of 'closeBranch' modifier: openBranch / closeBranch invocations should be balanced" ;
      inCompiler->onTheFlySemanticError (m COMMA_THERE) ;
    }else{
      checkAutomatonStates (inErrorLocation, inAutomatonFinalIssueArray, inCompiler COMMA_THERE) ;
    }
  //--- For all overriden maps, check variables transitions
    cSharedUniqueMapRoot * currentMap = mOverridenMap ;
    while (NULL != currentMap) {
      macroValidSharedObject (currentMap, cSharedUniqueMapRoot) ;
      MF_Assert (currentMap->mStateArrayLevel > 0, "currentMap->mStateArrayLevel == 0", 0, 0) ;
      recursiveCheckBranchTransition (inCompiler, inErrorLocation, currentMap->mRoot,
                                      mOverridenMap->mBranchBehaviourArray,
                                      mOverridenMap->mBranchBehaviourArraySize,
                                      mOverridenMap->mBranchCombinationArray,
                                      mOverridenMap->mBranchCombinationArraySize,
                                      #ifndef DO_NOT_GENERATE_CHECKINGS
                                        inAutomatonStateCount,
                                      #endif
                                      currentMap->mStateArrayLevel - 1,
                                      mOverridenMap->mEndBranchCount > 1
                                      COMMA_THERE) ;
      currentMap = currentMap->mOverridenMap ;
    }
  //--- Remove all entries of first level
    macroMyDelete (mRoot) ;
    mNodeCount = 0 ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkMap (HERE) ;
    #endif
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::closeBranch (const GALGAS_location & inErrorLocation,
                                       const cMapAutomatonFinalIssue inAutomatonFinalIssueArray [],
                                       #ifndef DO_NOT_GENERATE_CHECKINGS
                                         const uint32_t inAutomatonStateCount,
                                       #endif
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    mSharedMap->closeBranch (inErrorLocation,
                             inAutomatonFinalIssueArray,
                             #ifndef DO_NOT_GENERATE_CHECKINGS
                               inAutomatonStateCount,
                             #endif
                             inCompiler COMMA_THERE) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark map End Override
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void recursiveSetFinalState (cUniqueMapNode * inNode,
                                    const uint32_t inIndex) {
  if (NULL != inNode) {
    recursiveSetFinalState (inNode->mInfPtr, inIndex) ;
    MF_Assert (inIndex < inNode->mStateArraySize, "inIndex %lld >= inNode->mStateArraySize %lld", inIndex, inNode->mStateArraySize) ;
    inNode->mCurrentState = inNode->mStateArray [inIndex].mResultingStateIndex ;
    recursiveSetFinalState (inNode->mSupPtr, inIndex) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::closeOverride (const GALGAS_location & inErrorLocation,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  // printf ("-------------------------- closeOverride\n") ;
  if (NULL != mOverrideName) {
    C_String m ;
    m << "Illegal invocation of 'closeOverride' modifier: the '"
      << mOverrideName
      << "' override is still running" ;
    inCompiler->semanticErrorAtLocation (inErrorLocation, m, TC_Array <C_FixItDescription> () COMMA_THERE) ;
  }else if (mOverridenMap->mBeginBranchCount != mOverridenMap->mEndBranchCount) {
    C_String m ;
    m << "Illegal invocation of 'closeOverride' modifier: openBranch / closeBranch invocations should be balanced" ;
    inCompiler->semanticErrorAtLocation (inErrorLocation, m, TC_Array <C_FixItDescription> () COMMA_THERE) ;
  }
//--- Decrement level of overriden maps
  macroValidSharedObject (mOverridenMap, cSharedUniqueMapRoot) ;
  mOverridenMap->mOverrideName = NULL ;
  cSharedUniqueMapRoot * currentMap = mOverridenMap ;
  while (NULL != currentMap) {
    macroValidSharedObject (currentMap, cSharedUniqueMapRoot) ;
    MF_Assert (currentMap->mStateArrayLevel > 0, "currentMap->mStateArrayLevel == 0", 0, 0) ;
    currentMap->mStateArrayLevel -- ;
    recursiveSetFinalState (currentMap->mRoot, currentMap->mStateArrayLevel) ;
    currentMap = currentMap->mOverridenMap ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkMap (HERE) ;
  #endif
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::setter_closeOverride (const GALGAS_location & inErrorLocation,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    mSharedMap->closeOverride (inErrorLocation, inCompiler COMMA_THERE) ;
    macroValidSharedObject (mSharedMap->mOverridenMap, cSharedUniqueMapRoot) ;
    cSharedUniqueMapRoot * p = mSharedMap->mOverridenMap ;
    macroAssignSharedObject (mSharedMap, p) ;
    macroValidSharedObject (mSharedMap, cSharedUniqueMapRoot) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      mSharedMap->checkMap (HERE) ;
    #endif
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark map checkAutomatonStates
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void recursiveCheckAutomatonStates (const cUniqueMapNode * inNode,
                                           C_Compiler * inCompiler,
                                           const GALGAS_location & inErrorLocation,
                                           const cMapAutomatonFinalIssue inAutomatonFinalIssueArray []
                                           COMMA_LOCATION_ARGS) {
  if (NULL != inNode) {
    recursiveCheckAutomatonStates (inNode->mInfPtr, inCompiler, inErrorLocation, inAutomatonFinalIssueArray COMMA_THERE) ;
    const uint32_t currentState = inNode->mCurrentState ;
    const cMapAutomatonFinalIssue & issue = inAutomatonFinalIssueArray [currentState] ;
    if (NULL != issue.mIssueMessage) {
      switch (issue.mIssue) {
        case kMapAutomatonIssueWarning : {
          const C_String warningMessage = buildIssueMessage (issue.mIssueMessage, inNode->mKey) ;
          macroValidSharedObject (inNode->mAttributes.ptr (), cMapElement) ;
          const GALGAS_location loc = ((const cMapElement *) inNode->mAttributes.ptr ())->mProperty_lkey.mProperty_location ;
          inCompiler->semanticWarningAtLocation (loc, warningMessage COMMA_THERE) ;
          }
          break ;
        case kMapAutomatonIssueError : {
          const C_String errorMessage = buildIssueMessage (issue.mIssueMessage, inNode->mKey) ;
          macroValidSharedObject (inNode->mAttributes.ptr (), cMapElement) ;
          const GALGAS_location loc = ((const cMapElement *) inNode->mAttributes.ptr ())->mProperty_lkey.mProperty_location ;
          inCompiler->semanticErrorAtLocation (loc, errorMessage, TC_Array <C_FixItDescription> () COMMA_THERE) ;
          }
          break ;
        case kMapAutomatonNoIssue : break ;
      }
    }
    recursiveCheckAutomatonStates (inNode->mSupPtr, inCompiler, inErrorLocation, inAutomatonFinalIssueArray COMMA_THERE) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::checkAutomatonStates (const GALGAS_location & inErrorLocation,
                                                 const cMapAutomatonFinalIssue inAutomatonFinalIssueArray [],
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  recursiveCheckAutomatonStates (mRoot, inCompiler, inErrorLocation, inAutomatonFinalIssueArray COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::checkAutomatonStates (const GALGAS_location & inErrorLocation,
                                                const cMapAutomatonFinalIssue inAutomatonFinalIssueArray [],
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  if (isValid () && inErrorLocation.isValid ()) {
    mSharedMap->checkAutomatonStates (inErrorLocation, inAutomatonFinalIssueArray, inCompiler COMMA_THERE) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark map cEnumerator
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void enterAscendingEnumeration (cUniqueMapNode * inNode,
                                       capCollectionElementArray & ioEnumerationArray) {
  if (inNode != NULL) {
    enterAscendingEnumeration (inNode->mInfPtr, ioEnumerationArray) ;
    if (NULL != inNode->mAttributes.ptr ()) {
      ioEnumerationArray.appendObject (inNode->mAttributes) ;
    }
    enterAscendingEnumeration (inNode->mSupPtr, ioEnumerationArray) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedUniqueMapRoot::populateEnumerationArray (capCollectionElementArray & ioEnumerationArray) const {
  // printf ("MAP COUNT %u\n", count ()) ;
  ioEnumerationArray.setCapacity (mNodeCount) ;
  enterAscendingEnumeration (mRoot, ioEnumerationArray) ;
  MF_Assert (mNodeCount == (uint32_t) ioEnumerationArray.count (),
             "mNodeCount (%lld) != ioEnumerationArray.count () (%lld)",
             mNodeCount, ioEnumerationArray.count ()) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMap::populateEnumerationArray (capCollectionElementArray & ioEnumerationArray) const {
  // printf ("MAP COUNT %u\n", count ()) ;
  if (isValid ()) {
    mSharedMap->populateEnumerationArray (ioEnumerationArray) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cSharedProxy::cSharedProxy (cUniqueMapNode * inNode
                            COMMA_LOCATION_ARGS) :
C_SharedObject (THERE),
mNode (inNode) {
  macroValidPointer (inNode) ;
  inNode->mProxy = this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cSharedProxy::~cSharedProxy (void) {
  detachProxy () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedProxy::detachProxy (void) {
  if (NULL != mNode) {
    mNode->mProxy = NULL ;
    mNode = NULL ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Map Proxy
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_uniqueMapProxy::AC_GALGAS_uniqueMapProxy (void) :
AC_GALGAS_root (),
mState (kNotValid),
mSharedProxy (NULL) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_uniqueMapProxy::AC_GALGAS_uniqueMapProxy (const AC_GALGAS_uniqueMapProxy & inSource) :
AC_GALGAS_root (),
mState (inSource.mState),
mSharedProxy (NULL) {
  macroAssignSharedObject (mSharedProxy, inSource.mSharedProxy) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_uniqueMapProxy & AC_GALGAS_uniqueMapProxy::operator = (const AC_GALGAS_uniqueMapProxy & inSource) {
  mState = inSource.mState ;
  macroAssignSharedObject (mSharedProxy, inSource.mSharedProxy) ;
  return * this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_uniqueMapProxy::~ AC_GALGAS_uniqueMapProxy (void) {
  drop () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool AC_GALGAS_uniqueMapProxy::isValid (void) const {
  return (kIsNull == mState) || (kIsRegular == mState) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMapProxy::drop (void) {
  macroDetachSharedObject (mSharedProxy) ;
  mState = kNotValid ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMapProxy::makeNullProxy (LOCATION_ARGS) {
  MF_AssertThere (kNotValid == mState, "invalid state for 'makeNullProxy'", 0, 0) ;
  mState = kIsNull ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMapProxy::attachProxyToMapNode (cUniqueMapNode * inMapNode) {
  MF_Assert (kNotValid == mState, "invalid state for 'makeNullProxy'", 0, 0) ;
  if (NULL != inMapNode) {
    macroValidSharedObject (inMapNode, cUniqueMapNode) ;
    if (NULL == inMapNode->mProxy) {
      macroMyNew (mSharedProxy, cSharedProxy (inMapNode COMMA_HERE)) ;
    }else{
      macroAssignSharedObject (mSharedProxy, inMapNode->mProxy) ;
    }
    mState = kIsRegular ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool AC_GALGAS_uniqueMapProxy::getter_isRegular (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (kIsRegular == mState) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool AC_GALGAS_uniqueMapProxy::getter_isNull (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (kIsNull == mState) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool AC_GALGAS_uniqueMapProxy::getter_isSolved (C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_bool result ;
  switch (mState) {
  case kIsNull :
    result = GALGAS_bool (true) ; // A NULL proxy is always solved
    break ;
  case kIsRegular :
    macroValidSharedObject (mSharedProxy, cSharedProxy) ;
    if (NULL == mSharedProxy->mNode) {
      inCompiler->onTheFlySemanticError ("cannot run 'isSolved' reader of map proxy: entry has been deleted" COMMA_THERE) ;
    }else{
      macroValidPointer (mSharedProxy->mNode) ;
      result = GALGAS_bool (NULL != mSharedProxy->mNode->mAttributes.ptr ()) ;
    }
    break ;
  case kNotValid :
    break ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const cMapElement * AC_GALGAS_uniqueMapProxy::getAttributeListPointer (C_Compiler * inCompiler,
                                                                       const char * inReaderName
                                                                       COMMA_LOCATION_ARGS) const {
  const cMapElement * result = NULL ;
  switch (mState) {
  case kIsNull : // A NULL proxy has no key
    inCompiler->onTheFlySemanticError (C_String ("cannot compute '") + inReaderName + "' reader of map proxy: proxy is null" COMMA_THERE) ;
    break ;
  case kIsRegular :
    macroValidSharedObject (mSharedProxy, cSharedProxy) ;
    if (NULL == mSharedProxy->mNode) {
      inCompiler->onTheFlySemanticError (C_String ("cannot compute '") + inReaderName + "' reader of map proxy: entry has been deleted" COMMA_THERE) ;
    }else{
      macroValidPointer (mSharedProxy->mNode) ;
      result = (const cMapElement *) mSharedProxy->mNode->mAttributes.ptr () ;
      macroNullOrValidSharedObject (result, cMapElement) ;
    }
    break ;
  case kNotValid :
    break ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_lstring AC_GALGAS_uniqueMapProxy::getter_lkey (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  const cMapElement * p = getAttributeListPointer (inCompiler, "lkey" COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement) ;
    result = p->mProperty_lkey ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_string AC_GALGAS_uniqueMapProxy::getter_key (C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  switch (mState) {
  case kIsNull : // A NULL proxy has no key
    inCompiler->onTheFlySemanticError ("cannot compute 'key' reader of map proxy: proxy is null" COMMA_THERE) ;
    break ;
  case kIsRegular :
    macroValidSharedObject (mSharedProxy, cSharedProxy) ;
    if (NULL == mSharedProxy->mNode) {
      inCompiler->onTheFlySemanticError ("cannot compute 'key' reader of map proxy: entry has been deleted" COMMA_THERE) ;
    }else{
      macroValidPointer (mSharedProxy->mNode) ;
      result = mSharedProxy->mNode->mKey ;
    }
    break ;
  case kNotValid :
    break ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_string AC_GALGAS_uniqueMapProxy::getter_identifierRepresentation (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  switch (mState) {
  case kIsNull : // A NULL proxy has no key
    inCompiler->onTheFlySemanticError ("cannot compute 'identifierRepresentation' reader of map proxy: proxy is null" COMMA_THERE) ;
    break ;
  case kIsRegular :
    macroValidSharedObject (mSharedProxy, cSharedProxy) ;
    if (NULL == mSharedProxy->mNode) {
      inCompiler->onTheFlySemanticError ("cannot compute 'identifierRepresentation' reader of map proxy: entry has been deleted" COMMA_THERE) ;
    }else{
      macroValidPointer (mSharedProxy->mNode) ;
      result = mSharedProxy->mNode->mKey.identifierRepresentation () ;
    }
    break ;
  case kNotValid :
    break ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMapProxy::description (C_String & ioString,
                                            const int32_t /* inIndentation */) const {
  ioString << "<@"
           << staticTypeDescriptor ()->mGalgasTypeName
           << " " ;
  switch (mState) {
  case kIsNull : // A NULL proxy has no key
    ioString << "null" ;
    break ;
  case kIsRegular :
    macroValidSharedObject (mSharedProxy, cSharedProxy) ;
    if (NULL == mSharedProxy->mNode) {
      ioString << "deleted" ;
    }else{
      ioString << "regular (key " ;
      macroValidPointer (mSharedProxy->mNode) ;
      ioString.appendCLiteralStringConstant (mSharedProxy->mNode->mKey) ;
      ioString << ", "
               << (mSharedProxy->mNode->isSolved () ? "solved" : "unsolved")
               << ")" ;
    }
    break ;
  case kNotValid :
    ioString << "not built" ;
    break ;
  }
  ioString << ">" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cUniqueMapNode * AC_GALGAS_uniqueMap::searchEntryInMap (const C_String & inKey) const {
  cUniqueMapNode * result = NULL ;
  if (isValid ()) {
    result = mSharedMap->findEntryInMap (inKey, mSharedMap) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMapProxy::internalMakeRegularProxyBySearchingKey (const AC_GALGAS_uniqueMap & inMap,
                                                                       const GALGAS_lstring & inKey,
                                                                       const char * inSearchErrorMessage,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) {
  if (inKey.isValid ()) {
    cUniqueMapNode * node = inMap.searchEntryInMap (inKey.mProperty_string.stringValue ()) ;
    if (NULL == node) {
      TC_UniqueArray <C_String> nearestKeyArray ;
      inMap.findNearestKey (inKey.mProperty_string.stringValue (), nearestKeyArray) ;
      inCompiler->semanticErrorWith_K_message (inKey, nearestKeyArray, inSearchErrorMessage COMMA_THERE) ;
    }
    attachProxyToMapNode (node) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static cUniqueMapNode * internalInsertProxy (cUniqueMapNode * & ioRootPtr,
                                             const C_String & inKey,
                                             const GALGAS_location & inLocation,
                                             bool & ioExtension) {
  cUniqueMapNode * matchingEntry = NULL ;
  if (ioRootPtr == NULL) {
    capCollectionElement emptyAttributes ;
    macroMyNew (ioRootPtr, cUniqueMapNode (inKey, 0, emptyAttributes)) ;
    if (inLocation.isValidAndNotNowhere ()) {
      ioRootPtr->mInvocationLocationArray.appendObject (inLocation) ;
    }
    ioExtension = true ;
    matchingEntry = ioRootPtr ;
  }else{
    macroValidPointer (ioRootPtr) ;
    const int32_t comparaison = ioRootPtr->mKey.compare (inKey) ;
    if (comparaison > 0) {
      matchingEntry = internalInsertProxy (ioRootPtr->mInfPtr, inKey, inLocation, ioExtension) ;
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
      matchingEntry = internalInsertProxy (ioRootPtr->mSupPtr, inKey, inLocation, ioExtension) ;
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
    }else{ // Ok, entry already exists
      matchingEntry = ioRootPtr ;
      if (inLocation.isValidAndNotNowhere () && (! ioRootPtr->isSolved ())) {
        ioRootPtr->mInvocationLocationArray.appendObject (inLocation) ;
      }
      ioExtension = false ;
    }
  }
  return matchingEntry ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cUniqueMapNode * cSharedUniqueMapRoot::performInsertProxy (const C_String & inKey,
                                                           const GALGAS_location & inLocation) {
  bool extension = false ; // Unused here
  return internalInsertProxy (mRoot, inKey, inLocation, extension) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cUniqueMapNode * AC_GALGAS_uniqueMap::performInsertProxy (const C_String & inKey,
                                                          const GALGAS_location & inLocation
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  cUniqueMapNode * result = NULL ;
  if (isValid ()) {
    result = mSharedMap->performInsertProxy (inKey, inLocation) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMapProxy::internalMakeProxy (AC_GALGAS_uniqueMap & ioMap,
                                                  const GALGAS_lstring & inKey
                                                  COMMA_LOCATION_ARGS) {
  drop () ;
  if (inKey.isValid ()) {
    cUniqueMapNode * node = ioMap.performInsertProxy (inKey.getter_string (THERE).stringValue (),
                                                      inKey.getter_location (THERE)
                                                      COMMA_THERE) ;
    macroValidPointer (node) ;
    attachProxyToMapNode (node) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMapProxy::internalMakeOptionalProxy (AC_GALGAS_uniqueMap & ioMap,
                                                          const GALGAS_lstring & inKey
                                                          COMMA_LOCATION_ARGS) {
  drop () ;
  if (inKey.isValid ()) {
    const C_String key = inKey.getter_string (THERE).stringValue () ;
    if (key.length() == 0) {
      makeNullProxy (THERE) ;
    }else{
      cUniqueMapNode * node = ioMap.performInsertProxy (key,
                                                        inKey.getter_location (THERE)
                                                        COMMA_THERE) ;
      macroValidPointer (node) ;
      attachProxyToMapNode (node) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_uniqueMapProxy::internalMakeProxyFromString (AC_GALGAS_uniqueMap & ioMap,
                                                            const GALGAS_string & inKey
                                                            COMMA_LOCATION_ARGS) {
  drop () ;
  if (inKey.isValid ()) {
    cUniqueMapNode * node = ioMap.performInsertProxy (inKey.stringValue (),
                                                      GALGAS_location ()
                                                      COMMA_THERE) ;
    macroValidPointer (node) ;
    attachProxyToMapNode (node) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult AC_GALGAS_uniqueMapProxy::objectCompare (const AC_GALGAS_uniqueMapProxy & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    int32_t r = mState - inOperand.mState ;
    if (0 == r) {
      const size_t entry1 = (size_t) mSharedProxy ;
      const size_t entry2 = (size_t) inOperand.mSharedProxy ;
      if (entry1 < entry2) {
        r = -1 ;
      }else if (entry1 > entry2) {
        r = +1 ;
      }
    }
    if (r < 0) {
      result = kFirstOperandLowerThanSecond ;
    }else if (r > 0) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

