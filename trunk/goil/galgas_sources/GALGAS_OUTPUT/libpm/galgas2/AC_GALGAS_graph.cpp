//---------------------------------------------------------------------------*
//                                                                           *
//  AC_GALGAS_graph : Base class for GALGAS list                              *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2008, ..., 2010 Pierre Molinaro.                           *
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

#include "predefined-types.h"
#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------*

class cGraphNode {
  public : cGraphNode * mInfPtr ;
  public : cGraphNode * mSupPtr ;
  public : PMSInt32 mBalance ;
  public : const C_String mKey ;
  public : const PMUInt32 mNodeID ;
  public : capCollectionElement mAttributes ;
  public : GALGAS_location mDefinitionLocation ;
  public : TC_UniqueArray <GALGAS_location> mReferenceLocationArray ;

//--- Constructors
  public : cGraphNode (const C_String & inKey,
                       const PMUInt32 inNodeID) ;

  public : cGraphNode (cGraphNode * inNode) ;

//--- Destructor
  public : ~ cGraphNode (void) ;

//--- No copy
  private : cGraphNode (const cGraphNode &) ;
  private : cGraphNode & operator = (const cGraphNode &) ;
} ;

//---------------------------------------------------------------------------*

cGraphNode::~ cGraphNode (void) {
  macroMyDelete (mInfPtr) ;
  macroMyDelete (mSupPtr) ;
}

//---------------------------------------------------------------------------*

typedef struct {
  PMUInt32 mSourceNodeID ;
  PMUInt32 mTargetNodeID ;
} tArcStruct ;

//---------------------------------------------------------------------------*

class cSharedGraph : public C_SharedObject {
//--------------------------------- Attributes
  private : cGraphNode * mRoot ;
  public : inline const cGraphNode * root (void) const { return mRoot ; }
  private : PMUInt32 mAllNodeCount ;
  private : PMUInt32 mDefinedNodeCount ;
  private : TC_UniqueArray <tArcStruct> mArcArray ;

//--- Count
  public : inline PMUInt32 definedNodeCount (void) const { return mDefinedNodeCount ; }
  public : inline PMUInt32 allNodeCount (void) const { return mAllNodeCount ; }

//--- Constructor
  public : cSharedGraph (LOCATION_ARGS) ;

//--- Destructor
  public : virtual ~ cSharedGraph (void) ;

//--- Internal methods
  public : void description (C_String & ioString,
                             const PMSInt32 inIndentation) const ;

  public : void copyFrom (const cSharedGraph * inSource) ;

  public : PMSInt32 graphCompare (const cSharedGraph * inOperand) const ;

  public : cGraphNode * findOrAddNodeForKey (const C_String & inKey) ;

  protected : cGraphNode * internalInsert (cGraphNode * & ioRootPtr,
                                           const C_String & inKey,
                                           bool & ioExtension) ;

  public : void internalAddNode (const GALGAS_lstring & inKey,
                                 const char * inErrorMessage,
                                 const capCollectionElement & inAttributes,
                                 C_Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

  public : void addArc (const C_String & inSourceNodeKey,
                        const C_String & inTargetNodeKey,
                        const GALGAS_location & inTargetNodeLocation) ;

  public : void internalTopologicalSort (cSharedList * & outSortedList,
                                         GALGAS_lstringlist & outSortedNodeKeyList,
                                         cSharedList * & outUnsortedList,
                                         GALGAS_lstringlist & outUnsortedNodeKeyList) const ;

//--- No copy
  private : cSharedGraph (const cSharedGraph &) ;
  private : cSharedGraph & operator = (const cSharedGraph &) ;
} ;

//---------------------------------------------------------------------------*

cSharedGraph::cSharedGraph (LOCATION_ARGS) :
C_SharedObject (THERE),
mRoot (NULL),
mAllNodeCount (0),
mDefinedNodeCount (0),
mArcArray () {
}

//---------------------------------------------------------------------------*

cSharedGraph::~ cSharedGraph (void) {
  macroMyDelete (mRoot) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Copy
#endif

//---------------------------------------------------------------------------*

cGraphNode::cGraphNode (cGraphNode * inNode) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (inNode->mBalance),
mKey (inNode->mKey),
mNodeID (inNode->mNodeID),
mAttributes (inNode->mAttributes),
mDefinitionLocation (inNode->mDefinitionLocation),
mReferenceLocationArray () {
  if (NULL != inNode->mInfPtr) {
    macroMyNew (mInfPtr, cGraphNode (inNode->mInfPtr)) ;
  }
  if (NULL != inNode->mSupPtr) {
    macroMyNew (mSupPtr, cGraphNode (inNode->mSupPtr)) ;
  }
  mReferenceLocationArray.makeRoom (inNode->mReferenceLocationArray.count ()) ;
  for (PMSInt32 i=0 ; i<inNode->mReferenceLocationArray.count () ; i++) {
    mReferenceLocationArray.addObject (inNode->mReferenceLocationArray (i COMMA_HERE)) ;
  }
}

//---------------------------------------------------------------------------*

void cSharedGraph::copyFrom (const cSharedGraph * inSource) {
  macroUniqueSharedObject (this) ;
  if (NULL != inSource->mRoot) {
    macroMyNew (mRoot, cGraphNode (inSource->mRoot)) ;
    mDefinedNodeCount = inSource->mDefinedNodeCount ;
    mAllNodeCount = inSource->mAllNodeCount ;
    mArcArray.makeRoom (inSource->mArcArray.count ()) ;
    for (PMSInt32 i=0 ; i<inSource->mArcArray.count () ; i++) {
      mArcArray (i COMMA_HERE) = inSource->mArcArray (i COMMA_HERE) ;
    }
  }
}

//---------------------------------------------------------------------------*

void cSharedGraph::description (C_String & ioString,
                                const PMSInt32 /* inIndentation */) const {
  ioString << " ("
           << cStringWithUnsigned (mDefinedNodeCount)
           << " object" << ((mDefinedNodeCount > 1) ? "s" : "")
           << ")" ;
}

//---------------------------------------------------------------------------*
//    AC_GALGAS_graph                                                        *
//---------------------------------------------------------------------------*

AC_GALGAS_graph::AC_GALGAS_graph (void) :
AC_GALGAS_root (),
mSharedGraph (NULL) {
}

//---------------------------------------------------------------------------*

AC_GALGAS_graph::~ AC_GALGAS_graph (void) {
  macroDetachSharedObject (mSharedGraph) ;
}

//---------------------------------------------------------------------------*

AC_GALGAS_graph::AC_GALGAS_graph (const AC_GALGAS_graph & inSource) :
AC_GALGAS_root (),
mSharedGraph (NULL) {
  macroAssignSharedObject (mSharedGraph, inSource.mSharedGraph) ;
}

//---------------------------------------------------------------------------*

AC_GALGAS_graph & AC_GALGAS_graph::operator = (const AC_GALGAS_graph & inSource) {
  macroAssignSharedObject (mSharedGraph, inSource.mSharedGraph) ;
  return * this ;
}

//---------------------------------------------------------------------------*

void AC_GALGAS_graph::makeNewEmptyGraph (LOCATION_ARGS) {
  macroMyNew (mSharedGraph, cSharedGraph (THERE)) ;
}

//---------------------------------------------------------------------------*

void AC_GALGAS_graph::description (C_String & ioString,
                                  const PMSInt32 inIndentation) const {
  ioString << "<graph @"
           << staticTypeDescriptor ()->mGalgasTypeName ;
  if (isValid ()) {
    mSharedGraph->description (ioString, inIndentation) ;
  }else{
    ioString << " not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------*

PMUInt32 AC_GALGAS_graph::count () const {
  PMUInt32 result = 0 ;
  if (isValid ()) {
    result = mSharedGraph->definedNodeCount () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_uint AC_GALGAS_graph::reader_count (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint (count ()) ;
}

//---------------------------------------------------------------------------*

void AC_GALGAS_graph::drop (void) {
  macroDetachSharedObject (mSharedGraph) ;
}

//---------------------------------------------------------------------------*

void AC_GALGAS_graph::insulateGraph (LOCATION_ARGS) {
  if ((mSharedGraph != NULL) && (mSharedGraph->retainCount () > 1)) {
    cSharedGraph * p = NULL ;
    macroMyNew (p, cSharedGraph (THERE)) ;
    p->copyFrom (mSharedGraph) ;
    macroAssignSharedObject (mSharedGraph, p) ;
    macroDetachSharedObject (p) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Object Compare
#endif

//---------------------------------------------------------------------------*

PMSInt32 cSharedGraph::graphCompare (const cSharedGraph * inOperand) const {
  PMSInt32 r = ((PMSInt32) definedNodeCount ()) - ((PMSInt32) inOperand->definedNodeCount ()) ;
  if (r == 0) {

  }
  return r ;
}

//---------------------------------------------------------------------------*

typeComparisonResult AC_GALGAS_graph::objectCompare (const AC_GALGAS_graph & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const PMSInt32 r = mSharedGraph->graphCompare (inOperand.mSharedGraph) ;
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

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Node Insertion
#endif

//---------------------------------------------------------------------------*

static void rotateLeft (cGraphNode * & ioRootPtr) {
  cGraphNode * b = ioRootPtr->mSupPtr ;
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

//---------------------------------------------------------------------

static void rotateRight (cGraphNode * & ioRootPtr) {
  cGraphNode * b = ioRootPtr->mInfPtr ;
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

//---------------------------------------------------------------------------*

cGraphNode::cGraphNode (const C_String & inKey,
                        const PMUInt32 inNodeID) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mKey (inKey),
mNodeID (inNodeID),
mAttributes (),
mDefinitionLocation (),
mReferenceLocationArray () {
}

//---------------------------------------------------------------------------*

cGraphNode * cSharedGraph::internalInsert (cGraphNode * & ioRootPtr,
                                           const C_String & inKey,
                                           bool & ioExtension) {
  cGraphNode * matchingEntry = NULL ;
  if (ioRootPtr == NULL) {
    macroMyNew (ioRootPtr, cGraphNode (inKey, mAllNodeCount)) ;
    ioExtension = true ;
    mAllNodeCount ++ ;
    matchingEntry = ioRootPtr ;
  }else{
    macroValidPointer (ioRootPtr) ;
    const PMSInt32 comparaison = ioRootPtr->mKey.compare (inKey) ;
    if (comparaison > 0) {
      matchingEntry = internalInsert (ioRootPtr->mInfPtr, inKey, ioExtension) ;
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
      matchingEntry = internalInsert (ioRootPtr->mSupPtr, inKey, ioExtension) ;
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
    }else{ // Entry already exists
      matchingEntry = ioRootPtr ;
      ioExtension = false ;
    }
  }
  return matchingEntry ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark internalAddNode
#endif

//---------------------------------------------------------------------------*

cGraphNode * cSharedGraph::findOrAddNodeForKey (const C_String & inKey) {
  bool extension = false ; // Unused here
  return internalInsert (mRoot, inKey, extension) ;
}

//---------------------------------------------------------------------------*

void cSharedGraph::internalAddNode (const GALGAS_lstring & inKey,
                                    const char * inErrorMessage,
                                    const capCollectionElement & inAttributes,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cGraphNode * node = findOrAddNodeForKey (inKey.mAttribute_string.stringValue ()) ;
  if (node->mAttributes.ptr () == NULL) { // Node exists, but is undefined
    node->mAttributes = inAttributes ;
    node->mDefinitionLocation = inKey.mAttribute_location ;
    mDefinedNodeCount ++ ;  
  }else{ // Error : node redefinition
    GALGAS_lstring existingKey ;
    existingKey.mAttribute_location = node->mDefinitionLocation ;
    existingKey.mAttribute_string = GALGAS_string (node->mKey) ;
    inCompiler->semanticErrorWith_K_L_message (existingKey, inErrorMessage, inKey.mAttribute_location COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------*

void AC_GALGAS_graph::internalAddNode (const GALGAS_lstring & inKey,
                                       const char * inErrorMessage,
                                       const capCollectionElement & inAttributes,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid () && inAttributes.isValid ()) {
    insulateGraph (THERE) ;
    mSharedGraph->internalAddNode (inKey, inErrorMessage, inAttributes, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark modifier noteNode
#endif

//---------------------------------------------------------------------------*

void AC_GALGAS_graph::modifier_noteNode (const GALGAS_lstring & inKey
                                         COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    insulateGraph (THERE) ;
    cGraphNode * node = mSharedGraph->findOrAddNodeForKey (inKey.mAttribute_string.stringValue ()) ;
    node->mReferenceLocationArray.addObject (inKey.mAttribute_location) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Modifier addArc
#endif

//---------------------------------------------------------------------------*

void cSharedGraph::addArc (const C_String & inSourceNodeKey,
                           const C_String & inTargetNodeKey,
                           const GALGAS_location & inTargetNodeLocation) {
  cGraphNode * sourceNode = findOrAddNodeForKey (inSourceNodeKey) ;
  cGraphNode * targetNode = findOrAddNodeForKey (inTargetNodeKey) ;
  targetNode->mReferenceLocationArray.addObject (inTargetNodeLocation) ;
  const tArcStruct arc = {sourceNode->mNodeID, targetNode->mNodeID} ;
  mArcArray.addObject (arc) ;
}

//---------------------------------------------------------------------------*

void AC_GALGAS_graph::modifier_addArc (const GALGAS_lstring & inSourceNodeKey,
                                       const GALGAS_lstring & inTargetNodeKey
                                       COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inSourceNodeKey.isValid () && inTargetNodeKey.isValid ()) {
    insulateGraph (HERE) ;
    mSharedGraph->addArc (inSourceNodeKey.mAttribute_string.stringValue (),
                          inTargetNodeKey.mAttribute_string.stringValue (),
                          inTargetNodeKey.mAttribute_location) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark reader_undefinedNodeCount
#endif

//---------------------------------------------------------------------------*

GALGAS_uint AC_GALGAS_graph::reader_undefinedNodeCount (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mSharedGraph->allNodeCount () - mSharedGraph->definedNodeCount ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark reader_undefinedNodeKeyList
#endif

//---------------------------------------------------------------------------*

static void buildUndefinedNodeKeyList (const cGraphNode * inNode, GALGAS_stringlist & ioResult) {
  if (NULL != inNode) {
    buildUndefinedNodeKeyList (inNode->mInfPtr, ioResult) ;
    if (NULL == inNode->mAttributes.ptr ()) {
      ioResult.addAssign_operation (GALGAS_string (inNode->mKey) COMMA_HERE) ;
    }
    buildUndefinedNodeKeyList (inNode->mSupPtr, ioResult) ;
  }
}

//---------------------------------------------------------------------------*

GALGAS_stringlist AC_GALGAS_graph::reader_undefinedNodeKeyList (LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    buildUndefinedNodeKeyList (mSharedGraph->root (), result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Topological sort
#endif

//---------------------------------------------------------------------------*

class cTopologicalSortEntry {
  public : capCollectionElement mAttributes ;
  public : PMUInt32 mDependencyCount ;
  public : TC_Array <PMUInt32> mDependenceArray ; // Node indexes of nodes after current node
  public : PMSInt32 mLink ;
  public : GALGAS_lstring mKey ; // For display only

//--- Constructor
  public : cTopologicalSortEntry (void) ;
} ;

//---------------------------------------------------------------------------*

cTopologicalSortEntry::cTopologicalSortEntry (void) :
mAttributes (),
mDependencyCount (0),
mDependenceArray (),
mLink (-1),
mKey () {
}

//---------------------------------------------------------------------------*

static void enterNodes (const cGraphNode * inNode,
                        TC_UniqueArray <cTopologicalSortEntry> & ioArray) {
  if (NULL != inNode) {
    enterNodes (inNode->mInfPtr, ioArray) ;
    GALGAS_lstring lkey ;
    lkey.mAttribute_location = inNode->mDefinitionLocation ;
    lkey.mAttribute_string = GALGAS_string (inNode->mKey) ;
    ioArray ((PMSInt32) inNode->mNodeID COMMA_HERE).mKey = lkey ;
    ioArray ((PMSInt32) inNode->mNodeID COMMA_HERE).mAttributes = inNode->mAttributes ;
    enterNodes (inNode->mSupPtr, ioArray) ;
  }
}

//---------------------------------------------------------------------------*

void cSharedGraph::internalTopologicalSort (cSharedList * & outSortedList,
                                            GALGAS_lstringlist & outSortedNodeKeyList,
                                            cSharedList * & outUnsortedList,
                                            GALGAS_lstringlist & outUnsortedNodeKeyList) const {
  TC_UniqueArray <cTopologicalSortEntry> array ((PMSInt32) mAllNodeCount COMMA_HERE) ;
  array.addObjects ((PMSInt32) mAllNodeCount, cTopologicalSortEntry ()) ;
//--- Enter nodes
  enterNodes (mRoot, array) ;
//--- Enter arcs
  for (PMSInt32 i=0 ; i<mArcArray.count () ; i++) {
    const PMUInt32 sourceNodeID = mArcArray (i COMMA_HERE).mSourceNodeID ;
    cTopologicalSortEntry & source = array ((PMSInt32) sourceNodeID COMMA_HERE) ;
    cTopologicalSortEntry & target = array ((PMSInt32) mArcArray (i COMMA_HERE).mTargetNodeID COMMA_HERE) ;
    source.mDependencyCount ++ ;
    target.mDependenceArray.addObject (sourceNodeID) ;
  }
//--- Make exploration link
  for (PMSInt32 i=1 ; i<array.count () ; i++) {
    array (i-1 COMMA_HERE).mLink = i ;
  }
  PMSInt32 root = (mAllNodeCount > 0) ? 0 : -1 ;
//--- Display
  /* printf ("*** Working array:\n") ;
    for (PMSInt32 i=0 ; i<array.count () ; i++) {
      cTopologicalSortEntry & entry = array (i COMMA_HERE) ;
      printf ("#%d '%s' dep %d :", i, entry.mKey.cString (HERE), entry.mDependencyCount) ;
      for (PMSInt32 j=0 ; j<entry.mDependenceArray.count () ; j++) {
        printf (" %d", entry.mDependenceArray (j COMMA_HERE)) ;
      }
      printf ("\n") ;
    } */
//--- Loop for accumulating sorted nodes
  AC_GALGAS_list::makeNewSharedList (outSortedList COMMA_HERE) ;
  outSortedNodeKeyList = GALGAS_lstringlist::constructor_emptyList (HERE) ;
  bool loop = true ;
  while (loop) {
    loop = false ;
    PMSInt32 p = root ;
    root = -1 ;
    while (p >= 0) {
      cTopologicalSortEntry & entry = array (p COMMA_HERE) ;
      const PMSInt32 next = entry.mLink ;
      if (0 == entry.mDependencyCount) {
        loop = true ;
        for (PMSInt32 i=0 ; i<entry.mDependenceArray.count () ; i++) {
          array ((PMSInt32) entry.mDependenceArray (i COMMA_HERE) COMMA_HERE).mDependencyCount -- ;
        }
        AC_GALGAS_list::insertInSharedList (outSortedList, entry.mAttributes) ;
        outSortedNodeKeyList.addAssign_operation (entry.mKey COMMA_HERE) ;
      }else{
        entry.mLink = root ;
        root = p ;
      }
      p = next ;
    }
  }
//--- Add unsorted nodes
  AC_GALGAS_list::makeNewSharedList (outUnsortedList COMMA_HERE) ;
  outUnsortedNodeKeyList = GALGAS_lstringlist::constructor_emptyList (HERE) ;
  PMSInt32 p = root ;
  while (p >= 0) {
    cTopologicalSortEntry & entry = array (p COMMA_HERE) ;
    AC_GALGAS_list::insertInSharedList (outUnsortedList, entry.mAttributes) ;
    outUnsortedNodeKeyList.addAssign_operation (entry.mKey COMMA_HERE) ;
    p = entry.mLink ;
  }
}

//---------------------------------------------------------------------------*

void AC_GALGAS_graph::internalTopologicalSort (cSharedList * & outSortedList,
                                               GALGAS_lstringlist & outSortedNodeKeyList,
                                               cSharedList * & outUnsortedList,
                                               GALGAS_lstringlist & outUnsortedNodeKeyList,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  outSortedNodeKeyList.drop () ;
  outUnsortedNodeKeyList.drop () ;
  if (isValid ()) {
    const PMUInt32 undefinedNodeCount = mSharedGraph->allNodeCount () - mSharedGraph->definedNodeCount () ; 
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
      mSharedGraph->internalTopologicalSort (outSortedList, outSortedNodeKeyList, outUnsortedList, outUnsortedNodeKeyList) ;
    }
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark reader_undefinedNodeReferenceList
#endif

//---------------------------------------------------------------------------*

static void buildUndefinedNodeReferenceList (const cGraphNode * inNode,
                                             GALGAS_lstringlist & ioResult) {
  if (NULL != inNode) {
    buildUndefinedNodeReferenceList (inNode->mInfPtr, ioResult) ;
    if (NULL == inNode->mAttributes.ptr ()) {
      GALGAS_lstring lkey ;
      lkey.mAttribute_string = GALGAS_string (inNode->mKey) ;
      for (PMSInt32 i=0 ; i<inNode->mReferenceLocationArray.count () ; i++) {
        lkey.mAttribute_location = inNode->mReferenceLocationArray (i COMMA_HERE) ;
        ioResult.addAssign_operation (lkey COMMA_HERE) ;
      }
    }
    buildUndefinedNodeReferenceList (inNode->mSupPtr, ioResult) ;
  }
}

//---------------------------------------------------------------------------*

GALGAS_lstringlist AC_GALGAS_graph::reader_undefinedNodeReferenceList (LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (isValid ()) {
    result = GALGAS_lstringlist::constructor_emptyList (THERE) ;
    buildUndefinedNodeReferenceList (mSharedGraph->root (), result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
